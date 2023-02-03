#pragma once
////////////////////////////////////////////////////////////////////////////////////////////
// base.h                                                                                 //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////

// Commands
 #include "device.h"
 #include "timing.h"
 #include "spriting.h"

 //DirectX Tool Kit
  #include "SpriteBatch.h"
  #include "Keyboard.h"
  #include "GamePad.h"
  #include "Mouse.h"
  #include "PostProcess.h"
  #include <Audio.h>
 //-//
 
 #define HEPTA_THIS_VERSION      0.85220408
 #define HEPTA_LOCATION_ENGINE   "System.as"
 #define HEPTA_LOCATION_DATA     "Data.txt"
 #define HEPTA_LOCATION_DATABASE "Database.edb"
 #define HEPTA_LOCATION_BASE     "Database"
 #define HEPTA_LOCATION_RECORD   "Recording"
 #define HEPTA_LOCATION_LANG_EN  HEPTA_LOCATION_BASE "\\LangEN.txt"
 #define HEPTA_LOCATION_LANG_ID  HEPTA_LOCATION_BASE "\\LangID.txt"
 #define HEPTA_LOCATION_LANG_CN  HEPTA_LOCATION_BASE "\\LangCN.txt"
 #define HEPTA_LOCATION_LANG_CN2 HEPTA_LOCATION_BASE "\\LangCN2.txt"
 #define HEPTA_LOCATION_LANG_RU  HEPTA_LOCATION_BASE "\\LangRU.txt"
 #define HEPTA_LOCATION_LANG_JP  HEPTA_LOCATION_BASE "\\LangJP.txt"

 using int0 = void;                  // -
 using int1 = bool;                  // I know it's not being stored as 1 bit.
 using int8 = char;                  // -
 using int16 = short;                // -
 using int32 = int;                  // -
 using int64 = long long;            // -
 using uint8 = unsigned char;        // -
 using uint16 = unsigned short;      // -
 using uint32 = unsigned int;        // -
 using uint64 = unsigned long long;  // -
 using xint32 = float;               // -
 using xint64 = double;              // -
 using string = std::string;         // -
 using stream = std::stringstream;   //
 using insize = uint32;              // Maximum size of vector.

 #define rint0 static_cast < int0 >
 #define rint1 static_cast < int1 >
 #define rint8 static_cast < int8 >
 #define rint16 static_cast < int16 >
 #define rint32 static_cast < int32 >
 #define rint64 static_cast < int64 >
 #define ruint8 static_cast < uint8 >
 #define ruint16 static_cast < uint16 >
 #define ruint32 static_cast < uint32 >
 #define ruint64 static_cast < uint64 >
 #define rxint32 static_cast < xint32 >
 #define rxint64 static_cast < xint64 >
 #define rinsize static_cast < insize >
 #define fastened noexcept
//-//

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game final : public DX::IDeviceNotify
{
 public:
  Game() noexcept(false);
  ~Game() = default;

  Game(Game&&) = default;
  Game& operator= (Game&&) = default;

  Game(Game const&) = delete;
  Game& operator= (Game const&) = delete;

  // Initialization and management
  void Initialize(HWND window, unsigned int width, unsigned int height);

  // Basic game loop
  void Tick();

  // IDeviceNotify
  void OnDeviceLost() override;
  void OnDeviceRestored() override;

  // Messages
  void OnActivated();
  void OnDeactivated();
  void OnSuspending();
  void OnResuming();
  void OnWindowMoved();
  void OnDisplayChange();
  void OnWindowSizeChanged(unsigned int width, unsigned int height);

  // Properties
  void GetDefaultSize(unsigned int &width, unsigned int &height) const noexcept;

  // Spriting
  insize C_Sprite_Set(const string &Temp01, uint32 Vrab01, uint32 Vrab02, uint32 Vrab03, uint32 Vrab04) fastened;
  int0 Engine_Display() fastened;
 private:
  void Update(DX::StepTimer const &timer);
  void Render();

  void Clear();

  void CreateDeviceDependentResources();
  void CreateWindowSizeDependentResources();

  // Device resources.
  std::unique_ptr < DX::DeviceResources > m_deviceResources;

  // Rendering loop timer.
  DX::StepTimer m_timer;

  // Physical Inputs.
  std::unique_ptr < DirectX::Keyboard > m_keyboard;
  std::unique_ptr < DirectX::Mouse > m_mouse;
  std::unique_ptr < DirectX::GamePad > m_gamepad;

  // Visual Output.
  Microsoft::WRL::ComPtr < ID3D11Device1 > m_d3dDevice;
  Microsoft::WRL::ComPtr < ID3D11ShaderResourceView > m_texture;
  std::unique_ptr < DirectX::BasicPostProcess > postProcess;
  ID3D11Texture2D *tex;
  D3D11_TEXTURE2D_DESC sTexDesc;
  D3D11_SUBRESOURCE_DATA tbsd;
  RECT m_fullscreenRect;
  struct POSITIONAL {unsigned int Width; unsigned int Height;}; POSITIONAL DisplayingSize;
  std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
  std::vector < std::unique_ptr < AnimatedTexture > > m_source;

  // Audio Output.
  std::unique_ptr < DirectX::AudioEngine > audEngine;
  std::unique_ptr < DirectX::SoundEffect > soundEffect;
};


 namespace {std::unique_ptr < Game > g_game;}
