////////////////////////////////////////////////////////////////////////////////////////////
// "platform.h"                                                                           //
//                                                                                        //
// Generals' declarator for the platform.                                                 //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef _HEPTA_PRAGMA_PLATFORM_H
 #define _HEPTA_PRAGMA_PLATFORM_H
 
 // Commands
  // General
   #include <winsdkver.h>
   #ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0601
   #endif
   #include <sdkddkver.h>

   #define NOMINMAX   // Use the C++ standard templated min/max.
   #define NODRAWTEXT // DirectX apps don't need GDI.
   #define NOGDI      // DirectX apps don't need GDI.
   #define NOBITMAP   // DirectX apps don't need GDI.
   #define NOMCX      // Include <mcx.h> if you need this.
   #define NOSERVICE  // Include <winsvc.h> if you need this.
   #define NOHELP     // WinHelp is deprecated.

   #define WIN32_LEAN_AND_MEAN

   #include <Windows.h>
   #include <combaseapi.h>
   #include <wrl/client.h>
   #include <shellapi.h>

   #pragma warning (push, 0)
    #include <d3d11_1.h>
    #include <dxgi1_6.h>
   #pragma warning (pop)

   #include <fstream>
   #include <sstream>
   #include <memory>
   #include <stdexcept>
   #include <exception>
   
   //DirectX Tool Kit
    #pragma warning (push, 0)
     #include <SpriteBatch.h>
     #include <WICTextureLoader.h>
     #include <CommonStates.h>

     #include <Keyboard.h>
     #include <GamePad.h>
     #include <Mouse.h>

     #include <Audio.h>
    #pragma warning (pop)
   //-//
   
  //-//

  using int0 = void;                 // -
  using int1 = bool;                 // I know, it's not 1 byte.
  using int8 = char;                 // -
  using int16 = short;               // -
  using int32 = int;                 // -
  using int64 = long long;           // -
  using sint8 = signed char;         // -
  using sint16 = signed short;       // -
  using sint32 = signed int;         // -
  using sint64 = signed long long;   // -
  using lint32 = long;               // -
  using uint8 = unsigned char;       // -
  using uint16 = unsigned short;     // -
  using uint32 = unsigned int;       // -
  using uint64 = unsigned long long; // -
  using xint32 = float;              // -
  using xint64 = double;             // -
  using string = std::string;        // -
  using stream = std::stringstream;  // -
  using insize = uint32;             // Vector maximum size.

  #define unique std::unique_ptr

  #define rint1 static_cast < int1 >
  #define rint8 static_cast < int8 >
  #define rint16 static_cast < int16 >
  #define rint32 static_cast < int32 >
  #define rint64 static_cast < int64 >
  #define rsint8 static_cast < sint8 >
  #define rsint16 static_cast < sint16 >
  #define rsint32 static_cast < sint32 >
  #define rsint64 static_cast < sint64 >
  #define ruint8 static_cast < uint8 >
  #define ruint16 static_cast < uint16 >
  #define ruint32 static_cast < uint32 >
  #define ruint64 static_cast < uint64 >
  #define rxint32 static_cast < xint32 >
  #define rxint64 static_cast < xint64 >
  #define rinsize static_cast < insize >

  #define remains static
  #define absolut constexpr
  #define statics const
  #define univers virtual
  #define fastened noexcept
 //-//

 // Stuctures / Classes
  // DirectX
   struct HEPTA_DEVICENOTIFY
   {
    univers int0 OnDeviceLost() = 0ui8;
    univers int0 OnDeviceRestored() = 0ui8;
    protected:
     ~HEPTA_DEVICENOTIFY() = default;
   };
   
   struct HEPTA_DEVICE
   {
    remains absolut uint32 c_FlipPresent  = 0x1;
    remains absolut uint32 c_AllowTearing = 0x2;
    remains absolut uint32 c_EnableHDR    = 0x4;
    
    HEPTA_DEVICE(DXGI_FORMAT, DXGI_FORMAT, uint32, D3D_FEATURE_LEVEL, uint32) fastened;
    ~HEPTA_DEVICE() = default;
    HEPTA_DEVICE(HEPTA_DEVICE&&) = default;
    HEPTA_DEVICE& operator= (HEPTA_DEVICE&&) = default;
    HEPTA_DEVICE(HEPTA_DEVICE statics&) = delete;
    HEPTA_DEVICE& operator= (HEPTA_DEVICE statics&) = delete;
    
    int0 CreateDeviceResources();
    int0 CreateWindowSizeDependentResources();
    int0 SetWindow(HWND, uint32, uint32) fastened;
    int0 HandleDeviceLost();
    int0 RegisterDeviceNotify(HEPTA_DEVICENOTIFY* deviceNotify) fastened {m_deviceNotify = deviceNotify;}
    int0 Present();
    int0 UpdateColorSpace();
    int1 WindowSizeChanged(uint32, uint32);
    
    RECT                    GetOutputSize()         statics fastened {return m_outputSize;}                // Device accessor.
    auto                    GetD3DDevice()          statics fastened {return m_d3dDevice.Get();}           // Direct3D Accessors.
    auto                    GetD3DDeviceContext()   statics fastened {return m_d3dContext.Get();}          // Direct3D Accessors.
    auto                    GetSwapChain()          statics fastened {return m_swapChain.Get();}           // Direct3D Accessors.
    auto                    GetDXGIFactory()        statics fastened {return m_dxgiFactory.Get();}         // Direct3D Accessors.
    HWND                    GetWindow()             statics fastened {return m_window;}                    // Direct3D Accessors.
    D3D_FEATURE_LEVEL       GetDeviceFeatureLevel() statics fastened {return m_d3dFeatureLevel;}           // Direct3D Accessors.
    ID3D11Texture2D*        GetRenderTarget()       statics fastened {return m_renderTarget.Get();}        // Direct3D Accessors.
    ID3D11Texture2D*        GetDepthStencil()       statics fastened {return m_depthStencil.Get();}        // Direct3D Accessors.
    ID3D11RenderTargetView* GetRenderTargetView()   statics fastened {return m_d3dRenderTargetView.Get();} // Direct3D Accessors.
    ID3D11DepthStencilView* GetDepthStencilView()   statics fastened {return m_d3dDepthStencilView.Get();} // Direct3D Accessors.
    DXGI_FORMAT             GetBackBufferFormat()   statics fastened {return m_backBufferFormat;}          // Direct3D Accessors.
    DXGI_FORMAT             GetDepthBufferFormat()  statics fastened {return m_depthBufferFormat;}         // Direct3D Accessors.
    D3D11_VIEWPORT          GetScreenViewport()     statics fastened {return m_screenViewport;}            // Direct3D Accessors.
    UINT                    GetBackBufferCount()    statics fastened {return m_backBufferCount;}           // Direct3D Accessors.
    DXGI_COLOR_SPACE_TYPE   GetColorSpace()         statics fastened {return m_colorSpace;}                // Direct3D Accessors.
    uint32                  GetDeviceOptions()      statics fastened {return m_options;}                   // Direct3D Accessors.
    
    int0 PIXBeginEvent(_In_z_ statics wchar_t* name){m_d3dAnnotation->BeginEvent(name);} // Performance event.
    int0 PIXEndEvent()                              {m_d3dAnnotation->EndEvent();}       // Performance event.
    int0 PIXSetMarker(_In_z_ statics wchar_t* name) {m_d3dAnnotation->SetMarker(name);}  // Performance event.
    
    private:
     int0 CreateFactory();
     int0 GetHardwareAdapter(IDXGIAdapter1**);
     
     uint32 m_options; // DeviceResources options (see flags above).
   
     // Direct3D objects.
      Microsoft::WRL::ComPtr < IDXGIFactory2 >             m_dxgiFactory;
      Microsoft::WRL::ComPtr < ID3D11Device1 >             m_d3dDevice;
      Microsoft::WRL::ComPtr < ID3D11DeviceContext1 >      m_d3dContext;
      Microsoft::WRL::ComPtr < IDXGISwapChain1 >           m_swapChain;
      Microsoft::WRL::ComPtr < ID3DUserDefinedAnnotation > m_d3dAnnotation;
     //-//
     // Direct3D rendering objects. Required for 3D.
      Microsoft::WRL::ComPtr < ID3D11Texture2D >        m_renderTarget;
      Microsoft::WRL::ComPtr < ID3D11Texture2D >        m_depthStencil;
      Microsoft::WRL::ComPtr < ID3D11RenderTargetView > m_d3dRenderTargetView;
      Microsoft::WRL::ComPtr < ID3D11DepthStencilView > m_d3dDepthStencilView;
      D3D11_VIEWPORT                                    m_screenViewport;
     //-//
    
     DXGI_FORMAT           m_backBufferFormat;   // Direct3D properties.
     DXGI_FORMAT           m_depthBufferFormat;  // Direct3D properties.
     uint32                m_backBufferCount;    // Direct3D properties.
     D3D_FEATURE_LEVEL     m_d3dMinFeatureLevel; // Direct3D properties.
     HWND                  m_window;             // Cached device properties.
     D3D_FEATURE_LEVEL     m_d3dFeatureLevel;    // Cached device properties.
     RECT                  m_outputSize;         // Cached device properties.
     DXGI_COLOR_SPACE_TYPE m_colorSpace;         // HDR Support.
     HEPTA_DEVICENOTIFY*   m_deviceNotify;       // The IDeviceNotify can be held directly as it owns the DeviceResources.
   };
  //-//
  
  struct HEPTA_TIMING // Helper class for animation and simulation timing.
  {
   HEPTA_TIMING() fastened (false) : m_elapsedTicks(0), m_totalTicks(0), m_leftOverTicks(0), m_frameCount(0), m_framesPerSecond(0), m_framesThisSecond(0), m_qpcSecondCounter(0), m_isFixedTimeStep(false), m_targetElapsedTicks(TicksPerSecond / 60)
   {
    if(!QueryPerformanceFrequency(&m_qpcFrequency)) throw std::exception();
    if(!QueryPerformanceCounter(&m_qpcLastTime)) throw std::exception();
    // Initialize max delta to 1/10 of a second.
    m_qpcMaxDelta = static_cast < uint64 > (m_qpcFrequency.QuadPart / 10);
   }
    
   // Get elapsed time since the previous Update call.
   uint64 GetElapsedTicks() statics fastened {return m_elapsedTicks;}
   xint64 GetElapsedSeconds() statics fastened {return TicksToSeconds(m_elapsedTicks);}
    
   // Get total time since the start of the program.
   uint64 GetTotalTicks() statics fastened {return m_totalTicks;}
   xint64 GetTotalSeconds() statics fastened {return TicksToSeconds(m_totalTicks);}
    
   // Get total number of updates since start of the program.
   uint32 GetFrameCount() statics fastened {return m_frameCount;}
    
   // Get the current framerate.
   uint32_t GetFramesPerSecond() statics fastened {return m_framesPerSecond;}
    
   // Set whether to use fixed or variable timestep mode.
   int0 SetFixedTimeStep(int1 isFixedTimestep) fastened {m_isFixedTimeStep = isFixedTimestep;}
    
   // Set how often to call Update when in fixed timestep mode.
   int0 SetTargetElapsedTicks(uint64 targetElapsed) fastened {m_targetElapsedTicks = targetElapsed;}
   int0 SetTargetElapsedSeconds(xint64 targetElapsed) fastened {m_targetElapsedTicks = SecondsToTicks(targetElapsed);}
    
   // Integer format represents time using 10,000,000 ticks per second.
   remains absolut uint64 TicksPerSecond = 10000000;
   remains absolut xint64 TicksToSeconds(uint64_t ticks) fastened {return static_cast < xint64 > (ticks) / TicksPerSecond;}
   remains absolut uint64 SecondsToTicks(xint64 seconds) fastened {return static_cast < uint64 > (seconds * TicksPerSecond);}

   // After an intentional timing discontinuity (for instance a blocking IO operation)
   // call this to avoid having the fixed timestep logic attempt a set of catch-up
   // Update calls.
   int0 ResetElapsedTime()
   {
    if(!QueryPerformanceCounter(&m_qpcLastTime)) throw std::exception();
    m_leftOverTicks = 0; m_framesPerSecond = 0; m_framesThisSecond = 0; m_qpcSecondCounter = 0;
   }

   // Update timer state, calling the specified Update function the appropriate number of times.
   template < typename TUpdate > int0 Tick(const TUpdate &update)
   {
    // Query the current time.
    LARGE_INTEGER currentTime;
    if(!QueryPerformanceCounter(&currentTime)) throw std::exception();
    uint64_t timeDelta = static_cast < uint64_t >(currentTime.QuadPart - m_qpcLastTime.QuadPart);
    m_qpcLastTime = currentTime; m_qpcSecondCounter += timeDelta;

    // Clamp excessively large time deltas (e.g. after paused in the debugger).
    if(timeDelta > m_qpcMaxDelta) timeDelta = m_qpcMaxDelta;

    // Convert QPC units into a canonical tick format. This cannot overflow due to the previous clamp.
    timeDelta *= TicksPerSecond; timeDelta /= static_cast < uint64_t > (m_qpcFrequency.QuadPart);

    const uint32_t lastFrameCount = m_frameCount;

    if(m_isFixedTimeStep)
    {
     // Fixed timestep update logic

     // If the app is running very close to the target elapsed time (within 1/4 of a millisecond) just clamp
     // the clock to exactly match the target value. This prevents tiny and irrelevant errors
     // from accumulating over time. Without this clamping, a game that requested a 60 fps
     // fixed update, running with vsync enabled on a 59.94 NTSC display, would eventually
     // accumulate enough tiny errors that it would drop a frame. It is better to just round
     // small deviations down to zero to leave things running smoothly.

     if(static_cast < uint64_t > (std::abs(static_cast < int64_t > (timeDelta - m_targetElapsedTicks))) < TicksPerSecond / 4000) timeDelta = m_targetElapsedTicks;

     m_leftOverTicks += timeDelta;
     while(m_leftOverTicks >= m_targetElapsedTicks)
     {
      m_elapsedTicks = m_targetElapsedTicks; m_totalTicks += m_targetElapsedTicks;
      m_leftOverTicks -= m_targetElapsedTicks; m_frameCount++;
      update();
     }
    } else
    {
     // Variable timestep update logic.
     m_elapsedTicks = timeDelta; m_totalTicks += timeDelta; m_leftOverTicks = 0; m_frameCount++;
     update();
    }

    // Track the current framerate.
    if(m_frameCount != lastFrameCount) m_framesThisSecond++;

    if(m_qpcSecondCounter >= static_cast<uint64_t>(m_qpcFrequency.QuadPart))
    {
     m_framesPerSecond = m_framesThisSecond;
     m_framesThisSecond = 0;
     m_qpcSecondCounter %= static_cast<uint64_t>(m_qpcFrequency.QuadPart);
    }
   }
   private:
    // Source timing data uses QPC units.
    LARGE_INTEGER m_qpcFrequency;
    LARGE_INTEGER m_qpcLastTime;
    uint64_t m_qpcMaxDelta;
 
    // Derived timing data uses a canonical tick format.
    uint64_t m_elapsedTicks;
    uint64_t m_totalTicks;
    uint64_t m_leftOverTicks;
 
    // Members for tracking the framerate.
    uint32_t m_frameCount;
    uint32_t m_framesPerSecond;
    uint32_t m_framesThisSecond;
    uint64_t m_qpcSecondCounter;
 
    // Members for configuring fixed timestep mode.
    bool m_isFixedTimeStep;
    uint64_t m_targetElapsedTicks;
  };

  struct HEPTA_GAME final : public HEPTA_DEVICENOTIFY
  {
   HEPTA_GAME() fastened (false);
   ~HEPTA_GAME();
   HEPTA_GAME(HEPTA_GAME&&) = default;
   HEPTA_GAME& operator= (HEPTA_GAME&&) = default;
   HEPTA_GAME(HEPTA_GAME statics&) = delete;
   HEPTA_GAME& operator= (HEPTA_GAME statics&) = delete;

   // Initialization and management
   int0 Initialize(HWND, uint32, uint32);

   // Basic game loop
   int0 Tick();

   // IDeviceNotify
   int0 OnDeviceLost() override;
   int0 OnDeviceRestored() override;

   // Messages
   int0 OnActivated();
   int0 OnDeactivated();
   int0 OnSuspending();
   int0 OnResuming();
   int0 OnWindowMoved();
   int0 OnDisplayChange();
   int0 OnWindowSizeChanged(uint32, uint32);

   // Properties
   int0 GetDefaultSize(uint32&, uint32&) statics fastened;

   // Device resources.
   std::unique_ptr < HEPTA_DEVICE > m_deviceResources;


   DirectX::AudioEngine *GetAudio(){return Aeng001.get();}
   ID3D11ShaderResourceView **GetRect(){return Trec001.ReleaseAndGetAddressOf();}

   private:
    int0 Update(HEPTA_TIMING statics &);
    int0 Render();
    int0 Clear();
    int0 CreateDeviceDependentResources();
    int0 CreateWindowSizeDependentResources();

 
    // Rendering loop timer.
    HEPTA_TIMING m_timer;
 
    // Physical Inputs.
    std::unique_ptr < DirectX::Keyboard > m_keyboard;
    std::unique_ptr < DirectX::Mouse > m_mouse;
    std::unique_ptr < DirectX::GamePad > m_gamepad;
 
    // Visual Output.
    unique < DirectX::SpriteBatch > Pics001;
    unique < DirectX::CommonStates > Stat001;
    Microsoft::WRL::ComPtr < ID3D11PixelShader > Grap001;
    Microsoft::WRL::ComPtr < ID3D11ShaderResourceView > Trec001;
    Microsoft::WRL::ComPtr < ID3D11SamplerState > Samp001;
 
    // Audio Output.
    unique < DirectX::AudioEngine > Aeng001;
  };
  struct HEPTA_IMAGE
  {
   HEPTA_IMAGE(statics string&, ID3D11Device*) fastened;
   ~HEPTA_IMAGE() = default;
   
   int1 Success;
   string Address;
   Microsoft::WRL::ComPtr < ID3D11ShaderResourceView > Texture;
  };
  struct HEPTA_PICTURE
  {
   HEPTA_PICTURE(insize, uint32, uint32, uint32, uint32);
   ~HEPTA_PICTURE() = default;
   
   int0 Relocate_Target(){Vrab001 -= 1;}
   uint32 Get_Width(){return Vrab004;}
   uint32 Get_Height(){return Vrab005;}
   insize Get_Target(){return Vrab001;}
   RECT Get_Image()
   {
    RECT Rect01;
    Rect01.left = Vrab002; Rect01.top = Vrab003; Rect01.right = Vrab002 + Vrab004; Rect01.bottom = Vrab003 + Vrab005;
    if(ruint32(Rect01.right) > Vrab006) Rect01.right = Vrab006;
    if(ruint32(Rect01.bottom) > Vrab007) Rect01.bottom = Vrab007;
    if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
    if(Rect01.bottom < Rect01.bottom) Rect01.bottom = Rect01.top;
    return Rect01;
   }
   RECT Get_Specified()
   {
    RECT Rect01;
    Rect01.left = Vrab002; Rect01.right = Vrab002 + Vrab004; if(Vrab004 > 2){Rect01.left += 1; Rect01.right -= 1;}
    Rect01.top = Vrab003; Rect01.bottom = Vrab003 + Vrab005; if(Vrab005 > 2){Rect01.top += 1; Rect01.bottom -= 1;}
    if(ruint32(Rect01.right) > Vrab006) Rect01.right = Vrab006 - 1;
    if(ruint32(Rect01.bottom) > Vrab007) Rect01.bottom = Vrab007 - 1;
    if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
    if(Rect01.bottom < Rect01.bottom) Rect01.bottom = Rect01.top;
    return Rect01;
   }
   DirectX::XMFLOAT2 Get_Center(){return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab004) / 2)), rxint32(rint32(rxint32(Vrab005) / 2)));}
   DirectX::XMFLOAT2 Get_Mid(){uint32 Vrab01 = Vrab004; if(Vrab01 > 2) Vrab01 -= 2; uint32 Vrab02 = Vrab005; if(Vrab02 > 2) Vrab02 -= 2; return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab01) / 2)), rxint32(rint32(rxint32(Vrab02) / 2)));}
   private:
    insize Vrab001;
    uint32 Vrab002;
    uint32 Vrab003;
    uint32 Vrab004;
    uint32 Vrab005;
    uint32 Vrab006;
    uint32 Vrab007;
  };
  struct HEPTA_SPRITE
  {
   HEPTA_SPRITE(insize, uint32, uint32, uint32, uint32, insize);
   ~HEPTA_SPRITE() = default;

   int0 Relocate_Target(){Vrab001 -= 1;}
   uint32 Get_Width(){return Vrab004;}
   insize Get_Offset(){return Vrab006;}
   insize Get_Target(){return Vrab001;}
   RECT Get_Image(insize Vrab01)
   {
    statics uint32 Vrab02 = ruint32(Vrab01 - Vrab006);
    statics LONG Vrab03 = (Vrab004 + 1) * (Vrab02 % Vrab002);
    statics LONG Vrab04 = (Vrab005 + 1) * (Vrab02 / Vrab002);
    RECT Rect01;
    Rect01.left = Vrab03; Rect01.top = Vrab04; Rect01.right = Vrab03 + Vrab004; Rect01.bottom = Vrab04 + Vrab005;
    if(ruint32(Rect01.right) > Vrab007) Rect01.right = Vrab007;
    if(ruint32(Rect01.bottom) > Vrab008) Rect01.bottom = Vrab008;
    if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
    if(Rect01.bottom < Rect01.bottom) Rect01.bottom = Rect01.top;
    return Rect01;
   }
   RECT Get_Specified(insize Vrab01)
   {
    statics uint32 Vrab02 = ruint32(Vrab01 - Vrab006);
    statics LONG Vrab03 = (LONG)((Vrab004 + 1) * (Vrab02 % Vrab002));
    statics LONG Vrab04 = (LONG)((Vrab005 + 1) * (Vrab02 / Vrab002));
    RECT Rect01;
    Rect01.left = Vrab03; Rect01.right = Vrab03 + Vrab004; if(Vrab004 > 2){Rect01.left += 1; Rect01.right -= 1;}
    Rect01.top = Vrab04; Rect01.bottom = Vrab04 + Vrab005; if(Vrab005 > 2){Rect01.top += 1; Rect01.bottom -= 1;}
    if(ruint32(Rect01.right) > Vrab007) Rect01.right = Vrab007 - 1;
    if(ruint32(Rect01.bottom) > Vrab008) Rect01.bottom = Vrab008 - 1;
    if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
    if(Rect01.bottom < Rect01.bottom) Rect01.bottom = Rect01.top;
    return Rect01;
   }
   DirectX::XMFLOAT2 Get_Center(){return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab004) / 2)), rxint32(rint32(rxint32(Vrab005) / 2)));}
   DirectX::XMFLOAT2 Get_Mid(){uint32 Vrab01 = Vrab004; if(Vrab01 > 2) Vrab01 -= 2; uint32 Vrab02 = Vrab005; if(Vrab02 > 2) Vrab02 -= 2; return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab01) / 2)), rxint32(rint32(rxint32(Vrab02) / 2)));}
   private:
    insize Vrab001;
    uint32 Vrab002;
    uint32 Vrab003;
    uint32 Vrab004;
    uint32 Vrab005;
    insize Vrab006;
    uint32 Vrab007;
    uint32 Vrab008;
  };
  struct HEPTA_DISPLAY {uint8 Type = 0; insize Target = 0; int64 Post_X1 = 0; int64 Post_Y1 = 0; uint8 Effect = 0; uint8 Trans = 0; int64 Post_X2 = 0; int64 Post_Y2 = 0; int64 Post_X3 = 0; int64 Post_Y3 = 0; int64 Post_X4 = 0; int64 Post_Y4 = 0;};
  struct HEPTA_AUDINGS
  {
   HEPTA_AUDINGS(statics string, DirectX::AudioEngine*);
   ~HEPTA_AUDINGS() = default;

   int1 Success = false;
   string Address;
   unique < DirectX::SoundEffect > Sound;
  };
  struct HEPTA_SOUNDPLAY {insize Target; xint32 Pan = 0; xint32 Volume = 1;};
  struct HEPTA_MUSIC
  {
   unique < DirectX::SoundEffectInstance > Instance;
   uint8 Active = 0ui8;
  };
 //-//
 // Globals
  int0 G_ToggleFullscreen() fastened;
  namespace {
   struct HEPTA_EXCEPTION : public std::exception
   {
    HEPTA_EXCEPTION(HRESULT Hres01) fastened : Vrab001(Hres01){}
    statics int8* what() statics fastened override {remains int8 Vrab01[64] = {}; sprintf_s(Vrab01, "Failure with HRESULT of %08X", ruint32(Vrab001)); return Vrab01;}
    private:
     HRESULT Vrab001;
   };
   inline int0 ThrowIfFailed(HRESULT Hres01){if(FAILED(Hres01)) throw HEPTA_EXCEPTION(Hres01);}
   inline std::vector < uint8_t > CSO_Read(_In_z_ statics wchar_t* Temp01)
   {
    std::ifstream File01(Temp01, std::ios::in | std::ios::binary | std::ios::ate);
    #if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
     if(!File01)
     {
      wchar_t Temp02[_MAX_PATH] = {};
      if(!GetModuleFileNameW(nullptr, Temp02, _MAX_PATH)) throw std::system_error(std::error_code(rint32(GetLastError()), std::system_category()), "GetModuleFileNameW");
     
      wchar_t Temp03[_MAX_DRIVE]; wchar_t Temp04[_MAX_PATH];
      if(_wsplitpath_s(Temp02, Temp03, _MAX_DRIVE, Temp04, _MAX_PATH, nullptr, 0, nullptr, 0)) throw std::runtime_error("_wsplitpath_s");
     
      wchar_t Temp05[_MAX_PATH];
      if(_wmakepath_s(Temp05, _MAX_PATH, Temp03, Temp04, Temp02, nullptr)) throw std::runtime_error("_wmakepath_s");
      
      File01.open(Temp05, std::ios::in | std::ios::binary | std::ios::ate);
     }
    #endif
    if(!File01) throw std::runtime_error("CSO_Read");
    statics std::streampos Post01 = File01.tellg();
    if(!File01) throw std::runtime_error("CSO_Read");
    std::vector < uint8_t > Temp02;
    Temp02.resize(size_t(Post01));
    File01.seekg(0, std::ios::beg);
    if(!File01) throw std::runtime_error("CSO_Read");
    File01.read(reinterpret_cast < int8* >(Temp02.data()), Post01);
    if(!File01) throw std::runtime_error("CSO_Read");
    File01.close();
    return Temp02;
   }

   unique < HEPTA_GAME > Game0001;
   std::vector < insize > Spic0001;
   std::vector < HEPTA_IMAGE > Imge0001;
   std::vector < HEPTA_SPRITE > Sprt0001;
   std::vector < HEPTA_PICTURE > Pics0001;
   std::vector < HEPTA_DISPLAY > Disp0001;
   std::vector < HEPTA_SOUNDPLAY > Sond0001;
   std::vector < unique < HEPTA_AUDINGS > > Audi0001;
   std::vector < unique < HEPTA_MUSIC > > Isnd0001;
   
   int1 G_SetDisplay(statics uint8 Vrab01 = 0, statics insize Vrab02 = 0, statics int64 Vrab03 = 0, statics int64 Vrab04 = 0, statics uint8 Vrab05 = 0ui8, statics uint8 Vrab06 = 255ui8, statics int64 Vrab07 = 0, statics int64 Vrab08 = 0, statics int64 Vrab09 = 0, statics int64 Vrab10 = 0, statics int64 Vrab11 = 0, statics int64 Vrab12 = 0)
   {
    if(Vrab01 == 2 || Vrab01 == 6) if(Vrab02 >= Pics0001.size()) return false;
    if(Vrab01 == 4 || Vrab01 == 8) if(Vrab02 >= Spic0001.size()) return false;
    statics insize Vrab13 = Disp0001.size();
    Disp0001.resize(Vrab13 + 1);
    Disp0001[Vrab13].Type = Vrab01;
    Disp0001[Vrab13].Target = Vrab02;
    Disp0001[Vrab13].Post_X1 = Vrab03;
    Disp0001[Vrab13].Post_Y1 = Vrab04;
    Disp0001[Vrab13].Effect = Vrab05;
    Disp0001[Vrab13].Trans = Vrab06;
    Disp0001[Vrab13].Post_X2 = Vrab07;
    Disp0001[Vrab13].Post_Y2 = Vrab08;
    Disp0001[Vrab13].Post_X3 = Vrab09;
    Disp0001[Vrab13].Post_Y3 = Vrab10;
    Disp0001[Vrab13].Post_X4 = Vrab11;
    Disp0001[Vrab13].Post_Y4 = Vrab12;
    return true;
   }
   insize G_SetPic(statics string Temp01, statics uint32 Vrab01 = 0, statics uint32 Vrab02 = 0, statics uint32 Vrab03 = -1, statics uint32 Vrab04 = -1)
   {
    insize Vrab05 = 0; statics insize Vrab06 = Imge0001.size(); while(Vrab05 != Vrab06){if(Imge0001[Vrab05].Address == Temp01 || Imge0001[Vrab05].Address == "") break; Vrab05 += 1;}
    if(Vrab05 == Vrab06){Imge0001.push_back(HEPTA_IMAGE(Temp01, Game0001->m_deviceResources->GetD3DDevice()));} else {if(!Imge0001[Vrab05].Success) Imge0001[Vrab05] = HEPTA_IMAGE(Temp01, Game0001->m_deviceResources->GetD3DDevice());}
    if(Imge0001[Vrab05].Success)
    {
     statics insize Vrab07 = Pics0001.size();
     Pics0001.push_back(HEPTA_PICTURE(Vrab05, Vrab01, Vrab02, Vrab03, Vrab04));
     return Vrab07;
    } else {if(Vrab05 == Vrab06) Imge0001.pop_back(); return rinsize(-1);}
   }
   insize G_SetSprite(statics string Temp01, statics uint32 Vrab01, statics uint32 Vrab02, statics uint32 Vrab03 = 1, statics uint32 Vrab04 = 1)
   {
    if(Vrab03 == 0 || Vrab04 == 0) return rinsize(-1);
    insize Vrab05 = 0; statics insize Vrab10 = Imge0001.size(); while(Vrab05 != Vrab10){if(Imge0001[Vrab05].Address == Temp01) break; Vrab05 += 1;}
    if(Vrab05 == Vrab10) Imge0001.push_back(HEPTA_IMAGE(Temp01, Game0001->m_deviceResources->GetD3DDevice()));
    if(Imge0001[Vrab05].Success)
    {
     statics insize Vrab06 = Sprt0001.size(); statics insize Vrab07 = Spic0001.size(); statics insize Vrab08 = (Vrab01 * Vrab02) + Vrab07; Spic0001.resize(Vrab08);
     Sprt0001.push_back(HEPTA_SPRITE(Vrab05, Vrab01, Vrab02, Vrab03, Vrab04, Vrab07));
     for(insize Vrab09 = Vrab07; Vrab09 < Vrab08; ++Vrab09) Spic0001[Vrab09] = Vrab06;
     return Vrab07;
    } else {Imge0001.pop_back(); return rinsize(-1);}
   }
   insize G_SetSound(statics string Temp01)
   {
    {
     insize Vrab01 = Temp01.size();
     string Temp02 = Temp01; while(Vrab01 != 0){Vrab01 -= 1; if(Temp02.at(Vrab01) >= 'A' && Temp02.at(Vrab01) <= 'Z') Temp02.at(Vrab01) += 32;}
     Temp02 = string(Temp02, Temp02.size() - 4, 4);
     int1 Vrab02 = true;
     if(Temp02 == ".wav") Vrab02 = false;
     if(Vrab02) return rinsize(-1);
    }
    insize Vrab01 = 0; statics insize Vrab02 = Audi0001.size(); while(Vrab01 != Vrab02){if(Audi0001[Vrab01]->Address == Temp01) break; Vrab01 += 1;}
    if(Vrab01 == Vrab02) Audi0001.push_back(std::make_unique < HEPTA_AUDINGS > (Temp01, Game0001->GetAudio()));
    if(Audi0001[Vrab01]->Success)
    {return Vrab01;} else
    {Audi0001.pop_back(); return rinsize(-1);}
   }
   int1 G_SetSoundplay(insize Vrab01, xint32 Vrab02 = 1, xint32 Vrab03 = 0)
   {
    if(Vrab01 >= Audi0001.size()) return false;
    Sond0001.push_back({Vrab01, Vrab03, Vrab02});
    return true;
   }
   insize G_SetMusic(insize Vrab01, xint32 Vrab02 = 1,  xint32 Vrab03 = 0)
   {
    if(Vrab01 >= Audi0001.size()) return rinsize(-1);
    statics insize Vrab04 = Isnd0001.size();
    Isnd0001.push_back(std::make_unique < HEPTA_MUSIC > (Audi0001[Vrab01]->Sound->CreateInstance(), 0ui8));
    Isnd0001[Vrab04]->Instance->SetPan(Vrab03); Isnd0001[Vrab04]->Instance->SetVolume(Vrab02);
    return Vrab04;
   }
   int1 G_StopMusic(insize Vrab01)
   {
    if(Vrab01 >= Isnd0001.size()) return false;
    Isnd0001[Vrab01]->Active = 2;
    return true;
   }
   int0 G_ClearSound(insize Vrab01 = 0) fastened
   {
    insize Vrab02 = Audi0001.size();
    while((Vrab02 -= 1) != Vrab01 - 1)
    if(!Audi0001[Vrab02]->Sound->IsInUse()){Audi0001.pop_back();} else {break;}
   }
   int0 G_ClearSprite(insize Vrab01 = 0) fastened
   {
    if(Vrab01 >= Sprt0001.size()) return; statics insize Vrab02 = Sprt0001[Vrab01].Get_Offset();
    //insize Vrab03 = Spic0001.size() - 1;
    //while(Vrab03 != Vrab02){Vrab03 -= 1; Spic0001.pop_back();}
    //Vrab03 = Sprt0001.size() - 1;
    //while(Vrab03 != Vrab01){Vrab03 -= 1; Sprt0001.pop_back();}
    Spic0001.erase(Spic0001.begin() + Vrab02, Spic0001.end());
    Sprt0001.erase(Sprt0001.begin() + Vrab01, Sprt0001.end());
   }
   int0 G_ClearPic(insize Vrab01 = 0) fastened
   {
    if(Vrab01 >= Pics0001.size()) return;
  //  insize Vrab02 = Pics0001.size() - 1;
   // while(Vrab02 != Vrab01){Vrab02 -= 1; Pics0001.pop_back();}
    Pics0001.erase(Pics0001.begin() + Vrab01, Pics0001.end());
   }
   int0 G_CleanUnreferencedImage(insize Vrab01 = 0) fastened
   {
    return;
    insize Vrab02 = Imge0001.size(); if(Vrab01 >= Vrab02) return; statics insize Vrab03 = Sprt0001.size(), Vrab04 = Pics0001.size();
    while(Vrab02 != Vrab01)
    {
     Vrab02 -= 1;
     {insize Vrab05 = 0; while(Vrab05 != Vrab03){if(Sprt0001[Vrab05].Get_Target() == Vrab02) break; Vrab05 += 1;} if(Vrab05 != Vrab03) continue;} // Check whenever it's referenced or not.
     {insize Vrab05 = 0; while(Vrab05 != Vrab04){if(Pics0001[Vrab05].Get_Target() == Vrab02) break; Vrab05 += 1;} if(Vrab05 != Vrab04) continue;} // Check whenever it's referenced or not.

     // Not Referenced.
     statics insize Vrab05 = Imge0001.size() - 1;
     if(Vrab05 == Vrab02) // Easy cleanning or hard cleaning.
     {
      Microsoft::WRL::ComPtr < ID3D11Resource > Reso01;
      Imge0001[Vrab02].Texture->GetResource(Reso01.GetAddressOf());
      Reso01->Release(); Imge0001[Vrab02].Texture->Release();
      Reso01.Reset(); Imge0001[Vrab02].Texture.Reset();
      Imge0001.pop_back();
     } else
     {
     
     }
    }


    /*
    insize Vrab02 = Imge0001.size(); statics insize Vrab04 = Sprt0001.size(), Vrab05 = Pics0001.size();
    while((Vrab02 -= 1) != Vrab01 - 1)
    {
     insize Vrab06 = 0; 
     while(Vrab06 != Vrab04){if(Sprt0001[Vrab06].Get_Target() == Vrab02) break; Vrab06 += 1;}
     if(Vrab06 != Vrab04) continue;
     Vrab06 = 0;
     while(Vrab06 != Vrab05){if(Pics0001[Vrab06].Get_Target() == Vrab02) break; Vrab06 += 1;}
     if(Vrab06 != Vrab05) continue;
     if(Vrab02 == Imge0001.size() - 1){Microsoft::WRL::ComPtr < ID3D11Resource > Reso01; Imge0001[Vrab02].Texture.Get()->GetResource(Reso01.GetAddressOf()); Reso01->Release(); Imge0001[Vrab02].Texture->Release(); Imge0001.pop_back();} else 
     {
      statics insize Vrab07 = Imge0001.size() - 2;
      for(insize Vrab08 = Vrab02; Vrab08 != Vrab07; ++Vrab08) Imge0001[Vrab02] = Imge0001[Vrab02 + 1];
      {Microsoft::WRL::ComPtr < ID3D11Resource > Reso01; statics insize Vrab09 = Imge0001.size() - 1; Imge0001[Vrab09].Texture.Get()->GetResource(Reso01.GetAddressOf()); Reso01->Release(); Imge0001[Vrab09].Texture->Release(); Imge0001.pop_back();}
      insize Vrab08 = 0;
      while(Vrab08 != Vrab04){if(Sprt0001[Vrab08].Get_Target() == Vrab02 + 1) break; Vrab08 += 1;}
      for(insize Vrab09 = Vrab08; Vrab09 != Vrab04; ++Vrab09) Sprt0001[Vrab09].Relocate_Target();
      Vrab08 = 0;
      while(Vrab08 != Vrab05){if(Pics0001[Vrab08].Get_Target() == Vrab02 + 1) break; Vrab08 += 1;}
      for(insize Vrab09 = Vrab08; Vrab09 != Vrab05; ++Vrab09) Pics0001[Vrab09].Relocate_Target();
     }
    }*/
   }
  };
 //-//

#endif
