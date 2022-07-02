//Includes
 #include "Includes\framework.h"
 #include "Includes\Native Platform.h"
 #include <string>
 #include <dos.h>
 #include <timeapi.h>
 #include <chrono>
 #include <thread>
 #include <cmath>
//-//

//Global Variables
 #define MAX_LOADSTRING 100
 HINSTANCE hInst;                                // current instance
 WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
 WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
 ATOM MyRegisterClass(HINSTANCE hInstance);
 BOOL InitInstance(HINSTANCE, int);
 LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
 INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
 HBITMAP LayerOut;
 RECT Tempo;
 HDC HDCl01;
 HDC hdcP;
 HWND HwnD;
 std::jthread SystemThread;
 std::time_t tempF;
 std::string temp2;
 std::wstring temp;
 std::chrono::steady_clock::time_point Timminging;
 std::chrono::steady_clock::time_point Timminging2;
 std::chrono::steady_clock::time_point NowTime;
 std::chrono::steady_clock::time_point NowTimeEx;
 COLORREF Display[8294400];
 COLORREF Screening[8294400];
 void Paintting();
 void MainPlat();
//-//

//Platform's Variables
 void ID();
 int count0;
 double count1;
 unsigned long long int AppRuntime = 0;
 bool DynamicFPS = false;
 int LayerX = 0;
 int LayerY = 0;
 int LayerW = 794;
 int LayerH = 550;
 int DisplayW = 794;
 int DisplayH = 550;
 double DisplayRatio = 1;
 bool Running = true;
 bool FStart = true;
 int FC = 0;
 int FCR = 1;
 int FPI = 0;
 int FPS = 0;
 bool ShowFPS = false;
//-//

//Global Functions
 int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)  
 {
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
  LoadStringW(hInstance, IDC_NATIVEPLATFORM, szWindowClass, MAX_LOADSTRING);
  MyRegisterClass(hInstance);
  if(!InitInstance(hInstance, nCmdShow)){return FALSE;}
  HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NATIVEPLATFORM));
  MSG msg;
  hdcP = GetDC(HwnD);
  Timminging = std::chrono::steady_clock::now();
  std::jthread SystemThread(MainPlat);
  while(GetMessage(&msg, nullptr, 0, 0))
  {
   if(!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)){TranslateMessage(&msg); DispatchMessage(&msg);}
  }
  return (int) msg.wParam;
 }
 ATOM MyRegisterClass(HINSTANCE hInstance)
 {
  WNDCLASSEXW wcex;
  wcex.cbSize        = sizeof(WNDCLASSEX);
  wcex.style         = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc   = WndProc;
  wcex.cbClsExtra    = 0;
  wcex.cbWndExtra    = 0;
  wcex.hInstance     = hInstance;
  wcex.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NATIVEPLATFORM));
  wcex.hCursor       = LoadCursor(nullptr, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
  wcex.lpszMenuName  = MAKEINTRESOURCEW(IDC_NATIVEPLATFORM);
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm       = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
  return RegisterClassExW(&wcex);
 }
 BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
 {
  HWND hwnding = GetDesktopWindow();
  GetWindowRect(hwnding, &Tempo);
  hInst = hInstance; // Store instance handle in our global variable
  HwnD = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, (Tempo.right / 2) - (LayerW / 2), (Tempo.bottom / 2) - (LayerH / 2), 810, 589, nullptr, nullptr, hInstance, nullptr);
  DeleteObject(hwnding);
  if (!HwnD){return FALSE;}
  ShowWindow(HwnD, nCmdShow);
  return TRUE;
 }
 LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
 {
  switch (message)
  {
   case WM_DESTROY:
    Running = false;
    PostQuitMessage(0);
   break;
   default: return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
 }
//-//

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 UNREFERENCED_PARAMETER(lParam);
 switch (message)
 {
  case WM_INITDIALOG: return (INT_PTR)TRUE;
  case WM_COMMAND:
   if(LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL){EndDialog(hDlg, LOWORD(wParam)); return (INT_PTR)TRUE;}
  break;
 }
 return (INT_PTR)FALSE;
}

//Main Functions
 void Timming()
 {
  NowTime = std::chrono::steady_clock::now();
  NowTimeEx = Timminging + std::chrono::milliseconds(8 * ((FPI * FCR) + FC));
  while(NowTime > NowTimeEx) NowTimeEx += std::chrono::milliseconds(8);
  if(DynamicFPS)
  {
   while(NowTime < NowTimeEx) NowTime = std::chrono::steady_clock::now();
  } else
  {
   std::this_thread::sleep_until(NowTimeEx - std::chrono::microseconds(7000));
  }
  return;
 }
 void MainPlat()
 {
  Run:
  Timming();
  Timminging2 = std::chrono::steady_clock::now();
  if(Timminging + std::chrono::seconds(1) < Timminging2)
  {
   AppRuntime += 1;
   if(AppRuntime == 18446744073709551614) AppRuntime = 1000;
   Timminging += std::chrono::seconds(1);
   FPS = FPI; FPI = 0;
  }
  FC += 1;
  if(FC != FCR) if(Running){goto Run;} else {return;}
  FC = 0;
  FPI += 1;
  /////////////////////////////////////////////////
   
  ID();
  
  //////////////////////////////////////////////////
  Paintting(); if(Running){goto Run;} else {return;}
 }
 double Rerounding(double Varb01){return (Varb01 - (double)(int)Varb01);}
 double InvertionR(double Varb01){return 1 - (Varb01 - (double)(int)Varb01);}
 void Paintting()
 {
  GetWindowRect(HwnD, &Tempo);
  LayerW = -Tempo.left + Tempo.right - 16;
  LayerH = -Tempo.top + Tempo.bottom - 39;
  for(count0 = 0; count0 < LayerW * LayerH; ++count0) Screening[count0] = Display[count0];
  /*count0 = 0;
  if(LayerW > DisplayW){count1 = ((double)LayerW / (double)DisplayW) - 1;} else {count1 = 1 - ((double)LayerW / (double)DisplayW);}
  while(count0 <= LayerW)
  {
   if(count1 == (double)(int)count1)
   {
    Screening[count0] = Display[(int)count1];
   } else
   {
    Screening[count0] = RGB((int)((double)GetRValue(Display[(int)count1]) * InvertionR(count1)) + ((double)GetRValue(Display[(int)(count1 + 1)]) * Rerounding(count1)), (int)((double)GetGValue(Display[(int)count1]) * InvertionR(count1)) + ((double)GetGValue(Display[(int)(count1 + 1)]) * Rerounding(count1)), (int)((double)GetBValue(Display[(int)count1]) * InvertionR(count1)) + ((double)GetBValue(Display[(int)(count1 + 1)]) * Rerounding(count1)));
   }
    count0 += 1;
    count1 += (double)LayerW / (double)DisplayW;
  }*/
  LayerOut = CreateBitmap(LayerW, LayerH, 1, 8*4, Screening);
  HDCl01 = CreateCompatibleDC(hdcP);
  SelectObject(HDCl01, LayerOut);
  BitBlt(hdcP, LayerX, LayerY, LayerW, LayerH, HDCl01, 0, 0, SRCCOPY);
  if(ShowFPS){temp2 = std::to_string(FPS); temp = std::wstring(temp2.begin(), temp2.end()); TextOutW(hdcP, 0, 0, temp.c_str(), 3);}
  DeleteObject(LayerOut);
  DeleteDC(HDCl01);
  return;
 }
//-//
//-//


//Game
 //Memorized Variables
  int Varb0001;
  int ScreenCount = 0;
  int ScreenCount2 = 0;
  int ScreenCount3 = 0;
 //-//
 
 //System
  void ID()
  {

   ShowFPS = true;
   ScreenCount3 += 1;
   if(ScreenCount3 == 256){ScreenCount3 = 0; ScreenCount2 += 1;}
   if(ScreenCount2 == 256){ScreenCount2 = 0; ScreenCount += 1;}
   if(ScreenCount == 256) ScreenCount = 0;
   for(Varb0001 = 0; Varb0001 < 794 * 550; ++Varb0001)
   Display[Varb0001] = RGB(ScreenCount + FPI, ScreenCount2 * FPI, ScreenCount3 + Varb0001);

   return;
  }
 //-//
//-//