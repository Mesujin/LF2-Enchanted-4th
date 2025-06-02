////////////////////////////////////////////////////////////////////////////////////////////
// "platform.h", based on DirectXTK's template.                                           //
//                                                                                        //
// Header of the platform.                                                                //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef _HEPTA_PRAGMA_PLATFORM_H
 #define _HEPTA_PRAGMA_PLATFORM_H
 
 // Commands
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

  using int0   = void;               // -
  using int1   = bool;               // I know, it's not 1 byte.
  using int8   = char;               // -
  using int16  = short;              // -
  using int32  = int;                // -
  using int64  = long long;          // -
  using sint8  = signed char;        // -
  using sint16 = signed short;       // -
  using sint32 = signed int;         // -
  using sint64 = signed long long;   // -
  using lint32 = long;               // -
  using uint8  = unsigned char;      // -
  using uint16 = unsigned short;     // -
  using uint32 = unsigned int;       // -
  using uint64 = unsigned long long; // -
  using xint32 = float;              // -
  using xint64 = double;             // -
  using string = std::string;        // -
  using stream = std::stringstream;  // -
  using insize = size_t;             // Vector's maximum size.

  #define unique std::unique_ptr

  #define rint1   static_cast < int1 >
  #define rint8   static_cast < int8 >
  #define rint16  static_cast < int16 >
  #define rint32  static_cast < int32 >
  #define rint64  static_cast < int64 >
  #define rsint8  static_cast < sint8 >
  #define rsint16 static_cast < sint16 >
  #define rsint32 static_cast < sint32 >
  #define rsint64 static_cast < sint64 >
  #define rlint32 static_cast < lint32 >
  #define ruint8  static_cast < uint8 >
  #define ruint16 static_cast < uint16 >
  #define ruint32 static_cast < uint32 >
  #define ruint64 static_cast < uint64 >
  #define rxint32 static_cast < xint32 >
  #define rxint64 static_cast < xint64 >
  #define rinsize static_cast < insize >

  #define remains static
  #define written constexpr
  #define statics const
  #define univers virtual
  #define stacked inline
  #define perfect noexcept

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
    remains written uint32 c_FlipPresent  = 0x1;
    remains written uint32 c_AllowTearing = 0x2;
    remains written uint32 c_EnableHDR    = 0x4;
    
    HEPTA_DEVICE(DXGI_FORMAT, DXGI_FORMAT, uint32, D3D_FEATURE_LEVEL, uint32) perfect;
    ~HEPTA_DEVICE() = default;
    HEPTA_DEVICE(HEPTA_DEVICE&&) = default;
    HEPTA_DEVICE& operator= (HEPTA_DEVICE&&) = default;
    HEPTA_DEVICE(HEPTA_DEVICE statics&) = delete;
    HEPTA_DEVICE& operator= (HEPTA_DEVICE statics&) = delete;
    
    int0 CreateDeviceResources();
    int0 CreateWindowSizeDependentResources();
    int0 SetWindow(HWND, uint32, uint32) perfect;
    int0 HandleDeviceLost();
    int0 RegisterDeviceNotify(HEPTA_DEVICENOTIFY* deviceNotify) perfect {m_deviceNotify = deviceNotify;}
    int0 Present();
    int0 UpdateColorSpace();
    int1 WindowSizeChanged(uint32, uint32);
    
    RECT                    GetOutputSize()         statics perfect {return m_outputSize;}                // Device accessor.
    auto                    GetD3DDevice()          statics perfect {return m_d3dDevice.Get();}           // Direct3D Accessors.
    auto                    GetD3DDeviceContext()   statics perfect {return m_d3dContext.Get();}          // Direct3D Accessors.
    auto                    GetSwapChain()          statics perfect {return m_swapChain.Get();}           // Direct3D Accessors.
    auto                    GetDXGIFactory()        statics perfect {return m_dxgiFactory.Get();}         // Direct3D Accessors.
    HWND                    GetWindow()             statics perfect {return m_window;}                    // Direct3D Accessors.
    D3D_FEATURE_LEVEL       GetDeviceFeatureLevel() statics perfect {return m_d3dFeatureLevel;}           // Direct3D Accessors.
    ID3D11Texture2D*        GetRenderTarget()       statics perfect {return m_renderTarget.Get();}        // Direct3D Accessors.
    ID3D11Texture2D*        GetDepthStencil()       statics perfect {return m_depthStencil.Get();}        // Direct3D Accessors.
    ID3D11RenderTargetView* GetRenderTargetView()   statics perfect {return m_d3dRenderTargetView.Get();} // Direct3D Accessors.
    ID3D11DepthStencilView* GetDepthStencilView()   statics perfect {return m_d3dDepthStencilView.Get();} // Direct3D Accessors.
    DXGI_FORMAT             GetBackBufferFormat()   statics perfect {return m_backBufferFormat;}          // Direct3D Accessors.
    DXGI_FORMAT             GetDepthBufferFormat()  statics perfect {return m_depthBufferFormat;}         // Direct3D Accessors.
    D3D11_VIEWPORT          GetScreenViewport()     statics perfect {return m_screenViewport;}            // Direct3D Accessors.
    UINT                    GetBackBufferCount()    statics perfect {return m_backBufferCount;}           // Direct3D Accessors.
    DXGI_COLOR_SPACE_TYPE   GetColorSpace()         statics perfect {return m_colorSpace;}                // Direct3D Accessors.
    uint32                  GetDeviceOptions()      statics perfect {return m_options;}                   // Direct3D Accessors.
    
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

  struct HEPTA_TIMING // Helper class for animation and simulation timing.
  {
   HEPTA_TIMING() perfect (false) : m_elapsedTicks(0), m_totalTicks(0), m_leftOverTicks(0), m_frameCount(0), m_framesPerSecond(0), m_framesThisSecond(0), m_qpcSecondCounter(0), m_isFixedTimeStep(false), m_targetElapsedTicks(TicksPerSecond / 60)
   {
    if(!QueryPerformanceFrequency(&m_qpcFrequency)) throw std::exception();
    if(!QueryPerformanceCounter(&m_qpcLastTime)) throw std::exception();
    // Initialize max delta to 1/10 of a second.
    m_qpcMaxDelta = static_cast < uint64 > (m_qpcFrequency.QuadPart / 10);
   }
    
   // Get elapsed time since the previous Update call.
   uint64 GetElapsedTicks() statics perfect {return m_elapsedTicks;}
   xint64 GetElapsedSeconds() statics perfect {return TicksToSeconds(m_elapsedTicks);}
    
   // Get total time since the start of the program.
   uint64 GetTotalTicks() statics perfect {return m_totalTicks;}
   xint64 GetTotalSeconds() statics perfect {return TicksToSeconds(m_totalTicks);}
    
   // Get total number of updates since start of the program.
   uint32 GetFrameCount() statics perfect {return m_frameCount;}
    
   // Get the current framerate.
   uint32_t GetFramesPerSecond() statics perfect {return m_framesPerSecond;}
    
   // Set whether to use fixed or variable timestep mode.
   int0 SetFixedTimeStep(int1 isFixedTimestep) perfect {m_isFixedTimeStep = isFixedTimestep;}
    
   // Set how often to call Update when in fixed timestep mode.
   int0 SetTargetElapsedTicks(uint64 targetElapsed) perfect {m_targetElapsedTicks = targetElapsed;}
   int0 SetTargetElapsedSeconds(xint64 targetElapsed) perfect {m_targetElapsedTicks = SecondsToTicks(targetElapsed);}
    
   // Integer format represents time using 10,000,000 ticks per second.
   remains written uint64 TicksPerSecond = 10000000;
   remains written xint64 TicksToSeconds(uint64_t ticks) perfect {return static_cast < xint64 > (ticks) / TicksPerSecond;}
   remains written uint64 SecondsToTicks(xint64 seconds) perfect {return static_cast < uint64 > (seconds * TicksPerSecond);}

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
  struct HEPTA_IMAGE
  {
   HEPTA_IMAGE(statics string&, ID3D11Device*) perfect;
   
   int1 Success = false;
   string Address;
   ID3D11Resource *Data = nullptr;
   ID3D11ShaderResourceView *Texture = nullptr;
  };
  struct HEPTA_PICTURE
  {
   HEPTA_PICTURE(insize, uint32, uint32, uint32, uint32);
   
   int0   Relocate_Target() perfect {Vrab001 -= 1;}
   uint32 Get_Width()       perfect {return Vrab004;}
   uint32 Get_Height()      perfect {return Vrab005;}
   insize Get_Target()      perfect {return Vrab001;}
   RECT Get_Image()         perfect 
   {
    RECT Rect01;
    Rect01.left = Vrab002; Rect01.top = Vrab003; Rect01.right = Vrab002 + Vrab004; Rect01.bottom = Vrab003 + Vrab005;
    if(ruint32(Rect01.right) > Vrab006) Rect01.right = Vrab006;
    if(ruint32(Rect01.bottom) > Vrab007) Rect01.bottom = Vrab007;
    if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
    if(Rect01.bottom < Rect01.bottom) Rect01.bottom = Rect01.top;
    return Rect01;
   }
   RECT Get_Specified()     perfect
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
   DirectX::XMFLOAT2 Get_Center() perfect {return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab004) / 2)), rxint32(rint32(rxint32(Vrab005) / 2)));}
   DirectX::XMFLOAT2 Get_Mid()    perfect {uint32 Vrab01 = Vrab004; if(Vrab01 > 2) Vrab01 -= 2; uint32 Vrab02 = Vrab005; if(Vrab02 > 2) Vrab02 -= 2; return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab01) / 2)), rxint32(rint32(rxint32(Vrab02) / 2)));}
   
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

   int0 Relocate_Target() perfect {Vrab001 -= 1;}
   uint32 Get_Width()     perfect {return Vrab004;}
   uint32 Get_Height()    perfect {return Vrab005;}
   insize Get_Offset()    perfect {return Vrab006;}
   insize Get_Target()    perfect {return Vrab001;}
   RECT Get_Image(statics insize Vrab01, statics int1 Vrab02 = false)     perfect
   {
    statics uint32 Vrab03 = ruint32(Vrab01 - Vrab006);
    statics LONG Vrab04 = (LONG)((Vrab004 + 1) * (Vrab03 % Vrab002) * (Vrab02 ? -1 : 1)) + (LONG)(Vrab02 ? Vrab007 : 0);
    statics LONG Vrab05 = (LONG)((Vrab005 + 1) * (Vrab03 / Vrab002));
    RECT Rect01;
    Rect01.left = Vrab04; Rect01.right = (Vrab02 ? (Vrab04 - Vrab004) : (Vrab04 + Vrab004));
    Rect01.top = Vrab05; Rect01.bottom = Vrab05 + Vrab005;
    if(Vrab02){if(ruint32(Rect01.right) < 0) Rect01.right = 0; auto Vrab06 = Rect01.right; Rect01.right = Rect01.left; Rect01.left = Vrab06;} else
    {if(ruint32(Rect01.right) > Vrab007) Rect01.right = Vrab007;}
    if(ruint32(Rect01.bottom) > Vrab008) Rect01.bottom = Vrab008;
    if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
    if(Rect01.bottom < Rect01.bottom) Rect01.bottom = Rect01.top;
    return Rect01;
   }
   RECT Get_Specified(statics insize Vrab01, statics int1 Vrab02 = false) perfect
   {
    statics uint32 Vrab03 = ruint32(Vrab01 - Vrab006);
    statics LONG Vrab04 = (LONG)((Vrab004 + 1) * (Vrab03 % Vrab002) * (Vrab02 ? -1 : 1)) + (LONG)(Vrab02 ? Vrab007 : 0);
    statics LONG Vrab05 = (LONG)((Vrab005 + 1) * (Vrab03 / Vrab002));
    RECT Rect01;
    Rect01.left = Vrab04; Rect01.right = (Vrab02 ? (Vrab04 - Vrab004) : (Vrab04 + Vrab004));
    Rect01.top = Vrab05; Rect01.bottom = Vrab05 + Vrab005;
    if(Vrab004 > 2){Rect01.left += 1; Rect01.right -= 1;} if(Vrab005 > 2){Rect01.top += 1; Rect01.bottom -= 1;}
    if(Vrab02){if(ruint32(Rect01.right) < 0) Rect01.right = 1; auto Vrab06 = Rect01.right; Rect01.right = Rect01.left; Rect01.left = Vrab06;} else
    {if(ruint32(Rect01.right) > Vrab007) Rect01.right = Vrab007 - 1;}
    if(ruint32(Rect01.bottom) > Vrab008) Rect01.bottom = Vrab008 - 1;
    if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
    if(Rect01.bottom < Rect01.bottom) Rect01.bottom = Rect01.top;
    return Rect01;
   }
   DirectX::XMFLOAT2 Get_Center() perfect {return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab004) / 2)), rxint32(rint32(rxint32(Vrab005) / 2)));}
   DirectX::XMFLOAT2 Get_Mid()    perfect {uint32 Vrab01 = Vrab004; if(Vrab01 > 2) Vrab01 -= 2; uint32 Vrab02 = Vrab005; if(Vrab02 > 2) Vrab02 -= 2; return DirectX::XMFLOAT2(rxint32(rint32(rxint32(Vrab01) / 2)), rxint32(rint32(rxint32(Vrab02) / 2)));}
   
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
  struct HEPTA_DISPLAY {uint8 Type = 0; insize Target = 0; int64 Post_X1 = 0; int64 Post_Y1 = 0; int16 Effect = 0; uint8 Trans = 0; int64 Post_X2 = 0; int64 Post_Y2 = 0; int64 Post_X3 = 0; int64 Post_Y3 = 0; int64 Post_X4 = 0; int64 Post_Y4 = 0;};
  struct HEPTA_AUDINGS
  {
   HEPTA_AUDINGS(statics string, DirectX::AudioEngine*);
   ~HEPTA_AUDINGS(){Sound.reset();}

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

  struct HEPTA_GAME final : public HEPTA_DEVICENOTIFY
  {
   HEPTA_GAME() perfect (false);
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
  
 // Memory / Variables
  unique < HEPTA_GAME > Game0001;
  std::vector < insize > Spic0001;
  std::vector < HEPTA_IMAGE > Imge0001;
  std::vector < HEPTA_SPRITE > Sprt0001;
  std::vector < HEPTA_PICTURE > Pics0001;
  std::vector < HEPTA_DISPLAY > Disp0001;
  std::vector < HEPTA_SOUNDPLAY > Sond0001;
  std::vector < unique < HEPTA_AUDINGS > > Audi0001;
  std::vector < unique < HEPTA_MUSIC > > Isnd0001;

 // Global Function
  int0 G_ToggleFullscreen() perfect;
  int0 G_Adjust_Window(statics uint32 = 1920, statics uint32 = 1080, statics int1 = true, statics string = "Hepta : Enchanted") perfect;
  int0 ThrowIfFailed(HRESULT Hres01, statics string Temp01 = "")
  {
   if(SUCCEEDED(Hres01)) return;
   if(FACILITY_WINDOWS == HRESULT_FACILITY(Hres01)) Hres01 = HRESULT_CODE(Hres01);
   
   string Temp02 = "Exception Occur, Error Code : 0x" + std::format("{:X}", ruint32(Hres01)); if(Temp01 != "") Temp02 += " (" + Temp01 + ")";
   statics std::wstring Temp03 = L"\n\nWould be helpful if you would inform the developer (Mesujin).";

   TCHAR* Temp04; std::wstring Temp05;
   if(FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, Hres01, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&Temp04, 0, NULL) != 0) 
   {Temp05 = std::wstring(Temp04); Temp05.pop_back(); Temp05.pop_back(); Temp05 = std::wstring(Temp02.begin(), Temp02.end()) + L"\n\"" + Temp05 + L".\"" + Temp03;} else 
   {Temp05 = std::wstring(Temp02.begin(), Temp02.end()) + Temp03;}
   
   MessageBox(NULL, Temp05.c_str(), L"Platform Error", MB_OK | MB_ICONERROR);
   exit(0); /*throw HEPTA_EXCEPTION(Hres01);*/
  }
  std::vector < uint8_t > CSO_Read(_In_z_ statics wchar_t* Temp01)
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
   std::vector < uint8_t > Vect01; Vect01.resize(size_t(Post01));  File01.seekg(0, std::ios::beg);
   if(!File01) throw std::runtime_error("CSO_Read");
   File01.read(reinterpret_cast < int8* >(Vect01.data()), Post01);
   if(!File01) throw std::runtime_error("CSO_Read");
   File01.close(); return Vect01;
  }

  // Platform's Action
   insize P_Load_Pic(statics string Temp01, statics uint32 Vrab01 = 0, statics uint32 Vrab02 = 0, statics uint32 Vrab03 = -1, statics uint32 Vrab04 = -1) perfect
   {
    insize Vrab05 = 0; statics insize Vrab06 = Imge0001.size();

    while(Vrab05 != Vrab06){if(Imge0001[Vrab05].Address == Temp01) break; Vrab05 += 1;}
    if(Vrab05 != Vrab06)
    {if(!Imge0001[Vrab05].Success) Imge0001[Vrab05] = HEPTA_IMAGE(Temp01, Game0001->m_deviceResources->GetD3DDevice());} else
    {Imge0001.push_back(HEPTA_IMAGE(Temp01, Game0001->m_deviceResources->GetD3DDevice()));}
    if(!Imge0001[Vrab05].Success){if(Vrab05 == Vrab06) Imge0001.pop_back(); return rinsize(-1);}
    
    statics insize Vrab07 = Pics0001.size();
    Pics0001.push_back(HEPTA_PICTURE(Vrab05, Vrab01, Vrab02, Vrab03, Vrab04));
    return Vrab07;
   }
   insize P_Load_Sprite(statics string Temp01, statics uint32 Vrab01, statics uint32 Vrab02, statics uint32 Vrab03 = 1, statics uint32 Vrab04 = 1) perfect
   {
    if(Vrab03 == 0 || Vrab04 == 0) return rinsize(-1);
    insize Vrab05 = 0; statics insize Vrab06 = Imge0001.size();

    while(Vrab05 != Vrab06){if(Imge0001[Vrab05].Address == Temp01) break; Vrab05 += 1;}
    if(Vrab05 != Vrab06)
    {if(!Imge0001[Vrab05].Success) Imge0001[Vrab05] = HEPTA_IMAGE(Temp01, Game0001->m_deviceResources->GetD3DDevice());} else
    {Imge0001.push_back(HEPTA_IMAGE(Temp01, Game0001->m_deviceResources->GetD3DDevice()));}
    if(!Imge0001[Vrab05].Success){if(Vrab05 == Vrab06) Imge0001.pop_back(); return rinsize(-1);}

    statics insize Vrab07 = Sprt0001.size(); statics insize Vrab08 = Spic0001.size(); statics insize Vrab09 = (Vrab01 * Vrab02) + Vrab08; Spic0001.resize(Vrab09);
    Sprt0001.push_back(HEPTA_SPRITE(Vrab05, Vrab01, Vrab02, Vrab03, Vrab04, Vrab08));
    for(insize Vrab10 = Vrab08; Vrab10 < Vrab09; ++Vrab10) Spic0001[Vrab10] = Vrab07;
    return Vrab08;
   }
   insize P_Load_Sound(statics string Temp01) perfect
   {
    insize Vrab01 = Temp01.size();
    string Temp02 = Temp01; while(Vrab01 != 0){Vrab01 -= 1; if(Temp02.at(Vrab01) >= 'A' && Temp02.at(Vrab01) <= 'Z') Temp02.at(Vrab01) += 32;}
    Temp02 = string(Temp02, Temp02.size() - 4, 4);
    int1 Vrab02 = true;
    if(Temp02 == ".wav") Vrab02 = false;
    if(Vrab02) return rinsize(-1);
    insize Vrab03 = 0; statics insize Vrab04 = Audi0001.size(); while(Vrab03 != Vrab04){if(Audi0001[Vrab03]->Address == Temp01) break; Vrab03 += 1;}
    if(Vrab03 == Vrab04) Audi0001.push_back(std::make_unique < HEPTA_AUDINGS > (Temp01, Game0001->GetAudio()));
    if(Audi0001[Vrab03]->Success){return Vrab03;} else {Audi0001.pop_back(); return rinsize(-1);}
   }

   int64  P_Get_Width(statics insize Vrab01, statics int1 Vrab02 = false) perfect
   {
    if(Vrab02)
    {
     if(Vrab01 < Spic0001.size()) return Sprt0001[Spic0001[Vrab01]].Get_Width();
    } else
    {
     if(Vrab01 < Pics0001.size()) return Pics0001[Vrab01].Get_Width();
    }
    return 1;
   }
   int64  P_Get_Height(statics insize Vrab01, statics int1 Vrab02 = false) perfect
   {
    if(Vrab02)
    {
     if(Vrab01 < Spic0001.size()) return Sprt0001[Spic0001[Vrab01]].Get_Height();
    } else
    {
     if(Vrab01 < Pics0001.size()) return Pics0001[Vrab01].Get_Height();
    }
    return 1;
   }

   int1   P_Set_Display(statics uint8 Vrab01 = 0, statics insize Vrab02 = 0, statics int64 Vrab03 = 0, statics int64 Vrab04 = 0, statics uint8 Vrab05 = 0ui8, statics uint8 Vrab06 = 255ui8, statics int64 Vrab07 = 0, statics int64 Vrab08 = 0, statics int64 Vrab09 = 0, statics int64 Vrab10 = 0, statics int64 Vrab11 = 0, statics int64 Vrab12 = 0) perfect
   {
    if(Vrab01 == 2 || Vrab01 == 3 || Vrab01 == 6 || Vrab01 == 7) if(Vrab02 >= Pics0001.size()) return false;
    if(Vrab01 == 4 || Vrab01 == 5 || Vrab01 == 8 || Vrab01 == 9) if(Vrab02 >= Spic0001.size()) return false;
    statics insize Vrab13 = Disp0001.size(); if(Vrab13 >= rinsize(0xFFFFFFF)) return false; Disp0001.push_back(HEPTA_DISPLAY());
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
   int1   P_Set_Sound(statics insize Vrab01, statics xint32 Vrab02 = 1, statics xint32 Vrab03 = 0) perfect
   {
    if(Vrab01 >= Audi0001.size()) return false;
    Sond0001.push_back({Vrab01, Vrab03, Vrab02});
    return true;
   }
   insize P_Set_Music(statics insize Vrab01, statics xint32 Vrab02 = 1, statics xint32 Vrab03 = 0) perfect
   {
    if(Vrab01 >= Audi0001.size()) return rinsize(-1);
    statics insize Vrab04 = Isnd0001.size();
    Isnd0001.push_back(std::make_unique < HEPTA_MUSIC > (Audi0001[Vrab01]->Sound->CreateInstance(), 0ui8));
    Isnd0001[Vrab04]->Instance->SetVolume(Vrab02); Isnd0001[Vrab04]->Instance->SetPan(Vrab03); 
    return Vrab04;
   }

   int1   P_Control_Music(statics insize Vrab01, statics xint32 Vrab02 = 1, statics xint32 Vrab03 = 0, statics int1 Vrab04 = false) perfect
   {
    if(Vrab01 >= Isnd0001.size()) return false; if(Vrab04){Isnd0001[Vrab01]->Active = 2; return true;}
    Isnd0001[Vrab01]->Instance->SetVolume(Vrab02); Isnd0001[Vrab01]->Instance->SetPan(Vrab03); 
    return true;
   }
   
   int0   P_Unload_Pic(statics insize Vrab01 = 0) perfect
   {
    if(Vrab01 >= Pics0001.size()) return;
    Pics0001.erase(Pics0001.begin() + Vrab01, Pics0001.end());
   }
   int0   P_Unload_Sprite(statics insize Vrab01 = 0) perfect
   {
    if(Vrab01 >= Sprt0001.size()) return; statics insize Vrab02 = Sprt0001[Vrab01].Get_Offset();
    Spic0001.erase(Spic0001.begin() + Vrab02, Spic0001.end());
    Sprt0001.erase(Sprt0001.begin() + Vrab01, Sprt0001.end());
   }
   int0   P_Unload_Sound(statics insize Vrab01 = 0) perfect
   {
    if(Vrab01 >= Audi0001.size()) return;
    Audi0001.erase(Audi0001.begin() + Vrab01, Audi0001.end());
    Isnd0001.clear();
   }
   int0   P_Unload_Image() perfect
   {
    Game0001->m_deviceResources->GetD3DDeviceContext()->ClearState();
    Game0001->m_deviceResources->GetD3DDeviceContext()->Flush();

    insize Vrab01 = Imge0001.size(); statics insize Vrab02 = Sprt0001.size(), Vrab03 = Pics0001.size();
    while(Vrab01 != 0)
    {
     Vrab01 -= 1;
     {insize Vrab04 = 0; while(Vrab04 != Vrab02){if(Sprt0001[Vrab04].Get_Target() == Vrab01) break; Vrab04 += 1;} if(Vrab04 != Vrab02) continue;} // Check whenever it's referenced or not.
     {insize Vrab04 = 0; while(Vrab04 != Vrab03){if(Pics0001[Vrab04].Get_Target() == Vrab01) break; Vrab04 += 1;} if(Vrab04 != Vrab03) continue;} // Check whenever it's referenced or not.
     
     // Is unreferenced.
     {
      ID3D11Texture2D *Texd01;
      Imge0001[Vrab01].Data->QueryInterface < ID3D11Texture2D > (&Texd01);
      Imge0001[Vrab01].Texture->Release(); Imge0001[Vrab01].Data->Release();
      while(true) if(Texd01->Release() == 0) break;

      insize Vrab04 = Imge0001.size();
      if(Vrab01 == Vrab04 - 1)
      {Imge0001.pop_back();} else
      {
       while(Vrab04 != Vrab01 + 1)
       {
        Vrab04 -= 1;
        insize Vrab05 = Vrab02; while(Vrab05 != 0){Vrab05 -= 1; if(Sprt0001[Vrab05].Get_Target() == Vrab04) Sprt0001[Vrab05].Relocate_Target();}
        insize Vrab06 = Vrab03; while(Vrab06 != 0){Vrab06 -= 1; if(Pics0001[Vrab06].Get_Target() == Vrab04) Pics0001[Vrab06].Relocate_Target();}
       }
       Imge0001.erase(Imge0001.begin() + Vrab01);
      }
     }
    }

    Game0001->m_deviceResources->GetD3DDeviceContext()->ClearState();
    Game0001->m_deviceResources->GetD3DDeviceContext()->Flush();
   }
  //-//
 //-//
#endif
