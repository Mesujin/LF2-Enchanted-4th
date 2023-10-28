////////////////////////////////////////////////////////////////////////////////////////////
// "engine.h"                                                                             //
//                                                                                        //
// Main source of "Hepta: Enchanted".                                                     //
// Dunno what to text here, but this is my usual style for a header text...               //
// Everything that's about the "mechanic" of the game were written here, the other part   //
// of the game, such as drawing, playing the sound, etc weren't written here.             //
//                                                                                        //
// There weren't many note about "what was it?", "what this line of code do?", etc,       //
// since most of the code were written with basic programming, i thought it might not     //
// that necessary to have a note. "A note won't help much here anyway..".                 //
//                                                                                        //
// Under GNU General Public License v3.0.                                                 //
// Written by Mesujin.                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef _HEPTA_PRAGMA_ENGINE_H
 #define _HEPTA_PRAGMA_ENGINE_H
 // Includes
  #include <random>
  #include <chrono>
  #include <filesystem>
  #include <math.h>
  #include "platform.h"
  
  // AngelScript
   #include "AngelScript/angelscript.h"
   #include "AngelScript/scriptarray.h"
   #include "AngelScript/scriptmath.h"
   #include "AngelScript/scriptmathcomplex.h"
   #include "AngelScript/scriptstdstring.h"

 // Early Declaration (In order to access Global Variables.)
  int1   L_Exist(statics string&) fastened;
  int32  L_Rounding(statics xint64) fastened;
  int64  L_Rounding64(statics xint64) fastened;
  string L_Directory(statics string) fastened;
  string L_Lowercase(string Temp01) fastened;
  int0   EIDP_LF2Enchanted(uint32, uint64) fastened;

 // Global Variables
  string Temp0001 = "";     // App Working Directory.
  uint64 Vrab0001 = 0;      // App Runtime.
  uint64 Vrab0002 = 0;      // App Looptime.
  uint8  Vrab0003 = 8;      // App FPS Ratio. (1 = 960, 2 = 480, 4 = 240, 8 = 120, 16 = 60, 32 = 30, 64 = 15, 128 = 7.5)
  int1   Vrab0004 = false;  // Display Update?
  uint32 Vrab0005 = 1920;   // Display Width Resolution.
  uint32 Vrab0006 = 1080;   // Display Height Resolution.
  uint32 Vrab0007 = 0;      // Display X Offset.
  uint32 Vrab0008 = 0;      // Display Y Offset.
  int1   Vrab0009 = false;  // Display Fullscreen?
  int1   Vrab0010 = true;   // Display Keep Aspect Ratio?
  int1   Vrab0011 = false;  // Display Force Pixel Resolution?
  xint32 Vrab0012 = 0.1f;   // Audio Volume.
  xint32 Vrab0013 = 0.0f;   // Audio Pan.
  xint64 Vrab0014 = 0.0;    // Input Mouse X Offset Ratio.
  xint64 Vrab0015 = 0.0;    // Input Mouse Y Offset Ratio.
  uint8  Vrab0016 = 70;     // Input Keyboard Default OK.
  uint8  Vrab0017 = 52;     // Input Keyboard Default CANCEL.
  uint8  Vrab0018 = 48;     // Input Keyboard Default UP.
  uint8  Vrab0019 = 49;     // Input Keyboard Default LEFT.
  uint8  Vrab0020 = 50;     // Input Keyboard Default DOWN.
  uint8  Vrab0021 = 51;     // Input Keyboard Default RIGHT.
  uint8  Vrab0022 = 0;      // Input Pad Default OK.
  uint8  Vrab0023 = 0;      // Input Pad Default CANCEL.
  uint8  Vrab0024 = 0;      // Input Pad Default UP.
  uint8  Vrab0025 = 0;      // Input Pad Default LEFT.
  uint8  Vrab0026 = 0;      // Input Pad Default DOWN.
  uint8  Vrab0027 = 0;      // Input Pad Default RIGHT.
  uint32 Vrab0028 = 800;    // Window Width.
  uint32 Vrab0029 = 450;    // Window Height.
  int1   Vrab0030 = false;  // Window Exit?
  uint64 Vrab0031 = 0;      // Random Seed.
  int1   Vrab0032 = true;   // Random Reset.

  uint8  Vrab0033 = 0;      // LF2_Enchanted Status.
 
 // Stuctures
  struct HEPTA_INPUT
  {
   int1  RESH_ANY;

   uint8 MAIN_1; uint8 MAIN_2; uint8 MAIN_3; uint8 MAIN_4; uint8 MAIN_5; uint8 MAIN_6; uint8 MAIN_7; uint8 MAIN_8; uint8 MAIN_9; uint8 MAIN_0;
   uint8 MAIN_A; uint8 MAIN_B; uint8 MAIN_C; uint8 MAIN_D; uint8 MAIN_E; uint8 MAIN_F; uint8 MAIN_G; uint8 MAIN_H; uint8 MAIN_I; uint8 MAIN_J; uint8 MAIN_K; uint8 MAIN_L; uint8 MAIN_M; uint8 MAIN_N; uint8 MAIN_O; uint8 MAIN_P; uint8 MAIN_Q; uint8 MAIN_R; uint8 MAIN_S; uint8 MAIN_T; uint8 MAIN_U; uint8 MAIN_V; uint8 MAIN_W; uint8 MAIN_X; uint8 MAIN_Y; uint8 MAIN_Z;
   uint8 MAIN_TILDE;        // ` ~
   uint8 MAIN_MINUS;        // - _
   uint8 MAIN_PLUS;         // = +
   uint8 MAIN_OPENBRACKED;  // [ {
   uint8 MAIN_CLOSEBRACKED; // ] }
   uint8 MAIN_PIPE;         // \ |
   uint8 MAIN_SEMICOLON;    // ; :
   uint8 MAIN_QUOTES;       // ' "
   uint8 MAIN_QUESTION;     // / ?
   uint8 MAIN_PERIOD;       // . >
   uint8 MAIN_COMMA;        // , <
   uint8 MAIN_SPACE;        // 

   uint8 CONS_F1; uint8 CONS_F2; uint8 CONS_F3; uint8 CONS_F4; uint8 CONS_F5; uint8 CONS_F6; uint8 CONS_F7; uint8 CONS_F8; uint8 CONS_F9; uint8 CONS_F10; uint8 CONS_F11; uint8 CONS_F12;
   uint8 CONS_ESC; uint8 CONS_PRTSC; uint8 CONS_DELETE; uint8 CONS_BACK; uint8 CONS_TAB; uint8 CONS_CAPS; uint8 CONS_ENTER;
   uint8 CONS_LSHIFT; uint8 CONS_RSHIFT;
   uint8 CONS_LALT; uint8 CONS_RALT;
   uint8 CONS_LCTRL; uint8 CONS_RCTRL;
   uint8 CONS_UP; uint8 CONS_LEFT; uint8 CONS_DOWN; uint8 CONS_RIGHT;
   uint8 CONS_WINDOWS;
   int1  RESH_CAPS;

   uint8 NUMS_NUMLOCK;
   uint8 NUMS_MULTIPLE; uint8 NUMS_DEVIDE; uint8 NUMS_ADD; uint8 NUMS_SUBTRACT; uint8 NUMS_POINT;
   uint8 NUMS_0; uint8 NUMS_1; uint8 NUMS_2; uint8 NUMS_3; uint8 NUMS_4; uint8 NUMS_5; uint8 NUMS_6; uint8 NUMS_7; uint8 NUMS_8; uint8 NUMS_9;

   int32 MOUS_X;
   int32 MOUS_Y;
   uint8 MOUS_Left;
   uint8 MOUS_Right;
   uint8 MOUS_Mid;
   uint8 MOUS_Left_Release;
   uint8 MOUS_Right_Release;
   uint8 MOUS_Mid_Release;
   int32 MOUS_X_Left;
   int32 MOUS_Y_Left;
   int32 MOUS_X_Right;
   int32 MOUS_Y_Right;
   int32 MOUS_X_Mid;
   int32 MOUS_Y_Mid;
   int32 MOUS_SCROLL;
   int32 MOUS_SCROLL2;

   int1  PADS_ON;
  };

  struct HEPTA_LF2_ENCHANTED
  {
   // Variables
    int1   Vrab001 = true;          // Initialization.
    insize Vrab002 = rinsize(-1);   // Background Index.
    int1   Vrab003 = false;         // Background Type.
    std::vector < uint8 >  Vect001; // Window Order.
    std::vector < insize > Vect002; // Interface Index - Background(s).
    std::vector < int1 >   Vect003; // Interface Index - Background(s)'s Type.
    std::vector < insize > Vect004; // Interface Index - Images.
    std::vector < insize > Vect005; // Interface Index - Sound.

   // Structures
    struct HEPTA_LF2_ENCHANTED_SETTING_PLAYER_MACRO
    {
     int1   Latency = false;
     int1   Loop_Cancel = true;
     uint8  Key = 0;
     uint16 Loop = 0;
     std::vector < std::vector < uint8 > > Input;
    };
    struct HEPTA_LF2_ENCHANTED_SETTING_PLAYER
    {
     string Name;
     uint8  Type  = 0;
     uint8  Up    = 26;
     uint8  Left  = 22;
     uint8  Down  = 43;
     uint8  Right = 44;
     uint8  Attack  = 21;
     uint8  Defend  = 40;
     uint8  Jump    = 41;
     uint8  Command = 25;
     uint8  P_Up    = 0;
     uint8  P_Left  = 0;
     uint8  P_Down  = 0;
     uint8  P_Right = 0;
     uint8  P_Attack  = 0;
     uint8  P_Defend  = 0;
     uint8  P_Jump    = 0;
     uint8  P_Command = 0;
     std::vector < HEPTA_LF2_ENCHANTED_SETTING_PLAYER_MACRO > Macro;
    };
    struct HEPTA_LF2_ENCHANTED_SETTING
    {
     int64  Width  = 800;
     int64  Height = 450;
     int1   Fullscreen = true;
     int1   Aspect_Ratio = true;
     uint8  UI_FPS = 8;
     uint8  Brightness = 100;
     uint8  Volume = 80;
     int8   Pan = 0;

     int1   Fast_Loading = false;
     int1   Skip_Animation = false;
     int1   Show_FPS = true;
     uint8  Engine = 0;
     string Engine_Setting;
     string Address = "Database\\MiniGame_Enchanted\\";
     string Address_Game = "GameData_Default\\";
     string Address_Data = "data\\data.txt";
     string Address_Interface = "Interface\\";
     string Address_Recording = "Recordings\\";

     uint8  Health_Bar = 0;
     uint8  Camera_Speed = 100;
     insize Max_SFX = 8;
     insize Max_Object = 1000;

     uint8  Esc = 52;   // Common Exit / Cancel
     uint8  Enter = 70; // Common Select / Ok
     uint8  F1 = 53;    // Common Pause
     uint8  F2 = 54;    // Common Forced Pause
     uint8  F10 = 62;   // Common Volume Up
     uint8  F11 = 63;   // Common Volume Down
     uint8  F12 = 64;   // Common Half Brightness
     uint8  F3 = 55;    // Special Function 1
     uint8  F4 = 56;    // Special Function 2
     uint8  F5 = 57;    // Special Function 3
     uint8  F6 = 58;    // Special Function 4
     uint8  F7 = 59;    // Special Function 5
     uint8  F8 = 60;    // Special Function 6
     uint8  F9 = 61;    // Special Function 7

     int1   Recording = true;
     int1   True_Recording = false;
     string User  = "<none>";
     string Email = "<none>";
     string Note  = "<none>";

     std::vector < HEPTA_LF2_ENCHANTED_SETTING_PLAYER > Player;
    };
     
    HEPTA_LF2_ENCHANTED_SETTING Setting[2];

   // Functions
    int0  Setting_Load() fastened
    {
    
    }
    int0  Setting_Save() fastened
    {
    
    }
  };

 // Unique
  unique < HEPTA_INPUT > Input;
  unique < HEPTA_LF2_ENCHANTED > Enchanted;

 // Light Functions
  int1   L_Any()                             fastened {return Input->RESH_ANY;}
  int1   L_Exist(statics string &Temp01)     fastened {struct stat Vrab01; return (stat(Temp01.c_str(), &Vrab01) == 0);} // Check if the certain directory is exist or not.
  uint8  L_Input(uint8 Vrab01)               fastened
  {
   switch(Vrab01)
   {
    case 1: return Input->MAIN_1;
    case 2: return Input->MAIN_2;
    case 3: return Input->MAIN_3;
    case 4: return Input->MAIN_4;
    case 5: return Input->MAIN_5;
    case 6: return Input->MAIN_6;
    case 7: return Input->MAIN_7;
    case 8: return Input->MAIN_8;
    case 9: return Input->MAIN_9;
    case 10: return Input->MAIN_0;
    case 11: return Input->MAIN_A;
    case 12: return Input->MAIN_B;
    case 13: return Input->MAIN_C;
    case 14: return Input->MAIN_D;
    case 15: return Input->MAIN_E;
    case 16: return Input->MAIN_F;
    case 17: return Input->MAIN_G;
    case 18: return Input->MAIN_H;
    case 19: return Input->MAIN_I;
    case 20: return Input->MAIN_J;
    case 21: return Input->MAIN_K;
    case 22: return Input->MAIN_L;
    case 23: return Input->MAIN_M;
    case 24: return Input->MAIN_N;
    case 25: return Input->MAIN_O;
    case 26: return Input->MAIN_P;
    case 27: return Input->MAIN_Q;
    case 28: return Input->MAIN_R;
    case 29: return Input->MAIN_S;
    case 30: return Input->MAIN_T;
    case 31: return Input->MAIN_U;
    case 32: return Input->MAIN_V;
    case 33: return Input->MAIN_W;
    case 34: return Input->MAIN_X;
    case 35: return Input->MAIN_Y;
    case 36: return Input->MAIN_Z;
    case 37: return Input->MAIN_TILDE;
    case 38: return Input->MAIN_MINUS;
    case 39: return Input->MAIN_PLUS;
    case 40: return Input->MAIN_OPENBRACKED;
    case 41: return Input->MAIN_CLOSEBRACKED;
    case 42: return Input->MAIN_PIPE;
    case 43: return Input->MAIN_SEMICOLON;
    case 44: return Input->MAIN_QUOTES;
    case 45: return Input->MAIN_QUESTION;
    case 46: return Input->MAIN_PERIOD;
    case 47: return Input->MAIN_COMMA;
    case 48: return Input->CONS_UP;
    case 49: return Input->CONS_LEFT;
    case 50: return Input->CONS_DOWN;
    case 51: return Input->CONS_RIGHT;
    case 52: return Input->CONS_ESC;
    case 53: return Input->CONS_F1;
    case 54: return Input->CONS_F2;
    case 55: return Input->CONS_F3;
    case 56: return Input->CONS_F4;
    case 57: return Input->CONS_F5;
    case 58: return Input->CONS_F6;
    case 59: return Input->CONS_F7;
    case 60: return Input->CONS_F8;
    case 61: return Input->CONS_F9;
    case 62: return Input->CONS_F10;
    case 63: return Input->CONS_F11;
    case 64: return Input->CONS_F12;
    case 65: return Input->CONS_PRTSC;
    case 66: return Input->CONS_DELETE;
    case 67: return Input->CONS_BACK;
    case 68: return Input->CONS_TAB;
    case 69: return Input->CONS_CAPS;
    case 70: return Input->CONS_ENTER;
    case 71: return Input->CONS_LSHIFT;
    case 72: return Input->CONS_RSHIFT;
    case 73: return Input->CONS_LCTRL;
    case 74: return Input->CONS_RCTRL;
    case 75: return Input->CONS_LALT;
    case 76: return Input->CONS_RALT;
    case 77: return Input->NUMS_NUMLOCK;
    case 78: return Input->NUMS_MULTIPLE;
    case 79: return Input->NUMS_DEVIDE;
    case 80: return Input->NUMS_ADD;
    case 81: return Input->NUMS_SUBTRACT;
    case 82: return Input->NUMS_1;
    case 83: return Input->NUMS_2;
    case 84: return Input->NUMS_3;
    case 85: return Input->NUMS_4;
    case 86: return Input->NUMS_5;
    case 87: return Input->NUMS_6;
    case 88: return Input->NUMS_7;
    case 89: return Input->NUMS_8;
    case 90: return Input->NUMS_9;
    case 91: return Input->NUMS_0;
    case 92: return Input->NUMS_POINT;
    case 94: return Input->MAIN_SPACE;
   
    default: return 0;
   }
  }
  uint8  L_Press()                           fastened 
  {
   if(L_Input(Vrab0016) == 1 || L_Input(Vrab0017) == 1) return 0ui8;
   if(Input->MAIN_1 == 1) return 1ui8;
   if(Input->MAIN_2 == 1) return 2ui8;
   if(Input->MAIN_3 == 1) return 3ui8;
   if(Input->MAIN_4 == 1) return 4ui8;
   if(Input->MAIN_5 == 1) return 5ui8;
   if(Input->MAIN_6 == 1) return 6ui8;
   if(Input->MAIN_7 == 1) return 7ui8;
   if(Input->MAIN_8 == 1) return 8ui8;
   if(Input->MAIN_9 == 1) return 9ui8;
   if(Input->MAIN_0 == 1) return 10ui8;
   if(Input->MAIN_A == 1) return 11ui8;
   if(Input->MAIN_B == 1) return 12ui8;
   if(Input->MAIN_C == 1) return 13ui8;
   if(Input->MAIN_D == 1) return 14ui8;
   if(Input->MAIN_E == 1) return 15ui8;
   if(Input->MAIN_F == 1) return 16ui8;
   if(Input->MAIN_G == 1) return 17ui8;
   if(Input->MAIN_H == 1) return 18ui8;
   if(Input->MAIN_I == 1) return 19ui8;
   if(Input->MAIN_J == 1) return 20ui8;
   if(Input->MAIN_K == 1) return 21ui8;
   if(Input->MAIN_L == 1) return 22ui8;
   if(Input->MAIN_M == 1) return 23ui8;
   if(Input->MAIN_N == 1) return 24ui8;
   if(Input->MAIN_O == 1) return 25ui8;
   if(Input->MAIN_P == 1) return 26ui8;
   if(Input->MAIN_Q == 1) return 27ui8;
   if(Input->MAIN_R == 1) return 28ui8;
   if(Input->MAIN_S == 1) return 29ui8;
   if(Input->MAIN_T == 1) return 30ui8;
   if(Input->MAIN_U == 1) return 31ui8;
   if(Input->MAIN_V == 1) return 32ui8;
   if(Input->MAIN_W == 1) return 33ui8;
   if(Input->MAIN_X == 1) return 34ui8;
   if(Input->MAIN_Y == 1) return 35ui8;
   if(Input->MAIN_Z == 1) return 36ui8;
   if(Input->MAIN_TILDE == 1)        return 37ui8;
   if(Input->MAIN_MINUS == 1)        return 38ui8;
   if(Input->MAIN_PLUS == 1)         return 39ui8;
   if(Input->MAIN_OPENBRACKED == 1)  return 40ui8;
   if(Input->MAIN_CLOSEBRACKED == 1) return 41ui8;
   if(Input->MAIN_PIPE == 1)         return 42ui8;
   if(Input->MAIN_SEMICOLON == 1)    return 43ui8;
   if(Input->MAIN_QUOTES == 1)       return 44ui8;
   if(Input->MAIN_QUESTION == 1)     return 45ui8;
   if(Input->MAIN_PERIOD == 1)       return 46ui8;
   if(Input->MAIN_COMMA == 1)        return 47ui8;
   if(Input->CONS_UP == 1)    return 48ui8;
   if(Input->CONS_LEFT == 1)  return 49ui8;
   if(Input->CONS_DOWN == 1)  return 50ui8;
   if(Input->CONS_RIGHT == 1) return 51ui8;
   if(Input->CONS_ESC == 1) return 52ui8;
   if(Input->CONS_F1 == 1)  return 53ui8;
   if(Input->CONS_F2 == 1)  return 54ui8;
   if(Input->CONS_F3 == 1)  return 55ui8;
   if(Input->CONS_F4 == 1)  return 56ui8;
   if(Input->CONS_F5 == 1)  return 57ui8;
   if(Input->CONS_F6 == 1)  return 58ui8;
   if(Input->CONS_F7 == 1)  return 59ui8;
   if(Input->CONS_F8 == 1)  return 60ui8;
   if(Input->CONS_F9 == 1)  return 61ui8;
   if(Input->CONS_F10 == 1) return 62ui8;
   if(Input->CONS_F11 == 1) return 63ui8;
   if(Input->CONS_F12 == 1) return 64ui8;
   if(Input->CONS_PRTSC == 1)  return 65ui8;
   if(Input->CONS_DELETE == 1) return 66ui8;
   if(Input->CONS_BACK == 1)   return 67ui8;
   if(Input->CONS_TAB == 1)    return 68ui8;
   if(Input->CONS_CAPS == 1)   return 69ui8;
   if(Input->CONS_ENTER == 1)  return 70ui8;
   if(Input->CONS_LSHIFT == 1) return 71ui8;
   if(Input->CONS_RSHIFT == 1) return 72ui8;
   if(Input->CONS_LCTRL == 1)  return 73ui8;
   if(Input->CONS_RCTRL == 1)  return 74ui8;
   if(Input->CONS_LALT == 1)   return 75ui8;
   if(Input->CONS_RALT == 1)   return 76ui8;
   if(Input->NUMS_NUMLOCK == 1)  return 77ui8;
   if(Input->NUMS_MULTIPLE == 1) return 78ui8;
   if(Input->NUMS_DEVIDE == 1)   return 79ui8;
   if(Input->NUMS_ADD == 1)      return 80ui8;
   if(Input->NUMS_SUBTRACT == 1) return 81ui8;
   if(Input->NUMS_1 == 1) return 82ui8;
   if(Input->NUMS_2 == 1) return 83ui8;
   if(Input->NUMS_3 == 1) return 84ui8;
   if(Input->NUMS_4 == 1) return 85ui8;
   if(Input->NUMS_5 == 1) return 86ui8;
   if(Input->NUMS_6 == 1) return 87ui8;
   if(Input->NUMS_7 == 1) return 88ui8;
   if(Input->NUMS_8 == 1) return 89ui8;
   if(Input->NUMS_9 == 1) return 90ui8;
   if(Input->NUMS_0 == 1) return 91ui8;
   if(Input->NUMS_POINT == 1) return 92ui8;
   if(Input->MAIN_SPACE == 1) return 94ui8;
   return 255ui8;
  }
  int32  L_Rounding(statics xint64 Vrab01)   fastened {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint32(Vrab01); return rint32(Vrab01) + (Vrab02 ? -1 : 1);} // Round xint64 into int32.
  int64  L_Rounding64(statics xint64 Vrab01) fastened {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint64(Vrab01); return rint64(Vrab01) + (Vrab02 ? -1 : 1);} // Round xint64 into int64.
  uint64 L_Random(uint64 Vrab01)             fastened {remains std::mt19937 Varb01; if(Vrab0032){Varb01 = std::mt19937(ruint32(Vrab0031)); Vrab0032 = false;} Vrab0031 += 1; uint64 Vrab02 = ruint64(Varb01()); Vrab02 %= ruint64(0xFFFFFFFF) + 1; return ruint64(L_Rounding64((rxint64(Vrab02) / rxint64(0xFFFFFFFF)) * rxint64(Vrab01)));}
  string L_Directory(statics string Temp01)  fastened {return Temp0001 + Temp01;}
  string L_Lowercase(string Temp01)          fastened {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) >= 'A' && Temp01.at(Vrab01) <= 'Z') Temp01.at(Vrab01) += 32;} return Temp01;}

 // Main Functions
  int0 M_EngineInput(DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01) fastened
  {
   int1 Vrab01 = false;
   auto Ikey02 = Ikey01->GetState(); statics uint8 Vrab02 = ruint8(L_Rounding(256.0 / rxint64(Vrab0003)) - 1), Vrab03 = Vrab02 - ruint8(L_Rounding(32.0 / rxint64(Vrab0003))); 
   if(Ikey02.D0){Vrab01 = true; if((++Input->MAIN_0) == Vrab02) Input->MAIN_0 = Vrab03;} else {Input->MAIN_0 = 0ui8;}
   if(Ikey02.D1){Vrab01 = true; if((++Input->MAIN_1) == Vrab02) Input->MAIN_1 = Vrab03;} else {Input->MAIN_1 = 0ui8;}
   if(Ikey02.D2){Vrab01 = true; if((++Input->MAIN_2) == Vrab02) Input->MAIN_2 = Vrab03;} else {Input->MAIN_2 = 0ui8;}
   if(Ikey02.D3){Vrab01 = true; if((++Input->MAIN_3) == Vrab02) Input->MAIN_3 = Vrab03;} else {Input->MAIN_3 = 0ui8;}
   if(Ikey02.D4){Vrab01 = true; if((++Input->MAIN_4) == Vrab02) Input->MAIN_4 = Vrab03;} else {Input->MAIN_4 = 0ui8;}
   if(Ikey02.D5){Vrab01 = true; if((++Input->MAIN_5) == Vrab02) Input->MAIN_5 = Vrab03;} else {Input->MAIN_5 = 0ui8;}
   if(Ikey02.D6){Vrab01 = true; if((++Input->MAIN_6) == Vrab02) Input->MAIN_6 = Vrab03;} else {Input->MAIN_6 = 0ui8;}
   if(Ikey02.D7){Vrab01 = true; if((++Input->MAIN_7) == Vrab02) Input->MAIN_7 = Vrab03;} else {Input->MAIN_7 = 0ui8;}
   if(Ikey02.D8){Vrab01 = true; if((++Input->MAIN_8) == Vrab02) Input->MAIN_8 = Vrab03;} else {Input->MAIN_8 = 0ui8;}
   if(Ikey02.D9){Vrab01 = true; if((++Input->MAIN_9) == Vrab02) Input->MAIN_9 = Vrab03;} else {Input->MAIN_9 = 0ui8;}
   if(Ikey02.A) {Vrab01 = true; if((++Input->MAIN_A) == Vrab02) Input->MAIN_A = Vrab03;} else {Input->MAIN_A = 0ui8;}
   if(Ikey02.B) {Vrab01 = true; if((++Input->MAIN_B) == Vrab02) Input->MAIN_B = Vrab03;} else {Input->MAIN_B = 0ui8;}
   if(Ikey02.C) {Vrab01 = true; if((++Input->MAIN_C) == Vrab02) Input->MAIN_C = Vrab03;} else {Input->MAIN_C = 0ui8;}
   if(Ikey02.D) {Vrab01 = true; if((++Input->MAIN_D) == Vrab02) Input->MAIN_D = Vrab03;} else {Input->MAIN_D = 0ui8;}
   if(Ikey02.E) {Vrab01 = true; if((++Input->MAIN_E) == Vrab02) Input->MAIN_E = Vrab03;} else {Input->MAIN_E = 0ui8;}
   if(Ikey02.F) {Vrab01 = true; if((++Input->MAIN_F) == Vrab02) Input->MAIN_F = Vrab03;} else {Input->MAIN_F = 0ui8;}
   if(Ikey02.G) {Vrab01 = true; if((++Input->MAIN_G) == Vrab02) Input->MAIN_G = Vrab03;} else {Input->MAIN_G = 0ui8;}
   if(Ikey02.H) {Vrab01 = true; if((++Input->MAIN_H) == Vrab02) Input->MAIN_H = Vrab03;} else {Input->MAIN_H = 0ui8;}
   if(Ikey02.I) {Vrab01 = true; if((++Input->MAIN_I) == Vrab02) Input->MAIN_I = Vrab03;} else {Input->MAIN_I = 0ui8;}
   if(Ikey02.J) {Vrab01 = true; if((++Input->MAIN_J) == Vrab02) Input->MAIN_J = Vrab03;} else {Input->MAIN_J = 0ui8;}
   if(Ikey02.K) {Vrab01 = true; if((++Input->MAIN_K) == Vrab02) Input->MAIN_K = Vrab03;} else {Input->MAIN_K = 0ui8;}
   if(Ikey02.L) {Vrab01 = true; if((++Input->MAIN_L) == Vrab02) Input->MAIN_L = Vrab03;} else {Input->MAIN_L = 0ui8;}
   if(Ikey02.M) {Vrab01 = true; if((++Input->MAIN_M) == Vrab02) Input->MAIN_M = Vrab03;} else {Input->MAIN_M = 0ui8;}
   if(Ikey02.N) {Vrab01 = true; if((++Input->MAIN_N) == Vrab02) Input->MAIN_N = Vrab03;} else {Input->MAIN_N = 0ui8;}
   if(Ikey02.O) {Vrab01 = true; if((++Input->MAIN_O) == Vrab02) Input->MAIN_O = Vrab03;} else {Input->MAIN_O = 0ui8;}
   if(Ikey02.P) {Vrab01 = true; if((++Input->MAIN_P) == Vrab02) Input->MAIN_P = Vrab03;} else {Input->MAIN_P = 0ui8;}
   if(Ikey02.Q) {Vrab01 = true; if((++Input->MAIN_Q) == Vrab02) Input->MAIN_Q = Vrab03;} else {Input->MAIN_Q = 0ui8;}
   if(Ikey02.R) {Vrab01 = true; if((++Input->MAIN_R) == Vrab02) Input->MAIN_R = Vrab03;} else {Input->MAIN_R = 0ui8;}
   if(Ikey02.S) {Vrab01 = true; if((++Input->MAIN_S) == Vrab02) Input->MAIN_S = Vrab03;} else {Input->MAIN_S = 0ui8;}
   if(Ikey02.T) {Vrab01 = true; if((++Input->MAIN_T) == Vrab02) Input->MAIN_T = Vrab03;} else {Input->MAIN_T = 0ui8;}
   if(Ikey02.U) {Vrab01 = true; if((++Input->MAIN_U) == Vrab02) Input->MAIN_U = Vrab03;} else {Input->MAIN_U = 0ui8;}
   if(Ikey02.V) {Vrab01 = true; if((++Input->MAIN_V) == Vrab02) Input->MAIN_V = Vrab03;} else {Input->MAIN_V = 0ui8;}
   if(Ikey02.W) {Vrab01 = true; if((++Input->MAIN_W) == Vrab02) Input->MAIN_W = Vrab03;} else {Input->MAIN_W = 0ui8;}
   if(Ikey02.X) {Vrab01 = true; if((++Input->MAIN_X) == Vrab02) Input->MAIN_X = Vrab03;} else {Input->MAIN_X = 0ui8;}
   if(Ikey02.Y) {Vrab01 = true; if((++Input->MAIN_Y) == Vrab02) Input->MAIN_Y = Vrab03;} else {Input->MAIN_Y = 0ui8;}
   if(Ikey02.Z) {Vrab01 = true; if((++Input->MAIN_Z) == Vrab02) Input->MAIN_Z = Vrab03;} else {Input->MAIN_Z = 0ui8;}
   if(Ikey02.OemTilde)        {Vrab01 = true; if((++Input->MAIN_TILDE) == Vrab02) Input->MAIN_TILDE = Vrab03;} else {Input->MAIN_TILDE = 0ui8;}
   if(Ikey02.OemMinus)        {Vrab01 = true; if((++Input->MAIN_MINUS) == Vrab02) Input->MAIN_MINUS = Vrab03;} else {Input->MAIN_MINUS = 0ui8;}
   if(Ikey02.OemPlus)         {Vrab01 = true; if((++Input->MAIN_PLUS) == Vrab02) Input->MAIN_PLUS = Vrab03;} else {Input->MAIN_PLUS = 0ui8;}
   if(Ikey02.OemOpenBrackets) {Vrab01 = true; if((++Input->MAIN_OPENBRACKED) == Vrab02) Input->MAIN_OPENBRACKED = Vrab03;} else {Input->MAIN_OPENBRACKED = 0ui8;}
   if(Ikey02.OemCloseBrackets){Vrab01 = true; if((++Input->MAIN_CLOSEBRACKED) == Vrab02) Input->MAIN_CLOSEBRACKED = Vrab03;} else {Input->MAIN_CLOSEBRACKED = 0ui8;}
   if(Ikey02.OemPipe)         {Vrab01 = true; if((++Input->MAIN_PIPE) == Vrab02) Input->MAIN_PIPE = Vrab03;} else {Input->MAIN_PIPE = 0ui8;}
   if(Ikey02.OemSemicolon)    {Vrab01 = true; if((++Input->MAIN_SEMICOLON) == Vrab02) Input->MAIN_SEMICOLON = Vrab03;} else {Input->MAIN_SEMICOLON = 0ui8;}
   if(Ikey02.OemQuotes)       {Vrab01 = true; if((++Input->MAIN_QUOTES) == Vrab02) Input->MAIN_QUOTES = Vrab03;} else {Input->MAIN_QUOTES = 0ui8;}
   if(Ikey02.OemQuestion)     {Vrab01 = true; if((++Input->MAIN_QUESTION) == Vrab02) Input->MAIN_QUESTION = Vrab03;} else {Input->MAIN_QUESTION = 0ui8;}
   if(Ikey02.OemPeriod)       {Vrab01 = true; if((++Input->MAIN_PERIOD) == Vrab02) Input->MAIN_PERIOD = Vrab03;} else {Input->MAIN_PERIOD = 0ui8;}
   if(Ikey02.OemComma)        {Vrab01 = true; if((++Input->MAIN_COMMA) == Vrab02) Input->MAIN_COMMA = Vrab03;} else {Input->MAIN_COMMA = 0ui8;}
   if(Ikey02.Space)           {Vrab01 = true; if((++Input->MAIN_SPACE) == Vrab02) Input->MAIN_SPACE = Vrab03;} else {Input->MAIN_SPACE = 0ui8;}
   if(Ikey02.Escape){Vrab01 = true; if((++Input->CONS_ESC) == Vrab02) Input->CONS_ESC = Vrab03;} else {Input->CONS_ESC = 0ui8;}
   if(Ikey02.F1)    {Vrab01 = true; if((++Input->CONS_F1) == Vrab02) Input->CONS_F1 = Vrab03;} else {Input->CONS_F1 = 0ui8;}
   if(Ikey02.F2)    {Vrab01 = true; if((++Input->CONS_F2) == Vrab02) Input->CONS_F2 = Vrab03;} else {Input->CONS_F2 = 0ui8;}
   if(Ikey02.F3)    {Vrab01 = true; if((++Input->CONS_F3) == Vrab02) Input->CONS_F3 = Vrab03;} else {Input->CONS_F3 = 0ui8;}
   if(Ikey02.F4)    {Vrab01 = true; if((++Input->CONS_F4) == Vrab02) Input->CONS_F4 = Vrab03;} else {Input->CONS_F4 = 0ui8;}
   if(Ikey02.F5)    {Vrab01 = true; if((++Input->CONS_F5) == Vrab02) Input->CONS_F5 = Vrab03;} else {Input->CONS_F5 = 0ui8;}
   if(Ikey02.F6)    {Vrab01 = true; if((++Input->CONS_F6) == Vrab02) Input->CONS_F6 = Vrab03;} else {Input->CONS_F6 = 0ui8;}
   if(Ikey02.F7)    {Vrab01 = true; if((++Input->CONS_F7) == Vrab02) Input->CONS_F7 = Vrab03;} else {Input->CONS_F7 = 0ui8;}
   if(Ikey02.F8)    {Vrab01 = true; if((++Input->CONS_F8) == Vrab02) Input->CONS_F8 = Vrab03;} else {Input->CONS_F8 = 0ui8;}
   if(Ikey02.F9)    {Vrab01 = true; if((++Input->CONS_F9) == Vrab02) Input->CONS_F9 = Vrab03;} else {Input->CONS_F9 = 0ui8;}
   if(Ikey02.F10)   {Vrab01 = true; if((++Input->CONS_F10) == Vrab02) Input->CONS_F10 = Vrab03;} else {Input->CONS_F10 = 0ui8;}
   if(Ikey02.F11)   {Vrab01 = true; if((++Input->CONS_F11) == Vrab02) Input->CONS_F11 = Vrab03;} else {Input->CONS_F11 = 0ui8;}
   if(Ikey02.F12)   {Vrab01 = true; if((++Input->CONS_F12) == Vrab02) Input->CONS_F12 = Vrab03;} else {Input->CONS_F12 = 0ui8;}
   if(Ikey02.PrintScreen) {Vrab01 = true; if((++Input->CONS_PRTSC) == Vrab02) Input->CONS_PRTSC = Vrab03;} else {Input->CONS_PRTSC = 0ui8;}
   if(Ikey02.Delete)      {Vrab01 = true; if((++Input->CONS_DELETE) == Vrab02) Input->CONS_DELETE = Vrab03;} else {Input->CONS_DELETE = 0ui8;}
   if(Ikey02.Back)        {Vrab01 = true; if((++Input->CONS_BACK) == Vrab02) Input->CONS_BACK = Vrab03;} else {Input->CONS_BACK = 0ui8;}
   if(Ikey02.Tab)         {Vrab01 = true; if((++Input->CONS_TAB) == Vrab02) Input->CONS_TAB = Vrab03;} else {Input->CONS_TAB = 0ui8;}
   if(Ikey02.CapsLock)    {Vrab01 = true; if((++Input->CONS_CAPS) == Vrab02) Input->CONS_CAPS = Vrab03;} else {Input->CONS_CAPS = 0ui8;}
   if(Ikey02.Enter)       {Vrab01 = true; if((++Input->CONS_ENTER) == Vrab02) Input->CONS_ENTER = Vrab03;} else {Input->CONS_ENTER = 0ui8;}
   if(Ikey02.LeftShift)   {Vrab01 = true; if((++Input->CONS_LSHIFT) == Vrab02) Input->CONS_LSHIFT = Vrab03;} else {Input->CONS_LSHIFT = 0ui8;}
   if(Ikey02.RightShift)  {Vrab01 = true; if((++Input->CONS_RSHIFT) == Vrab02) Input->CONS_RSHIFT = Vrab03;} else {Input->CONS_RSHIFT = 0ui8;}
   if(Ikey02.LeftAlt)     {Vrab01 = true; if((++Input->CONS_LALT) == Vrab02) Input->CONS_LALT = Vrab03;} else {Input->CONS_LALT = 0ui8;}
   if(Ikey02.RightAlt)    {Vrab01 = true; if((++Input->CONS_RALT) == Vrab02) Input->CONS_RALT = Vrab03;} else {Input->CONS_RALT = 0ui8;}
   if(Ikey02.LeftControl) {Vrab01 = true; if((++Input->CONS_LCTRL) == Vrab02) Input->CONS_LCTRL = Vrab03;} else {Input->CONS_LCTRL = 0ui8;}
   if(Ikey02.RightControl){Vrab01 = true; if((++Input->CONS_RCTRL) == Vrab02) Input->CONS_RCTRL = Vrab03;} else {Input->CONS_RCTRL = 0ui8;}
   if(Ikey02.Up)   {Vrab01 = true; if((++Input->CONS_UP) == Vrab02) Input->CONS_UP = Vrab03;} else {Input->CONS_UP = 0ui8;}
   if(Ikey02.Left) {Vrab01 = true; if((++Input->CONS_LEFT) == Vrab02) Input->CONS_LEFT = Vrab03;} else {Input->CONS_LEFT = 0ui8;}
   if(Ikey02.Down) {Vrab01 = true; if((++Input->CONS_DOWN) == Vrab02) Input->CONS_DOWN = Vrab03;} else {Input->CONS_DOWN = 0ui8;}
   if(Ikey02.Right){Vrab01 = true; if((++Input->CONS_RIGHT) == Vrab02) Input->CONS_RIGHT = Vrab03;} else {Input->CONS_RIGHT = 0ui8;}
   if(Ikey02.NumPad0){Vrab01 = true; if((++Input->NUMS_0) == Vrab02) Input->NUMS_0 = Vrab03;} else {Input->NUMS_0 = 0ui8;}
   if(Ikey02.NumPad1){Vrab01 = true; if((++Input->NUMS_1) == Vrab02) Input->NUMS_1 = Vrab03;} else {Input->NUMS_1 = 0ui8;}
   if(Ikey02.NumPad2){Vrab01 = true; if((++Input->NUMS_2) == Vrab02) Input->NUMS_2 = Vrab03;} else {Input->NUMS_2 = 0ui8;}
   if(Ikey02.NumPad3){Vrab01 = true; if((++Input->NUMS_3) == Vrab02) Input->NUMS_3 = Vrab03;} else {Input->NUMS_3 = 0ui8;}
   if(Ikey02.NumPad4){Vrab01 = true; if((++Input->NUMS_4) == Vrab02) Input->NUMS_4 = Vrab03;} else {Input->NUMS_4 = 0ui8;}
   if(Ikey02.NumPad5){Vrab01 = true; if((++Input->NUMS_5) == Vrab02) Input->NUMS_5 = Vrab03;} else {Input->NUMS_5 = 0ui8;}
   if(Ikey02.NumPad6){Vrab01 = true; if((++Input->NUMS_6) == Vrab02) Input->NUMS_6 = Vrab03;} else {Input->NUMS_6 = 0ui8;}
   if(Ikey02.NumPad7){Vrab01 = true; if((++Input->NUMS_7) == Vrab02) Input->NUMS_7 = Vrab03;} else {Input->NUMS_7 = 0ui8;}
   if(Ikey02.NumPad8){Vrab01 = true; if((++Input->NUMS_8) == Vrab02) Input->NUMS_8 = Vrab03;} else {Input->NUMS_8 = 0ui8;}
   if(Ikey02.NumPad9){Vrab01 = true; if((++Input->NUMS_9) == Vrab02) Input->NUMS_9 = Vrab03;} else {Input->NUMS_9 = 0ui8;}
   if(Ikey02.LeftWindows || Ikey02.RightWindows){Vrab01 = true; if((++Input->CONS_WINDOWS) == Vrab02) Input->CONS_WINDOWS = Vrab03;} else {Input->CONS_WINDOWS = 0ui8;}
   
   Input->RESH_CAPS = (GetKeyState(VK_CAPITAL) & 0x0001);

   auto Imou02 = Imou01->GetState();
   Input->MOUS_X = L_Rounding(rxint64(Imou02.x) / Vrab0014) - Vrab0007;
   Input->MOUS_Y = L_Rounding(rxint64(Imou02.y) / Vrab0015) - Vrab0008;
   if(Imou02.leftButton)    {Vrab01 = true; if((++Input->MOUS_Left) == Vrab02) Input->MOUS_Left = Vrab03; Input->MOUS_Left_Release = 0ui8;} else {Input->MOUS_Left = 0ui8;     if((++Input->MOUS_Left_Release) == Vrab02) Input->MOUS_Left_Release = Vrab03;}
   if(Imou02.middleButton)  {Vrab01 = true; if((++Input->MOUS_Mid) == Vrab02) Input->MOUS_Mid = Vrab03; Input->MOUS_Mid_Release = 0ui8;} else {Input->MOUS_Mid = 0ui8;         if((++Input->MOUS_Mid_Release) == Vrab02) Input->MOUS_Mid_Release = Vrab03;}
   if(Imou02.rightButton)   {Vrab01 = true; if((++Input->MOUS_Right) == Vrab02) Input->MOUS_Right = Vrab03; Input->MOUS_Right_Release = 0ui8;} else {Input->MOUS_Right = 0ui8; if((++Input->MOUS_Right_Release) == Vrab02) Input->MOUS_Right_Release = Vrab03;}
   if(Input->MOUS_Left == 1 || Input->MOUS_Left_Release > 1) {Input->MOUS_X_Left = Input->MOUS_X; Input->MOUS_Y_Left = Input->MOUS_Y;}
   if(Input->MOUS_Mid == 1 || Input->MOUS_Mid_Release > 1)  {Input->MOUS_X_Mid = Input->MOUS_X; Input->MOUS_Y_Mid = Input->MOUS_Y;}
   if(Input->MOUS_Right == 1 || Input->MOUS_Right_Release > 1){Input->MOUS_X_Right = Input->MOUS_X; Input->MOUS_Y_Right = Input->MOUS_Y;}
   Input->MOUS_SCROLL = Input->MOUS_SCROLL2 - Imou02.scrollWheelValue;
   Input->MOUS_SCROLL2 = Imou02.scrollWheelValue;

   auto Ipad02 = Ipad01->GetState(0);
			Input->PADS_ON = Ipad02.connected;
			if(Input->PADS_ON)
			{
			
			} else
			{
			
			}

   Input->RESH_ANY = Vrab01;
  }
  int0 M_EngineFrame(xint64 Vrab01, xint64 Vrab02, uint32 Vrab03, uint32 Vrab04, DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01) fastened
  {
   UNREFERENCED_PARAMETER(Vrab02); UNREFERENCED_PARAMETER(Vrab03);
   if(Vrab0002 == 0)
   {
    G_ToggleFullscreen();
	Input = std::make_unique < HEPTA_INPUT > ();
	Temp0001 = std::filesystem::current_path().string() + "\\";
	Vrab0032 = std::chrono::steady_clock::now().time_since_epoch().count();
	Vrab0033 = L_Exist(L_Directory("Database\\Game\\Enchanted")) ? 1 : 0;
   }

   Vrab0002 += 1; if(Vrab0002 == 0xFFFFFFFFFFFFFFFF) Vrab0002 = 0xFFFFFFFFFFFEBF;
   if(Vrab0003 != 1 && Vrab0003 != 2 && Vrab0003 != 4 && Vrab0003 != 8 && Vrab0003 != 16 && Vrab0003 != 32 && Vrab0003 != 64 && Vrab0003 != 128) Vrab0003 = 8;
   remains xint64 Varb01; Varb01 += Vrab01; if(Vrab0002 % ruint64(Vrab0003) != 0) return; Vrab0001 += Vrab0003; M_EngineInput(Ikey01, Ipad01, Imou01); Disp0001.clear();
   remains uint64 Varb02; Varb02 += 1;
   remains uint64 Varb03; if(Varb01 > 1.0){while(Varb01 > 1.0) Varb01 -= 1.0; Varb03 = Varb02; Varb02 = 0;}

   // Starting.
    if(Vrab0001 < 200){G_Set_Display(0, 0xFFFFFF, 0, 0, 0ui8, 255ui8, Vrab0005, Vrab0006); G_Load_Pic(L_Directory("Database\\Interface\\READ.PNG"));}
    {
     statics int64 Vrab05 = 1920 - Vrab0005, Vrab06 = 1080 - Vrab0006;
     if(Vrab0001 >= 200 && Vrab0001 < 4040)
     {
      G_Set_Display(2, G_Load_Pic(L_Directory("Database\\Interface\\READ.PNG")), -L_Rounding64(rxint64(Vrab05) / 2.0), -L_Rounding64(rxint64(Vrab06) / 2.0), 0ui8, 255ui8, -Vrab05, -Vrab06);
      if(Vrab0001 < 680){G_Set_Display(0, 0xFFFFFF, 0, 0, 0ui8, ruint8(255.0 * (rxint64(480 - (Vrab0001 - 200)) / 480.0)), Vrab0005, Vrab0006);} else {G_Load_Pic(L_Directory("Database\\Interface\\TITLE1.PNG")); G_Load_Pic(L_Directory("Database\\Interface\\TITLE2.PNG"));}
      if(Vrab0001 >= 3560){G_Set_Display(0, 0x0, 0, 0, 0ui8, ruint8(255.0 * (rxint64(Vrab0001 - 3560) / 480.0)), Vrab0005, Vrab0006);} else {if(L_Any()) Vrab0001 = 3560;}
      
     }
     if(Vrab0001 >= 4040 && Vrab0001 < 8600)
     {
      uint8 Vrab07 = 255;
      if(Vrab0001 < 4520) Vrab07 = ruint8(255.0 * (rxint64(Vrab0001 - 4040) / 480.0));
      if(Vrab0001 >= 5240) Vrab07 = ruint8(255.0 * (rxint64(480 - (Vrab0001 - 5240)) / 480.0));
      if(Vrab0001 >= 5720) Vrab07 = 0;
      G_Set_Display(2, G_Load_Pic(L_Directory("Database\\Interface\\TITLE1.PNG")), -L_Rounding64(rxint64(Vrab05) / 2.0), -L_Rounding64(rxint64(Vrab06) / 2.0), 0ui8, Vrab07, -Vrab05, -Vrab06);
      if(Vrab0001 >= 5000)
      {
       uint8 Vrab08 = 255; if(Vrab0001 < 5480) Vrab08 = ruint8(255.0 * (rxint64(Vrab0001 - 5000) / 480.0));
       G_Set_Display(2, G_Load_Pic(L_Directory("Database\\Interface\\TITLE2.PNG")), -L_Rounding64(rxint64(Vrab05) / 2.0), -L_Rounding64(rxint64(Vrab06) / 2.0), 0ui8, Vrab08, -Vrab05, -Vrab06);
      }
      if(Vrab0001 >= 8120){G_Set_Display(0, 0x0, 0, 0, 0ui8, ruint8(255.0 * (rxint64(Vrab0001 - 8120) / 480.0)), Vrab0005, Vrab0006);} else {if(L_Any()) Vrab0001 = 8120;}
     }
     if(Vrab0001 >= 8600){G_Unload_Pic(); G_Unload_Image();}
    }

   // LF2 : Enchanted 4th.
    if(Vrab0001 >= 8600)
    if(Vrab0033 == 1){Enchanted = std::make_unique < HEPTA_LF2_ENCHANTED > (); Vrab0033 = 2;}
	if(Vrab0033 == 2) EIDP_LF2Enchanted(Vrab04, Varb03);
   
   // Purging Offside Images.
    G_Set_Display(0, 0x0, -rint64(Vrab0007), -rint64(Vrab0008), 0ui8, 255ui8, Vrab0007, rint64(Vrab0008) + rint64(Vrab0006));
    G_Set_Display(0, 0x0, -rint64(Vrab0007), rint64(Vrab0006), 0ui8, 255ui8, rint64(Vrab0007) + rint64(Vrab0005), Vrab0008);
	G_Set_Display(0, 0x0, rint64(Vrab0005), 0, 0ui8, 255ui8, Vrab0007, rint64(Vrab0008) + rint64(Vrab0006));
    G_Set_Display(0, 0x0, 0, -rint64(Vrab0008), 0ui8, 255ui8, rint64(Vrab0007) + rint64(Vrab0005), Vrab0008);
  }

 // External-Included Dependencies Program's Main Functions
  int0 EIDP_LF2Enchanted(uint32 Vrab01, uint64 Vrab02) fastened
  {
   // Initialization
    if(Enchanted->Vrab001)
    {
     Enchanted->Vrab001 = false;
     Enchanted->Setting[0].Player.resize(2);
     Enchanted->Setting[0].Player[0].Name = "Mesujin"; Enchanted->Setting[0].Player[0].Name = "Kitty";
     Enchanted->Setting[0].Player[0].Type = 0;         Enchanted->Setting[0].Player[0].Type = 0;
     Enchanted->Setting[0].Player[0].Up   = 22;        Enchanted->Setting[0].Player[0].Up   = 15;
     Enchanted->Setting[0].Player[0].Left = 46;        Enchanted->Setting[0].Player[0].Left = 14;
     Enchanted->Setting[0].Player[0].Down = 47;        Enchanted->Setting[0].Player[0].Down = 29;
     Enchanted->Setting[0].Player[0].Right = 45;       Enchanted->Setting[0].Player[0].Right = 16;
     Enchanted->Setting[0].Player[0].Attack = 23;      Enchanted->Setting[0].Player[0].Attack = 11;
     Enchanted->Setting[0].Player[0].Defend = 44;      Enchanted->Setting[0].Player[0].Defend = 30;
     Enchanted->Setting[0].Player[0].Jump   = 43;      Enchanted->Setting[0].Player[0].Jump   = 28;
     Enchanted->Setting[0].Player[0].Command = 21;     Enchanted->Setting[0].Player[0].Command = 33;
     Enchanted->Setting_Load(); Enchanted->Setting_Save();

     // Background(s) Load.
     {
      statics string Temp01 = L_Directory(Enchanted->Setting[0].Address_Interface), Temp02 = ".BMP", Temp03 = ".JPG";
      int1 Vrab03 = true; insize Vrab04 = 0;
      while(Vrab03)
      {
       Vrab04 += 1;
       Enchanted->Vect002.push_back(G_Load_Pic(Temp01 + "BACK" + std::to_string(Vrab04) + Temp02, 0ui32, 0ui32, ruint32(-1), 550));
       Enchanted->Vect003.push_back(false); Vrab03 = Enchanted->Vect002[Vrab04 - 1] != rinsize(-1);
       if(!Vrab03)
       {
        Enchanted->Vect002[Vrab04 - 1] = G_Load_Pic(Temp01 + "BACK" + std::to_string(Vrab04) + Temp03, 0ui32, 0ui32, ruint32(-1), 550);
        Enchanted->Vect003[Vrab04 - 1] = true; Vrab03 = Enchanted->Vect002[Vrab04 - 1] != rinsize(-1);
       }
      }
      Enchanted->Vect002.pop_back(); Enchanted->Vect003.pop_back();
  
      // First Random Background.
      if(Enchanted->Vect002.size() > 0)
      {
       statics insize Vrab05 = rinsize(L_Random(Enchanted->Vect002.size() - 1));
       Enchanted->Vrab002 = Enchanted->Vect002[Vrab05];
       Enchanted->Vrab003 = Enchanted->Vect003[Vrab05];
      }
     }

     // Interface Load.
     {
    
     }

     // Sound Load.
     {
     
     }
    }

   // Applying Setting
    {
    
    }

   G_Set_Display();
  }
#endif










#ifndef _HEPTA_PRAGMA_ENGINE_H
 #define _HEPTA_PRAGMA_ENGINE_H
 // Commands
  #include <random>
  #include <chrono>
  #include <filesystem>
  #include <math.h>
  #include "platform.h"
  
  // AngelScript
   #include "AngelScript/angelscript.h"
   #include "AngelScript/scriptarray.h"
   #include "AngelScript/scriptmath.h"
   #include "AngelScript/scriptmathcomplex.h"
   #include "AngelScript/scriptstdstring.h"
  //-//
 //-//
 // Earlier Function Declaration
  int0   LF2_Enchanted(uint32, uint64) fastened;
  int0   L_Robust(string&) fastened;
  int1   L_Exist(statics string&) fastened;
  uint8  L_Input(uint8) fastened;
  int32  L_Numbering(string) fastened;
  int32  L_Positive(int32) fastened;
  int32  L_Rounding(xint64) fastened;
  int64  L_Rounding64(xint64) fastened;
  uint64 L_Random(uint64) fastened;
  uint64 L_Interprocessing(statics string&) fastened;
  xint64 L_Positive64(xint64) fastened;
  xint64 L_Doubling(string) fastened;
  xint64 L_Distance(xint64, xint64, xint64, xint64) fastened;
  string L_Number(insize) fastened;
  string L_Lowercase(string) fastened;
  string L_Spacemaker(string) fastened;
  string L_Execute(statics string) fastened;
  string L_Rename(string, string) fastened;
  string L_Focus(statics string) fastened;
  string L_Revoke(string, uint8, uint8) fastened;
 //-//
 // Memory / Variables
  // Basic
   uint64 Varb0001 = 0;               // App Runtime
   uint32 Varb0002 = 800;             // Display W
   uint32 Varb0003 = 450;             // Display H
   uint8  Varb0004 = 1;               // FPS Ratio
   int1   Varb0005 = true;            // Keep aspect ratio?
   int1   Varb0006 = true;            // Limit displayed resolution if window's resolution is higher than display's resolution?
   int1   Varb0007 = false;           // Update Display?
   uint32 Varb0008 = 0;               // X Display Offset
   uint32 Varb0009 = 0;               // Y Display Offset
   xint64 Varb0010 = 1;               // Mouse X Offset Ratio
   xint64 Varb0011 = 1;               // Mouse Y Offset Ratio
   xint32 Varb0012 = 0.1;             // Volume
   xint32 Varb0013 = 0;               // Sound Main Pan
   int1   Varb0014 = false;           // Fullscreen ?
   uint64 Varb0015 = 0;               // Random Seed
   int1   Varb0016 = false;           // Random Reset
   uint32 Varb0017 = 0;               // Window Size W
   uint32 Varb0018 = 0;               // Window Size H
   uint8  Varb0019 = 52;              // Common ESC   - Keyboard
   uint8  Varb0020 = 70;              // Common Enter - Keyboard
   uint8  Varb0021 = 48;              // Common Up    - Keyboard
   uint8  Varb0022 = 49;              // Common Left  - Keyboard
   uint8  Varb0023 = 50;              // Common Down  - Keyboard
   uint8  Varb0024 = 51;              // Common Right - Keyboard
   int1   Varb0025 = false;           // LF2 : Enchanted 4th Available?
   int1   Varb0026 = false;           // LF2 : Enchanted 4th?
   int1   Varb0027 = false;           // Exit?
  //-//
  // Complex
   // Structures / Classes
    struct HEPTA_INPUTS
    {
     uint8 MAIN_1; uint8 MAIN_2; uint8 MAIN_3; uint8 MAIN_4; uint8 MAIN_5; uint8 MAIN_6; uint8 MAIN_7; uint8 MAIN_8; uint8 MAIN_9; uint8 MAIN_0;
     uint8 MAIN_A; uint8 MAIN_B; uint8 MAIN_C; uint8 MAIN_D; uint8 MAIN_E; uint8 MAIN_F; uint8 MAIN_G; uint8 MAIN_H; uint8 MAIN_I; uint8 MAIN_J; uint8 MAIN_K; uint8 MAIN_L; uint8 MAIN_M; uint8 MAIN_N; uint8 MAIN_O; uint8 MAIN_P; uint8 MAIN_Q; uint8 MAIN_R; uint8 MAIN_S; uint8 MAIN_T; uint8 MAIN_U; uint8 MAIN_V; uint8 MAIN_W; uint8 MAIN_X; uint8 MAIN_Y; uint8 MAIN_Z;
     uint8 MAIN_TILDE;        // ` ~
     uint8 MAIN_MINUS;        // - _
     uint8 MAIN_PLUS;         // = +
     uint8 MAIN_OPENBRACKED;  // [ {
     uint8 MAIN_CLOSEBRACKED; // ] }
     uint8 MAIN_PIPE;         // \ |
     uint8 MAIN_SEMICOLON;    // ; :
     uint8 MAIN_QUOTES;       // ' "
     uint8 MAIN_QUESTION;     // / ?
     uint8 MAIN_PERIOD;       // . >
     uint8 MAIN_COMMA;        // , <
     uint8 MAIN_SPACE;        // 
     uint8 CONS_ESC;
     uint8 CONS_F1; uint8 CONS_F2; uint8 CONS_F3; uint8 CONS_F4; uint8 CONS_F5; uint8 CONS_F6; uint8 CONS_F7; uint8 CONS_F8; uint8 CONS_F9; uint8 CONS_F10; uint8 CONS_F11; uint8 CONS_F12;
     uint8 CONS_PRTSC;
     uint8 CONS_DELETE;
     uint8 CONS_BACK;
     uint8 CONS_TAB;
     uint8 CONS_CAPS;
     uint8 CONS_ENTER;
     uint8 CONS_LSHIFT; uint8 CONS_RSHIFT;
     uint8 CONS_LALT; uint8 CONS_RALT;
     uint8 CONS_LCTRL; uint8 CONS_RCTRL;
     uint8 CONS_UP; uint8 CONS_LEFT; uint8 CONS_DOWN; uint8 CONS_RIGHT;
     uint8 CONS_WINDOWS;
     uint8 NUMS_NUMLOCK;
     uint8 NUMS_MULTIPLE;
     uint8 NUMS_DEVIDE;
     uint8 NUMS_ADD;
     uint8 NUMS_SUBTRACT;
     uint8 NUMS_0; uint8 NUMS_1; uint8 NUMS_2; uint8 NUMS_3; uint8 NUMS_4; uint8 NUMS_5; uint8 NUMS_6; uint8 NUMS_7; uint8 NUMS_8; uint8 NUMS_9;
     uint8 NUMS_POINT;

     int32 MOUS_X;
     int32 MOUS_Y;
     uint8 MOUS_Left;
     uint8 MOUS_Right;
     uint8 MOUS_Mid;
     uint8 MOUS_Left_Release;
     uint8 MOUS_Right_Release;
     uint8 MOUS_Mid_Release;
     int32 MOUS_X_Left;
     int32 MOUS_Y_Left;
     int32 MOUS_X_Right;
     int32 MOUS_Y_Right;
     int32 MOUS_X_Mid;
     int32 MOUS_Y_Mid;
     int32 MOUS_SCROLL;
     int32 MOUS_SCROLL2;

     int1  RESH_CAPS;
    };
    
    struct HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_OBJECT_INFO
    {
     int64 X = 0, Y = 0; uint8 Color = 0; string Name;
     xint64 HP = 0.0, DHP = 0.0, MHP = 0.0, MP = 0.0, MMP = 0.0;
     uint8 Integrate = 0; uint8 Player = 0; insize Icon1 = rinsize(-1), Icon2 = rinsize(-1);
    };
    struct HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_OBJECT
    {
     int1 Facing = false; uint8 Flip = 0;
     uint8 Trans = 255;
     int64 X = 0, Y = 0, Z = 0, W = 0, H = 0;
     uint32 Rotate = 0;
     insize Pic = rinsize(-1); insize Pic_M = rinsize(-1);
     int1 Character = false;
     unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_OBJECT_INFO > Info;
    };
    struct HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT
    {
     int1 Facing = false;
     uint8 Type = 0;
     uint8 Trans = 255;
     int64 X = 0, Y = 0, W = 0, H = 0;
     uint32 Rotate = 0;
     insize Pic = rinsize(-1);
    };
    struct HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW
    {
     insize Sound = 0;
     xint64 X = 0; xint64 Y = 0; xint64 Z = 0; insize D = 0;
    };
    struct HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW
    {
     uint8 Type = 0; int1 Last = false;
     insize Pic = rinsize(-1);
     int64 X = 0; int64 Y = 0;
    };
    struct HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW
    {
     int1 Type = false;
     unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_OBJECT > Object;
     unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > Effect;
    };

    struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_STAGE_PHASE_ENTITY
    {
     insize id = 0;
     uint8 Class = 0;
     int32 x = 0, y = 0;
     int32 hp = 500, act = 0, times = 0, reserve = 0, join = 0, join_reserve = 0;
     xint64 ratio = 1;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_STAGE_PHASE
    {
     int64 bound = 0;
     insize music_Index = rinsize(-1);
     insize when_clear_goto_phase = rinsize(-1);
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_STAGE_PHASE_ENTITY > Entity;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_STAGE
    {
     insize id = 0;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_STAGE_PHASE > Phase;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE
    {
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_STAGE > Stage;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER 
    {
     int32 transparency = 0, width = 0, height = 0, x = 0, y = 0, loop = 0, cc = 0, c1 = 0, c2 = 0, rect32 = 0;
     insize image_Index = rinsize(-1);
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND
    {
     string name; insize id = 0; int32 Shift = 0;
     int32 x = 0;
     uint32 width = 800, zboundary[2]{}, perspective[2]{}, shadowsize[2]{};
     insize shadow_Index = 0;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER > Layer;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT
    {
     xint64 X = 0.0, Y = 0.0, Z = 0.0; int1 Exist = true;
     insize Pic = 0; int1 Sprite = false; int1 Loop = false; int1 Screen = false;
     std::vector < insize > Pics;
    };
				struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_PPOINT
				{
				 int32 pic, x, y, rotate, w, h, trans;
				};
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_BPOINT
    {
     int32 x, y;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_CPOINT
    {
     int32 kind, x, y, vaction, aaction, daction, jaction, taction, throwvx, throwvy, throwvz, throwinjury, dircontrol, hurtable, decrease, cover, injury, fronthurtact, backhurtact;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_WPOINT
    {
     int32 kind, x, y, dvx, dvy, dvz, weaponact, attacking, cover;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_OPOINT
    {
     int32 kind, x, y, dvx, dvy, oid, action, facing;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT
    {
     int32 kind, x, y, w, h, zwidth, dvx, dvy, fall, arest, vrest, respond, effect, bdefend, injury, catchingact[2], caughtact[2];
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_HPOINT
    {
     int32 kind, x, y, w, h;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME
    {
     int1 Exist = false;
     insize pic = rinsize(-1);
     int32 state = 0, wait = 0, next = 0, dvx = 0, dvy = 0, dvz = 0, centerx = 0, centery = 0, hit_a = 0, hit_d = 0, hit_j = 0, hit_Fa = 0, hit_Fj = 0, hit_Da = 0, hit_Dj = 0, hit_Ua = 0, hit_Uj = 0, hit_ja = 0, mp = 0;
     insize sound_Index = rinsize(-1);
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_PPOINT > ppoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_BPOINT > bpoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_CPOINT > cpoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_WPOINT > wpoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_OPOINT > opoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT > itr;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_HPOINT > bdy;
     
     // Runtime Data
     int32 bdy_X = 0, bdy_Y = 0, bdy_W = 0, bdy_H = 0;
     int32 itr_X = 0, itr_Y = 0, itr_W = 0, itr_H = 0, itr_Z = 0;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_STRENGTH
    {
     int32 zwidth, dvx, dvy, fall, arest, vrest, respond, effect, bdefend, injury;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_PIC
    {
     insize Picture_Index = rinsize(-1);
     insize Picture_Mirror_Index = rinsize(-1);
     string address;
     uint32 w = 1, h = 1, col = 1, row = 1;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT
    {
     insize id = rinsize(-1);
     uint8 type = 0;
     string name;
     insize head_Index = rinsize(-1);
     insize small_Index = rinsize(-1);
     std::vector < insize > file_Index;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_PIC > file;
     uint32 walking_frame_rate;
     uint32 running_frame_rate;
     xint64 walking_speed;
     xint64 walking_speedz;
     xint64 running_speed;
     xint64 running_speedz;
     xint64 heavy_walking_speed;
     xint64 heavy_walking_speedz;
     xint64 heavy_running_speed;
     xint64 heavy_running_speedz;
     xint64 jump_height;
     xint64 jump_distance;
     xint64 jump_distancez;
     xint64 dash_height;
     xint64 dash_distance;
     xint64 dash_distancez;
     xint64 rowing_height;
     xint64 rowing_distance;
     int32 weapon_hp, weapon_drop_hurt;
     insize weapon_hit_sound_Index = rinsize(-1), weapon_drop_sound_Index = rinsize(-1), weapon_broken_sound_Index = rinsize(-1);
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_STRENGTH > Strength;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME* > Frame;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT
    {
     int1 Exist = true; int1 Lock = false; int1 Facing = false; int1 Landing = false; int1 Heavy_Hold = false;
     insize Frame = 0, Frame2 = 0, Frame3 = 0, Frame4 = 0, Team = 0, Pic_Offset = 0;
     xint64 X = 0, Y = 0, Z = 0; insize D = rinsize(-1);
     xint64 X_Vel = 0, Y_Vel = 0, Z_Vel = 0; int8 Vel = 0;
     xint64 X_Accel = 0, Y_Accel = 0, Z_Accel = 0; int8 Shake = 0;
     xint64 Scale = 1.0;
     uint32 Walk_Animation = 0, Walk_Phase = 0, Run_Animation = 0, Run_Phase = 0, Wait = 0, Lying = 0;

     insize Rotation = 0;

     insize Target = rinsize(-1), Clone = rinsize(-1), Held = rinsize(-1), Hold = rinsize(-1), Catch = rinsize(-1), Caught = rinsize(-1);

     uint8  Player = 0;
     insize Index = 0;
     string Name;
     xint64 MHP = 0, DHP = 0, HP = 0, SP = 0, MMP = 0, MP = 0;
     int16  Counter = 500;
     int32  Throw = 0;
     int32  Blink = 0;
     int32  Fall = 0;
     int32  Heal = 0; uint16 Heal_Ratio = 1000;
     uint16 Arest = 0;
     std::vector < uint16 > Vrest;
     int1   Float = false;
     int1   Super_Attack = false;
     uint8  Affected = 0;
     uint16 Catch_Time = 0;
     insize Attacking = 0;
     
     insize Last_Hit = rinsize(-1);
     uint16 Damage_Taken = 1000;
     uint16 Damage_Dealt = 1000;

     std::vector < insize > Owners;
     xint64 Summary_Damage_Dealt = 0;
     xint64 Summary_Damage_Taken = 0;
     xint64 Summary_HP_Heal = 0;
     uint64 Summary_HP_Heal_Percent = 0;
     uint64 Summary_Pick = 0;
     
     
     int1  In_A = false, In_D = false, In_J = false, In_C = false, In_Up = false, In_Left = false, In_Down = false, In_Right = false;
     uint8 Input_A = 0, Input_D = 0, Input_J = 0, Input_C = 0, Input_Up = 0, Input_Left = 0, Input_Down = 0, Input_Right = 0;
     uint8 Press_A = 0, Press_D = 0, Press_J = 0, Press_RR = 0, Press_LL = 0;
     uint8 Cast_A = 0, Cast_D = 0, Cast_J = 0, Cast_DRA = 0, Cast_DLA = 0, Cast_DRJ = 0, Cast_DLJ = 0, Cast_DDA = 0, Cast_DDJ = 0, Cast_DUA = 0, Cast_DUJ = 0, Cast_DJA = 0;
     HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT *Data;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT* > Trans_Address; uint8 Trans = 0;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT* > Return_Address; uint8 Return = 0;

					int1 Stamp = false;
					uint64 Stamp_Time = 0;
					std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Stamp_Data;
					std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT > Stamp_Effect;
					std::vector < std::vector < uint32 > > Stamp_Animation;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1
    {
     HEPTA_LF2_ENCHANTED_ENGINE1()
     {
      Frames.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME >());
      std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out); if(File01.is_open()){File01 << "[] INFO - Engine1 : Origin - Starting.\n"; File01.close();}
     }

     // AngelScript

     uint32 MaximumFrame = rinsize(-1);
     uint32 MaximumObject = rinsize(-1);
     int32  MaximumMP = 500;

     uint32 ModuleID = 0;

     uint32 ElapsedTime = 0;
     int32  Background_width = 0;
     int32  Background_zwidth1 = 0;
     int32  Background_zwidth2 = 0;
     int32  Stage = 0;
     int1   Stage_clear = 0;
     int32  Stage_bound = 0;
     int32  Phase = 0;
     int32  Phase_Count = 0;
     int32  User = -1;

     int1   L_Gets_int1(uint64 Vrab01) fastened {return *(int1*)Vrab01;}
     int8   L_Gets_int8(uint64 Vrab01) fastened {return *(int8*)Vrab01;}
     int16  L_Gets_int16(uint64 Vrab01) fastened {return *(int16*)Vrab01;}
     int32  L_Gets_int32(uint64 Vrab01) fastened {return *(int32*)Vrab01;}
     int64  L_Gets_int64(uint64 Vrab01) fastened {return *(int64*)Vrab01;}
     uint8  L_Gets_uint8(uint64 Vrab01) fastened {return *(uint8*)Vrab01;}
     uint16 L_Gets_uint16(uint64 Vrab01) fastened {return *(uint16*)Vrab01;}
     uint32 L_Gets_uint32(uint64 Vrab01) fastened {return *(uint32*)Vrab01;}
     uint64 L_Gets_uint64(uint64 Vrab01) fastened {return *(uint64*)Vrab01;}
     xint32 L_Gets_xint32(uint64 Vrab01) fastened {return *(xint32*)Vrab01;}
     xint64 L_Gets_xint64(uint64 Vrab01) fastened {return *(xint64*)Vrab01;}
     int1   L_Gets_int1S(const string &Temp01) fastened {return L_Gets_int1(L_Interprocessing(Temp01));}
     int8   L_Gets_int8S(const string &Temp01) fastened {return L_Gets_int8(L_Interprocessing(Temp01));}
     int16  L_Gets_int16S(const string &Temp01) fastened {return L_Gets_int16(L_Interprocessing(Temp01));}
     int32  L_Gets_int32S(const string &Temp01) fastened {return L_Gets_int32(L_Interprocessing(Temp01));}
     int64  L_Gets_int64S(const string &Temp01) fastened {return L_Gets_int64(L_Interprocessing(Temp01));}
     uint8  L_Gets_uint8S(const string &Temp01) fastened {return L_Gets_uint8(L_Interprocessing(Temp01));}
     uint16 L_Gets_uint16S(const string &Temp01) fastened {return L_Gets_uint16(L_Interprocessing(Temp01));}
     uint32 L_Gets_uint32S(const string &Temp01) fastened {return L_Gets_uint32(L_Interprocessing(Temp01));}
     uint64 L_Gets_uint64S(const string &Temp01) fastened {return L_Gets_uint64(L_Interprocessing(Temp01));}
     xint32 L_Gets_xint32S(const string &Temp01) fastened {return L_Gets_xint32(L_Interprocessing(Temp01));}
     xint64 L_Gets_xint64S(const string &Temp01) fastened {return L_Gets_xint64(L_Interprocessing(Temp01));}

     int0   L_Sets_int1(const uint64 Vrab01, int1 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 1, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){int1 &Vrab03 = *((int1*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 1, Dwrd01, &Dwrd01);}}
     int0   L_Sets_int8(const uint64 Vrab01, int8 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 1, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){int8 &Vrab03 = *((int8*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 1, Dwrd01, &Dwrd01);}}
     int0   L_Sets_int16(const uint64 Vrab01, int16 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 2, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){int16 &Vrab03 = *((int16*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 2, Dwrd01, &Dwrd01);}}
     int0   L_Sets_int32(const uint64 Vrab01, int32 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 4, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){int32 &Vrab03 = *((int32*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 4, Dwrd01, &Dwrd01);}}
     int0   L_Sets_int64(const uint64 Vrab01, int64 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 8, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){int64 &Vrab03 = *((int64*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 8, Dwrd01, &Dwrd01);}}
     int0   L_Sets_uint8(const uint64 Vrab01, uint8 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 1, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){uint8 &Vrab03 = *((uint8*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 1, Dwrd01, &Dwrd01);}}
     int0   L_Sets_uint16(const uint64 Vrab01, uint16 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 2, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){uint16 &Vrab03 = *((uint16*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 2, Dwrd01, &Dwrd01);}}
     int0   L_Sets_uint32(const uint64 Vrab01, uint32 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 4, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){uint32 &Vrab03 = *((uint32*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 4, Dwrd01, &Dwrd01);}}
     int0   L_Sets_uint64(const uint64 Vrab01, uint64 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 8, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){uint64 &Vrab03 = *((uint64*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 8, Dwrd01, &Dwrd01);}}
     int0   L_Sets_xint32(const uint64 Vrab01, xint32 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 4, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){xint32 &Vrab03 = *((xint32*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 4, Dwrd01, &Dwrd01);}}
     int0   L_Sets_xint64(const uint64 Vrab01, xint64 Vrab02) fastened {DWORD Dwrd01; if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 8, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0){xint64 &Vrab03 = *((xint64*)Vrab01); Vrab03 = Vrab02; VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), 8, Dwrd01, &Dwrd01);}}
     int0   L_Sets_int1S(const string &Temp01, int1 Vrab01) fastened {L_Sets_int1(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_int8S(const string &Temp01, int8 Vrab01) fastened {L_Sets_int8(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_int16S(const string &Temp01, int16 Vrab01) fastened {L_Sets_int16(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_int32S(const string &Temp01, int32 Vrab01) fastened {L_Sets_int32(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_int64S(const string &Temp01, int64 Vrab01) fastened {L_Sets_int64(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_uint8S(const string &Temp01, uint8 Vrab01) fastened {L_Sets_uint8(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_uint16S(const string &Temp01, uint16 Vrab01) fastened {L_Sets_uint16(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_uint32S(const string &Temp01, uint32 Vrab01) fastened {L_Sets_uint32(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_uint64S(const string &Temp01, uint64 Vrab01) fastened {L_Sets_uint64(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_xint32S(const string &Temp01, xint32 Vrab01) fastened {L_Sets_xint32(L_Interprocessing(Temp01), Vrab01);}
     int0   L_Sets_xint64S(const string &Temp01, xint64 Vrab01) fastened {L_Sets_xint64(L_Interprocessing(Temp01), Vrab01);}

     int0   L_Sets(uint64 Vrab01, const string &Temp01) fastened 
   {
    const string Temp02 = L_Lowercase(Temp01);
    const uint32 Vrab02 = Temp02.size(); uint32 Vrab03 = 0; int1 Vrab04 = true;
    while(Vrab03 != Vrab02)
    switch(Temp02.at(Vrab03))
    {
     case '\n': Vrab04 = true; case ' ': case ',': case 13: Vrab03 += 1; break; case '-': if(!Vrab04){Vrab03 += 1; break;}
     default:
      {
       string Temp03 = "";
       while(Vrab03 != Vrab02)
       {
        const int8 Vrab05 = Temp02.at(Vrab03); switch(Vrab05)
        {
         case '\n': Vrab04 = true; case ' ': case ',': case 13: break; case '-': if(!Vrab04) break;
         default:
          Temp03.push_back(Vrab05);
          Vrab03 += 1;
         continue;
        }
        break;
       }

       int1 Vrab05 = false; std::vector < uint8 > Vect01;
       if(Temp03 != "")
       {
        if(Temp03 == "-") Vrab04 = false;

        if(Vrab04)
        {
         const uint64 Vrab06 = L_Interprocessing(Temp03);
         if(Vrab06 != 0)
         {Vrab04 = false; Vrab01 = Vrab06; goto Labl01;}
        }

        const uint32 Vrab06 = Temp03.size(); uint32 Vrab07 = 0; Vrab05 = true;
        while(Vrab07 != Vrab06)
        {
         string Temp04 = "";
         const int8 Vrab08 = Temp03.at(Vrab07); switch(Vrab08){case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': break; default: Vrab05 = false; goto Labl01;}
         Temp04.push_back(Vrab08);
         Vrab07 += 1; if(Vrab07 == Vrab06)
         {
          Temp04.push_back('0');
         } else
         {
          const int8 Vrab09 = Temp03.at(Vrab07); switch(Vrab09){case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': break; default: Vrab05 = false; goto Labl01;}
          Temp04.push_back(Vrab09);
          Vrab07 += 1;
         }
         Vect01.push_back(ruint8(L_Interprocessing(Temp04)));
        }
       }

       Labl01:
       if(Vrab05)
       {
        const uint32 Vrab08 = Vect01.size(); uint32 Vrab09 = 0; DWORD Dwrd01;
        if(Vrab08 != 0) if(VirtualProtect(static_cast < LPVOID > ((uint64*)Vrab01), Vrab08, PAGE_EXECUTE_READWRITE, &Dwrd01) != 0)
        {
         while(Vrab09 != Vrab08)
         {
          uint8 &Vrab10 = *((uint8*)Vrab01); Vrab10 = Vect01[Vrab09]; Vrab09 += 1; Vrab01 += 1;
         }
         VirtualProtect(static_cast < LPVOID > ((uint64*)(Vrab01 - Vrab08)), Vrab08, Dwrd01, &Dwrd01);
        }
       }

       Vrab03 += 1; continue;
      }
     break;
    }
   }
     int0   L_SetsS(const string &Temp01, const string &Temp02) fastened {L_Sets(L_Interprocessing(Temp01), Temp02);}
  
     int0   L_Draw(uint32 Vrab01, uint32 Vrab02, uint32 Vrab03, uint32 Vrab04, uint8 Vrab05, uint8 Vrab06, uint8 Vrab07)
     {
      G_Set_Display(0, (Vrab07 + (Vrab06 << 8) + (Vrab05 << 16)), rint64(Vrab01), rint64(Vrab02), 0ui8, 255ui8, rint64(Vrab03), rint64(Vrab04));
     }

     int1   L_Copy(uint32 Vrab01, uint32 Vrab02, uint32 Vrab03) fastened {if(Vrab01 >= Objects.size()) return false; if(Vrab02 >= MaximumFrame || Vrab02 < 0 || Vrab03 >= MaximumFrame || Vrab03 < 0) return false; Objects[Vrab01].Frame[Vrab03] = Objects[Vrab01].Frame[Vrab02]; return true;}
     int1   L_Copys(uint32 Vrab01, uint32 Vrab02, uint32 Vrab03, uint32 Vrab04) fastened {statics insize Vrab05 = Objects.size(); if(Vrab01 >= Vrab05 || Vrab02 >= Vrab05) return false; if(Vrab03 >= MaximumFrame || Vrab03 < 0 || Vrab04 >= MaximumFrame || Vrab04 < 0) return false;  Objects[Vrab02].Frame[Vrab04] = Objects[Vrab01].Frame[Vrab03]; return true;}
     uint32 L_Address(int32 Vrab01) fastened {insize Vrab02 = Objects.size(); while(Vrab02 != 0){Vrab02 -= 1; if(Objects[Vrab02].id == rinsize(Vrab01)) return Vrab02;} return rinsize(-1);}
     int32  L_Random(int32 Vrab01)  fastened {return rint32(::L_Random(ruint64(Vrab01)));}
     insize L_Generate(int32 Vrab01, int32 Vrab02, int32 Vrab03, xint64 Vrab04, xint64 Vrab05, xint64 Vrab06, uint8 Vrab07) fastened
     {
      if(Vrab01 < 0 || Vrab01 >= rint32(MaximumObject)) return rinsize(-1);
      if(Object[Vrab01].Exist) return rinsize(-1);
      insize Vrab08 = Objects.size();
      while(Vrab08 != 0)
      {
       Vrab08 -= 1; if(Objects[Vrab08].id == rinsize(Vrab02)){Object[Vrab01].Data = &Objects[Vrab08]; break;}
       if(Vrab08 == 0) return rinsize(-1);
      }
      Object[Vrab01].Frame = rinsize(Vrab03);
      Object[Vrab01].X = Vrab04;
      Object[Vrab01].Y = Vrab05;
      Object[Vrab01].Z = Vrab06;
      Object[Vrab01].Facing = Vrab07 != 0;
     }
     int32  L_Aggring(int32 Vrab01) fastened {if(User == -1) return -1; if(Vrab01 < 0 || Vrab01 >= rint32(MaximumObject)) return -1; if(!Object[Vrab01].Exist) return -1; return (Object[Vrab01].Target = Vrab01);}
     int0   L_InputClear()          fastened {if(User == -1) return; Object[User].In_A = false; Object[User].In_D = false; Object[User].In_J = false; Object[User].In_C = false; Object[User].In_Up = false; Object[User].In_Left = false; Object[User].In_Down = false; Object[User].In_Right = false;}
     int0   L_InputUP()             fastened {if(User == -1) return; Object[User].In_Up = Object[User].Input_Up == 0;}
     int0   L_InputLEFT()           fastened {if(User == -1) return; Object[User].In_Left = Object[User].Input_Left == 0;}
     int0   L_InputDOWN()           fastened {if(User == -1) return; Object[User].In_Down = Object[User].Input_Down == 0;}
     int0   L_InputRIGHT()          fastened {if(User == -1) return; Object[User].In_Right = Object[User].Input_Right == 0;}
     int0   L_InputATTACK()         fastened {if(User == -1) return; Object[User].In_A = Object[User].Input_A == 0;}
     int0   L_InputDEFEND()         fastened {if(User == -1) return; Object[User].In_D = Object[User].Input_D == 0;}
     int0   L_InputJUMP()           fastened {if(User == -1) return; Object[User].In_J = Object[User].Input_J == 0;}
     int0   L_InputCOMMAND()        fastened {if(User == -1) return; Object[User].In_C = Object[User].Input_C == 0;}
     int0   L_InputUPH()            fastened {if(User == -1) return; Object[User].In_Up = true;}
     int0   L_InputLEFTH()          fastened {if(User == -1) return; Object[User].In_Left = true;}
     int0   L_InputDOWNH()          fastened {if(User == -1) return; Object[User].In_Down = true;}
     int0   L_InputRIGHTH()         fastened {if(User == -1) return; Object[User].In_Right = true;}
     int0   L_InputATTACKH()        fastened {if(User == -1) return; Object[User].In_A = true;}
     int0   L_InputDEFENDH()        fastened {if(User == -1) return; Object[User].In_D = true;}
     int0   L_InputJUMPH()          fastened {if(User == -1) return; Object[User].In_J = true;}
     int0   L_InputCOMMANDH()       fastened {if(User == -1) return; Object[User].In_C = true;}
     int0   L_InputDRA()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Right == 0 && Object[User].Input_A == 0){L_InputClear(); L_InputDEFEND(); L_InputRIGHT(); L_InputATTACK();} else {Object[User].In_D = false; Object[User].In_Right = false; Object[User].In_A = false;}}
     int0   L_InputDLA()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Left == 0 && Object[User].Input_A == 0) {L_InputClear(); L_InputDEFEND(); L_InputLEFT(); L_InputATTACK();} else  {Object[User].In_D = false; Object[User].In_Left = false; Object[User].In_A = false;}}
     int0   L_InputDUA()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Up == 0 && Object[User].Input_A == 0)   {L_InputClear(); L_InputDEFEND(); L_InputUP(); L_InputATTACK();} else    {Object[User].In_D = false; Object[User].In_Up = false; Object[User].In_A = false;}}
     int0   L_InputDDA()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Down == 0 && Object[User].Input_A == 0) {L_InputClear(); L_InputDEFEND(); L_InputDOWN(); L_InputATTACK();} else  {Object[User].In_D = false; Object[User].In_Down = false; Object[User].In_A = false;}}
     int0   L_InputDRJ()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Right == 0 && Object[User].Input_J == 0){L_InputClear(); L_InputDEFEND(); L_InputRIGHT(); L_InputJUMP();} else   {Object[User].In_D = false; Object[User].In_Right = false; Object[User].In_J = false;}}
     int0   L_InputDLJ()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Left == 0 && Object[User].Input_J == 0) {L_InputClear(); L_InputDEFEND(); L_InputLEFT(); L_InputJUMP();} else    {Object[User].In_D = false; Object[User].In_Left = false; Object[User].In_J = false;}}
     int0   L_InputDUJ()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Up == 0 && Object[User].Input_J == 0)   {L_InputClear(); L_InputDEFEND(); L_InputUP(); L_InputJUMP();} else      {Object[User].In_D = false; Object[User].In_Up = false; Object[User].In_J = false;}}
     int0   L_InputDDJ()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_Down == 0 && Object[User].Input_J == 0) {L_InputClear(); L_InputDEFEND(); L_InputDOWN(); L_InputJUMP();} else    {Object[User].In_D = false; Object[User].In_Down = false; Object[User].In_J = false;}}
     int0   L_InputDJA()            fastened {if(User == -1) return; if(Object[User].Input_D == 0 && Object[User].Input_J == 0 && Object[User].Input_A == 0)    {L_InputClear(); L_InputDEFEND(); L_InputJUMP(); L_InputATTACK();} else  {Object[User].In_D = false; Object[User].In_J = false; Object[User].In_A = false;}}

     int0   C_Clear() fastened
     {
      HANDLE Hand01 = GetStdHandle(STD_OUTPUT_HANDLE);
      if(Hand01 == INVALID_HANDLE_VALUE) return;
      const COORD Cord01 = {0, 0};
      DWORD Dwrd01, Dwrd02;
      CONSOLE_SCREEN_BUFFER_INFO Csbi01;
      if(!GetConsoleScreenBufferInfo(Hand01, &Csbi01)){return;}
      Dwrd02 = Csbi01.dwSize.X * Csbi01.dwSize.Y;
      if(!FillConsoleOutputCharacterA(Hand01, ' ', Dwrd02, Cord01, &Dwrd01)){return;}
      SetConsoleCursorPosition(Hand01, Cord01);
     }
     int0   C_PrintAddr(const int0 *Vrab01)    fastened {printf("%p", Vrab01);}
     int0   C_Print(const int1 Vrab01)         fastened {if(Vrab01){printf("true");} else {printf("false");}}
     int0   C_Print(const int8 Vrab01)         fastened {printf("%i", Vrab01);}
     int0   C_Print(const int16 Vrab01)        fastened {printf("%i", Vrab01);}
     int0   C_Print(const int32 Vrab01)        fastened {printf("%i", Vrab01);}
     int0   C_Print(const int64 Vrab01)        fastened {printf("%lli", Vrab01);}
     int0   C_Print(const uint8 Vrab01)        fastened {printf("%u", Vrab01);}
     int0   C_Print(const uint16 Vrab01)       fastened {printf("%u", Vrab01);}
     int0   C_Print(const uint32 Vrab01)       fastened {printf("%u", Vrab01);}
     int0   C_Print(const uint64 Vrab01)       fastened {printf("%llu", Vrab01);}
     int0   C_Print(const xint32 Vrab01)       fastened {printf("%f", Vrab01);}
     int0   C_Print(const xint64 Vrab01)       fastened {printf("%Lf", Vrab01);}
     int0   C_Print(const string &Temp01)      fastened {printf("%s", Temp01.c_str());}

     //-//

     int0   Start(statics uint8 Vrab01, statics insize Vrab02, statics uint8 Vrab03, statics insize Vrab04)
     {
      Independent_Team = 5;
      Mode = Vrab01;
      Background = Vrab02; if(Background >= Backgrounds.size()) Background = 0;
      Difficult = Vrab03;
      Max = Vrab04; Effect.clear(); Object.clear();
      Gametime = 0; Move = false;
      Pause = false; Frame_Pause = false; Speed = 2; F6 = false; Hitboxes = false; Fill_Hitboxes = false;
      Animation[Background].clear();
     }
     int0   Set(statics uint8 Vrab01, statics insize Vrab02, statics uint8 Vrab03, statics string Temp01)
     {
      statics insize Vrab04 = Object.size(); Object.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT());
      if(Vrab03 == 0){Object[Vrab04].Team = Independent_Team; Independent_Team += 1;} else {Object[Vrab04].Team = Vrab03 - 1;}
      Object[Vrab04].Player = Vrab01 + 1;
      Object[Vrab04].Name = Temp01;
      Object[Vrab04].Data = &Objects[Vrab02];
      Object[Vrab04].Lock = true; Object[Vrab04].HP = 500; Object[Vrab04].DHP = 500; Object[Vrab04].MHP = 500; Object[Vrab04].MP = 200; Object[Vrab04].MMP = 500;
      Object[Vrab04].Blink = -75; Object[Vrab04].Facing = L_Random(1) == 0; Object[Vrab04].Y_Vel = 1;
      {
       statics xint64 Vrab05 = rxint64(Backgrounds[Background].width) / 2.0, Vrab06 = rxint64(Backgrounds[Background].zboundary[1] - Backgrounds[Background].zboundary[0]) / 2.0;
       Object[Vrab04].X = rxint64(L_Random(rint32(Vrab05))) + (Vrab05 / 2.0);
       Object[Vrab04].Z = rxint64(L_Random(rint32(Vrab06))) + rxint64(Backgrounds[Background].zboundary[0]) + (Vrab06 / 2.0);
      }
     }
     int0   Input(statics uint8 Vrab01, statics int1 Vrab02, statics int1 Vrab03, statics int1 Vrab04, statics int1 Vrab05, statics int1 Vrab06, statics int1 Vrab07, statics int1 Vrab08, statics int1 Vrab09) fastened
     {
      statics insize Vrab10 = Object.size(); insize Vrab11 = 0;
      while(Vrab11 < Vrab10){if(Object[Vrab11].Player == Vrab01 + 1) break; Vrab11 += 1;}
      if(Vrab11 == Vrab10) return;
      Object[Vrab11].In_Up = Vrab02;
      Object[Vrab11].In_Left = Vrab03;
      Object[Vrab11].In_Down = Vrab04;
      Object[Vrab11].In_Right = Vrab05;
      Object[Vrab11].In_A = Vrab06;
      Object[Vrab11].In_J = Vrab07;
      Object[Vrab11].In_D = Vrab08;
      Object[Vrab11].In_C = Vrab09;
     }
     std::vector < HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW > Run(statics int1 Vrab01 = false, statics int1 Vrab02 = false, statics int1 Vrab03 = false, statics int1 Vrab04 = false, statics int1 Vrab05 = false, statics int1 Vrab06 = false, statics int1 Vrab07 = false, statics int1 Vrab08 = false, statics int1 Vrab09 = false) fastened
     {
      std::vector < HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW > Vect01;

      // Functions Keys.
      {
       if(Vrab01) Pause = !Pause;
       if(Frame_Pause){Pause = true; Frame_Pause = false;} if(Vrab02) if(Pause){Pause = false; Frame_Pause = true;} else {Pause = true;}
       if(Vrab03) if(Speed != 0) Speed -= 1;
       if(Vrab04) if(Speed != 4) Speed += 1;
       if(Vrab05) if(Fill_Hitboxes){Hitboxes = false; Fill_Hitboxes = false;} else {if(Hitboxes){Fill_Hitboxes = true;} else {Hitboxes = true;}}
       if(Vrab06) F6 = !F6;
       if(Vrab07){statics insize Vrab99 = Object.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98) if(Object[Vrab98].Exist) if(Object[Vrab98].Data->type == 0){Object[Vrab98].DHP = Object[Vrab98].MHP; Object[Vrab98].HP = Object[Vrab98].DHP; Object[Vrab98].MP = Object[Vrab98].MMP;}}
       if(Vrab08)
       {
        insize Vrab99 = Objects.size(); while(Vrab99 != 0)
        {
         Vrab99 -= 1; if(Objects[Vrab99].id >= 100 && Objects[Vrab99].id <= 199)
         {
          statics insize Vrab98 = Add(Objects[Vrab99].id); if(Vrab98 == rinsize(-1)) continue;
          Object[Vrab98].Y = -500; Object[Vrab98].Facing = L_Random(1) == 0; Object[Vrab98].Frame = 0; Object[Vrab98].Wait = 0; Object[Vrab98].Team = rinsize(-2);
          int1 Vrab97 = L_Random(14) == 0;
          if(Vrab97)
          {
           std::vector < insize > Vect03; insize Vrab96 = Object.size(); while(Vrab96 != 0){Vrab96 -= 1; if(Object[Vrab96].Exist) if(Object[Vrab96].Data->type == 0) Vect03.push_back(Vrab96);}
           if(Vect03.size() != 0)
           {
            Vrab96 = Vect03[L_Random(Vect03.size() - 1)];
            Object[Vrab98].X = Object[Vrab96].X; Object[Vrab98].Z = Object[Vrab96].Z;
           } else {Vrab97 = false;}
          }
          if(!Vrab97)
          {
           statics xint64 Vrab96 = (rxint64(Backgrounds[Background].width) / 30.0) * 28.0, Vrab95 = (rxint64(Backgrounds[Background].zboundary[1] - Backgrounds[Background].zboundary[0]) / 30.0) * 28.0;
           Object[Vrab98].X = rxint64(L_Random(rint32(Vrab96))) + rxint64(Backgrounds[Background].Shift) + (Vrab96 / 28.0);
           Object[Vrab98].Z = rxint64(L_Random(rint32(Vrab95))) + rxint64(Backgrounds[Background].zboundary[0]) + (Vrab95 / 28.0);
          }
         }
        }
       }
       if(Vrab09){statics insize Vrab99 = Object.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98) if(Object[Vrab98].Exist) if(Object[Vrab98].Data->type != 0 && Object[Vrab98].Data->type != 5) Object[Vrab98].HP = 0;}
      }

      // Main Events.
      if(Pause)
      {
       while(true)
       {
        insize Vrab99 = Effect.size(); statics std::vector < insize > Vect02(1, Pics[1]); int1 Vrab98 = false;
        while(Vrab99 != 0)
        {
         Vrab99 -= 1; if(!Effect[Vrab99].Exist) continue; if(Effect[Vrab99].Pics == Vect02){Vrab98 = true; break;}
        }
        if(Vrab98) break;
        statics insize Vrab97 = Effect.size();
        Effect.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT()); Effect[Vrab97].Pics = Vect02; Effect[Vrab97].Screen = true; Effect[Vrab97].X = 358; Effect[Vrab97].Y = 214 - rint64(0xFFFFFF); Effect[Vrab97].Z = 0xFFFFFF;
        break;
       }
      } else
      {
       std::vector < insize > Vect02; Gametime += 1; Playtime += 1; Coloring = 0;

       #pragma region Phase 0 : Arranging Main Values, Random Falling Weapons.
       {
        // Arranging Main Values.
        {
         {insize Vrab99 = Effect.size(); while(Vrab99 != 0){Vrab99 -= 1; statics insize Vrab98 = Effect[Vrab99].Pics.size(); if(Vrab98 != Effect[Vrab99].Pic + 1){Effect[Vrab99].Pic += 1;} else {if(Effect[Vrab99].Loop && Vrab98 != 0){Effect[Vrab99].Pic = 0;} else {Effect[Vrab99].Exist = false;}}}}
         {insize Vrab99 = Object.size(); if(Vrab99 != 0){while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Exist) break;} if(Vrab99 == 0) if(!Object[Vrab99].Exist) Vrab99 -= 1; Object.resize(Vrab99 + 1);}}
         {insize Vrab99 = Effect.size(); if(Vrab99 != 0){while(Vrab99 != 0){Vrab99 -= 1; if(Effect[Vrab99].Exist) break;} if(Vrab99 == 0) if(!Effect[Vrab99].Exist) Vrab99 -= 1; Effect.resize(Vrab99 + 1);}}
         {insize Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; insize Vrab98 = Object[Vrab99].Vrest.size(); if(Vrab98 != 0){while(Vrab98 != 0){Vrab98 -= 1; if(Object[Vrab99].Vrest[Vrab98] != 0) break;} if(Vrab98 == 0) if(Object[Vrab99].Vrest[Vrab98] == 0) Vrab98 -= 1; Object[Vrab99].Vrest.resize(Vrab98 + 1);}}}
         {statics insize Vrab99 = Object.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98) if(Object[Vrab98].Exist) Vect02.push_back(Vrab98);}
         {insize Vrab99 = (Varb0002 < 800) ? (800 - Varb0002) : 0; if(Background >= Backgrounds.size()) Background = 0; if(Backgrounds[Background].width < 800 - Vrab99){Backgrounds[Background].Shift = L_Rounding(rxint64(800 - Backgrounds[Background].width - Vrab99) / 2.0);} else {Backgrounds[Background].Shift = 0;}}
        }

        // Random Falling Weapons.
        {
         insize Vrab99 = 0; {insize Vrab98 = Vect02.size(); while(Vrab98 != 0){Vrab98 -= 1; statics insize Vrab97 = Object[Vect02[Vrab98]].Data->type; switch(Vrab97){case 0: break; case 3: break; case 5: break; default: if(Vrab97 > 6) break; Vrab99 += 1; continue;}}}
         insize Vrab98 = Objects.size();
         while(Vrab98 != 0 && Vrab99 < 4)
         {
          Vrab98 -= 1; if(Objects[Vrab98].id < 100 || Objects[Vrab98].id > 199) continue; if(L_Random(549) != 0) continue; Vrab99 += 1;
          statics insize Vrab97 = Add(Objects[Vrab98].id);
          if(Vrab97 == rinsize(-1)) continue;
          Object[Vrab97].Y = -500; Object[Vrab97].Facing = L_Random(1) == 0; Object[Vrab97].Frame = 0; Object[Vrab97].Team = rinsize(-2);
          int1 Vrab96 = L_Random(14) == 0;
          if(Vrab96)
          {
           std::vector < insize > Vect03; insize Vrab95 = Vect02.size(); while(Vrab95 != 0){Vrab95 -= 1; if(Object[Vect02[Vrab95]].Data->type == 0) Vect03.push_back(Vect02[Vrab95]);}
           if(Vect03.size() != 0)
           {
            Vrab95 = Vect03[L_Random(Vect03.size() - 1)];
            Object[Vrab97].X = Object[Vrab95].X; Object[Vrab97].Z = Object[Vrab95].Z;
           } else {Vrab96 = false;}
          }
          if(!Vrab96)
          {
           statics xint64 Vrab95 = (rxint64(Backgrounds[Background].width) / 30.0) * 28.0, Vrab94 = (rxint64(Backgrounds[Background].zboundary[1] - Backgrounds[Background].zboundary[0]) / 30.0) * 28.0;
           Object[Vrab97].X = rxint64(L_Random(rint32(Vrab95))) + rxint64(Backgrounds[Background].Shift) + (Vrab95 / 28.0);
           Object[Vrab97].Z = rxint64(L_Random(rint32(Vrab94))) + rxint64(Backgrounds[Background].zboundary[0]) + (Vrab94 / 28.0);
          }
         }
        }

        Vect02.clear(); insize Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Exist) Vect02.push_back(Vrab99);}
       }
       #pragma endregion

       #pragma region Phase 1 : Values Control, Next, Negative MP & Repetition, Disintegrate, Opoint, Hardcoded Next, Natural Regen.
       {
        insize Vrab99 = Vect02.size(), Vrab98 = 0;
        while(Vrab98 < Vrab99)
        {
         statics insize Vrab97 = Vect02[Vrab98]; Vrab98 += 1;
         if(Vrab97 >= Object.size()) continue; if(!Object[Vrab97].Exist) continue; Object[Vrab97].Frame3 = Object[Vrab97].Frame;

         // Values Control
         {
          if(!Polish || Gametime % 4 == 0)
          {
           if(Object[Vrab97].Blink > 0) Object[Vrab97].Blink -= 1;
           if(Object[Vrab97].Blink < 0) Object[Vrab97].Blink += 1;
           if(Object[Vrab97].Shake > 0){Object[Vrab97].X_Vel = 0; Object[Vrab97].Y_Vel = 0; Object[Vrab97].Z_Vel = 0; Object[Vrab97].Shake -= 1;}
           if(Object[Vrab97].Shake < 0) Object[Vrab97].Shake += 1;
           if(Object[Vrab97].Shake == 0)
           {
            Object[Vrab97].X_Vel += Object[Vrab97].X_Accel; Object[Vrab97].Y_Vel += Object[Vrab97].Y_Accel; Object[Vrab97].Z_Vel += Object[Vrab97].Z_Accel;
            Object[Vrab97].X_Accel = 0; Object[Vrab97].Y_Accel = 0; Object[Vrab97].Z_Accel = 0;
            if(Object[Vrab97].Arest > 0) Object[Vrab97].Arest -= 1;
           }
           insize Vrab96 = Object[Vrab97].Vrest.size(); while(Vrab96 != 0){Vrab96 -= 1; if(Object[Vrab97].Vrest[Vrab96] > 0) Object[Vrab97].Vrest[Vrab96] -= 1;}
          }
         }

         // Next.
         {
          int1 Vrab96 = false;
          while(true)
          {
           statics insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 == 1000 || Vrab95 == 9998){Vrab96 = true; break;} if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;
           if(Object[Vrab97].Held != rinsize(-1) || Object[Vrab97].Caught != rinsize(-1)) break;
           if(Object[Vrab97].Shake != 0 && Object[Vrab97].Data->type != 3) break;
           if(Object[Vrab97].Data->Frame[Vrab95]->state != 14){Object[Vrab97].Wait += 1; if(Object[Vrab97].Data->type == 0) Object[Vrab97].Lying = 0;} else {if(Object[Vrab97].HP > 0) Object[Vrab97].Wait += 1; Object[Vrab97].Lying += 1;}

           int32 Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->next;
           if(Vrab94 != 0)
           if(Object[Vrab97].Wait > ((ruint32(Object[Vrab97].Data->Frame[Vrab95]->wait) + 1) * (Polish ? 4 : 1)) - 1)
           {
            if(Vrab94 < 0){Vrab94 = -Vrab94; Object[Vrab97].Facing = !Object[Vrab97].Facing;}
            if(Vrab94 == 1000 || Vrab94 == 9998){Vrab96 = true; break;}

            int1 Vrab93 = Object[Vrab97].Data->Frame[Vrab95]->state == 14 && Object[Vrab97].Lying >= 20;
            while(true)
            {
             if(rinsize(Vrab94) >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;
             if(Object[Vrab97].Data->Frame[rinsize(Vrab94)]->state == 14) Vrab93 = false;
             break;
            }
            if(Vrab93) Object[Vrab97].Blink = -15;

            if(Object[Vrab97].Frame == 13)
            {
             
            }

            Object[Vrab97].Frame = rinsize(Vrab94); Object[Vrab97].Wait = 0;
           }

           break;
          }
          if(Vrab96){Remove(Vrab97); continue;}
         }

         // Negative MP & Repetition.
         {
          int1 Vrab96 = false;
          while(true)
          {
           if(Object[Vrab97].Shake != 0 && Object[Vrab97].Data->type != 3) break;
           insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;

           // Repetition
           if(Object[Vrab97].Data->type == 3)
           {
            statics int32 Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->hit_a; int32 Vrab93 = Object[Vrab97].Data->Frame[Vrab95]->hit_d;
            if(Vrab93 != 0)
            {
             Object[Vrab97].Counter -= rint16(Vrab94);
             if((Object[Vrab97].Counter <= 0 || Vrab94 >= 500) && Vrab95 != rinsize(L_Positive(Vrab93)))
             {
              Vrab95 = rinsize(L_Positive(Vrab93)); if(Vrab93 < 0) Object[Vrab97].Facing = !Object[Vrab97].Facing; Object[Vrab97].Wait = 0;
              Object[Vrab97].Frame = Vrab95; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;
             }
            }
           }
           
           if(Object[Vrab97].Wait != 0) break;
           statics int32 Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->mp;
           if(Vrab94 < 0)
           {
            int32 Vrab93 = Object[Vrab97].Data->Frame[Vrab95]->hit_d;
            if(Vrab93 != 0 && (Object[Vrab97].MP < rxint64(-Vrab94) || ((Object[Vrab97].Facing ? (Object[Vrab97].Input_Left > 0 && Object[Vrab97].Input_Right == 0) : (Object[Vrab97].Input_Right > 0 && Object[Vrab97].Input_Left == 0)) && Object[Vrab97].Y >= 0)))
            {
             if(Vrab93 < 0){Vrab93 = -Vrab93; Object[Vrab97].Facing = !Object[Vrab97].Facing;}
             if(Vrab93 == 1000 || Vrab93 == 9998){Vrab96 = true; break;}
             Object[Vrab97].Frame = rinsize(Vrab93); Object[Vrab97].Wait = 0;
            } else {Object[Vrab97].MP -= rxint64(-Vrab94); if(Object[Vrab97].MP < 0) Object[Vrab97].MP = 0;}
           }
           break;
          }
          if(Vrab96){Remove(Vrab97); continue;}
         }

         // Disintegrate.
         {
          int1 Vrab96 = false;
          while(true)
          {
           if(Object[Vrab97].Frame == 9998){Vrab96 = true; break;}
           if(Object[Vrab97].Held != rinsize(-1) || Object[Vrab97].Caught != rinsize(-1)) break;

           statics xint64 Vrab95 = rxint64(Backgrounds[Background].Shift), Vrab94 = Vrab95 + rxint64(Backgrounds[Background].width);
           if(Object[Vrab97].Data->type != 0 && Object[Vrab97].Data->type != 3)
           {
            if(Object[Vrab97].Y >= 0){Object[Vrab97].Lying += 1;} else {Object[Vrab97].Lying = 0;}
            if(Object[Vrab97].Lying >= 60ui32 * (Polish ? 4ui32 : 1ui32))
            if(Object[Vrab97].X < Vrab95 || Object[Vrab97].X > Vrab94){Vrab96 = true; break;}
           }
           if(Object[Vrab97].Data->type != 0)
           if(Object[Vrab97].X < Vrab95 - 200 || Object[Vrab97].X > Vrab94 + 200){Vrab96 = true; break;}

           statics insize Vrab93 = Object[Vrab97].Frame; if(Vrab93 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab93]->Exist) break;
           statics int32 Vrab92 = Object[Vrab97].Data->Frame[Vrab93]->state;
           switch(Vrab92)
           {
            case 9999: if(Object[Vrab97].Y >= 0) Vrab96 = true; break;
            case 9998: Vrab96 = true; break;
            default: break;
           }
           break;
          }
          while(true)
          {
           statics insize Vrab95 = Object[Vrab97].Frame2; if(Vrab95 == Object[Vrab97].Frame) break; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;
           if(Object[Vrab97].Data->Frame[Vrab95]->state == 13)
           {
            statics insize Vrab94 = 5; // Big Ice. (120 ~ 123)
            statics insize Vrab93 = 3; // Small Ice. (125 ~ 128)
            statics insize Vrab92 = 5; // Big Ice2. (130 ~ 133)
            statics insize Vrab91 = 3; // Small Ice2. (135 ~ 138)
            insize Vrab90 = 0;
            while(Vrab90 < Vrab94 + Vrab93 + Vrab92 + Vrab91)
            {
             Vrab90 += 1; 
             statics insize Vrab89 = Add(999);
             if(Vrab89 == rinsize(-1)) break; Vect02.push_back(Vrab89); Vrab99 += 1;

             Object[Vrab89].Facing = L_Random(1) == 0;
             Object[Vrab89].Team = Object[Vrab97].Team; Object[Vrab89].Name = Object[Vrab97].Name; Object[Vrab89].Owners = Object[Vrab97].Owners; Object[Vrab89].Owners.push_back(Vrab97); Object[Vrab89].Scale = Object[Vrab97].Scale;
             Object[Vrab89].Frame = L_Random(3); if(Object[Vrab97].Blink > 0) Object[Vrab89].Blink = Object[Vrab97].Blink;
 
             if(Object[Vrab89].Data->type == 0)
             {statics int1 Vrab88 = (Object[Vrab97].Data->id == 52 || Object[Vrab97].Data->id == 5); Object[Vrab89].Clone = Vrab97; Object[Vrab89].MP = Vrab88 ? 100 : 500; Object[Vrab89].MMP = Vrab88 ? 100 : 500; Object[Vrab89].HP = Vrab88 ? 10 : 500; Object[Vrab89].DHP = Vrab88 ? 10 : 500; Object[Vrab89].MHP = Vrab88 ? 10 : 500;} else
             {Object[Vrab89].MP = 500; Object[Vrab89].MMP = 500; statics xint64 Vrab88 = rxint64(Object[Vrab89].Data->weapon_hp); Object[Vrab89].HP = Vrab88; Object[Vrab89].DHP = Vrab88; Object[Vrab89].MHP = Vrab88;}
 
             Object[Vrab89].X = Object[Vrab97].X - 25 + rxint64(L_Random(50));
             Object[Vrab89].Y = Object[Vrab97].Y - 55 + rxint64(L_Random(50));
             Object[Vrab89].Z = Object[Vrab97].Z;
             Object[Vrab89].D = Object[Vrab97].D;
             Object[Vrab89].X_Vel = Object[Vrab97].X_Vel - 1.0 + (rxint64(L_Random(10)) * 0.2);
             Object[Vrab89].Y_Vel = Object[Vrab97].Y_Vel - 1.0 - (rxint64(L_Random(10)) * 0.3);
             Object[Vrab89].Z_Vel = Object[Vrab97].Z_Vel - 0.4 + (rxint64(L_Random(10)) * 0.08);
             if(Object[Vrab97].Shake != 0)
             {
              Object[Vrab89].X_Vel += Object[Vrab97].X_Accel;
              Object[Vrab89].Y_Vel += Object[Vrab97].Y_Accel;
              Object[Vrab89].Z_Vel += Object[Vrab97].Z_Accel;
             }

             if(Vrab90 <= Vrab94)
             {Object[Vrab89].Frame += 120; continue;}
             if(Vrab90 - Vrab94 <= Vrab93)
             {Object[Vrab89].Frame += 125; continue;}
             if(Vrab90 - Vrab94 - Vrab93 <= Vrab92)
             {Object[Vrab89].Frame += 130; continue;}
             Object[Vrab89].Frame += 135;
            }
           }
           break;
          } Object[Vrab97].Frame2 = Object[Vrab97].Frame;
          if(Vrab96){Remove(Vrab97); continue;}
         }
         
         // Opoint.
         {
          if(Object[Vrab97].Wait == 0)
          while(true)
          {
           if(Object[Vrab97].Shake != 0 && Object[Vrab97].Data->type != 3) break;
           statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab96]->Exist) break;
           statics insize Vrab95 = Object[Vrab97].Data->Frame[Vrab96]->opoint.size();
           for(insize Vrab94 = 0; Vrab94 < Vrab95; ++Vrab94)
           {
            statics int32 Vrab93 = Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].kind;
            if(Vrab93 == 0 || Vrab93 > 2) continue;

            statics int32 Vrab92 = Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].facing;
            insize Vrab91 = Vrab92 / 10; if(Vrab92 <= 0 || Vrab91 == 0) Vrab91 = 1;
            for(insize Vrab90 = 0; Vrab90 < Vrab91; ++Vrab90)
            {
             statics insize Vrab89 = Add(rinsize(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].oid));
             if(Vrab89 == rinsize(-1)) break; Vect02.push_back(Vrab89); Vrab99 += 1;
             
             if(Vrab93 == 2){Object[Vrab89].Held = Vrab97; Object[Vrab97].Hold = Vrab89;}
             Object[Vrab89].Frame = rinsize(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].action); if(Object[Vrab89].Data->type == 0) if(Object[Vrab97].Blink > 0) Object[Vrab89].Blink = Object[Vrab97].Blink;
             Object[Vrab89].Team = Object[Vrab97].Team; Object[Vrab89].Name = Object[Vrab97].Name; Object[Vrab89].Owners = Object[Vrab97].Owners; Object[Vrab89].Owners.push_back(Vrab97); Object[Vrab89].Scale = Object[Vrab97].Scale;
             Object[Vrab89].Facing = (Vrab92 == 10 || Vrab92 % 10 == 2) ? true : (Vrab92 % 10 == 3 ? false : (Vrab92 % 10 == 1 ? !Object[Vrab97].Facing : Object[Vrab97].Facing));
             
             if(Object[Vrab89].Data->type == 0)
             {statics int1 Vrab88 = (Object[Vrab97].Data->id == 52 || Object[Vrab97].Data->id == 5); Object[Vrab89].Clone = Vrab97; Object[Vrab89].MP = Vrab88 ? 100 : 500; Object[Vrab89].MMP = Vrab88 ? 100 : 500; Object[Vrab89].HP = Vrab88 ? 10 : 500; Object[Vrab89].DHP = Vrab88 ? 10 : 500; Object[Vrab89].MHP = Vrab88 ? 10 : 500;} else
             {Object[Vrab89].MP = 500; Object[Vrab89].MMP = 500; statics xint64 Vrab88 = rxint64(Object[Vrab89].Data->weapon_hp); Object[Vrab89].HP = Vrab88; Object[Vrab89].DHP = Vrab88; Object[Vrab89].MHP = Vrab88;}
             
             if(Object[Vrab97].Facing)
             {Object[Vrab89].X = Object[Vrab97].X - rxint64(Object[Vrab97].Data->Frame[Vrab96]->centerx) + rxint64(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].x); Object[Vrab89].X_Vel = (Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].facing % 10 == 1 ? -1 : 1) * rxint64(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].dvx);} else
             {Object[Vrab89].X = Object[Vrab97].X + rxint64(Object[Vrab97].Data->Frame[Vrab96]->centerx) - rxint64(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].x); Object[Vrab89].X_Vel = (Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].facing % 10 == 1 ? 1 : -1) * rxint64(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].dvx);}
             Object[Vrab89].Y = Object[Vrab97].Y - rxint64(Object[Vrab97].Data->Frame[Vrab96]->centery) + rxint64(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].y); Object[Vrab89].Y_Vel = rxint64(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].dvy);
             Object[Vrab89].Z = Object[Vrab97].Z + 1.0;
             Object[Vrab89].D = Object[Vrab97].D;

             if(Object[Vrab89].Data->id != 223 && Object[Vrab89].Data->id != 224)
             while(true)
             {
              statics insize Vrab88 = Object[Vrab89].Frame; if(Vrab88 >= Object[Vrab89].Data->Frame.size()) break; if(!Object[Vrab89].Data->Frame[Vrab88]->Exist) break;
              statics int32 Vrab87 = Object[Vrab89].Data->Frame[Vrab88]->state;
              int1 Vrab86 = false;
              switch(Vrab87){case 3000: case 3006: Vrab86 = true; break; default: break;}
              if(Object[Vrab89].Data->type != 3 && Object[Vrab89].Data->type != 0) Vrab86 = true;
              if(Vrab86 && Object[Vrab89].Y <= 0) Object[Vrab89].Z_Vel = ((Object[Vrab97].Input_Down > 0 && Object[Vrab97].Input_Up == 0) ? 1.0 : ((Object[Vrab97].Input_Up > 0 && Object[Vrab97].Input_Down == 0) ? -1.0 : 0.0)) * (Object[Vrab89].Data->id == 211 ? 0.625 : 2.5);
              break;
             }

             if(Vrab91 > 1)
             {
              Object[Vrab89].Z_Vel += -5.0 + ((10.0 / rxint64(Vrab91 - 1)) * rxint64(Vrab90));
              Object[Vrab89].X_Vel += (Object[Vrab89].X_Vel <= 0 ? 1 : -1) * (Object[Vrab89].X_Vel == 0 ? ((Object[Vrab97].Facing ? -1 : 1) * (-5.0 + ((10.0 / rxint64(Vrab91 - 1)) * rxint64(Vrab90)))) : L_Positive64(-5.0 + ((10.0 / rxint64(Vrab91 - 1)) * rxint64(Vrab90))));
             }
            }
           }
           break;
          }
         }

         // Hardcoded Next.
         {
          if(Object[Vrab97].Wait == 0) if(Object[Vrab97].Shake == 0 || Object[Vrab97].Data->type == 3)
          switch(Object[Vrab97].Frame)
          {
           case 212:
            {
             Object[Vrab97].Landing = true;
             statics xint64 Vrab91 = Object[Vrab97].Data->jump_height; /*if((Vrab91 > 0 && Object[Vrab97].Y_Vel < Vrab91) || (Vrab91 < 0 && Object[Vrab97].Y_Vel > Vrab91))*/ Object[Vrab97].Y_Vel = Vrab91;
             statics xint64 Vrab90 = Object[Vrab97].Data->jump_distance, Vrab89 = Object[Vrab97].Data->jump_distancez;
             if(Object[Vrab97].Input_Left >= 1 && Object[Vrab97].Input_Right == 0) if((Vrab90 > 0 && Object[Vrab97].X_Vel > -Vrab90) || (Vrab90 < 0 && Object[Vrab97].X_Vel < -Vrab90)) Object[Vrab97].X_Vel = -Vrab90;
             if(Object[Vrab97].Input_Right >= 1 && Object[Vrab97].Input_Left == 0) if((Vrab90 > 0 && Object[Vrab97].X_Vel < Vrab90) || (Vrab90 < 0 && Object[Vrab97].X_Vel > Vrab90)) Object[Vrab97].X_Vel = Vrab90;
             if(Object[Vrab97].Input_Up >= 1 && Object[Vrab97].Input_Down == 0) if((Vrab89 > 0 && Object[Vrab97].Z_Vel > -Vrab89) || (Vrab89 < 0 && Object[Vrab97].Z_Vel < -Vrab89)) Object[Vrab97].Z_Vel = -Vrab89;
             if(Object[Vrab97].Input_Down >= 1 && Object[Vrab97].Input_Up == 0) if((Vrab89 > 0 && Object[Vrab97].Z_Vel < Vrab89) || (Vrab89 < 0 && Object[Vrab97].Z_Vel > Vrab89)) Object[Vrab97].Z_Vel = Vrab89;
            }
           break;
           case 999:
            {
             if(Object[Vrab97].Y < 0 && Object[Vrab97].Data->type == 0){Object[Vrab97].Frame = 212; Object[Vrab97].Landing = true;} else {Object[Vrab97].Frame = 0;}
             if(Object[Vrab97].Heavy_Hold) Object[Vrab97].Frame = 12;
            }
           break;
           default:
            if(Object[Vrab97].Frame >= 1100 && Object[Vrab97].Frame <= 1299)
            {
             statics int32 Vrab91 = rint32(Object[Vrab97].Frame) - 1100; Object[Vrab97].Blink = Vrab91; Object[Vrab97].Frame = 0;
             std::vector < insize > Vect03 = Vect02; Vect03.erase(Vect03.begin() + Vrab98 - 1);
             std::vector < insize > Vect04(1, Vrab97);
             insize Vrab90 = Vect03.size();
             while(Vrab90 != 0)
             {
              Vrab90 -= 1; statics insize Vrab89 = Object[Vect03[Vrab90]].Clone;
              if(Vrab89 == rinsize(-1)){Vect03.erase(Vect03.begin() + Vrab90); continue;}
              insize Vrab88 = Vect04.size();
              while(Vrab88 != 0)
              {
               Vrab88 -= 1; if(Vrab89 == Vect04[Vrab88]){Vect04.push_back(Vect03[Vrab90]); if(Object[Vect03[Vrab90]].Data->type == 0 && L_Positive(Object[Vect03[Vrab90]].Blink) < Vrab91) Object[Vect03[Vrab90]].Blink = Vrab91; Vect03.erase(Vect03.begin() + Vrab90); Vrab90 = Vect03.size(); break;}
              }
             }
            }
           break;
          }
         }

         // Natural Regen.
         {
          // Arest's Special Reset. (Reset Arest when there's no Arest-Type ITR exist.)
          {
           int1 Vrab96 = true;
           while(true){statics insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break; insize Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->itr.size(); while(Vrab94 != 0){Vrab94 -= 1; if(Object[Vrab97].Data->Frame[Vrab95]->itr[Vrab94].vrest == 0){Vrab96 = false; break;}} break;}
           if(Vrab96) Object[Vrab97].Arest = 0;
          }

          if(Object[Vrab97].HP <= 0) Object[Vrab97].HP = 0;
          if(Object[Vrab97].DHP <= 0) Object[Vrab97].DHP = 0;
          if(Object[Vrab97].MHP <= 0) Object[Vrab97].MHP = 0;

          if(Object[Vrab97].Data->type == 0)
          if(Object[Vrab97].HP > 0)
          {
           if(Object[Vrab97].Blink <= 0)
           {
            // Natural HP Regen.
            {
             statics xint64 Vrab96 = Polish ? (0.25 / 12.0) : (1.0 / 12.0);
             if(Object[Vrab97].HP < Object[Vrab97].DHP) if(Object[Vrab97].HP + Vrab96 > Object[Vrab97].DHP){Object[Vrab97].HP = Object[Vrab97].DHP;} else {Object[Vrab97].HP += Vrab96;}
             if(Object[Vrab97].HP > Object[Vrab97].DHP) if(Object[Vrab97].HP - Vrab96 < Object[Vrab97].DHP){Object[Vrab97].HP = Object[Vrab97].DHP;} else {Object[Vrab97].HP -= Vrab96;}
            }

            // Natural MP Regen.
            {
             xint64 Vrab96 = Polish ? 2.5 : 10;
             if(!F6){Vrab96 = 0; if(Gametime % 3 == 0){Vrab96 = Polish ? 0.25 : 1; if(Object[Vrab97].HP < Object[Vrab97].MHP) Vrab96 = ((1 + (1 * rxint64((L_Rounding64(Object[Vrab97].MHP - Object[Vrab97].HP)) / (Object[Vrab97].MHP / 5)))) / (Polish ? 4 : 1)); switch(Object[Vrab97].Data->id){case 51: case 52: if(Vrab96 < 2) Vrab96 = 2; default: break;}}}
             if(Object[Vrab97].MP + Vrab96 < Object[Vrab97].MMP){Object[Vrab97].MP += Vrab96;} else {Object[Vrab97].MP = Object[Vrab97].MMP;}
            }
           }

           // HP Regen.
           {
            statics xint64 Vrab96 = ((Object[Vrab97].MHP / 500.0) / (Polish ? 4 : 1)) * (rxint64(Object[Vrab97].Heal_Ratio) / 1000), Vrab95 = Vrab96 / 4.0; Object[Vrab97].Heal_Ratio = 1000;
            if(Object[Vrab97].Heal > 0)
            {
             Object[Vrab97].Heal -= 1; if(Object[Vrab97].HP >= Object[Vrab97].DHP){Object[Vrab97].HP += Vrab95;} else {statics xint64 Vrab94 = Object[Vrab97].DHP - Object[Vrab97].HP; if(Vrab94 < Vrab96){Object[Vrab97].HP += Vrab94 + ((Vrab96 - Vrab94) * Vrab95);} else {Object[Vrab97].HP += Vrab96;}}
            } else {Object[Vrab97].Heal = 0;}
           }
          }
         }
        }
        
        Vect02.clear(); Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Exist) Vect02.push_back(Vrab99);}
       }
       #pragma endregion

       #pragma region Phase 2 : Sound Effect, Input, Position Shift.
       {
        insize Vrab99 = Vect02.size();
        while(Vrab99 != 0)
        {
         Vrab99 -= 1; statics insize Vrab98 = Vect02[Vrab99];

         // Sound Effect.
         {
          while(true)
          {
           statics insize Vrab97 = Object[Vrab98].Frame; if(Vrab97 == Object[Vrab98].Frame4) break; Object[Vrab98].Frame4 = Vrab97;
           if(Vrab97 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab97]->Exist) break;
           statics insize Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->sound_Index;
           if(Vrab96 != rinsize(-1)) Vect01.push_back({Vrab96, Object[Vrab98].X, Object[Vrab98].Y, Object[Vrab98].Z, Object[Vrab98].D});
           break;
          }
         }

         // Input.
         {
          Control(Vrab98);

          if(Object[Vrab98].In_Up)   {if((++Object[Vrab98].Input_Up) == 255ui8) Object[Vrab98].Input_Up = 254ui8;} else {Object[Vrab98].Input_Up = 0ui8;}
          if(Object[Vrab98].In_Left) {if((++Object[Vrab98].Input_Down) == 255ui8) Object[Vrab98].Input_Down = 254ui8;} else {Object[Vrab98].Input_Down = 0ui8;}
          if(Object[Vrab98].In_Down) {if((++Object[Vrab98].Input_Left) == 255ui8) Object[Vrab98].Input_Left = 254ui8;} else {Object[Vrab98].Input_Left = 0ui8;}
          if(Object[Vrab98].In_Right){if((++Object[Vrab98].Input_Right) == 255ui8) Object[Vrab98].Input_Right = 254ui8;} else {Object[Vrab98].Input_Right = 0ui8;}
          if(Object[Vrab98].In_A)    {if((++Object[Vrab98].Input_A) == 255ui8) Object[Vrab98].Input_A = 254ui8;} else {Object[Vrab98].Input_A = 0ui8;}
          if(Object[Vrab98].In_J)    {if((++Object[Vrab98].Input_J) == 255ui8) Object[Vrab98].Input_J = 254ui8;} else {Object[Vrab98].Input_J = 0ui8;}
          if(Object[Vrab98].In_D)    {if((++Object[Vrab98].Input_D) == 255ui8) Object[Vrab98].Input_D = 254ui8;} else {Object[Vrab98].Input_D = 0ui8;}
          if(Object[Vrab98].In_C)    {if((++Object[Vrab98].Input_C) == 255ui8) Object[Vrab98].Input_C = 254ui8;} else {Object[Vrab98].Input_C = 0ui8;}

          if(Object[Vrab98].Press_A > 0) Object[Vrab98].Press_A -= 1;
          if(Object[Vrab98].Press_D > 0) Object[Vrab98].Press_D -= 1;
          if(Object[Vrab98].Press_J > 0) Object[Vrab98].Press_J -= 1;

          if(Object[Vrab98].Cast_A > 0) Object[Vrab98].Cast_A -= 1;
          if(Object[Vrab98].Cast_D > 0) Object[Vrab98].Cast_D -= 1;
          if(Object[Vrab98].Cast_J > 0) Object[Vrab98].Cast_J -= 1;
          if(Object[Vrab98].Cast_DRA == 4) Object[Vrab98].Cast_DRA = 0;
          if(Object[Vrab98].Cast_DLA == 4) Object[Vrab98].Cast_DLA = 0;
          if(Object[Vrab98].Cast_DRJ == 4) Object[Vrab98].Cast_DRJ = 0;
          if(Object[Vrab98].Cast_DLJ == 4) Object[Vrab98].Cast_DLJ = 0;
          if(Object[Vrab98].Cast_DDA == 4) Object[Vrab98].Cast_DDA = 0;
          if(Object[Vrab98].Cast_DDJ == 4) Object[Vrab98].Cast_DDJ = 0;
          if(Object[Vrab98].Cast_DUA == 4) Object[Vrab98].Cast_DUA = 0;
          if(Object[Vrab98].Cast_DUJ == 4) Object[Vrab98].Cast_DUJ = 0;
          if(Object[Vrab98].Cast_DJA == 4) Object[Vrab98].Cast_DJA = 0;
          if(Object[Vrab98].Input_D == 1)
          {
           Object[Vrab98].Press_D = (Polish ? 16 : 4); Object[Vrab98].Cast_D = (Polish ? 16 : 4); Object[Vrab98].Cast_A = 0; Object[Vrab98].Cast_J = 0;
           Object[Vrab98].Cast_DRA = Object[Vrab98].Cast_DRA > 0 ? 0 : 1;
           Object[Vrab98].Cast_DLA = Object[Vrab98].Cast_DLA > 0 ? 0 : 1;
           Object[Vrab98].Cast_DRJ = Object[Vrab98].Cast_DRJ > 0 ? 0 : 1;
           Object[Vrab98].Cast_DLJ = Object[Vrab98].Cast_DLJ > 0 ? 0 : 1;
           Object[Vrab98].Cast_DDA = Object[Vrab98].Cast_DDA > 0 ? 0 : 1;
           Object[Vrab98].Cast_DDJ = Object[Vrab98].Cast_DDJ > 0 ? 0 : 1;
           Object[Vrab98].Cast_DUA = Object[Vrab98].Cast_DUA > 0 ? 0 : 1;
           Object[Vrab98].Cast_DUJ = Object[Vrab98].Cast_DUJ > 0 ? 0 : 1;
           Object[Vrab98].Cast_DJA = Object[Vrab98].Cast_DJA > 0 ? 0 : 1;
          }
          if(Object[Vrab98].Input_Left == 1) {if(Object[Vrab98].Cast_DLA == 1){Object[Vrab98].Cast_DLA = 2;} else {Object[Vrab98].Cast_DLA = 0;} if(Object[Vrab98].Cast_DLJ == 1){Object[Vrab98].Cast_DLJ = 2;} else {Object[Vrab98].Cast_DLJ = 0;} Object[Vrab98].Cast_DRA = 0; Object[Vrab98].Cast_DRJ = 0; Object[Vrab98].Cast_DDA = 0; Object[Vrab98].Cast_DDJ = 0; Object[Vrab98].Cast_DUA = 0; Object[Vrab98].Cast_DUJ = 0; Object[Vrab98].Cast_DJA = 0;}
          if(Object[Vrab98].Input_Right == 1){if(Object[Vrab98].Cast_DRA == 1){Object[Vrab98].Cast_DRA = 2;} else {Object[Vrab98].Cast_DRA = 0;} if(Object[Vrab98].Cast_DRJ == 1){Object[Vrab98].Cast_DRJ = 2;} else {Object[Vrab98].Cast_DRJ = 0;} Object[Vrab98].Cast_DLA = 0; Object[Vrab98].Cast_DLJ = 0; Object[Vrab98].Cast_DDA = 0; Object[Vrab98].Cast_DDJ = 0; Object[Vrab98].Cast_DUA = 0; Object[Vrab98].Cast_DUJ = 0; Object[Vrab98].Cast_DJA = 0;}
          if(Object[Vrab98].Input_Up == 1)   {if(Object[Vrab98].Cast_DUA == 1){Object[Vrab98].Cast_DUA = 2;} else {Object[Vrab98].Cast_DUA = 0;} if(Object[Vrab98].Cast_DUJ == 1){Object[Vrab98].Cast_DUJ = 2;} else {Object[Vrab98].Cast_DUJ = 0;} Object[Vrab98].Cast_DLA = 0; Object[Vrab98].Cast_DLJ = 0; Object[Vrab98].Cast_DRA = 0; Object[Vrab98].Cast_DRJ = 0; Object[Vrab98].Cast_DDA = 0; Object[Vrab98].Cast_DDJ = 0; Object[Vrab98].Cast_DJA = 0;}
          if(Object[Vrab98].Input_Down == 1) {if(Object[Vrab98].Cast_DDA == 1){Object[Vrab98].Cast_DDA = 2;} else {Object[Vrab98].Cast_DDA = 0;} if(Object[Vrab98].Cast_DDJ == 1){Object[Vrab98].Cast_DDJ = 2;} else {Object[Vrab98].Cast_DDJ = 0;} Object[Vrab98].Cast_DLA = 0; Object[Vrab98].Cast_DLJ = 0; Object[Vrab98].Cast_DRA = 0; Object[Vrab98].Cast_DRJ = 0; Object[Vrab98].Cast_DUA = 0; Object[Vrab98].Cast_DUJ = 0; Object[Vrab98].Cast_DJA = 0;}
          if(Object[Vrab98].Input_J == 1)
          {
           Object[Vrab98].Press_J = (Polish ? 16 : 4); Object[Vrab98].Cast_J = (Polish ? 16 : 4); if(Object[Vrab98].Cast_D == (Polish ? 16 : 4)) Object[Vrab98].Cast_J = 0; Object[Vrab98].Cast_A = 0; Object[Vrab98].Cast_D = 0;
           if(Object[Vrab98].Cast_DRJ == 2){if(Object[Vrab98].Input_Right == 1){Object[Vrab98].Cast_DRJ = 4;} else {Object[Vrab98].Cast_DRJ = 3;}} else {Object[Vrab98].Cast_DRJ = 0;}
           if(Object[Vrab98].Cast_DLJ == 2){if(Object[Vrab98].Input_Left == 1) {Object[Vrab98].Cast_DLJ = 4;} else {Object[Vrab98].Cast_DLJ = 3;}} else {Object[Vrab98].Cast_DLJ = 0;}
           if(Object[Vrab98].Cast_DDJ == 2){if(Object[Vrab98].Input_Down == 1) {Object[Vrab98].Cast_DDJ = 4;} else {Object[Vrab98].Cast_DDJ = 3;}} else {Object[Vrab98].Cast_DDJ = 0;}
           if(Object[Vrab98].Cast_DUJ == 2){if(Object[Vrab98].Input_Up == 1)   {Object[Vrab98].Cast_DUJ = 4;} else {Object[Vrab98].Cast_DUJ = 3;}} else {Object[Vrab98].Cast_DUJ = 0;}
           if(Object[Vrab98].Cast_DJA == 1){Object[Vrab98].Cast_DJA = 2;} else {Object[Vrab98].Cast_DJA = 0;} Object[Vrab98].Cast_DRA = 0; Object[Vrab98].Cast_DLA = 0; Object[Vrab98].Cast_DDA = 0; Object[Vrab98].Cast_DUA = 0;
          }
          if(Object[Vrab98].Input_A == 1)
          {
           Object[Vrab98].Press_A = (Polish ? 16 : 4); Object[Vrab98].Cast_A = (Polish ? 16 : 4); if(Object[Vrab98].Cast_J == (Polish ? 16 : 4) || Object[Vrab98].Cast_D == (Polish ? 16 : 4)) Object[Vrab98].Cast_A = 0; Object[Vrab98].Cast_D = 0; Object[Vrab98].Cast_J = 0;
           if(Object[Vrab98].Cast_DRA == 2){if(Object[Vrab98].Input_Right == 1){Object[Vrab98].Cast_DRA = 4;} else {Object[Vrab98].Cast_DRA = 3;}} else {Object[Vrab98].Cast_DRA = 0;}
           if(Object[Vrab98].Cast_DLA == 2){if(Object[Vrab98].Input_Left == 1) {Object[Vrab98].Cast_DLA = 4;} else {Object[Vrab98].Cast_DLA = 3;}} else {Object[Vrab98].Cast_DLA = 0;}
           if(Object[Vrab98].Cast_DDA == 2){if(Object[Vrab98].Input_Down == 1) {Object[Vrab98].Cast_DDA = 4;} else {Object[Vrab98].Cast_DDA = 3;}} else {Object[Vrab98].Cast_DDA = 0;}
           if(Object[Vrab98].Cast_DUA == 2){if(Object[Vrab98].Input_Up == 1)   {Object[Vrab98].Cast_DUA = 4;} else {Object[Vrab98].Cast_DUA = 3;}} else {Object[Vrab98].Cast_DUA = 0;}
           if(Object[Vrab98].Cast_DJA == 2){if(Object[Vrab98].Input_J == 1)    {Object[Vrab98].Cast_DJA = 4;} else {Object[Vrab98].Cast_DJA = 3;}} else {Object[Vrab98].Cast_DJA = 0;}
           Object[Vrab98].Cast_DRJ = 0; Object[Vrab98].Cast_DLJ = 0; Object[Vrab98].Cast_DDJ = 0; Object[Vrab98].Cast_DUJ = 0;
          }

          // Main.
          {
           int1 Vrab97 = false; int32 Vrab96 = 0;
           while(true)
           {
            if(Object[Vrab98].Shake != 0) break;

            // Transform's Return.
            if(Object[Vrab98].Return != 0 && Object[Vrab98].Cast_DJA >= 3)
            {
             int1 Vrab95 = true;
          
             if(Object[Vrab98].Y != 0) Vrab95 = false;
             if(Object[Vrab98].Hold != rinsize(-1)) if(Object[Object[Vrab98].Hold].Data->type == 2) Vrab95 = false;
             if(Object[Vrab98].Return == 2)
             while(true)
             {
              statics insize Vrab94 = Object[Vrab98].Frame; if(Vrab94 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) break;
              switch(Object[Vrab98].Data->Frame[Vrab94]->state)
              {
               case 0: case 1: case 2: case 4: break;
               case 7: if(Vrab94 == 110) break; default: Vrab95 = false; break;
              }
              break;
             }
 
             if(Vrab95)
             {
              statics insize Vrab94 = Object[Vrab98].Return_Address.size() - 1;
              Object[Vrab98].Data = Object[Vrab98].Return_Address[Vrab94]; Object[Vrab98].Return_Address.pop_back();
              if(Object[Vrab98].Trans != 0)Object[Vrab98].Trans_Address.pop_back();
              Object[Vrab98].Trans = Object[Vrab98].Return;
              if(Vrab94 == 0) Object[Vrab98].Return = 0;
              Object[Vrab98].Frame = 245; Object[Vrab98].Wait = 0; Object[Vrab98].Y_Vel = 0;
              Object[Vrab98].Cast_DJA = 0;
              Object[Vrab98].Cast_A = 0; Object[Vrab98].Cast_D = 0; Object[Vrab98].Cast_J = 0; Object[Vrab98].Press_A = 0; Object[Vrab98].Press_D = 0; Object[Vrab98].Press_J = 0; break;
             }
            }

            if(!Vrab97)
            while(true)
            {
             statics insize Vrab95 = Object[Vrab98].Frame; if(Vrab95 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab95]->Exist) break;
 
             if(!Object[Vrab98].Heavy_Hold)
             {
              {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_ja)); if(Object[Vrab98].Cast_DJA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DJA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_ja; Vrab97 = true; break;}}
              {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Uj)); if(Object[Vrab98].Cast_DUJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DUJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Uj; Vrab97 = true; break;}}
              {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Ua)); if(Object[Vrab98].Cast_DUA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DUA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Ua; Vrab97 = true; break;}}
              {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Dj)); if(Object[Vrab98].Cast_DDJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DDJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Dj; Vrab97 = true; break;}}
              {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Da)); if(Object[Vrab98].Cast_DDA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DDA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Da; Vrab97 = true; break;}}
              {
               statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Fj));
               if(Object[Vrab98].Cast_DLJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DLJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = false; Vrab97 = true; Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Fj; break;}
               if(Object[Vrab98].Cast_DRJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DRJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = true; Vrab97 = true; Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Fj; break;}
              }
              {
               statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Fa));
               if(Object[Vrab98].Cast_DLA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DLA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = false; Vrab97 = true; Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Fa; break;}
               if(Object[Vrab98].Cast_DRA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DRA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = true; Vrab97 = true; Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_Fa; break;}
              }
             }
             {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_j)); if(Object[Vrab98].Cast_J >= 1 && Vrab94 != 0){Object[Vrab98].Cast_J = 0; Object[Vrab98].Press_J = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_j; Vrab97 = true; break;}}
             {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_d)); if(Object[Vrab98].Cast_D >= 1 && Vrab94 != 0){Object[Vrab98].Cast_D = 0; Object[Vrab98].Press_D = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_d; Vrab97 = true; break;}}
             {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_a)); if(Object[Vrab98].Cast_A >= 1 && Vrab94 != 0){Object[Vrab98].Cast_A = 0; Object[Vrab98].Press_A = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Object[Vrab98].Data->Frame[Vrab95]->hit_a; Vrab97 = true; break;}}
  
             break;
            }
            if(!Vrab97 && Vrab96 == 69) break;

            if(Vrab97 && Vrab96 != 0)
            {
             if(Vrab96 == 999) Vrab96 = 0;
             statics insize Vrab95 = rinsize(Vrab96 < 0 ? -Vrab96 : Vrab96);
             statics int32 Vrab94 = Object[Vrab98].Data->Frame[Vrab95]->mp;
             int1 Vrab93 = true;
              
             switch(Object[Vrab98].Data->Frame[Vrab95]->state)
             {
              case 500: Vrab93 = Object[Vrab98].Trans; break;
														case 6901: Vrab93 = Object[Vrab98].Stamp; break;
              default: break;
             }

             if(Vrab93)
             if(Object[Vrab98].MP >= rxint64(Vrab94 % 1000))
             {
              if(Vrab94 > 0)
              {
               if(Object[Vrab98].HP > rxint64(Vrab94 / 1000) * 10)
               {
                if(Vrab96 < 0) Object[Vrab98].Facing = !Object[Vrab98].Facing;
                Object[Vrab98].Frame = Vrab95; Object[Vrab98].Wait = 0;
                Object[Vrab98].MP -= rxint64(Vrab94 % 1000);
                Object[Vrab98].HP -= rxint64(Vrab94 / 1000) * 10;
                Object[Vrab98].Cast_A = 0; Object[Vrab98].Cast_D = 0; Object[Vrab98].Cast_J = 0; Object[Vrab98].Press_A = 0; Object[Vrab98].Press_D = 0; Object[Vrab98].Press_J = 0;
                break;
               }
              } else
              {
               if(Vrab96 < 0) Object[Vrab98].Facing = !Object[Vrab98].Facing;
               Object[Vrab98].Frame = Vrab95; Object[Vrab98].Wait = 0; Object[Vrab98].MP -= rxint64(Vrab94);
               Object[Vrab98].Cast_A = 0; Object[Vrab98].Cast_D = 0; Object[Vrab98].Cast_J = 0; Object[Vrab98].Press_A = 0; Object[Vrab98].Press_D = 0; Object[Vrab98].Press_J = 0;
               break;
              }
             }
            } else
            {
             int1 Vrab95 = true; int1 Vrab94 = true;
             while(true)
             {
              statics insize Vrab93 = Object[Vrab98].Frame; if(Vrab93 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab93]->Exist) break;
              int32 Vrab92 = Object[Vrab98].Data->Frame[Vrab93]->state; int1 Vrab91 = false, Vrab90 = false, Vrab89 = false;

              // Mains.
              {
               if(Vrab94)
               {
                // Facing.
                {
                 int1 Vrab88 = false;
                 
                 switch(Vrab93){case 110: case 212: Vrab88 = true; break; default: break;}
                 switch(Vrab92){case 4: if(Object[Vrab98].Y >= 0) break; case 0: case 1: case 5: Vrab88 = true; break; default: break;}

                 if(Vrab88)
                 {
                  if(Object[Vrab98].Input_Left > 0 && Object[Vrab98].Input_Right == 0) if(Object[Vrab98].Facing)
                  {Object[Vrab98].Facing = !Object[Vrab98].Facing; if(Vrab93 == 213 || Vrab93 == 216){Object[Vrab98].Frame = 214; Object[Vrab98].Wait = 0;} if(Vrab93 == 214 || Vrab93 == 217){Object[Vrab98].Frame = 213; Object[Vrab98].Wait = 0;}}
                  if(Object[Vrab98].Input_Right > 0 && Object[Vrab98].Input_Left == 0) if(!Object[Vrab98].Facing)
                   {Object[Vrab98].Facing = !Object[Vrab98].Facing; if(Vrab93 == 213 || Vrab93 == 216){Object[Vrab98].Frame = 214; Object[Vrab98].Wait = 0;} if(Vrab93 == 214 || Vrab93 == 217){Object[Vrab98].Frame = 213; Object[Vrab98].Wait = 0;}}
                 }
                }

                // Into Running.
                {
                 if(Vrab92 == 0 || Vrab92 == 1)
                 {
                  if(Object[Vrab98].Press_RR > 0) Object[Vrab98].Press_RR -= 1;
                  if(Object[Vrab98].Press_LL > 0) Object[Vrab98].Press_LL -= 1;
                  if(Object[Vrab98].Press_LL != 0) if(Object[Vrab98].Input_Left == 1 && Object[Vrab98].Input_Right == 0){Vrab92 = 2; Object[Vrab98].Facing = false;}
                  if(Object[Vrab98].Press_RR != 0) if(Object[Vrab98].Input_Right == 1 && Object[Vrab98].Input_Left == 0){Vrab92 = 2; Object[Vrab98].Facing = true;}
                 }
                 if(Vrab92 == 0 || Vrab92 == 1 || Vrab92 == 10 || Vrab92 == 15)
                 {
                  if(Object[Vrab98].Input_Left == 1 && Object[Vrab98].Input_Right == 0){if(Object[Vrab98].Press_LL != 0){Object[Vrab98].Press_LL = 0;} else {Object[Vrab98].Press_LL = (Polish ? 40 : 10);} Object[Vrab98].Press_RR = 0;}
                  if(Object[Vrab98].Input_Right == 1 && Object[Vrab98].Input_Left == 0){if(Object[Vrab98].Press_RR != 0){Object[Vrab98].Press_RR = 0;} else {Object[Vrab98].Press_RR = (Polish ? 40 : 10);} Object[Vrab98].Press_LL = 0;}
                  if(Object[Vrab98].Input_Right >= 1 && Object[Vrab98].Input_Left >= 1){Object[Vrab98].Press_LL = 0; Object[Vrab98].Press_RR = 0;}
                 }
                 if(Vrab92 == 2){Object[Vrab98].Press_LL = 0; Object[Vrab98].Press_RR = 0;}
                }
           
                // Walking.
                {
                 if(Vrab92 == 0 || Vrab92 == 1)
                 {
                  xint64 Vrab88 = Object[Vrab98].Heavy_Hold ? Object[Vrab98].Data->heavy_walking_speed : Object[Vrab98].Data->walking_speed; xint64 Vrab87 = Object[Vrab98].Heavy_Hold ? Object[Vrab98].Data->heavy_walking_speedz : Object[Vrab98].Data->walking_speedz; int1 Vrab86 = false;

                  if(Object[Vrab98].Input_Up >= 1 && Object[Vrab98].Input_Down == 0){Vrab88 *= 0.714285185; if(Object[Vrab98].Z_Vel > -Vrab87) Object[Vrab98].Z_Vel = -Vrab87; Vrab86 = true;}
                  if(Object[Vrab98].Input_Down >= 1 && Object[Vrab98].Input_Up == 0){Vrab88 *= 0.714285185; if(Object[Vrab98].Z_Vel < Vrab87) Object[Vrab98].Z_Vel = Vrab87; Vrab86 = true;}
                  if(Object[Vrab98].Input_Left >= 1 && Object[Vrab98].Input_Right == 0){if(Object[Vrab98].X_Vel > -Vrab88) Object[Vrab98].X_Vel = -Vrab88; Vrab86 = true;}
                  if(Object[Vrab98].Input_Right >= 1 && Object[Vrab98].Input_Left == 0){if(Object[Vrab98].X_Vel < Vrab88) Object[Vrab98].X_Vel = Vrab88; Vrab86 = true;}

                  if(Vrab86)
                  {
                   Object[Vrab98].Walk_Animation += 1; if(Object[Vrab98].Walk_Animation >= Object[Vrab98].Data->walking_frame_rate * (Polish ? 4 : 1)){Object[Vrab98].Walk_Animation = 0; Object[Vrab98].Walk_Phase += 1; if(Object[Vrab98].Walk_Phase > 5) Object[Vrab98].Walk_Phase = 0;}
                   int1 Vrab85 = false; if(Object[Vrab98].Hold != rinsize(-1)) if(Object[Vrab98].Hold < Object.size()) if(Object[Object[Vrab98].Hold].Exist) Vrab85 = Object[Vrab98].Heavy_Hold;
                   Object[Vrab98].Wait = 0;
                   switch(Object[Vrab98].Walk_Phase)
                   {
                    case 1: case 5: Object[Vrab98].Frame = Vrab85 ? 13 : 6; break;
                    case 2: case 4: Object[Vrab98].Frame = Vrab85 ? 14 : 7; break;
                    case 3: Object[Vrab98].Frame = Vrab85 ? 15 : 8; break;
                    default: Object[Vrab98].Frame = Vrab85 ? 12 : 5; break;
                   }
                  }
                 }
                }
 
                // Running.
                {
                 if(Vrab92 != 2) while(true){statics insize Vrab88 = Object[Vrab98].Frame; if(Vrab88 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab88]->Exist) break; if(Object[Vrab98].Data->Frame[Vrab88]->state == 2) Vrab92 = 2; break;}
                 if(Vrab92 == 2)
                 {
                  xint64 Vrab88 = Object[Vrab98].Heavy_Hold ? Object[Vrab98].Data->heavy_running_speed : Object[Vrab98].Data->running_speed, Vrab87 = Object[Vrab98].Heavy_Hold ? Object[Vrab98].Data->heavy_running_speedz : Object[Vrab98].Data->running_speedz;

                  if(Object[Vrab98].Input_Up >= 1 && Object[Vrab98].Input_Down == 0){Vrab88 *= 0.833333333; if(Object[Vrab98].Z_Vel > -Vrab87) Object[Vrab98].Z_Vel = -Vrab87;}
                  if(Object[Vrab98].Input_Down >= 1 && Object[Vrab98].Input_Up == 0){Vrab88 *= 0.833333333; if(Object[Vrab98].Z_Vel < Vrab87) Object[Vrab98].Z_Vel = Vrab87;}

                  Object[Vrab98].Run_Animation += 1; if(Object[Vrab98].Run_Animation >= Object[Vrab98].Data->running_frame_rate * (Polish ? 4 : 1)){Object[Vrab98].Run_Animation = 0; Object[Vrab98].Run_Phase += 1; if(Object[Vrab98].Run_Phase > 3) Object[Vrab98].Run_Phase = 0;}
                  int1 Vrab86 = false; if(Object[Vrab98].Hold != rinsize(-1)) if(Object[Vrab98].Hold < Object.size()) if(Object[Object[Vrab98].Hold].Exist) Vrab86 = Object[Vrab98].Heavy_Hold;
                  Object[Vrab98].Wait = 0;
                  if(Object[Vrab98].Frame >= rinsize(Vrab86 ? 16 : 9) && Object[Vrab98].Frame <= rinsize(Vrab86 ? 18 : 11))
                  {
                   switch(Object[Vrab98].Run_Phase)
                   {
                    case 1: case 3: Object[Vrab98].Frame = Vrab86 ? 17 : 10; break;
                    case 2: Object[Vrab98].Frame = Vrab86 ? 18 : 11; break;
                    default: Object[Vrab98].Frame = Vrab86 ? 16 : 9; break;
                   }
                  } else {Object[Vrab98].Frame = Vrab86 ? 16 : 9; Object[Vrab98].Run_Animation = 0; Object[Vrab98].Run_Phase = 0;}

                  if(Object[Vrab98].Facing)
                  {Object[Vrab98].X_Vel = Vrab88; if(Object[Vrab98].Input_Left >= 1) Object[Vrab98].Frame = Vrab86 ? 19 : 218;} else
                  {Object[Vrab98].X_Vel = -Vrab88; if(Object[Vrab98].Input_Right >= 1) Object[Vrab98].Frame = Vrab86 ? 19 : 218;}
                 }
                }
               }

               Vrab94 = false;
              }

              // Base.
              {
               int1 Vrab88 = false, Vrab87 = false, Vrab86 = false, Vrab85 = false; insize Vrab84 = 0;

               while(true)
               {
                // Hold Check.
                {
                 int1 Vrab83 = false;
                 while(true)
                 {
                  statics insize Vrab82 = Object[Vrab98].Hold; if(Vrab82 == rinsize(-1)) break; if(Vrab82 >= Object.size()) break; if(!Object[Vrab82].Exist) break; if(Object[Vrab82].Held != Vrab98) break;
                  Vrab91 = true; if(Object[Object[Vrab98].Hold].Data->type == 4 && Vrab93 != 213 && Vrab93 != 216) Vrab89 = true; statics insize Vrab81 = Object[Object[Vrab98].Hold].Data->id;
                  if(Vrab81 == 122 || Vrab81 == 123) Vrab90 = true;
                  if(((Vrab81 == 120 || Vrab81 == 124 || Vrab92 == 2 || (Vrab92 == 4 && Object[Vrab98].Y < 0)) && Vrab93 != 213 && Vrab93 != 216) || Vrab90 || Object[Object[Vrab98].Hold].Data->type == 4)
                  if((Object[Vrab98].Input_Right > 0 && Object[Vrab98].Input_Left == 0 && Object[Vrab98].Facing) || (Object[Vrab98].Input_Left > 0 && Object[Vrab98].Input_Right == 0 && !Object[Vrab98].Facing)) Vrab89 = true;
                  if(!Object[Vrab98].Heavy_Hold) break; Vrab83 = true;

                  if(Vrab92 == 0 || Vrab92 == 1 || Vrab92 == 2)
                  {
                   if(Object[Vrab98].Press_A > 0){Vrab85 = true; Object[Vrab98].Press_A = 0; Vrab84 = 50; break;}
                  }

                  break;
                 } if(Vrab83) break;
                }

                if(Vrab92 == 0 || Vrab92 == 1)
                {
                 if(Object[Vrab98].Press_J > 0){Vrab85 = true; Object[Vrab98].Press_J = 0; Vrab84 = 210; break;}
                 if(Object[Vrab98].Press_D > 0){int1 Vrab83 = true; while(true){statics insize Vrab82 = Object[Vrab98].Frame3; if(Vrab82 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab82]->Exist) break; if(Object[Vrab98].Data->Frame[Vrab82]->state > 1) Vrab83 = false; break;} if(Vrab83){Vrab85 = true; Object[Vrab98].Press_D = 0; Vrab84 = 110; break;}}
                 if(Object[Vrab98].Press_A > 0){Vrab85 = true; Object[Vrab98].Press_A = 0; Vrab84 = Vrab91 ? (Vrab90 ? 55 : (Vrab89 ? 45 : (L_Random(1) == 0 ? 20 : 25))) : (Object[Vrab98].Super_Attack ? 70 : (L_Random(1) == 0 ? 60 : 65)); break;}
                }
                if(Vrab92 == 2)
                {
                 if(Object[Vrab98].Press_J > 0){Vrab85 = true; Object[Vrab98].Press_J = 0; Vrab88 = true; Vrab87 = Object[Vrab98].Facing; Vrab86 = true; break;}
                 if(Object[Vrab98].Press_D > 0){Vrab85 = true; Object[Vrab98].Press_D = 0; Vrab84 = 102; break;}
                 if(Object[Vrab98].Press_A > 0){Vrab85 = true; Object[Vrab98].Press_A = 0; Vrab84 = Vrab91 ? (Vrab90 ? 55 : (Vrab89 ? 45 : 35)) : 85; break;}
                }
                if(Vrab92 == 4 && Object[Vrab98].Y < 0)
                {
                 if(Object[Vrab98].Input_A > 0 && Vrab95){Vrab85 = true; Vrab95 = false; Vrab84 = Vrab91 ? (Vrab90 ? 52 : (Vrab89 ? 52 : 30)) : 80; break;}
                }
                if(Vrab93 == 213 || Vrab93 == 216)
                {
                 if(Object[Vrab98].Input_A > 0 && Vrab95){Vrab85 = true; Vrab95 = false; Vrab84 = Vrab91 ? (Vrab89 ? 52 : 40) : 90; break;}
                }
                if(Vrab93 == 215)
                {
                 if(Object[Vrab98].Press_J > 0){if(Object[Vrab98].Vel != 0){Vrab88 = true; Vrab87 = Object[Vrab98].Vel > 0;} if(Object[Vrab98].Input_Left > 0 && Object[Vrab98].Input_Right == 0){Vrab88 = true; Vrab87 = false; Vrab86 = true;} if(Object[Vrab98].Input_Right > 0 && Object[Vrab98].Input_Left == 0){Vrab88 = true; Vrab87 = true; Vrab86 = true;} if(!Vrab88) break; Object[Vrab98].Press_J = 0; Vrab85 = true; break;}
                 if(Object[Vrab98].Press_D > 0){Vrab85 = true; Object[Vrab98].Press_D = 0; Vrab84 = 102; break;}
                }
                break;
               }

               if(Vrab85)
               {
                while(true)
                {
                 if(Vrab88) if(Vrab86){Vrab84 = 213;} else {Vrab84 = Object[Vrab98].Facing ? (Vrab87 ? 213 : 214) : (Vrab87 ? 214 : 213);}
                 if(Vrab84 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab84]->Exist) break;
                 statics int32 Vrab83 = Object[Vrab98].Data->Frame[Vrab84]->mp; xint64 Vrab82 = 0, Vrab81 = 0, Vrab80 = 0;
                 
                 if(Vrab88)
                 {
                  Vrab82 = Vrab87 ? Object[Vrab98].Data->dash_distance : -(Object[Vrab98].Data->dash_distance);
                  Vrab81 = Object[Vrab98].Data->dash_height;
                  Vrab80 = (Object[Vrab98].Input_Up > 0 && Object[Vrab98].Input_Down == 0) ? -(Object[Vrab98].Data->dash_distancez) : ((Object[Vrab98].Input_Down > 0 && Object[Vrab98].Input_Up == 0) ? (Object[Vrab98].Data->dash_distancez) : 0);
                 }
 
                 if(Object[Vrab98].MP >= rxint64(Vrab83 % 1000))
                 {
                  if(Vrab83 > 0)
                  {
                   if(Object[Vrab98].HP > rxint64(Vrab83 / 1000) * 10){Object[Vrab98].Frame = Vrab84; Object[Vrab98].Wait = 0; Object[Vrab98].MP -= rxint64(Vrab83 % 1000); Object[Vrab98].HP -= rxint64(Vrab83 / 1000) * 10;} else {Vrab88 = false;}
                  } else
                  {
                   if(Object[Vrab98].MP >= rxint64(-Vrab83)){Object[Vrab98].Frame = Vrab84; Object[Vrab98].Wait = 0; Object[Vrab98].MP += rxint64(Vrab83);} else {Vrab88 = false;}
                  }
                 } else {Vrab88 = false;}

                 if(Vrab88)
                 {
                  Vect01.push_back({Sounds[0], Object[Vrab98].X, Object[Vrab98].Y, Object[Vrab98].Z, Object[Vrab98].D});
                  if(Vrab86) Object[Vrab98].Facing = Vrab87;
                  if(Vrab82 < 0){if(Object[Vrab98].X_Vel > Vrab82) Object[Vrab98].X_Vel = Vrab82;}
                  if(Vrab82 > 0){if(Object[Vrab98].X_Vel < Vrab82) Object[Vrab98].X_Vel = Vrab82;}
                  if(Vrab81 < 0){if(Object[Vrab98].Y_Vel > Vrab81) Object[Vrab98].Y_Vel = Vrab81;}
                  if(Vrab81 > 0){if(Object[Vrab98].Y_Vel < Vrab81) Object[Vrab98].Y_Vel = Vrab81;}
                  if(Vrab80 < 0){if(Object[Vrab98].Z_Vel > Vrab80) Object[Vrab98].Z_Vel = Vrab80;}
                  if(Vrab80 > 0){if(Object[Vrab98].Z_Vel < Vrab80) Object[Vrab98].Z_Vel = Vrab80;}
                 }

                 break;
                } continue;
               }
              }

              break;
             }
             Vrab97 = false; Vrab96 = 69; continue;
            }
            break;
           }
          }

          Object[Vrab98].Super_Attack = false; Object[Vrab98].Vel = 0;
         }

         // Position Shift.
         {
          if(Background >= Backgrounds.size()) Background = 0;
          {insize Vrab97 = (Varb0002 < 800) ? (800 - Varb0002) : 0; if(Backgrounds[Background].width < 800 - Vrab97){Backgrounds[Background].Shift = L_Rounding(rxint64(800 - Backgrounds[Background].width - Vrab97) / 2.0);} else {Backgrounds[Background].Shift = 0;}}

          statics xint64 Vrab97 = rxint64(Backgrounds[Background].Shift), Vrab96 = Vrab97 + rxint64(Backgrounds[Background].width), Vrab95 = rxint64(Backgrounds[Background].zboundary[0]), Vrab94 = rxint64(Backgrounds[Background].zboundary[1]);
          if(Object[Vrab98].Lock)
          {
           if(Object[Vrab98].X < Vrab97) Object[Vrab98].X = Vrab97; if(Object[Vrab98].X > Vrab96) Object[Vrab98].X = Vrab96;
          } else
          {
           if(Object[Vrab98].Data->type == 0){if(Object[Vrab98].X < Vrab97 - 200) Object[Vrab98].X = Vrab97 - 200; if(Object[Vrab98].X > Vrab96 + 200) Object[Vrab98].X = Vrab96 + 200;}
          }
          if(Object[Vrab98].Z < Vrab95) Object[Vrab98].Z = Vrab95; if(Object[Vrab98].Z > Vrab94) Object[Vrab98].Z = Vrab94;
         }
        }
       }
       #pragma endregion

       #pragma region Phase 3 : Hardcoded Behavour, Velocity, Move & Landing, Hardcoded State, Sound Effect, Position Shift.
       {
        insize Vrab99 = Vect02.size(); std::vector < xint64 > Vect03(Vrab99), Vect04(Vrab99), Vect05(Vrab99); while(Vrab99 != 0){Vrab99 -= 1; Vect03[Vrab99] = Object[Vect02[Vrab99]].X; Vect04[Vrab99] = Object[Vect02[Vrab99]].Y; Vect05[Vrab99] = Object[Vect02[Vrab99]].Z;} Vrab99 = Vect02.size();
        while(Vrab99 != 0)
        {
         Vrab99 -= 1; statics insize Vrab98 = Vect02[Vrab99];

         // Hardcoded Behavour.
         {
          while(true)
          {
           if(Object[Vrab98].Shake != 0) break;
           statics insize Vrab97 = Object[Vrab98].Frame; if(Vrab97 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab97]->Exist) break;
           statics int32 Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->state;

           switch(Vrab96)
           {
            case 301:
             {
              statics xint64 Vrab95 = 1.6;
              if(Object[Vrab98].Input_Up > 0 && Object[Vrab98].Input_Down == 0){if(Object[Vrab98].Z_Vel > -Vrab95) Object[Vrab98].Z_Vel = -Vrab95;}
              if(Object[Vrab98].Input_Down > 0 && Object[Vrab98].Input_Up == 0){if(Object[Vrab98].Z_Vel < Vrab95) Object[Vrab98].Z_Vel = Vrab95;}
             }
            break;
            case 19:  
             {
              statics xint64 Vrab95 = Object[Vrab98].Data->running_speedz;
              if(Object[Vrab98].Input_Up > 0 && Object[Vrab98].Input_Down == 0){if(-Vrab95 < 0){if(Object[Vrab98].Z_Vel > -Vrab95) Object[Vrab98].Z_Vel = -Vrab95;} if(-Vrab95 > 0){if(Object[Vrab98].Z_Vel < -Vrab95) Object[Vrab98].Z_Vel = -Vrab95;}}
              if(Object[Vrab98].Input_Down > 0 && Object[Vrab98].Input_Up == 0){if(Vrab95 < 0){if(Object[Vrab98].Z_Vel > Vrab95) Object[Vrab98].Z_Vel = Vrab95;}    if(Vrab95 > 0){if(Object[Vrab98].Z_Vel < Vrab95) Object[Vrab98].Z_Vel = Vrab95;}}
             }
            break;
            default: break;
           }

           if(Object[Vrab98].Data->type == 0) break;
           statics int32 Vrab95 = Object[Vrab98].Data->Frame[Vrab97]->hit_Fa;

           switch(Vrab95)
           {
            case 11:
             {
              for(insize Vrab94 = 0; Vrab94 < 6; ++Vrab94)
              {
               statics insize Vrab93 = Add(212);
               if(Vrab93 != rinsize(-1))
               {
                Object[Vrab93].Facing = Vrab94 > 2;
                Object[Vrab93].Team = Object[Vrab98].Team; Object[Vrab93].Name = Object[Vrab98].Name; Object[Vrab93].Owners = Object[Vrab98].Owners; Object[Vrab93].Owners.push_back(Vrab98); Object[Vrab93].Scale = Object[Vrab98].Scale;
                Object[Vrab93].Frame = 100; if(Object[Vrab98].Blink > 0) Object[Vrab93].Blink = Object[Vrab98].Blink;
 
                if(Object[Vrab93].Data->type == 0)
                {statics int1 Vrab92 = (Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5); Object[Vrab93].Clone = Vrab98; Object[Vrab93].MP = Vrab92 ? 100 : 500; Object[Vrab93].MMP = Vrab92 ? 100 : 500; Object[Vrab93].HP = Vrab92 ? 10 : 500; Object[Vrab93].DHP = Vrab92 ? 10 : 500; Object[Vrab93].MHP = Vrab92 ? 10 : 500;} else
                {Object[Vrab93].MP = 500; Object[Vrab93].MMP = 500; statics xint64 Vrab92 = rxint64(Object[Vrab93].Data->weapon_hp); Object[Vrab93].HP = Vrab92; Object[Vrab93].DHP = Vrab92; Object[Vrab93].MHP = Vrab92;}

                Object[Vrab93].X = Object[Vrab98].X + (Vrab94 < 3 ? -100 : 100) + ((Vrab94 % 3 == 0 || Vrab94 % 3 == 2) ? (Vrab94 < 3 ? 20 : -20) : 0);
                Object[Vrab93].Y = Object[Vrab98].Y - 3;
                Object[Vrab93].Z = Object[Vrab98].Z;
                Object[Vrab93].D = Object[Vrab98].D;
                Object[Vrab93].X_Vel = Object[Vrab98].X_Vel;
                Object[Vrab93].Y_Vel = Object[Vrab98].Y_Vel;
                Object[Vrab93].Z_Vel = Object[Vrab98].Z_Vel + (Vrab94 % 3 == 0 ? -7 : 0) + (Vrab94 % 3 == 2 ? 7 : 0);
               }
              }

              statics int1 Vrab94 = L_Random(1) == 0;
              for(insize Vrab93 = 0; Vrab93 < 6; ++Vrab93)
              {
               statics insize Vrab92 = Add(211);
               if(Vrab92 != rinsize(-1))
               {
                Object[Vrab92].Facing = (Vrab93 < 4 ? (Vrab93 >= 2) : (Vrab93 != 4)); if(Vrab94) Object[Vrab92].Facing = !Object[Vrab92].Facing;
                Object[Vrab92].Team = Object[Vrab98].Team; Object[Vrab92].Name = Object[Vrab98].Name; Object[Vrab92].Owners = Object[Vrab98].Owners; Object[Vrab92].Owners.push_back(Vrab98); Object[Vrab92].Scale = Object[Vrab98].Scale;
                Object[Vrab92].Frame = 50; if(Object[Vrab98].Blink > 0) Object[Vrab92].Blink = Object[Vrab98].Blink;
 
                if(Object[Vrab92].Data->type == 0)
                {statics int1 Vrab91 = (Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5); Object[Vrab92].Clone = Vrab98; Object[Vrab92].MP = Vrab91 ? 100 : 500; Object[Vrab92].MMP = Vrab91 ? 100 : 500; Object[Vrab92].HP = Vrab91 ? 10 : 500; Object[Vrab92].DHP = Vrab91 ? 10 : 500; Object[Vrab92].MHP = Vrab91 ? 10 : 500;} else
                {Object[Vrab92].MP = 500; Object[Vrab92].MMP = 500; statics xint64 Vrab91 = rxint64(Object[Vrab92].Data->weapon_hp); Object[Vrab92].HP = Vrab91; Object[Vrab92].DHP = Vrab91; Object[Vrab92].MHP = Vrab91;}
                
                Object[Vrab92].X = Object[Vrab98].X + (Vrab93 < 4 ? (Vrab93 % 2 == 0 ? 30 : -30) : 0);
                Object[Vrab92].Y = Object[Vrab98].Y - 1;
                Object[Vrab92].Z = Object[Vrab98].Z + (Vrab93 < 4 ? (Vrab93 < 2 ? 4 : -4) : (Vrab93 == 4 ? 9 : -9));
                Object[Vrab92].D = Object[Vrab98].D;
                Object[Vrab92].X_Vel = Object[Vrab98].X_Vel; Object[Vrab92].Y_Vel = Object[Vrab98].Y_Vel; Object[Vrab92].Z_Vel = Object[Vrab98].Z_Vel;
               }
              }
              
              statics insize Vrab93 = Add(211);
              if(Vrab93 != rinsize(-1))
              {
               Object[Vrab93].Facing = Object[Vrab98].Facing;
               Object[Vrab93].Team = Object[Vrab98].Team; Object[Vrab93].Name = Object[Vrab98].Name; Object[Vrab93].Owners = Object[Vrab98].Owners; Object[Vrab93].Owners.push_back(Vrab98); Object[Vrab93].Scale = Object[Vrab98].Scale;
               Object[Vrab93].Frame = 109; if(Object[Vrab98].Blink > 0) Object[Vrab93].Blink = Object[Vrab98].Blink;
 
               if(Object[Vrab93].Data->type == 0)
               {statics int1 Vrab92 = (Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5); Object[Vrab93].Clone = Vrab98; Object[Vrab93].MP = Vrab92 ? 100 : 500; Object[Vrab93].MMP = Vrab92 ? 100 : 500; Object[Vrab93].HP = Vrab92 ? 10 : 500; Object[Vrab93].DHP = Vrab92 ? 10 : 500; Object[Vrab93].MHP = Vrab92 ? 10 : 500;} else
               {Object[Vrab93].MP = 500; Object[Vrab93].MMP = 500; statics xint64 Vrab92 = rxint64(Object[Vrab93].Data->weapon_hp); Object[Vrab93].HP = Vrab92; Object[Vrab93].DHP = Vrab92; Object[Vrab93].MHP = Vrab92;}

               Object[Vrab93].X = Object[Vrab98].X; Object[Vrab93].Y = Object[Vrab98].Y; Object[Vrab93].Z = Object[Vrab98].Z;
               Object[Vrab93].X_Vel = Object[Vrab98].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab98].Y_Vel; Object[Vrab93].Z_Vel = Object[Vrab98].Z_Vel;
              }

              statics insize Vrab92 = Add(221);
              if(Vrab92 != rinsize(-1))
              {
               Object[Vrab92].Facing = Object[Vrab92].Facing;
               Object[Vrab92].Team = Object[Vrab98].Team; Object[Vrab92].Name = Object[Vrab98].Name; Object[Vrab92].Owners = Object[Vrab98].Owners; Object[Vrab92].Owners.push_back(Vrab98); Object[Vrab92].Scale = Object[Vrab98].Scale;
               Object[Vrab92].Frame = 81; if(Object[Vrab98].Blink > 0) Object[Vrab92].Blink = Object[Vrab98].Blink;
 
               if(Object[Vrab92].Data->type == 0)
               {statics int1 Vrab91 = (Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5); Object[Vrab92].Clone = Vrab98; Object[Vrab92].MP = Vrab91 ? 100 : 500; Object[Vrab92].MMP = Vrab91 ? 100 : 500; Object[Vrab92].HP = Vrab91 ? 10 : 500; Object[Vrab92].DHP = Vrab91 ? 10 : 500; Object[Vrab92].MHP = Vrab91 ? 10 : 500;} else
               {Object[Vrab92].MP = 500; Object[Vrab92].MMP = 500; statics xint64 Vrab91 = rxint64(Object[Vrab92].Data->weapon_hp); Object[Vrab92].HP = Vrab91; Object[Vrab92].DHP = Vrab91; Object[Vrab92].MHP = Vrab91;}
                
               Object[Vrab92].X = Object[Vrab98].X;
               Object[Vrab92].Y = Object[Vrab98].Y - 100;
               Object[Vrab92].Z = Object[Vrab98].Z;
               Object[Vrab92].D = Object[Vrab98].D;
               Object[Vrab92].X_Vel = Object[Vrab98].X_Vel; Object[Vrab92].Y_Vel = Object[Vrab98].Y_Vel; Object[Vrab92].Z_Vel = Object[Vrab98].Z_Vel;

               Vect02.insert(Vect02.begin(), Vrab92); Vrab99 += 1;
               Vect03.insert(Vect03.begin(), Object[Vrab92].X);
               Vect05.insert(Vect05.begin(), Object[Vrab92].Z);
              }

              Remove(Vrab98);
             }
            break;
            case 9: case 8: case 6: case 5: if(Object[Vrab98].Wait != 0) break;
             {
              std::vector < insize > Vect06;
              std::vector < xint64 > Vect07;
              
              // Picking Target(s).
              {
               insize Vrab94 = Vect02.size();
               while(Vrab94 != 0)
               {
                Vrab94 -= 1; statics insize Vrab93 = Vect02[Vrab94];
                if(Object[Vrab93].Blink >= 25) continue;
                if(Object[Vrab93].Hold != rinsize(-1)) continue;
                if(Object[Vrab93].Data->type != 0) continue;
                if(Vrab95 == 5){if(Object[Vrab93].Clone != rinsize(-1)) continue; if(Object[Vrab93].Team != Object[Vrab98].Team) continue;} else {if(Object[Vrab93].Team == Object[Vrab98].Team) continue;}

                insize Vrab92 = Vect06.size(); statics xint64 Vrab91 =  L_Distance(Vect03[Vrab99], Vect05[Vrab99] * 2.5, Vect03[Vrab94], Vect05[Vrab94] * 2.5);
                while(Vrab92 != 0)
                {
                 Vrab92 -= 1; if(Vect07[Vrab92] < Vrab91){Vrab92 += 1; Vect06.insert(Vect06.begin() + Vrab92, Vrab94); Vect07.insert(Vect07.begin() + Vrab92, Vrab91); break;}
                } if(Vrab92 == 0){Vect06.insert(Vect06.begin(), Vrab94); Vect07.insert(Vect07.begin(), Vrab91);}
               }
              }

              statics insize Vrab94 = Vect06.size();
              if(Vrab94 > 0)
              {
               insize Vrab93 = Vrab95 == 9 ? 4 : (Vrab95 == 8 ? 3 : 1); if(Vrab94 > Vrab93) Vrab93 = Vrab94;
               insize Vrab92 = 0; insize Vrab91 = 0;
               while(Vrab92 < 8 || (Vrab95 == 6 && Vrab92 < 10) || Vrab95 == 5 || (Vrab95 == 8 && Vrab92 < 15))
               {
                statics insize Vrab90 = Add(Vrab95 == 9 ? (L_Random(1) == 0 ? 222 : 221) : ( Vrab95 == 8 ? 225 : (Vrab95 == 6 ? 220 : 219)));
                if(Vrab90 != rinsize(-1))
                {
                 Object[Vrab90].Facing = Object[Vrab90].Facing;
                 Object[Vrab90].Team = Object[Vrab98].Team; Object[Vrab90].Name = Object[Vrab98].Name; Object[Vrab90].Owners = Object[Vrab98].Owners; Object[Vrab90].Owners.push_back(Vrab98); Object[Vrab90].Scale = Object[Vrab98].Scale;
                 Object[Vrab90].Frame = 0; if(Object[Vrab98].Blink > 0) Object[Vrab90].Blink = Object[Vrab98].Blink;
 
                 if(Object[Vrab90].Data->type == 0)
                 {statics int1 Vrab89 = (Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5); Object[Vrab90].Clone = Vrab98; Object[Vrab90].MP = Vrab89 ? 100 : 500; Object[Vrab90].MMP = Vrab89 ? 100 : 500; Object[Vrab90].HP = Vrab89 ? 10 : 500; Object[Vrab90].DHP = Vrab89 ? 10 : 500; Object[Vrab90].MHP = Vrab89 ? 10 : 500;} else
                 {Object[Vrab90].MP = 500; Object[Vrab90].MMP = 500; statics xint64 Vrab89 = rxint64(Object[Vrab90].Data->weapon_hp); Object[Vrab90].HP = Vrab89; Object[Vrab90].DHP = Vrab89; Object[Vrab90].MHP = Vrab89;}
                
                 Object[Vrab90].X = Object[Vrab98].X; Object[Vrab90].Y = Object[Vrab98].Y; Object[Vrab90].Z = Object[Vrab98].Z; Object[Vrab90].D = Object[Vrab98].D;
                 Object[Vrab90].X_Vel = Object[Vrab98].X_Vel - 7.5 + L_Random(15);
                 Object[Vrab90].Y_Vel = (Vrab95 == 5 || Vrab95 == 8) ? 0 : (-4 - rxint64(L_Random(12)));
                 Object[Vrab90].Z_Vel = Object[Vrab98].Z_Vel - 3 + L_Random(6);

                 if(Object[Vrab90].X_Vel < 0) Object[Vrab90].Facing = false;
                 if(Object[Vrab90].X_Vel > 0) Object[Vrab90].Facing = true;
                 Object[Vrab90].Target = Vect02[Vect06[Vrab91]];
                }

                Vrab92 += 1; if(Vrab92 == Vrab93) break;
                Vrab91 += 1; if(Vrab91 == Vrab94) if(Vrab95 == 5){break;} else {Vrab91 = 0;}
               }
              }

              Remove(Vrab98);
             }
            break;
            case 7:
             {
              statics insize Vrab94 = Add(Object[Vrab98].Data->id);
              if(Vrab94 != rinsize(-1))
              {
               Object[Vrab94].Facing = Object[Vrab98].Facing;
               Object[Vrab94].Team = Object[Vrab98].Team; Object[Vrab94].Name = Object[Vrab98].Name; Object[Vrab94].Owners = Object[Vrab98].Owners; Object[Vrab94].Owners.push_back(Vrab98); Object[Vrab94].Scale = Object[Vrab98].Scale;
               Object[Vrab94].Frame = 40; if(Object[Vrab98].Blink > 0) Object[Vrab94].Blink = Object[Vrab98].Blink;
               
               if(Object[Vrab94].Data->type == 0)
               {statics int1 Vrab93 = (Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5); Object[Vrab94].Clone = Vrab98; Object[Vrab94].MP = Vrab93 ? 100 : 500; Object[Vrab94].MMP = Vrab93 ? 100 : 500; Object[Vrab94].HP = Vrab93 ? 10 : 500; Object[Vrab94].DHP = Vrab93 ? 10 : 500; Object[Vrab94].MHP = Vrab93 ? 10 : 500;} else
               {Object[Vrab94].MP = 500; Object[Vrab94].MMP = 500; statics xint64 Vrab93 = rxint64(Object[Vrab94].Data->weapon_hp); Object[Vrab94].HP = Vrab93; Object[Vrab94].DHP = Vrab93; Object[Vrab94].MHP = Vrab93;}

               Object[Vrab94].X = Object[Vrab98].X; Object[Vrab94].Y = Object[Vrab98].Y; Object[Vrab94].Z = Object[Vrab98].Z; Object[Vrab94].D = Object[Vrab98].D;
               Object[Vrab94].X_Vel = 0; Object[Vrab94].Y_Vel = 0; Object[Vrab94].Z_Vel = 0;
              }
             }
            case 14: case 13: case 12: case 10: case 4: case 3: case 2: case 1:
             {
              if(Object[Vrab98].Target == rinsize(-1) && Object[Vrab98].Counter > 0)
              {
               // Picking Target(s).
               std::vector < insize > Vect06; std::vector < xint64 > Vect07;

               insize Vrab94 = Vect02.size(); while(Vrab94 != 0)
               {
                Vrab94 -= 1; statics insize Vrab93 = Vect02[Vrab94];
                if(Object[Vrab93].Blink >= 25) continue;
                if(Object[Vrab93].Hold != rinsize(-1)) continue;
                if(Object[Vrab93].Data->type != 0) continue;
                if(Vrab95 == 4){if(Object[Vrab93].Clone != rinsize(-1)) continue; if(Object[Vrab93].Team != Object[Vrab98].Team) continue;} else {if(Object[Vrab93].Team == Object[Vrab98].Team) continue;}

                statics xint64 Vrab92 = L_Distance(Vect03[Vrab99], Vect05[Vrab99] * 2.5, Vect03[Vrab94], Vect05[Vrab94] * 2.5);

                statics insize Vrab91 = Vect06.size(); insize Vrab90 = 0;
                while(Vrab90 < Vrab91){if(Vect07[Vrab90] < Vrab92) break; if(Vect07[Vrab90] > Vrab92){Vect06.clear(); Vect07.clear(); Vrab90 = Vrab91; break;} Vrab90 += 1;}
                if(Vrab90 == Vrab91){Vect06.push_back(Vrab94); Vect07.push_back(Vrab92);}
               }

               if(Vect06.size() > 0)
               Object[Vrab98].Target = Vect02[Vect06[rinsize(L_Random(Vect06.size() - 1))]];
              }
              
              xint64 Vrab94 = 40;
              xint64 Vrab93 = 0, Vrab92 = 0, Vrab91 = 0, Vrab90 = 0, Vrab89 = 0, Vrab88 = 0, Vrab87 = 0, Vrab86 = 0, Vrab85 = 0;
              
              switch(Vrab95)
              {
               case 1:
                Vrab93 = 13; Vrab90 = 0.85; Vrab92 = 1.2; Vrab89 = 1.2; Vrab91 = 2; Vrab88 = 0.3; Vrab94 = 10;
               break;
               case 2: case 12:
                if(Object[Vrab98].Counter <= 0){Vrab93 = 17; Vrab90 = 2;} else {Vrab93 = 14; Vrab90 = 0.7;} Vrab92 = 1; Vrab89 = 1; Vrab91 = 2.2; Vrab88 = 0.4;
               break;
               case 3: case 4:
                Vrab93 = 14; Vrab90 = 0.7; Vrab92 = 1; Vrab89 = 1; Vrab91 = 2.2; Vrab88 = 0.4;
               break;
               case 7:
                Vrab93 = 14; Vrab90 = 0.7; Vrab92 = 8.0; Vrab89 = 0.8; Vrab91 = 2.2; Vrab88 = 0.4; Vrab94 = -100000000;
                break;
               case 10:
                Vrab93 = 30; Vrab90 = 1.1; Vrab92 = 1.2; Vrab89 = 1.2; Vrab91 = 2; Vrab88 = 0.3; Vrab94 = 10;
               break;
               case 13: case 14:
                if(Object[Vrab98].Counter <= 0){Vrab93 = 17; Vrab90 = 2;} else {Vrab93 = 14; Vrab90 = 0.7;} Vrab92 = 0.1; Vrab89 = 0.1; Vrab91 = 1.5; Vrab88 = 0.4;
               break;
               default: break;
              }
              
              insize Vrab84 = rinsize(-1);
              while(true)
              {
               insize Vrab83 = Object[Vrab98].Target; if(Vrab83 >= Object.size()) Vrab83 = rinsize(-1); if(!Object[Vrab83].Exist) Vrab83 = rinsize(-1);
               if(Vrab83 == rinsize(-1) || Object[Vrab98].Counter <= 0){Object[Vrab98].Target = rinsize(-1); break;}
               
               if(Object[Vrab83].Blink >= 25) break;
               if(Object[Vrab83].Hold != rinsize(-1)) break;
               if(Object[Vrab83].Data->type != 0) break;
               if(Vrab95 == 4){if(Object[Vrab83].Clone != rinsize(-1)) break; if(Object[Vrab83].Team != Object[Vrab98].Team) break;} else {if(Object[Vrab83].Team == Object[Vrab98].Team) break;}

               {
                statics insize Vrab82 = Vect02.size(); insize Vrab81 = 0;
                while(Vrab81 < Vrab82){if(Vect02[Vrab81] == Vrab83){Vrab84 = Vrab81; break;} Vrab81 += 1;}
                if(Vrab81 == Vrab82) break;
               }
               break;
              }

              int1 Vrab83 = Object[Vrab98].X_Vel < 0;
              int1 Vrab82 = Object[Vrab98].X_Vel > 0;
              int1 Vrab81 = Vect04[Vrab99] >= -Vrab94 - Vrab92;
              int1 Vrab80 = Vect04[Vrab99] <= -Vrab94 + Vrab92;
              int1 Vrab79 = Object[Vrab98].Z_Vel < 0;
              int1 Vrab78 = Object[Vrab98].Z_Vel > 0;
              int1 Vrab77 = Vect04[Vrab99] < -Vrab94 && Vect04[Vrab99] > -Vrab94 + Vrab92;
              int1 Vrab76 = Vect04[Vrab99] > -Vrab94 && Vect04[Vrab99] < -Vrab94 - Vrab92;
              
              if(Vrab84 != rinsize(-1))
              {
               Vrab83 = Vect03[Vrab84] < Vect03[Vrab99];
               Vrab82 = Vect03[Vrab84] > Vect03[Vrab99];
               Vrab81 = Vect04[Vrab84] <= Vect04[Vrab99] + Vrab94 + Vrab92;
               Vrab80 = Vect04[Vrab84] >= Vect04[Vrab99] + Vrab94 - Vrab92;
               Vrab79 = Vect05[Vrab84] < Vect05[Vrab99];
               Vrab78 = Vect05[Vrab84] > Vect05[Vrab99];
               Vrab77 = Vect04[Vrab84] > Vect04[Vrab99] + Vrab94 && Vect04[Vrab84] < Vect04[Vrab99] + Vrab94 - Vrab89;
               Vrab76 = Vect04[Vrab84] < Vect04[Vrab99] + Vrab94 && Vect04[Vrab84] > Vect04[Vrab99] + Vrab94 + Vrab89;
              }
              
              if(Vrab83)
              {
               if(Object[Vrab98].X_Vel < -Vrab93) if(Object[Vrab98].X_Vel + Vrab87 > -Vrab93){Object[Vrab98].X_Vel = -Vrab93;} else {Object[Vrab98].X_Vel += Vrab87;}
               if(Object[Vrab98].X_Vel > -Vrab93) if(Object[Vrab98].X_Vel - Vrab90 < -Vrab93){Object[Vrab98].X_Vel = -Vrab93;} else {Object[Vrab98].X_Vel -= Vrab90;}
              }
              if(Vrab82)
              {
               if(Object[Vrab98].X_Vel > Vrab93) if(Object[Vrab98].X_Vel - Vrab87 < Vrab93){Object[Vrab98].X_Vel = Vrab93;} else {Object[Vrab98].X_Vel -= Vrab87;}
               if(Object[Vrab98].X_Vel < Vrab93) if(Object[Vrab98].X_Vel + Vrab90 > Vrab93){Object[Vrab98].X_Vel = Vrab93;} else {Object[Vrab98].X_Vel += Vrab90;}
              }
              if(Vrab81 || Vrab77)
              {
               if(Object[Vrab98].Y_Vel < -Vrab92) if(Object[Vrab98].Y_Vel + Vrab86 > -Vrab92){Object[Vrab98].Y_Vel = -Vrab92;} else {Object[Vrab98].Y_Vel += Vrab86;}
               if(Object[Vrab98].Y_Vel > -Vrab92) if(Object[Vrab98].Y_Vel - Vrab89 < -Vrab92){Object[Vrab98].Y_Vel = -Vrab92;} else {Object[Vrab98].Y_Vel -= Vrab89;}
              }
              if(Vrab80 || Vrab76)
              {
               if(Object[Vrab98].Y_Vel > Vrab92) if(Object[Vrab98].Y_Vel - Vrab86 < Vrab92){Object[Vrab98].Y_Vel = Vrab92;} else {Object[Vrab98].Y_Vel -= Vrab86;}
               if(Object[Vrab98].Y_Vel < Vrab92) if(Object[Vrab98].Y_Vel + Vrab89 > Vrab92){Object[Vrab98].Y_Vel = Vrab92;} else {Object[Vrab98].Y_Vel += Vrab89;}
              }
              if(Vrab79)
              {
               if(Object[Vrab98].Z_Vel < -Vrab91) if(Object[Vrab98].Z_Vel + Vrab85 > -Vrab91){Object[Vrab98].Z_Vel = -Vrab91;} else {Object[Vrab98].Z_Vel += Vrab85;}
               if(Object[Vrab98].Z_Vel > -Vrab91) if(Object[Vrab98].Z_Vel - Vrab88 < -Vrab91){Object[Vrab98].Z_Vel = -Vrab91;} else {Object[Vrab98].Z_Vel -= Vrab88;}
              }
              if(Vrab78)
              {
               if(Object[Vrab98].Z_Vel > Vrab91) if(Object[Vrab98].Z_Vel - Vrab85 < Vrab91){Object[Vrab98].Z_Vel = Vrab91;} else {Object[Vrab98].Z_Vel -= Vrab85;}
               if(Object[Vrab98].Z_Vel < Vrab91) if(Object[Vrab98].Z_Vel + Vrab88 > Vrab91){Object[Vrab98].Z_Vel = Vrab91;} else {Object[Vrab98].Z_Vel += Vrab88;}
              }
              if(Vrab77 || Vrab76) if(Object[Vrab98].Y_Vel >= -Vrab89 && Object[Vrab98].Y_Vel <= Vrab89) Object[Vrab98].Y_Vel = 0;

              switch(Vrab95)
              {
               case 4:
                if(Vrab84 != rinsize(-1))
                if(Vect03[Vrab84] <= Vect03[Vrab99] + 20 && Vect03[Vrab84] >= Vect03[Vrab99] - 20)
                if(Vect04[Vrab84] <= Vect04[Vrab99] + Vrab94 + 20 && Vect04[Vrab84] >= Vect04[Vrab99] + Vrab94 - 20)
                if(Vect05[Vrab84] <= Vect05[Vrab99] + 8 && Vect05[Vrab84] >= Vect05[Vrab99] - 8)
                {
                 Object[Vrab98].Frame = 60; Object[Vrab98].Wait = 0; Object[Vect02[Vrab84]].Heal += 25;
                 Object[Vrab98].X = Vect03[Vrab84]; Object[Vrab98].Y = Vect04[Vrab84] - Vrab94; Object[Vrab98].Z = Vect05[Vrab84]; Object[Vrab98].X_Vel = 0; Object[Vrab98].Y_Vel = 0; Object[Vrab98].Z_Vel = 0;
                }
               case 2: case 12:
                if((Vrab95 == 2 || Vrab95 == 12) && Object[Vrab98].Data->id == 215)
                {
                 if(Object[Vrab98].X_Vel <= 7 && Object[Vrab98].X_Vel >= -7)
                 {if(Object[Vrab98].Frame < 1 || Object[Vrab98].Frame > 2){Object[Vrab98].Frame = 1; Object[Vrab98].Wait = 0;}} else
                 {
                  if(Object[Vrab98].X_Vel <= 14 && Object[Vrab98].X_Vel >= -14)
                  {if(Object[Vrab98].Frame < 3 || Object[Vrab98].Frame > 4){Object[Vrab98].Frame = 3; Object[Vrab98].Wait = 0;}} else
                  {if(Object[Vrab98].Frame < 5 || Object[Vrab98].Frame > 6){Object[Vrab98].Frame = 5; Object[Vrab98].Wait = 0;}}
                 }
                }
               case 13: case 14:
                if(Vrab95 == 13 || Vrab95 == 14)
                {
                 if(Vrab95 == 13){if(Object[Vrab98].X_Vel <= 8 && Object[Vrab98].X_Vel >= -8){Object[Vrab98].Frame = 50;} else {Object[Vrab98].Frame = 0;} Object[Vrab98].Wait = 0;} else
                 {
                  if(Object[Vrab98].X_Vel <= 8 && Object[Vrab98].X_Vel >= -8)
                  {if(Object[Vrab98].Frame < 50 || Object[Vrab98].Frame > 59) Object[Vrab98].Frame = (Object[Vrab98].Frame % 10) + 50;} else
                  {if(Object[Vrab98].Frame > 9) Object[Vrab98].Frame = Object[Vrab98].Frame % 10;}
                 }
                }
               default:
                if(Object[Vrab98].X_Vel < 0) Object[Vrab98].Facing = false; if(Object[Vrab98].X_Vel > 0) Object[Vrab98].Facing = true;
               break;
              }
             }
            break;
            default: break;
           }

           break;
          }
          if(!Object[Vrab98].Exist) continue;
         }

         // Velocity.
         {
          while(true)
          {
           statics insize Vrab97 = Object[Vrab98].Frame; if(Vrab97 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab97]->Exist) break;

           if(Object[Vrab98].Data->type != 0)
           {
            xint64 Vrab96 = rxint64(Object[Vrab98].Data->Frame[Vrab97]->hit_j); if(Vrab96 == 0) Vrab96 = 50;
            if(Object[Vrab98].Affected == 0 || Object[Vrab98].Affected == 2) Object[Vrab98].Z += (Vrab96 - 50) / (Polish ? 4 : 1);
           }

           xint64 Vrab96 = rxint64(Object[Vrab98].Data->Frame[Vrab97]->dvx); if(Vrab96 <= 500) Vrab96 *= (Object[Vrab98].Facing ? 1 : -1);
           xint64 Vrab95 = rxint64(Object[Vrab98].Data->Frame[Vrab97]->dvz); if(Vrab95 <= 500) Vrab95 *= ((Object[Vrab98].Input_Down > 0 && Object[Vrab98].Input_Up == 0) ? 1 : ((Object[Vrab98].Input_Up > 0 && Object[Vrab98].Input_Down == 0) ? -1 : 0));
           statics xint64 Vrab94 = rxint64(Object[Vrab98].Data->Frame[Vrab97]->dvy);

           if(Vrab96 != 0)
           if(Vrab96 > 500){Object[Vrab98].X_Vel = Vrab96 - 550;} else
           {
            statics xint64 Vrab93 = Object[Vrab98].X_Vel;
            if(Vrab96 < 0)
            {if(Vrab93 > Vrab96) Object[Vrab98].X_Vel = Vrab96;} else
            {if(Vrab93 < Vrab96) Object[Vrab98].X_Vel = Vrab96;}
           }
           
           if(Vrab95 != 0)
           if(Vrab95 > 500){Object[Vrab98].Z_Vel = Vrab95 - 550;} else
           {
            statics xint64 Vrab93 = Object[Vrab98].Z_Vel;
            if(Vrab95 < 0)
            {if(Vrab93 > Vrab95) Object[Vrab98].Z_Vel = Vrab95;} else
            {if(Vrab93 < Vrab95) Object[Vrab98].Z_Vel = Vrab95;}
           }
           
           if(Vrab94 != 0)
           if(Vrab94 > 500){Object[Vrab98].Y_Vel = Vrab94 - 550;} else
           {Object[Vrab98].Y_Vel += Vrab94 / (Polish ? 4 : 1);}

           break;
          }
         }

         // Move & Landing.
         {
          int1 Vrab97 = false; insize Vrab96 = 219; int1 Vrab95 = false; int1 Vrab94 = false; int1 Vrab93 = false;
          while(true)
          {
           if(Object[Vrab98].Held != rinsize(-1) || Object[Vrab98].Caught != rinsize(-1)) break;
           statics uint8 Vrab92 = Object[Vrab98].Affected; Object[Vrab98].Affected = 0;
           
           if(Object[Vrab98].Shake == 0)
           {
            if(Vrab92 == 0 || Vrab92 == 3) Object[Vrab98].X += Object[Vrab98].X_Vel / (Polish ? 4 : 1); if(Object[Vrab98].X_Vel > 0) Object[Vrab98].Vel = 1; if(Object[Vrab98].X_Vel < 0) Object[Vrab98].Vel = -1;
            if(Vrab92 == 0 || Vrab92 == 2) Object[Vrab98].Z += Object[Vrab98].Z_Vel / (Polish ? 4 : 1);
            Object[Vrab98].Y += Object[Vrab98].Y_Vel / (Polish ? 4 : 1);
           }
           if(Object[Vrab98].Y_Vel == 0.0) break; 
           statics uint8 Vrab91 = Object[Vrab98].Data->type; if(Vrab91 != 3) if(Object[Vrab98].Y <= 0) break;
           Vrab97 = true;

           // Base Argument.
           {
            switch(Vrab91)
            {
             case 1: case 4: case 6: Vrab96 = 60; break;
             case 2: Vrab96 = 20; break;
             case 3: case 5: Vrab97 = false; break;
             default: break;
            }
           }

           // Specified Argument Based On Frame.
           {
            statics insize Vrab90 = Object[Vrab98].Frame;
            if(Vrab90 >= Object[Vrab98].Data->Frame.size()){if(Vrab91 == 3 && Object[Vrab98].Y <= 0) Vrab97 = false; break;}
            if(!Object[Vrab98].Data->Frame[Vrab90]->Exist){if(Vrab91 == 3 && Object[Vrab98].Y <= 0) Vrab97 = false; break;}
            if(Vrab91 == 3) if(Object[Vrab98].Data->Frame[Vrab90]->hit_Fa == 7){if(Object[Vrab98].Y <= -21){Vrab97 = false; break;}} else {if(Object[Vrab98].Y <= 0){Vrab97 = false; break;}}
            
            statics int32 Vrab89 = Object[Vrab98].Data->Frame[Vrab90]->state;
            switch(Vrab91)
            {
             case 0: case 5:
              if(Vrab89 == 100) Vrab96 = 94;
              if(Vrab89 == 6) Vrab96 = 215;
              if(Vrab90 == 212) Vrab96 = 215;
              if(Vrab89 == 12 || Vrab89 == 13 || Vrab89 == 14 || Vrab89 == 18)
              if((Vrab89 == 13 && (Object[Vrab98].Y_Vel > 17 || Object[Vrab98].X_Vel > 9 || Object[Vrab98].X_Vel < -9)) || (Vrab89 != 13 && (Object[Vrab98].Y_Vel >= 10 || Object[Vrab98].X_Vel > 9 || Object[Vrab98].X_Vel < -9)))
              {if(Vrab90 >= 186 && Vrab90 <= 191){Vrab96 = 191;} else {Vrab96 = 185;} Vrab95 = true;} else 
              {if(Vrab90 >= 186 && Vrab90 <= 191){Vrab96 = 231;} else {Vrab96 = 230;}}
             break;
             case 2:
              if(Object[Vrab98].Y_Vel > 9)
              {
               Vrab95 = true; Vrab94 = true; Vrab93 = true; Vrab96 = 0;
              }
             break;
             case 3:
              if(Object[Vrab98].Data->Frame[Vrab90]->hit_Fa == 7){Vrab97 = true; Vrab94 = true; Vrab96 = 60;}
             break;
             case 1:
              if(Object[Vrab98].Y_Vel >= 10 && Vrab89 == 1002)
              {
               Vrab95 = true; Vrab94 = true; Vrab96 = 0;
              }
             case 4: case 6:
              if(Vrab89 == 1002 && Vrab96 == 60) Vrab96 = 70;
              if(Vrab91 == 1) break;
              if(Vrab89 >= 1000 && Vrab89 <= 1004)
              if(Object[Vrab98].Y_Vel >= 9 || (Object[Vrab98].X_Vel > 11 || Object[Vrab98].X_Vel < -11))
              {
               Vrab95 = true; Vrab94 = true; Vrab96 = 0;
              }
             default:

             break;
            }
           }

           break;
          } if(Vrab97)
          {
           Object[Vrab98].Frame = Vrab96; Object[Vrab98].Y = 0; Object[Vrab98].Throw = 0; if(Vrab95 || Object[Vrab98].Data->type == 0) Object[Vrab98].Wait = 0;
           if(Vrab95)
           {
            Object[Vrab98].X_Vel *= 0.7; Object[Vrab98].Z_Vel *= 0.7;
            if(Vrab94)
            {
             Object[Vrab98].Y_Vel = -(Object[Vrab98].Y_Vel * 0.7); if(Object[Vrab98].Data->type != 1){if(Object[Vrab98].Y_Vel < (Vrab93 ? -5 : -10)) Object[Vrab98].Y_Vel = (Vrab93 ? -5 : -10);} else {Object[Vrab98].Y_Vel = -8;}
             statics insize Vrab90 = Object[Vrab98].Data->weapon_drop_sound_Index;
             if(Vrab90 != rinsize(-1)) Vect01.push_back({Vrab90, Object[Vrab98].X, Object[Vrab98].Y, Object[Vrab98].Z, Object[Vrab98].D});
            } else {Object[Vrab98].Y_Vel = -3.5; if(Object[Vrab98].X_Vel > 7) Object[Vrab98].X_Vel = 7; if(Object[Vrab98].X_Vel < -7) Object[Vrab98].X_Vel = -7;}
           } else 
           {
            Object[Vrab98].Y_Vel = 0;
            if(Object[Vrab98].Data->type == 0)
            {if(Vrab94){Object[Vrab98].X_Vel = 0; Object[Vrab98].Z_Vel = 0;} else {Object[Vrab98].X_Vel /= 3.0; Object[Vrab98].Z_Vel /= 3.0;}} else
            {if(Vrab94){Object[Vrab98].X_Vel = 0; Object[Vrab98].Z_Vel = 0; Object[Vrab98].Y = -21;} else {Object[Vrab98].X_Vel *= 0.7; Object[Vrab98].Z_Vel *= 0.7;}}
           }
          }
         }

         // Hardcoded State.
         {
          while(true)
          {
           if(!Object[Vrab98].Exist) break; if(Object[Vrab98].Shake != 0) break;
           statics insize Vrab97 = Object[Vrab98].Frame; if(Vrab97 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab97]->Exist) break;
           statics int32 Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->state;

           switch(Vrab96)
           {
            case 9999: if(Object[Vrab98].Y < 0) break;
            case 9998: Remove(Vrab98); continue;
            case 9996:
             {
              if(Object[Vrab98].Wait != 0) break;
              insize Vrab95 = 5; while(Vrab95 != 0)
              {
               Vrab95 -= 1;
               statics insize Vrab94 = Add(Vrab95 == 0 ? 218 : 217);
               if(Vrab94 == rinsize(-1)) continue;
               Object[Vrab94].Team = rinsize(-2); Object[Vrab94].Name = Object[Vrab98].Name; Object[Vrab94].Owners = Object[Vrab98].Owners; Object[Vrab94].Owners.push_back(Vrab98); Object[Vrab94].Scale = Object[Vrab98].Scale;
               Object[Vrab94].Frame = L_Random(5); if(Object[Vrab98].Blink > 0) Object[Vrab94].Blink = Object[Vrab98].Blink;

               if(Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5)
               {Object[Vrab94].HP = 10; Object[Vrab94].DHP = 10; Object[Vrab94].MHP = 10; Object[Vrab94].MP = 100; Object[Vrab94].MMP = 100; Object[Vrab94].Clone = Vrab98;} else
               {Object[Vrab94].HP = 500; Object[Vrab94].DHP = 500; Object[Vrab94].MHP = 10; Object[Vrab94].MP = 500; Object[Vrab94].MMP = 500;}
 
               Object[Vrab94].X = Object[Vrab98].X; Object[Vrab94].Y = Object[Vrab98].Y; Object[Vrab94].Z = Object[Vrab98].Z; Object[Vrab94].D = Object[Vrab98].D;
               Object[Vrab94].X_Vel = Object[Vrab98].X_Vel; Object[Vrab94].Y_Vel = Object[Vrab98].Y_Vel; Object[Vrab94].Z_Vel = Object[Vrab98].Z_Vel;

               xint64 Vrab93 = 1 + rxint64(L_Random(2)), Vrab92 = -3 - rxint64(L_Random(5)), Vrab91 = 1 + rxint64(L_Random(1)), Vrab90 = 10 + rxint64(L_Random(2)), Vrab89 = -5 - rxint64(L_Random(6)), Vrab88 = 3 + rxint64(L_Random(1));
               switch(Vrab95)
               {
                case 4: Vrab91 = -Vrab91; Vrab88 = -Vrab88; Object[Vrab94].Facing = !Object[Vrab98].Facing; break;
                case 3: Object[Vrab94].Facing = !Object[Vrab98].Facing; break;
                case 2: Vrab93 = -Vrab93; Vrab91 = -Vrab91; Vrab90 = -Vrab90; Vrab88 = -Vrab88; Object[Vrab94].Facing = Object[Vrab98].Facing; break;
                case 1: Vrab93 = -Vrab93; Vrab90 = -Vrab90; Object[Vrab94].Facing = Object[Vrab98].Facing; break;
                default: Vrab93 = 0; Vrab91 = 0; Vrab90 = -2 + rxint64(L_Random(4)); Vrab88 = -1 + rxint64(L_Random(2)); Object[Vrab94].Facing = L_Random(1) == 0; break;
               }
               Object[Vrab94].X += Object[Vrab98].Facing ? Vrab93 : -Vrab93; Object[Vrab94].Y += Vrab92; Object[Vrab94].Z += Vrab91;
               Object[Vrab94].X_Vel += Object[Vrab98].Facing ? Vrab90 : -Vrab90; Object[Vrab94].Y_Vel += Vrab89; Object[Vrab94].Z_Vel += Vrab88;
              }
             }
            break;
            case 9995:
             {
              statics insize Vrab95 = Objects.size();
              for(insize Vrab94 = 0; Vrab94 < Vrab95; ++Vrab94)
              if(Objects[Vrab94].id == 50){Object[Vrab98].Data = &Objects[Vrab94]; Object[Vrab98].Frame = 0; Object[Vrab98].Wait = 0; break;}
             }
            break;
												case 6800: if(Coloring != 0){if(L_Random(1) == 0) Coloring = 1;} else {Coloring = 1;} break;
												case 6801: if(Coloring != 0){if(L_Random(1) == 0) Coloring = 2;} else {Coloring = 2;} break;
            case 2000:
             if(Object[Vrab98].Y >= 0) Object[Vrab98].Frame = 20;
            break;
            case 2003: case 2004:
             {
              if(Object[Vrab98].Y >= 0) break;
              Object[Vrab98].Frame = 0;
             }
            break;
            case 1700:
             if(Object[Vrab98].Wait == 0) Object[Vrab98].Heal += 75;
            break;
            case 1000: case 1003: case 1004:
             {
              if(Object[Vrab98].Y >= 0 && Vrab96 != 1000) break;
              if(Object[Vrab98].Y >= 0 && Vrab96 == 1000) Object[Vrab98].Frame = 60;
              if(Vrab96 != 1000) Object[Vrab98].Frame = 0;
              switch(Object[Vrab98].Data->type)
              {
               case 4: case 6:
                if(Object[Vrab98].X_Vel >= 10 || Object[Vrab98].X_Vel <= -10)
                if(Object[Vrab98].Frame >= 0 && Object[Vrab98].Frame <= 15){Object[Vrab98].Frame += 40;} else {Object[Vrab98].Frame = 40;}
               break;
               default: break;
              }
             }
            break;
            case 501:
             {
              if(Object[Vrab98].Trans)
              {
               Object[Vrab98].Return_Address.push_back(Object[Vrab98].Data); Object[Vrab98].Return = Object[Vrab98].Trans;
               Object[Vrab98].Data = Object[Vrab98].Trans_Address[Object[Vrab98].Trans_Address.size() - 1]; Object[Vrab98].Trans = 0;
              }
              if(Object[Vrab98].Y >= 0){Object[Vrab98].Frame = 0;} else {Object[Vrab98].Frame = 212;} Object[Vrab98].Wait = 0;
             }
            break;
            case 400: case 401:
             if((Object[Vrab98].Data->Frame[Vrab97]->wait == 1 && Object[Vrab98].Wait > 0) || Object[Vrab98].Data->Frame[Vrab97]->wait != 1)
             {
              std::vector < insize > Vect06; xint64 Vrab95 = 0xFFFFFFFFFF;
              insize Vrab94 = Vect02.size();
              while(Vrab94 != 0)
              {
               Vrab94 -= 1;
               if(Object[Vect02[Vrab94]].Data->type == 0)
               if(Object[Vect02[Vrab94]].HP > 0)
               if(Vrab96 == 400 ? Object[Vrab98].Team != Object[Vect02[Vrab94]].Team : (Object[Vrab98].Team == Object[Vect02[Vrab94]].Team && Vect02[Vrab94] != Vrab98))
               {
                statics xint64 Vrab93 = L_Distance(Vect03[Vrab99], Vect05[Vrab99] * 2.5, Vect03[Vrab94], Vect05[Vrab94] * 2.5);
                if(Vrab93 <= Vrab95){if(Vrab93 < Vrab95) Vect06.clear(); Vect06.push_back(Vrab94); Vrab95 = Vrab93;}
               }
              }

              statics insize Vrab93 = Vect06.size();
              if(Vrab93 > 0)
              {
               if(Object[Vrab98].Player > 0 && Object[Vrab98].Player <= 8) Move = true;
               statics insize Vrab92 = Vect06[L_Random(Vrab93 - 1)];
               Object[Vrab98].X = Vect03[Vrab92] + (Object[Vrab98].Facing ? -120 : 120);
               Object[Vrab98].Z = Vect05[Vrab92];
              }
              Object[Vrab98].Y = 0; Object[Vrab98].X_Vel = 0; Object[Vrab98].Y_Vel = 0; Object[Vrab98].Z_Vel = 0;
             }
            break;
            case 19: case 18:
             {
              if(Vrab96 != 19)
              {
               insize Vrab95 = Object[Vrab98].Frame;
               if(Vrab95 >= 203 && Vrab95 <= 206)
               if(Object[Vrab98].Y_Vel > 0)
               {if(Vrab95 < 205 || Vrab95 > 206){Vrab95 = 205; Object[Vrab98].Wait = 0;}} else 
               {if(Vrab95 < 203 || Vrab95 > 204){Vrab95 = 203; Object[Vrab98].Wait = 0;}}
               Object[Vrab98].Frame = Vrab95;
              }
              if(L_Random(2) == 0)
              {
               statics insize Vrab95 = Add(999);
               if(Vrab95 != rinsize(-1))
               {
                Object[Vrab95].Facing = Object[Vrab98].Facing;
                Object[Vrab95].Team = Object[Vrab98].Team; Object[Vrab95].Name = Object[Vrab98].Name; Object[Vrab95].Owners = Object[Vrab98].Owners; Object[Vrab95].Owners.push_back(Vrab98); Object[Vrab95].Scale = Object[Vrab98].Scale;
                Object[Vrab95].Frame = 140; if(Object[Vrab98].Blink > 0) Object[Vrab95].Blink = Object[Vrab98].Blink;
 
                if(Object[Vrab95].Data->type == 0)
                {statics int1 Vrab94 = (Object[Vrab98].Data->id == 52 || Object[Vrab98].Data->id == 5); Object[Vrab95].Clone = Vrab98; Object[Vrab95].MP = Vrab94 ? 100 : 500; Object[Vrab95].MMP = Vrab94 ? 100 : 500; Object[Vrab95].HP = Vrab94 ? 10 : 500; Object[Vrab95].DHP = Vrab94 ? 10 : 500; Object[Vrab95].MHP = Vrab94 ? 10 : 500;} else
                {Object[Vrab95].MP = 500; Object[Vrab95].MMP = 500; statics xint64 Vrab94 = rxint64(Object[Vrab95].Data->weapon_hp); Object[Vrab95].HP = Vrab94; Object[Vrab95].DHP = Vrab94; Object[Vrab95].MHP = Vrab94;}
 
                Object[Vrab95].X = Object[Vrab98].X - 17 + rxint64(L_Random(34));
                Object[Vrab95].Y = Object[Vrab98].Y - 34 + rxint64(L_Random(34));
                Object[Vrab95].Z = Object[Vrab98].Z;
                Object[Vrab95].D = Object[Vrab98].D;
                Object[Vrab95].X_Vel = Object[Vrab98].X_Vel - 2 + rxint64(L_Random(4));
                Object[Vrab95].Y_Vel = Object[Vrab98].Y_Vel - rxint64(L_Random(4));
                Object[Vrab95].Z_Vel = Object[Vrab98].Z_Vel;
               }
              }
             }
            break;
            case 12:
             {
              insize Vrab95 = Object[Vrab98].Frame; int1 Vrab94 = Vrab95 >= 186; Vrab95 -= (Vrab94 ? 6 : 0);
              if(Vrab95 >= 180 && Vrab95 <= 184)
              {
               Object[Vrab98].Wait = 0; statics xint64 Vrab93 = Object[Vrab98].Y_Vel; int1 Vrab92 = true;
               if(Object[Vrab98].Y == 0 && Vrab93 == 0)
               {
                if(Vrab95 != 184) Vrab95 += 1; Vrab92 = false;
               }
               if(Vrab92)
               {
                if(Vrab93 <= -8) Vrab95 = 180;
                if(Vrab93 > -8) Vrab95 = 181;
                if(Vrab93 > 0) Vrab95 = 182;
                if(Vrab93 > 8) Vrab95 = 183;
               }
              }
              Object[Vrab98].Frame = Vrab95 + (Vrab94 ? 6 : 0);
             }
            break;
            case 0: case 1: case 2:
             {
              int1 Vrab95 = false; while(true){statics insize Vrab94 = Object[Vrab98].Hold; if(Vrab94 == rinsize(-1)) break; if(Vrab94 >= Object.size()) break; if(!Object[Vrab94].Exist) break; Vrab95 = Object[Vrab94].Data->type == 2; break;}
              if(Vrab95) break;
              if(Object[Vrab98].Y < 0) Object[Vrab98].Frame = 212;
             }
            default:
             if(Vrab96 >= 8000 && Vrab96 <= 8999)
             {
              insize Vrab95 = rinsize(-1); {statics insize Vrab94 = Vrab96 - 8000; statics insize Vrab93 = Objects.size(); insize Vrab92 = 0; while(Vrab92 < Vrab93){if(Objects[Vrab92].id == Vrab94){Vrab95 = Vrab92; break;} Vrab92 += 1;}}
              Object[Vrab98].Wait = 0; Object[Vrab98].Pic_Offset = 140; Object[Vrab98].Frame = Object[Vrab98].Data->Frame[Vrab97]->next;
              if(Vrab95 != rinsize(-1)) Object[Vrab98].Data = &Objects[Vrab95];
              int1 Vrab94 = true;
              while(true)
              {
               statics insize Vrab93 = Object[Vrab98].Frame; if(Vrab93 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab93]->Exist) break;
               Vrab94 = false; break;
              } if(Vrab94)
              {
               Object[Vrab98].Frame = 0;
              }
             }
            break;
           }

           break;
          }
          if(!Object[Vrab98].Exist) continue;
         }

         // Sound Effect.
         {
          while(true)
          {
           statics insize Vrab97 = Object[Vrab98].Frame; if(Vrab97 == Object[Vrab98].Frame4) break; Object[Vrab98].Frame4 = Vrab97;
           if(Vrab97 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab97]->Exist) break;
           statics insize Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->sound_Index;
           if(Vrab96 != rinsize(-1)) Vect01.push_back({Vrab96, Object[Vrab98].X, Object[Vrab98].Y, Object[Vrab98].Z, Object[Vrab98].D});
           break;
          }
         }

         // Position Shift.
         {
          if(Background >= Backgrounds.size()) Background = 0;
          {insize Vrab97 = (Varb0002 < 800) ? (800 - Varb0002) : 0; if(Backgrounds[Background].width < 800 - Vrab97){Backgrounds[Background].Shift = L_Rounding(rxint64(800 - Backgrounds[Background].width - Vrab97) / 2.0);} else {Backgrounds[Background].Shift = 0;}}

          statics xint64 Vrab97 = rxint64(Backgrounds[Background].Shift), Vrab96 = Vrab97 + rxint64(Backgrounds[Background].width), Vrab95 = rxint64(Backgrounds[Background].zboundary[0]), Vrab94 = rxint64(Backgrounds[Background].zboundary[1]);
          if(Object[Vrab98].Lock)
          {
           if(Object[Vrab98].X < Vrab97) Object[Vrab98].X = Vrab97; if(Object[Vrab98].X > Vrab96) Object[Vrab98].X = Vrab96;
          } else
          {
           if(Object[Vrab98].Data->type == 0){if(Object[Vrab98].X < Vrab97 - 200) Object[Vrab98].X = Vrab97 - 200; if(Object[Vrab98].X > Vrab96 + 200) Object[Vrab98].X = Vrab96 + 200;}
          }
          if(Object[Vrab98].Z < Vrab95) Object[Vrab98].Z = Vrab95; if(Object[Vrab98].Z > Vrab94) Object[Vrab98].Z = Vrab94;
         }
        }
        
        Vect02.clear(); Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Exist) Vect02.push_back(Vrab99);}

        // False Future.
        {
         std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Vect06;
	        struct Srct01 
		       {
		        uint64 Time = 0;
          std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > *Stamp_Object;
          std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT > *Stamp_Effect;
										std::vector < std::vector < uint32 > > *Stamp_Animation;
		       }; std::vector < Srct01 > Vect07;
         int1 Vrab98 = false;

									{
										insize Vrab97 = Vect02.size();
										while(Vrab97 != 0)
										{
											Vrab97 -= 1; statics insize Vrab96 = Vect02[Vrab97]; statics insize Vrab95 = Object[Vrab96].Frame;
											if(Vrab95 >= Object[Vrab96].Data->Frame.size()) continue; if(!Object[Vrab96].Data->Frame[Vrab95]->Exist) continue;
											if(Object[Vrab96].Data->Frame[Vrab95]->state == 6900) Vrab98 = true;
											if(Object[Vrab96].Data->Frame[Vrab95]->state == 6910) if(Object[Vrab96].Stamp) Vect07.push_back({Object[Vrab96].Stamp_Time, &Object[Vrab96].Stamp_Data, &Object[Vrab96].Stamp_Effect, &Object[Vrab96].Stamp_Animation});
										}
										
										Vrab97 = Vect07.size();
          if(Vrab97 > 0)
          {
           uint64 Vrab96 = ruint64(-1);
           std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > *Vect08;
           std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT > *Vect09;
										 std::vector < std::vector < uint32 > > *Vect10;
											while(Vrab97 != 0){Vrab97 -= 1; if(Vect07[Vrab97].Time < Vrab96){Vrab96 = Vect07[Vrab97].Time; Vect08 = Vect07[Vrab97].Stamp_Object; Vect09 = Vect07[Vrab97].Stamp_Effect; Vect10 = Vect07[Vrab97].Stamp_Animation;}}
											std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Vect11 = *Vect08;
											Effect = *Vect09; Object = Vect11; Gametime = Vrab96; Animation = *Vect10; Move = true;
          }
									}

									if(Vrab98)
         {
          Vect06 = Object;
          insize Vrab97 = Vect02.size(); 
										while(Vrab97 != 0)
          {
           Vrab97 -= 1; statics insize Vrab96 = Vect02[Vrab97]; statics insize Vrab95 = Object[Vrab96].Frame;
											if(Vrab95 >= Object[Vrab96].Data->Frame.size()) continue; if(!Object[Vrab96].Data->Frame[Vrab95]->Exist) continue;
											if(Object[Vrab96].Data->Frame[Vrab95]->state == 6900){Object[Vrab96].Stamp_Data = Vect06; Object[Vrab96].Stamp_Animation = Animation; Object[Vrab96].Stamp_Effect = Effect; Object[Vrab96].Stamp_Time = Gametime; Object[Vrab96].Stamp = true;}
          }
         }
        }
       }
       #pragma endregion

       #pragma region Phase 4 : Early Cpoint, Early Wpoint, Interact.
       {
        statics insize Vrab99 = Vect02.size();

        // Early Cpoint.
        {
         std::vector < insize > Vect03 = Vect02;
         insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
         while(Vrab97 < Vrab98)
         {
          statics insize Vrab95 = Vect03[Vrab97]; Vrab97 += 1;
          
          // Catch.
          if(Object[Vrab95].Catch != rinsize(-1))
          {
           int1 Vrab94 = true; statics insize Vrab93 = Object[Vrab95].Catch;
           while(true)
           {
            if(Vrab93 >= Vrab96) break; if(!Object[Vrab93].Exist) break; if(Object[Vrab93].Caught != Vrab95) break;
            statics insize Vrab92 = Object[Vrab95].Frame; if(Vrab92 >= Object[Vrab95].Data->Frame.size()) break; if(!Object[Vrab95].Data->Frame[Vrab92]->Exist) break;
            if(Object[Vrab95].Data->Frame[Vrab92]->cpoint.size() == 0) break; if(Object[Vrab95].Data->Frame[Vrab92]->cpoint[0].kind != 1) break;
            statics insize Vrab91 = Object[Vrab93].Frame; if(Vrab91 >= Object[Vrab93].Data->Frame.size()) break; if(!Object[Vrab93].Data->Frame[Vrab91]->Exist) break;
            if(Object[Vrab93].Data->Frame[Vrab91]->cpoint.size() == 0) break; if(Object[Vrab93].Data->Frame[Vrab91]->cpoint[0].kind != 2) break;
            Vrab94 = false;
            break;
           } if(Vrab94)
           {
            continue;
           } else
           {
            Vect03.push_back(Vrab93); Vrab98 += 1;
           }

           insize Vrab92 = 0;
           while(true)
           {
            Object[Vrab93].X = Object[Vrab95].X; Object[Vrab93].Y = Object[Vrab95].Y + 1; Object[Vrab93].Z = Object[Vrab95].Z - 1;
            Object[Vrab93].X_Vel = Object[Vrab95].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab95].Y_Vel; Object[Vrab93].Z_Vel = 0;
            Object[Vrab93].Frame = 0; Object[Vrab93].Wait = 0; Object[Vrab93].Attacking = 0; Object[Vrab93].Throw = 0;

            statics insize Vrab91 = Object[Vrab95].Frame;
            if(Object[Vrab95].Facing)
            {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->centerx;} else {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->centerx;}
            Object[Vrab93].Y -= Object[Vrab95].Data->Frame[Vrab91]->centery;

            if(Object[Vrab95].Facing)
            {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;} else {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;}
            Object[Vrab93].Y += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].y;
            if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10 == 1)
            {Object[Vrab93].Y -= 2; Object[Vrab93].Z += 2;}

            int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].vaction;
            if(Vrab90 < 0){Vrab90 = -Vrab90; Object[Vrab93].Facing = Object[Vrab95].Facing;} else {Object[Vrab93].Facing = !Object[Vrab95].Facing;}
            if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover - (Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10) == 10) Object[Vrab93].Facing = !Object[Vrab93].Facing;
            Object[Vrab93].Frame = rinsize(Vrab90); Vrab92 = rinsize(Vrab90);

            statics xint64 Vrab89 = (Object[Vrab95].Facing ? 1 : -1) * rxint64(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvx);
            statics xint64 Vrab88 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvy;
            xint64 Vrab87 = 0; if(Object[Vrab95].Input_Down > 0 && Object[Vrab95].Input_Up == 0) Vrab87 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz; if(Object[Vrab95].Input_Up > 0 && Object[Vrab95].Input_Down == 0) Vrab87 = -(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz);
            statics int32 Vrab86 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwinjury;
            if(Vrab89 != 0 || Vrab88 != 0)
            {
             Object[Vrab93].Caught = rinsize(-1); Object[Vrab93].Throw = -1;
             Object[Vrab93].X_Vel += Vrab89; Object[Vrab93].Y_Vel += Vrab88; Object[Vrab93].Z_Vel += Vrab87;
             if(Vrab86 == -1 || Vrab86 == -2 || Vrab86 == -3)
             {
              if(Vrab86 != -3){Object[Vrab95].Return_Address.push_back(Object[Vrab95].Data); Object[Vrab95].Return = ruint8(-rint8(Vrab86));}
              Object[Vrab95].Data = Object[Vrab93].Data;
              if(Vrab86 != -3){Object[Vrab95].Trans_Address.push_back(Object[Vrab93].Data); Object[Vrab95].Trans = 0;}
              Object[Vrab95].Frame = 0; Object[Vrab95].Wait = 0;
             } else {if(Vrab86 != 0) Object[Vrab93].Throw = Vrab86;}
            }

            break;
           } while(true)
           {
            if(Object[Vrab93].Throw != 0) break;
            if(Vrab92 >= Object[Vrab93].Data->Frame.size()){Object[Vrab93].Caught = rinsize(-1); break;} if(!Object[Vrab93].Data->Frame[Vrab92]->Exist){Object[Vrab93].Caught = rinsize(-1); break;}
            
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->centerx;} else {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->centerx;}
            Object[Vrab93].Y += Object[Vrab93].Data->Frame[Vrab92]->centery;
            
            if(Object[Vrab93].Data->Frame[Vrab92]->cpoint.size() == 0){Object[Vrab93].Caught = rinsize(-1); break;}
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].x;} else {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].x;}
            Object[Vrab93].Y -= Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].y;

            if(Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].kind != 2) Object[Vrab93].Caught = rinsize(-1);
            break;
           }
          }
         }
        }

        // Early Wpoint.
        {
         std::vector < insize > Vect03 = Vect02;
         insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
         while(Vrab97 < Vrab98)
         {
          statics insize Vrab95 = Vect03[Vrab97]; Vrab97 += 1;

          // Hold.
          if(Object[Vrab95].Hold != rinsize(-1))
          {
           int1 Vrab94 = true; statics insize Vrab93 = Object[Vrab95].Hold;
           while(true)
           {
            if(Vrab93 >= Vrab96) break; if(!Object[Vrab93].Exist) break; if(Object[Vrab93].Held != Vrab95) break;
            Vrab94 = false;
            break;
           } if(Vrab94)
           {
            Object[Vrab95].Hold = rinsize(-1); continue;
           } else
           {
            Vect03.push_back(Vrab93); Vrab98 += 1;
           }

           insize Vrab92 = 0;
           while(true)
           {
            Object[Vrab93].X = Object[Vrab95].X; Object[Vrab93].Y = Object[Vrab95].Y - 1; Object[Vrab93].Z = Object[Vrab95].Z + 1;
            Object[Vrab93].X_Vel = Object[Vrab95].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab95].Y_Vel; Object[Vrab93].Z_Vel = Object[Vrab95].Z_Vel;
            Object[Vrab93].Frame = 0; Object[Vrab93].Wait = 0; Object[Vrab93].Attacking = 0;

            statics insize Vrab91 = Object[Vrab95].Frame; if(Vrab91 >= Object[Vrab95].Data->Frame.size()) break; if(!Object[Vrab95].Data->Frame[Vrab91]->Exist) break;
            if(Object[Vrab95].Facing)
            {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->centerx;} else {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->centerx;}
            Object[Vrab93].Y -= Object[Vrab95].Data->Frame[Vrab91]->centery;

            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint.size() == 0) break;
            if(Object[Vrab95].Facing)
            {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].x;} else {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].x;}
            Object[Vrab93].Y += Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].y;
            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].cover % 10 == 1)
            {Object[Vrab93].Y += 2; Object[Vrab93].Z -= 2;}

            int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].weaponact;
            if(Vrab90 < 0){Vrab90 = -Vrab90; Object[Vrab93].Facing = !Object[Vrab95].Facing;} else {Object[Vrab93].Facing = Object[Vrab95].Facing;}
            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].cover - (Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].cover % 10) == 10) Object[Vrab93].Facing = !Object[Vrab93].Facing;
            Object[Vrab93].Frame = rinsize(Vrab90); Object[Vrab93].Attacking = rinsize(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].attacking);
            Vrab92 = Object[Vrab93].Frame;

            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].kind == 3)
            {
             Object[Vrab93].Frame = L_Random(15); Object[Vrab95].Heavy_Hold = false; Object[Vrab95].Hold = rinsize(-1); Object[Vrab93].Held = rinsize(-1);
             Object[Vrab93].X_Vel += -3 + rxint64(L_Random(6)); Object[Vrab93].Z_Vel += -1 + rxint64(L_Random(2)); Object[Vrab93].Y_Vel += -4 + rxint64(L_Random(4));
            } else
            {
             xint64 Vrab89 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvx; if(!Object[Vrab95].Facing) Vrab89 = -Vrab89;
             statics xint64 Vrab88 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvy; 
             xint64 Vrab87 = 0; if(Object[Vrab95].Input_Down > 0 && Object[Vrab95].Input_Up == 0) Vrab87 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvz; if(Object[Vrab95].Input_Up > 0 && Object[Vrab95].Input_Down == 0) Vrab87 = -(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvz);
             if(Vrab89 != 0 && Vrab88 != 0)
             {
              Object[Vrab93].Frame = Object[Vrab93].Data->type == 2 ? 0 : 40; Object[Vrab95].Heavy_Hold = false; Object[Vrab95].Hold = rinsize(-1); Object[Vrab93].Held = rinsize(-1);
              Object[Vrab93].X_Vel = Vrab89; Object[Vrab93].Y_Vel = Vrab88; Object[Vrab93].Z_Vel = Vrab87;
             }
            }

            break;
           } while(true)
           {
            if(Vrab92 >= Object[Vrab93].Data->Frame.size()) break; if(!Object[Vrab93].Data->Frame[Vrab92]->Exist) break;
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->centerx;} else {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->centerx;}
            Object[Vrab93].Y += Object[Vrab93].Data->Frame[Vrab92]->centery;
            
            if(Object[Vrab93].Data->Frame[Vrab92]->wpoint.size() == 0) break;
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->wpoint[0].x;} else {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->wpoint[0].x;}
            Object[Vrab93].Y -= Object[Vrab93].Data->Frame[Vrab92]->wpoint[0].y;

            break;
           }
          } else {Object[Vrab95].Heavy_Hold = false;}
         }
        }

        // Interact.
        {
         std::vector < insize > Vect03(Vrab99, rinsize(-1)); // Frame.
         std::vector < xint64 > Vect04(Vrab99);              // X.
         std::vector < xint64 > Vect05(Vrab99);              // Y.
         std::vector < xint64 > Vect06(Vrab99);              // Z.
         std::vector < insize > Vect07(Vrab99);              // D.
         std::vector < int1 > Vect08(Vrab99);                // Facing.
         
         std::vector < std::vector < std::vector < std::vector < xint64 > > > > Vect09(Vrab99); // Precalculated Hitbox(es).
         struct Srct01 {insize Vrab001 = rinsize(-1); insize Vrab002 = 0;};
         std::vector < std::vector < std::vector < Srct01 > > > Vect10(Vrab99);                 // Collision Result.

         #pragma region 0th Phase : Collision Check.
         {
          std::vector < std::vector < int1 > > Vect11(Vrab99, std::vector < int1 >(Vrab99));     // Result.
          std::vector < xint64 > Vect12(Vrab99);                                                 // Itr X.
          std::vector < xint64 > Vect13(Vrab99);                                                 // Bdy X.

          // Initializing Default Values.
          {
           for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
           {
            statics insize Vrab97 = Vect02[Vrab98];
            statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) continue; if(!Object[Vrab97].Data->Frame[Vrab96]->Exist) continue;
            Vect03[Vrab98] = Vrab96; Vect08[Vrab98] = Object[Vrab97].Facing;
            Vect04[Vrab98] = Object[Vrab97].X; Vect05[Vrab98] = Object[Vrab97].Y; Vect06[Vrab98] = Object[Vrab97].Z; Vect07[Vrab98] = Object[Vrab97].D;
            Vect12[Vrab98] = Object[Vrab97].X + (Object[Vrab97].Facing ? (Object[Vrab97].Data->Frame[Vrab96]->itr_X - Object[Vrab97].Data->Frame[Vrab96]->centerx) : (Object[Vrab97].Data->Frame[Vrab96]->centerx - Object[Vrab97].Data->Frame[Vrab96]->itr_X));
            Vect13[Vrab98] = Object[Vrab97].X + (Object[Vrab97].Facing ? (Object[Vrab97].Data->Frame[Vrab96]->bdy_X - Object[Vrab97].Data->Frame[Vrab96]->centerx) : (Object[Vrab97].Data->Frame[Vrab96]->centerx - Object[Vrab97].Data->Frame[Vrab96]->bdy_X));
           }
          }
 
          // Global Conditions Check.
          {
           for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
           {
            if(Vect03[Vrab98] == rinsize(-1)) continue;
            statics insize Vrab97 = Vect02[Vrab98];
            if(Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr.size() > 0)
            {
             statics xint64 Vrab96 = Vect12[Vrab98] - (Vect08[Vrab98] ? 0 : Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr_W);
             statics xint64 Vrab95 = Vect12[Vrab98] + (Vect08[Vrab98] ? Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr_W : 0);
             statics xint64 Vrab94 = Vect05[Vrab98] - Object[Vrab97].Data->Frame[Vect03[Vrab98]]->centery + Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr_Y;
             statics xint64 Vrab93 = Vrab94 + Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr_H;
             statics xint64 Vrab92 = Vect06[Vrab98] - (Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr_Z) + 1;
             statics xint64 Vrab91 = Vect06[Vrab98] + (Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr_Z) - 1;
             for(insize Vrab90 = 0; Vrab90 < Vrab99; ++Vrab90)
             {
              if(Vrab90 == Vrab98) continue;
              if(Vect03[Vrab90] == rinsize(-1)) continue;
              if(Vect07[Vrab98] != Vect07[Vrab90]) continue;
              statics insize Vrab89 = Vect02[Vrab90];
              statics xint64 Vrab88 = Vect05[Vrab90] - Object[Vrab89].Data->Frame[Vect03[Vrab90]]->centery + Object[Vrab89].Data->Frame[Vect03[Vrab90]]->bdy_Y;
              if(Object[Vrab89].Data->Frame[Vect03[Vrab90]]->bdy.size() > 0)
              {
               if(Vect06[Vrab90] <= Vrab91 && Vect06[Vrab90] >= Vrab92)
               if(Vrab95 >= Vect13[Vrab90] - (Vect08[Vrab90] ? 0 : Object[Vrab89].Data->Frame[Vect03[Vrab90]]->bdy_W) && Vrab96 <= Vect13[Vrab90] + (Vect08[Vrab90] ? Object[Vrab89].Data->Frame[Vect03[Vrab90]]->bdy_W : 0))
               if(Vrab93 >= Vrab88 && Vrab94 <= Vrab88 + Object[Vrab89].Data->Frame[Vect03[Vrab90]]->bdy_H)
               Vect11[Vrab98][Vrab90] = true;
              }
             }
            }
           }
           Vect12.clear(); Vect13.clear();
          }

          // Initializing Second Default Values.
          {
           for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
           {
            if(Vect03[Vrab98] == rinsize(-1)) continue; Vect09[Vrab98].resize(2);
            statics insize Vrab97 = Vect02[Vrab98]; statics insize Vrab96 = Vect03[Vrab98]; statics int1 Vrab95 = Vect08[Vrab98];
            statics xint64 Vrab94 = Vect04[Vrab98] + ((Vrab95 ? -1.0 : 1.0) * rxint64(Object[Vrab97].Data->Frame[Vrab96]->centerx));
            statics xint64 Vrab93 = Vect05[Vrab98] - Object[Vrab97].Data->Frame[Vrab96]->centery;
            statics xint64 Vrab92 = Vect06[Vrab98];
            insize Vrab91 = Object[Vrab97].Data->Frame[Vrab96]->itr.size(); Vect09[Vrab98][0].resize(Vrab91);
            while(Vrab91 != 0)
            {
             Vrab91 -= 1; Vect09[Vrab98][0][Vrab91].resize(6);
             statics xint64 Vrab90 = Vrab93 + Object[Vrab97].Data->Frame[Vrab96]->itr[Vrab91].y;
             Vect09[Vrab98][0][Vrab91][2] = Vrab90; Vect09[Vrab98][0][Vrab91][3] = Vrab90 + Object[Vrab97].Data->Frame[Vrab96]->itr[Vrab91].h;
             xint64 Vrab89 = (Object[Vrab97].Data->Frame[Vrab96]->itr[Vrab91].zwidth) - 1.0; if(Vrab89 == -1.0) Vrab89 = 14;
             Vect09[Vrab98][0][Vrab91][4] = Vrab92 - Vrab89; Vect09[Vrab98][0][Vrab91][5] = Vrab92 + Vrab89;
             if(Vrab95)
             {
              statics xint64 Vrab88 = Vrab94 + Object[Vrab97].Data->Frame[Vrab96]->itr[Vrab91].x;
              Vect09[Vrab98][0][Vrab91][0] = Vrab88; Vect09[Vrab98][0][Vrab91][1] = Vrab88 + Object[Vrab97].Data->Frame[Vrab96]->itr[Vrab91].w;
             } else
             {
              statics xint64 Vrab88 = Vrab94 - Object[Vrab97].Data->Frame[Vrab96]->itr[Vrab91].x;
              Vect09[Vrab98][0][Vrab91][1] = Vrab88; Vect09[Vrab98][0][Vrab91][0] = Vrab88 - Object[Vrab97].Data->Frame[Vrab96]->itr[Vrab91].w;
             }
            }
            Vrab91 = Object[Vrab97].Data->Frame[Vrab96]->bdy.size(); Vect09[Vrab98][1].resize(Vrab91);
            while(Vrab91 != 0)
            {
             Vrab91 -= 1; Vect09[Vrab98][1][Vrab91].resize(4);
             statics xint64 Vrab90 = Vrab93 + Object[Vrab97].Data->Frame[Vrab96]->bdy[Vrab91].y;
             Vect09[Vrab98][1][Vrab91][2] = Vrab90; Vect09[Vrab98][1][Vrab91][3] = Vrab90 + Object[Vrab97].Data->Frame[Vrab96]->bdy[Vrab91].h;
             if(Vrab95)
             {
              statics xint64 Vrab88 = Vrab94 + Object[Vrab97].Data->Frame[Vrab96]->bdy[Vrab91].x;
              Vect09[Vrab98][1][Vrab91][0] = Vrab88; Vect09[Vrab98][1][Vrab91][1] = Vrab88 + Object[Vrab97].Data->Frame[Vrab96]->bdy[Vrab91].w;
             } else
             {
              statics xint64 Vrab88 = Vrab94 - Object[Vrab97].Data->Frame[Vrab96]->bdy[Vrab91].x;
              Vect09[Vrab98][1][Vrab91][1] = Vrab88; Vect09[Vrab98][1][Vrab91][0] = Vrab88 - Object[Vrab97].Data->Frame[Vrab96]->bdy[Vrab91].w;
             }
            }
           }
          }

          // Base Conditions Check.
          {
           for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
           {
            if(Vect03[Vrab98] == rinsize(-1)) continue;
            statics insize Vrab97 = Vect02[Vrab98];
            for(insize Vrab96 = 0; Vrab96 < Vrab99; ++Vrab96)
            {
             if(!Vect11[Vrab98][Vrab96]) continue;
             statics insize Vrab95 = Vect02[Vrab96];
             statics insize Vrab94 = Vect09[Vrab98][0].size();
             for(insize Vrab93 = 0; Vrab93 < Vrab94; ++Vrab93)
             {
              // Base Conditions.
              {
               int1 Vrab92 = true;

               {
                // Base Value.
                statics insize Vrab91 = Vect03[Vrab98], Vrab90 = Vect03[Vrab96];
                statics int32  Vrab89 = Object[Vrab97].Data->Frame[Vrab91]->itr[Vrab93].kind;
                statics int32  Vrab88 = Object[Vrab97].Data->Frame[Vrab91]->state;
                statics int32  Vrab87 = Object[Vrab95].Data->Frame[Vrab90]->state;
                statics int1   Vrab86 = !((Object[Vrab97].Team != Object[Vrab95].Team) || (Object[Vrab97].Team == rinsize(-2)) || (Vrab88 == 18 && Object[Vrab97].Data->id != 211) || Vrab87 == 13 || Vrab87 == 10);
                statics insize Vrab85 = Object[Vrab97].Data->type, Vrab84 = Object[Vrab95].Data->type;
                statics insize Vrab83 = Object[Vrab97].Data->Frame[Vrab91]->itr[Vrab93].effect;
                statics insize Vrab82 = Object[Vrab97].Data->Frame[Vrab91]->itr[Vrab93].fall;
                statics int1   Vrab81 = Object[Vrab95].Blink != 0;
                statics int1   Vrab80 = Object[Vrab97].Facing == Object[Vrab95].Facing;

                switch(Vrab89)
                {
                 case 6: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
                  Vrab92 = false;
                 break;
                 case 2:
                  if(Object[Vrab97].Hold != rinsize(-1)) if(Vrab87 == 1004) Vrab92 = false;
                 case 7:
                  if(Object[Vrab97].Input_A != 1) Vrab92 = false;
                  if(Vrab87 != 1004 && Vrab87 != 2004) Vrab92 = false;
                 break;
                 case 1:
                  if(Vrab87 != 16) Vrab92 = false;
                  if(Vrab81) Vrab92 = false;
                  if(!Vrab86) if(Vrab80) Vrab92 = false;
                 break;
                 case 3:
                  if(Vrab84 != 0) Vrab92 = false;
                  if(Vrab87 == 12) if(Vrab82 < 40) Vrab92 = false;
                  if(Vrab86 || Vrab81) Vrab92 = false;
                 break;
                 case 8:
                  if(Vrab84 != 0) Vrab92 = false;
                  if(Vrab87 == 12) if(Vrab82 < 40) Vrab92 = false;
                 break;
                 case 4: if(Object[Vrab97].Throw == 0){Vrab92 = false; break;}
                 case 5: if(Vrab89 != 4 && Object[Vrab97].Attacking == 0){Vrab92 = false; break;}
                 default: // kind: 0, 4, 5, 9.
                  {
                   if(Vrab81) Vrab92 = false;
                   if(Vrab85 == 0) if(Vrab87 == 1004) Vrab92 = false;
                   if(Vrab84 == 3) if(Vrab86 && Vrab89 != 4) if(Vect08[Vrab98] == Vect08[Vrab96]) Vrab92 = false;
                   if(Vrab84 == 0)
                   {
                    if(Vrab83 == 4 || (Vrab86 && Vrab89 != 4)) Vrab92 = false;
                    if(Vrab87 == 12) if(Vrab82 <= 40) Vrab92 = false;
                   }
                  }
                 break;
                }
               }
 
               if(!Vrab92) continue;
              }

              statics insize Vrab92 = Vect09[Vrab96][1].size();
              for(insize Vrab91 = 0; Vrab91 < Vrab92; ++Vrab91)
              {
               // Specified Conditionals.
               {
                int1 Vrab90 = true;

                {
                 // Hitbox check.
                 Vrab90 = (Vect09[Vrab98][0][Vrab93][1] >= Vect09[Vrab96][1][Vrab91][0] && Vect09[Vrab98][0][Vrab93][0] <= Vect09[Vrab96][1][Vrab91][1] && Vect09[Vrab98][0][Vrab93][3] >= Vect09[Vrab96][1][Vrab91][2] && Vect09[Vrab98][0][Vrab93][2] <= Vect09[Vrab96][1][Vrab91][3] && Vect09[Vrab98][0][Vrab93][5] >= Object[Vrab95].Z && Vect09[Vrab98][0][Vrab93][4] <= Object[Vrab95].Z);
                }

                if(!Vrab90) continue;
               }
                 
               // Hit.
               {
                Vect10[Vrab98].resize(Vrab94); Vect10[Vrab98][Vrab93].push_back({Vrab96, Vrab91}); break;
               }
              }
             }
            }
           }
          }
         }
         #pragma endregion

         #pragma region 1st Phase : Arest Management.
         {
          for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
          {
           statics insize Vrab97 = Vect10[Vrab98].size(); if(Vrab97 == 0) continue; std::vector < int1 > Vect11(Vrab97);
           for(insize Vrab96 = 0; Vrab96 < Vrab97; ++Vrab96) switch(Object[Vect02[Vrab98]].Data->Frame[Vect03[Vrab98]]->itr[Vrab96].kind){case 0: case 4: case 5: case 9: Vect11[Vrab96] = (Object[Vect02[Vrab98]].Data->Frame[Vect03[Vrab98]]->itr[Vrab96].vrest == 0); break; default: Vect11[Vrab96] = false; break;}

           // Removing False Target.
           {
            std::vector < insize > Vect12;
            for(insize Vrab96 = 0; Vrab96 < Vrab97; ++Vrab96) if(Vect11[Vrab96]) for(insize Vrab95 = 0; Vrab95 < Vect10[Vrab98][Vrab96].size(); ++Vrab95){statics insize Vrab94 = Vect12.size(); insize Vrab93 = 0; while(Vrab93 < Vrab94){if(Vect10[Vrab98][Vrab96][Vrab95].Vrab001 == Vect12[Vrab93]) break; Vrab93 += 1;} if(Vrab93 == Vrab94) Vect12.push_back(Vect10[Vrab98][Vrab96][Vrab95].Vrab001);}
            
            if(Object[Vect02[Vrab98]].Arest > 0) Vect12.clear();
            xint64 Vrab96 = rxint64(0xFFFFFFFFF); insize Vrab95 = Vect12.size();
            while(Vrab95 != 0)
            {
             Vrab95 -= 1; statics insize Vrab94 = Vect12[Vrab95]; statics xint64 Vrab93 = L_Distance(Vect04[Vrab98], Vect06[Vrab98], Vect04[Vrab94], Vect06[Vrab94]);
             if(Vrab93 < Vrab96){Vrab96 = Vrab93; Vect12.resize(Vrab95 + 1);} else
             {if(Vrab93 > Vrab96) Vect12.erase(Vect12.begin() + Vrab95);}
            }
            
            for(insize Vrab94 = 0; Vrab94 < Vrab97; ++Vrab94) if(Vect11[Vrab94])
            {
             insize Vrab93 = Vect10[Vrab98][Vrab94].size(); while(Vrab93 != 0)
             {
              Vrab93 -= 1; statics insize Vrab92 = Vect12.size(); insize Vrab91 = 0;
              while(Vrab91 < Vrab92){if(Vect10[Vrab98][Vrab94][Vrab93].Vrab001 == Vect12[Vrab91]) break; Vrab91 += 1;} if(Vrab91 == Vrab92) Vect10[Vrab98][Vrab94].erase(Vect10[Vrab98][Vrab94].begin() + Vrab93);
             }
            }
           }

           // Picking Target.
           {
            std::vector < insize > Vect12; for(insize Vrab96 = 0; Vrab96 < Vrab97; ++Vrab96) if(Vect11[Vrab96]) if(Vect10[Vrab98][Vrab96].size() != 0) Vect12.push_back(Vrab96);
            insize Vrab96 = Vect12.size();
            if(Vrab96 > 0)
            {
             Vrab96 = Vect12[L_Random(Vrab96 - 1)]; Vect12.clear();

             std::vector < insize > Vect13; insize Vrab95 = Vect10[Vrab98][Vrab96].size();
             while(Vrab95 != 0){Vrab95 -= 1; Vect12.push_back(Vect10[Vrab98][Vrab96][Vrab95].Vrab001); Vect13.push_back(Vect10[Vrab98][Vrab96][Vrab95].Vrab002);}
             for(insize Vrab94 = 0; Vrab94 < Vrab97; ++Vrab94) if(Vect11[Vrab94]) Vect10[Vrab98][Vrab94].clear();

             insize Vrab94 = Vect12.size();
             if(Vrab94 > 0){Vrab94 = L_Random(Vrab94 - 1); Vect10[Vrab98][Vrab96].push_back({Vect12[Vrab94], Vect13[Vrab94]});}
            }
           }

           for(insize Vrab96 = 0; Vrab96 < Vrab97; ++Vrab96) switch(Object[Vect02[Vrab98]].Data->Frame[Vect03[Vrab98]]->itr[Vrab96].kind){case 1: case 3: case 8: case 13: Vect11[Vrab96] = (Object[Vect02[Vrab98]].Data->Frame[Vect03[Vrab98]]->itr[Vrab96].vrest == 0); break; default: Vect11[Vrab96] = false; break;}

           // Removing False Target. (Interacting ITR)
           {
            std::vector < insize > Vect12;
            for(insize Vrab96 = 0; Vrab96 < Vrab97; ++Vrab96) if(Vect11[Vrab96]) for(insize Vrab95 = 0; Vrab95 < Vect10[Vrab98][Vrab96].size(); ++Vrab95){statics insize Vrab94 = Vect12.size(); insize Vrab93 = 0; while(Vrab93 < Vrab94){if(Vect10[Vrab98][Vrab96][Vrab95].Vrab001 == Vect12[Vrab93]) break; Vrab93 += 1;} if(Vrab93 == Vrab94) Vect12.push_back(Vect10[Vrab98][Vrab96][Vrab95].Vrab001);}
            
            xint64 Vrab96 = rxint64(0xFFFFFFFFF); insize Vrab95 = Vect12.size();
            while(Vrab95 != 0)
            {
             Vrab95 -= 1; statics insize Vrab94 = Vect12[Vrab95]; statics xint64 Vrab93 = L_Distance(Vect04[Vrab98], Vect06[Vrab98], Vect04[Vrab94], Vect06[Vrab94]);
             if(Vrab93 < Vrab96){Vrab96 = Vrab93; Vect12.resize(Vrab95 + 1);} else
             {if(Vrab93 > Vrab96) Vect12.erase(Vect12.begin() + Vrab95);}
            }
            
            for(insize Vrab94 = 0; Vrab94 < Vrab97; ++Vrab94) if(Vect11[Vrab94])
            {
             insize Vrab93 = Vect10[Vrab98][Vrab94].size(); while(Vrab93 != 0)
             {
              Vrab93 -= 1; statics insize Vrab92 = Vect12.size(); insize Vrab91 = 0;
              while(Vrab91 < Vrab92){if(Vect10[Vrab98][Vrab94][Vrab93].Vrab001 == Vect12[Vrab91]) break; Vrab91 += 1;} if(Vrab91 == Vrab92) Vect10[Vrab98][Vrab94].erase(Vect10[Vrab98][Vrab94].begin() + Vrab93);
             }
            }
           }

           // Picking Target. (Interacting ITR)
           {
            std::vector < insize > Vect12; for(insize Vrab96 = 0; Vrab96 < Vrab97; ++Vrab96) if(Vect11[Vrab96]) if(Vect10[Vrab98][Vrab96].size() != 0) Vect12.push_back(Vrab96);
            insize Vrab96 = Vect12.size();
            if(Vrab96 > 0)
            {
             Vrab96 = Vect12[rinsize(L_Random(Vrab96 - 1))]; Vect12.clear();

             std::vector < insize > Vect13; insize Vrab95 = Vect10[Vrab98][Vrab96].size();
             while(Vrab95 != 0){Vrab95 -= 1; Vect12.push_back(Vect10[Vrab98][Vrab96][Vrab95].Vrab001); Vect13.push_back(Vect10[Vrab98][Vrab96][Vrab95].Vrab002);}
             for(insize Vrab94 = 0; Vrab94 < Vrab97; ++Vrab94) if(Vect11[Vrab94]) Vect10[Vrab98][Vrab94].clear();
             
             insize Vrab94 = Vect12.size();
             if(Vrab94 > 0){Vrab94 = L_Random(Vrab94 - 1); Vect10[Vrab98][Vrab96].push_back({Vect12[Vrab94], Vect13[Vrab94]});}
            }
           }
          }
         }
         #pragma endregion

         // 2nd Phase : Early Interacts. (An object that being reflected will have his entire ITR disabled in this Frame. Criminal's release included here.)
         {
          std::vector < uint8 > Vect11(Vrab99, 0); std::vector < std::vector < insize > > Vect12(Vrab99);

          /*/
          {
           insize Vrab98 = Vrab99;
           while(Vrab98 != 0)
           {
            Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98]; statics insize Vrab96 = Vect10[Vrab98].size(); insize Vrab95 = 0;
            while(Vrab95 < Vrab96)
            {
             statics insize Vrab94 = Vrab95; Vrab95 += 1;
             statics int32 Vrab93 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].kind;
             switch(Vrab93)
             {
              case 14: case 15: case 16:
              case 1: case 2: case 3: case 7: case 8: case 13: continue; 
              default: break;
             }

             int32 Vrab92 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].arest; if(Vrab92 == 0) Vrab92 = 4; if(Vrab92 < 0) Vrab92 = 0;
             int32 Vrab91 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].vrest; if(Vrab91 < 0) Vrab91 = 0; if(Vrab91 == 0) if(Object[Vrab97].Arest != 0) continue;

             insize Vrab90 = Vect10[Vrab98][Vrab94].size();
             while(Vrab90 != 0)
             {
              Vrab90 -= 1; statics insize Vrab89 = Vect10[Vrab98][Vrab94][Vrab90].Vrab001; statics insize Vrab88 = Vect02[Vrab89];
              if(Object[Vrab88].Data->type == 0) continue;
              if(Vrab91 != 0){statics insize Vrab87 = Object[Vrab88].Vrest.size(); if(Vrab87 <= Vrab97) Object[Vrab88].Vrest.resize(Vrab97 + 1); if(Object[Vrab88].Vrest[Vrab97] != 0) continue; Object[Vrab88].Vrest[Vrab97] = ruint16(Vrab91);}
              Object[Vrab97].Arest = ruint16(Vrab92);
              if(Object[Vrab88].Shake <= 1){Object[Vrab88].X_Accel = 0; Object[Vrab88].Y_Accel = 0; Object[Vrab88].Z_Accel = 0;} Object[Vrab88].Shake = 3; if(Object[Vrab97].Shake <= 0){Object[Vrab97].Shake = -3;} else {Object[Vrab97].Shake = 3;}

              {
               statics int32 Vrab87 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].fall;
               int32 Vrab86 = -Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].dvx; if(Object[Vrab97].Data->type == 2){if(Vect04[Vrab98] - Vect04[Vrab89] < 0) Vrab86 = -Vrab86; if(Vect04[Vrab98] - Vect04[Vrab89] == 0) Vrab86 = 0;} else {if(Vect08[Vrab98]) Vrab86 = -Vrab86;}
               statics int32 Vrab85 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].dvy;
               switch(Object[Vrab88].Data->type)
               {
                case 3: break;
                default:
                 if(Vrab87 >= 40)
                 {
                  if(Object[Vrab88].Data->type == 2)
                  {Object[Vrab88].Frame = 21; Object[Vrab88].X_Accel += rxint64(Vrab86) * 0.3; Object[Vrab88].Y_Accel += rxint64(Vrab85) * 0.3;} else
                  {Object[Vrab88].Frame = rinsize(L_Random(5)); Object[Vrab88].X_Accel += rxint64(Vrab86); Object[Vrab88].Y_Accel += rxint64(Vrab85);}
                 } else
                 {
                  if(Object[Vrab88].Data->type != 2)
                  {Object[Vrab88].Frame = 70; Object[Vrab88].X_Accel += rxint64(Vrab86);}
                 }
                break;
               }
              }

              statics insize Vrab87 = Vect10[Vrab98][Vrab94][Vrab90].Vrab002;
              statics xint64 Vrab86 = Vect06[Vrab98] > Vect06[Vrab89] ? Vect06[Vrab98] : Vect06[Vrab89];
              xint64 Vrab85; if(Vect09[Vrab98][0][Vrab94][0] - Vect09[Vrab89][1][Vrab87][0] < 0){Vrab85 = Vect09[Vrab89][1][Vrab87][0];} else {Vrab85 = Vect09[Vrab98][0][Vrab94][0];}
              xint64 Vrab84; if(Vect09[Vrab98][0][Vrab94][1] - Vect09[Vrab89][1][Vrab87][1] > 0){Vrab84 = Vect09[Vrab89][1][Vrab87][1];} else {Vrab84 = Vect09[Vrab98][0][Vrab94][1];}
              xint64 Vrab83; if(Vect09[Vrab98][0][Vrab94][2] - Vect09[Vrab89][1][Vrab87][2] < 0){Vrab83 = Vect09[Vrab89][1][Vrab87][2];} else {Vrab83 = Vect09[Vrab98][0][Vrab94][2];}
              xint64 Vrab82; if(Vect09[Vrab98][0][Vrab94][3] - Vect09[Vrab89][1][Vrab87][3] > 0){Vrab82 = Vect09[Vrab89][1][Vrab87][3];} else {Vrab82 = Vect09[Vrab98][0][Vrab94][3];}
              Spark(0, ((Vrab85 + Vrab84) / 2) - 10 + L_Random(20), ((Vrab83 + Vrab82) / 2) - 10 + L_Random(20) - (Vrab86 - Vect06[Vrab89]), Vrab86);
             }
            }
           }
          }*/

          for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98) if(Vect11[Vrab98]){Vect10[Vrab98].clear(); }
         }

         /*/ 4th Phase : Main Interacts.
         {
          std::vector < uint8 > Vect11(Vrab99);  // Hit.
          std::vector < int1 > Vect12(Vrab99);   // On Hit.
          std::vector < int32 > Vect13(Vrab99);  // Fall.
          std::vector < xint64 > Vect14(Vrab99); // X-Vel.
          std::vector < xint64 > Vect15(Vrab99); // Y-Vel.
          std::vector < xint64 > Vect16(Vrab99); // Z-Vel.

          insize Vrab98 = Vrab99;
          while(Vrab98 != 0){Vrab98 -= 1; Vect13[Vrab98] = Object[Vect02[Vrab98]].Fall;} Vrab98 = Vrab99;
          while(Vrab98 != 0)
          {
           Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98]; statics insize Vrab96 = Vect10[Vrab98].size(); insize Vrab95 = 0;
           
           // Vrest-type Interact.
           while(Vrab95 < Vrab96)
           {
            statics insize Vrab94 = Vrab95; Vrab95 += 1;
            if(Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].effect == 4) continue;
            statics int32 Vrab93 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab94].kind;
            switch(Vrab93)
            {
             case 1: case 2: case 3: case 7: case 8: case 13: continue; 
             default: break;
            }
            insize Vrab92 = Vect10[Vrab98][Vrab94].size();
            while(Vrab92 != 0)
            {
             Vrab92 -= 1; statics insize Vrab91 = Vect10[Vrab98][Vrab94][Vrab92].Vrab001; statics insize Vrab90 = Vect02[Vrab91]; int1 Vrab89 = false;
             switch(Vrab93)
             {
              case 14:
               {
                statics xint64 Vrab88 = Vect04[Vrab98] - Vect04[Vrab91];
                if((Vrab88 >= 0 && Object[Vrab90].X_Vel > 0) || (Vrab88 <= 0 && Object[Vrab90].X_Vel < 0)) if(Object[Vrab90].Affected != 1) if(Object[Vrab90].Affected == 3){Object[Vrab90].Affected = 1;} else {Object[Vrab90].Affected = 2;}
                statics xint64 Vrab87 = Vect06[Vrab98] - Vect06[Vrab91];
                if((Vrab87 >= 0 && Object[Vrab90].Z_Vel > 0) || (Vrab87 <= 0 && Object[Vrab90].Z_Vel < 0)) if(Object[Vrab90].Affected != 1) if(Object[Vrab90].Affected == 2){Object[Vrab90].Affected = 1;} else {Object[Vrab90].Affected = 3;} 
               }
              break;
              case 16:
               {
                statics uint8 Vrab88 = Object[Vrab90].Data->type;
                if(Vrab88 == 0 || Vrab88 == 3 || Vrab88 == 5)
                {
                 if(Vrab88 == 3) break;

                 break;
                }
               }
              case 15:
               {
                if(Object[Vrab90].Data->id == 201 || Object[Vrab90].Data->id == 202) break;
                Object[Vrab90].Float = true;
                statics xint64 Vrab88 = Vect04[Vrab98] - Vect04[Vrab91];
                if(Vrab88 > 0 || (Vrab88 == 0 && Vect08[Vrab91])) Vect14[Vrab91] += 1;
                if(Vrab88 < 0 || (Vrab88 == 0 && !Vect08[Vrab91])) Vect14[Vrab91] -= 1;
                statics xint64 Vrab87 = Vect06[Vrab98] - Vect06[Vrab91];
                if(Vrab87 < 0 || (Vrab87 == 0 && L_Random(1) == 0)){Vect16[Vrab91] -= 0.5; break;}
                if(Vrab87 >= 0) Vect16[Vrab91] += 0.5;
               }
              break;
              default: break;
             } if(Vrab89)
             {
              statics insize Vrab88 = Vect10[Vrab98][Vrab94][Vrab92].Vrab002;
              statics xint64 Vrab87 = Vect06[Vrab98] > Vect06[Vrab91] ? Vect06[Vrab98] : Vect06[Vrab91];
              Spark(0, ((Vect09[Vrab98][0][Vrab94][0] + Vect09[Vrab98][0][Vrab94][1] + Vect09[Vrab91][1][Vrab88][0] + Vect09[Vrab91][1][Vrab88][1]) / 4) - 10 + L_Random(20), ((Vect09[Vrab98][0][Vrab94][2] + Vect09[Vrab98][0][Vrab94][3] + Vect09[Vrab91][1][Vrab88][2] + Vect09[Vrab91][1][Vrab88][3]) / 4) - 10 + L_Random(20) - (Vrab87 - ((Vect06[Vrab98] + Vect06[Vrab91]) / 2)), Vrab87);
             }
            }
           } Vrab95 = 0;

           // Arest-type Interact.
           while(Vrab95 < Vrab96)
           {
           
           }
          } Vrab98 = 0;
          while(Vrab98 != 0)
          {
           Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98];
           Object[Vrab97].X_Accel += Vect14[Vrab98]; Object[Vrab97].Y_Accel += Vect15[Vrab98]; Object[Vrab97].Z_Accel += Vect16[Vrab98];
           if(Vect11[Vrab98] != 0)
           {
            Object[Vrab97].Shake = 3;
            switch(Object[Vrab97].Data->type)
            {
             case 0:

             break;
             case 2: Object[Vrab97].Frame = L_Random(21); Object[Vrab97].Wait = 0; break;
             case 3:

             break;
             default: Object[Vrab97].Frame = L_Random(70); Object[Vrab97].Wait = 0; break;
            }
           }
           if(Object[Vrab97].Shake == 0)
           {Object[Vrab97].X_Vel += Object[Vrab97].X_Accel; Object[Vrab97].Y_Vel += Object[Vrab97].Y_Accel; Object[Vrab97].Z_Vel += Object[Vrab97].Z_Accel; Object[Vrab97].X_Accel = 0; Object[Vrab97].Y_Accel = 0; Object[Vrab97].Z_Accel = 0;} else
           {Object[Vrab97].X_Vel = Object[Vrab97].X_Accel; Object[Vrab97].Y_Vel = Object[Vrab97].Y_Accel; Object[Vrab97].Z_Vel = Object[Vrab97].Z_Accel;}
          }

         }*/

         #pragma region 3rd Phase : Side Interacts. (An ITR that interact by applying specified effect.)
         {
          struct Srct02
          {
           std::vector < uint16 > Heal_Ratio;
           std::vector < uint16 > Damage_Taken;
           std::vector < uint16 > Damage_Dealt;
          }; std::vector < Srct02 > Vect11(Vrab99);

          //
          {
           insize Vrab98 = Vrab99;
           while(Vrab98 != 0)
           {
            Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98]; int1 Vrab96[2] = {false, false};
            statics insize Vrab95 = Vect10[Vrab98].size(); insize Vrab94 = 0;
            while(Vrab94 < Vrab95)
            {
             statics insize Vrab93 = Vrab94; Vrab94 += 1;
             statics int32 Vrab92 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].kind;
             switch(Vrab92)
             {
              case 1: case 2: case 3: case 7: case 8: case 13: break;
              default: continue;
             }

             // Applying Effect.
             {
              insize Vrab87 = Vect10[Vrab98][Vrab93].size();
              while(Vrab87 != 0)
              {
               Vrab87 -= 1; statics insize Vrab86 = Vect10[Vrab98][Vrab93][Vrab87].Vrab001; statics insize Vrab85 = Vect02[Vrab86]; uint8 Vrab84 = 2ui8;
               switch(Vrab92)
               {
                case 8:
                 {
                  int32 Vrab83 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].injury;
                  if(Vrab83 < -1000) Vrab83 = -1000;
                  if(Vrab83 < 0) Vect11[Vrab86].Heal_Ratio.push_back(ruint16(-Vrab83));
                 }
                break;
                default:  break;
               }
              }
             }
            }
           }
          }

          for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
          {
           statics insize Vrab97 = Vect02[Vrab98];
           xint64 Vrab96 = 1, Vrab95 = 1, Vrab94 = 1;

           insize Vrab93 = Vect11[Vrab98].Heal_Ratio.size();
           while(Vrab93 != 0){Vrab93 -= 1; Vrab96 *= rxint64(Vect11[Vrab98].Heal_Ratio[Vrab93]) / 1000.0;}
           Vrab93 = Vect11[Vrab98].Damage_Dealt.size();
           while(Vrab93 != 0){Vrab93 -= 1; Vrab96 *= rxint64(Vect11[Vrab98].Damage_Dealt[Vrab93]) / 1000.0;}
           Vrab93 = Vect11[Vrab98].Damage_Taken.size();
           while(Vrab93 != 0){Vrab93 -= 1; Vrab96 *= rxint64(Vect11[Vrab98].Damage_Taken[Vrab93]) / 1000.0;}

           Object[Vrab97].Heal_Ratio = ruint16(L_Rounding(Vrab96 * 1000) % 60000);
           Object[Vrab97].Damage_Dealt = ruint16(L_Rounding(Vrab95 * 1000) % 60000);
           Object[Vrab97].Damage_Taken = ruint16(L_Rounding(Vrab94 * 1000) % 60000);
          }
         }
         #pragma endregion
         
         #pragma region 4th Phase : Main Interacts. (An ITR that interact with Type0.)
         {
          struct Srct02
          {
           xint64 Damage = 0;
           insize Dealer = rinsize(-1);
           int32  Fall;
           int32  BDefend;
           int1   Facing;
           int32  Arest;
           int32  Vrest;
           int32  DVX;
           int32  DVY;
          };
          struct Srct03
          {
           xint64 Healing = 0.0;
           std::vector < int32 > Fall;

           uint8 Hit_Effect = 0;
           std::vector < Srct02 > Ice_Conditional;
           std::vector < Srct02 > Fire_Conditional;

           std::vector < insize > Hit;
          }; std::vector < Srct03 > Vect11(Vrab99);

          //
          {
           insize Vrab98 = Vrab99;
           while(Vrab98 != 0)
           {
            Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98]; 
            statics insize Vrab95 = Vect10[Vrab98].size(); insize Vrab94 = 0;
            while(Vrab94 < Vrab95)
            {
             statics insize Vrab93 = Vrab94; Vrab94 += 1;
             statics int32 Vrab92 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].kind;
             switch(Vrab92)
             {
              case 1: case 2: case 3: case 7: case 8: case 12: case 13: continue;
              default: break;
             }

             int32 Vrab91 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].dvx;
             int32 Vrab90 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].dvy;
             int32 Vrab89 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].fall;
             int32 Vrab88 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].bdefend;
             int32 Vrab87 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].effect;
             int32 Vrab86 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].arest;
             int32 Vrab85 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].vrest;
             int32 Vrab84 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].injury;

             if(Vrab92 == 5) while(true)
             {
              statics insize Vrab83 = Object[Vrab97].Attacking - 1;
              if(Vrab83 >= Object[Vrab97].Data->Strength.size()) break;

              Vrab91 = Object[Vrab97].Data->Strength[Vrab83].dvx;
              Vrab90 = Object[Vrab97].Data->Strength[Vrab83].dvy;
              Vrab89 = Object[Vrab97].Data->Strength[Vrab83].fall;
              Vrab88 = Object[Vrab97].Data->Strength[Vrab83].bdefend;
              Vrab87 = Object[Vrab97].Data->Strength[Vrab83].effect;
              Vrab86 = Object[Vrab97].Data->Strength[Vrab83].arest;
              Vrab85 = Object[Vrab97].Data->Strength[Vrab83].vrest;
              Vrab84 = Object[Vrab97].Data->Strength[Vrab83].injury;

              break;
             }
             
             insize Vrab83 = Vect10[Vrab98][Vrab93].size();
             while(Vrab83 != 0)
             {
              Vrab83 -= 1; statics insize Vrab82 = Vect10[Vrab98][Vrab93][Vrab83].Vrab001; statics insize Vrab81 = Vect02[Vrab82];
              int1 Vrab80 = false;

              switch(Vrab92)
              {
			   case 1: case 2: case 3: case 6: case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 16: break;
               default: // kind: 0, 4, 5, 9.
                if(Object[Vrab81].Data->type != 0 || Vrab87 == 4) continue;
                if(Vrab86 != 0 || (Vrab86 == 0 && Vrab85 == 0)) if(Object[Vrab97].Arest > 0) continue;
                if(Vrab85 != 0) if(Object[Vrab81].Vrest.size() > Vrab97) if(Object[Vrab81].Vrest[Vrab97] > 0) continue;
                Vrab80 = Vrab87 != 5;

                // Attacker's Respond.
                {
                 if(Object[Vrab97].Shake <= 0){Object[Vrab97].Shake = -4;} else {Object[Vrab97].Shake = 4;}
                 if(Object[Vrab97].Data->Frame[Vect03[Vrab98]]->state == 3000){Object[Vrab97].Frame = 10; Object[Vrab97].Wait = 0; Object[Vrab97].X_Vel = 0; Object[Vrab97].Y_Vel = 0; Object[Vrab97].Z_Vel = 0;}
                 if(Vrab92 == 9 || Object[Vrab97].Data->id == 214) Object[Vrab97].Counter = 0;
                 switch(Object[Vrab97].Data->type){case 1: case 4: case 6: Object[Vrab97].Frame = 0; Object[Vrab97].Wait = 0; Object[Vrab97].X_Vel = Object[Vrab97].Facing ? -4 : 4; Object[Vrab97].Y_Vel = -2; break; default: break;}
                }

                // Victim's Respond.
                {
                 Object[Vrab81].Shake = 4; Vect11[Vrab82].Hit.push_back(Vrab97);
                 statics xint64 Vrab79 = rxint64(Vrab84) * (rxint64(Object[Vrab97].Damage_Dealt) / 1000.0) * (rxint64(Object[Vrab81].Damage_Taken) / 1000.0) * (Object[Vrab81].Fall < 0 ? 0.5 : 1.0);
               
				 switch (Vrab87)
				 {
				  case 20: case 21: case 30: break;
                  /* Vect11[Vrab82].Fire_Conditional.push_back({Vrab79, Vrab97, Vrab89, Vrab88});
                   if(Vect11[Vrab82].Fire_Conditional_Facing != 3)
                   Vect11[Vrab82].Fire_Conditional_Facing = Vect08[Vrab98] ? (Vect11[Vrab82].Fire_Conditional_Facing == 2 ? 3 : 1) : (Vect11[Vrab82].Fire_Conditional_Facing == 1 ? 3 : 2);
                  break;
                  case 30:
                   Vect11[Vrab82].Ice_Conditional.push_back({Vrab79, Vrab97, Vrab89, Vrab88});
                   if(Vect11[Vrab82].Ice_Conditional_Facing != 3)
                   Vect11[Vrab82].Ice_Conditional_Facing = Vect08[Vrab98] ? (Vect11[Vrab82].Ice_Conditional_Facing == 2 ? 3 : 1) : (Vect11[Vrab82].Ice_Conditional_Facing == 1 ? 3 : 2);
                  break;*/
                  default:
                   if(Vrab84 < 0)
                   {Object[Vrab81].DHP -= (rxint64(Vrab84) / 4.0) * (rxint64(Object[Vrab81].Heal_Ratio) / 1000.0); Vect11[Vrab82].Healing += rxint64(Vrab84); Object[Vrab97].Summary_HP_Heal += rxint64(Vrab84);} else
                   {Object[Vrab81].HP -= Vrab79; Object[Vrab81].DHP -= Vrab79 / 4.0; Object[Vrab81].Summary_Damage_Taken += Vrab79; Object[Vrab97].Summary_Damage_Dealt += Vrab79;}
                  break;  
                 }
                }

                if(Vrab86 != 0 || (Vrab86 == 0 && Vrab85 == 0)) if(Vrab86 >= 0){if(Vrab86 == 0){Object[Vrab97].Arest = 4;} else {Object[Vrab97].Arest = Vrab86 % 65535;}} else {Object[Vrab97].Arest = 0;}
                if(Vrab85 != 0){if(Object[Vrab81].Vrest.size() <= Vrab97) Object[Vrab81].Vrest.resize(Vrab97 + 1); if(Vrab85 > 0){Object[Vrab81].Vrest[Vrab97] = Vrab85 % 65535;} else {Object[Vrab81].Vrest[Vrab97] = 0;}}
               break;
              }

              if(Vrab80)
              {
               statics insize Vrab79 = Vect10[Vrab98][Vrab93][Vrab83].Vrab002;
               statics xint64 Vrab78 = Vect06[Vrab98] > Vect06[Vrab82] ? Vect06[Vrab98] : Vect06[Vrab82];
               xint64 Vrab77; if(Vect09[Vrab98][0][Vrab93][0] - Vect09[Vrab82][1][Vrab79][0] < 0){Vrab77 = Vect09[Vrab82][1][Vrab79][0];} else {Vrab77 = Vect09[Vrab98][0][Vrab93][0];}
               xint64 Vrab76; if(Vect09[Vrab98][0][Vrab93][1] - Vect09[Vrab82][1][Vrab79][1] > 0){Vrab76 = Vect09[Vrab82][1][Vrab79][1];} else {Vrab76 = Vect09[Vrab98][0][Vrab93][1];}
               xint64 Vrab75; if(Vect09[Vrab98][0][Vrab93][2] - Vect09[Vrab82][1][Vrab79][2] < 0){Vrab75 = Vect09[Vrab82][1][Vrab79][2];} else {Vrab75 = Vect09[Vrab98][0][Vrab93][2];}
               xint64 Vrab74; if(Vect09[Vrab98][0][Vrab93][3] - Vect09[Vrab82][1][Vrab79][3] > 0){Vrab74 = Vect09[Vrab82][1][Vrab79][3];} else {Vrab74 = Vect09[Vrab98][0][Vrab93][3];}
               Spark((Vrab87 == 1 ? 2 : 0) + (Vrab89 >= 70 ? 1 : 0), ((Vrab77 + Vrab76) / 2) - 10 + L_Random(20), ((Vrab75 + Vrab74) / 2) - 10 + L_Random(20) - (Vrab78 - Vect06[Vrab82]), Vrab78);
              }
             }
            }
           }
          }

          for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
          {
           if(Vect11[Vrab98].Hit.size() == 0) continue;
           statics insize Vrab97 = Vect02[Vrab98];

           Object[Vrab97].Last_Hit = Vect11[Vrab98].Hit[L_Random(Vect11[Vrab98].Hit.size() - 1)];

           // Ice-conditional Damage.
           {
            insize Vrab96 = Vect11[Vrab98].Ice_Conditional.size();
            if(Vrab96 > 0)
            {
             Vrab96 -= 1;
             xint64 Vrab95 = Vect11[Vrab98].Ice_Conditional[0].Damage; xint64 Vrab94 = Vrab95;
             int32  Vrab93 = Vect11[Vrab98].Ice_Conditional[0].Fall;
             int32  Vrab92 = Vect11[Vrab98].Ice_Conditional[0].BDefend;
             while(Vrab96 != 0)
             {
              Vrab96 -= 1;
              statics xint64 Vrab91 = Vect11[Vrab98].Ice_Conditional[Vrab96].Damage;  if(Vrab91 > Vrab95) Vrab95 = Vrab91; Vrab94 += Vrab91;
              statics int32  Vrab90 = Vect11[Vrab98].Ice_Conditional[Vrab96].Fall;    if(Vrab90 > Vrab93) Vrab93 = Vrab90;
              statics int32  Vrab89 = Vect11[Vrab98].Ice_Conditional[Vrab96].BDefend; if(Vrab89 > Vrab92) Vrab92 = Vrab89;
             }

             Vect11[Vrab98].Fall.push_back(Vrab93);
             //if((Object[Vrab97].Data->Frame[Vect03[Vrab98]]->state == 7 && (Vect08[Vrab98] ? (Vect11[Vrab98].Ice_Conditional_Facing == 2) : (Vect11[Vrab98].Ice_Conditional_Facing == 1))) || Object[Vrab97].Data->Frame[Vect03[Vrab98]]->state == 69)
             if(Vrab92 < 80){Vrab95 *= 0.1; Vect11[Vrab98].Fall.pop_back();}

             Object[Vrab97].Summary_Damage_Taken += Vrab95;

             Vrab96 = Vect11[Vrab98].Ice_Conditional.size();
             while(Vrab96 != 0)
             {
              Vrab96 -= 1; statics insize Vrab91 = Vect11[Vrab98].Ice_Conditional[Vrab96].Dealer;
              Object[Vrab91].Summary_Damage_Dealt += Vrab95 * (Vrab94 / Vect11[Vrab98].Ice_Conditional[Vrab96].Damage);

              insize Vrab90 = Object[Vrab91].Owners.size();
              while(Vrab90 != 0)
              {
               Vrab90 -= 1; statics insize Vrab89 = Object[Vrab91].Owners[Vrab90]; if(Vrab89 >= Object.size()) continue; if(!Object[Vrab89].Exist) continue;
               Object[Vrab89].Summary_Damage_Dealt += Vrab95 * (Vrab94 / Vect11[Vrab98].Ice_Conditional[Vrab96].Damage);
              }
             }
            }
           }

           // Fire-conditional Damage.

           // Healing.
           {
            statics xint64 Vrab96 = Vect11[Vrab98].Healing * (rxint64(Object[Vrab97].Heal_Ratio) / 1000.0);
            if(Object[Vrab97].HP >= Object[Vrab97].DHP){Object[Vrab97].HP += Vrab96 / 4.0;} else
            {
             if(Object[Vrab97].HP + Vrab96 > Object[Vrab97].DHP){Object[Vrab97].HP += ((Vrab96 + Object[Vrab97].HP - Object[Vrab97].DHP) / 4.0) + (Object[Vrab97].DHP - Object[Vrab97].HP);} else
             {Object[Vrab97].HP += Vrab96;}
            }
           }

           switch(Vect11[Vrab98].Hit_Effect)
           {
            case 1: // Front Hit.

            break;
            case 2: // Back Hit.

            break;
            case 3: // Front & Back Hit.

            break;
            case 4: // Fire Hit.

            break;
            case 5: // Ice Hit.

            break;
            case 6: // Fire & Ice Hit.

            break;
            default: break;
           }

          }
         }
         #pragma endregion

         #pragma region 5th Phase : Misc Interacts. (An ITR that cause frame change.)
         {
          struct Srct02 {insize Vrab001 = 0; xint64 Vrab002 = 0; xint64 Vrab003 = 0; xint64 Vrab004 = 0; uint8 Vrab005 = 0; insize Vrab006 = rinsize(-1);};
          std::vector < std::vector < Srct02 > > Vect11(Vrab99);

          //
          {
           insize Vrab98 = Vrab99;
           while(Vrab98 != 0)
           {
            Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98]; int1 Vrab96[2] = {false, false};
            statics insize Vrab95 = Vect10[Vrab98].size(); insize Vrab94 = 0;
            while(Vrab94 < Vrab95)
            {
             statics insize Vrab93 = Vrab94; Vrab94 += 1;
             statics int32 Vrab92 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].kind;
             switch(Vrab92)
             {
              case 1: case 2: case 3: case 7: case 8: case 13: break;
              default: continue;
             }

             // Picking Target.
             {
              if(Vrab92 == 2 || Vrab92 == 7) if(Vrab96[0]) continue;
              if(Vrab92 == 1 || Vrab92 == 3) if(Vrab96[1]) continue;
              
              std::vector < insize > Vect12;
              xint64 Vrab91 = rxint64(0xFFFFFFFFF); insize Vrab90 = Vect10[Vrab98][Vrab93].size();
              while(Vrab90 != 0)
              {
               Vrab90 -= 1; statics insize Vrab89 = Vect10[Vrab98][Vrab93][Vrab90].Vrab001; statics xint64 Vrab88 = L_Distance(Vect04[Vrab98], Vect06[Vrab98], Vect04[Vrab89], Vect06[Vrab89]);
               if(Vrab88 <= Vrab91){if(Vrab88 < Vrab91){Vrab91 = Vrab88; Vect12.clear();} Vect12.push_back(Vrab90);}
              }
              statics insize Vrab89 = Vect12.size();
              if(Vrab89 > 0)
              {
               statics insize Vrab88 = Vect12[rinsize(L_Random(Vrab89 - 1))]; statics insize Vrab87 = Vect10[Vrab98][Vrab93][Vrab88].Vrab001; statics insize Vrab86 = Vect02[Vrab87];
               switch(Vrab92)
               {
                case 1: case 3:
                 {
                  if(Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].effect == 0)
                  {
                   Object[Vrab97].Facing = (Vect04[Vrab98] - Vect04[Vrab87] == 0) ? Vect08[Vrab98] : (Vect04[Vrab98] - Vect04[Vrab87] < 0);
                  }
                  int32 Vrab85 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].catchingact[0]; if(Vrab85 < 0){Vrab85 = -Vrab85; Object[Vrab97].Facing = !Object[Vrab97].Facing;}
                  Object[Vrab97].Frame = rinsize(Vrab85); Object[Vrab97].Wait = 0; Object[Vrab97].Catch = Vrab86; Vrab96[1] = true;
                 }
                break;
                case 2:
                 {
                  int32 Vrab85 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].respond; if(Object[Vrab86].Data->type == 2){Object[Vrab97].Heavy_Hold = true; if(Vrab85 == 0) Vrab85 = 116;} else {if(Vrab85 == 0) Vrab85 = 115;} 
                  if(Vrab85 < 0){Vrab85 = -Vrab85; Object[Vrab97].Facing = !Vect08[Vrab98];} else {Object[Vrab97].Facing = Vect08[Vrab98];}
                  Object[Vrab97].Frame = rinsize(Vrab85); Object[Vrab97].Wait = 0;
                 }
                case 7:
                 Object[Vrab97].Hold = Vrab86; Vrab96[0] = true;
                break;
                case 8:
                 {
                  int32 Vrab85 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].dvx; if(Vrab85 < 0){Vrab85 = -Vrab85; Object[Vrab97].Facing = !Vect08[Vrab98];} else {Object[Vrab97].Facing = Vect08[Vrab98];}
                  if(rinsize(Vrab85) != Object[Vrab97].Frame) Object[Vrab97].Wait = 0; Object[Vrab97].Frame = rinsize(Vrab85); Object[Vrab97].X = Vect04[Vrab87]; Object[Vrab97].Z = Vect06[Vrab87] + 1;
                 }
                break;
                default:
                 {
                  int32 Vrab85 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].respond; if(Vrab85 < 0){Vrab85 = -Vrab85; Object[Vrab97].Facing = !Vect08[Vrab98];} else {Object[Vrab97].Facing = Vect08[Vrab98];}
                  Object[Vrab97].Frame = rinsize(Vrab85); Object[Vrab97].Wait = 0;
                  switch(Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].effect % 10)
                  {
                   case 1: Object[Vrab97].X = Vect04[Vrab87]; break;
                   case 2: Object[Vrab97].Y = Vect05[Vrab87]; break;
                   case 3: Object[Vrab97].Z = Vect06[Vrab87]; break;
                   case 4: Object[Vrab97].X = Vect04[Vrab87]; Object[Vrab97].Y = Vect05[Vrab87]; break;
                   case 5: Object[Vrab97].X = Vect04[Vrab87]; Object[Vrab97].Z = Vect06[Vrab87]; break;
                   case 6: Object[Vrab97].Y = Vect05[Vrab87]; Object[Vrab97].Z = Vect06[Vrab87]; break;
                   case 7: Object[Vrab97].X = Vect04[Vrab87]; Object[Vrab97].Y = Vect05[Vrab87]; Object[Vrab97].Z = Vect06[Vrab87]; break;
                   default: break;
                  }
                 }
                break;
               }
              }
             }

             // Applying Effect.
             {
              int1 Vrab91 = false; 
              insize Vrab90; {statics int32 Vrab89 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].caughtact[0]; if(Vrab89 < 0){Vrab91 = true; Vrab90 = rinsize(-Vrab89);} else {Vrab90 = rinsize(Vrab89);}} 
              int1 Vrab89 = false;
              insize Vrab88; {statics int32 Vrab87 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].dvx; if(Vrab87 < 0){Vrab89 = true; Vrab88 = rinsize(-Vrab87);} else {Vrab88 = rinsize(Vrab87);}}

              insize Vrab87 = Vect10[Vrab98][Vrab93].size();
              while(Vrab87 != 0)
              {
               Vrab87 -= 1; statics insize Vrab86 = Vect10[Vrab98][Vrab93][Vrab87].Vrab001; statics insize Vrab85 = Vect02[Vrab86]; uint8 Vrab84 = 2ui8;
               switch(Vrab92)
               {
                case 2: case 7: if(Object[Vrab97].Hold != Vrab85) break;
                 Vrab84 += 2ui8;
                 Vrab91 = Vrab91 ? !Vect08[Vrab86] : Vect08[Vrab86];
                 Vect11[Vrab86].push_back({Vrab90, Vect04[Vrab86], Vect05[Vrab86], Vect06[Vrab86], ruint8(Vrab84 + (Vrab91 ? 0ui8 : 1ui8)), Vrab97});
                break;
                case 1: case 3:
                 Vrab91 = Vrab91 ? Vect08[Vrab86] : !Vect08[Vrab86];
                 if(((Vect04[Vrab98] - Vect04[Vrab86]) < 0 && !Vect08[Vrab86]) || ((Vect04[Vrab98] - Vect04[Vrab86]) > 0 && Vect08[Vrab86])) Vrab91 = !Vrab91;
                 Vect11[Vrab86].push_back({Vrab90, (Vect04[Vrab98] + Vect04[Vrab86]) / 2, (Vect05[Vrab98] + Vect05[Vrab86]) / 2, (Vect06[Vrab98] + Vect06[Vrab86]) / 2, (Vrab91 ? 3ui8 : 2ui8), Vrab97});
                break;
                case 8:
                 {
                  int32 Vrab83 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].injury;
                  if(Vrab83 <= 0) break;
                  if(Polish) Vrab83 *= 4; Vrab83 = L_Rounding(rxint64(Vrab83) * 0.75); if(Object[Vrab85].Heal + Vrab83 < 0x7FFFFFFE){Object[Vrab85].Heal += Vrab83;} else {Object[Vrab85].Heal = 0x7FFFFFFE;}
                 }
                break;
                default:
                 {
                  int32 Vrab83 = Object[Vrab97].Data->Frame[Vect03[Vrab98]]->itr[Vrab93].effect; Vrab83 = (Vrab83 % 100) - (Vrab83 % 10);
                  xint64 Vrab82 = Vect04[Vrab86];
                  xint64 Vrab81 = Vect05[Vrab86];
                  xint64 Vrab80 = Vect06[Vrab86];

                  switch(Vrab83)
                  {
                   case 10: Vrab82 = Vect04[Vrab98]; break;
                   case 20: Vrab81 = Vect05[Vrab98]; break;
                   case 30: Vrab80 = Vect06[Vrab98]; break;
                   case 40: Vrab82 = Vect04[Vrab98]; Vrab81 = Vect05[Vrab98]; break;
                   case 50: Vrab82 = Vect04[Vrab98]; Vrab80 = Vect06[Vrab98]; break;
                   case 60: Vrab81 = Vect05[Vrab98]; Vrab80 = Vect06[Vrab98]; break;
                   case 70: Vrab82 = Vect04[Vrab98]; Vrab81 = Vect05[Vrab98]; Vrab80 = Vect06[Vrab98]; break;
                   case 80: Vrab82 = (Vrab82 + Vect04[Vrab98]) / 2.0; Vrab80 = (Vrab80 + Vect06[Vrab98]) / 2.0; break;
                   case 90: Vrab82 = (Vrab82 + Vect04[Vrab98]) / 2.0; Vrab81 = (Vrab81 + Vect05[Vrab98]) / 2.0; Vrab80 = (Vrab80 + Vect06[Vrab98]) / 2.0; break;
                   default: break;
                  }
                  
                  Vect11[Vrab86].push_back({Vrab90, Vrab82, Vrab81, Vrab80, (Vrab89 ? 0ui8 : 1ui8), rinsize(-1)});
                 }
                break;
               }
              }
             }
            }
           }
          }

          for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
          {
           insize Vrab97 = Vect11[Vrab98].size(); if(Vrab97 == 0) continue; Vrab97 = rinsize(L_Random(Vrab97 - 1));
           statics insize Vrab96 = Vect02[Vrab98]; statics uint8 Vrab95 = Vect11[Vrab98][Vrab97].Vrab005; statics insize Vrab94 = Vect11[Vrab98][Vrab97].Vrab006;
           Object[Vrab96].Frame = Vect11[Vrab98][Vrab97].Vrab001; Object[Vrab96].Wait = 0;
           Object[Vrab96].X = Vect11[Vrab98][Vrab97].Vrab002; Object[Vrab96].Y = Vect11[Vrab98][Vrab97].Vrab003; Object[Vrab96].Z = Vect11[Vrab98][Vrab97].Vrab004;
           Object[Vrab96].Facing = Vrab95 % 2 == 0;
           switch(Vrab95)
           {
            case 3: case 2: Object[Vrab96].Caught = Vrab94; break;
            case 5: case 4: if(Object[Vrab96].Held == rinsize(-1) && Object[Vrab94].Hold == Vrab96) Object[Vrab94].Summary_Pick += 1; Object[Vrab96].Held = Vrab94; break;
            default: break;
           }
          }
         }
         #pragma endregion
        }
       }
       #pragma endregion

       #pragma region Phase 5 : Friction, Cpoint, Wpoint, Position Shift.
       {
        statics insize Vrab99 = Vect02.size();

        // Friction
        {
         insize Vrab98 = 0;
         while(Vrab98 < Vrab99)
         {
          statics insize Vrab97 = Vect02[Vrab98]; Vrab98 += 1;
          if(Object[Vrab97].Held == rinsize(-1) && Object[Vrab97].Caught == rinsize(-1) && Object[Vrab97].Shake == 0)
          {
           switch(Object[Vrab97].Data->type)
           {
            case 3: if(Object[Vrab97].Y < 0) break;
            default:
             if(Object[Vrab97].Y < 0)
             {
              int1 Vrab96 = false; {while(true){statics insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break; Vrab96 = Object[Vrab97].Data->Frame[Vrab95]->state == 1002; break;}}
              xint64 Vrab95 = (17.0 / 10.0) / (Polish ? 4 : 1);
              switch(Object[Vrab97].Data->type)
              {
               case 4: Vrab95 = (17.0 / 20.0) / (Polish ? 4 : 1); Vrab96 = false; break;
               case 6: Vrab95 = (17.0 / 15.0) / (Polish ? 4 : 1); Vrab96 = false; break;
               default: break;
              }
              if(Vrab96)
              switch(Object[Vrab97].Data->id)
              {
               case 101: Vrab95 = (17.0 / 15.0) / (Polish ? 4 : 1); break;
               case 120: Vrab95 = (17.0 / 40.0) / (Polish ? 4 : 1); break;
               case 124: Vrab95 = (17.0 / 100.0) / (Polish ? 4 : 1); break;
               default: Vrab95 = (17.0 / 30.0) / (Polish ? 4 : 1); break;
              }
              Object[Vrab97].Y_Vel += Vrab95;
             } else
             {
              if(Object[Vrab97].X_Vel > 0) if(Object[Vrab97].X_Vel - (Polish ? 0.25 : 1) < 0){Object[Vrab97].X_Vel = 0;} else {Object[Vrab97].X_Vel -= (Polish ? 0.25 : 1);}
              if(Object[Vrab97].X_Vel < 0) if(Object[Vrab97].X_Vel + (Polish ? 0.25 : 1) > 0){Object[Vrab97].X_Vel = 0;} else {Object[Vrab97].X_Vel += (Polish ? 0.25 : 1);}
              if(Object[Vrab97].Z_Vel > 0) if(Object[Vrab97].Z_Vel - (Polish ? 0.25 : 1) < 0){Object[Vrab97].Z_Vel = 0;} else {Object[Vrab97].Z_Vel -= (Polish ? 0.25 : 1);}
              if(Object[Vrab97].Z_Vel < 0) if(Object[Vrab97].Z_Vel + (Polish ? 0.25 : 1) > 0){Object[Vrab97].Z_Vel = 0;} else {Object[Vrab97].Z_Vel += (Polish ? 0.25 : 1);}
             }
            break;
           }
           
           if(Object[Vrab97].Float) if(Object[Vrab97].Y_Vel >= -6) Object[Vrab97].Y_Vel -= 3;
          }
          Object[Vrab97].Float = false;
         }
        }
       
        // Cpoint.
        {
         std::vector < insize > Vect03 = Vect02;
         insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
         while(Vrab97 < Vrab98)
         {
          statics insize Vrab95 = Vect03[Vrab97]; Vrab97 += 1;

          // Caught.
          if(Object[Vrab95].Caught != rinsize(-1))
          {
           int1 Vrab94 = true;
           while(true)
           {
            statics insize Vrab93 = Object[Vrab95].Caught; if(Vrab93 >= Vrab96) break; if(!Object[Vrab93].Exist) break; if(Object[Vrab93].Catch != Vrab95) break;
            statics insize Vrab92 = Object[Vrab93].Frame; if(Vrab92 >= Object[Vrab93].Data->Frame.size()) break; if(!Object[Vrab93].Data->Frame[Vrab92]->Exist) break;
            if(Object[Vrab93].Data->Frame[Vrab92]->cpoint.size() == 0) break; if(Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].kind != 1) break;
            statics insize Vrab91 = Object[Vrab95].Frame; if(Vrab91 >= Object[Vrab95].Data->Frame.size()) break; if(!Object[Vrab95].Data->Frame[Vrab91]->Exist) break;
            if(Object[Vrab95].Data->Frame[Vrab91]->cpoint.size() == 0) break; if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].kind != 2) break;
            Vrab94 = false;
            break;
           } if(Vrab94) while(true)
           {
            Object[Vrab95].Caught = rinsize(-1);
            statics insize Vrab93 = Object[Vrab95].Frame; if(Vrab93 >= Object[Vrab95].Data->Frame.size()) break; if(!Object[Vrab95].Data->Frame[Vrab93]->Exist) break;
            if(Object[Vrab95].Data->Frame[Vrab93]->cpoint.size() == 0) break; if(Object[Vrab95].Data->Frame[Vrab93]->cpoint[0].kind != 2) break;
            Object[Vrab95].Wait = 0; Object[Vrab95].Y -= 3; Object[Vrab95].Y_Vel = -3; if(Object[Vrab95].Y >= 0){Object[Vrab95].Y_Vel = 0; Object[Vrab95].Frame = 215;} else {Object[Vrab95].Frame = 212;}
            break;
           }
          }

          // Catch.
          if(Object[Vrab95].Catch != rinsize(-1))
          {
           int1 Vrab94 = true; statics insize Vrab93 = Object[Vrab95].Catch;
           while(true)
           {
            if(Vrab93 >= Vrab96) break; if(!Object[Vrab93].Exist) break; if(Object[Vrab93].Caught != Vrab95) break;
            statics insize Vrab92 = Object[Vrab95].Frame; if(Vrab92 >= Object[Vrab95].Data->Frame.size()) break; if(!Object[Vrab95].Data->Frame[Vrab92]->Exist) break;
            if(Object[Vrab95].Data->Frame[Vrab92]->cpoint.size() == 0) break; if(Object[Vrab95].Data->Frame[Vrab92]->cpoint[0].kind != 1) break;
            statics insize Vrab91 = Object[Vrab93].Frame; if(Vrab91 >= Object[Vrab93].Data->Frame.size()) break; if(!Object[Vrab93].Data->Frame[Vrab91]->Exist) break;
            if(Object[Vrab93].Data->Frame[Vrab91]->cpoint.size() == 0) break; if(Object[Vrab93].Data->Frame[Vrab91]->cpoint[0].kind != 2) break;
            Vrab94 = false;
            break;
           } if(Vrab94)
           {
            continue;
           } else
           {
            Vect03.push_back(Vrab93); Vrab98 += 1;
           }

           insize Vrab92 = 0;
           while(true)
           {
            Object[Vrab93].X = Object[Vrab95].X; Object[Vrab93].Y = Object[Vrab95].Y + 1; Object[Vrab93].Z = Object[Vrab95].Z - 1;
            Object[Vrab93].X_Vel = Object[Vrab95].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab95].Y_Vel; Object[Vrab93].Z_Vel = 0;
            Object[Vrab93].Frame = 0; Object[Vrab93].Wait = 0; Object[Vrab93].Attacking = 0; Object[Vrab93].Throw = 0;

            statics insize Vrab91 = Object[Vrab95].Frame;
            if(Object[Vrab95].Facing)
            {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->centerx;} else {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->centerx;}
            Object[Vrab93].Y -= Object[Vrab95].Data->Frame[Vrab91]->centery;

            if(Object[Vrab95].Facing)
            {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;} else {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;}
            Object[Vrab93].Y += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].y;
            if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10 == 1)
            {Object[Vrab93].Y -= 2; Object[Vrab93].Z += 2;}

            int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].vaction;
            if(Vrab90 < 0){Vrab90 = -Vrab90; Object[Vrab93].Facing = Object[Vrab95].Facing;} else {Object[Vrab93].Facing = !Object[Vrab95].Facing;}
            if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover - (Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10) == 10) Object[Vrab93].Facing = !Object[Vrab93].Facing;
            Object[Vrab93].Frame = rinsize(Vrab90); Vrab92 = rinsize(Vrab90);

            statics xint64 Vrab89 = (Object[Vrab95].Facing ? 1 : -1) * rxint64(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvx);
            statics xint64 Vrab88 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvy;
            xint64 Vrab87 = 0; if(Object[Vrab95].Input_Down > 0 && Object[Vrab95].Input_Up == 0) Vrab87 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz; if(Object[Vrab95].Input_Up > 0 && Object[Vrab95].Input_Down == 0) Vrab87 = -(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz);
            statics int32 Vrab86 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwinjury;
            if(Vrab89 != 0 || Vrab88 != 0)
            {
             Object[Vrab93].Caught = rinsize(-1); Object[Vrab93].Throw = -1;
             Object[Vrab93].X_Vel += Vrab89; Object[Vrab93].Y_Vel += Vrab88; Object[Vrab93].Z_Vel += Vrab87;
             if(Vrab86 == -1 || Vrab86 == -2 || Vrab86 == -3)
             {
              if(Vrab86 != -3){Object[Vrab95].Return_Address.push_back(Object[Vrab95].Data); Object[Vrab95].Return = ruint8(-rint8(Vrab86));}
              Object[Vrab95].Data = Object[Vrab93].Data;
              if(Vrab86 != -3){Object[Vrab95].Trans_Address.push_back(Object[Vrab93].Data); Object[Vrab95].Trans = 0;}
              Object[Vrab95].Frame = 0; Object[Vrab95].Wait = 0;
             } else {if(Vrab86 != 0) Object[Vrab93].Throw = Vrab86;}
            }

            break;
           } while(true)
           {
            if(Object[Vrab93].Throw != 0) break;
            if(Vrab92 >= Object[Vrab93].Data->Frame.size()){Object[Vrab93].Caught = rinsize(-1); break;} if(!Object[Vrab93].Data->Frame[Vrab92]->Exist){Object[Vrab93].Caught = rinsize(-1); break;}
            
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->centerx;} else {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->centerx;}
            Object[Vrab93].Y += Object[Vrab93].Data->Frame[Vrab92]->centery;
            
            if(Object[Vrab93].Data->Frame[Vrab92]->cpoint.size() == 0){Object[Vrab93].Caught = rinsize(-1); break;}
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].x;} else {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].x;}
            Object[Vrab93].Y -= Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].y;

            if(Object[Vrab93].Data->Frame[Vrab92]->cpoint[0].kind != 2) Object[Vrab93].Caught = rinsize(-1);
            break;
           }
          }
         }
        }

        // Wpoint.
        {
         std::vector < insize > Vect03 = Vect02;
         insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
         while(Vrab97 < Vrab98)
         {
          statics insize Vrab95 = Vect03[Vrab97]; Vrab97 += 1;

          // Held.
          if(Object[Vrab95].Held != rinsize(-1))
          {
           int1 Vrab94 = true;
           while(true)
           {
            statics insize Vrab93 = Object[Vrab95].Held; if(Vrab93 >= Vrab96) break; if(!Object[Vrab93].Exist) break; if(Object[Vrab93].Hold != Vrab95) break;
            Vrab94 = false;
            break;
           } if(Vrab94)
           {
            Object[Vrab95].Held = rinsize(-1); Object[Vrab95].Wait = 0; Object[Vrab95].X_Vel = 0; Object[Vrab95].Y_Vel = 0; Object[Vrab95].Z_Vel = 0;
           }
          }

          // Hold.
          if(Object[Vrab95].Hold != rinsize(-1))
          {
           int1 Vrab94 = true; statics insize Vrab93 = Object[Vrab95].Hold;
           while(true)
           {
            if(Vrab93 >= Vrab96) break; if(!Object[Vrab93].Exist) break; if(Object[Vrab93].Held != Vrab95) break;
            Vrab94 = false;
            break;
           } if(Vrab94)
           {
            Object[Vrab95].Hold = rinsize(-1); continue;
           } else
           {
            Vect03.push_back(Vrab93); Vrab98 += 1;
           }

           insize Vrab92 = 0;
           while(true)
           {
            Object[Vrab93].X = Object[Vrab95].X; Object[Vrab93].Y = Object[Vrab95].Y - 1; Object[Vrab93].Z = Object[Vrab95].Z + 1;
            Object[Vrab93].X_Vel = Object[Vrab95].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab95].Y_Vel; Object[Vrab93].Z_Vel = Object[Vrab95].Z_Vel;
            Object[Vrab93].Frame = 0; Object[Vrab93].Wait = 0; Object[Vrab93].Attacking = 0;

            statics insize Vrab91 = Object[Vrab95].Frame; if(Vrab91 >= Object[Vrab95].Data->Frame.size()) break; if(!Object[Vrab95].Data->Frame[Vrab91]->Exist) break;
            if(Object[Vrab95].Facing)
            {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->centerx;} else {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->centerx;}
            Object[Vrab93].Y -= Object[Vrab95].Data->Frame[Vrab91]->centery;

            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint.size() == 0) break;
            if(Object[Vrab95].Facing)
            {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].x;} else {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].x;}
            Object[Vrab93].Y += Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].y;
            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].cover % 10 == 1)
            {Object[Vrab93].Y += 2; Object[Vrab93].Z -= 2;}

            int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].weaponact;
            if(Vrab90 < 0){Vrab90 = -Vrab90; Object[Vrab93].Facing = !Object[Vrab95].Facing;} else {Object[Vrab93].Facing = Object[Vrab95].Facing;}
            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].cover - (Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].cover % 10) == 10) Object[Vrab93].Facing = !Object[Vrab93].Facing;
            Object[Vrab93].Frame = rinsize(Vrab90); Object[Vrab93].Attacking = rinsize(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].attacking);
            Vrab92 = Object[Vrab93].Frame;

            if(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].kind == 3)
            {
             Object[Vrab93].Frame = L_Random(15); Object[Vrab95].Heavy_Hold = false; Object[Vrab95].Hold = rinsize(-1); Object[Vrab93].Held = rinsize(-1);
             Object[Vrab93].X_Vel += -3 + rxint64(L_Random(6)); Object[Vrab93].Z_Vel += -1 + rxint64(L_Random(2)); Object[Vrab93].Y_Vel += -4 + rxint64(L_Random(4));
            } else
            {
             xint64 Vrab89 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvx; if(!Object[Vrab95].Facing) Vrab89 = -Vrab89;
             statics xint64 Vrab88 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvy; 
             xint64 Vrab87 = 0; if(Object[Vrab95].Input_Down > 0 && Object[Vrab95].Input_Up == 0) Vrab87 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvz; if(Object[Vrab95].Input_Up > 0 && Object[Vrab95].Input_Down == 0) Vrab87 = -(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].dvz);
             if(Vrab89 != 0 && Vrab88 != 0)
             {
              Object[Vrab93].Frame = Object[Vrab93].Data->type == 2 ? 0 : 40; Object[Vrab95].Heavy_Hold = false; Object[Vrab95].Hold = rinsize(-1); Object[Vrab93].Held = rinsize(-1);
              Object[Vrab93].X_Vel = Vrab89; Object[Vrab93].Y_Vel = Vrab88; Object[Vrab93].Z_Vel = Vrab87;
             }
            }

            break;
           } while(true)
           {
            if(Vrab92 >= Object[Vrab93].Data->Frame.size()) break; if(!Object[Vrab93].Data->Frame[Vrab92]->Exist) break;
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->centerx;} else {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->centerx;}
            Object[Vrab93].Y += Object[Vrab93].Data->Frame[Vrab92]->centery;
            
            if(Object[Vrab93].Data->Frame[Vrab92]->wpoint.size() == 0) break;
            if(Object[Vrab93].Facing)
            {Object[Vrab93].X -= Object[Vrab93].Data->Frame[Vrab92]->wpoint[0].x;} else {Object[Vrab93].X += Object[Vrab93].Data->Frame[Vrab92]->wpoint[0].x;}
            Object[Vrab93].Y -= Object[Vrab93].Data->Frame[Vrab92]->wpoint[0].y;

            break;
           }
          } else {Object[Vrab95].Heavy_Hold = false;}
         }
        }

        // Position Shift.
        {
         insize Vrab98 = Vrab99;
         while(Vrab98 != 0)
         {
          Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98];
          statics xint64 Vrab96 = rxint64(Backgrounds[Background].Shift), Vrab95 = Vrab96 + rxint64(Backgrounds[Background].width), Vrab94 = rxint64(Backgrounds[Background].zboundary[0]), Vrab93 = rxint64(Backgrounds[Background].zboundary[1]);
          if(Object[Vrab97].Lock)
          {
           if(Object[Vrab97].X < Vrab96) Object[Vrab97].X = Vrab96; if(Object[Vrab97].X > Vrab95) Object[Vrab97].X = Vrab95;
          } else
          {
           if(Object[Vrab97].Data->type == 0){if(Object[Vrab97].X < Vrab96 - 200) Object[Vrab97].X = Vrab96 - 200; if(Object[Vrab97].X > Vrab95 + 200) Object[Vrab97].X = Vrab95 + 200;}
          }
          if(Object[Vrab97].Z < Vrab94) Object[Vrab97].Z = Vrab94; if(Object[Vrab97].Z > Vrab93) Object[Vrab97].Z = Vrab93;
         }
        }
       }
       #pragma endregion
      }

      // Camera.
      {
       insize Vrab99 = Object.size();
       while(Vrab99 != 0)
       {
        Vrab99 -= 1; if(!Object[Vrab99].Exist) continue;
        if(Object[Vrab99].Player > 0 && Object[Vrab99].Player <= 8)
        if(Object[Vrab99].HP > 0)
        if(Object[Vrab99].Facing)
        {Vect01.push_back({0, (Object[Vrab99].X + 100), (Object[Vrab99].Y * 0.75), (Object[Vrab99].Z + 165), Object[Vrab99].D});} else
        {Vect01.push_back({0, (Object[Vrab99].X - 100), (Object[Vrab99].Y * 0.75), (Object[Vrab99].Z + 165), Object[Vrab99].D});}
       }
       if(Vect01.size() == 0)
       {
        
       }
      }

      return Vect01;
     }
     std::vector < HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW > Rear(statics int64 Vrab01, statics int64 Vrab02) fastened
     {
      UNREFERENCED_PARAMETER(Vrab02);
      std::vector < HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW > Vect01;
      statics insize Vrab03 = Backgrounds[Background].Layer.size(); if(Animation[Background].size() == 0) Animation[Background].resize(Vrab03); insize Vrab04 = 0;
      while(Vrab04 < Vrab03)
      {
       statics insize Vrab05 = Backgrounds[Background].Layer[Vrab04].image_Index;
       statics uint32 Vrab06 = Backgrounds[Background].Layer[Vrab04].loop, Vrab07 = Backgrounds[Background].Layer[Vrab04].rect32;
       statics uint8  Vrab08 = ruint8(Backgrounds[Background].Layer[Vrab04].transparency);
       statics int64  Vrab09 = rint64(Backgrounds[Background].Layer[Vrab04].x) + int64(Backgrounds[Background].Shift), Vrab10 = Backgrounds[Background].Layer[Vrab04].y;

       if(Vrab07 != 0){int64 Vrab11 = rint64(Backgrounds[Background].Layer[Vrab04].width); if(Backgrounds[Background].Shift == 0 && Vrab11 == 794) Vrab11 = 800; Vect01.push_back({3, (Backgrounds[Background].Layer[Vrab04].transparency > 1), Vrab07, Vrab09 + Vrab01, Vrab10}); Vect01.push_back({0, (Backgrounds[Background].Layer[Vrab04].transparency > 1), 0, Vrab11, rint64(Backgrounds[Background].Layer[Vrab04].height)});} else
       {
        if(!Pause) Animation[Background][Vrab04] += 1; if(Animation[Background][Vrab04] >= ruint32(Backgrounds[Background].Layer[Vrab04].cc)) Animation[Background][Vrab04] = 0; statics uint32 Vrab11 = Animation[Background][Vrab04];
        if(Vrab11 >= ruint32(Backgrounds[Background].Layer[Vrab04].c1) && Vrab11 <= ruint32(Backgrounds[Background].Layer[Vrab04].c2))

        {
         int64 Vrab12 = 0; int64 Vrab13 = rint64(Backgrounds[Background].width); int64 Vrab14 = Vrab06; if(Vrab06 == 0) Vrab14 = Vrab13 + 1;
         uint8 Vrab15 = 0; if(Vrab08 == 0 || Vrab08 == 2) Vrab15 = 2;
         statics int64 Vrab16 = rint64(Backgrounds[Background].Layer[Vrab04].width); statics int1 Vrab17 = Vrab16 != 0;
         statics int64 Vrab18 = 800 - (rint64(Backgrounds[Background].Shift) * 2);
         while(true)
         {
          int64 Vrab19 = Vrab09 + Vrab12;
          if(Vrab17){if(Vrab13 - Vrab18 != 0) Vrab19 -= (((Vrab16 - Vrab18) * Vrab01) / (Vrab13 - Vrab18)) - Vrab01;}
          if(Vrab19 > Vrab13) break;
          Vect01.push_back({Vrab15, (Backgrounds[Background].Layer[Vrab04].transparency > 1), Vrab05, Vrab19, Vrab10});
          Vrab12 += Vrab14;
         }
        }
       }
       Vrab04 += 1;
      }
      return Vect01;
     }
     std::vector < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW > Draw(statics int64 Vrab01, statics int64 Vrab02) fastened
     {
      std::vector < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW > Vect01;

      {
       std::vector < insize > Vect02; std::vector < uint8 > Vect03; std::vector < xint64 > Vect04;

       // Sorting Order.
       {
        // Object.
        {
         insize Vrab99 = Object.size(); while(Vrab99 != 0)
         {
          Vrab99 -= 1;
          if(!Object[Vrab99].Exist) continue;
          statics uint8 Vrab98 = Object[Vrab99].Data->type; statics xint64 Vrab97 = Object[Vrab99].Z;
          statics insize Vrab96 = Vect02.size(); insize Vrab95 = 0; while(Vrab95 != Vrab96)
          {
           if(Vrab97 < Vect04[Vrab95]) break;
           if(Vrab97 == Vect04[Vrab95]) if(Vrab98 < Vect03[Vrab95]) break;
           Vrab95 += 1;
          }
          if(Vrab95 == Vrab96){Vect02.push_back(Vrab99); Vect03.push_back(Vrab98); Vect04.push_back(Vrab97);} else
          {Vect02.insert(Vect02.begin() + Vrab95, Vrab99); Vect03.insert(Vect03.begin() + Vrab95, Vrab98); Vect04.insert(Vect04.begin() + Vrab95, Vrab97);}
         }
        }

        // Effect.
        {
         insize Vrab99 = Effect.size(); while(Vrab99 != 0)
         {
          Vrab99 -= 1;
          if(!Effect[Vrab99].Exist) continue;
          statics xint64 Vrab98 = Effect[Vrab99].Z;
          statics insize Vrab97 = Vect02.size(); insize Vrab96 = 0; while(Vrab96 != Vrab97)
          {
           if(Vrab98 < Vect04[Vrab96]) break;
           Vrab96 += 1;
          }
          if(Vrab96 == Vrab98){Vect02.push_back(Vrab99); Vect03.push_back(255ui8); Vect04.push_back(Vrab98);} else
          {Vect02.insert(Vect02.begin() + Vrab96, Vrab99); Vect03.insert(Vect03.begin() + Vrab96, 255ui8); Vect04.insert(Vect04.begin() + Vrab96, Vrab98);}
         }
        }
       }

       // Shadow. (Drawn before any entities.)
       {
        statics insize Vrab99 = Backgrounds[Background].shadow_Index;
        statics xint64 Vrab98 = rxint64(Backgrounds[Background].shadowsize[0]), Vrab97 = rxint64(Backgrounds[Background].shadowsize[1]);
        statics int64 Vrab96 = rint64(Vrab98 / 2), Vrab95 = rint64(Vrab97 / 2);
        insize Vrab94 = Object.size(); insize Vrab93 = Vect01.size();
        while(Vrab94 != 0)
        {
         Vrab94 -= 1;
         if(!Object[Vrab94].Exist) continue;
         if(Object[Vrab94].Held != rinsize(-1)) continue;
         statics insize Vrab92 = Object[Vrab94].Data->id; if(Vrab92 == 223 || Vrab92 == 224) continue;
         statics int32 Vrab91 = Object[Vrab94].Blink; if(Vrab91 < 70){if((Vrab91 % 4 > 1 && Vrab91 > 0) || (Vrab91 % 4 < -1 && Vrab91 < 0)) continue;} else {continue;}
         statics insize Vrab90 = Object[Vrab94].Frame; if(Vrab90 < Object[Vrab94].Data->Frame.size()) if(Object[Vrab94].Data->Frame[Vrab90]->Exist) switch(Object[Vrab94].Data->Frame[Vrab90]->state)
         {
          case 3005: case 400: case 401: continue;
          default: break;
         }
         Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());
         Vect01[Vrab93].Effect = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > ();
         Vect01[Vrab93].Effect->Pic = Vrab99;
         Vect01[Vrab93].Effect->X = L_Rounding64(Object[Vrab94].X) - Vrab96;
         Vect01[Vrab93].Effect->Y = L_Rounding64(Object[Vrab94].Z) - Vrab95;
         Vect01[Vrab93].Effect->W = L_Rounding64((Vrab98 * Object[Vrab94].Scale) - Vrab98);
         Vect01[Vrab93].Effect->H = L_Rounding64((Vrab97 * Object[Vrab94].Scale) - Vrab97);
         Vrab93 += 1;
        }
       }

       // Entity.
       {
        insize Vrab99 = Vect01.size();
        statics insize Vrab98 = Vect02.size(); insize Vrab97 = 0; while(Vrab97 < Vrab98)
        {
         statics insize Vrab96 = Vrab97; Vrab97 += 1;
         statics insize Vrab95 = Vect02[Vrab96];
         statics insize Vrab94 = Vrab99; Vrab99 += 1;
         Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());

         if(Vect03[Vrab96] == 255ui8)
         {
          Vect01[Vrab94].Effect = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > ();
          Vect01[Vrab94].Effect->Pic = Effect[Vrab95].Pics[Effect[Vrab95].Pic];
          Vect01[Vrab94].Effect->Type = Effect[Vrab95].Sprite ? 1 : 0;
          Vect01[Vrab94].Effect->X = L_Rounding64(Effect[Vrab95].X);
          Vect01[Vrab94].Effect->Y = L_Rounding64(Effect[Vrab95].Z) + L_Rounding64(Effect[Vrab95].Y);
          if(Effect[Vrab95].Screen){Vect01[Vrab94].Effect->X += Vrab01; Vect01[Vrab94].Effect->Y += Vrab02;}
         } else
         {
          Vect01[Vrab94].Type = true;
          Vect01[Vrab94].Object = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_OBJECT > ();

          statics int32 Vrab93 = Object[Vrab95].Blink;
          if(Vrab93 < 25)
          {
           if(Object[Vrab95].Data->type == 0)
           {
            Vect01[Vrab94].Object->Character = true;
            Vect01[Vrab94].Object->Info = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_OBJECT_INFO > ();
            Vect01[Vrab94].Object->Info->Name = Object[Vrab95].Name;
            Vect01[Vrab94].Object->Info->Player = Object[Vrab95].Player - 1;
            Vect01[Vrab94].Object->Info->Icon1 = Object[Vrab95].Data->small_Index;
            if(Object[Vrab95].Return_Address.size() > 0) Vect01[Vrab94].Object->Info->Icon2 = Object[Vrab95].Return_Address[Object[Vrab95].Return_Address.size() - 1]->small_Index;
            Vect01[Vrab94].Object->Info->X = L_Rounding64(Object[Vrab95].X);
            Vect01[Vrab94].Object->Info->Y = L_Rounding64(Object[Vrab95].Z);
            if(Object[Vrab95].Heal > 0 && (Gametime % 4) <= 1) Vect01[Vrab94].Object->Info->Integrate = 1;
            if(Object[Vrab95].Clone >= rinsize(-2) || Object[Vrab95].HP <= 0)
            {
             Vect01[Vrab94].Object->Info->HP = Object[Vrab95].HP;
             Vect01[Vrab94].Object->Info->DHP = Object[Vrab95].DHP;
             Vect01[Vrab94].Object->Info->MHP = Object[Vrab95].MHP;
             Vect01[Vrab94].Object->Info->MP = Object[Vrab95].MP;
             Vect01[Vrab94].Object->Info->MMP = Object[Vrab95].MMP;
            } else
            {
             statics insize Vrab92 = Object[Vrab95].Clone;
             Vect01[Vrab94].Object->Info->HP = Object[Vrab92].HP;
             Vect01[Vrab94].Object->Info->DHP = Object[Vrab92].DHP;
             Vect01[Vrab94].Object->Info->MHP = Object[Vrab92].MHP;
             Vect01[Vrab94].Object->Info->MP = Object[Vrab92].MP;
             Vect01[Vrab94].Object->Info->MMP = Object[Vrab92].MMP;
            }
            statics insize Vrab92 = Object[Vrab95].Team; if(Vrab92 < 6){Vect01[Vrab94].Object->Info->Color = ruint8(Vrab92) + 1;} else {Vect01[Vrab94].Object->Info->Color = 0;}
           }

           if(Object[Vrab95].Facing)
           {
            Vect01[Vrab94].Object->Facing = true;
            Vect01[Vrab94].Object->X = L_Rounding64(Object[Vrab95].X);
           } else
           {
            Vect01[Vrab94].Object->Facing = false;
            Vect01[Vrab94].Object->X = L_Rounding64(Object[Vrab95].X);
           }
           Vect01[Vrab94].Object->Z = L_Rounding64(Object[Vrab95].Z);
           Vect01[Vrab94].Object->Y = L_Rounding64(Object[Vrab95].Y) + Vect01[Vrab94].Object->Z;
           if(Object[Vrab95].Shake > 0) if(Gametime % 2 == 0){if(Object[Vrab95].Facing){Vect01[Vrab94].Object->X -= 1;} else {Vect01[Vrab94].Object->X += 1;}} else {if(Object[Vrab95].Facing){Vect01[Vrab94].Object->X += 1;} else {Vect01[Vrab94].Object->X -= 1;}}
           
           
           while(true)
           {
            statics insize Vrab92 = Object[Vrab95].Frame; if(Vrab92 >= Object[Vrab95].Data->Frame.size()) break; if(!Object[Vrab95].Data->Frame[Vrab92]->Exist) break;

            if(Object[Vrab95].Facing)
            {
             Vect01[Vrab94].Object->Facing = true;
             Vect01[Vrab94].Object->X -= Object[Vrab95].Data->Frame[Vrab92]->centerx;
            } else
            {
             Vect01[Vrab94].Object->Facing = false;
													Vect01[Vrab94].Object->X += Object[Vrab95].Data->Frame[Vrab92]->centerx;
            }
            Vect01[Vrab94].Object->Y -= rint64(Object[Vrab95].Data->Frame[Vrab92]->centery);

												if(Object[Vrab95].Data->Frame[Vrab92]->ppoint.size() != 0)
												{
												 insize Vrab91 = Object[Vrab95].Data->Frame[Vrab92]->ppoint.size();
													while(Vrab91 != 0)
													{
													 Vrab91 -= 1; insize Vrab90 = rinsize(Object[Vrab95].Data->Frame[Vrab92]->ppoint[Vrab91].pic) + Object[Vrab95].Pic_Offset;
																										 insize Vrab89 = rinsize(-1), Vrab88 = rinsize(-1); int64 Vrab87 = 0, Vrab86 = 0;

              statics insize Vrab85 = Object[Vrab95].Data->file_Index.size(); insize Vrab84 = 0;
              while(Vrab84 < Vrab85)
              {
               if(Vrab90 < Object[Vrab95].Data->file_Index[Vrab84])
               {
                if(Vrab84 > 0) Vrab90 -= Object[Vrab95].Data->file_Index[Vrab84 - 1];
                Vrab89 = Object[Vrab95].Data->file[Vrab84].Picture_Index + Vrab90;
                Vrab87 = Object[Vrab95].Data->file[Vrab84].w; Vrab86 = Object[Vrab95].Data->file[Vrab84].h;
                statics insize Vrab83 = Object[Vrab95].Data->file[Vrab84].Picture_Mirror_Index; if(Vrab83 != rinsize(-1)) Vrab88 = Vrab83 + Vrab90;
                break;
               }
               Vrab84 += 1;
              }
             
              if((Vrab93 % 4 < 2 && Vrab93 > 0) || (Vrab93 % 4 > -2 && Vrab93 < 0) || Vrab93 == 0)
              if(Vrab89 != rinsize(-1))
              {
															statics insize Vrab83 = Vrab99; Vrab99 += 1; Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());
															Vect01[Vrab83].Effect = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > ();
															Vect01[Vrab83].Effect->Type = 1;
               if(!Object[Vrab95].Facing) 
															{if(Vrab88 != rinsize(-1)){Vect01[Vrab83].Effect->Pic = Vrab88;} else {Vect01[Vrab83].Effect->Pic = Vrab89; Vect01[Vrab83].Effect->Facing = true;}} else {Vect01[Vrab83].Effect->Pic = Vrab89;}
															Vect01[Vrab83].Effect->X = Vect01[Vrab94].Object->X - (Object[Vrab95].Facing ? 0 : Vrab87) + rint64(Object[Vrab95].Data->Frame[Vrab92]->ppoint[Vrab91].x * (Object[Vrab95].Facing ? 1 : -1));
															Vect01[Vrab83].Effect->Y = Vect01[Vrab94].Object->Y + rint64(Object[Vrab95].Data->Frame[Vrab92]->ppoint[Vrab91].y);
															Vect01[Vrab83].Effect->W = L_Rounding64(rxint64(Vrab87) * Object[Vrab95].Scale) - Vrab87 + rint64(Object[Vrab95].Data->Frame[Vrab92]->ppoint[Vrab91].w);
															Vect01[Vrab83].Effect->H = L_Rounding64(rxint64(Vrab86) * Object[Vrab95].Scale) - Vrab86 + rint64(Object[Vrab95].Data->Frame[Vrab92]->ppoint[Vrab91].h);
															Vect01[Vrab83].Effect->Trans = 255 - ruint8(Object[Vrab95].Data->Frame[Vrab92]->ppoint[Vrab91].trans);
															Vect01[Vrab83].Effect->Rotate = ruint32((Object[Vrab95].Facing ? 0 : 360) + (Object[Vrab95].Data->Frame[Vrab92]->ppoint[Vrab91].rotate * (Object[Vrab95].Facing ? 1 : -1))) % 360;
              }
													}
													{statics xint64 Vrab90 = rxint64(Object[Vrab95].Data->Frame[Vrab92]->centery) / 2; Vect01[Vrab94].Object->Y -= L_Rounding64((Vrab90 * Object[Vrab95].Scale) - Vrab90);}
												} else
												{
             insize Vrab91 = rinsize(Object[Vrab95].Data->Frame[Vrab92]->pic) + Object[Vrab95].Pic_Offset;
												 insize Vrab90 = rinsize(-1), Vrab89 = rinsize(-1); int64 Vrab88 = 0, Vrab87 = 0;

             statics insize Vrab86 = Object[Vrab95].Data->file_Index.size(); insize Vrab85 = 0;
             while(Vrab85 < Vrab86)
             {
              if(Vrab91 < Object[Vrab95].Data->file_Index[Vrab85])
              {
               if(Vrab85 > 0) Vrab91 -= Object[Vrab95].Data->file_Index[Vrab85 - 1];
               Vrab90 = Object[Vrab95].Data->file[Vrab85].Picture_Index + Vrab91;
               Vrab88 = Object[Vrab95].Data->file[Vrab85].w; Vrab87 = Object[Vrab95].Data->file[Vrab85].h;
               statics insize Vrab84 = Object[Vrab95].Data->file[Vrab85].Picture_Mirror_Index; if(Vrab84 != rinsize(-1)) Vrab89 = Vrab84 + Vrab91;
               break;
              }
              Vrab85 += 1;
             }
            
             if(!Object[Vrab95].Facing) Vect01[Vrab94].Object->X -= Vrab88;
             
             if((Vrab93 % 4 < 2 && Vrab93 > 0) || (Vrab93 % 4 > -2 && Vrab93 < 0) || Vrab93 == 0)
             if(Vrab90 != rinsize(-1))
             {
              Vect01[Vrab94].Object->Pic = Vrab90;
              Vect01[Vrab94].Object->Pic_M = Vrab89;
              Vect01[Vrab94].Object->Rotate = Object[Vrab95].Rotation % 360;
              Vect01[Vrab94].Object->W = L_Rounding64(rxint64(Vrab88) * Object[Vrab95].Scale) - Vrab88;
              Vect01[Vrab94].Object->H = L_Rounding64(rxint64(Vrab87) * Object[Vrab95].Scale) - Vrab87;
              {statics xint64 Vrab84 = rxint64(Object[Vrab95].Data->Frame[Vrab92]->centery) / 2; Vect01[Vrab94].Object->Y -= L_Rounding64((Vrab84 * Object[Vrab95].Scale) - Vrab84);}
             }
												}

            break;
           } 
          }
         }
        }
       }

       // Hitbox Visualization. (Drawn last.)
       {
        if(Hitboxes)
        {
         insize Vrab99 = Object.size(); insize Vrab98 = Vect01.size();
         while(Vrab99 != 0)
         {
          Vrab99 -= 1;
          if(!Object[Vrab99].Exist) continue;
          statics insize Vrab97 = Object[Vrab99].Frame; if(Vrab97 < Object[Vrab99].Data->Frame.size()) if(Object[Vrab99].Data->Frame[Vrab97]->Exist)
          {
           insize Vrab96 = Object[Vrab99].Data->Frame[Vrab97]->bdy.size();
           while(Vrab96 != 0)
           {
            Vrab96 -= 1;
            Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());
            Vect01[Vrab98].Effect = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > ();
            Vect01[Vrab98].Effect->Type = 3;
            Vect01[Vrab98].Effect->Pic = 0xFF00;
            Vect01[Vrab98].Effect->W = Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].w;
            Vect01[Vrab98].Effect->H = Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].h;
            Vect01[Vrab98].Effect->X = L_Rounding64(Object[Vrab99].X) + ((Object[Vrab99].Facing ? -1 : 1) * (rint64(Object[Vrab99].Data->Frame[Vrab97]->centerx) - rint64(Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].x))) - (Object[Vrab99].Facing ? 0 : Vect01[Vrab98].Effect->W);
            Vect01[Vrab98].Effect->Y = L_Rounding64(Object[Vrab99].Z + Object[Vrab99].Y) - (rint64(Object[Vrab99].Data->Frame[Vrab97]->centery) - rint64(Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].y));
            Vrab98 += 1;
            if(Fill_Hitboxes)
            if(Vect01[Vrab98 - 1].Effect->W > 2 && Vect01[Vrab98 - 1].Effect->H > 2)
            {
             Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());
             Vect01[Vrab98].Effect = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > ();
             Vect01[Vrab98].Effect->Type = 2;
             Vect01[Vrab98].Effect->Trans = 50;
             Vect01[Vrab98].Effect->Pic = 0xFF00;
             Vect01[Vrab98].Effect->W = rint64(Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].w) - 2;
             Vect01[Vrab98].Effect->H = rint64(Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].h) - 2;
             Vect01[Vrab98].Effect->X = L_Rounding64(Object[Vrab99].X) + ((Object[Vrab99].Facing ? -1 : 1) * (rint64(Object[Vrab99].Data->Frame[Vrab97]->centerx) - rint64(Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].x))) - (Object[Vrab99].Facing ? 0 : (Vect01[Vrab98].Effect->W + 2)) + 1;
             Vect01[Vrab98].Effect->Y = L_Rounding64(Object[Vrab99].Z + Object[Vrab99].Y) - (rint64(Object[Vrab99].Data->Frame[Vrab97]->centery) - rint64(Object[Vrab99].Data->Frame[Vrab97]->bdy[Vrab96].y)) + 1;
             Vrab98 += 1;
            }
           }
           Vrab96 = Object[Vrab99].Data->Frame[Vrab97]->itr.size();
           while(Vrab96 != 0)
           {
            Vrab96 -= 1;
            Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());
            Vect01[Vrab98].Effect = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > ();
            Vect01[Vrab98].Effect->Type = 3;
            Vect01[Vrab98].Effect->Pic = 0xFF0000; switch(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].kind){case 0: case 3: break; default: Vect01[Vrab98].Effect->Pic = 0xFFA500; break;}
            Vect01[Vrab98].Effect->W = Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].w;
            Vect01[Vrab98].Effect->H = Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].h;
            Vect01[Vrab98].Effect->X = L_Rounding64(Object[Vrab99].X) + ((Object[Vrab99].Facing ? -1 : 1) * (rint64(Object[Vrab99].Data->Frame[Vrab97]->centerx) - rint64(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].x))) - (Object[Vrab99].Facing ? 0 : Vect01[Vrab98].Effect->W);
            Vect01[Vrab98].Effect->Y = L_Rounding64(Object[Vrab99].Z + Object[Vrab99].Y) - (rint64(Object[Vrab99].Data->Frame[Vrab97]->centery) - rint64(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].y));
            Vrab98 += 1;
            if(Fill_Hitboxes)
            if(Vect01[Vrab98 - 1].Effect->W > 2 && Vect01[Vrab98 - 1].Effect->H > 2)
            {
             Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());
             Vect01[Vrab98].Effect = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_EFFECT > ();
             Vect01[Vrab98].Effect->Type = 2;
             Vect01[Vrab98].Effect->Trans = 50;
             Vect01[Vrab98].Effect->Pic = 0xFF0000; switch(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].kind){case 0: case 3: break; default: Vect01[Vrab98].Effect->Pic = 0xFFA500; break;}
             Vect01[Vrab98].Effect->W = rint64(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].w) - 2;
             Vect01[Vrab98].Effect->H = rint64(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].h) - 2;
             Vect01[Vrab98].Effect->X = L_Rounding64(Object[Vrab99].X) + ((Object[Vrab99].Facing ? -1 : 1) * (rint64(Object[Vrab99].Data->Frame[Vrab97]->centerx) - rint64(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].x))) - (Object[Vrab99].Facing ? 0 : (Vect01[Vrab98].Effect->W + 2)) + 1;
             Vect01[Vrab98].Effect->Y = L_Rounding64(Object[Vrab99].Z + Object[Vrab99].Y) - (rint64(Object[Vrab99].Data->Frame[Vrab97]->centery) - rint64(Object[Vrab99].Data->Frame[Vrab97]->itr[Vrab96].y)) + 1;
             Vrab98 += 1;
            }
           }
          }
         }
        }
       }

       /*/ Shadows Testament
        {
         insize Vrab01 = Vect01.size();
         statics insize Vrab02 = Vect02.size(); insize Vrab03 = 0; while(Vrab03 < Vrab02)
         {
          if(Vect03[Vrab03] == 255ui8)
          {

          } else
          {
           statics insize Vrab04 = Vect02[Vrab03];
           statics int32 Vrab05 = Object[Vrab04].Blink; statics insize Vrab06 = Object[Vrab04].Frame; insize Vrab07 = rinsize(-1), Vrab08 = Vrab07; int64 Vrab09 = 0, Vrab10 = 0;
           if(Vrab05 < 25 && ((Vrab05 % 4 < 2 && Vrab05 > 0) || (Vrab05 % 4 > -2 && Vrab05 < 0) || Vrab05 == 0))
           if(Vrab06 < Object[Vrab04].Data->Frame.size()) if(Object[Vrab04].Data->Frame[Vrab06].Exist)
           {
            statics insize Vrab11 = Object[Vrab04].Data->Frame[Vrab06].pic; statics insize Vrab12 = Object[Vrab04].Data->file_Index.size(); insize Vrab13 = 0;
            while(Vrab13 < Vrab12){if(Vrab11 < Object[Vrab04].Data->file_Index[Vrab13]) break; Vrab13 += 1;}
            if(Vrab13 < Vrab12)
            {
             Vrab07 = Object[Vrab04].Data->file[Vrab13].Picture_Index + Vrab11; statics insize Vrab14 = Object[Vrab04].Data->file[Vrab13].Picture_Mirror_Index; if(Vrab14 != rinsize(-1)) Vrab08 = Vrab14 + Vrab11;
             if(Vrab13 > 0){Vrab07 -= Object[Vrab04].Data->file_Index[Vrab13 - 1]; if(Vrab14 != rinsize(-1)) Vrab08 -= Object[Vrab04].Data->file_Index[Vrab13 - 1];}
             Vrab09 = Object[Vrab04].Data->file[Vrab13].w; Vrab10 = Object[Vrab04].Data->file[Vrab13].h;
            }
           }
           if(Vrab06 != rinsize(-1))
           {
            Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW());
            Vect01[Vrab01].Type = true;
            Vect01[Vrab01].Object = std::make_unique < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW_OBJECT > ();
            Vect01[Vrab01].Object->Flip = 1;
            Vect01[Vrab01].Object->Trans = 63;
            Vect01[Vrab01].Object->Pic = Vrab07; Vect01[Vrab01].Object->Pic_M = Vrab08;
            if(Object[Vrab04].Facing)
            {
             Vect01[Vrab01].Object->Facing = true;
             Vect01[Vrab01].Object->X = L_Rounding64(Object[Vrab04].X) - Object[Vrab04].Data->Frame[Vrab06].centerx;
            } else
            {
             Vect01[Vrab01].Object->Facing = false;
             Vect01[Vrab01].Object->X = L_Rounding64(Object[Vrab04].X) + Object[Vrab04].Data->Frame[Vrab06].centerx - Vrab09;
            }
            Vect01[Vrab01].Object->Z = L_Rounding64(Object[Vrab04].Z);
            Vect01[Vrab01].Object->Y = Vect01[Vrab01].Object->Z - L_Rounding64(Object[Vrab04].Y * 0.4) + L_Rounding64(rxint64(Object[Vrab04].Data->Frame[Vrab06].centery) * 0.4) - L_Rounding64(rxint64(Vrab10) * 0.7);
            {statics xint64 Vrab11 = rxint64(Object[Vrab04].Data->Frame[Vrab06].centery) / 2; Vect01[Vrab01].Object->Y -= L_Rounding64((Vrab11 * Object[Vrab04].Scale) - Vrab11);}
            Vect01[Vrab01].Object->W = L_Rounding64(rxint64(Vrab09) * Object[Vrab04].Scale) - Vrab09;
            Vect01[Vrab01].Object->H = -L_Rounding64(rxint64(Vrab10) * 0.6);
            Vrab01 += 1;
           }
          }
          Vrab03 += 1;
         }
        }
       //-/*/
      }

      return Vect01;
     }
     int1   Warning()                                                                fastened {return Vrab003;}
     int1   Select(statics insize Vrab01, statics uint8 Vrab02)                      fastened
     {
      if(Vrab02 == 0)
      {
       All_Char.push_back(true);
       if((Vrab01 >= 0 && Vrab01 <= 29) || Vrab01 >= 100){Selectable_Char.push_back(true); return true;} else {Selectable_Char.push_back(false);}
      } else {All_Char.push_back(false); Selectable_Char.push_back(false);}
      return false;
     }
     int1   Random(statics insize Vrab01)                                            fastened {statics insize Vrab02 = Objects[Vrab01].id; if(!All_Char[Vrab01] || Vrab02 == 0 || (Vrab02 >= 30 && Vrab02 <= 99)) return false; return true;}
     uint8  Pick(statics insize Vrab01, statics int1 Vrab02 = true)                  fastened
     {
      if(Vrab02)
      {
       if(Vrab01 >= Selectable_Char.size()) return 2;
       if(Selectable_Char[Vrab01]) return 1; return 0;
      } else
      {
       if(Vrab01 >= All_Char.size()) return 2;
       if(All_Char[Vrab01]) return 1; return 0;
      }
     }
     insize Face(statics insize Vrab01)                                              fastened {return Objects[Vrab01].head_Index;}
     insize Range(statics int1 Vrab01 = true)                                        fastened {if(Vrab01) return Selectable_Char.size(); return All_Char.size();}
     insize Limit()                                                                  fastened {return Backgrounds.size();}
     string Name(statics insize Vrab01)                                              fastened {return Objects[Vrab01].name;}
     string Place(statics insize Vrab01)                                             fastened {return Backgrounds[Vrab01].name;}
     uint8  New(statics insize Vrab01, statics uint8 Vrab02, statics string &Temp01) fastened
     {
      statics uint8 Vrab03 = Decode(Temp01); if(Vrab03 < 4) return Vrab03;
      Vrab001 = Objects.size(); Vrab002 = 0; Vrab004 = 0; Objects.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT());
      Objects[Vrab001].id = Vrab01; Objects[Vrab001].type = Vrab02; Vect001.clear();
      std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app);
      if(File01.is_open()){File01 << "[] INFO - Processing \"" + Temp01 + "\" object into the system.\n"; insize Vrab04 = Objects.size() - 1; while(Vrab04 != 0){Vrab04 -= 1; if(Objects[Vrab04].id == Vrab01){Vrab003 = true; File01 << ")( WARNING - ID used by this object, \"id: " + std::to_string(Vrab01) + "\", already used by another object(s) above, this object might not be used in the game.\n"; break;}}}
      return 0;
     }
     uint8  Create(statics insize Vrab01, statics string &Temp01)                    fastened
     {
      statics uint8 Vrab02 = Decode(Temp01); if(Vrab02 < 4) return Vrab02;
      Vrab001 = Backgrounds.size(); Vrab002 = 0; Vrab004 = 0; Backgrounds.resize(Vrab001 + 1);
      Backgrounds[Vrab001].id = Vrab01; Animation.push_back(std::vector < uint32 >());
      std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); if(File01.is_open()){File01 << "[] INFO - Processing \"" + Temp01 + "\" background into the system.\n";}
      return 0;
     }
     string Load(statics string Temp01, statics int1 Vrab01)                         fastened
     {
      int1 Vrab02 = false; string Temp02, Temp03 = "E"; insize Vrab03 = 0, Vrab04 = 0;
      while(File001)
      {
       if(Vrab002 != 99ui8){File001 >> Temp02; if(!File001) break; if(Temp02.at(0) == '#'){std::getline(File001, Temp02); continue;} if(Temp02.size() > 1) if(Temp02.at(0) == '/' && Temp02.at(1) == '/'){std::getline(File001, Temp02); continue;}} else
       {
        statics insize Vrab05 = Objects[Vrab001].file_Index.size();
        if(Vrab05 == Objects[Vrab001].file.size()){Vrab002 = 0; continue;} else
        {
         Objects[Vrab001].file_Index.resize(Vrab05 + 1);
         Temp02 = Temp01 + Objects[Vrab001].file[Vrab05].address; if(Objects[Vrab001].file[Vrab05].row == 0) Objects[Vrab001].file[Vrab05].row = 1; if( Objects[Vrab001].file[Vrab05].col == 0)  Objects[Vrab001].file[Vrab05].col = 1;
         statics insize Vrab06 = G_Load_Sprite(Temp02, Objects[Vrab001].file[Vrab05].row, Objects[Vrab001].file[Vrab05].col, Objects[Vrab001].file[Vrab05].w, Objects[Vrab001].file[Vrab05].h);
         if(Vrab06 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";}} else
         {
          Temp03 = "S"+ Temp02; Objects[Vrab001].file[Vrab05].Picture_Index = Vrab06;
          if(Vrab01) Objects[Vrab001].file[Vrab05].Picture_Mirror_Index = G_Load_Sprite(L_Rename(Temp02, "_mirror"), Objects[Vrab001].file[Vrab05].row, Objects[Vrab001].file[Vrab05].col, Objects[Vrab001].file[Vrab05].w, Objects[Vrab001].file[Vrab05].h);
          Objects[Vrab001].file_Index[Vrab05] = (Objects[Vrab001].file[Vrab05].row * Objects[Vrab001].file[Vrab05].col);
          if(Vrab05 > 0) Objects[Vrab001].file_Index[Vrab05] += Objects[Vrab001].file_Index[Vrab05 - 1];
         }
         Vrab02 = true; break;
        }
       }
       switch(Vrab002)
       {
        case 0:
         if(Temp02 == "<bmp_begin>")               {Vrab002 = 1; continue;}
         if(Temp02 == "<weapon_strength_list>")    {Vrab002 = 2; continue;}
         if(Temp02 == "<frame>")                   {Vrab002 = 3; File001 >> Temp02; statics insize Vrab05 = rinsize(L_Numbering(Temp02)); statics insize Vrab06 = Objects[Vrab001].Frame.size(); if(Vrab06 <= Vrab05){Objects[Vrab001].Frame.insert(Objects[Vrab001].Frame.end(), Vrab05 + 1 - Vrab06, Frames[0].get()); Vect001.resize(Vrab05 + 1);} Vrab03 = Vrab05; if(Objects[Vrab001].Frame[Vrab03] == Frames[0].get()){insize Vrab07 = Frames.size(); Frames.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME >()); Objects[Vrab001].Frame[Vrab03] = Frames[Vrab07].get();} else {*Objects[Vrab001].Frame[Vrab03] = HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME();} if(Objects[Vrab001].Frame[Vrab03]->Exist && !Vect001[Vrab03]){Vect001[Vrab03] = true; Vrab003 = true; std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); if(File01.is_open()){File01 << ")( WARNING - \"<frame> " + std::to_string(Vrab03) + "\" was declared more than once, only the bottom one is going to be used.\n"; File01.close();}} Objects[Vrab001].Frame[Vrab03]->Exist = true; File001 >> Temp02; continue;}
        break;
        case 1:
         if(Temp02 == "<bmp_end>")                 {Vrab002 = 99ui8; continue;}
         if(Temp02 == "name:")                     {File001 >> Objects[Vrab001].name; continue;}
         if(Temp02 == "head:")                     {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_Load_Pic(Temp02); if(Vrab05 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";}} else {Temp03 = "S" + Temp02; Objects[Vrab001].head_Index = Vrab05;} Vrab02 = true; break;}
         if(Temp02 == "small:")                    {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_Load_Pic(Temp02); if(Vrab05 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";}} else {Temp03 = "S" + Temp02; Objects[Vrab001].small_Index = Vrab05;} Vrab02 = true; break;}
         if(string(Temp02, 0, 5) == "file(")       {Vrab03 = Objects[Vrab001].file.size(); Objects[Vrab001].file.resize(Vrab03 + 1); File001 >> Objects[Vrab001].file[Vrab03].address; continue;}
         if(Temp02 == "w:")                        {File001 >> Temp02; if(Objects[Vrab001].file.size() > 0){Objects[Vrab001].file[Vrab03].w = ruint32(L_Numbering(Temp02));} continue;}
         if(Temp02 == "h:")                        {File001 >> Temp02; if(Objects[Vrab001].file.size() > 0){Objects[Vrab001].file[Vrab03].h = ruint32(L_Numbering(Temp02));} continue;}
         if(Temp02 == "row:")                      {File001 >> Temp02; if(Objects[Vrab001].file.size() > 0){Objects[Vrab001].file[Vrab03].row = ruint32(L_Numbering(Temp02));} continue;}
         if(Temp02 == "col:")                      {File001 >> Temp02; if(Objects[Vrab001].file.size() > 0){Objects[Vrab001].file[Vrab03].col = ruint32(L_Numbering(Temp02));} continue;}
         if(Temp02 == "walking_frame_rate")        {File001 >> Temp02; Objects[Vrab001].walking_frame_rate = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "running_frame_rate")        {File001 >> Temp02; Objects[Vrab001].running_frame_rate = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "walking_speed")             {File001 >> Temp02; Objects[Vrab001].walking_speed = L_Doubling(Temp02); continue;}
         if(Temp02 == "walking_speedz")            {File001 >> Temp02; Objects[Vrab001].walking_speedz = L_Doubling(Temp02); continue;}
         if(Temp02 == "running_speed")             {File001 >> Temp02; Objects[Vrab001].running_speed = L_Doubling(Temp02); continue;}
         if(Temp02 == "running_speedz")            {File001 >> Temp02; Objects[Vrab001].running_speedz = L_Doubling(Temp02); continue;}
         if(Temp02 == "heavy_walking_speed")       {File001 >> Temp02; Objects[Vrab001].heavy_walking_speed = L_Doubling(Temp02); continue;}
         if(Temp02 == "heavy_walking_speedz")      {File001 >> Temp02; Objects[Vrab001].heavy_walking_speedz = L_Doubling(Temp02); continue;}
         if(Temp02 == "heavy_running_speed")       {File001 >> Temp02; Objects[Vrab001].heavy_running_speed = L_Doubling(Temp02); continue;}
         if(Temp02 == "heavy_running_speedz")      {File001 >> Temp02; Objects[Vrab001].heavy_running_speedz = L_Doubling(Temp02); continue;}
         if(Temp02 == "jump_height")               {File001 >> Temp02; Objects[Vrab001].jump_height = L_Doubling(Temp02); continue;}
         if(Temp02 == "jump_distance")             {File001 >> Temp02; Objects[Vrab001].jump_distance = L_Doubling(Temp02); continue;}
         if(Temp02 == "jump_distancez")            {File001 >> Temp02; Objects[Vrab001].jump_distancez = L_Doubling(Temp02); continue;}
         if(Temp02 == "dash_height")               {File001 >> Temp02; Objects[Vrab001].dash_height = L_Doubling(Temp02); continue;}
         if(Temp02 == "dash_distance")             {File001 >> Temp02; Objects[Vrab001].dash_distance = L_Doubling(Temp02); continue;}
         if(Temp02 == "dash_distancez")            {File001 >> Temp02; Objects[Vrab001].dash_distancez = L_Doubling(Temp02); continue;}
         if(Temp02 == "rowing_height")             {File001 >> Temp02; Objects[Vrab001].rowing_height = L_Doubling(Temp02); continue;}
         if(Temp02 == "rowing_distance")           {File001 >> Temp02; Objects[Vrab001].rowing_distance = L_Doubling(Temp02); continue;}
         if(Temp02 == "weapon_hp:")                {File001 >> Temp02; Objects[Vrab001].weapon_hp = L_Numbering(Temp02); continue;}
         if(Temp02 == "weapon_drop_hurt:")         {File001 >> Temp02; Objects[Vrab001].weapon_drop_hurt = L_Numbering(Temp02); continue;}
         if(Temp02 == "weapon_hit_sound:")         {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_Load_Sound(Temp02); if(Vrab05 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";} Vrab02 = true; break;} else {Temp03 = "S" + Temp02; Objects[Vrab001].weapon_hit_sound_Index = Vrab05; continue;}}
         if(Temp02 == "weapon_drop_sound:")        {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_Load_Sound(Temp02); if(Vrab05 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";} Vrab02 = true; break;} else {Temp03 = "S" + Temp02; Objects[Vrab001].weapon_drop_sound_Index = Vrab05; continue;}}
         if(Temp02 == "weapon_broken_sound:")      {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_Load_Sound(Temp02); if(Vrab05 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";} Vrab02 = true; break;} else {Temp03 = "S" + Temp02; Objects[Vrab001].weapon_broken_sound_Index = Vrab05; continue;}}
         
         if(Temp02 == "<bmp_begin>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<weapon_strength_list>")    {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 2:
         if(Temp02 == "<weapon_strength_list_end>"){Vrab002 = 0; continue;}
         if(Temp02 == "entry:")                    {File001 >> Temp02; Vrab03 = Objects[Vrab001].Strength.size(); Objects[Vrab001].Strength.resize(Vrab03 + 1); File001 >> Temp02; continue;}
         if(Temp02 == "zwidth:")                   {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].zwidth = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].dvx = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].dvy = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "fall:")                     {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].fall = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "arest:")                    {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].arest = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "vrest:")                    {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].vrest = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "respond:")                  {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].respond = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "effect:")                   {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].effect = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "bdefend:")                  {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].bdefend = L_Numbering(Temp02); continue;} else {break;}}
         if(Temp02 == "injury:")                   {File001 >> Temp02; if(Objects[Vrab001].Strength.size() > 0){Objects[Vrab001].Strength[Vrab03].injury = L_Numbering(Temp02); continue;} else {break;}}
         
         if(Temp02 == "<bmp_begin>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<weapon_strength_list>")    {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 3:
         if(Temp02 == "<frame_end>")               {Vrab002 = 0; continue;}
         if(Temp02 == "pic:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->pic = L_Numbering(Temp02); continue;}
         if(Temp02 == "state:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->state = L_Numbering(Temp02); continue;}
         if(Temp02 == "wait:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wait = L_Numbering(Temp02); continue;}
         if(Temp02 == "next:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->next = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvz:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->dvz = L_Numbering(Temp02); continue;}
         if(Temp02 == "centerx:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->centerx = L_Numbering(Temp02); continue;}
         if(Temp02 == "centery:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->centery = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_a:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_a = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_d:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_d = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_j:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_j = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Fa:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_Fa = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Fj:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_Fj = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Da:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_Da = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Dj:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_Dj = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Ua:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_Ua = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Uj:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_Uj = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_ja:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->hit_ja = L_Numbering(Temp02); continue;}
         if(Temp02 == "mp:")                       {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->mp = L_Numbering(Temp02); continue;}
         if(Temp02 == "sound:")                    {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_Load_Sound(Temp02); if(Vrab05 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";} Vrab02 = true; break;} else {Temp03 = "S" + Temp02; Objects[Vrab001].Frame[Vrab03]->sound_Index = Vrab05; continue;}}
         if(Temp02 == "ppoint:")                   {Vrab002 = 12; Vrab04 = Objects[Vrab001].Frame[Vrab03]->ppoint.size(); Objects[Vrab001].Frame[Vrab03]->ppoint.resize(Vrab04 + 1); continue;}
									if(Temp02 == "bpoint:")                   {Vrab002 = 4; Vrab04 = Objects[Vrab001].Frame[Vrab03]->bpoint.size(); Objects[Vrab001].Frame[Vrab03]->bpoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "cpoint:")                   {Vrab002 = 5; Vrab04 = Objects[Vrab001].Frame[Vrab03]->cpoint.size(); Objects[Vrab001].Frame[Vrab03]->cpoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "wpoint:")                   {Vrab002 = 6; Vrab04 = Objects[Vrab001].Frame[Vrab03]->wpoint.size(); Objects[Vrab001].Frame[Vrab03]->wpoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "opoint:")                   {Vrab002 = 7; Vrab04 = Objects[Vrab001].Frame[Vrab03]->opoint.size(); Objects[Vrab001].Frame[Vrab03]->opoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "itr:")                      {Vrab002 = 8; Vrab04 = Objects[Vrab001].Frame[Vrab03]->itr.size(); Objects[Vrab001].Frame[Vrab03]->itr.resize(Vrab04 + 1); continue;}
         if(Temp02 == "bdy:")                      {Vrab002 = 9; Vrab04 = Objects[Vrab001].Frame[Vrab03]->bdy.size(); Objects[Vrab001].Frame[Vrab03]->bdy.resize(Vrab04 + 1); continue;}
         
         if(Temp02 == "<bmp_begin>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<weapon_strength_list>")    {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
        break;
								case 12:
         if(Temp02 == "ppoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "pic:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->ppoint[Vrab04].pic = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->ppoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->ppoint[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "w:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->ppoint[Vrab04].w = L_Numbering(Temp02); continue;}
         if(Temp02 == "h:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->ppoint[Vrab04].h = L_Numbering(Temp02); continue;}
         if(Temp02 == "rotate:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->ppoint[Vrab04].rotate = L_Numbering(Temp02); continue;}
         if(Temp02 == "trans:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->ppoint[Vrab04].trans = L_Numbering(Temp02); continue;}
									
         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "ppoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
								break;
        case 4:
         if(Temp02 == "bpoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->bpoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->bpoint[Vrab04].y = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "ppoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 5:
         if(Temp02 == "cpoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "vaction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].vaction = L_Numbering(Temp02); continue;}
         if(Temp02 == "aaction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].aaction = L_Numbering(Temp02); continue;}
         if(Temp02 == "daction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].daction = L_Numbering(Temp02); continue;}
         if(Temp02 == "jaction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].jaction = L_Numbering(Temp02); continue;}
         if(Temp02 == "taction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].taction = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwvx:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].throwvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwvy:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].throwvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwvz:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].throwvz = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwinjury:")              {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].throwinjury = L_Numbering(Temp02); continue;}
         if(Temp02 == "dircontrol:")               {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].dircontrol = L_Numbering(Temp02); continue;}
         if(Temp02 == "hurtable:")                 {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].hurtable = L_Numbering(Temp02); continue;}
         if(Temp02 == "decrease:")                 {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].decrease = L_Numbering(Temp02); continue;}
         if(Temp02 == "cover:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].cover = L_Numbering(Temp02); continue;}
         if(Temp02 == "injury:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].injury = L_Numbering(Temp02); continue;}
         if(Temp02 == "fronthurtact:")             {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].fronthurtact = L_Numbering(Temp02); continue;}
         if(Temp02 == "backhurtact:")              {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->cpoint[Vrab04].backhurtact = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "ppoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 6:
         if(Temp02 == "wpoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvz:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].dvz = L_Numbering(Temp02); continue;}
         if(Temp02 == "weaponact:")                {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].weaponact = L_Numbering(Temp02); continue;}
         if(Temp02 == "attacking:")                {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].attacking = L_Numbering(Temp02); continue;}
         if(Temp02 == "cover:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->wpoint[Vrab04].cover = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "ppoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 7:
         if(Temp02 == "opoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "oid:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].oid = L_Numbering(Temp02); continue;}
         if(Temp02 == "action:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].action = L_Numbering(Temp02); continue;}
         if(Temp02 == "facing:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->opoint[Vrab04].facing = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "ppoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 8: case 10: case 11:
         if(Temp02 == "itr_end:")                  {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "w:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].w = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "h:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].h = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "zwidth:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].zwidth = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "fall:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].fall = L_Numbering(Temp02); continue;}
         if(Temp02 == "arest:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].arest = L_Numbering(Temp02); continue;}
         if(Temp02 == "vrest:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].vrest = L_Numbering(Temp02); continue;}
         if(Temp02 == "respond:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].respond = L_Numbering(Temp02); continue;}
         if(Temp02 == "effect:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].effect = L_Numbering(Temp02); continue;}
         if(Temp02 == "bdefend:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].bdefend = L_Numbering(Temp02); continue;}
         if(Temp02 == "injury:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].injury = L_Numbering(Temp02); continue;}
         if(Temp02 == "catchingact:")              {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].catchingact[0] = L_Numbering(Temp02); Vrab002 = 10; continue;}
         if(Temp02 == "caughtact:")                {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].caughtact[0] = L_Numbering(Temp02); Vrab002 = 11; continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "ppoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}

         if(Vrab002 == 10){Vrab002 = 8; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].catchingact[1] = L_Numbering(Temp02); continue;}
         if(Vrab002 == 11){Vrab002 = 8; Objects[Vrab001].Frame[Vrab03]->itr[Vrab04].caughtact[1] = L_Numbering(Temp02); continue;}
        break;
        case 9:
         if(Temp02 == "bdy_end:")                  {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->bdy[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->bdy[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->bdy[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "w:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->bdy[Vrab04].w = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "h:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03]->bdy[Vrab04].h = ruint32(L_Numbering(Temp02)); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "ppoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        default: break;
       }
       if(Vrab02){break;} else {if(Vrab004 != 11){std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); Vrab003 = true; if(!File01.is_open()) continue; if(Vrab004 == 10){Vrab004 += 1; File01 << ")( WARNING - Too many unknown syntax founds.\n";} else
       {
        Vrab004 += 1;
        switch(Vrab002)
        {
         case 1: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in \"<bmp_begin>\".\n"; break;
         case 2: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found after \"entry: " + std::to_string(Vrab03) + "\".\n"; break;
         case 3: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
         case 12: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"ppoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
         case 4: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"bpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
         case 5: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"cpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
         case 6: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"wpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
         case 7: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"opoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
									case 8: case 10: case 11: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"itr:\" in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
         case 9: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"bdy:\" in \"<frame> " + std::to_string(Vrab03) + "\".\n"; break;
         default: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found.\n"; break;
        }
       } File01.close();}}
      }
      if(Vrab02 && Vrab002 < 100){return Temp03;} else
      {
       switch((Vrab002 % 100))
       {
        case 1: return "E\"<bmp_begin>\"|0|Unexpected end of \"<bmp_begin>\", it should be end with \"<bmp_end>\".";
        case 2: return "E\"<weapon_strength_list>\"|0|Unexpected end of \"<weapon_strength_list>\", it should be end with \"<weapon_strength_list_end>\".";
        case 3: return "E\"<frame>\"|0|Unexpected end of \"<frame> " + std::to_string(Vrab03) + "\", it should be end with \"<frame_end>\".";
        case 12: return "E\"bpoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"ppoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 4: return "E\"bpoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"bpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 5: return "E\"cpoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"cpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 6: return "E\"wpoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"wpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 7: return "E\"opoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"opoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
								case 8: case 10: case 11: return "E\"itr:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"itr:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 9: return "E\"bdy:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"bdy:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        default: File001.close(); return "D";
       }
      }
     }
     string Manage(statics string Temp01)                                            fastened
     {
      int1 Vrab01 = false; string Temp02, Temp03 = "E"; insize Vrab02 = 0;
      while(File001)
      {
       File001 >> Temp02; if(!File001) break; if(Temp02.at(0) == '#'){std::getline(File001, Temp02); continue;} if(Temp02.size() > 1) if(Temp02.at(0) == '/' && Temp02.at(1) == '/'){std::getline(File001, Temp02); continue;}
       switch(Vrab002)
       {
        case 0: case 1: case 2: case 3: case 4: case 5:
         if(Temp02 == "name:")       {File001 >> Backgrounds[Vrab001].name; continue;}
         if(Temp02 == "width:")      {File001 >> Temp02; Backgrounds[Vrab001].width = L_Numbering(Temp02); continue;}
         if(Temp02 == "zboundary:")  {File001 >> Temp02; Vrab002 = 1; Backgrounds[Vrab001].zboundary[0] = L_Numbering(Temp02); continue;}
         if(Temp02 == "perspective:"){File001 >> Temp02; Vrab002 = 2; Backgrounds[Vrab001].perspective[0] = L_Numbering(Temp02); continue;}
         if(Temp02 == "shadow:")     {File001 >> Temp02; Vrab002 = 3; Temp02 = Temp01 + Temp02; statics insize Vrab03 = G_Load_Pic(Temp02); if(Vrab03 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E"+ Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible.";}} else {Temp03 = "S"+ Temp02; Backgrounds[Vrab001].shadow_Index = Vrab03;} Vrab01 = true; break;}
         if(Temp02 == "layer:")      {File001 >> Temp02; Vrab002 = 6; Temp02 = Temp01 + Temp02; statics insize Vrab03 = G_Load_Pic(Temp02); if(Vrab03 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E"+ Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible.";}} else {Temp03 = "S"+ Temp02; statics insize Vrab04 = Backgrounds[Vrab001].Layer.size(); Backgrounds[Vrab001].Layer.resize(Vrab04 + 1); Backgrounds[Vrab001].Layer[Vrab04].image_Index = Vrab03;} Vrab01 = true; break;}
         if(Vrab002 == 1){Vrab002 = 0; Backgrounds[Vrab001].zboundary[1] = L_Numbering(Temp02); continue;}
         if(Vrab002 == 2){Vrab002 = 0; Backgrounds[Vrab001].perspective[1] = L_Numbering(Temp02); continue;}
         if(Vrab002 == 3){Vrab002 = 4; continue;}
         if(Vrab002 == 4){Vrab002 = 5; Backgrounds[Vrab001].shadowsize[0] = L_Numbering(Temp02); continue;}
         if(Vrab002 == 5){Vrab002 = 0; Backgrounds[Vrab001].shadowsize[1] = L_Numbering(Temp02); continue;}
        break;
        case 6: Vrab02 = Backgrounds[Vrab001].Layer.size() - 1; Vrab002 = 7;
        case 7:
         if(Temp02 == "layer_end")    {Vrab002 = 0; continue;}
         if(Temp02 == "transparency:"){File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].transparency = L_Numbering(Temp02); continue;}
         if(Temp02 == "width:")       {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].width = L_Numbering(Temp02); continue;}
         if(Temp02 == "height:")      {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].height = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")           {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")           {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "loop:")        {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].loop = L_Numbering(Temp02); continue;}
         if(Temp02 == "cc:")          {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].cc = L_Numbering(Temp02); continue;}
         if(Temp02 == "c1:")          {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].c1 = L_Numbering(Temp02); continue;}
         if(Temp02 == "c2:")          {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].c2 = L_Numbering(Temp02); continue;}
         if(Temp02 == "rect:")        
         {
          File001 >> Temp02; statics uint32 Vrab03 = ruint32(L_Numbering(Temp02));
          uint32 Vrab04 = 0; uint32 Vrab05 = 0; uint32 Vrab06 = 0;
          switch(Vrab03)
          {
           case 4706:  Vrab04 = 16;  Vrab05 = 79;  Vrab06 = 16;  break; // Lion Forest.
           case 40179: Vrab04 = 157; Vrab05 = 159; Vrab06 = 161; break; // HK Coliseum
           case 29582: Vrab04 = 119; Vrab05 = 119; Vrab06 = 119; break; // -
           case 37773: Vrab04 = 151; Vrab05 = 119; Vrab06 = 111; break; // -
           case 33580: Vrab04 = 135; Vrab05 = 107; Vrab06 = 103; break; // -
           case 25356: Vrab04 = 103; Vrab05 = 103; Vrab06 = 103; break; // -
           case 21096: Vrab04 = 90;  Vrab05 = 78;  Vrab06 = 75;  break; // Stanley Prison.
           case 37770: Vrab04 = 154; Vrab05 = 110; Vrab06 = 90;  break; // The Great Wall.
           case 16835: Vrab04 = 66;  Vrab05 = 56;  Vrab06 = 24;  break; // Queen's Island.
           case 34816: Vrab04 = 143; Vrab05 = 7;   Vrab06 = 7;   break; // Forbidden Tower.
           default:
            Vrab04 = (Vrab03 >> 11 << 3) + 10; Vrab05 = ((Vrab03 >> 6 & 31) << 3) - 2; Vrab06 = ((Vrab03 & 31) << 3) + 10; // Blue  161   75   90
           break;
          }
          Backgrounds[Vrab001].Layer[Vrab02].rect32 = Vrab06 + (Vrab05 << 8) + (Vrab04 << 16);
          continue;
         }
         if(Temp02 == "rect32:")      {File001 >> Temp02; Backgrounds[Vrab001].Layer[Vrab02].rect32 = L_Numbering(Temp02); continue;}
         if(Temp02 == "layer:")       {Vrab002 += 100; Vrab01 = true; break;}
        break;
        default: break;
       }
       if(Vrab01){break;} else {if(Vrab004 != 11){std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); Vrab003 = true; if(!File01.is_open()) continue; if(Vrab004 == 10){Vrab004 += 1; File01 << ")( WARNING - Too many unknown syntax founds.\n";} else
       {
        Vrab004 += 1;
        switch(Vrab002)
        {
         case 7: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab02 + 1) + " \"layer:\".\n"; break;
         default: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found.\n"; break;
        }
       } File01.close();}}
      }
      if(Vrab01 && Vrab002 < 100){return Temp03;} else
      {
       switch((Vrab002 % 100))
       {
        case 7: return "E\"layer:\"|0|Unexpected end of " + L_Number(Vrab02 + 1) + " \"layer:\", it should ended with \"layer_end\".";
        default: File001.close(); return "D";
       }
      }
     }
     string Finalizer(statics string Temp01)                                                 fastened 
     {
      {
       {std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); if(File01.is_open()){File01 << "[] INFO - Processing hardcoded datas into the system.\n"; File01.close();}}
       string Temp02 = ""; int1 Vrab01 = false;
       {
        statics string Temp03 = Temp01 + "data\\"; statics string Temp04 = ".wav";
        {statics string Temp05 = Temp03 + "017" + Temp04; statics insize Vrab02 = G_Load_Sound(Temp05); Sounds.push_back(Vrab02); if(Vrab02 == rinsize(-1)){Vrab01 = true; if(L_Exist(Temp05)){Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", either there's no remaining memory to load or unsupported file format.\n";} else {Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", Either the following file cannot be found or inaccessible.\n";}}}
       }
       {
        statics string Temp03 = Temp01 + "interface\\"; statics string Temp04 = ".bmp";
        {statics string Temp05 = Temp03 + "DEMO" + Temp04; statics insize Vrab02 = G_Load_Pic(Temp05); Pics.push_back(Vrab02); if(Vrab02 == rinsize(-1)){Vrab01 = true; if(L_Exist(Temp05)){Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", either there's no remaining memory to load or unsupported file format.\n";} else {Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", Either the following file cannot be found or inaccessible.\n";}}}
        {statics string Temp05 = Temp03 + "PAUSE" + Temp04; statics insize Vrab02 = G_Load_Pic(Temp05); Pics.push_back(Vrab02); if(Vrab02 == rinsize(-1)){Vrab01 = true; if(L_Exist(Temp05)){Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", either there's no remaining memory to load or unsupported file format.\n";} else {Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", Either the following file cannot be found or inaccessible.\n";}}}
        {statics string Temp05 = Temp03 + "SPARK" + Temp04; statics insize Vrab02 = G_Load_Sprite(Temp05, 6, 6, 90, 60); Pics.push_back(Vrab02); if(Vrab02 == rinsize(-1)){Vrab01 = true; if(L_Exist(Temp05)){Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", either there's no remaining memory to load or unsupported file format.\n";} else {Temp02 += ")( WARNING - Error while processing \"" + Temp05 + "\", Either the following file cannot be found or inaccessible.\n";}}}
       }
       if(Vrab01)
       {
        Vrab003 = true; std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); if(File01.is_open()){File01 << Temp02; File01.close();}
       }
      }
      {
       Vect001.clear();
       insize Vrab01 = Objects.size(); 
       while(Vrab01 != 0)
       {
        Vrab01 -= 1; insize Vrab02 = Objects[Vrab01].Frame.size();
        while(Vrab02 != 0)
        {
         Vrab02 -= 1;
         if(!Objects[Vrab01].Frame[Vrab02]->Exist) continue;
         insize Vrab03 = Objects[Vrab01].Frame[Vrab02]->bdy.size();
         if(Vrab03 > 0)
         {
          int32 Vrab04 = 0x7FFFFFFF, Vrab05 = 0x7FFFFFFF, Vrab06 = 0x80000000, Vrab07 = 0x80000000;
          while(Vrab03 != 0)
          {
           Vrab03 -= 1;
           statics int32 Vrab08 = Objects[Vrab01].Frame[Vrab02]->bdy[Vrab03].x;
           statics int32 Vrab09 = Objects[Vrab01].Frame[Vrab02]->bdy[Vrab03].y;
           if(Vrab04 > Vrab08) Vrab04 = Vrab08;
           if(Vrab05 > Vrab09) Vrab05 = Vrab09;
           statics uint32 Vrab10 = ruint32(Objects[Vrab01].Frame[Vrab02]->bdy[Vrab03].w);
           statics uint32 Vrab11 = ruint32(Objects[Vrab01].Frame[Vrab02]->bdy[Vrab03].h);
           if(Vrab08 + rint32(Vrab10) > Vrab06) Vrab06 = Vrab08 + rint32(Vrab10);
           if(Vrab09 + rint32(Vrab11) > Vrab07) Vrab07 = Vrab09 + rint32(Vrab11);
          }
          Objects[Vrab01].Frame[Vrab02]->bdy_X = Vrab04;
          Objects[Vrab01].Frame[Vrab02]->bdy_Y = Vrab05;
          Objects[Vrab01].Frame[Vrab02]->bdy_W = Vrab06 - Vrab04;
          Objects[Vrab01].Frame[Vrab02]->bdy_H = Vrab07 - Vrab05;
         }
         Vrab03 = Objects[Vrab01].Frame[Vrab02]->itr.size();
         if(Vrab03 > 0)
         {
          int32 Vrab04 = 0x7FFFFFFF, Vrab05 = 0x7FFFFFFF, Vrab06 = 0x80000000, Vrab07 = 0x80000000; uint32 Vrab08 = 0;
          while(Vrab03 != 0)
          {
           Vrab03 -= 1;
           statics int32 Vrab09 = Objects[Vrab01].Frame[Vrab02]->itr[Vrab03].x;
           statics int32 Vrab10 = Objects[Vrab01].Frame[Vrab02]->itr[Vrab03].y;
           if(Vrab09 < Vrab04) Vrab04 = Vrab09;
           if(Vrab10 < Vrab05) Vrab05 = Vrab10;
           statics uint32 Vrab11 = ruint32(Objects[Vrab01].Frame[Vrab02]->itr[Vrab03].w);
           statics uint32 Vrab12 = ruint32(Objects[Vrab01].Frame[Vrab02]->itr[Vrab03].h);
           if(Vrab09 + rint32(Vrab11) > Vrab06) Vrab06 = Vrab09 + rint32(Vrab11);
           if(Vrab10 + rint32(Vrab12) > Vrab07) Vrab07 = Vrab10 + rint32(Vrab12);
           uint32 Vrab13 = Objects[Vrab01].Frame[Vrab02]->itr[Vrab03].zwidth; if(Vrab13 == 0) Vrab13 = 15;
           if(Vrab08 < Vrab13) Vrab08 = Vrab13;
          }
          Objects[Vrab01].Frame[Vrab02]->itr_X = Vrab04;
          Objects[Vrab01].Frame[Vrab02]->itr_Y = Vrab05;
          Objects[Vrab01].Frame[Vrab02]->itr_W = Vrab06 - Vrab04;
          Objects[Vrab01].Frame[Vrab02]->itr_H = Vrab07 - Vrab05;
          Objects[Vrab01].Frame[Vrab02]->itr_Z = Vrab08;
         }
        }
       }
      }
      {
       string Temp02 = Temp01 + "data\\stagez.dat"; if(!L_Exist(Temp02)) Temp02 = Temp01 + "data\\stage.txt";
       {std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); if(File01.is_open()){if(L_Exist(Temp02)){File01 << "[] INFO - Processing \"" + Temp02 + "\" into the system.\n";} else {File01 << "[] INFO - Cannot find \"" + Temp01 + "data\\stagez.dat\" nor \"" + Temp02 + "\", resuming without Stage.\n";} File01.close();}}
       switch(Decode(Temp02))
       {
        case 1: Stages = std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE > (); return "F";
        case 2: return "D";
        case 3: return "E" + Temp02 + "|1|Failed to execute the decoding, make sure the following file has no error.";
        default: break;
       }
       Vrab001 = 0; Vrab002 = 0; Vrab004 = 0; Stages = std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE > ();
       int1 Vrab01 = false; string Temp03 = "E"; insize Vrab02 = rinsize(-1); insize Vrab03 = rinsize(-1);
       while(File001)
       {
        File001 >> Temp02; if(!File001) break; if(Temp02.at(0) == '#'){std::getline(File001, Temp02); continue;} if(Temp02.size() > 1) if(Temp02.at(0) == '/' && Temp02.at(1) == '/'){std::getline(File001, Temp02); continue;}
        switch(Vrab002)
        {
         case 0:
          if(Temp02 == "<stage>"){Vrab002 = 1; Vrab001 = Stages->Stage.size(); Stages->Stage.resize(Vrab001 + 1); continue;}
         break;
         case 1:
          if(Temp02 == "<stage_end>"){Vrab002 = 0; continue;}
          if(Temp02 == "id:")        {File001 >> Temp02; Stages->Stage[Vrab001].id = L_Numbering(Temp02); continue;}
          if(Temp02 == "<phase>")    {Vrab002 = 2; Vrab02 = Stages->Stage[Vrab001].Phase.size(); Stages->Stage[Vrab001].Phase.resize(Vrab02 + 1); Vrab03 = rinsize(-1); continue;}
         
          if(Temp02 == "<stage>")    {Vrab002 += 100; Vrab01 = true; break;}
         break;
         case 2:
          if(Temp02 == "<phase_end>")           {Vrab002 = 1; continue;}
          if(Temp02 == "bound:")                {File001 >> Temp02; Stages->Stage[Vrab001].Phase[Vrab02].bound = L_Numbering(Temp02); continue;}
          if(Temp02 == "music:")                {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab04 = G_Load_Sound(Temp02); if(Vrab04 == rinsize(-1)){if(L_Exist(Temp02)){Temp03 = "E" + Temp02 + "|1|Either there's no remaining memory to load or unsupported file format.";} else {Temp03 = "E" + Temp02 + "|1|Either the following file cannot be found or inaccessible.";} Vrab01 = true; break;} else {Stages->Stage[Vrab001].Phase[Vrab02].music_Index = Vrab04; continue;}}
          if(Temp02 == "when_clear_goto_phase:"){File001 >> Temp02; Stages->Stage[Vrab001].Phase[Vrab02].when_clear_goto_phase = L_Numbering(Temp02); continue;}
          if(Temp02 == "id:")                   {File001 >> Temp02; Vrab03 = Stages->Stage[Vrab001].Phase[Vrab02].Entity.size(); Stages->Stage[Vrab001].Phase[Vrab02].Entity.resize(Vrab03 + 1); Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].id = L_Numbering(Temp02); continue;}
          if(Temp02 == "x:")                    {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].x = L_Numbering(Temp02); continue;}
          if(Temp02 == "y:")                    {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].y = L_Numbering(Temp02); continue;}
          if(Temp02 == "act:")                  {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].act = L_Numbering(Temp02); continue;}
          if(Temp02 == "hp:")                   {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].hp = L_Numbering(Temp02); continue;}
          if(Temp02 == "times:")                {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].times = L_Numbering(Temp02); continue;}
          if(Temp02 == "reserve:")              {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].reserve = L_Numbering(Temp02); continue;}
          if(Temp02 == "join:")                 {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].join = L_Numbering(Temp02); continue;}
          if(Temp02 == "join_reserve:")         {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].join_reserve = L_Numbering(Temp02); continue;}
          if(Temp02 == "ratio:")                {File001 >> Temp02; if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].ratio = L_Doubling(Temp02); continue;}
          if(Temp02 == "<soldier>")             {if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].Class = 1; continue;}
          if(Temp02 == "<boss>")                {if(Vrab03 != rinsize(-1)) Stages->Stage[Vrab001].Phase[Vrab02].Entity[Vrab03].Class = 2; continue;}
        
          if(Temp02 == "<stage>")               {Vrab002 += 100; Vrab01 = true; break;}
          if(Temp02 == "<phase>")               {Vrab002 += 100; Vrab01 = true; break;}
         break;
         default: break;
        }
        if(Vrab01){break;} else {if(Vrab004 != 11){std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); Vrab003 = true; if(!File01.is_open()) continue; if(Vrab004 == 10){Vrab004 += 1; File01 << ")( WARNING - Too many unknown syntax founds.\n";} else
        {
         Vrab004 += 1;
         switch(Vrab002)
         {
          case 1: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in \"<stage> id: " + std::to_string(Stages->Stage[Vrab001].id) + "\".\n"; break;
          case 2: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab02 + 1) + " \"<phase>\" in \"<stage> id: " + std::to_string(Stages->Stage[Vrab001].id) + "\".\n"; break;
          default: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found.\n"; break;
         }
        } File01.close();}}
       }
       if(Vrab01 && Vrab002 < 100){return Temp03;} else
       {
        switch((Vrab002 % 100))
        {
         case 1: return "E\"<stage>\"|0|Unexpected end of \"<stage> id: "+ std::to_string(Stages->Stage[Vrab001].id) +"\", it should ended with \"<stage_end>\".";
         case 2: return "E\"<phase>\"|0|Unexpected end of " + L_Number(Vrab02 + 1) + " \"<phase>\" in \"<stage> id: " + std::to_string(Stages->Stage[Vrab001].id) + "\".";
         default: File001.close(); return "D";
        }
       }
      }
     }
     int1   Staging()                                                                fastened {return Stages->Stage.size() != 0;}
     int1   Reset()                                                                  fastened {statics int1 Vrab01 = Move; Move = false; return Vrab01;}
     string Info()                                                                   fastened {return "Origin Version : v2.1b.";}
     uint8  Frame()                                                                  fastened {if(Polish){switch(Speed){case 0: return 1ui8; case 1: return 2ui8; case 3: return 8ui8; case 4: return 16ui8; default: return 4ui8;}} else {switch(Speed){case 0: return 4ui8; case 1: return 8ui8; case 3: return 32ui8; case 4: return 64ui8; default: break;}} return 16ui8;}
     int64  Area()                                                                   fastened {return Backgrounds[Background].width;} 
     string Text(statics uint8 Vrab01)                                               fastened {string Temp01 = ""; switch(Vrab01){case 0: Temp01 = "5|0|Versus (" + string((Difficult > 0) ? (Difficult > 1 ? (Difficult > 2 ? "CRAZY!" : "Hard") : "Normal") : "Easy") + ")"; break; case 1: {string Temp02 = "", Temp03 = "", Temp04 = "", Temp05 = ""; Temp02 = std::to_string((Gametime / 3) % 10); statics uint64 Vrab02 = (Gametime / 30) % 60; if(Vrab02 < 10) Temp03 = "0"; Temp03 += std::to_string(Vrab02); statics uint64 Vrab03 = (Gametime / 1800) % 60; if(Vrab03 < 10) Temp04 = "0"; Temp04 += std::to_string(Vrab03); statics uint64 Vrab04 = (Gametime / 108000); if(Vrab04 > 0){Temp05 = std::to_string(Vrab04);} Temp01 = "4|0|" + (Temp05 != "" ? (Temp05 + ":") : "") + Temp04 + ":" + Temp03 + "." + Temp02 + (Gametime % 3 == 0 ? "00" : (Gametime % 3 == 1 ? "33" : "67"));} break; case 2: Temp01 = "3|0|" + L_Revoke(Backgrounds[Background].name, '_', ' '); break; default: break;} return Temp01;}
     int0   Angel(asIScriptEngine *Engi01, asIScriptEngine *Engi02, asIScriptEngine *Engi03, unique < HEPTA_LF2_ENCHANTED_ENGINE1 > Uniq01) fastened
     {
      Engi03->Release();
      uint8 Vrab01 = 0;
      while(Vrab01 != 2)
      {
       int1 Vrab02 = false;
       asIScriptEngine *Engi04 = NULL;
       switch(Vrab01)
       {
        case 0: Engi04 = Engi01; break;
        case 1: Engi04 = Engi02; Vrab02 = true; break;
        default: break;
       }
       Vrab01 += 1;

       Engi04->RegisterObjectType("ENGINE", 0, asOBJ_REF | asOBJ_NOCOUNT);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(bool Value)",   asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (int1 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(int8 Value)",   asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (int8 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(int16 Value)",  asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (int16 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(int32 Value)",  asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (int32 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(int64 Value)",  asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (int64 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(uint8 Value)",  asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (uint8 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(uint16 Value)", asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (uint16 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(uint32 Value)", asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (uint32 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(uint64 Value)", asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (uint64 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(float Value)",  asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (xint32 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(double Value)", asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (xint64 Vrab01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print(const string &in String)", asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE1, C_Print, (statics string &Temp01), int0), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Print_Clear()",       asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, C_Clear), asCALL_THISCALL);

       Engi04->RegisterObjectMethod("ENGINE", "void Input_Clear()",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputClear), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Up()",           asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputUP), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Left()",         asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputLEFT), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Down()",         asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputDOWN), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Right()",        asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputRIGHT), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Attack()",       asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputATTACK), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Defend()",       asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputDEFEND), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Jump()",         asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputJUMP), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Command()",      asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputCOMMAND), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Up_Hold()",      asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputUPH), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Left_Hold()",    asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputLEFTH), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Down_Hold()",    asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputDOWNH), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Right_Hold()",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputRIGHTH), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Attack_Hold()",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputATTACKH), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Defend_Hold()",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputDEFENDH), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Jump_Hold()",    asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputJUMPH), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "void Command_Hold()", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_InputCOMMANDH), asCALL_THISCALL);

       Engi04->RegisterObjectMethod("ENGINE", "int32 Random(int32 Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Random), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int32 Set_Enemy(int32 Object)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Aggring), asCALL_THISCALL);

       Engi04->RegisterObjectMethod("ENGINE", "bool   Get_bool(uint64 Address)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int1), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int8   Get_char(uint64 Address)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int8), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int8   Get_int8(uint64 Address)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int8), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int16  Get_int16(uint64 Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int16), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int32  Get_int(uint64 Address)",    asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int32), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int32  Get_int32(uint64 Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int32), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int64  Get_int64(uint64 Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int64), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint8  Get_uint8(uint64 Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint8), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint16 Get_uint16(uint64 Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint16), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint32 Get_uint32(uint64 Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint32), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint64 Get_uint64(uint64 Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint64), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "float  Get_float(uint64 Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_xint32), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "double Get_double(uint64 Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_xint64), asCALL_THISCALL);

       Engi04->RegisterObjectMethod("ENGINE", "bool   Get_bool(const string &in Address)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int1S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int8   Get_char(const string &in Address)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int8S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int8   Get_int8(const string &in Address)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int8S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int16  Get_int16(const string &in Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int16S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int32  Get_int(const string &in Address)",    asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int32S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int32  Get_int32(const string &in Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int32S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "int64  Get_int64(const string &in Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_int64S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint8  Get_uint8(const string &in Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint8S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint16 Get_uint16(const string &in Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint16S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint32 Get_uint32(const string &in Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint32S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "uint64 Get_uint64(const string &in Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_uint64S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "float  Get_float(const string &in Address)",  asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_xint32S), asCALL_THISCALL);
       Engi04->RegisterObjectMethod("ENGINE", "double Get_double(const string &in Address)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Gets_xint64S), asCALL_THISCALL);

       Engi04->RegisterObjectProperty("ENGINE", "const uint32 Background",     asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, Background));
       Engi04->RegisterObjectProperty("ENGINE", "const uint32 Maximum_Object", asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, MaximumObject));
       Engi04->RegisterObjectProperty("ENGINE", "const uint32 Maximum_Frame",  asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, MaximumFrame));
       Engi04->RegisterObjectProperty("ENGINE", "const int32  Maximum_MP",     asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, MaximumMP));
       Engi04->RegisterObjectProperty("ENGINE", "const uint32 Max_Object",     asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, MaximumObject));
       Engi04->RegisterObjectProperty("ENGINE", "const uint32 Max_Frame",      asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, MaximumFrame));
       Engi04->RegisterObjectProperty("ENGINE", "const int32  Max_MP",         asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, MaximumMP));
       Engi04->RegisterObjectProperty("ENGINE", "const uint32 User",           asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, User));

       if(Vrab02)
       {
        Engi04->RegisterObjectMethod("ENGINE", "uint32 Copy_Frame(uint32 Data, uint32 Frame1, uint32 Frame2)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Copy), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "uint32 Copy_Data_Frame(uint32 Data1, uint32 Data2, uint32 Frame1, uint32 Frame2)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Copys), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "uint32 Get_ID_Data(uint32 ID)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Address), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "uint32 Set_Object(int32 Owner, uint32 ID, int32 Frame, double X, double Y, double Z, bool Facing)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Generate), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void   Draw_RECT(int32 X_Position, int32 Y_Position, uint32 Width, uint32 Height, uint8 Red, uint8 Green, uint8 Blue)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Draw), asCALL_THISCALL);
      
        Engi04->RegisterObjectMethod("ENGINE", "void Set_bool(uint64 Address, bool Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int1), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_char(uint64 Address, int8 Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int8), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int8(uint64 Address, int8 Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int8), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int16(uint64 Address, int16 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int16), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int(uint64 Address, int32 Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int32), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int32(uint64 Address, int32 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int32), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int64(uint64 Address, int64 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int64), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint8(uint64 Address, uint8 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint8), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint16(uint64 Address, uint16 Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint16), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint32(uint64 Address, uint32 Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint32), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint64(uint64 Address, uint64 Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint64), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_float(uint64 Address, float Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_xint32), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_double(uint64 Address, double Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_xint64), asCALL_THISCALL);

        Engi04->RegisterObjectMethod("ENGINE", "void Set_bool(const string &in Address, bool Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int1S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_char(const string &in Address, int8 Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int8S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int8(const string &in Address, int8 Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int8S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int16(const string &in Address, int16 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int16S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int(const string &in Address, int32 Value)",     asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int32S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int32(const string &in Address, int32 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int32S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_int64(const string &in Address, int64 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_int64S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint8(const string &in Address, uint8 Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint8S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint16(const string &in Address, uint16 Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint16S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint32(const string &in Address, uint32 Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint32S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_uint64(const string &in Address, uint64 Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_uint64S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_float(const string &in Address, float Value)",   asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_xint32S), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Set_double(const string &in Address, double Value)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets_xint64S), asCALL_THISCALL);
      
        Engi04->RegisterObjectMethod("ENGINE", "void Sets(uint64 Address, const string &in Assembly)",           asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_Sets), asCALL_THISCALL);
        Engi04->RegisterObjectMethod("ENGINE", "void Sets(const string &in Address, const string &in Assembly)", asMETHOD(HEPTA_LF2_ENCHANTED_ENGINE1, L_SetsS), asCALL_THISCALL);

        Engi04->RegisterObjectProperty("ENGINE", "const int32 Module_ID", asOFFSET(HEPTA_LF2_ENCHANTED_ENGINE1, ModuleID));
       }
     
       Engi04->RegisterGlobalProperty("const GAME Game", Uniq01.get());
       Engi04->RegisterGlobalProperty("const ENGINE Engine", Uniq01.get());
      }
     }
     string Debug()                                                                  fastened {insize Vrab01 = Effect.size(); insize Vrab02 = 0; while(Vrab01 != 0){Vrab01 -= 1; if(Effect[Vrab01].Exist) Vrab02 += 1;} insize Vrab03 = Object.size(); insize Vrab04 = 0; while(Vrab03 != 0){Vrab03 -= 1; if(Object[Vrab03].Exist) Vrab04 += 1;} return "Objects: " + std::to_string(Vrab04) + " Effects: " + std::to_string(Vrab02);}
					uint64 Colour()                                                                 fastened {return (ruint64(Coloring) << 32ull) + ruint64(Color);}
					int0   Cleanup()                                                                fastened
     {
      Object.clear(); Effect.clear(); Animation.clear();
     }

     private:
      insize Vrab001 = 0;
      uint8  Vrab002 = 0;
      int1   Vrab003 = false;
      uint8  Vrab004 = 0;
      std::vector < int1 > Vect001;
      std::ifstream File001;

      int1   Move = false;
      uint8  Mode = 0;
      uint8  Difficult = 0;
						uint8  Coloring = 0;
						uint32 Color = 0;
      uint64 Gametime = 0;
      uint64 Playtime = 0;
      insize Background = 0;
      insize Independent_Team = 0;
      insize Max = 0;
      std::vector < insize > Pics;
      std::vector < insize > Sounds;

      int1   Polish = false;
      int1   Hitboxes = false;
      int1   Fill_Hitboxes = true;

      int1   Pause = false;
      int1   Frame_Pause = false;
      int1   F6 = false;
      uint8  Speed = 2;

      std::vector < int1 > All_Char;
      std::vector < int1 > Selectable_Char;
      std::vector < std::vector < uint32 > > Animation;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT > Effect;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Object;
     
      unique < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE > Stages;
      std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME > > Frames; // Frames' Pointer.
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT > Objects;                 // Objects' Database.
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND > Backgrounds;         // Backgrounds' Database.

      uint8  Decode(statics string Temp01) fastened
      {
       if(File001.is_open()) File001.close(); File001.open(Temp01, std::ios::binary | std::ios::in); if(!File001.is_open()) return 1;
       statics string Temp02 = L_Lowercase(string(Temp01, Temp01.size() - 4, 4)); if(Temp02 != ".dat" && Temp02 != ".txt") return 2;
       if(Temp02 == ".dat")
       {
        stream Strn01; Strn01 << File001.rdbuf(); File001.close();
        string Temp03 = Strn01.str(); statics string Temp04 = "SiuHungIsAGoodBearBecauseHeIsVeryGood";
        statics insize Vrab01 = Temp03.size(); insize Vrab02 = 12; statics insize Vrab03 = Temp04.size();
        for(uint32 Vrab04 = 123; Vrab04 < Vrab01; ++Vrab04){Temp03.at(Vrab04) -= Temp04.at(Vrab02); Vrab02 += 1; if(Vrab02 == Vrab03) Vrab02 = 0;}
        std::ofstream File01(L_Execute("Database\\Temp.log"), std::ios::binary | std::ios::out); Temp03.erase(0, 123); File01 << Temp03; File01.close();
        File001.open("Database\\Temp.log", std::ios::binary | std::ios::in);
       } else 
       {
        stream Strn01; Strn01 << File001.rdbuf(); File001.close(); string Temp03 = Strn01.str();
        std::ofstream File01(L_Execute("Database\\Temp.log"), std::ios::binary | std::ios::out); File01 << Temp03; File01.close();
        File001.open("Database\\Temp.log", std::ios::binary | std::ios::in);
       }
       if(!File001.is_open()) return 3;
       return 4;
      }
      int0   Remove(statics insize Vrab01)  fastened
      {
       if(Vrab01 >= Object.size()) return;

       Object[Vrab01].Exist = false;
       Object[Vrab01].Trans_Address.clear();
       Object[Vrab01].Return_Address.clear();
       Object[Vrab01].Vrest.clear();

       insize Vrab02 = Object.size();
       while(Vrab02 != 0)
       {
        Vrab02 -= 1; if(!Object[Vrab02].Exist) continue;
        if(Object[Vrab02].Target == Vrab01) Object[Vrab02].Target = rinsize(-1);
        if(Object[Vrab02].Clone == Vrab01) Object[Vrab02].Clone = rinsize(-2);
        if(Vrab01 < Object[Vrab02].Vrest.size()) Object[Vrab02].Vrest[Vrab01] = 0;
        insize Vrab03 = Object[Vrab02].Owners.size();
        while(Vrab03 != 0){Vrab03 -= 1; if(Object[Vrab02].Owners[Vrab03] == Vrab01) Object[Vrab02].Owners[Vrab03] = rinsize(-1);}
       }

       if(Vrab01 == rinsize(-1)) return;
       Vrab02 = Object.size();
       while(Vrab02 != 0)
       {
        Vrab02 -= 1; if(!Object[Vrab02].Exist) continue; if(Object[Vrab02].D == Vrab01) Remove(Vrab02);
       }
      }
      insize Add(statics insize Vrab01)   fastened
      {
       int1 Vrab02 = false; insize Vrab03 = 0;
       {
        statics insize Vrab04 = Objects.size(); insize Vrab05 = 0;
        while(Vrab05 < Vrab04)
        {
         if(Objects[Vrab05].id == Vrab01){Vrab02 = true; Vrab03 = Vrab05; break;}
         Vrab05 += 1;
        }
       }
       if(Vrab02)
       {
        statics insize Vrab04 = Object.size(); insize Vrab05 = 0;
        while(Vrab05 < Vrab04)
        {
         if(!Object[Vrab05].Exist) break;
         Vrab05 += 1;
        }
        if(Vrab05 == Vrab04)
        {
         if(Vrab05 == Max) return rinsize(-1);
         Object.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT());
         Object[Vrab05].Data = &Objects[Vrab03]; return Vrab05;
        } else
        {
         Object[Vrab05] = HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT();
         Object[Vrab05].Data = &Objects[Vrab03]; return Vrab05;
        }
       }
       return rinsize(-1);
      }
      int0   Spark(statics uint8 Vrab01, statics xint64 Vrab02, statics xint64 Vrab03, statics xint64 Vrab04) fastened
      {
       if(Pics[2] == rinsize(-1)) return;
       statics insize Vrab05 = Effect.size(); insize Vrab06 = 0;
       while(Vrab06 < Vrab05){if(!Effect[Vrab06].Exist) break; Vrab06 += 1;}
       if(Vrab06 == Vrab05){Effect.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT());} else {Effect[Vrab06] = HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT();}
       Effect[Vrab06].X = Vrab02 - 45; Effect[Vrab06].Y = Vrab03 - 30; Effect[Vrab06].Z = Vrab04; Effect[Vrab06].Sprite = true; Effect[Vrab06].Pics.resize(6);
       insize Vrab07 = 0; insize Vrab08 = 0;
       switch(Vrab01)
       {
        case 1: break; case 2: Vrab08 = 18; break; case 3: Vrab08 = 12; break;
        default: Vrab08 = 6; break;
       }
       while(Vrab07 != 6){Effect[Vrab06].Pics[Vrab07] = Pics[2] + Vrab07 + Vrab08; Vrab07 += 1;}
      }
      int0   Control(statics insize Vrab01){}
    };
    
    struct HEPTA_LF2_ENCHANTED_ANGELSCRIPT
    {
     int0   Start()     fastened
     {
      Vrab004 = true;
      int32 Vrab01 = 0; if(Vrab003 > 127){Vrab01 = 0;} else {Vrab01 = 255;}
      int16 Vrab02 = 0; if(Vrab001) Vrab02 = 400;
      statics int16 Vrab03 = Vrab002 & 0xFF;
      AllocConsole();
      HANDLE Hand01 = GetStdHandle(STD_OUTPUT_HANDLE);
      freopen("CONIN$", "rb", stdin);   // reopen stdin handle as console window input
      freopen("CONOUT$", "wb", stdout); // reopen stout handle as console window output
      freopen("CONOUT$", "wb", stderr); // reopen stderr handle as console window output
      SMALL_RECT Rect01 = {0, 0, Vrab03, (Vrab03 / 2)};
      CONSOLE_SCREEN_BUFFER_INFOEX Info01; Info01.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
      SetConsoleScreenBufferSize(Hand01, {Vrab03, (int16)((Vrab03 / 2) - 2 + Vrab02)});
      GetConsoleScreenBufferInfoEx(Hand01, &Info01);
      Info01.wAttributes = true; Info01.srWindow = Rect01;
      Info01.ColorTable[0] = Vrab003 + (Vrab003 << 8) + (Vrab003 << 16);
      Info01.ColorTable[1] = Vrab01 + (Vrab01 << 8) + (Vrab01 << 16);
      Info01.ColorTable[7] = Info01.ColorTable[1];
      SetConsoleScreenBufferInfoEx(Hand01, &Info01);
      SetConsoleScreenBufferSize(Hand01, {Vrab03, (int16)((Vrab03 / 2) - 2 + Vrab02)});
      SetConsoleTitleA("AngelScript's Console");
     }
     int0   End()       fastened {ShowWindow(GetConsoleWindow(), 0); FreeConsole(); Vrab004 = false;}
     int0   Switch()    fastened {if(Vrab004){End();} else {Start();}}
     int0   Print(statics string Temp01) fastened {Temp001 << Temp01;}
     int0   Message(statics asSMessageInfo *Mesg01, int0*) fastened
     {
	  if(Mesg01->section[0] == '\0')
	  {
	   printf("%s - %s\n", Mesg01->type == asMSGTYPE_ERROR ? ">< ERROR" : Mesg01->type == asMSGTYPE_WARNING ? ")( WARNING" : "() INFO", Mesg01->message);
	  } else if(Mesg01->row == 0 && Mesg01->col == 0)
	  {
	   printf("%s { %s } - %s\n", Mesg01->type == asMSGTYPE_ERROR ? ">< ERROR" : Mesg01->type == asMSGTYPE_WARNING ? ")( WARNING" : "() INFO", L_Focus(Mesg01->section).c_str(), Mesg01->message);
	  } else
	  {
	   printf("%s { %s [%d, %d] } - %s\n", Mesg01->type == asMSGTYPE_ERROR ? ">< ERROR" : Mesg01->type == asMSGTYPE_WARNING ? ")( WARNING" : "() INFO", L_Focus(Mesg01->section).c_str(), Mesg01->row, Mesg01->col, Mesg01->message);
	  }
	 }
     int0   Set()       fastened
     {
      if(Vrab005) Reset();
      int8 Vrab01 = 0;
      while(Vrab01 != 3)
      {
       asIScriptEngine  *Engi01 = NULL;
       asIScriptContext *Cont01 = NULL;
       statics int1 Vrab02 = Vrab01 == 1;
       Engi01 = asCreateScriptEngine(ANGELSCRIPT_VERSION); if(! Engi01) return;
       Engi01->SetMessageCallback(asMETHOD(HEPTA_LF2_ENCHANTED_ANGELSCRIPT, Message), NULL, asCALL_CDECL);
       Cont01 = Engi01->CreateContext();
       RegisterScriptArray(Engi01, true);
       RegisterScriptMath(Engi01);
       RegisterScriptMathComplex(Engi01);
       RegisterStdString(Engi01);
       RegisterStdStringUtils(Engi01);
       switch(Vrab01)
       {
        case 0: Engi001 = Engi01; Cont001 = Cont01; break;
        case 1: Engi002 = Engi01; Cont002 = Cont01; break;
        case 2: Engi003 = Engi01; Cont003 = Cont01; break;
        default: break; 
       }
       Vrab01 += 1;
      }
      Vrab005 = true;
     }
     int0   Reset()     fastened
     {
      Modu001 = NULL;
      Engi001->ShutDownAndRelease(); Engi002->ShutDownAndRelease(); Engi003->ShutDownAndRelease();
      Cont001->Unprepare(); Cont001->Release(); Cont002->Unprepare(); Cont002->Release(); Cont003->Unprepare(); Cont003->Release();
      if(Vrab004) End();
      Vrab005 = false;
     }
     int1   Available() fastened {return Vrab005;}
     string Version()   fastened {return ANGELSCRIPT_VERSION_STRING;}
     private:
      int1   Vrab001 = false;
      int16  Vrab002 = 60;
      int32  Vrab003 = 0;
      int1   Vrab004 = false;
      int1   Vrab005 = false;
      stream Temp001;
      
      asIScriptModule  *Modu001 = NULL;
      asIScriptEngine  *Engi001 = NULL;
      asIScriptEngine  *Engi002 = NULL;
      asIScriptEngine  *Engi003 = NULL;
      asIScriptContext *Cont001 = NULL;
      asIScriptContext *Cont002 = NULL;
      asIScriptContext *Cont003 = NULL;
    };
    struct HEPTA_LF2_ENCHANTED_INFO_MANAGER
    {
     int64 Target = 0;
     uint64 Runtime = 0;
    };
    struct HEPTA_LF2_ENCHANTED_INFO
    {
     int1   Volume = false;
     int1   Question = false;
     int64  Y = 0;
     uint64 Runtime = 0;
     uint64 Slot = 0;
     string String;
     std::vector < HEPTA_LF2_ENCHANTED_INFO_MANAGER > Manager;
    };
				struct HEPTA_LF2_ENCHANTED_PLAYER
				{
				 string Name;
					uint8 Type = 0;
					uint8 Input[16];
				};
    struct HEPTA_LF2_ENCHANTED_MEMORY
    {
					//std::vector < HEPTA_LF2_ENCHANTED_PLAYER > Player;
     uint8  P_Con[4]{};
     uint8  P_Input[4][16]{};
     string P_Name[4]{"P1", "P2", "P3", "P4"};

     int1   Meta_Selection = false;
     int1   Custom_Mirror = false;
     int1   Fast_Loading = false;
     int1   Show_FPS = true;
     int1   Show_Time = true;
     int1   Fullscreen = true;
     int1   Aspect_Ratio = true;
     int1   Skip_Animation = false;
     uint8  Health_Bar = 0;
     uint8  Engine = 0;
     uint8  Brightness = 100;
     int32  Pan = 0;
     uint32 Screen_W = 800;
     uint32 Screen_H = 450;
     uint32 Volume = 80;
     uint32 Camera_Speed = 100;
     insize Max_SFX = 8;
     insize Max_Object = 1000;
     string Address = "Database\\Game\\Enchanted\\Origin\\";
     string Data_Address = "data\\data.txt";

     // Engine 0 : Original 's Setting
      int1   E0_Random_Item = true;
      int1   E0_High_Conditional_Dash = true;
      int1   E0_Stackable_Velocity = false;
      int1   E0_Kind14_Transpareness = true;
      int1   E0_Kind14_Uncrossable = true;
      int1   E0_High_Quality_Break_Parts = true;
     //-//
     // Engine 1 : Enchanted 's Setting
      int1   E1_Random_Item = true;
      int1   E1_Z_Camera = false;
     //-//

     uint8  Esc = 52;   // Common Exit / Cancel
     uint8  Enter = 70; // Common Select / Ok
     uint8  F1 = 53;    // Common Pause
     uint8  F2 = 54;    // Common Forced Pause
     uint8  F10 = 62;   // Common Volume Up
     uint8  F11 = 63;   // Common Volume Down
     uint8  F12 = 64;   // Common Half Brightness
     uint8  F3 = 55;    // Special Function 1
     uint8  F4 = 56;    // Special Function 2
     uint8  F5 = 57;    // Special Function 3
     uint8  F6 = 58;    // Special Function 4
     uint8  F7 = 59;    // Special Function 5
     uint8  F8 = 60;    // Special Function 6
     uint8  F9 = 61;    // Special Function 7

     int1   Recording = true;
     int1   True_Recording = false;
     string Record_Address = "Database\\Game\\Enchanted\\Recordings\\";
     string User = "<none>";
     string Email = "<none>";
     string Note = "<none>";
    };
    struct HEPTA_LF2_ENCHANTED
    {
     // Core
      int1   Initialization = true;    // First initialization?
      int1   Hidden_Char = false;      // 
      int1   Draw = true;              // Mouse's rectangle draw?
      int1   Draw_Pausing = false;     // Mouse's rectangle draw's pausing?
      uint8  Draw_Color = 0;           // Mouse's rectangle draw's color.
      uint8  Draw_Trans = 0;           // Mouse's rectangle draw's trans.
      uint8  Menu = 0;                 // Interface's menu.
      int64  Display_CenX = 0, Display_CenY = 0, Display_W = 0, Display_H = 0; // For compatible positioning.
      int32  Mouse_X = 0, Mouse_Y = 0; // Last frame position.
      uint8  Mouse_Standby = 0;        // Stay countup.
      uint64 Tick = 0;                 // Gametime.
      uint64 Info_Slot = 0;            // Info current slot.
      insize Number_Of_Sound = 0;      // Max SFX.
      insize Current_Music[2] = {rinsize(-1), rinsize(-1)}; // Music.
     //-//
     // Event
      int1   Focused = true;
      uint64 Runtime1 = 0; uint64 Runtime2 = 0; uint8 Runtime3 = 0;
      int64  CameraX = 0; xint64 CameraX_Acceleration = 0, CameraX_Post = 0;
      int64  CameraY = 0; xint64 CameraY_Acceleration = 0, CameraY_Post = 0;
      xint64 Darktime1 = 0;
      insize Background1 = 0; int1 Background2 = false;
      insize Select_Background = 0; insize Select_Music = 0; uint8 Select_Mode = 0; uint8 Select_Difficult = 0;
      string String[4];
      std::ifstream File1;
      std::vector < uint8 > Select;
      std::vector < uint8 > Select_Team;
      std::vector < insize > Select_Character;

     //-//
     // Production
      HEPTA_LF2_ENCHANTED_MEMORY Memory[2];                      // System's Memory.
      unique < HEPTA_LF2_ENCHANTED_ENGINE1 > Engine1;            // System's In-Game. (Engine 0)
    //unique < HEPTA_LF2_ENCHANTED_ENGINE2 > Engine2;            // System's In-Game. (Engine 1)
      unique < HEPTA_LF2_ENCHANTED_ANGELSCRIPT > Angel;          // System's AngelScript.
      std::vector < insize > Pic_Index_Interface;                // System's pics.
      std::vector < insize > Back_Index_Interface;               // System's background.
      std::vector < int1 > Back_Index_Interface_Type;            // System's background's type.
      std::vector < insize > Sound_Index_Interface;              // System's sounds.
      std::vector < HEPTA_LF2_ENCHANTED_INFO > Info;             // System's info notification.
     //-//
     // Light Functions
      int0   Not_Found() fastened {String[2] = "\"" + String[1] + "\""; String[3] = "Either can't be found or inaccessible.";}
      int0   Reset(statics uint8 Vrab01 = 0, statics uint64 Vrab02 = 0, statics uint64 Vrab03 = 0, statics uint8 Vrab04 = 0) fastened {Menu = Vrab01; Runtime1 = Vrab02; Runtime2 = Vrab03; Runtime3 = Vrab04;}
      int0   Print_Text(statics int64 Vrab01, statics int64 Vrab02, uint8 Vrab03, statics string &Temp01, statics int64 Vrab04 = 0, statics int64 Vrab05 = 0) fastened
      {
       statics string Temp02 = Temp01;
       statics insize Vrab06 = Temp02.size(); insize Vrab07 = 0; int64 Vrab08 = rint64(Vrab01); Vrab03 %= 6;
       if(Vrab04 == 0 && Vrab05 == 0)
       {
        while(Vrab07 != Vrab06)
        {
         statics int64 Vrab09 = rint64(Temp02.at(Vrab07)); int64 Vrab10 = 0, Vrab11 = 0;
         switch(Vrab09)
         {
          case 95: case 103: case 106: case 112: case 113: case 121: case 152: case 159: case 230: case 237: case 244: case 245: Vrab11 = 1; break;
          case 128: case 135: Vrab11 = 2; break;
          case 109: Vrab10 = 1; break;
          default: break;
         }
         G_Set_Display(3, Pic_Index_Interface[rinsize(Vrab03)], Vrab08 - Vrab10, Vrab02 + Vrab11, 0ui8, 255ui8, 15, 15, (Vrab09 % 16) * 16, (Vrab09 / 16) * 16);
         Vrab07 += 1; Vrab08 += 9;
        }
       } else
       {
        while(Vrab07 != Vrab06)
        {
         statics int64 Vrab09 = rint64(Temp02.at(Vrab07)); int64 Vrab10 = 0, Vrab11 = 0;
         switch(Vrab09)
         {
          case 95: case 103: case 106: case 112: case 113: case 121: case 152: case 159: case 230: case 237: case 244: case 245: Vrab11 = 1; break;
          case 128: case 135: Vrab11 = 2; break;
          case 109: Vrab10 = 1; break;
          default: break;
         }
         int64 Vrab12 = 0; int64 Vrab13 = 0;
         {
          statics int64 Vrab14 = Vrab02 + Vrab11 - Vrab04; if(Vrab14 < 0) Vrab12 = -Vrab14;
          statics int64 Vrab15 = Vrab02 + Vrab11 - Vrab05 + 15; if(Vrab15 > 0) Vrab13 = Vrab15;
         }
         if(Vrab12 + Vrab13 < 15)
         G_Set_Display(3, Pic_Index_Interface[rinsize(Vrab03)], Vrab08 - Vrab10, Vrab02 + Vrab11 + Vrab12, 0ui8, 255ui8, 15, 15 - Vrab12 - Vrab13, (Vrab09 % 16) * 16, ((Vrab09 / 16) * 16) + Vrab12);
         Vrab07 += 1; Vrab08 += 9;
        }
       }
      }
      int0   Print_Bar(int64 Vrab01, int64 Vrab02, uint64 Vrab03, uint64 Vrab04) fastened
      {
       if(Vrab03 % 2 == 1) Vrab03 += 1; if(Vrab04 % 2 == 1) Vrab04 += 1;
       G_Set_Display(2, Pic_Index_Interface[6], Vrab01 - 12, Vrab02 - 12);
       G_Set_Display(2, Pic_Index_Interface[7], Vrab01 + Vrab03 + 1, Vrab02 - 12);
       G_Set_Display(2, Pic_Index_Interface[8], Vrab01 - 12, Vrab02 + Vrab04 + 1);
       G_Set_Display(2, Pic_Index_Interface[9], Vrab01 + Vrab03 + 1, Vrab02 + Vrab04 + 1);
       G_Set_Display(2, Pic_Index_Interface[10], Vrab01, Vrab02 - 12, 0ui8, 255ui8, Vrab03);
       G_Set_Display(2, Pic_Index_Interface[10], Vrab01, Vrab02 + Vrab04 + 10, 0ui8, 255ui8, Vrab03);
       G_Set_Display(2, Pic_Index_Interface[11], Vrab01 - 12, Vrab02, 0ui8, 255ui8, 0, Vrab04);
       G_Set_Display(2, Pic_Index_Interface[11], Vrab01 + Vrab03 + 10, Vrab02, 0ui8, 255ui8, 0, Vrab04);

       {
        uint64 Vrab05 = Vrab04 + 1; uint64 Vrab06 = ruint64(-1);
        while(Vrab05 > 0)
        {
         uint64 Vrab07 = Vrab05 / 198; if(Vrab07 > 0){Vrab07 = 198;} else {Vrab07 = Vrab05 % 198;} Vrab05 -= Vrab07; Vrab06 += 1;
         G_Set_Display(3, Pic_Index_Interface[12], Vrab01 - 9, Vrab02 + (Vrab06 * 198), 0ui8, 255ui8, 9, Vrab07, 0, 1);
         G_Set_Display(3, Pic_Index_Interface[12], Vrab01 + Vrab03 + 1, Vrab02 + (Vrab06 * 198), 0ui8, 255ui8, 9, Vrab07, 0, 1);
        }
       }
       {
        uint64 Vrab05 = Vrab04 + 19; uint64 Vrab06 = ruint64(-1);
        while(Vrab05 > 0)
        {
         uint64 Vrab07 = Vrab05 / 198; if(Vrab07 > 0){Vrab07 = 198;} else {Vrab07 = Vrab05 % 198;} Vrab05 -= Vrab07; Vrab06 += 1;
         uint64 Vrab08 = Vrab03 + 1; uint64 Vrab09 = ruint64(-1);
         while(Vrab08 > 0)
         {
          uint64 Vrab10 = Vrab08 / 198; if(Vrab10 > 0){Vrab10 = 198;} else {Vrab10 = Vrab08 % 198;} Vrab08 -= Vrab10; Vrab09 += 1;
          G_Set_Display(3, Pic_Index_Interface[12], Vrab01 + (Vrab09 * 198), Vrab02 - 9 + (Vrab06 * 198), 0ui8, 255ui8, Vrab10, Vrab07, 1, 0);
         }
        }
       }
      }
      int0   Print_Menu(int64 Vrab01, int64 Vrab02, uint64 Vrab03, uint64 Vrab04)
      {
       G_Set_Display(2, Pic_Index_Interface[108], Vrab01 - 8, Vrab02 - 8);
       G_Set_Display(2, Pic_Index_Interface[109], Vrab01 + Vrab03, Vrab02 - 8);
       G_Set_Display(2, Pic_Index_Interface[110], Vrab01 - 8, Vrab02 + Vrab04);
       G_Set_Display(2, Pic_Index_Interface[111], Vrab01 + Vrab03, Vrab02 + Vrab04);
       G_Set_Display(2, Pic_Index_Interface[112], Vrab01, Vrab02 - 8, 0ui8, 255ui8, Vrab03, 0);
       G_Set_Display(2, Pic_Index_Interface[113], Vrab01 - 8, Vrab02, 0ui8, 255ui8, 0, Vrab04);
       G_Set_Display(2, Pic_Index_Interface[114], Vrab01, Vrab02 + Vrab04, 0ui8, 255ui8, Vrab03, 0);
       G_Set_Display(2, Pic_Index_Interface[115], Vrab01 + Vrab03, Vrab02, 0ui8, 255ui8, 0, Vrab04);
       G_Set_Display(2, Pic_Index_Interface[116], Vrab01, Vrab02, 0ui8, 255ui8, Vrab03, Vrab04);
      }
      int0   Play_Sound(statics insize Vrab01, statics xint32 Vrab02 = 0.0, statics uint32 Vrab03 = 100) fastened
      {
       if(Number_Of_Sound == Memory[0].Max_SFX) return;
       Number_Of_Sound += 1;
       G_Set_Sound(Vrab01, rxint32((rxint64(Vrab03) / 100) * rxint64(Varb0012)), rxint32(Varb0013 + Vrab02));
      }
      int0   Stop_Music() fastened
      {
       G_Control_Music(Current_Music[1], 0.f, 0.f, true);
      }
      int0   Play_Music(statics insize Vrab01, statics xint32 Vrab02 = 0.0, statics uint32 Vrab03 = 100) fastened
      {
       if(Vrab01 == Current_Music[0])
       {
        G_Control_Music(Current_Music[1], rxint32((rxint64(Vrab03) / 100) * rxint64(Varb0012)), rxint32(Varb0013 + Vrab02));
       } else
       {
        Stop_Music(); Current_Music[0] = Vrab01; Current_Music[1] = G_Set_Music(Vrab01, rxint32((rxint64(Vrab03) / 100) * rxint64(Varb0012)), rxint32(Varb0013 + Vrab02));
       }
      }
      int0   Post_Info(statics string Temp01, statics int1 Vrab01 = false, statics int1 Vrab02 = false) fastened
      {
       statics insize Vrab03 = Info.size(); Info.resize(Vrab03 + 1);

       // Shift all the current existing info/notification.
       {
        int64 Vrab04 = 29;
        insize Vrab05 = 0, Vrab06 = 0, Vrab07 = Temp01.size(); while(Vrab07 > 41){Vrab07 -= 40; if(Temp01.at((Vrab05 * 40) + Vrab06 + 40) == ' '){Vrab07 -= 1; Vrab06 += 1;} Vrab05 += 1;}
        if(Temp01.size() > 41){Vrab04 += 7 + (16 * rint64(Vrab05));} else
        {Vrab04 += 5;}

        for(insize Vrab08 = 0; Vrab08 < Vrab03; ++Vrab08)
        {
         statics insize Vrab09 = Info[Vrab08].Manager.size(); Info[Vrab08].Manager.resize(Vrab09 + 1);
         Info[Vrab08].Manager[Vrab09].Target = Vrab04;
        }
       }

       // Values
       if(Vrab03 == 0) Info_Slot = 0; Info[Vrab03].Slot = ++Info_Slot;
       if(Vrab01){Info[Vrab03].Volume = true;} else {Info[Vrab03].String = Temp01;}
       Info[Vrab03].Question = Vrab02;
      }
      string Input_Name(uint8 Vrab01) fastened
      {
       switch(Vrab01)
       {
        case 1: return "1"; case 2: return "2"; case 3: return "3"; case 4: return "4"; case 5: return "5"; case 6: return "6"; case 7: return "7"; case 8: return "8"; case 9: return "9"; case 10: return "0";
        case 11: return "A"; case 12: return "B"; case 13: return "C"; case 14: return "D"; case 15: return "E"; case 16: return "F"; case 17: return "G"; case 18: return "H"; case 19: return "I"; case 20: return "J"; case 21: return "K"; case 22: return "L"; case 23: return "M"; case 24: return "N"; case 25: return "O"; case 26: return "P"; case 27: return "Q"; case 28: return "R"; case 29: return "S"; case 30: return "T"; case 31: return "U"; case 32: return "V"; case 33: return "W"; case 34: return "X"; case 35: return "Y"; case 36: return "Z";
        case 37: return "`"; case 38: return "-"; case 39: return "="; case 40: return "["; case 41: return "]"; case 42: return "\\"; case 43: return ";"; case 44: return "\'"; case 45: return "/"; case 46: return "."; case 47: return ",";
        case 48: return "Up"; case 49: return "Left"; case 50: return "Down"; case 51: return "Right";
        case 52: return "Escape";
        case 53: return "F1"; case 54: return "F2"; case 55: return "F3"; case 56: return "F4"; case 57: return "F5"; case 58: return "F6"; case 59: return "F7"; case 60: return "F8"; case 61: return "F9"; case 62: return "F10"; case 63: return "F11"; case 64: return "F12";
        case 65: return "Print Screen";
        case 66: return "Delete";
        case 67: return "Backspace";
        case 68: return "Tab";
        case 69: return "Caps Lock";
        case 70: return "Enter";
        case 71: return "Shift (Left)"; case 72: return "Shift (Right)";
        case 73: return "Ctrl (Left)"; case 74: return "Ctrl (Right)";
        case 75: return "Alt (Left)"; case 76: return "Alt (Right)";
        case 77: return "Num lock";
        case 78: return "* (Num)";
        case 79: return "/ (Num)";
        case 80: return "+ (Num)";
        case 81: return "- (Num)";
        case 82: return "1 (Num)"; case 83: return "2 (Num)"; case 84: return "3 (Num)"; case 85: return "4 (Num)"; case 86: return "5 (Num)"; case 87: return "6 (Num)"; case 88: return "7 (Num)"; case 89: return "8 (Num)"; case 90: return "9 (Num)"; case 91: return "0 (Num)";
        case 92: return ". (Num)";
        case 94: return "Space";
        default: return "<none>";
       }
      }
      string Difficult(statics uint8 Vrab01) fastened {switch(Vrab01){case 0: return "Easy"; case 1: return "Normal"; case 2: return "Hard"; default: return "CRAZY!";}}
      string Version() fastened {return "0.8.230826";}
     //-//
     // Core Functions
      int0   Update_Window(uint32 Vrab01, uint32 Vrab02, int1 Vrab03, string Temp01 = "Little Fighter 2 Enchanted 4th") fastened
      {
       Varb0002 = Vrab01; Varb0003 = Vrab02;
       Game0001->OnWindowSizeChanged(Varb0002, Varb0003);
       auto Hwnd01 = Game0001->m_deviceResources->GetWindow();
       SetWindowPos(Hwnd01, HWND_TOP, CW_USEDEFAULT, CW_USEDEFAULT, static_cast < LONG > (Varb0002 + 16), static_cast < LONG > (Varb0003 + 39), SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
       if(Vrab03 != Varb0014) G_ToggleFullscreen();
       SetWindowTextA(Hwnd01, Temp01.c_str());
       Display_CenX = L_Rounding64(rxint64(Vrab01) / 2); Display_CenY = L_Rounding64(rxint64(Vrab02) / 2);
       Display_W = rint64(rint32(Vrab01)); Display_H = rint64(rint32(Vrab02));
      }
      int1   Save_Memory() fastened
      {
       statics string Temp01 = "Database\\Game\\Enchanted\\config.ini";
       std::ofstream File01(L_Execute(Temp01));
       if(!File01.is_open()) return false;
							/*
							std::vector < int1 > Vect01(0);
							std::vector < uint64 > Vect02(0);
							std::vector < xint64 > Vect03(0);
							std::vector < string > Vect04(0);
							std::vector < string > Vect05(0);

							{
								statics insize Vrab01 = Memory[0].Player.size();
							 Vect02[0] = ruint64(Vrab01);

							}

							insize Vrab01 = 0;
							Vrab01 = Vect01.size(); File01 << Vrab01 + " ";
							while(Vrab01 != 0){Vrab01 -= 1; File01 << Vect01[Vrab01] ? "T " : "F ";}
							Vrab01 = Vect02.size(); File01 << Vrab01 + " ";
							while(Vrab01 != 0){Vrab01 -= 1; File01 << Vect02[Vrab01] << " ";}
							Vrab01 = Vect03.size(); File01 << Vrab01 + " ";
							while(Vrab01 != 0){Vrab01 -= 1; File01 << Vect03[Vrab01] << " ";}
							Vrab01 = Vect04.size(); File01 << Vrab01 + " ";
							while(Vrab01 != 0){Vrab01 -= 1; File01 << L_Spacemaker(Vect04[Vrab01]) + " ";}
							Vrab01 = Vect05.size(); File01 << Vrab01 + "\n";
							while(Vrab01 != 0){Vrab01 -= 1; File01 << Vect05[Vrab01] + "\n";}

							File01.close(); return true;*/

       File01 << L_Spacemaker(Memory[0].P_Name[0]) << " " << L_Spacemaker(Memory[0].P_Name[1]) << " " << L_Spacemaker(Memory[0].P_Name[2]) << " " << L_Spacemaker(Memory[0].P_Name[3]) << "\n";
       File01 << ruint32(Memory[0].P_Input[0][0]) << " " << ruint32(Memory[0].P_Input[0][1]) << " " << ruint32(Memory[0].P_Input[0][2]) << " " << ruint32(Memory[0].P_Input[0][3]) << " " << ruint32(Memory[0].P_Input[0][4]) << " " << ruint32(Memory[0].P_Input[0][5]) << " " << ruint32(Memory[0].P_Input[0][6]) << " " << ruint32(Memory[0].P_Input[0][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[1][0]) << " " << ruint32(Memory[0].P_Input[1][1]) << " " << ruint32(Memory[0].P_Input[1][2]) << " " << ruint32(Memory[0].P_Input[1][3]) << " " << ruint32(Memory[0].P_Input[1][4]) << " " << ruint32(Memory[0].P_Input[1][5]) << " " << ruint32(Memory[0].P_Input[1][6]) << " " << ruint32(Memory[0].P_Input[1][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[2][0]) << " " << ruint32(Memory[0].P_Input[2][1]) << " " << ruint32(Memory[0].P_Input[2][2]) << " " << ruint32(Memory[0].P_Input[2][3]) << " " << ruint32(Memory[0].P_Input[2][4]) << " " << ruint32(Memory[0].P_Input[2][5]) << " " << ruint32(Memory[0].P_Input[2][6]) << " " << ruint32(Memory[0].P_Input[2][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[3][0]) << " " << ruint32(Memory[0].P_Input[3][1]) << " " << ruint32(Memory[0].P_Input[3][2]) << " " << ruint32(Memory[0].P_Input[3][3]) << " " << ruint32(Memory[0].P_Input[3][4]) << " " << ruint32(Memory[0].P_Input[3][5]) << " " << ruint32(Memory[0].P_Input[3][6]) << " " << ruint32(Memory[0].P_Input[3][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[0][8]) << " " << ruint32(Memory[0].P_Input[0][9]) << " " << ruint32(Memory[0].P_Input[0][10]) << " " << ruint32(Memory[0].P_Input[0][11]) << " " << ruint32(Memory[0].P_Input[0][12]) << " " << ruint32(Memory[0].P_Input[0][13]) << " " << ruint32(Memory[0].P_Input[0][14]) << " " << ruint32(Memory[0].P_Input[0][15]) << "\n";
       File01 << ruint32(Memory[0].P_Input[1][8]) << " " << ruint32(Memory[0].P_Input[1][9]) << " " << ruint32(Memory[0].P_Input[1][10]) << " " << ruint32(Memory[0].P_Input[1][11]) << " " << ruint32(Memory[0].P_Input[1][12]) << " " << ruint32(Memory[0].P_Input[1][13]) << " " << ruint32(Memory[0].P_Input[1][14]) << " " << ruint32(Memory[0].P_Input[1][15]) << "\n";
       File01 << ruint32(Memory[0].P_Input[2][8]) << " " << ruint32(Memory[0].P_Input[2][9]) << " " << ruint32(Memory[0].P_Input[2][10]) << " " << ruint32(Memory[0].P_Input[2][11]) << " " << ruint32(Memory[0].P_Input[2][12]) << " " << ruint32(Memory[0].P_Input[2][13]) << " " << ruint32(Memory[0].P_Input[2][14]) << " " << ruint32(Memory[0].P_Input[2][15]) << "\n";
       File01 << ruint32(Memory[0].P_Input[3][8]) << " " << ruint32(Memory[0].P_Input[3][9]) << " " << ruint32(Memory[0].P_Input[3][10]) << " " << ruint32(Memory[0].P_Input[3][11]) << " " << ruint32(Memory[0].P_Input[3][12]) << " " << ruint32(Memory[0].P_Input[3][13]) << " " << ruint32(Memory[0].P_Input[3][14]) << " " << ruint32(Memory[0].P_Input[3][15]) << "\n";
       File01 << ruint32(Memory[0].P_Con[0]) << " " << ruint32(Memory[0].P_Con[1]) << " " << ruint32(Memory[0].P_Con[2]) << " " << ruint32(Memory[0].P_Con[3]) << "\n";
       
       if(Memory[0].Meta_Selection){File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Custom_Mirror) {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Fast_Loading)  {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Show_FPS)      {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Show_Time)     {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Fullscreen)    {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Aspect_Ratio)  {File01 << "T ";} else {File01 << "F ";}
       File01 << ruint32(Memory[0].Health_Bar) << " " << ruint32(Memory[0].Engine) << " " << ruint32(Memory[0].Brightness) << " " << ruint32(Memory[0].Screen_W) << " " << ruint32(Memory[0].Screen_H) << " " << ruint32(Memory[0].Volume) << " " << ruint32(Memory[0].Pan) << " " << ruint32(Memory[0].Camera_Speed) << " " << ruint32(Memory[0].Max_SFX) << " " << ruint32(Memory[0].Max_Object) << "\n";
       File01 << L_Spacemaker(Memory[0].Address) + " " + L_Spacemaker(Memory[0].Data_Address) + "\n";
       
       if(Memory[0].Recording)     {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].True_Recording){File01 << "T ";} else {File01 << "F ";}
       File01 << L_Spacemaker(Memory[0].Record_Address) + "\n" + Memory[0].User + "\n" + Memory[0].Email + "\n" + Memory[0].Note + "\n";

       File01 << ruint32(Memory[0].Esc) << " " << ruint32(Memory[0].Enter) << " " << ruint32(Memory[0].F1) << " " << ruint32(Memory[0].F2) << " " << ruint32(Memory[0].F10) << " " << ruint32(Memory[0].F11) << " " << ruint32(Memory[0].F12) << " " << ruint32(Memory[0].F3) << " " << ruint32(Memory[0].F4) << " " << ruint32(Memory[0].F5) << " " << ruint32(Memory[0].F6) << " " << ruint32(Memory[0].F7) << " " << ruint32(Memory[0].F8) << " " << ruint32(Memory[0].F9) << "\n\n";
       File01 << Version() + "\n\n";
       
       if(Memory[0].E0_Random_Item)             {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].E0_High_Conditional_Dash)   {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].E0_Stackable_Velocity)      {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].E0_Kind14_Transpareness)    {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].E0_Kind14_Uncrossable)      {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].E0_High_Quality_Break_Parts){File01 << "T ";} else {File01 << "F ";}


       File01.close(); return true;
      }
      int0   Load_Memory() fastened
      {
       statics string Temp01 = "Database\\Game\\Enchanted\\config.ini";
       std::ifstream File01(Temp01); 
       if(!File01.is_open()){Save_Memory(); File01.open(Temp01);}
       if(!File01.is_open()) return;

       string Temp02;

       if(File01){File01 >> Temp02; if(Temp02 == "\376") Temp02 = ""; Memory[1].P_Name[0] = L_Revoke(Temp02, 255ui8, ' ');} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "\376") Temp02 = ""; Memory[1].P_Name[1] = L_Revoke(Temp02, 255ui8, ' ');} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "\376") Temp02 = ""; Memory[1].P_Name[2] = L_Revoke(Temp02, 255ui8, ' ');} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "\376") Temp02 = ""; Memory[1].P_Name[3] = L_Revoke(Temp02, 255ui8, ' ');} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[0][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[1][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[2][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[3][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[0][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[1][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[2][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[3][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Con[0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Con[1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Con[2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Con[3] = ruint8(L_Numbering(Temp02));} else {return;}
       
       if(File01){File01 >> Temp02; Memory[1].Meta_Selection = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Custom_Mirror = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Fast_Loading = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Show_FPS = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Show_Time = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Fullscreen = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Aspect_Ratio = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Health_Bar = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Engine = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Brightness = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Screen_W = ruint32(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Screen_H = ruint32(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Volume = ruint32(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Pan = L_Numbering(Temp02);} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Camera_Speed = ruint32(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Max_SFX = rinsize(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Max_Object = rinsize(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "\376") Temp02 = ""; L_Robust(Memory[1].Address = L_Revoke(Temp02, 255ui8, ' '));} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "\376") Temp02 = ""; L_Robust(Memory[1].Data_Address = L_Revoke(Temp02, 255ui8, ' '));} else {return;}

       if(File01){File01 >> Temp02; Memory[1].Recording = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].True_Recording = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "\376") Temp02 = ""; L_Robust(Memory[1].Record_Address = L_Revoke(Temp02, 255ui8, ' '));} else {return;}
       if(File01){std::getline(File01, Temp02); std::getline(File01, Memory[1].User);} else {return;}
       if(File01){std::getline(File01, Memory[1].Email);} else {return;}
       if(File01){std::getline(File01, Memory[1].Note);} else {return;}
       
       if(File01){File01 >> Temp02; Memory[1].Esc = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].Enter = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F1 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F2 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F10 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F11 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F12 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F3 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F4 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F5 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F6 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F7 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F8 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].F9 = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 != Version()){Memory[0] = Memory[1]; File01.close(); return;}} else {return;}

       Memory[0] = Memory[1];
       File01.close();
      }
     //-//
    };
   //-//

   HEPTA_INPUTS Input;
   unique < HEPTA_LF2_ENCHANTED > Enchanted;
  //-//
 //-//
 // Light Functions
  int0   L_Typing(string &Temp01) fastened
  {
   statics uint8 Vrab01 = ruint8(L_Rounding(256.0 / rxint64(Varb0004)) - 1) - 1, Vrab02 = Vrab01 - ruint8(L_Rounding(64.0 / rxint64(Varb0004)));
   if(Input.RESH_CAPS || Input.CONS_LSHIFT > 0 || Input.CONS_RSHIFT > 0)
   {
    {statics uint8 &Vrab03 = Input.MAIN_A; if(Vrab03 == Vrab02) Input.MAIN_A = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('A');}
    {statics uint8 &Vrab03 = Input.MAIN_B; if(Vrab03 == Vrab02) Input.MAIN_B = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('B');}
    {statics uint8 &Vrab03 = Input.MAIN_C; if(Vrab03 == Vrab02) Input.MAIN_C = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('C');}
    {statics uint8 &Vrab03 = Input.MAIN_D; if(Vrab03 == Vrab02) Input.MAIN_D = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('D');}
    {statics uint8 &Vrab03 = Input.MAIN_E; if(Vrab03 == Vrab02) Input.MAIN_E = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('E');}
    {statics uint8 &Vrab03 = Input.MAIN_F; if(Vrab03 == Vrab02) Input.MAIN_F = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('F');}
    {statics uint8 &Vrab03 = Input.MAIN_G; if(Vrab03 == Vrab02) Input.MAIN_G = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('G');}
    {statics uint8 &Vrab03 = Input.MAIN_H; if(Vrab03 == Vrab02) Input.MAIN_H = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('H');}
    {statics uint8 &Vrab03 = Input.MAIN_I; if(Vrab03 == Vrab02) Input.MAIN_I = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('I');}
    {statics uint8 &Vrab03 = Input.MAIN_J; if(Vrab03 == Vrab02) Input.MAIN_J = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('J');}
    {statics uint8 &Vrab03 = Input.MAIN_K; if(Vrab03 == Vrab02) Input.MAIN_K = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('K');}
    {statics uint8 &Vrab03 = Input.MAIN_L; if(Vrab03 == Vrab02) Input.MAIN_L = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('L');}
    {statics uint8 &Vrab03 = Input.MAIN_M; if(Vrab03 == Vrab02) Input.MAIN_M = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('M');}
    {statics uint8 &Vrab03 = Input.MAIN_N; if(Vrab03 == Vrab02) Input.MAIN_N = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('N');}
    {statics uint8 &Vrab03 = Input.MAIN_O; if(Vrab03 == Vrab02) Input.MAIN_O = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('O');}
    {statics uint8 &Vrab03 = Input.MAIN_P; if(Vrab03 == Vrab02) Input.MAIN_P = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('P');}
    {statics uint8 &Vrab03 = Input.MAIN_Q; if(Vrab03 == Vrab02) Input.MAIN_Q = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('Q');}
    {statics uint8 &Vrab03 = Input.MAIN_R; if(Vrab03 == Vrab02) Input.MAIN_R = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('R');}
    {statics uint8 &Vrab03 = Input.MAIN_S; if(Vrab03 == Vrab02) Input.MAIN_S = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('S');}
    {statics uint8 &Vrab03 = Input.MAIN_T; if(Vrab03 == Vrab02) Input.MAIN_T = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('T');}
    {statics uint8 &Vrab03 = Input.MAIN_U; if(Vrab03 == Vrab02) Input.MAIN_U = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('U');}
    {statics uint8 &Vrab03 = Input.MAIN_V; if(Vrab03 == Vrab02) Input.MAIN_V = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('V');}
    {statics uint8 &Vrab03 = Input.MAIN_W; if(Vrab03 == Vrab02) Input.MAIN_W = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('W');}
    {statics uint8 &Vrab03 = Input.MAIN_X; if(Vrab03 == Vrab02) Input.MAIN_X = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('X');}
    {statics uint8 &Vrab03 = Input.MAIN_Y; if(Vrab03 == Vrab02) Input.MAIN_Y = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('Y');}
    {statics uint8 &Vrab03 = Input.MAIN_Z; if(Vrab03 == Vrab02) Input.MAIN_Z = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('Z');}
   } else
   {
    {statics uint8 &Vrab03 = Input.MAIN_A; if(Vrab03 == Vrab02) Input.MAIN_A = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('a');}
    {statics uint8 &Vrab03 = Input.MAIN_B; if(Vrab03 == Vrab02) Input.MAIN_B = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('b');}
    {statics uint8 &Vrab03 = Input.MAIN_C; if(Vrab03 == Vrab02) Input.MAIN_C = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('c');}
    {statics uint8 &Vrab03 = Input.MAIN_D; if(Vrab03 == Vrab02) Input.MAIN_D = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('d');}
    {statics uint8 &Vrab03 = Input.MAIN_E; if(Vrab03 == Vrab02) Input.MAIN_E = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('e');}
    {statics uint8 &Vrab03 = Input.MAIN_F; if(Vrab03 == Vrab02) Input.MAIN_F = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('f');}
    {statics uint8 &Vrab03 = Input.MAIN_G; if(Vrab03 == Vrab02) Input.MAIN_G = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('g');}
    {statics uint8 &Vrab03 = Input.MAIN_H; if(Vrab03 == Vrab02) Input.MAIN_H = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('h');}
    {statics uint8 &Vrab03 = Input.MAIN_I; if(Vrab03 == Vrab02) Input.MAIN_I = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('i');}
    {statics uint8 &Vrab03 = Input.MAIN_J; if(Vrab03 == Vrab02) Input.MAIN_J = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('j');}
    {statics uint8 &Vrab03 = Input.MAIN_K; if(Vrab03 == Vrab02) Input.MAIN_K = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('k');}
    {statics uint8 &Vrab03 = Input.MAIN_L; if(Vrab03 == Vrab02) Input.MAIN_L = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('l');}
    {statics uint8 &Vrab03 = Input.MAIN_M; if(Vrab03 == Vrab02) Input.MAIN_M = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('m');}
    {statics uint8 &Vrab03 = Input.MAIN_N; if(Vrab03 == Vrab02) Input.MAIN_N = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('n');}
    {statics uint8 &Vrab03 = Input.MAIN_O; if(Vrab03 == Vrab02) Input.MAIN_O = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('o');}
    {statics uint8 &Vrab03 = Input.MAIN_P; if(Vrab03 == Vrab02) Input.MAIN_P = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('p');}
    {statics uint8 &Vrab03 = Input.MAIN_Q; if(Vrab03 == Vrab02) Input.MAIN_Q = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('q');}
    {statics uint8 &Vrab03 = Input.MAIN_R; if(Vrab03 == Vrab02) Input.MAIN_R = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('r');}
    {statics uint8 &Vrab03 = Input.MAIN_S; if(Vrab03 == Vrab02) Input.MAIN_S = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('s');}
    {statics uint8 &Vrab03 = Input.MAIN_T; if(Vrab03 == Vrab02) Input.MAIN_T = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('t');}
    {statics uint8 &Vrab03 = Input.MAIN_U; if(Vrab03 == Vrab02) Input.MAIN_U = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('u');}
    {statics uint8 &Vrab03 = Input.MAIN_V; if(Vrab03 == Vrab02) Input.MAIN_V = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('v');}
    {statics uint8 &Vrab03 = Input.MAIN_W; if(Vrab03 == Vrab02) Input.MAIN_W = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('w');}
    {statics uint8 &Vrab03 = Input.MAIN_X; if(Vrab03 == Vrab02) Input.MAIN_X = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('x');}
    {statics uint8 &Vrab03 = Input.MAIN_Y; if(Vrab03 == Vrab02) Input.MAIN_Y = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('y');}
    {statics uint8 &Vrab03 = Input.MAIN_Z; if(Vrab03 == Vrab02) Input.MAIN_Z = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('z');}
   }
   {statics uint8 &Vrab03 = Input.NUMS_0; if(Vrab03 == Vrab02) Input.NUMS_0 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('0');}
   {statics uint8 &Vrab03 = Input.NUMS_1; if(Vrab03 == Vrab02) Input.NUMS_1 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('1');}
   {statics uint8 &Vrab03 = Input.NUMS_2; if(Vrab03 == Vrab02) Input.NUMS_2 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('2');}
   {statics uint8 &Vrab03 = Input.NUMS_3; if(Vrab03 == Vrab02) Input.NUMS_3 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('3');}
   {statics uint8 &Vrab03 = Input.NUMS_4; if(Vrab03 == Vrab02) Input.NUMS_4 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('4');}
   {statics uint8 &Vrab03 = Input.NUMS_5; if(Vrab03 == Vrab02) Input.NUMS_5 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('5');}
   {statics uint8 &Vrab03 = Input.NUMS_6; if(Vrab03 == Vrab02) Input.NUMS_6 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('6');}
   {statics uint8 &Vrab03 = Input.NUMS_7; if(Vrab03 == Vrab02) Input.NUMS_7 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('7');}
   {statics uint8 &Vrab03 = Input.NUMS_8; if(Vrab03 == Vrab02) Input.NUMS_8 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('8');}
   {statics uint8 &Vrab03 = Input.NUMS_9; if(Vrab03 == Vrab02) Input.NUMS_9 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('9');}
   if(Input.CONS_LSHIFT > 0 || Input.CONS_RSHIFT > 0)
   {
    {statics uint8 &Vrab03 = Input.MAIN_0; if(Vrab03 == Vrab02) Input.MAIN_0 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back(')');}
    {statics uint8 &Vrab03 = Input.MAIN_1; if(Vrab03 == Vrab02) Input.MAIN_1 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('!');}
    {statics uint8 &Vrab03 = Input.MAIN_2; if(Vrab03 == Vrab02) Input.MAIN_2 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('@');}
    {statics uint8 &Vrab03 = Input.MAIN_3; if(Vrab03 == Vrab02) Input.MAIN_3 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('#');}
    {statics uint8 &Vrab03 = Input.MAIN_4; if(Vrab03 == Vrab02) Input.MAIN_4 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('$');}
    {statics uint8 &Vrab03 = Input.MAIN_5; if(Vrab03 == Vrab02) Input.MAIN_5 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('%');}
    {statics uint8 &Vrab03 = Input.MAIN_6; if(Vrab03 == Vrab02) Input.MAIN_6 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('^');}
    {statics uint8 &Vrab03 = Input.MAIN_7; if(Vrab03 == Vrab02) Input.MAIN_7 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('&');}
    {statics uint8 &Vrab03 = Input.MAIN_8; if(Vrab03 == Vrab02) Input.MAIN_8 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('*');}
    {statics uint8 &Vrab03 = Input.MAIN_9; if(Vrab03 == Vrab02) Input.MAIN_9 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('(');}
    {statics uint8 &Vrab03 = Input.MAIN_TILDE;        if(Vrab03 == Vrab02) Input.MAIN_TILDE = Vrab01;        if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('~');}
    {statics uint8 &Vrab03 = Input.MAIN_MINUS;        if(Vrab03 == Vrab02) Input.MAIN_MINUS = Vrab01;        if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('_');}
    {statics uint8 &Vrab03 = Input.MAIN_PLUS;         if(Vrab03 == Vrab02) Input.MAIN_PLUS = Vrab01;         if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('+');}
    {statics uint8 &Vrab03 = Input.MAIN_OPENBRACKED;  if(Vrab03 == Vrab02) Input.MAIN_OPENBRACKED = Vrab01;  if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('{');}
    {statics uint8 &Vrab03 = Input.MAIN_CLOSEBRACKED; if(Vrab03 == Vrab02) Input.MAIN_CLOSEBRACKED = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('}');}
    {statics uint8 &Vrab03 = Input.MAIN_PIPE;         if(Vrab03 == Vrab02) Input.MAIN_PIPE = Vrab01;         if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('|');}
    {statics uint8 &Vrab03 = Input.MAIN_SEMICOLON;    if(Vrab03 == Vrab02) Input.MAIN_SEMICOLON = Vrab01;    if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back(':');}
    {statics uint8 &Vrab03 = Input.MAIN_QUOTES;       if(Vrab03 == Vrab02) Input.MAIN_QUOTES = Vrab01;       if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('\"');}
    {statics uint8 &Vrab03 = Input.MAIN_QUESTION;     if(Vrab03 == Vrab02) Input.MAIN_QUESTION = Vrab01;     if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('?');}
    {statics uint8 &Vrab03 = Input.MAIN_PERIOD;       if(Vrab03 == Vrab02) Input.MAIN_PERIOD = Vrab01;       if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('>');}
    {statics uint8 &Vrab03 = Input.MAIN_COMMA;        if(Vrab03 == Vrab02) Input.MAIN_COMMA = Vrab01;        if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('<');}
   } else
   {
    {statics uint8 &Vrab03 = Input.MAIN_0; if(Vrab03 == Vrab02) Input.MAIN_0 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('0');}
    {statics uint8 &Vrab03 = Input.MAIN_1; if(Vrab03 == Vrab02) Input.MAIN_1 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('1');}
    {statics uint8 &Vrab03 = Input.MAIN_2; if(Vrab03 == Vrab02) Input.MAIN_2 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('2');}
    {statics uint8 &Vrab03 = Input.MAIN_3; if(Vrab03 == Vrab02) Input.MAIN_3 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('3');}
    {statics uint8 &Vrab03 = Input.MAIN_4; if(Vrab03 == Vrab02) Input.MAIN_4 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('4');}
    {statics uint8 &Vrab03 = Input.MAIN_5; if(Vrab03 == Vrab02) Input.MAIN_5 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('5');}
    {statics uint8 &Vrab03 = Input.MAIN_6; if(Vrab03 == Vrab02) Input.MAIN_6 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('6');}
    {statics uint8 &Vrab03 = Input.MAIN_7; if(Vrab03 == Vrab02) Input.MAIN_7 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('7');}
    {statics uint8 &Vrab03 = Input.MAIN_8; if(Vrab03 == Vrab02) Input.MAIN_8 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('8');}
    {statics uint8 &Vrab03 = Input.MAIN_9; if(Vrab03 == Vrab02) Input.MAIN_9 = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('9');}
    {statics uint8 &Vrab03 = Input.MAIN_TILDE;        if(Vrab03 == Vrab02) Input.MAIN_TILDE = Vrab01;        if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('`');}
    {statics uint8 &Vrab03 = Input.MAIN_MINUS;        if(Vrab03 == Vrab02) Input.MAIN_MINUS = Vrab01;        if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('-');}
    {statics uint8 &Vrab03 = Input.MAIN_PLUS;         if(Vrab03 == Vrab02) Input.MAIN_PLUS = Vrab01;         if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('=');}
    {statics uint8 &Vrab03 = Input.MAIN_OPENBRACKED;  if(Vrab03 == Vrab02) Input.MAIN_OPENBRACKED = Vrab01;  if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('[');}
    {statics uint8 &Vrab03 = Input.MAIN_CLOSEBRACKED; if(Vrab03 == Vrab02) Input.MAIN_CLOSEBRACKED = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back(']');}
    {statics uint8 &Vrab03 = Input.MAIN_PIPE;         if(Vrab03 == Vrab02) Input.MAIN_PIPE = Vrab01;         if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('\\');}
    {statics uint8 &Vrab03 = Input.MAIN_SEMICOLON;    if(Vrab03 == Vrab02) Input.MAIN_SEMICOLON = Vrab01;    if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back(';');}
    {statics uint8 &Vrab03 = Input.MAIN_QUOTES;       if(Vrab03 == Vrab02) Input.MAIN_QUOTES = Vrab01;       if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('\'');}
    {statics uint8 &Vrab03 = Input.MAIN_QUESTION;     if(Vrab03 == Vrab02) Input.MAIN_QUESTION = Vrab01;     if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('/');}
    {statics uint8 &Vrab03 = Input.MAIN_PERIOD;       if(Vrab03 == Vrab02) Input.MAIN_PERIOD = Vrab01;       if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('.');}
    {statics uint8 &Vrab03 = Input.MAIN_COMMA;        if(Vrab03 == Vrab02) Input.MAIN_COMMA = Vrab01;        if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back(',');}
   }
   {statics uint8 &Vrab03 = Input.MAIN_SPACE; if(Vrab03 == Vrab02) Input.MAIN_SPACE = Vrab01; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back(' ');}
   {statics uint8 &Vrab03 = Input.CONS_BACK;  if(Vrab03 == Vrab02) Input.CONS_BACK = Vrab01;  if(Vrab03 == 1 || Vrab03 == Vrab01) if(Temp01.size() > 0) Temp01.pop_back();}
  }
  int0   L_Robust(string &Temp01) fastened {string Temp02; insize Vrab01 = 0; statics insize Vrab02 = Temp01.size(); while(Vrab01 != Vrab02){statics uint8 Vrab03 = Temp01.at(Vrab01); switch(Vrab03){case '/': case ':': case '*': case '?': case '\"': case '<': case '>': case '|': Vrab01 += 1; continue; default: break;} Temp02 += Vrab03; Vrab01 += 1;} Temp01 = Temp02;}
  int1   L_Within(statics int64 Vrab01, statics int64 Vrab02, statics int64 Vrab03, statics int64 Vrab04, statics uint64 Vrab05, statics uint64 Vrab06) fastened {if(Vrab01 >= Vrab03 && Vrab01 <= rint64(Vrab03 + Vrab05)) if(Vrab02 >= Vrab04 && Vrab02 <= rint64(Vrab04 + Vrab06)) return true; return false;}
  int1   L_In(statics int64 Vrab01, statics int64 Vrab02, statics int64 Vrab03, statics int64 Vrab04) fastened
  {
   return L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, Vrab01, Vrab02, Vrab03, Vrab04);
  }
  int1   L_On(statics int64 Vrab01, statics int64 Vrab02, statics int64 Vrab03, statics int64 Vrab04) fastened
  {
   return L_Within(Input.MOUS_X, Input.MOUS_Y, Vrab01, Vrab02, Vrab03, Vrab04) && (Input.MOUS_Left_Release == 1);
  }
  int1   L_Exist(statics string &Temp01)  fastened {struct stat Vrab01; return (stat(Temp01.c_str(), &Vrab01) == 0);}
  uint8  L_Press() fastened 
  {
   if(L_Input(Varb0019) == 1 || L_Input(Varb0020)) return 0ui8;
   if(Input.MAIN_1 == 1) return 1ui8;
   if(Input.MAIN_2 == 1) return 2ui8;
   if(Input.MAIN_3 == 1) return 3ui8;
   if(Input.MAIN_4 == 1) return 4ui8;
   if(Input.MAIN_5 == 1) return 5ui8;
   if(Input.MAIN_6 == 1) return 6ui8;
   if(Input.MAIN_7 == 1) return 7ui8;
   if(Input.MAIN_8 == 1) return 8ui8;
   if(Input.MAIN_9 == 1) return 9ui8;
   if(Input.MAIN_0 == 1) return 10ui8;
   if(Input.MAIN_A == 1) return 11ui8;
   if(Input.MAIN_B == 1) return 12ui8;
   if(Input.MAIN_C == 1) return 13ui8;
   if(Input.MAIN_D == 1) return 14ui8;
   if(Input.MAIN_E == 1) return 15ui8;
   if(Input.MAIN_F == 1) return 16ui8;
   if(Input.MAIN_G == 1) return 17ui8;
   if(Input.MAIN_H == 1) return 18ui8;
   if(Input.MAIN_I == 1) return 19ui8;
   if(Input.MAIN_J == 1) return 20ui8;
   if(Input.MAIN_K == 1) return 21ui8;
   if(Input.MAIN_L == 1) return 22ui8;
   if(Input.MAIN_M == 1) return 23ui8;
   if(Input.MAIN_N == 1) return 24ui8;
   if(Input.MAIN_O == 1) return 25ui8;
   if(Input.MAIN_P == 1) return 26ui8;
   if(Input.MAIN_Q == 1) return 27ui8;
   if(Input.MAIN_R == 1) return 28ui8;
   if(Input.MAIN_S == 1) return 29ui8;
   if(Input.MAIN_T == 1) return 30ui8;
   if(Input.MAIN_U == 1) return 31ui8;
   if(Input.MAIN_V == 1) return 32ui8;
   if(Input.MAIN_W == 1) return 33ui8;
   if(Input.MAIN_X == 1) return 34ui8;
   if(Input.MAIN_Y == 1) return 35ui8;
   if(Input.MAIN_Z == 1) return 36ui8;
   if(Input.MAIN_TILDE == 1)        return 37ui8;
   if(Input.MAIN_MINUS == 1)        return 38ui8;
   if(Input.MAIN_PLUS == 1)         return 39ui8;
   if(Input.MAIN_OPENBRACKED == 1)  return 40ui8;
   if(Input.MAIN_CLOSEBRACKED == 1) return 41ui8;
   if(Input.MAIN_PIPE == 1)         return 42ui8;
   if(Input.MAIN_SEMICOLON == 1)    return 43ui8;
   if(Input.MAIN_QUOTES == 1)       return 44ui8;
   if(Input.MAIN_QUESTION == 1)     return 45ui8;
   if(Input.MAIN_PERIOD == 1)       return 46ui8;
   if(Input.MAIN_COMMA == 1)        return 47ui8;
   if(Input.CONS_UP == 1)    return 48ui8;
   if(Input.CONS_LEFT == 1)  return 49ui8;
   if(Input.CONS_DOWN == 1)  return 50ui8;
   if(Input.CONS_RIGHT == 1) return 51ui8;
   if(Input.CONS_ESC == 1) return 52ui8;
   if(Input.CONS_F1 == 1)  return 53ui8;
   if(Input.CONS_F2 == 1)  return 54ui8;
   if(Input.CONS_F3 == 1)  return 55ui8;
   if(Input.CONS_F4 == 1)  return 56ui8;
   if(Input.CONS_F5 == 1)  return 57ui8;
   if(Input.CONS_F6 == 1)  return 58ui8;
   if(Input.CONS_F7 == 1)  return 59ui8;
   if(Input.CONS_F8 == 1)  return 60ui8;
   if(Input.CONS_F9 == 1)  return 61ui8;
   if(Input.CONS_F10 == 1) return 62ui8;
   if(Input.CONS_F11 == 1) return 63ui8;
   if(Input.CONS_F12 == 1) return 64ui8;
   if(Input.CONS_PRTSC == 1)  return 65ui8;
   if(Input.CONS_DELETE == 1) return 66ui8;
   if(Input.CONS_BACK == 1)   return 67ui8;
   if(Input.CONS_TAB == 1)    return 68ui8;
   if(Input.CONS_CAPS == 1)   return 69ui8;
   if(Input.CONS_ENTER == 1)  return 70ui8;
   if(Input.CONS_LSHIFT == 1) return 71ui8;
   if(Input.CONS_RSHIFT == 1) return 72ui8;
   if(Input.CONS_LCTRL == 1)  return 73ui8;
   if(Input.CONS_RCTRL == 1)  return 74ui8;
   if(Input.CONS_LALT == 1)   return 75ui8;
   if(Input.CONS_RALT == 1)   return 76ui8;
   if(Input.NUMS_NUMLOCK == 1)  return 77ui8;
   if(Input.NUMS_MULTIPLE == 1) return 78ui8;
   if(Input.NUMS_DEVIDE == 1)   return 79ui8;
   if(Input.NUMS_ADD == 1)      return 80ui8;
   if(Input.NUMS_SUBTRACT == 1) return 81ui8;
   if(Input.NUMS_1 == 1) return 82ui8;
   if(Input.NUMS_2 == 1) return 83ui8;
   if(Input.NUMS_3 == 1) return 84ui8;
   if(Input.NUMS_4 == 1) return 85ui8;
   if(Input.NUMS_5 == 1) return 86ui8;
   if(Input.NUMS_6 == 1) return 87ui8;
   if(Input.NUMS_7 == 1) return 88ui8;
   if(Input.NUMS_8 == 1) return 89ui8;
   if(Input.NUMS_9 == 1) return 90ui8;
   if(Input.NUMS_0 == 1) return 91ui8;
   if(Input.NUMS_POINT == 1) return 92ui8;
   if(Input.MAIN_SPACE == 1) return 94ui8;
   return 255ui8;
  }
  uint8  L_Input(uint8 Vrab01) fastened
  {
   switch(Vrab01)
   {
    case 1: return Input.MAIN_1;
    case 2: return Input.MAIN_2;
    case 3: return Input.MAIN_3;
    case 4: return Input.MAIN_4;
    case 5: return Input.MAIN_5;
    case 6: return Input.MAIN_6;
    case 7: return Input.MAIN_7;
    case 8: return Input.MAIN_8;
    case 9: return Input.MAIN_9;
    case 10: return Input.MAIN_0;
    case 11: return Input.MAIN_A;
    case 12: return Input.MAIN_B;
    case 13: return Input.MAIN_C;
    case 14: return Input.MAIN_D;
    case 15: return Input.MAIN_E;
    case 16: return Input.MAIN_F;
    case 17: return Input.MAIN_G;
    case 18: return Input.MAIN_H;
    case 19: return Input.MAIN_I;
    case 20: return Input.MAIN_J;
    case 21: return Input.MAIN_K;
    case 22: return Input.MAIN_L;
    case 23: return Input.MAIN_M;
    case 24: return Input.MAIN_N;
    case 25: return Input.MAIN_O;
    case 26: return Input.MAIN_P;
    case 27: return Input.MAIN_Q;
    case 28: return Input.MAIN_R;
    case 29: return Input.MAIN_S;
    case 30: return Input.MAIN_T;
    case 31: return Input.MAIN_U;
    case 32: return Input.MAIN_V;
    case 33: return Input.MAIN_W;
    case 34: return Input.MAIN_X;
    case 35: return Input.MAIN_Y;
    case 36: return Input.MAIN_Z;
    case 37: return Input.MAIN_TILDE;
    case 38: return Input.MAIN_MINUS;
    case 39: return Input.MAIN_PLUS;
    case 40: return Input.MAIN_OPENBRACKED;
    case 41: return Input.MAIN_CLOSEBRACKED;
    case 42: return Input.MAIN_PIPE;
    case 43: return Input.MAIN_SEMICOLON;
    case 44: return Input.MAIN_QUOTES;
    case 45: return Input.MAIN_QUESTION;
    case 46: return Input.MAIN_PERIOD;
    case 47: return Input.MAIN_COMMA;
    case 48: return Input.CONS_UP;
    case 49: return Input.CONS_LEFT;
    case 50: return Input.CONS_DOWN;
    case 51: return Input.CONS_RIGHT;
    case 52: return Input.CONS_ESC;
    case 53: return Input.CONS_F1;
    case 54: return Input.CONS_F2;
    case 55: return Input.CONS_F3;
    case 56: return Input.CONS_F4;
    case 57: return Input.CONS_F5;
    case 58: return Input.CONS_F6;
    case 59: return Input.CONS_F7;
    case 60: return Input.CONS_F8;
    case 61: return Input.CONS_F9;
    case 62: return Input.CONS_F10;
    case 63: return Input.CONS_F11;
    case 64: return Input.CONS_F12;
    case 65: return Input.CONS_PRTSC;
    case 66: return Input.CONS_DELETE;
    case 67: return Input.CONS_BACK;
    case 68: return Input.CONS_TAB;
    case 69: return Input.CONS_CAPS;
    case 70: return Input.CONS_ENTER;
    case 71: return Input.CONS_LSHIFT;
    case 72: return Input.CONS_RSHIFT;
    case 73: return Input.CONS_LCTRL;
    case 74: return Input.CONS_RCTRL;
    case 75: return Input.CONS_LALT;
    case 76: return Input.CONS_RALT;
    case 77: return Input.NUMS_NUMLOCK;
    case 78: return Input.NUMS_MULTIPLE;
    case 79: return Input.NUMS_DEVIDE;
    case 80: return Input.NUMS_ADD;
    case 81: return Input.NUMS_SUBTRACT;
    case 82: return Input.NUMS_1;
    case 83: return Input.NUMS_2;
    case 84: return Input.NUMS_3;
    case 85: return Input.NUMS_4;
    case 86: return Input.NUMS_5;
    case 87: return Input.NUMS_6;
    case 88: return Input.NUMS_7;
    case 89: return Input.NUMS_8;
    case 90: return Input.NUMS_9;
    case 91: return Input.NUMS_0;
    case 92: return Input.NUMS_POINT;
    case 94: return Input.MAIN_SPACE;
   
    default: return 0;
   }
  }
  int32  L_Numbering(string Temp01)       fastened {while(Temp01.size() > 0 && Temp01.at(0) != '-' && (Temp01.at(0) < '0' || Temp01.at(0) > '9')) Temp01.erase(0, 1); uint32 Vrab01 = Temp01.size(); if(Vrab01 == 0) return 0; while(Vrab01 != 1) if(Temp01.at(Vrab01 - 1) < '0' || Temp01.at(Vrab01 - 1) > '9'){Vrab01 -= 1;} else {break;} int32 Vrab02 = 0; if(Temp01.at(0) == '-'){if(Vrab01 == 1) return 0; if(Temp01.at(1) < '0' || Temp01.at(1) > '9') return 0; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1; break; case '2': Vrab02 -= 2; break; case '3': Vrab02 -= 3; break; case '4': Vrab02 -= 4; break; case '5': Vrab02 -= 5; break; case '6': Vrab02 -= 6; break; case '7': Vrab02 -= 7; break; case '8': Vrab02 -= 8; break; case '9': Vrab02 -= 9; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10; break; case '2': Vrab02 -= 20; break; case '3': Vrab02 -= 30; break; case '4': Vrab02 -= 40; break; case '5': Vrab02 -= 50; break; case '6': Vrab02 -= 60; break; case '7': Vrab02 -= 70; break; case '8': Vrab02 -= 80; break; case '9': Vrab02 -= 90; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100; break; case '2': Vrab02 -= 200; break; case '3': Vrab02 -= 300; break; case '4': Vrab02 -= 400; break; case '5': Vrab02 -= 500; break; case '6': Vrab02 -= 600; break; case '7': Vrab02 -= 700; break; case '8': Vrab02 -= 800; break; case '9': Vrab02 -= 900; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000; break; case '2': Vrab02 -= 2000; break; case '3': Vrab02 -= 3000; break; case '4': Vrab02 -= 4000; break; case '5': Vrab02 -= 5000; break; case '6': Vrab02 -= 6000; break; case '7': Vrab02 -= 7000; break; case '8': Vrab02 -= 8000; break; case '9': Vrab02 -= 9000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000; break; case '2': Vrab02 -= 20000; break; case '3': Vrab02 -= 30000; break; case '4': Vrab02 -= 40000; break; case '5': Vrab02 -= 50000; break; case '6': Vrab02 -= 60000; break; case '7': Vrab02 -= 70000; break; case '8': Vrab02 -= 80000; break; case '9': Vrab02 -= 90000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000; break; case '2': Vrab02 -= 200000; break; case '3': Vrab02 -= 300000; break; case '4': Vrab02 -= 400000; break; case '5': Vrab02 -= 500000; break; case '6': Vrab02 -= 600000; break; case '7': Vrab02 -= 700000; break; case '8': Vrab02 -= 800000; break; case '9': Vrab02 -= 900000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000000; break; case '2': Vrab02 -= 2000000; break; case '3': Vrab02 -= 3000000; break; case '4': Vrab02 -= 4000000; break; case '5': Vrab02 -= 5000000; break; case '6': Vrab02 -= 6000000; break; case '7': Vrab02 -= 7000000; break; case '8': Vrab02 -= 8000000; break; case '9': Vrab02 -= 9000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000000; break; case '2': Vrab02 -= 20000000; break; case '3': Vrab02 -= 30000000; break; case '4': Vrab02 -= 40000000; break; case '5': Vrab02 -= 50000000; break; case '6': Vrab02 -= 60000000; break; case '7': Vrab02 -= 70000000; break; case '8': Vrab02 -= 80000000; break; case '9': Vrab02 -= 90000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000; break; case '2': Vrab02 -= 200000000; break; case '3': Vrab02 -= 300000000; break; case '4': Vrab02 -= 400000000; break; case '5': Vrab02 -= 500000000; break; case '6': Vrab02 -= 600000000; break; case '7': Vrab02 -= 700000000; break; case '8': Vrab02 -= 800000000; break; case '9': Vrab02 -= 900000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; for(int32 Vrab03 = 10; Vrab01 > 0; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000 * Vrab03; break; case '2': Vrab02 -= 200000000 * Vrab03; break; case '3': Vrab02 -= 300000000 * Vrab03; break; case '4': Vrab02 -= 400000000 * Vrab03; break; case '5': Vrab02 -= 500000000 * Vrab03; break; case '6': Vrab02 -= 600000000 * Vrab03; break; case '7': Vrab02 -= 700000000 * Vrab03; break; case '8': Vrab02 -= 800000000 * Vrab03; break; case '9': Vrab02 -= 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;} else {Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1; break; case '2': Vrab02 += 2; break; case '3': Vrab02 += 3; break; case '4': Vrab02 += 4; break; case '5': Vrab02 += 5; break; case '6': Vrab02 += 6; break; case '7': Vrab02 += 7; break; case '8': Vrab02 += 8; break; case '9': Vrab02 += 9; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10; break; case '2': Vrab02 += 20; break; case '3': Vrab02 += 30; break; case '4': Vrab02 += 40; break; case '5': Vrab02 += 50; break; case '6': Vrab02 += 60; break; case '7': Vrab02 += 70; break; case '8': Vrab02 += 80; break; case '9': Vrab02 += 90; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100; break; case '2': Vrab02 += 200; break; case '3': Vrab02 += 300; break; case '4': Vrab02 += 400; break; case '5': Vrab02 += 500; break; case '6': Vrab02 += 600; break; case '7': Vrab02 += 700; break; case '8': Vrab02 += 800; break; case '9': Vrab02 += 900; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000; break; case '2': Vrab02 += 2000; break; case '3': Vrab02 += 3000; break; case '4': Vrab02 += 4000; break; case '5': Vrab02 += 5000; break; case '6': Vrab02 += 6000; break; case '7': Vrab02 += 7000; break; case '8': Vrab02 += 8000; break; case '9': Vrab02 += 9000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000; break; case '2': Vrab02 += 20000; break; case '3': Vrab02 += 30000; break; case '4': Vrab02 += 40000; break; case '5': Vrab02 += 50000; break; case '6': Vrab02 += 60000; break; case '7': Vrab02 += 70000; break; case '8': Vrab02 += 80000; break; case '9': Vrab02 += 90000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000; break; case '2': Vrab02 += 200000; break; case '3': Vrab02 += 300000; break; case '4': Vrab02 += 400000; break; case '5': Vrab02 += 500000; break; case '6': Vrab02 += 600000; break; case '7': Vrab02 += 700000; break; case '8': Vrab02 += 800000; break; case '9': Vrab02 += 900000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000000; break; case '2': Vrab02 += 2000000; break; case '3': Vrab02 += 3000000; break; case '4': Vrab02 += 4000000; break; case '5': Vrab02 += 5000000; break; case '6': Vrab02 += 6000000; break; case '7': Vrab02 += 7000000; break; case '8': Vrab02 += 8000000; break; case '9': Vrab02 += 9000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000000; break; case '2': Vrab02 += 20000000; break; case '3': Vrab02 += 30000000; break; case '4': Vrab02 += 40000000; break; case '5': Vrab02 += 50000000; break; case '6': Vrab02 += 60000000; break; case '7': Vrab02 += 70000000; break; case '8': Vrab02 += 80000000; break; case '9': Vrab02 += 90000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000; break; case '2': Vrab02 += 200000000; break; case '3': Vrab02 += 300000000; break; case '4': Vrab02 += 400000000; break; case '5': Vrab02 += 500000000; break; case '6': Vrab02 += 600000000; break; case '7': Vrab02 += 700000000; break; case '8': Vrab02 += 800000000; break; case '9': Vrab02 += 900000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; for(int32 Vrab03 = 10; Vrab01 != -1; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000 * Vrab03; break; case '2': Vrab02 += 200000000 * Vrab03; break; case '3': Vrab02 += 300000000 * Vrab03; break; case '4': Vrab02 += 400000000 * Vrab03; break; case '5': Vrab02 += 500000000 * Vrab03; break; case '6': Vrab02 += 600000000 * Vrab03; break; case '7': Vrab02 += 700000000 * Vrab03; break; case '8': Vrab02 += 800000000 * Vrab03; break; case '9': Vrab02 += 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;}}
  int32  L_Positive(int32 Vrab01)         fastened {if(Vrab01 < 0) return -Vrab01; return Vrab01;}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
  int32  L_Rounding(xint64 Vrab01)        fastened {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint32(Vrab01); return rint32(Vrab01) + (Vrab02 ? -1 : 1);}
  int64  L_Rounding64(xint64 Vrab01)      fastened {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint64(Vrab01); return rint64(Vrab01) + (Vrab02 ? -1 : 1);}
  uint64 L_Interprocessing(statics string &Temp01) fastened 
  {
   insize Vrab01 = Temp01.size(); uint64 Vrab02 = 0; uint64 Vrab03 = 0;
   while(Vrab01 != 0)
   {
    Vrab01 -= 1;
    switch(Temp01.at(Vrab01))
    {
     case '0': break;
     case '1': Vrab03 += (1ULL << Vrab02); break;
     case '2': Vrab03 += (2ULL << Vrab02); break;
     case '3': Vrab03 += (3ULL << Vrab02); break;
     case '4': Vrab03 += (4ULL << Vrab02); break;
     case '5': Vrab03 += (5ULL << Vrab02); break;
     case '6': Vrab03 += (6ULL << Vrab02); break;
     case '7': Vrab03 += (7ULL << Vrab02); break;
     case '8': Vrab03 += (8ULL << Vrab02); break;
     case '9': Vrab03 += (9ULL << Vrab02); break;
     case 'A': case 'a': Vrab03 += (10ULL << Vrab02); break;
     case 'B': case 'b': Vrab03 += (11ULL << Vrab02); break;
     case 'C': case 'c': Vrab03 += (12ULL << Vrab02); break;
     case 'D': case 'd': Vrab03 += (13ULL << Vrab02); break;
     case 'E': case 'e': Vrab03 += (14ULL << Vrab02); break;
     case 'F': case 'f': Vrab03 += (15ULL << Vrab02); break;
     case 'x': case 'X': return Vrab03;
     default: return 0;
    }
    Vrab02 += 4;
   }
   return Vrab03;
  }
  uint64 L_Random(uint64 Vrab01)          fastened {remains std::mt19937 Vrab02; if(!Varb0016){Vrab02 = std::mt19937(ruint32(Varb0015)); Varb0016 = true;} Varb0015 += 1; remains statics std::uniform_int_distribution < uint32 > Vrab03(0, ruint32(-1)); uint64 Vrab04 = Vrab03(Vrab02); Vrab04 %= ruint64(0xFFFFFFFF) + 1; return ruint64(L_Rounding64((rxint64(Vrab04) / rxint64(0xFFFFFFFF)) * rxint64(Vrab01)));}
  xint64 L_Positive64(xint64 Vrab01)      fastened {if(Vrab01 < 0) return -Vrab01; return Vrab01;} 
  xint64 L_Doubling(string Temp01)        fastened 
  {
   statics insize Vrab01 = Temp01.size(); insize Vrab02 = Vrab01; while(Vrab02 != 0){Vrab02 -= 1; if(Temp01.at(Vrab02) == '.') break;}
   xint64 Vrab03 = 0.0;
   if(Temp01.at(Vrab02) == '.')
   {
    if(Vrab02 != 0) Vrab03 = rxint64(L_Numbering(string(Temp01, 0, Vrab02)));
    int32 Vrab04 = Vrab01 - Vrab02 + 1; if(Vrab04 < 9){Vrab04 = L_Numbering(string(Temp01, Vrab02 + 1, Vrab04));} else {Vrab04 = L_Numbering(string(Temp01, Vrab02 + 1, 9));}
    statics int32 Vrab05 = Vrab04; int1 Vrab06 = false; while(true){if(Vrab03 != 0.0){Vrab06 = Vrab03 < 0; break;} while(Vrab02 != 0){Vrab02 -= 1; if(Temp01.at(Vrab02) == '-'){Vrab06 = true; break;}} break;}
    if(Vrab06) Vrab04 = -Vrab04;
    if(Vrab05 < 10)
    {
     Vrab03 += rxint64(Vrab04) / 10.0;
    } else
    {
     if(Vrab05 < 100)
     {
      Vrab03 += rxint64(Vrab04) / 100.0;
     } else
     {
      if(Vrab05 < 1000)
      {
       Vrab03 += rxint64(Vrab04) / 1000.0;
      } else
      {
       if(Vrab05 < 10000)
       {
        Vrab03 += rxint64(Vrab04) / 10000.0;
       } else
       {
        if(Vrab05 < 100000)
        {
         Vrab03 += rxint64(Vrab04) / 100000.0;
        } else
        {
         if(Vrab05 < 1000000)
         {
          Vrab03 += rxint64(Vrab04) / 1000000.0;
         } else
         {
          if(Vrab05 < 10000000)
          {
           Vrab03 += rxint64(Vrab04) / 10000000.0;
          } else
          {
           if(Vrab05 < 100000000)
           {
            Vrab03 += rxint64(Vrab04) / 100000000.0;
           } else
           {
            Vrab03 += rxint64(Vrab04) / 1000000000.0;
           }
          }
         }
        }
       }
      }
     }
    }
   } else
   {
    Vrab03 = rxint64(L_Numbering(Temp01));
   }
   return Vrab03;
  }
  xint64 L_Distance(xint64 Vrab01, xint64 Vrab02, xint64 Vrab03, xint64 Vrab04) fastened
  {
   return sqrt(pow(Vrab03 - Vrab01, 2) + pow(Vrab04 - Vrab02, 2));
  }
  string L_Number(insize Vrab01)          fastened {statics string Temp01 = std::to_string(Vrab01); Vrab01 %= 100; if(Vrab01 <= 10 || Vrab01 >= 20){switch(ruint8(Vrab01 % 10)){case 1: return Temp01 + "st"; case 2: return Temp01 + "nd"; case 3: return Temp01 + "rd"; default: return Temp01 + "th";}} else {return Temp01 + "th";}}
  string L_Lowercase(string Temp01)       fastened {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) >= 'A' && Temp01.at(Vrab01) <= 'Z') Temp01.at(Vrab01) += 32;} return Temp01;}
  string L_Spacemaker(string Temp01)      fastened {insize Vrab01 = Temp01.size(); if(Vrab01 == 0) return "\376"; while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) == ' ') Temp01.at(Vrab01) = '\377';} return Temp01;}
  string L_Execute(statics string Temp01) fastened {string Temp02 = Temp01; uint32 Vrab01 = Temp02.size() - 1; while(Vrab01 != 0 && Temp02.at(Vrab01) != '\\') Vrab01 -= 1; if(Vrab01 > 0) Temp02.erase(Vrab01, Temp02.size() - Vrab01); std::filesystem::create_directories(Temp02); return Temp01;}
  string L_Rename(string Temp01, string Temp02) fastened 
  {
   insize Vrab01 = Temp01.size();
   while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) == '.') break;}
   if(Vrab01 != 0){Temp01.insert(Vrab01, Temp02);} else {Temp01 += Temp02;}
   return Temp01;
  }
  string L_Focus(statics string Temp01)   fastened {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; statics int8 Vrab02 = Temp01.at(Vrab01); if(Vrab02 == '\\' || Vrab02 == '/'){Vrab01 += 1; return string(Temp01, Vrab01, Temp01.size() - Vrab01);}} return Temp01;}
  string L_Revoke(string Temp01, uint8 Vrab01, uint8 Vrab02) fastened {insize Vrab03 = Temp01.size(); while(Vrab03 != 0){Vrab03 -= 1; if(Temp01.at(Vrab03) == Vrab01) Temp01.at(Vrab03) = Vrab02;} return Temp01;}
 //-//
 // Prime Functions
  int0 P_EngineInput(DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01)
  {
   auto Ikey02 = Ikey01->GetState(); statics uint8 Vrab01 = ruint8(L_Rounding(256.0 / rxint64(Varb0004)) - 1), Vrab02 = Vrab01 - ruint8(L_Rounding(32.0 / rxint64(Varb0004))); 
   if(Ikey02.D0){if((++Input.MAIN_0) == Vrab01) Input.MAIN_0 = Vrab02;} else {Input.MAIN_0 = 0ui8;}
   if(Ikey02.D1){if((++Input.MAIN_1) == Vrab01) Input.MAIN_1 = Vrab02;} else {Input.MAIN_1 = 0ui8;}
   if(Ikey02.D2){if((++Input.MAIN_2) == Vrab01) Input.MAIN_2 = Vrab02;} else {Input.MAIN_2 = 0ui8;}
   if(Ikey02.D3){if((++Input.MAIN_3) == Vrab01) Input.MAIN_3 = Vrab02;} else {Input.MAIN_3 = 0ui8;}
   if(Ikey02.D4){if((++Input.MAIN_4) == Vrab01) Input.MAIN_4 = Vrab02;} else {Input.MAIN_4 = 0ui8;}
   if(Ikey02.D5){if((++Input.MAIN_5) == Vrab01) Input.MAIN_5 = Vrab02;} else {Input.MAIN_5 = 0ui8;}
   if(Ikey02.D6){if((++Input.MAIN_6) == Vrab01) Input.MAIN_6 = Vrab02;} else {Input.MAIN_6 = 0ui8;}
   if(Ikey02.D7){if((++Input.MAIN_7) == Vrab01) Input.MAIN_7 = Vrab02;} else {Input.MAIN_7 = 0ui8;}
   if(Ikey02.D8){if((++Input.MAIN_8) == Vrab01) Input.MAIN_8 = Vrab02;} else {Input.MAIN_8 = 0ui8;}
   if(Ikey02.D9){if((++Input.MAIN_9) == Vrab01) Input.MAIN_9 = Vrab02;} else {Input.MAIN_9 = 0ui8;}
   if(Ikey02.A){if((++Input.MAIN_A) == Vrab01) Input.MAIN_A = Vrab02;} else {Input.MAIN_A = 0ui8;}
   if(Ikey02.B){if((++Input.MAIN_B) == Vrab01) Input.MAIN_B = Vrab02;} else {Input.MAIN_B = 0ui8;}
   if(Ikey02.C){if((++Input.MAIN_C) == Vrab01) Input.MAIN_C = Vrab02;} else {Input.MAIN_C = 0ui8;}
   if(Ikey02.D){if((++Input.MAIN_D) == Vrab01) Input.MAIN_D = Vrab02;} else {Input.MAIN_D = 0ui8;}
   if(Ikey02.E){if((++Input.MAIN_E) == Vrab01) Input.MAIN_E = Vrab02;} else {Input.MAIN_E = 0ui8;}
   if(Ikey02.F){if((++Input.MAIN_F) == Vrab01) Input.MAIN_F = Vrab02;} else {Input.MAIN_F = 0ui8;}
   if(Ikey02.G){if((++Input.MAIN_G) == Vrab01) Input.MAIN_G = Vrab02;} else {Input.MAIN_G = 0ui8;}
   if(Ikey02.H){if((++Input.MAIN_H) == Vrab01) Input.MAIN_H = Vrab02;} else {Input.MAIN_H = 0ui8;}
   if(Ikey02.I){if((++Input.MAIN_I) == Vrab01) Input.MAIN_I = Vrab02;} else {Input.MAIN_I = 0ui8;}
   if(Ikey02.J){if((++Input.MAIN_J) == Vrab01) Input.MAIN_J = Vrab02;} else {Input.MAIN_J = 0ui8;}
   if(Ikey02.K){if((++Input.MAIN_K) == Vrab01) Input.MAIN_K = Vrab02;} else {Input.MAIN_K = 0ui8;}
   if(Ikey02.L){if((++Input.MAIN_L) == Vrab01) Input.MAIN_L = Vrab02;} else {Input.MAIN_L = 0ui8;}
   if(Ikey02.M){if((++Input.MAIN_M) == Vrab01) Input.MAIN_M = Vrab02;} else {Input.MAIN_M = 0ui8;}
   if(Ikey02.N){if((++Input.MAIN_N) == Vrab01) Input.MAIN_N = Vrab02;} else {Input.MAIN_N = 0ui8;}
   if(Ikey02.O){if((++Input.MAIN_O) == Vrab01) Input.MAIN_O = Vrab02;} else {Input.MAIN_O = 0ui8;}
   if(Ikey02.P){if((++Input.MAIN_P) == Vrab01) Input.MAIN_P = Vrab02;} else {Input.MAIN_P = 0ui8;}
   if(Ikey02.Q){if((++Input.MAIN_Q) == Vrab01) Input.MAIN_Q = Vrab02;} else {Input.MAIN_Q = 0ui8;}
   if(Ikey02.R){if((++Input.MAIN_R) == Vrab01) Input.MAIN_R = Vrab02;} else {Input.MAIN_R = 0ui8;}
   if(Ikey02.S){if((++Input.MAIN_S) == Vrab01) Input.MAIN_S = Vrab02;} else {Input.MAIN_S = 0ui8;}
   if(Ikey02.T){if((++Input.MAIN_T) == Vrab01) Input.MAIN_T = Vrab02;} else {Input.MAIN_T = 0ui8;}
   if(Ikey02.U){if((++Input.MAIN_U) == Vrab01) Input.MAIN_U = Vrab02;} else {Input.MAIN_U = 0ui8;}
   if(Ikey02.V){if((++Input.MAIN_V) == Vrab01) Input.MAIN_V = Vrab02;} else {Input.MAIN_V = 0ui8;}
   if(Ikey02.W){if((++Input.MAIN_W) == Vrab01) Input.MAIN_W = Vrab02;} else {Input.MAIN_W = 0ui8;}
   if(Ikey02.X){if((++Input.MAIN_X) == Vrab01) Input.MAIN_X = Vrab02;} else {Input.MAIN_X = 0ui8;}
   if(Ikey02.Y){if((++Input.MAIN_Y) == Vrab01) Input.MAIN_Y = Vrab02;} else {Input.MAIN_Y = 0ui8;}
   if(Ikey02.Z){if((++Input.MAIN_Z) == Vrab01) Input.MAIN_Z = Vrab02;} else {Input.MAIN_Z = 0ui8;}
   if(Ikey02.OemTilde)        {if((++Input.MAIN_TILDE) == Vrab01) Input.MAIN_TILDE = Vrab02;} else {Input.MAIN_TILDE = 0ui8;}
   if(Ikey02.OemMinus)        {if((++Input.MAIN_MINUS) == Vrab01) Input.MAIN_MINUS = Vrab02;} else {Input.MAIN_MINUS = 0ui8;}
   if(Ikey02.OemPlus)         {if((++Input.MAIN_PLUS) == Vrab01) Input.MAIN_PLUS = Vrab02;} else {Input.MAIN_PLUS = 0ui8;}
   if(Ikey02.OemOpenBrackets) {if((++Input.MAIN_OPENBRACKED) == Vrab01) Input.MAIN_OPENBRACKED = Vrab02;} else {Input.MAIN_OPENBRACKED = 0ui8;}
   if(Ikey02.OemCloseBrackets){if((++Input.MAIN_CLOSEBRACKED) == Vrab01) Input.MAIN_CLOSEBRACKED = Vrab02;} else {Input.MAIN_CLOSEBRACKED = 0ui8;}
   if(Ikey02.OemPipe)         {if((++Input.MAIN_PIPE) == Vrab01) Input.MAIN_PIPE = Vrab02;} else {Input.MAIN_PIPE = 0ui8;}
   if(Ikey02.OemSemicolon)    {if((++Input.MAIN_SEMICOLON) == Vrab01) Input.MAIN_SEMICOLON = Vrab02;} else {Input.MAIN_SEMICOLON = 0ui8;}
   if(Ikey02.OemQuotes)       {if((++Input.MAIN_QUOTES) == Vrab01) Input.MAIN_QUOTES = Vrab02;} else {Input.MAIN_QUOTES = 0ui8;}
   if(Ikey02.OemQuestion)     {if((++Input.MAIN_QUESTION) == Vrab01) Input.MAIN_QUESTION = Vrab02;} else {Input.MAIN_QUESTION = 0ui8;}
   if(Ikey02.OemPeriod)       {if((++Input.MAIN_PERIOD) == Vrab01) Input.MAIN_PERIOD = Vrab02;} else {Input.MAIN_PERIOD = 0ui8;}
   if(Ikey02.OemComma)        {if((++Input.MAIN_COMMA) == Vrab01) Input.MAIN_COMMA = Vrab02;} else {Input.MAIN_COMMA = 0ui8;}
   if(Ikey02.Space)           {if((++Input.MAIN_SPACE) == Vrab01) Input.MAIN_SPACE = Vrab02;} else {Input.MAIN_SPACE = 0ui8;}
   if(Ikey02.Escape){if((++Input.CONS_ESC) == Vrab01) Input.CONS_ESC = Vrab02;} else {Input.CONS_ESC = 0ui8;}
   if(Ikey02.F1)    {if((++Input.CONS_F1) == Vrab01) Input.CONS_F1 = Vrab02;} else {Input.CONS_F1 = 0ui8;}
   if(Ikey02.F2)    {if((++Input.CONS_F2) == Vrab01) Input.CONS_F2 = Vrab02;} else {Input.CONS_F2 = 0ui8;}
   if(Ikey02.F3)    {if((++Input.CONS_F3) == Vrab01) Input.CONS_F3 = Vrab02;} else {Input.CONS_F3 = 0ui8;}
   if(Ikey02.F4)    {if((++Input.CONS_F4) == Vrab01) Input.CONS_F4 = Vrab02;} else {Input.CONS_F4 = 0ui8;}
   if(Ikey02.F5)    {if((++Input.CONS_F5) == Vrab01) Input.CONS_F5 = Vrab02;} else {Input.CONS_F5 = 0ui8;}
   if(Ikey02.F6)    {if((++Input.CONS_F6) == Vrab01) Input.CONS_F6 = Vrab02;} else {Input.CONS_F6 = 0ui8;}
   if(Ikey02.F7)    {if((++Input.CONS_F7) == Vrab01) Input.CONS_F7 = Vrab02;} else {Input.CONS_F7 = 0ui8;}
   if(Ikey02.F8)    {if((++Input.CONS_F8) == Vrab01) Input.CONS_F8 = Vrab02;} else {Input.CONS_F8 = 0ui8;}
   if(Ikey02.F9)    {if((++Input.CONS_F9) == Vrab01) Input.CONS_F9 = Vrab02;} else {Input.CONS_F9 = 0ui8;}
   if(Ikey02.F10)   {if((++Input.CONS_F10) == Vrab01) Input.CONS_F10 = Vrab02;} else {Input.CONS_F10 = 0ui8;}
   if(Ikey02.F11)   {if((++Input.CONS_F11) == Vrab01) Input.CONS_F11 = Vrab02;} else {Input.CONS_F11 = 0ui8;}
   if(Ikey02.F12)   {if((++Input.CONS_F12) == Vrab01) Input.CONS_F12 = Vrab02;} else {Input.CONS_F12 = 0ui8;}
   if(Ikey02.PrintScreen) {if((++Input.CONS_PRTSC) == Vrab01) Input.CONS_PRTSC = Vrab02;} else {Input.CONS_PRTSC = 0ui8;}
   if(Ikey02.Delete)      {if((++Input.CONS_DELETE) == Vrab01) Input.CONS_DELETE = Vrab02;} else {Input.CONS_DELETE = 0ui8;}
   if(Ikey02.Back)        {if((++Input.CONS_BACK) == Vrab01) Input.CONS_BACK = Vrab02;} else {Input.CONS_BACK = 0ui8;}
   if(Ikey02.Tab)         {if((++Input.CONS_TAB) == Vrab01) Input.CONS_TAB = Vrab02;} else {Input.CONS_TAB = 0ui8;}
   if(Ikey02.CapsLock)    {if((++Input.CONS_CAPS) == Vrab01) Input.CONS_CAPS = Vrab02;} else {Input.CONS_CAPS = 0ui8;}
   if(Ikey02.Enter)       {if((++Input.CONS_ENTER) == Vrab01) Input.CONS_ENTER = Vrab02;} else {Input.CONS_ENTER = 0ui8;}
   if(Ikey02.LeftShift)   {if((++Input.CONS_LSHIFT) == Vrab01) Input.CONS_LSHIFT = Vrab02;} else {Input.CONS_LSHIFT = 0ui8;}
   if(Ikey02.RightShift)  {if((++Input.CONS_RSHIFT) == Vrab01) Input.CONS_RSHIFT = Vrab02;} else {Input.CONS_RSHIFT = 0ui8;}
   if(Ikey02.LeftAlt)     {if((++Input.CONS_LALT) == Vrab01) Input.CONS_LALT = Vrab02;} else {Input.CONS_LALT = 0ui8;}
   if(Ikey02.RightAlt)    {if((++Input.CONS_RALT) == Vrab01) Input.CONS_RALT = Vrab02;} else {Input.CONS_RALT = 0ui8;}
   if(Ikey02.LeftControl) {if((++Input.CONS_LCTRL) == Vrab01) Input.CONS_LCTRL = Vrab02;} else {Input.CONS_LCTRL = 0ui8;}
   if(Ikey02.RightControl){if((++Input.CONS_RCTRL) == Vrab01) Input.CONS_RCTRL = Vrab02;} else {Input.CONS_RCTRL = 0ui8;}
   if(Ikey02.Up)   {if((++Input.CONS_UP) == Vrab01) Input.CONS_UP = Vrab02;} else {Input.CONS_UP = 0ui8;}
   if(Ikey02.Left) {if((++Input.CONS_LEFT) == Vrab01) Input.CONS_LEFT = Vrab02;} else {Input.CONS_LEFT = 0ui8;}
   if(Ikey02.Down) {if((++Input.CONS_DOWN) == Vrab01) Input.CONS_DOWN = Vrab02;} else {Input.CONS_DOWN = 0ui8;}
   if(Ikey02.Right){if((++Input.CONS_RIGHT) == Vrab01) Input.CONS_RIGHT = Vrab02;} else {Input.CONS_RIGHT = 0ui8;}
   if(Ikey02.NumPad0){if((++Input.NUMS_0) == Vrab01) Input.NUMS_0 = Vrab02;} else {Input.NUMS_0 = 0ui8;}
   if(Ikey02.NumPad1){if((++Input.NUMS_1) == Vrab01) Input.NUMS_1 = Vrab02;} else {Input.NUMS_1 = 0ui8;}
   if(Ikey02.NumPad2){if((++Input.NUMS_2) == Vrab01) Input.NUMS_2 = Vrab02;} else {Input.NUMS_2 = 0ui8;}
   if(Ikey02.NumPad3){if((++Input.NUMS_3) == Vrab01) Input.NUMS_3 = Vrab02;} else {Input.NUMS_3 = 0ui8;}
   if(Ikey02.NumPad4){if((++Input.NUMS_4) == Vrab01) Input.NUMS_4 = Vrab02;} else {Input.NUMS_4 = 0ui8;}
   if(Ikey02.NumPad5){if((++Input.NUMS_5) == Vrab01) Input.NUMS_5 = Vrab02;} else {Input.NUMS_5 = 0ui8;}
   if(Ikey02.NumPad6){if((++Input.NUMS_6) == Vrab01) Input.NUMS_6 = Vrab02;} else {Input.NUMS_6 = 0ui8;}
   if(Ikey02.NumPad7){if((++Input.NUMS_7) == Vrab01) Input.NUMS_7 = Vrab02;} else {Input.NUMS_7 = 0ui8;}
   if(Ikey02.NumPad8){if((++Input.NUMS_8) == Vrab01) Input.NUMS_8 = Vrab02;} else {Input.NUMS_8 = 0ui8;}
   if(Ikey02.NumPad9){if((++Input.NUMS_9) == Vrab01) Input.NUMS_9 = Vrab02;} else {Input.NUMS_9 = 0ui8;}
   if(Ikey02.LeftWindows || Ikey02.RightWindows){if((++Input.CONS_WINDOWS) == Vrab01) Input.CONS_WINDOWS = Vrab02;} else {Input.CONS_WINDOWS = 0ui8;}
   
   Input.RESH_CAPS = (GetKeyState(VK_CAPITAL) & 0x0001);

   auto Imou02 = Imou01->GetState();
   Input.MOUS_X = L_Rounding(rxint64(Imou02.x) / Varb0010) - Varb0008;
   Input.MOUS_Y = L_Rounding(rxint64(Imou02.y) / Varb0011) - Varb0009;
   if(Imou02.leftButton)    {if((++Input.MOUS_Left) == Vrab01) Input.MOUS_Left = Vrab02; Input.MOUS_Left_Release = 0ui8;} else {Input.MOUS_Left = 0ui8;     if((++Input.MOUS_Left_Release) == Vrab01) Input.MOUS_Left_Release = Vrab02;}
   if(Imou02.middleButton)  {if((++Input.MOUS_Mid) == Vrab01) Input.MOUS_Mid = Vrab02; Input.MOUS_Mid_Release = 0ui8;} else {Input.MOUS_Mid = 0ui8;         if((++Input.MOUS_Mid_Release) == Vrab01) Input.MOUS_Mid_Release = Vrab02;}
   if(Imou02.rightButton)   {if((++Input.MOUS_Right) == Vrab01) Input.MOUS_Right = Vrab02; Input.MOUS_Right_Release = 0ui8;} else {Input.MOUS_Right = 0ui8; if((++Input.MOUS_Right_Release) == Vrab01) Input.MOUS_Right_Release = Vrab02;}
   if(Input.MOUS_Left == 1 || Input.MOUS_Left_Release > 1) {Input.MOUS_X_Left = Input.MOUS_X; Input.MOUS_Y_Left = Input.MOUS_Y;}
   if(Input.MOUS_Mid == 1 || Input.MOUS_Mid_Release > 1)  {Input.MOUS_X_Mid = Input.MOUS_X; Input.MOUS_Y_Mid = Input.MOUS_Y;}
   if(Input.MOUS_Right == 1 || Input.MOUS_Right_Release > 1){Input.MOUS_X_Right = Input.MOUS_X; Input.MOUS_Y_Right = Input.MOUS_Y;}
   Input.MOUS_SCROLL = Input.MOUS_SCROLL2 - Imou02.scrollWheelValue;
   Input.MOUS_SCROLL2 = Imou02.scrollWheelValue;

   auto Ipad02 = Ipad01->GetState(0);
  }
  int0 P_EngineFrame(xint64 Vrab01, xint64 Vrab02, uint32 Vrab03, uint32 Vrab04, DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01)
  {
   UNREFERENCED_PARAMETER(Vrab02); UNREFERENCED_PARAMETER(Vrab03); UNREFERENCED_PARAMETER(Vrab04); if(Varb0001 == 0){Varb0015 = std::chrono::steady_clock::now().time_since_epoch().count(); Varb0025 = L_Exist("Database\\Game\\Enchanted");} Varb0001 += 1; if(Varb0001 == 0xFFFFFFFFFFFFFFFF) Varb0001 = 0xFFFFFFFFFFFEBF; remains xint64 Varb01; Varb01 += Vrab01; if(Varb0001 % ruint64(Varb0004) != 0) return; P_EngineInput(Ikey01, Ipad01, Imou01); Disp0001.clear(); remains uint64 Varb02; Varb02 += 1; remains uint64 Varb03; if(Varb01 > 1.0){while(Varb01 > 1.0) Varb01 -= 1.0; Varb03 = Varb02; Varb02 = 0;}
   
   if(!Varb0026 && Varb0025) // Go to "LF2 : Enchanted 4th"
   {
    Enchanted = std::make_unique < HEPTA_LF2_ENCHANTED > (); Varb0026 = true;
   } if(Varb0026) LF2_Enchanted(Vrab04, Varb03);

   
   // Purging Offside Images.
   G_Set_Display(0, 0x0, -rint64(Varb0008), -rint64(Varb0009), 0ui8, 255ui8, Varb0008, rint64(Varb0009) + rint64(Varb0003)); G_Set_Display(0, 0x0, -rint64(Varb0008), rint64(Varb0003), 0ui8, 255ui8, rint64(Varb0008) + rint64(Varb0002), Varb0009); G_Set_Display(0, 0x0, rint64(Varb0002), 0, 0ui8, 255ui8, Varb0008, rint64(Varb0009) + rint64(Varb0003)); G_Set_Display(0, 0x0, 0, -rint64(Varb0009), 0ui8, 255ui8, rint64(Varb0008) + rint64(Varb0002), Varb0009);
  }
 //-//











 // External-Included Dependency Program(s)
  int0 LF2_Enchanted(uint32 Vrab01, uint64 Vrab02) fastened
  {
   string Temp69; // debug

   if(Enchanted->Initialization)
   {
    Varb0004 = 4;
    Enchanted->Initialization = false;
    Enchanted->Pic_Index_Interface.clear(); Enchanted->Sound_Index_Interface.clear(); Enchanted->Back_Index_Interface.clear(); statics string Temp01 = Enchanted->Memory[0].Address;
    Enchanted->Memory[0].P_Input[3][0] = 22; Enchanted->Memory[0].P_Input[0][0] = 15;
    Enchanted->Memory[0].P_Input[3][1] = 46; Enchanted->Memory[0].P_Input[0][1] = 14;
    Enchanted->Memory[0].P_Input[3][2] = 47; Enchanted->Memory[0].P_Input[0][2] = 29;
    Enchanted->Memory[0].P_Input[3][3] = 45; Enchanted->Memory[0].P_Input[0][3] = 16;
    Enchanted->Memory[0].P_Input[3][4] = 23; Enchanted->Memory[0].P_Input[0][4] = 11;
    Enchanted->Memory[0].P_Input[3][5] = 44; Enchanted->Memory[0].P_Input[0][5] = 30;
    Enchanted->Memory[0].P_Input[3][6] = 43; Enchanted->Memory[0].P_Input[0][6] = 28;
    Enchanted->Memory[0].P_Input[3][7] = 21; Enchanted->Memory[0].P_Input[0][7] = 33;
    Enchanted->Memory[0].P_Name[3] = "Mesujin"; Enchanted->Memory[0].P_Name[0] = "Kitty";
    Enchanted->Load_Memory(); Enchanted->Save_Memory(); Varb0012 = rxint32((rxint64(Enchanted->Memory[0].Volume) / 100) * 0.1); if(Enchanted->Memory[0].Pan > 0){Varb0013 = rxint32(Enchanted->Memory[0].Pan) / 100;} else {Varb0013 = -(rxint32(-Enchanted->Memory[0].Pan) / 100);}
    Enchanted->Update_Window(Enchanted->Memory[0].Screen_W, Enchanted->Memory[0].Screen_H, Enchanted->Memory[0].Fullscreen);
    
    // Interface's background load.
    {
     statics string Temp02 = "Database\\Interface\\Enchanted\\", Temp03 = ".bmp", Temp04 = ".jpg";
     int1 Vrab03 = true; insize Vrab04 = 0;
     while(Vrab03)
     {
      Vrab04 += 1;
      Enchanted->Back_Index_Interface.push_back(G_Load_Pic(Temp02 + "BACK" + std::to_string(Vrab04) + Temp03, 0ui32, 0ui32, ruint32(-1), 550));
      Enchanted->Back_Index_Interface_Type.push_back(false); Vrab03 = Enchanted->Back_Index_Interface[Vrab04 - 1] != rinsize(-1);
      if(!Vrab03)
      {
       Enchanted->Back_Index_Interface[Vrab04 - 1] = G_Load_Pic(Temp02 + "BACK" + std::to_string(Vrab04) + Temp04, 0ui32, 0ui32, ruint32(-1), 550);
       Enchanted->Back_Index_Interface_Type[Vrab04 - 1] = true; Vrab03 = Enchanted->Back_Index_Interface[Vrab04 - 1] != rinsize(-1);
      }
     }
     Enchanted->Back_Index_Interface.pop_back(); Enchanted->Back_Index_Interface_Type.pop_back();
  
     // First randomized background.
     if(Enchanted->Back_Index_Interface.size() > 0)
     {
      statics insize Vrab05 = rinsize(L_Random(Enchanted->Back_Index_Interface.size() - 1));
      Enchanted->Background1 = Enchanted->Back_Index_Interface[Vrab05];
      Enchanted->Background2 = Enchanted->Back_Index_Interface_Type[Vrab05];
     }
    }

    // Interface's pic load.
    {
     statics string Temp02 = "Database\\Interface\\Enchanted\\", Temp03 = ".bmp";
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "WORDS1" + Temp03, 0, 0, 255, 255));         // Index : 0
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "WORDS2" + Temp03, 0, 0, 255, 255));         // Index : 1
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "WORDS3" + Temp03, 0, 0, 255, 255));         // Index : 2
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "WORDS4" + Temp03, 0, 0, 255, 255));         // Index : 3
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "WORDS5" + Temp03, 0, 0, 255, 255));         // Index : 4
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "WORDS6" + Temp03, 0, 0, 255, 255));         // Index : 5
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 278, 260, 12, 12));        // Index : 6 (Info Bar Top-Left Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 291, 260, 12, 12));        // Index : 7 (Info Bar Top-Right Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 278, 273, 12, 12));        // Index : 8 (Info Bar Bottom-Left Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 291, 273, 12, 12));        // Index : 9 (Info Bar Bottom-Right Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 290, 260, 1, 3));          // Index : 10 (Info Bar Horizontal Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 278, 272, 3, 1));          // Index : 11 (Info Bar Vertical Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 801, 382, 200, 200));      // Index : 12 (Info Bar Area)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "CURSOR1" + Temp03));                        // Index : 13
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "CURSOR2" + Temp03));                        // Index : 14
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 0, 0, 800, 37));           // Index : 15 (Copyright)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 0, 38, 490, 79));          // Index : 16 (Title)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 38, 154, 169));       // Index : 17 (Main Buttons)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 646, 38, 154, 18));        // Index : 18 (Main Buttons - Game Start)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 646, 67, 154, 20));        // Index : 19 (Main Buttons - Network Game)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 646, 98, 154, 20));        // Index : 20 (Main Buttons - General Settings)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 646, 129, 154, 20));       // Index : 21 (Main Buttons - Control Settings)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 646, 161, 154, 19));       // Index : 22 (Main Buttons - Recording Info)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 646, 191, 154, 16));       // Index : 23 (Main Buttons - Official Fansite)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 0, 118, 151, 26));         // Index : 24 (Ok Button)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 0, 145, 151, 26));         // Index : 25 (Ok Button)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 152, 118, 151, 26));       // Index : 26 (Cancel Button)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 152, 145, 151, 26));       // Index : 27 (Cancel Button)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 801, 0, 704, 381));        // Index : 28 (Control Setting Menu)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 587, 300, 106, 91));       // Index : 29 (Input - Keyboard)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 694, 208, 106, 91));       // Index : 30 (Input - Joy1)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 587, 208, 106, 91));       // Index : 31 (Input - Joy2)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 694, 392, 106, 91));       // Index : 32 (Input - Joy3)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 694, 300, 106, 91));       // Index : 33 (Input - Joy4)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 304, 118, 186, 169));      // Index : 34 (Game Buttons)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 304, 288, 186, 14));       // Index : 35 (Game Buttons - Versus)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 304, 319, 186, 18));       // Index : 36 (Game Buttons - Stage)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 304, 349, 186, 19));       // Index : 37 (Game Buttons - Championship)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 304, 380, 186, 15));       // Index : 38 (Game Buttons - Battle)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 304, 411, 186, 19));       // Index : 39 (Game Buttons - Recording Playback)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 304, 443, 186, 14));       // Index : 40 (Game Buttons - Return)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1506, 0, 744, 437));       // Index : 41 (Character Selection)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1264, 382, 120, 66));      // Index : 42 (Character Selection - Press Attack to Join)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1385, 382, 120, 66));      // Index : 43 (Character Selection - Press Attack to Join2)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1001, 382, 120, 120));     // Index : 44 (Character Selection - Random)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 535, 208, 51, 58));        // Index : 45 (Character Selection - Counter - 5)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 535, 267, 51, 58));        // Index : 46 (Character Selection - Counter - 4)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 535, 326, 51, 58));        // Index : 47 (Character Selection - Counter - 3)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 590, 392, 51, 58));        // Index : 48 (Character Selection - Counter - 2)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 642, 392, 51, 58));        // Index : 49 (Character Selection - Counter - 1)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 0, 172, 303, 87));         // Index : 50 (Character Selection - Computer Player)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 208, 6, 10));         // Index : 51 (Character Selection - Computer Player - 0)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 498, 208, 6, 10));         // Index : 52 (Character Selection - Computer Player - 1)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 505, 208, 6, 10));         // Index : 53 (Character Selection - Computer Player - 2)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 512, 208, 6, 10));         // Index : 54 (Character Selection - Computer Player - 3)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 519, 208, 6, 10));         // Index : 55 (Character Selection - Computer Player - 4)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 526, 208, 6, 10));         // Index : 56 (Character Selection - Computer Player - 5)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 219, 6, 10));         // Index : 57 (Character Selection - Computer Player - 6)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 498, 219, 6, 10));         // Index : 58 (Character Selection - Computer Player - 7)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 505, 219, 6, 10));         // Index : 59 (Character Selection - Computer Player - 0 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 512, 219, 6, 10));         // Index : 60 (Character Selection - Computer Player - 1 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 519, 219, 6, 10));         // Index : 61 (Character Selection - Computer Player - 2 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 526, 219, 6, 10));         // Index : 62 (Character Selection - Computer Player - 3 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 230, 6, 10));         // Index : 63 (Character Selection - Computer Player - 4 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 498, 230, 6, 10));         // Index : 64 (Character Selection - Computer Player - 5 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 505, 230, 6, 10));         // Index : 65 (Character Selection - Computer Player - 6 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 512, 230, 6, 10));         // Index : 66 (Character Selection - Computer Player - 7 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 0, 260, 264, 168));        // Index : 67 (Character Selection - Menu)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 208, 1, 1));          // Index : 68 (Color - 1) (#10206C)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 210, 1, 1));          // Index : 69 (Color - 2)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 212, 1, 1));          // Index : 70 (Color - 3)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 214, 1, 1));          // Index : 71 (Color - 4)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 216, 1, 1));          // Index : 72 (Color - 5)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 218, 1, 1));          // Index : 73 (Color - 6)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 220, 1, 1));          // Index : 74 (Color - 7)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 222, 1, 1));          // Index : 75 (Color - 8)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 224, 1, 1));          // Index : 76 (Color - 9)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 226, 1, 1));          // Index : 77 (Color - 10)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 228, 1, 1));          // Index : 78 (Color - 11)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 230, 1, 1));          // Index : 79 (Color - 12)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 232, 1, 1));          // Index : 80 (Color - 13)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 234, 1, 1));          // Index : 81 (Color - 14)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 236, 1, 1));          // Index : 82 (Color - 15)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 533, 238, 1, 1));          // Index : 83 (Color - 16)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 307, 21, 21));        // Index : 84 (Input - Attack)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 307, 21, 21));        // Index : 85 (Input - Attack Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 285, 21, 21));        // Index : 86 (Input - Defend)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 329, 21, 21));        // Index : 87 (Input - Defend Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 285, 21, 21));        // Index : 88 (Input - Jump)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 329, 21, 21));        // Index : 89 (Input - Jump Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 241, 21, 21));        // Index : 90 (Input - Up)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 351, 21, 21));        // Index : 91 (Input - Up Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 241, 21, 21));        // Index : 92 (Input - Left)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 351, 21, 21));        // Index : 93 (Input - Left Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 263, 21, 21));        // Index : 94 (Input - Down)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 373, 21, 21));        // Index : 95 (Input - Down Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 263, 21, 21));        // Index : 96 (Input - Right)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 513, 373, 21, 21));        // Index : 97 (Input - Right Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 395, 66, 17));        // Index : 98 (Setting - Graphic)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 413, 66, 17));        // Index : 99 (Setting - Audio)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 491, 431, 66, 17));        // Index : 100 (Setting - Platform)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 2251, 0, 704, 338));       // Index : 101 (Recording Info)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 456, 484, 344, 23));       // Index : 102 (Recording Info - Button)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 284, 286, 19, 19));        // Index : 103 (Check)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 284, 306, 19, 19));        // Index : 104 (Check - Off)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 265, 286, 18, 18));        // Index : 105 (Info - Question)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 265, 305, 18, 18));        // Index : 106 (Info - Important)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 519, 230, 6, 10));         // Index : 107 (Character Selection - Computer Player - 8 Active)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 286, 326, 8, 8));          // Index : 108 (Menu Bar Top-Left Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 295, 326, 8, 8));          // Index : 109 (Menu Bar Top-Right Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 286, 335, 8, 8));          // Index : 110 (Menu Bar Bottom-Left Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 295, 335, 8, 8));          // Index : 111 (Menu Bar Bottom-Right Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 294, 326, 1, 8));          // Index : 112 (Menu Bar Horizontal-Top Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 286, 334, 8, 1));          // Index : 113 (Menu Bar Vertical-Left Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 294, 335, 1, 8));          // Index : 114 (Menu Bar Horizontal-Bottom Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 295, 334, 8, 1));          // Index : 115 (Menu Bar Vertical-Right Corner)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 294, 334, 1, 1));          // Index : 116 (Menu Bar Area)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 2956, 0, 169, 324));       // Index : 117 (Meta Character Selection - Char View)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 284, 326, 1, 1));          // Index : 118 (Menu Bar Color - 1)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 284, 328, 1, 1));          // Index : 119 (Menu Bar Color - 2)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 284, 330, 1, 1));          // Index : 120 (Menu Bar Color - 3)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 284, 332, 1, 1));          // Index : 121 (Menu Bar Color - 4)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 284, 334, 1, 1));          // Index : 122 (Menu Bar Color - 5)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU2" + Temp03, 0, 0, 665, 900));          // Index : 123 (General Setting - Scrolling Display)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1506, 438, 200, 50));      // Index : 124 (Player Info - 1)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1707, 438, 200, 50));      // Index : 125 (Player Info - 2)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1908, 438, 200, 50));      // Index : 126 (Player Info - 3)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 2109, 438, 200, 50));      // Index : 127 (Player Info - 4)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1506, 489, 200, 50));      // Index : 128 (Player Info - 5)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1707, 489, 200, 50));      // Index : 129 (Player Info - 6)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1908, 489, 200, 50));      // Index : 130 (Player Info - 7)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 2109, 489, 200, 50));      // Index : 131 (Player Info - 8)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1506, 540, 200, 50));      // Index : 132 (Player Info - 9)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1707, 540, 200, 50));      // Index : 133 (Player Info - 10)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 1908, 540, 200, 50));      // Index : 134 (Player Info - 11)
     Enchanted->Pic_Index_Interface.push_back(G_Load_Pic(Temp02 + "MENU1" + Temp03, 2109, 540, 200, 50));      // Index : 135 (Player Info - 12)
    }

    // Interface's sound load.
    {
     statics string Temp02 = "Database\\Audio\\Enchanted\\", Temp03 = ".wav";
     Enchanted->Sound_Index_Interface.push_back(G_Load_Sound(Temp02 + "OK" + Temp03));       // Index : 0
     Enchanted->Sound_Index_Interface.push_back(G_Load_Sound(Temp02 + "CANCEL" + Temp03));   // Index : 1
      
     int1 Vrab03 = true; insize Vrab04 = 0;
     while(Vrab03){Vrab04 += 1; Enchanted->Sound_Index_Interface.push_back(G_Load_Sound(Temp02 + "MUSIC" + std::to_string(Vrab04) + Temp03)); Vrab03 = Enchanted->Sound_Index_Interface[Vrab04 + 1] != rinsize(-1);}
     Enchanted->Sound_Index_Interface.pop_back();
    }

    Enchanted->Post_Info("Platform Version : " + Enchanted->Version() + " (Beta).");
    Enchanted->Angel = std::make_unique < HEPTA_LF2_ENCHANTED_ANGELSCRIPT > ();
   } else {Varb0005 = Enchanted->Memory[0].Aspect_Ratio; if(L_Input(Enchanted->Memory[0].F12) == 1 && (Input.CONS_LALT >= 1 || Input.CONS_RALT >= 1)) Enchanted->Angel->Switch(); if(Enchanted->Memory[0].Fullscreen != Varb0014){Enchanted->Memory[0].Fullscreen = Varb0014; Enchanted->Save_Memory();} if(Enchanted->Menu != 10) L_Random(0); Enchanted->Tick += 1; if(Enchanted->Tick == 0xFFFFFFFFFFFFFFFF) Enchanted->Tick = 0xFFFFFFFFFFFEBF; Enchanted->Draw = true; Enchanted->Number_Of_Sound = 0; Varb0012 = rxint32((rxint64(Enchanted->Memory[0].Volume) / 30) * 0.1); if(Enchanted->Memory[0].Pan > 0){Varb0013 = rxint32(Enchanted->Memory[0].Pan) / 100;} else {Varb0013 = -(rxint32(-Enchanted->Memory[0].Pan) / 100);}}

   {
    statics int64 &Vrab03 = Enchanted->Display_CenX, &Vrab04 = Enchanted->Display_CenY, &Vrab05 = Enchanted->Display_W, &Vrab06 = Enchanted->Display_H;
    switch(Enchanted->Menu)
    {
     case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 250: case 251: case 252: case 253: case 254: case 255: // Main Menu
      {
       if(Enchanted->Sound_Index_Interface.size() > 2) Enchanted->Play_Music(Enchanted->Sound_Index_Interface[2]);
       G_Set_Display(6, Enchanted->Pic_Index_Interface[68], 0, 0, 0, 255ui8, Vrab05, Vrab06);
       if(Enchanted->Background2){G_Set_Display(0, 0x0, 0, 0, 0ui8, 255ui8, Varb0002, Varb0003); G_Set_Display(2, Enchanted->Background1, 0, Vrab04 - 275ll); G_Set_Display(0, 0x0, 0, 0, 0ui8, 50ui8, Varb0002, Varb0003); G_Set_Display(0, 0x0, Vrab03 - 99, Vrab04 - 95, 0ui8, 140ui8, 199, 189); G_Set_Display(0, 0x0, Vrab03 - 102, Vrab04 - 91, 0ui8, 140ui8, 3, 181); G_Set_Display(0, 0x0, Vrab03 + 100, Vrab04 - 91, 0ui8, 140ui8, 3, 181); Enchanted->Print_Bar(Vrab03 - 93, Vrab04 - 86, 186, 169);} else
       {G_Set_Display(2, Enchanted->Background1, 0, Vrab04 - 275ll);}
       G_Set_Display(2, Enchanted->Pic_Index_Interface[15], Vrab03 - 400, Vrab06 - 43);
       G_Set_Display(2, Enchanted->Pic_Index_Interface[16], Vrab03 - 245, L_Rounding64(rxint64(Vrab04) / 2) - 79);
       if(Enchanted->Menu < 7 || Enchanted->Menu > 8) G_Set_Display(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85);

       switch(Enchanted->Menu)
       {
        case 0: // Base
         {
          uint8 Vrab07 = 0;
          if(L_In(Vrab03 - 80, Vrab04 - 86, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[18], Vrab03 - 77, Vrab04 - 85); if(L_On(Vrab03 - 80, Vrab04 - 86, 160, 20)) Vrab07 = 1;}
          if(L_In(Vrab03 - 80, Vrab04 - 55, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[19], Vrab03 - 77, Vrab04 - 56); if(L_On(Vrab03 - 80, Vrab04 - 55, 160, 20)) Vrab07 = 2;}
          if(L_In(Vrab03 - 80, Vrab04 - 24, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[20], Vrab03 - 77, Vrab04 - 25); if(L_On(Vrab03 - 80, Vrab04 - 24, 160, 20)) Vrab07 = 3;}
          if(L_In(Vrab03 - 80, Vrab04 + 7, 160, 20)) {Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[21], Vrab03 - 77, Vrab04 + 6);  if(L_On(Vrab03 - 80, Vrab04 + 7, 160, 20))  Vrab07 = 4;}
          if(L_In(Vrab03 - 80, Vrab04 + 38, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[22], Vrab03 - 77, Vrab04 + 38); if(L_On(Vrab03 - 80, Vrab04 + 38, 160, 20)) Vrab07 = 5;}
          if(L_In(Vrab03 - 80, Vrab04 + 69, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[23], Vrab03 - 77, Vrab04 + 68); if(L_On(Vrab03 - 80, Vrab04 + 69, 160, 20)) Vrab07 = 6;}
          if(Enchanted->Runtime3 > 2) if(Enchanted->Memory[0].Skip_Animation){Enchanted->Runtime3 = 0;} else {Enchanted->Runtime3 -= 3; G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);}

          int1 Vrab08 = L_Input(Varb0021) == 1, Vrab09 = L_Input(Varb0023) == 1, Vrab10 = L_Input(Varb0020) == 1; statics int1 Vrab11 = ((Enchanted->Tick % 20) / 10) == 0;
          if(!Vrab08){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab08 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][0]) == 1); if(Vrab08) break;}}
          if(!Vrab09){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab09 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][1]) == 1); if(Vrab09) break;}}
          if(!Vrab10){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab10 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][4]) == 1); if(Vrab10) break;}}
          if(Vrab08 == Vrab09){Vrab08 = Vrab09 = false;} if(Enchanted->Runtime1 == 0) if(L_Input(Varb0022) == 1 || L_Input(Varb0024) == 1) Enchanted->Runtime1 = 1;
          {
           statics int64 Vrab12 = Vrab03 - 95, Vrab13 = 190, Vrab14 = 26; int64 Vrab15 = Vrab04 - 1;
           switch(ruint8(Enchanted->Runtime1))
           {
            case 1: Vrab15 -= 89; case 0: if(Vrab08) Enchanted->Runtime1 = 6; if(Vrab09) Enchanted->Runtime1 = 2; if(Vrab10) Vrab07 = 1;
            break;
            case 2: Vrab15 -= 58; if(Vrab08) Enchanted->Runtime1 = 1; if(Vrab09) Enchanted->Runtime1 = 3; if(Vrab10) Vrab07 = 2; break;
            case 3: Vrab15 -= 27; if(Vrab08) Enchanted->Runtime1 = 2; if(Vrab09) Enchanted->Runtime1 = 4; if(Vrab10) Vrab07 = 3; break;
            case 4: Vrab15 += 4; if(Vrab08) Enchanted->Runtime1 = 3; if(Vrab09) Enchanted->Runtime1 = 5; if(Vrab10) Vrab07 = 4; break;
            case 5: Vrab15 += 35; if(Vrab08) Enchanted->Runtime1 = 4; if(Vrab09) Enchanted->Runtime1 = 6; if(Vrab10) Vrab07 = 5; break;
            case 6: Vrab15 += 66; if(Vrab08) Enchanted->Runtime1 = 5; if(Vrab09) Enchanted->Runtime1 = 1; if(Vrab10) Vrab07 = 6; break;
            default: break;
           }
           if(Enchanted->Runtime1 > 0){G_Set_Display(1, 0xFFFFFF, Vrab12, Vrab15, 0, 255ui8, Vrab13, Vrab14); if(Vrab11) G_Set_Display(1, 0xFFFFFF, Vrab12 - 1, Vrab15 - 1, 0, 255ui8, Vrab13 + 2, Vrab14 + 2);}
          }

          if(Vrab07 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);
          switch(Vrab07)
          {
           case 1: if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(255);} else {Enchanted->Reset(1, 0, 120, Enchanted->Runtime3);} break;
           case 2: Enchanted->Post_Info("Sorry, \"Network Game\" is currently unavailable. ;')                              Tho i'm not sure if i'm going to make this rather than resuming to my actual game."); break;
           case 3: Enchanted->Memory[1] = Enchanted->Memory[0]; if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(251);} else {Enchanted->Reset(250, 0, 120, Enchanted->Runtime3);} break;
           case 4: Enchanted->Memory[1] = Enchanted->Memory[0]; if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(255);} else {Enchanted->Reset(254, 0, 120, Enchanted->Runtime3);} break;
           case 5: Enchanted->Memory[1] = Enchanted->Memory[0]; if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(253);} else {Enchanted->Reset(252, 0, 120, Enchanted->Runtime3);} break;
           case 6: ShellExecuteW(0, 0, L"http://www.lf-empire.de", 0, 0, SW_SHOW); break;
           default: break;
          }
         }
        break;
        case 1: // Game Start - Animation Phase 1
         {
          if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);
          Enchanted->Runtime1 += Enchanted->Runtime2 / 9; Enchanted->Runtime2 -= 1;

          Enchanted->Print_Bar(Vrab03 + 704 - (Enchanted->Runtime1), Vrab04 - 24, 100, 0);

          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(2, 0, 64, Enchanted->Runtime3);
         }
        break;
        case 2: // Game Start - Animation Phase 2
         {
          if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);
          Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 -= 1;

          statics int64 Vrab07 = L_Rounding64(rxint64(Enchanted->Runtime1) / 2), Vrab08 = L_Rounding64(rxint64(Enchanted->Runtime1) / 4);
          Enchanted->Print_Bar(Vrab03 - 50 - Vrab07, Vrab04 - 24 - Vrab08, 100 + (Vrab07 * 2), Vrab07);

          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(3);
         }
        break;
        case 3: // Game Start
         {
          Enchanted->String[1] = "<none>";

          if(Enchanted->Runtime3 == 0)
          {
           Enchanted->Runtime3 = 1; statics string Temp01 = Enchanted->Memory[0].Address + Enchanted->Memory[0].Data_Address;
           Enchanted->File1.open(Temp01); Enchanted->String[0] = Temp01;
           if(!Enchanted->File1.is_open()){Enchanted->Runtime3 = 7; Enchanted->Not_Found();} else
           {
            switch(Enchanted->Memory[0].Engine)
            {
             case 1: break;
             default: Enchanted->Engine1 = std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1 > (); break;
            }
           }
           goto Labl02;
          }

          if(Enchanted->Runtime3 == 1)
          {
           string Temp01;
           while(Enchanted->File1)
           {
            Enchanted->File1 >> Temp01; if(!Enchanted->File1) break; if(Temp01.at(0) == '#'){std::getline(Enchanted->File1, Temp01); continue;}
            if(Temp01 == "<object>"){Enchanted->Runtime3 = 2; break;}
           }
           if(Enchanted->Runtime3 == 1)
           {
            Enchanted->Runtime3 = 7;
            statics string Temp02 = Enchanted->Memory[0].Address + Enchanted->Memory[0].Data_Address;
            Enchanted->String[0] = Temp02; Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "\"<object>\" syntax is undefined.";
           }
          }

          Labl01:
          if(Enchanted->Runtime3 == 2)
          {
           string Temp01; statics string Temp02 = Enchanted->Memory[0].Address + Enchanted->Memory[0].Data_Address; Enchanted->String[0] = Temp02; Enchanted->String[1] = "<object>";
           while(Enchanted->File1)
           {
            Enchanted->File1 >> Temp01; if(!Enchanted->File1) break; if(Temp01.at(0) == '#'){std::getline(Enchanted->File1, Temp01); continue;}
            if(Temp01 == "id:")
            {
             Enchanted->File1 >> Temp01; statics insize Vrab07 = rinsize(L_Numbering(Temp01)); Enchanted->File1 >> Temp01;
             if(Temp01 != "type:"){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "\"id: " + std::to_string(Vrab07) + "\" isn't followed with \"type:\"."; Enchanted->Runtime3 = 7; break;}
             Enchanted->File1 >> Temp01; statics uint8 Vrab08 = ruint8(L_Numbering(Temp01)); Enchanted->File1 >> Temp01;
             if(Temp01 != "file:"){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "\"id: " + std::to_string(Vrab07) + " type: " + std::to_string(Vrab08) + "\" isn't followed with \"file:\"."; Enchanted->Runtime3 = 7; break;}
             Enchanted->File1 >> Temp01; Temp01 = Enchanted->Memory[0].Address + Temp01; Enchanted->String[0] = Temp01;

             uint8 Vrab09 = 0;
             switch(Enchanted->Memory[0].Engine)
             {
              case 1: break;
              default: Vrab09 = Enchanted->Engine1->New(Vrab07, Vrab08, Temp01); break;
             }
             switch(Vrab09)
             {
              case 1: Enchanted->Not_Found(); Enchanted->Runtime3 = 7; break;
              case 2: continue;
              case 3: Enchanted->String[2] = "\"" + Enchanted->String[0] + "\""; Enchanted->String[3] = "Failed to execute the decoding/convertion, make sure the following file has no error."; Enchanted->Runtime3 = 7; break;
              default:
               Enchanted->Runtime3 = 3;
               {
                int1 Vrab10 = false;
                switch(Enchanted->Memory[0].Engine)
                {
                 case 1: break;
                 default: Vrab10 = Enchanted->Engine1->Select(Vrab07, Vrab08); break;
                }
                if(Vrab10) Enchanted->Runtime1 += 1;
               }
              break;
             }
             break;
            }
            if(Temp01 == "<object_end>")
            {
             Enchanted->Runtime3 = 4;
             if(Enchanted->Runtime1 == 0){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "No selectable character is found, at least one selectable character is required."; Enchanted->Runtime3 = 7;}
             Enchanted->Runtime1 = 0;
             break;
            }
            if(Temp01 == "<file_editing>") break;
            if(Temp01 == "<background>") break;
           }
           if(Enchanted->Runtime3 == 2){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "Unexpected end of \"<object>\", it should ended with \"<object_end>\"."; Enchanted->Runtime3 = 7;}
          }

          if(Enchanted->Runtime3 == 3)
          {
           string Temp01; Labl03:
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: Temp01 = Enchanted->Engine1->Load(Enchanted->Memory[0].Address, Enchanted->Memory[0].Custom_Mirror); break;
           }
           switch(Temp01.at(0))
           {
            case 'D': Enchanted->Runtime3 = 2; goto Labl01;
            case 'E': Enchanted->Runtime3 = 7; break;
            default: if(Enchanted->Memory[0].Fast_Loading) goto Labl03; break;
           }
           statics insize Vrab07 = Temp01.size() - 1; insize Vrab08 = 0;
           string Temp02; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} Enchanted->String[1] = Temp02;
           Temp02 = ""; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} if(Temp02.size() == 1){if(Temp02.at(0) != '0'){Enchanted->String[2] = "\"" + Enchanted->String[1] + "\"";} else {Enchanted->String[2] = "\"" + Enchanted->String[0] + "\"";}} else {Enchanted->String[2] = Temp02;}
           Temp02 = ""; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} Enchanted->String[3] = Temp02;
          }

          if(Enchanted->Runtime3 == 4)
          {
           string Temp01; statics string Temp02 = Enchanted->Memory[0].Address + Enchanted->Memory[0].Data_Address;
           if(!Enchanted->File1){if(Enchanted->File1.is_open()) Enchanted->File1.close(); Enchanted->File1.open(Temp02);} Enchanted->File1.seekg(Enchanted->File1.beg);
           while(Enchanted->File1)
           {
            Enchanted->File1 >> Temp01; if(!Enchanted->File1) break; if(Temp01.at(0) == '#'){std::getline(Enchanted->File1, Temp01); continue;}
            if(Temp01 == "<background>"){Enchanted->Runtime3 = 5; break;}
           }
           if(Enchanted->Runtime3 == 4)
           {
            Enchanted->Runtime3 = 7;
            Enchanted->String[0] = Temp02; Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "\"<background>\" syntax is undefined.";
           }
          }

          Labl02:
          if(Enchanted->Runtime3 == 5)
          {
           string Temp01; statics string Temp02 = Enchanted->Memory[0].Address + Enchanted->Memory[0].Data_Address; Enchanted->String[0] = Temp02; Enchanted->String[1] = "<background>";
           while(Enchanted->File1)
           {
            Enchanted->File1 >> Temp01; if(!Enchanted->File1) break; if(Temp01.at(0) == '#'){std::getline(Enchanted->File1, Temp01); continue;}
            if(Temp01 == "id:")
            {
             Enchanted->File1 >> Temp01; statics insize Vrab07 = rinsize(L_Numbering(Temp01)); Enchanted->File1 >> Temp01;
             if(Temp01 != "file:"){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "\"id: " + std::to_string(Vrab07) + "\" isn't followed with \"file:\"."; Enchanted->Runtime3 = 7; break;}
             Enchanted->File1 >> Temp01; Temp01 = Enchanted->Memory[0].Address + Temp01; Enchanted->String[0] = Temp01;

             uint8 Vrab08 = 0;
             switch(Enchanted->Memory[0].Engine)
             {
              case 1: break;
              default: Vrab08 = Enchanted->Engine1->Create(Vrab07, Temp01); break;
             }
             switch(Vrab08)
             {
              case 1: Enchanted->Not_Found(); Enchanted->Runtime3 = 7; break;
              case 2: continue;
              case 3: Enchanted->String[2] = "\"" + Enchanted->String[0] + "\""; Enchanted->String[3] = "Failed to execute the decoding/convertion, make sure the following file has no error."; Enchanted->Runtime3 = 7; break;
              default: Enchanted->Runtime3 = 6; Enchanted->Runtime1 += 1; break;
             }
             break;
            }
            if(Temp01 == "<background_end>")
            {
             Enchanted->Runtime3 = 8;
             if(Enchanted->Runtime1 == 0){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "No background is found, at least one background is required."; Enchanted->Runtime3 = 7;}
             break;
            }
            if(Temp01 == "<file_editing>") break;
            if(Temp01 == "<object>") break;
           }
           if(Enchanted->Runtime3 == 5){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "Unexpected end of \"<background>\", it should ended with \"<background_end>\"."; Enchanted->Runtime3 = 7;}
          }

          if(Enchanted->Runtime3 == 6)
          {
           string Temp01; Labl04:
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: Temp01 = Enchanted->Engine1->Manage(Enchanted->Memory[0].Address); break;
           }
           switch(Temp01.at(0))
           {
            case 'D': Enchanted->Runtime3 = 5; goto Labl02;
            case 'E': Enchanted->Runtime3 = 7; break;
            default: if(Enchanted->Memory[0].Fast_Loading) goto Labl04; break;
           }
           statics insize Vrab07 = Temp01.size() - 1; insize Vrab08 = 0;
           string Temp02; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} Enchanted->String[1] = Temp02;
           Temp02 = ""; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} if(Temp02.size() == 1){if(Temp02.at(0) != '0'){Enchanted->String[2] = "\"" + Enchanted->String[1] + "\"";} else {Enchanted->String[2] = "\"" + Enchanted->String[0] + "\"";}} else {Enchanted->String[2] = Temp02;}
           Temp02 = ""; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} Enchanted->String[3] = Temp02;
          }

          if(Enchanted->Runtime3 == 8) while(true)
          {
           {
            string Temp01;
            switch(Enchanted->Memory[0].Engine)
            {
             case 1: break;
             default:
              Temp01 = Enchanted->Memory[0].Address + "data\\stagez.dat"; if(!L_Exist(Temp01)){Enchanted->String[0] = Enchanted->Memory[0].Address + "data\\stage.txt";} else {Enchanted->String[0] = Enchanted->Memory[0].Address + "data\\stages.dat";}
              Temp01 = Enchanted->Engine1->Finalizer(Enchanted->Memory[0].Address);
             break;
            }
            switch(Temp01.at(0))
            {
             case 'E': Enchanted->Runtime3 = 7; break;
             default: break;
            }
            statics insize Vrab07 = Temp01.size() - 1; insize Vrab08 = 0;
            string Temp02; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} Enchanted->String[1] = Temp02;
            Temp02 = ""; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} if(Temp02.size() == 1){if(Temp02.at(0) != '0'){Enchanted->String[2] = "\"" + Enchanted->String[1] + "\"";} else {Enchanted->String[2] = "\"" + Enchanted->String[0] + "\"";}} else {Enchanted->String[2] = Temp02;}
            Temp02 = ""; while(Vrab08 < Vrab07){Vrab08 += 1; statics uint8 Vrab09 = Temp01.at(Vrab08); if(Vrab09 == '|') break; Temp02.push_back(Vrab09);} Enchanted->String[3] = Temp02;
            if(Enchanted->Runtime3 == 7) break;
           }

           {int1 Vrab07 = false; switch(Enchanted->Memory[0].Engine){case 1: break; default: Vrab07 = Enchanted->Engine1->Warning(); break;} if(Vrab07) Enchanted->Post_Info("Warning(s) found while processing the data(s), check \"Database\\Log.log\" for details.");}
           if(L_Exist("Database\\Temp.log")){std::ofstream File01(L_Execute("Database\\Temp.log"), std::ios::binary | std::ios::out); File01 << "You will find the last data that was processed here when there were irregularities or error in the data(s).\n\nIt's fine to remove/delete this file if you want, including \"Log.log\" too."; File01.close();} Enchanted->Post_Info(Enchanted->Engine1->Info()); Enchanted->Angel->Set(); if(Enchanted->Angel->Available()){Enchanted->Post_Info("AngelScript Version : " + Enchanted->Angel->Version() + ".");} else {Enchanted->Post_Info("Failed in initializing AngelScript.");} Enchanted->Reset(7, 0, 0, 180); Enchanted->String[0] = "<none>"; Enchanted->String[1] = "<none>"; if(Enchanted->File1.is_open()) Enchanted->File1.close();
           break;
          }
          
          if(Enchanted->Runtime3 == 7) Enchanted->Reset(4, 0, 100);

          {
           G_Set_Display(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06);
           statics int64 Vrab07 = L_Rounding64(145.0 / 2), Vrab08 = Vrab03 - 50 - Vrab07, Vrab09 = Vrab04 - 24 - L_Rounding64(145.0 / 4);
           Enchanted->Print_Bar(Vrab08, Vrab09, 100 + (Vrab07 * 2), Vrab07);
           string Temp01 = "Loading data(s)"; {statics uint64 Vrab10 = Enchanted->Tick % 120; if(Vrab10 / 30 > 0) Temp01.push_back('.'); if(Vrab10 / 60 > 0) Temp01.push_back('.'); if(Vrab10 / 90 > 0) Temp01.push_back('.');}
           string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
           string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
           Enchanted->Print_Text(Vrab08 + 3, Vrab09, 0, Temp01);
           Enchanted->Print_Text(Vrab08 + 3, Vrab09 + 38, 0, Temp02);
           Enchanted->Print_Text(Vrab08 + 247 - (rint64(Temp03.size()) * 9), Vrab09 + 57, 0, Temp03);
          }
         }
        break;
        case 4: // Game Start - Failed - Animation Phase 1
         {
          G_Set_Display(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06);
          statics int64 Vrab07 = L_Rounding64(145.0 / 2), Vrab08 = Vrab03 - 50 - Vrab07, Vrab09 = Vrab04 - 24 - L_Rounding64(145.0 / 4);
          Enchanted->Print_Bar(Vrab08, Vrab09, 100 + (Vrab07 * 2), Vrab07);
          string Temp01 = "Loading data(s)...";
          string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
          string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
          Enchanted->Print_Text(Vrab08 + 3, Vrab09, 2, Temp01);
          Enchanted->Print_Text(Vrab08 + 3, Vrab09 + 38, 0, Temp02);
          Enchanted->Print_Text(Vrab08 + 247 - (rint64(Temp03.size()) * 9), Vrab09 + 57, 0, Temp03);
          int32 Vrab10 = 15;
          if(Enchanted->String[2].size() > rinsize(Vrab10)) Vrab10 = Enchanted->String[2].size();
          if(Enchanted->String[3].size() > rinsize(Vrab10)) Vrab10 = Enchanted->String[3].size();
          statics int32 Vrab11 = L_Rounding(rxint64(rint64(Vrab10) - 1) * 4.5) - 1;
          Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 -= 1;
          Enchanted->Print_Bar(Vrab03 - Vrab11 - 8, Vrab04 + 458 - rint64(Enchanted->Runtime1), (ruint64(Vrab11) * 2) + 14, Vrab07 + 6);
          Enchanted->Print_Text(Vrab03 - L_Rounding64(rxint64(rint64(Enchanted->String[2].size())) * 4.5), Vrab04 + 458 - rint64(Enchanted->Runtime1), 4, Enchanted->String[2]);
          Enchanted->Print_Text(Vrab03 - L_Rounding64(rxint64(rint64(Enchanted->String[3].size())) * 4.5), Vrab04 + 477 - rint64(Enchanted->Runtime1), 0, Enchanted->String[3]);
          G_Set_Display(2, Enchanted->Pic_Index_Interface[24], Vrab03 - 76, Vrab04 + 509 - rint64(Enchanted->Runtime1));
          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(5);
         }
        break;
        case 5: // Game Start - Failed
         {
          if(Enchanted->Runtime3 == 0)
          {
           Enchanted->Runtime3 = 1;
           if(Enchanted->File1.is_open()) Enchanted->File1.close();
           G_Unload_Sprite(0); G_Unload_Pic(Enchanted->Pic_Index_Interface[Enchanted->Pic_Index_Interface.size() - 1] + 1); G_Unload_Image();
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: Enchanted->Engine1.reset(); break;
           }
          }
          G_Set_Display(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06);
          statics int64 Vrab07 = L_Rounding64(145.0 / 2), Vrab08 = Vrab03 - 50 - Vrab07, Vrab09 = Vrab04 - 24 - L_Rounding64(145.0 / 4);
          Enchanted->Print_Bar(Vrab08, Vrab09, 100 + (Vrab07 * 2), Vrab07);
          string Temp01 = "Loading data(s)...";
          string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
           string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
          Enchanted->Print_Text(Vrab08 + 3, Vrab09, 2, Temp01);
          Enchanted->Print_Text(Vrab08 + 3, Vrab09 + 38, 0, Temp02);
          Enchanted->Print_Text(Vrab08 + 247 - (rint64(Temp03.size()) * 9), Vrab09 + 57, 0, Temp03);
          int32 Vrab10 = 15;
          if(Enchanted->String[2].size() > rinsize(Vrab10)) Vrab10 = Enchanted->String[2].size();
          if(Enchanted->String[3].size() > rinsize(Vrab10)) Vrab10 = Enchanted->String[3].size();
          statics int32 Vrab11 = L_Rounding(rxint64(rint64(Vrab10) - 1) * 4.5) - 1;
          Enchanted->Print_Bar(Vrab03 - Vrab11 - 8, Vrab04 + 82, (ruint64(Vrab11) * 2) + 14, Vrab07 + 6);
          Enchanted->Print_Text(Vrab03 - L_Rounding64(rxint64(rint64(Enchanted->String[2].size())) * 4.5), Vrab04 + 82, 4, Enchanted->String[2]);
          Enchanted->Print_Text(Vrab03 - L_Rounding64(rxint64(rint64(Enchanted->String[3].size())) * 4.5), Vrab04 + 101, 0, Enchanted->String[3]);
          if(L_Input(Varb0020) == 1){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); Enchanted->Reset(6, 0, 0, 180);}
          statics int64 Vrab12 = Vrab03 - 76, Vrab13 = Vrab04 + 133; if(L_In(Vrab12, Vrab13, 151, 26)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[25], Vrab12, Vrab13); if(L_On(Vrab12, Vrab13, 151, 26)){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); Enchanted->Reset(6, 0, 0, 180);}} else
          {G_Set_Display(2, Enchanted->Pic_Index_Interface[24], Vrab12, Vrab13);}
          if(Enchanted->Runtime1 == 0)
          {if(L_Input(Varb0021) == 1 || L_Input(Varb0022) == 1 || L_Input(Varb0023) == 1 || L_Input(Varb0024) == 1) Enchanted->Runtime1 = 1;}
          if(Enchanted->Runtime1 == 1)
          {G_Set_Display(1, 0xFFFFFF, Vrab12 -1, Vrab13 - 1, 0ui8, 255ui8, 153, 28); if((Enchanted->Tick % 20) / 10 == 0) G_Set_Display(1, 0xFFFFFF, Vrab12 - 2, Vrab13 - 2, 0ui8, 255ui8, 155, 30);}
         }
        break;
        case 6: // Game Start - Failed - Animation Phase 2
         {
          if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);
          Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 += 1;
          
          statics int64 Vrab07 = L_Rounding64(145.0 / 2), Vrab08 = Vrab03 - 50 - Vrab07, Vrab09 = Vrab04 - 24 - L_Rounding64(145.0 / 4);
          Enchanted->Print_Bar(Vrab08, Vrab09 - rint64(Enchanted->Runtime1), 100 + (Vrab07 * 2), Vrab07);
          string Temp01 = "Loading data(s)...";
          string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
           string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
          Enchanted->Print_Text(Vrab08 + 3, Vrab09 - rint64(Enchanted->Runtime1), 2, Temp01);
          Enchanted->Print_Text(Vrab08 + 3, Vrab09 + 38 - rint64(Enchanted->Runtime1), 0, Temp02);
          Enchanted->Print_Text(Vrab08 + 247 - (rint64(Temp03.size()) * 9), Vrab09 + 57 - rint64(Enchanted->Runtime1), 0, Temp03);
          int32 Vrab10 = 15;
          if(Enchanted->String[2].size() > rinsize(Vrab10)) Vrab10 = Enchanted->String[2].size();
          if(Enchanted->String[3].size() > rinsize(Vrab10)) Vrab10 = Enchanted->String[3].size();
          statics int32 Vrab11 = L_Rounding(rxint64(rint64(Vrab10) - 1) * 4.5) - 1;
          Enchanted->Print_Bar(Vrab03 - Vrab11 - 8, Vrab04 + 82 + rint64(Enchanted->Runtime1), (ruint64(Vrab11) * 2) + 14, Vrab07 + 6);
          Enchanted->Print_Text(Vrab03 - L_Rounding64(rxint64(rint64(Enchanted->String[2].size())) * 4.5), Vrab04 + 82 + rint64(Enchanted->Runtime1), 4, Enchanted->String[2]);
          Enchanted->Print_Text(Vrab03 - L_Rounding64(rxint64(rint64(Enchanted->String[3].size())) * 4.5), Vrab04 + 101 + rint64(Enchanted->Runtime1), 0, Enchanted->String[3]);
          G_Set_Display(2, Enchanted->Pic_Index_Interface[24], Vrab03 - 76, Vrab04 + 133 + rint64(Enchanted->Runtime1));

          if(Enchanted->Runtime2 == 121) Enchanted->Reset(0);
         }
        break;
        case 7: // Game Start - Success
         {
          Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 += 1;

          if(Enchanted->Runtime2 < 20) G_Set_Display(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85);
          if(Enchanted->Runtime2 >= 20 && Enchanted->Runtime2 <= 70){G_Set_Display(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(70 - Enchanted->Runtime2) / 50) * 255.0)));}
          if(Enchanted->Runtime2 >= 71){G_Set_Display(2, Enchanted->Pic_Index_Interface[34], Vrab03 - 93, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(Enchanted->Runtime2 - 71) / 50) * 255.0)));}
          
          if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);

          statics int64 Vrab07 = L_Rounding64(145.0 / 2), Vrab08 = Vrab03 - 50 - Vrab07, Vrab09 = Vrab04 - 24 - L_Rounding64(145.0 / 4);
          Enchanted->Print_Bar(Vrab08 - rint64(Enchanted->Runtime1), Vrab09, 100 + (Vrab07 * 2), Vrab07);
          string Temp01 = "Loading data(s) complete.";
          string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
          string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
          Enchanted->Print_Text(Vrab08 + 3 - rint64(Enchanted->Runtime1), Vrab09, 1, Temp01);
          Enchanted->Print_Text(Vrab08 + 3 - rint64(Enchanted->Runtime1), Vrab09 + 38, 0, Temp02);
          Enchanted->Print_Text(Vrab08 + 247 - (rint64(Temp03.size()) * 9) - rint64(Enchanted->Runtime1), Vrab09 + 57, 0, Temp03);

          if(Enchanted->Runtime2 == 121) Enchanted->Reset(8);
         }
        break;
        case 8: // Game Start - Menu
         {
          if(Enchanted->Runtime1 != 7){G_Set_Display(2, Enchanted->Pic_Index_Interface[34], Vrab03 - 93, Vrab04 - 85);} else
          {
           Enchanted->Runtime2 += 1;
           if(Enchanted->Runtime2 <= 50){G_Set_Display(2, Enchanted->Pic_Index_Interface[34], Vrab03 - 93, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(50 - Enchanted->Runtime2) / 50) * 255.0)));}
           if(Enchanted->Runtime2 >= 51){G_Set_Display(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(Enchanted->Runtime2 - 51) / 50) * 255.0)));}
           if(Enchanted->Runtime2 == 101){Enchanted->Reset(0); break;}
          }

          if(Enchanted->Runtime1 <= 6)
          {
           uint8 Vrab07 = 0;
           if(L_In(Vrab03 - 80, Vrab04 - 86, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[35], Vrab03 - 93, Vrab04 - 85); if(L_On(Vrab03 - 80, Vrab04 - 86, 160, 20)) Vrab07 = 1;}
           if(L_In(Vrab03 - 80, Vrab04 - 55, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[36], Vrab03 - 93, Vrab04 - 54); if(L_On(Vrab03 - 80, Vrab04 - 55, 160, 20)) Vrab07 = 2;}
           if(L_In(Vrab03 - 80, Vrab04 - 24, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[37], Vrab03 - 93, Vrab04 - 24); if(L_On(Vrab03 - 80, Vrab04 - 24, 160, 20)) Vrab07 = 3;}
           if(L_In(Vrab03 - 80, Vrab04 + 7, 160, 20)) {Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[38], Vrab03 - 93, Vrab04 + 7);  if(L_On(Vrab03 - 80, Vrab04 + 7, 160, 20))  Vrab07 = 4;}
           if(L_In(Vrab03 - 80, Vrab04 + 38, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[39], Vrab03 - 93, Vrab04 + 38); if(L_On(Vrab03 - 80, Vrab04 + 38, 160, 20)) Vrab07 = 5;}
           if(L_In(Vrab03 - 80, Vrab04 + 69, 160, 20)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[40], Vrab03 - 93, Vrab04 + 70); if(L_On(Vrab03 - 80, Vrab04 + 69, 160, 20)) Vrab07 = 6;}

           if(Enchanted->Runtime3 > 2) if(Enchanted->Memory[0].Skip_Animation){Enchanted->Runtime3 = 0;} else {Enchanted->Runtime3 -= 3; G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);}

           int1 Vrab08 = L_Input(Varb0021) == 1, Vrab09 = L_Input(Varb0023) == 1, Vrab10 = L_Input(Varb0020) == 1; statics int1 Vrab11 = ((Enchanted->Tick % 20) / 10) == 0;
           if(!Vrab08){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab08 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][0]) == 1); if(Vrab08) break;}}
           if(!Vrab09){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab09 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][1]) == 1); if(Vrab09) break;}}
           if(!Vrab10){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab10 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][4]) == 1); if(Vrab10) break;}}
           if(Vrab08 == Vrab09){Vrab08 = Vrab09 = false;} if(Enchanted->Runtime1 == 0) if(L_Input(Varb0022) == 1 || L_Input(Varb0024) == 1) Enchanted->Runtime1 = 1;
           {
            statics int64 Vrab12 = Vrab03 - 95, Vrab13 = 190, Vrab14 = 26; int64 Vrab15 = Vrab04 - 1;
            switch(ruint8(Enchanted->Runtime1))
            {
             case 1: Vrab15 -= 89; case 0: if(Vrab08) Enchanted->Runtime1 = 6; if(Vrab09) Enchanted->Runtime1 = 2; if(Vrab10) Vrab07 = 1;
             break;
             case 2: Vrab15 -= 58; if(Vrab08) Enchanted->Runtime1 = 1; if(Vrab09) Enchanted->Runtime1 = 3; if(Vrab10) Vrab07 = 2; break;
             case 3: Vrab15 -= 27; if(Vrab08) Enchanted->Runtime1 = 2; if(Vrab09) Enchanted->Runtime1 = 4; if(Vrab10) Vrab07 = 3; break;
             case 4: Vrab15 += 4; if(Vrab08) Enchanted->Runtime1 = 3; if(Vrab09) Enchanted->Runtime1 = 5; if(Vrab10) Vrab07 = 4; break;
             case 5: Vrab15 += 35; if(Vrab08) Enchanted->Runtime1 = 4; if(Vrab09) Enchanted->Runtime1 = 6; if(Vrab10) Vrab07 = 5; break;
             case 6: Vrab15 += 66; if(Vrab08) Enchanted->Runtime1 = 5; if(Vrab09) Enchanted->Runtime1 = 1; if(Vrab10) Vrab07 = 6; break;
             default: break;
            }
            if(Enchanted->Runtime1 > 0){G_Set_Display(1, 0xFFFFFF, Vrab12, Vrab15, 0, 255ui8, Vrab13, Vrab14); if(Vrab11) G_Set_Display(1, 0xFFFFFF, Vrab12 - 1, Vrab15 - 1, 0, 255ui8, Vrab13 + 2, Vrab14 + 2);}
           }

           if(Vrab07 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);
           switch(Vrab07)
           {
            case 1: Enchanted->Reset(8, 8); break;
            case 2:
             {
              int1 Vrab12 = false;
              switch(Enchanted->Memory[0].Engine)
              {
               case 1: break;
               default: Vrab12 = Enchanted->Engine1->Staging(); break;
              }
              if(Vrab12){Enchanted->Reset(8, 8);} else {Enchanted->Post_Info("\"Stage\" is not installed.");}
             }
            break;
            case 3: Enchanted->Post_Info("Sorry, \"Championship\" is currently unavailable."); break;
            case 4: Enchanted->Post_Info("Sorry, \"Battle\" is currently unavailable."); break;
            case 5:
             Enchanted->Post_Info("Sorry, \"Playback Recording\" is currently unavailable.");
             {

             }
            break;
            case 6:
             {
              //Enchanted->Post_Info("\"Return\" might allows you to reload stuff without having to quit/close the game, but sadly, the assets/sprites won't get updated, so in order to update the assets/sprites, re-opening the game is a must.");
              G_Unload_Sprite(0); G_Unload_Pic(Enchanted->Pic_Index_Interface[Enchanted->Pic_Index_Interface.size() - 1] + 1); G_Unload_Image();
              switch(Enchanted->Memory[0].Engine)
              {
               case 1: break;
               default: Enchanted->Engine1.reset(); break;
              }
              Enchanted->Angel->Reset();
              Enchanted->Select_Background = 0; Enchanted->Select_Character.clear(); Enchanted->Select_Difficult = 0; Enchanted->Select_Mode = 0; Enchanted->Select_Music = 0; Enchanted->Select_Team.clear();
              Enchanted->Runtime1 = 7; Enchanted->Runtime2 = 0;
             }
            break;
            default: break;
           }
          }

          if(Enchanted->Runtime1 == 8)
          {
           G_Set_Display(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(Enchanted->Runtime2) / 30) * 255.0)), Vrab05, Vrab06);
           if(Enchanted->Runtime2 < 30){Enchanted->Runtime2 += 1;} else
           {
            switch(Enchanted->Runtime3)
            {
             case 1: break;
             default: Enchanted->Reset(9); break;
            }
           }
          }

          if(Enchanted->Runtime1 == 9)
          {
           G_Set_Display(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(30 - Enchanted->Runtime2) / 30) * 255.0)), Vrab05, Vrab06);
           if(Enchanted->Runtime2 <= 30){Enchanted->Runtime2 += 1;} else {Enchanted->Reset(8);}
          }
         }
        break;
        case 250: // General Settings - Animation Phase
         {
          if(Enchanted->Runtime2 > 120)
          {if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; Enchanted->Runtime1 -= ((Enchanted->Runtime2 - 120) / 9); Enchanted->Runtime2 += 1;} else
          {if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; Enchanted->Runtime1 += (Enchanted->Runtime2 / 9); Enchanted->Runtime2 -= 1;}
          G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);
          
          goto Labl05;
          Labl06:

          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(251, Enchanted->Runtime1);
          if(Enchanted->Runtime2 == 241) Enchanted->Reset(0, 0, 0, Enchanted->Runtime3);
         }
        break;
        case 251: // General Settings
         {
          G_Set_Display(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06);

          Labl05:
          {
           statics int64 Vrab07 = Vrab03 + rint64(Enchanted->Runtime1 & 0xFFF) - 1104, Vrab08 = Vrab04 - 175; uint64 Vrab09 = 700, Vrab10 = 350;
           if(Vrab09 % 2 == 1) Vrab09 += 1; if(Vrab10 % 2 == 1) Vrab10 += 1;

           G_Set_Display(2, Enchanted->Pic_Index_Interface[6], Vrab07 - 12, Vrab08 - 12);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[7], Vrab07 + Vrab09 + 1, Vrab08 - 12);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[8], Vrab07 - 12, Vrab08 + Vrab10 + 1);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[9], Vrab07 + Vrab09 + 1, Vrab08 + Vrab10 + 1);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[10], Vrab07, Vrab08 + Vrab10 + 10, 0ui8, 255ui8, Vrab09);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[11], Vrab07 - 12, Vrab08, 0ui8, 255ui8, 0, Vrab10);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[11], Vrab07 + Vrab09 + 10, Vrab08, 0ui8, 255ui8, 0, Vrab10);

           {
            statics uint64 Vrab11 = 105;
            statics uint64 Vrab12 = L_Rounding64(rxint64(Vrab09) / 2.0) - Vrab11;
            G_Set_Display(2, Enchanted->Pic_Index_Interface[10], Vrab07, Vrab08 - 12, 0ui8, 255ui8, Vrab12);
            G_Set_Display(2, Enchanted->Pic_Index_Interface[10], Vrab07 + Vrab12 + (Vrab11 * 2), Vrab08 - 12, 0ui8, 255ui8, Vrab12);
           }

           {
            uint64 Vrab11 = Vrab10 + 1; uint64 Vrab12 = ruint64(-1);
            while(Vrab11 > 0)
            {
             uint64 Vrab13 = Vrab11 / 198; if(Vrab13 > 0){Vrab13 = 198;} else {Vrab13 = Vrab11 % 198;} Vrab11 -= Vrab13; Vrab12 += 1;
             G_Set_Display(3, Enchanted->Pic_Index_Interface[12], Vrab07 - 9, Vrab08 + (Vrab12 * 198), 0ui8, 255ui8, 9, Vrab13, 0, 1);
             G_Set_Display(3, Enchanted->Pic_Index_Interface[12], Vrab07 + Vrab09 + 1, Vrab08 + (Vrab12 * 198), 0ui8, 255ui8, 9, Vrab13, 0, 1);
            }
           }

           {
            uint64 Vrab11 = Vrab10 + 19; uint64 Vrab12 = ruint64(-1);
            while(Vrab11 > 0)
            {
             uint64 Vrab13 = Vrab11 / 198; if(Vrab13 > 0){Vrab13 = 198;} else {Vrab13 = Vrab11 % 198;} Vrab11 -= Vrab13; Vrab12 += 1;
             uint64 Vrab14 = Vrab09 + 1; uint64 Vrab15 = ruint64(-1);
             while(Vrab14 > 0)
             {
              uint64 Vrab16 = Vrab14 / 198; if(Vrab16 > 0){Vrab16 = 198;} else {Vrab16 = Vrab14 % 198;} Vrab14 -= Vrab16; Vrab15 += 1;
              G_Set_Display(3, Enchanted->Pic_Index_Interface[12], Vrab07 + (Vrab15 * 198), Vrab08 - 9 + (Vrab12 * 198), 0ui8, 255ui8, Vrab16, Vrab13, 1, 0);
             }
            }
           }
           
           G_Set_Display(2, Enchanted->Pic_Index_Interface[20], Vrab07 + 273, Vrab08 - 21);

           {
            uint8 Vrab11 = 0;
            {statics int64 Vrab12 = Vrab07 + 377, Vrab13 = Vrab08 + 324; if(L_In(Vrab12, Vrab13, 151, 26) && Enchanted->Menu != 250){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[25], Vrab12, Vrab13); if(L_On(Vrab12, Vrab13, 151, 26)) Vrab11 = 41;} else {G_Set_Display(2, Enchanted->Pic_Index_Interface[24], Vrab12, Vrab13);}}
            {statics int64 Vrab12 = Vrab07 + 549, Vrab13 = Vrab08 + 324; if(L_In(Vrab12, Vrab13, 151, 26) && Enchanted->Menu != 250){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[27], Vrab12, Vrab13); if(L_On(Vrab12, Vrab13, 151, 26)) Vrab11 = 42;} else {G_Set_Display(2, Enchanted->Pic_Index_Interface[26], Vrab12, Vrab13);}}
           
            {
             uint64 Vrab12 = Enchanted->Runtime1; uint64 Vrab13 = (Vrab12 & 0xFFFFFF) >> 12; uint64 Vrab14 = (Vrab12 & 0xFFFFFFFFF) >> 24; uint64 Vrab15 = (Vrab12 & 0xFFFFFFFFFF) >> 36; Vrab12 = Vrab12 & 0xFFF;

             if(Enchanted->Menu != 250)
             {
              if(L_In(Vrab07 + 679, Vrab08 + 14, 10, 300))
              {
               Enchanted->Draw = false;
               if(Input.MOUS_Left > 0 || L_On(Vrab07 + 679, Vrab08 + 14, 10, 300))
               {
                if(Vrab14 == 999 && (Input.MOUS_Y_Left < Vrab08 + 14 + L_Rounding64((rxint64(Vrab13) / 900.0) * 300.0) || Input.MOUS_Y_Left > Vrab08 + 14 + L_Rounding64((300.0 / 900.0) * 300.0) + L_Rounding64((rxint64(Vrab13) / 900.0) * 300.0)))
                {
                 if(L_On(Vrab07 + 679, Vrab08 + 14, 10, 300))
                 {
                  statics int64 Vrab16 = L_Rounding64(rxint64(Input.MOUS_Y - (Vrab08 + 14) - L_Rounding64(((300.0 / 900.0) * 300.0) / 2.0)) * (900 / 300));
                  Vrab13 = Vrab16;
                  if(Vrab16 < 0) if(Vrab13 > 600) Vrab13 = 0; if(Vrab13 > 600) Vrab13 = 600;
                 }
                } else
                {
                 if(Input.MOUS_Left > 0)
                 {
                  if(Vrab14 == 999) Vrab14 = Vrab13;
                  statics int64 Vrab16 = L_Rounding64((rxint64(Input.MOUS_Y) - rxint64(Input.MOUS_Y_Left)) * (900 / 300));
                  Vrab13 = Vrab14 + Vrab16;
                  if(Vrab16 < 0) if(Vrab13 > 600) Vrab13 = 0; if(Vrab13 > 600) Vrab13 = 600;
                 }
                } 
               } else {Vrab14 = 999;}
              } else {Vrab14 = 999;}
              if(Vrab14 == 999) if(Input.MOUS_X >= Vrab07 + 14 && Input.MOUS_X <= Vrab07 + 689 && Input.MOUS_Y >= Vrab08 + 14 && Input.MOUS_Y <= Vrab08 + 314)
              {
               Vrab13 += L_Rounding64(rxint64(Input.MOUS_SCROLL) * (900.0 / 300.0) / 10.0); if(Input.MOUS_SCROLL < 0) if(Vrab13 > 600) Vrab13 = 0; if(Vrab13 > 600) Vrab13 = 600;
              }
             }

             G_Set_Display(2, Enchanted->Pic_Index_Interface[122], Vrab07 + 14, Vrab08 + 14, 0ui8, 255ui8, 665, 300);
             G_Set_Display(3, Enchanted->Pic_Index_Interface[123], Vrab07 + 14, Vrab08 + 14, 0ui8, 255ui8, 665, 300, 0, Vrab13);
             G_Set_Display(2, Enchanted->Pic_Index_Interface[120], Vrab07 + 679, Vrab08 + 14, 0ui8, 255ui8, 10, 300);
             G_Set_Display(2, Enchanted->Pic_Index_Interface[121], Vrab07 + 679, Vrab08 + 14 + L_Rounding64((rxint64(Vrab13) / 900.0) * 300.0), 0ui8, 255ui8, 10, L_Rounding64((300.0 / 900.0) * 300.0));
             G_Set_Display(2, Enchanted->Pic_Index_Interface[120], Vrab07 + 681, Vrab08 + 11 + L_Rounding64((rxint64(Vrab13) / 900.0) * 300.0) + L_Rounding64(((300.0 / 900.0) * 300.0) / 2.0), 0ui8, 255ui8, 6, 0);
             G_Set_Display(2, Enchanted->Pic_Index_Interface[120], Vrab07 + 681, Vrab08 + 14 + L_Rounding64((rxint64(Vrab13) / 900.0) * 300.0) + L_Rounding64(((300.0 / 900.0) * 300.0) / 2.0), 0ui8, 255ui8, 6, 0);
             G_Set_Display(2, Enchanted->Pic_Index_Interface[120], Vrab07 + 681, Vrab08 + 17 + L_Rounding64((rxint64(Vrab13) / 900.0) * 300.0) + L_Rounding64(((300.0 / 900.0) * 300.0) / 2.0), 0ui8, 255ui8, 6, 0);

             Enchanted->Print_Text(Vrab07 + 14, Vrab08 + 314 - Vrab13, 0, "asdkasogkaoskddasohjasjdlaks " + std::to_string(Enchanted->Memory[0].Volume), Vrab08 + 14, Vrab08 + 314);

             Enchanted->Runtime1 = (Vrab12 & 0xFFF) + ((Vrab13 & 0xFFF) << 12) + ((Vrab14 & 0xFFF) << 24) + ((Vrab15 & 0xF) << 36);
            }

            switch(Vrab11)
            {
             case 41: Enchanted->Memory[0] = Enchanted->Memory[1]; Enchanted->Save_Memory();
             case 42:
              if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(0);} else {Enchanted->Reset(250, Enchanted->Runtime1, 121, 180);}
             break;
             default: break;
            }
            if(Vrab11 == 42){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]);} else {if(Vrab11 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);}
           }
          }
          if(Enchanted->Menu == 250) goto Labl06;
         
         }
        break;
        case 252: // Recording Info - Animation Phase
         {
          if(Enchanted->Runtime2 > 120)
          {if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; Enchanted->Runtime1 -= ((Enchanted->Runtime2 - 120) / 12); Enchanted->Runtime2 += 1;} else
          {if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 -= 1;}
          G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);

          {
           statics int64 Vrab07 = Vrab03 - 352, Vrab08 = Vrab04 - 718 + (Enchanted->Runtime1);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[101], Vrab07, Vrab08);
           Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 37, 0, Enchanted->Memory[1].User);
           {
            statics insize Vrab09 = Enchanted->Memory[1].Note.size();
            if(Vrab09 <= 57)
            {Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 62, 0, Enchanted->Memory[1].Note);} else
            {
             if(Vrab09 <= 114)
             {Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 62, 0, string(Enchanted->Memory[1].Note, 0, 57)); Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 78, 0, string(Enchanted->Memory[1].Note, 57, Vrab09 - 57));} else
             {
              if(Vrab09 <= 171)
              {Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 62, 0, string(Enchanted->Memory[1].Note, 0, 57)); Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 78, 0, string(Enchanted->Memory[1].Note, 57, 57)); Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 94, 0, string(Enchanted->Memory[1].Note, 114, Vrab09 - 114));} else
              {
               Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 62, 0, string(Enchanted->Memory[1].Note, 0, 57)); Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 78, 0, string(Enchanted->Memory[1].Note, 57, 57));
               Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 94, 0, string(Enchanted->Memory[1].Note, 114, 57)); Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 110, 0, string(Enchanted->Memory[1].Note, 171, Vrab09 - 171));
              }
             }
            }
           }
           Enchanted->Print_Text(Vrab07 + 169, Vrab08 + 139, 0, Enchanted->Memory[1].Email);
           Enchanted->Print_Text(Vrab07 + 353 - L_Rounding64(rxint64(Enchanted->Memory[1].Record_Address.size()) * 4.5), Vrab08 + 236, 0, Enchanted->Memory[1].Record_Address);
           if(Enchanted->Memory[1].Recording)
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[103], Vrab07 + 166, Vrab08 + 211);} else
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[104], Vrab07 + 166, Vrab08 + 211);}
           if(Enchanted->Memory[1].True_Recording)
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[103], Vrab07 + 519, Vrab08 + 211);} else
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[104], Vrab07 + 519, Vrab08 + 211);}
          }
          
          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(253);
          if(Enchanted->Runtime2 == 241) Enchanted->Reset(0, 0, 0, Enchanted->Runtime3);
         }
        break;
        case 253: // Recording Info
         {
          G_Set_Display(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06); uint8 Vrab07 = 0;

          if(Enchanted->Runtime2 == 0)
          {
           int1 Vrab08 = L_Input(Varb0021) == 1, Vrab09 = L_Input(Varb0023) == 1, Vrab10 = L_Input(Varb0022) == 1, Vrab11 = L_Input(Varb0024) == 1, Vrab12 = L_Input(Varb0020) == 1;
           if(!Vrab08){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab08 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][0]) == 1); if(Vrab08) break;}}
           if(!Vrab09){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab09 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][1]) == 1); if(Vrab09) break;}}
           if(!Vrab10){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab10 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][2]) == 1); if(Vrab10) break;}}
           if(!Vrab11){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab11 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][3]) == 1); if(Vrab11) break;}}
           if(!Vrab12){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab12 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][4]) == 1); if(Vrab12) break;}}
           if(Vrab08 == Vrab09){Vrab08 = Vrab09 = false;}
           if(Vrab10 == Vrab11){Vrab10 = Vrab11 = false;}

           switch(ruint8(Enchanted->Runtime1))
           {
            case 1: if(Vrab08) Enchanted->Runtime1 = 7; if(Vrab09) Enchanted->Runtime1 = 2; break;
            case 0: case 7: case 9: if(Vrab08) Enchanted->Runtime1 = 6; if(Vrab09) Enchanted->Runtime1 = 1; break;
            case 8: if(Vrab08) Enchanted->Runtime1 = 3; if(Vrab09) Enchanted->Runtime1 = 5; break;
            default: if(Vrab08) Enchanted->Runtime1 -= 1; if(Vrab09) Enchanted->Runtime1 += 1; break;
           }
           switch(ruint8(Enchanted->Runtime1))
           {
            case 4: if(Vrab10 || Vrab11) Enchanted->Runtime1 = 8; break;
            case 0: case 7: if(Vrab10 || Vrab11) Enchanted->Runtime1 = 9; break;
            case 8: if(Vrab10 || Vrab11) Enchanted->Runtime1 = 4; break;
            case 9: if(Vrab10 || Vrab11) Enchanted->Runtime1 = 7; break;
            default: break;
           }

           if(Vrab12)
           {
            Vrab07 = ruint8(Enchanted->Runtime1); if(Vrab07 == 0) Vrab07 = 7;
            switch(Vrab07)
            {
             case 1: case 2: case 3: Enchanted->Runtime2 = Enchanted->Runtime1; break;
             case 5: Enchanted->Runtime2 = 4; break;
             case 4: Enchanted->Memory[1].Recording = !Enchanted->Memory[1].Recording; break;
             case 8: Enchanted->Memory[1].True_Recording = !Enchanted->Memory[1].True_Recording; break;
             default: break;
            }
           }
          }

          {
           statics int64 Vrab08 = Vrab03 - 352, Vrab09 = Vrab04 - 168;
           G_Set_Display(2, Enchanted->Pic_Index_Interface[101], Vrab08, Vrab09);

           if(L_In(Vrab08 + 165, Vrab09 + 211, 19, 19)){Enchanted->Draw = false; if(L_On(Vrab08 + 165, Vrab09 + 211, 19, 19)) Enchanted->Memory[1].Recording = !Enchanted->Memory[1].Recording;}
           if(L_In(Vrab08 + 519, Vrab09 + 211, 19, 19)){Enchanted->Draw = false; if(L_On(Vrab08 + 519, Vrab09 + 211, 19, 19)) Enchanted->Memory[1].True_Recording = !Enchanted->Memory[1].True_Recording;}
           if(L_In(Vrab08 + 180, Vrab09 + 261, 344, 23)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[102], Vrab08 + 180, Vrab09 + 261); if(L_On(Vrab08 + 180, Vrab09 + 261, 344, 23)) Vrab07 = 6;}
           if(L_In(Vrab08 + 187, Vrab09 + 296, 151, 26)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[25], Vrab08 + 187, Vrab09 + 296); if(L_On(Vrab08 + 187, Vrab09 + 296, 151, 26)) Vrab07 = 7;}
           if(L_In(Vrab08 + 366, Vrab09 + 296, 151, 26)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[27], Vrab08 + 366, Vrab09 + 296); if(L_On(Vrab08 + 366, Vrab09 + 296, 151, 26)) Vrab07 = 9;}

           if(L_In(Vrab08 + 166, Vrab09 + 37, 521, 19))
           {
            Enchanted->Draw = false; if(L_On(Vrab08 + 166, Vrab09 + 37, 521, 19)) if(Enchanted->Runtime2 == 1){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = 1;}
           }
           if(L_In(Vrab08 + 166, Vrab09 + 62, 521, 71))
           {
            Enchanted->Draw = false; if(L_On(Vrab08 + 166, Vrab09 + 62, 521, 71)) if(Enchanted->Runtime2 == 2){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = 2;}
           }
           if(L_In(Vrab08 + 166, Vrab09 + 139, 521, 19))
           {
            Enchanted->Draw = false; if(L_On(Vrab08 + 166, Vrab09 + 139, 521, 19)) if(Enchanted->Runtime2 == 3){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = 3;}
           }
           if(L_In(Vrab08 + 166, Vrab09 + 236, 372, 19))
           {
            Enchanted->Draw = false; if(L_On(Vrab08 + 166, Vrab09 + 236, 372, 19)) if(Enchanted->Runtime2 == 4){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = 4;}
           }

           if(Enchanted->Runtime2 == 1)
           {
            if(Vrab07 == 0) L_Typing(Enchanted->Memory[1].User); if(Enchanted->Memory[1].User.size() > 57) Enchanted->Memory[1].User.resize(57); if(L_Input(Varb0020) == 1 && Vrab07 == 0) Enchanted->Runtime2 = 0;
            Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 37, 1, Enchanted->Memory[1].User);
           } else
           {
            if(Enchanted->Memory[1].User == "") Enchanted->Memory[1].User = "<none>";
            Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 37, 0, Enchanted->Memory[1].User);
           }
           {
            uint8 Vrab10 = 0;
            if(Enchanted->Runtime2 == 2)
            {
             if(Vrab07 == 0) L_Typing(Enchanted->Memory[1].Note); if(Enchanted->Memory[1].Note.size() > 228) Enchanted->Memory[1].Note.resize(228); if(L_Input(Varb0020) == 1 && Vrab07 == 0) Enchanted->Runtime2 = 0;
             Vrab10 = 1;
            } else
            {
             if(Enchanted->Memory[1].Note == "") Enchanted->Memory[1].Note = "<none>";
            }
            statics insize Vrab11 = Enchanted->Memory[1].Note.size();
            if(Vrab11 <= 57)
            {Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 62, Vrab10, Enchanted->Memory[1].Note);} else
            {
             if(Vrab11 <= 114)
             {Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 62, Vrab10, string(Enchanted->Memory[1].Note, 0, 57)); Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 78, Vrab10, string(Enchanted->Memory[1].Note, 57, Vrab11 - 57));} else
             {
              if(Vrab11 <= 171)
              {Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 62, Vrab10, string(Enchanted->Memory[1].Note, 0, 57)); Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 78, Vrab10, string(Enchanted->Memory[1].Note, 57, 57)); Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 94, Vrab10, string(Enchanted->Memory[1].Note, 114, Vrab11 - 114));} else
              {
               Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 62, Vrab10, string(Enchanted->Memory[1].Note, 0, 57)); Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 78, Vrab10, string(Enchanted->Memory[1].Note, 57, 57));
               Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 94, Vrab10, string(Enchanted->Memory[1].Note, 114, 57)); Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 110, Vrab10, string(Enchanted->Memory[1].Note, 171, Vrab11 - 171));
              }
             }
            }
           }
           if(Enchanted->Runtime2 == 3)
           {
            if(Vrab07 == 0) L_Typing(Enchanted->Memory[1].Email); if(Enchanted->Memory[1].Email.size() > 57) Enchanted->Memory[1].Email.resize(57); if(L_Input(Varb0020) == 1 && Vrab07 == 0) Enchanted->Runtime2 = 0;
            Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 139, 1, Enchanted->Memory[1].Email);
           } else
           {
            if(Enchanted->Memory[1].Email == "") Enchanted->Memory[1].Email = "<none>";
            Enchanted->Print_Text(Vrab08 + 169, Vrab09 + 139, 0, Enchanted->Memory[1].Email);
           }
           if(Enchanted->Runtime2 == 4)
           {
            if(Vrab07 == 0) L_Typing(Enchanted->Memory[1].Record_Address); L_Robust(Enchanted->Memory[1].Record_Address); if(Enchanted->Memory[1].Record_Address.size() > 40) Enchanted->Memory[1].Record_Address.resize(40); if(L_Input(Varb0020) == 1 && Vrab07 == 0) Enchanted->Runtime2 = 0;
            Enchanted->Print_Text(Vrab08 + 353 - L_Rounding64(rxint64(Enchanted->Memory[1].Record_Address.size()) * 4.5), Vrab09 + 236, 1, Enchanted->Memory[1].Record_Address);
           } else
           {
            Enchanted->Print_Text(Vrab08 + 353 - L_Rounding64(rxint64(Enchanted->Memory[1].Record_Address.size()) * 4.5), Vrab09 + 236, 0, Enchanted->Memory[1].Record_Address);
           }
           if(Enchanted->Memory[1].Recording)
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[103], Vrab08 + 166, Vrab09 + 211);} else
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[104], Vrab08 + 166, Vrab09 + 211);}
           if(Enchanted->Memory[1].True_Recording)
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[103], Vrab08 + 519, Vrab09 + 211);} else
           {G_Set_Display(2, Enchanted->Pic_Index_Interface[104], Vrab08 + 519, Vrab09 + 211);}

           if(ruint8(Enchanted->Runtime1) != 0)
           {
            statics int1 Vrab10 = ((Enchanted->Tick % 20) / 10) == 0; int64 Vrab11 = 0, Vrab12 = 0, Vrab13 = 523, Vrab14 = 21;
            switch(ruint8(Enchanted->Runtime1))
            {
             case 1: Vrab11 = Vrab08 + 165; Vrab12 = Vrab09 + 36; break;
             case 3: Vrab11 = Vrab08 + 165; Vrab12 = Vrab09 + 138; break;
             case 4: Vrab11 = Vrab08 + 165; Vrab12 = Vrab09 + 210; Vrab13 = 21; break;
             case 8: Vrab11 = Vrab08 + 518; Vrab12 = Vrab09 + 210; Vrab13 = 21; break;
             case 5: Vrab11 = Vrab08 + 165; Vrab12 = Vrab09 + 235; Vrab13 = 374; break;
             case 2: Vrab11 = Vrab08 + 165; Vrab12 = Vrab09 + 61; Vrab13 = 523; Vrab14 = 73; break;
             case 6: Vrab11 = Vrab08 + 179; Vrab12 = Vrab09 + 260; Vrab13 = 346; Vrab14 = 25; break;
             case 7: Vrab11 = Vrab08 + 186; Vrab12 = Vrab09 + 295; Vrab13 = 153; Vrab14 = 28; break;
             case 9: Vrab11 = Vrab08 + 365; Vrab12 = Vrab09 + 295; Vrab13 = 153; Vrab14 = 28; break;
             default: break;
            }
            G_Set_Display(1, 0xFFFFFF, Vrab11, Vrab12, 0ui8, 255ui8, Vrab13, Vrab14); if(Vrab10) G_Set_Display(1, 0xFFFFFF, Vrab11 - 1, Vrab12 - 1, 0ui8, 255ui8, Vrab13 + 2, Vrab14 + 2);
           }
          }

          switch(Vrab07)
          {
           case 6: {statics string Temp01 = Enchanted->Memory[0].Address + Enchanted->Memory[1].Record_Address; if(L_Exist(Temp01)) ShellExecuteW(0, 0, std::wstring(Temp01.begin(), Temp01.end()).c_str(), 0, 0, SW_SHOW);} break;
           case 7: Enchanted->Memory[0] = Enchanted->Memory[1]; Enchanted->Save_Memory();
           case 9:
            if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(0);} else {Enchanted->Reset(252, 550, 121, 180);}
           break;
           default: break;
          }
          if(Vrab07 == 9){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]);} else
          {if(Vrab07 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);}
         }
        break;
        case 254: // Control Settings - Animation Phase
         {
          if(Enchanted->Runtime2 > 120)
          {if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; Enchanted->Runtime1 -= ((Enchanted->Runtime2 - 120) / 12); Enchanted->Runtime2 += 1;} else
          {if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 -= 1;}
          G_Set_Display(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);

          {
           statics int64 Vrab07 = Vrab03 - 352, Vrab08 = Vrab04 + 356 - (Enchanted->Runtime1);
           G_Set_Display(2, Enchanted->Pic_Index_Interface[28], Vrab07, Vrab08);
           for(uint64 Vrab09 = 0; Vrab09 < 4; ++Vrab09)
           {
            if(Enchanted->Memory[1].P_Name[Vrab09] == "") Enchanted->Memory[1].P_Name[Vrab09] = "P" + std::to_string(Vrab09 + 1);
            Enchanted->Print_Text(Vrab07 + 203 + (139 * Vrab09) - L_Rounding64(rxint64(Enchanted->Memory[1].P_Name[Vrab09].size()) * 4.5), Vrab08 + 35, 0, Enchanted->Memory[1].P_Name[Vrab09]);
            G_Set_Display(2, Enchanted->Pic_Index_Interface[29 + Enchanted->Memory[1].P_Con[Vrab09]], Vrab07 + 148 + (139 * Vrab09), Vrab08 + 61);
            uint64 Vrab10 = 0; if(Enchanted->Memory[1].P_Con[Vrab09] != 0) Vrab10 = 8;
            for(uint64 Vrab11 = Vrab10; Vrab11 < Vrab10 + 8; ++Vrab11)
            {
             statics string Temp01 = Enchanted->Input_Name(Enchanted->Memory[1].P_Input[Vrab09][Vrab11]);
             Enchanted->Print_Text(Vrab07 + 203 + (139 * Vrab09) - L_Rounding64(rxint64(Temp01.size()) * 4.5), Vrab08 + 159 + (22 * (Vrab11 - Vrab10)), 0, Temp01);
            }
           }
          }

          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(255);
          if(Enchanted->Runtime2 == 241) Enchanted->Reset(0, 0, 0, Enchanted->Runtime3);
         }
        break;
        case 255: // Control Settings
         {
          G_Set_Display(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06); uint8 Vrab07 = 0;

          if(Enchanted->Runtime2 == 0)
          {
           int1 Vrab08 = L_Input(Varb0021) == 1, Vrab09 = L_Input(Varb0023) == 1, Vrab10 = L_Input(Varb0022) == 1, Vrab11 = L_Input(Varb0024) == 1, Vrab12 = L_Input(Varb0020) == 1;
           if(!Vrab08){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab08 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][0]) == 1); if(Vrab08) break;}}
           if(!Vrab09){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab09 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][1]) == 1); if(Vrab09) break;}}
           if(!Vrab10){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab10 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][2]) == 1); if(Vrab10) break;}}
           if(!Vrab11){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab11 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][3]) == 1); if(Vrab11) break;}}
           if(!Vrab12){for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab12 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][4]) == 1); if(Vrab12) break;}}
           if(Vrab08 == Vrab09){Vrab08 = Vrab09 = false;}
           if(Vrab10 == Vrab11){Vrab10 = Vrab11 = false;}

           switch(ruint8(Enchanted->Runtime1))
           {
            case 1: case 2: case 3: if(Vrab08) Enchanted->Runtime1 = 41; if(Vrab09) Enchanted->Runtime1 += 4; break;
            case 4: if(Vrab08) Enchanted->Runtime1 = 42; if(Vrab09) Enchanted->Runtime1 += 4; break;
            case 37: if(Vrab08) Enchanted->Runtime1 -= 4; if(Vrab09) Enchanted->Runtime1 = 41; break;
            case 38: if(Vrab08) Enchanted->Runtime1 -= 4; if(Vrab09) Enchanted->Runtime1 = 41; break;
            case 39: if(Vrab08) Enchanted->Runtime1 -= 4; if(Vrab09) Enchanted->Runtime1 = 41; break;
            case 40: if(Vrab08) Enchanted->Runtime1 -= 4; if(Vrab09) Enchanted->Runtime1 = 42; break;
            case 0: case 41: if(Vrab08) Enchanted->Runtime1 = 39; if(Vrab09) Enchanted->Runtime1 = 3; break;
            case 42: if(Vrab08) Enchanted->Runtime1 = 40; if(Vrab09) Enchanted->Runtime1 = 4; break;
            default: if(Vrab08) Enchanted->Runtime1 -= 4; if(Vrab09) Enchanted->Runtime1 += 4; break;
           }
           switch(ruint8(Enchanted->Runtime1))
           {
            case 1: case 5: case 9: case 13: case 17: case 21: case 25: case 29: case 33: case 37: if(Vrab10) Enchanted->Runtime1 += 3; if(Vrab11) Enchanted->Runtime1 += 1; break;
            case 4: case 8: case 12: case 16: case 20: case 24: case 28: case 32: case 36: case 40: if(Vrab10) Enchanted->Runtime1 -= 1; if(Vrab11) Enchanted->Runtime1 -= 3; break;
            case 0: case 41: if(Vrab10 || Vrab11) Enchanted->Runtime1 = 42; break;
            case 42: if(Vrab10 || Vrab11) Enchanted->Runtime1 = 41; break;
            default: if(Vrab10) Enchanted->Runtime1 -= 1; if(Vrab11) Enchanted->Runtime1 += 1; break;
           }

           if(Vrab12)
           if(ruint8(Enchanted->Runtime1) > 0)
           {Vrab07 = ruint8(Enchanted->Runtime1);} else
           {Vrab07 = 41;}

           switch(Vrab07)
           {
            case 1: case 2: case 3: case 4: {statics uint64 Vrab13 = ruint64(Vrab07); if(Enchanted->Runtime2 == Vrab13){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = Vrab13;}} break;
            case 5: case 6: case 7: case 8: {Enchanted->Memory[1].P_Con[Vrab07 - 5] += 1; Enchanted->Memory[1].P_Con[Vrab07 - 5] %= 5;} break;
            case 0: case 41: case 42: break;
            default:
             {
              statics uint64 Vrab13 = ruint64(Vrab07 - 1) % 4, Vrab14 = ruint64(Vrab07 - 9) / 4, Vrab15 = (ruint64(Vrab13) * 8) + 5 + Vrab14;
              if(Enchanted->Runtime2 == Vrab15){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = Vrab15;}
             }
            break;
           }
          }

          {
           statics int64 Vrab08 = Vrab03 - 352, Vrab09 = Vrab04 - 194;
           G_Set_Display(2, Enchanted->Pic_Index_Interface[28], Vrab08, Vrab09);
           {statics int64 Vrab10 = Vrab08 + 368, Vrab11 = Vrab09 + 342; if(L_In(Vrab10, Vrab11, 151, 26)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[25], Vrab10, Vrab11); if(L_On(Vrab10, Vrab11, 151, 26)) Vrab07 = 41;}}
           {statics int64 Vrab10 = Vrab08 + 540, Vrab11 = Vrab09 + 342; if(L_In(Vrab10, Vrab11, 151, 26)){Enchanted->Draw = false; G_Set_Display(2, Enchanted->Pic_Index_Interface[27], Vrab10, Vrab11); if(L_On(Vrab10, Vrab11, 151, 26)) Vrab07 = 42;}}

           for(uint64 Vrab10 = 0; Vrab10 < 4; ++Vrab10)
           {
            if(L_In(Vrab08 + 148 + (139 * Vrab10), Vrab09 + 35, 106, 19))
            {
             Enchanted->Draw = false; if(L_On(Vrab08 + 148 + (139 * Vrab10), Vrab09 + 35, 106, 19))
             {statics auto Vrab11 = ruint64(Vrab10) + 1; if(Enchanted->Runtime2 == Vrab11){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = Vrab11;}}
            }
            if(L_In(Vrab08 + 148 + (139 * Vrab10), Vrab09 + 61, 106, 91))
            {
             Enchanted->Draw = false; if(L_On(Vrab08 + 148 + (139 * Vrab10), Vrab09 + 61, 106, 91))
             {Enchanted->Memory[1].P_Con[Vrab10] += 1; Enchanted->Memory[1].P_Con[Vrab10] %= 5;}
            }
        
            if(Enchanted->Runtime2 == ruint64(Vrab10) + 1)
            {
             if(Vrab07 == 0) L_Typing(Enchanted->Memory[1].P_Name[Vrab10]); if(Enchanted->Memory[1].P_Name[Vrab10].size() > 100) Enchanted->Memory[1].P_Name[Vrab10].resize(100); if(L_Input(Varb0020) == 1 && Vrab07 == 0) Enchanted->Runtime2 = 0;
             Enchanted->Print_Text(Vrab08 + 203 + (139 * Vrab10) - L_Rounding64(rxint64(Enchanted->Memory[1].P_Name[Vrab10].size()) * 4.5), Vrab09 + 35, 1, Enchanted->Memory[1].P_Name[Vrab10]);
            } else
            {
             if(Enchanted->Memory[1].P_Name[Vrab10] == "") Enchanted->Memory[1].P_Name[Vrab10] = "P" + std::to_string(Vrab10 + 1);
             Enchanted->Print_Text(Vrab08 + 203 + (139 * Vrab10) - L_Rounding64(rxint64(Enchanted->Memory[1].P_Name[Vrab10].size()) * 4.5), Vrab09 + 35, 0, Enchanted->Memory[1].P_Name[Vrab10]);
            }
            G_Set_Display(2, Enchanted->Pic_Index_Interface[29 + Enchanted->Memory[1].P_Con[Vrab10]], Vrab08 + 148 + (139 * Vrab10), Vrab09 + 61);
            uint64 Vrab11 = 0; if(Enchanted->Memory[1].P_Con[Vrab10] != 0) Vrab11 = 8;
            for(uint64 Vrab12 = Vrab11; Vrab12 < Vrab11 + 8; ++Vrab12)
            {
             if(L_In(Vrab08 + 148 + (139 * Vrab10), Vrab09 + 159 + (22 * (Vrab12 - Vrab11)), 106, 19))
             {
              Enchanted->Draw = false; if(L_On(Vrab08 + 148 + (139 * Vrab10), Vrab09 + 159 + (22 * (Vrab12 - Vrab11)), 106, 19) && Input.MOUS_Left_Release == 1)
              {statics auto Vrab13 = (ruint64(Vrab10) * 8) + 5 + (Vrab12 - Vrab11); if(Enchanted->Runtime2 == Vrab13){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = Vrab13;}}
             }
         
             statics string Temp01 = Enchanted->Input_Name(Enchanted->Memory[1].P_Input[Vrab10][Vrab12]);
             if(Enchanted->Runtime2 == (ruint64(Vrab10) * 8) + 5 + (Vrab12 - Vrab11))
             {
              statics uint8 Vrab13 = L_Press(); if(Vrab07 == 0) if(Vrab13 != 255ui8) if(Vrab13 != 0 || (Vrab13 == 0 && L_Input(Varb0020) == 1 && Vrab07 == 0)){Enchanted->Memory[1].P_Input[Vrab10][Vrab12] = Vrab13; Enchanted->Runtime2 = 0;}
              Enchanted->Print_Text(Vrab08 + 203 + (139 * Vrab10) - L_Rounding64(rxint64(Temp01.size()) * 4.5), Vrab09 + 159 + (22 * (Vrab12 - Vrab11)), 1, Temp01);
             } else {Enchanted->Print_Text(Vrab08 + 203 + (139 * Vrab10) - L_Rounding64(rxint64(Temp01.size()) * 4.5), Vrab09 + 159 + (22 * (Vrab12 - Vrab11)), 0, Temp01);}
            }
           }

           statics uint8 Vrab10 = ruint8(Enchanted->Runtime1); if(Vrab10 > 0)
           {
            statics int1 Vrab11 = ((Enchanted->Tick % 20) / 10) == 0;
            {
             int64 Vrab12 = 0, Vrab13 = 0, Vrab14 = 0, Vrab15 = 0;
             if(Vrab10 < 5 && Vrab10 != 0){Vrab12 = Vrab08 + 147 + (139 * rint64(Vrab10 - 1)); Vrab13 = Vrab09 + 34; Vrab14 = 108; Vrab15 = 21;}
             if(Vrab10 > 4 && Vrab10 <= 8){Vrab12 = Vrab08 + 147 + (139 * rint64(Vrab10 - 5)); Vrab13 = Vrab09 + 56; Vrab14 = 108; Vrab15 = 93;}
             if(Vrab10 > 8 && Vrab10 < 41){Vrab12 = Vrab08 + 147 + (139 * rint64((Vrab10 - 9) % 4)); Vrab13 = Vrab09 + 158 + (22 * rint64((Vrab10 - 9) / 4)); Vrab14 = 108; Vrab15 = 21;}
             if(Vrab10 > 40 && Vrab10 < 43){Vrab12 = Vrab08 + 367 + (172 * rint64(Vrab10 - 41)); Vrab13 = Vrab09 + 341; Vrab14 = 153; Vrab15 = 28;}
             G_Set_Display(1, 0xFFFFFF, Vrab12, Vrab13, 0ui8, 255ui8, Vrab14, Vrab15); if(Vrab11) G_Set_Display(1, 0xFFFFFF, Vrab12 - 1, Vrab13 - 1, 0ui8, 255ui8, Vrab14 + 2, Vrab15 + 2);
            }
           }
          }
          
          switch(Vrab07)
          {
           case 41: Enchanted->Memory[0] = Enchanted->Memory[1]; Enchanted->Save_Memory();
           case 42:
            if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(0);} else {Enchanted->Reset(254, 550, 121, 180);}
           break;
           default: break;
          }
          if(Vrab07 == 42){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]);} else
          {if(Vrab07 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);}
         }
        break;
        default: break;
       }
      }
     break;
     case 9: // Character Selection Menu
      {
       if(Enchanted->Memory[0].Meta_Selection)
       {
        // Inputs for interacts.
        int1 Vrab07 = L_Input(Varb0021) == 1, Vrab08 = L_Input(Varb0023) == 1, Vrab09 = L_Input(Varb0022) == 1, Vrab10 = L_Input(Varb0024) == 1, Vrab11 = L_Input(Varb0020) == 1, Vrab12 = L_Input(Varb0019) == 1;
        if(!Vrab07) for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab07 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][0]) == 1); if(Vrab07) break;} // Up
        if(!Vrab08) for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab08 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][1]) == 1); if(Vrab08) break;} // Down
        if(!Vrab09) for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab09 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][2]) == 1); if(Vrab09) break;} // Left
        if(!Vrab10) for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab10 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][3]) == 1); if(Vrab10) break;} // Right
        if(!Vrab11) for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab11 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][4]) == 1); if(Vrab11) break;} // Select
        if(!Vrab12) for(insize Vrab13 = 0; Vrab13 < 4; ++Vrab13){Vrab12 = (L_Input(Enchanted->Memory[0].P_Input[Vrab13][5]) == 1); if(Vrab12) break;} // Back

        // Positions, Menu, & Animation.
        uint8 Vrab13 = 0; int64 Vrab14 = 0, Vrab15 = 0;
        {
         uint64 Vrab16 = Enchanted->Runtime1, Vrab17 = (Vrab16 & 0xFFFF) >> 8, Vrab18 = (Vrab16 & 0xFFFFF) >> 16, Vrab19 = (Vrab16 & 0xFFFFFFFF) >> 20, Vrab20 = (Vrab16 & 0xFFFFFFFFFFF) >> 32, Vrab21 = (Vrab16 & 0xFFFFFFFFFFFFF) >> 44, Vrab22 = Vrab16 >> 52; Vrab16 = Vrab16 & 0xFF;

         Vrab13 = ruint8(Vrab18);
         if(Vrab16 >= Varb0004){Vrab16 -= Varb0004;} else {Vrab16 = 0;} Vrab14 = (Vrab13 == 1 ? 800 : 0) + ((Vrab13 == 1 ? -1 : 1) * L_Rounding64(((rxint64((Vrab16 * Vrab16) + Vrab16) / 2) / 32896) * rxint64(Vrab19)));
         if(Vrab17 >= Varb0004){Vrab17 -= Varb0004;} else {Vrab17 = 0;} Vrab15 = (Vrab13 == 2 ? 500 : 0) + ((Vrab13 == 2 ? -1 : 1) * L_Rounding64(((rxint64((Vrab17 * Vrab17) + Vrab17) / 2) / 32896) * rxint64(Vrab20)));

         switch(Vrab13)
         {
          case 0:
           switch(Enchanted->Runtime2)
           {
            case 0:
             if(Vrab11){Vrab18 = 1; Vrab16 = 0xFF; Vrab19 = 800 - Vrab14;}
             if(Vrab10){Vrab18 = 2; Vrab17 = 0xFF; Vrab20 = 500 - Vrab15;}
            break;
           }
          break;
          case 1:
           switch(Enchanted->Runtime2)
           {
            case 0:
             if(Vrab11){Vrab18 = 0; Vrab16 = 0xFF; Vrab19 = 800 - (800 - Vrab14);}
            break;
           }
          break;
          case 2:
           switch(Enchanted->Runtime2)
           {
            case 0:
             if(Vrab10){Vrab18 = 0; Vrab17 = 0xFF; Vrab20 = 500 - (500 - Vrab15);}
            break;
           }
          break;
          default: break;
         }
         
         Enchanted->Print_Text(3, 15, 0, std::to_string(Vrab16));
         Enchanted->Print_Text(3, 30, 0, std::to_string(Vrab17));
         Enchanted->Print_Text(3, 45, 0, std::to_string(Vrab18));
         Enchanted->Print_Text(3, 60, 0, std::to_string(Vrab19));
         Enchanted->Print_Text(3, 75, 0, std::to_string(Vrab20));
         Enchanted->Print_Text(3, 90, 0, std::to_string(Vrab21));

         Enchanted->Runtime1 = (Vrab16 & 0xFF) + ((Vrab17 & 0xFF) << 8) + ((Vrab18 & 0xF) << 16) + ((Vrab19 & 0xFFF) << 20) + ((Vrab20 & 0xFFF) << 32) + ((Vrab21 & 0xFF) << 44);
        }

        

        // Draw.
        G_Set_Display(2, Enchanted->Pic_Index_Interface[117], Vrab14 + Vrab05 - 1069, Vrab15 + Vrab04 - 162);
        Enchanted->Print_Menu(Vrab14 + Vrab03 - 300, Vrab15 + Vrab04 - 150, 600, 300);
        G_Set_Display(2, Enchanted->Pic_Index_Interface[118], Vrab14 + Vrab03 - 292, Vrab15 + Vrab04 - 140, 0ui8, 255ui8, 582, 282);
        G_Set_Display(2, Enchanted->Pic_Index_Interface[119], Vrab14 + Vrab03 - 290, Vrab15 + Vrab04 - 142, 0ui8, 255ui8, 582, 282);
        G_Set_Display(0, 0x0, Vrab14 + Vrab03 - 290, Vrab15 + Vrab04 - 140, 0ui8, 255ui8, 580, 280);
        //G_Set_Display(2, Enchanted->Pic_Index_Interface[117], Vrab14 + Vrab05 - 169, Vrab15 + Vrab04 - 162);
        G_Set_Display(2, Enchanted->Pic_Index_Interface[67], Vrab14 + 100, Vrab15 + Vrab06 - 768);


        if(Vrab12) if(Enchanted->Runtime3 == 30){Enchanted->Runtime3 = 31; Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]);}
       
       } else
       {
        statics int64 Vrab07 = Vrab03 - 372, Vrab08 = Vrab04 - 218; G_Set_Display(2, Enchanted->Pic_Index_Interface[41], Vrab07, Vrab08);

        if(Enchanted->Runtime1 == 0)
        {
         Enchanted->Select.resize(8); Enchanted->Select_Team.resize(8); Enchanted->Select_Character.resize(8);
         int1 Vrab09 = true;
         for(insize Vrab10 = 0; Vrab10 < 8; ++Vrab10) if(Enchanted->Select[Vrab10] > 0){Vrab09 = false; break;}
         if(Vrab09)
         {
          if(L_Input(Varb0020) == 1){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); Enchanted->Runtime1 = 1;}
          for(insize Vrab10 = 0; Vrab10 < 4; ++Vrab10)
          if(Enchanted->Runtime3 == 30) if(L_Input(Enchanted->Memory[0].P_Input[Vrab10][5]) == 1){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); Enchanted->Runtime3 = 31;}
         }
         if(Enchanted->Runtime1 == 0)
         for(insize Vrab10 = 0; Vrab10 < 4; ++Vrab10)
        {
         statics int1 Vrab11 = L_Input(Enchanted->Memory[0].P_Input[Vrab10][4]) == 1, Vrab12 = L_Input(Enchanted->Memory[0].P_Input[Vrab10][2]) == 1, Vrab13 = L_Input(Enchanted->Memory[0].P_Input[Vrab10][3]) == 1, Vrab14 = L_Input(Enchanted->Memory[0].P_Input[Vrab10][5]) == 1, Vrab17 = L_Input(Enchanted->Memory[0].P_Input[Vrab10][0]) == 1;
         if(Vrab11) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); if(Vrab14) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]);
         switch(Enchanted->Select[Vrab10])
         {
          case 0:
           if(Vrab11) Enchanted->Select[Vrab10] = ruint8(Vrab10) + 1;
          break;
          case 1: case 2: case 3: case 4:
           {
            insize Vrab15 = 0;
            switch(Enchanted->Memory[0].Engine)
            {
             case 1: break;
             default: Vrab15 = Enchanted->Engine1->Range(Enchanted->Hidden_Char); break;
            }
            if(Vrab11) Enchanted->Select[Vrab10] += 8; if(Vrab14) Enchanted->Select[Vrab10] = 0; if(Vrab17) Enchanted->Select_Character[Vrab10] = 0;
            if(Vrab12)
            {
             if(Enchanted->Select_Character[Vrab10] == 0) Enchanted->Select_Character[Vrab10] = Vrab15;
             uint8 Vrab16 = 0;
             while(Vrab16 != 1)
             {
              Enchanted->Select_Character[Vrab10] -= 1;
              if(Enchanted->Select_Character[Vrab10] == 0){Vrab16 = 1;} else
              {
               switch(Enchanted->Memory[0].Engine)
               {
                case 1: break;
                default: Vrab16 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab10] - 1, Enchanted->Hidden_Char); break;
               }
               if(Vrab16 == 2) Enchanted->Select_Character[Vrab10] = Vrab15 + 1;
              }
             }
            }
            if(Vrab13) if(Enchanted->Select_Character[Vrab10] == Vrab15){Enchanted->Select_Character[Vrab10] = 0;} else
            {
             uint8 Vrab16 = 0;
             while(Vrab16 != 1)
             {
              Enchanted->Select_Character[Vrab10] += 1;
              if(Enchanted->Select_Character[Vrab10] == 0){Vrab16 = 1;} else
              {
               switch(Enchanted->Memory[0].Engine)
               {
                case 1: break;
                default: Vrab16 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab10] - 1, Enchanted->Hidden_Char); break;
               }
               if(Vrab16 == 2) Enchanted->Select_Character[Vrab10] = rinsize(-1);
              }
             }
            }
           }
          break;
          case 9: case 10: case 11: case 12: if(Vrab11) if(Enchanted->Select_Character[Vrab10] == 0){Enchanted->Select[Vrab10] += 16;} else {Enchanted->Select[Vrab10] += 8;} if(Vrab14) Enchanted->Select[Vrab10] -= 8; if(Vrab12) if(Enchanted->Select_Team[Vrab10] == 0){Enchanted->Select_Team[Vrab10] = 5;} else {Enchanted->Select_Team[Vrab10] -= 1;} if(Vrab13) if(Enchanted->Select_Team[Vrab10] == 5){Enchanted->Select_Team[Vrab10] = 0;} else {Enchanted->Select_Team[Vrab10] += 1;} break;
          default: if(Vrab14) if(Enchanted->Select[Vrab10] >= 25){Enchanted->Select[Vrab10] -= 16;} else {Enchanted->Select[Vrab10] -= 8;} break;
         }
        }
         insize Vrab10 = 0, Vrab11 = 0, Vrab12 = Enchanted->Select.size();
         while(Vrab10 < Vrab12){if(Enchanted->Select[Vrab10] != 0){if(Enchanted->Select[Vrab10] < 17) break;} else {Vrab11 += 1;} Vrab10 += 1;}
         if(Vrab10 == Vrab12 && Vrab11 != Vrab12) Enchanted->Runtime1 = 1;
        }

        if(Enchanted->Runtime1 >= 1 && Enchanted->Runtime1 <= 601)
        {
         Enchanted->Runtime1 += 1;
         for(insize Vrab09 = 0; Vrab09 < 4; ++Vrab09)
         {
          statics int1 Vrab10 = L_Input(Enchanted->Memory[0].P_Input[Vrab09][4]) == 1, Vrab11 = L_Input(Enchanted->Memory[0].P_Input[Vrab09][5]) == 1;
          if(Enchanted->Runtime1 >= 3) if(Vrab11) if(Enchanted->Runtime1 + 120 > 602){Enchanted->Runtime1 = 602;} else {Enchanted->Runtime1 += 120;}
          if(Vrab10) if(Enchanted->Select[Vrab09] == 0){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); Enchanted->Select[Vrab09] = ruint8(Vrab09) + 1; Enchanted->Runtime1 = 0;}
         }
        }
       
        if(Enchanted->Runtime1 <= 602 || Enchanted->Runtime1 >= 604) if(L_Input(Varb0019) == 1 && Enchanted->Runtime3 == 30){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); Enchanted->Runtime3 = 31;}

        if(Enchanted->Runtime1 == 603)
        {
         int1 Vrab09 = L_Input(Varb0022) == 1, Vrab10 = L_Input(Varb0024) == 1, Vrab11 = L_Input(Varb0021) == 1, Vrab12 = L_Input(Varb0020) == 1, Vrab13 = L_Input(Varb0019) == 1;
         if(!Vrab09){for(insize Vrab14 = 0; Vrab14 < 4; ++Vrab14){Vrab09 = (L_Input(Enchanted->Memory[0].P_Input[Vrab14][2]) == 1); if(Vrab09) break;}}
         if(!Vrab10){for(insize Vrab14 = 0; Vrab14 < 4; ++Vrab14){Vrab10 = (L_Input(Enchanted->Memory[0].P_Input[Vrab14][3]) == 1); if(Vrab10) break;}}
         if(!Vrab11){for(insize Vrab14 = 0; Vrab14 < 4; ++Vrab14){Vrab11 = (L_Input(Enchanted->Memory[0].P_Input[Vrab14][0]) == 1); if(Vrab11) break;}}
         if(!Vrab12){for(insize Vrab14 = 0; Vrab14 < 4; ++Vrab14){Vrab12 = (L_Input(Enchanted->Memory[0].P_Input[Vrab14][4]) == 1); if(Vrab12) break;}}
         if(!Vrab13){for(insize Vrab14 = 0; Vrab14 < 4; ++Vrab14){Vrab13 = (L_Input(Enchanted->Memory[0].P_Input[Vrab14][5]) == 1); if(Vrab13) break;}}
         insize Vrab14 = 0; while(Vrab14 < Enchanted->Select.size())
         {
          uint8 Vrab15 = Enchanted->Select[Vrab14];
          if(Vrab15 >= 34 && Vrab15 < 37)
          {
           if(Vrab15 == 34) Enchanted->Select[Vrab14] = 35;
           switch(Vrab15)
           {
            case 34: case 35:
             {
              if(Vrab12){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); Enchanted->Select[Vrab14] += 1;}
              if(Vrab13)
              {
               Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]);
               Enchanted->Select[Vrab14] = 34;
               insize Vrab16 = Enchanted->Select.size(); int1 Vrab17 = true;
               while(Vrab16 != 0)
               {
                Vrab16 -= 1;
                if(Enchanted->Select[Vrab16] >= 37){Vrab17 = false; Enchanted->Select[Vrab16] = 36; break;}
               }
               if(Vrab17){Enchanted->Runtime1 = 602; for(insize Vrab18 = 0; Vrab18 < 8; ++Vrab18) if(Enchanted->Select[Vrab18] == 34) Enchanted->Select[Vrab18] = 0; Vrab14 = 0;} break;
              }
              insize Vrab16 = 0;
              switch(Enchanted->Memory[0].Engine)
              {
               case 1: break;
               default: Vrab16 = Enchanted->Engine1->Range(Enchanted->Hidden_Char); break;
              }
              if(Vrab11) Enchanted->Select_Character[Vrab14] = 0;
              if(Vrab09)
              {
               if(Enchanted->Select_Character[Vrab14] == 0) Enchanted->Select_Character[Vrab14] = Vrab16;
               uint8 Vrab17 = 0;
               while(Vrab17 != 1)
               {
                Enchanted->Select_Character[Vrab14] -= 1; if(Enchanted->Select_Character[Vrab14] == 0){Vrab17 = 1;} else
                {
                 switch(Enchanted->Memory[0].Engine)
                 {
                  case 1: break;
                  default: Vrab17 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab14] - 1, Enchanted->Hidden_Char); break;
                 }
                 if(Vrab17 == 2) Enchanted->Select_Character[Vrab14] = Vrab16 + 1;
                }
               }
              }
              if(Vrab10) if(Enchanted->Select_Character[Vrab14] == Vrab16){Enchanted->Select_Character[Vrab14] = 0;} else
              {
               uint8 Vrab17 = 0;
               while(Vrab17 != 1)
               {
                Enchanted->Select_Character[Vrab14] += 1; if(Enchanted->Select_Character[Vrab14] == 0){Vrab17 = 1;} else
                {
                 switch(Enchanted->Memory[0].Engine)
                 {
                  case 1: break;
                  default: Vrab17 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab14] - 1, Enchanted->Hidden_Char); break;
                 }
                 if(Vrab17 == 2) Enchanted->Select_Character[Vrab14] = rinsize(-1);
                }
               }
              }
             }
            break;
            case 36:
            {
             if(Vrab13){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); Enchanted->Select[Vrab14] -= 1;}
             if(Vrab12){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); if(Enchanted->Select_Character[Vrab14] == 0){Enchanted->Select[Vrab14] = 38;} else {Enchanted->Select[Vrab14] = 37;}}
             uint8 Vrab16 = 254ui8; 
             {insize Vrab17 = Enchanted->Select.size(); while(Vrab17 != 0){Vrab17 -= 1; if(Enchanted->Select[Vrab17] >= 34) if(Vrab17 == Vrab14){Vrab16 = 255ui8; break;} else {break;}}}
             if(Vrab16 == 255ui8) for(insize Vrab17 = 0; Vrab17 < Enchanted->Select.size(); ++Vrab17) if(Vrab17 != Vrab14) if(Enchanted->Select[Vrab17] != 0 && Enchanted->Select[Vrab17] != 34) if(Vrab16 == 255ui8){if(Enchanted->Select_Team[Vrab17] == 0){Vrab16 = 254ui8; break;} Vrab16 = Enchanted->Select_Team[Vrab17];} else {if(Enchanted->Select_Team[Vrab17] != Vrab16){Vrab16 = 254ui8; break;}}
             if(Enchanted->Select_Team[Vrab14] == Vrab16) Enchanted->Select_Team[Vrab14] = 0;
             if(Vrab09) if(Enchanted->Select_Team[Vrab14] == 0){if(Vrab16 == 5){Enchanted->Select_Team[Vrab14] = 4;} else {Enchanted->Select_Team[Vrab14] = 5;}} else {Enchanted->Select_Team[Vrab14] -= 1; if(Enchanted->Select_Team[Vrab14] == Vrab16) Enchanted->Select_Team[Vrab14] -= 1;}
             if(Vrab10) if(Enchanted->Select_Team[Vrab14] == 5){Enchanted->Select_Team[Vrab14] = 0;} else {Enchanted->Select_Team[Vrab14] += 1; if(Enchanted->Select_Team[Vrab14] == Vrab16) if(Vrab16 == 5){Enchanted->Select_Team[Vrab14] = 0;} else {Enchanted->Select_Team[Vrab14] += 1;}}
            }
            break;
            default: break;
           }
           break;
          }
          Vrab14 += 1;
         }
         if(Vrab14 == 8) Enchanted->Runtime1 = 604;
        }

        {
         for(insize Vrab10 = 0; Vrab10 < Enchanted->Select.size() / 2; ++Vrab10)
         for(insize Vrab11 = 0; Vrab11 < 2; ++Vrab11)
         {
          insize Vrab12 = rinsize(-1); int64 Vrab13 = 0; int8 Vrab14 = ruint8((Enchanted->Tick % 20) / 10), Vrab15 = Vrab14, Vrab16 = Vrab14; statics int64 Vrab17 = rint64(Vrab10) * 153, Vrab18 = rint64(Vrab11) * 212; string Temp01, Temp02, Temp03;
          statics uint8 Vrab19 = Enchanted->Select[Vrab10 + (4 * Vrab11)]; statics insize Vrab20 = Enchanted->Select_Character[Vrab10 + (4 * Vrab11)]; int64 Vrab21 = 0;
          if(Vrab19 == 0 || Vrab19 == 34)
          {
           if(Enchanted->Runtime1 == 0)
           {
            Vrab12 = Enchanted->Pic_Index_Interface[42 + rinsize((Enchanted->Tick % 20) / 10)]; Vrab13 = 27; Temp01 = "Join?";
           } else
           {
            if(Enchanted->Runtime1 <= 602)
            {
             if(Enchanted->Runtime1 <= 601) Vrab12 = Enchanted->Pic_Index_Interface[45 + rinsize((Enchanted->Runtime1 - 2) / 120)];
             Vrab13 = 32; Vrab21 = 35; Temp01 = "-";
            } else
            {
             if(Vrab19 == 34){Temp01 = "Computer";} else {Temp01 = "-";}
            }
            Vrab14 = 0;
           }
          } else
          {
           Vrab14 = 0;
           if(Vrab19 <= 33){if(((Vrab19 - 1) % 8) < 4) Temp01 = Enchanted->Memory[0].P_Name[rinsize((Vrab19 - 1) % 8)];} else {Temp01 = "Computer";}
           if(Vrab20 == 0)
           {
            Vrab12 = Enchanted->Pic_Index_Interface[44]; Temp02 = "Random";
           } else
           {
            switch(Enchanted->Memory[0].Engine)
            {
             case 1: break;
             default: statics insize Vrab22 = Enchanted->Select_Character[Vrab10 + (4 * Vrab11)] - 1; Vrab12 = Enchanted->Engine1->Face(Vrab22); Temp02 = Enchanted->Engine1->Name(Vrab22); break;
            }
           }
           if((Vrab19 >= 9 && Vrab19 < 33) || (Vrab19 >= 36 && Vrab19 <= 38))
           {
            Vrab15 = 0; switch(Enchanted->Select_Team[Vrab10 + (4 * Vrab11)])
            {
             case 1: Temp03 = "Team 1"; break;
             case 2: Temp03 = "Team 2"; break;
             case 3: Temp03 = "Team 3"; break;
             case 4: Temp03 = "Team 4"; break;
             case 5: Temp03 = "Team 5"; break;
             default: Temp03 = "Independent"; break;
            }
           }
           if((Vrab19 >= 17 && Vrab19 < 33) || (Vrab19 == 37 || Vrab19 == 38)){Vrab16 = 0;}
          }
 
          G_Set_Display(2, Vrab12, Vrab07 + 107 + Vrab21 + Vrab17, Vrab08 + 19 + Vrab13 + Vrab18);
          Enchanted->Print_Text(Vrab07 + 169 + Vrab17 - L_Rounding64(rxint64(Temp01.size()) * 4.5), Vrab08 + 143 + Vrab18, Vrab14, Temp01);
          Enchanted->Print_Text(Vrab07 + 169 + Vrab17 - L_Rounding64(rxint64(Temp02.size()) * 4.5), Vrab08 + 165 + Vrab18, Vrab15, Temp02);
          Enchanted->Print_Text(Vrab07 + 169 + Vrab17 - L_Rounding64(rxint64(Temp03.size()) * 4.5), Vrab08 + 187 + Vrab18, Vrab16, Temp03);
         }
        }

        if(Enchanted->Runtime1 >= 605)
        {
         if(Enchanted->Runtime1 < 896){Enchanted->Runtime1 += 1; statics uint64 Vrab09 = Enchanted->Runtime1; if(Vrab09 >= 785 && Vrab09 < 845){Enchanted->Runtime2 += (Vrab09 - 785) / 12;} if(Vrab09 >= 845 && Vrab09 < 905){Enchanted->Runtime2 += (60 - (Vrab09 - 845)) / 12;}  if(Vrab09 >= 894) Enchanted->Runtime2 += 1;}
         statics int64 Vrab09 = Vrab03 - 394 - rint64(Enchanted->Runtime2 % 1000), Vrab10 = Vrab04 + 51;
         int1 Vrab11 = L_Input(Varb0021) == 1, Vrab12 = L_Input(Varb0023) == 1, Vrab13 = L_Input(Varb0020) == 1, Vrab14 = L_Input(Varb0022) == 1, Vrab15 = L_Input(Varb0024) == 1, Vrab16 = false;
         if(!Vrab11){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab11 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][0]) == 1); if(Vrab11) break;}}
         if(!Vrab12){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab12 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][1]) == 1); if(Vrab12) break;}}
         if(!Vrab13){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab13 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][4]) == 1); if(Vrab13) break;}}
         if(!Vrab14){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab14 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][2]) == 1); if(Vrab14) break;}}
         if(!Vrab15){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab15 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][3]) == 1); if(Vrab15) break;}}
                     for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab16 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][5]) == 1); if(Vrab16) break;}
         if(Vrab11 || Vrab12 || Vrab13){Enchanted->Runtime1 = 605; Enchanted->Runtime2 -= Enchanted->Runtime2 % 1000;}
 
         int64 Vrab17 = Enchanted->Runtime2 / 1000;
         if(Vrab11) if(Vrab17 == 0){Vrab17 = 5;} else {Vrab17 -= 1;}
         if(Vrab12) if(Vrab17 == 5){Vrab17 = 0;} else {Vrab17 += 1;}
         if(Vrab13) if(Vrab17 < 5) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);
         if(Vrab13) switch(ruint8(Vrab17))
         {
          case 0: Enchanted->Runtime1 = 900; if(Enchanted->Runtime3 == 30) Enchanted->Runtime3 = 31; break;
          case 1: case 2: if(Vrab17 == 1){Enchanted->Runtime1 = 0;} else {Enchanted->Runtime1 = 604;}
           for(insize Vrab18 = 0; Vrab18 < 8; ++Vrab18){if((Enchanted->Select[Vrab18] >= 25 && Enchanted->Select[Vrab18] <= 33) || Enchanted->Select[Vrab18] == 38) Enchanted->Select_Character[Vrab18] = 0; if(Vrab17 == 1) Enchanted->Select[Vrab18] = 0;}
          break;
          case 3: {insize Vrab18 = 0; switch(Enchanted->Memory[0].Engine){case 1: break; default: Vrab18 = Enchanted->Engine1->Limit(); break;} if(Enchanted->Select_Background == Vrab18){Enchanted->Select_Background = 0;} else {Enchanted->Select_Background += 1;}} break;
          case 4: if(Enchanted->Select_Difficult == 3){Enchanted->Select_Difficult = 0;} else {Enchanted->Select_Difficult += 1;} break;
          default: Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); if(Enchanted->Runtime3 == 30) Enchanted->Runtime3 = 31; break;
         }
         Enchanted->Runtime2 = (Enchanted->Runtime2 % 1000) + (Vrab17 * 1000);
         string Temp01;
         if(Enchanted->Select_Background == 0){Temp01 = "Random";} else
         {
          switch(Enchanted->Memory[0].Engine)
          {
           case 1: break;
           default: Temp01 = Enchanted->Engine1->Place(Enchanted->Select_Background - 1); break;
          }
         }
         if(Temp01.size() > 14) Temp01.resize(14);
         G_Set_Display(0, 0x0, Vrab09 + 124, Vrab10 + 87, 0, 255ui8, 122, 16); G_Set_Display(0, 0x0, Vrab09 + 124, Vrab10 + 111, 0, 255ui8, 100, 16);
         Enchanted->Print_Text(Vrab09 + 127, Vrab10 + 86, 0, L_Revoke(Temp01, '_', ' '));
         Enchanted->Print_Text(Vrab09 + 127, Vrab10 + 110, 0, Enchanted->Difficult(Enchanted->Select_Difficult));
         G_Set_Display(2, Enchanted->Pic_Index_Interface[67], Vrab09, Vrab10);
         G_Set_Display(1, 0xFFFFFF, Vrab09 + 13, Vrab10 + 13 + (24 * Vrab17), 0, 255ui8, 238, 20); if((Enchanted->Tick % 20) / 10 == 0) G_Set_Display(1, 0xFFFFFF, Vrab09 + 12, Vrab10 + 12 + (24 * Vrab17), 0, 255ui8, 240, 22);
        }
 
        if(Enchanted->Runtime1 == 604)
        {
         std::vector < insize > Vect01;
         switch(Enchanted->Memory[0].Engine)
         {
          case 1: break;
          default: {statics insize Vrab09 = Enchanted->Engine1->Range(); insize Vrab10 = 0; while(Vrab10 < Vrab09){if(Enchanted->Engine1->Random(Vrab10)) Vect01.push_back(Vrab10); Vrab10 += 1;}} break;
         }
         statics auto Vect02 = Vect01;
         for(insize Vrab09 = 0; Vrab09 < 8; ++Vrab09) if(Enchanted->Select[Vrab09] > 0){statics insize Vrab10 = Enchanted->Select_Character[Vrab09]; if(Vrab10 > 0){insize Vrab11 = Vect01.size(); while(Vrab11 != 0){Vrab11 -= 1; if((Vrab10 - 1) == Vect01[Vrab11]){Vect01.erase(Vect01.begin() + Vrab11); break;}}}}
         for(insize Vrab09 = 0; Vrab09 < 8; ++Vrab09) if(Enchanted->Select[Vrab09] > 0) if(Enchanted->Select_Character[Vrab09] == 0) {insize Vrab11 = Vect01.size(); if(Vrab11 == 0){Vect01 = Vect02; Vrab11 = Vect01.size();} statics insize Vrab12 = rinsize(L_Random(ruint64(Vrab11) - 1)); Enchanted->Select_Character[Vrab09] = Vect01[Vrab12] + 1; Vect01.erase(Vect01.begin() + Vrab12);}
         Enchanted->Runtime1 = 605; Enchanted->Runtime2 -= Enchanted->Runtime2 % 1000;
        }

        if(Enchanted->Runtime1 == 602)
        {
         statics int64 Vrab09 = Vrab03 - 152, Vrab10 = Vrab04 - 44;
         G_Set_Display(2, Enchanted->Pic_Index_Interface[50], Vrab09, Vrab10);
         insize Vrab11 = 0, Vrab12 = 0;
         for(insize Vrab13 = 0; Vrab13 < 8; ++Vrab13) if(Enchanted->Select[Vrab13] == 0) Vrab11 += 1;
         statics int1 Vrab16 = (Vrab11 == 8); if(Vrab16)
         {
          for(insize Vrab13 = 0; Vrab13 < 6; ++Vrab13)
          {G_Set_Display(2, Enchanted->Pic_Index_Interface[61 + Vrab13], Vrab09 + 73 + (rint64(Vrab13) * 30), Vrab10 + 53);}
          G_Set_Display(2, Enchanted->Pic_Index_Interface[52], Vrab09 + 43, Vrab10 + 53);
          G_Set_Display(2, Enchanted->Pic_Index_Interface[107], Vrab09 + 253, Vrab10 + 53); Vrab12 = 1;
         } else
         {
          {
           uint8 Vrab13 = 254ui8;
           for(insize Vrab14 = 0; Vrab14 < 8; ++Vrab14)
           {if(Enchanted->Select[Vrab14] > 0) if(Vrab13 == 254ui8){Vrab13 = Enchanted->Select_Team[Vrab14];} else {if(Vrab13 != Enchanted->Select_Team[Vrab14]) Vrab13 = 255ui8;}}
           if(Vrab13 > 0 && Vrab13 != 255ui8) Vrab12 = 1;
           if(Vrab11 == 7) Vrab12 = 1;
          }
          for(insize Vrab13 = 0; Vrab13 < 8; ++Vrab13)
          {insize Vrab14 = 0; if(Vrab13 < Vrab12 || Vrab13 > Vrab11) Vrab14 = 8; G_Set_Display(2, Enchanted->Pic_Index_Interface[59 + Vrab13 - Vrab14], Vrab09 + 43 + (rint64(Vrab13) * 30), Vrab10 + 53);}
          Vrab11 += 1;
         }
 
         int1 Vrab13 = L_Input(Varb0022) == 1, Vrab14 = L_Input(Varb0024) == 1, Vrab15 = L_Input(Varb0020) == 1;
         if(!Vrab13){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab13 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][2]) == 1); if(Vrab13) break;}}
         if(!Vrab14){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab14 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][3]) == 1); if(Vrab14) break;}}
         if(!Vrab15){for(insize Vrab17 = 0; Vrab17 < 4; ++Vrab17){Vrab15 = (L_Input(Enchanted->Memory[0].P_Input[Vrab17][4]) == 1); if(Vrab15) break;}}

         if(Enchanted->Runtime2 < Vrab12 || Enchanted->Runtime2 > Vrab11) Enchanted->Runtime2 = Vrab12;
         if(Vrab13){Enchanted->Runtime2 -= 1; if(Enchanted->Runtime2 == ruint64(-1) || Enchanted->Runtime2 < Vrab12) Enchanted->Runtime2 = Vrab11 - 1;}
         if(Vrab14){Enchanted->Runtime2 += 1; if(Enchanted->Runtime2 >= Vrab11) Enchanted->Runtime2 = Vrab12;}

         if(Vrab15)
         {
          Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);
          insize Vrab17 = 0; if(Vrab16) Vrab17 = 1;
          Vrab17 += rinsize(Enchanted->Runtime2); insize Vrab18 = 0;
          while(Vrab17 != 0)
          {
           if(Enchanted->Select[Vrab18] == 0){Vrab17 -= 1; Enchanted->Select[Vrab18] = 34;}
           Vrab18 += 1;
          }
          Enchanted->Runtime1 = 603;
         }
 
         G_Set_Display(1, 0xFFFFFF, Vrab09 + 38 + (rint64(Enchanted->Runtime2) * 30), Vrab10 + 48, 0, 255ui8, 16, 20); if((Enchanted->Tick % 20) / 10 == 0) G_Set_Display(1, 0xFFFFFF, Vrab09 + 37 + (rint64(Enchanted->Runtime2) * 30), Vrab10 + 47, 0, 255ui8, 18, 22);
        }
       }

       if(Enchanted->Runtime3 < 30)
       {
        G_Set_Display(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(30 - Enchanted->Runtime3) / 30) * 255.0)), Vrab05, Vrab06);
        Enchanted->Runtime3 += 1;
       }
       if(Enchanted->Runtime3 > 30)
       {
        G_Set_Display(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(Enchanted->Runtime3 - 30) / 30) * 255.0)), Vrab05, Vrab06);
        Enchanted->Runtime3 += 1;
       }
       if(Enchanted->Runtime3 == 60) if(Enchanted->Runtime1 == 900)
       {Enchanted->Reset(10);} else
       {
        Enchanted->Reset(8, 9);
        if(Enchanted->Back_Index_Interface.size() > 0)
        {
         statics insize Vrab07 = rinsize(L_Random(Enchanted->Back_Index_Interface.size() - 1));
         Enchanted->Background1 = Enchanted->Back_Index_Interface[Vrab07];
         Enchanted->Background2 = Enchanted->Back_Index_Interface_Type[Vrab07];
        }
        if(Enchanted->Memory[0].Meta_Selection){} else {for(insize Vrab09 = 0; Vrab09 < 8; ++Vrab09) if((Enchanted->Select[Vrab09] >= 25 && Enchanted->Select[Vrab09] <= 33) || Enchanted->Select[Vrab09] == 38) Enchanted->Select_Character[Vrab09] = 0; Enchanted->Select.clear();}
       }
      }
     break;
     case 10: // In-game 
      {
       // Initialization.
       {
        if(Enchanted->Runtime1 == 0)
        {
         Varb0016 = false; insize Vrab07 = Enchanted->Select_Background; if(Vrab07 > 0){Vrab07 -= 1;} else {switch(Enchanted->Memory[0].Engine){case 1: break; default: Vrab07 = rinsize(L_Random(Enchanted->Engine1->Limit() - 1)); break;}}
         statics insize Vrab08 = Enchanted->Select.size();
         switch(Enchanted->Memory[0].Engine)
         {
          case 1: break;
          default:
           {
            // Main Initialization.
            Enchanted->Engine1->Start(Enchanted->Select_Mode, Vrab07, Enchanted->Select_Difficult, Enchanted->Memory[0].Max_Object);

            // Player Initialization.
            for(insize Vrab09 = 0; Vrab09 < Vrab08; ++Vrab09)
            if(Enchanted->Select[Vrab09] > 0 && Enchanted->Select[Vrab09] <= 33)
            {
             statics uint8 Vrab10 = (Enchanted->Select[Vrab09] - 1) % 8;
             Enchanted->Engine1->Set(Vrab10, Enchanted->Select_Character[Vrab09] - 1, Enchanted->Select_Team[Vrab09], Enchanted->Memory[0].P_Name[rinsize(Vrab10)]);
            }

            // Computer Initialization.
            for(insize Vrab09 = 0; Vrab09 < Vrab08; ++Vrab09)
            if(Enchanted->Select[Vrab09] > 34 && Enchanted->Select[Vrab09] <= 38)
            {
             Enchanted->Engine1->Set(ruint8(Vrab09) + 8, Enchanted->Select_Character[Vrab09] - 1, Enchanted->Select_Team[Vrab09], "Com");
            }
           } 
          break;
         }
        }
       }
       
       // Progressive.
       {
        // FPS.
        switch(Enchanted->Memory[0].Engine){case 1: break; default: Varb0004 = Enchanted->Engine1->Frame(); break;}

        // Draw's Values.
        std::vector < HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW > Vect01;
        std::vector < HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW > Vect02;
        std::vector < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW > Vect03;

        // Player's Input & "HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW" Initialization.
        {
         switch(Enchanted->Memory[0].Engine)
         {
          case 1: break;
          default:
           {
            for(insize Vrab07 = 0; Vrab07 < 4; ++Vrab07) Enchanted->Engine1->Input(ruint8(Vrab07), L_Input(Enchanted->Memory[0].P_Input[Vrab07][0]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][1]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][2]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][3]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][4]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][5]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][6]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][7]) > 0);
            Vect01 = Enchanted->Engine1->Run(L_Input(Enchanted->Memory[0].F1) == 1, L_Input(Enchanted->Memory[0].F2) == 1, L_Input(Enchanted->Memory[0].F3) == 1, L_Input(Enchanted->Memory[0].F4) == 1, L_Input(Enchanted->Memory[0].F5) == 1, L_Input(Enchanted->Memory[0].F6) == 1, L_Input(Enchanted->Memory[0].F7) == 1, L_Input(Enchanted->Memory[0].F8) == 1, L_Input(Enchanted->Memory[0].F9) == 1);
           }
          break;
         }
        }

        // Sound Effects, Camera's Positioning, "HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW" Initialization, "HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW" Initialization.
        {
         insize Vrab07 = 0;
         
         // Sound Effects.
         {
          insize Vrab08 = Vect01.size(); while(Vrab08 != 0){Vrab08 -= 1; if(Vect01[Vrab08].Sound == 0){Vrab07 += 1;} else {Enchanted->Play_Sound(Vect01[Vrab08].Sound);}}
         }

         // Camera's Positioning, "HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW" Initialization, "HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW" Initialization.
         {
          // Target.
          xint64 Vrab08 = 0; xint64 Vrab09 = 0;

          if(Vrab07 == 0)
          {
          
          } else
          {
           // Target Position.
           {
            insize Vrab10 = Vect01.size();
            while(Vrab10 != 0)
            {Vrab10 -= 1; if(Vect01[Vrab10].Sound == 0){Vrab08 += Vect01[Vrab10].X; Vrab09 += Vect01[Vrab10].Z + Vect01[Vrab10].Y;}}
            Vrab08 /= rxint64(Vrab07); Vrab09 /= rxint64(Vrab07);
           }
          }

          // Actual Position.
          {
           int1 Vrab10 = Enchanted->Runtime1 == 0; if(Vrab10){Enchanted->CameraY_Post = 0; Enchanted->CameraY_Acceleration = 0.0;}
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: if(Enchanted->Engine1->Reset()) Vrab10 = true; break;
           }

           if(Vrab10){Enchanted->CameraX_Acceleration = 0.0;} else
           {
            // X-Camera Acceleration.
            {
             xint64 Vrab11 = (((Vrab08 - Enchanted->CameraX_Post) / 23.0) / 16.0) * rxint64(Varb0004), Vrab12 = ((Vrab11 / 3.0) / 16.0) * rxint64(Varb0004), Vrab13 = ((Vrab11 / 16.0) / 16.0) * rxint64(Varb0004);
 
             if(Vrab11 != 0)
             if(Vrab11 < 0)
             {
              if(Vrab11 > -0.05) Vrab11 = -0.05;
              if(Enchanted->CameraX_Acceleration < Vrab11)
              {if(Enchanted->CameraX_Acceleration - Vrab13 < Vrab11){Enchanted->CameraX_Acceleration -= Vrab13;} else {Enchanted->CameraX_Acceleration = Vrab11;}} else
              {if(Enchanted->CameraX_Acceleration + Vrab12 > Vrab11){Enchanted->CameraX_Acceleration += Vrab12;} else {Enchanted->CameraX_Acceleration = Vrab11;}}
              if(Vrab11 == -0.05) if(Enchanted->CameraX_Post + Enchanted->CameraX_Acceleration < Vrab08){Enchanted->CameraX_Post = Vrab08; Enchanted->CameraX_Acceleration = 0;}
             } else
             {
              if(Vrab11 < 0.05) Vrab11 = 0.05;
              if(Enchanted->CameraX_Acceleration > Vrab11)
              {if(Enchanted->CameraX_Acceleration - Vrab13 > Vrab11){Enchanted->CameraX_Acceleration -= Vrab13;} else {Enchanted->CameraX_Acceleration = Vrab11;}} else
              {if(Enchanted->CameraX_Acceleration + Vrab12 < Vrab11){Enchanted->CameraX_Acceleration += Vrab12;} else {Enchanted->CameraX_Acceleration = Vrab11;}}
              if(Vrab11 == 0.05) if(Enchanted->CameraX_Post + Enchanted->CameraX_Acceleration > Vrab08){Enchanted->CameraX_Post = Vrab08; Enchanted->CameraX_Acceleration = 0;}
             }
            }

            Vrab08 = Enchanted->CameraX_Post + Enchanted->CameraX_Acceleration;
           }
            
           // Y-Camera Acceleration.
           {
            xint64 Vrab11 = (((Vrab09 - Enchanted->CameraY_Post) / 9.0) / 16.0) * rxint64(Varb0004), Vrab12 = ((Vrab11 / 3.0) / 16.0) * rxint64(Varb0004), Vrab13 = ((Vrab11 / 16.0) / 16.0) * rxint64(Varb0004);
             
            if(Vrab11 != 0)
            if(Vrab11 < 0)
            {
             if(Vrab11 > -0.05) Vrab11 = -0.05;
             if(Enchanted->CameraY_Acceleration < Vrab11)
             {if(Enchanted->CameraY_Acceleration - Vrab13 < Vrab11){Enchanted->CameraY_Acceleration -= Vrab13;} else {Enchanted->CameraY_Acceleration = Vrab11;}} else
             {if(Enchanted->CameraY_Acceleration + Vrab12 > Vrab11){Enchanted->CameraY_Acceleration += Vrab12;} else {Enchanted->CameraY_Acceleration = Vrab11;}}
             if(Vrab11 == -0.05) if(Enchanted->CameraY_Post + Enchanted->CameraY_Acceleration < Vrab09){Enchanted->CameraY_Post = Vrab09; Enchanted->CameraY_Acceleration = 0;}
            } else
            {
             if(Vrab11 < 0.05) Vrab11 = 0.05;
             if(Enchanted->CameraY_Acceleration > Vrab11)
             {if(Enchanted->CameraY_Acceleration - Vrab13 > Vrab11){Enchanted->CameraY_Acceleration -= Vrab13;} else {Enchanted->CameraY_Acceleration = Vrab11;}} else
             {if(Enchanted->CameraY_Acceleration + Vrab12 < Vrab11){Enchanted->CameraY_Acceleration += Vrab12;} else {Enchanted->CameraY_Acceleration = Vrab11;}}
             if(Vrab11 == 0.05) if(Enchanted->CameraY_Post + Enchanted->CameraY_Acceleration > Vrab09){Enchanted->CameraY_Post = Vrab09; Enchanted->CameraY_Acceleration = 0;}
            }
           }

           Vrab09 = Enchanted->CameraY_Post + Enchanted->CameraY_Acceleration;
          }
          
          // Position Cap.
          {
           int64 Vrab10 = 0, Vrab11 = 0, Vrab12 = rint64(Varb0003 >= 550 ? 0 : 125), Vrab13 = Vrab12;
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: Vrab11 = Enchanted->Engine1->Area(); break;
           }
           Vrab08 -= 400; statics int64 Vrab14 = (Varb0002 < 800) ? (800 - Varb0002) : 0;
           if(Vrab08 > rxint64(Vrab11 - 800 + Vrab14)) Vrab08 = rxint64(Vrab11 - 800 + Vrab14);
           if(Vrab08 < 0) Vrab08 = 0;
           Vrab09 -= 200; statics int64 Vrab15 = (Varb0003 < 400) ? (400 - Varb0003) : 0;
           if(Vrab09 > rxint64(Vrab13 - 400 + Vrab15)) Vrab09 = rxint64(Vrab13 - 400 + Vrab15);
           if(Vrab09 < rxint64(Vrab12)) Vrab09 = rxint64(Vrab12);
           Enchanted->CameraX_Post = Vrab08 + 400; Enchanted->CameraY_Post = Vrab09 + 200;
          }

          // Position Result & Initialization
          {
           int64 Vrab10 = 0; int64 Vrab11 = 0;
           if(Varb0002 > 800) Vrab10 = (Varb0002 - 800) / 2;
           if(Varb0003 > 400 && Varb0003 < 550) Vrab11 = (Varb0003 - 400) / 2;
           if(Varb0003 >= 550) Vrab11 = (Varb0003 - 550) / 2;
           Enchanted->CameraX = L_Rounding64(Vrab08) - Vrab10; Enchanted->CameraY = L_Rounding64(Vrab09) - Vrab11;
            
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default:
             Vect02 = Enchanted->Engine1->Rear(Enchanted->CameraX + Vrab10, Enchanted->CameraY + Vrab11); Vect03 = Enchanted->Engine1->Draw(Enchanted->CameraX + Vrab10, Enchanted->CameraY + Vrab11);
            break;
           }
          }
         }
        }

        // Drawing.
        {
         // Limiter.
         int64 Vrab07 = 0, Vrab08 = Varb0002, Vrab09 = 0, Vrab10 = Varb0003;
         {
          Vrab07 = Vrab08 - 800; if(Vrab07 < 0){Vrab07 = 0;} else
          {
           statics int64 Vrab11 = Vrab07 / 2; Vrab08 -= Vrab07 - Vrab11; Vrab07 = Vrab11;
          }
          if(Vrab10 > 400 && Vrab10 < 550)
          {
           Vrab09 = Vrab10 - 400; if(Vrab09 < 0){Vrab09 = 0;} else
           {
            statics int64 Vrab11 = Vrab09 / 2; Vrab10 -= Vrab09 - Vrab11; Vrab09 = Vrab11;
           }
          }
          if(Vrab10 >= 550)
          {
           Vrab09 = Vrab10 - 500;
           statics int64 Vrab11 = Vrab09 / 2; Vrab10 -= Vrab09 - Vrab11; Vrab09 = Vrab11 + 100;
          }
         }

									// Color Control
									{
										uint64 Vrab11 = 0; switch(Enchanted->Memory[0].Engine){case 1: break; default: Vrab11 = Enchanted->Engine1->Colour(); break;}
										G_Set_Display(10, ruint32(Vrab11), (Vrab11 >> 32ull));
									}

         // Drawing Background.
         {
          statics insize Vrab11 = Vect02.size(); insize Vrab12 = 0;
          while(Vrab12 < Vrab11)
          {
           if(Vect02[Vrab12].Last){Vrab12 += 1; if(Vect02[Vrab12].Type == 3) Vrab12 += 1; continue;}
           if(Vect02[Vrab12].Type == 3)
           {
            statics insize Vrab13 = Vect02[Vrab12].Pic; statics int64 Vrab14 = Vect02[Vrab12].X, Vrab15 = Vect02[Vrab12].Y;
            Vrab12 += 1; G_Set_Display(0, Vrab13, Vrab14 - Enchanted->CameraX, Vrab15 - Enchanted->CameraY, 0ui8, 255ui8, Vect02[Vrab12].X, Vect02[Vrab12].Y);
           } else
           {
            uint8 Vrab13 = 2; statics insize Vrab14 = Vect02[Vrab12].Pic;
            if(Vect02[Vrab12].Type == 1){Vrab13 = 6;}
            if(Vect02[Vrab12].Type == 2)
            {
             statics int64 Vrab15 = rint64(Pics0001[Vrab14].Get_Width()) - 1, Vrab16 = rint64(Pics0001[Vrab14].Get_Height()) - 1;
             statics int64 Vrab17 = L_Rounding64(30 * (40.0 / rxint64(Vrab16)));
             if(Vrab16 - Vrab17 >= 0)
             G_Set_Display(3, Vrab14, Vect02[Vrab12].X - Enchanted->CameraX, Vect02[Vrab12].Y - Enchanted->CameraY + Vrab16 - Vrab17, 0ui8, 255ui8, 1, 1, 42, Vrab16 - 5, Vrab15, Vrab17);
            }
            G_Set_Display(Vrab13, Vrab14, Vect02[Vrab12].X - Enchanted->CameraX, Vect02[Vrab12].Y - Enchanted->CameraY);
           }
           Vrab12 += 1;
          }
         }

         // Player Info.
         struct Srct01 {uint8 Vrab001 = 0; uint8 Vrab002 = 0; xint64 Vrab003 = 0; xint64 Vrab004 = 0; xint64 Vrab005 = 0; xint64 Vrab006 = 0; xint64 Vrab007 = 0; insize Vrab008 = rinsize(-1); insize Vrab009 = rinsize(-1);};
         std::vector < Srct01 > Vect04;

         // Drawing Entities.
         {
          statics insize Vrab11 = Vect03.size(); insize Vrab12 = 0;
          while(Vrab12 < Vrab11)
          {
           if(Vect03[Vrab12].Type)
           {
            auto Auto01 = Vect03[Vrab12].Object.get();
            statics insize Vrab13 = Auto01->Pic_M; statics int64 Vrab14 = Auto01->X - Enchanted->CameraX, Vrab15 = Auto01->Y - Enchanted->CameraY;

            if(Auto01->Facing)
            {
             G_Set_Display(4, Auto01->Pic, Vrab14, Vrab15, (Auto01->Flip * 2), Auto01->Trans, Auto01->W, Auto01->H, Auto01->Rotate);
            } else
            {
             if(Vrab13 != rinsize(-1))
             {
              G_Set_Display(5, Vrab13, Vrab14, Vrab15, (Auto01->Flip * 2), Auto01->Trans, Auto01->W, Auto01->H, Auto01->Rotate);
             } else
             {
              G_Set_Display(4, Auto01->Pic, Vrab14, Vrab15, 1ui8 + (Auto01->Flip * 2), Auto01->Trans, Auto01->W, Auto01->H, Auto01->Rotate);
             }
            }

            if(Auto01->Character)
            {
             statics int64 Vrab16 = rint64(Auto01->Info->Name.size()) * 9; statics int64 Vrab17 = Auto01->Info->X - Enchanted->CameraX - L_Rounding64(rxint64(Vrab16) / 2.0);
             int64 Vrab18 = Vrab17;
             if(Vrab18 > Vrab08 - Vrab16 - 1) Vrab18 = Vrab08 - Vrab16 - 1;
             if(Vrab18 < Vrab07 + 2) Vrab18 = Vrab07 + 2;
             {int64 Vrab19 = Auto01->Info->Y - Enchanted->CameraY + 2; if(Vrab19 > Vrab10 - 16) Vrab19 = Vrab10 - 16; if(Vrab19 < Vrab09) Vrab19 = Vrab09; Enchanted->Print_Text(Vrab18, Vrab19, Auto01->Info->Color, Auto01->Info->Name);}

             insize Vrab19 = 73, Vrab20 = 71, Vrab21 = 76, Vrab22 = 74;
             switch(Auto01->Info->Integrate)
             { 
              case 1: Vrab20 = 72; break;
              default: break;
             }
             xint64 Vrab23 = Auto01->Info->MHP; {statics xint64 Vrab24 = Auto01->Info->DHP; if(Vrab24 > Vrab23) Vrab23 = Vrab24;}
             int64 Vrab24 = L_Rounding64((Auto01->Info->HP / Vrab23) * 60.0);
             int64 Vrab25 = L_Rounding64((Auto01->Info->DHP / Vrab23) * 60.0);
             int64 Vrab26 = L_Rounding64((Auto01->Info->MP / Auto01->Info->MMP) * 60.0);
             if(Vrab24 > Vrab25){auto Vrab27 = Vrab24; Vrab24 = Vrab25; Vrab25 = Vrab27; if(Vrab20 == 71 || Vrab20 == 72) Vrab19 = 80;}
             int64 Vrab27 = 0;
             if(Vrab25 > 60){Vrab27 = Vrab25 - 60; Vrab25 = 60; if(Vrab27 > 60) Vrab27 = 60;}
             if(Vrab26 > 60) Vrab26 = 60;
             if(Vrab25 > 0) G_Set_Display(2, Enchanted->Pic_Index_Interface[Vrab19], Auto01->Info->X - Enchanted->CameraX - 30, Auto01->Y - Enchanted->CameraY - 13, 0ui8, 255ui8, Vrab25, 3);
             if(Vrab24 > 0) G_Set_Display(2, Enchanted->Pic_Index_Interface[Vrab20], Auto01->Info->X - Enchanted->CameraX - 30, Auto01->Y - Enchanted->CameraY - 13, 0ui8, 255ui8, Vrab24, 3);
             if(Vrab27 > 0) G_Set_Display(2, Enchanted->Pic_Index_Interface[Vrab19], Auto01->Info->X - Enchanted->CameraX - 30, Auto01->Y - Enchanted->CameraY - 13, 0ui8, 255ui8, Vrab27, 3);
             if(Vrab24 > 0 || Vrab25 > 0) G_Set_Display(2, Enchanted->Pic_Index_Interface[Vrab21], Auto01->Info->X - Enchanted->CameraX - 30, Auto01->Y - Enchanted->CameraY - 10, 0ui8, 255ui8, 60, 3);
             if(Vrab26 > 0) G_Set_Display(2, Enchanted->Pic_Index_Interface[Vrab22], Auto01->Info->X - Enchanted->CameraX - 30, Auto01->Y - Enchanted->CameraY - 10, 0ui8, 255ui8, Vrab26, 3);
              
             if(Auto01->Info->Player < 16) Vect04.push_back({ruint8(Auto01->Info->Player % 8ui8), Auto01->Info->Integrate, Auto01->Info->HP, Auto01->Info->DHP, Auto01->Info->MHP, Auto01->Info->MP, Auto01->Info->MMP, Auto01->Info->Icon1, Auto01->Info->Icon2});
             Vect03[Vrab12].Object->Info.reset();
            }
            Vect03[Vrab12].Object.reset();
           } else
           {
            auto Auto01 = Vect03[Vrab12].Effect.get();
            uint8 Vrab13 = 0; if(Auto01->Facing) Vrab13 = 1;
            uint8 Vrab14 = 2; switch(Auto01->Type){case 1: Vrab14 = 4; break; case 2: Vrab14 = 0; break; case 3: Vrab14 = 1; break; default: break;} 
            G_Set_Display(Vrab14, Auto01->Pic, Auto01->X - Enchanted->CameraX, Auto01->Y - Enchanted->CameraY, Vrab13, Auto01->Trans, Auto01->W, Auto01->H, Auto01->Rotate);
            Vect03[Vrab12].Effect.reset();
           }
           Vrab12 += 1;
          }
         }

         // Drawing Front Background.
         {
          statics insize Vrab11 = Vect02.size(); insize Vrab12 = 0;
          while(Vrab12 < Vrab11)
          {
           if(!Vect02[Vrab12].Last){Vrab12 += 1; if(Vect02[Vrab12].Type == 3) Vrab12 += 1; continue;}
           if(Vect02[Vrab12].Type == 3)
           {
            statics insize Vrab13 = Vect02[Vrab12].Pic; statics int64 Vrab14 = Vect02[Vrab12].X, Vrab15 = Vect02[Vrab12].Y;
            Vrab12 += 1; G_Set_Display(0, Vrab13, Vrab14 - Enchanted->CameraX, Vrab15 - Enchanted->CameraY, 0ui8, 255ui8, Vect02[Vrab12].X, Vect02[Vrab12].Y);
           } else
           {
            uint8 Vrab13 = 2; statics insize Vrab14 = Vect02[Vrab12].Pic;
            if(Vect02[Vrab12].Type == 1){Vrab13 = 6;}
            if(Vect02[Vrab12].Type == 2)
            {
             statics int64 Vrab15 = rint64(Pics0001[Vrab14].Get_Width()) - 1, Vrab16 = rint64(Pics0001[Vrab14].Get_Height()) - 1;
             statics int64 Vrab17 = L_Rounding64(30 * (40.0 / rxint64(Vrab16)));
             if(Vrab16 - Vrab17 >= 0)
             G_Set_Display(3, Vrab14, Vect02[Vrab12].X - Enchanted->CameraX, Vect02[Vrab12].Y - Enchanted->CameraY + Vrab16 - Vrab17, 0ui8, 255ui8, 1, 1, 42, Vrab16 - 5, Vrab15, Vrab17);
            }
            G_Set_Display(Vrab13, Vrab14, Vect02[Vrab12].X - Enchanted->CameraX, Vect02[Vrab12].Y - Enchanted->CameraY);
           }
           Vrab12 += 1;
          }
         }

         // Inner Display Cut.
         {
										G_Set_Display(10, 0, 0);
          G_Set_Display(0, 0x0, 0, 0, 0ui8, 255ui8, Vrab07, Vrab06);
          G_Set_Display(0, 0x0, Vrab08, 0, 0ui8, 255ui8, Vrab05 - Vrab08, Vrab06);
          G_Set_Display(0, 0x0, 0, 0, 0ui8, 255ui8, Vrab05, Vrab09);
          G_Set_Display(0, 0x0, 0, Vrab10, 0ui8, 255ui8, Vrab05, Vrab06 - Vrab10);
         }

         // Player Info.
         {
          for(insize Vrab11 = 0; Vrab11 < 8; Vrab11 += 1)
          G_Set_Display(2, Enchanted->Pic_Index_Interface[124], Vrab07 + (200 * (rint64(Vrab11) % 4)), Vrab09 - 125 + (50 * (rint64(Vrab11) / 4)));
          insize Vrab11 = Vect04.size();
          while(Vrab11 != 0)
          {
           Vrab11 -= 1; statics int64 Vrab12 = Vrab07 + (200 * (rint64(Vect04[Vrab11].Vrab001) % 4)), Vrab13 = Vrab09 - 125 + (50 * (rint64(Vect04[Vrab11].Vrab001) / 4));
           G_Set_Display(3, Vect04[Vrab11].Vrab008, Vrab12 + 5, Vrab13 + 5, 0ui8, 255ui8, 190, 40);
           G_Set_Display(2, Vect04[Vrab11].Vrab009, Vrab12 + 15, Vrab13 + 15, 0ui8, 155ui8, -20, -20);
           insize Vrab14 = 127, Vrab15 = 125, Vrab16 = 131, Vrab17 = 129;
           switch(Vect04[Vrab11].Vrab002)
           {
            case 1: Vrab15 = 126; break;
            default: break;
           }
           xint64 Vrab18 = Vect04[Vrab11].Vrab005; {statics xint64 Vrab19 = Vect04[Vrab11].Vrab004; if(Vrab19 > Vrab18) Vrab18 = Vrab19;}
           int64 Vrab19 = L_Rounding64((Vect04[Vrab11].Vrab003 / Vrab18) * 140.0);
           int64 Vrab20 = L_Rounding64((Vect04[Vrab11].Vrab004 / Vrab18) * 140.0);
           int64 Vrab21 = L_Rounding64((Vect04[Vrab11].Vrab006 / Vect04[Vrab11].Vrab007) * 140.0);
           if(Vrab19 > Vrab20){auto Vrab22 = Vrab19; Vrab19 = Vrab20; Vrab20 = Vrab22; if(Vrab15 == 125 || Vrab15 == 126) Vrab14 = 132;}
           int64 Vrab22 = 0;
           if(Vrab20 > 140){Vrab22 = Vrab20 - 140; Vrab20 = 140; if(Vrab22 > 140) Vrab22 = 140;}
           if(Vrab21 > 140) Vrab21 = 140;
           if(Vrab20 > 0) G_Set_Display(3, Enchanted->Pic_Index_Interface[Vrab14], Vrab12, Vrab13, 0ui8, 255ui8, 53 + Vrab20, 50);
           if(Vrab19 > 0) G_Set_Display(3, Enchanted->Pic_Index_Interface[Vrab15], Vrab12, Vrab13, 0ui8, 255ui8, 53 + Vrab19, 50);
           if(Vrab22 > 0) G_Set_Display(3, Enchanted->Pic_Index_Interface[Vrab14], Vrab12, Vrab13, 0ui8, 255ui8, 53 + Vrab22, 50);
           if(Vrab19 > 0 || Vrab20 > 0) G_Set_Display(2, Enchanted->Pic_Index_Interface[Vrab16], Vrab12, Vrab13);
           if(Vrab21 > 0) G_Set_Display(3, Enchanted->Pic_Index_Interface[Vrab17], Vrab12, Vrab13, 0ui8, 255ui8, 53 + Vrab21, 50);

           G_Set_Display(2, Enchanted->Pic_Index_Interface[128], Vrab12, Vrab13);
           string Temp01 = "0"; if(Vect04[Vrab11].Vrab003 > 0) if(Vect04[Vrab11].Vrab003 > Vect04[Vrab11].Vrab004)
           {
            xint64 Vrab23 = Vect04[Vrab11].Vrab004; if(Vrab23 < 0) Vrab23 = 0.0;
            xint64 Vrab24 = Vect04[Vrab11].Vrab003 - Vrab23;
            if(Vrab23 > 999999.0) Vrab23 = 999999.0;
            if(Vrab24 > 999999.0) Vrab24 = 999999.0;
            Temp01 = "(" + std::to_string(L_Rounding64(Vrab24)) + ")" + std::to_string(L_Rounding64(Vrab23));
           } else 
           {
            if(Vect04[Vrab11].Vrab003 > 999999.0){Temp01 = "999999";} else {Temp01 = std::to_string(L_Rounding64(Vect04[Vrab11].Vrab003));}
           }
           Enchanted->Print_Text(Vrab12 + 193 - (rint64(Temp01.size()) * 9), Vrab13 + 5, 0ui8, Temp01);
           if(Vect04[Vrab11].Vrab006 > 999999.0){Temp01 = "999999";} else {Temp01 = std::to_string(L_Rounding64(Vect04[Vrab11].Vrab006));}
           Enchanted->Print_Text(Vrab12 + 193 - (rint64(Temp01.size()) * 9), Vrab13 + 28, 0ui8, Temp01);
          }
         }

         // Texts.
         {
          struct Srct01 {string Temp001; uint8 Vrab001 = 0; uint8 Vrab002 = 0;};
          std::vector < Srct01 > Vect05;
          {
           uint8 Vrab11 = 0; string Temp01;
           while(Vrab11 != 255)
           {
            switch(Enchanted->Memory[0].Engine)
            {
             case 1: break;
             default: Temp01 = Enchanted->Engine1->Text(Vrab11); break;
            }
            statics insize Vrab12 = Temp01.size(); insize Vrab13 = 0; string Temp02, Temp03;
            while(Vrab13 != Vrab12)
            {
             statics int8 Vrab14 = Temp01.at(Vrab13); Vrab13 += 1;
             if(Vrab14 != '|'){Temp02.push_back(Vrab14);} else {break;}
            }
            while(Vrab13 != Vrab12)
            {
             statics int8 Vrab14 = Temp01.at(Vrab13); Vrab13 += 1;
             if(Vrab14 != '|'){Temp03.push_back(Vrab14);} else {break;}
            }
            if(Vrab12 == Vrab13) break;
            Vect05.push_back(Srct01());
            Vect05[rinsize(Vrab11)].Temp001 = string(Temp01, Vrab13, Vrab12 - Vrab13);
            Vect05[rinsize(Vrab11)].Vrab001 = ruint8(L_Numbering(Temp02));
            Vect05[rinsize(Vrab11)].Vrab002 = ruint8(L_Numbering(Temp03));
            Vrab11 += 1;
           }
          }

          insize Vrab11 = Vect05.size();
          while(Vrab11 != 0)
          {
           Vrab11 -= 1; int64 Vrab12 = 0, Vrab13 = 0;
           statics int64 Vrab14 = rint64(Vect05[Vrab11].Temp001.size()) * 9;
           switch(Vect05[Vrab11].Vrab001){case 0: case 3: Vrab12 = Vrab07 + 2; break; case 1: case 4: Vrab12 = ((Vrab07 + Vrab08) / 2) - L_Rounding64(rxint64(Vrab14) / 2.0); break; default: Vrab12 = Vrab08; break;}
           switch(Vect05[Vrab11].Vrab001){case 0: case 1: case 2: Vrab13 = Vrab09 - 21; break; default: Vrab13 = Vrab10 + 5; break;}
           if(Vrab12 == Vrab08)
           {
            if(Vrab12 < Vrab07 + 2) Vrab12 = Vrab07 + 2;
            if(Vrab12 > Vrab08 - Vrab14 - 1) Vrab12 = Vrab08 - Vrab14 - 1;
           } else
           {
            if(Vrab12 > Vrab08 - Vrab14 - 1) Vrab12 = Vrab08 - Vrab14 - 1;
            if(Vrab12 < Vrab07 + 2) Vrab12 = Vrab07 + 2;
           }
           if(Vrab13 > Vrab06 - 21) Vrab13 = Vrab06 - 21;
           if(Vrab13 < 5) Vrab13 = 5;
           Enchanted->Print_Text(Vrab12 + 1, Vrab13, Vect05[Vrab11].Vrab002, Vect05[Vrab11].Temp001);
           Enchanted->Print_Text(Vrab12, Vrab13 + 1, Vect05[Vrab11].Vrab002, Vect05[Vrab11].Temp001);
           Enchanted->Print_Text(Vrab12, Vrab13, Vect05[Vrab11].Vrab002, Vect05[Vrab11].Temp001);
          }
         }
        }
        
        // Debug.
        {
         switch(Enchanted->Memory[0].Engine)
         {
          case 1: break;
          default: Temp69 = Enchanted->Engine1->Debug(); break;
         }
        }

        Vect01.clear(); Vect02.clear(); Vect03.clear();
       }

       // Entrance.
       {
        Enchanted->Runtime1 += 1; if(Enchanted->Runtime1 == 0xFFFFFFFFFFFFFFFF) Enchanted->Runtime1 = 0xFFFFFFFFFFFEBF;
        if(L_Input(Varb0019) == 1 && Enchanted->Runtime3 == 120){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); Enchanted->Runtime3 = 121;}
        if(Enchanted->Runtime3 < 120){G_Set_Display(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(120 - Enchanted->Runtime3) / 120) * 255.0)), Vrab05, Vrab06); Enchanted->Runtime3 += Varb0004; if(Enchanted->Runtime3 > 120) Enchanted->Runtime3 = 120;}
        if(Enchanted->Runtime3 > 120){G_Set_Display(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(Enchanted->Runtime3 - 120) / 120) * 255.0)), Vrab05, Vrab06); Enchanted->Runtime3 += Varb0004;}
        if(Enchanted->Runtime3 >= 240){switch(Enchanted->Memory[0].Engine){case 1: break; default: Enchanted->Engine1->Cleanup(); break;} Enchanted->Reset(9, 605); Varb0004 = 4;}
       }
      }
     break;
     default: break;
    }
   }

   // Finalizer.
   {
    // Exit.
    {
     if(Enchanted->Menu == 0 || Enchanted->Menu == 8)
     if(L_Input(Varb0019) == 1)
     {
      statics insize Vrab03 = Enchanted->Info.size(); insize Vrab04 = 0;
      while(Vrab03 != Vrab04)
      {
       if(Enchanted->Info[Vrab04].String == ("Press \"" + Enchanted->Input_Name(Varb0019) + "\" once again to exit."))
       Varb0027 = true;
       Vrab04 += 1;
      } if(Vrab03 == Vrab04)
      {
       Enchanted->Post_Info("Press \"" + Enchanted->Input_Name(Varb0019) + "\" once again to exit.");
       
       /* ID3D11Debug* Debg01;
       Game0001->m_deviceResources->GetD3DDevice()->QueryInterface < ID3D11Debug > (&Debg01);
       ThrowIfFailed(Debg01->ReportLiveDeviceObjects(D3D11_RLDO_DETAIL));*/
      }
     }
    }

    // Mouse Draw & Brightness.
    {
     int1 Vrab03 = false; Enchanted->Draw_Pausing = false;
     if(Input.MOUS_Right == 1){Enchanted->Draw_Color += 1; Enchanted->Draw_Color %= 5;}
     if(Input.MOUS_Mid == 1 || ((Input.CONS_LSHIFT >= 1 || Input.CONS_RSHIFT >= 1) && (Input.CONS_LCTRL >= 1 || Input.CONS_RCTRL >= 1) && Input.CONS_WINDOWS == 1)){Enchanted->Draw_Trans += 1; Enchanted->Draw_Trans %= 5;}
     if(Input.MOUS_Left >= 1 && Enchanted->Draw)
     {
      int64 Vrab04 = Input.MOUS_X, Vrab05 = Input.MOUS_Y, Vrab06 = Input.MOUS_X_Left, Vrab07 = Input.MOUS_Y_Left;
      if(Vrab06 < Vrab04){Vrab04 = Vrab06; Vrab06 = Input.MOUS_X;} else {Vrab04 -= 1; Vrab06 += 1;}
      if(Vrab07 < Vrab05){Vrab05 = Vrab07; Vrab07 = Input.MOUS_Y;} else {Vrab05 -= 1; Vrab07 += 1;}
      Vrab06 -= Vrab04; Vrab07 -= Vrab05;
      if(Vrab06 > 10 || Vrab07 > 10)
      {
       Vrab03 = true; Enchanted->Draw_Pausing = true; insize Vrab08 = 0xFF00; uint8 Vrab09 = 50ui8;
       switch(Enchanted->Draw_Color)
       {
        case 1: Vrab08 = 0xFF; break;
        case 2: Vrab08 = 0x0; break;
        case 3: Vrab08 = 0xFFFFFF; break;
        case 4: Vrab08 = 0xFF0000; break;
        default: break;
       }
       switch(Enchanted->Draw_Trans)
       {
        case 1: Vrab09 = 100ui8; break;
        case 2: Vrab09 = 175ui8; break;
        case 3: Vrab09 = 255ui8; break;
        case 4: Vrab09 = 0ui8; break;
        default: break;
       }
       G_Set_Display(1, Vrab08, Vrab04, Vrab05, 0, 255ui8, Vrab06, Vrab07); G_Set_Display(0, Vrab08, Vrab04 + 1, Vrab05 + 1, 0, Vrab09, Vrab06 - 2, Vrab07 - 2);
      }
     }

     if(L_Input(Enchanted->Memory[0].F12) > 0){Enchanted->Draw_Pausing = true; if(Enchanted->Darktime1 - (0.0125 * rxint64(Varb0004)) < 0.35){Enchanted->Darktime1 = 0.35;} else {Enchanted->Darktime1 -= 0.0125 * rxint64(Varb0004);}} else
     {if(Enchanted->Darktime1 < 1.0) Enchanted->Darktime1 += 0.0025 * rxint64(Varb0004);}
     {
      statics uint8 Vrab04 = ruint8(L_Rounding(rxint64(Enchanted->Memory[0].Brightness) * Enchanted->Darktime1));
      if(Vrab04 > 100)
      {G_Set_Display(0, 0xFFFFFF, 0, 0, 0, ruint8(L_Rounding((rxint64(Vrab04 - 100) / 100.0) * 255.0)), Enchanted->Display_W, Enchanted->Display_H);} else
      {G_Set_Display(0, 0x0, 0, 0, 0, 255 - ruint8(L_Rounding((rxint64(Vrab04) / 100.0) * 255.0)), Enchanted->Display_W, Enchanted->Display_H);}
     }

     if(Input.MOUS_X == Enchanted->Mouse_X && Input.MOUS_Y == Enchanted->Mouse_Y && Input.MOUS_Left == 0){if((++Enchanted->Mouse_Standby) == 255ui8) Enchanted->Mouse_Standby = 254ui8;} else {Enchanted->Mouse_Standby = 0ui8;}
     if(Enchanted->Mouse_Standby < 150ui8){ShowCursor(TRUE); if(Vrab03){G_Set_Display(2, Enchanted->Pic_Index_Interface[14], Input.MOUS_X - 11ull, Input.MOUS_Y - 11ull);} else {G_Set_Display(2, Enchanted->Pic_Index_Interface[13], Input.MOUS_X - 3ull, Input.MOUS_Y - 3ull);}} else
     {if(Enchanted->Mouse_Standby == 156ui8){ShowCursor(FALSE); SetCursor(NULL);}}
     Enchanted->Mouse_X = Input.MOUS_X; Enchanted->Mouse_Y = Input.MOUS_Y;
    }

    // Info & Volume Notification.
    {
     insize Vrab03 = Enchanted->Info.size();
     while(Vrab03 != 0)
     {
      Vrab03 -= 1;
      
      // Volume special notification.
      if(Enchanted->Info[Vrab03].Volume) Enchanted->Info[Vrab03].String = "Volume is adjusted to " + std::to_string(Enchanted->Memory[0].Volume) + "%.";
      insize Vrab04 = Enchanted->Info[Vrab03].String.size();

      // Position.
      int64 Vrab05 = 0, Vrab06 = Enchanted->Info[Vrab03].Y + (Enchanted->Menu == 10 ? 15 : Enchanted->Memory[0].Show_FPS ? 30 : 15);
      if(Enchanted->Menu == 10){int64 Vrab07 = 0; statics int64 Vrab08 = Varb0003; if(Vrab08 > 400 && Vrab08 < 550){Vrab07 = Vrab08 - 400; if(Vrab07 < 0){Vrab07 = 0;} else {Vrab07 = Vrab07 / 2;}} if(Vrab08 >= 550){Vrab07 = Vrab08 - 500; Vrab07 = (Vrab07 / 2) + 100;} if(Enchanted->Memory[0].Show_FPS) if(Vrab07 < 15) Vrab07 = 15; Vrab06 += Vrab07;}
      int1 Vrab07 = true; int1 Vrab08 = false;
     
      // Transition.
      if(Enchanted->Info[Vrab03].Runtime < 280)
       {
        statics int64 Vrab09 = 280 - rint64(Enchanted->Info[Vrab03].Runtime);
        Vrab05 = -L_Rounding64(((rxint64((Vrab09 * Vrab09) + Vrab09) / 2) / 39340) * 400.0);
       } else
      {
       statics uint64 Vrab09 = 1200 + (ruint64(Vrab04) * 30);
       if(Enchanted->Info[Vrab03].Runtime >= Vrab09 - Varb0004)
       if(Enchanted->Info[Vrab03].Runtime >= Vrab09)
       {
        statics int64 Vrab10 = rint64(Enchanted->Info[Vrab03].Runtime) - Vrab09; Vrab08 = true;
   
        // Shift back.
        if(Vrab10 >= 24 && Vrab10 < 24 + rint64(Varb0004))
        {
         int64 Vrab11 = 29;
         {
          insize Vrab12 = 0, Vrab13 = 0, Vrab14 = Vrab04; while(Vrab14 > 41){Vrab14 -= 40; if(Enchanted->Info[Vrab03].String.at((Vrab12 * 40) + Vrab13 + 40) == ' '){Vrab14 -= 1; Vrab13 += 1;} Vrab12 += 1;}
          if(Vrab04 > 41){Vrab11 += 7 + (16 * rint64(Vrab12));} else
          {Vrab11 += 5;}
         }
 
         statics insize Vrab12 = Enchanted->Info.size();
         for(insize Vrab13 = 0; Vrab13 < Vrab12; ++Vrab13)
         if(Enchanted->Info[Vrab03].Slot > Enchanted->Info[Vrab13].Slot)
         {
          statics insize Vrab14 = Enchanted->Info[Vrab13].Manager.size(); Enchanted->Info[Vrab13].Manager.resize(Vrab14 + 1);
          Enchanted->Info[Vrab13].Manager[Vrab14].Target = -Vrab11;
         }
        }

        Vrab05 = -L_Rounding64(((rxint64((Vrab10 * Vrab10) + Vrab10) / 2) / 39340) * 420.0);
       } else {if(Enchanted->Draw_Pausing) Enchanted->Info[Vrab03].Runtime -= Varb0004;}
       if(Enchanted->Info[Vrab03].Runtime > Vrab09 + 280) Vrab07 = false;
      }
      Enchanted->Info[Vrab03].Runtime += Varb0004;

      // Shifts.
      {
       insize Vrab09 = Enchanted->Info[Vrab03].Manager.size();
       while(Vrab09 != 0)
       {
        Vrab09 -= 1; Enchanted->Info[Vrab03].Manager[Vrab09].Runtime += Varb0004;
        int64 Vrab10 = 256 - rint64(Enchanted->Info[Vrab03].Manager[Vrab09].Runtime); if(Vrab10 < 0) Vrab10 = 0;
        statics int64 Vrab11 = Enchanted->Info[Vrab03].Manager[Vrab09].Target, Vrab12 = L_Rounding64(((rxint64((Vrab10 * Vrab10) + Vrab10) / 2) / 32896) * Vrab11) - Vrab11;
        Vrab06 -= Vrab12;
        if(Vrab10 == 0 || (Vrab08 && Vrab11 < 0)){Enchanted->Info[Vrab03].Y -= Vrab12; Enchanted->Info[Vrab03].Manager.erase(Enchanted->Info[Vrab03].Manager.begin() + Vrab09);}
       }
      }

      // Drawing.
      if(Vrab07)
      {
       {
        insize Vrab09 = 0, Vrab10 = 0, Vrab11 = Vrab04;
        while(Vrab11 > 41){Vrab11 -= 40; if(Enchanted->Info[Vrab03].String.at((Vrab09 * 40) + Vrab10 + 40) == ' '){Vrab11 -= 1; Vrab10 += 1;} Vrab09 += 1;}
       
        if(Vrab04 > 41)
        {Enchanted->Print_Bar(Vrab05 + 15, Vrab06, 380, 7 + (16 * rint64(Vrab09)));} else
        {Enchanted->Print_Bar(Vrab05 + 15, Vrab06, 13 + (9 * rint64(Vrab11)), 5);}
       }
       {
        insize Vrab09 = 0, Vrab10 = 0;
        while(Vrab04 > 41){Vrab04 -= 40; statics insize Vrab11 = Vrab09 * 40; string Temp01 = string(Enchanted->Info[Vrab03].String, Vrab11 + Vrab10, 40); if(Enchanted->Info[Vrab03].String.at(Vrab11 + Vrab10 + 40) != ' '){if(Enchanted->Info[Vrab03].String.at(Vrab11 + Vrab10 + 39) != ' ') Temp01.push_back('-');} else {Vrab04 -= 1; Vrab10 += 1;} Enchanted->Print_Text(Vrab05 + 30, Vrab06 - 6 + (16 * rint64(Vrab09)), 0, Temp01); Vrab09 += 1;}
        Enchanted->Print_Text(Vrab05 + 30, Vrab06 - 6 + (16 * rint64(Vrab09)), 0, string(Enchanted->Info[Vrab03].String, (Vrab09 * 40) + Vrab10, Vrab04));
       }
       G_Set_Display(2, Enchanted->Pic_Index_Interface[Enchanted->Info[Vrab03].Question ? 105 : 106], Vrab05 + 9, Vrab06 - 6);
      } else {Enchanted->Info.erase(Enchanted->Info.begin() + Vrab03);}
     }

     // Volume
     int1 Vrab04 = false;
     Vrab03 = Enchanted->Info.size(); while(Vrab03 != 0){Vrab03 -= 1; if(Enchanted->Info[Vrab03].Volume) if(Enchanted->Info[Vrab03].Runtime < 1200 + (ruint64(Enchanted->Info[Vrab03].String.size()) * 26)){Vrab04 = true; break;}}
     statics uint8 Vrab05 = L_Input(Enchanted->Memory[0].F10), Vrab06 = L_Input(Enchanted->Memory[0].F11);
     if(Vrab05 > 0 || Vrab06 > 0)
     {
      if(Vrab04){if(Enchanted->Info[Vrab03].Runtime > 280) Enchanted->Info[Vrab03].Runtime = 280;} else {Enchanted->Post_Info("", true);}
      uint8 Vrab07 = ruint8(L_Rounding(8.0 / rxint64(Varb0004))); if(Vrab07 == 0) Vrab07 = 1;
      if(Vrab05 > 0 && Vrab06 == 0)
      if(Vrab05 == 1 || (Vrab05 % Vrab07 == 0 && Vrab05 > Vrab07 * 12)){Enchanted->Memory[0].Volume -= 1; if(Enchanted->Memory[0].Volume > 150) Enchanted->Memory[0].Volume = 0; Enchanted->Memory[1].Volume = Enchanted->Memory[0].Volume;}
      if(Vrab06 > 0 && Vrab05 == 0)
      if(Vrab06 == 1 || (Vrab06 % Vrab07 == 0 && Vrab06 > Vrab07 * 12)){Enchanted->Memory[0].Volume += 1; if(Enchanted->Memory[0].Volume > 150) Enchanted->Memory[0].Volume = 150; Enchanted->Memory[1].Volume = Enchanted->Memory[0].Volume;}
     }
    }

    // FPS Draw.
    if(Enchanted->Memory[0].Show_FPS) Enchanted->Print_Text(3, 0, 0, std::to_string(Vrab01) + "|" + std::to_string(Vrab02) + " (" + std::to_string(Imge0001.size()) + ")" + ((Temp69 != "") ? (" [" + Temp69 + "]") : ("")));
   }
  }
 //-//











































#endif