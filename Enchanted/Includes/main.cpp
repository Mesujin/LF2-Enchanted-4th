
#include "engine.h"
#include "main.h"


// std::vector <DISPLAY> Display;
// INPUT Inpt0001;

int main()
{
 //Do these every FPS. (the FPS should be "(120 / Varb0004)")
  Inpt0001;        // <- Fill this struct with the inputs
  Platform_Main(); // <- Call this
  Display;         // <- Display this vector(/as an array) into the layer | 
 //-//
 return 0;
}

INT WINAPI wWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
 HRESULT hr = S_OK;
 // Enable run-time memory check for debug builds.
  #if defined (DEBUG) | defined (_DEBUG)
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  #endif

 // Begin initialization.
  // Instantiate the window manager class.
   std::shared_ptr < MainClass > winMain = std::shared_ptr < MainClass >(new MainClass());
  
  // Create a window.
   hr = winMain->CreateDesktopWindow();
   if(SUCCEEDED(hr))
   {
    // Instantiate the device manager class.
     std::shared_ptr < DeviceResources > deviceResources = std::shared_ptr < DeviceResources > (new DeviceResources());
        
	// Create device resources.
     deviceResources->CreateDeviceResources();

    // Instantiate the renderer.
     std::shared_ptr < Renderer > renderer = std::shared_ptr < Renderer > (new Renderer(deviceResources));
     renderer->CreateDeviceDependentResources();

    // We have a window, so initialize window size-dependent resources.
     deviceResources->CreateWindowResources(winMain->GetWindowHandle());
     renderer->CreateWindowSizeDependentResources();

    // Go full-screen.
  //   deviceResources->GoFullScreen();

    // Whoops! We resized the "window" when we went full-screen. Better tell the renderer.
   //  renderer->CreateWindowSizeDependentResources();

    // Run the program.
     hr = winMain->Run(deviceResources, renderer);
   }

 // Cleanup is handled in destructors.
 return hr;
}