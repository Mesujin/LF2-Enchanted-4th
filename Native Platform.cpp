//Main Platform
 //Commands
  #include "Includes\bmp.h"
  #include "Includes\framework.h"
  #include "Includes\angelscript.h"
  #include "Includes\Native Platform.h"
  #include "Includes\scriptbuilder.h"
  #include "Includes\scriptstdstring.h"
  #include <filesystem>
  #include <fstream>
  #include <chrono>
  #include <string>
  #include <thread>
  #include <dos.h>
  #include <map>
  #define MAX_QUALITY    8294400
  #define MAX_LOADSTRING 100
  #pragma warning(disable : 4996)

  using uint64 = unsigned long long int;
  using uint32 = unsigned int;
  using uint16 = unsigned short;
  using uint8 = unsigned char;
  using int64 = long long int;
  using int32 = int;
  using int16 = short;
  using int8 = char;
  using int2 = bool;
  using string = std::string;
  using xint64 = double;
 //-//
 //Non-basic Variables
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
  string Strn0001;
  std::ostringstream Ostr0001;
  std::wstring Wstr0001;
  std::ofstream File0001;
  std::ifstream File0002;
  std::chrono::steady_clock::time_point Time0001;
  std::chrono::steady_clock::time_point Time0002;
  std::chrono::steady_clock::time_point Time0003;
  std::chrono::steady_clock::time_point Time0004;
  std::chrono::microseconds Time0005 = std::chrono::microseconds(2500);
  std::time_t Time0006;
  std::time_t Time0007;
  enum Enum0001 {U00, U01, U02, U03, U04, U05, U06, U07, U08, U09, U0A, U0B, U0C, U0D, U0E, U0F, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U1A, U1B, U1C, U1D, U1E, U1F, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U2A, U2B, U2C, U2D, U2E, U2F, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U3A, U3B, U3C, U3D, U3E, U3F, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49, U4A, U4B, U4C, U4D, U4E, U4F, U50, U51, U52, U53, U54, U55, U56, U57, U58, U59, U5A, U5B, U5C, U5D, U5E, U5F, U60, U61, U62, U63, U64, U65, U66, U67, U68, U69, U6A, U6B, U6C, U6D, U6E, U6F, U70, U71, U72, U73, U74, U75, U76, U77, U78, U79, U7A, U7B, U7C, U7D, U7E, U7F};
  enum Enum0002
  {
   Property,
    name,
    face,
    mini,
    Pic,
     w,
     h,
     row,
     col,
    Pic_End,
    maxhp,
    speed,
    weight,
    speciality,
    startingframe,
   Property_End,
   Frame,
    st,
    st2,
    st3,
    centerx,
    centery,
    wait,
    next,
    vx,
    vy,
    vz,
    in_uu,
    in_ff,
    in_dd,
    in_bb,
    in_b,
    in_a,
    in_d,
    in_j,
    in_ad,
    in_aj,
    in_dj,
    in_dfa,
    in_dfj,
    in_dda,
    in_ddj,
    in_dua,
    in_duj,
    in_dja,
    sound,
    mp,
    Catch,
     x, y, z,
    Catch_End,
    Helda,

    Helda_End,
    Heldb,

    Heldb_End,
    Body,
     rot,
    Body_End,
    Fpoint,
     kind,
    Fpoint_End,
    Bpoint,
    Bpoint_End,
    Spoint,
     pic,
     x2,
     y2,
     x3,
     y3,
     x4,
     y4,
     trans,
    Spoint_End,
    Ipoint,
     l,
     shape,
     dimen,
    Ipoint_End,
    Rpoint,
    Rpoint_End,
    Opoint,
     id,
     act,
    Opoint_End,
   Frame_End,
   Guide,
   Guide_End,
  };
  static std::map<char, Enum0001> Maps0001;
  static std::map<std::string, Enum0002> Maps0002;
  struct stat Stat0001;
 //-//
 //Basic Variables
  struct OBJECT {bool Exist; unsigned char Text; unsigned char Transparency; unsigned int Pic; unsigned int PicX1; unsigned int PicY1; unsigned int PicX2; unsigned int PicY2; double X1; double X2; double X3; double X4; double Y1; double Y2; double Y3; double Y4;};

  std::vector <COLORREF> PicColor;
  std::vector <std::string> PicAddress;
  std::vector <unsigned int> PicIndex;
  std::vector <unsigned int> PicWidth;
  std::vector <unsigned int> PicHeight;
  std::vector <OBJECT> Objects;
  
  uint64 Vrab0001 = 0;    // App Runtime
  int2 Vrab0002 = false;  // Plat Running
  int2 Vrab0003 = false;  // DynamicFPS
  int2 Vrab0004 = false;  // DynamicFPS Med
  int2 Vrab0005 = false;  // Disp FPS
  int2 Vrab0006 = false;  // Color Quality
  int32 Vrab0007 = 4;     // FPS Ratio
  int32 Vrab0008 = 400;   // Layer W
  int32 Vrab0009 = 300;   // Layer H
  int32 Vrab0010 = 400;   // Display W
  int32 Vrab0011 = 300;   // Display H
  int32 Vrab0012 = 0;     // FC
  int32 Vrab0013 = 0;     // FPI
  int32 Vrab0014 = 0;     // FPS
  int32 Vrab0015 = 0;     // Layer X
  int32 Vrab0016 = 0;     // Layer Y
  int32 Vrab0017;         // Temporal I01 : Count W
  int32 Vrab0018;         // Temporal I02 : Count H
  int32 Vrab0019;         // Temporal I03 : Temp 4th
  xint64 Vrab0020;        // Temporal D01 : Temp 3rd
  xint64 Vrab0021;        // Temporal D02 : Temp 2nd
  xint64 Vrab0022;        // Temporal D03 : Temp 1st
  xint64 Vrab0023;        // Temporal D04 : Count BitW
  xint64 Vrab0024;        // Temporal D05 : Count BitH
  uint32 Vrab0025 = 0;    // Pic Number
  uint32 Vrab0026;        // Temporal I04
  uint8 Vrab0027;         // Temporal C01
  uint16 Vrab0028;        // Temporal S01

  int32 ScreenCount = 0;
  int32 ScreenCount2 = 0;
  int32 ScreenCount3 = 0;
 //-//
 //AngelScript Communication
  struct DATASAVE
  {
   char UserName[30];
   bool LoadData(const int8 *Vrab01)
   {
    File0002.open(Vrab01);
    if(File0002.is_open())
    {
     
    } else {return false;}
    File0002.close();
   }
  };
  struct PLATFORM
  {
   void MaxObject(uint32 Vrab01){Objects.resize(Vrab01);}
   void AddObject(uint32 Vrab01, uint8 Vrab02, uint8 Vrab03, uint32 Vrab04, uint32 Vrab05, uint32 Vrab06, uint32 Vrab07, uint32 Vrab08, xint64 Vrab09, xint64 Vrab10, xint64 Vrab11, xint64 Vrab12, xint64 Vrab13, xint64 Vrab14, xint64 Vrab15, xint64 Vrab16)
   {
    Objects[Vrab01].Exist = true;
    Objects[Vrab01].Text = Vrab02;
    Objects[Vrab01].Transparency = Vrab03;
    Objects[Vrab01].Pic = Vrab04;
    Objects[Vrab01].PicX1 = Vrab05;
    Objects[Vrab01].PicY1 = Vrab06;
    Objects[Vrab01].PicX2 = Vrab07;
    Objects[Vrab01].PicY2 = Vrab08;
    Objects[Vrab01].X1 = Vrab09;
    Objects[Vrab01].X2 = Vrab10;
    Objects[Vrab01].X3 = Vrab11;
    Objects[Vrab01].X4 = Vrab12;
    Objects[Vrab01].Y1 = Vrab13;
    Objects[Vrab01].Y2 = Vrab14;
    Objects[Vrab01].Y3 = Vrab15;
    Objects[Vrab01].Y4 = Vrab16;
   }
   void DeleteObject(uint32 Vrab01){Objects[Vrab01].Exist = false;}
   void FPSDisplay(int2 Vrab01){Vrab0005 = Vrab01;}
   DATASAVE Save;
  }; PLATFORM Platform;
 //-//
 //Functions
  xint64 Rerounding(xint64 Varb01){return (Varb01 - (double)(int)Varb01);}
  xint64 InvertionR(xint64 Varb01){return 1 - (Varb01 - (double)(int)Varb01);}
  int32 Rounding(xint64 Varb01){if(Varb01 > (double)(int)Varb01 + 0.5){return (int)Varb01 + 1;} else {return (int)Varb01;}}
  int2 Exists(const int8 *Vrab01){struct stat Vrab02; if(stat(Vrab01, &Vrab02) != 0){return false;} else {if(Vrab02.st_mode & S_IFDIR) return true; return false;}}
  int2 Exist(const string &Vrab01){struct stat Vrab02; return (stat (Vrab01.c_str(), &Vrab02) == 0);}
  void Initialization(){Maps0001['\u0000'] = U00; Maps0001['\u0001'] = U01; Maps0001['\u0002'] = U02; Maps0001['\u0003'] = U03; Maps0001['\u0004'] = U04; Maps0001['\u0005'] = U05; Maps0001['\u0006'] = U06; Maps0001['\u0007'] = U07; Maps0001['\u0008'] = U08; Maps0001['\u0009'] = U09; Maps0001['\u000a'] = U0A; Maps0001['\u000b'] = U0B; Maps0001['\u000c'] = U0C; Maps0001['\u000d'] = U0D; Maps0001['\u000e'] = U0E; Maps0001['\u000f'] = U0F; Maps0001['\u0010'] = U10; Maps0001['\u0011'] = U11; Maps0001['\u0012'] = U12; Maps0001['\u0013'] = U13; Maps0001['\u0014'] = U14; Maps0001['\u0015'] = U15; Maps0001['\u0016'] = U16; Maps0001['\u0017'] = U17; Maps0001['\u0018'] = U18; Maps0001['\u0019'] = U19; Maps0001['\u001a'] = U1A; Maps0001['\u001b'] = U1B; Maps0001['\u001c'] = U1C; Maps0001['\u001d'] = U1D; Maps0001['\u001e'] = U1E; Maps0001['\u001f'] = U1F; Maps0001['\u0020'] = U20; Maps0001['\u0021'] = U21; Maps0001['\u0022'] = U22; Maps0001['\u0023'] = U23; Maps0001['\u0024'] = U24; Maps0001['\u0025'] = U25; Maps0001['\u0026'] = U26; Maps0001['\u0027'] = U27; Maps0001['\u0028'] = U28; Maps0001['\u0029'] = U29; Maps0001['\u002a'] = U2A; Maps0001['\u002b'] = U2B; Maps0001['\u002c'] = U2C; Maps0001['\u002d'] = U2D; Maps0001['\u002e'] = U2E; Maps0001['\u002f'] = U2F; Maps0001['\u0030'] = U30; Maps0001['\u0031'] = U31; Maps0001['\u0032'] = U32; Maps0001['\u0033'] = U33; Maps0001['\u0034'] = U34; Maps0001['\u0035'] = U35; Maps0001['\u0036'] = U36; Maps0001['\u0037'] = U37; Maps0001['\u0038'] = U38; Maps0001['\u0039'] = U39; Maps0001['\u003a'] = U3A; Maps0001['\u003b'] = U3B; Maps0001['\u003c'] = U3C; Maps0001['\u003d'] = U3D; Maps0001['\u003e'] = U3E; Maps0001['\u003f'] = U3F; Maps0001['\u0040'] = U40; Maps0001['\u0041'] = U41; Maps0001['\u0042'] = U42; Maps0001['\u0043'] = U43; Maps0001['\u0044'] = U44; Maps0001['\u0045'] = U45; Maps0001['\u0046'] = U46; Maps0001['\u0047'] = U47; Maps0001['\u0048'] = U48; Maps0001['\u0049'] = U49; Maps0001['\u004a'] = U4A; Maps0001['\u004b'] = U4B; Maps0001['\u004c'] = U4C; Maps0001['\u004d'] = U4D; Maps0001['\u004e'] = U4E; Maps0001['\u004f'] = U4F; Maps0001['\u0050'] = U50; Maps0001['\u0051'] = U51; Maps0001['\u0052'] = U52; Maps0001['\u0053'] = U53; Maps0001['\u0054'] = U54; Maps0001['\u0055'] = U55; Maps0001['\u0056'] = U56; Maps0001['\u0057'] = U57; Maps0001['\u0058'] = U58; Maps0001['\u0059'] = U59; Maps0001['\u005a'] = U5A; Maps0001['\u005b'] = U5B; Maps0001['\u005c'] = U5C; Maps0001['\u005d'] = U5D; Maps0001['\u005e'] = U5E; Maps0001['\u005f'] = U5F; Maps0001['\u0060'] = U60; Maps0001['\u0061'] = U61; Maps0001['\u0062'] = U62; Maps0001['\u0063'] = U63; Maps0001['\u0064'] = U64; Maps0001['\u0065'] = U65; Maps0001['\u0066'] = U66; Maps0001['\u0067'] = U67; Maps0001['\u0068'] = U68; Maps0001['\u0069'] = U69; Maps0001['\u006a'] = U6A; Maps0001['\u006b'] = U6B; Maps0001['\u006c'] = U6C; Maps0001['\u006d'] = U6D; Maps0001['\u006e'] = U6E; Maps0001['\u006f'] = U6F; Maps0001['\u0070'] = U70; Maps0001['\u0071'] = U71; Maps0001['\u0072'] = U72; Maps0001['\u0073'] = U73; Maps0001['\u0074'] = U74; Maps0001['\u0075'] = U75; Maps0001['\u0076'] = U76; Maps0001['\u0077'] = U77; Maps0001['\u0078'] = U78; Maps0001['\u0079'] = U79; Maps0001['\u007a'] = U7A; Maps0001['\u007b'] = U7B; Maps0001['\u007c'] = U7C; Maps0001['\u007d'] = U7D; Maps0001['\u007e'] = U7E; Maps0001['\u007f'] = U7F;}
  void ECDInitalization()
  {
   Maps0002["<property>"] = Property;
   Maps0002["name:"] = name;
   Maps0002["face:"] = face;
   Maps0002["mini:"] = mini;
   Maps0002["<pic>"] = Pic;
   Maps0002["w:"] = w;
   Maps0002["h:"] = h;
   Maps0002["row:"] = row;
   Maps0002["col:"] = col;
   Maps0002["<pic_end>"] = Pic_End;
   Maps0002["maxhp:"] = maxhp;
   Maps0002["speed:"] = speed;
   Maps0002["weight:"] = weight;
   Maps0002["speciality:"] = speciality;
   Maps0002["startingframe:"] = startingframe;
   Maps0002["<property_end>"] = Property_End;
   Maps0002["<frame>"] = Frame;
   Maps0002["st:"] = st;
   Maps0002["st2:"] = st2;
   Maps0002["st3:"] = st3;
   Maps0002["centerx:"] = centerx;
   Maps0002["centery:"] = centery;
   Maps0002["wait:"] = wait;
   Maps0002["next:"] = next;
   Maps0002["vx:"] = vx;
   Maps0002["vy:"] = vy;
   Maps0002["vz:"] = vz;
   Maps0002["in_uu:"] = in_uu;
   Maps0002["in_ff:"] = in_ff;
   Maps0002["in_dd:"] = in_dd;
   Maps0002["in_bb:"] = in_bb;
   Maps0002["in_b:"] = in_b;
   Maps0002["in_a:"] = in_a;
   Maps0002["in_d:"] = in_d;
   Maps0002["in_j:"] = in_j;
   Maps0002["in_ad:"] = in_ad;
   Maps0002["in_aj:"] = in_aj;
   Maps0002["in_dj:"] = in_dj;
   Maps0002["in_dfa:"] = in_dfa;
   Maps0002["in_dfj:"] = in_dfj;
   Maps0002["in_dda:"] = in_dda;
   Maps0002["in_ddj:"] = in_ddj;
   Maps0002["in_dua:"] = in_dua;
   Maps0002["in_duj:"] = in_duj;
   Maps0002["in_dja:"] = in_dja;
   Maps0002["sound:"] = sound;
   Maps0002["mp:"] = mp;
   Maps0002["<catch>"] = Catch;
   Maps0002["x:"] = x;
   Maps0002["y:"] = y;
   Maps0002["z:"] = z;

   Maps0002["<catch_end>"] = Catch_End;
   Maps0002["<helda>"] = Helda;
   //Maps0002["x:"] = x;
   //Maps0002["y:"] = y;
   //Maps0002["z:"] = z;

   Maps0002["<helda_end>"] = Helda_End;
   Maps0002["<heldb>"] = Heldb;

   Maps0002["<heldb_end>"] = Heldb_End;
   Maps0002["<body>"] = Body;
   //Maps0002["x:"] = x;
   //Maps0002["y:"] = y;
   //Maps0002["w:"] = w;
   //Maps0002["h:"] = h;
   Maps0002["rot:"] = rot;
   Maps0002["<body_end>"] = Body_End;
   Maps0002["<fpoint>"] = Fpoint;
   //Maps0002["x:"] = x;
   //Maps0002["y:"] = y;
   Maps0002["<fpoint_end>"] = Fpoint_End;
   Maps0002["<bpoint>"] = Bpoint;
   //Maps0002["x:"] = x;
   //Maps0002["y:"] = y;
   Maps0002["<bpoint_end>"] = Bpoint_End;
   Maps0002["<spoint>"] = Spoint;
   Maps0002["pic:"] = pic;
   Maps0002["x1:"] = x;
   Maps0002["y1:"] = y;
   Maps0002["x2:"] = x2;
   Maps0002["y2:"] = y2;
   Maps0002["x3:"] = x3;
   Maps0002["y3:"] = y3;
   Maps0002["x4:"] = x4;
   Maps0002["y4:"] = y4;
   Maps0002["trans:"] = trans;
   Maps0002["<spoint_end>"] = Spoint_End;
   Maps0002["<ipoint>"] = Ipoint;
   //Maps0002["x:"] = x;
   //Maps0002["y:"] = y;
   //Maps0002["z:"] = z;
   //Maps0002["w:"] = w;
   //Maps0002["h:"] = h;
   Maps0002["l:"] = l;
   Maps0002["shape:"] = shape;
   Maps0002["dimen:"] = dimen;

   Maps0002["<ipoint_end>"] = Ipoint_End;
   Maps0002["<rpoint>"] = Rpoint;
   //Maps0002["x:"] = x;
   //Maps0002["y:"] = y;
   //Maps0002["z:"] = z;
   //Maps0002["w:"] = w;
   //Maps0002["h:"] = h;
   //Maps0002["l:"] = l;
   //Maps0002["shape:"] = shape;
   //Maps0002["dimen:"] = dimen;
   Maps0002["<rpoint_end>"] = Rpoint_End;
   Maps0002["<opoint>"] = Opoint;
   Maps0002["kind:"] = kind;
   //Maps0002["x:"] = x;
   //Maps0002["y:"] = y;
   Maps0002["id:"] = id;
   Maps0002["act:"] = act;
   Maps0002["<opoint_end>"] = Opoint_End;
   Maps0002["<frame_end>"] = Frame_End;
   Maps0002["<guide>"] = Guide;

   Maps0002["<guide_end>"] = Guide_End;
  }
  xint64 DecryptionDOUBLE94(int8 Vrab01){return (xint64)(Vrab01 - 33);}
  xint64 DecryptionDOUBLE(const int8 Vrab01[11]){return DecryptionDOUBLE94(Vrab01[0]) * 8836 + DecryptionDOUBLE94(Vrab01[1]) * 94 + DecryptionDOUBLE94(Vrab01[2]) - 400000 + DecryptionDOUBLE94(Vrab01[3]) * 0.064847759419264 + DecryptionDOUBLE94(Vrab01[4]) * 0.000689869781056 + DecryptionDOUBLE94(Vrab01[5]) * 0.000007339040224 + DecryptionDOUBLE94(Vrab01[6]) * 0.000000078074896 +  DecryptionDOUBLE94(Vrab01[7]) * 0.000000000830584 + DecryptionDOUBLE94(Vrab01[8]) * 0.000000000008836 + DecryptionDOUBLE94(Vrab01[9]) * 0.000000000000094 + DecryptionDOUBLE94(Vrab01[10]) * 0.000000000000001;}
  uint32 Decryption94(int8 Vrab01){return (uint32)(Vrab01 - 33);}
  uint32 DecryptionUINT32(const int8 Vrab01[5]){return Decryption94(Vrab01[4]) + Decryption94(Vrab01[3]) * 94 + Decryption94(Vrab01[2]) * 8836 + Decryption94(Vrab01[1]) * 830584 + Decryption94(Vrab01[0]) * 78074896;}
  uint16 DecryptionUINT16(int8 Vrab01[3]){return (uint16)Decryption94(Vrab01[2]) + (uint16)Decryption94(Vrab01[1]) * 94 + (uint16)Decryption94(Vrab01[0]) * 8836;}
  uint8 DecryptionUINT8(int8 Vrab01[2]){return (uint8)Decryption94(Vrab01[1]) + (uint8)Decryption94(Vrab01[0]) * 94;}
  int32 DecryptionINT32(int8 Vrab01[5]){return (int32)Decryption94(Vrab01[4]) + (int32)Decryption94(Vrab01[3]) * 94 + Decryption94(Vrab01[2]) * 8836 + Decryption94(Vrab01[1]) * 830584 + Decryption94(Vrab01[0]) * 78074896;}
  string Encryption94(uint8 Vrab01){switch(Vrab01){case 0: return "\u0021"; case 1: return "\u0022"; case 2: return "\u0023"; case 3: return "\u0024"; case 4: return "\u0025"; case 5: return "\u0026"; case 6: return "\u0027"; case 7: return "\u0028"; case 8: return "\u0029"; case 9: return "\u002A"; case 10: return "\u002B"; case 11: return "\u002C"; case 12: return "\u002D"; case 13: return "\u002E"; case 14: return "\u002F"; case 15: return "\u0030"; case 16: return "\u0031"; case 17: return "\u0032"; case 18: return "\u0033"; case 19: return "\u0034"; case 20: return "\u0035"; case 21: return "\u0036"; case 22: return "\u0037"; case 23: return "\u0038"; case 24: return "\u0039"; case 25: return "\u003A"; case 26: return "\u003B"; case 27: return "\u003C"; case 28: return "\u003D"; case 29: return "\u003E"; case 30: return "\u003F"; case 31: return "\u0040"; case 32: return "\u0041"; case 33: return "\u0042"; case 34: return "\u0043"; case 35: return "\u0044"; case 36: return "\u0045"; case 37: return "\u0046"; case 38: return "\u0047"; case 39: return "\u0048"; case 40: return "\u0049"; case 41: return "\u004A"; case 42: return "\u004B"; case 43: return "\u004C"; case 44: return "\u004D"; case 45: return "\u004E"; case 46: return "\u004F"; case 47: return "\u0050"; case 48: return "\u0051"; case 49: return "\u0052"; case 50: return "\u0053"; case 51: return "\u0054"; case 52: return "\u0055"; case 53: return "\u0056"; case 54: return "\u0057"; case 55: return "\u0058"; case 56: return "\u0059"; case 57: return "\u005A"; case 58: return "\u005B"; case 59: return "\u005C"; case 60: return "\u005D"; case 61: return "\u005E"; case 62: return "\u005F"; case 63: return "\u0060"; case 64: return "\u0061"; case 65: return "\u0062"; case 66: return "\u0063"; case 67: return "\u0064"; case 68: return "\u0065"; case 69: return "\u0066"; case 70: return "\u0067"; case 71: return "\u0068"; case 72: return "\u0069"; case 73: return "\u006A"; case 74: return "\u006B"; case 75: return "\u006C"; case 76: return "\u006D"; case 77: return "\u006E"; case 78: return "\u006F"; case 79: return "\u0070"; case 80: return "\u0071"; case 81: return "\u0072"; case 82: return "\u0073"; case 83: return "\u0074"; case 84: return "\u0075"; case 85: return "\u0076"; case 86: return "\u0077"; case 87: return "\u0078"; case 88: return "\u0079"; case 89: return "\u007A"; case 90: return "\u007B"; case 91: return "\u007C"; case 92: return "\u007D"; case 93: return "\u007E"; default: return "";}}
  string EncryptionDOUBLE(xint64 Vrab01){Vrab01 += 400000; if(Vrab01 < 0){Vrab01 = 0;} else {if(Vrab01 > 800000) Vrab01 = 800000;} uint64 Vrab02 = (uint64)Vrab01; uint64 Vrab03 = Vrab02 / 94; Vrab0020 = (Vrab01 - (xint64)(uint64)Vrab01) * 100000; Vrab0021 = (Vrab0020 - (xint64)(uint64)Vrab0020) * 100000; Vrab0022 = (Vrab0021 - (xint64)(uint64)Vrab0021) * 100000; uint64 Vrab04 = (uint64)Vrab0020 * 10000000000 + (uint64)Vrab0021* 100000 + (uint64)Vrab0022; uint64 Vrab05 = Vrab04 / 94; uint64 Vrab06 = Vrab05 / 94; uint64 Vrab07 = Vrab06 / 94; uint64 Vrab08 = Vrab07 / 94; uint64 Vrab09 = Vrab08 / 94; uint64 Vrab10 = Vrab09 / 94; return Encryption94((Vrab03 / 94) % 94) + Encryption94(Vrab03 % 94) + Encryption94(Vrab02 % 94) + Encryption94((Vrab10 / 94) % 94) + Encryption94(Vrab10 % 94) + Encryption94(Vrab09 % 94) + Encryption94(Vrab08 % 94) + Encryption94(Vrab07 % 94) + Encryption94(Vrab06 % 94) + Encryption94(Vrab05 % 94) + Encryption94(Vrab04 % 94);}
  string EncryptionUINT32(uint32 Vrab01){uint32 Vrab02 = Vrab01 / 94; uint32 Vrab03 = Vrab02 / 94; uint32 Vrab04 = Vrab03 / 94; return Encryption94((Vrab04 / 94) % 94) + Encryption94(Vrab04 % 94) + Encryption94(Vrab03 % 94) + Encryption94(Vrab02 % 94) + Encryption94(Vrab01 % 94);}
  string EncryptionUINT16(uint16 Vrab01){uint32 Vrab02 = Vrab01 / 94; return Encryption94((Vrab02 / 94) % 94) + Encryption94(Vrab02 % 94) + Encryption94(Vrab01 % 94);}
  string EncryptionUINT8(uint8 Vrab01){return Encryption94((Vrab01 / 94) % 94) + Encryption94(Vrab01 % 94);}
  string EncryptionINT32(int32 Vrab01){return EncryptionUINT32(Vrab01);}
  string EncryptionECD(string Vrab01)
  {
   switch(Vrab0017)
   {
    case 0: //None
     switch(Maps0002[Vrab01])
     {
      case Property: Vrab0017 = 1; return "\u0021";
      case Frame: Vrab0017 = 2; File0002 >> Vrab0026 >> Strn0001; Strn0001 += "                             "; Strn0001.resize(30); return "\u0022" + EncryptionUINT32(Vrab0026) + Strn0001;
      case Guide: Vrab0017 = 3; return "\u0023";
      default: return "";
     }
    case 1: //<property>
     switch(Maps0002[Vrab01])
     {
      case name: File0002 >> Strn0001; Strn0001 += "                              "; Strn0001.resize(30); return "\u0021" + Strn0001;
      case face: File0002 >> Strn0001; Strn0001 += "                                                            "; Strn0001.resize(60); return "\u0022" + Strn0001;
      case mini: File0002 >> Strn0001; Strn0001 += "                                                            "; Strn0001.resize(60); return "\u0023" + Strn0001;
      case Pic: Vrab0017 = 4; File0002 >> Strn0001; Strn0001 += "                                                            "; Strn0001.resize(60); return "\u0024" + Strn0001;
      case maxhp: File0002 >> Vrab0026; return "\u0025" + EncryptionUINT32(Vrab0026);
      case speed: File0002 >> Vrab0026; return "\u0026" + EncryptionUINT32(Vrab0026);
      case weight: File0002 >> Vrab0020; return "\u0027" + EncryptionDOUBLE(Vrab0020);
      case speciality: File0002 >> Vrab0026; Strn0001 = EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); File0002 >> Vrab0026; Strn0001 += EncryptionUINT32(Vrab0026); return "\u0028" + Strn0001;
      case startingframe: File0002 >> Vrab0026; return "\u0029" + EncryptionUINT32(Vrab0026);
      case Property_End: Vrab0017 = 0; return "\u002A";
      default: return "";
     }
    case 2: //<frame>
     switch(Maps0002[Vrab01])
     {
      case st: File0002 >> Vrab0026; return "\u0021" + EncryptionUINT32(Vrab0026);
      case st2: File0002 >> Vrab0026; return "\u0022" + EncryptionUINT32(Vrab0026);
      case st3: File0002 >> Vrab0026; return "\u0023" + EncryptionUINT32(Vrab0026);
      case centerx: File0002 >> Vrab0018; return "\u0024" + EncryptionINT32(Vrab0018);
      case centery: File0002 >> Vrab0018; return "\u0025" + EncryptionINT32(Vrab0018);
      case wait: File0002 >> Vrab0026; return "\u0026" + EncryptionUINT32(Vrab0026);
      case next: File0002 >> Vrab0026; return "\u0027" + EncryptionUINT32(Vrab0026);
      case vx: File0002 >> Vrab0027 >> Vrab0028; return "\u0028" + EncryptionUINT8(Vrab0027) + EncryptionUINT16(Vrab0028);
      case vy: File0002 >> Vrab0027 >> Vrab0028; return "\u0029" + EncryptionUINT8(Vrab0027) + EncryptionUINT16(Vrab0028);
      case vz: File0002 >> Vrab0027 >> Vrab0028; return "\u002A" + EncryptionUINT8(Vrab0027) + EncryptionUINT16(Vrab0028);
      case in_uu: File0002 >> Vrab0027 >> Vrab0026; return "\u002B" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_bb: File0002 >> Vrab0027 >> Vrab0026; return "\u002C" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_dd: File0002 >> Vrab0027 >> Vrab0026; return "\u002D" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_ff: File0002 >> Vrab0027 >> Vrab0026; return "\u002E" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_b: File0002 >> Vrab0027 >> Vrab0026; return "\u002F" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_a: File0002 >> Vrab0027 >> Vrab0026; return "\u0030" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_d: File0002 >> Vrab0027 >> Vrab0026; return "\u0031" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_j: File0002 >> Vrab0027 >> Vrab0026; return "\u0032" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_ad: File0002 >> Vrab0027 >> Vrab0026; return "\u0033" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_aj: File0002 >> Vrab0027 >> Vrab0026; return "\u0034" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_dj: File0002 >> Vrab0027 >> Vrab0026; return "\u0035" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_dfa: File0002 >> Vrab0027 >> Vrab0026; return "\u0036" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_dfj: File0002 >> Vrab0027 >> Vrab0026; return "\u0037" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_dda: File0002 >> Vrab0027 >> Vrab0026; return "\u0038" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_ddj: File0002 >> Vrab0027 >> Vrab0026; return "\u0039" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_dua: File0002 >> Vrab0027 >> Vrab0026; return "\u003A" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_duj: File0002 >> Vrab0027 >> Vrab0026; return "\u003B" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case in_dja: File0002 >> Vrab0027 >> Vrab0026; return "\u003C" + EncryptionUINT8(Vrab0027) + EncryptionUINT32(Vrab0026);
      case sound: File0002 >> Strn0001; Strn0001 += "                              "; Strn0001.resize(30); return "\u003D" + Strn0001;
      case mp: File0002 >> Vrab0026; return "\u003E" + EncryptionUINT32(Vrab0026);
      case Helda: Vrab0017 = 5; return "\u003F";
      case Heldb: Vrab0017 = 6; return "\u0040";
      case Catch: Vrab0017 = 7; return "\u0041";
      case Body: Vrab0017 = 8; return "\u0042";
      case Spoint: Vrab0017 = 9; return "\u0043";
      case Bpoint: Vrab0017 = 10; return "\u0044";
      case Fpoint: Vrab0017 = 11; return "\u0045";
      case Ipoint: Vrab0017 = 12; return "\u0046";
      case Rpoint: Vrab0017 = 13; return "\u0047";
      case Opoint: Vrab0017 = 14; return "\u0048";
      case Frame_End: Vrab0017 = 0; return "\u0049";
      default: return "";
     }
    case 3: //<guide>
     switch(Maps0002[Vrab01])
     {
      case Guide_End: Vrab0017 = 0; return "\u0021";
      default: return "";
     }
    case 4: //<property> - <pic>
     switch(Maps0002[Vrab01])
     {
      case w: File0002 >> Vrab0026; return "\u0021" + EncryptionUINT32(Vrab0026);
      case h: File0002 >> Vrab0026; return "\u0022" + EncryptionUINT32(Vrab0026);
      case row: File0002 >> Vrab0026; return "\u0023" + EncryptionUINT32(Vrab0026);
      case col: File0002 >> Vrab0026; return "\u0024" + EncryptionUINT32(Vrab0026);
      case Pic_End: Vrab0017 = 1; return "\u0025";
      default: return "";
     }
    case 5: //<frame> - <helda>
     switch(Maps0002[Vrab01])
     {
      case Helda_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 6: //<frame> - <heldb>
     switch(Maps0002[Vrab01])
     {
      case Heldb_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 7: //<frame> - <catch>
     switch(Maps0002[Vrab01])
     {
      case Catch_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 8: //<frame> - <body>
     switch(Maps0002[Vrab01])
     {
      case Body_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 9: //<frame> - <spoint>
     switch(Maps0002[Vrab01])
     {
      case Spoint_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 10: //<frame> - <bpoint>
     switch(Maps0002[Vrab01])
     {
      case Bpoint_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 11: //<frame> - <fpoint>
     switch(Maps0002[Vrab01])
     {
      case Fpoint_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 12: //<frame> - <ipoint>
     switch(Maps0002[Vrab01])
     {
      case Ipoint_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 13: //<frame> - <rpoint>
     switch(Maps0002[Vrab01])
     {
      case Rpoint_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    case 14: //<frame> - <opoint>
     switch(Maps0002[Vrab01])
     {
      case Opoint_End: Vrab0017 = 2; return "\u0021";
      default: return "";
     }
    default: break;
   }
   return "";
  }
 //-//
 //System Functions
  void Platform_Graphic();
  void Platform_AngelScript(bool);
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
   if(Vrab0005){Strn0001 = std::to_string(Vrab0014); Wstr0001 = std::wstring(Strn0001.begin(), Strn0001.end()); TextOutW(Phdc0001, 0, 0, Wstr0001.c_str(), Strn0001.length());} DeleteObject(Bmap0001); DeleteDC(Phdc0002); return;
  }
  void Platform_Error()
  {
   File0002.open("Database\\System.as");
   int16 Vrab01 = 60;
   if(File0002.is_open()){while(File0002){File0002 >> Strn0001; if(Strn0001.compare("ConsoleBuffer") == 0){File0002 >> Strn0001; File0002 >> Vrab01; goto Labl0005;}} File0002.close();}
   Labl0005:
   File0002.close();
   switch(Vrab01){case 60: case 80: case 100: case 120: break; default: Vrab01 = 100; break;}
   AllocConsole();
   HANDLE Hand01 = GetStdHandle(STD_OUTPUT_HANDLE);
   freopen("CONIN$", "rb", stdin);
   freopen("CONOUT$", "wb", stdout);
   freopen("CONOUT$", "wb", stderr);
   SMALL_RECT Rect01 = {0, 0, Vrab01, Vrab01 / 2};
   CONSOLE_SCREEN_BUFFER_INFOEX Info01;
   Info01.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
   GetConsoleScreenBufferInfoEx(Hand01, &Info01);
   Info01.wAttributes = true;
   Info01.srWindow = Rect01;
   Info01.ColorTable[0] = RGB(255, 255, 255);
   Info01.ColorTable[1] = RGB(0, 0, 0);
   Info01.ColorTable[7] = RGB(0, 0, 0);
   SetConsoleScreenBufferSize(Hand01, {Vrab01, 150});
   SetConsoleScreenBufferInfoEx(Hand01, &Info01);
   SetConsoleTitleA("Windows Console API - LF2 Enchanted 3rd");
   printf("Error while building \'Database\\System.as\';\n\n%s\nPress 'Enter' to exit... \n(Also type 'Y'/'y' to reset it into it's original state.)\n(Or 'R'/'r' to retry.)\n: ", Ostr0001.str().c_str());
   char Vrab02;
   Ostr0001.str("");
   std::cin.get(Vrab02);
   switch(Vrab02)
   {
    case 'R':
    case 'r':
     ShowWindow(GetConsoleWindow(), 0); FreeConsole();
     Platform_AngelScript(false);
    break;
    case 'Y':
    case 'y':
     Platform_AngelScript(true);
    default: Vrab0002 = false; PostMessageW(Hwnd0001, WM_DESTROY, 0, 0); ShowWindow(GetConsoleWindow(), 0); FreeConsole(); break;
   }
  }
  void Platform_Typing(const asSMessageInfo *Vrab01,void *)
  {
   if(Vrab01->section[0] == '\0')
   {
    Ostr0001 << ": " << (Vrab01->type == asMSGTYPE_ERROR ? "ERROR" : Vrab01->type == asMSGTYPE_WARNING ? "WARNING" : "INFO") << " - " << Vrab01->message << ".\n";
   } else if(Vrab01->row == 0 && Vrab01->col == 0)
   {
    Ostr0001 << "(): " << (Vrab01->type == asMSGTYPE_ERROR ? "ERROR" : Vrab01->type == asMSGTYPE_WARNING?"WARNING" : "INFO") << " - " << Vrab01->message << ".\n";
   } else
   {
    Ostr0001 << "(" << Vrab01->row << ", " << Vrab01->col << "): " << (Vrab01->type == asMSGTYPE_ERROR ? "ERROR" : Vrab01->type == asMSGTYPE_WARNING ? "WARNING" : "INFO") << " - " << Vrab01->message << ".\n";
   }
  }
  void Platform_AngelScript(bool Vrab02)
  {
   if(!Exist("Database")){std::filesystem::create_directory("Database");}
   if(Vrab02) goto Labl0002;
   Labl0003:
   File0002.open("Database\\System.as");
   if(File0002.is_open())
   {
    Vrab0025 = 1500;
    while(File0002)
    {
     File0002 >> Strn0001;
     if(Strn0001.compare("MaximumObjNum") == 0)
     {
      File0002 >> Strn0001 >> Vrab0025;
      goto Labl0004;
     }
    }
    Labl0004:
    Objects.resize(Vrab0025 * 12);
    File0002.close();
   } else
   {
    Labl0002:
    File0001.open("Database\\System.as");
    File0001 << "uint32 MaximumObjNum = 1500 ;\n void Main(){Platform.FPSDisplay(true); return;}";
    File0001.close();
    goto Labl0003;
   }
   Engi0001 = asCreateScriptEngine();
   RegisterStdString(Engi0001);
   Engi0001->SetMessageCallback(asFUNCTION(Platform_Typing), NULL, asCALL_CDECL);
   Engi0001->RegisterObjectType("PLATFORM", 0, asOBJ_REF | asOBJ_NOCOUNT);
   //Engi0001->RegisterObjectBehaviour("PLATFORM", asBEHAVE_ADDREF, "void AddRef()", asMETHOD(PLATFORM, AddRef), asCALL_THISCALL); Engi0001->RegisterObjectBehaviour("PLATFORM", asBEHAVE_RELEASE, "void ReleaseRef()", asMETHOD(PLATFORM, ReleaseRef), asCALL_THISCALL);
   Engi0001->RegisterObjectMethod("PLATFORM", "void MaxObject(uint32 Vrab01)", asMETHOD(PLATFORM, MaxObject), asCALL_THISCALL);
   Engi0001->RegisterObjectMethod("PLATFORM", "void AddObject(uint32 Vrab01, uint8 Vrab02, uint8 Vrab03, uint32 Vrab04, uint32 Vrab05, uint32 Vrab06, uint32 Vrab07, uint32 Vrab08, double Vrab09, double Vrab10, double Vrab11, double Vrab12, double Vrab13, double Vrab14, double Vrab15, double Vrab16)", asMETHOD(PLATFORM, AddObject), asCALL_THISCALL);
   Engi0001->RegisterObjectMethod("PLATFORM", "void DeleteObject(uint32 Vrab01)", asMETHOD(PLATFORM, DeleteObject), asCALL_THISCALL);
   Engi0001->RegisterObjectMethod("PLATFORM", "void FPSDisplay(bool Vrab01)", asMETHOD(PLATFORM, FPSDisplay), asCALL_THISCALL);
   Engi0001->RegisterGlobalProperty("PLATFORM Platform", &Platform);
   CScriptBuilder Make01;
   int32 Vrab01 = Make01.StartNewModule(Engi0001, "System");
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Platform_Error();
    return;
   }
   Vrab01 = Make01.AddSectionFromFile("Database\\System.as");
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Platform_Error();
    return;
   }
   if(stat("Database\\System.as", &Stat0001) == 0) Time0007 = Stat0001.st_mtime;
   Vrab01 = Make01.BuildModule();
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Platform_Error();
    return;
   }
   Modu0001 = Engi0001->GetModule("System");
   Func0001 = Modu0001->GetFunctionByDecl("void Main()");
   Cont0001 = Engi0001->CreateContext();
  }
  void Platform_AngelUp()
  {
   CScriptBuilder Make01;
   int32 Vrab01;
   int8 Vrab02 = 0;
   Labl0005:
   Vrab01 = Make01.StartNewModule(Engi0001, "System");
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Platform_Error();
    return;
   }
   Vrab01 = Make01.AddSectionFromFile("Database\\System.as");
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    if(Vrab02 >= 50){Platform_Error(); return;}
    Ostr0001.str("");
    Vrab02 += 1;
    goto Labl0005;
   }
   Vrab01 = Make01.BuildModule();
   if(Vrab01 < 0)
   {
	Engi0001->DiscardModule("System");
    Platform_Error();
    return;
   }
   Modu0001 = Engi0001->GetModule("System");
   Func0001 = Modu0001->GetFunctionByDecl("void Main()");
   Cont0001 = Engi0001->CreateContext();
   AllocConsole();
   HANDLE Hand01 = GetStdHandle(STD_OUTPUT_HANDLE);
   freopen("CONIN$", "rb", stdin);
   freopen("CONOUT$", "wb", stdout);
   freopen("CONOUT$", "wb", stderr);
   SMALL_RECT Rect01 = {0, 0, 60, 6};
   CONSOLE_SCREEN_BUFFER_INFOEX Info01;
   Info01.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
   GetConsoleScreenBufferInfoEx(Hand01, &Info01);
   Info01.wAttributes = true;
   Info01.srWindow = Rect01;
   Info01.ColorTable[0] = RGB(255, 255, 255);
   Info01.ColorTable[1] = RGB(0, 0, 0);
   Info01.ColorTable[7] = RGB(0, 0, 0);
   SetConsoleScreenBufferInfoEx(Hand01, &Info01);
   SetConsoleScreenBufferSize(Hand01, {60, 5});
   SetConsoleTitleA("Windows Console API - LF2 Enchanted 3rd");
   printf("\n\n(): INFO - Rebuilding \'Database\\System.as\'");
   std::this_thread::sleep_for(std::chrono::seconds(1));
   ShowWindow(GetConsoleWindow(), 0); FreeConsole();
  }
  void Platform_Main()
  {
   Platform_AngelScript(false);
   Labl0001:
   Platform_Timming();
   Time0002 = std::chrono::steady_clock::now();
   if(Time0001 + std::chrono::seconds(1) < Time0002)
   {Vrab0001 += 1; if(Vrab0001 == 18446744073709551614) Vrab0001 = 1000; Time0001 += std::chrono::seconds(1); Vrab0014 = Vrab0013; Vrab0013 = 0;}
   Vrab0012 += 1;
   if(Vrab0012 != Vrab0007) if(Vrab0002){goto Labl0001;} else {return;} Vrab0012 = 0; Vrab0013 += 1;
   if(Vrab0001 >= 0)
   {
    if(stat("Database\\System.as", &Stat0001) == 0) if(Time0007 < Stat0001.st_mtime)
    {
     Time0007 = Stat0001.st_mtime;
     Engi0001->DiscardModule("System");
     Platform_AngelUp();
     if(!Vrab0002) return;
    }
    Vrab0017 = Cont0001->Prepare(Func0001);
    if(Vrab0017 < 0){Engi0001->DiscardModule("System"); Platform_Error(); if(Vrab0002){goto Labl0001;} else {return;}}
    Vrab0017 = Cont0001->Execute();
    if(Vrab0017 < 0){Engi0001->DiscardModule("System"); Platform_Error(); if(Vrab0002){goto Labl0001;} else {return;}}
   }
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
  int2 Platform_Initialization(HINSTANCE Inst01, int32 Vrab01)
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
  int32 APIENTRY wWinMain(HINSTANCE Inst01, HINSTANCE Inst02, LPWSTR Wstr01, int32 Vrab01)
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
   uint8 Menu;
   int2 InGame = false;
   uint64  Time;
   uint64  Playtime;
   uint8 Background;
  };
  GAME Game;
 //-//
 
 //Graphic
  void Platform_Building()
  {
   File0002.open("Database\\Database.edb");
   if(File0002.is_open())
   {
    File0002.close();
   } else
   {
    File0001.open("Database\\Database.edb");
    Time0006 = 0;
    int8 Vrab01[MAX_PATH];
    if(!Exist("Database")){Vrab0002 = false; PostQuitMessage(0); return;}
    for(const auto& Vrab03 : std::filesystem::recursive_directory_iterator("Database"))
    {
     strcpy_s(Vrab01, Vrab03.path().string().c_str());
     if(stat(Vrab01, &Stat0001) == 0) if(Time0006 < Stat0001.st_mtime) Time0006 = Stat0001.st_mtime;
     switch(Vrab01[strlen(Vrab01) - 2])
     {
      case 'a':
      break;
      case 'c':
       File0002.open(Vrab01);
       if(!File0002.is_open()) break;
       while(File0002)
       {File0002 >> Strn0001; File0001 << EncryptionECD(Strn0001);}
       File0002.close();
      break;
      case 'm':
      break;
      default: break;
     }
    }
    File0001.close();
   }
  }
  void Platform_Graphic()
  {
   if(Vrab0001 == 8) Platform_Building();
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
    for(Vrab0017 = 0; Vrab0017 < 1; ++Vrab0017)
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
