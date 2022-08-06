#pragma once

#include <Windows.Foundation.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <d3d11.h>
#include <directxmath.h>
#include <dxgi1_3.h>
#include <ppltasks.h>

#include <windows.h>
#include <string>
#include <memory>

class DeviceResources
{
public:
    DeviceResources();
    ~DeviceResources();

    HRESULT CreateDeviceResources( HWND hWnd );
    HRESULT CreateDeviceResources( );
    HRESULT CreateWindowResources( HWND hWnd );

    HRESULT ConfigureBackBuffer();
    HRESULT ReleaseBackBuffer();
    HRESULT GoFullScreen();
    HRESULT GoWindowed();

    float GetAspectRatio();

    ID3D11Device*           GetDevice() { return m_pd3dDevice.Get(); };
    ID3D11DeviceContext*    GetDeviceContext() { return m_pd3dDeviceContext.Get(); };
    ID3D11RenderTargetView* GetRenderTarget() { return m_pRenderTarget.Get(); }
    ID3D11DepthStencilView* GetDepthStencil() { return m_pDepthStencilView.Get(); }
    
    void Present();

private:

    //-----------------------------------------------------------------------------
    // Direct3D device
    //-----------------------------------------------------------------------------
    Microsoft::WRL::ComPtr<ID3D11Device>        m_pd3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pd3dDeviceContext; // immediate context
    Microsoft::WRL::ComPtr<IDXGISwapChain>      m_pDXGISwapChain;


    //-----------------------------------------------------------------------------
    // DXGI swap chain device resources
    //-----------------------------------------------------------------------------
    Microsoft::WRL::ComPtr < ID3D11Texture2D>        m_pBackBuffer;
    Microsoft::WRL::ComPtr < ID3D11RenderTargetView> m_pRenderTarget;


    //-----------------------------------------------------------------------------
    // Direct3D device resources for the depth stencil
    //-----------------------------------------------------------------------------
    Microsoft::WRL::ComPtr<ID3D11Texture2D>         m_pDepthStencil;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_pDepthStencilView;


    //-----------------------------------------------------------------------------
    // Direct3D device metadata and device resource metadata
    //-----------------------------------------------------------------------------
    D3D_FEATURE_LEVEL       m_featureLevel;
    D3D11_TEXTURE2D_DESC    m_bbDesc;
    D3D11_VIEWPORT          m_viewport;
};

class Renderer
{
public:
    Renderer(std::shared_ptr<DeviceResources> deviceResources);
    ~Renderer();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();
    void Update();
    void Render();

private:
    HRESULT CreateShaders();
    HRESULT CreateCube();
    void    CreateViewAndPerspective();

    //-----------------------------------------------------------------------------
    // Pointer to device resource manager
    //-----------------------------------------------------------------------------
    std::shared_ptr<DeviceResources> m_deviceResources;

    //-----------------------------------------------------------------------------
    // Variables for rendering the cube
    //-----------------------------------------------------------------------------
    typedef struct _constantBufferStruct {
        DirectX::XMFLOAT4X4 world;
        DirectX::XMFLOAT4X4 view;
        DirectX::XMFLOAT4X4 projection;
    } ConstantBufferStruct;

    // Assert that the constant buffer remains 16-byte aligned.
    static_assert((sizeof(ConstantBufferStruct) % 16) == 0, "Constant Buffer size must be 16-byte aligned");

    //-----------------------------------------------------------------------------
    // Per-vertex data
    //-----------------------------------------------------------------------------
    typedef struct _vertexPositionColor
    {
        DirectX::XMFLOAT3 pos;
        DirectX::XMFLOAT3 color;
    } VertexPositionColor;

    //-----------------------------------------------------------------------------
    // Per-vertex data (extended)
    //-----------------------------------------------------------------------------
    typedef struct _vertexPositionColorTangent
    {
        DirectX::XMFLOAT3 pos;
        DirectX::XMFLOAT3 normal;
        DirectX::XMFLOAT3 tangent;
    } VertexPositionColorTangent;

    ConstantBufferStruct m_constantBufferData;
    unsigned int  m_indexCount;
    unsigned int  m_frameCount;

    //-----------------------------------------------------------------------------
    // Direct3D device resources
    //-----------------------------------------------------------------------------
    //ID3DXEffect* m_pEffect;
    Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pVertexBuffer;
    Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pIndexBuffer;
    Microsoft::WRL::ComPtr<ID3D11VertexShader>      m_pVertexShader;
    Microsoft::WRL::ComPtr<ID3D11InputLayout>       m_pInputLayout;
    Microsoft::WRL::ComPtr<ID3D11InputLayout>       m_pInputLayoutExtended;
    Microsoft::WRL::ComPtr<ID3D11PixelShader>       m_pPixelShader;
    Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pConstantBuffer;
};

class MainClass
{
 public:
  MainClass();
  ~MainClass();
  HRESULT CreateDesktopWindow();
  HWND GetWindowHandle() { return m_hWnd; };
  static LRESULT CALLBACK StaticWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
  HRESULT Run(
        std::shared_ptr<DeviceResources> deviceResources,
        std::shared_ptr<Renderer> renderer
        );

 private:
  HMENU m_hMenu;
  RECT m_rc;
  HWND m_hWnd;
};

// These are STATIC because this sample only creates one window.
// If your app can have multiple windows, MAKE SURE this is dealt with 
// differently.
static HINSTANCE m_hInstance;
static std::wstring m_windowClassName;