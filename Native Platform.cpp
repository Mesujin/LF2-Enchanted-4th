//Main Platform
 //Tags
  #include "Includes\framework.h"
  #include "Includes\Native Platform.h"
  #include <map>
  #include <string>
  #include <filesystem>
  #include <fstream>
  #include <dos.h>
  #include <chrono>
  #include <thread>
  #define MAX_LOADSTRING 50
  #define MAX_DISPOBJ 2000
  #define MAX_QUALITY 8294400
 //-//
 //Basic Variables
  COLORREF Display[MAX_QUALITY]; COLORREF Screening[MAX_QUALITY];
  unsigned long long int AppRuntime = 0;
  bool DynamicFPS = false;
  bool ShowFPS = false;
  int FCR = 1;
  int LayerW = 794;
  int LayerH = 550;
  int DisplayW = 794;
  int DisplayH = 550;
  double DisplayRatio = 4;
 //-//
 //System
  HINSTANCE hInst; WCHAR szTitle[MAX_LOADSTRING]; WCHAR szWindowClass[MAX_LOADSTRING]; ATOM MyRegisterClass(HINSTANCE hInstance); BOOL InitInstance(HINSTANCE, int); LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); HBITMAP LayerOut; RECT Tempo; HDC HDCl01; HDC hdcP; HWND HwnD; std::jthread SystemThread; std::time_t tempF; std::string temp2; std::wstring temp; std::chrono::steady_clock::time_point Timminging; std::chrono::steady_clock::time_point Timminging2; std::chrono::steady_clock::time_point NowTime; std::chrono::steady_clock::time_point NowTimeEx; void Paintting(); void MainPlat(); void ID(); double temporally; double temporally2; double temporally3; int temporally4; int countw; int counth; double countbitw; double countbith; int LayerX = 0; int LayerY = 0; bool Running = true; bool FStart = true; int FC = 0; int FPI = 0; int FPS = 0; int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) { UNREFERENCED_PARAMETER(hPrevInstance); UNREFERENCED_PARAMETER(lpCmdLine); LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); LoadStringW(hInstance, IDC_NATIVEPLATFORM, szWindowClass, MAX_LOADSTRING); MyRegisterClass(hInstance); if(!InitInstance(hInstance, nCmdShow)){return FALSE;} HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NATIVEPLATFORM)); MSG msg; hdcP = GetDC(HwnD); Timminging = std::chrono::steady_clock::now(); std::jthread SystemThread(MainPlat); while(GetMessage(&msg, nullptr, 0, 0)) { if(!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)){TranslateMessage(&msg); DispatchMessage(&msg);} } return (int) msg.wParam; } ATOM MyRegisterClass(HINSTANCE hInstance) { WNDCLASSEXW wcex; wcex.cbSize = sizeof(WNDCLASSEX); wcex.style = CS_HREDRAW | CS_VREDRAW; wcex.lpfnWndProc = WndProc; wcex.cbClsExtra = 0; wcex.cbWndExtra = 0; wcex.hInstance = hInstance; wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NATIVEPLATFORM)); wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_NATIVEPLATFORM); wcex.lpszClassName = szWindowClass; wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); return RegisterClassExW(&wcex); } BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) { HWND hwnding = GetDesktopWindow(); GetWindowRect(hwnding, &Tempo); hInst = hInstance; HwnD = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, (Tempo.right / 2) - (LayerW / 2), (Tempo.bottom / 2) - (LayerH / 2) - 30, 810, 589, nullptr, nullptr, hInstance, nullptr); DeleteObject(hwnding); if (!HwnD){return FALSE;} ShowWindow(HwnD, nCmdShow); return TRUE; } LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) { switch (message) { case WM_DESTROY: Running = false; PostQuitMessage(0); break; default: return DefWindowProc(hWnd, message, wParam, lParam); } return 0; } void Timming() { NowTime = std::chrono::steady_clock::now(); NowTimeEx = Timminging + std::chrono::nanoseconds(8333334 * ((FPI * FCR) + FC)); while(NowTime > NowTimeEx) NowTimeEx += std::chrono::nanoseconds(8333334); if(DynamicFPS) { while(NowTime < NowTimeEx - std::chrono::microseconds(1500)) NowTime = std::chrono::steady_clock::now(); } else { std::this_thread::sleep_until(NowTimeEx - std::chrono::microseconds(6666)); } return; } void MainPlat(){Run: Timming(); Timminging2 = std::chrono::steady_clock::now(); if(Timminging + std::chrono::seconds(1) < Timminging2){ AppRuntime += 1; if(AppRuntime == 18446744073709551614) AppRuntime = 1000; Timminging += std::chrono::seconds(1); FPS = FPI; FPI = 0; } FC += 1; if(FC != FCR) if(Running){goto Run;} else {return;} FC = 0; FPI += 1; ID(); Paintting(); if(Running){goto Run;} else {return;} } double Rerounding(double Varb01){return (Varb01 - (double)(int)Varb01);} double InvertionR(double Varb01){return 1 - (Varb01 - (double)(int)Varb01);} int Rounding(double Varb01){if(Varb01 > (double)(int)Varb01 + 0.5) return (int)Varb01 + 1; return (int)Varb01;} void Paintting() { GetWindowRect(HwnD, &Tempo); LayerW = -Tempo.left + Tempo.right - 16; LayerH = -Tempo.top + Tempo.bottom - 39; countw = 0; counth = 0; temporally = (double)DisplayW / (double)LayerW ; temporally2 = (double)DisplayH / (double)LayerH; if(temporally >= 1){temporally3 = std::fmod(temporally, 1);} else {temporally3 = temporally;} if(temporally2 >= 1){countbith = std::fmod(temporally2, 1);} else {countbith = temporally2;} while(counth < LayerH) { countw = 0; countbitw = temporally3; while(countw < LayerW) { if(countbitw == (double)(int)countbitw) { if(countbith == (double)(int)countbith) { Screening[(counth * (LayerW)) + countw] = Display[((int)countbith * (DisplayW)) + (int)countbitw]; } else { temporally4 = ((int)countbith * (DisplayW)) + (int)countbitw; Screening[(counth * (LayerW)) + countw] = RGB(Rounding(((double)GetRValue(Display[temporally4]) * InvertionR(countbith)) + ((double)GetRValue(Display[temporally4 + DisplayW]) * Rerounding(countbith))), Rounding(((double)GetGValue(Display[temporally4]) * InvertionR(countbith)) + ((double)GetGValue(Display[temporally4 + DisplayW]) * Rerounding(countbith))), Rounding(((double)GetBValue(Display[temporally4]) * InvertionR(countbith)) + ((double)GetBValue(Display[temporally4 + DisplayW]) * Rerounding(countbith))));}} else {if(countbith == (double)(int)countbith){temporally4 = ((int)countbith * (DisplayW)) + (int)countbitw; Screening[(counth * (LayerW)) + countw] = RGB(Rounding(((double)GetRValue(Display[temporally4]) * InvertionR(countbitw)) + ((double)GetRValue(Display[temporally4 + 1]) * Rerounding(countbitw))), Rounding(((double)GetGValue(Display[temporally4]) * InvertionR(countbitw)) + ((double)GetGValue(Display[temporally4 + 1]) * Rerounding(countbitw))), Rounding(((double)GetBValue(Display[temporally4]) * InvertionR(countbitw)) + ((double)GetBValue(Display[temporally4 + 1]) * Rerounding(countbitw)))); } else { temporally4 = ((int)countbith * (DisplayW)) + (int)countbitw; Screening[(counth * (LayerW)) + countw] = RGB(Rounding(((double)GetRValue(Display[temporally4]) * InvertionR(countbitw) * InvertionR(countbith)) + ((double)GetRValue(Display[temporally4 + 1]) * Rerounding(countbitw) * InvertionR(countbith)) + ((double)GetRValue(Display[temporally4 + DisplayW]) * Rerounding(countbith) * InvertionR(countbitw)) + ((double)GetRValue(Display[temporally4 + DisplayW + 1]) * Rerounding(countbitw) * Rerounding(countbith))), Rounding(((double)GetGValue(Display[temporally4]) * InvertionR(countbitw) * InvertionR(countbith)) + ((double)GetGValue(Display[temporally4 + 1]) * Rerounding(countbitw) * InvertionR(countbith)) + ((double)GetGValue(Display[temporally4 + DisplayW]) * Rerounding(countbith) * InvertionR(countbitw)) + ((double)GetGValue(Display[temporally4 + DisplayW + 1]) * Rerounding(countbitw) * Rerounding(countbith))), Rounding(((double)GetBValue(Display[temporally4]) * InvertionR(countbitw) * InvertionR(countbith)) + ((double)GetBValue(Display[temporally4 + 1]) * Rerounding(countbitw) * InvertionR(countbith)) + ((double)GetBValue(Display[temporally4 + DisplayW]) * Rerounding(countbith) * InvertionR(countbitw)) + ((double)GetBValue(Display[temporally4 + DisplayW + 1]) * Rerounding(countbitw) * Rerounding(countbith))));}} countbitw += temporally; countw += 1;} countbith += temporally2; counth += 1;} LayerOut = CreateBitmap(LayerW, LayerH, 1, 8*4, Screening); HDCl01 = CreateCompatibleDC(hdcP); SelectObject(HDCl01, LayerOut); BitBlt(hdcP, LayerX, LayerY, LayerW, LayerH, HDCl01, 0, 0, SRCCOPY); if(ShowFPS){temp2 = std::to_string(FPS); temp = std::wstring(temp2.begin(), temp2.end()); TextOutW(hdcP, 0, 0, temp.c_str(), 3);} DeleteObject(LayerOut); DeleteDC(HDCl01); return;}
 //-//
//-//
 
//Engine
 //Memorized Variables
  int Varb0001;
  bool Varb0002;
  int ScreenCount = 0;
  int ScreenCount2 = 0;
  int ScreenCount3 = 0;
 //-//
 //Object Variables
           bool ObjDisp_Exist[MAX_DISPOBJ];
      short int ObjDisp_X[MAX_DISPOBJ];
      short int ObjDisp_Y[MAX_DISPOBJ];
  unsigned char ObjDisp_Trans[MAX_DISPOBJ];
  long long int ObjDisp_Pic[MAX_DISPOBJ];
         double ObjDisp_Scale[MAX_DISPOBJ];
      short int ObjDisp_Rot[MAX_DISPOBJ];
      short int ObjDisp_ScaX1[MAX_DISPOBJ];
      short int ObjDisp_ScaX2[MAX_DISPOBJ];
      short int ObjDisp_ScaX3[MAX_DISPOBJ];
      short int ObjDisp_ScaY1[MAX_DISPOBJ];
      short int ObjDisp_ScaY2[MAX_DISPOBJ];
      short int ObjDisp_ScaY3[MAX_DISPOBJ];
 //-//
 
 //System
  enum DeCodeList {U0000, U0001, U0002, U0003, U0004, U0005, U0006, U0007, U0008, U0009, U000A, U000B, U000C, U000D, U000E, U000F, U0010, U0011, U0012, U0013, U0014, U0015, U0016, U0017, U0018, U0019, U001A, U001B, U001C, U001D, U001E, U001F, U0020, U0021, U0022, U0023, U0024, U0025, U0026, U0027, U0028, U0029, U002A, U002B, U002C, U002D, U002E, U002F, U0030, U0031, U0032, U0033, U0034, U0035, U0036, U0037, U0038, U0039, U003A, U003B, U003C, U003D, U003E, U003F, U0040, U0041, U0042, U0043, U0044, U0045, U0046, U0047, U0048, U0049, U004A, U004B, U004C, U004D, U004E, U004F, U0050, U0051, U0052, U0053, U0054, U0055, U0056, U0057, U0058, U0059, U005A, U005B, U005C, U005D, U005E, U005F, U0060, U0061, U0062, U0063, U0064, U0065, U0066, U0067, U0068, U0069, U006A, U006B, U006C, U006D, U006E, U006F, U0070, U0071, U0072, U0073, U0074, U0075, U0076, U0077, U0078, U0079, U007A, U007B, U007C, U007D, U007E, U007F, U0080, U0081, U0082, U0083, U0084, U0085, U0086, U0087, U0088, U0089, U008A, U008B, U008C, U008D, U008E, U008F, U0090, U0091, U0092, U0093, U0094, U0095, U0096, U0097, U0098, U0099, U009A, U009B, U009C, U009D, U009E, U009F, U00A0, U00A1, U00A2, U00A3, U00A4, U00A5, U00A6, U00A7, U00A8, U00A9, U00AA, U00AB, U00AC, U00AD, U00AE, U00AF, U00B0, U00B1, U00B2, U00B3, U00B4, U00B5, U00B6, U00B7, U00B8, U00B9, U00BA, U00BB, U00BC, U00BD, U00BE, U00BF, U00C0, U00C1, U00C2, U00C3, U00C4, U00C5, U00C6, U00C7, U00C8, U00C9, U00CA, U00CB, U00CC, U00CD, U00CE, U00CF, U00D0, U00D1, U00D2, U00D3, U00D4, U00D5, U00D6, U00D7, U00D8, U00D9, U00DA, U00DB, U00DC, U00DD, U00DE, U00DF, U00E0, U00E1, U00E2, U00E3, U00E4, U00E5, U00E6, U00E7, U00E8, U00E9, U00EA, U00EB, U00EC, U00ED, U00EE, U00EF, U00F0, U00F1, U00F2, U00F3, U00F4, U00F5, U00F6, U00F7, U00F8, U00F9, U00FA, U00FB, U00FC, U00FD, U00FE, U00FF};
  static std::map<char, DeCodeList> DeCodeCheck;
  void DeCodeInit()
  {
   DeCodeCheck['\u0000'] = U0000;
   DeCodeCheck['\u0001'] = U0001;
   DeCodeCheck['\u0002'] = U0002;
   DeCodeCheck['\u0003'] = U0003;
   DeCodeCheck['\u0004'] = U0004;
   DeCodeCheck['\u0005'] = U0005;
   DeCodeCheck['\u0006'] = U0006;
   DeCodeCheck['\u0007'] = U0007;
   DeCodeCheck['\u0008'] = U0008;
   DeCodeCheck['\u0009'] = U0009;
   DeCodeCheck['\u000A'] = U000A;
   DeCodeCheck['\u000B'] = U000B;
   DeCodeCheck['\u000C'] = U000C;
   DeCodeCheck['\u000D'] = U000D;
   DeCodeCheck['\u000E'] = U000E;
   DeCodeCheck['\u000F'] = U000F;
   DeCodeCheck['\u0010'] = U0010;
   DeCodeCheck['\u0011'] = U0011;
   DeCodeCheck['\u0012'] = U0012;
   DeCodeCheck['\u0013'] = U0013;
   DeCodeCheck['\u0014'] = U0014;
   DeCodeCheck['\u0015'] = U0015;
   DeCodeCheck['\u0016'] = U0016;
   DeCodeCheck['\u0017'] = U0017;
   DeCodeCheck['\u0018'] = U0018;
   DeCodeCheck['\u0019'] = U0019;
   DeCodeCheck['\u001A'] = U001A;
   DeCodeCheck['\u001B'] = U001B;
   DeCodeCheck['\u001C'] = U001C;
   DeCodeCheck['\u001D'] = U001D;
   DeCodeCheck['\u001E'] = U001E;
   DeCodeCheck['\u001F'] = U001F;
   DeCodeCheck['\u0020'] = U0020;
   DeCodeCheck['\u0021'] = U0021;
   DeCodeCheck['\u0022'] = U0022;
   DeCodeCheck['\u0023'] = U0023;
   DeCodeCheck['\u0024'] = U0024;
   DeCodeCheck['\u0025'] = U0025;
   DeCodeCheck['\u0026'] = U0026;
   DeCodeCheck['\u0027'] = U0027;
   DeCodeCheck['\u0028'] = U0028;
   DeCodeCheck['\u0029'] = U0029;
   DeCodeCheck['\u002A'] = U002A;
   DeCodeCheck['\u002B'] = U002B;
   DeCodeCheck['\u002C'] = U002C;
   DeCodeCheck['\u002D'] = U002D;
   DeCodeCheck['\u002E'] = U002E;
   DeCodeCheck['\u002F'] = U002F;
   DeCodeCheck['\u0030'] = U0030;
   DeCodeCheck['\u0031'] = U0031;
   DeCodeCheck['\u0032'] = U0032;
   DeCodeCheck['\u0033'] = U0033;
   DeCodeCheck['\u0034'] = U0034;
   DeCodeCheck['\u0035'] = U0035;
   DeCodeCheck['\u0036'] = U0036;
   DeCodeCheck['\u0037'] = U0037;
   DeCodeCheck['\u0038'] = U0038;
   DeCodeCheck['\u0039'] = U0039;
   DeCodeCheck['\u003A'] = U003A;
   DeCodeCheck['\u003B'] = U003B;
   DeCodeCheck['\u003C'] = U003C;
   DeCodeCheck['\u003D'] = U003D;
   DeCodeCheck['\u003E'] = U003E;
   DeCodeCheck['\u003F'] = U003F;
   DeCodeCheck['\u0040'] = U0040;
   DeCodeCheck['\u0041'] = U0041;
   DeCodeCheck['\u0042'] = U0042;
   DeCodeCheck['\u0043'] = U0043;
   DeCodeCheck['\u0044'] = U0044;
   DeCodeCheck['\u0045'] = U0045;
   DeCodeCheck['\u0046'] = U0046;
   DeCodeCheck['\u0047'] = U0047;
   DeCodeCheck['\u0048'] = U0048;
   DeCodeCheck['\u0049'] = U0049;
   DeCodeCheck['\u004A'] = U004A;
   DeCodeCheck['\u004B'] = U004B;
   DeCodeCheck['\u004C'] = U004C;
   DeCodeCheck['\u004D'] = U004D;
   DeCodeCheck['\u004E'] = U004E;
   DeCodeCheck['\u004F'] = U004F;
   DeCodeCheck['\u0050'] = U0050;
   DeCodeCheck['\u0051'] = U0051;
   DeCodeCheck['\u0052'] = U0052;
   DeCodeCheck['\u0053'] = U0053;
   DeCodeCheck['\u0054'] = U0054;
   DeCodeCheck['\u0055'] = U0055;
   DeCodeCheck['\u0056'] = U0056;
   DeCodeCheck['\u0057'] = U0057;
   DeCodeCheck['\u0058'] = U0058;
   DeCodeCheck['\u0059'] = U0059;
   DeCodeCheck['\u005A'] = U005A;
   DeCodeCheck['\u005B'] = U005B;
   DeCodeCheck['\u005C'] = U005C;
   DeCodeCheck['\u005D'] = U005D;
   DeCodeCheck['\u005E'] = U005E;
   DeCodeCheck['\u005F'] = U005F;
   DeCodeCheck['\u0060'] = U0060;
   DeCodeCheck['\u0061'] = U0061;
   DeCodeCheck['\u0062'] = U0062;
   DeCodeCheck['\u0063'] = U0063;
   DeCodeCheck['\u0064'] = U0064;
   DeCodeCheck['\u0065'] = U0065;
   DeCodeCheck['\u0066'] = U0066;
   DeCodeCheck['\u0067'] = U0067;
   DeCodeCheck['\u0068'] = U0068;
   DeCodeCheck['\u0069'] = U0069;
   DeCodeCheck['\u006A'] = U006A;
   DeCodeCheck['\u006B'] = U006B;
   DeCodeCheck['\u006C'] = U006C;
   DeCodeCheck['\u006D'] = U006D;
   DeCodeCheck['\u006E'] = U006E;
   DeCodeCheck['\u006F'] = U006F;
   DeCodeCheck['\u0070'] = U0070;
   DeCodeCheck['\u0071'] = U0071;
   DeCodeCheck['\u0072'] = U0072;
   DeCodeCheck['\u0073'] = U0073;
   DeCodeCheck['\u0074'] = U0074;
   DeCodeCheck['\u0075'] = U0075;
   DeCodeCheck['\u0076'] = U0076;
   DeCodeCheck['\u0077'] = U0077;
   DeCodeCheck['\u0078'] = U0078;
   DeCodeCheck['\u0079'] = U0079;
   DeCodeCheck['\u007A'] = U007A;
   DeCodeCheck['\u007B'] = U007B;
   DeCodeCheck['\u007C'] = U007C;
   DeCodeCheck['\u007D'] = U007D;
   DeCodeCheck['\u007E'] = U007E;
   DeCodeCheck['\u007F'] = U007F;
   DeCodeCheck['\u00A0'] = U00A0;
   DeCodeCheck['\u00A1'] = U00A1;
   DeCodeCheck['\u00A2'] = U00A2;
   DeCodeCheck['\u00A3'] = U00A3;
   DeCodeCheck['\u00A4'] = U00A4;
   DeCodeCheck['\u00A5'] = U00A5;
   DeCodeCheck['\u00A6'] = U00A6;
   DeCodeCheck['\u00A7'] = U00A7;
   DeCodeCheck['\u00A8'] = U00A8;
   DeCodeCheck['\u00A9'] = U00A9;
   DeCodeCheck['\u00AA'] = U00AA;
   DeCodeCheck['\u00AB'] = U00AB;
   DeCodeCheck['\u00AC'] = U00AC;
   DeCodeCheck['\u00AD'] = U00AD;
   DeCodeCheck['\u00AE'] = U00AE;
   DeCodeCheck['\u00AF'] = U00AF;
   DeCodeCheck['\u00B0'] = U00B0;
   DeCodeCheck['\u00B1'] = U00B1;
   DeCodeCheck['\u00B2'] = U00B2;
   DeCodeCheck['\u00B3'] = U00B3;
   DeCodeCheck['\u00B4'] = U00B4;
   DeCodeCheck['\u00B5'] = U00B5;
   DeCodeCheck['\u00B6'] = U00B6;
   DeCodeCheck['\u00B7'] = U00B7;
   DeCodeCheck['\u00B8'] = U00B8;
   DeCodeCheck['\u00B9'] = U00B9;
   DeCodeCheck['\u00BA'] = U00BA;
   DeCodeCheck['\u00BB'] = U00BB;
   DeCodeCheck['\u00BC'] = U00BC;
   DeCodeCheck['\u00BD'] = U00BD;
   DeCodeCheck['\u00BE'] = U00BE;
   DeCodeCheck['\u00BF'] = U00BF;
   DeCodeCheck['\u00C0'] = U00C0;
   DeCodeCheck['\u00C1'] = U00C1;
   DeCodeCheck['\u00C2'] = U00C2;
   DeCodeCheck['\u00C3'] = U00C3;
   DeCodeCheck['\u00C4'] = U00C4;
   DeCodeCheck['\u00C5'] = U00C5;
   DeCodeCheck['\u00C6'] = U00C6;
   DeCodeCheck['\u00C7'] = U00C7;
   DeCodeCheck['\u00C8'] = U00C8;
   DeCodeCheck['\u00C9'] = U00C9;
   DeCodeCheck['\u00CA'] = U00CA;
   DeCodeCheck['\u00CB'] = U00CB;
   DeCodeCheck['\u00CC'] = U00CC;
   DeCodeCheck['\u00CD'] = U00CD;
   DeCodeCheck['\u00CE'] = U00CE;
   DeCodeCheck['\u00CF'] = U00CF;
   DeCodeCheck['\u00D0'] = U00D0;
   DeCodeCheck['\u00D1'] = U00D1;
   DeCodeCheck['\u00D2'] = U00D2;
   DeCodeCheck['\u00D3'] = U00D3;
   DeCodeCheck['\u00D4'] = U00D4;
   DeCodeCheck['\u00D5'] = U00D5;
   DeCodeCheck['\u00D6'] = U00D6;
   DeCodeCheck['\u00D7'] = U00D7;
   DeCodeCheck['\u00D8'] = U00D8;
   DeCodeCheck['\u00D9'] = U00D9;
   DeCodeCheck['\u00DA'] = U00DA;
   DeCodeCheck['\u00DB'] = U00DB;
   DeCodeCheck['\u00DC'] = U00DC;
   DeCodeCheck['\u00DD'] = U00DD;
   DeCodeCheck['\u00DE'] = U00DE;
   DeCodeCheck['\u00DF'] = U00DF;
   DeCodeCheck['\u00E0'] = U00E0;
   DeCodeCheck['\u00E1'] = U00E1;
   DeCodeCheck['\u00E2'] = U00E2;
   DeCodeCheck['\u00E3'] = U00E3;
   DeCodeCheck['\u00E4'] = U00E4;
   DeCodeCheck['\u00E5'] = U00E5;
   DeCodeCheck['\u00E6'] = U00E6;
   DeCodeCheck['\u00E7'] = U00E7;
   DeCodeCheck['\u00E8'] = U00E8;
   DeCodeCheck['\u00E9'] = U00E9;
   DeCodeCheck['\u00EA'] = U00EA;
   DeCodeCheck['\u00EB'] = U00EB;
   DeCodeCheck['\u00EC'] = U00EC;
   DeCodeCheck['\u00ED'] = U00ED;
   DeCodeCheck['\u00EE'] = U00EE;
   DeCodeCheck['\u00EF'] = U00EF;
   DeCodeCheck['\u00F0'] = U00F0;
   DeCodeCheck['\u00F1'] = U00F1;
   DeCodeCheck['\u00F2'] = U00F2;
   DeCodeCheck['\u00F3'] = U00F3;
   DeCodeCheck['\u00F4'] = U00F4;
   DeCodeCheck['\u00F5'] = U00F5;
   DeCodeCheck['\u00F6'] = U00F6;
   DeCodeCheck['\u00F7'] = U00F7;
   DeCodeCheck['\u00F8'] = U00F8;
   DeCodeCheck['\u00F9'] = U00F9;
   DeCodeCheck['\u00FA'] = U00FA;
   DeCodeCheck['\u00FB'] = U00FB;
   DeCodeCheck['\u00FC'] = U00FC;
   DeCodeCheck['\u00FD'] = U00FD;
   DeCodeCheck['\u00FE'] = U00FE;
   DeCodeCheck['\u00FF'] = U00FF;
  }
  unsigned char DeCode(unsigned char Varb01)
  {
   switch(DeCodeCheck[Varb01])
   {
    case U0001: return 1;
    case U0002: return 2;
    case U0003: return 3;
    case U0004: return 4;
    case U0005: return 5;
    case U0006: return 6;
    case U0007: return 7;
    case U0008: return 8;
    case U0009: return 9;
    case U000A: return 10;
    case U000B: return 11;
    case U000C: return 12;
    case U000D: return 13;
    case U000E: return 14;
    case U000F: return 15;
    case U0010: return 16;
    case U0011: return 17;
    case U0012: return 18;
    case U0013: return 19;
    case U0014: return 20;
    case U0015: return 21;
    case U0016: return 22;
    case U0017: return 23;
    case U0018: return 24;
    case U0019: return 25;
    case U001A: return 26;
    case U001B: return 27;
    case U001C: return 28;
    case U001D: return 29;
    case U001E: return 30;
    case U001F: return 31;
    case U0020: return 32;
    case U0021: return 33;
    case U0022: return 34;
    case U0023: return 35;
    case U0024: return 36;
    case U0025: return 37;
    case U0026: return 38;
    case U0027: return 39;
    case U0028: return 40;
    case U0029: return 41;
    case U002A: return 42;
    case U002B: return 43;
    case U002C: return 44;
    case U002D: return 45;
    case U002E: return 46;
    case U002F: return 47;
    case U0030: return 48;
    case U0031: return 49;
    case U0032: return 50;
    case U0033: return 51;
    case U0034: return 52;
    case U0035: return 53;
    case U0036: return 54;
    case U0037: return 55;
    case U0038: return 56;
    case U0039: return 57;
    case U003A: return 58;
    case U003B: return 59;
    case U003C: return 60;
    case U003D: return 61;
    case U003E: return 62;
    case U003F: return 63;
    case U0040: return 64;
    case U0041: return 65;
    case U0042: return 66;
    case U0043: return 67;
    case U0044: return 68;
    case U0045: return 69;
    case U0046: return 70;
    case U0047: return 71;
    case U0048: return 72;
    case U0049: return 73;
    case U004A: return 74;
    case U004B: return 75;
    case U004C: return 76;
    case U004D: return 77;
    case U004E: return 78;
    case U004F: return 79;
    case U0050: return 80;
    case U0051: return 81;
    case U0052: return 82;
    case U0053: return 83;
    case U0054: return 84;
    case U0055: return 85;
    case U0056: return 86;
    case U0057: return 87;
    case U0058: return 88;
    case U0059: return 89;
    case U005A: return 90;
    case U005B: return 91;
    case U005C: return 92;
    case U005D: return 93;
    case U005E: return 94;
    case U005F: return 95;
    case U0060: return 96;
    case U0061: return 97;
    case U0062: return 98;
    case U0063: return 99;
    case U0064: return 100;
    case U0065: return 101;
    case U0066: return 102;
    case U0067: return 103;
    case U0068: return 104;
    case U0069: return 105;
    case U006A: return 106;
    case U006B: return 107;
    case U006C: return 108;
    case U006D: return 109;
    case U006E: return 110;
    case U006F: return 111;
    case U0070: return 112;
    case U0071: return 113;
    case U0072: return 114;
    case U0073: return 115;
    case U0074: return 116;
    case U0075: return 117;
    case U0076: return 118;
    case U0077: return 119;
    case U0078: return 120;
    case U0079: return 121;
    case U007A: return 122;
    case U007B: return 123;
    case U007C: return 124;
    case U007D: return 125;
    case U007E: return 126;
    case U007F: return 127;
    case U0080: return 128;
    case U0081: return 129;
    case U0082: return 130;
    case U0083: return 131;
    case U0084: return 132;
    case U0085: return 133;
    case U0086: return 134;
    case U0087: return 135;
    case U0088: return 136;
    case U0089: return 137;
    case U008A: return 138;
    case U008B: return 139;
    case U008C: return 140;
    case U008D: return 141;
    case U008E: return 142;
    case U008F: return 143;
    case U0090: return 144;
    case U0091: return 145;
    case U0092: return 146;
    case U0093: return 147;
    case U0094: return 148;
    case U0095: return 149;
    case U0096: return 150;
    case U0097: return 151;
    case U0098: return 152;
    case U0099: return 153;
    case U009A: return 154;
    case U009B: return 155;
    case U009C: return 156;
    case U009D: return 157;
    case U009E: return 158;
    case U009F: return 159;
    case U00A0: return 160;
    case U00A1: return 161;
    case U00A2: return 162;
    case U00A3: return 163;
    case U00A4: return 164;
    case U00A5: return 165;
    case U00A6: return 166;
    case U00A7: return 167;
    case U00A8: return 168;
    case U00A9: return 169;
    case U00AA: return 170;
    case U00AB: return 171;
    case U00AC: return 172;
    case U00AD: return 173;
    case U00AE: return 174;
    case U00AF: return 175;
    case U00B0: return 176;
    case U00B1: return 177;
    case U00B2: return 178;
    case U00B3: return 179;
    case U00B4: return 180;
    case U00B5: return 181;
    case U00B6: return 182;
    case U00B7: return 183;
    case U00B8: return 184;
    case U00B9: return 185;
    case U00BA: return 186;
    case U00BB: return 187;
    case U00BC: return 188;
    case U00BD: return 189;
    case U00BE: return 190;
    case U00BF: return 191;
    case U00C0: return 192;
    case U00C1: return 193;
    case U00C2: return 194;
    case U00C3: return 195;
    case U00C4: return 196;
    case U00C5: return 197;
    case U00C6: return 198;
    case U00C7: return 199;
    case U00C8: return 200;
    case U00C9: return 201;
    case U00CA: return 202;
    case U00CB: return 203;
    case U00CC: return 204;
    case U00CD: return 205;
    case U00CE: return 206;
    case U00CF: return 207;
    case U00D0: return 208;
    case U00D1: return 209;
    case U00D2: return 210;
    case U00D3: return 211;
    case U00D4: return 212;
    case U00D5: return 213;
    case U00D6: return 214;
    case U00D7: return 215;
    case U00D8: return 216;
    case U00D9: return 217;
    case U00DA: return 218;
    case U00DB: return 219;
    case U00DC: return 220;
    case U00DD: return 221;
    case U00DE: return 222;
    case U00DF: return 223;
    case U00E0: return 224;
    case U00E1: return 225;
    case U00E2: return 226;
    case U00E3: return 227;
    case U00E4: return 228;
    case U00E5: return 229;
    case U00E6: return 230;
    case U00E7: return 231;
    case U00E8: return 232;
    case U00E9: return 233;
    case U00EA: return 234;
    case U00EB: return 235;
    case U00EC: return 236;
    case U00ED: return 237;
    case U00EE: return 238;
    case U00EF: return 239;
    case U00F0: return 240;
    case U00F1: return 241;
    case U00F2: return 242;
    case U00F3: return 243;
    case U00F4: return 244;
    case U00F5: return 245;
    case U00F6: return 246;
    case U00F7: return 247;
    case U00F8: return 248;
    case U00F9: return 249;
    case U00FA: return 250;
    case U00FB: return 251;
    case U00FC: return 252;
    case U00FD: return 253;
    case U00FE: return 254;
    case U00FF: return 255;
    default: return 0;
   }
  }
  void BMPDecoding()
  {
   std::ifstream inputBMP("Database.edb");
   std::ofstream output("test.txt");
   if(inputBMP.is_open())
   {
    DeCodeInit();
    std::string reading;
    std::string tempingsad;
    unsigned int countingR = -1;
    unsigned char Temping;
    inputBMP >> Temping >> Temping >> reading;
    tempingsad = reading[0];
    while(!(tempingsad.compare("#") == 0))
    {
     inputBMP >> tempingsad;
     reading += tempingsad;
     tempingsad = reading[0];
    }
    Repeating:
    countingR += 1;
    switch(DeCode(reading[countingR]))
    {
     case 36: case 37: break;
     case 35:
      countingR += 1;
      Temping = DeCode(reading[countingR]);
      output << Temping + 35;
     goto Repeating;
     case 127:
      countingR += 1;
      Temping = DeCode(reading[countingR]);
      output << Temping + 127;
     goto Repeating;
     default: output << Temping; goto Repeating;
    }
    inputBMP.close();
   } else {output << "Error 2939: Can't open the \"Database.edb\".";}
   output.close();
  }
  bool dirExists(const char *path){struct stat info; if(stat(path, &info) != 0) return false; else if(info.st_mode & S_IFDIR) return true; else return false;}
  std::string EDBEncoding(std::string Varb01)
  {
   return "a";
  }
  std::string BMPEncoding(unsigned char Varb01)
  {
   switch(Varb01)
   {
    case 0: return "\u0000";
    case 1: return "\u0001";
    case 2: return "\u0002";
    case 3: return "\u0003";
    case 4: return "\u0004";
    case 5: return "\u0005";
    case 6: return "\u0006";
    case 7: return "\u0007";
    case 8: return "\u0008";
    case 9: return "\u0009";
    case 10: return "\u000A";
    case 11: return "\u000B";
    case 12: return "\u000C";
    case 13: return "\u000D";
    case 14: return "\u000E";
    case 15: return "\u000F";
    case 16: return "\u0010";
    case 17: return "\u0011";
    case 18: return "\u0012";
    case 19: return "\u0013";
    case 20: return "\u0014";
    case 21: return "\u0015";
    case 22: return "\u0016";
    case 23: return "\u0017";
    case 24: return "\u0018";
    case 25: return "\u0019";
    case 26: return "\u001A";
    case 27: return "\u001B";
    case 28: return "\u001C";
    case 29: return "\u001D";
    case 30: return "\u001E";
    case 31: return "\u001F";
    case 32: return "\u0020";
    case 33: return "\u0021";
    case 34: return "\u0022";
    case 35: return "\u0023\u0000";
    case 36: return "\u0023\u0001";
    case 37: return "\u0023\u0002";
    case 38: return "\u0026";
    case 39: return "\u0027";
    case 40: return "\u0028";
    case 41: return "\u0029";
    case 42: return "\u002A";
    case 43: return "\u002B";
    case 44: return "\u002C";
    case 45: return "\u002D";
    case 46: return "\u002E";
    case 47: return "\u002F";
    case 48: return "\u0030";
    case 49: return "\u0031";
    case 50: return "\u0032";
    case 51: return "\u0033";
    case 52: return "\u0034";
    case 53: return "\u0035";
    case 54: return "\u0036";
    case 55: return "\u0037";
    case 56: return "\u0038";
    case 57: return "\u0039";
    case 58: return "\u003A";
    case 59: return "\u003B";
    case 60: return "\u003C";
    case 61: return "\u003D";
    case 62: return "\u003E";
    case 63: return "\u003F";
    case 64: return "\u0040";
    case 65: return "\u0041";
    case 66: return "\u0042";
    case 67: return "\u0043";
    case 68: return "\u0044";
    case 69: return "\u0045";
    case 70: return "\u0046";
    case 71: return "\u0047";
    case 72: return "\u0048";
    case 73: return "\u0049";
    case 74: return "\u004A";
    case 75: return "\u004B";
    case 76: return "\u004C";
    case 77: return "\u004D";
    case 78: return "\u004E";
    case 79: return "\u004F";
    case 80: return "\u0050";
    case 81: return "\u0051";
    case 82: return "\u0052";
    case 83: return "\u0053";
    case 84: return "\u0054";
    case 85: return "\u0055";
    case 86: return "\u0056";
    case 87: return "\u0057";
    case 88: return "\u0058";
    case 89: return "\u0059";
    case 90: return "\u005A";
    case 91: return "\u005B";
    case 92: return "\u005C";
    case 93: return "\u005D";
    case 94: return "\u005E";
    case 95: return "\u005F";
    case 96: return "\u0060";
    case 97: return "\u0061";
    case 98: return "\u0062";
    case 99: return "\u0063";
    case 100: return "\u0064";
    case 101: return "\u0065";
    case 102: return "\u0066";
    case 103: return "\u0067";
    case 104: return "\u0068";
    case 105: return "\u0069";
    case 106: return "\u006A";
    case 107: return "\u006B";
    case 108: return "\u006C";
    case 109: return "\u006D";
    case 110: return "\u006E";
    case 111: return "\u006F";
    case 112: return "\u0070";
    case 113: return "\u0071";
    case 114: return "\u0072";
    case 115: return "\u0073";
    case 116: return "\u0074";
    case 117: return "\u0075";
    case 118: return "\u0076";
    case 119: return "\u0077";
    case 120: return "\u0078";
    case 121: return "\u0079";
    case 122: return "\u007A";
    case 123: return "\u007B";
    case 124: return "\u007C";
    case 125: return "\u007D";
    case 126: return "\u007E";

    case 127: return "\u007F\u0000";
    case 128: return "\u007F\u0001";
    case 129: return "\u007F\u0002";
    case 130: return "\u007F\u0003";
    case 131: return "\u007F\u0004";
    case 132: return "\u007F\u0005";
    case 133: return "\u007F\u0006";
    case 134: return "\u007F\u0007";
    case 135: return "\u007F\u0008";
    case 136: return "\u007F\u0009";
    case 137: return "\u007F\u000A";
    case 138: return "\u007F\u000B";
    case 139: return "\u007F\u000C";
    case 140: return "\u007F\u000D";
    case 141: return "\u007F\u000E";
    case 142: return "\u007F\u000F";
    case 143: return "\u007F\u0010";
    case 144: return "\u007F\u0011";
    case 145: return "\u007F\u0012";
    case 146: return "\u007F\u0013";
    case 147: return "\u007F\u0014";
    case 148: return "\u007F\u0015";
    case 149: return "\u007F\u0016";
    case 150: return "\u007F\u0017";
    case 151: return "\u007F\u0018";
    case 152: return "\u007F\u0019";
    case 153: return "\u007F\u001A";
    case 154: return "\u007F\u001B";
    case 155: return "\u007F\u001C";
    case 156: return "\u007F\u001D";
    case 157: return "\u007F\u001E";
    case 158: return "\u007F\u001F";
    case 159: return "\u007F\u0020";

    case 160: return "\u00A0";
    case 161: return "\u00A1";
    case 162: return "\u00A2";
    case 163: return "\u00A3";
    case 164: return "\u00A4";
    case 165: return "\u00A5";
    case 166: return "\u00A6";
    case 167: return "\u00A7";
    case 168: return "\u00A8";
    case 169: return "\u00A9";
    case 170: return "\u00AA";
    case 171: return "\u00AB";
    case 172: return "\u00AC";
    case 173: return "\u00AD";
    case 174: return "\u00AE";
    case 175: return "\u00AF";
    case 176: return "\u00B0";
    case 177: return "\u00B1";
    case 178: return "\u00B2";
    case 179: return "\u00B3";
    case 180: return "\u00B4";
    case 181: return "\u00B5";
    case 182: return "\u00B6";
    case 183: return "\u00B7";
    case 184: return "\u00B8";
    case 185: return "\u00B9";
    case 186: return "\u00BA";
    case 187: return "\u00BB";
    case 188: return "\u00BC";
    case 189: return "\u00BD";
    case 190: return "\u00BE";
    case 191: return "\u00BF";
    case 192: return "\u00C0";
    case 193: return "\u00C1";
    case 194: return "\u00C2";
    case 195: return "\u00C3";
    case 196: return "\u00C4";
    case 197: return "\u00C5";
    case 198: return "\u00C6";
    case 199: return "\u00C7";
    case 200: return "\u00C8";
    case 201: return "\u00C9";
    case 202: return "\u00CA";
    case 203: return "\u00CB";
    case 204: return "\u00CC";
    case 205: return "\u00CD";
    case 206: return "\u00CE";
    case 207: return "\u00CF";
    case 208: return "\u00D0";
    case 209: return "\u00D1";
    case 210: return "\u00D2";
    case 211: return "\u00D3";
    case 212: return "\u00D4";
    case 213: return "\u00D5";
    case 214: return "\u00D6";
    case 215: return "\u00D7";
    case 216: return "\u00D8";
    case 217: return "\u00D9";
    case 218: return "\u00DA";
    case 219: return "\u00DB";
    case 220: return "\u00DC";
    case 221: return "\u00DD";
    case 222: return "\u00DE";
    case 223: return "\u00DF";
    case 224: return "\u00E0";
    case 225: return "\u00E1";
    case 226: return "\u00E2";
    case 227: return "\u00E3";
    case 228: return "\u00E4";
    case 229: return "\u00E5";
    case 230: return "\u00E6";
    case 231: return "\u00E7";
    case 232: return "\u00E8";
    case 233: return "\u00E9";
    case 234: return "\u00EA";
    case 235: return "\u00EB";
    case 236: return "\u00EC";
    case 237: return "\u00ED";
    case 238: return "\u00EE";
    case 239: return "\u00EF";
    case 240: return "\u00F0";
    case 241: return "\u00F1";
    case 242: return "\u00F2";
    case 243: return "\u00F3";
    case 244: return "\u00F4";
    case 245: return "\u00F5";
    case 246: return "\u00F6";
    case 247: return "\u00F7";
    case 248: return "\u00F8";
    case 249: return "\u00F9";
    case 250: return "\u00FA";
    case 251: return "\u00FB";
    case 252: return "\u00FC";
    case 253: return "\u00FD";
    case 254: return "\u00FE";
    default: return "\u00FF";
   }
  }
  void DataPacking()
  {
   std::ofstream Database("Database.edb");
   std::ofstream Index("Index.edb");
   int Indexing = 0;
   std::string Temporals;
   char dataPaths[MAX_PATH];
   int Temporal;
   if(dirExists("Database\\Data")) for(const auto& DynamicEntry : std::filesystem::recursive_directory_iterator("Database\\Data"))
   {
    strcpy_s(dataPaths, DynamicEntry.path().string().c_str());
    Temporal = strlen(dataPaths);
    if(dataPaths[Temporal - 3] == 'e') if(dataPaths[Temporal - 2] == 'c') if(dataPaths[Temporal - 1] == 'd')
    {
     std::ifstream ECDF(dataPaths);
     if(!ECDF.is_open()){continue;}
     Database << "& " << Indexing << " "; Indexing += 1;
     Index << dataPaths << "\n";
     while(ECDF.is_open()){ECDF >> Temporals; Database << EDBEncoding(Temporals);}
     ECDF.close();
    }
   }
   if(dirExists("Database\\Sprite")) for(const auto& DynamicEntry : std::filesystem::recursive_directory_iterator("Database\\Sprite"))
   {
    strcpy_s(dataPaths, DynamicEntry.path().string().c_str());
    Temporal = strlen(dataPaths);
    if(dataPaths[Temporal - 3] == 'b') if(dataPaths[Temporal - 2] == 'm') if(dataPaths[Temporal - 1] == 'p')
    {
     std::ifstream BMPF(dataPaths);
     if(!BMPF.is_open()){continue;}
     Database << "# " << Indexing << " "; Indexing += 1;
     Index << dataPaths << "\n";
     unsigned char Fhead[14];
     BMPF.read(reinterpret_cast<char*>(Fhead), 14);
     unsigned char Ihead[40];
     BMPF.read(reinterpret_cast<char*>(Ihead), 40);
     int Fsize = Fhead[2] + (Fhead[3] << 8) + (Fhead[4] << 16) + (Fhead[5] << 24);
     int Fwidth = Ihead[4] + (Ihead[5] << 8) + (Ihead[6] << 16) + (Ihead[7] << 24);
     int Fheigh = Ihead[8] + (Ihead[9] << 8) + (Ihead[10] << 16) + (Ihead[11] << 24);
     Database << BMPEncoding(Fwidth % 256) << BMPEncoding((Fwidth / 256) % 256) << BMPEncoding(((Fwidth / 256) / 256) % 256) << BMPEncoding((((Fwidth / 256) / 256) / 256) % 256);
     Database << BMPEncoding(Fheigh % 256) << BMPEncoding((Fheigh / 256) % 256) << BMPEncoding(((Fheigh / 256) / 256) % 256) << BMPEncoding((((Fheigh / 256) / 256) / 256) % 256);
     unsigned char Fcolor[3];
     const int Fskip = ((4 - (Fwidth * 3) % 4) % 4);
     for(int CountB = 0; CountB < Fheigh; CountB++)
     {
      for(int CountBw = 0; CountBw < Fwidth; CountBw++)
      {
       BMPF.read(reinterpret_cast<char*>(Fcolor), 3);
       Database << BMPEncoding(Fcolor[2]) << BMPEncoding(Fcolor[1]) << BMPEncoding(Fcolor[0]);
      }
      BMPF.ignore(Fskip);
     }
     Database << " ";
     BMPF.close();
    }
   }
   Varb0001 = true;
  }
  void ID()
  {
   //if(AppRuntime == 1) Varb0001 = true;
   //if(AppRuntime == 4)
   //{
    //Varb0002 = false;
    //std::jthread LoadingThread(DataPacking);
   //}
   //if(AppRuntime == 30) BMPDecoding();

   ShowFPS = true;
   ScreenCount3 += 1;
   if(ScreenCount3 == 256){ScreenCount3 = 0; ScreenCount2 += 1;}
   if(ScreenCount2 == 256){ScreenCount2 = 0; ScreenCount += 1;}
   if(ScreenCount == 256) ScreenCount = 0;
   for(Varb0001 = 0; Varb0001 < 794 * 550; ++Varb0001)
   Display[Varb0001] = RGB(ScreenCount, ScreenCount2, ScreenCount3 + Varb0001);

   if(!Varb0001) for(Varb0001 = 100; Varb0001 < 200; ++Varb0001)
   for(temporally4 = 125; temporally4 < 225; ++temporally4)
   Display[(DisplayW * temporally4) + Varb0001] = RGB(125, 125, 125);
   
   //Drawing Objects
    Varb0001 = 0;
    while(Varb0001 < MAX_DISPOBJ)
    {
     if(ObjDisp_Exist[Varb0001])
     {
      
     }
     Varb0001 += 1;
    }
   //-//
   return;
  }
 //-//
//-//
