//Main Platform
 //Commands
  #include "Includes\bmp.h"
  #include "Includes\framework.h"
  #include "Includes\Native Platform.h"
  #include "Includes\angelscript.h"
  #include "Includes\scriptbuilder.h"
  #include "Includes\scriptstdstring.h"
  #include <filesystem>
  #include <fstream>
  #include <chrono>
  #include <string>
  #include <thread>
  #include <dos.h>
  #include <map>
  #define MAX_LOADSTRING 50
  #define MAX_DISPOBJ    18000
  #define MAX_QUALITY    8294400
 //-//
 //Functions
  double Rerounding(double Varb01){return (Varb01 - (double)(int)Varb01);}
  double InvertionR(double Varb01){return 1 - (Varb01 - (double)(int)Varb01);}
  int Rounding(double Varb01){if(Varb01 > (double)(int)Varb01 + 0.5){return (int)Varb01 + 1;} else {return (int)Varb01;}}
 //-//
 //System 
  asIScriptModule *Modu0001;
  asIScriptEngine *Engi0001;
  asIScriptContext *Cont0001;
  asIScriptFunction *Func0001;

  HINSTANCE Inst0001;
  COLORREF Cref0001[MAX_QUALITY];
  COLORREF Cref0002[MAX_QUALITY];
  HBITMAP Bmap0001;
  WCHAR Wchr0001[MAX_LOADSTRING];
  WCHAR Wchr0002[MAX_LOADSTRING];
  RECT Rect0001;
  HWND Hwnd0001;
  HDC Phdc0001;
  HDC Phdc0002;
  std::string Strn0001;
  std::wstring Wstr0001;
  std::ofstream File0001;
  std::ifstream File0002;
  std::chrono::steady_clock::time_point Time0001;
  std::chrono::steady_clock::time_point Time0002;
  std::chrono::steady_clock::time_point Time0003;
  std::chrono::steady_clock::time_point Time0004;
  std::chrono::microseconds Time0005 = std::chrono::microseconds(2500);
  
  unsigned long long int Vrab0001 = 0; // App Runtime
  bool Vrab0002 = false;               // Plat Running
  bool Vrab0003 = false;               // DynamicFPS
  bool Vrab0004 = false;               // DynamicFPS Med
  bool Vrab0005 = false;               // Disp FPS
  bool Vrab0006 = false;               // Color Quality
  int Vrab0007 = 4;                    // FPS Ratio
  int Vrab0008 = 400;                  // Layer W
  int Vrab0009 = 300;                  // Layer H
  int Vrab0010 = 400;                  // Display W
  int Vrab0011 = 300;                  // Display H
  int Vrab0012 = 0;                    // FC
  int Vrab0013 = 0;                    // FPI
  int Vrab0014 = 0;                    // FPS
  int Vrab0015 = 0;                    // Layer X
  int Vrab0016 = 0;                    // Layer Y
  int Vrab0017;                        // Temporal I01 : Count W
  int Vrab0018;                        // Temporal I02 : Count H
  int Vrab0019;                        // Temporal I03 : Temp 4th
  double Vrab0020;                     // Temporal D01 : Temp 3rd
  double Vrab0021;                     // Temporal D02 : Temp 2nd
  double Vrab0022;                     // Temporal D03 : Temp 1st
  double Vrab0023;                     // Temporal D04 : Count BitW
  double Vrab0024;                     // Temporal D05 : Count BitH
  unsigned int Vrab0025 = 0;           // Pic Number
  
  //Graphic Memory
  std::vector<COLORREF> PicColor;
  std::vector<std::string> PicAddress;
  std::vector<unsigned int> PicIndex;
  std::vector<unsigned int> PicWidth;
  std::vector<unsigned int> PicHeight;
  std::vector<OBJECT> Objects;

  int ScreenCount = 0;
  int ScreenCount2 = 0;
  int ScreenCount3 = 0;

  void Platform_Graphic();
  void Platform_Timming()
  {
   Time0003 = std::chrono::steady_clock::now();
   Time0004 = Time0001 + std::chrono::nanoseconds(8333334 * ((Vrab0013 * Vrab0007) + Vrab0012));
   while(Time0003 > Time0004) Time0004 += std::chrono::nanoseconds(8333334);
   if(Vrab0003)
   {
    if(Vrab0004)
    {while(Time0003 < Time0004 - Time0005){std::this_thread::sleep_for(std::chrono::nanoseconds(1)); Time0003 = std::chrono::steady_clock::now();}} else
    {while(Time0003 < Time0004 - Time0005) Time0003 = std::chrono::steady_clock::now();}
   } else
   {
    std::this_thread::sleep_until(Time0004 - std::chrono::microseconds(5151) - Time0005);
   }
   return;
  }
  void Platform_Display()
  {
   GetWindowRect(Hwnd0001, &Rect0001);
   Vrab0008 = -Rect0001.left + Rect0001.right - 16; Vrab0009 = -Rect0001.top + Rect0001.bottom - 39;
   if(Vrab0008 == Vrab0010 && Vrab0009 == Vrab0011)
   {
    std::copy(Cref0001, Cref0001 + MAX_QUALITY, Cref0002);
   } else
   {
    Vrab0017 = 0; Vrab0018 = 0; Vrab0022 = (double)Vrab0010 / (double)Vrab0008 ; Vrab0021 = (double)Vrab0011 / (double)Vrab0009;
    if(Vrab0022 >= 1){Vrab0020 = std::fmod(Vrab0022, 1);} else {Vrab0020 = Vrab0022;}
    if(Vrab0021 >= 1){Vrab0024 = std::fmod(Vrab0021, 1);} else {Vrab0024 = Vrab0021;}
    while(Vrab0018 < Vrab0009)
    {
     Vrab0017 = 0; Vrab0023 = Vrab0020;
     while(Vrab0017 < Vrab0008)
     {
      if(Vrab0023 == (double)(int)Vrab0023)
      {
       if(Vrab0024 == (double)(int)Vrab0024)
       {
        Cref0002[(Vrab0018 * (Vrab0008)) + Vrab0017] = Cref0001[((int)Vrab0024 * (Vrab0010)) + (int)Vrab0023];
       } else
       {
        Vrab0019 = ((int)Vrab0024 * (Vrab0010)) + (int)Vrab0023;
        Cref0002[(Vrab0018 * (Vrab0008)) + Vrab0017] = RGB(Rounding(((double)GetRValue(Cref0001[Vrab0019]) * InvertionR(Vrab0024)) + ((double)GetRValue(Cref0001[Vrab0019 + Vrab0010]) * Rerounding(Vrab0024))), Rounding(((double)GetGValue(Cref0001[Vrab0019]) * InvertionR(Vrab0024)) + ((double)GetGValue(Cref0001[Vrab0019 + Vrab0010]) * Rerounding(Vrab0024))), Rounding(((double)GetBValue(Cref0001[Vrab0019]) * InvertionR(Vrab0024)) + ((double)GetBValue(Cref0001[Vrab0019 + Vrab0010]) * Rerounding(Vrab0024))));
       }
      } else
      {
       if(Vrab0024 == (double)(int)Vrab0024)
       {
        Vrab0019 = ((int)Vrab0024 * (Vrab0010)) + (int)Vrab0023;
        Cref0002[(Vrab0018 * (Vrab0008)) + Vrab0017] = RGB(Rounding(((double)GetRValue(Cref0001[Vrab0019]) * InvertionR(Vrab0023)) + ((double)GetRValue(Cref0001[Vrab0019 + 1]) * Rerounding(Vrab0023))), Rounding(((double)GetGValue(Cref0001[Vrab0019]) * InvertionR(Vrab0023)) + ((double)GetGValue(Cref0001[Vrab0019 + 1]) * Rerounding(Vrab0023))), Rounding(((double)GetBValue(Cref0001[Vrab0019]) * InvertionR(Vrab0023)) + ((double)GetBValue(Cref0001[Vrab0019 + 1]) * Rerounding(Vrab0023))));
       } else
       {
        Vrab0019 = ((int)Vrab0024 * (Vrab0010)) + (int)Vrab0023;
        Cref0002[(Vrab0018 * (Vrab0008)) + Vrab0017] = RGB(Rounding(((double)GetRValue(Cref0001[Vrab0019]) * InvertionR(Vrab0023) * InvertionR(Vrab0024)) + ((double)GetRValue(Cref0001[Vrab0019 + 1]) * Rerounding(Vrab0023) * InvertionR(Vrab0024)) + ((double)GetRValue(Cref0001[Vrab0019 + Vrab0010]) * Rerounding(Vrab0024) * InvertionR(Vrab0023)) + ((double)GetRValue(Cref0001[Vrab0019 + Vrab0010 + 1]) * Rerounding(Vrab0023) * Rerounding(Vrab0024))), Rounding(((double)GetGValue(Cref0001[Vrab0019]) * InvertionR(Vrab0023) * InvertionR(Vrab0024)) + ((double)GetGValue(Cref0001[Vrab0019 + 1]) * Rerounding(Vrab0023) * InvertionR(Vrab0024)) + ((double)GetGValue(Cref0001[Vrab0019 + Vrab0010]) * Rerounding(Vrab0024) * InvertionR(Vrab0023)) + ((double)GetGValue(Cref0001[Vrab0019 + Vrab0010 + 1]) * Rerounding(Vrab0023) * Rerounding(Vrab0024))), Rounding(((double)GetBValue(Cref0001[Vrab0019]) * InvertionR(Vrab0023) * InvertionR(Vrab0024)) + ((double)GetBValue(Cref0001[Vrab0019 + 1]) * Rerounding(Vrab0023) * InvertionR(Vrab0024)) + ((double)GetBValue(Cref0001[Vrab0019 + Vrab0010]) * Rerounding(Vrab0024) * InvertionR(Vrab0023)) + ((double)GetBValue(Cref0001[Vrab0019 + Vrab0010 + 1]) * Rerounding(Vrab0023) * Rerounding(Vrab0024))));
       }
      }
      Vrab0023 += Vrab0022; Vrab0017 += 1;
     }
     Vrab0024 += Vrab0021; Vrab0018 += 1;
    }
   }
   Bmap0001 = CreateBitmap(Vrab0008, Vrab0009, 1, 8*4, Cref0002); Phdc0002 = CreateCompatibleDC(Phdc0001); SelectObject(Phdc0002, Bmap0001); BitBlt(Phdc0001, Vrab0015, Vrab0016, Vrab0008, Vrab0009, Phdc0002, 0, 0, SRCCOPY);
   if(Vrab0005){Strn0001 = std::to_string(Vrab0014); Wstr0001 = std::wstring(Strn0001.begin(), Strn0001.end()); TextOutW(Phdc0001, 0, 0, Wstr0001.c_str(), 3);} DeleteObject(Bmap0001); DeleteDC(Phdc0002); return;
  }
  void Platform_Main()
  {
   Labl0001:
   Platform_Timming();
   Time0002 = std::chrono::steady_clock::now();
   if(Time0001 + std::chrono::seconds(1) < Time0002)
   {Vrab0001 += 1; if(Vrab0001 == 18446744073709551614) Vrab0001 = 1000; Time0001 += std::chrono::seconds(1); Vrab0014 = Vrab0013; Vrab0013 = 0;}
   Vrab0012 += 1;
   if(Vrab0012 != Vrab0007) if(Vrab0002){goto Labl0001;} else {return;} Vrab0012 = 0; Vrab0013 += 1;
   if(Vrab0001 > 6 && )
   Vrab0017 = Cont0001->Prepare(Func0001);
   Vrab0017 = Cont0001->Execute();
   Platform_Graphic();
   Platform_Display();
   if(Vrab0002){goto Labl0001;} else {return;} 
  }
  LRESULT CALLBACK Platform_Process(HWND Hwnd01, UINT Uint01, WPARAM Wprm01, LPARAM Lprm01)
  {
   switch(Uint01)
   {
    case WM_DESTROY:
     Vrab0002 = false;
     PostQuitMessage(0);
    break;
    default:
    return DefWindowProc(Hwnd01, Uint01, Wprm01, Lprm01);
   }
   return 0;
  }
  BOOL Platform_Initialization(HINSTANCE Inst01, int Vrab01)
  {
   HWND Hwnd01 = GetDesktopWindow();
   GetWindowRect(Hwnd01, &Rect0001);
   DeleteObject(Hwnd01);
   Inst0001 = Inst01;
   Hwnd0001 = CreateWindowW(Wchr0002, Wchr0001, WS_OVERLAPPEDWINDOW, (Rect0001.right / 2) - (Vrab0008 / 2), (Rect0001.bottom / 2) - (Vrab0009 / 2) - 30, 810, 589, nullptr, nullptr, Inst01, nullptr);
   if(Hwnd0001){ShowWindow(Hwnd0001, Vrab01); return FALSE;} else {return TRUE;}
  }
  ATOM Platform_Window(HINSTANCE Inst01)
  {
   WNDCLASSEXW Wind01;
   Wind01.cbSize = sizeof(WNDCLASSEX);
   Wind01.style = CS_HREDRAW | CS_VREDRAW;
   Wind01.lpfnWndProc = Platform_Process;
   Wind01.cbClsExtra = 0;
   Wind01.cbWndExtra = 0;
   Wind01.hInstance = Inst01;
   Wind01.hIcon = LoadIcon(Inst01, MAKEINTRESOURCE(IDI_NATIVEPLATFORM));
   Wind01.hCursor = LoadCursor(nullptr, IDC_ARROW);
   Wind01.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
   Wind01.lpszMenuName = MAKEINTRESOURCEW(IDC_NATIVEPLATFORM);
   Wind01.lpszClassName = Wchr0002;
   Wind01.hIconSm = LoadIcon(Wind01.hInstance, MAKEINTRESOURCE(IDI_SMALL));
   return RegisterClassExW(&Wind01); 
  }
  void Platform_Call(unsigned char Vrab01, std::string Strn01)
  {
   switch(Vrab01)
   {
    case 0:     
     Vrab0005 = true;
    break;
    case 1:
     File0001.open(Strn01);
     File0001 << "A";
     File0001.close();
    break;
    default: return;
   }
   return;
  }
  void Platform_AngelScript()
  {
   Labl0003:
   File0002.open("Database\\System.as");
   if(File0002.is_open())
   {
    bool Vrab02 = true;
    Vrab0001 = 1500;
    while(File0002)
    {
     File0002 >> Strn0001;
     if(Strn0001.compare("MaximumObjNum") == 0)
     {
      File0002 >> Strn0001 >> Vrab0025;
      Objects.resize(Vrab0025 * 12);
      Vrab02 = false;
      goto Labl0004;
     }
    }
    Labl0004:
    File0002.close();
    if(Vrab02) goto Labl0002;
   } else
   {
    Labl0002:
    File0001.open("Database\\System.as");
    File0001 << R"""(

//////////////////////////////////////////////////////////////////////////////////////////////////
// Universal AI and Basic System for LF2ET, by Mesujin.                                         //
// Ver. 0.81.220722                                                                             //
//                                                                                              //
// Do not modify if you don't know what you're gonna modify!                                    //
// If you know what you're gonna modify, then have fun modifiying. ;3                           //
// You did better to turn off the "Word Wrap" setting to get better look to the code. XD        //
// ..normally, "Alt + Z" is the default shortcut for "Word Wrap" (if you don't know where it)   //
//                                                                                              //
// Repository: https://github.com/Mesujin/LF2-Enchanted-3rd-AI-and-System (More readable there) //
// The right of this AI belong to Mesujin :P this's mine :<                                     //
//////////////////////////////////////////////////////////////////////////////////////////////////

// The Value in Configuration must be Positive!
// (If there's no "Limit", then the "Limit" is their Data Type limit.)
// Try to return the Value to it's "Default" Value if you occuring an error.

//Configurationn
 //Main Configuration
  uint64 MaximumObjNum         = 1500 ;//In-Game maximum objects. {Limit = 1537228672809129301} {Default = 1500}

)""";
    File0001.close();
    goto Labl0003;
   }
   Vrab0001 = 0;
   Engi0001 = asCreateScriptEngine();
   RegisterStdString(Engi0001);
   Engi0001->RegisterGlobalFunction("void Call(uint8 Vrab01, string Strn01)", asFunctionPtr(Platform_Call), asCALL_CDECL);
   CScriptBuilder Make01;
   int Vrab01 = Make01.StartNewModule(Engi0001, "System");
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Vrab0002 = false;
    PostQuitMessage(0);
   }
   Vrab01 = Make01.AddSectionFromFile("Database\\System.as");
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Vrab0002 = false;
    PostQuitMessage(0);
   }
   Vrab01 = Make01.BuildModule();
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Vrab0002 = false;
    PostQuitMessage(0);
   }
   Modu0001 = Engi0001->GetModule("System");
   Func0001 = Modu0001->GetFunctionByDecl("void Main()");
   Cont0001 = Engi0001->CreateContext();
   return;
  }
  int APIENTRY wWinMain(HINSTANCE Inst01, HINSTANCE Inst02, LPWSTR Wstr01, int Vrab01)
  {
   UNREFERENCED_PARAMETER(Inst02); UNREFERENCED_PARAMETER(Wstr01);
   LoadStringW(Inst01, IDS_APP_TITLE, Wchr0001, MAX_LOADSTRING);
   LoadStringW(Inst01, IDC_NATIVEPLATFORM, Wchr0002, MAX_LOADSTRING);
   Platform_Window(Inst01);
   if(Platform_Initialization(Inst01, Vrab01)) return 0;
   Vrab0002 = true;
   HACCEL Accl01 = LoadAccelerators(Inst01, MAKEINTRESOURCE(IDC_NATIVEPLATFORM));
   MSG Mssg01;
   Phdc0001 = GetDC(Hwnd0001);
   Time0001 = std::chrono::steady_clock::now();
   Platform_AngelScript();
   std::jthread Thrd0001(Platform_Main);
   while(GetMessage(&Mssg01, nullptr, 0, 0))
   {
    if(!TranslateAccelerator(Mssg01.hwnd, Accl01, &Mssg01))
    {TranslateMessage(&Mssg01); DispatchMessage(&Mssg01);}
   }
   return (int)Mssg01.wParam;
  }
 //-//
//-//
 
//Engine
  struct GAME
  {
   unsigned char Menu;
   bool InGame = false;
   unsigned long long int Time;
   unsigned long long int Playtime;
   unsigned char Background;
  };
  GAME Game;
 //-//
 
 //Graphic
  void Platform_Building()
  {
   
  }
  void Platform_Graphic()
  {
   ScreenCount3 += 1 * Vrab0007;
   if(ScreenCount3 == 256){ScreenCount3 = 0; ScreenCount2 += 1 * Vrab0007;}
   if(ScreenCount2 == 256){ScreenCount2 = 0; ScreenCount += 1 * Vrab0007;}
   if(ScreenCount == 256) ScreenCount = 0;
   for(Vrab0017 = 0; Vrab0017 < 800 * 600; ++Vrab0017)
   Cref0001[Vrab0017] = RGB(ScreenCount, ScreenCount2, ScreenCount3 + Vrab0017);

   for(Vrab0017 = 100; Vrab0017 < 200; ++Vrab0017)
   for(Vrab0019 = 125; Vrab0019 < 225; ++Vrab0019)
   Cref0001[(Vrab0010 * Vrab0019) + Vrab0017] = RGB(125, 125, 125);

   //Objects Graphic
    for(Vrab0017 = 0; Vrab0017 < MAX_DISPOBJ; ++Vrab0017)
    if(Objects[Vrab0017].Exist)
    {
     if(Objects[Vrab0017].Text > 0)
     {
     
      continue;
     }
     if(PicWidth[Objects[Vrab0017].Pic] < Objects[Vrab0017].PicX1) continue;
     if(PicHeight[Objects[Vrab0017].Pic] < Objects[Vrab0017].PicY1) continue;
     if(PicWidth[Objects[Vrab0017].Pic] < Objects[Vrab0017].PicX2) continue;
     if(PicHeight[Objects[Vrab0017].Pic] < Objects[Vrab0017].PicY2) continue;
     for(Vrab0020 = 0; Vrab0020 < Objects[Vrab0017].X2 - Objects[Vrab0017].X1; ++Vrab0020)
     {}
    } else {break;}
   //-//
   
   return;
  }
 //-//
//-//
