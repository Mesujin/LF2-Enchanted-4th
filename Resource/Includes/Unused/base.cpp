////////////////////////////////////////////////////////////////////////////////////////////
// base.cpp                                                                               //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////

// Commands
 #include "engine.h"
 //#include "base.h"

 extern int0 ExitGame() noexcept;
//-//

Game::Game() noexcept(false)
{
 m_deviceResources = std::make_unique < DX::DeviceResources > ();
 
 // TODO: Provide parameters for swapchain format, depth/stencil format, and backbuffer count.
 //   Add DX::DeviceResources::c_AllowTearing to opt-in to variable rate displays.
 //   Add DX::DeviceResources::c_EnableHDR for HDR10 display.

 m_deviceResources->RegisterDeviceNotify(this);
}

// Initialize the Direct3D resources required to run.
int0 Game::Initialize(HWND window, uint32 width, uint32 height)
{
 m_deviceResources->SetWindow(window, width, height);
 m_deviceResources->CreateDeviceResources();
 CreateDeviceDependentResources();
 m_deviceResources->CreateWindowSizeDependentResources();
 CreateWindowSizeDependentResources();

 // TODO: Change the timer settings if you want something other than the default variable timestep mode.
 // e.g. for 60 FPS fixed timestep update logic, call:
 m_timer.SetFixedTimeStep(false);
 m_timer.SetTargetElapsedTicks(120);
    
 m_keyboard = std::make_unique<Keyboard>();
 m_gamepad = std::make_unique<GamePad>();
 m_mouse = std::make_unique<Mouse>();
 m_mouse->SetWindow(window);
}

#pragma region Frame Update
 // Executes the basic game loop.
 int0 Game::Tick()
 {
  m_timer.Tick([&](){Update(m_timer);});
  Render();
  // if(m_timer.GetFrameCount() % 150 == 0){soundEffect = std::make_unique < DirectX::SoundEffect > (audEngine.get(), L"Sound.wav"); soundEffect->CreateInstance()->Play(true);}
  if(audEngine->Update())
  {
  } else
  {audEngine->IsCriticalError();} 
 }

 // Updates the world.
 int0 Game::Update(DX::StepTimer const &timer)
 {
  Engine_Input(&m_keyboard, &m_gamepad, &m_mouse);
  Engine_Main(timer.GetElapsedSeconds(), timer.GetTotalSeconds(), timer.GetFrameCount(), timer.GetFramesPerSecond());
 }
#pragma endregion

#pragma region Frame Render
 // Draws the scene.
 int0 Game::Render()
 {
  // Don't try to render anything before the first Update.
  if(m_timer.GetFrameCount() == 0) return; Clear();
  if(Varb0007){DisplayStack.clear(); return;}

  m_deviceResources->PIXBeginEvent(L"Render");
  auto Cont01 = m_deviceResources->GetD3DDeviceContext();
  auto Devs01 = m_deviceResources->GetD3DDevice();
 
  if(Varb0008)
  {
  uint32 Vrab01 = DisplayingSize.Width;
  uint32 Vrab02 = DisplayingSize.Height;
  std::vector < uint32 > Vect01;
  Engine_Display();
  ////////////////////////////////////////////////////////////////////
  {
   uint32 Vrab08 = Varb0003 - 1; uint32 Vrab09 = Varb0002 - 1;
   if(Varb0005)
   {
    const xint64 Vrab03 = rxint64(Varb0002) / rxint64(Vrab01);
    const xint64 Vrab04 = rxint64(Varb0003) / rxint64(Vrab02);
    if(Vrab03 != Vrab04)
    {
     if(Vrab03 > Vrab04)
     {Vrab02 = INT32Rounding(rxint64(Varb0003) * Vrab03 * (rxint64(Vrab02) / rxint64(Varb0003))); Vrab01 = Varb0002;} else
     {Vrab01 = INT32Rounding(rxint64(Varb0002) * Vrab04 * (rxint64(Vrab01) / rxint64(Varb0002))); Vrab02 = Varb0003;}
     Vrab08 = (Vrab02 / 2) + (Varb0003 / 2) - 1; Vrab09 = (Vrab01 / 2) + (Varb0002 / 2) - 1;
    } else
    {Vrab01 = Varb0002; Vrab02 = Varb0003;}
   }
   Vect01.resize(Vrab01 * Vrab02);
   uint32 Vrab03 = Varb0003 - 1; uint32 Vrab06 = Vrab08;
   while(Vrab03 != 4294967295)
   {
    const uint32 Vrab04 = Vrab06 * Vrab01;
    uint32 Vrab05 = Varb0002 - 1; uint32 Vrab07 = Vrab09;
    while(Vrab05 != 4294967295)
    {
     Vect01[Vrab04 + Vrab07] = ruint32(Display[Vrab05][Vrab03].Blue) + (ruint32(Display[Vrab05][Vrab03].Green) << 8) + (ruint32(Display[Vrab05][Vrab03].Red) << 16);
     Vrab05 -= 1; Vrab07 -= 1;
    }
    Vrab03 -= 1; Vrab06 -= 1;
   }
  }
  /*
  if(Varb0006 && Vrab01 >= Varb0002 && Vrab02 >= Varb0003)
  {
   uint32 Vrab03 = 0; uint32 Vrab04 = 0; uint32 Vrab05 = 0; uint32 Vrab06 = 0; uint32 Vrab07 = 0;
   Vrab03 = Varb0003 - 1; Vrab05 = (Vrab01 / 2) + (Varb0003 / 2) - 1;
   while(Vrab03 != 4294967295)
   {
    Vrab07 = Vrab01 * Vrab05;
    Vrab04 = Varb0002 - 1; Vrab06 = (Vrab02 / 2) + (Varb0002 / 2) - 1;
    while(Vrab04 != 4294967295)
    {
     Vect01[Vrab07 + Vrab05] = ruint32(Display[Vrab04][Vrab03].Blue) + (ruint32(Display[Vrab04][Vrab03].Green) << 8) + (ruint32(Display[Vrab04][Vrab03].Red) << 16);
     Vrab04 -= 1; Vrab06 -= 1;
    }
    Vrab03 -= 1; Vrab05 -= 1;
   }
  } else
  {
   uint32 Vrab03 = 0; uint32 Vrab04 = 0; uint32 Vrab05 = 0; uint32 Vrab06 = 0; uint32 Vrab07 = 0; xint64 Vrab08 = 0; xint64 Vrab09 = 0;
   if(Varb0005)
   {
    Vrab08 = rxint64(Varb0002) / rxint64(Vrab01);
    Vrab09 = rxint64(Varb0003) / rxint64(Vrab02);
    if(Vrab08 != Vrab09)
    {
     if(Vrab08 > Vrab09)
     {Vrab02 = INT32Rounding(rxint64(Varb0003) * Vrab08 * (rxint64(Vrab02) / rxint64(Varb0003))); Vrab01 = Varb0002;} else
     {Vrab01 = INT32Rounding(rxint64(Varb0002) * Vrab09 * (rxint64(Vrab01) / rxint64(Varb0002))); Vrab02 = Varb0003;}
     
     Vect01.resize(Vrab01 * Vrab02);
     Vrab03 = Varb0003 - 1; Vrab05 = (Vrab01 / 2) + (Varb0003 / 2) - 1;
     while(Vrab03 != 4294967295)
     {
      Vrab07 = Vrab01 * Vrab05;
      Vrab04 = Varb0002 - 1; Vrab06 = (Vrab02 / 2) + (Varb0002 / 2) - 1;
      while(Vrab04 != 4294967295)
      {
       Vect01[Vrab07 + Vrab05] = ruint32(Display[Vrab04][Vrab03].Blue) + (ruint32(Display[Vrab04][Vrab03].Green) << 8) + (ruint32(Display[Vrab04][Vrab03].Red) << 16);
       Vrab04 -= 1; Vrab06 -= 1;
      }
      Vrab03 -= 1; Vrab05 -= 1;
     }
    } else
    {
     Vrab01 = Varb0002;
     Vrab02 = Varb0003;
     Vrab03 = Vrab01 * Vrab02; Vect01.resize(Vrab03);
     for(Vrab04 = 0; Vrab04 < Vrab02; ++Vrab04)
     {
      Vrab06 = Vrab04 * Vrab02;
      for(Vrab05 = 0; Vrab05 < Vrab01; ++Vrab05)
      Vect01[Vrab06 + Vrab05] = ruint32(Display[Vrab05][Vrab04].Blue) + (ruint32(Display[Vrab05][Vrab04].Green) << 8) + (ruint32(Display[Vrab05][Vrab04].Red) << 16);
     }
    }
   } else
   {
    Vrab01 = Varb0002;
    Vrab02 = Varb0003;
    Vrab03 = Vrab01 * Vrab02; Vect01.resize(Vrab03);
    for(Vrab04 = 0; Vrab04 < Vrab02; ++Vrab04)
    {
     Vrab06 = Vrab04 * Vrab02;
     for(Vrab05 = 0; Vrab05 < Vrab01; ++Vrab05)
     Vect01[Vrab06 + Vrab05] = ruint32(Display[Vrab05][Vrab04].Blue) + (ruint32(Display[Vrab05][Vrab04].Green) << 8) + (ruint32(Display[Vrab05][Vrab04].Red) << 16);
    }
   }
  }*/
  ////////////////////////////////////////////////////////////////////

  sTexDesc.Width = Vrab01; sTexDesc.Height = Vrab02;
  tbsd.pSysMem = static_cast < int0* > (&Vect01[0]);
  tbsd.SysMemPitch = Vrab01;
  DX::ThrowIfFailed(Devs01->CreateTexture2D(&sTexDesc, &tbsd, &tex));
 
  D3D11_MAPPED_SUBRESOURCE mappedResource; ZeroMemory(&mappedResource, sizeof(D3D11_MAPPED_SUBRESOURCE));
  Cont01->Map(tex, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
  BYTE* mappedData = reinterpret_cast < BYTE* > (mappedResource.pData);
  for(uint32 Vrab03 = 0; Vrab03 < Vrab02; ++Vrab03)
  {
   memcpy(mappedData, &Vect01[Vrab03 * Vrab01], mappedResource.RowPitch);
   mappedData += mappedResource.RowPitch;
  }
  Cont01->Unmap(tex, 0);
 
  DX::ThrowIfFailed(m_deviceResources->GetD3DDevice()->CreateShaderResourceView(tex, nullptr, m_texture.ReleaseAndGetAddressOf()));
  postProcess->SetSourceTexture(m_texture.Get());
  postProcess->SetEffect(BasicPostProcess::Copy);
  postProcess->Process(Cont01);
  tex->Release();
  Vect01.clear();
  } else
  {
   Engine_Display();
  }
 
  m_deviceResources->PIXEndEvent();
  m_deviceResources->Present();
 }
 
 // Helper method to clear the back buffers.
 int0 Game::Clear()
 {
  m_deviceResources->PIXBeginEvent(L"Clear");
 
  // Clear the views.
  auto context = m_deviceResources->GetD3DDeviceContext();
  auto renderTarget = m_deviceResources->GetRenderTargetView();
  auto depthStencil = m_deviceResources->GetDepthStencilView();
 
  context->ClearRenderTargetView(renderTarget, Colors::CornflowerBlue);
  context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
  context->OMSetRenderTargets(1, &renderTarget, depthStencil);
 
  // Set the viewport.
  auto const viewport = m_deviceResources->GetScreenViewport();
  context->RSSetViewports(1, &viewport);
 
  m_deviceResources->PIXEndEvent();
 }
#pragma endregion

#pragma region Message Handlers
 // Message handlers
 int0 Game::OnActivated()   // Game is becoming active window.
 {
  Varb0007 = false;
 }
 int0 Game::OnDeactivated() // Game is becoming background window.
 {

 }
 int0 Game::OnSuspending()  // Game is being power-suspended (or minimized).
 {
  Varb0007 = true;
 }
 int0 Game::OnResuming()    // Game is being power-resumed (or returning from minimize).
 {
  m_timer.ResetElapsedTime();
  Varb0007 = false;
 }
 int0 Game::OnWindowMoved()
 {
  auto const Vrab01 = m_deviceResources->GetOutputSize(); m_deviceResources->WindowSizeChanged(Vrab01.right, Vrab01.bottom);
 }
 int0 Game::OnDisplayChange()
 {
  m_deviceResources->UpdateColorSpace();
 }
 int0 Game::OnWindowSizeChanged(uint32 width, uint32 height) // Game window is being resized.
 {
  if(!m_deviceResources->WindowSizeChanged(width, height)) return;
  CreateWindowSizeDependentResources();
 }
 
 // Properties
 int0 Game::GetDefaultSize(uint32 &width, uint32 &height) const noexcept {width = Varb0002; height = Varb0003;}
#pragma endregion
 
#pragma region Direct3D Resources
 // These are the resources that depend on the device.
 int0 Game::CreateDeviceDependentResources()
 {
  auto device = m_deviceResources->GetD3DDevice();
  auto context = m_deviceResources->GetD3DDeviceContext();

  postProcess = std::make_unique < DirectX::BasicPostProcess > (device);
  m_spriteBatch = std::make_unique < SpriteBatch > (context);

   DX::ThrowIfFailed(CreateWICTextureFromFile(m_d3dDevice.Get(), L"Database\\Sprite\\Template\\template_0.bmp", nullptr, m_texture.ReleaseAndGetAddressOf()));
   const insize Vrab05 = m_source.size(); m_source.resize(Vrab05 + 1);
   m_source[Vrab05] = std::make_unique<AnimatedTexture>(); m_source[Vrab05]->Load(m_texture.Get(), 4, 20);
 
  uint32 Vrab01 = Varb0002; uint32 Vrab02 = Varb0003;
  uint32 *Vrab03 = new uint32 [Vrab01 * Vrab02];
 
  tbsd.pSysMem = static_cast < int0* > (Vrab03);
  tbsd.SysMemPitch = 4;
 
  sTexDesc.Width = Vrab01;
  sTexDesc.Height = Vrab02;
  sTexDesc.MipLevels = 1;
  sTexDesc.ArraySize = 1;
  sTexDesc.Format = DXGI_FORMAT_B8G8R8X8_UNORM;
  sTexDesc.SampleDesc.Count = 1;
  sTexDesc.SampleDesc.Quality = 0;
  sTexDesc.Usage = D3D11_USAGE_DYNAMIC;
  sTexDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
  sTexDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
  sTexDesc.MiscFlags = 0;
 
  DX::ThrowIfFailed(device->CreateTexture2D(&sTexDesc, &tbsd, &tex));
  
  AUDIO_ENGINE_FLAGS eflags = AudioEngine_Default;
  #ifdef _DEBUG
   eflags |= AudioEngine_Debug;
  #endif
  audEngine = std::make_unique < DirectX::AudioEngine > (eflags);
 } 

 // Allocate all memory resources that change on a window SizeChanged event.
 int0 Game::CreateWindowSizeDependentResources()
 {
  m_fullscreenRect = m_deviceResources->GetOutputSize();
  DisplayingSize.Width = m_fullscreenRect.right - m_fullscreenRect.left;
  DisplayingSize.Height = m_fullscreenRect.bottom - m_fullscreenRect.top;
 }
 int0 Game::OnDeviceLost() // Direct3D resource cleanup.
 {
  m_texture.Reset();
 }
 int0 Game::OnDeviceRestored()
 {
  CreateDeviceDependentResources();
  CreateWindowSizeDependentResources();
 }
#pragma endregion