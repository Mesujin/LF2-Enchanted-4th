////////////////////////////////////////////////////////////////////////////////////////////
// "platform.cpp", based on DirectXTK's template.                                         //
//                                                                                        //
// The base of the platform.                                                              //
////////////////////////////////////////////////////////////////////////////////////////////

// Commands
 #include "engine.h"
//-//

// Declarations
 int0 G_ToggleFullscreen() fastened
 {
  auto Hwnd01 = Game0001->m_deviceResources->GetWindow();
  if(Varb0014)
  {
   SetWindowLongPtr(Hwnd01, GWL_STYLE, WS_OVERLAPPEDWINDOW);
   SetWindowLongPtr(Hwnd01, GWL_EXSTYLE, 0);
   uint32 Vrab06 = Varb0002, Vrab07 = Varb0003;
   ShowWindow(Hwnd01, SW_SHOWNORMAL);
   SetWindowPos(Hwnd01, HWND_TOP, CW_USEDEFAULT, CW_USEDEFAULT, static_cast < LONG > (Vrab06 + 16), static_cast < LONG > (Vrab07 + 39), SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
  } else
  {
   SetWindowLongPtr(Hwnd01, GWL_STYLE, WS_POPUP);
   SetWindowLongPtr(Hwnd01, GWL_EXSTYLE, WS_EX_TOPMOST);
   SetWindowPos(Hwnd01, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
   ShowWindow(Hwnd01, SW_SHOWMAXIMIZED);
  }
  Varb0014 = !Varb0014;
 }

 HEPTA_IMAGE::HEPTA_IMAGE(statics string &Temp01, ID3D11Device *Dvis01) fastened
 {
  std::ifstream File01(Temp01);
  if(File01.is_open())
  {
   File01.close();
   if(DirectX::CreateWICTextureFromFileEx(Dvis01, std::wstring(Temp01.begin(), Temp01.end()).c_str(), 0U, D3D11_USAGE_DEFAULT, D3D11_BIND_SHADER_RESOURCE, 0U, 0U, DirectX::DX11::WIC_LOADER_DEFAULT, &Data, &Texture) == S_OK)
   //if(DirectX::CreateWICTextureFromFile(Dvis01, std::wstring(Temp01.begin(), Temp01.end()).c_str(), &Data, &Texture) == S_OK)
   {Success = true; Address = Temp01; return;}
  }
  Success = false;
 }
 HEPTA_SPRITE::HEPTA_SPRITE(insize Vrab01, uint32 Vrab02, uint32 Vrab03, uint32 Vrab04, uint32 Vrab05, insize Vrab06)
 {
  Vrab001 = Vrab01; Vrab002 = Vrab02; Vrab003 = Vrab03; Vrab004 = Vrab04; Vrab005 = Vrab05; Vrab006 = Vrab06;
  ID3D11Texture2D *Texd01 = 0; ID3D11Resource *Resh01; D3D11_TEXTURE2D_DESC Desc01;
  Imge0001[Vrab01].Texture->GetResource(&Resh01);
  Desc01.Width = ruint32(-1); Desc01.Height = ruint32(-1);
  if(SUCCEEDED(Resh01->QueryInterface<ID3D11Texture2D>(&Texd01))) Texd01->GetDesc(&Desc01);
  Vrab007 = Desc01.Width; Vrab008 = Desc01.Height;
  //Texd01->Release(); Resh01->Release();
 }
 HEPTA_PICTURE::HEPTA_PICTURE(insize Vrab01, uint32 Vrab02, uint32 Vrab03, uint32 Vrab04, uint32 Vrab05)
 {
  Vrab001 = Vrab01; Vrab002 = Vrab02; Vrab003 = Vrab03;
  ID3D11Texture2D *Texd01 = 0; ID3D11Resource *Resh01; D3D11_TEXTURE2D_DESC Desc01;
  Imge0001[Vrab01].Texture->GetResource(&Resh01);
  Desc01.Width = ruint32(-1); Desc01.Height = ruint32(-1);
  if(SUCCEEDED(Resh01->QueryInterface < ID3D11Texture2D > (&Texd01))) Texd01->GetDesc(&Desc01);
  Vrab006 = Desc01.Width; Vrab007 = Desc01.Height;
  if(Vrab04 == ruint32(-1)){Vrab004 = Vrab006;} else {Vrab004 = Vrab04;}
  if(Vrab05 == ruint32(-1)){Vrab005 = Vrab007;} else {Vrab005 = Vrab05;}
  //Texd01->Release(); Resh01->Release();
 }
 HEPTA_AUDINGS::HEPTA_AUDINGS(statics string Temp01, DirectX::AudioEngine *Aeng01)
 {
  if(L_Lowercase(string(Temp01, Temp01.size() - 4, 4)) != ".wav"){Success = false; return;}
  std::ifstream File01(Temp01);
  if(File01.is_open())
  {
   File01.close();
   Sound = std::make_unique < DirectX::SoundEffect > (Aeng01, std::wstring(Temp01.begin(), Temp01.end()).c_str());
   Address = Temp01; Success = true;
  } else
  {Success = false;}
 }

 namespace
 {
  #if defined(_DEBUG)
   // Check for SDK Layer support.
   stacked int1 SdkLayersAvailable() fastened {HRESULT hr = D3D11CreateDevice(nullptr,
                                                                             D3D_DRIVER_TYPE_NULL,       // There is no need to create a real hardware device.
                                                                             nullptr,
                                                                             D3D11_CREATE_DEVICE_DEBUG,  // Check for the SDK layers.
                                                                             nullptr,                    // Any feature level will do.
                                                                             0,
                                                                             D3D11_SDK_VERSION,
                                                                             nullptr,                    // No need to keep the D3D device reference.
                                                                             nullptr,                    // No need to know the feature level.
                                                                             nullptr                     // No need to keep the D3D device context reference.
                                                                            ); return SUCCEEDED(hr);}
  #endif

  stacked DXGI_FORMAT NoSRGB(DXGI_FORMAT Dxfm01) fastened
  {
   switch(Dxfm01)
   {
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: return DXGI_FORMAT_R8G8B8A8_UNORM;
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: return DXGI_FORMAT_B8G8R8A8_UNORM;
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB: return DXGI_FORMAT_B8G8R8X8_UNORM;
    default:                              return Dxfm01;
   }
  }
  stacked lint32 ComputeIntersectionArea(lint32 Vrab01, lint32 Vrab02, lint32 Vrab03, lint32 Vrab04, lint32 Vrab05, lint32 Vrab06, lint32 Vrab07, lint32 Vrab08) fastened
  {
   return std::max(0l, std::min(Vrab03, Vrab07) - std::max(Vrab01, Vrab05)) * std::max(0l, std::min(Vrab04, Vrab08) - std::max(Vrab02, Vrab06));
  }
 }

 // HEPTA_GAME::
  HEPTA_GAME::HEPTA_GAME() fastened (false)
  {
   m_deviceResources = std::make_unique < HEPTA_DEVICE > ();
   m_deviceResources->RegisterDeviceNotify(this);
  }
  HEPTA_GAME::~HEPTA_GAME()
  {
   if(Aeng001) Aeng001->Suspend();
   statics insize Vrab01 = Isnd0001.size(); for(insize Vrab02 = 0; Vrab02 < Vrab01; ++Vrab02) Isnd0001[Vrab02]->Instance.reset();
  }

  int0 HEPTA_GAME::Initialize(HWND Hwnd01, uint32 Vrab01, uint32 Vrab02)
  {
   m_deviceResources->SetWindow(Hwnd01, Vrab01, Vrab02);
   m_deviceResources->CreateDeviceResources(); CreateDeviceDependentResources();
   m_deviceResources->CreateWindowSizeDependentResources(); CreateWindowSizeDependentResources();

   m_timer.SetFixedTimeStep(true);
   m_timer.SetTargetElapsedSeconds(1.f / 480.f);
    
   m_keyboard = std::make_unique < DirectX::Keyboard > ();
   m_gamepad = std::make_unique < DirectX::GamePad > ();
   m_mouse = std::make_unique < DirectX::Mouse > (); m_mouse->SetWindow(Hwnd01);
  }
  int0 HEPTA_GAME::Tick()
  {
   m_timer.Tick([&](){Update(m_timer);}); Render();
   if(!Aeng001->Update()){Aeng001->IsCriticalError(); return;} 
   {
    // Sound Play.
    {
     statics insize Vrab01 = Audi0001.size(); insize Vrab02 = Sond0001.size();
     while(Vrab02 != 0)
     {
      Vrab02 -= 1; statics insize Vrab03 = Sond0001[Vrab02].Target;
      if(Vrab03 >= Vrab01) continue;
      Audi0001[Sond0001[Vrab02].Target]->Sound->Play(Sond0001[Vrab02].Volume, 0, Sond0001[Vrab02].Pan);
     }
     Sond0001.clear();
    }

    // Music Play.
    {
     insize Vrab01 = Isnd0001.size();
     while(Vrab01 != 0)
     {
      Vrab01 -= 1;
      switch(Isnd0001[Vrab01]->Active)
      {
       case 0ui8: Isnd0001[Vrab01]->Active = 1ui8; Isnd0001[Vrab01]->Instance->Play(true); break;
       case 2ui8: Isnd0001[Vrab01]->Instance.reset(); Isnd0001.erase(Isnd0001.begin() + Vrab01); break;
       default: break;
      }
     }
    }
   }
  }
  
  int0 HEPTA_GAME::OnDeviceLost() // Direct3D resource cleanup.
  {
   Pics001.reset(); Stat001.reset(); Grap001.Reset();
  }
  int0 HEPTA_GAME::OnDeviceRestored()
  {
   CreateDeviceDependentResources(); CreateWindowSizeDependentResources();
  }

  int0 HEPTA_GAME::OnActivated()   // Game is becoming active window.
  {
   Varb0007 = false;
  }
  int0 HEPTA_GAME::OnDeactivated() // Game is becoming background window.
  {
  
  }
  int0 HEPTA_GAME::OnSuspending()  // Game is being power-suspended (or minimized).
  {
   Varb0007 = true;
  }
  int0 HEPTA_GAME::OnResuming()    // Game is being power-resumed (or returning from minimize).
  {
   Varb0007 = false; m_timer.ResetElapsedTime();
  }
  int0 HEPTA_GAME::OnWindowMoved()
  {
   auto statics Vrab01 = m_deviceResources->GetOutputSize(); m_deviceResources->WindowSizeChanged(Vrab01.right, Vrab01.bottom);
  }
  int0 HEPTA_GAME::OnDisplayChange()
  {
   m_deviceResources->UpdateColorSpace();
  }
  int0 HEPTA_GAME::OnWindowSizeChanged(uint32 Vrab01, uint32 Vrab02) // Game window is being resized.
  {
   if(!m_deviceResources->WindowSizeChanged(Vrab01, Vrab02)) return;
   CreateWindowSizeDependentResources();
  }

  int0 HEPTA_GAME::Update(HEPTA_TIMING statics &Time01)
  {
   P_EngineFrame(Time01.GetElapsedSeconds(), Time01.GetTotalSeconds(), Time01.GetFrameCount(), Time01.GetFramesPerSecond(), m_keyboard.get(), m_gamepad.get(), m_mouse.get());
  }
  int0 HEPTA_GAME::Render()
  {
   if(Varb0007) Disp0001.clear();
   if(m_timer.GetFrameCount() == 0) return; Clear();
   if(Varb0027){Disp0001.clear(); Audi0001.clear(); G_Unload_Pic(); G_Unload_Sprite(); G_Unload_Sound(); G_Unload_Image(); PostQuitMessage(0); return;}

   m_deviceResources->PIXBeginEvent(L"Render");
   {
    DirectX::XMMATRIX Matx01 = DirectX::XMMatrixIdentity();
    DirectX::XMVECTOR Vect01 = DirectX::XMMatrixDeterminant(Matx01);
    Matx01 = DirectX::XMMatrixInverse(&Vect01, Matx01);
    Pics001->Begin(DirectX::SpriteSortMode_Deferred, Stat001->NonPremultiplied(), Samp001.Get(), nullptr, nullptr, [=]
     {
      m_deviceResources->GetD3DDeviceContext()->PSSetShader(Grap001.Get(), nullptr, 0);
     }, Matx01
    );
    
    statics insize Vrab01 = Disp0001.size();
    for(insize Vrab02 = 0; Vrab02 < Vrab01; ++Vrab02)
    {
     switch(Disp0001[Vrab02].Type)
     {
      case 0: // Filled Rectangle.
       {
        RECT Rect01;
        Rect01.left = (LONG)Disp0001[Vrab02].Post_X1 + Varb0008;
        Rect01.top = (LONG)Disp0001[Vrab02].Post_Y1 + Varb0009;

        Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2; if(Rect01.right < Rect01.left) Rect01.right = 0;
        Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y2; if(Rect01.bottom < Rect01.top) Rect01.bottom = 0;

        statics uint32 Vrab03 = L_Rounding(rxint64(rint64(Rect01.right) - rint64(Rect01.left)) / 2);
        statics uint32 Vrab04 = L_Rounding(rxint64(rint64(Rect01.bottom) - rint64(Rect01.top)) / 2);
        Rect01.left += Vrab03; Rect01.right += Vrab03;
        Rect01.top += Vrab04; Rect01.bottom += Vrab04;

        statics xint32 Vrab05 = rxint32((Disp0001[Vrab02].Target) & 0xFF) / 255.0f;
        statics xint32 Vrab06 = rxint32((Disp0001[Vrab02].Target >> 8) & 0xFF) / 255.0f;
        statics xint32 Vrab07 = rxint32((Disp0001[Vrab02].Target >> 16) & 0xFF) / 255.0f;
        statics xint32 Vrab08 = rxint32(Disp0001[Vrab02].Trans) / 255.0f;
        Pics001->Draw(Trec001.Get(), Rect01, nullptr, DirectX::XMVECTORF32({Vrab07, Vrab06, Vrab05, Vrab08}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Effect)), DirectX::XMFLOAT2(0.5f, 0.5f));
       }
      break;
      case 1: // Un-filled Rectangle
       {
        RECT Rect01;
        Rect01.left = (LONG)Disp0001[Vrab02].Post_X1 + Varb0008;
        Rect01.top = (LONG)Disp0001[Vrab02].Post_Y1 + Varb0009;
        Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2; if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
        Rect01.bottom = Rect01.top + 1;
        RECT Rect02;
        Rect02.left = Rect01.left;
        Rect02.top = Rect01.top;
        Rect02.right = Rect02.left + 1;
        Rect02.bottom = Rect02.top + (LONG)Disp0001[Vrab02].Post_Y2; if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        RECT Rect03;
        Rect03.left = Rect01.left;
        Rect03.top = Rect02.bottom - 1;
        Rect03.right = Rect01.right;
        Rect03.bottom = Rect03.top + 1;
        RECT Rect04;
        Rect04.left = Rect01.right - 1;
        Rect04.top = Rect01.top;
        Rect04.right = Rect04.left + 1;
        Rect04.bottom = Rect02.bottom;

        statics xint32 Vrab03 = rxint32(L_Rounding(rxint64(Disp0001[Vrab02].Post_X2) / 2));
        statics xint32 Vrab04 = rxint32(L_Rounding(rxint64(Disp0001[Vrab02].Post_Y2) / 2));

        Rect01.left += rint32(Vrab03); Rect01.right += rint32(Vrab03);
        Rect01.top += rint32(Vrab04); Rect01.bottom += rint32(Vrab04);
        Rect02.left += rint32(Vrab03); Rect02.right += rint32(Vrab03);
        Rect02.top += rint32(Vrab04); Rect02.bottom += rint32(Vrab04);

        Rect03.left += rint32(Vrab03); Rect03.right += rint32(Vrab03);
        Rect03.top -= rint32(Vrab04) - 1; Rect03.bottom -= rint32(Vrab04) - 1;
        Rect04.left -= rint32(Vrab03) - 1; Rect04.right -= rint32(Vrab03) - 1;
        Rect04.top += rint32(Vrab04); Rect04.bottom += rint32(Vrab04);

        statics xint32 Vrab05 = rxint32((Disp0001[Vrab02].Target) & 0xFF) / 255.0f;
        statics xint32 Vrab06 = rxint32((Disp0001[Vrab02].Target >> 8) & 0xFF) / 255.0f;
        statics xint32 Vrab07 = rxint32((Disp0001[Vrab02].Target >> 16) & 0xFF) / 255.0f;
        statics xint32 Vrab08 = rxint32(Disp0001[Vrab02].Trans) / 255.0f;

        Pics001->Draw(Trec001.Get(), Rect01, nullptr, DirectX::XMVECTORF32({Vrab07, Vrab06, Vrab05, Vrab08}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Effect)), DirectX::XMFLOAT2(0.5f, Vrab04));//, DirectX::XMFLOAT2(0.5f, 0));
        Pics001->Draw(Trec001.Get(), Rect02, nullptr, DirectX::XMVECTORF32({Vrab07, Vrab06, Vrab05, Vrab08}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Effect)), DirectX::XMFLOAT2(Vrab03, 0.5f));//, DirectX::XMFLOAT2(0.5f, 0.5f));
        Pics001->Draw(Trec001.Get(), Rect03, nullptr, DirectX::XMVECTORF32({Vrab07, Vrab06, Vrab05, Vrab08}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Effect)), DirectX::XMFLOAT2(0.5f, -Vrab04 + 1));//, DirectX::XMFLOAT2(0.5f, 0.5f));
        Pics001->Draw(Trec001.Get(), Rect04, nullptr, DirectX::XMVECTORF32({Vrab07, Vrab06, Vrab05, Vrab08}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Effect)), DirectX::XMFLOAT2(-Vrab03 + 1, 0.5f));//, DirectX::XMFLOAT2(0.5f, 0.5f));
       }
      break;
      case 2: case 6: // Image Draw
       {
        xint32 Vrab04 = 4.0f; if(Disp0001[Vrab02].Type == 6) Vrab04 = 2.0f;
        RECT Rect01;
        Rect01.left = (LONG)Disp0001[Vrab02].Post_X1 + Varb0008;
        Rect01.top = (LONG)Disp0001[Vrab02].Post_Y1 + Varb0009;
        statics insize Vrab03 = Disp0001[Vrab02].Target; DirectX::XMFLOAT2 Flts01; RECT Rect02;
        if(Disp0001[Vrab02].Post_X3 % 90 == 0)
        {
         Rect02 = Pics0001[Vrab03].Get_Image(); Flts01 = Pics0001[Vrab03].Get_Center();
         Rect01.left += rint32(Flts01.x); Rect01.top += rint32(Flts01.y);
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y2 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        } else
        {
         Rect02 = Pics0001[Vrab03].Get_Specified(); Flts01 = Pics0001[Vrab03].Get_Mid();
         Rect01.left += rint32(Flts01.x) + 1; Rect01.top += rint32(Flts01.y) + 1;
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y2 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        }
        auto Effc01 = DirectX::SpriteEffects_None;
        switch(Disp0001[Vrab02].Effect){case 1: Effc01 = DirectX::SpriteEffects_FlipHorizontally; break; case 2: Effc01 = DirectX::SpriteEffects_FlipVertically; break; case 3: Effc01 = DirectX::SpriteEffects_FlipBoth; break; default: break;}
        Pics001->Draw(Imge0001[Pics0001[Vrab03].Get_Target()].Texture, Rect01, &Rect02, DirectX::XMVECTORF32({0.0f, 0.0f, 0.0f, (rxint32(Disp0001[Vrab02].Trans) / 255) + Vrab04}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Post_X3)), Flts01, Effc01);
       }
      break;
      case 3: case 7: // Specific Image Draw
       {
        xint32 Vrab04 = 4.0f; if(Disp0001[Vrab02].Type == 7) Vrab04 = 2.0f;
        RECT Rect01;
        Rect01.left = (LONG)Disp0001[Vrab02].Post_X1 + Varb0008;
        Rect01.top = (LONG)Disp0001[Vrab02].Post_Y1 + Varb0009;
        statics insize Vrab03 = Disp0001[Vrab02].Target; DirectX::XMFLOAT2 Flts01; RECT Rect02;
        auto Effc01 = DirectX::SpriteEffects_None; uint8 Vrab05 = 0;
        switch(Disp0001[Vrab02].Effect){case 0: break; case 1: Effc01 = DirectX::SpriteEffects_FlipHorizontally; break; case 2: Effc01 = DirectX::SpriteEffects_FlipVertically; break; case 3: Effc01 = DirectX::SpriteEffects_FlipBoth; break; default: Vrab05 = (Disp0001[Vrab02].Effect - 4) * 2;break;}
        if(Vrab05 % 90 == 0)
        {
         statics RECT Rect03 = Pics0001[Vrab03].Get_Image();
         Rect02.left = Rect03.left + rint32(ruint64(Disp0001[Vrab02].Post_X3));
         Rect02.top = Rect03.top + rint32(ruint64(Disp0001[Vrab02].Post_Y3));
         if(Rect03.right < Rect02.left + rint32(ruint64(Disp0001[Vrab02].Post_X2))){Rect02.right = Rect03.right;} else {Rect02.right = Rect02.left + rint32(ruint64(Disp0001[Vrab02].Post_X2));}
         if(Rect03.bottom < Rect02.top + rint32(ruint64(Disp0001[Vrab02].Post_Y2))){Rect02.bottom = Rect03.bottom;} else {Rect02.bottom = Rect02.top + rint32(ruint64(Disp0001[Vrab02].Post_Y2));}
         if(Rect02.right < Rect02.left) Rect02.right = Rect02.left;
         if(Rect02.bottom < Rect02.top) Rect02.bottom = Rect02.top;

         Flts01 = DirectX::XMFLOAT2(rxint32(rint32(rxint32(Rect02.right - Rect02.left) / 2)), rxint32(rint32(rxint32(Rect02.bottom - Rect02.top) / 2)));
         Rect01.left += rint32(Flts01.x); Rect01.top += rint32(Flts01.y);
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X4 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y4 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        } else
        {
         statics RECT Rect03 = Pics0001[Vrab03].Get_Specified();
         Rect02.left = Rect03.left + rint32(ruint64(Disp0001[Vrab02].Post_X3));
         Rect02.top = Rect03.top + rint32(ruint64(Disp0001[Vrab02].Post_Y3));
         if(Rect03.right < Rect02.left + rint32(ruint64(Disp0001[Vrab02].Post_X2)) - 1){Rect02.right = Rect03.right;} else {Rect02.right = Rect02.left + rint32(ruint64(Disp0001[Vrab02].Post_X2)) - 1;}
         if(Rect03.bottom < Rect02.top + rint32(ruint64(Disp0001[Vrab02].Post_Y2)) - 1){Rect02.bottom = Rect03.bottom;} else {Rect02.bottom = Rect02.top + rint32(ruint64(Disp0001[Vrab02].Post_Y2)) - 1;}
         if(Rect02.right < Rect02.left) Rect02.right = Rect02.left;
         if(Rect02.bottom < Rect02.top) Rect02.bottom = Rect02.top;
         
         Flts01 = DirectX::XMFLOAT2(rxint32(rint32(rxint32(Rect02.right - Rect02.left - 2) / 2)), rxint32(rint32(rxint32(Rect02.bottom - Rect02.top - 2) / 2)));
         Rect01.left += rint32(Flts01.x) + 1; Rect01.top += rint32(Flts01.y) + 1;
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X4 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y4 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        }
        Pics001->Draw(Imge0001[Pics0001[Vrab03].Get_Target()].Texture, Rect01, &Rect02, DirectX::XMVECTORF32({0.0f, 0.0f, 0.0f, (rxint32(Disp0001[Vrab02].Trans) / 255) + Vrab04}), DirectX::XMConvertToRadians(rxint32(Vrab05)), Flts01, Effc01);
       }
      break;
      case 4: case 5: case 8: case 9: // Sprite Image Draw
       {
        xint32 Vrab04 = 4.0f; if(Disp0001[Vrab02].Type == 8 || Disp0001[Vrab02].Type == 9) Vrab04 = 2.0f;
        RECT Rect01;
        Rect01.left = (LONG)Disp0001[Vrab02].Post_X1 + Varb0008;
        Rect01.top = (LONG)Disp0001[Vrab02].Post_Y1 + Varb0009;
        statics insize Vrab03 = Spic0001[Disp0001[Vrab02].Target]; DirectX::XMFLOAT2 Flts01; RECT Rect02;
        if(Disp0001[Vrab02].Post_X3 % 90 == 0)
        {
         Rect02 = Sprt0001[Vrab03].Get_Image(Disp0001[Vrab02].Target, (Disp0001[Vrab02].Type == 5 || Disp0001[Vrab02].Type == 9)); Flts01 = Sprt0001[Vrab03].Get_Center();
         Rect01.left += rint32(Flts01.x); Rect01.top += rint32(Flts01.y);
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y2 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        } else
        {
         Rect02 = Sprt0001[Vrab03].Get_Specified(Disp0001[Vrab02].Target, (Disp0001[Vrab02].Type == 5 || Disp0001[Vrab02].Type == 9)); Flts01 = Sprt0001[Vrab03].Get_Mid();
         Rect01.left += rint32(Flts01.x) + 1; Rect01.top += rint32(Flts01.y) + 1;
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y2 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        }
        auto Effc01 = DirectX::SpriteEffects_None;
        switch(Disp0001[Vrab02].Effect){case 1: Effc01 = DirectX::SpriteEffects_FlipHorizontally; break; case 2: Effc01 = DirectX::SpriteEffects_FlipVertically; break; case 3: Effc01 = DirectX::SpriteEffects_FlipBoth; break; default: break;}
        Pics001->Draw(Imge0001[Sprt0001[Vrab03].Get_Target()].Texture, Rect01, &Rect02, DirectX::XMVECTORF32({0.0f, 0.0f, 0.0f, (rxint32(Disp0001[Vrab02].Trans) / 255) + Vrab04}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Post_X3)), Flts01, Effc01);
       }
      break;
      /*case 5: case 9: // Mirrored Sprite Image Draw
       {
        xint32 Vrab04 = 4.0f; if(Disp0001[Vrab02].Type == 9) Vrab04 = 2.0f;
        RECT Rect01;
        Rect01.left = (LONG)Disp0001[Vrab02].Post_X1 + Varb0008;
        Rect01.top = (LONG)Disp0001[Vrab02].Post_Y1 + Varb0009;
        statics insize Vrab03 = Spic0001[Disp0001[Vrab02].Target]; DirectX::XMFLOAT2 Flts01; RECT Rect02;
        if(Disp0001[Vrab02].Post_X3 % 90 == 0)
        {
         Rect02 = Sprt0001[Vrab03].Get_Image(Disp0001[Vrab02].Target); Rect02.left += 1; Rect02.right += 1; Flts01 = Sprt0001[Vrab03].Get_Center();
         Rect01.left += rint32(Flts01.x); Rect01.top += rint32(Flts01.y);
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y2 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        } else
        {
         Rect02 = Sprt0001[Vrab03].Get_Specified(Disp0001[Vrab02].Target); Rect02.left += 1; Rect02.right += 1; Flts01 = Sprt0001[Vrab03].Get_Mid();
         Rect01.left += rint32(Flts01.x) + 1; Rect01.top += rint32(Flts01.y) + 1;
         Rect01.right = Rect01.left + (LONG)Disp0001[Vrab02].Post_X2 + (Rect02.right - Rect02.left); if(Rect01.right < Rect01.left) Rect01.right = Rect01.left;
         Rect01.bottom = Rect01.top + (LONG)Disp0001[Vrab02].Post_Y2 + (Rect02.bottom - Rect02.top); if(Rect01.bottom < Rect01.top) Rect01.bottom = Rect01.top;
        }
        auto Effc01 = DirectX::SpriteEffects_None;
        switch(Disp0001[Vrab02].Effect){case 1: Effc01 = DirectX::SpriteEffects_FlipHorizontally; break; case 2: Effc01 = DirectX::SpriteEffects_FlipVertically; break; case 3: Effc01 = DirectX::SpriteEffects_FlipBoth; break; default: break;}
        Pics001->Draw(Imge0001[Sprt0001[Vrab03].Get_Target()].Texture.Get(), Rect01, &Rect02, DirectX::XMVECTORF32({0.0f, 0.0f, 0.0f, (rxint32(Disp0001[Vrab02].Trans) / 255) + Vrab04}), DirectX::XMConvertToRadians(rxint32(Disp0001[Vrab02].Post_X3)), Flts01, Effc01);
       }
      break;*/
      default: break;
     }
    }

    Pics001->End();
   }
   m_deviceResources->PIXEndEvent();
   m_deviceResources->Present();
  }
  int0 HEPTA_GAME::Clear()
  {
   m_deviceResources->PIXBeginEvent(L"Clear");
   {
    // Clear the views.
    auto statics Cont01 = m_deviceResources->GetD3DDeviceContext(); auto statics Rend01 = m_deviceResources->GetRenderTargetView(); auto statics Dept01 = m_deviceResources->GetDepthStencilView();
   
    Cont01->ClearRenderTargetView(Rend01, DirectX::Colors::Black);
    Cont01->ClearDepthStencilView(Dept01, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    Cont01->OMSetRenderTargets(1, &Rend01, Dept01);
   
    // Set the viewport.
    auto statics View01 = m_deviceResources->GetScreenViewport();
    Cont01->RSSetViewports(1, &View01);
   }
   m_deviceResources->PIXEndEvent();
  }
  
  int0 HEPTA_GAME::CreateDeviceDependentResources()
  {
   auto statics Dvis01 = m_deviceResources->GetD3DDevice(); auto statics Cont01 = m_deviceResources->GetD3DDeviceContext();
   
   Stat001 = std::make_unique < DirectX::CommonStates > (Dvis01); Stat001->DepthNone();
   Aeng001 = std::make_unique < DirectX::AudioEngine > (DirectX::AudioEngine_Default);
   Pics001 = std::make_unique < DirectX::SpriteBatch > (Cont01);
   
   D3D11_SAMPLER_DESC Desc01;
   Desc01.Filter = D3D11_FILTER_MINIMUM_MIN_MAG_MIP_POINT;
   Desc01.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
   Desc01.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
   Desc01.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
   Desc01.MipLODBias = 0.0f;
   Desc01.MaxAnisotropy = 1;
   Desc01.ComparisonFunc = D3D11_COMPARISON_NEVER;
   Desc01.BorderColor[0] = 1.0f;
   Desc01.BorderColor[1] = 1.0f;
   Desc01.BorderColor[2] = 1.0f;
   Desc01.BorderColor[3] = 1.0f;
   Desc01.MinLOD = -FLT_MAX;
   Desc01.MaxLOD = FLT_MAX;
   ThrowIfFailed(Dvis01->CreateSamplerState(&Desc01, Samp001.ReleaseAndGetAddressOf()));

   auto Hlsl01 = CSO_Read(L"Database\\Platform.cso");
   ThrowIfFailed(Dvis01->CreatePixelShader(Hlsl01.data(), Hlsl01.size(), nullptr, Grap001.ReleaseAndGetAddressOf()));
  }
  int0 HEPTA_GAME::CreateWindowSizeDependentResources()
  {

  }
 //-//
 // HEPTA_DEVICE::
  HEPTA_DEVICE::HEPTA_DEVICE(DXGI_FORMAT Dxfm01 = DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT Dxfm02 = DXGI_FORMAT_D32_FLOAT, uint32 Vrab01 = 2, D3D_FEATURE_LEVEL Dxfl01 = D3D_FEATURE_LEVEL_9_1, uint32 Vrab02 = c_FlipPresent) fastened : m_screenViewport{}, m_backBufferFormat(Dxfm01), m_depthBufferFormat(Dxfm02), m_backBufferCount(Vrab01), m_d3dMinFeatureLevel(Dxfl01), m_window(nullptr), m_d3dFeatureLevel(D3D_FEATURE_LEVEL_9_1), m_outputSize{0, 0, 1, 1}, m_colorSpace(DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709), m_options(Vrab02 | c_FlipPresent), m_deviceNotify(nullptr) {}
  
  int0 HEPTA_DEVICE::CreateDeviceResources()
  {
   uint32 Vrab01 = D3D11_CREATE_DEVICE_BGRA_SUPPORT; CreateFactory();

   // Determines whether tearing support is available for fullscreen borderless windows.
   if(m_options & c_AllowTearing)
   {
    BOOL allowTearing = FALSE;
    Microsoft::WRL::ComPtr < IDXGIFactory5 > Dxif01;
    HRESULT Hslt01 = m_dxgiFactory.As(&Dxif01);
    if(SUCCEEDED(Hslt01))
    {
     Hslt01 = Dxif01->CheckFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING, &allowTearing, sizeof(allowTearing));
    }
    if(FAILED(Hslt01) || !allowTearing)
    {
     m_options &= ~c_AllowTearing;
    }
   }

   // Disable HDR if we are on an OS that can't support FLIP swap effects.
   if(m_options & c_EnableHDR)
   {
    Microsoft::WRL::ComPtr < IDXGIFactory5 > Dxif01;
    if(FAILED(m_dxgiFactory.As(&Dxif01)))
    {
     m_options &= ~c_EnableHDR;
    }
   }

   // Disable FLIP if not on a supporting OS.
   if(m_options & c_FlipPresent)
   {
    Microsoft::WRL::ComPtr < IDXGIFactory4 > Dxif01;
    if(FAILED(m_dxgiFactory.As(&Dxif01)))
    {
     m_options &= ~c_FlipPresent;
    }
   }

   // Initializing DirectX.
   {
    // Determine DirectX hardware feature levels this app will support.
    remains statics D3D_FEATURE_LEVEL s_featureLevels[] = {D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0, D3D_FEATURE_LEVEL_9_3, D3D_FEATURE_LEVEL_9_2, D3D_FEATURE_LEVEL_9_1};
    UINT featLevelCount = 0;
    while(featLevelCount < static_cast < UINT > (std::size(s_featureLevels)))
    {
     if(s_featureLevels[featLevelCount] < m_d3dMinFeatureLevel) break; ++featLevelCount;
    }
    if(!featLevelCount) throw std::out_of_range("minFeatureLevel too high");
   
    // Create the Direct3D 11 API device object and a corresponding context.
    Microsoft::WRL::ComPtr < IDXGIAdapter1 > Dxia01; GetHardwareAdapter(Dxia01.GetAddressOf());
    Microsoft::WRL::ComPtr < ID3D11Device > Dvis01;
    Microsoft::WRL::ComPtr < ID3D11DeviceContext > Cont01;
    HRESULT Hslt01 = E_FAIL;

    if(Dxia01)
    {
     Hslt01 = D3D11CreateDevice(Dxia01.Get(),
                                D3D_DRIVER_TYPE_UNKNOWN,
                                nullptr,
                                Vrab01,
                                s_featureLevels,
                                featLevelCount,
                                D3D11_SDK_VERSION,
                                Dvis01.GetAddressOf(),  // Returns the Direct3D device created.
                                &m_d3dFeatureLevel,     // Returns feature level of device created.
                                Cont01.GetAddressOf());  // Returns the device immediate context.
    }
    #if defined(NDEBUG)
     else
     {
      MessageBox(NULL, L"No Direct3D hardware device found.", L"Graphic Error", MB_OK | MB_ICONERROR);
      throw std::runtime_error("No Direct3D hardware device found.");
     }
    #endif

    if(FAILED(Hslt01))
    {
     // If the initialization fails, fall back to the WARP device.
     // For more information on WARP, see:
     // http://go.microsoft.com/fwlink/?LinkId=286690
     Hslt01 = D3D11CreateDevice(nullptr,
                                D3D_DRIVER_TYPE_WARP, // Create a WARP device instead of a hardware device.
                                nullptr,
                                Vrab01,
                                s_featureLevels,
                                featLevelCount,
                                D3D11_SDK_VERSION,
                                Dvis01.GetAddressOf(),
                                &m_d3dFeatureLevel,
                                Cont01.GetAddressOf());
    }
    if(FAILED(Hslt01)) throw std::runtime_error("No compatible Direct3D device found.");
  
    #ifndef NDEBUG
     Microsoft::WRL::ComPtr < ID3D11Debug > Ddbg01;
     if(SUCCEEDED(Dvis01.As(&Ddbg01)))
     {
      Microsoft::WRL::ComPtr < ID3D11InfoQueue > Dinq01;
      if(SUCCEEDED(Ddbg01.As(&Dinq01)))
      {
       #ifdef _DEBUG
        Dinq01->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_CORRUPTION, true);
        Dinq01->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_ERROR, true);
       #endif
       D3D11_MESSAGE_ID Dmsg01 [] = {D3D11_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS};
       D3D11_INFO_QUEUE_FILTER Dfil01 = {};
       Dfil01.DenyList.NumIDs = static_cast<UINT>(std::size(Dmsg01));
       Dfil01.DenyList.pIDList = Dmsg01;
       Dinq01->AddStorageFilterEntries(&Dfil01);
      }
     }
    #endif

    ThrowIfFailed(Dvis01.As(&m_d3dDevice));
    ThrowIfFailed(Cont01.As(&m_d3dContext));
    ThrowIfFailed(Cont01.As(&m_d3dAnnotation));
   }
  }
  int0 HEPTA_DEVICE::CreateWindowSizeDependentResources()
  {
   if(!m_window) throw std::logic_error("Call SetWindow with a valid Win32 window handle");

   // Clear the previous window size specific context.
   {
    m_d3dContext->OMSetRenderTargets(0, nullptr, nullptr);
    m_d3dRenderTargetView.Reset();
    m_d3dDepthStencilView.Reset();
    m_renderTarget.Reset();
    m_depthStencil.Reset();
    m_d3dContext->Flush();
   }

   // Determine the render target size in pixels.
   statics UINT        backBufferWidth  = std::max < UINT > (static_cast < UINT > (m_outputSize.right - m_outputSize.left), 1u);
   statics UINT        backBufferHeight = std::max < UINT > (static_cast < UINT > (m_outputSize.bottom - m_outputSize.top), 1u);
   statics DXGI_FORMAT backBufferFormat = (m_options & (c_FlipPresent | c_AllowTearing | c_EnableHDR)) ? NoSRGB(m_backBufferFormat) : m_backBufferFormat;

   if(m_swapChain)
   {
    // If the swap chain already exists, resize it.
    HRESULT Hslt01 = m_swapChain->ResizeBuffers(m_backBufferCount,
                                                backBufferWidth,
                                                backBufferHeight,
                                                backBufferFormat,
                                                (m_options & c_AllowTearing) ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0u);

    if(Hslt01 == DXGI_ERROR_DEVICE_REMOVED || Hslt01 == DXGI_ERROR_DEVICE_RESET) // || Hslt02 == DXGI_ERROR_DEVICE_REMOVED || Hslt02 == DXGI_ERROR_DEVICE_RESET)
    {
     #ifdef _DEBUG
      {
       int8 Vect01[64] = {};
       sprintf_s(Vect01, "Device Lost on ResizeBuffers: Reason code 0x%08X\n",
       ruint32((Hslt01 == DXGI_ERROR_DEVICE_REMOVED) ? m_d3dDevice->GetDeviceRemovedReason() : Hslt01));
       OutputDebugStringA(Vect01);
      }
     #endif

     // If the device was removed for any reason, a new device and swap chain will need to be created.
     HandleDeviceLost();

     // Everything is set up now. Do not continue execution of this method. HandleDeviceLost will reenter this method and correctly set up the new device.
     return;
    } else {ThrowIfFailed(Hslt01);}
   } else
   {
    DXGI_SWAP_CHAIN_DESC1 Dxsc01 = {};
    Dxsc01.Width = backBufferWidth;
    Dxsc01.Height = backBufferHeight;
    Dxsc01.Format = backBufferFormat;
    Dxsc01.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    Dxsc01.BufferCount = m_backBufferCount;
    Dxsc01.SampleDesc.Count = 1;
    Dxsc01.SampleDesc.Quality = 0;
    Dxsc01.Scaling = DXGI_SCALING_STRETCH;
    Dxsc01.SwapEffect = (m_options & (c_FlipPresent | c_AllowTearing | c_EnableHDR)) ? DXGI_SWAP_EFFECT_FLIP_DISCARD : DXGI_SWAP_EFFECT_DISCARD;
    Dxsc01.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
    Dxsc01.Flags = (m_options & c_AllowTearing) ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0u;

    DXGI_SWAP_CHAIN_FULLSCREEN_DESC Dxsf01 = {};
    Dxsf01.Windowed = TRUE;

    ThrowIfFailed(m_dxgiFactory->CreateSwapChainForHwnd(m_d3dDevice.Get(), m_window, &Dxsc01, &Dxsf01, nullptr, m_swapChain.ReleaseAndGetAddressOf()));

    // This class does not support exclusive full-screen mode and prevents DXGI from responding to the ALT+ENTER shortcut.
    ThrowIfFailed(m_dxgiFactory->MakeWindowAssociation(m_window, DXGI_MWA_NO_ALT_ENTER));
   }

   // Handle color space settings for HDR.
   UpdateColorSpace();

   // Create a render target view of the swap chain back buffer.
   ThrowIfFailed(m_swapChain->GetBuffer(0, IID_PPV_ARGS(m_renderTarget.ReleaseAndGetAddressOf())));

   CD3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDesc(D3D11_RTV_DIMENSION_TEXTURE2D, m_backBufferFormat);
   ThrowIfFailed(m_d3dDevice->CreateRenderTargetView(m_renderTarget.Get(), &renderTargetViewDesc, m_d3dRenderTargetView.ReleaseAndGetAddressOf()));

   if(m_depthBufferFormat != DXGI_FORMAT_UNKNOWN)
   {
    // Create a depth stencil view for use with 3D rendering if needed.
    CD3D11_TEXTURE2D_DESC depthStencilDesc(m_depthBufferFormat,
                                          backBufferWidth,
                                          backBufferHeight,
                                          1, // This depth stencil view has only one texture.
                                          1, // Use a single mipmap level.
                                          D3D11_BIND_DEPTH_STENCIL);

    ThrowIfFailed(m_d3dDevice->CreateTexture2D(&depthStencilDesc, nullptr, m_depthStencil.ReleaseAndGetAddressOf()));
    ThrowIfFailed(m_d3dDevice->CreateDepthStencilView(m_depthStencil.Get(), nullptr, m_d3dDepthStencilView.ReleaseAndGetAddressOf()));
   }

   m_screenViewport = {0.f, 0.f, rxint32(backBufferWidth), rxint32(backBufferHeight), 0.f, 0.f };
  }

  int0 HEPTA_DEVICE::SetWindow(HWND Hwnd01, uint32 Vrab01, uint32 Vrab02) fastened
  {
   m_window = Hwnd01; m_outputSize.left = m_outputSize.top = 0; m_outputSize.right = Vrab01; m_outputSize.bottom = Vrab02;
  }
  int0 HEPTA_DEVICE::HandleDeviceLost()
  {
   if(m_deviceNotify) m_deviceNotify->OnDeviceLost();
  
   m_d3dDepthStencilView.Reset();
   m_d3dRenderTargetView.Reset();
   m_renderTarget.Reset();
   m_depthStencil.Reset();
   m_swapChain.Reset();
   m_d3dContext.Reset();
   m_d3dAnnotation.Reset();
   m_d3dDevice.Reset();
   m_dxgiFactory.Reset();

   CreateDeviceResources();
   CreateWindowSizeDependentResources();

   if(m_deviceNotify) m_deviceNotify->OnDeviceRestored();
  }
  int0 HEPTA_DEVICE::GetHardwareAdapter(IDXGIAdapter1** Dxad01)
  {
   *Dxad01 = nullptr;
   Microsoft::WRL::ComPtr < IDXGIAdapter1 > Dxad02;
   Microsoft::WRL::ComPtr < IDXGIFactory6 > Dxfc01;
   HRESULT Hslt01 = m_dxgiFactory.As(&Dxfc01);
   if(SUCCEEDED(Hslt01))
   {
    for(uint32 Vrab01 = 0; SUCCEEDED(Dxfc01->EnumAdapterByGpuPreference(Vrab01, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(Dxad02.ReleaseAndGetAddressOf()))); Vrab01++)
    {
     DXGI_ADAPTER_DESC1 desc;
     ThrowIfFailed(Dxad02->GetDesc1(&desc));
    
     // Don't select the Basic Render Driver adapter.
     if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;

     #ifdef _DEBUG
      wchar_t Vect01[256] = {};
      swprintf_s(Vect01, L"Direct3D Dxad02 (%u): VID:%04X, PID:%04X - %ls\n", Vrab01, desc.VendorId, desc.DeviceId, desc.Description);
      OutputDebugStringW(Vect01);
     #endif

     break;
    }
   }

   if(!Dxad02)
   {
    for(uint32 Vrab01 = 0; SUCCEEDED(m_dxgiFactory->EnumAdapters1(Vrab01, Dxad02.ReleaseAndGetAddressOf())); Vrab01++)
    {
     DXGI_ADAPTER_DESC1 desc;
     ThrowIfFailed(Dxad02->GetDesc1(&desc));
    
     // Don't select the Basic Render Driver adapter.
     if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;
            
     #ifdef _DEBUG
      wchar_t Vect01[256] = {};
      swprintf_s(Vect01, L"Direct3D Dxad02 (%u): VID:%04X, PID:%04X - %ls\n", Vrab01, desc.VendorId, desc.DeviceId, desc.Description);
      OutputDebugStringW(Vect01);
     #endif

    break;
    }
   }

   *Dxad01 = Dxad02.Detach();
  }

  int0 HEPTA_DEVICE::Present()
  {
   HRESULT Hslt01 = E_FAIL;

   if(m_options & c_AllowTearing)
   {Hslt01 = m_swapChain->Present(0, DXGI_PRESENT_ALLOW_TEARING);} else
   {Hslt01 = m_swapChain->Present(1, 0);}

   m_d3dContext->DiscardView(m_d3dRenderTargetView.Get());
   if(m_d3dDepthStencilView) m_d3dContext->DiscardView(m_d3dDepthStencilView.Get());

   if(Hslt01 == DXGI_ERROR_DEVICE_REMOVED || Hslt01 == DXGI_ERROR_DEVICE_RESET)
   {HandleDeviceLost();} else
   {ThrowIfFailed(Hslt01); if(!m_dxgiFactory->IsCurrent()) UpdateColorSpace();}
  }
  int0 HEPTA_DEVICE::UpdateColorSpace()
  {
   if(!m_dxgiFactory) return;
   if(!m_dxgiFactory->IsCurrent()) CreateFactory();
   
   int1 Vrab01 = false;
   if(m_swapChain)
   {
    RECT Rect01; if(!GetWindowRect(m_window, &Rect01)) throw std::system_error(std::error_code(rint32(GetLastError()), std::system_category()), "GetWindowRect");
    statics lint32 Vrab02 = Rect01.left, Vrab03 = Rect01.top, Vrab04 = Rect01.right, Vrab05 = Rect01.bottom;

    lint32 Vrab06 = -1; Microsoft::WRL::ComPtr < IDXGIOutput > Dxou01; Microsoft::WRL::ComPtr < IDXGIAdapter > Dxad02;
    for(uint32 Vrab07 = 0; SUCCEEDED(m_dxgiFactory->EnumAdapters(Vrab07, Dxad02.ReleaseAndGetAddressOf())); ++Vrab07)
    {
     Microsoft::WRL::ComPtr < IDXGIOutput > Dxou02;
     for(uint32 Vrab08 = 0; SUCCEEDED(Dxad02->EnumOutputs(Vrab08, Dxou02.ReleaseAndGetAddressOf())); ++Vrab08)
     {
      // Get the rectangle bounds of current output.
      DXGI_OUTPUT_DESC Dxod01; ThrowIfFailed(Dxou02->GetDesc(&Dxod01));
      statics auto& Rect02 = Dxod01.DesktopCoordinates;
 
      // Compute the intersection.
      statics lint32 Vrab09 = ComputeIntersectionArea(Vrab02, Vrab03, Vrab04, Vrab05, Rect02.left, Rect02.top, Rect02.right, Rect02.bottom);
      if(Vrab09 > Vrab06){Dxou01.Swap(Dxou02); Vrab06 = Vrab09;}
     }
    }

    if(Dxou01)
    {
     Microsoft::WRL::ComPtr<IDXGIOutput6> Dxou02;
     if(SUCCEEDED(Dxou01.As(&Dxou02)))
     {
      DXGI_OUTPUT_DESC1 Dxod01; ThrowIfFailed(Dxou02->GetDesc1(&Dxod01));
     
      // Check if Display output is HDR10.
      if(Dxod01.ColorSpace == DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020) Vrab01 = true;
     }
    }
   }

   DXGI_COLOR_SPACE_TYPE Dxcs01 = DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709;
   if((m_options & c_EnableHDR) && Vrab01)
   switch(m_backBufferFormat)
   {
    case DXGI_FORMAT_R10G10B10A2_UNORM: // The application creates the HDR10 signal.
     Dxcs01 = DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020;
    break;
    case DXGI_FORMAT_R16G16B16A16_FLOAT: // The system creates the HDR10 signal; application uses linear values.
     Dxcs01 = DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709;
    break;
    default: break;
   }
   m_colorSpace = Dxcs01;

   Microsoft::WRL::ComPtr < IDXGISwapChain3 > Dxch01;
   if(m_swapChain && SUCCEEDED(m_swapChain.As(&Dxch01)))
   {uint32 Vrab02 = 0; if(SUCCEEDED(Dxch01->CheckColorSpaceSupport(Dxcs01, &Vrab02)) && (Vrab02 & DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT)) ThrowIfFailed(Dxch01->SetColorSpace1(Dxcs01));}
  }
  int0 HEPTA_DEVICE::CreateFactory()
  {
   #if defined(_DEBUG) && (_WIN32_WINNT >= 0x0603 /*_WIN32_WINNT_WINBLUE*/)
    int1 Vrab01 = false;
    {
     Microsoft::WRL::ComPtr < IDXGIInfoQueue > Dxiq01;
     if(SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(Dxiq01.GetAddressOf()))))
     {
      Vrab01 = true;
      ThrowIfFailed(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(m_dxgiFactory.ReleaseAndGetAddressOf())));
 
      Dxiq01->SetBreakOnSeverity(DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_ERROR, true);
      Dxiq01->SetBreakOnSeverity(DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_CORRUPTION, true);

      // IDXGISwapChain::GetContainingOutput: The swapchain's Dxad02 does not control the output on which the swapchain's window resides.
      DXGI_INFO_QUEUE_MESSAGE_ID Dxmg01[] = {80};
      DXGI_INFO_QUEUE_FILTER Dxfl01 = {};
      Dxfl01.DenyList.NumIDs = static_cast < UINT > (std::size(Dxmg01));
      Dxfl01.DenyList.pIDList = Dxmg01;
      Dxiq01->AddStorageFilterEntries(DXGI_DEBUG_DXGI, &Dxfl01);
     }
    }

    if(!Vrab01)
   #endif

   ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(m_dxgiFactory.ReleaseAndGetAddressOf())), "CreateDXGIFactory1");
  }
  int1 HEPTA_DEVICE::WindowSizeChanged(uint32 Vrab01, uint32 Vrab02)
  {
   Varb0017 = Vrab01; Varb0018 = Vrab02;
   RECT Rect01; Rect01.left = Rect01.top = 0; Varb0008 = 0; Varb0009 = 0;
   statics xint64 Vrab05 = rxint64(Vrab01) / rxint64(Varb0002);
   statics xint64 Vrab06 = rxint64(Vrab02) / rxint64(Varb0003);
   if(Varb0005)
   {
    if(Vrab05 != Vrab06)
    {
     if(Vrab05 > Vrab06)
     {
      Rect01.right = L_Rounding(rxint64(Varb0002) / (Vrab06 * (rxint64(Varb0002) / rxint64(Vrab01)))); Rect01.bottom = Varb0003; Varb0008 = L_Rounding(rxint64(ruint64(Rect01.right) - Varb0002) / 2);
     } else
     {
      Rect01.bottom = L_Rounding(rxint64(Varb0003) / (Vrab05 * (rxint64(Varb0003) / rxint64(Vrab02)))); Rect01.right = Varb0002; Varb0009 = L_Rounding(rxint64(ruint64(Rect01.bottom) - Varb0003) / 2);
     }
    } else
    {
     Rect01.right = Varb0002; Rect01.bottom = Varb0003;
    }
    if(Vrab05 < Vrab06)
    {Varb0010 = Varb0011 = Vrab05;} else {Varb0010 = Varb0011 = Vrab06;}
   } else
   {
    Rect01.right = Varb0002; Rect01.bottom = Varb0003;
    Varb0010 = Vrab05; Varb0011 = Vrab06;
   }

   if(m_outputSize == Rect01)
   {
    // Handle color space settings for HDR
    UpdateColorSpace(); return false;
   }
   m_outputSize = Rect01;
   CreateWindowSizeDependentResources();
   return true;
  }
 //-//
//-//

// Windows' Window
 LRESULT CALLBACK wWinCall(HWND Hwnd01, UINT Vrab01, WPARAM Wpar01, LPARAM Lpar01)
 {
  remains int1 Vrab02 = false, // in sizemove.
  Vrab03 = false,              // in suspend.
  Vrab04 = false;              // minimized.

  auto Game01 = reinterpret_cast < HEPTA_GAME* > (GetWindowLongPtr(Hwnd01, GWLP_USERDATA));
  
  switch(Vrab01)
  {
   case WM_PAINT:
    if(Vrab02 && Game01){Game01->Tick();} else
    {PAINTSTRUCT ps; std::ignore = BeginPaint(Hwnd01, &ps); EndPaint(Hwnd01, &ps);}
   break;
   case WM_DISPLAYCHANGE:
    if(Game01) Game01->OnDisplayChange();
   break;
   case WM_MOVE:
    if(Game01) Game01->OnWindowMoved();
   break;
   case WM_SIZE:
    if(Wpar01 == SIZE_MINIMIZED)
    {if(!Vrab04){Vrab04 = true; if(!Vrab03 && Game01) Game01->OnSuspending(); Vrab03 = true;}} else
    {
     if(Vrab04){Vrab04 = false; if(Vrab03 && Game01) Game01->OnResuming(); Vrab03 = false;} else
     {if(!Vrab02 && Game01){Game01->OnWindowSizeChanged(LOWORD(Lpar01), HIWORD(Lpar01));}}
    }
   break;
   case WM_ENTERSIZEMOVE: Vrab02 = true; break;
   case WM_EXITSIZEMOVE:
    Vrab02 = false;
    if(Game01){RECT Rect01; GetClientRect(Hwnd01, &Rect01); Game01->OnWindowSizeChanged(Rect01.right - Rect01.left, Rect01.bottom - Rect01.top);}
   break;
   case WM_GETMINMAXINFO:
    if(Lpar01){auto Info01 = reinterpret_cast < MINMAXINFO* > (Lpar01); Info01->ptMinTrackSize.x = 320; Info01->ptMinTrackSize.y = 200;}
   break;
   case WM_ACTIVATEAPP:
    DirectX::Keyboard::ProcessMessage(Vrab01, Wpar01, Lpar01);
    DirectX::Mouse::ProcessMessage(Vrab01, Wpar01, Lpar01);
    if(Game01){if(Wpar01){Game01->OnActivated();} else {Game01->OnDeactivated();}}
   break;
   case WM_POWERBROADCAST:
    switch(Wpar01)
    {
     case PBT_APMQUERYSUSPEND:
      if(!Vrab03 && Game01) Game01->OnSuspending(); Vrab03 = true;
      return TRUE;
     case PBT_APMRESUMESUSPEND:
      if(!Vrab04){if(Vrab03 && Game01) Game01->OnResuming(); Vrab03 = false;}
      return TRUE;
    }
   break;
   case WM_DESTROY: PostQuitMessage(0); break;
   case WM_ACTIVATE:
   case WM_INPUT:
   case WM_MOUSEMOVE:
   case WM_LBUTTONDOWN:
   case WM_LBUTTONUP:
   case WM_RBUTTONDOWN:
   case WM_RBUTTONUP:
   case WM_MBUTTONDOWN:
   case WM_MBUTTONUP:
   case WM_XBUTTONDOWN:
   case WM_XBUTTONUP:
   case WM_MOUSEWHEEL:
   case WM_MOUSEHOVER:
    DirectX::Mouse::ProcessMessage(Vrab01, Wpar01, Lpar01);
   break;
   case WM_KEYDOWN:
   case WM_KEYUP:
   case WM_SYSKEYUP:
    DirectX::Keyboard::ProcessMessage(Vrab01, Wpar01, Lpar01);
   break;
   case WM_SYSKEYDOWN:
    if(Wpar01 == VK_F4 && (Lpar01 & 0x60000000) == 0x20000000){PostQuitMessage(0); break;}
    if(Wpar01 == VK_RETURN && (Lpar01 & 0x60000000) == 0x20000000) // Implements the classic ALT+ENTER fullscreen toggle.
    {G_ToggleFullscreen();} else {DirectX::Keyboard::ProcessMessage(Vrab01, Wpar01, Lpar01);}
   return 0;
   case WM_MOUSEACTIVATE: // When you click activate the window, we want Mouse to ignore it.
    return MA_ACTIVATEANDEAT;
   case WM_MENUCHAR:      // A menu is active and the user presses a key that does not correspond to any mnemonic or accelerator key. Ignore so we don't produce an error beep.
    return MAKELRESULT(0, MNC_CLOSE);
  }
  return DefWindowProc(Hwnd01, Vrab01, Wpar01, Lpar01);
 }
 int32   WINAPI   wWinMain(_In_ HINSTANCE Hins01, _In_opt_ HINSTANCE Hins02, _In_ LPWSTR Lpws01, _In_ int32 Vrab01)
 {
  UNREFERENCED_PARAMETER(Hins02); UNREFERENCED_PARAMETER(Lpws01);

  if(!DirectX::XMVerifyCPUSupport()) return 1;
  if(FAILED(CoInitializeEx(nullptr, COINITBASE_MULTITHREADED))) return 1;

  Game0001 = std::make_unique < HEPTA_GAME > ();
  
  // Register class and create window.
  {
   WNDCLASSEXW Wind01 = {};
   Wind01.cbSize = sizeof(WNDCLASSEXW);
   Wind01.style = CS_HREDRAW | CS_VREDRAW;
   Wind01.lpfnWndProc = wWinCall;
   Wind01.hInstance = Hins01;
   Wind01.hIcon = LoadIconW(Hins01, L"IDI_ICON");
   Wind01.hCursor = LoadCursorW(nullptr, IDC_ARROW);
   Wind01.hbrBackground = reinterpret_cast < HBRUSH > (COLOR_WINDOW + 1);
   Wind01.lpszClassName = L"EnchantedWindowClass";
   Wind01.hIconSm = LoadIconW(Hins01, L"IDI_ICON");
   if(!RegisterClassExW(&Wind01)) return 1;

   uint32 Vrab02 = Varb0002, Vrab03 = Varb0003;
   RECT Rect01 = {0, 0, static_cast < LONG > (Vrab02), static_cast < LONG > (Vrab03)};
   
   AdjustWindowRect(&Rect01, WS_OVERLAPPEDWINDOW, FALSE);
   HWND Hwnd01 = CreateWindowExW(0, Wind01.lpszClassName, L"Hepta : Enchanted", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, Rect01.right - Rect01.left, Rect01.bottom - Rect01.top, nullptr, nullptr, Hins01, nullptr);
   if(!Hwnd01) return 1; ShowWindow(Hwnd01, Vrab01);

   // Quit if main Shader isn't found.
   {
    std::ifstream File01("Database\\Platform.cso");
    if(!File01.is_open()){MessageBox(NULL, L"\"Database\\Platform.cso\" was not found. Reinstalling the program may fix this problem.", L"Graphic Error", MB_OK | MB_ICONERROR); return rint32(WM_QUIT);}
    File01.close();
   }

   SetWindowLongPtrW(Hwnd01, GWLP_USERDATA, reinterpret_cast < LONG_PTR > (Game0001.get())); GetClientRect(Hwnd01, &Rect01);
   Game0001->Initialize(Hwnd01, Rect01.right - Rect01.left, Rect01.bottom - Rect01.top);
  }

  // DirectX's main configuration.
  {
   statics uint32 Vrab04 = 0;
   D3D11_SUBRESOURCE_DATA Sdat01 = {&Vrab04, sizeof(uint32), 0};
   D3D11_TEXTURE2D_DESC Desc01;
   memset(&Desc01, 0, sizeof(Desc01));
   Desc01.Width = Desc01.Height = Desc01.MipLevels = Desc01.ArraySize = 1;
   Desc01.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
   Desc01.SampleDesc.Count = 1;
   Desc01.Usage = D3D11_USAGE_IMMUTABLE;
   Desc01.BindFlags = D3D11_BIND_SHADER_RESOURCE;

   Microsoft::WRL::ComPtr < ID3D11Texture2D > Text01;
   ThrowIfFailed(Game0001->m_deviceResources->GetD3DDevice()->CreateTexture2D(&Desc01, &Sdat01, &Text01), "CreateTexture2D");

   D3D11_SHADER_RESOURCE_VIEW_DESC Vdec01;
   memset(&Vdec01, 0, sizeof(Vdec01));
   Vdec01.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
   Vdec01.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
   Vdec01.Texture2D.MipLevels = 1;

   ThrowIfFailed(Game0001->m_deviceResources->GetD3DDevice()->CreateShaderResourceView(Text01.Get(), &Vdec01, Game0001->GetRect()));
  }

  // Main message loop.
  {
   MSG Mssg01 = {};
   while (WM_QUIT != Mssg01.message)
   {
    if(PeekMessage(&Mssg01, nullptr, 0, 0, PM_REMOVE))
    {
     TranslateMessage(&Mssg01);
     DispatchMessage(&Mssg01);
    } else
    {
     Game0001->Tick();
    }
   }
   Game0001.reset(); CoUninitialize();
   return rint32(Mssg01.wParam);
  }
 }
//-//