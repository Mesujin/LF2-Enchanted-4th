////////////////////////////////////////////////////////////////////////////////////////////
// "engine.h"                                                                             //
//                                                                                        //
// Main source of "Hepta: Enchanted".                                                     //
// Dunno what to text here, but this is my usual style for a header text...               //
//                                                                                        //
// Please refer to "platform.h" for the "typedef"/"using".                                //
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
  #include <thread>
  #include <future>
  #include <initializer_list>
  #include <math.h>
  #include "platform.h"
  
  // AngelScript
   #include "AngelScript/angelscript.h"
   #include "AngelScript/scriptarray.h"
   #include "AngelScript/scriptbuilder.h"
   #include "AngelScript/scriptmath.h"
   #include "AngelScript/scriptmathcomplex.h"
   #include "AngelScript/scriptstdstring.h"

  // Pre-defined Variable
   #define HEPTA_BASE_FRAME_PER_SECOND 960

 // Early Declaration (In order to be accessible by Global Variables.)
  int0   L_Message(statics asSMessageInfo*, int0*) perfect;
  int1   L_Exist(statics string&)     perfect;
  int32  L_Rounding(statics xint64)   perfect;
  int32  L_Positive(statics int32)    perfect;
  int32  L_Numbering(string)          perfect;
  int64  L_Rounding64(statics xint64) perfect;
  xint64 L_Positive64(statics xint64) perfect;
  uint64 L_Random(uint64 Vrab01, insize Vrab02 = 0) perfect;
  uint64 L_Convert(string)            perfect;
  xint64 L_Doubling(statics string&)  perfect;
  xint64 L_Distance(xint64, xint64, xint64, xint64) perfect;
  xint64*L_Degree(statics xint64, statics xint64, statics xint64, statics xint64, statics xint64, statics xint64, statics int1 = true) perfect;
  xint64*L_Rotate(statics xint64, statics xint64, statics xint64) perfect;
  string L_Execute(statics string&)   perfect;
  string L_Pronounce(statics uint64)  perfect; 
  string L_Directory(statics string&) perfect;
  string L_Lowercase(string)          perfect;
  string L_Simplfy(statics string&)   perfect;
  string L_Cut(string Temp01, insize Vrab01 = 2, insize Vrab02 = 0) perfect;
  string L_Load(uint8 Vrab01, uint8 Vrab02 = 0)                     perfect;
  string L_Save(uint8 Vrab01, string Temp01 = "", uint8 Vrab02 = 0) perfect;
  int0   EIDP_LF2Enchanted(uint32, uint64) perfect;
  int0   EIDP_LF2Forevered(uint32, uint64) perfect;

  // Encryption & Decryption Functions
   int0   S_Control()                          perfect;
   int8   S_Decryption94(statics int8)         perfect;
   int8   S_DecryptionINT8(statics int8[2])    perfect;
   int16  S_DecryptionINT16(statics int8[3])   perfect;
   int32  S_DecryptionINT32(statics int8[5])   perfect;
   int64  S_DecryptionINT64(statics int8[10])  perfect;
   uint32 S_DecryptionUINT4(statics int8[1])   perfect;
   uint8  S_DecryptionUINT8(statics int8[2])   perfect;
   uint32 S_DecryptionUINT10(statics int8[2])  perfect;
   uint16 S_DecryptionUINT16(statics int8[3])  perfect;
   uint32 S_DecryptionUINT18(statics int8[3])  perfect;
   uint32 S_DecryptionUINT24(statics int8[4])  perfect;
   uint32 S_DecryptionUINT32(statics int8[5])  perfect;
   uint64 S_DecryptionUINT64(statics int8[10]) perfect;
   xint64 S_DecryptionXINT64(statics int8[11]) perfect;
   string S_DecryptionSTRING(string)           perfect;
   string S_Encryption94(statics uint64)       perfect;
   string S_EncryptionUINT4(statics uint32)    perfect;
   string S_EncryptionUINT8(statics uint8)     perfect;
   string S_EncryptionUINT10(statics uint32)   perfect;
   string S_EncryptionUINT16(statics uint16)   perfect;
   string S_EncryptionUINT18(statics uint32)   perfect;
   string S_EncryptionUINT24(statics uint32)   perfect;
   string S_EncryptionUINT32(statics uint32)   perfect;
   string S_EncryptionUINT64(statics uint64)   perfect;
   string S_EncryptionXINT64(statics xint64)   perfect;
   string S_EncryptionSTRING(string)           perfect;

 // Global Variables
  string Temp0001 = "";     // App Working Directory.
  string Temp0002 = "";     // App Encryption-Decryption Key.
  uint64 Vrab0001 = 0;      // App Runtime.
  uint64 Vrab0002 = 0;      // App Looptime.
  uint8  Vrab0003 = 8;      // App FPS Ratio. (1 = 960, 2 = 480, 4 = 240, 8 = 120, 16 = 60, 32 = 30, 64 = 15, 128 = 7.5)
  int1   Vrab0004 = false;  // Display Update?
  uint32 Vrab0005 = 1920;   // Display Width Resolution.
  uint32 Vrab0006 = 1080;   // Display Height Resolution.
  uint32 Vrab0007 = 0;      // Display X Offset.
  uint32 Vrab0008 = 0;      // Display Y Offset.
  int1   Vrab0009 = false;  // Display Fullscreen?
  int1   Vrab0010 = false;  // Display Keep Aspect Ratio?
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
  uint8  Vrab0022 = 103;    // Input Pad Default OK.
  uint8  Vrab0023 = 104;    // Input Pad Default CANCEL.
  uint8  Vrab0024 = 95;     // Input Pad Default UP.
  uint8  Vrab0025 = 96;     // Input Pad Default LEFT.
  uint8  Vrab0026 = 97;     // Input Pad Default DOWN.
  uint8  Vrab0027 = 98;     // Input Pad Default RIGHT.
  uint32 Vrab0028 = 800;    // Window Width.
  uint32 Vrab0029 = 450;    // Window Height.
  uint8  Vrab0030 = 0;      // Window Exit?
  uint64 Vrab0031 = 0;      // Random Seed.
  int1   Vrab0032 = true;   // Random Reset.

  uint8  Vrab0033 = 0;      // LF2_Enchanted Status.
  uint8  Vrab0034 = 0;      // LF2_Forevered Status.
 
  std::vector < insize > Vect0001; // Language Index.
  std::vector < string > Vect0002; // Language String.
  
 // Unique
  struct HEPTA_INPUT; struct HEPTA_ANGELSCRIPT; struct HEPTA_LF2_ENCHANTED; struct HEPTA_LF2_FOREVERED;
  unique < HEPTA_INPUT > Input;
  unique < HEPTA_ANGELSCRIPT > Angel;
  unique < HEPTA_LF2_ENCHANTED > Enchanted;
  unique < HEPTA_LF2_FOREVERED > Forevered;

 // Stuctures
  struct HEPTA_INPUT
  {
   HEPTA_INPUT(){PADS_ON.resize(5); PADS_UP.resize(5); PADS_LEFT.resize(5); PADS_DOWN.resize(5); PADS_RIGHT.resize(5); PADS_A.resize(5); PADS_B.resize(5); PADS_X.resize(5); PADS_Y.resize(5); PADS_START.resize(5); PADS_BACK.resize(5); PADS_MENU.resize(5); PADS_VIEW.resize(5);}
   uint16 RESH_ANY;

   uint16 MAIN_1, MAIN_2, MAIN_3, MAIN_4, MAIN_5, MAIN_6, MAIN_7, MAIN_8, MAIN_9, MAIN_0;
   uint16 MAIN_A, MAIN_B, MAIN_C, MAIN_D, MAIN_E, MAIN_F, MAIN_G, MAIN_H, MAIN_I, MAIN_J, MAIN_K, MAIN_L, MAIN_M, MAIN_N, MAIN_O, MAIN_P, MAIN_Q, MAIN_R, MAIN_S, MAIN_T, MAIN_U, MAIN_V, MAIN_W, MAIN_X, MAIN_Y, MAIN_Z;
   uint16 MAIN_TILDE;        // ` ~
   uint16 MAIN_MINUS;        // - _
   uint16 MAIN_PLUS;         // = +
   uint16 MAIN_OPENBRACKED;  // [ {
   uint16 MAIN_CLOSEBRACKED; // ] }
   uint16 MAIN_PIPE;         // \ |
   uint16 MAIN_SEMICOLON;    // ; :
   uint16 MAIN_QUOTES;       // ' "
   uint16 MAIN_QUESTION;     // / ?
   uint16 MAIN_PERIOD;       // . >
   uint16 MAIN_COMMA;        // , <
   uint16 MAIN_SPACE;        // 

   uint16 CONS_F1, CONS_F2, CONS_F3, CONS_F4, CONS_F5, CONS_F6, CONS_F7, CONS_F8, CONS_F9, CONS_F10, CONS_F11, CONS_F12;
   uint16 CONS_ESC, CONS_PRTSC, CONS_DELETE, CONS_BACK, CONS_TAB, CONS_CAPS, CONS_ENTER;
   uint16 CONS_LSHIFT, CONS_RSHIFT;
   uint16 CONS_LALT, CONS_RALT;
   uint16 CONS_LCTRL, CONS_RCTRL;
   uint16 CONS_UP, CONS_LEFT, CONS_DOWN, CONS_RIGHT;
   uint16 CONS_WINDOWS;
   int1   RESH_CAPS;

   uint16 NUMS_NUMLOCK;
   uint16 NUMS_MULTIPLE, NUMS_DEVIDE, NUMS_ADD, NUMS_SUBTRACT, NUMS_POINT;
   uint16 NUMS_0, NUMS_1, NUMS_2, NUMS_3, NUMS_4, NUMS_5, NUMS_6, NUMS_7, NUMS_8, NUMS_9;

   int32  MOUS_X;
   int32  MOUS_Y;
   uint16 MOUS_Left;
   uint16 MOUS_Right;
   uint16 MOUS_Mid;
   uint16 MOUS_Left_Release;
   uint16 MOUS_Right_Release;
   uint16 MOUS_Mid_Release;
   int32  MOUS_X_Left;
   int32  MOUS_Y_Left;
   int32  MOUS_X_Right;
   int32  MOUS_Y_Right;
   int32  MOUS_X_Mid;
   int32  MOUS_Y_Mid;
   int32  MOUS_SCROLL;
   int32  MOUS_SCROLL2;

   std::vector < int1 > PADS_ON;
   std::vector < uint16 > PADS_UP, PADS_LEFT, PADS_DOWN, PADS_RIGHT, PADS_A, PADS_B, PADS_X, PADS_Y, PADS_START, PADS_BACK, PADS_MENU, PADS_VIEW;
  };
  struct HEPTA_ANGELSCRIPT
  {
   uint8  Vrab001 = 0;      // Initialization Status.

   asIScriptEngine  *Engi001;
   asIScriptModule  *Modu001;
   asIScriptContext *Cont001;

   int0 Initialize() perfect
   {
   
   }
   int0 Uninitialize() perfect
   {
   
   }
   int0 Register(uint8 Vrab01, string Temp01, int32 Vrab02 = 0, string Temp02 = "", int0 *Vrab03 = nullptr) perfect
   {
    if(Vrab001 == 0) return;
    switch(Vrab01)
    {
     case 0:
      Engi001->RegisterGlobalProperty(Temp01.c_str(), Vrab03);
     break;
     case 1:
      Engi001->RegisterGlobalFunction(Temp01.c_str(), asFunctionPtr(Vrab03), asCALL_CDECL);
     break;
     case 2:
      Engi001->RegisterObjectType(Temp01.c_str(), 0, (Vrab02 == 0 ? (asOBJ_REF) : (asOBJ_REF | asOBJ_NOCOUNT)));
     break;
     case 3:
      Engi001->RegisterObjectMethod(Temp01.c_str(), Temp02.c_str(), asFunctionPtr(Vrab03), asCALL_THISCALL);
     break;
     case 4:
      Engi001->RegisterObjectBehaviour(Temp01.c_str(), (Vrab02 == 0 ? asBEHAVE_ADDREF : (Vrab02 == 1 ? asBEHAVE_RELEASE : asBEHAVE_FACTORY)), Temp02.c_str(), asFunctionPtr(Vrab03), (Vrab02 > 1 ? asCALL_CDECL : asCALL_THISCALL));
     break;
     case 5:
      Engi001->RegisterObjectProperty(Temp01.c_str(), Temp02.c_str(), Vrab02);
     break;
     default: break;
    }
   }
  };
  struct HEPTA_LF2_ENCHANTED
  {
   // Variables
    int1   Vrab001 = true;          // Initialization.
    insize Vrab002 = rinsize(-1);   // Background Index.
    int1   Vrab003 = false;         // Background Type.
    int1   Vrab004 = false;         // Go Load Engine?
    uint8  Vrab005 = 0;             // Base Menu.
    insize Vrab006 = 0;             // Info's Slot.
    int1   Vrab007 = true;          // Mouse's rectangle draw?
    int1   Vrab008 = false;         // Mouse's rectangle draw's pausing?
    uint8  Vrab009 = 0;             // Mouse's rectangle draw's color.
    uint8  Vrab010 = 0;             // Mouse's rectangle draw's trans.
    xint64 Vrab011 = 0;             // Screen brightness.
    uint8  Vrab012 = 0;             // Mouse's standby countup.
    int32  Vrab013 = 0;             // Mouse's last frame x position.
    int32  Vrab014 = 0;             // Mouse's last frame y position.
    uint8  Vrab015 = ruint8(-1);    // Last used Language.
    int64  Vrab016[2]{0, 0};        // Last print_text size.
    std::vector < uint8 >  Vect001; // Window Order.
    std::vector < insize > Vect002; // Interface Index - Background(s).
    std::vector < int1 >   Vect003; // Interface Index - Background(s)'s Type.
    std::vector < insize > Vect004; // Interface Index - Images.
    std::vector < insize > Vect005; // Interface Index - Sound.
    std::vector < int1 >   Vect006; // Engine Load?

   // Structures
    struct HEPTA_LF2_ENCHANTED_ENGINE0
    {
     string Load() perfect
     {
      return "";
     }
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1
    {
     private:
      int1   Vrab001 = false;         // Initiate Reload?
      string Temp001 = "";            // Address.
      string Temp002 = "";            // Game Address.
      std::ifstream File001;          // File Open.
      std::vector < insize > Vect001; // Reload IDs.
      
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_SUBPHASE_ENTITY
      {
       insize id = rinsize(-1);
       int32  x[2] = {0, 0};
       int32  y[2] = {0, 0};
       int32  z[2] = {0, 0};
       xint64 dvx = 0.0;
       xint64 dvy = 0.0;
       xint64 dvz = 0.0;
       std::vector < int32 > action = {0};
       int32  facing = 0;
       int32  hp = 1000;
       int32  mp = 500;
       int32  blink = 0;
       xint64 ratio = 1.0;
       int32  times = 0;
       int32  reserve = 0;
       int32  join = 0;
       int32  join_reserve = 0;
       insize team = rinsize(-1);
       uint8  lock = 2;
       string name = "";
       uint8  category = 0;
       xint64 scale = 1.0;
       insize drop_id = rinsize(-1);
       int32  drop_act = 0;
       int32  drop_y = 0;
       int32  drop_dvy = 0;
       insize death_cutscene = rinsize(-1);
       insize trigger_subphase = rinsize(-1);
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_SUBPHASE
      {
       insize Index_music = rinsize(-1);

       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_SUBPHASE_ENTITY > Entity;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_CUTSCENE
      {
      
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE
      {
      
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_CUTSCENE > Cutscene;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_SUBPHASE > Subphase;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGE
      {
       insize id = rinsize(-1);
       string name = "";
       insize next_stage = rinsize(-1);

       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE > Phase;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_OPOINT
      {
       int32  kind = 0;
       int32  x[2] = {0, 0};
       int32  y[2] = {0, 0};
       int32  z[2] = {0, 0};
       xint64 dvx = 0.0;
       xint64 dvy = 0.0;
       xint64 dvz = 0.0;
       insize oid = rinsize(-1);
       std::vector < int32 > action = {0};
       int32  facing = 0;
       uint32 cc = 0;
       uint32 c1 = 0;
       uint32 c2 = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER
      {
       insize Index_pic = rinsize(-1);
       int32  kind = 0;
       int32  x = 0;
       int32  y = 0;
       int32  z = 0;
       int32  width = 0;
       int32  height = 0;
       int32  trans = 0;
       int32  rotate = 0;
       uint32 color = 0;
       int32  loop = 0;
       int32  loop_count = 0;
       uint32 cc = 0;
       uint32 c1 = 0;
       uint32 c2 = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND
      {
       insize id = rinsize(-1);
       string file = "";

       string name = "";
       int32  width[2] = {0, 0};
       int32  zwidth[2] = {0, 0};
       int32  cam[4] = {0, 0, 0, 0};
       insize Index_shadow = rinsize(-1);
       uint32 shadow[2] = {0, 0};

       std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER > > Layer;
       std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_OPOINT > > Opoint;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_BACKGROUND
      {
       int32  kind = 0;
       int32  width[2] = {0, 0};
       int32  zwidth[2] = {0, 0};
       int32  cam[4] = {0, 0, 0, 0};
       insize Index_shadow = rinsize(-1);
       uint32 shadow[2] = {0, 0};

       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER* > Layer;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_OPOINT* > Opoint;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_EFFECT
      {
       int1   Exist = false;
       int32  duration = 0;
       int32  duration_add = 0;
       int32  duration_max = 0;
       int32  duration_lost = 0;
       int32  duration_lost_intv = 0;
       int32  stack = 0;
       int32  stack_add = 0;
       int32  stack_max = 0;
       int32  stack_lost = 0;
       int32  stack_lost_intv = 0;
       xint64 stack_dmgdealt = 0.0;
       xint64 stack_dmgtaken = 0.0;
       xint64 bounce = 0.0;
       std::vector < insize > transfer = {0};
       string desc = "";
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_HPOINT
      {
       int32  kind = 0;
       xint64 x = 0.0;
       xint64 y = 0.0;
       xint64 z = -5.0;
       xint64 w = 0.0;
       xint64 h = 0.0;
       xint64 l = 10.0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT
      {
       int32  kind = 0;
       xint64 x = 0.0;
       xint64 y = 0.0;
       xint64 z = -9.0;
       xint64 w = 0.0;
       xint64 h = 0.0;
       xint64 l = 18.0;
       xint64 dvx = 0.0;
       xint64 dvy = 0.0;
       xint64 dvz = 0.0;
       int32  fall = 0;
       int32  arest = 0;
       int32  vrest = 0;
       std::vector < int32 > respond = {0};
       std::vector < int32 > effect = {0};
       int32  bdefend = 0;
       int32  injury = 0;
       int32  catchingact[2] = {0, 0};
       int32  caughtact[2] = {0, 0};
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_OPOINT
      {
       int32  kind = 0;
       int32  x = 0;
       int32  y = 0;
       int32  z = 0;
       xint64 dvx = 0.0;
       xint64 dvy = 0.0;
       xint64 dvz = 0.0;
       insize oid = rinsize(-1);
       std::vector < int32 > action = {0};
       int32  facing = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_WPOINT
      {
       int32  kind = 0;
       int32  x = 0;
       int32  y = 0;
       int32  z = 0;
       xint64 dvx = 0.0;
       xint64 dvy = 0.0;
       xint64 dvz = 0.0;
       std::vector < int32 > weaponact = {0};
       int32  attacking = 0;
       int32  cover = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_CPOINT
      {
       int32  kind = 0;
       int32  x = 0;
       int32  y = 0;
       int32  z = 0;
       xint64 throwvx = 0.0;
       xint64 throwvy = 0.0;
       xint64 throwvz = 0.0;
       int32  throwinjury = 0;
       std::vector < int32 > vaction = {0};
       std::vector < int32 > aaction = {0};
       std::vector < int32 > daction = {0};
       std::vector < int32 > jaction = {0};
       std::vector < int32 > taction = {0};
       int32  dircontrol = 0;
       int32  hurtable = 0;
       int32  decrease = 0;
       int32  cover = 0;
       int32  injury = 0;
       int32  fronthurtact = 0;
       int32  backhurtact = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_BPOINT
      {
       int32 x = 0;
       int32 y = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_EPOINT
      {
       int32 x = 0;
       int32 y = 0;
       int32 w = 0;
       int32 h = 0;
       int32 rotate = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_PPOINT
      {
       insize pic = rinsize(-1);
       int32  x = 0;
       int32  y = 0;
       int32  z = 0;
       int32  trans = 0;
       int32  rotate = 0;
       int32  stx = 0;
       int32  sty = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME
      {
       int1   Exist = false;
       insize pic = rinsize(-1);
       std::vector < int32 > state = {0};
       int32  wait = 0;
       std::vector < int32 > next = {0};
       xint64 dvx = 0;
       xint64 dvy = 0;
       xint64 dvz = 0;
       int32  centerx = 0;
       int32  centery = 0;
       int32  centerz = 0;
       std::vector < int32 > hit_a = {0};
       std::vector < int32 > hit_d = {0};
       std::vector < int32 > hit_j = {0};
       std::vector < int32 > hit_Fa = {0};
       std::vector < int32 > hit_Fj = {0};
       std::vector < int32 > hit_Da = {0};
       std::vector < int32 > hit_Dj = {0};
       std::vector < int32 > hit_Ua = {0};
       std::vector < int32 > hit_Uj = {0};
       std::vector < int32 > hit_ja = {0};
       int32  mp[2] = {0, 0};
       insize Index_sound = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_PPOINT > ppoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_EPOINT > epoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_BPOINT > bpoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_CPOINT > cpoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_WPOINT > wpoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_OPOINT > opoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT > itr;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_HPOINT > bdy;
     
       // Runtime Data
       xint64 bdy_X = 0xFFFFFFFF, bdy_Y = 0xFFFFFFFF, bdy_Z = 0xFFFFFFFF, bdy_W = -rxint64(0xFFFFFFFF), bdy_H = -rxint64(0xFFFFFFFF), bdy_L = -rxint64(0xFFFFFFFF);
       xint64 itr_X = 0xFFFFFFFF, itr_Y = 0xFFFFFFFF, itr_Z = 0xFFFFFFFF, itr_W = -rxint64(0xFFFFFFFF), itr_H = -rxint64(0xFFFFFFFF), itr_L = -rxint64(0xFFFFFFFF);
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_STRENGTH
      {
       int32 dvx = 0;
       int32 dvy = 0;
       int32 dvz = 0;
       int32 fall = 0;
       int32 arest = 0;
       int32 vrest = 0;
       std::vector < int32 > respond = {0};
       int32 effect = 0;
       int32 bdefend = 0;
       int32 injury = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_PIC
      {
       insize Index_pic = rinsize(-1);
       uint32 w = 0;
       uint32 h = 0;
       uint32 row = 0;
       uint32 col = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT
      {
       insize id = rinsize(-1);
       int32  type = 0;
       string file = "";

       string name = "";
       insize Index_head = rinsize(-1);
       insize Index_small = rinsize(-1);
       xint64 movement_speed = 1.0;
       xint64 movement_speedz = 0.7;
       xint64 heavy_movement_speed = 0.65;
       uint32 walking_frame_rate = 2;
       uint32 running_frame_rate = 3;
       xint64 walking_speed = 1.0;
       xint64 walking_speedz = 0.4;
       xint64 running_speed = 2.0;
       xint64 running_speedz = 0.275;
       xint64 heavy_walking_speed = 1.0;
       xint64 heavy_walking_speedz = 0.4;
       xint64 heavy_running_speed = 2.0;
       xint64 heavy_running_speedz = 0.275;
       xint64 base_jump_height = -16.0;
       xint64 jump_height = -0.1;
       xint64 jump_distance = 1.5;
       xint64 jump_distancez = 0.6;
       xint64 base_dash_height = -10.0;
       xint64 dash_height = -0.1;
       xint64 dash_distance = 3.0;
       xint64 dash_distancez = 0.5;
       xint64 rowing_height = -2.0;
       xint64 rowing_distance = 6.0;
       int32  weapon_hp = 200;
       int32  weapon_drop_hurt = 10;
       insize Index_weapon_hit_sound = rinsize(-1);
       insize Index_weapon_drop_sound = rinsize(-1);
       insize Index_weapon_broken_sound = rinsize(-1);
       int32  starting_frame = 0;
       int32  starting_hp = 1000;
       int32  starting_mp = 150;
       
       std::vector < insize > pic;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_PIC > Pic;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_STRENGTH > Strength;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME* > Frame;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_EFFECT* > Effect;
       HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_BACKGROUND* Background = nullptr;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_LOAD
      {
       string File = "";
       uint8  Type = 0;
       uint32 W = 1;
       uint32 H = 1;
       uint32 Row = 0;
       uint32 Col = 0;
      };

      struct HEPTA_LF2_ENCHANTED_ENGINE1_GAMEEFFECT
      {
       int1   Exist = true;
       insize Section = 0;
       xint64 X = 0.0;
       xint64 Y = 0.0;
       xint64 Z = 0.0;
       insize Pic = 0;
       int1   Sprite = false;
       int1   Loop = false;
       uint32 Loop_Count = 0;
       int1   Screen = false;
       std::vector < insize > Pics;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT_EFFECT
      {
       insize ID = rinsize(-1);
       insize Effect = rinsize(-1);
       uint32 Interval = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT
      {
       int1   Exist = true;
       insize Section = 0;
       uint8  User = 0;
       string Name = "";
       HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT* Data = nullptr;

       std::vector < insize > Owners;
       insize Frame = 0;
       insize Frame2 = 0; // Last Frame, for disintegrate.
       insize Frame3 = 0;
       insize Frame4 = 0;
       insize Frame_Offset = 0;
       insize Pic_Offset = 0;
       uint32 Walk_Animation = 0;
       insize Walk_Phase = 0;
       insize Run_Animation = 0;
       insize Run_Phase = 0;
       insize Wait = 0;
       insize Lying = 0;

       uint8  Lock = 2;
       int8   Throw = 0;
       int1   Landing = false;
       int1   Heavy_Hold = false;
       int1   Super_Attack = false;
       int1   Float = false;

       xint64 X = 0.0;
       xint64 Y = 0.0;
       xint64 Z = 0.0;
       insize D = rinsize(-1);
       xint64 D_Shift_X = 0;
       xint64 D_Shift_Y = 0;
       xint64 D_Shift_Z = 0;
       xint64 X_Vel = 0.0;
       xint64 Y_Vel = 0.0;
       xint64 Z_Vel = 0.0;
       int8   Vel = 0;
       xint64 X_Acc = 0.0;
       xint64 Y_Acc = 0.0;
       xint64 Z_Acc = 0.0;

       xint64 HP = 1000.0;
       xint64 DHP = 1000.0;
       xint64 MHP = 1000.0;
       xint64 MP = 0.0;
       xint64 DMP = 500.0;
       xint64 MMP = 500.0;

       int1   Facing = false;
       int32  Blink = 0;
       insize Attacking = 0;        // Weapon attacking:.
       insize Team = rinsize(-1);   // Team.
       insize Target = rinsize(-1); // Current targeting ObjNum.
       insize Clone = rinsize(-1);  // Clone of ObjNum.
       insize Hold = rinsize(-1);   // Holding ObjNum.
       insize Held = rinsize(-1);   // Is Hold by ObjNum.
       insize Catch = rinsize(-1);  // Catching ObjNum.
       insize Caught = rinsize(-1); // Is Caught by ObjNum.
       insize Thrown = rinsize(-1); // Is Thrown by ObjNum.

       uint8  Affected = 0; // Itk14 blockade.
       uint16 Counter = 0;  // Homing counter, stop upon reaching 500.
       xint64 Fall = 0;     // Fall x Resistance.
       int8   Shake = 0;    // Hitlag.
       uint32 HP_Regen = 0; // HP regen.
       uint32 MP_Regen = 0; // MP regen
       uint16 Arest = 0;    // Attacker Rest
       std::vector < uint16 > Vrest; // Victim Rest

       insize Last_Hit = rinsize(-1);
       uint16 Last_Hit_Counter = 0;
       xint64 Scale = 1.0;
       xint64 Damage_Dealt = 1.0;
       xint64 Damage_Taken = 1.0;
       xint64 Movement_Speed = 1.0;
       xint64 HP_Restoration = 1.0;
       xint64 MP_Regeneration = 1.0;

       int1  In_A = false, In_D = false, In_J = false, In_C = false, In_Up = false, In_Left = false, In_Down = false, In_Right = false;
       uint8 Input_A = 0, Input_D = 0, Input_J = 0, Input_C = 0, Input_Up = 0, Input_Left = 0, Input_Down = 0, Input_Right = 0;
       uint8 Press_A = 0, Press_D = 0, Press_J = 0, Press_RR = 0, Press_LL = 0;
       uint8 Cast_A = 0, Cast_D = 0, Cast_J = 0, Cast_DRA = 0, Cast_DLA = 0, Cast_DRJ = 0, Cast_DLJ = 0, Cast_DDA = 0, Cast_DDJ = 0, Cast_DUA = 0, Cast_DUJ = 0, Cast_DJA = 0;
       
       std::vector < uint32 > Animation;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT_EFFECT > Effect;
       
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT* > Trans_Address; uint8 Trans = 0;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT* > Return_Address; uint8 Return = 0;
       
       int1   Stamp = false;
       uint64 Stamp_Time = 0;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Stamp_Data;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEEFFECT > Stamp_Effect;
       std::vector < uint32 > Stamp_Animation;
      };

      struct HEPTA_LF2_ENCHANTED_ENGINE1_SECTIONDATA
      {
       int1   Ready = false;
       int1   Pause = false;
       int1   TPause = false;
       uint8  Mode = ruint8(-1);
       uint8  Difficulty = 0;
       uint64 Frame = 0;
       uint64 Timeunit = 0;
       uint64 Playtime = 0;
       insize Background = 0;
       insize Max = 1500;
       insize Independent_Team = rinsize(-1);
       std::vector < string > Commands;

       int1   Mana = false;
       uint8  Coloring = 0;
       std::vector < uint32 > Animation;

       xint64 Camera[4] = {0, 0, rxint64(rinsize(-2)), 0};
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_PLAYERINPUTS
      {
       insize User = rinsize(-1);
       uint8 Up = 0;
       uint8 Left = 0;
       uint8 Down = 0;
       uint8 Right = 0;
       uint8 A = 0;
       uint8 D = 0;
       uint8 J = 0;
       uint8 C = 0;
      };
      
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEEFFECT > Effect;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Object;

      std::vector < insize > Sounds;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_LOAD > Loads;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGE > Stages;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT > Objects;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND > Backgrounds;
      std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME > > Frames;
      std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_EFFECT > > Effects;
      std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_BACKGROUND > > Object_Backgrounds;

      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_PLAYERINPUTS > Inputs;

      uint8  Decode  (statics string &Temp01) perfect
      {
       if(File001.is_open()) File001.close(); if(!L_Exist(Temp01)) return 1; File001.open(Temp01, std::ios::binary | std::ios::in); if(!File001.is_open()) return 2;
       statics string Temp02 = L_Lowercase(string(Temp01, Temp01.size() - 4, 4));
       if(Temp02 == ".dat")
       {
        stream Strn01; Strn01 << File001.rdbuf(); File001.close();
        string Temp03 = Strn01.str(); statics string Temp04 = "SiuHungIsAGoodBearBecauseHeIsVeryGood";
        statics insize Vrab01 = Temp03.size(); insize Vrab02 = 12; statics insize Vrab03 = Temp04.size();
        for(uint32 Vrab04 = 123; Vrab04 < Vrab01; ++Vrab04){Temp03.at(Vrab04) -= Temp04.at(Vrab02); Vrab02 += 1; if(Vrab02 == Vrab03) Vrab02 = 0;}
        std::ofstream File01(L_Execute(Temp001 + "temp.log"), std::ios::binary | std::ios::out); Temp03.erase(0, 123); File01 << Temp03; File01.close();
        File001.open(Temp001 + "temp.log", std::ios::binary | std::ios::in);
       } else 
       {
        stream Strn01; Strn01 << File001.rdbuf(); File001.close(); string Temp03 = Strn01.str();
        std::ofstream File01(L_Execute(Temp001 + "temp.log"), std::ios::binary | std::ios::out); File01 << Temp03; File01.close();
        File001.open(Temp001 + "temp.log", std::ios::binary | std::ios::in);
       }
       if(!File001.is_open()) return 3;
       return 0;
      }
      insize Preload (statics string &Temp01, statics uint8 Vrab01 = 0, statics uint32 Vrab02 = 1, statics uint32 Vrab03 = 1, statics uint32 Vrab04 = 0, statics uint32 Vrab05 = 0) perfect
      {
       statics insize Vrab06 = Loads.size(); insize Vrab07 = 0;
       while(Vrab07 < Vrab06)
       {
        while(true)
        {
         if(Loads[Vrab07].File != Temp01) break;
         if(Loads[Vrab07].Type != Vrab01) break;
         if(Loads[Vrab07].W != Vrab02) break;
         if(Loads[Vrab07].H != Vrab03) break;
         if(Loads[Vrab07].Row != Vrab04) break;
         if(Loads[Vrab07].Col != Vrab05) break;
         return Vrab07;
        }
        Vrab07 += 1;
       }
       Loads.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_LOAD());
       Loads[Vrab06].File = Temp01;
       Loads[Vrab06].Type = Vrab01;
       Loads[Vrab06].W = Vrab02;
       Loads[Vrab06].H = Vrab03;
       Loads[Vrab06].Row = Vrab04;
       Loads[Vrab06].Col = Vrab05;
       return Vrab06;
      }
      
      int0         Shifts (statics insize Vrab01, statics insize Vrab02 = rinsize(-1))
      {
       xint64 Vrab03[4] = {0, 0, 0, 0};
       if(Section[Vrab01].Background >= Backgrounds.size()) Section[Vrab01].Background = 0;
       Vrab03[0] = rxint64(Backgrounds[Section[Vrab01].Background].width[0]);
       Vrab03[1] = rxint64(Backgrounds[Section[Vrab01].Background].width[1]);
       Vrab03[2] = rxint64(Backgrounds[Section[Vrab01].Background].zwidth[0]);
       Vrab03[3] = rxint64(Backgrounds[Section[Vrab01].Background].zwidth[1]);

       insize Vrab04 = Object.size(); int1 Vrab05 = false;
       while(Vrab04 != 0)
       {
        if(Vrab05) break;
        Vrab04 -= 1; if(Vrab02 != rinsize(-1)){Vrab04 = Vrab02; Vrab05 = true;}
        if(Object[Vrab04].Section != Vrab01) continue; if(!Object[Vrab04].Exist) continue; if(Object[Vrab04].Lock == 0) continue;
        
        xint64 Vrab06[4] = {0, 0, 0, 0};
        if(Object[Vrab04].D == rinsize(-1))
        {
         Vrab06[0] = Vrab03[0];
         Vrab06[1] = Vrab03[1];
         Vrab06[2] = Vrab03[2];
         Vrab06[3] = Vrab03[3];
        } else
        {
         if(Object[Vrab04].D < Object.size())
         if(Object[Object[Vrab04].D].Exist)
         {
          Vrab06[0] = Object[Object[Vrab04].D].Data->Background->width[0];
          Vrab06[1] = Object[Object[Vrab04].D].Data->Background->width[1];
          Vrab06[2] = Object[Object[Vrab04].D].Data->Background->zwidth[0];
          Vrab06[3] = Object[Object[Vrab04].D].Data->Background->zwidth[1];
         }
        }

        if(Object[Vrab04].Lock == 1 || Object[Vrab04].Lock == 3)
        {
         if(Object[Vrab04].X < Vrab06[0]) Object[Vrab04].X = Vrab06[0];
         if(Object[Vrab04].X > Vrab06[1]) Object[Vrab04].X = Vrab06[1];
        }
        if(Object[Vrab04].Lock == 2 || Object[Vrab04].Lock == 3)
        {
         if(Object[Vrab04].Z < Vrab06[2]) Object[Vrab04].Z = Vrab06[2];
         if(Object[Vrab04].Z > Vrab06[3]) Object[Vrab04].Z = Vrab06[3];
        }
       }
      }
      int0         Remove (statics insize Vrab01, statics insize Vrab02 = rinsize(-1)) perfect
      {
       if(Vrab02 != rinsize(-1))
       {
        insize Vrab03 = Object.size();
        while(Vrab03 != 0){Vrab03 -= 1; if(Object[Vrab03].Exist) if(Object[Vrab03].Section == Vrab02) Remove(Vrab03);}
        Vrab03 = Effect.size();
        while(Vrab03 != 0){Vrab03 -= 1; if(Effect[Vrab03].Exist) if(Effect[Vrab03].Section == Vrab02) Effect[Vrab03].Exist = false;}
        return;
       }
       if(Vrab01 >= Object.size()) return;

       // Base Cleanup.
       Object[Vrab01].Exist = false;
       Object[Vrab01].Trans_Address.clear();
       Object[Vrab01].Return_Address.clear();
       Object[Vrab01].Stamp_Data.clear();
       Object[Vrab01].Stamp_Effect.clear();

       // Reference Cleanup
       insize Vrab03 = Object.size();
       while(Vrab03 != 0)
       {
        Vrab03 -= 1; if(!Object[Vrab03].Exist) continue;
        if(Object[Vrab03].Target == Vrab01) Object[Vrab03].Target = rinsize(-1);
        if(Object[Vrab03].Clone == Vrab01) Object[Vrab03].Clone = rinsize(-2);
        if(Vrab01 < Object[Vrab03].Vrest.size()) Object[Vrab03].Vrest[Vrab01] = 0;

        insize Vrab04 = Object[Vrab03].Owners.size();
        while(Vrab04 != 0){Vrab04 -= 1; if(Object[Vrab03].Owners[Vrab04] == Vrab01) Object[Vrab03].Owners[Vrab04] = rinsize(-1);}
       }

       // Dimension Cleanup
       Vrab03 = Object.size();
       while(Vrab03 != 0)
       {
        Vrab03 -= 1; if(Object[Vrab03].Exist) if(Object[Vrab03].D == Vrab01) Remove(Vrab03);
       }
      }
      insize       Add    (statics insize Vrab01, statics insize Vrab02 = 0) perfect
      {
       // ID search.
       int1 Vrab03 = false; insize Vrab04 = rinsize(-1);
       {
        insize Vrab05 = Objects.size();
        while(Vrab05 != 0)
        {Vrab05 -= 1; if(Objects[Vrab05].id == Vrab01){Vrab03 = true; Vrab04 = Vrab05; break;}}
       }

       if(Vrab03)
       {
        statics insize Vrab05 = Object.size(); insize Vrab06 = 0;
        while(Vrab06 < Vrab05)
        {if(!Object[Vrab06].Exist) break; Vrab06 += 1;}

        if(Vrab06 == Section[Vrab02].Max) return rinsize(-1); 
        if(Vrab06 == Vrab05)
        {Object.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT());} else
        {Object[Vrab06] = HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT();}

        Object[Vrab06].Data = &Objects[Vrab04]; Object[Vrab06].Section = Vrab02; return Vrab06;
       }
       return rinsize(-1);
      }
      int1         States (statics HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME* Vrab01, statics int32 Vrab02[], insize Vrab03) perfect
      {
       while(Vrab03 != 0)
       {
        Vrab03 -= 1; insize Vrab04 = Vrab01->state.size();
        while(Vrab04 != 0)
        {
         Vrab04 -= 1; if(Vrab01->state[Vrab04] == Vrab02[Vrab03]) return true;
        }
       }
       return false;
      };
      stacked int1 States (statics HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME* Vrab01, std::initializer_list < int32 > Vrab03)
      {
       return States(Vrab01, Vrab03.begin(), Vrab03.size());
      }
      int1         Arrays (statics std::vector < int32 > Vrab01, statics int32 Vrab02[], insize Vrab03) perfect
      {
       while(Vrab03 != 0)
       {
        Vrab03 -= 1; insize Vrab04 = Vrab01.size();
        while(Vrab04 != 0)
        {
         Vrab04 -= 1; if(Vrab01[Vrab04] == Vrab02[Vrab03]) return true;
        }
       }
       return false;
      };
      stacked int1 Arrays (statics std::vector < int32 > Vrab01, std::initializer_list < int32 > Vrab03)
      {
       return Arrays(Vrab01, Vrab03.begin(), Vrab03.size());
      }
      insize*      Pic_To_Address(insize Vrab01, statics HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT* Vect01)
      {
       remains insize Vrab02[3]; Vrab02[0] = rinsize(-1); Vrab02[1] = rinsize(-1);
       statics insize Vrab03 = Vect01->Pic.size(); insize Vrab04 = 0;
       while(Vrab04 < Vrab03)
       {
        insize Vrab05 = Vect01->Pic[Vrab04].row * Vect01->Pic[Vrab04].col;
        if(Vrab01 >= Vrab05){Vrab01 -= Vrab05; Vrab04 += 1; continue;}
        Vrab02[0] = Vect01->Pic[Vrab04].Index_pic + Vrab01; Vrab02[1] = Vect01->Pic[Vrab04].w; Vrab02[2] = Vrab04;
        break;
       }
       return Vrab02;
      }

      int0 Control(statics insize Vrab01, statics insize Vrab02)
      {
       insize Vrab03 = Inputs.size();
       while(Vrab03 != 0)
       {
        Vrab03 -= 1; if(Inputs[Vrab03].User == Vrab01)
        {
         if(Inputs[Vrab03].Up == 2)   {Object[Vrab02].In_Up = !Object[Vrab02].In_Up;} else {Object[Vrab02].In_Up = Inputs[Vrab03].Up == 1;}
         if(Inputs[Vrab03].Left == 2) {Object[Vrab02].In_Left = !Object[Vrab02].In_Left;} else {Object[Vrab02].In_Left = Inputs[Vrab03].Left == 1;}
         if(Inputs[Vrab03].Down == 2) {Object[Vrab02].In_Down = !Object[Vrab02].In_Down;} else {Object[Vrab02].In_Down = Inputs[Vrab03].Down == 1;}
         if(Inputs[Vrab03].Right == 2){Object[Vrab02].In_Right = !Object[Vrab02].In_Right;} else {Object[Vrab02].In_Right = Inputs[Vrab03].Right == 1;}
         if(Inputs[Vrab03].A == 2)    {Object[Vrab02].In_A = !Object[Vrab02].In_A;} else {Object[Vrab02].In_A = Inputs[Vrab03].A == 1;}
         if(Inputs[Vrab03].D == 2)    {Object[Vrab02].In_D = !Object[Vrab02].In_D;} else {Object[Vrab02].In_D = Inputs[Vrab03].D == 1;}
         if(Inputs[Vrab03].J == 2)    {Object[Vrab02].In_J = !Object[Vrab02].In_J;} else {Object[Vrab02].In_J = Inputs[Vrab03].J == 1;}
         if(Inputs[Vrab03].C == 2)    {Object[Vrab02].In_C = !Object[Vrab02].In_C;} else {Object[Vrab02].In_C = Inputs[Vrab03].C == 1;}
         return;
        }
       }

       // AI
       {
       
       }
      }
      int0 Emulate(statics insize Vrab01) perfect
      {
       #pragma region Sector 1 : Commands Effect (Function Keys)
       {
       
       }
       #pragma endregion
       #pragma region Sector 2 : Events
       {
        if(Section[Vrab01].Pause)
        {
        
        } else
        {
         struct Strc01 {insize Vrab001; int64 Vrab002; int64 Vrab003; int64 Vrab004; insize Vrab005;};
         std::vector < insize > Vect01; std::vector < insize > Vect02; std::vector < Strc01 > Vect03;
         Section[Vrab01].Timeunit += 1;
         
         #pragma region Phase 0 : Arranging Main Values, Random Falling Items.
         {
          // Arranging Main Values & Effect.
          {
           {insize Vrab99 = Effect.size(); while(Vrab99 != 0){Vrab99 -= 1; statics insize Vrab98 = Effect[Vrab99].Pics.size(); if(Vrab98 != Effect[Vrab99].Pic + 1){Effect[Vrab99].Pic += 1;} else {if(Effect[Vrab99].Loop && Vrab98 != 0){Effect[Vrab99].Pic = 0;} else {Effect[Vrab99].Exist = false;}}}}
           if(Section[Vrab01].Timeunit % 120 == 0)
           {
            {insize Vrab99 = Effect.size(); if(Vrab99 != 0){while(Vrab99 != 0){Vrab99 -= 1; if(Effect[Vrab99].Exist) break;} if(Vrab99 == 0) if(!Effect[Vrab99].Exist) Vrab99 -= 1; Effect.resize(Vrab99 + 1);}}
            {insize Vrab99 = Object.size(); if(Vrab99 != 0){while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Exist) break;} if(Vrab99 == 0) if(!Object[Vrab99].Exist) Vrab99 -= 1; Object.resize(Vrab99 + 1);}}
            {insize Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; insize Vrab98 = Object[Vrab99].Vrest.size(); if(Vrab98 != 0){while(Vrab98 != 0){Vrab98 -= 1; if(Object[Vrab99].Vrest[Vrab98] != 0) break;} if(Vrab98 == 0) if(Object[Vrab99].Vrest[Vrab98] == 0) Vrab98 -= 1; Object[Vrab99].Vrest.resize(Vrab98 + 1);}}}
           }
           {statics insize Vrab99 = Effect.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98) if(Effect[Vrab98].Section == Vrab01) if(Effect[Vrab98].Exist) Vect01.push_back(Vrab98);}
           {statics insize Vrab99 = Object.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98) if(Object[Vrab98].Section == Vrab01) if(Object[Vrab98].Exist) Vect02.push_back(Vrab98);}
          }

          // Random Falling Weapons.
          {
           insize Vrab99 = 0; {insize Vrab98 = Vect02.size(); while(Vrab98 != 0){Vrab98 -= 1; statics insize Vrab97 = Object[Vect02[Vrab98]].Data->type; switch(Vrab97){case 0: break; case 3: break; case 5: break; default: if(Vrab97 > 6) break; Vrab99 += 1; continue;}}}
           insize Vrab98 = Objects.size();
           while(Vrab98 != 0 && Vrab99 < 4)
           {
            Vrab98 -= 1; if(Objects[Vrab98].id < 100 || Objects[Vrab98].id > 199) continue;
            if(L_Random(549) != 0) continue; Vrab99 += 1;

            statics insize Vrab97 = Add(Objects[Vrab98].id, Vrab01); if(Vrab97 == rinsize(-1)) continue;
            Object[Vrab97].Facing = L_Random(1) == 0; Object[Vrab97].Team = rinsize(-2);
            Object[Vrab97].Y = -500;

            int1 Vrab96 = L_Random(14) == 0;
            if(Vrab96)
            {
             std::vector < insize > Vect04;
             insize Vrab95 = Vect02.size(); while(Vrab95 != 0){Vrab95 -= 1; if(Object[Vect02[Vrab95]].Data->type == 0) Vect04.push_back(Vect02[Vrab95]);}
             if(Vect04.size() != 0)
             {
              Vrab95 = Vect04[rinsize(L_Random(Vect04.size() - 1))];
              Object[Vrab97].X = Object[Vrab95].X; Object[Vrab97].Z = Object[Vrab95].Z;
             } else {Vrab96 = false;}
            } if(!Vrab96)
            {
             statics xint64 Vrab95 = (rxint64(Backgrounds[Section[Vrab01].Background].width[1] - Backgrounds[Section[Vrab01].Background].width[0]) / 30.0) * 28.0;
             statics xint64 Vrab94 = (rxint64(Backgrounds[Section[Vrab01].Background].zwidth[1] - Backgrounds[Section[Vrab01].Background].zwidth[0]) / 30.0) * 28.0;
             Object[Vrab97].X = rxint64(L_Random(rint32(Vrab95))) + rxint64(Backgrounds[Section[Vrab01].Background].width[0]) + (Vrab95 / 28.0);
             Object[Vrab97].Z = rxint64(L_Random(rint32(Vrab94))) + rxint64(Backgrounds[Section[Vrab01].Background].zwidth[0]) + (Vrab94 / 28.0);
            }
           }
          }

          // Position Shift.
          Shifts(Vrab01);

          Vect02.clear(); insize Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Section == Vrab01) if(Object[Vrab99].Exist) Vect02.push_back(Vrab99);}
         }
         #pragma endregion
         #pragma region Phase 1 : Values Control, Next, Negative MP & Repetition, Disintegrate, Opoint, Hardcoded Next, Natural Regen.
         {
          insize Vrab99 = Vect02.size(), Vrab98 = 0;
          while(Vrab98 < Vrab99)
          {
           statics insize Vrab97 = Vect02[Vrab98]; Vrab98 += 1;
           if(Vrab97 >= Object.size()) continue; if(!Object[Vrab97].Exist) continue; Object[Vrab97].Frame3 = Object[Vrab97].Frame; 

           // Duration Decrease.
           {
            if(!Polish || Section[Vrab01].Timeunit % 4 == 0)
            {
             if(Object[Vrab97].Blink > 0) Object[Vrab97].Blink -= 1;
             if(Object[Vrab97].Blink < 0) Object[Vrab97].Blink += 1;
             if(Object[Vrab97].Shake > 0){Object[Vrab97].X_Vel = 0; Object[Vrab97].Y_Vel = 0; Object[Vrab97].Z_Vel = 0; Object[Vrab97].Shake -= 1;}
             if(Object[Vrab97].Shake < 0) Object[Vrab97].Shake += 1;
             if(Object[Vrab97].Shake == 0)
             {
              Object[Vrab97].X_Vel += Object[Vrab97].X_Acc; Object[Vrab97].Y_Vel += Object[Vrab97].Y_Acc; Object[Vrab97].Z_Vel += Object[Vrab97].Z_Acc;
              Object[Vrab97].X_Acc = 0; Object[Vrab97].Y_Acc = 0; Object[Vrab97].Z_Acc = 0;
             }
            }
            if(Object[Vrab97].Arest > 0) Object[Vrab97].Arest -= 1;
            {insize Vrab96 = Object[Vrab97].Vrest.size(); while(Vrab96 != 0){Vrab96 -= 1; if(Object[Vrab97].Vrest[Vrab96] > 0) Object[Vrab97].Vrest[Vrab96] -= 1;}}
            if(Object[Vrab97].Fall > 0) if(Object[Vrab97].Fall - 1 < 0){Object[Vrab97].Fall = 0;} else {Object[Vrab97].Fall -= 1;}
            if(Object[Vrab97].Fall < 0) if(Object[Vrab97].Fall + 0.4 > 0){Object[Vrab97].Fall = 0;} else {Object[Vrab97].Fall += 0.4;}
           }

           // Next
           {
            int1 Vrab96 = false;
            while(true)
            {
             statics insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 == 1000 || Vrab95 == 9998){Vrab96 = true; break;}
             if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;

             if(Object[Vrab97].Held != rinsize(-1) || Object[Vrab97].Caught != rinsize(-1)) break;
             if(Object[Vrab97].Shake != 0 && Object[Vrab97].Data->type != 3) break;

             if(States(Object[Vrab97].Data->Frame[Vrab95], {14}))
             {
              Object[Vrab97].Lying += 1;
              if(Object[Vrab97].HP > 0) Object[Vrab97].Wait += 1;
             } else {Object[Vrab97].Lying = 0; Object[Vrab97].Wait += 1;}

             int32 Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->next[rinsize(L_Random(Object[Vrab97].Data->Frame[Vrab95]->next.size() - 1))];
             if(Vrab94 != 0)
             if(Object[Vrab97].Wait > ((ruint32(Object[Vrab97].Data->Frame[Vrab95]->wait) + 1) * (Polish ? 4 : 1)) - 1)
             {
              if(Vrab94 < 0){Vrab94 = -Vrab94; Object[Vrab97].Facing = !Object[Vrab97].Facing;}
              if(Vrab94 == 1000 || Vrab94 == 9998){Vrab96 = true; break;}

              int1 Vrab93 = (States(Object[Vrab97].Data->Frame[Vrab95], {14})) && (Object[Vrab97].Lying > 15ui32 * (Polish ? 4ui32 : 1ui32));
              while(true)
              {
               if(rinsize(Vrab94) >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[rinsize(Vrab94)]->Exist) break;
               if(States(Object[Vrab97].Data->Frame[rinsize(Vrab94)], {14})) Vrab93 = false;
               break;
              } if(Vrab93) Object[Vrab97].Blink = -15;

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
              statics int32 Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->hit_a[0];
              statics int32 Vrab93 = Object[Vrab97].Data->Frame[Vrab95]->hit_d[0];
              if(Vrab93 != 0)
              {
               Object[Vrab97].Counter += rint16(Vrab94);
               if((Object[Vrab97].Counter >= (Polish ? 2000 : 500) || Vrab94 >= (Polish ? 2000 : 500)) && Vrab95 != rinsize(L_Positive(Vrab93)))
               {
                Vrab95 = rinsize(L_Positive(Vrab93)); if(Vrab93 < 0) Object[Vrab97].Facing = !Object[Vrab97].Facing; Object[Vrab97].Wait = 0;
                Object[Vrab97].Frame = Vrab95; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;
               }
              }
             }
            
             if(Object[Vrab97].Wait != 0) break;
             statics int32 Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->mp[0];
             if(Vrab94 < 0)
             {
              int32 Vrab93 = Object[Vrab97].Data->Frame[Vrab95]->hit_d[L_Random(Object[Vrab97].Data->Frame[Vrab95]->hit_d.size() - 1)];
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
  
             xint64 Vrab95 = rxint64(Backgrounds[Section[Vrab01].Background].width[0]), Vrab94 = rxint64(Backgrounds[Section[Vrab01].Background].width[1]);
             if(Object[Vrab97].D != rinsize(-1)){Vrab95 = rxint64(Object[Object[Vrab97].D].Data->Background->width[0]); Vrab94 = rxint64(Object[Object[Vrab97].D].Data->Background->width[1]);}
             if(Object[Vrab97].Data->type != 0 && Object[Vrab97].Data->type != 3)
             {
              if(Object[Vrab97].Y >= 0){Object[Vrab97].Lying += 1;} else {Object[Vrab97].Lying = 0;}
              if(Object[Vrab97].Lying >= 60ui32 * (Polish ? 4ui32 : 1ui32))
              if(Object[Vrab97].X < Vrab95 || Object[Vrab97].X > Vrab94){Vrab96 = true; break;}
             }
             if(Object[Vrab97].Data->type != 0)
             if(Object[Vrab97].X < Vrab95 - 200 || Object[Vrab97].X > Vrab94 + 200){Vrab96 = true; break;}
  
             statics insize Vrab93 = Object[Vrab97].Frame; if(Vrab93 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab93]->Exist) break;
             insize Vrab92 = Object[Vrab97].Data->Frame[Vrab93]->state.size();
             while(Vrab92 != 0)
             {
              Vrab92 -= 1;
              switch(Object[Vrab97].Data->Frame[Vrab93]->state[Vrab92])
              {
               case 9999: if(Object[Vrab97].Y >= 0) Vrab96 = true; break;
               case 9998: Vrab96 = true; break;
               default: break;
              }
             }
             break;
            }
            while(true)
            {
             statics insize Vrab95 = Object[Vrab97].Frame2; if(Vrab95 == Object[Vrab97].Frame) break; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;
             if(States(Object[Vrab97].Data->Frame[Vrab95], {13}))
             {
              statics insize Vrab94 = 2; // Big Ice. (120 ~ 123)
              statics insize Vrab93 = 2; // Small Ice. (125 ~ 128)
              statics insize Vrab92 = 2; // Big Ice2. (130 ~ 133)
              statics insize Vrab91 = 2; // Small Ice2. (135 ~ 138)
              insize Vrab90 = 0;
              while(Vrab90 < Vrab94 + Vrab93 + Vrab92 + Vrab91)
              {
               Vrab90 += 1; 
               statics insize Vrab89 = Add(999, Vrab01);
               if(Vrab89 == rinsize(-1)) continue; Vect02.push_back(Vrab89); Vrab99 += 1;
 
               Object[Vrab89].Facing = L_Random(1) == 0;
               Object[Vrab89].Team = Object[Vrab97].Team; Object[Vrab89].Name = Object[Vrab97].Name; Object[Vrab89].Owners = Object[Vrab97].Owners; Object[Vrab89].Owners.push_back(Vrab97);
               Object[Vrab89].Scale = Object[Vrab97].Scale;
               Object[Vrab89].Frame = L_Random(3); if(Object[Vrab97].Blink > 0) Object[Vrab89].Blink = Object[Vrab97].Blink;
  
               Object[Vrab89].X = Object[Vrab97].X - 25 + rxint64(L_Random(50));
               Object[Vrab89].Y = Object[Vrab97].Y - 55 + rxint64(L_Random(50));
               Object[Vrab89].Z = Object[Vrab97].Z;
               Object[Vrab89].D = Object[Vrab97].D;
               Object[Vrab89].X_Vel = Object[Vrab97].X_Vel - 1.0 + (rxint64(L_Random(10)) * 0.2);
               Object[Vrab89].Y_Vel = Object[Vrab97].Y_Vel - 1.0 - (rxint64(L_Random(10)) * 0.3);
               Object[Vrab89].Z_Vel = Object[Vrab97].Z_Vel - 0.4 + (rxint64(L_Random(10)) * 0.08);
               if(Object[Vrab97].Shake != 0)
               {
                Object[Vrab89].X_Vel += Object[Vrab97].X_Acc;
                Object[Vrab89].Y_Vel += Object[Vrab97].Y_Acc;
                Object[Vrab89].Z_Vel += Object[Vrab97].Z_Acc;
               }
 
               if(Vrab90 <= Vrab94)
               {Object[Vrab89].Frame += 120; continue;}
               if(Vrab90 - Vrab94 <= Vrab93)
               {Object[Vrab89].Frame += 125; continue;}
               if(Vrab90 - Vrab94 - Vrab93 <= Vrab92)
               {Object[Vrab89].Frame += 130;} else {Object[Vrab89].Frame += 135;}
              }
             }
             break;
            } Object[Vrab97].Frame2 = Object[Vrab97].Frame;
            if(Vrab96){Remove(Vrab97); continue;}
           }
         
           // Opoint
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
               Object[Vrab89].Frame = rinsize(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].action[L_Random(Object[Vrab97].Data->Frame[Vrab96]->opoint[Vrab94].action.size() - 1)]); if(Object[Vrab89].Data->type == 0) if(Object[Vrab97].Blink > 0) Object[Vrab89].Blink = Object[Vrab97].Blink;
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
                int1 Vrab87 = States(Object[Vrab89].Data->Frame[Vrab88], {3000, 3006});
                if(Object[Vrab89].Data->type != 3 && Object[Vrab89].Data->type != 0) Vrab87 = true;
                if(Vrab87 && Object[Vrab89].Y <= 0) Object[Vrab89].Z_Vel = ((Object[Vrab97].Input_Down > 0 && Object[Vrab97].Input_Up == 0) ? 1.0 : ((Object[Vrab97].Input_Up > 0 && Object[Vrab97].Input_Down == 0) ? -1.0 : 0.0)) * (Object[Vrab89].Data->id == 211 ? 0.625 : 2.5);
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

           // Hardcoded Next
           {
            if(Object[Vrab97].Wait == 0)
            if(Object[Vrab97].Shake == 0 || Object[Vrab97].Data->type == 3)
            switch(Object[Vrab97].Frame)
            {
             case 212:
             {
              statics xint64 Vrab91 = Object[Vrab97].Data->jump_height;
              statics xint64 Vrab90 = Object[Vrab97].Data->jump_distance;
              statics xint64 Vrab89 = Object[Vrab97].Data->jump_distancez;
              Object[Vrab97].Y_Vel = Vrab91; Object[Vrab97].Landing = true;
              if(Object[Vrab97].Input_Left > 0 && Object[Vrab97].Input_Right == 0) if((Vrab90 > 0 && Object[Vrab97].X_Vel > -Vrab90) || (Vrab90 < 0 && Object[Vrab97].X_Vel < -Vrab90)) Object[Vrab97].X_Vel = -Vrab90;
              if(Object[Vrab97].Input_Right > 0 && Object[Vrab97].Input_Left == 0) if((Vrab90 > 0 && Object[Vrab97].X_Vel < Vrab90) || (Vrab90 < 0 && Object[Vrab97].X_Vel > Vrab90)) Object[Vrab97].X_Vel = Vrab90;
              if(Object[Vrab97].Input_Up > 0 && Object[Vrab97].Input_Down == 0) if((Vrab89 > 0 && Object[Vrab97].Z_Vel > -Vrab89) || (Vrab89 < 0 && Object[Vrab97].Z_Vel < -Vrab89)) Object[Vrab97].Z_Vel = -Vrab89;
              if(Object[Vrab97].Input_Down > 0 && Object[Vrab97].Input_Up == 0) if((Vrab89 > 0 && Object[Vrab97].Z_Vel < Vrab89) || (Vrab89 < 0 && Object[Vrab97].Z_Vel > Vrab89)) Object[Vrab97].Z_Vel = Vrab89;
             }
             break;
             case 999:
             {
              if(Object[Vrab97].Y < 0 && Object[Vrab97].Data->type == 0)
              {Object[Vrab97].Frame = 212;} else {Object[Vrab97].Frame = 0;}
              if(Object[Vrab97].Heavy_Hold) Object[Vrab97].Frame = 12;
             }
             break;
             default:
              if(Object[Vrab97].Frame >= 1100 && Object[Vrab97].Frame <= 1299)
              {
               statics int32 Vrab91 = rint32(Object[Vrab97].Frame) - 1100;
               Object[Vrab97].Blink = Vrab91; Object[Vrab97].Frame = 0;
                
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
                 Vrab88 -= 1;
                 if(Vrab89 == Vect04[Vrab88])
                 {
                  if(Object[Vect03[Vrab90]].Data->type == 0)
                  if(L_Positive(Object[Vect03[Vrab90]].Blink) < Vrab91) Object[Vect03[Vrab90]].Blink = Vrab91;
                  Vect04.push_back(Vect03[Vrab90]); Vect03.erase(Vect03.begin() + Vrab90); Vrab90 = Vect03.size();
                  break;
                 }
                }
               }
              }
             break;
            } 
           }

           // Natural Regeneration.
           {
            // Arest's Special Reset. (Reset Arest when there's no Arest-Type ITR exist.)
            {
             int1 Vrab96 = true;
             while(true)
             {
              statics insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break;
              insize Vrab94 = Object[Vrab97].Data->Frame[Vrab95]->itr.size();
              while(Vrab94 != 0){Vrab94 -= 1; if(Object[Vrab97].Data->Frame[Vrab95]->itr[Vrab94].arest != 0){Vrab96 = false; break;}} 
              break;
             } if(Vrab96) Object[Vrab97].Arest = 0;
            }
 
            if(Object[Vrab97].HP <= 0) Object[Vrab97].HP = 0;
            if(Object[Vrab97].DHP <= 0) Object[Vrab97].DHP = 0;
            if(Object[Vrab97].MHP <= 0) Object[Vrab97].MHP = 0;
            if(Object[Vrab97].DMP <= 0) Object[Vrab97].DMP = 0;
            if(Object[Vrab97].MMP <= 0) Object[Vrab97].MMP = 0;

            if(Object[Vrab97].Data->type == 0)
            if(Object[Vrab97].HP > 0)
            {
             if(Object[Vrab97].Blink <= 0)
             {
              // Natural HP Regen.
              {
               statics xint64 Vrab96 = (Polish ? (0.25 / 12.0) : (1.0 / 12.0)) * Object[Vrab97].HP_Restoration; 
               if(Object[Vrab97].HP < Object[Vrab97].DHP) if(Object[Vrab97].HP + Vrab96 > Object[Vrab97].DHP){Object[Vrab97].HP = Object[Vrab97].DHP;} else {Object[Vrab97].HP += Vrab96;}
               if(Object[Vrab97].HP > Object[Vrab97].DHP) if(Object[Vrab97].HP - Vrab96 < Object[Vrab97].DHP){Object[Vrab97].HP = Object[Vrab97].DHP;} else {Object[Vrab97].HP -= Vrab96;}
              }

              // Natural MP Regen.
              {
               statics xint64 Vrab96 = (Section[Vrab01].Mana ? (Polish ? 2.5 : 10) : (Polish ? 0.25 : 1)) * Object[Vrab97].MP_Regeneration;
               if(Object[Vrab97].MP < Object[Vrab97].DMP) if(Object[Vrab97].MP + Vrab96 > Object[Vrab97].DMP){Object[Vrab97].MP = Object[Vrab97].DMP;} else {Object[Vrab97].MP += Vrab96;}
               if(Object[Vrab97].MP > Object[Vrab97].DMP) if(Object[Vrab97].MP - Vrab96 < Object[Vrab97].DMP){Object[Vrab97].MP = Object[Vrab97].DMP;} else {Object[Vrab97].MP -= Vrab96;}
              }
             }

             // HP Regen.
             if(Object[Vrab97].HP_Regen > 0)
             {
              statics xint64 Vrab96 = ((Object[Vrab97].MHP / 1000.0) / (Polish ? 4 : 1)) * Object[Vrab97].HP_Restoration, Vrab95 = Vrab96 / 4.0;
              Object[Vrab97].HP_Regen -= 1;

              if(Object[Vrab97].HP >= Object[Vrab97].DHP)
              {Object[Vrab97].HP += Vrab95;} else
              {
               statics xint64 Vrab94 = Object[Vrab97].DHP - Object[Vrab97].HP;
               if(Vrab94 < Vrab96){Object[Vrab97].HP += Vrab94 + ((Vrab96 - Vrab94) * Vrab95);} else {Object[Vrab97].HP += Vrab96;}
              }
             }

             // MP Regen.
             if(Object[Vrab97].MP_Regen > 0)
             {
              statics xint64 Vrab96 = ((Object[Vrab97].MMP / 500.0) / (Polish ? 4 : 1)) * Object[Vrab97].MP_Regeneration, Vrab95 = Vrab96 / 4.0;
              Object[Vrab97].MP_Regen -= 1;

              if(Object[Vrab97].MP >= Object[Vrab97].DMP)
              {Object[Vrab97].MP += Vrab95;} else
              {
               statics xint64 Vrab94 = Object[Vrab97].DMP - Object[Vrab97].MP;
               if(Vrab94 < Vrab96){Object[Vrab97].MP += Vrab94 + ((Vrab96 - Vrab94) * Vrab95);} else {Object[Vrab97].MP += Vrab96;}
              }
             }

             // Reset HP & MP Regen.
             Object[Vrab97].HP_Restoration = 1.0; Object[Vrab97].MP_Regeneration = 1.0;
            }
           }
          }

          // Position Shifts.
          Shifts(Vrab01);

          Vect02.clear(); Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Section == Vrab01) if(Object[Vrab99].Exist) Vect02.push_back(Vrab99);}
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
             statics insize Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->Index_sound;
             if(Vrab96 != rinsize(-1)) Vect03.push_back({Vrab96, L_Rounding64(Object[Vrab98].X), L_Rounding64(Object[Vrab98].Y), L_Rounding64(Object[Vrab98].Z), Object[Vrab98].D});
             break;
            }
           }

           // Input.
           {
            Control(Object[Vrab98].User, Vrab98);

            if(Object[Vrab98].In_Up)   {if((++Object[Vrab98].Input_Up) == 255ui8) Object[Vrab98].Input_Up = 254ui8;} else {Object[Vrab98].Input_Up = 0ui8;}
            if(Object[Vrab98].In_Left) {if((++Object[Vrab98].Input_Left) == 255ui8) Object[Vrab98].Input_Left = 254ui8;} else {Object[Vrab98].Input_Left = 0ui8;}
            if(Object[Vrab98].In_Down) {if((++Object[Vrab98].Input_Down) == 255ui8) Object[Vrab98].Input_Down = 254ui8;} else {Object[Vrab98].Input_Down = 0ui8;}
            if(Object[Vrab98].In_Right){if((++Object[Vrab98].Input_Right) == 255ui8) Object[Vrab98].Input_Right = 254ui8;} else {Object[Vrab98].Input_Right = 0ui8;}
            if(Object[Vrab98].In_A)    {if((++Object[Vrab98].Input_A) == 255ui8) Object[Vrab98].Input_A = 254ui8;} else {Object[Vrab98].Input_A = 0ui8;}
            if(Object[Vrab98].In_D)    {if((++Object[Vrab98].Input_D) == 255ui8) Object[Vrab98].Input_D = 254ui8;} else {Object[Vrab98].Input_D = 0ui8;}
            if(Object[Vrab98].In_J)    {if((++Object[Vrab98].Input_J) == 255ui8) Object[Vrab98].Input_J = 254ui8;} else {Object[Vrab98].Input_J = 0ui8;}
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

            if(Object[Vrab98].Press_RR > 0) Object[Vrab98].Press_RR -= 1;
            if(Object[Vrab98].Press_LL > 0) Object[Vrab98].Press_LL -= 1;

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
                Vrab95 = States(Object[Vrab98].Data->Frame[Vrab94], {0, 1, 2, 4});
                if(States(Object[Vrab98].Data->Frame[Vrab94], {7})) if(Vrab94 != 110) Vrab95 = false;
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
                {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_ja[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_ja.size() - 1)])); if(Object[Vrab98].Cast_DJA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DJA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
                {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Uj[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_Uj.size() - 1)])); if(Object[Vrab98].Cast_DUJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DUJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
                {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Ua[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_Ua.size() - 1)])); if(Object[Vrab98].Cast_DUA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DUA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
                {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Dj[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_Dj.size() - 1)])); if(Object[Vrab98].Cast_DDJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DDJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
                {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Da[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_Da.size() - 1)])); if(Object[Vrab98].Cast_DDA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DDA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
                {
                 statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Fj[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_Fj.size() - 1)]));
                 if(Object[Vrab98].Cast_DLJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DLJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = false; Vrab96 = Vrab94; Vrab97 = true; break;}
                 if(Object[Vrab98].Cast_DRJ >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DRJ = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = true; Vrab96 = Vrab94; Vrab97 = true; break;}
                }
                {
                 statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_Fa[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_Fa.size() - 1)]));
                 if(Object[Vrab98].Cast_DLA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DLA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = false; Vrab96 = Vrab94; Vrab97 = true; break;}
                 if(Object[Vrab98].Cast_DRA >= 3 && Vrab94 != 0){Object[Vrab98].Cast_DRA = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Object[Vrab98].Facing = true; Vrab96 = Vrab94; Vrab97 = true; break;}
                }
               }
               {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_j[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_j.size() - 1)])); if(Object[Vrab98].Cast_J >= 1 && Vrab94 != 0){Object[Vrab98].Cast_J = 0; Object[Vrab98].Press_J = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
               {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_d[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_d.size() - 1)])); if(Object[Vrab98].Cast_D >= 1 && Vrab94 != 0){Object[Vrab98].Cast_D = 0; Object[Vrab98].Press_D = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
               {statics insize Vrab94 = rinsize(L_Positive(Object[Vrab98].Data->Frame[Vrab95]->hit_a[L_Random(Object[Vrab98].Data->Frame[Vrab95]->hit_a.size() - 1)])); if(Object[Vrab98].Cast_A >= 1 && Vrab94 != 0){Object[Vrab98].Cast_A = 0; Object[Vrab98].Press_A = 0; if(Vrab94 != 999){if(Vrab94 >= Object[Vrab98].Data->Frame.size()) continue; if(!Object[Vrab98].Data->Frame[Vrab94]->Exist) continue;} Vrab96 = Vrab94; Vrab97 = true; break;}}
  
               break;
              }
              if(!Vrab97 && Vrab96 == 69) break;

              if(Vrab97 && Vrab96 != 0)
              {
               if(Vrab96 == 999) Vrab96 = 0;
               statics insize Vrab95 = rinsize(Vrab96 < 0 ? -Vrab96 : Vrab96);
               statics int32 Vrab94 = Object[Vrab98].Data->Frame[Vrab95]->mp[0];
               int1 Vrab93 = true;
               if(States(Object[Vrab98].Data->Frame[Vrab95], {500})) Vrab93 = Object[Vrab98].Trans;
               if(States(Object[Vrab98].Data->Frame[Vrab95], {6901})) Vrab93 = Object[Vrab98].Stamp;

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
                int32 Vrab92 = rinsize(-1); int1 Vrab91 = false, Vrab90 = false, Vrab89 = false;

                // Mains.
                {
                 if(Vrab94)
                 {
                  // Facing.
                  {
                   int1 Vrab88 = false;
                 
                   switch(Vrab93){case 110: case 212: Vrab88 = true; break; default: break;}
                   if(States(Object[Vrab98].Data->Frame[Vrab93], {0, 1, 5})) Vrab88 = true;
                   if(States(Object[Vrab98].Data->Frame[Vrab93], {4})) if(Object[Vrab98].Y >= 0) Vrab88 = true;

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
                   if(States(Object[Vrab98].Data->Frame[Vrab93], {0, 1}))
                   {
                    if(Object[Vrab98].Press_LL != 0) if(Object[Vrab98].Input_Left == 1 && Object[Vrab98].Input_Right == 0){Vrab92 = 2; Object[Vrab98].Facing = false;}
                    if(Object[Vrab98].Press_RR != 0) if(Object[Vrab98].Input_Right == 1 && Object[Vrab98].Input_Left == 0){Vrab92 = 2; Object[Vrab98].Facing = true;}
                   }
                   if(States(Object[Vrab98].Data->Frame[Vrab93], {0, 1, 10, 15}))
                   {
                    if(Object[Vrab98].Input_Left == 1 && Object[Vrab98].Input_Right == 0){if(Object[Vrab98].Press_LL != 0){Object[Vrab98].Press_LL = 0;} else {Object[Vrab98].Press_LL = (Polish ? 40 : 10);} Object[Vrab98].Press_RR = 0;}
                    if(Object[Vrab98].Input_Right == 1 && Object[Vrab98].Input_Left == 0){if(Object[Vrab98].Press_RR != 0){Object[Vrab98].Press_RR = 0;} else {Object[Vrab98].Press_RR = (Polish ? 40 : 10);} Object[Vrab98].Press_LL = 0;}
                    if(Object[Vrab98].Input_Right >= 1 && Object[Vrab98].Input_Left >= 1){Object[Vrab98].Press_LL = 0; Object[Vrab98].Press_RR = 0;}
                   }
                   if(States(Object[Vrab98].Data->Frame[Vrab93], {2, Vrab92})){Object[Vrab98].Press_LL = 0; Object[Vrab98].Press_RR = 0;}
                  }
           
                  // Walking.
                  {
                   if(States(Object[Vrab98].Data->Frame[Vrab93], {0, 1}))
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
                   if(!States(Object[Vrab98].Data->Frame[Vrab93], {2}) && Vrab92 != 2) while(true){statics insize Vrab88 = Object[Vrab98].Frame; if(Vrab88 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab88]->Exist) break; if(States(Object[Vrab98].Data->Frame[Vrab88], {2})) Vrab92 = 2; break;}
                   if(States(Object[Vrab98].Data->Frame[Vrab93], {2}) || Vrab92 == 2)
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
                    if(((Vrab81 == 120 || Vrab81 == 124 || States(Object[Vrab98].Data->Frame[Vrab93], {2, Vrab92}) || (States(Object[Vrab98].Data->Frame[Vrab93], {4}) && Object[Vrab98].Y < 0)) && Vrab93 != 213 && Vrab93 != 216) || Vrab90 || Object[Object[Vrab98].Hold].Data->type == 4)
                    if((Object[Vrab98].Input_Right > 0 && Object[Vrab98].Input_Left == 0 && Object[Vrab98].Facing) || (Object[Vrab98].Input_Left > 0 && Object[Vrab98].Input_Right == 0 && !Object[Vrab98].Facing)) Vrab89 = true;
                    if(!Object[Vrab98].Heavy_Hold) break; Vrab83 = true;

                    if(States(Object[Vrab98].Data->Frame[Vrab93], {0, 1, 2, Vrab92}))
                    {
                     if(Object[Vrab98].Press_A > 0){Vrab85 = true; Object[Vrab98].Press_A = 0; Vrab84 = 50; break;}
                    }

                    break;
                   } if(Vrab83) break;
                  }

                  if(States(Object[Vrab98].Data->Frame[Vrab93], {0, 1}))
                  {
                   if(Object[Vrab98].Press_J > 0){Vrab85 = true; Object[Vrab98].Press_J = 0; Vrab84 = 210; break;}
                   if(Object[Vrab98].Press_D > 0){int1 Vrab83 = true; while(true){statics insize Vrab82 = Object[Vrab98].Frame3; if(Vrab82 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab82]->Exist) break; if(!States(Object[Vrab98].Data->Frame[Vrab82], {0, 1})) Vrab83 = false; break;} if(Vrab83){Vrab85 = true; Object[Vrab98].Press_D = 0; Vrab84 = 110; break;}}
                   if(Object[Vrab98].Press_A > 0){Vrab85 = true; Object[Vrab98].Press_A = 0; Vrab84 = Vrab91 ? (Vrab90 ? 55 : (Vrab89 ? 45 : (L_Random(1) == 0 ? 20 : 25))) : (Object[Vrab98].Super_Attack ? 70 : (L_Random(1) == 0 ? 60 : 65)); break;}
                  }
                  if(States(Object[Vrab98].Data->Frame[Vrab93], {2}) || Vrab92 == 2)
                  {
                   if(Object[Vrab98].Press_J > 0){Vrab85 = true; Object[Vrab98].Press_J = 0; Vrab88 = true; Vrab87 = Object[Vrab98].Facing; Vrab86 = true; break;}
                   if(Object[Vrab98].Press_D > 0){Vrab85 = true; Object[Vrab98].Press_D = 0; Vrab84 = 102; break;}
                   if(Object[Vrab98].Press_A > 0){Vrab85 = true; Object[Vrab98].Press_A = 0; Vrab84 = Vrab91 ? (Vrab90 ? 55 : (Vrab89 ? 45 : 35)) : 85; break;}
                  }
                  if(States(Object[Vrab98].Data->Frame[Vrab93], {4}) && Object[Vrab98].Y < 0)
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
                   statics int32 Vrab83 = Object[Vrab98].Data->Frame[Vrab84]->mp[0]; xint64 Vrab82 = 0, Vrab81 = 0, Vrab80 = 0;
                 
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
                    Vect03.push_back({Sounds[0], L_Rounding64(Object[Vrab98].X), L_Rounding64(Object[Vrab98].Y), L_Rounding64(Object[Vrab98].Z), Object[Vrab98].D});
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
          }

          // Position Shifts.
          Shifts(Vrab01);
         }
         #pragma endregion
         #pragma region Phase 3 : Hardcoded Behavour, Velocity, Move & Landing, Hardcoded State, Sound Effect, Position Shift.
         {
          struct Strc01 {xint64 Vrab001, Vrab002, Vrab003;};
          insize Vrab99 = Vect02.size();
          std::vector < Strc01 > Vect04(Vrab99); while(Vrab99 != 0){Vrab99 -= 1; Vect04[Vrab99].Vrab001 = Object[Vect02[Vrab99]].X; Vect04[Vrab99].Vrab002 = Object[Vect02[Vrab99]].Y; Vect04[Vrab99].Vrab003 = Object[Vect02[Vrab99]].Z;}
          
          Vrab99 = Vect02.size(); while(Vrab99 != 0)
          {
           Vrab99 -= 1; statics insize Vrab98 = Vect02[Vrab99];

           // Hardcoded Behavour.
           {
            while(true)
            {
             if(Object[Vrab98].Shake != 0) break;
             statics insize Vrab97 = Object[Vrab98].Frame; if(Vrab97 >= Object[Vrab98].Data->Frame.size()) break; if(!Object[Vrab98].Data->Frame[Vrab97]->Exist) break;
             insize Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->state.size();

             while(Vrab96 != 0)
             {
              Vrab96 -= 1;
              switch(Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96])
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
             }

             if(Object[Vrab98].Data->type == 0) break;
             insize Vrab95 = Object[Vrab98].Data->Frame[Vrab97]->hit_Fa.size();

             while(Vrab95 != 0)
             {
              Vrab95 -= 1;
              switch(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95])
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

                 Object[Vrab93].X = Object[Vrab98].X; Object[Vrab93].Y = Object[Vrab98].Y; Object[Vrab93].Z = Object[Vrab98].Z;
                 Object[Vrab93].X_Vel = Object[Vrab98].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab98].Y_Vel; Object[Vrab93].Z_Vel = Object[Vrab98].Z_Vel;
                }

                statics insize Vrab92 = Add(221);
                if(Vrab92 != rinsize(-1))
                {
                 Object[Vrab92].Facing = Object[Vrab92].Facing;
                 Object[Vrab92].Team = Object[Vrab98].Team; Object[Vrab92].Name = Object[Vrab98].Name; Object[Vrab92].Owners = Object[Vrab98].Owners; Object[Vrab92].Owners.push_back(Vrab98); Object[Vrab92].Scale = Object[Vrab98].Scale;
                 Object[Vrab92].Frame = 81; if(Object[Vrab98].Blink > 0) Object[Vrab92].Blink = Object[Vrab98].Blink;
                
                 Object[Vrab92].X = Object[Vrab98].X;
                 Object[Vrab92].Y = Object[Vrab98].Y - 100;
                 Object[Vrab92].Z = Object[Vrab98].Z;
                 Object[Vrab92].D = Object[Vrab98].D;
                 Object[Vrab92].X_Vel = Object[Vrab98].X_Vel; Object[Vrab92].Y_Vel = Object[Vrab98].Y_Vel; Object[Vrab92].Z_Vel = Object[Vrab98].Z_Vel;

                 Vect02.insert(Vect02.begin(), Vrab92); Vrab99 += 1;
                 Vect04.insert(Vect04.begin(), {Object[Vrab92].X, Object[Vrab92].Y, Object[Vrab92].Z});
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
                  if(Object[Vrab93].D != Object[Vrab98].D) continue;
                  if(Object[Vrab93].Blink >= 25) continue;
                  if(Object[Vrab93].Held != rinsize(-1)) continue;
                  if(Object[Vrab93].Data->type != 0) continue;
                  if(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 5){if(Object[Vrab93].Clone != rinsize(-1)) continue; if(Object[Vrab93].Team != Object[Vrab98].Team) continue;} else {if(Object[Vrab93].Team == Object[Vrab98].Team) continue;}

                  insize Vrab92 = Vect06.size(); statics xint64 Vrab91 = L_Distance(Vect04[Vrab99].Vrab001, Vect04[Vrab99].Vrab003 * 2.5, Vect04[Vrab94].Vrab001, Vect04[Vrab94].Vrab003 * 2.5);
                  while(Vrab92 != 0)
                  {
                   Vrab92 -= 1; if(Vect07[Vrab92] < Vrab91){Vrab92 += 1; Vect06.insert(Vect06.begin() + Vrab92, Vrab94); Vect07.insert(Vect07.begin() + Vrab92, Vrab91); break;}
                  } if(Vrab92 == 0){Vect06.insert(Vect06.begin(), Vrab94); Vect07.insert(Vect07.begin(), Vrab91);}
                 }
                }

                statics insize Vrab94 = Vect06.size();
                if(Vrab94 > 0)
                {
                 insize Vrab93 = Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 9 ? 4 : (Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 8 ? 3 : 1); if(Vrab94 > Vrab93) Vrab93 = Vrab94;
                 insize Vrab92 = 0; insize Vrab91 = 0;
                 while(Vrab92 < 8 || (Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 6 && Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] < 10) || Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 5 || (Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 8 && Vrab92 < 15))
                 {
                  statics insize Vrab90 = Add(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 9 ? (L_Random(1) == 0 ? 222 : 221) : (Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 8 ? 225 : (Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 6 ? 220 : 219)));
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
                   Object[Vrab90].Y_Vel = (Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 5 || Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 8) ? 0 : (-4 - rxint64(L_Random(12)));
                   Object[Vrab90].Z_Vel = Object[Vrab98].Z_Vel - 3 + L_Random(6);

                   if(Object[Vrab90].X_Vel < 0) Object[Vrab90].Facing = false;
                   if(Object[Vrab90].X_Vel > 0) Object[Vrab90].Facing = true;
                   Object[Vrab90].Target = Vect02[Vect06[Vrab91]];
                  }

                  Vrab92 += 1; if(Vrab92 == Vrab93) break;
                  Vrab91 += 1; if(Vrab91 == Vrab94) if(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 5){break;} else {Vrab91 = 0;}
                 }
                }

                Remove(Vrab98);
               }
               break;
               case 7:
               if(Polish ? (Section[Vrab01].Timeunit % 4 == 0) : true)
               {
                statics insize Vrab94 = Add(Object[Vrab98].Data->id);
                if(Vrab94 != rinsize(-1))
                {
                 Object[Vrab94].Facing = Object[Vrab98].Facing;
                 Object[Vrab94].Team = Object[Vrab98].Team; Object[Vrab94].Name = Object[Vrab98].Name; Object[Vrab94].Owners = Object[Vrab98].Owners; Object[Vrab94].Owners.push_back(Vrab98);
                 Object[Vrab94].Scale = Object[Vrab98].Scale;
                 Object[Vrab94].Frame = 40; if(Object[Vrab98].Blink > 0) Object[Vrab94].Blink = Object[Vrab98].Blink;
               
                 Object[Vrab94].X = Object[Vrab98].X; Object[Vrab94].Y = Object[Vrab98].Y; Object[Vrab94].Z = Object[Vrab98].Z; Object[Vrab94].D = Object[Vrab98].D;
                 Object[Vrab94].X_Vel = 0; Object[Vrab94].Y_Vel = 0; Object[Vrab94].Z_Vel = 0;
                }
               }
               case 14: case 13: case 12: case 10: case 4: case 3: case 2: case 1:
               {
                if(Object[Vrab98].Target == rinsize(-1) && Object[Vrab98].Counter < (Polish ? 2000 : 500))
                {
                 // Picking Target(s).
                 std::vector < insize > Vect06; std::vector < xint64 > Vect07;

                 insize Vrab94 = Vect02.size(); while(Vrab94 != 0)
                 {
                  Vrab94 -= 1; statics insize Vrab93 = Vect02[Vrab94];
                  if(Object[Vrab93].D != Object[Vrab98].D) continue;
                  if(Object[Vrab93].Blink >= 25) continue;
                  if(Object[Vrab93].Held != rinsize(-1)) continue;
                  if(Object[Vrab93].Data->type != 0) continue;
                  if(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 4){if(Object[Vrab93].Clone != rinsize(-1)) continue; if(Object[Vrab93].Team != Object[Vrab98].Team) continue;} else {if(Object[Vrab93].Team == Object[Vrab98].Team) continue;}

                  statics xint64 Vrab92 = L_Distance(Vect04[Vrab99].Vrab001, Vect04[Vrab99].Vrab003 * 2.5, Vect04[Vrab94].Vrab001, Vect04[Vrab94].Vrab003 * 2.5);

                  statics insize Vrab91 = Vect06.size(); insize Vrab90 = 0;
                  while(Vrab90 < Vrab91){if(Vect07[Vrab90] < Vrab92) break; if(Vect07[Vrab90] > Vrab92){Vect06.clear(); Vect07.clear(); Vrab90 = Vrab91; break;} Vrab90 += 1;}
                  if(Vrab90 == Vrab91){Vect06.push_back(Vrab94); Vect07.push_back(Vrab92);}
                 }

                 if(Vect06.size() > 0)
                 Object[Vrab98].Target = Vect02[Vect06[rinsize(L_Random(Vect06.size() - 1))]];
                }
              
                xint64 Vrab94 = 40;
                xint64 Vrab93 = 0, Vrab92 = 0, Vrab91 = 0, Vrab90 = 0, Vrab89 = 0, Vrab88 = 0, Vrab87 = 0, Vrab86 = 0, Vrab85 = 0;
              
                switch(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95])
                {
                 case 1:
                  Vrab93 = 13; Vrab90 = 0.85; Vrab92 = 1.2; Vrab89 = 1.2; Vrab91 = 2; Vrab88 = 0.3; Vrab94 = 10;
                 break;
                 case 2: case 12:
                  if(Object[Vrab98].Counter > (Polish ? 2000 : 500)){Vrab93 = 17; Vrab90 = 2;} else {Vrab93 = 14; Vrab90 = 0.7;} Vrab92 = 1; Vrab89 = 1; Vrab91 = 2.2; Vrab88 = 0.4;
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
                  if(Object[Vrab98].Counter > (Polish ? 2000 : 500)){Vrab93 = 17; Vrab90 = 2;} else {Vrab93 = 14; Vrab90 = 0.7;} Vrab92 = 0.1; Vrab89 = 0.1; Vrab91 = 1.5; Vrab88 = 0.4;
                 break;
                 default: break;
                }
                if(Polish)
                {Vrab90 /= 4, Vrab89 /= 4, Vrab88 /= 4, Vrab87 /= 4, Vrab86 /= 4, Vrab85 /= 4;}
              
                insize Vrab84 = rinsize(-1);
                while(true)
                {
                 insize Vrab83 = Object[Vrab98].Target; if(Vrab83 >= Object.size()) Vrab83 = rinsize(-1); if(Vrab83 < Object.size()) if(!Object[Vrab83].Exist) Vrab83 = rinsize(-1);
                 if(Vrab83 == rinsize(-1) || Object[Vrab98].Counter > (Polish ? 2000 : 500)){Object[Vrab98].Target = rinsize(-1); break;}
               
                 if(Object[Vrab83].D != Object[Vrab98].D) break;
                 if(Object[Vrab83].Blink >= 25) break;
                 if(Object[Vrab83].Held != rinsize(-1)) break;
                 if(Object[Vrab83].Data->type != 0) break;
                 if(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 4){if(Object[Vrab83].Clone != rinsize(-1)) break; if(Object[Vrab83].Team != Object[Vrab98].Team) break;} else {if(Object[Vrab83].Team == Object[Vrab98].Team) break;}

                 {
                  statics insize Vrab82 = Vect02.size(); insize Vrab81 = 0;
                  while(Vrab81 < Vrab82){if(Vect02[Vrab81] == Vrab83){Vrab84 = Vrab81; break;} Vrab81 += 1;}
                  if(Vrab81 == Vrab82) break;
                 }
                 break;
                }

                int1 Vrab83 = Object[Vrab98].X_Vel < 0;
                int1 Vrab82 = Object[Vrab98].X_Vel > 0;
                int1 Vrab81 = Vect04[Vrab99].Vrab002 >= -Vrab94 - Vrab92;
                int1 Vrab80 = Vect04[Vrab99].Vrab002 <= -Vrab94 + Vrab92;
                int1 Vrab79 = Object[Vrab98].Z_Vel < 0;
                int1 Vrab78 = Object[Vrab98].Z_Vel > 0;
                int1 Vrab77 = Vect04[Vrab99].Vrab002 < -Vrab94 && Vect04[Vrab99].Vrab002 > -Vrab94 + Vrab92;
                int1 Vrab76 = Vect04[Vrab99].Vrab002 > -Vrab94 && Vect04[Vrab99].Vrab002 < -Vrab94 - Vrab92;
              
                if(Vrab84 != rinsize(-1))
                {
                 Vrab83 = Vect04[Vrab84].Vrab001 < Vect04[Vrab99].Vrab001;
                 Vrab82 = Vect04[Vrab84].Vrab001 > Vect04[Vrab99].Vrab001;
                 Vrab81 = Vect04[Vrab84].Vrab002 <= Vect04[Vrab99].Vrab002 + Vrab94 + Vrab92;
                 Vrab80 = Vect04[Vrab84].Vrab002 >= Vect04[Vrab99].Vrab002 + Vrab94 - Vrab92;
                 Vrab79 = Vect04[Vrab84].Vrab003 < Vect04[Vrab99].Vrab003;
                 Vrab78 = Vect04[Vrab84].Vrab003 > Vect04[Vrab99].Vrab003;
                 Vrab77 = Vect04[Vrab84].Vrab002 > Vect04[Vrab99].Vrab002 + Vrab94 && Vect04[Vrab84].Vrab002 < Vect04[Vrab99].Vrab002 + Vrab94 - Vrab89;
                 Vrab76 = Vect04[Vrab84].Vrab002 < Vect04[Vrab99].Vrab002 + Vrab94 && Vect04[Vrab84].Vrab002 > Vect04[Vrab99].Vrab002 + Vrab94 + Vrab89;
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

                switch(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95])
                {
                 case 4:
                  if(Vrab84 != rinsize(-1))
                  if(Vect04[Vrab84].Vrab001 <= Vect04[Vrab99].Vrab001 + 20 && Vect04[Vrab84].Vrab001 >= Vect04[Vrab99].Vrab001 - 20)
                  if(Vect04[Vrab84].Vrab002 <= Vect04[Vrab99].Vrab002 + Vrab94 + 20 && Vect04[Vrab84].Vrab002 >= Vect04[Vrab99].Vrab002 + Vrab94 - 20)
                  if(Vect04[Vrab84].Vrab003 <= Vect04[Vrab99].Vrab003 + 8 && Vect04[Vrab84].Vrab003 >= Vect04[Vrab99].Vrab003 - 8)
                  {
                   Object[Vrab98].Frame = 60; Object[Vrab98].Wait = 0; Object[Vect02[Vrab84]].HP_Regen += 25;
                   Object[Vrab98].X = Vect04[Vrab84].Vrab001; Object[Vrab98].Y = Vect04[Vrab84].Vrab002 - Vrab94; Object[Vrab98].Z = Vect04[Vrab84].Vrab003; Object[Vrab98].X_Vel = 0; Object[Vrab98].Y_Vel = 0; Object[Vrab98].Z_Vel = 0;
                  }
                 case 2: case 12:
                  if((Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 2 || Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 12) && Object[Vrab98].Data->id == 215)
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
                  if(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 13 || Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 14)
                  {
                   if(Object[Vrab98].Data->Frame[Vrab97]->hit_Fa[Vrab95] == 13){if(Object[Vrab98].X_Vel <= 8 && Object[Vrab98].X_Vel >= -8){Object[Vrab98].Frame = 50;} else {Object[Vrab98].Frame = 0;} Object[Vrab98].Wait = 0;} else
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
              xint64 Vrab96 = rxint64(Object[Vrab98].Data->Frame[Vrab97]->hit_j[0]); if(Vrab96 == 0) Vrab96 = 50;
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
              if(Vrab91 == 3) if(Arrays(Object[Vrab98].Data->Frame[Vrab90]->hit_Fa, {7})){if(Object[Vrab98].Y <= -21){Vrab97 = false; break;}} else {if(Object[Vrab98].Y <= 0){Vrab97 = false; break;}}
            
              //statics int32 Vrab89 = Object[Vrab98].Data->Frame[Vrab90]->state;
              switch(Vrab91)
              {
               case 0: case 5:
                if(States(Object[Vrab98].Data->Frame[Vrab90], {100})) Vrab96 = 94;
                if(States(Object[Vrab98].Data->Frame[Vrab90], {6})) Vrab96 = 215;
                if(Vrab90 == 212) Vrab96 = 215;
                if(States(Object[Vrab98].Data->Frame[Vrab90], {12, 13, 14, 18}))
                if((States(Object[Vrab98].Data->Frame[Vrab90], {13}) && (Object[Vrab98].Y_Vel > 17 || Object[Vrab98].X_Vel > 9 || Object[Vrab98].X_Vel < -9)) || (!States(Object[Vrab98].Data->Frame[Vrab90], {13}) && (Object[Vrab98].Y_Vel >= 10 || Object[Vrab98].X_Vel > 9 || Object[Vrab98].X_Vel < -9)))
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
                if(Arrays(Object[Vrab98].Data->Frame[Vrab90]->hit_Fa, {7})){Vrab97 = true; Vrab94 = true; Vrab96 = 60;}
               break;
               case 1:
                if(Object[Vrab98].Y_Vel >= 10 && States(Object[Vrab98].Data->Frame[Vrab90], {1002}))
                {
                 Vrab95 = true; Vrab94 = true; Vrab96 = 0;
                }
               case 4: case 6:
                if(States(Object[Vrab98].Data->Frame[Vrab90], {1002}) && Vrab96 == 60) Vrab96 = 70;
                if(Vrab91 == 1) break;
                if(States(Object[Vrab98].Data->Frame[Vrab90], {1000, 1001, 1002, 1003, 1004}))
                if(Object[Vrab98].Y_Vel >= 9 || (Object[Vrab98].X_Vel > 11 || Object[Vrab98].X_Vel < -11))
                {
                 Vrab95 = true; Vrab94 = true; Vrab96 = 0;
                }
               default: break;
              }
             }

             break;
            } if(Vrab97)
            {
             Object[Vrab98].Frame = Vrab96; Object[Vrab98].Y = 0; Object[Vrab98].Thrown = rinsize(-1); if(Vrab95 || Object[Vrab98].Data->type == 0) Object[Vrab98].Wait = 0;
             if(Vrab95)
             {
              Object[Vrab98].X_Vel *= 0.7; Object[Vrab98].Z_Vel *= 0.7;
              if(Vrab94)
              {
               Object[Vrab98].Y_Vel = -(Object[Vrab98].Y_Vel * 0.7); if(Object[Vrab98].Data->type != 1){if(Object[Vrab98].Y_Vel < (Vrab93 ? -5 : -10)) Object[Vrab98].Y_Vel = (Vrab93 ? -5 : -10);} else {Object[Vrab98].Y_Vel = -8;}
               statics insize Vrab90 = Object[Vrab98].Data->Index_weapon_drop_sound;
               if(Vrab90 != rinsize(-1)) Vect03.push_back({Vrab90, L_Rounding64(Object[Vrab98].X), L_Rounding64(Object[Vrab98].Y), L_Rounding64(Object[Vrab98].Z), Object[Vrab98].D});
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
             
             insize Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->state.size();
             while(Vrab96 != 0)
             {
              Vrab96 -= 1;
              switch(Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96])
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
			   case 6800: if(Section[Vrab01].Coloring != 0){if(L_Random(1) == 0) Section[Vrab01].Coloring = 1;} else {Section[Vrab01].Coloring = 1;} break;
			   case 6801: if(Section[Vrab01].Coloring != 0){if(L_Random(1) == 0) Section[Vrab01].Coloring = 2;} else {Section[Vrab01].Coloring = 2;} break;
               case 6700:
                if(Polish ? (Section[Vrab01].Timeunit % 4 == 0) : true)
                if(Object[Vrab98].D != Vrab98)
                {
                 insize Vrab95 = Vect02.size(); int1 Vrab94 = true;
                 while(Vrab95 != 0)
                 {
                  Vrab95 -= 1; statics insize Vrab93 = Vect02[Vrab95];
                  if(Object[Vrab93].D == Vrab98) if(Object[Vrab93].Data->type == 0){Vrab94 = false; break;}
                 } if(Vrab94)
                 {
                  Object[Vrab98].D_Shift_X = Object[Vrab98].X;
                  Object[Vrab98].D_Shift_Y = Object[Vrab98].Y;
                  Object[Vrab98].D_Shift_Z = Object[Vrab98].Z;
                  Object[Vrab98].D = Vrab98;
                  Object[Vrab98].X = (Object[Vrab98].Data->Background->width[1] + Object[Vrab98].Data->Background->width[0]) / 2.0;
                  Object[Vrab98].Y = 0;
                  Object[Vrab98].Z = (Object[Vrab98].Data->Background->zwidth[1] + Object[Vrab98].Data->Background->zwidth[0]) / 2.0;
                  if(Object[Vrab98].Hold != rinsize(-1)) Object[Object[Vrab98].Hold].D = Vrab98;
                  if(Object[Vrab98].Catch != rinsize(-1)) Object[Object[Vrab98].Catch].D = Vrab98;
                 } else
                 {
                 
                 }
                } else
                {
                 Object[Vrab98].D = rinsize(-1);
                 Object[Vrab98].X = Object[Vrab98].D_Shift_X + (Object[Vrab98].X - ((Object[Vrab98].Data->Background->width[1] + Object[Vrab98].Data->Background->width[0]) / 2.0));
                 Object[Vrab98].Y = Object[Vrab98].D_Shift_Y + (Object[Vrab98].Y);
                 Object[Vrab98].Z = Object[Vrab98].D_Shift_Z + (Object[Vrab98].Z - ((Object[Vrab98].Data->Background->zwidth[1] + Object[Vrab98].Data->Background->zwidth[0]) / 2.0));
                 if(Object[Vrab98].Hold != rinsize(-1)) Object[Object[Vrab98].Hold].D = rinsize(-1);
                 if(Object[Vrab98].Catch != rinsize(-1)) Object[Object[Vrab98].Catch].D = rinsize(-1);
                }
               break;
               case 2000:
                if(Object[Vrab98].Y >= 0) Object[Vrab98].Frame = 20;
               break;
               case 2003: case 2004:
               {
                if(Object[Vrab98].Y >= 0) break;
                Object[Vrab98].Frame = 0;
               }
               break;
               case 1701:
                if(Object[Vrab98].Wait == 0) Object[Vrab98].HP = Object[Vrab98].DHP;
               break;
               case 1700:
                if(Object[Vrab98].Wait == 0) Object[Vrab98].HP_Regen += 75;
               break;
               case 1000: case 1003: case 1004:
               {
                if(Object[Vrab98].Y >= 0 && !States(Object[Vrab98].Data->Frame[Vrab97], {1000})) break;
                if(Object[Vrab98].Y >= 0 && States(Object[Vrab98].Data->Frame[Vrab97], {1000})) Object[Vrab98].Frame = 60;
                if(!States(Object[Vrab98].Data->Frame[Vrab97], {1000})) Object[Vrab98].Frame = 0;
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
                  if(Object[Vect02[Vrab94]].D == Object[Vrab98].D)
                  if(Object[Vect02[Vrab94]].Data->type == 0)
                  if(Object[Vect02[Vrab94]].HP > 0)
                  if(Object[Vect02[Vrab94]].Held == rinsize(-1))
                  if(States(Object[Vrab98].Data->Frame[Vrab97], {400}) ? Object[Vrab98].Team != Object[Vect02[Vrab94]].Team : (Object[Vrab98].Team == Object[Vect02[Vrab94]].Team && Vect02[Vrab94] != Vrab98))
                  {
                   statics xint64 Vrab93 = L_Distance(Vect04[Vrab99].Vrab001, Vect04[Vrab99].Vrab003 * 2.5, Vect04[Vrab94].Vrab001, Vect04[Vrab94].Vrab003 * 2.5);
                   if(Vrab93 <= Vrab95){if(Vrab93 < Vrab95) Vect06.clear(); Vect06.push_back(Vrab94); Vrab95 = Vrab93;}
                  }
                 }

                 statics insize Vrab93 = Vect06.size();
                 if(Vrab93 > 0)
                 {
                  //if(Object[Vrab98].User > 0 && Object[Vrab98].User <= 8) 
                  statics insize Vrab92 = Vect06[L_Random(Vrab93 - 1)];
                  Object[Vrab98].X = Vect04[Vrab92].Vrab001 + (Object[Vrab98].Facing ? -120 : 120);
                  Object[Vrab98].Z = Vect04[Vrab92].Vrab003;
                 }
                 Object[Vrab98].Y = 0; Object[Vrab98].X_Vel = 0; Object[Vrab98].Y_Vel = 0; Object[Vrab98].Z_Vel = 0;
                }
               break;
               case 19: case 18:
               {
                if(!States(Object[Vrab98].Data->Frame[Vrab97], {19}))
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
                if((Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96] >= 8000 && Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96] <= 8999) || (Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96] >= 4000 && Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96] <= 4999))
                {
                 insize Vrab95 = rinsize(-1); {statics insize Vrab94 = Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96] - ((Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96] > 8000) ? 8000 : 4000); statics insize Vrab93 = Objects.size(); insize Vrab92 = 0; while(Vrab92 < Vrab93){if(Objects[Vrab92].id == Vrab94){Vrab95 = Vrab92; break;} Vrab92 += 1;}}
                 Object[Vrab98].Wait = 0; Object[Vrab98].Pic_Offset = (Object[Vrab98].Data->Frame[Vrab97]->state[Vrab96] > 8000) ? 140 : 0; Object[Vrab98].Frame = Object[Vrab98].Data->Frame[Vrab97]->next[L_Random(Object[Vrab98].Data->Frame[Vrab97]->next.size() - 1)];
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
             statics insize Vrab96 = Object[Vrab98].Data->Frame[Vrab97]->Index_sound;
             if(Vrab96 != rinsize(-1)) Vect03.push_back({Vrab96, L_Rounding64(Object[Vrab98].X), L_Rounding64(Object[Vrab98].Y), L_Rounding64(Object[Vrab98].Z), Object[Vrab98].D});
             break;
            }
           }
          }

          Shifts(Vrab01);
          
          Vect04.clear(); Vect02.clear(); Vrab99 = Object.size(); while(Vrab99 != 0){Vrab99 -= 1; if(Object[Vrab99].Section == Vrab01) if(Object[Vrab99].Exist) Vect02.push_back(Vrab99);}

          // False Future.
          {
           std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Vect06;
	       struct Srct01
           {
		    uint64 Time = 0;
            std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > *Stamp_Object;
            std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEEFFECT > *Stamp_Effect;
            std::vector < uint32 > *Stamp_Animation;
		   }; std::vector < Srct01 > Vect07;
           
           int1 Vrab98 = false;
           {
            insize Vrab97 = Vect02.size();
            while(Vrab97 != 0)
            {
             Vrab97 -= 1; statics insize Vrab96 = Vect02[Vrab97]; statics insize Vrab95 = Object[Vrab96].Frame;
             if(Vrab95 >= Object[Vrab96].Data->Frame.size()) continue; if(!Object[Vrab96].Data->Frame[Vrab95]->Exist) continue;
             if(States(Object[Vrab96].Data->Frame[Vrab95], {6900})) Vrab98 = true;
             if(States(Object[Vrab96].Data->Frame[Vrab95], {6910})) if(Object[Vrab96].Stamp) Vect07.push_back({Object[Vrab96].Stamp_Time, &Object[Vrab96].Stamp_Data, &Object[Vrab96].Stamp_Effect, &Object[Vrab96].Stamp_Animation});
            }
            Vrab97 = Vect07.size();
            if(Vrab97 > 0)
            {
             uint64 Vrab96 = ruint64(-1);
             std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > *Vect08;
             std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEEFFECT > *Vect09;
             std::vector < uint32 > *Vect10;
             while(Vrab97 != 0){Vrab97 -= 1; if(Vect07[Vrab97].Time < Vrab96){Vrab96 = Vect07[Vrab97].Time; Vect08 = Vect07[Vrab97].Stamp_Object; Vect09 = Vect07[Vrab97].Stamp_Effect; Vect10 = Vect07[Vrab97].Stamp_Animation;}}
			 std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Vect11 = *Vect08;
			 Effect = *Vect09; Object = Vect11; Section[Vrab01].Timeunit = Vrab96; Section[Vrab01].Animation = *Vect10;
            }
           } if(Vrab98)
           {
            Vect06 = Object;
            insize Vrab97 = Vect02.size();
            while(Vrab97 != 0)
            {
             Vrab97 -= 1; statics insize Vrab96 = Vect02[Vrab97]; statics insize Vrab95 = Object[Vrab96].Frame;
             if(Vrab95 >= Object[Vrab96].Data->Frame.size()) continue; if(!Object[Vrab96].Data->Frame[Vrab95]->Exist) continue;
             if(States(Object[Vrab96].Data->Frame[Vrab95], {6900})){Object[Vrab96].Stamp_Data = Vect06; Object[Vrab96].Stamp_Animation = Section[Vrab01].Animation; Object[Vrab96].Stamp_Effect = Effect; Object[Vrab96].Stamp_Time = Section[Vrab01].Timeunit; Object[Vrab96].Stamp = true;}
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
           std::vector < insize > Vect04 = Vect02;
           insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
           while(Vrab97 < Vrab98)
           {
            statics insize Vrab95 = Vect04[Vrab97]; Vrab97 += 1;
          
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
              Vect04.push_back(Vrab93); Vrab98 += 1;
             }

             insize Vrab92 = 0;
             while(true)
             {
              Object[Vrab93].X = Object[Vrab95].X; Object[Vrab93].Y = Object[Vrab95].Y + 1; Object[Vrab93].Z = Object[Vrab95].Z - 1;
              Object[Vrab93].X_Vel = Object[Vrab95].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab95].Y_Vel; Object[Vrab93].Z_Vel = 0;
              Object[Vrab93].Frame = 0; Object[Vrab93].Wait = 0; Object[Vrab93].Attacking = 0; Object[Vrab93].Thrown = rinsize(-1);

              statics insize Vrab91 = Object[Vrab95].Frame;
              if(Object[Vrab95].Facing)
              {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->centerx;} else {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->centerx;}
              Object[Vrab93].Y -= Object[Vrab95].Data->Frame[Vrab91]->centery;

              if(Object[Vrab95].Facing)
              {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;} else {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;}
              Object[Vrab93].Y += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].y;
              if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10 == 1)
              {Object[Vrab93].Y -= 2; Object[Vrab93].Z += 2;}

              int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].vaction[L_Random(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].vaction.size() - 1)];
              if(Vrab90 < 0){Vrab90 = -Vrab90; Object[Vrab93].Facing = Object[Vrab95].Facing;} else {Object[Vrab93].Facing = !Object[Vrab95].Facing;}
              if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover - (Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10) == 10) Object[Vrab93].Facing = !Object[Vrab93].Facing;
              Object[Vrab93].Frame = rinsize(Vrab90); Vrab92 = rinsize(Vrab90);

              statics xint64 Vrab89 = (Object[Vrab95].Facing ? 1 : -1) * rxint64(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvx);
              statics xint64 Vrab88 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvy;
              xint64 Vrab87 = 0; if(Object[Vrab95].Input_Down > 0 && Object[Vrab95].Input_Up == 0) Vrab87 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz; if(Object[Vrab95].Input_Up > 0 && Object[Vrab95].Input_Down == 0) Vrab87 = -(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz);
              statics int32 Vrab86 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwinjury;
              if(Vrab89 != 0 || Vrab88 != 0)
              {
               Object[Vrab93].Caught = rinsize(-1); Object[Vrab93].Thrown = rinsize(-1);
               Object[Vrab93].X_Vel += Vrab89; Object[Vrab93].Y_Vel += Vrab88; Object[Vrab93].Z_Vel += Vrab87;
               if(Vrab86 == -1 || Vrab86 == -2 || Vrab86 == -3)
               {
                if(Vrab86 != -3){Object[Vrab95].Return_Address.push_back(Object[Vrab95].Data); Object[Vrab95].Return = ruint8(-rint8(Vrab86));}
                Object[Vrab95].Data = Object[Vrab93].Data;
                if(Vrab86 != -3){Object[Vrab95].Trans_Address.push_back(Object[Vrab93].Data); Object[Vrab95].Trans = 0;}
                Object[Vrab95].Frame = 0; Object[Vrab95].Wait = 0;
               } else {if(Vrab86 != 0) Object[Vrab93].Thrown = Vrab95;}
              }

              break;
             } while(true)
             {
              if(Object[Vrab93].Thrown != rinsize(-1)) break;
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
           std::vector < insize > Vect04 = Vect02;
           insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
           while(Vrab97 < Vrab98)
           {
            statics insize Vrab95 = Vect04[Vrab97]; Vrab97 += 1;

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
              Vect04.push_back(Vrab93); Vrab98 += 1;
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

              int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].weaponact[L_Random(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].weaponact.size() - 1)];
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
           struct Strc02 {int1 Vrab001 = false; xint64 Vrab002[6] = {0, 0, 0, 0, 0, 0}; int1 Vrab003 = false; xint64 Vrab004[6] = {0, 0, 0, 0, 0, 0};};
           std::vector < Strc02 > Vect04(Vrab99); std::vector < std::vector < insize > > Vect05(Vrab99);

           // Pre-Calculate Base Hitbox
           {
            insize Vrab98 = Vrab99;
            while(Vrab98 != 0)
            {
             Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98];
             statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) continue; if(!Object[Vrab97].Data->Frame[Vrab96]->Exist) continue;
             auto Vrab95 = Object[Vrab97].Data->Frame[Vrab96];
             
             if(Vrab95->itr_W > 0 && Vrab95->itr_H > 0 && Vrab95->itr_L > 0)
             {
              Vect04[Vrab98].Vrab001 = true;
              Vect04[Vrab98].Vrab002[0] = Object[Vrab97].X + ((Object[Vrab97].Facing ? 1.0 : -1.0) * Vrab95->itr_X);
              Vect04[Vrab98].Vrab002[1] = Vect04[Vrab98].Vrab002[0] + ((Object[Vrab97].Facing ? 1.0 : -1.0) * Vrab95->itr_W); if(!Object[Vrab97].Facing){auto Vrab94 = Vect04[Vrab98].Vrab002[0]; Vect04[Vrab98].Vrab002[0] = Vect04[Vrab98].Vrab002[1]; Vect04[Vrab98].Vrab002[1] = Vrab94;}
              Vect04[Vrab98].Vrab002[2] = Object[Vrab97].Y + Vrab95->itr_Y;
              Vect04[Vrab98].Vrab002[3] = Vect04[Vrab98].Vrab002[2] + Vrab95->itr_H;
              Vect04[Vrab98].Vrab002[4] = Object[Vrab97].Z + Vrab95->itr_Z;
              Vect04[Vrab98].Vrab002[5] = Vect04[Vrab98].Vrab002[4] + Vrab95->itr_L;
             }
             if(Vrab95->bdy_W > 0 && Vrab95->bdy_H > 0 && Vrab95->bdy_L > 0)
             {
              Vect04[Vrab98].Vrab003 = true;
              Vect04[Vrab98].Vrab004[0] = Object[Vrab97].X + ((Object[Vrab97].Facing ? 1.0 : -1.0) * Vrab95->bdy_X);
              Vect04[Vrab98].Vrab004[1] = Vect04[Vrab98].Vrab004[0] + ((Object[Vrab97].Facing ? 1.0 : -1.0) * Vrab95->bdy_W); if(!Object[Vrab97].Facing){auto Vrab94 = Vect04[Vrab98].Vrab004[0]; Vect04[Vrab98].Vrab004[0] = Vect04[Vrab98].Vrab004[1]; Vect04[Vrab98].Vrab004[1] = Vrab94;}
              Vect04[Vrab98].Vrab004[2] = Object[Vrab97].Y + Vrab95->bdy_Y;
              Vect04[Vrab98].Vrab004[3] = Vect04[Vrab98].Vrab004[2] + Vrab95->bdy_H;
              Vect04[Vrab98].Vrab004[4] = Object[Vrab97].Z + Vrab95->bdy_Z;
              Vect04[Vrab98].Vrab004[5] = Vect04[Vrab98].Vrab004[4] + Vrab95->bdy_L;
             }
            }
           }

           // Base Hitbox Check
           {
            insize Vrab98 = Vrab99;
            while(Vrab98 != 0)
            {
             Vrab98 -= 1; if(!Vect04[Vrab98].Vrab001) continue;

             insize Vrab97 = Vrab99;
             while(Vrab97 != 0)
             {
              Vrab97 -= 1;
              if(Vrab98 == Vrab97) continue;
              if(!Vect04[Vrab98].Vrab003) continue;
              if(Object[Vect02[Vrab98]].D != Object[Vect02[Vrab97]].D) continue;
              if(Vect04[Vrab98].Vrab002[2] > Vect04[Vrab97].Vrab004[3]) continue;
              if(Vect04[Vrab98].Vrab002[3] < Vect04[Vrab97].Vrab004[2]) continue;
              if(Vect04[Vrab98].Vrab002[0] > Vect04[Vrab97].Vrab004[1]) continue;
              if(Vect04[Vrab98].Vrab002[1] < Vect04[Vrab97].Vrab004[0]) continue;
              if(Vect04[Vrab98].Vrab002[4] > Vect04[Vrab97].Vrab004[5]) continue;
              if(Vect04[Vrab98].Vrab002[5] < Vect04[Vrab97].Vrab004[4]) continue;
              Vect05[Vrab98].push_back(Vrab97);
             }
            }
           }
           
           struct Strc03 {insize Vrab001, Vrab002;};
           std::vector < std::vector < std::vector < Strc03 > > > Vect06(Vrab99);

           // Interact Hitbox & Condition Check
           {
            insize Vrab98 = Vrab99;
            while(Vrab98 != 0)
            {
             Vrab98 -= 1; statics insize Vrab97 = Vect05[Vrab98].size(); if(Vrab97 == 0) continue;
             statics insize Vrab96 = Vect02[Vrab98], Vrab95 = Object[Vrab96].Frame;
             insize Vrab94 = Object[Vrab96].Data->Frame[Vrab95]->itr.size(); Vect06[Vrab98].resize(Vrab94);
             while(Vrab94 != 0)
             {
              Vrab94 -= 1;
              
              switch(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].kind)
              {
               case 7:
                if(Object[Vrab96].Input_A != 1) continue;
               case 2: case 6: case 8: case 14: break;
               case 1:
                if((Object[Vrab96].Input_Right == 0 || !Object[Vrab96].Facing) && (Object[Vrab96].Input_Left == 0 || Object[Vrab96].Facing)) continue;
               case 3:
               default:
                if(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].arest != 0) if(Object[Vrab96].Arest != 0) continue;
               break;
              }
              
              xint64 Vrab93[6] = {0, 0, 0, 0, 0, 0};
              Vrab93[0] = Object[Vrab96].X + ((Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].x - Object[Vrab96].Data->Frame[Vrab95]->centerx) * (Object[Vrab96].Facing ? 1.0 : -1.0));
              Vrab93[1] = Vrab93[0] + (Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].w * (Object[Vrab96].Facing ? 1.0 : -1.0)); if(!Object[Vrab96].Facing){auto Vrab92 = Vrab93[0]; Vrab93[0] = Vrab93[1]; Vrab93[1] = Vrab92;}
              Vrab93[2] = Object[Vrab96].Y + Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].y - Object[Vrab96].Data->Frame[Vrab95]->centery;
              Vrab93[3] = Vrab93[2] + Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].h;
              Vrab93[4] = Object[Vrab96].Z + Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].z - Object[Vrab96].Data->Frame[Vrab95]->centerz;
              Vrab93[5] = Vrab93[4] + Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].l;
              insize Vrab92 = Vrab97;
              while(Vrab92 != 0)
              {
               Vrab92 -= 1; statics insize Vrab90 = Vect02[Vect05[Vrab98][Vrab92]], Vrab89 = Object[Vrab90].Frame;

               switch(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].kind)
               {
                case 7: case 2: case 8: case 14: break;
                case 6:
                 if(Object[Vrab90].Data->type != 0) continue;
                 if(!(States(Object[Vrab96].Data->Frame[Vrab95], {18}) && !Arrays(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].effect, {21, 22})))
                 if(Object[Vrab90].Team == Object[Vrab96].Team) continue;
                break;
                case 1: case 3:
                 if(Object[Vrab90].Data->type != 0) continue;
                default:
                 if(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].kind == 4)
                 {
                  if(Object[Vrab96].Thrown == rinsize(-1)) continue;
                  if(Object[Vrab96].Thrown == Vrab90) continue;
                 }
                 if(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].kind == 5) if(Object[Vrab96].Attacking == 0) continue;
                 if(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].vrest != 0)
                 if(Object[Vrab90].Vrest.size() > Vrab96)
                 if(Object[Vrab90].Vrest[Vrab96] != 0) continue;
                 if(Object[Vrab90].Blink != 0) continue;
                 if(!(States(Object[Vrab96].Data->Frame[Vrab95], {18}) && !Arrays(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].effect, {21, 22})))
                 if(Object[Vrab90].Team == Object[Vrab96].Team) continue;
                break;
               }
               {
                insize Vrab88 = Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].effect.size(); int1 Vrab87 = false;
                while(Vrab88 != 0)
                {
                 Vrab88 -= 1; switch(Object[Vrab96].Data->Frame[Vrab95]->itr[Vrab94].effect[Vrab88])
                 {
                  case 4:
                   if(Object[Vrab90].Data->type == 0) Vrab87 = true;
                  break;
                  case 20: case 21:
                   if(States(Object[Vrab90].Data->Frame[Vrab89], {18})) Vrab87 = true;
                  break;
                  case 30:
                   if(States(Object[Vrab90].Data->Frame[Vrab89], {13})) Vrab87 = true;
                  break;
                  default: break;
                 }
                } if(Vrab87) continue;
               }

               insize Vrab88 = Object[Vrab90].Data->Frame[Vrab89]->bdy.size();
               while(Vrab88 != 0)
               {
                Vrab88 -= 1; xint64 Vrab87[6] = {0, 0, 0, 0, 0, 0};
                Vrab87[0] = Object[Vrab90].X + ((Object[Vrab90].Data->Frame[Vrab89]->bdy[Vrab88].x - Object[Vrab90].Data->Frame[Vrab89]->centerx) * (Object[Vrab90].Facing ? 1.0 : -1.0));
                Vrab87[1] = Vrab87[0] + (Object[Vrab90].Data->Frame[Vrab89]->bdy[Vrab88].w * (Object[Vrab90].Facing ? 1.0 : -1.0)); if(!Object[Vrab90].Facing){auto Vrab86 = Vrab87[0]; Vrab87[0] = Vrab87[1]; Vrab87[1] = Vrab86;}
                Vrab87[2] = Object[Vrab90].Y + Object[Vrab90].Data->Frame[Vrab89]->bdy[Vrab88].y - Object[Vrab90].Data->Frame[Vrab89]->centery;
                Vrab87[3] = Vrab87[2] + Object[Vrab90].Data->Frame[Vrab89]->bdy[Vrab88].h;
                Vrab87[4] = Object[Vrab90].Z + Object[Vrab90].Data->Frame[Vrab89]->bdy[Vrab88].z - Object[Vrab90].Data->Frame[Vrab89]->centerz;
                Vrab87[5] = Vrab87[4] + Object[Vrab90].Data->Frame[Vrab89]->bdy[Vrab88].l;

                if(Vrab93[0] <= Vrab87[1] && Vrab93[1] >= Vrab87[0])
                if(Vrab93[2] <= Vrab87[3] && Vrab93[3] >= Vrab87[2])
                if(Vrab93[4] <= Vrab87[5] && Vrab93[5] >= Vrab87[4])
                {Vect06[Vrab98][Vrab94].push_back({Vect05[Vrab98][Vrab92], Vrab88}); break;}
               }
              }
             }
            }
           }

           struct Strc04 {std::vector < insize > Vect001; std::vector < insize > Vect002; std::vector < insize > Vect003;};
           struct Strc05 {xint64 Vrab001, Vrab002, Vrab003;};
           struct Strc06
           {
            insize Vrab001 = rinsize(-1); // Attacker
            int1   Vrab002 = false;       // Attacker Facing
            HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT* Vrab003 = nullptr; // Itr
           };
           std::vector < insize > Vect07(Vrab99);
           std::vector < Strc04 > Vect08(Vrab99); // Frame, Held, & Caught Stack
           std::vector < Strc05 > Vect09(Vrab99);
           std::vector < std::vector < Strc06 > > Vect10(Vrab99); // Interact Hit

           // Pre-Defined Values
           {
            insize Vrab98 = Vrab99;
            while(Vrab98 != 0)
            {
             Vrab98 -= 1;
             Vect07[Vrab98] = Object[Vect02[Vrab98]].Frame;
             Vect09[Vrab98].Vrab001 = Object[Vect02[Vrab98]].X;
             Vect09[Vrab98].Vrab002 = Object[Vect02[Vrab98]].Y;
             Vect09[Vrab98].Vrab003 = Object[Vect02[Vrab98]].Z;
            }
           }

           // Interact Application
           {
            insize Vrab98 = Vrab99;
            while(Vrab98 != 0)
            {
             Vrab98 -= 1; statics insize Vrab97 = Vect06[Vrab98].size(); if(Vect06[Vrab98].size() == 0) continue;
             insize Vrab96 = 0; insize Vrab95 = 30;
             statics insize Vrab94 = Vect02[Vrab98], Vrab93 = Vect07[Vrab98];
             while(Vrab96 < Vrab97)
             {
              struct Strc05 {insize Vrab001; int1 Vrab002 = false; xint64 Vrab003;}; std::vector < Strc05 > Vect11;
              insize Vrab92 = Vect06[Vrab98][Vrab96].size();
              while(Vrab92 != 0)
              {
               Vrab92 -= 1; statics insize Vrab91 = Vect06[Vrab98][Vrab96][Vrab92].Vrab001;
               switch(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind)
               {
                case 2: case 7:
                 if(States(Object[Vect02[Vrab91]].Data->Frame[Vect07[Vrab91]], {1004}))
                 { 
                  Vect11.push_back({Vrab91, true, L_Distance(Vect09[Vrab98].Vrab001, Vect09[Vrab98].Vrab003 * 2.5, Vect09[Vrab91].Vrab001, Vect09[Vrab91].Vrab003 * 2.5)});
                 } else if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind != 7)
                 {
                  if(States(Object[Vect02[Vrab91]].Data->Frame[Vect07[Vrab91]], {2004}))
                  Vect11.push_back({Vrab91, false, L_Distance(Vect09[Vrab98].Vrab001, Vect09[Vrab98].Vrab003 * 2.5, Vect09[Vrab91].Vrab001, Vect09[Vrab91].Vrab003 * 2.5)});
                 }
                break;
                case 6: case 14:
                 Vect11.push_back({Vrab91, false, L_Distance(Vect09[Vrab98].Vrab001, Vect09[Vrab98].Vrab003 * 2.5, Vect09[Vrab91].Vrab001, Vect09[Vrab91].Vrab003 * 2.5)});
                break;
                default:
                 if(Object[Vect02[Vrab91]].Vrest.size() > Vrab94) if(Object[Vect02[Vrab91]].Vrest[Vrab94] > 0) if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].vrest != 0) break;
                 if(Object[Vect02[Vrab91]].Arest > 0) if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].arest != 0) break;
                 switch(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind)
                 {
                  case 1:
                   if(!States(Object[Vect02[Vrab91]].Data->Frame[Vect07[Vrab91]], {16})) break;
                  default:
                   Vect11.push_back({Vrab91, false, L_Distance(Vect09[Vrab98].Vrab001, Vect09[Vrab98].Vrab003 * 2.5, Vect09[Vrab91].Vrab001, Vect09[Vrab91].Vrab003 * 2.5)});
                  break;
                 }
                break;
               }
              }

              // Sorting by Distance & Apply
              {
               std::vector < Strc05* > Vect12;
               {
                insize Vrab91 = Vect11.size();
                while(Vrab91 != 0)
                {
                 Vrab91 -= 1; statics insize Vrab90 = Vect12.size(); insize Vrab89 = 0;
                 while(Vrab89 < Vrab90)
                 {
                  if(Vect11[Vrab91].Vrab003 > Vect12[Vrab89]->Vrab003) break;
                  if(Vect11[Vrab91].Vrab003 == Vect12[Vrab89]->Vrab003) if(L_Random(1) == 0) break;
                  Vrab89 += 1;
                 }
                 Vect12.insert(Vect12.begin() + Vrab89, &Vect11[Vrab91]);
                }
               }

               if(Vect12.size() != 0)
               switch(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind)
               {
                case 2: case 7:
                {
                 Vect08[Vect12[0]->Vrab001].Vect002.push_back(Vrab94); Object[Vrab94].Hold = Vect02[Vect12[0]->Vrab001];
                 statics insize Vrab91 = Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond[L_Random(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond.size() - 1)];
                 if(Vrab91 == 0)
                 {
                  if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind == 2)
                  {if(Vect12[0]->Vrab002){Object[Vrab94].Frame = 115;} else {Object[Vrab94].Frame = 116; Object[Vrab94].Heavy_Hold = true;} Object[Vrab94].Wait = 0;}
                 } else
                 {
                  if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind == 2)
                  {if(Vect12[0]->Vrab002){Object[Vrab94].Frame = Vrab91;} else {Object[Vrab94].Frame = Vrab91 + 1; Object[Vrab94].Heavy_Hold = true;}} else
                  {Object[Vrab94].Frame = Vrab91;}
                  Object[Vrab94].Wait = 0;
                 }
                }
                break;
                default:
                {
                 insize Vrab91 = 1;
                 if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind == 6) Vrab91 = Vect12.size();
                 if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].vrest != 0) Vrab91 = Vect12.size();
                 while(Vrab91 != 0)
                 {
                  Vrab91 -= 1; if(Vrab95 == 0) break; Vrab95 -= 1; statics insize Vrab90 = Vect12[Vrab91]->Vrab001;
                  switch(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind)
                  {
                   case 1: case 3:
                    Vect08[Vrab90].Vect001.push_back(Object[Vect02[Vrab90]].Facing == Object[Vrab94].Facing ? Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].caughtact[0] : Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].caughtact[1]);
                    Vect08[Vrab90].Vect003.push_back(Vrab94);
                    if(Vrab91 == 0)
                    {
                     Object[Vrab94].Catch = Vect02[Vrab90];
                     statics insize Vrab89 = Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond[L_Random(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond.size() - 1)];
                     if(Vrab89 == 0)
                     {Vect08[Vrab98].Vect001.push_back(Object[Vect02[Vrab90]].Facing == Object[Vrab94].Facing ? Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].catchingact[0] : Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].catchingact[1]);} else
                     {Vect08[Vrab98].Vect001.push_back(Vrab89);}
                    }
                   break;
                   case 6:
                    Object[Vect02[Vrab90]].Super_Attack = true;
                   break;
                   case 14:
                   {
                    statics xint64 Vrab89 = Vect09[Vrab98].Vrab001 - Vect09[Vrab90].Vrab001;
                    if((Vrab89 >= 0 && Object[Vect02[Vrab90]].X_Vel > 0) || (Vrab89 <= 0 && Object[Vect02[Vrab90]].X_Vel < 0)) if(Object[Vect02[Vrab90]].Affected != 1) if(Object[Vect02[Vrab90]].Affected == 3){Object[Vect02[Vrab90]].Affected = 1;} else {Object[Vect02[Vrab90]].Affected = 2;}
                    statics xint64 Vrab88 = Vect09[Vrab98].Vrab003 - Vect09[Vrab90].Vrab003;
                    if((Vrab88 >= 0 && Object[Vect02[Vrab90]].Z_Vel > 0) || (Vrab88 <= 0 && Object[Vect02[Vrab90]].Z_Vel < 0)) if(Object[Vect02[Vrab90]].Affected != 1) if(Object[Vect02[Vrab90]].Affected == 2){Object[Vect02[Vrab90]].Affected = 1;} else {Object[Vect02[Vrab90]].Affected = 3;} 
                   }
                   break;
                   case 12: case 13: break;
                   case 8:
                    if(Vrab91 == 0)
                    {
                     statics insize Vrab89 = Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond[L_Random(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond.size() - 1)];
                     if(Vrab89 == 0)
                     {Vect08[Vrab98].Vect001.push_back(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].dvx);} else
                     {Vect08[Vrab98].Vect001.push_back(Vrab89);}
                     if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].dvx != 0) Object[Vrab94].X = Vect09[Vrab90].Vrab001;
                     if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].dvy != 0) Object[Vrab94].Y = Vect09[Vrab90].Vrab002;
                     if(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].dvz == 0) Object[Vrab94].Z = Vect09[Vrab90].Vrab003;
                    }
                   case 9:
                    if((Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].kind) == 9)
                    if(Object[Vect02[Vrab90]].Data->type == 0) Object[Vrab94].Counter = Polish ? 2000 : 500;
                   default:
                   {
                    switch(Object[Vrab94].Data->type)
                    {
                     case 3:
                      if(Object[Vect02[Vrab90]].Data->type == 0)
                      {
                       if(States(Object[Vrab94].Data->Frame[Vrab93], {3000}))
                       {
                        Object[Vrab94].Frame = 10; Object[Vrab94].Wait = 0; Object[Vrab94].X_Vel = 0; Object[Vrab94].Y_Vel = 0; Object[Vrab94].Z_Vel = 0;
                       }
                      } else
                      {
                       if(States(Object[Vrab94].Data->Frame[Vrab93], {3000}))
                       {
                        if(States(Object[Vect02[Vrab90]].Data->Frame[Vect07[Vrab90]], {3000, 3005, 3006}))
                        {Object[Vrab94].Frame = 20; Object[Vrab94].Wait = 0; Object[Vrab94].X_Vel = 0; Object[Vrab94].Y_Vel = 0; Object[Vrab94].Z_Vel = 0;} else
                        {Object[Vrab94].Frame = 10; Object[Vrab94].Wait = 0; Object[Vrab94].X_Vel = 0; Object[Vrab94].Y_Vel = 0; Object[Vrab94].Z_Vel = 0;}
                       }
                       if(States(Object[Vrab94].Data->Frame[Vrab93], {3005}))
                       {
                        if(States(Object[Vect02[Vrab90]].Data->Frame[Vect07[Vrab90]], {3005}))
                        {Object[Vrab94].Frame = 40; Object[Vrab94].Wait = 0; Object[Vrab94].X_Vel = 0; Object[Vrab94].Y_Vel = 0; Object[Vrab94].Z_Vel = 0;}
                       }
                       if(States(Object[Vrab94].Data->Frame[Vrab93], {3006}))
                       {
                        if(States(Object[Vect02[Vrab90]].Data->Frame[Vect07[Vrab90]], {3005, 3006}))
                        {Object[Vrab94].Frame = 20; Object[Vrab94].Wait = 0; Object[Vrab94].X_Vel = 0; Object[Vrab94].Y_Vel = 0; Object[Vrab94].Z_Vel = 0;}
                       }
                      }
                     break;
                     default: break;
                    }
                    statics int32 Vrab89 = Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].arest;
                    statics int32 Vrab88 = Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].vrest;
                    if(Vrab89 > 0) Object[Vrab94].Arest = Vrab89 * (Polish ? 4 : 1);
                    if(Vrab88 > 0)
                    {
                     if(Object[Vect02[Vrab90]].Vrest.size() <= Vrab94) Object[Vect02[Vrab90]].Vrest.resize(Vrab94 + 1);
                     Object[Vect02[Vrab90]].Vrest[Vrab94] = Vrab88 * (Polish ? 4 : 1);
                    }
                    statics insize Vrab87 = Vect10[Vrab90].size(); Vect10[Vrab90].push_back(Strc06());
                    Vect10[Vrab90][Vrab87].Vrab001 = Vrab98;
                    Vect10[Vrab90][Vrab87].Vrab002 = Object[Vrab94].Facing;
                    Vect10[Vrab90][Vrab87].Vrab003 = &Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96];
                    statics insize Vrab86 = Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond[L_Random(Object[Vrab94].Data->Frame[Vrab93]->itr[Vrab96].respond.size() - 1)];
                    if(Vrab86 != 0) Vect08[Vrab98].Vect001.push_back(Vrab86);
                   }
                   break;
                  }
                 }
                }
                break;
               }
              }

              Vrab96 += 1; 
             }
            }
           }

           // Frame, Held, & Caught Randomizer
           {
            insize Vrab98 = Vrab99;
            while(Vrab98 != 0)
            {
             Vrab98 -= 1; statics insize Vrab97 = Vect02[Vrab98];
             statics insize Vrab96 = Vect08[Vrab98].Vect001.size(), Vrab95 = Vect08[Vrab98].Vect002.size(), Vrab94 = Vect08[Vrab98].Vect003.size();
             if(Vrab96 != 0){Object[Vrab97].Frame = Vect08[Vrab98].Vect001[L_Random(Vrab96 - 1)]; Object[Vrab97].Wait = 0;}
             if(Vrab95 != 0){statics insize Vrab93 = Vect08[Vrab98].Vect002[L_Random(Vrab95 - 1)]; Object[Vrab97].Held = Vrab93; Object[Vrab97].Team = Object[Vrab93].Team;}
             if(Vrab94 != 0){Object[Vrab97].Caught = Vect08[Vrab98].Vect003[L_Random(Vrab94 - 1)];}
            }
           }

           // Interaction Hit
           {
            insize Vrab98 = Vrab99;
            while(Vrab98 != 0)
            {
             Vrab98 -= 1; statics insize Vrab97 = Vect10[Vrab98].size(); if(Vrab97 == 0) continue; insize Vrab96 = 0;
             statics insize Vrab95 = Vect02[Vrab98];
             while(Vrab96 < Vrab97)
             {
              switch(Object[Vrab95].Data->type)
              {
               case 0:
               {
                xint64 Vrab94 = Vect10[Vrab98][Vrab96].Vrab003->fall; if(Vrab94 == 0) Vrab94 = 20;
                Object[Vrab95].Fall += Vrab94 * (Polish ? 4 : 1);
               }
               break;
               case 3:
               {
                statics insize Vrab94 = Vect10[Vrab98][Vrab96].Vrab001;
                if(States(Object[Vrab95].Data->Frame[Vect07[Vrab98]], {3005, 3006}))
                {
                 if(Object[Vect02[Vrab94]].Data->type == 3)
                 {
                  if(States(Object[Vrab95].Data->Frame[Vect07[Vrab98]], {3005}))
                  if(States(Object[Vect02[Vrab94]].Data->Frame[Vect07[Vrab94]], {3005}))
                  {
                   Object[Vrab95].Frame = 40; Object[Vrab95].Wait = 0; Object[Vrab95].X_Vel = 0; Object[Vrab95].Y_Vel = 0; Object[Vrab95].Z_Vel = 0;
                  }
                  if(States(Object[Vrab95].Data->Frame[Vect07[Vrab98]], {3006}))
                  if(States(Object[Vect02[Vrab94]].Data->Frame[Vect07[Vrab94]], {3005, 3006}))
                  {
                   Object[Vrab95].Frame = 20; Object[Vrab95].Wait = 0; Object[Vrab95].X_Vel = 0; Object[Vrab95].Y_Vel = 0; Object[Vrab95].Z_Vel = 0;
                  }
                 }
                 if(Vect10[Vrab98][Vrab96].Vrab003->kind == 9)
                 {
                  Object[Vrab95].Frame = 20; Object[Vrab95].Wait = 0; Object[Vrab95].X_Vel = 0; Object[Vrab95].Y_Vel = 0; Object[Vrab95].Z_Vel = 0;
                 }
                } else
                {
                 if(States(Object[Vrab95].Data->Frame[Vect07[Vrab98]], {3000}))
                 {
                  if(States(Object[Vect02[Vrab94]].Data->Frame[Vect07[Vrab94]], {3000, 3005, 3006}) && Object[Vect02[Vrab94]].Data->type == 3)
                  {Object[Vrab95].Frame = 20;} else {Object[Vrab95].Frame = 30;}
                 } else
                 {
                  if(Object[Vect02[Vrab94]].Data->type == 0){Object[Vrab95].Frame = 30;} else {Object[Vrab95].Frame = 20;}
                 }
                 Object[Vrab95].Wait = 0; Object[Vrab95].X_Vel = 0; Object[Vrab95].Y_Vel = 0; Object[Vrab95].Z_Vel = 0;
                }
               }
               break;
               case 1:

               break;
               default: break;
              }  
              Vrab96 += 1;
             }

             // Apply
             {
              switch(Object[Vrab95].Data->type)
              {
               case 0:
                if(Object[Vrab95].Fall > 0){Object[Vrab95].Wait = 0;}
                if(Object[Vrab95].Fall >= 70 * (Polish ? 4 : 1)){Object[Vrab95].Frame = 180; Object[Vrab95].Y_Vel -= 4; Object[Vrab95].Fall = 0;}
                if(Object[Vrab95].Fall > 40 * (Polish ? 4 : 1) && Object[Vrab95].Fall <= 60 * (Polish ? 4 : 1)){Object[Vrab95].Frame = 226; Object[Vrab95].Fall = 60 * (Polish ? 4 : 1);}
                if(Object[Vrab95].Fall > 20 * (Polish ? 4 : 1) && Object[Vrab95].Fall <= 40 * (Polish ? 4 : 1)){Object[Vrab95].Frame = 222; Object[Vrab95].Fall = 40 * (Polish ? 4 : 1);}
                if(Object[Vrab95].Fall > 0 * (Polish ? 4 : 1) && Object[Vrab95].Fall <= 20 * (Polish ? 4 : 1)){Object[Vrab95].Frame = 220; Object[Vrab95].Fall = 20 * (Polish ? 4 : 1);}
               break;
               case 3:
                
               break;
               case 1:

               break;
               default: break;
              }  
             }
            }
           }

           Vect04.clear(); Vect05.clear(); Vect06.clear(); Vect07.clear(); Vect08.clear(); Vect09.clear(); Vect10.clear();
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
                int1 Vrab96 = false; {while(true){statics insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95]->Exist) break; Vrab96 = States(Object[Vrab97].Data->Frame[Vrab95], {1002}); break;}}
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
           std::vector < insize > Vect04 = Vect02;
           insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
           while(Vrab97 < Vrab98)
           {
            statics insize Vrab95 = Vect04[Vrab97]; Vrab97 += 1;

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
              Vect04.push_back(Vrab93); Vrab98 += 1;
             }

             insize Vrab92 = 0;
             while(true)
             {
              Object[Vrab93].X = Object[Vrab95].X; Object[Vrab93].Y = Object[Vrab95].Y + 1; Object[Vrab93].Z = Object[Vrab95].Z - 1;
              Object[Vrab93].X_Vel = Object[Vrab95].X_Vel; Object[Vrab93].Y_Vel = Object[Vrab95].Y_Vel; Object[Vrab93].Z_Vel = 0;
              Object[Vrab93].Frame = 0; Object[Vrab93].Wait = 0; Object[Vrab93].Attacking = 0; Object[Vrab93].Thrown = rinsize(-1);

              statics insize Vrab91 = Object[Vrab95].Frame;
              if(Object[Vrab95].Facing)
              {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->centerx;} else {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->centerx;}
              Object[Vrab93].Y -= Object[Vrab95].Data->Frame[Vrab91]->centery;

              if(Object[Vrab95].Facing)
              {Object[Vrab93].X += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;} else {Object[Vrab93].X -= Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].x;}
              Object[Vrab93].Y += Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].y;
              if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10 == 1)
              {Object[Vrab93].Y -= 2; Object[Vrab93].Z += 2;}

              int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].vaction[L_Random(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].vaction.size() - 1)];
              if(Vrab90 < 0){Vrab90 = -Vrab90; Object[Vrab93].Facing = Object[Vrab95].Facing;} else {Object[Vrab93].Facing = !Object[Vrab95].Facing;}
              if(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover - (Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].cover % 10) == 10) Object[Vrab93].Facing = !Object[Vrab93].Facing;
              Object[Vrab93].Frame = rinsize(Vrab90); Vrab92 = rinsize(Vrab90);

              statics xint64 Vrab89 = (Object[Vrab95].Facing ? 1 : -1) * rxint64(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvx);
              statics xint64 Vrab88 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvy;
              xint64 Vrab87 = 0; if(Object[Vrab95].Input_Down > 0 && Object[Vrab95].Input_Up == 0) Vrab87 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz; if(Object[Vrab95].Input_Up > 0 && Object[Vrab95].Input_Down == 0) Vrab87 = -(Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwvz);
              statics int32 Vrab86 = Object[Vrab95].Data->Frame[Vrab91]->cpoint[0].throwinjury;
              if(Vrab89 != 0 || Vrab88 != 0)
              {
               Object[Vrab93].Caught = rinsize(-1); Object[Vrab93].Thrown = rinsize(-1);
               Object[Vrab93].X_Vel += Vrab89; Object[Vrab93].Y_Vel += Vrab88; Object[Vrab93].Z_Vel += Vrab87;
               if(Vrab86 == -1 || Vrab86 == -2 || Vrab86 == -3)
               {
                if(Vrab86 != -3){Object[Vrab95].Return_Address.push_back(Object[Vrab95].Data); Object[Vrab95].Return = ruint8(-rint8(Vrab86));}
                Object[Vrab95].Data = Object[Vrab93].Data;
                if(Vrab86 != -3){Object[Vrab95].Trans_Address.push_back(Object[Vrab93].Data); Object[Vrab95].Trans = 0;}
                Object[Vrab95].Frame = 0; Object[Vrab95].Wait = 0;
               } else {if(Vrab86 != 0) Object[Vrab93].Thrown = Vrab95;}
              }

              break;
             } while(true)
             {
              if(Object[Vrab93].Thrown != rinsize(-1)) break;
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
           std::vector < insize > Vect04 = Vect02;
           insize Vrab98 = Vrab99; insize Vrab97 = 0; statics insize Vrab96 = Object.size();
           while(Vrab97 < Vrab98)
           {
            statics insize Vrab95 = Vect04[Vrab97]; Vrab97 += 1;

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
              Vect04.push_back(Vrab93); Vrab98 += 1;
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

              int32 Vrab90 = Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].weaponact[L_Random(Object[Vrab95].Data->Frame[Vrab91]->wpoint[0].weaponact.size() - 1)];
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
          Shifts(Vrab01);
         }
         #pragma endregion
         #pragma region Phase EX : Camera, Sounds
         {
          std::vector < insize > Vect01;
          insize Vrab99 = rinsize(-1);

          statics insize Vrab98 = Object.size(); insize Vrab97 = 0; int1 Vrab96 = true;
          while(Vrab97 < Vrab98)
          {
           if(Object[Vrab97].Exist) if(Object[Vrab97].Section == Vrab01)
            if(Object[Vrab97].User != 0){Vrab99 = Object[Vrab97].D; Vrab96 = false; break;}
           Vrab97 += 1;
          } if(Vrab96)
          {
           Vrab97 = 0;
           while(Vrab97 < Vrab98)
           {
            if(Object[Vrab97].Exist) if(Object[Vrab97].Section == Vrab01)
             if(Object[Vrab97].Data->type == 0) if(Object[Vrab97].D == Vrab99) Vect01.push_back(Vrab97);
            Vrab97 += 1;
           }
          } else
          {
           Vrab97 = 0;
           while(Vrab97 < Vrab98)
           {
            if(Object[Vrab97].Exist) if(Object[Vrab97].Section == Vrab01)
             if(Object[Vrab97].User != 0) if(Object[Vrab97].D == Vrab99) Vect01.push_back(Vrab97);
            Vrab97 += 1;
           }
          }

          Section[Vrab01].Camera[0] = 0; Section[Vrab01].Camera[1] = 0;
          Vrab97 = Vect01.size(); insize Vrab95 = 0;
          while(Vrab97 != 0)
          {
           Vrab97 -= 1;
           Vrab95 += 1;
           Section[Vrab01].Camera[0] += Object[Vect01[Vrab97]].X - 400 + (Object[Vect01[Vrab97]].Facing ? 15 : -15);
           Section[Vrab01].Camera[1] += Object[Vect01[Vrab97]].Z - 315;
          }
          Section[Vrab01].Camera[0] = (Section[Vrab01].Camera[0] / rxint64(Vrab95)) + 400;
          Section[Vrab01].Camera[1] = (Section[Vrab01].Camera[1] / rxint64(Vrab95)) + 200;
          Section[Vrab01].Camera[2] = rxint64(Vrab99);

          Vrab97 = Vect03.size();
          while(Vrab97 != 0)
          {
           Vrab97 -= 1; if(Vect03[Vrab97].Vrab005 == Vrab99) Enchanted->Sound_Effect(Vect03[Vrab97].Vrab001);
          }
         }
         #pragma endregion

         if(Section[Vrab01].TPause){Section[Vrab01].Pause = true; Section[Vrab01].TPause = false;}
        }
       }
       #pragma endregion
      }
      int0 Context(statics insize Vrab01)
      {
       Section[Vrab01].Frame += ruint64(Vrab0003);
       if(Section[Vrab01].Frame >= Base_FPS) while(Section[Vrab01].Frame != 0)
       {
        Section[Vrab01].Frame -= Base_FPS;
        Emulate(Vrab01);
       }
      }
      int0 Loading() perfect
      {
       Load_Text = "||Loading"; Loaded = 1;
       string Temp01 = "";
       insize Vrab01 = 0;
       insize Vrab02[5] = {0, 0, 0, 0, 0};
       std::vector < string > Vect01;

       Sounds.clear();
       Objects.clear(); Stages.clear(); Loads.clear();
       Backgrounds.clear(); Backgrounds.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND());
       Frames.clear(); Frames.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME > ());
       Effects.clear(); Effects.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_EFFECT > ());
       Object_Backgrounds.clear(); Object_Backgrounds.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_BACKGROUND > ());

       while(true)
       {
        switch(Vrab01)
        {
         case 0: // Default Sound Effects -> data.txt
         {
          statics string Temp02 = Temp001 + Temp002 + "data\\";
          statics string Temp03 = ".wav";
          Sounds.push_back(Preload(Temp02 + "017" + Temp03, 1));

          Temp01 = Temp02 + "data.txt";
          {statics uint8 Vrab03 = Decode(Temp01); if(Vrab03 == 0){Load_Text = "|" + Temp01 + "|Reading \"data.txt\"|";} else {Load_Text = "F|" + Temp01 + "|Either \"data.txt\" unaccessible or missing.|" + std::to_string(Vrab03); Loaded = 2; return;}}
          Vrab01 = 1; Vrab02[0] = 0; Vrab02[1] = rinsize(-1); continue;
         }
         case 2: // data.txt check
          Load_Text = "||Finish reading \"data.txt\"|";
          if(Objects.size() == 0){Load_Text = "F||At least one <object> should exist in \"data.txt\".|"; Loaded = 2; return;}
          if(Backgrounds.size() == 1){Load_Text = "F||At least one <background> should exist in \"data.txt\".|"; Loaded = 2; return;}

          Vrab01 = 3; Vrab02[0] = 0; continue;
         case 3: case 4:
          if(Vrab02[0] >= Objects.size()) if(Vrab01 != 3){Vrab01 = 7; Vrab02[0] = 1; continue;} else
          {Load_Text = "F||At least one playable character should exist.|"; Loaded = 2; return;}
          if(Objects[Vrab02[0]].type == 0) Vrab01 = 4;

          Temp01 = Temp001 + Temp002 + Objects[Vrab02[0]].file;
          {statics uint8 Vrab03 = Decode(Temp01); if(Vrab03 == 0){Load_Text = "|" + Temp01 + "|Reading \"" + Objects[Vrab02[0]].file + "\"|";} else {Load_Text = "F|" + Temp01 + "|Either \"" + Objects[Vrab02[0]].file + "\" unaccessible or missing.|" + std::to_string(Vrab03); Loaded = 2; return;}}
          Vrab01 += 2; Vrab02[1] = 0; continue;
         case 7:
          if(Vrab02[0] >= Backgrounds.size()){Vrab01 = 9; Vrab02[0] = 0; continue;}

          Temp01 = Temp001 + Temp002 + Backgrounds[Vrab02[0]].file;
          {statics uint8 Vrab03 = Decode(Temp01); if(Vrab03 == 0){Load_Text = "|" + Temp01 + "|Reading \"" + Backgrounds[Vrab02[0]].file + "\"|";} else {Load_Text = "F|" + Temp01 + "|Either \"" + Backgrounds[Vrab02[0]].file + "\" unaccessible or missing.|" + std::to_string(Vrab03); Loaded = 2; return;}}
          Vrab01 = 8; Vrab02[1] = 0; continue;
         case 9:
          Temp01 = Temp001 + Temp002 + "data\\stage.dat";
          {statics uint8 Vrab03 = Decode(Temp01); if(Vrab03 == 0){Load_Text = "|" + Temp01 + "|Reading \"data\\stage.dat\"|";} else {Load_Text = "F|" + Temp01 + "|Either \"data\\stage.dat\" unaccessible or missing.|" + std::to_string(Vrab03); Loaded = 2; return;}}
          Vrab01 = 10; Vrab02[0] = 0; continue;
         case 11:
         {
          std::vector < insize > Vect02;

          // Load
          while(true)
          {
           statics insize Vrab03 = Loads.size(); Vrab02[0] += 1;
           if(Vrab02[0] >= Vrab03){break;} else
           {
            Load_Text = "||Loading \"" + Loads[Vrab02[0]].File + "\"|";
            switch(Loads[Vrab02[0]].Type)
            {
             case 0: Vect02.push_back(P_Load_Pic(Temp001 + Temp002 + Loads[Vrab02[0]].File)); continue;
             case 1: Vect02.push_back(P_Load_Sound(Temp001 + Temp002 + Loads[Vrab02[0]].File)); continue;
             case 2: Vect02.push_back(P_Load_Sprite(Temp001 + Temp002 + Loads[Vrab02[0]].File, Loads[Vrab02[0]].Row, Loads[Vrab02[0]].Col, Loads[Vrab02[0]].W, Loads[Vrab02[0]].H)); continue;
             default: break;
            }
           }
          }

          // Apply
          {
           statics insize Vrab04 = Vect02.size(); insize Vrab05 = 0;
           Vrab05 = Sounds.size(); while(Vrab05 != 0)
           {
            Vrab05 -= 1;
            statics insize Vrab06 = Sounds[Vrab05]; if(Vrab06 < Vrab04) Sounds[Vrab05] = Vect02[Vrab06];
           }
           Vrab05 = Objects.size(); while(Vrab05 != 0)
           {
            Vrab05 -= 1;
            {statics insize Vrab06 = Objects[Vrab05].Index_head; if(Vrab06 < Vrab04) Objects[Vrab05].Index_head = Vect02[Vrab06];}
            {statics insize Vrab06 = Objects[Vrab05].Index_small; if(Vrab06 < Vrab04) Objects[Vrab05].Index_small = Vect02[Vrab06];}
            {statics insize Vrab06 = Objects[Vrab05].Index_weapon_hit_sound; if(Vrab06 < Vrab04) Objects[Vrab05].Index_weapon_hit_sound = Vect02[Vrab06];}
            {statics insize Vrab06 = Objects[Vrab05].Index_weapon_drop_sound; if(Vrab06 < Vrab04) Objects[Vrab05].Index_weapon_drop_sound = Vect02[Vrab06];}
            {statics insize Vrab06 = Objects[Vrab05].Index_weapon_broken_sound; if(Vrab06 < Vrab04) Objects[Vrab05].Index_weapon_broken_sound = Vect02[Vrab06];}

            insize Vrab06 = Objects[Vrab05].Pic.size();
            while(Vrab06 != 0){Vrab06 -= 1; statics insize Vrab07 = Objects[Vrab05].Pic[Vrab06].Index_pic; if(Vrab07 < Vrab04) Objects[Vrab05].Pic[Vrab06].Index_pic = Vect02[Vrab07];}

            Vrab06 = Objects[Vrab05].Frame.size();
            while(Vrab06 != 0)
            {
             Vrab06 -= 1; if(Objects[Vrab05].Frame[Vrab06]->Exist)
             {
              insize Vrab07 = Objects[Vrab05].Frame[Vrab06]->Index_sound; if(Vrab07 < Vrab04) Objects[Vrab05].Frame[Vrab06]->Index_sound = Vect02[Vrab07];
              statics xint64 Vrab08 = rxint64(Objects[Vrab05].Frame[Vrab06]->centerx), Vrab09 = rxint64(Objects[Vrab05].Frame[Vrab06]->centery), Vrab10 = rxint64(Objects[Vrab05].Frame[Vrab06]->centerz);
              Vrab07 = Objects[Vrab05].Frame[Vrab06]->bdy.size();
              while(Vrab07 != 0)
              {
               Vrab07 -= 1; statics xint64 Vrab11 = Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].x - Vrab08, Vrab12 = Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].y - Vrab09, Vrab13 = Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].z - Vrab10;
               if(Vrab11 < Objects[Vrab05].Frame[Vrab06]->bdy_X) Objects[Vrab05].Frame[Vrab06]->bdy_X = Vrab11;
               if(Vrab12 < Objects[Vrab05].Frame[Vrab06]->bdy_Y) Objects[Vrab05].Frame[Vrab06]->bdy_Y = Vrab12;
               if(Vrab13 < Objects[Vrab05].Frame[Vrab06]->bdy_Z) Objects[Vrab05].Frame[Vrab06]->bdy_Z = Vrab13;
               if(Vrab11 + Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].w > Objects[Vrab05].Frame[Vrab06]->bdy_W) Objects[Vrab05].Frame[Vrab06]->bdy_W = Vrab11 + Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].w;
               if(Vrab12 + Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].h > Objects[Vrab05].Frame[Vrab06]->bdy_H) Objects[Vrab05].Frame[Vrab06]->bdy_H = Vrab12 + Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].h;
               if(Vrab13 + Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].l > Objects[Vrab05].Frame[Vrab06]->bdy_L) Objects[Vrab05].Frame[Vrab06]->bdy_L = Vrab13 + Objects[Vrab05].Frame[Vrab06]->bdy[Vrab07].l;
              }
              Vrab07 = Objects[Vrab05].Frame[Vrab06]->itr.size();
              while(Vrab07 != 0)
              {
               Vrab07 -= 1; statics xint64 Vrab11 = Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].x - Vrab08, Vrab12 = Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].y - Vrab09, Vrab13 = Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].z - Vrab10;
               if(Vrab11 < Objects[Vrab05].Frame[Vrab06]->itr_X) Objects[Vrab05].Frame[Vrab06]->itr_X = Vrab11;
               if(Vrab12 < Objects[Vrab05].Frame[Vrab06]->itr_Y) Objects[Vrab05].Frame[Vrab06]->itr_Y = Vrab12;
               if(Vrab13 < Objects[Vrab05].Frame[Vrab06]->itr_Z) Objects[Vrab05].Frame[Vrab06]->itr_Z = Vrab13;
               if(Vrab11 + Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].w > Objects[Vrab05].Frame[Vrab06]->itr_W) Objects[Vrab05].Frame[Vrab06]->itr_W = Vrab11 + Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].w;
               if(Vrab12 + Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].h > Objects[Vrab05].Frame[Vrab06]->itr_H) Objects[Vrab05].Frame[Vrab06]->itr_H = Vrab12 + Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].h;
               if(Vrab13 + Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].l > Objects[Vrab05].Frame[Vrab06]->itr_L) Objects[Vrab05].Frame[Vrab06]->itr_L = Vrab13 + Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].l;
               if(Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].arest == 0 && Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].vrest == 0) Objects[Vrab05].Frame[Vrab06]->itr[Vrab07].arest = 5;
              }
              Objects[Vrab05].Frame[Vrab06]->bdy_W = Objects[Vrab05].Frame[Vrab06]->bdy_W - Objects[Vrab05].Frame[Vrab06]->bdy_X;
              Objects[Vrab05].Frame[Vrab06]->bdy_H = Objects[Vrab05].Frame[Vrab06]->bdy_H - Objects[Vrab05].Frame[Vrab06]->bdy_Y;
              Objects[Vrab05].Frame[Vrab06]->bdy_L = Objects[Vrab05].Frame[Vrab06]->bdy_L - Objects[Vrab05].Frame[Vrab06]->bdy_Z;
              Objects[Vrab05].Frame[Vrab06]->itr_W = Objects[Vrab05].Frame[Vrab06]->itr_W - Objects[Vrab05].Frame[Vrab06]->itr_X;
              Objects[Vrab05].Frame[Vrab06]->itr_H = Objects[Vrab05].Frame[Vrab06]->itr_H - Objects[Vrab05].Frame[Vrab06]->itr_Y;
              Objects[Vrab05].Frame[Vrab06]->itr_L = Objects[Vrab05].Frame[Vrab06]->itr_L - Objects[Vrab05].Frame[Vrab06]->itr_Z;
             }
            }
           }
           Vrab05 = Object_Backgrounds.size(); while(Vrab05 != 0)
           {
            Vrab05 -= 1;
            insize Vrab06 = Object_Backgrounds[Vrab05]->Index_shadow; if(Vrab06 < Vrab04) Object_Backgrounds[Vrab05]->Index_shadow = Vect02[Vrab06];
           }
           Vrab05 = Backgrounds.size(); while(Vrab05 != 0)
           {
            Vrab05 -= 1; 
            insize Vrab06 = Backgrounds[Vrab05].Index_shadow; if(Vrab06 < Vrab04) Backgrounds[Vrab05].Index_shadow = Vect02[Vrab06];
            Vrab06 = Backgrounds[Vrab05].Layer.size();
            while(Vrab06 != 0){Vrab06 -= 1; statics insize Vrab07 = Backgrounds[Vrab05].Layer[Vrab06]->Index_pic; if(Vrab07 < Vrab04) Backgrounds[Vrab05].Layer[Vrab06]->Index_pic = Vect02[Vrab07];}
           }
           Vrab05 = Stages.size(); while(Vrab05 != 0)
           {
            Vrab05 -= 1;

            insize Vrab06 = Stages[Vrab05].Phase.size();
            while(Vrab06 != 0)
            {
             Vrab06 -= 1;

             insize Vrab07 = Stages[Vrab05].Phase[Vrab06].Subphase.size();
             while(Vrab07 != 0)
             {Vrab07 -= 1; statics insize Vrab08 = Stages[Vrab05].Phase[Vrab06].Subphase[Vrab07].Index_music; if(Vrab08 < Vrab04) Stages[Vrab05].Phase[Vrab06].Subphase[Vrab07].Index_music = Vect02[Vrab08];}
            }
           }
          }

          Loads.clear(); Loaded = 3;
         }
         return;
         case 1: // data.txt
          while(File001)
          {
           File001 >> Temp01; if(!File001) break; if(Temp01.at(0) == '#'){std::getline(File001, Temp01); continue;} if(Temp01.size() > 1) if(Temp01.at(0) == '/' && Temp01.at(1) == '/'){std::getline(File001, Temp01); continue;}
           switch(Vrab02[0])
           {
            case 0:
             if(Temp01 == "<object>")    {Vrab02[0] = 1; continue;}
             if(Temp01 == "<background>"){Vrab02[0] = 2; continue;}
            break;
            case 1:
             if(Temp01 == "<object_end>"){Vrab02[0] = 0; continue;}
             if(Temp01 == "id:")         {File001 >> Temp01; Vrab02[1] = Objects.size(); Objects.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT()); Objects[Vrab02[1]].id = rinsize(L_Numbering(Temp01)); Objects[Vrab02[1]].Background = Object_Backgrounds[0].get(); continue;}
             if(Temp01 == "type:")       {File001 >> Temp01; if(Vrab02[1] < Objects.size()) Objects[Vrab02[1]].type = L_Numbering(Temp01); continue;}
             if(Temp01 == "file:")       {File001 >> Temp01; if(Vrab02[1] < Objects.size()) Objects[Vrab02[1]].file = Temp01; continue;}
            break;
            case 2:
             if(Temp01 == "<background_end>"){Vrab02[0] = 0; continue;}
             if(Temp01 == "id:")             {File001 >> Temp01; Vrab02[1] = Backgrounds.size(); Backgrounds.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND()); Backgrounds[Vrab02[1]].id = rinsize(L_Numbering(Temp01)); continue;}
             if(Temp01 == "file:")           {File001 >> Temp01; if(Vrab02[1] < Backgrounds.size()) Backgrounds[Vrab02[1]].file = Temp01; continue;}
            break;
            default: break;
           }
          }
          if(!File001){Vrab01 = 2; continue;}
         break;
         case 5: case 6: // object.dat
          while(File001)
          {
           File001 >> Temp01; if(!File001) break; if(Temp01.at(0) == '#'){std::getline(File001, Temp01); continue;} if(Temp01.size() > 1) if(Temp01.at(0) == '/' && Temp01.at(1) == '/'){std::getline(File001, Temp01); continue;}
           switch(Vrab02[1])
           {
            case 0:
             if(Temp01 == "<property>" || Temp01 == "<bmp_begin>")            {Vrab02[1] = 1; Vrab02[2] = rinsize(-1); Objects[Vrab02[0]].Pic.clear(); Vect01.clear(); continue;}
             if(Temp01 == "<strength>" || Temp01 == "<weapon_strength_list>") {Vrab02[1] = 3; Vrab02[2] = rinsize(-1); continue;}
             if(Temp01 == "<frame>")                                          
             {
              Vrab02[1] = 5;
              File001 >> Temp01;
              statics insize Vrab03 = rinsize(L_Numbering(Temp01));
              statics insize Vrab04 = Objects[Vrab02[0]].Frame.size();
              if(Vrab04 <= Vrab03)
              {
               Objects[Vrab02[0]].Frame.insert(Objects[Vrab02[0]].Frame.end(), Vrab03 + 1 - Vrab04, Frames[0].get());
              } Vrab02[2] = Vrab03;
              if(Objects[Vrab02[0]].Frame[Vrab02[2]] == Frames[0].get())
              {
               insize Vrab05 = Frames.size();
               Frames.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME > ());
               Objects[Vrab02[0]].Frame[Vrab02[2]] = Frames[Vrab05].get();
              } else {*Objects[Vrab02[0]].Frame[Vrab02[2]] = HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME();}
              Objects[Vrab02[0]].Frame[Vrab02[2]]->Exist = true; File001 >> Temp01; continue;
             }
             if(Temp01 == "<background>")                                     {Vrab02[1] = 54; if(Objects[Vrab02[0]].Background == Object_Backgrounds[0].get()){insize Vrab03 = Object_Backgrounds.size(); Object_Backgrounds.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_BACKGROUND > ()); Objects[Vrab02[0]].Background = Object_Backgrounds[Vrab03].get();} else {*Objects[Vrab02[0]].Background = HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_BACKGROUND();} continue;}
             if(Temp01 == "<effect>")                                         {Vrab02[1] = 52; File001 >> Temp01; statics insize Vrab03 = rinsize(L_Numbering(Temp01)); statics insize Vrab04 = Objects[Vrab02[0]].Effect.size(); if(Vrab04 <= Vrab03){Objects[Vrab02[0]].Effect.insert(Objects[Vrab02[0]].Effect.end(), Vrab03 + 1 - Vrab04, Effects[0].get());} Vrab02[2] = Vrab03; if(Objects[Vrab02[0]].Effect[Vrab02[2]] == Effects[0].get()){insize Vrab05 = Effect.size(); Effects.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_EFFECT > ()); Objects[Vrab02[0]].Effect[Vrab02[2]] = Effects[Vrab05].get();} else {*Objects[Vrab02[0]].Effect[Vrab02[2]] = HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_EFFECT();} Objects[Vrab02[0]].Effect[Vrab02[2]]->Exist = true; File001 >> Temp01; continue;}
            break;
            case 1:
             if(Temp01 == "<property_end>" || Temp01 == "<bmp_end>") {Vrab02[1] = 0; insize Vrab03 = Objects[Vrab02[0]].Pic.size(); while(Vrab03 != 0){Vrab03 -= 1; Objects[Vrab02[0]].Pic[Vrab03].Index_pic = Preload(Vect01[Vrab03], 2, Objects[Vrab02[0]].Pic[Vrab03].w, Objects[Vrab02[0]].Pic[Vrab03].h, Objects[Vrab02[0]].Pic[Vrab03].row, Objects[Vrab02[0]].Pic[Vrab03].col);} Vect01.clear(); continue;}
             if(Temp01 == "name:")                {File001 >> Objects[Vrab02[0]].name; continue;}
             if(Temp01 == "head:")                {File001 >> Temp01; Objects[Vrab02[0]].Index_head = Preload(Temp01); continue;}
             if(Temp01 == "small:")               {File001 >> Temp01; Objects[Vrab02[0]].Index_small = Preload(Temp01); continue;}
             if(Temp01 == "movement_speed:")      {File001 >> Temp01; Objects[Vrab02[0]].movement_speed = L_Doubling(Temp01); continue;}
             if(Temp01 == "movement_speedz:")     {File001 >> Temp01; Objects[Vrab02[0]].movement_speedz = L_Doubling(Temp01); continue;}
             if(Temp01 == "heavy_movement_speed:"){File001 >> Temp01; Objects[Vrab02[0]].heavy_movement_speed = L_Doubling(Temp01); continue;}
             if(Temp01 == "walking_frame_rate")   {File001 >> Temp01; Objects[Vrab02[0]].walking_frame_rate = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "running_frame_rate")   {File001 >> Temp01; Objects[Vrab02[0]].running_frame_rate = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "walking_speed")        {File001 >> Temp01; Objects[Vrab02[0]].walking_speed = L_Doubling(Temp01); continue;}
             if(Temp01 == "walking_speedz")       {File001 >> Temp01; Objects[Vrab02[0]].walking_speedz = L_Doubling(Temp01); continue;}
             if(Temp01 == "running_speed")        {File001 >> Temp01; Objects[Vrab02[0]].running_speed = L_Doubling(Temp01); continue;}
             if(Temp01 == "running_speedz")       {File001 >> Temp01; Objects[Vrab02[0]].running_speedz = L_Doubling(Temp01); continue;}
             if(Temp01 == "heavy_walking_speed")  {File001 >> Temp01; Objects[Vrab02[0]].heavy_walking_speed = L_Doubling(Temp01); continue;}
             if(Temp01 == "heavy_walking_speedz") {File001 >> Temp01; Objects[Vrab02[0]].heavy_walking_speedz = L_Doubling(Temp01); continue;}
             if(Temp01 == "heavy_running_speed")  {File001 >> Temp01; Objects[Vrab02[0]].heavy_running_speed = L_Doubling(Temp01); continue;}
             if(Temp01 == "heavy_running_speedz") {File001 >> Temp01; Objects[Vrab02[0]].heavy_running_speedz = L_Doubling(Temp01); continue;}
             if(Temp01 == "base_jump_height")     {File001 >> Temp01; Objects[Vrab02[0]].base_jump_height = L_Doubling(Temp01); continue;}
             if(Temp01 == "jump_height")          {File001 >> Temp01; Objects[Vrab02[0]].jump_height = L_Doubling(Temp01); Objects[Vrab02[0]].base_jump_height = 0.0; continue;}
             if(Temp01 == "jump_distance")        {File001 >> Temp01; Objects[Vrab02[0]].jump_distance = L_Doubling(Temp01); continue;}
             if(Temp01 == "jump_distancez")       {File001 >> Temp01; Objects[Vrab02[0]].jump_distancez = L_Doubling(Temp01); continue;}
             if(Temp01 == "base_dash_height")     {File001 >> Temp01; Objects[Vrab02[0]].base_dash_height = L_Doubling(Temp01); continue;}
             if(Temp01 == "dash_height")          {File001 >> Temp01; Objects[Vrab02[0]].dash_height = L_Doubling(Temp01); Objects[Vrab02[0]].base_dash_height = 0.0; continue;}
             if(Temp01 == "dash_distance")        {File001 >> Temp01; Objects[Vrab02[0]].dash_distance = L_Doubling(Temp01); continue;}
             if(Temp01 == "dash_distancez")       {File001 >> Temp01; Objects[Vrab02[0]].dash_distancez = L_Doubling(Temp01); continue;}
             if(Temp01 == "rowing_height")        {File001 >> Temp01; Objects[Vrab02[0]].rowing_height = L_Doubling(Temp01); continue;}
             if(Temp01 == "rowing_distance")      {File001 >> Temp01; Objects[Vrab02[0]].rowing_distance = L_Doubling(Temp01); continue;}
             if(Temp01 == "weapon_hp:")           {File001 >> Temp01; Objects[Vrab02[0]].weapon_hp = L_Numbering(Temp01); continue;}
             if(Temp01 == "weapon_drop_hurt:")    {File001 >> Temp01; Objects[Vrab02[0]].weapon_drop_hurt = L_Numbering(Temp01); continue;}
             if(Temp01 == "weapon_hit_sound:")    {File001 >> Temp01; Objects[Vrab02[0]].Index_weapon_hit_sound = Preload(Temp01, 1); continue;}
             if(Temp01 == "weapon_drop_sound:")   {File001 >> Temp01; Objects[Vrab02[0]].Index_weapon_drop_sound = Preload(Temp01, 1); continue;}
             if(Temp01 == "weapon_broken_sound:") {File001 >> Temp01; Objects[Vrab02[0]].Index_weapon_broken_sound = Preload(Temp01, 1); continue;}
             if(Temp01 == "starting_frame:")      {File001 >> Temp01; Objects[Vrab02[0]].starting_frame = L_Numbering(Temp01); continue;}
             if(Temp01 == "starting_hp:")         {File001 >> Temp01; Objects[Vrab02[0]].starting_hp = L_Numbering(Temp01); continue;}
             if(Temp01 == "starting_mp:")         {File001 >> Temp01; Objects[Vrab02[0]].starting_mp = L_Numbering(Temp01); continue;}
             if(Temp01 == "<pic>")                {File001 >> Temp01; Vrab02[2] = Objects[Vrab02[0]].Pic.size(); Objects[Vrab02[0]].Pic.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_PIC()); Vect01.push_back(Temp01); Vrab02[1] = 2; continue;}

             if(Temp01.size() >= 9) if(string(Temp01, 0, 5) == "file(") {File001 >> Temp01; Vrab02[2] = Objects[Vrab02[0]].Pic.size(); Objects[Vrab02[0]].Pic.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_PIC()); Vect01.push_back(Temp01); continue;}
             if(Temp01 == "w:")   {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Pic.size()) Objects[Vrab02[0]].Pic[Vrab02[2]].w = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "h:")   {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Pic.size()) Objects[Vrab02[0]].Pic[Vrab02[2]].h = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "row:") {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Pic.size()) Objects[Vrab02[0]].Pic[Vrab02[2]].row = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "col:") {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Pic.size()) Objects[Vrab02[0]].Pic[Vrab02[2]].col = ruint32(L_Numbering(Temp01)); continue;}
            break;
            case 2:
             if(Temp01 == "<pic_end>") {Vrab02[1] = 1; continue;}
             if(Temp01 == "w:")   {File001 >> Temp01; Objects[Vrab02[0]].Pic[Vrab02[2]].w = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "h:")   {File001 >> Temp01; Objects[Vrab02[0]].Pic[Vrab02[2]].h = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "row:") {File001 >> Temp01; Objects[Vrab02[0]].Pic[Vrab02[2]].row = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "col:") {File001 >> Temp01; Objects[Vrab02[0]].Pic[Vrab02[2]].col = ruint32(L_Numbering(Temp01)); continue;}
            break;
            case 3: case 4:
             if(Temp01 == "<strength_end>" || Temp01 == "<weapon_strength_list_end>") {Vrab02[1] = 0; continue;}
             if(Temp01 == "entry:")   {File001 >> Temp01; Vrab02[2] = Objects[Vrab02[0]].Strength.size(); Objects[Vrab02[0]].Strength.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_STRENGTH()); File001 >> Temp01; continue;}
             if(Temp01 == "dvx:")     {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].dvx = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "dvy:")     {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].dvy = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "dvz:")     {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].dvz = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "fall:")    {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].fall = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "arest:")   {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].arest = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "vrest:")   {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].vrest = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "respond:") {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()){Objects[Vrab02[0]].Strength[Vrab02[2]].respond.clear(); Objects[Vrab02[0]].Strength[Vrab02[2]].respond.push_back(L_Numbering(Temp01));} Vrab02[1] = 4; continue;}
             if(Temp01 == "effect:")  {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].effect = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "bdefend:") {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].bdefend = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}
             if(Temp01 == "injury:")  {File001 >> Temp01; if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].injury = L_Numbering(Temp01); if(Vrab02[1] != 3) Vrab02[1] = 3; continue;}

             if(Vrab02[1] == 4) {if(Vrab02[2] < Objects[Vrab02[0]].Strength.size()) Objects[Vrab02[0]].Strength[Vrab02[2]].respond.push_back(L_Numbering(Temp01)); continue;}
            break;
            case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
             if(Temp01 == "<frame_end>")                 {Vrab02[1] = 0; continue;}
             if(Temp01 == "pic:")                        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->pic = L_Numbering(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "state:")                      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->state.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->state.push_back(L_Numbering(Temp01)); Vrab02[1] = 6; continue;}
             if(Temp01 == "wait:")                       {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wait = L_Numbering(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "next:")                       {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->next.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->next.push_back(L_Numbering(Temp01)); Vrab02[1] = 7; continue;}
             if(Temp01 == "dvx:")                        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->dvx = L_Doubling(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "dvy:")                        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->dvy = L_Doubling(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "dvz:")                        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->dvz = L_Doubling(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "centerx:")                    {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->centerx = L_Numbering(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "centery:")                    {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->centery = L_Numbering(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "centerz:")                    {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->centerz = L_Numbering(Temp01); if(Vrab02[1] != 5) Vrab02[1] = 5; continue;}
             if(Temp01 == "hit_a:")                      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_a.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_a.push_back(L_Numbering(Temp01)); Vrab02[1] = 8; continue;}
             if(Temp01 == "hit_d:")                      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_d.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_d.push_back(L_Numbering(Temp01)); Vrab02[1] = 9; continue;}
             if(Temp01 == "hit_j:")                      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_j.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_j.push_back(L_Numbering(Temp01)); Vrab02[1] = 10; continue;}
             if(Temp01 == "hit_Fa:")                     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Fa.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Fa.push_back(L_Numbering(Temp01)); Vrab02[1] = 11; continue;}
             if(Temp01 == "hit_Fj:")                     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Fj.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Fj.push_back(L_Numbering(Temp01)); Vrab02[1] = 12; continue;}
             if(Temp01 == "hit_Da:")                     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Da.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Da.push_back(L_Numbering(Temp01)); Vrab02[1] = 13; continue;}
             if(Temp01 == "hit_Dj:")                     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Dj.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Dj.push_back(L_Numbering(Temp01)); Vrab02[1] = 14; continue;}
             if(Temp01 == "hit_Ua:")                     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Ua.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Ua.push_back(L_Numbering(Temp01)); Vrab02[1] = 15; continue;}
             if(Temp01 == "hit_Uj:")                     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Uj.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Uj.push_back(L_Numbering(Temp01)); Vrab02[1] = 16; continue;}
             if(Temp01 == "hit_ja:")                     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_ja.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_ja.push_back(L_Numbering(Temp01)); Vrab02[1] = 17; continue;}
             if(Temp01 == "mp:")                         {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->mp[0] = L_Numbering(Temp01); Objects[Vrab02[0]].Frame[Vrab02[2]]->mp[1] = 0; Vrab02[1] = 18; continue;}
             if(Temp01 == "sound:")                      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->Index_sound = Preload(Temp01, 1); continue;}
             if(Temp01 == "ppoint:")                     {Vrab02[1] = 19; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_PPOINT()); continue;}
             if(Temp01 == "epoint:")                     {Vrab02[1] = 20; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->epoint.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->epoint.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_EPOINT()); continue;}
             if(Temp01 == "bpoint:")                     {Vrab02[1] = 21; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->bpoint.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->bpoint.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_BPOINT()); continue;}
             if(Temp01 == "cpoint:")                     {Vrab02[1] = 22; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_CPOINT()); continue;}
             if(Temp01 == "wpoint:")                     {Vrab02[1] = 28; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_WPOINT()); continue;}
             if(Temp01 == "opoint:")                     {Vrab02[1] = 30; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_OPOINT()); continue;}
             if(Temp01 == "ipoint:" || Temp01 == "itr:") {Vrab02[1] = 32; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->itr.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->itr.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT()); continue;}
             if(Temp01 == "hpoint:" || Temp01 == "bdy:") {Vrab02[1] = 37; Vrab02[3] = Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy.size(); Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_HPOINT()); continue;}

             if(Vrab02[1] == 6)  {Objects[Vrab02[0]].Frame[Vrab02[2]]->state.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 7)  {Objects[Vrab02[0]].Frame[Vrab02[2]]->next.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 8)  {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_a.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 9)  {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_d.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 10) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_j.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 11) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Fa.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 12) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Fj.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 13) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Da.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 14) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Dj.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 15) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Ua.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 16) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_Uj.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 17) {Objects[Vrab02[0]].Frame[Vrab02[2]]->hit_ja.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 18) {Objects[Vrab02[0]].Frame[Vrab02[2]]->mp[1] = L_Numbering(Temp01); Vrab02[1] = 5; continue;}
            break;
            case 19:
             if(Temp01 == "ppoint_end:") {Vrab02[1] = 5; continue;}
             if(Temp01 == "pic:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].pic = L_Numbering(Temp01); continue;}
             if(Temp01 == "x:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].x = L_Numbering(Temp01); continue;}
             if(Temp01 == "y:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].y = L_Numbering(Temp01); continue;}
             if(Temp01 == "z:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].z = L_Numbering(Temp01); continue;}
             if(Temp01 == "trans:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].trans = L_Numbering(Temp01); continue;}
             if(Temp01 == "rotate:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].rotate = L_Numbering(Temp01); continue;}
             if(Temp01 == "stx:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].stx = L_Numbering(Temp01); continue;}
             if(Temp01 == "sty:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->ppoint[Vrab02[3]].sty = L_Numbering(Temp01); continue;}
            break;
            case 20:
             if(Temp01 == "epoint_end:") {Vrab02[1] = 5; continue;}
             if(Temp01 == "x:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->epoint[Vrab02[3]].x = L_Numbering(Temp01); continue;}
             if(Temp01 == "y:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->epoint[Vrab02[3]].y = L_Numbering(Temp01); continue;}
             if(Temp01 == "w:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->epoint[Vrab02[3]].w = L_Numbering(Temp01); continue;}
             if(Temp01 == "h:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->epoint[Vrab02[3]].h = L_Numbering(Temp01); continue;}
             if(Temp01 == "rotate:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->epoint[Vrab02[3]].rotate = L_Numbering(Temp01); continue;}
            break;
            case 21:
             if(Temp01 == "bpoint_end:") {Vrab02[1] = 5; continue;}
             if(Temp01 == "x:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bpoint[Vrab02[3]].x = L_Numbering(Temp01); continue;}
             if(Temp01 == "y:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bpoint[Vrab02[3]].y = L_Numbering(Temp01); continue;}
            break;
            case 22: case 23: case 24: case 25: case 26: case 27:
             if(Temp01 == "cpoint_end:")   {Vrab02[1] = 5; continue;}
             if(Temp01 == "kind:")         {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].kind = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "x:")            {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].x = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "y:")            {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].y = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "vaction:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].vaction.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].vaction.push_back(L_Numbering(Temp01)); Vrab02[1] = 23; continue;}
             if(Temp01 == "aaction:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].aaction.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].aaction.push_back(L_Numbering(Temp01)); Vrab02[1] = 24; continue;}
             if(Temp01 == "daction:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].daction.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].daction.push_back(L_Numbering(Temp01)); Vrab02[1] = 25; continue;}
             if(Temp01 == "jaction:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].jaction.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].jaction.push_back(L_Numbering(Temp01)); Vrab02[1] = 26; continue;}
             if(Temp01 == "taction:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].taction.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].taction.push_back(L_Numbering(Temp01)); Vrab02[1] = 27; continue;}
             if(Temp01 == "throwvx:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].throwvx = L_Doubling(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "throwvy:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].throwvy = L_Doubling(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "throwvz:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].throwvz = L_Doubling(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "throwinjury:")  {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].throwinjury = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "dircontrol:")   {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].dircontrol = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "hurtable:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].hurtable = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "decrease:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].decrease = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "cover:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].cover = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "injury:")       {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].injury = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "fronthurtact:") {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].fronthurtact = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
             if(Temp01 == "backhurtact:")  {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].backhurtact = L_Numbering(Temp01); if(Vrab02[1] != 22) Vrab02[1] = 22; continue;}
 
             if(Vrab02[1] == 23) {Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].vaction.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 24) {Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].aaction.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 25) {Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].daction.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 26) {Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].jaction.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 27) {Objects[Vrab02[0]].Frame[Vrab02[2]]->cpoint[Vrab02[3]].taction.push_back(L_Numbering(Temp01)); continue;}
            break;
            case 28: case 29:
             if(Temp01 == "wpoint_end:") {Vrab02[1] = 5; continue;}
             if(Temp01 == "kind:")       {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].kind = L_Numbering(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "x:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].x = L_Numbering(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "y:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].y = L_Numbering(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "z:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].z = L_Numbering(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "dvx:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].dvx = L_Doubling(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "dvy:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].dvy = L_Doubling(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "dvz:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].dvz = L_Doubling(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "weaponact:")  {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].weaponact.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].weaponact.push_back(L_Numbering(Temp01)); Vrab02[1] = 29; continue;}
             if(Temp01 == "attacking:")  {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].attacking = L_Numbering(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             if(Temp01 == "cover:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].cover = L_Numbering(Temp01); if(Vrab02[1] != 28) Vrab02[1] = 28; continue;}
             
             if(Vrab02[1] == 29) {Objects[Vrab02[0]].Frame[Vrab02[2]]->wpoint[Vrab02[3]].weaponact.push_back(L_Numbering(Temp01)); continue;}
            break;
            case 30: case 31:
             if(Temp01 == "opoint_end:") {Vrab02[1] = 5; continue;}
             if(Temp01 == "kind:")       {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].kind = L_Numbering(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "x:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].x = L_Numbering(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "y:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].y = L_Numbering(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "z:")          {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].z = L_Numbering(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "dvx:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].dvx = L_Doubling(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "dvy:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].dvy = L_Doubling(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "dvz:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].dvz = L_Doubling(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "oid:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].oid = L_Numbering(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             if(Temp01 == "action:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].action.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].action.push_back(L_Numbering(Temp01)); Vrab02[1] = 31; continue;}
             if(Temp01 == "facing:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].facing = L_Numbering(Temp01); if(Vrab02[1] != 30) Vrab02[1] = 30; continue;}
             
             if(Vrab02[1] == 31) {Objects[Vrab02[0]].Frame[Vrab02[2]]->opoint[Vrab02[3]].action.push_back(L_Numbering(Temp01)); continue;}
            break;
            case 32: case 33: case 34: case 35: case 36:
             if(Temp01 == "ipoint_end:" || Temp01 == "itr_end:") {Vrab02[1] = 5; continue;}
             if(Temp01 == "kind:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].kind = L_Numbering(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "x:")           {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].x = L_Doubling(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "y:")           {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].y = L_Doubling(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "z:")           {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].z = L_Doubling(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "w:")           {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].w = L_Positive64(L_Doubling(Temp01)); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "h:")           {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].h = L_Positive64(L_Doubling(Temp01)); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "l:")           {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].l = L_Positive64(L_Doubling(Temp01)); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "zwidth:")      {File001 >> Temp01; statics int32 Vrab03 = L_Positive(L_Numbering(Temp01)); Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].z = -Vrab03; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].l = Vrab03 * 2; if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "dvx:")         {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].dvx = L_Doubling(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "dvy:")         {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].dvy = L_Doubling(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "dvy:")         {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].dvz = L_Doubling(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "fall:")        {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].fall = L_Numbering(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "arest:")       {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].arest = L_Numbering(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "vrest:")       {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].vrest = L_Numbering(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "respond:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].respond.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].respond.push_back(L_Numbering(Temp01)); Vrab02[1] = 33; continue;}
             if(Temp01 == "effect:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].effect.clear(); Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].effect.push_back(L_Numbering(Temp01)); Vrab02[1] = 34; continue;}
             if(Temp01 == "bdefend:")     {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].bdefend = L_Numbering(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "injury:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].injury = L_Numbering(Temp01); if(Vrab02[1] != 32) Vrab02[1] = 32; continue;}
             if(Temp01 == "catchingact:") {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].catchingact[0] = L_Numbering(Temp01); Vrab02[1] = 35; continue;}
             if(Temp01 == "caughtact:")   {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].caughtact[0] = L_Numbering(Temp01); Vrab02[1] = 36; continue;}

             if(Vrab02[1] == 33) {Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].respond.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 34) {Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].effect.push_back(L_Numbering(Temp01)); continue;}
             if(Vrab02[1] == 35) {Vrab02[1] = 32; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].catchingact[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 36) {Vrab02[1] = 32; Objects[Vrab02[0]].Frame[Vrab02[2]]->itr[Vrab02[3]].caughtact[1] = L_Numbering(Temp01); continue;}
            break;
            case 37:
             if(Temp01 == "hpoint_end:" || Temp01 == "bdy_end:") {Vrab02[1] = 5; continue;}
             if(Temp01 == "kind:")   {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].kind = L_Numbering(Temp01); continue;}
             if(Temp01 == "x:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].x = L_Doubling(Temp01); continue;}
             if(Temp01 == "y:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].y = L_Doubling(Temp01); continue;}
             if(Temp01 == "z:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].z = L_Doubling(Temp01); continue;}
             if(Temp01 == "w:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].w = L_Positive64(L_Doubling(Temp01)); continue;}
             if(Temp01 == "h:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].h = L_Positive64(L_Doubling(Temp01)); continue;}
             if(Temp01 == "l:")      {File001 >> Temp01; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].l = L_Positive64(L_Doubling(Temp01)); continue;}
             if(Temp01 == "zwidth:") {File001 >> Temp01; statics xint64 Vrab03 = L_Positive64(L_Doubling(Temp01)); Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].z = -Vrab03; Objects[Vrab02[0]].Frame[Vrab02[2]]->bdy[Vrab02[3]].l = Vrab03 * 2; continue;}
            break;
            case 54:
             if(Temp01 == "<background_end>"){Vrab02[1] = 0; continue;}
             if(Temp01 == "<property>")      {Vrab02[1] = 38; continue;}
             if(Temp01 == "<layer>")         {Vrab02[1] = 46; insize Vrab03 = Backgrounds[0].Layer.size(); Backgrounds[0].Layer.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER > ()); Vrab02[2] = Objects[Vrab02[0]].Background->Layer.size(); Objects[Vrab02[0]].Background->Layer.push_back(Backgrounds[0].Layer[Vrab03].get()); File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->Index_pic = Preload(Temp01); continue;}
             if(Temp01 == "<opoint>")        {Vrab02[1] = 47; insize Vrab03 = Backgrounds[0].Opoint.size(); Backgrounds[0].Opoint.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_OPOINT > ()); Vrab02[2] = Objects[Vrab02[0]].Background->Opoint.size(); Objects[Vrab02[0]].Background->Opoint.push_back(Backgrounds[0].Opoint[Vrab03].get()); continue;}
            break;
            case 38: case 39: case 40: case 41: case 42: case 43: case 44: case 45:
             if(Temp01 == "<property_end>"){Vrab02[1] = 54; continue;}
             if(Temp01 == "kind:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->kind = L_Numbering(Temp01); if(Vrab02[1] != 38) Vrab02[1] = 38; continue;}
             if(Temp01 == "width:")        {File001 >> Temp01; Objects[Vrab02[0]].Background->width[0] = L_Numbering(Temp01); Objects[Vrab02[0]].Background->width[1] = 0; Vrab02[1] = 39; continue;}
             if(Temp01 == "zwidth:")       {File001 >> Temp01; Objects[Vrab02[0]].Background->zwidth[0] = L_Numbering(Temp01); Objects[Vrab02[0]].Background->zwidth[1] = 0; Vrab02[1] = 40; continue;}
             if(Temp01 == "cam:")          {File001 >> Temp01; Objects[Vrab02[0]].Background->cam[0] = L_Numbering(Temp01); Objects[Vrab02[0]].Background->cam[1] = 0; Objects[Vrab02[0]].Background->cam[2] = 0; Objects[Vrab02[0]].Background->cam[3] = 0; Vrab02[1] = 41; continue;}
             if(Temp01 == "shadow:")       {File001 >> Temp01; Objects[Vrab02[0]].Background->Index_shadow = Preload(Temp01); Objects[Vrab02[0]].Background->shadow[0] = 0; Objects[Vrab02[0]].Background->shadow[1] = 0; Vrab02[1] = 44; continue;}

             if(Vrab02[1] == 39){Vrab02[1] = 38; Objects[Vrab02[0]].Background->width[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 40){Vrab02[1] = 38; Objects[Vrab02[0]].Background->zwidth[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 41){Vrab02[1] = 42; Objects[Vrab02[0]].Background->cam[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 42){Vrab02[1] = 43; Objects[Vrab02[0]].Background->cam[2] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 43){Vrab02[1] = 38; Objects[Vrab02[0]].Background->cam[3] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 44){Vrab02[1] = 45; Objects[Vrab02[0]].Background->shadow[0] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 45){Vrab02[1] = 38; Objects[Vrab02[0]].Background->shadow[1] = L_Numbering(Temp01); continue;}
            break;
            case 46:
             if(Temp01 == "<layer_end>") {Vrab02[1] = 54; continue;}
             if(Temp01 == "kind:")       {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->kind = L_Numbering(Temp01); continue;}
             if(Temp01 == "x:")          {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->x = L_Numbering(Temp01); continue;}
             if(Temp01 == "y:")          {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->y = L_Numbering(Temp01); continue;}
             if(Temp01 == "z:")          {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->z = L_Numbering(Temp01); continue;}
             if(Temp01 == "width:")      {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->width = L_Numbering(Temp01); continue;}
             if(Temp01 == "height:")     {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->height = L_Numbering(Temp01); continue;}
             if(Temp01 == "trans:")      {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->trans = L_Numbering(Temp01); continue;}
             if(Temp01 == "rotate:")     {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->rotate = L_Numbering(Temp01); continue;}
             if(Temp01 == "color:")      {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->color = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "colorhex:")   {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->color = ruint32(L_Convert(Temp01)); continue;}
             if(Temp01 == "loop:")       {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->loop = L_Numbering(Temp01); continue;}
             if(Temp01 == "loop_count:") {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->loop_count = L_Numbering(Temp01); continue;}
             if(Temp01 == "cc:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->cc = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "c1:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->c1 = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "c2:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->Layer[Vrab02[2]]->c2 = ruint32(L_Numbering(Temp01)); continue;}
            break;
            case 47: case 48: case 49: case 50: case 51:
             if(Temp01 == "<opoint_end>") {Vrab02[1] = 54; continue;}
             if(Temp01 == "kind:")        {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->kind = L_Numbering(Temp01); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "x:")           {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->x[0] = L_Numbering(Temp01); Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->x[1] = Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->x[0]; Vrab02[1] = 48; continue;}
             if(Temp01 == "y:")           {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->y[0] = L_Numbering(Temp01); Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->y[1] = Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->y[0]; Vrab02[1] = 49; continue;}
             if(Temp01 == "z:")           {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->z[0] = L_Numbering(Temp01); Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->y[1] = Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->y[0]; Vrab02[1] = 50; continue;}
             if(Temp01 == "dvx:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->dvx = L_Doubling(Temp01); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "dvy:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->dvy = L_Doubling(Temp01); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "dvz:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->dvz = L_Doubling(Temp01); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "oid:")         {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->oid = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "action:")      {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->action.clear(); Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->action.push_back(L_Numbering(Temp01)); Vrab02[1] = 51; continue;}
             if(Temp01 == "facing:")      {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->facing = L_Numbering(Temp01); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "cc:")          {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->cc = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "c1:")          {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->c1 = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}
             if(Temp01 == "c2:")          {File001 >> Temp01; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->c2 = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 47) Vrab02[1] = 47; continue;}

             if(Vrab02[1] == 48) {Vrab02[1] = 47; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->x[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 49) {Vrab02[1] = 47; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->y[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 50) {Vrab02[1] = 47; Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->z[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 51) {Objects[Vrab02[0]].Background->Opoint[Vrab02[2]]->action.push_back(L_Numbering(Temp01)); continue;}
            break;
            case 52: case 53:
             if(Temp01 == "<effect_end>")            {Vrab02[1] = 0; continue;}
             if(Temp01 == "duration:")               {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->duration = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "duration_add:")           {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->duration_add = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "duration_max:")           {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->duration_max = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "duration_lost:")          {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->duration_lost = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "duration_lost_intv:")     {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->duration_lost_intv = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "stack:")                  {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->stack = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "stack_add:")              {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->stack_add = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "stack_max:")              {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->stack_max = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "stack_lost:")             {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->stack_lost = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "stack_lost_intv:")        {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->stack_lost_intv = L_Numbering(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "stack_dmgdealt:")         {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->stack_dmgdealt = L_Doubling(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "stack_dmgtaken:")         {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->stack_dmgtaken = L_Doubling(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "bounce:")                 {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->bounce = L_Doubling(Temp01); if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}
             if(Temp01 == "transfer:")               {File001 >> Temp01; Objects[Vrab02[0]].Effect[Vrab02[2]]->transfer.clear(); Objects[Vrab02[0]].Effect[Vrab02[2]]->transfer.push_back(rinsize(L_Numbering(Temp01))); Vrab02[1] = 53; continue;}
             if(Temp01.size() >= 6) if(string(Temp01, 0, 6) == "<desc>") {string Temp02 = ""; if(Temp01.size() > 6){Temp02 += string(Temp01, 6, Temp01.size() - 13);} else {File001 >> Temp02;} while(File001){File001 >> Temp01; if(Temp01.size() >= 10) if(string(Temp01, Temp01.size() - 10, 10) == "<desc_end>"){if(Temp01.size() > 10) Temp02 += " " + string(Temp01, 0, Temp01.size() - 10); break;} Temp02 += " " + Temp01;} Objects[Vrab02[0]].Effect[Vrab02[2]]->desc = Temp02; if(Vrab02[1] != 52) Vrab02[1] = 52; continue;}

             if(Vrab02[1] == 53) {Objects[Vrab02[0]].Effect[Vrab02[2]]->transfer.push_back(rinsize(L_Numbering(Temp01))); continue;}
            break;
            default: break;
           }
          }
          if(!File001){Vrab01 -= 2; Vrab02[0] += 1; if(File001.is_open()) File001.close(); continue;}
         break;
         case 8: // background.dat
          while(File001)
          {
           File001 >> Temp01; if(!File001) break; if(Temp01.at(0) == '#'){std::getline(File001, Temp01); continue;} if(Temp01.size() > 1) if(Temp01.at(0) == '/' && Temp01.at(1) == '/'){std::getline(File001, Temp01); continue;}
           switch(Vrab02[1])
           {
            case 0:
             if(Temp01 == "<property>") {Vrab02[1] = 1; continue;}
             if(Temp01 == "<layer>")    {Vrab02[1] = 9; Vrab02[2] = Backgrounds[Vrab02[0]].Layer.size(); Backgrounds[Vrab02[0]].Layer.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER > ()); File001 >> Temp01;  Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->Index_pic = Preload(Temp01); continue;}
             if(Temp01 == "<opoint>")   {Vrab02[1] = 10; Vrab02[2] = Backgrounds[Vrab02[0]].Opoint.size(); Backgrounds[Vrab02[0]].Opoint.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_OPOINT > ()); continue;}
            break;
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
             if(Temp01 == "<property_end>") {Vrab02[1] = 0; continue;}
             if(Temp01 == "name:")          {File001 >> Temp01; Backgrounds[Vrab02[0]].name = Temp01; if(Vrab02[1] != 1) Vrab02[1] = 1; continue;}
             if(Temp01 == "width:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].width[0] = L_Numbering(Temp01); Backgrounds[Vrab02[0]].width[1] = 0; Vrab02[1] = 2; continue;}
             if(Temp01 == "zwidth:")        {File001 >> Temp01; Backgrounds[Vrab02[0]].zwidth[0] = L_Numbering(Temp01); Backgrounds[Vrab02[0]].zwidth[1] = 0; Vrab02[1] = 3; continue;}
             if(Temp01 == "cam:")           {File001 >> Temp01; Backgrounds[Vrab02[0]].cam[0] = L_Numbering(Temp01); Backgrounds[Vrab02[0]].cam[1] = 0; Backgrounds[Vrab02[0]].cam[2] = 0; Backgrounds[Vrab02[0]].cam[3] = 0; Vrab02[1] = 4; continue;}
             if(Temp01 == "shadow:")        {File001 >> Temp01; Backgrounds[Vrab02[0]].Index_shadow = Preload(Temp01); Backgrounds[Vrab02[0]].shadow[0] = 0; Backgrounds[Vrab02[0]].shadow[1] = 0; Vrab02[1] = 7; continue;}

             if(Vrab02[1] == 2){Vrab02[1] = 1; Backgrounds[Vrab02[0]].width[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 3){Vrab02[1] = 1; Backgrounds[Vrab02[0]].zwidth[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 4){Vrab02[1] = 5; Backgrounds[Vrab02[0]].cam[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 5){Vrab02[1] = 6; Backgrounds[Vrab02[0]].cam[2] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 6){Vrab02[1] = 1; Backgrounds[Vrab02[0]].cam[3] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 7){Vrab02[1] = 8; Backgrounds[Vrab02[0]].shadow[0] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 8){Vrab02[1] = 1; Backgrounds[Vrab02[0]].shadow[1] = L_Numbering(Temp01); continue;}
            break;
            case 9:
             if(Temp01 == "<layer_end>") {Vrab02[1] = 0; continue;}
             if(Temp01 == "kind:")       {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->kind = L_Numbering(Temp01); continue;}
             if(Temp01 == "x:")          {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->x = L_Numbering(Temp01); continue;}
             if(Temp01 == "y:")          {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->y = L_Numbering(Temp01); continue;}
             if(Temp01 == "z:")          {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->z = L_Numbering(Temp01); continue;}
             if(Temp01 == "width:")      {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->width = L_Numbering(Temp01); continue;}
             if(Temp01 == "height:")     {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->height = L_Numbering(Temp01); continue;}
             if(Temp01 == "trans:")      {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->trans = L_Numbering(Temp01); continue;}
             if(Temp01 == "rotate:")     {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->rotate = L_Numbering(Temp01); continue;}
             if(Temp01 == "color:")      {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->color = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "colorhex:")   {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->color = ruint32(L_Convert(Temp01)); continue;}
             if(Temp01 == "loop:")       {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->loop = L_Numbering(Temp01); continue;}
             if(Temp01 == "loop_count:") {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->loop_count = L_Numbering(Temp01); continue;}
             if(Temp01 == "cc:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->cc = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "c1:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->c1 = ruint32(L_Numbering(Temp01)); continue;}
             if(Temp01 == "c2:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].Layer[Vrab02[2]]->c2 = ruint32(L_Numbering(Temp01)); continue;}
            break;
            case 10: case 11: case 12: case 13: case 14:
             if(Temp01 == "<opoint_end>") {Vrab02[1] = 0; continue;}
             if(Temp01 == "kind:")        {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->kind = L_Numbering(Temp01); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "x:")           {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->x[0] = L_Numbering(Temp01); Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->x[1] = Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->x[0]; Vrab02[1] = 11; continue;}
             if(Temp01 == "y:")           {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->y[0] = L_Numbering(Temp01); Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->y[1] = Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->y[0]; Vrab02[1] = 12; continue;}
             if(Temp01 == "z:")           {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->z[0] = L_Numbering(Temp01); Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->y[1] = Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->y[0]; Vrab02[1] = 13; continue;}
             if(Temp01 == "dvx:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->dvx = L_Doubling(Temp01); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "dvy:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->dvy = L_Doubling(Temp01); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "dvz:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->dvz = L_Doubling(Temp01); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "oid:")         {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->oid = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "action:")      {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->action.clear(); Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->action.push_back(L_Numbering(Temp01)); Vrab02[1] = 14; continue;}
             if(Temp01 == "facing:")      {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->facing = L_Numbering(Temp01); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "cc:")          {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->cc = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "c1:")          {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->c1 = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}
             if(Temp01 == "c2:")          {File001 >> Temp01; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->c2 = rinsize(L_Numbering(Temp01)); if(Vrab02[1] != 10) Vrab02[1] = 10; continue;}

             if(Vrab02[1] == 11) {Vrab02[1] = 10; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->x[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 12) {Vrab02[1] = 10; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->y[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 13) {Vrab02[1] = 10; Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->z[1] = L_Numbering(Temp01); continue;}
             if(Vrab02[1] == 14) {Backgrounds[Vrab02[0]].Opoint[Vrab02[2]]->action.push_back(L_Numbering(Temp01)); continue;}
            break;
            default: break;
           }
          }
          if(!File001){Vrab01 = 7; Vrab02[0] += 1; if(File001.is_open()) File001.close(); continue;}
         break;
         case 10: // stage.dat
          while(File001)
          {
           File001 >> Temp01; if(!File001) break; if(Temp01.at(0) == '#'){std::getline(File001, Temp01); continue;} if(Temp01.size() > 1) if(Temp01.at(0) == '/' && Temp01.at(1) == '/'){std::getline(File001, Temp01); continue;}
           switch(Vrab02[0])
           {
            case 0:
             if(Temp01 == "<stage>") {Vrab02[0] = 1; Vrab02[1] = Stages.size(); Stages.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_STAGE()); continue;}
            break;
            case 1:
             if(Temp01 == "<stage_end>") {Vrab02[0] = 0; continue;}
             if(Temp01 == "id:")         {File001 >> Temp01; Stages[Vrab02[1]].id = rinsize(L_Numbering(Temp01)); continue;}
             if(Temp01 == "name:")       {File001 >> Temp01; Stages[Vrab02[1]].name = Temp01; continue;}
             if(Temp01 == "next_stage:") {File001 >> Temp01; Stages[Vrab02[1]].next_stage = L_Numbering(Temp01); continue;}
             if(Temp01 == "<phase>")     {Vrab02[0] = 2; Vrab02[2] = Stages[Vrab02[1]].Phase.size(); Stages[Vrab02[1]].Phase.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE()); continue;}
            break;
            case 2:
             if(Temp01 == "<phase_end>") {Vrab02[0] = 1; continue;}
             if(Temp01 == "<cutscene>")  {Vrab02[0] = 3; Vrab02[3] = Stages[Vrab02[1]].Phase[Vrab02[2]].Cutscene.size(); Stages[Vrab02[1]].Phase[Vrab02[2]].Cutscene.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_CUTSCENE()); continue;}
             if(Temp01 == "<subphase>")  {Vrab02[0] = 4; Vrab02[3] = Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase.size(); Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_SUBPHASE()); Vrab02[4] = rinsize(-1); continue;}
            break;
            case 3:
             if(Temp01 == "<cutscene_end>") {Vrab02[0] = 2; continue;}
            break;
            case 4:
             if(Temp01 == "<subphase_end>") {Vrab02[0] = 2; continue;}
             if(Temp01 == "id:")            {File001 >> Temp01; Vrab02[4] = Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase[Vrab02[3]].Entity.size(); Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase[Vrab02[3]].Entity.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_STAGE_PHASE_SUBPHASE_ENTITY()); continue;}
             if(Temp01 == "x:")             {File001 >> Temp01; if(Vrab02[4] < Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase[Vrab02[3]].Entity.size()){Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase[Vrab02[3]].Entity[Vrab02[4]].x[0] = L_Numbering(Temp01); Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase[Vrab02[3]].Entity[Vrab02[4]].x[1] = 0;} Vrab02[0] = 5; continue;}

             if(Vrab02[0] == 5){Vrab02[0] = 4; if(Vrab02[4] < Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase[Vrab02[3]].Entity.size()) Stages[Vrab02[1]].Phase[Vrab02[2]].Subphase[Vrab02[3]].Entity[Vrab02[4]].x[1] = L_Numbering(Temp01); continue;}
            break;
            default: break;
           }
          }
          if(!File001){Vrab01 = 11; Vrab02[0] = rinsize(-1); continue;}
         break;
         default: break;
        }
        break;
       }

       if(File001.is_open()) File001.close(); Vect001.clear();
      }

     public:
      int1   Game = false;
      uint8  Loaded = 0;
      string Load_Text = "";

      int1   Polish = false;
      uint8  Speed = 2;
      uint8  Base_FPS = 32;
      uint8  Hitboxes = 0;

      //std::jthread Loader;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_SECTIONDATA > Section;

      int1    Begin (statics string Temp01, statics string Temp02, statics int32 Vrab01 = rinsize(-1)) perfect 
      {
       Temp001 = Temp01; Temp002 = Temp02;
       Game = true; Loaded = false;

       Objects.clear(); Stages.clear(); Loads.clear();
       Backgrounds.clear(); Backgrounds.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND());
       Frames.clear(); Frames.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME > ());
       Effects.clear(); Effects.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_EFFECT > ());
       Object_Backgrounds.clear(); Object_Backgrounds.push_back(std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_BACKGROUND > ());
       return true;
      }
      int1    Load  () perfect
      {
       if(!Game) return false; if(Loaded == 1) return false; //if(!Loader.joinable()) return false;

       //if(Loader.joinable()) Loader.join();
       
       std::jthread AVCD(&HEPTA_LF2_ENCHANTED_ENGINE1::Loading, Enchanted->Engine1.get());
       AVCD.detach();

       return true;
      }
      int0    Clear () perfect
      {
       //Loader.join();
       Object.clear(); Effect.clear();
       Inputs.clear(); Section.clear(); 

       Loads.clear();
       Stages.clear();
       Objects.clear();
       Backgrounds.clear();
       Frames.clear();
       Effects.clear();
       Object_Backgrounds.clear();

       Loaded = 0; Game = false; Load_Text = "";
       return;
      }

      int1    Start (statics uint8 Vrab01, statics insize Vrab02, statics uint8 Vrab03, statics insize Vrab04, statics insize Vrab05 = 0) perfect
      {
       if(Section.size() <= Vrab05) Section.resize(Vrab05 + 1); if(Loaded != 3) return false;

       Section[Vrab05] = HEPTA_LF2_ENCHANTED_ENGINE1_SECTIONDATA();
       Section[Vrab05].Mode = Vrab01;
       Section[Vrab05].Background = Vrab02; if(Section[Vrab05].Background == 0){Section[Vrab05].Background = 1 + L_Random(Backgrounds.size() - 2);}
       Section[Vrab05].Difficulty = Vrab03;
       Section[Vrab05].Max = Vrab04;
       Section[Vrab05].Ready = true;

       return true;
      }
      int1    Set   (statics uint8 Vrab01, statics insize Vrab02, statics uint8 Vrab03, statics string Temp01, statics insize Vrab04 = 0) perfect
      {
       if(Section.size() <= Vrab04) Section.resize(Vrab04 + 1); if(Loaded != 3) return false; if(!Section[Vrab04].Ready) return false;

       statics insize Vrab05 = Add(Vrab02, Vrab04); if(Vrab05 == rinsize(-1)) return false;
       Object[Vrab05].User = Vrab01 + 1;
       Object[Vrab05].Section = Vrab04;
       Object[Vrab05].Name = Temp01;
       Object[Vrab05].Lock = 3;
       Object[Vrab05].Facing = L_Random(1) == 0;
       Object[Vrab05].Y_Vel = 1;

       if(Vrab03 == 0)
       {Object[Vrab05].Team = Section[Vrab04].Independent_Team; Section[Vrab04].Independent_Team -= 1;} else 
       {Object[Vrab05].Team = Vrab03;}

       statics xint64 Vrab06 = rxint64(Backgrounds[Section[Vrab04].Background].width[1] - Backgrounds[Section[Vrab04].Background].width[0]) / 2.0;
       statics xint64 Vrab07 = rxint64(Backgrounds[Section[Vrab04].Background].zwidth[1] - Backgrounds[Section[Vrab04].Background].zwidth[0]) / 2.0;
       Object[Vrab05].X = rxint64(L_Random(rint64(Vrab06))) + rxint64(Backgrounds[Section[Vrab04].Background].width[0]) + (Vrab06 / 2.0);
       Object[Vrab05].Z = rxint64(L_Random(rint64(Vrab07))) + rxint64(Backgrounds[Section[Vrab04].Background].zwidth[0]) + (Vrab07 / 2.0);

       return true;
      }

      xint64* Main  (statics insize Vrab01 = 0) perfect 
      {
       if(Section.size() <= Vrab01) Section.resize(Vrab01 + 1); if(Loaded != 3) return Section[Vrab01].Camera; if(!Section[Vrab01].Ready) return Section[Vrab01].Camera;
       //if(Loader.joinable()) Loader.join();

       // In-Game Reload
       if(Vrab001)
       {
        insize Vrab02 = Object.size();
        while(Vrab02 != 0)
        {
         Vrab02 -= 1; insize Vrab03 = Objects.size(); int1 Vrab04 = true;
         while(Vrab03 != 0)
         {
          Vrab03 -= 1; if(Objects[Vrab03].id == Vect001[Vrab02]){Object[Vrab02].Data = &Objects[Vrab03]; Vrab04 = false; break;}
         } if(Vrab04) Remove(Vrab02);
        }
        Vrab001 = false; Vect001.clear();
       }

       Context(Vrab01); //std::thread Thrd01(&HEPTA_LF2_ENCHANTED_ENGINE1::Context, this, Vrab01); Thrd01.join();

       return Section[Vrab01].Camera;
      }
      int0    Draw  (statics insize Vrab01 = 0, statics int64 Vrab02 = 0, statics int64 Vrab03 = 0, statics int64 Vrab04 = 800, statics int64 Vrab05 = 400, int64 Vrab06 = 0, int64 Vrab07 = 0, insize Vrab08 = rinsize(-1), statics uint64 Vrab09 = 0) perfect
      {
       if(Section.size() <= Vrab01) Section.resize(Vrab01 + 1); if(Loaded != 3) return; if(!Section[Vrab01].Ready) return;

       if(Object.size() < Vrab08) Vrab08 = rinsize(-1); if(Vrab08 != rinsize(-1)) if(!Object[Vrab08].Exist) Vrab08 = rinsize(-1);
       Vrab06 -= Vrab04 / 2.0; Vrab07 -= Vrab05 / 2.0;
       struct Strc01
       {
        xint64 Vrab01 = 0;
        uint8  Vrab02 = 0;
        insize Vrab03 = rinsize(-1);
        int64  Vrab04 = 0;
        int64  Vrab05 = 0;
        uint8  Vrab06 = 0ui8;
        uint8  Vrab07 = 255ui8;
        int64  Vrab08 = 0;
        int64  Vrab09 = 0;
        int64  Vrab10 = 0;
        string Temp01 = "";

        int1 operator < (statics Strc01& Vect001) statics {return (Vrab01 > Vect001.Vrab01);}
       };
       std::vector < Strc01 > Vect01;

       // Background
       if(Vrab08 == rinsize(-1))
       {
        // Camera Limits
        {
         int64 Vrab10 = Backgrounds[Section[Vrab01].Background].cam[0] + Backgrounds[Section[Vrab01].Background].width[0];
         int64 Vrab11 = Backgrounds[Section[Vrab01].Background].cam[1] + Backgrounds[Section[Vrab01].Background].width[1];
         int64 Vrab12 = Backgrounds[Section[Vrab01].Background].cam[2] + Backgrounds[Section[Vrab01].Background].zwidth[0];
         int64 Vrab13 = Backgrounds[Section[Vrab01].Background].cam[3] + Backgrounds[Section[Vrab01].Background].zwidth[1];
         if(Vrab11 - Vrab10 <= Vrab04){Vrab06 = 0;} else
         {
          if(Vrab06 < Vrab10) Vrab06 = Vrab10;
          if(Vrab06 + Vrab04 > Vrab11) Vrab06 = Vrab11 - Vrab04;
         }
         if(Vrab13 - Vrab12 <= Vrab05){Vrab07 = 0;} else
         {
          if(Vrab07 < Vrab12) Vrab07 = Vrab12;
          if(Vrab07 + Vrab05 > Vrab13) Vrab07 = Vrab13 - Vrab05;
         }
        }

        statics insize Vrab10 = Backgrounds[Section[Vrab01].Background].Layer.size(); 
        if(Section[Vrab01].Animation.size() <= Vrab10 + Backgrounds[Section[Vrab01].Background].Opoint.size()) Section[Vrab01].Animation.resize(Vrab10 + Backgrounds[Section[Vrab01].Background].Opoint.size());
        insize Vrab11 = 0; while(Vrab11 < Vrab10)
        {
         statics insize &Vrab12 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->Index_pic;
         statics uint32 &Vrab13 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->loop;
         statics insize &Vrab14 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->loop_count;
         statics uint32 &Vrab15 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->color;
         statics uint8  &Vrab16 = ruint8(Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->kind); if(Vrab16 == 2){Vrab11 += 1; continue;}
         statics int64  &Vrab17 = rint64(Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->x);
         statics int64  &Vrab18 = rint64(Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->y);
         statics int64  &Vrab19 = rint64(Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->z);

         if(Vrab15 != 0)
         {
          statics insize Vrab20 = Vect01.size(); Vect01.push_back(Strc01());
          Vect01[Vrab20].Vrab01 = rxint64((Vrab19 <= Backgrounds[Section[Vrab01].Background].zwidth[0]) ? (-100000 + Backgrounds[Section[Vrab01].Background].zwidth[0]) : Vrab19);
          Vect01[Vrab20].Vrab02 = 0;
          Vect01[Vrab20].Vrab03 = Vrab15;
          Vect01[Vrab20].Vrab04 = Vrab17;
          Vect01[Vrab20].Vrab05 = Vrab18;
          Vect01[Vrab20].Vrab06 = ruint8(Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->rotate);
          Vect01[Vrab20].Vrab07 = ruint8(255 - Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->trans);
          Vect01[Vrab20].Vrab08 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->width;
          Vect01[Vrab20].Vrab09 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->height;         
         } else
         {
          statics uint32 Vrab20 = Section[Vrab01].Animation[Vrab11];
          if(Vrab20 >= (Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->c1 * (Polish ? 4 : 1)) && Vrab20 <= (Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->c2 * (Polish ? 4 : 1)) + (Polish ? 3 : 0))
          {
           int64  Vrab21 = 0;
           int64  Vrab22 = rint64(Backgrounds[Section[Vrab01].Background].width[1]);
           int64  Vrab23 = Vrab13; if(Vrab13 == 0) Vrab23 = Vrab22 + 1;
           statics int64 Vrab24 = rint64(Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->width);
           statics int1  Vrab25 = Vrab24 != 0;
           insize Vrab26 = Vrab14; if(Vrab26 == 0) Vrab26 = rinsize(-1);
           while(true)
           {
            int64 Vrab27 = Vrab17 + Vrab21;
            if(Vrab25) if(Vrab22 - 800 != 0) Vrab27 -= (((Vrab24 - 800) * Vrab06) / (Vrab22 - 800)) - Vrab06;
            if(Vrab27 > Vrab22) break;
            statics int64 Vrab28 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->height;
            statics int1  Vrab29 = Vrab28 != 0;
            int64 Vrab30 = Vrab18; if(Vrab29) if(Backgrounds[Section[Vrab01].Background].zwidth[1] - 400 != 0) Vrab30 -= (((Vrab28 - 400) * Vrab07) / (Backgrounds[Section[Vrab01].Background].zwidth[1] - 400)) - Vrab07;

            statics insize Vrab31 = Vect01.size(); Vect01.push_back(Strc01());
            Vect01[Vrab31].Vrab01 = rxint64((Vrab19 <= Backgrounds[Section[Vrab01].Background].zwidth[0]) ? (-100000 + Backgrounds[Section[Vrab01].Background].zwidth[0]) : Vrab19);
            Vect01[Vrab31].Vrab02 = Vrab16 == 1 ? 6 : 2;
            Vect01[Vrab31].Vrab03 = Vrab12;
            Vect01[Vrab31].Vrab04 = Vrab27;
            Vect01[Vrab31].Vrab05 = Vrab30;
            Vect01[Vrab31].Vrab06 = 0;
            Vect01[Vrab31].Vrab07 = ruint8(255 - Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->trans);
            Vect01[Vrab31].Vrab08 = 0;
            Vect01[Vrab31].Vrab09 = 0;
            Vect01[Vrab31].Vrab10 = Backgrounds[Section[Vrab01].Background].Layer[Vrab11]->rotate;

            Vrab21 += Vrab23; Vrab26 -= 1; if(Vrab26 == 0) break;
           }
          }
         }
         Vrab11 += 1;
        }
       } else
       {
        // Camera Limits
        {
         int64 Vrab10 = Object[Vrab08].Data->Background->cam[0] + Object[Vrab08].Data->Background->width[0];
         int64 Vrab11 = Object[Vrab08].Data->Background->cam[1] + Object[Vrab08].Data->Background->width[1];
         int64 Vrab12 = Object[Vrab08].Data->Background->cam[2] + Object[Vrab08].Data->Background->zwidth[0];
         int64 Vrab13 = Object[Vrab08].Data->Background->cam[3] + Object[Vrab08].Data->Background->zwidth[1];
         if(Vrab11 - Vrab10 <= Vrab04){Vrab06 = 0;} else
         {
          if(Vrab06 < Vrab10) Vrab06 = Vrab10;
          if(Vrab06 + Vrab04 > Vrab11) Vrab06 = Vrab11 - Vrab04;
         }
         if(Vrab13 - Vrab12 <= Vrab05){Vrab07 = 0;} else
         {
          if(Vrab07 < Vrab12) Vrab07 = Vrab12;
          if(Vrab07 + Vrab05 > Vrab13) Vrab07 = Vrab13 - Vrab05;
         }
        }

        statics insize Vrab10 = Object[Vrab08].Data->Background->Layer.size(); 
        if(Object[Vrab08].Animation.size() <= Vrab10 + Object[Vrab08].Data->Background->Opoint.size()) Object[Vrab08].Animation.resize(Vrab10 + Object[Vrab08].Data->Background->Opoint.size());
        insize Vrab11 = 0; while(Vrab11 < Vrab10)
        {
         statics insize &Vrab12 = Object[Vrab08].Data->Background->Layer[Vrab11]->Index_pic;
         statics uint32 &Vrab13 = Object[Vrab08].Data->Background->Layer[Vrab11]->loop;
         statics insize &Vrab14 = Object[Vrab08].Data->Background->Layer[Vrab11]->loop_count;
         statics uint32 &Vrab15 = Object[Vrab08].Data->Background->Layer[Vrab11]->color;
         statics uint8  &Vrab16 = ruint8(Object[Vrab08].Data->Background->Layer[Vrab11]->kind); if(Vrab16 == 2){Vrab11 += 1; continue;}
         statics int64  &Vrab17 = rint64(Object[Vrab08].Data->Background->Layer[Vrab11]->x);
         statics int64  &Vrab18 = rint64(Object[Vrab08].Data->Background->Layer[Vrab11]->y);
         statics int64  &Vrab19 = rint64(Object[Vrab08].Data->Background->Layer[Vrab11]->z);

         if(Vrab15 != 0)
         {
          statics insize Vrab20 = Vect01.size(); Vect01.push_back(Strc01());
          Vect01[Vrab20].Vrab01 = rxint64((Vrab19 <= Object[Vrab08].Data->Background->zwidth[0]) ? (-100000 + Object[Vrab08].Data->Background->zwidth[0]) : Vrab19);
          Vect01[Vrab20].Vrab02 = 0;
          Vect01[Vrab20].Vrab03 = Vrab15;
          Vect01[Vrab20].Vrab04 = Vrab17;
          Vect01[Vrab20].Vrab05 = Vrab18;
          Vect01[Vrab20].Vrab06 = ruint8(Object[Vrab08].Data->Background->Layer[Vrab11]->rotate);
          Vect01[Vrab20].Vrab07 = ruint8(255 - Object[Vrab08].Data->Background->Layer[Vrab11]->trans);
          Vect01[Vrab20].Vrab08 = Object[Vrab08].Data->Background->Layer[Vrab11]->width;
          Vect01[Vrab20].Vrab09 = Object[Vrab08].Data->Background->Layer[Vrab11]->height;         
         } else
         {
          statics uint32 Vrab20 = Object[Vrab08].Animation[Vrab11];
          if(Vrab20 >= (Object[Vrab08].Data->Background->Layer[Vrab11]->c1 * (Polish ? 4 : 1)) && Vrab20 <= (Object[Vrab08].Data->Background->Layer[Vrab11]->c2 * (Polish ? 4 : 1)) + (Polish ? 3 : 0))
          {
           int64  Vrab21 = 0;
           int64  Vrab22 = rint64(Object[Vrab08].Data->Background->width[1]);
           int64  Vrab23 = Vrab13; if(Vrab13 == 0) Vrab23 = Vrab22 + 1;
           statics int64 Vrab24 = rint64(Object[Vrab08].Data->Background->Layer[Vrab11]->width);
           statics int1  Vrab25 = Vrab24 != 0;
           insize Vrab26 = Vrab14; if(Vrab26 == 0) Vrab26 = rinsize(-1);
           while(true)
           {
            int64 Vrab27 = Vrab17 + Vrab21;
            if(Vrab25) if(Vrab22 - 800 != 0) Vrab27 -= (((Vrab24 - 800) * Vrab06) / (Vrab22 - 800)) - Vrab06;
            if(Vrab27 > Vrab22) break;
            statics int64 Vrab28 = Object[Vrab08].Data->Background->Layer[Vrab11]->height;
            statics int1  Vrab29 = Vrab28 != 0;
            int64 Vrab30 = Vrab18; if(Vrab29) if(Object[Vrab08].Data->Background->zwidth[1] - 400 != 0) Vrab30 -= (((Vrab28 - 400) * Vrab07) / (Object[Vrab08].Data->Background->zwidth[1] - 400)) - Vrab07;

            statics insize Vrab31 = Vect01.size(); Vect01.push_back(Strc01());
            Vect01[Vrab31].Vrab01 = rxint64((Vrab19 <= Object[Vrab08].Data->Background->zwidth[0]) ? (-100000 + Object[Vrab08].Data->Background->zwidth[0]) : Vrab19);
            Vect01[Vrab31].Vrab02 = Vrab16 == 1 ? 6 : 2;
            Vect01[Vrab31].Vrab03 = Vrab12;
            Vect01[Vrab31].Vrab04 = Vrab27;
            Vect01[Vrab31].Vrab05 = Vrab30;
            Vect01[Vrab31].Vrab06 = 0;
            Vect01[Vrab31].Vrab07 = ruint8(255 - Object[Vrab08].Data->Background->Layer[Vrab11]->trans);
            Vect01[Vrab31].Vrab08 = 0;
            Vect01[Vrab31].Vrab09 = 0;
            Vect01[Vrab31].Vrab10 = Object[Vrab08].Data->Background->Layer[Vrab11]->rotate;

            Vrab21 += Vrab23; Vrab26 -= 1; if(Vrab26 == 0) break;
           }
          }
         }
         Vrab11 += 1;
        }
       }

       // Shadow. (Drawn before any entities.)
       {
        insize Vrab10 = Backgrounds[Section[Vrab01].Background].Index_shadow;
        xint64 Vrab11 = rxint64(Backgrounds[Section[Vrab01].Background].shadow[0]);
        xint64 Vrab12 = rxint64(Backgrounds[Section[Vrab01].Background].shadow[1]);
        if(Vrab08 != rinsize(-1))
        {
         Vrab10 = Object[Vrab08].Data->Background->Index_shadow;
         Vrab11 = rxint64(Object[Vrab08].Data->Background->shadow[0]);
         Vrab12 = rxint64(Object[Vrab08].Data->Background->shadow[1]);
        }

        insize Vrab13 = Object.size();
        while(Vrab13 != 0)
        {
         Vrab13 -= 1; if(!Object[Vrab13].Exist) continue; if(Object[Vrab13].Section != Vrab01) continue; if(Object[Vrab13].D != Vrab08) continue;
         if(Object[Vrab13].Held != rinsize(-1)) continue;
         statics insize Vrab14 = Object[Vrab13].Data->id; if(Vrab14 == 223 || Vrab14 == 224) continue;
         statics int32  Vrab15 = Object[Vrab13].Blink; if(Vrab15 < 70){if((Vrab15 % 4 > 1 && Vrab15 > 0) || (Vrab15 % 4 < -1 && Vrab15 < 0)) continue;} else {continue;}
         statics insize Vrab16 = Object[Vrab13].Frame; if(Vrab16 < Object[Vrab13].Data->Frame.size()) if(Object[Vrab13].Data->Frame[Vrab16]->Exist)
         {
          insize Vrab17 = Object[Vrab13].Data->Frame[Vrab16]->state.size(); int1 Vrab18 = false;
          while(Vrab17 != 0)
          {
           Vrab17 -= 1;
           switch(Object[Vrab13].Data->Frame[Vrab16]->state[Vrab17])
           {
           case 3005: case 400: case 401: Vrab18 = true; break;
           default: break;
           }
          } if(Vrab18) continue;
         }
         statics insize Vrab17 = Vect01.size(); Vect01.resize(Vrab17 + 1);
         Vect01[Vrab17].Vrab01 = -10000;
         Vect01[Vrab17].Vrab02 = 2;
         Vect01[Vrab17].Vrab03 = Vrab10;
         Vect01[Vrab17].Vrab04 = Object[Vrab13].X - Vrab11;
         Vect01[Vrab17].Vrab05 = Object[Vrab13].Z - Vrab12;
        }
       }

       // Object
       {
        insize Vrab10 = Object.size();
        while(Vrab10 != 0)
        {
         Vrab10 -= 1; if(!Object[Vrab10].Exist) continue; if(Object[Vrab10].Section != Vrab01) continue; if(Object[Vrab10].D != Vrab08) continue;

         statics insize Vrab11 = Object[Vrab10].Frame + Object[Vrab10].Frame_Offset;
         if(Vrab11 >= Object[Vrab10].Data->Frame.size()) continue; if(!Object[Vrab10].Data->Frame[Vrab11]->Exist) continue;

         // Name & Info
         {
          statics insize Vrab12 = Vect01.size(); Vect01.resize(Vrab12 + 1);
          Vect01[Vrab12].Vrab01 = Object[Vrab10].Z;
          Vect01[Vrab12].Vrab02 = 69;
          Vect01[Vrab12].Vrab04 = Object[Vrab10].X;
          Vect01[Vrab12].Vrab05 = Object[Vrab10].Z;

          // Bar
          if(Object[Vrab10].Data->type == 0)
          {
           Vect01[Vrab12].Temp01 = Object[Vrab10].Name;
           insize Vrab19 = 73, Vrab20 = (Object[Vrab10].HP_Regen > 0 && Section[Vrab01].Timeunit % 4 > 1) ? 72 : 71, Vrab21 = 76, Vrab22 = 74;
           xint64 Vrab23 = Object[Vrab10].MHP; {statics xint64 Vrab24 = Object[Vrab10].DHP; if(Vrab24 > Vrab23) Vrab23 = Vrab24;}
           int64 Vrab24 = L_Rounding64((Object[Vrab10].HP / Vrab23) * 60.0);
           int64 Vrab25 = L_Rounding64((Object[Vrab10].DHP / Vrab23) * 60.0);
           int64 Vrab26 = L_Rounding64((Object[Vrab10].MP / Object[Vrab10].MMP) * 60.0);
           if(Vrab24 > Vrab25){auto Vrab27 = Vrab24; Vrab24 = Vrab25; Vrab25 = Vrab27; if(Object[Vrab10].HP > Object[Vrab10].DHP) Vrab19 = 80;}
           int64 Vrab27 = 0;
           if(Vrab25 > 60){Vrab27 = Vrab25 - 60; Vrab25 = 60; if(Vrab27 > 60) Vrab27 = 60;}
           if(Vrab26 > 60) Vrab26 = 60;
           if(Vrab25 > 0)
           {
            statics insize Vrab28 = Vect01.size(); Vect01.resize(Vrab28 + 1);
            Vect01[Vrab28].Vrab01 = Object[Vrab10].Z;
            Vect01[Vrab28].Vrab02 = 2;
            Vect01[Vrab28].Vrab03 = Enchanted->Vect004[Vrab19];
            Vect01[Vrab28].Vrab04 = Object[Vrab10].X - 30;
            Vect01[Vrab28].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery - 13;
            Vect01[Vrab28].Vrab08 = Vrab25;
            Vect01[Vrab28].Vrab09 = 3;
           }
           if(Vrab24 > 0)
           {
            statics insize Vrab28 = Vect01.size(); Vect01.resize(Vrab28 + 1);
            Vect01[Vrab28].Vrab01 = Object[Vrab10].Z;
            Vect01[Vrab28].Vrab02 = 2;
            Vect01[Vrab28].Vrab03 = Enchanted->Vect004[Vrab20];
            Vect01[Vrab28].Vrab04 = Object[Vrab10].X - 30;
            Vect01[Vrab28].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery - 13;
            Vect01[Vrab28].Vrab08 = Vrab24;
            Vect01[Vrab28].Vrab09 = 3;
           }
           if(Vrab27 > 0)
           {
            statics insize Vrab28 = Vect01.size(); Vect01.resize(Vrab28 + 1);
            Vect01[Vrab28].Vrab01 = Object[Vrab10].Z;
            Vect01[Vrab28].Vrab02 = 2;
            Vect01[Vrab28].Vrab03 = Enchanted->Vect004[Vrab19];
            Vect01[Vrab28].Vrab04 = Object[Vrab10].X - 30;
            Vect01[Vrab28].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery - 13;
            Vect01[Vrab28].Vrab08 = Vrab27;
            Vect01[Vrab28].Vrab09 = 3;
           }
           if(Vrab24 > 0 || Vrab25 > 0)
           {
            statics insize Vrab28 = Vect01.size(); Vect01.resize(Vrab28 + 1);
            Vect01[Vrab28].Vrab01 = Object[Vrab10].Z;
            Vect01[Vrab28].Vrab02 = 2;
            Vect01[Vrab28].Vrab03 = Enchanted->Vect004[Vrab21];
            Vect01[Vrab28].Vrab04 = Object[Vrab10].X - 30;
            Vect01[Vrab28].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery - 10;
            Vect01[Vrab28].Vrab08 = 60;
            Vect01[Vrab28].Vrab09 = 3;
           }
           if(Vrab26 > 0)
           {
            statics insize Vrab28 = Vect01.size(); Vect01.resize(Vrab28 + 1);
            Vect01[Vrab28].Vrab01 = Object[Vrab10].Z;
            Vect01[Vrab28].Vrab02 = 2;
            Vect01[Vrab28].Vrab03 = Enchanted->Vect004[Vrab22];
            Vect01[Vrab28].Vrab04 = Object[Vrab10].X - 30;
            Vect01[Vrab28].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery - 10;
            Vect01[Vrab28].Vrab08 = Vrab26;
            Vect01[Vrab28].Vrab09 = 3;
           }
          }

          // Hitboxes
          if(Hitboxes)
          {
           insize Vrab13 = Object[Vrab10].Data->Frame[Vrab11]->itr.size();
           while(Vrab13 != 0)
           {
            Vrab13 -= 1; insize Vrab14 = Vect01.size(); Vect01.resize(Vrab14 + 1);
            Vect01[Vrab14].Vrab01 = 9999999999;
            Vect01[Vrab14].Vrab02 = 1;
            Vect01[Vrab14].Vrab03 = Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].kind != 0 ? 0xFFA500 : 0xFF0000;
            Vect01[Vrab14].Vrab04 = Object[Vrab10].X - ((Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].x - Object[Vrab10].Data->Frame[Vrab11]->centerx) * (Object[Vrab10].Facing ? -1.0 : 1.0)) - (Object[Vrab10].Facing ? 0 : Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].w);
            Vect01[Vrab14].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery + Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].y;
            Vect01[Vrab14].Vrab08 = Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].w;
            Vect01[Vrab14].Vrab09 = Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].h;
            Vrab14 = Vect01.size(); Vect01.resize(Vrab14 + 1);
            Vect01[Vrab14].Vrab01 = 999999999;
            Vect01[Vrab14].Vrab02 = 0;
            Vect01[Vrab14].Vrab03 = Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].kind != 0 ? 0xFFA500 : 0xFF0000;
            Vect01[Vrab14].Vrab04 = Object[Vrab10].X - ((Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].x - Object[Vrab10].Data->Frame[Vrab11]->centerx) * (Object[Vrab10].Facing ? -1.0 : 1.0)) - (Object[Vrab10].Facing ? 0 : Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].w) + 1;
            Vect01[Vrab14].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery + Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].y + 1;
            Vect01[Vrab14].Vrab07 = 50;
            Vect01[Vrab14].Vrab08 = Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].w - 2;
            Vect01[Vrab14].Vrab09 = Object[Vrab10].Data->Frame[Vrab11]->itr[Vrab13].h - 2;
           }
           Vrab13 = Object[Vrab10].Data->Frame[Vrab11]->bdy.size();
           while(Vrab13 != 0)
           {
            Vrab13 -= 1; insize Vrab14 = Vect01.size(); Vect01.resize(Vrab14 + 1);
            Vect01[Vrab14].Vrab01 = 9999999999;
            Vect01[Vrab14].Vrab02 = 1;
            Vect01[Vrab14].Vrab03 = 0xFF00;
            Vect01[Vrab14].Vrab04 = Object[Vrab10].X - ((Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].x - Object[Vrab10].Data->Frame[Vrab11]->centerx) * (Object[Vrab10].Facing ? -1.0 : 1.0)) - (Object[Vrab10].Facing ? 0 : Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].w);
            Vect01[Vrab14].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery + Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].y;
            Vect01[Vrab14].Vrab08 = Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].w;
            Vect01[Vrab14].Vrab09 = Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].h;
            Vrab14 = Vect01.size(); Vect01.resize(Vrab14 + 1);
            Vect01[Vrab14].Vrab01 = 999999999;
            Vect01[Vrab14].Vrab02 = 0;
            Vect01[Vrab14].Vrab03 = 0xFF00;
            Vect01[Vrab14].Vrab04 = Object[Vrab10].X - ((Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].x - Object[Vrab10].Data->Frame[Vrab11]->centerx) * (Object[Vrab10].Facing ? -1.0 : 1.0)) - (Object[Vrab10].Facing ? 0 : Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].w) + 1;
            Vect01[Vrab14].Vrab05 = Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery + Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].y + 1;
            Vect01[Vrab14].Vrab07 = 50;
            Vect01[Vrab14].Vrab08 = Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].w - 2;
            Vect01[Vrab14].Vrab09 = Object[Vrab10].Data->Frame[Vrab11]->bdy[Vrab13].h - 2;
           }
          }
         }

         {statics int32 Vrab12 = Object[Vrab10].Blink; if(Vrab12 < 70){if((Vrab12 % 4 > 1 && Vrab12 > 0) || (Vrab12 % 4 < -1 && Vrab12 < 0)) continue;} else {continue;}}
         statics xint64 Vrab12 = (Object[Vrab10].Facing ? 1.0 : -1.0);
         statics xint64 Vrab13[3] = {(Object[Vrab10].X - (Object[Vrab10].Data->Frame[Vrab11]->centerx * Vrab12)), (Object[Vrab10].Z + Object[Vrab10].Y - Object[Vrab10].Data->Frame[Vrab11]->centery), (Object[Vrab10].Z)};

         insize Vrab14 = Object[Vrab10].Data->Frame[Vrab11]->ppoint.size();
         if(Vrab14 != 0)
         {
          while(Vrab14 != 0)
          {
           Vrab14 -= 1; statics insize *Vrab15 = Pic_To_Address(Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].pic + Object[Vrab10].Pic_Offset, Object[Vrab10].Data);
           statics insize Vrab16 = Vect01.size(); Vect01.resize(Vrab16 + 1);
           Vect01[Vrab16].Vrab01 = Vrab13[2] + Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].z + (rxint64(Object[Vrab10].Data->type) * 0.00001);
           Vect01[Vrab16].Vrab02 = 4;
           Vect01[Vrab16].Vrab03 = Vrab15[0];
           Vect01[Vrab16].Vrab04 = Vrab13[0] + (Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].x * Vrab12) - (Object[Vrab10].Facing ? 0 : Vrab15[1]);
           Vect01[Vrab16].Vrab05 = Vrab13[1] + Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].y;
           Vect01[Vrab16].Vrab06 = (Object[Vrab10].Facing ? 0ui8 : 1ui8);
           Vect01[Vrab16].Vrab07 = ruint8(255 - Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].trans);
           Vect01[Vrab16].Vrab08 = Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].stx;
           Vect01[Vrab16].Vrab09 = Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].sty;
           Vect01[Vrab16].Vrab10 = ruint8(Object[Vrab10].Data->Frame[Vrab11]->ppoint[Vrab14].rotate);
          }
         } else
         {
          statics insize *Vrab15 = Pic_To_Address(Object[Vrab10].Data->Frame[Vrab11]->pic + Object[Vrab10].Pic_Offset, Object[Vrab10].Data);
          statics insize Vrab16 = Vect01.size(); Vect01.resize(Vrab16 + 1);
          Vect01[Vrab16].Vrab01 = Vrab13[2] + (rxint64(Object[Vrab10].Data->type) * 0.00001);
          Vect01[Vrab16].Vrab02 = 4;
          Vect01[Vrab16].Vrab03 = Vrab15[0];
          Vect01[Vrab16].Vrab04 = Vrab13[0] - (Object[Vrab10].Facing ? 0 : Vrab15[1]);
          Vect01[Vrab16].Vrab05 = Vrab13[1];
          Vect01[Vrab16].Vrab06 = (Object[Vrab10].Facing ? 0ui8 : 1ui8);
         }
        }
       }

       // Sorting & Drawing.
       {
        //std::vector < Strc01* > Vect02;
        /*
        {
        insize Vrab10 = Vect01.size();
        while(Vrab10 != 0)
        {
        Vrab10 -= 1; statics insize Vrab11 = Vect02.size(); insize Vrab12 = 0;
        while(Vrab12 < Vrab11)
        {
        if(Vect01[Vrab10].Vrab01 > Vect02[Vrab12]->Vrab01) break;
        Vrab12 += 1;
        }
        Vect02.insert(Vect02.begin() + Vrab12, &Vect01[Vrab10]);
        }
        }*/

        std::sort(Vect01.begin(), Vect01.end());

        insize Vrab10 = Vect01.size(); int64 Vrab11 = Vrab09 % 1000; xint64 Vrab12 = (((Vrab09 % 10000 < 1000) ? 1.0 : -1.0) * rxint64(Vrab09 - (Vrab09 % 10000))) / 10000000.0; xint64 Vrab13 = rxint64(Vrab02) + (rxint64(Vrab04) / 2.0); xint64 Vrab14 = rxint64(Vrab03) + (rxint64(Vrab05) / 2.0);
        while(Vrab10 != 0)
        {
         Vrab10 -= 1; 
         int64 Vrab15 = Vect01[Vrab10].Vrab04 + Vrab02 - Vrab06; int64 Vrab16 = Vect01[Vrab10].Vrab05 + Vrab03 - Vrab07;
         if(Vect01[Vrab10].Vrab02 == 69) Enchanted->Print_Text(0, 0, 0, Vect01[Vrab10].Temp01, 0, 1);
         if(Vrab09 != 0)
         {
          statics xint64 Vrab17 = Vrab12 + 1.0;
          if(Vect01[Vrab10].Vrab02 < 2)
          {
           xint64 Vrab18 = (rxint64(Vrab15) + (rxint64(Vect01[Vrab10].Vrab08) / 2.0) - Vrab13) * Vrab17;
           xint64 Vrab19 = (rxint64(Vrab16) + (rxint64(Vect01[Vrab10].Vrab09) / 2.0) - Vrab14) * Vrab17;
           if(Vrab11 != 0)
           {
            statics xint64 *Vrab20 = L_Rotate(Vrab18, Vrab19, Vrab11);
            Vrab18 = Vrab20[0]; Vrab19 = Vrab20[1]; Vect01[Vrab10].Vrab06 = (Vect01[Vrab10].Vrab06 + Vrab11) % 180;
           }
           statics xint64 Vrab20 = rxint64(Vect01[Vrab10].Vrab08) * Vrab17;
           statics xint64 Vrab21 = rxint64(Vect01[Vrab10].Vrab09) * Vrab17;
           Vrab15 = L_Rounding64(Vrab18 - (Vrab20 / 2.0) + Vrab13);
           Vrab16 = L_Rounding64(Vrab19 - (Vrab21 / 2.0) + Vrab14);
           Vect01[Vrab10].Vrab08 = L_Rounding64(Vrab20);
           Vect01[Vrab10].Vrab09 = L_Rounding64(Vrab21);
          } else
          {
           xint64 Vrab18 = 0; xint64 Vrab19 = 0;
           if(Vect01[Vrab10].Vrab02 == 69)
           {
            Vrab19 = Enchanted->Vrab016[1];
           } else
           {
            statics int1 Vrab20 = ((Vect01[Vrab10].Vrab02 >= 4 && Vect01[Vrab10].Vrab02 <= 5) || (Vect01[Vrab10].Vrab02 >= 8 && Vect01[Vrab10].Vrab02 <= 9));
            Vrab18 = P_Get_Width(Vect01[Vrab10].Vrab03, Vrab20); Vrab19 = P_Get_Height(Vect01[Vrab10].Vrab03, Vrab20);
           }
           xint64 Vrab20 = (rxint64(Vrab15) + (Vrab18 / 2.0) - Vrab13) * Vrab17;
           xint64 Vrab21 = (rxint64(Vrab16) + (Vrab19 / 2.0) - Vrab14) * Vrab17;
           if(Vrab11 != 0)
           {
            statics xint64 *Vrab22 = L_Rotate(Vrab20, Vrab21, Vrab11);
            Vrab20 = Vrab22[0]; Vrab21 = Vrab22[1]; Vect01[Vrab10].Vrab10 += Vrab11;
           }
           statics xint64 Vrab22 = (Vrab18 + rxint64(Vect01[Vrab10].Vrab08)) * Vrab17;
           statics xint64 Vrab23 = (Vrab19 + rxint64(Vect01[Vrab10].Vrab09)) * Vrab17;
           Vrab15 = L_Rounding64(Vrab20 - (Vrab18 / 2.0) + Vrab13);
           Vrab16 = L_Rounding64(Vrab21 - (Vrab19 / 2.0) + Vrab14);
           Vect01[Vrab10].Vrab08 = L_Rounding64(Vrab22) - Vrab18;
           Vect01[Vrab10].Vrab09 = L_Rounding64(Vrab23) - Vrab19;
          }
         }
         if(Vect01[Vrab10].Vrab02 == 69)
         {
          Vrab15 -= L_Rounding64(Enchanted->Vrab016[0] / 2.0);
          if(Vrab15 + Enchanted->Vrab016[0] > Vrab02 + Vrab04) Vrab15 = Vrab02 + Vrab04 - Enchanted->Vrab016[0];
          if(Vrab15 < Vrab02) Vrab15 = Vrab02;
          if(Vrab16 + Enchanted->Vrab016[1] > Vrab03 + Vrab05) Vrab16 = Vrab03 + Vrab05 - Enchanted->Vrab016[1];
          if(Vrab16 < Vrab03) Vrab16 = Vrab03;
          Enchanted->Print_Text(Vrab15, Vrab16, 0, Vect01[Vrab10].Temp01); continue;
         }
         P_Set_Display(Vect01[Vrab10].Vrab02, Vect01[Vrab10].Vrab03, Vrab15, Vrab16, Vect01[Vrab10].Vrab06, Vect01[Vrab10].Vrab07, Vect01[Vrab10].Vrab08, Vect01[Vrab10].Vrab09, Vect01[Vrab10].Vrab10);
        }
       }
      }

      int0    Order (statics string Temp01, statics insize Vrab01 = 0)
      {
       if(Section.size() <= Vrab01) Section.resize(Vrab01 + 1); if(Loaded != 3) return; if(!Section[Vrab01].Ready) return;

       if(Temp01 == "pause") Section[Vrab01].Pause = !Section[Vrab01].Pause;
       if(Temp01 == "fpause"){Section[Vrab01].Pause = false; Section[Vrab01].TPause = true;}
       if(Temp01 == "hitbox"){Hitboxes += 1; if(Hitboxes > 2) Hitboxes = 0;}
       if(Temp01 == "reload")
       {
        insize Vrab02 = Object.size(); Vect001.clear(); Vect001.resize(Vrab02); Vrab001 = true;
        while(Vrab02 != 0)
        {
         Vrab02 -= 1;
         if(Object[Vrab02].Exist)
         {
          Vect001[Vrab02] = Object[Vrab02].Data->id; Object[Vrab02].Data = nullptr;
          Object[Vrab02].Trans_Address.clear(); Object[Vrab02].Trans = 0;
          Object[Vrab02].Return_Address.clear(); Object[Vrab02].Return = 0;
         } else {Vect001[Vrab02] = rinsize(-1);}
        }
        Loaded = 0;
       }
      }
      int0    Keys  (std::vector < std::vector < int8 > > Vect01) perfect
      {
       Inputs.clear();
       statics insize Vrab01 = Vect01.size(); insize Vrab02 = 0;
       while(Vrab02 < Vrab01)
       {
        Inputs.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_PLAYERINPUTS());
        Inputs[Vrab02].User = Vrab02 + 1;
        Inputs[Vrab02].Up = (Vect01[Vrab02][0] > 0) ? 1 : 0;
        Inputs[Vrab02].Left = (Vect01[Vrab02][1] > 0) ? 1 : 0;
        Inputs[Vrab02].Down = (Vect01[Vrab02][2] > 0) ? 1 : 0;
        Inputs[Vrab02].Right = (Vect01[Vrab02][3] > 0) ? 1 : 0;
        Inputs[Vrab02].A = (Vect01[Vrab02][4] > 0) ? 1 : 0;
        Inputs[Vrab02].D = (Vect01[Vrab02][5] > 0) ? 1 : 0;
        Inputs[Vrab02].J = (Vect01[Vrab02][6] > 0) ? 1 : 0;
        Inputs[Vrab02].C = (Vect01[Vrab02][7] > 0) ? 1 : 0;
        Vrab02 += 1;
       }
      }

      string  Temp  (statics insize Vrab01 = 0)
      {
       if(Section.size() <= Vrab01) Section.resize(Vrab01 + 1); if(Loaded != 3) return ""; if(!Section[Vrab01].Ready) return "";

       insize Vrab02 = 0;
       insize Vrab03 = Object.size();
       while(Vrab03 != 0){Vrab03 -= 1; if(Object[Vrab03].Exist) Vrab02 += 1;}
       return std::to_string(Vrab02);
      }
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE2
    {
     private:
      /*
      struct HEPTA_LF2_ENCHANTED_ENGINE2_STAGES_STAGE_PHASE_ENTITY
      {
       uint8  role = 0; // <boss> , <soldier>
       insize id = rinsize(-1);
       int32  hp = 500;
       int32  x, y, z, act, times, reserve, join, join_reserve;
       xint64 ratio = 1;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_STAGES_STAGE_PHASE
      {
       int32  bound = 0;
       insize music_Index = rinsize(-1);
       insize when_clear_goto_phase = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_STAGES_STAGE_PHASE_ENTITY > Entity;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_STAGES_STAGE
      {
       insize id = 0;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_STAGES_STAGE_PHASE > Phase;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_STAGES
      {
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_STAGES_STAGE > Stage;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_BACKGROUND_LAYER 
      {
       int32  transparency, width, height, x, y, loop, cc, c1, c2, rect32;
       insize image_Index = rinsize(-1);
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_BACKGROUND
      {
       string name;
       insize id = rinsize(-1);
       int32  x, width, zboundary[2]{}, perspective[2]{}, shadowsize[2]{};
       insize shadow_Index = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_BACKGROUND_LAYER > Layer;
      };
	     struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_PPOINT
	  {
	   int32 pic, x, y, z, rotate, w, h, trans;
	  };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_BPOINT
      {
       int32 x, y, z, w, h, rect32;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_CPOINT
      {
       int32 kind, x, y, z, vaction, aaction, daction, jaction, taction, throwvx, throwvy, throwvz, throwinjury, dircontrol, hurtable, decrease, cover, injury, fronthurtact, backhurtact;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_WPOINT
      {
       int32 kind, x, y, z, dvx, dvy, dvz, weaponact, attacking, cover;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_OPOINT
      {
       int32 kind, x, y, z, dvx, dvy, dvz, oid, action, facing;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_IPOINT
      {
       int32 kind, x, y, z, w, h, zwidth, dvx, dvy, dvz, fall, arest, vrest, respond, effect, bdefend, injury, catchingact[2], caughtact[2];
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_HPOINT
      {
       int32 kind, x, y, z, w, h, zwidth;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME
      {
       int1   Exist = false;
       insize pic = rinsize(-1);
       int32  state, wait, next, dvx, dvy, dvz, centerx, centery, centerz, mp, hit_a, hit_d, hit_j, hit_Fa, hit_Fj, hit_Da, hit_Dj, hit_Ua, hit_Uj, hit_ja;
       insize sound_Index = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_PPOINT > ppoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_BPOINT > bpoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_CPOINT > cpoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_WPOINT > wpoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_OPOINT > opoint;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_IPOINT > itr;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME_HPOINT > bdy;
     
       // Runtime Data
       int32 bdy_X = 0, bdy_Y = 0, bdy_W = 0, bdy_H = 0;
       int32 itr_X = 0, itr_Y = 0, itr_W = 0, itr_H = 0, itr_Z = 0;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_STRENGTH
      {
       int32 dvx, dvy, dvz, fall, arest, vrest, respond, effect, bdefend, injury;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_PIC
      {
       insize Picture_Index = rinsize(-1);
       insize Picture_Mirror_Index = rinsize(-1);
       string address;
       uint32 w = 1, h = 1, col = 1, row = 1;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT
      {
       insize id = rinsize(-1);
       uint8  type = 0;
       string name;
       insize head_Index = rinsize(-1), small_Index = rinsize(-1);
       std::vector < insize > file_Index;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_PIC > file;
       int32  walking_frame_rate, running_frame_rate, weapon_hp, weapon_drop_hurt;
       xint64 walking_speed, walking_speedz, running_speed, running_speedz, heavy_walking_speed, heavy_walking_speedz, heavy_running_speed, heavy_running_speedz, jump_height, jump_distance, jump_distancez, dash_height, dash_distance, dash_distancez, rowing_height, rowing_distance;
       insize weapon_hit_sound_Index = rinsize(-1), weapon_drop_sound_Index = rinsize(-1), weapon_broken_sound_Index = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_STRENGTH > Strength;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME* > Frame;
      };
    
      struct HEPTA_LF2_ENCHANTED_ENGINE2_EFFECT
      {
       xint64 X = 0.0, Y = 0.0, Z = 0.0; int1 Exist = true;
       insize Pic = 0; int1 Sprite = false; int1 Loop = false; int1 Screen = false;
       std::vector < insize > Pics;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE2_GAMEOBJECT
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
       HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT *Data;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT* > Trans_Address; uint8 Trans = 0;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT* > Return_Address; uint8 Return = 0;

					int1 Stamp = false;
					uint64 Stamp_Time = 0;
					std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_GAMEOBJECT > Stamp_Data;
					std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_EFFECT > Stamp_Effect;
					std::vector < std::vector < uint32 > > Stamp_Animation;
      };

      string Temp001;        // Working Address.
      int1   Vrab001 = true; // Debug output.

      std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_EFFECT >     Effect;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_GAMEOBJECT > Object;
     
      unique < HEPTA_LF2_ENCHANTED_ENGINE2_STAGES > Stages;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT >     Objects;             // Database of Objects.
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE2_BACKGROUND > Backgrounds;         // Database of Backgrounds.
      std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE2_OBJECT_FRAME > > Frames; // Frames' Pointer.
      */
      
      string Temp001;                 // Working Address.
      string Temp002;                 // Main Address.
      int1   Vrab001 = true;          // Debug output.
      int1   Vrab002 = false;         // Load file open?
      std::ifstream File001;          // Load file.
      asIScriptEngine *Engi001;       // AngelScript's Engine.
      asIScriptModule *Modu001;       // AngelScript's Engine.
      asIScriptContext *Cont001;      // AngelScript's Engine.
      asIScriptFunction *Func001;     // AngelScript's Engine.
      std::time_t Time001;            // Engine's Modified Time.
      struct stat Stat001;            // Global Stat.
      
      int0   Printaddr(int0 *Vrab01){printf("%p", Vrab01);}
      int0   Print(int1 Vrab01)  {printf(Vrab01 ? "true" : "false");}
      int0   Print(int8 Vrab01)  {printf("%d", Vrab01);}
      int0   Print(int16 Vrab01) {printf("%d", Vrab01);}
      int0   Print(int32 Vrab01) {printf("%d", Vrab01);}
      int0   Print(int64 Vrab01) {printf("%lld", Vrab01);}
      int0   Print(uint8 Vrab01) {printf("%u", Vrab01);}
      int0   Print(uint16 Vrab01){printf("%u", Vrab01);}
      int0   Print(uint32 Vrab01){printf("%u", Vrab01);}
      int0   Print(uint64 Vrab01){printf("%llu", Vrab01);}
      int0   Print(xint32 Vrab01){printf("%f", Vrab01);}
      int0   Print(xint64 Vrab01){printf("%Lf", Vrab01);}
      int0   Print(statics string &Temp01){printf("%s", Temp01.c_str());}

      int0   Debug(statics string Temp01, statics int8 Vrab01 = 0 , statics int1 Vrab02 = false) perfect
      {
       if(!Vrab001) return;
       if(Vrab02){std::ofstream File01(L_Execute(Temp001 + "debug.log"), std::ios::binary); File01 << ""; File01.close();}
       std::ofstream File01(L_Execute(Temp001 + "debug.log"), std::ios::binary | std::ios::app);
       File01 << (Vrab01 == 0 ? "[" : (Vrab01 == 1 ? ")" : ">")) << L_Pronounce(std::chrono::time_point_cast < std::chrono::milliseconds > (std::chrono::system_clock::now()).time_since_epoch().count()) << (Vrab01 == 0 ? "] INFO - " : (Vrab01 == 1 ? "( WARNING - " : "< ERROR - ")) << Temp01 << "\n";
       File01.close();
      }

     public:
      int1 Running = false;
      int1 Available = false;

      HEPTA_LF2_ENCHANTED_ENGINE2(){}
      int0   Begin(statics string Temp01, statics string Temp02, statics int32 Vrab01 = 0) perfect
      {
       Temp001 = Temp01 + Temp02; Temp002 = Temp01;
       Debug("Enhanced Engine - Starting.", 0, true);
       Running = true;
       
       Debug("Enhanced Engine - AngelScript Initialization.");
       AllocConsole();
       HANDLE Hand01 = GetStdHandle(STD_OUTPUT_HANDLE);
       freopen("CONIN$", "rb", stdin);   // Reopen stdin handle as console window input.
       freopen("CONOUT$", "wb", stdout); // Reopen stout handle as console window output.
       freopen("CONOUT$", "wb", stderr); // Reopen stderr handle as console window output.
       SMALL_RECT Rect01 = {0, 0, 60, 30};
       CONSOLE_SCREEN_BUFFER_INFOEX Info01;
       Info01.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
       SetConsoleScreenBufferSize(Hand01, {60, 150});
       GetConsoleScreenBufferInfoEx(Hand01, &Info01);
       Info01.wAttributes = true; Info01.srWindow = Rect01;
       {
        int32 Vrab02 = 0; if(Vrab01 > 127){Vrab02 = 0;} else {Vrab02 = 255;}
        Info01.ColorTable[0] = Vrab01 + (Vrab01 << 8) + (Vrab01 << 16);
        Info01.ColorTable[1] = Vrab02 + (Vrab02 << 8) + (Vrab02 << 16);
        Info01.ColorTable[7] = Info01.ColorTable[1];
       }
       SetConsoleScreenBufferInfoEx(Hand01, &Info01);
       SetConsoleScreenBufferSize(Hand01, {60, 150});
       SetConsoleTitleA("Windows Console API - LF2: Enchanted");

       Engi001 = NULL;
       Engi001 = asCreateScriptEngine(ANGELSCRIPT_VERSION);
       if(!Engi001) return;
       Engi001->SetMessageCallback(asFUNCTION(L_Message), NULL, asCALL_CDECL);
       RegisterScriptArray(Engi001, true);
       RegisterScriptMath(Engi001);
       RegisterScriptMathComplex(Engi001);
       RegisterStdString(Engi001);
       RegisterStdStringUtils(Engi001);

       // Function Regis
       {
        Engi001->RegisterGlobalFunction("void print(bool p)",             asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (int1 Vrab01),   int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(int8 p)",             asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (int8 Vrab01),   int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(int16 p)",            asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (int16 Vrab01),  int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(int32 p)",            asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (int32 Vrab01),  int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(int64 p)",            asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (int64 Vrab01),  int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(uint8 p)",            asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (uint8 Vrab01),  int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(uint16 p)",           asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (uint16 Vrab01), int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(uint32 p)",           asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (uint32 Vrab01), int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(uint64 p)",           asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (uint64 Vrab01), int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(float p)",            asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (xint32 Vrab01), int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(double p)",           asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (xint64 Vrab01), int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
        Engi001->RegisterGlobalFunction("void print(const string &in p)", asMETHODPR(HEPTA_LF2_ENCHANTED_ENGINE2, Print, (statics string &Temp01), int0), asCALL_THISCALL_ASGLOBAL, &Enchanted->Engine1);
       }
       
       Debug("Enhanced Engine - System Load, \"" + Temp002 + "engine1.as\"."); printf("\nAngelScript - v%s\n\n", ANGELSCRIPT_VERSION_STRING);
       Engi001->WriteMessage((Temp002 + "engine1.as").c_str(), 0, 0, asMSGTYPE_INFORMATION, ("Building \"" + Temp002 + "engine1.as\"").c_str());
       CScriptBuilder Make01;
       if(!L_Exist(Temp002 + "engine1.as"))                               {Engi001->WriteMessage((Temp002 + "engine1.as").c_str(), 0, 0, asMSGTYPE_ERROR, ("Unable to the system, \"" + Temp002 + "engine1.as\"").c_str()); return;}
       if(stat((Temp002 + "engine1.as").c_str(), &Stat001) == 0) Time001 = Stat001.st_mtime;
       if(Make01.StartNewModule(Engi001, "SYSTEM") < 0)                   {Engi001->DiscardModule("SYSTEM"); Engi001->WriteMessage((Temp002 + "engine1.as").c_str(), 0, 0, asMSGTYPE_ERROR, "Unable to start the Module"); return;}
       if(Make01.AddSectionFromFile((Temp002 + "engine1.as").c_str()) < 0){Engi001->DiscardModule("SYSTEM"); Engi001->WriteMessage((Temp002 + "engine1.as").c_str(), 0, 0, asMSGTYPE_ERROR, ("Unable to load the system, \"" + Temp002 + "engine1.as\"").c_str()); return;}
       if(Make01.BuildModule() < 0)                                       {Engi001->DiscardModule("SYSTEM"); Engi001->WriteMessage((Temp002 + "engine1.as").c_str(), 0, 0, asMSGTYPE_ERROR, "Unable to build the Module"); return;}
       
       Modu001 = Engi001->GetModule("SYSTEM");
       Cont001 = Engi001->CreateContext();

       // System Begin
       if((Func001 = Modu001->GetFunctionByDecl("void Begin()"))){Cont001->Prepare(Func001); Cont001->Execute();}
       Available = true;
      }
      int0   Shutdown() perfect
      {
       Running = false; Available = false;
       if(Vrab002){File001.close(); Vrab002 = false;}
       FreeConsole();
      }
      int0   Main() perfect
      {
       if(!Running) return;
       if(Available) if((Func001 = Modu001->GetFunctionByDecl("void Main()"))){Cont001->Prepare(Func001); Cont001->Execute();}

       // System Update
       if(L_Exist(Temp002 + "engine1.as"))
       if(stat((Temp002 + "engine1.as").c_str(), &Stat001) == 0)
       if(Time001 < Stat001.st_mtime) Shutdown();
      }
      string Load() perfect
      {
       if(!Vrab002)
       {
        Debug("Enhanced Engine - Data Load, \"" + Temp001 + "data\\data.txt\"."); Vrab002 = true;
        int1 Vrab01 = true;
        while(true)
        {
         if(!L_Exist(Temp001 + "data\\data.txt")) break;
         File001.open(Temp001 + "data\\data.txt"); if(!File001.is_open()) break;
         Vrab01 = false; break;
        } if(Vrab01){Debug("Enhanced Engine - \"" + Temp001 + "data\\data.txt\" cannot be found."); return "F";}
       }
       return "";
      }
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE3
    {
     string Load() perfect
     {
      return "";
     }
    };
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
     int1   Menu = false;
     uint32 Width  = 800;
     uint32 Height = 450;
     int1   Fullscreen = false;
     int1   Aspect_Ratio = true;
     uint8  UI_FPS = 8;
     uint8  Brightness = 100;
     uint8  Volume = 80;
     int8   Pan = 0;
     uint8  Lang = 1;

     int1   Fast_Loading = false;
     int1   Skip_Animation = false;
     int1   Show_FPS = true;
     uint8  Engine = 1;
     string Engine_Setting;
     string Address = "Database\\MiniGame_Enchanted\\";
     string Address_Game = "GameData_Default\\";
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
    struct HEPTA_LF2_ENCHANTED_RUNTIMEDATA
    {
     std::vector < int1 > INT1;
     std::vector < int8 > INT8;
     std::vector < int16 > INT16;
     std::vector < int32 > INT32;
     std::vector < int64 > INT64;
     std::vector < uint8 > UINT8;
     std::vector < uint16 > UINT16;
     std::vector < uint32 > UINT32;
     std::vector < uint64 > UINT64;
     std::vector < xint64 > XINT64;
     std::vector < insize > INSIZE;
     std::vector < string > STRING;

     int0 CLEAR(){INT1.clear(); INT8.clear(); INT16.clear(); INT32.clear(); INT64.clear(); UINT8.clear(); UINT16.clear(); UINT32.clear(); UINT64.clear(); XINT64.clear(); INSIZE.clear(); STRING.clear();}
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
    struct HEPTA_LF2_ENCHANTED_FONT_SHIFT
    {
     int1 c; int1 C; int32 x, y;
    };
    struct HEPTA_LF2_ENCHANTED_FONT
    {
     string Address;
     insize Pic_Index = rinsize(-1);
     int32  x = 0;
     int32  y = 0;
     int32  w = 0;
     int32  h = 0;
     int32  row = 0;
     int32  col = 0;
     int32  type = 0;
     int32  num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     int32  sizex = 0;
     int32  sizey = 0;
     int32  shiftx = 0;
     int32  shifty = 0;
     int32  caps = 0;
     int32  caps2 = 0;
     int32  stx = 0;
     int32  sty = 0;
     std::vector < HEPTA_LF2_ENCHANTED_FONT_SHIFT > Shift;
    }; 
    struct HEPTA_LF2_ENCHANTED_TEXT_FONT
    {
     insize index = rinsize(-1);
     insize color = 0;
     int32 w = 0, rotate = 0, zoomw = 0, zoomh = 0;
    };
    struct HEPTA_LF2_ENCHANTED_TEXT
    {
     int32 y = 0, h = 0;
     std::vector < HEPTA_LF2_ENCHANTED_TEXT_FONT > Font;
    };

    HEPTA_LF2_ENCHANTED_SETTING Setting[2];
    std::vector < HEPTA_LF2_ENCHANTED_TEXT > Text;
    std::vector < HEPTA_LF2_ENCHANTED_FONT > Font;
    std::vector < HEPTA_LF2_ENCHANTED_INFO > Info;
    std::vector < HEPTA_LF2_ENCHANTED_RUNTIMEDATA > Data;
    unique < HEPTA_LF2_ENCHANTED_ENGINE0 > Engine0 = std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE0 > ();
    unique < HEPTA_LF2_ENCHANTED_ENGINE1 > Engine1 = std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE1 > ();
    unique < HEPTA_LF2_ENCHANTED_ENGINE2 > Engine2 = std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE2 > ();
    unique < HEPTA_LF2_ENCHANTED_ENGINE3 > Engine3 = std::make_unique < HEPTA_LF2_ENCHANTED_ENGINE3 > ();

   // Functions
    int0   Setting_Load() perfect
    {
     string Temp01 = L_Load(2); if(Temp01.at(0) == 'F') return; Temp01 = L_Cut(Temp01);
     Setting[1] = Setting[0];

     statics insize Vrab01 = Temp01.size(); insize Vrab02 = Vrab01; insize Vrab03 = 0;
     while(Vrab02 != 0)
     {
      switch(Vrab03)
      {
       case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        if(Vrab02 < 5){Vrab02 = 0; break;}
        {
         insize Vrab04 = S_DecryptionUINT32(string(Temp01, Vrab01 - Vrab02, 5).c_str()); Vrab02 -= 5;
         if(Vrab02 < Vrab04){Vrab02 = 0; break;}
         statics string Temp02 = string(Temp01, Vrab01 - Vrab02, Vrab04); Vrab02 -= Vrab04;
         switch(Vrab03)
         {
          case 0: Setting[1].Address = Temp02; break;
          case 1: Setting[1].Address_Game = Temp02; break;
          case 2: Setting[1].Address_Interface = Temp02; break;
          case 3: Setting[1].Address_Recording = Temp02; break;
          case 4: Setting[1].User = Temp02; break;
          case 5: Setting[1].Email = Temp02; break;
          case 6: Setting[1].Note = Temp02; break;
          default: break;
         }
        }
       break;
       default: Vrab02 = 0; break;
      }
      Vrab03 += 1;
     }

     Setting[0] = Setting[1];
    }
    int0   Setting_Save() perfect
    {
     string Temp01 = "";
     for(insize Vrab01 = 0; Vrab01 < 10; ++Vrab01) switch(Vrab01)
     {
      case 0: Temp01 += S_EncryptionUINT32(Setting[0].Address.size()) + Setting[0].Address; break;
      case 1: Temp01 += S_EncryptionUINT32(Setting[0].Address_Game.size()) + Setting[0].Address_Game; break;
      case 2: Temp01 += S_EncryptionUINT32(Setting[0].Address_Interface.size()) + Setting[0].Address_Interface; break;
      case 3: Temp01 += S_EncryptionUINT32(Setting[0].Address_Recording.size()) + Setting[0].Address_Recording; break;
      case 4: Temp01 += S_EncryptionUINT32(Setting[0].User.size()) + Setting[0].User; break;
      case 5: Temp01 += S_EncryptionUINT32(Setting[0].Email.size()) + Setting[0].Email; break;
      case 6: Temp01 += S_EncryptionUINT32(Setting[0].Note.size()) + Setting[0].Note; break;
      default: break;
     }
     L_Save(2, Temp01);
    }
    int0   Sound_Effect(statics insize Vrab01)
    {
     P_Set_Sound(Vrab01, (rxint32(Enchanted->Setting[0].Volume) / 100.0f) * Vrab0012, Vrab0013);
    }
    int0   Post_Info(statics string Temp01, statics int1 Vrab01 = false, statics int1 Vrab02 = false) perfect
    {
     statics insize Vrab03 = Info.size(); Info.resize(Vrab03 + 1);

     // Shift all the current existing info/notification.
     {
      Print_Text(0, 0, 0, Temp01, 360, 1);
      for(insize Vrab04 = 0; Vrab04 < Vrab03; ++Vrab04)
      {
       statics insize Vrab05 = Info[Vrab04].Manager.size(); Info[Vrab04].Manager.resize(Vrab05 + 1);
       Info[Vrab04].Manager[Vrab05].Target = 34 + Vrab016[1];
      }
     }

     // Values
     if(Vrab03 == 0) Vrab006 = 0; Info[Vrab03].Slot = ++Vrab006;
     if(Vrab02){Info[Vrab03].Volume = true;} else {Info[Vrab03].String = Temp01;}
     Info[Vrab03].Question = Vrab01;
    }
    int0   Print_Text(statics int64 Vrab01, statics int64 Vrab02, uint8 Vrab03, statics string &Temp01, int64 Vrab04 = 0, statics uint8 Vrab05 = 0) perfect
    {
     statics string Temp02 = Temp01; if(Vrab04 <= 0) Vrab04 = 0x7FFFFFFFFFFFFFFF; Vrab016[0] = 0; Vrab016[1] = 0;
     statics insize Vrab06 = Temp02.size(); insize Vrab07 = 0; int64 Vrab08[3]{0, 0, 0}; remains xint64 Vrab09[2]{9, 15};
     insize Vrab10[4]{0xFFFFFF, 0, 10000, 0};
     struct Strc01 {int64 Vrab001, Vrab002; int8 Vrab003; int64 Vrab004, Vrab005;};
     std::vector < Strc01 > Vect01;

     if(Vrab05 != 2)
     {
      Text.clear(); Vrab016[0] = 0; Vrab016[1] = 0;
      while(Vrab07 < Vrab06)
      {
       // Command
       if(Temp02[Vrab07] == '[')
       {
        string Temp03 = ""; insize Vrab11 = Vrab07 + 1; int1 Vrab12 = false;
        while(Vrab11 < Vrab06)
        {
         if(Temp02[Vrab11] == '[') break;
         if(Temp02[Vrab11] == ']'){Vrab12 = true; break;}
         Temp03 += Temp02[Vrab11];
         Vrab11 += 1;
        } if(Vrab12)
        {
         // Size
         if(Temp03.size() >= 3)
         {
          if(Temp03[0] == 's')
          Vrab10[2] = rinsize(10000 + L_Numbering(string(Temp03, 1, Temp03.size() - 1)));
         }

         // Color
         if(Temp03.size() == 6) Vrab10[0] = rinsize(L_Convert(Temp03));
         
         if(Temp03.size() == 1)
         {
          // Caps
          if(Temp03[0] == 'c') Vrab10[1] = 1;
         }
 
         if(Temp03.size() == 2) if(Temp03[0] == '/')
         {
          // Caps End
          if(Temp03[1] == 'c') Vrab10[1] = 0;
         }

         Vrab07 += Temp03.size() + 2; continue;
        }
       }

       // Preload Font
       {
        insize Vrab13[3] = {rinsize(Temp02[Vrab07]), 0, 0}; {if(Vrab07 + 1 < Vrab06) Vrab13[1] = Temp02[Vrab07 + 1]; if(Vrab07 + 2 < Vrab06) Vrab13[2] = Temp02[Vrab07 + 2];}
        insize Vrab14 = Font.size();
        while(Vrab14 != 0)
        {
         Vrab14 -= 1; int1 Vrab15 = false;
         while(true)
         {
          if(Font[Vrab14].type != Vrab03) break;
          if(Font[Vrab14].num[0] > 0) if(Font[Vrab14].num[1] > Vrab13[0] || Font[Vrab14].num[7] < Vrab13[0]) break;
          if(Font[Vrab14].num[0] > 1) if(Font[Vrab14].num[2] > Vrab13[1] || Font[Vrab14].num[8] < Vrab13[1]) break;
          if(Font[Vrab14].num[0] > 2) if(Font[Vrab14].num[3] > Vrab13[2] || Font[Vrab14].num[9] < Vrab13[2]) break;
          Vrab15 = true; break;
         } if(Vrab15)
         {
          Vrab09[0] = rxint64(Font[Vrab14].sizex) * (rxint64(Vrab10[2]) / 10000.0); Vrab09[1] = rxint64(Font[Vrab14].sizey) * (rxint64(Vrab10[2]) / 10000.0);
          insize Vrab16 = rinsize(-1); 
          {
           Vrab16 = ((Vrab13[0] - Font[Vrab14].num[1]) * Font[Vrab14].num[4]);
           if(Font[Vrab14].num[0] > 1) Vrab16 += ((Vrab13[1] - Font[Vrab14].num[2]) * Font[Vrab14].num[5]);
           if(Font[Vrab14].num[0] > 2) Vrab16 += ((Vrab13[2] - Font[Vrab14].num[3]) * Font[Vrab14].num[6]);
           if(Vrab10[1] == 1){if(Font[Vrab14].Shift.size() > Vrab16 + 1){if(Font[Vrab14].Shift[Vrab16].c) Vrab16 += Font[Vrab14].caps; if(Font[Vrab14].Shift[Vrab16].C) Vrab16 += Font[Vrab14].caps2;}}
          }
          statics int64 Vrab17 = Font[Vrab14].w, Vrab18 = Font[Vrab14].h;
          int64 Vrab19 = Font[Vrab14].shiftx, Vrab20 = Font[Vrab14].shifty;
          if(Font[Vrab14].Shift.size() > Vrab16 + 1){Vrab19 += Font[Vrab14].Shift[Vrab16].x; Vrab20 += Font[Vrab14].Shift[Vrab16].y;}
          if(Vrab05 != 1)  P_Set_Display(3, Font[Vrab14].Pic_Index, Vrab01 + Vrab08[0] + Vrab19, Vrab02 + Vrab08[1] + Vrab20, 0ui8, 255ui8, Vrab17, Vrab18, (Vrab16 % Font[Vrab14].row) * (Vrab17 + 1), (Vrab16 / Font[Vrab14].row) * (Vrab18 + 1), Font[Vrab14].stx, Font[Vrab14].sty);
          Vrab016[0] += Vrab09[0]; Vrab016[1] = 16; Vrab08[0] += Vrab09[0];
         }
        } 
       }

       Vrab07 += 1;
      }
     }

     if(Vrab05 != 1)
     {
      statics insize Vrab11 = Text.size(); insize Vrab12 = 0;
      while(Vrab12 < Vrab11)
      {
       statics insize Vrab13 = Text[Vrab12].Font.size(); insize Vrab14 = 0;
       while(Vrab14 < Vrab13)
       {

        Vrab14 += 1;
       }
       Vrab12 += 1;
      }
     }

     /*
     insize Vrab11[4] = {-1, 0, 0, 0};

     // Look for font.
     {
      insize Vrab12 = Text.size(); insize Vrab13[3] = {rinsize(Temp02[Vrab07]), 0, 0}; {if(Vrab07 + 1 < Vrab06) Vrab13[1] = Temp02[Vrab07 + 1]; if(Vrab07 + 2 < Vrab06) Vrab13[2] = Temp02[Vrab07 + 2];}
      while(Vrab12 != 0)
      {
       Vrab12 -= 1; int1 Vrab14 = false;
       while(true)
       {
        if(Text[Vrab12].type != Vrab03) break;
        if(Text[Vrab12].num[0] > 0) if(Text[Vrab12].num[1] > Vrab13[0] || Text[Vrab12].num[7] < Vrab13[0]) break;
        if(Text[Vrab12].num[0] > 1) if(Text[Vrab12].num[2] > Vrab13[1] || Text[Vrab12].num[8] < Vrab13[1]) break;
        if(Text[Vrab12].num[0] > 2) if(Text[Vrab12].num[3] > Vrab13[2] || Text[Vrab12].num[9] < Vrab13[2]) break;
        Vrab14 = true; break;
       } if(Vrab14)
       {
        Vrab09[0] = Text[Vrab12].sizex; Vrab09[1] = Text[Vrab12].sizey;
        if(Vrab08[2] < Vrab09[1]) Vrab08[2] = Vrab09[1];
        if(Vrab08[0] == 0){Vrab08[0] = Vrab09[0];} else 
        {
         if(Vrab08[0] + Vrab09[0] <= Vrab04){Vrab08[0] += Vrab09[0];} else 
         {
         }
        }

        // Drawing
        if(Vrab05 != 1)
        {
         insize Vrab15 = rinsize(-1);
         {
          Vrab15 = (Vrab13[0] - Text[Vrab12].num[1]) * Text[Vrab12].num[4];
          Vrab15 += (Vrab13[0] - Text[Vrab12].num[2]) * Text[Vrab12].num[5];
          Vrab15 += (Vrab13[0] - Text[Vrab12].num[3]) * Text[Vrab12].num[6];
         }
        }


        if(Vrab08[0] != 0 && Vrab08[0] + Vrab09[0] > Vrab04)
        {
         if(Vrab05 == 2) if(Vect01[0] != ' ') {Print_Text(Vrab01 + Vrab08[0], Vrab02 + Vrab08[1], Vrab03, "-");
         Vrab016[0] = 0;} Vrab08[0] = 0; Vrab08[1] += Vrab09[1]; Vrab016[0] = Vrab04; Vrab016[1] = Vrab08[1];
        }
        if(Vrab05 != 1)
        {
         insize Vrab13 = rinsize(-1); {Vrab13 = ((Vect01[0] - Text[Vrab11].num[1]) * Text[Vrab11].num[4]); if(Vrab10 > 1) Vrab13 += ((Vect01[1] - Text[Vrab11].num[2]) * Text[Vrab11].num[5]); if(Vrab10 > 2) Vrab13 += ((Vect01[2] - Text[Vrab11].num[3]) * Text[Vrab11].num[6]);}
         statics int64 Vrab14 = Text[Vrab11].w, Vrab15 = Text[Vrab11].h;
         int64 Vrab16 = Text[Vrab11].shiftx, Vrab17 = Text[Vrab11].shifty; if(Text[Vrab11].Shift.size() > Vrab13 + 1){Vrab16 += Text[Vrab11].Shift[Vrab13].x; Vrab17 += Text[Vrab11].Shift[Vrab13].y;}
         P_Set_Display(3, Text[Vrab11].Pic_Index, Vrab01 + Vrab08[0] + Vrab16, Vrab02 + Vrab08[1] + Vrab17, 0ui8, 255ui8, Vrab14, Vrab15, (Vrab13 % Text[Vrab11].row) * (Vrab14 + 1), (Vrab13 / Text[Vrab11].row) * (Vrab15 + 1), Text[Vrab11].stx, Text[Vrab11].sty);
        }
        Vrab08[0] += Vrab09[0]; if(Vrab016[0] < Vrab08[0]) Vrab016[0] = Vrab08[0];
        break;
       }
      }
     }*/
     
     /*
     while(Vrab07 < Vrab06)
     {
      insize Vrab10 = 1;
      {
       statics int8 Vrab11 = Temp02[Vrab07];
       if(Vrab11 <= -44 && Vrab11 >= -48) Vrab10 = 2;
       if(Vrab07 + Vrab10 > Vrab06) break;
       if(Vrab11 == '\n'){Vrab08[0] = 0; Vrab08[1] += Vrab09[1]; Vrab07 += Vrab10; Vrab016[1] = Vrab08[1]; continue;}
      }
      std::vector < int8 > Vect01(Vrab10); Vect01[0] = Temp02[Vrab07]; if(Vrab10 > 1) Vect01[1] = Temp02[Vrab07 + 1]; if(Vrab10 > 2) Vect01[2] = Temp02[Vrab07 + 2];
      insize Vrab11 = Text.size();
      while(Vrab11 != 0)
      {
       Vrab11 -= 1; int1 Vrab12 = false;
       while(true)
       {
        if(rinsize(Text[Vrab11].num[0]) != Vrab10) break;
        if(Text[Vrab11].type != Vrab03) break;
        if(Text[Vrab11].num[1] > Vect01[0] || Text[Vrab11].num[7] < Vect01[0]) break;
        if(Vrab10 > 1) if(Text[Vrab11].num[2] > Vect01[1] || Text[Vrab11].num[8] < Vect01[1]) break;
        if(Vrab10 > 2) if(Text[Vrab11].num[3] > Vect01[2] || Text[Vrab11].num[9] < Vect01[2]) break;
        Vrab12 = true; break;
       }
       if(Vrab12)
       {
        Vrab09[0] = Text[Vrab11].sizex; Vrab09[1] = Text[Vrab11].sizey;
        if(Vrab08[0] != 0 && Vrab08[0] + Vrab09[0] > Vrab04)
        {
         if(Vrab05 == 2) if(Vect01[0] != ' ') {Print_Text(Vrab01 + Vrab08[0], Vrab02 + Vrab08[1], Vrab03, "-");
         Vrab016[0] = 0;} Vrab08[0] = 0; Vrab08[1] += Vrab09[1]; Vrab016[0] = Vrab04; Vrab016[1] = Vrab08[1];
        }
        if(Vrab05 != 1)
        {
         insize Vrab13 = rinsize(-1); {Vrab13 = ((Vect01[0] - Text[Vrab11].num[1]) * Text[Vrab11].num[4]); if(Vrab10 > 1) Vrab13 += ((Vect01[1] - Text[Vrab11].num[2]) * Text[Vrab11].num[5]); if(Vrab10 > 2) Vrab13 += ((Vect01[2] - Text[Vrab11].num[3]) * Text[Vrab11].num[6]);}
         statics int64 Vrab14 = Text[Vrab11].w, Vrab15 = Text[Vrab11].h;
         int64 Vrab16 = Text[Vrab11].shiftx, Vrab17 = Text[Vrab11].shifty; if(Text[Vrab11].Shift.size() > Vrab13 + 1){Vrab16 += Text[Vrab11].Shift[Vrab13].x; Vrab17 += Text[Vrab11].Shift[Vrab13].y;}
         P_Set_Display(3, Text[Vrab11].Pic_Index, Vrab01 + Vrab08[0] + Vrab16, Vrab02 + Vrab08[1] + Vrab17, 0ui8, 255ui8, Vrab14, Vrab15, (Vrab13 % Text[Vrab11].row) * (Vrab14 + 1), (Vrab13 / Text[Vrab11].row) * (Vrab15 + 1), Text[Vrab11].stx, Text[Vrab11].sty);
        }
        Vrab08[0] += Vrab09[0]; if(Vrab016[0] < Vrab08[0]) Vrab016[0] = Vrab08[0];
        break;
       }
      }

      Vrab07 += Vrab10;
     }
     */
    }
    int0   Print_Bar(int64 Vrab01, int64 Vrab02, uint64 Vrab03, uint64 Vrab04) perfect
    {
     if(Vrab03 % 2 == 1) Vrab03 += 1; if(Vrab04 % 2 == 1) Vrab04 += 1;
     P_Set_Display(2, Vect004[6], Vrab01 - 12, Vrab02 - 12);
     P_Set_Display(2, Vect004[7], Vrab01 + Vrab03 + 1, Vrab02 - 12);
     P_Set_Display(2, Vect004[8], Vrab01 - 12, Vrab02 + Vrab04 + 1);
     P_Set_Display(2, Vect004[9], Vrab01 + Vrab03 + 1, Vrab02 + Vrab04 + 1);
     P_Set_Display(2, Vect004[10], Vrab01, Vrab02 - 12, 0ui8, 255ui8, Vrab03);
     P_Set_Display(2, Vect004[10], Vrab01, Vrab02 + Vrab04 + 10, 0ui8, 255ui8, Vrab03);
     P_Set_Display(2, Vect004[11], Vrab01 - 12, Vrab02, 0ui8, 255ui8, 0, Vrab04);
     P_Set_Display(2, Vect004[11], Vrab01 + Vrab03 + 10, Vrab02, 0ui8, 255ui8, 0, Vrab04);

     {
      uint64 Vrab05 = Vrab04 + 1; uint64 Vrab06 = ruint64(-1);
      while(Vrab05 > 0)
      {
       uint64 Vrab07 = Vrab05 / 198; if(Vrab07 > 0){Vrab07 = 198;} else {Vrab07 = Vrab05 % 198;} Vrab05 -= Vrab07; Vrab06 += 1;
       P_Set_Display(3, Vect004[12], Vrab01 - 9, Vrab02 + (Vrab06 * 198), 0ui8, 255ui8, 9, Vrab07, 0, 1);
       P_Set_Display(3, Vect004[12], Vrab01 + Vrab03 + 1, Vrab02 + (Vrab06 * 198), 0ui8, 255ui8, 9, Vrab07, 0, 1);
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
        P_Set_Display(3, Vect004[12], Vrab01 + (Vrab09 * 198), Vrab02 - 9 + (Vrab06 * 198), 0ui8, 255ui8, Vrab10, Vrab07, 1, 0);
       }
      }
     }
    }
    int0   Typing(string &Temp01) perfect
    {
     statics uint16 Vrab01 = ruint16(L_Rounding(480.0 / rxint64(Vrab0003)) - 1) - 1; remains int1 Vrab02 = true;
     if((Input->CONS_LSHIFT == 1 && Input->CONS_RSHIFT > 0) || (Input->CONS_LSHIFT > 0 && Input->CONS_RSHIFT == 1)) Vrab02 = !Vrab02;
     if(Input->RESH_CAPS || Input->CONS_LSHIFT > 0 || Input->CONS_RSHIFT > 0)
     {
      {statics uint16 Vrab03 = Input->MAIN_A; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('A');} else {Temp01 += "\xd0\xa4";}}
      {statics uint16 Vrab03 = Input->MAIN_B; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('B');} else {Temp01 += "\xd0\x98";}}
      {statics uint16 Vrab03 = Input->MAIN_C; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('C');} else {Temp01 += "\xd0\xa1";}}
      {statics uint16 Vrab03 = Input->MAIN_D; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('D');} else {Temp01 += "\xd0\x92";}}
      {statics uint16 Vrab03 = Input->MAIN_E; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('E');} else {Temp01 += "\xd0\xa3";}}
      {statics uint16 Vrab03 = Input->MAIN_F; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('F');} else {Temp01 += "\xd0\x90";}}
      {statics uint16 Vrab03 = Input->MAIN_G; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('G');} else {Temp01 += "\xd0\x9f";}}
      {statics uint16 Vrab03 = Input->MAIN_H; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('H');} else {Temp01 += "\xd0\xa0";}}
      {statics uint16 Vrab03 = Input->MAIN_I; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('I');} else {Temp01 += "\xd0\xa8";}}
      {statics uint16 Vrab03 = Input->MAIN_J; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('J');} else {Temp01 += "\xd0\x9e";}}
      {statics uint16 Vrab03 = Input->MAIN_K; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('K');} else {Temp01 += "\xd0\x9b";}}
      {statics uint16 Vrab03 = Input->MAIN_L; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('L');} else {Temp01 += "\xd0\x94";}}
      {statics uint16 Vrab03 = Input->MAIN_M; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('M');} else {Temp01 += "\xd0\xac";}}
      {statics uint16 Vrab03 = Input->MAIN_N; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('N');} else {Temp01 += "\xd0\xa2";}}
      {statics uint16 Vrab03 = Input->MAIN_O; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('O');} else {Temp01 += "\xd0\xa9";}}
      {statics uint16 Vrab03 = Input->MAIN_P; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('P');} else {Temp01 += "\xd0\x97";}}
      {statics uint16 Vrab03 = Input->MAIN_Q; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('Q');} else {Temp01 += "\xd0\x99";}}
      {statics uint16 Vrab03 = Input->MAIN_R; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('R');} else {Temp01 += "\xd0\x9a";}}
      {statics uint16 Vrab03 = Input->MAIN_S; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('S');} else {Temp01 += "\xd0\xab";}}
      {statics uint16 Vrab03 = Input->MAIN_T; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('T');} else {Temp01 += "\xd0\x95";}}
      {statics uint16 Vrab03 = Input->MAIN_U; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('U');} else {Temp01 += "\xd0\x93";}}
      {statics uint16 Vrab03 = Input->MAIN_V; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('V');} else {Temp01 += "\xd0\x9c";}}
      {statics uint16 Vrab03 = Input->MAIN_W; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('W');} else {Temp01 += "\xd0\xa6";}}
      {statics uint16 Vrab03 = Input->MAIN_X; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('X');} else {Temp01 += "\xd0\xa7";}}
      {statics uint16 Vrab03 = Input->MAIN_Y; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('Y');} else {Temp01 += "\xd0\x9d";}}
      {statics uint16 Vrab03 = Input->MAIN_Z; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('Z');} else {Temp01 += "\xd0\xaf";}}
     } else
     {
      {statics uint16 Vrab03 = Input->MAIN_A; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('a');} else {Temp01 += "\xd1\x84";}}
      {statics uint16 Vrab03 = Input->MAIN_B; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('b');} else {Temp01 += "\xd0\xb8";}}
      {statics uint16 Vrab03 = Input->MAIN_C; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('c');} else {Temp01 += "\xd1\x81";}}
      {statics uint16 Vrab03 = Input->MAIN_D; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('d');} else {Temp01 += "\xd0\xb2";}}
      {statics uint16 Vrab03 = Input->MAIN_E; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('e');} else {Temp01 += "\xd1\x83";}}
      {statics uint16 Vrab03 = Input->MAIN_F; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('f');} else {Temp01 += "\xd0\xb0";}}
      {statics uint16 Vrab03 = Input->MAIN_G; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('g');} else {Temp01 += "\xd0\xbf";}}
      {statics uint16 Vrab03 = Input->MAIN_H; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('h');} else {Temp01 += "\xd1\x80";}}
      {statics uint16 Vrab03 = Input->MAIN_I; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('i');} else {Temp01 += "\xd1\x88";}}
      {statics uint16 Vrab03 = Input->MAIN_J; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('j');} else {Temp01 += "\xd0\xbe";}}
      {statics uint16 Vrab03 = Input->MAIN_K; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('k');} else {Temp01 += "\xd0\xbb";}}
      {statics uint16 Vrab03 = Input->MAIN_L; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('l');} else {Temp01 += "\xd0\xb4";}}
      {statics uint16 Vrab03 = Input->MAIN_M; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('m');} else {Temp01 += "\xd1\x8c";}}
      {statics uint16 Vrab03 = Input->MAIN_N; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('n');} else {Temp01 += "\xd1\x82";}}
      {statics uint16 Vrab03 = Input->MAIN_O; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('o');} else {Temp01 += "\xd1\x89";}}
      {statics uint16 Vrab03 = Input->MAIN_P; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('p');} else {Temp01 += "\xd0\xb7";}}
      {statics uint16 Vrab03 = Input->MAIN_Q; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('q');} else {Temp01 += "\xd0\xb9";}}
      {statics uint16 Vrab03 = Input->MAIN_R; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('r');} else {Temp01 += "\xd0\xba";}}
      {statics uint16 Vrab03 = Input->MAIN_S; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('s');} else {Temp01 += "\xd1\x8b";}}
      {statics uint16 Vrab03 = Input->MAIN_T; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('t');} else {Temp01 += "\xd0\xb5";}}
      {statics uint16 Vrab03 = Input->MAIN_U; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('u');} else {Temp01 += "\xd0\xb3";}}
      {statics uint16 Vrab03 = Input->MAIN_V; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('v');} else {Temp01 += "\xd0\xbc";}}
      {statics uint16 Vrab03 = Input->MAIN_W; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('w');} else {Temp01 += "\xd1\x86";}}
      {statics uint16 Vrab03 = Input->MAIN_X; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('x');} else {Temp01 += "\xd1\x87";}}
      {statics uint16 Vrab03 = Input->MAIN_Y; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('y');} else {Temp01 += "\xd0\xbd";}}
      {statics uint16 Vrab03 = Input->MAIN_Z; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('z');} else {Temp01 += "\xd1\x8f";}}
     }
     {statics uint16 Vrab03 = Input->NUMS_0; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('0');}
     {statics uint16 Vrab03 = Input->NUMS_1; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('1');}
     {statics uint16 Vrab03 = Input->NUMS_2; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('2');}
     {statics uint16 Vrab03 = Input->NUMS_3; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('3');}
     {statics uint16 Vrab03 = Input->NUMS_4; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('4');}
     {statics uint16 Vrab03 = Input->NUMS_5; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('5');}
     {statics uint16 Vrab03 = Input->NUMS_6; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('6');}
     {statics uint16 Vrab03 = Input->NUMS_7; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('7');}
     {statics uint16 Vrab03 = Input->NUMS_8; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('8');}
     {statics uint16 Vrab03 = Input->NUMS_9; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('9');}
     if(Input->CONS_LSHIFT > 0 || Input->CONS_RSHIFT > 0)
     {
      {statics uint16 Vrab03 = Input->MAIN_0; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back(')');} else {Temp01 += ")";}}
      {statics uint16 Vrab03 = Input->MAIN_1; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('!');} else {Temp01 += "!";}}
      {statics uint16 Vrab03 = Input->MAIN_2; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('@');} else {Temp01 += "\"";}}
      {statics uint16 Vrab03 = Input->MAIN_3; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('#');} else {Temp01 += "\xe2\x84\x96";}}
      {statics uint16 Vrab03 = Input->MAIN_4; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('$');} else {Temp01 += ";";}}
      {statics uint16 Vrab03 = Input->MAIN_5; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('%');} else {Temp01 += "%";}}
      {statics uint16 Vrab03 = Input->MAIN_6; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('^');} else {Temp01 += ":";}}
      {statics uint16 Vrab03 = Input->MAIN_7; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('&');} else {Temp01 += "?";}}
      {statics uint16 Vrab03 = Input->MAIN_8; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('*');} else {Temp01 += "*";}}
      {statics uint16 Vrab03 = Input->MAIN_9; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('(');} else {Temp01 += "(";}}
      {statics uint16 Vrab03 = Input->MAIN_TILDE;        if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('~');} else {Temp01 += "\xd0\x81";}}
      {statics uint16 Vrab03 = Input->MAIN_MINUS;        if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('_');} else {Temp01 += "_";}}
      {statics uint16 Vrab03 = Input->MAIN_PLUS;         if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('+');} else {Temp01 += "+";}}
      {statics uint16 Vrab03 = Input->MAIN_OPENBRACKED;  if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('{');} else {Temp01 += "\xd0\xa5";}}
      {statics uint16 Vrab03 = Input->MAIN_CLOSEBRACKED; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('}');} else {Temp01 += "\xd0\xaa";}}
      {statics uint16 Vrab03 = Input->MAIN_PIPE;         if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('|');} else {Temp01 += "/";}}
      {statics uint16 Vrab03 = Input->MAIN_SEMICOLON;    if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back(':');} else {Temp01 += "\xd0\x96";}}
      {statics uint16 Vrab03 = Input->MAIN_QUOTES;       if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('\"');} else {Temp01 += "\xd0\xad";}}
      {statics uint16 Vrab03 = Input->MAIN_QUESTION;     if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('?');} else {Temp01 += ",";}}
      {statics uint16 Vrab03 = Input->MAIN_PERIOD;       if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('>');} else {Temp01 += "\xd0\xae";}}
      {statics uint16 Vrab03 = Input->MAIN_COMMA;        if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('<');} else {Temp01 += "\xd0\x91";}}
     } else
     {
      {statics uint16 Vrab03 = Input->MAIN_0; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('0');}
      {statics uint16 Vrab03 = Input->MAIN_1; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('1');}
      {statics uint16 Vrab03 = Input->MAIN_2; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('2');}
      {statics uint16 Vrab03 = Input->MAIN_3; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('3');}
      {statics uint16 Vrab03 = Input->MAIN_4; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('4');}
      {statics uint16 Vrab03 = Input->MAIN_5; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('5');}
      {statics uint16 Vrab03 = Input->MAIN_6; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('6');}
      {statics uint16 Vrab03 = Input->MAIN_7; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('7');}
      {statics uint16 Vrab03 = Input->MAIN_8; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('8');}
      {statics uint16 Vrab03 = Input->MAIN_9; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back('9');}
      {statics uint16 Vrab03 = Input->MAIN_TILDE;        if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('`');} else {Temp01 += "\xd1\x91";}}
      {statics uint16 Vrab03 = Input->MAIN_MINUS;        if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('-');} else {Temp01 += "-";}}
      {statics uint16 Vrab03 = Input->MAIN_PLUS;         if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('=');} else {Temp01 += "=";}}
      {statics uint16 Vrab03 = Input->MAIN_OPENBRACKED;  if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('[');} else {Temp01 += "\xd1\x85";}}
      {statics uint16 Vrab03 = Input->MAIN_CLOSEBRACKED; if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back(']');} else {Temp01 += "\xd1\x8a";}}
      {statics uint16 Vrab03 = Input->MAIN_PIPE;         if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('\\');} else {Temp01 += "\\";}}
      {statics uint16 Vrab03 = Input->MAIN_SEMICOLON;    if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back(';');} else {Temp01 += "\xd0\xb6";}}
      {statics uint16 Vrab03 = Input->MAIN_QUOTES;       if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('\'');} else {Temp01 += "\xd1\x8d";}}
      {statics uint16 Vrab03 = Input->MAIN_QUESTION;     if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('/');} else {Temp01 += ".";}}
      {statics uint16 Vrab03 = Input->MAIN_PERIOD;       if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back('.');} else {Temp01 += "\xd1\x8e";}}
      {statics uint16 Vrab03 = Input->MAIN_COMMA;        if(Vrab03 == 1 || Vrab03 == Vrab01) if(Vrab02){Temp01.push_back(',');} else {Temp01 += "\xd0\xb1";}}
     }
     {statics uint16 Vrab03 = Input->MAIN_SPACE; if(Vrab03 == 1 || Vrab03 == Vrab01) Temp01.push_back(' ');}
     {statics uint16 Vrab03 = Input->CONS_BACK;  if(Vrab03 == 1 || Vrab03 == Vrab01){statics insize Vrab04 = Temp01.size(); if(Vrab04 - 2 < Vrab04) if(Temp01[Vrab04 - 1] <= -65 && Temp01[Vrab04 - 1] >= -128) if(Temp01[Vrab04 - 2] <= -44 && Temp01[Vrab04 - 2] >= -48) Temp01.pop_back(); if(Temp01.size() > 0) Temp01.pop_back();}}
    }
    string Input_Name(uint8 Vrab01) perfect
    {
     switch (Vrab01)
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
  };
  struct HEPTA_LF2_FOREVERED
  {
   // Variables
    int1   Vrab001 = true;          // Initialization.
    
   // Structures
    struct HEPTA_LF2_FOREVERED_SETTING
    {
     uint32 Width  = 800;
     uint32 Height = 450;
     int1   Fullscreen = false;
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
     string Address = "Database\\MiniGame_Forevered\\";
     string Address_Game = "GameData_Default\\";
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
    };

    HEPTA_LF2_FOREVERED_SETTING Setting[2];

   // Functions
    int0   Setting_Load() perfect
    {
     string Temp01 = L_Load(3); if(Temp01.at(0) == 'F') return; Temp01 = L_Cut(Temp01);
     Setting[1] = Setting[0];

     statics insize Vrab01 = Temp01.size(); insize Vrab02 = Vrab01; insize Vrab03 = 0;
     while(Vrab02 != 0)
     {
      switch(Vrab03)
      {
       case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        if(Vrab02 < 5){Vrab02 = 0; break;}
        {
         insize Vrab04 = S_DecryptionUINT32(string(Temp01, Vrab01 - Vrab02, 5).c_str()); Vrab02 -= 5;
         if(Vrab02 < Vrab04){Vrab02 = 0; break;}
         statics string Temp02 = string(Temp01, Vrab01 - Vrab02, Vrab04); Vrab02 -= Vrab04;
         switch(Vrab03)
         {
          case 0: Setting[1].Address = Temp02; break;
          case 1: Setting[1].Address_Game = Temp02; break;
          case 2: Setting[1].Address_Interface = Temp02; break;
          case 3: Setting[1].Address_Recording = Temp02; break;
          case 4: Setting[1].User = Temp02; break;
          case 5: Setting[1].Email = Temp02; break;
          case 6: Setting[1].Note = Temp02; break;
          default: break;
         }
        }
       break;
       default: Vrab02 = 0; break;
      }
      Vrab03 += 1;
     }

     Setting[0] = Setting[1];
    }
    int0   Setting_Save() perfect
    {
     string Temp01 = "";
     for(insize Vrab01 = 0; Vrab01 < 10; ++Vrab01) switch(Vrab01)
     {
      case 0: Temp01 += S_EncryptionUINT32(Setting[0].Address.size()) + Setting[0].Address; break;
      case 1: Temp01 += S_EncryptionUINT32(Setting[0].Address_Game.size()) + Setting[0].Address_Game; break;
      case 2: Temp01 += S_EncryptionUINT32(Setting[0].Address_Interface.size()) + Setting[0].Address_Interface; break;
      case 3: Temp01 += S_EncryptionUINT32(Setting[0].Address_Recording.size()) + Setting[0].Address_Recording; break;
      case 4: Temp01 += S_EncryptionUINT32(Setting[0].User.size()) + Setting[0].User; break;
      case 5: Temp01 += S_EncryptionUINT32(Setting[0].Email.size()) + Setting[0].Email; break;
      case 6: Temp01 += S_EncryptionUINT32(Setting[0].Note.size()) + Setting[0].Note; break;
      default: break;
     }
     L_Save(3, Temp01);
    }
  };

 // Encryption & Decryption Functions
  int0   S_Control()                                 perfect {if(Temp0002.size() <= 94) Temp0002.resize(95);}
  int8   S_Decryption94(statics int8 Vrab01)         perfect {if(Vrab01 == Temp0002[0]) return 0; if(Vrab01 == Temp0002[1]) return 1; if(Vrab01 == Temp0002[2]) return 2; if(Vrab01 == Temp0002[3]) return 3; if(Vrab01 == Temp0002[4]) return 4; if(Vrab01 == Temp0002[5]) return 5; if(Vrab01 == Temp0002[6]) return 6; if(Vrab01 == Temp0002[7]) return 7; if(Vrab01 == Temp0002[8]) return 8; if(Vrab01 == Temp0002[9]) return 9; if(Vrab01 == Temp0002[10]) return 10; if(Vrab01 == Temp0002[11]) return 11; if(Vrab01 == Temp0002[12]) return 12; if(Vrab01 == Temp0002[13]) return 13; if(Vrab01 == Temp0002[14]) return 14; if(Vrab01 == Temp0002[15]) return 15; if(Vrab01 == Temp0002[16]) return 16; if(Vrab01 == Temp0002[17]) return 17; if(Vrab01 == Temp0002[18]) return 18; if(Vrab01 == Temp0002[19]) return 19; if(Vrab01 == Temp0002[20]) return 20; if(Vrab01 == Temp0002[21]) return 21; if(Vrab01 == Temp0002[22]) return 22; if(Vrab01 == Temp0002[23]) return 23; if(Vrab01 == Temp0002[24]) return 24; if(Vrab01 == Temp0002[25]) return 25; if(Vrab01 == Temp0002[26]) return 26; if(Vrab01 == Temp0002[27]) return 27; if(Vrab01 == Temp0002[28]) return 28; if(Vrab01 == Temp0002[29]) return 29; if(Vrab01 == Temp0002[30]) return 30; if(Vrab01 == Temp0002[31]) return 31; if(Vrab01 == Temp0002[32]) return 32; if(Vrab01 == Temp0002[33]) return 33; if(Vrab01 == Temp0002[34]) return 34; if(Vrab01 == Temp0002[35]) return 35; if(Vrab01 == Temp0002[36]) return 36; if(Vrab01 == Temp0002[37]) return 37; if(Vrab01 == Temp0002[38]) return 38; if(Vrab01 == Temp0002[39]) return 39; if(Vrab01 == Temp0002[40]) return 40; if(Vrab01 == Temp0002[41]) return 41; if(Vrab01 == Temp0002[42]) return 42; if(Vrab01 == Temp0002[43]) return 43; if(Vrab01 == Temp0002[44]) return 44; if(Vrab01 == Temp0002[45]) return 45; if(Vrab01 == Temp0002[46]) return 46; if(Vrab01 == Temp0002[47]) return 47; if(Vrab01 == Temp0002[48]) return 48; if(Vrab01 == Temp0002[49]) return 49; if(Vrab01 == Temp0002[50]) return 50; if(Vrab01 == Temp0002[51]) return 51; if(Vrab01 == Temp0002[52]) return 52; if(Vrab01 == Temp0002[53]) return 53; if(Vrab01 == Temp0002[54]) return 54; if(Vrab01 == Temp0002[55]) return 55; if(Vrab01 == Temp0002[56]) return 56; if(Vrab01 == Temp0002[57]) return 57; if(Vrab01 == Temp0002[58]) return 58; if(Vrab01 == Temp0002[59]) return 59; if(Vrab01 == Temp0002[60]) return 60; if(Vrab01 == Temp0002[61]) return 61; if(Vrab01 == Temp0002[62]) return 62; if(Vrab01 == Temp0002[63]) return 63; if(Vrab01 == Temp0002[64]) return 64; if(Vrab01 == Temp0002[65]) return 65; if(Vrab01 == Temp0002[66]) return 66; if(Vrab01 == Temp0002[67]) return 67; if(Vrab01 == Temp0002[68]) return 68; if(Vrab01 == Temp0002[69]) return 69; if(Vrab01 == Temp0002[70]) return 70; if(Vrab01 == Temp0002[71]) return 71; if(Vrab01 == Temp0002[72]) return 72; if(Vrab01 == Temp0002[73]) return 73; if(Vrab01 == Temp0002[74]) return 74; if(Vrab01 == Temp0002[75]) return 75; if(Vrab01 == Temp0002[76]) return 76; if(Vrab01 == Temp0002[77]) return 77; if(Vrab01 == Temp0002[78]) return 78; if(Vrab01 == Temp0002[79]) return 79; if(Vrab01 == Temp0002[80]) return 80; if(Vrab01 == Temp0002[81]) return 81; if(Vrab01 == Temp0002[82]) return 82; if(Vrab01 == Temp0002[83]) return 83; if(Vrab01 == Temp0002[84]) return 84; if(Vrab01 == Temp0002[85]) return 85; if(Vrab01 == Temp0002[86]) return 86; if(Vrab01 == Temp0002[87]) return 87; if(Vrab01 == Temp0002[88]) return 88; if(Vrab01 == Temp0002[89]) return 89; if(Vrab01 == Temp0002[90]) return 90; if(Vrab01 == Temp0002[91]) return 91; if(Vrab01 == Temp0002[92]) return 92; if(Vrab01 == Temp0002[93]) return 93; return 0;}
  int8   S_DecryptionINT8(statics int8 Vrab01[2])    perfect {S_Control(); return (int8)(ruint8(S_Decryption94(Vrab01[1])) + ruint8(S_Decryption94(Vrab01[0])) * 94);}
  int16  S_DecryptionINT16(statics int8 Vrab01[3])   perfect {S_Control(); return (int16)(ruint16(S_Decryption94(Vrab01[2])) + ruint16(S_Decryption94(Vrab01[1])) * 94 + ruint16(S_Decryption94(Vrab01[0])) * 8836);}
  int32  S_DecryptionINT32(statics int8 Vrab01[5])   perfect {S_Control(); return (int32)(ruint32(S_Decryption94(Vrab01[4])) + ruint32(S_Decryption94(Vrab01[3])) * 94 + ruint32(S_Decryption94(Vrab01[2])) * 8836 + ruint32(S_Decryption94(Vrab01[1])) * 830584 + ruint32(S_Decryption94(Vrab01[0])) * 78074896);}
  int64  S_DecryptionINT64(statics int8 Vrab01[10])  perfect {S_Control(); return (int64)(ruint64(S_Decryption94(Vrab01[9])) + ruint64(S_Decryption94(Vrab01[8])) * 94 + ruint64(S_Decryption94(Vrab01[7])) * 8836 + ruint64(S_Decryption94(Vrab01[6])) * 830584 + ruint64(S_Decryption94(Vrab01[5])) * 78074896 + ruint64(S_Decryption94(Vrab01[4])) * 7339040224 + ruint64(S_Decryption94(Vrab01[3])) * 689869781056 + ruint64(S_Decryption94(Vrab01[2])) * 64847759419264 + ruint64(S_Decryption94(Vrab01[1])) * 6095689385410816 + ruint64(S_Decryption94(Vrab01[0])) * 572994802228616704);}
  uint32 S_DecryptionUINT4(statics int8 Vrab01[1])   perfect {S_Control(); return S_Decryption94(Vrab01[0]);}
  uint8  S_DecryptionUINT8(statics int8 Vrab01[2])   perfect {S_Control(); return S_Decryption94(Vrab01[1]) + (S_Decryption94(Vrab01[0]) * 94);}
  uint32 S_DecryptionUINT10(statics int8 Vrab01[2])  perfect {S_Control(); return S_Decryption94(Vrab01[1]) + (S_Decryption94(Vrab01[0]) * 94);}
  uint16 S_DecryptionUINT16(statics int8 Vrab01[3])  perfect {S_Control(); return ruint16(S_Decryption94(Vrab01[2])) + ruint16(S_Decryption94(Vrab01[1])) * 94 + ruint16(S_Decryption94(Vrab01[0])) * 8836;}
  uint32 S_DecryptionUINT18(statics int8 Vrab01[3])  perfect {S_Control(); return ruint16(S_Decryption94(Vrab01[2])) + ruint16(S_Decryption94(Vrab01[1])) * 94 + ruint16(S_Decryption94(Vrab01[0])) * 8836;}
  uint32 S_DecryptionUINT24(statics int8 Vrab01[4])  perfect {S_Control(); return ruint32(S_Decryption94(Vrab01[3])) + ruint32(S_Decryption94(Vrab01[2])) * 94 + ruint32(S_Decryption94(Vrab01[1])) * 8836 + ruint32(S_Decryption94(Vrab01[0])) * 830584;}
  uint32 S_DecryptionUINT32(statics int8 Vrab01[5])  perfect {S_Control(); return ruint32(S_Decryption94(Vrab01[4])) + ruint32(S_Decryption94(Vrab01[3])) * 94 + ruint32(S_Decryption94(Vrab01[2])) * 8836 + ruint32(S_Decryption94(Vrab01[1])) * 830584 + ruint32(S_Decryption94(Vrab01[0])) * 78074896;}
  uint64 S_DecryptionUINT64(statics int8 Vrab01[10]) perfect {S_Control(); return ruint64(S_Decryption94(Vrab01[9])) + ruint64(S_Decryption94(Vrab01[8])) * 94 + ruint64(S_Decryption94(Vrab01[7])) * 8836 + ruint64(S_Decryption94(Vrab01[6])) * 830584 + ruint64(S_Decryption94(Vrab01[5])) * 78074896 + ruint64(S_Decryption94(Vrab01[4])) * 7339040224 + ruint64(S_Decryption94(Vrab01[3])) * 689869781056 + ruint64(S_Decryption94(Vrab01[2])) * 64847759419264 + ruint64(S_Decryption94(Vrab01[1])) * 6095689385410816 + ruint64(S_Decryption94(Vrab01[0])) * 572994802228616704;}
  xint64 S_DecryptionXINT64(statics int8 Vrab01[11]) perfect {S_Control(); return rxint64(S_Decryption94(Vrab01[0])) * 8836 + rxint64(S_Decryption94(Vrab01[1])) * 94 + rxint64(S_Decryption94(Vrab01[2])) - 400000 + rxint64(S_Decryption94(Vrab01[3])) * 0.064847759419264 + rxint64(S_Decryption94(Vrab01[4])) * 0.000689869781056 + rxint64(S_Decryption94(Vrab01[5])) * 0.000007339040224 + rxint64(S_Decryption94(Vrab01[6])) * 0.000000078074896 +  rxint64(S_Decryption94(Vrab01[7])) * 0.000000000830584 + rxint64(S_Decryption94(Vrab01[8])) * 0.000000000008836 + rxint64(S_Decryption94(Vrab01[9])) * 0.000000000000094 + rxint64(S_Decryption94(Vrab01[10])) * 0.000000000000001;}
  string S_DecryptionSTRING(string Temp01)           perfect {int8 Vrab01 = 0; statics uint32 Vrab02 = Temp01.size(); uint32 Vrab03 = 0;  while(Vrab03 != Vrab02){Vrab01 = Temp01.at(Vrab03); if(Vrab01 >= '!' && Vrab01 <= '~') Temp01.at(Vrab03) = ((S_Decryption94(Vrab01) + 94 - (Vrab03 % 94)) % 94) + 33; Vrab03 += 1;} return Temp01;}
  string S_Encryption94(statics uint64 Vrab01)       perfect {S_Control(); return {Temp0002[(Vrab01 % 94)]};}
  string S_EncryptionUINT4(statics uint32 Vrab01)    perfect {S_Control(); return S_Encryption94(Vrab01);}
  string S_EncryptionUINT8(statics uint8 Vrab01)     perfect {S_Control(); return S_Encryption94(Vrab01 / 94) + S_Encryption94(Vrab01);}
  string S_EncryptionUINT10(statics uint32 Vrab01)   perfect {S_Control(); return S_Encryption94(Vrab01 / 94) + S_Encryption94(Vrab01);}
  string S_EncryptionUINT16(statics uint16 Vrab01)   perfect {S_Control(); return S_Encryption94(Vrab01 / 8836) + S_Encryption94(Vrab01 / 94) + S_Encryption94(Vrab01);}
  string S_EncryptionUINT18(statics uint32 Vrab01)   perfect {S_Control(); return S_Encryption94(Vrab01 / 8836) + S_Encryption94(Vrab01 / 94) + S_Encryption94(Vrab01);}
  string S_EncryptionUINT24(statics uint32 Vrab01)   perfect {S_Control(); return S_Encryption94(Vrab01 / 830584) + S_Encryption94(Vrab01 / 8836) + S_Encryption94(Vrab01 / 94) + S_Encryption94(Vrab01);}
  string S_EncryptionUINT32(statics uint32 Vrab01)   perfect {S_Control(); return S_Encryption94(Vrab01 / 78074896) + S_Encryption94(Vrab01 / 830584) + S_Encryption94(Vrab01 / 8836) + S_Encryption94(Vrab01 / 94) + S_Encryption94(Vrab01);}
  string S_EncryptionUINT64(statics uint64 Vrab01)   perfect {S_Control(); return S_Encryption94(Vrab01 / 572994802228616704) + S_Encryption94(Vrab01 / 6095689385410816) + S_Encryption94(Vrab01 / 64847759419264) + S_Encryption94(Vrab01 / 689869781056) + S_Encryption94(Vrab01 / 7339040224) + S_Encryption94(Vrab01 / 78074896) + S_Encryption94(Vrab01 / 830584) + S_Encryption94(Vrab01 / 8836) + S_Encryption94(Vrab01 / 94) + S_Encryption94(Vrab01);}
  string S_EncryptionXINT64(statics xint64 Vrab01)   perfect {S_Control(); xint64 Vrab02 = Vrab01 + 400000; if(Vrab02 < 0){Vrab02 = 0;} else {if(Vrab02 > 800000) Vrab02 = 800000;} statics int64 Vrab03 = rint64(Vrab02); statics int64 Vrab04 = Vrab03 / 94; statics xint64 Vrab05 = (Vrab02 - rxint64(rint64(Vrab02))) * 100000; statics xint64 Vrab06 = (Vrab05 - rxint64(rint64(Vrab05))) * 100000; statics xint64 Vrab07 = (Vrab06 - rxint64(rint64(Vrab06))) * 100000; statics int64 Vrab08 = rint64(Vrab05) * 10000000000 + rint64(Vrab06) * 100000 + rint64(Vrab07); statics int64 Vrab09 = Vrab08 / 94; statics int64 Vrab10 = Vrab09 / 94; statics int64 Vrab11 = Vrab10 / 94; statics int64 Vrab12 = Vrab11 / 94; statics int64 Vrab13 = Vrab12 / 94; statics int64 Vrab14 = Vrab13 / 94; return S_Encryption94(Vrab04 / 94) + S_Encryption94(Vrab04) + S_Encryption94(Vrab03) + S_Encryption94(Vrab14 / 94) + S_Encryption94(Vrab14) + S_Encryption94(Vrab13) + S_Encryption94(Vrab12) + S_Encryption94(Vrab11) + S_Encryption94(Vrab10) + S_Encryption94(Vrab09) + S_Encryption94(Vrab08);}
  string S_EncryptionSTRING(string Temp01)           perfect {S_Control(); int8 Vrab01 = 0; statics uint32 Vrab02 = Temp01.size(); uint32 Vrab03 = 0; while(Vrab03 != Vrab02){Vrab01 = Temp01.at(Vrab03); if(Vrab01 >= '!' && Vrab01 <= '~') Temp01.at(Vrab03) = (S_Encryption94(rint64(Vrab01) + rint64(Vrab03) - 33)).at(0); Vrab03 += 1;} return Temp01;}

 // Light Functions
  int0   L_Message(statics asSMessageInfo *Amsg01, int0 *Vrab01)    perfect
  {
   UNREFERENCED_PARAMETER(Vrab01); statics string Temp01 = L_Simplfy(Amsg01->section);
   if(Temp01 == "")
   {
    printf("%s - %s\n", Amsg01->type == asMSGTYPE_ERROR ? ("ERROR") : (Amsg01->type == asMSGTYPE_WARNING ? "WARNING" : "INFO"), Amsg01->message);
   } else
   {
    if(Amsg01->row == 0 && Amsg01->col == 0)
    {
     printf("%s: %s - %s\n", Temp01.c_str(), Amsg01->type == asMSGTYPE_ERROR ? ("ERROR") : (Amsg01->type == asMSGTYPE_WARNING ? "WARNING" : "INFO"), Amsg01->message);
    } else
    {
     printf("%s(%d, %d): %s - %s\n", Temp01.c_str(), Amsg01->row, Amsg01->col, Amsg01->type == asMSGTYPE_ERROR ? ("ERROR") : (Amsg01->type == asMSGTYPE_WARNING ? "WARNING" : "INFO"), Amsg01->message);
    }
   }
  }
  int1   L_Any()                                                    perfect {return Input->RESH_ANY == 1;}
  int1   L_Exist(statics string &Temp01)                            perfect {struct stat Stat01; return (stat(Temp01.c_str(), &Stat01) == 0);} // Check if the certain directory is exist or not.
  uint8  L_Input(uint8 Vrab01)                                      perfect
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
    case 95: return Input->PADS_UP[0];
    case 96: return Input->PADS_LEFT[0];
    case 97: return Input->PADS_DOWN[0];
    case 98: return Input->PADS_RIGHT[0];
    case 99: return Input->PADS_A[0];
    case 100: return Input->PADS_B[0];
    case 101: return Input->PADS_X[0];
    case 102: return Input->PADS_Y[0];
    case 103: return Input->PADS_START[0];
    case 104: return Input->PADS_BACK[0];
    case 105: return Input->PADS_MENU[0];
    case 106: return Input->PADS_VIEW[0];
   
    default: return 0;
   }
  }
  uint8  L_Press()                                                  perfect 
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
   if(Input->PADS_UP[0] == 1) return 95ui8;
   if(Input->PADS_LEFT[0] == 1) return 96ui8;
   if(Input->PADS_DOWN[0] == 1) return 97ui8;
   if(Input->PADS_RIGHT[0] == 1) return 98ui8;
   if(Input->PADS_A[0] == 1) return 99ui8;
   if(Input->PADS_B[0] == 1) return 100ui8;
   if(Input->PADS_X[0] == 1) return 101ui8;
   if(Input->PADS_Y[0] == 1) return 102ui8;
   if(Input->PADS_START[0] == 1) return 103ui8;
   if(Input->PADS_BACK[0] == 1) return 104ui8;
   if(Input->PADS_MENU[0] == 1) return 105ui8;
   if(Input->PADS_VIEW[0] == 1) return 106ui8;
   return 255ui8;
  }
  int32  L_Numbering(string Temp01)                                 perfect {while(Temp01.size() > 0 && Temp01.at(0) != '-' && (Temp01.at(0) < '0' || Temp01.at(0) > '9')) Temp01.erase(0, 1); uint32 Vrab01 = Temp01.size(); if(Vrab01 == 0) return 0; while(Vrab01 != 1) if(Temp01.at(Vrab01 - 1) < '0' || Temp01.at(Vrab01 - 1) > '9'){Vrab01 -= 1;} else {break;} int32 Vrab02 = 0; if(Temp01.at(0) == '-'){if(Vrab01 == 1) return 0; if(Temp01.at(1) < '0' || Temp01.at(1) > '9') return 0; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1; break; case '2': Vrab02 -= 2; break; case '3': Vrab02 -= 3; break; case '4': Vrab02 -= 4; break; case '5': Vrab02 -= 5; break; case '6': Vrab02 -= 6; break; case '7': Vrab02 -= 7; break; case '8': Vrab02 -= 8; break; case '9': Vrab02 -= 9; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10; break; case '2': Vrab02 -= 20; break; case '3': Vrab02 -= 30; break; case '4': Vrab02 -= 40; break; case '5': Vrab02 -= 50; break; case '6': Vrab02 -= 60; break; case '7': Vrab02 -= 70; break; case '8': Vrab02 -= 80; break; case '9': Vrab02 -= 90; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100; break; case '2': Vrab02 -= 200; break; case '3': Vrab02 -= 300; break; case '4': Vrab02 -= 400; break; case '5': Vrab02 -= 500; break; case '6': Vrab02 -= 600; break; case '7': Vrab02 -= 700; break; case '8': Vrab02 -= 800; break; case '9': Vrab02 -= 900; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000; break; case '2': Vrab02 -= 2000; break; case '3': Vrab02 -= 3000; break; case '4': Vrab02 -= 4000; break; case '5': Vrab02 -= 5000; break; case '6': Vrab02 -= 6000; break; case '7': Vrab02 -= 7000; break; case '8': Vrab02 -= 8000; break; case '9': Vrab02 -= 9000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000; break; case '2': Vrab02 -= 20000; break; case '3': Vrab02 -= 30000; break; case '4': Vrab02 -= 40000; break; case '5': Vrab02 -= 50000; break; case '6': Vrab02 -= 60000; break; case '7': Vrab02 -= 70000; break; case '8': Vrab02 -= 80000; break; case '9': Vrab02 -= 90000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000; break; case '2': Vrab02 -= 200000; break; case '3': Vrab02 -= 300000; break; case '4': Vrab02 -= 400000; break; case '5': Vrab02 -= 500000; break; case '6': Vrab02 -= 600000; break; case '7': Vrab02 -= 700000; break; case '8': Vrab02 -= 800000; break; case '9': Vrab02 -= 900000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000000; break; case '2': Vrab02 -= 2000000; break; case '3': Vrab02 -= 3000000; break; case '4': Vrab02 -= 4000000; break; case '5': Vrab02 -= 5000000; break; case '6': Vrab02 -= 6000000; break; case '7': Vrab02 -= 7000000; break; case '8': Vrab02 -= 8000000; break; case '9': Vrab02 -= 9000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000000; break; case '2': Vrab02 -= 20000000; break; case '3': Vrab02 -= 30000000; break; case '4': Vrab02 -= 40000000; break; case '5': Vrab02 -= 50000000; break; case '6': Vrab02 -= 60000000; break; case '7': Vrab02 -= 70000000; break; case '8': Vrab02 -= 80000000; break; case '9': Vrab02 -= 90000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000; break; case '2': Vrab02 -= 200000000; break; case '3': Vrab02 -= 300000000; break; case '4': Vrab02 -= 400000000; break; case '5': Vrab02 -= 500000000; break; case '6': Vrab02 -= 600000000; break; case '7': Vrab02 -= 700000000; break; case '8': Vrab02 -= 800000000; break; case '9': Vrab02 -= 900000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; for(int32 Vrab03 = 10; Vrab01 > 0; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000 * Vrab03; break; case '2': Vrab02 -= 200000000 * Vrab03; break; case '3': Vrab02 -= 300000000 * Vrab03; break; case '4': Vrab02 -= 400000000 * Vrab03; break; case '5': Vrab02 -= 500000000 * Vrab03; break; case '6': Vrab02 -= 600000000 * Vrab03; break; case '7': Vrab02 -= 700000000 * Vrab03; break; case '8': Vrab02 -= 800000000 * Vrab03; break; case '9': Vrab02 -= 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;} else {Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1; break; case '2': Vrab02 += 2; break; case '3': Vrab02 += 3; break; case '4': Vrab02 += 4; break; case '5': Vrab02 += 5; break; case '6': Vrab02 += 6; break; case '7': Vrab02 += 7; break; case '8': Vrab02 += 8; break; case '9': Vrab02 += 9; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10; break; case '2': Vrab02 += 20; break; case '3': Vrab02 += 30; break; case '4': Vrab02 += 40; break; case '5': Vrab02 += 50; break; case '6': Vrab02 += 60; break; case '7': Vrab02 += 70; break; case '8': Vrab02 += 80; break; case '9': Vrab02 += 90; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100; break; case '2': Vrab02 += 200; break; case '3': Vrab02 += 300; break; case '4': Vrab02 += 400; break; case '5': Vrab02 += 500; break; case '6': Vrab02 += 600; break; case '7': Vrab02 += 700; break; case '8': Vrab02 += 800; break; case '9': Vrab02 += 900; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000; break; case '2': Vrab02 += 2000; break; case '3': Vrab02 += 3000; break; case '4': Vrab02 += 4000; break; case '5': Vrab02 += 5000; break; case '6': Vrab02 += 6000; break; case '7': Vrab02 += 7000; break; case '8': Vrab02 += 8000; break; case '9': Vrab02 += 9000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000; break; case '2': Vrab02 += 20000; break; case '3': Vrab02 += 30000; break; case '4': Vrab02 += 40000; break; case '5': Vrab02 += 50000; break; case '6': Vrab02 += 60000; break; case '7': Vrab02 += 70000; break; case '8': Vrab02 += 80000; break; case '9': Vrab02 += 90000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000; break; case '2': Vrab02 += 200000; break; case '3': Vrab02 += 300000; break; case '4': Vrab02 += 400000; break; case '5': Vrab02 += 500000; break; case '6': Vrab02 += 600000; break; case '7': Vrab02 += 700000; break; case '8': Vrab02 += 800000; break; case '9': Vrab02 += 900000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000000; break; case '2': Vrab02 += 2000000; break; case '3': Vrab02 += 3000000; break; case '4': Vrab02 += 4000000; break; case '5': Vrab02 += 5000000; break; case '6': Vrab02 += 6000000; break; case '7': Vrab02 += 7000000; break; case '8': Vrab02 += 8000000; break; case '9': Vrab02 += 9000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000000; break; case '2': Vrab02 += 20000000; break; case '3': Vrab02 += 30000000; break; case '4': Vrab02 += 40000000; break; case '5': Vrab02 += 50000000; break; case '6': Vrab02 += 60000000; break; case '7': Vrab02 += 70000000; break; case '8': Vrab02 += 80000000; break; case '9': Vrab02 += 90000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000; break; case '2': Vrab02 += 200000000; break; case '3': Vrab02 += 300000000; break; case '4': Vrab02 += 400000000; break; case '5': Vrab02 += 500000000; break; case '6': Vrab02 += 600000000; break; case '7': Vrab02 += 700000000; break; case '8': Vrab02 += 800000000; break; case '9': Vrab02 += 900000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; for(int32 Vrab03 = 10; Vrab01 != -1; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000 * Vrab03; break; case '2': Vrab02 += 200000000 * Vrab03; break; case '3': Vrab02 += 300000000 * Vrab03; break; case '4': Vrab02 += 400000000 * Vrab03; break; case '5': Vrab02 += 500000000 * Vrab03; break; case '6': Vrab02 += 600000000 * Vrab03; break; case '7': Vrab02 += 700000000 * Vrab03; break; case '8': Vrab02 += 800000000 * Vrab03; break; case '9': Vrab02 += 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;}}
  int32  L_Positive(statics int32 Vrab01)                           perfect {if(Vrab01 < 0) return -Vrab01; return Vrab01;}
  int32  L_Rounding(statics xint64 Vrab01)                          perfect {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint32(Vrab01); return rint32(Vrab01) + (Vrab02 ? -1 : 1);} // Round xint64 into int32.
  xint64 L_Positive64(statics xint64 Vrab01)                        perfect {if(Vrab01 < 0) return -Vrab01; return Vrab01;}
  int64  L_Rounding64(statics xint64 Vrab01)                        perfect {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint64(Vrab01); return rint64(Vrab01) + (Vrab02 ? -1 : 1);} // Round xint64 into int64.
  uint64 L_Random(uint64 Vrab01, insize Vrab02)                     perfect 
  {
   remains std::vector < int1 > Vect01;
   if(Vrab0032){Vrab0032 = false; Vect01.clear();} if(Vect01.size() <= Vrab02) Vect01.resize(Vrab02 + 1);

   remains std::vector < std::mt19937 > Vect02;
   if(Vect02.size() <= Vrab02) Vect02.resize(Vrab02 + 1);

   if(!Vect01[Vrab02])
   {
    Vect01[Vrab02] = true;
    Vect02[Vrab02] = std::mt19937(ruint32(Vrab0031));
   } Vrab0031 += 1; 

   uint64 Vrab03 = ruint64(Vect02[Vrab02]()); Vrab03 %= ruint64(0xFFFFFFFF) + 1;
   return ruint64(L_Rounding64((rxint64(Vrab03) / rxint64(0xFFFFFFFF)) * rxint64(Vrab01)));
  }
  uint64 L_Convert(string Temp01)                                   perfect
  {
   string Temp02 = L_Lowercase(Temp01);
   insize Vrab01 = Temp02.size(); uint64 Vrab02 = 0; insize Vrab03 = 0;
   while(Vrab01 > 0)
   {
    Vrab01 -= 1; uint64 Vrab04 = 0;
    switch(Temp02[Vrab01])
    {
     case '0': Vrab04 = 0; break;
     case '1': Vrab04 = 1; break;
     case '2': Vrab04 = 2; break;
     case '3': Vrab04 = 3; break;
     case '4': Vrab04 = 4; break;
     case '5': Vrab04 = 5; break;
     case '6': Vrab04 = 6; break;
     case '7': Vrab04 = 7; break;
     case '8': Vrab04 = 8; break;
     case '9': Vrab04 = 9; break;
     case 'a': Vrab04 = 10; break;
     case 'b': Vrab04 = 11; break;
     case 'c': Vrab04 = 12; break;
     case 'd': Vrab04 = 13; break;
     case 'e': Vrab04 = 14; break;
     case 'f': Vrab04 = 15; break;
     default: Vrab01 = 0; break;
    }
    Vrab02 += (Vrab04 << Vrab03);
    Vrab03 += 4;
   }
   return Vrab02;
  }
  xint64 L_Doubling(statics string &Temp01)                         perfect 
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
  xint64 L_Distance(xint64 Vrab01, xint64 Vrab02, xint64 Vrab03, xint64 Vrab04) perfect
  {
   return sqrt(pow(Vrab03 - Vrab01, 2) + pow(Vrab04 - Vrab02, 2));
  }
  xint64*L_Degree(statics xint64 Vrab01, statics xint64 Vrab02, statics xint64 Vrab03, statics xint64 Vrab04, statics xint64 Vrab05, statics xint64 Vrab06, statics int1 Vrab07) perfect
  {
   remains xint64 Vrab08[3];
   statics xint64 Vrab09 = Vrab04 - Vrab01;
   statics xint64 Vrab10 = Vrab05 - Vrab02;
   statics xint64 Vrab11 = (Vrab06 - Vrab03) * (Vrab07 ? 2.5 : 1.0);
   statics xint64 Vrab12 = sqrt((Vrab09 * Vrab09) + (Vrab10 * Vrab10) + (Vrab11 * Vrab11));
   if(Vrab12 == 0){Vrab08[0] = 0; Vrab08[1] = 0; Vrab08[2] = 0; return Vrab08;}
   Vrab08[0] = Vrab09 / Vrab12;
   Vrab08[1] = Vrab10 / Vrab12;
   Vrab08[2] = Vrab11 / Vrab12;
   return Vrab08;
  }
  xint64*L_Rotate(statics xint64 Vrab01, statics xint64 Vrab02, statics xint64 Vrab03) perfect
  {
   remains xint64 Vrab06[2]; Vrab06[0] = Vrab01; Vrab06[1] = Vrab02;
   
   statics xint64 Vrab07 = sqrt((Vrab01 * Vrab01) + (Vrab02 * Vrab02));
   if(Vrab07 == 0) return Vrab06;
   xint64 Vrab08 = Vrab01 / Vrab07;
   xint64 Vrab09 = Vrab02 / Vrab07;
   xint64 Vrab10 = -(xint64(DirectX::XMConvertToDegrees(std::acos(Vrab08))) - 90.0);
   xint64 Vrab11 = -(xint64(DirectX::XMConvertToDegrees(std::acos(Vrab09))) - 90.0);
   xint64 Vrab12 = 0.0;

   if(Vrab10 < 0.0 && Vrab11 <= 0.0) // (X -90 Y 0) ~ (X 0 Y -90) = 0 Degree
   {
    Vrab12 = -Vrab11;
   }
   if(Vrab10 >= 0.0 && Vrab11 < 0.0) // (X 0 Y -90) ~ (X 90 Y 0) = 90 Degree
   {
    Vrab12 = 90.0 + Vrab10;
   }
   if(Vrab10 > 0.0 && Vrab11 >= 0.0) // (X 90 Y 0) ~ (X 0 Y 90) = 180 Degree
   {
    Vrab12 = 180.0 + Vrab11;
   }
   if(Vrab10 <= 0.0 && Vrab11 > 0.0) // (X 0 Y 90) ~ (X -90 Y 0) = 270 Degree
   {
    Vrab12 = 270.0 - Vrab10;
   }

   Vrab12 += Vrab03; while(Vrab12 < 0.0) Vrab12 += 360.0; while(Vrab12 >= 360.0) Vrab12 -= 360.0;

   if(Vrab12 >= 0.0 && Vrab12 < 90.0)
   {
    Vrab10 = Vrab12 - 90.0; Vrab11 = -Vrab12;
   }
   if(Vrab12 >= 90.0 && Vrab12 < 180.0)
   {
    Vrab10 = Vrab12 - 90.0; Vrab11 = Vrab12 - 180.0;
   }
   if(Vrab12 >= 180.0 && Vrab12 < 270.0)
   {
    Vrab10 = 270.0 - Vrab12; Vrab11 = Vrab12 - 180.0;
   }
   if(Vrab12 >= 270.0 && Vrab12 < 360.0)
   {
    Vrab10 = 270.0 - Vrab12; Vrab11 = 360.0 - Vrab12;
   }

   xint64 Vrab13 = 0;
   {
    if(Vrab08 < 0) Vrab08 = -Vrab08; if(Vrab09 < 0) Vrab09 = -Vrab09;
    xint64 Vrab14 = Vrab08 + Vrab09; if(Vrab14 == 0.0) return Vrab06;
    xint64 Vrab15 = Vrab01; xint64 Vrab16 = Vrab02;
    if(Vrab15 < 0) Vrab15 = -Vrab15; if(Vrab16 < 0) Vrab16 = -Vrab16;
    Vrab13 = (Vrab15 + Vrab16) / Vrab14;
   }
   Vrab06[0] = xint64(std::cos(DirectX::XMConvertToRadians((-Vrab10) + 90.0))) * Vrab13;
   Vrab06[1] = xint64(std::cos(DirectX::XMConvertToRadians((-Vrab11) + 90.0))) * Vrab13;

   return Vrab06;
  }
  string L_Simplfy(statics string &Temp01)                          perfect {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) == '\\' || Temp01.at(Vrab01) == '/'){Vrab01 += 1; break;}} if(Vrab01 == 0) return Temp01; return string(Temp01, Vrab01, Temp01.size() - Vrab01);}
  string L_Cut(string Temp01, insize Vrab01, insize Vrab02)         perfect {statics insize Vrab03 = Temp01.size(); if(Vrab01 > Vrab03) Vrab01 = Vrab03; if(Vrab02 == 0) Vrab02 = Vrab03 - Vrab01; return string(Temp01, Vrab01, Vrab02);}
  string L_Pronounce(statics uint64 Vrab01)                         perfect {statics uint64 Vrab02 = (Vrab01 % 1000) + 1000; statics uint64 Vrab03 = Vrab01 / 1000; statics uint64 Vrab04 = Vrab03 / 60; statics uint64 Vrab05 = Vrab04 / 60; return std::to_string(Vrab05 / 24) + " - "+ string(std::to_string((Vrab05 % 24) + 100), 1, 2) + ":" + string(std::to_string((Vrab04 % 60) + 100), 1, 2) + ":" + string(std::to_string((Vrab03 % 60) + 100), 1, 2) + "." + string(std::to_string(Vrab02), 1, 3);}
  string L_Directory(statics string &Temp01)                        perfect {return Temp0001 + Temp01;}
  string L_Execute(statics string &Temp01)                          perfect {string Temp02 = Temp01; uint32 Vrab01 = Temp02.size() - 1; while(Vrab01 != 0 && Temp02.at(Vrab01) != '\\') Vrab01 -= 1; if(Vrab01 > 0) Temp02.erase(Vrab01, Temp02.size() - Vrab01); std::filesystem::create_directories(Temp02); return Temp01;}
  string L_Lowercase(string Temp01)                                 perfect {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) >= 'A' && Temp01.at(Vrab01) <= 'Z') Temp01.at(Vrab01) += 32;} return Temp01;}
  string L_Load(uint8 Vrab01, uint8 Vrab02)                         perfect
  {
   statics string Temp01 = L_Directory("SaveData_" + (Vrab02 == 0 ? "Autosave" : std::to_string(ruint32(Vrab02))) + ".esd");
   std::ifstream File01(Temp01, std::ios::binary); if(!File01.is_open()) return "F|Either no save file detected or unable to access the file.";
   std::time_t Time01 = 0; struct stat Stat01; if(stat(Temp01.c_str(), &Stat01) == 0) Time01 = Stat01.st_mtime;

   int1 Vrab03 = false; string Temp02 = "";
   while(true)
   {
    int8 Vrab04 = 0; string Temp03; insize Vrab05 = 0; uint8 Vrab06 = 0;

    Vrab05 = 10; Temp03 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp03.push_back(Vrab04);} if(Vrab03) break;
    if(ruint64(Time01) > S_DecryptionUINT64(Temp03.c_str())) return "F|The data was modified!";

    Vrab05 = 2; Temp03 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp03.push_back(Vrab04);} if(Vrab03) break;
    Vrab06 = S_DecryptionUINT8(Temp03.c_str()); if(Vrab06 < Vrab01) return "F|No data detected.";

    uint8 Vrab07 = 0;
    while(Vrab06 != ruint8(-1))
    {
     Vrab06 -= 1;

     Vrab05 = 5; Temp03 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp03.push_back(Vrab04);} if(Vrab03) break;
     Vrab05 = rinsize(S_DecryptionUINT32(Temp03.c_str()));

     Temp03 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp03.push_back(Vrab04);} if(Vrab03) break;
     if(Vrab07 == Vrab01) Temp02 = Temp03; Vrab07 += 1;
    } if(Vrab03) break;

    Vrab05 = 10; Temp03 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp03.push_back(Vrab04);} if(Vrab03) break;
    if(ruint64(Time01) > S_DecryptionUINT64(Temp03.c_str())) return "F|The data was modified!";

    break;
   }
   File01.close(); if(Vrab03) return "F|Unexpected end of data."; return "T|" + S_DecryptionSTRING(Temp02);
  }
  string L_Save(uint8 Vrab01, string Temp01, uint8 Vrab02)          perfect
  {
   statics string Temp02 = L_Directory("SaveData_" + (Vrab02 == 0 ? "Autosave" : std::to_string(ruint32(Vrab02))) + ".esd");
   string Temp03 = "", Temp04 = "";
   
   std::ifstream File01(Temp02, std::ios::binary); if(File01.is_open())
   {
    std::time_t Time01 = 0; struct stat Stat01; if(stat(Temp02.c_str(), &Stat01) == 0) Time01 = Stat01.st_mtime; int1 Vrab03 = false;

    while(true)
    {
     int8 Vrab04 = 0; string Temp05; insize Vrab05 = 0; uint8 Vrab06 = 0;

     Vrab05 = 10; Temp05 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp05.push_back(Vrab04);} if(Vrab03) break;
     if(ruint64(Time01) > S_DecryptionUINT64(Temp05.c_str())){Vrab03 = true; break;}

     Vrab05 = 2; Temp05 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp05.push_back(Vrab04);} if(Vrab03) break;
     Vrab06 = S_DecryptionUINT8(Temp05.c_str());
     if(Vrab06 < Vrab01){Temp03 += S_EncryptionUINT8(Vrab01);} else {Temp03 += Temp05;}

     uint8 Vrab07 = Vrab06 + 1; uint8 Vrab08 = ruint8(-1); int1 Vrab09 = true;
     while(Vrab07 != 0)
     {
      Vrab07 -= 1; Vrab08 += 1;
      
      if(Vrab08 == Vrab01)
      {
       Vrab05 = 5; Temp05 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp05.push_back(Vrab04);} if(Vrab03) break;
       Vrab05 = rinsize(S_DecryptionUINT32(Temp05.c_str()));
       Temp05 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp05.push_back(Vrab04);} if(Vrab03) break;
       
       Vrab09 = false; continue;
      }

      Vrab05 = 5; Temp05 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp05.push_back(Vrab04);} if(Vrab03) break;
      Vrab05 = rinsize(S_DecryptionUINT32(Temp05.c_str()));
      if(Vrab09){Temp03 += Temp05;} else {Temp04 += Temp05;}

      Temp05 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp05.push_back(Vrab04);} if(Vrab03) break;
      if(Vrab09){Temp03 += Temp05;} else {Temp04 += Temp05;}
     }

     if(Vrab06 + 1 < Vrab01){Vrab07 = Vrab01 - Vrab06 - 1;} else {Vrab07 = 0;}
     while(Vrab07 != 0)
     {
      Vrab07 -= 1;
      Temp03 += S_EncryptionUINT32(0);
     }

     Vrab05 = 10; Temp05 = ""; while(Vrab05 != 0){Vrab05 -= 1; if(!File01){Vrab03 = true; break;} File01.read(&Vrab04, 1); Temp05.push_back(Vrab04);} if(Vrab03) break;
     if(ruint64(Time01) > S_DecryptionUINT64(Temp05.c_str())){Vrab03 = true; break;}

     break;
    } if(Vrab03){Temp03 = ""; Temp04 = "";}
    File01.close();
   }

   if(Temp03 == "")
   {
    Temp03 += S_EncryptionUINT8(Vrab01);
    uint8 Vrab03 = Vrab01;
    while(Vrab03 != 0)
    {
     Vrab03 -= 1; Temp03 += S_EncryptionUINT32(0);
    }
   }

   std::ofstream File02(L_Execute(Temp02), std::ios::binary); if(!File02.is_open()) return "F|Unable to create a save file.";
   File02 << S_EncryptionUINT64(std::chrono::time_point_cast < std::chrono::seconds > (std::chrono::system_clock::now()).time_since_epoch().count());
   File02 << Temp03;

   File02 << S_EncryptionUINT32(ruint32(Temp01.size())) + S_EncryptionSTRING(Temp01);

   File02 << Temp04;
   File02 << S_EncryptionUINT64(std::chrono::time_point_cast < std::chrono::seconds > (std::chrono::system_clock::now()).time_since_epoch().count());
   return "T|Successfully save the data.";
  }
  string L_Lang(insize Vrab01, string Temp01 = "")                  perfect
  {
   if(Temp01 != "")
   {
    string Temp02 = "F"; Vect0001.clear(); Vect0002.clear(); Vect0002.push_back("");
    while(true)
    {
     if(!L_Exist(Temp01)) break;
     std::ifstream File01(Temp01); stream Strn01; Strn01 << File01.rdbuf(); File01.close(); statics string Temp03 = "</> " + Strn01.str() + "</> ";

     insize Vrab02 = 0; statics insize Vrab03 = Temp03.size();
     int1 Vrab04 = false; // On Read
     int1 Vrab05 = false; // First Append to ignore spaces and enter on comment
     insize Vrab06 = rinsize(-1); // Current text num
     int1 Vrab07 = false; // Complete/Save last read.
     insize Vrab08 = rinsize(-1); // Last read text num
     string Temp04 = "<none>"; // on read
     while(Vrab02 < Vrab03)
     {
      if(Vrab07) if(Vrab08 < Vect0001.size()) 
      {insize Vrab09 = Vect0002.size(); if(Temp04 == ""){Vrab09 = 0;} else {Vect0002.push_back("");} Vect0002[Vrab09] = Temp04; Vect0001[Vrab08] = Vrab09; Temp04 = ""; Vrab07 = false;}
      Vrab08 = Vrab06;

      // Commands
      if(!(Vrab04 == false && Vrab05 == true))
      if(Vrab02 + 2 < Vrab03) if(Temp03[Vrab02] == '<')
      {
       if(Temp03[Vrab02 + 1] == '/' && Temp03[Vrab02 + 2] == '>')
       {
        Vrab06 += 1;
        if(!Vrab04) Vrab02 -= 1; Vrab04 = true; Vrab05 = true; Vrab07 = true; Vrab02 += 3; continue;
       }
       if(Temp03[Vrab02 + 1] == ':')
       {
        string Temp05; insize Vrab09 = Vrab02 + 2; while(Vrab09 < Vrab03){if(Temp03[Vrab09] == '>') break; Temp05 += Temp03[Vrab09]; Vrab09 += 1;} if(Vrab09 == Vrab03) continue; Vrab06 = L_Numbering(Temp05);
        if(!Vrab04) Vrab02 -= 1; Vrab04 = true; Vrab05 = true; Vrab07 = true; Vrab02 += Temp05.size() + 3; continue;
       }
      }
      if(Vrab04)
      {
       if(Vrab06 >= Vect0001.size()) Vect0001.resize(Vrab06 + 1);
       statics int8 Vrab09 = Temp03[Vrab02]; Temp04.push_back(Vrab09);
       if(Vrab05)
       {
        if(Vrab02 + 1 < Vrab03) if(Temp03[Vrab02] == '/' && Temp03[Vrab02 + 1] == '/'){Temp04 = ""; Vrab04 = false;}
        if(Vrab09 == '\n') Temp04 = "";
        if(Vrab04) if(Vrab09 != ' ' && Vrab09 != '\n') Vrab05 = false;
       }
      } else {if(Vrab05) if(Temp03[Vrab02] == '\n') Vrab04 = true;}

      Vrab02 += 1;
     }

     Temp02 = "T"; break;
    } return Temp02;
   } else {if(Vrab01 < Vect0001.size()){return Vect0002[Vect0001[Vrab01]];} else {return "";}}
  }

 // Main Functions
  int0 M_EngineInput(DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01) perfect
  {
   int1 Vrab01 = false;
   auto Ikey02 = Ikey01->GetState(); statics uint16 Vrab02 = ruint16(L_Rounding(480.0 / rxint64(Vrab0003)) - 1), Vrab03 = Vrab02 - ruint16(L_Rounding(64.0 / rxint64(Vrab0003))); 
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

   std::vector < std::vector < int1 > > Vect01(4, std::vector < int1 > (9));
   for(insize Vrab04 = 1; Vrab04 < 5; Vrab04++)
   {
    auto Ipad02 = Ipad01->GetState(Vrab04 - 1); statics insize Vrab05 = Vrab04 - 1;
			 Input->PADS_ON[Vrab04] = Ipad02.connected; if(!Input->PADS_ON[Vrab04]) continue;
    if(Ipad02.dpad.up)   {Vect01[Vrab05][0] = true; if((++Input->PADS_UP[Vrab04]) == Vrab02) Input->PADS_UP[Vrab04] = Vrab03;} else {Input->PADS_UP[Vrab04] = 0ui8;}
    if(Ipad02.dpad.left) {Vect01[Vrab05][1] = true; if((++Input->PADS_LEFT[Vrab04]) == Vrab02) Input->PADS_LEFT[Vrab04] = Vrab03;} else {Input->PADS_LEFT[Vrab04] = 0ui8;}
    if(Ipad02.dpad.down) {Vect01[Vrab05][2] = true; if((++Input->PADS_DOWN[Vrab04]) == Vrab02) Input->PADS_DOWN[Vrab04] = Vrab03;} else {Input->PADS_DOWN[Vrab04] = 0ui8;}
    if(Ipad02.dpad.right){Vect01[Vrab05][3] = true; if((++Input->PADS_RIGHT[Vrab04]) == Vrab02) Input->PADS_RIGHT[Vrab04] = Vrab03;} else {Input->PADS_RIGHT[Vrab04] = 0ui8;}
    if(Ipad02.buttons.a) {Vect01[Vrab05][4] = true; if((++Input->PADS_A[Vrab04]) == Vrab02) Input->PADS_A[Vrab04] = Vrab03;} else {Input->PADS_A[Vrab04] = 0ui8;}
    if(Ipad02.buttons.b) {Vect01[Vrab05][5] = true; if((++Input->PADS_B[Vrab04]) == Vrab02) Input->PADS_B[Vrab04] = Vrab03;} else {Input->PADS_B[Vrab04] = 0ui8;}
    if(Ipad02.buttons.x) {Vect01[Vrab05][6] = true; if((++Input->PADS_X[Vrab04]) == Vrab02) Input->PADS_X[Vrab04] = Vrab03;} else {Input->PADS_X[Vrab04] = 0ui8;}
    if(Ipad02.buttons.y) {Vect01[Vrab05][7] = true; if((++Input->PADS_Y[Vrab04]) == Vrab02) Input->PADS_Y[Vrab04] = Vrab03;} else {Input->PADS_Y[Vrab04] = 0ui8;}
    if(Ipad02.buttons.start){Vect01[Vrab05][8] = true; if((++Input->PADS_START[Vrab04]) == Vrab02) Input->PADS_START[Vrab04] = Vrab03;} else {Input->PADS_START[Vrab04] = 0ui8;}
    if(Ipad02.buttons.back) {Vect01[Vrab05][9] = true; if((++Input->PADS_BACK[Vrab04]) == Vrab02) Input->PADS_BACK[Vrab04] = Vrab03;} else {Input->PADS_BACK[Vrab04] = 0ui8;}
    if(Ipad02.buttons.menu) {Vect01[Vrab05][10] = true; if((++Input->PADS_MENU[Vrab04]) == Vrab02) Input->PADS_MENU[Vrab04] = Vrab03;} else {Input->PADS_MENU[Vrab04] = 0ui8;}
    if(Ipad02.buttons.view) {Vect01[Vrab05][11] = true; if((++Input->PADS_VIEW[Vrab04]) == Vrab02) Input->PADS_VIEW[Vrab04] = Vrab03;} else {Input->PADS_VIEW[Vrab04] = 0ui8;}
   }
   if(Vect01[0][0] || Vect01[1][0] || Vect01[2][0] || Vect01[3][0])    {Vrab01 = true; if((++Input->PADS_UP[0]) == Vrab02) Input->PADS_UP[0] = Vrab03;} else {Input->PADS_UP[0] = 0ui8;}
   if(Vect01[0][1] || Vect01[1][1] || Vect01[2][1] || Vect01[3][1])    {Vrab01 = true; if((++Input->PADS_LEFT[0]) == Vrab02) Input->PADS_LEFT[0] = Vrab03;} else {Input->PADS_LEFT[0] = 0ui8;}
   if(Vect01[0][2] || Vect01[1][2] || Vect01[2][2] || Vect01[3][2])    {Vrab01 = true; if((++Input->PADS_DOWN[0]) == Vrab02) Input->PADS_DOWN[0] = Vrab03;} else {Input->PADS_DOWN[0] = 0ui8;}
   if(Vect01[0][3] || Vect01[1][3] || Vect01[2][3] || Vect01[3][3])    {Vrab01 = true; if((++Input->PADS_RIGHT[0]) == Vrab02) Input->PADS_RIGHT[0] = Vrab03;} else {Input->PADS_RIGHT[0] = 0ui8;}
   if(Vect01[0][4] || Vect01[1][4] || Vect01[2][4] || Vect01[3][4])    {Vrab01 = true; if((++Input->PADS_A[0]) == Vrab02) Input->PADS_A[0] = Vrab03;} else {Input->PADS_A[0] = 0ui8;}
   if(Vect01[0][5] || Vect01[1][5] || Vect01[2][5] || Vect01[3][5])    {Vrab01 = true; if((++Input->PADS_B[0]) == Vrab02) Input->PADS_B[0] = Vrab03;} else {Input->PADS_B[0] = 0ui8;}
   if(Vect01[0][6] || Vect01[1][6] || Vect01[2][6] || Vect01[3][6])    {Vrab01 = true; if((++Input->PADS_X[0]) == Vrab02) Input->PADS_X[0] = Vrab03;} else {Input->PADS_X[0] = 0ui8;}
   if(Vect01[0][7] || Vect01[1][7] || Vect01[2][7] || Vect01[3][7])    {Vrab01 = true; if((++Input->PADS_Y[0]) == Vrab02) Input->PADS_Y[0] = Vrab03;} else {Input->PADS_Y[0] = 0ui8;}
   if(Vect01[0][8] || Vect01[1][8] || Vect01[2][8] || Vect01[3][8])    {Vrab01 = true; if((++Input->PADS_START[0]) == Vrab02) Input->PADS_START[0] = Vrab03;} else {Input->PADS_START[0] = 0ui8;}
   if(Vect01[0][9] || Vect01[1][9] || Vect01[2][9] || Vect01[3][9])    {Vrab01 = true; if((++Input->PADS_BACK[0]) == Vrab02) Input->PADS_BACK[0] = Vrab03;} else {Input->PADS_BACK[0] = 0ui8;}
   if(Vect01[0][10] || Vect01[1][10] || Vect01[2][10] || Vect01[3][10]){Vrab01 = true; if((++Input->PADS_MENU[0]) == Vrab02) Input->PADS_MENU[0] = Vrab03;} else {Input->PADS_MENU[0] = 0ui8;}
   if(Vect01[0][11] || Vect01[1][11] || Vect01[2][11] || Vect01[3][11]){Vrab01 = true; if((++Input->PADS_VIEW[0]) == Vrab02) Input->PADS_VIEW[0] = Vrab03;} else {Input->PADS_VIEW[0] = 0ui8;}

   if(Vrab01){if((++Input->RESH_ANY) == Vrab02) Input->RESH_ANY = Vrab03;} else {Input->RESH_ANY = 0ui8;}
  }
  int0 M_EngineFrame(xint64 Vrab01, xint64 Vrab02, uint32 Vrab03, uint32 Vrab04, DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01) perfect
  {
   UNREFERENCED_PARAMETER(Vrab02); UNREFERENCED_PARAMETER(Vrab03);
   if(Vrab0002 == 0)
   {
	   Input = std::make_unique < HEPTA_INPUT > ();
	   Temp0001 = std::filesystem::current_path().string() + "\\"; Temp0002 = "!\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	   Vrab0032 = std::chrono::steady_clock::now().time_since_epoch().count();
	   Vrab0033 = L_Exist(L_Directory("Database\\MiniGame_Enchanted")) ? 1 : 0;
	   Vrab0034 = L_Exist(L_Directory("Database\\MiniGame_Forevered")) ? 1 : 0;

    string Temp01 = L_Load(0); if(Temp01.at(0) == 'T'){Temp01 = L_Cut(Temp01);} else {Temp01 = "TTF4192041080";} L_Save(0, Temp01);
    Vrab0010 = (Temp01.at(1) != 'F');
    Vrab0011 = (Temp01.at(2) != 'F');
    statics insize Vrab05 = rinsize(L_Numbering(L_Cut(Temp01, 3, 1)));
    Vrab0005 = L_Numbering(L_Cut(Temp01, 4, Vrab05));
    statics insize Vrab06 = rinsize(L_Numbering(L_Cut(Temp01, 4 + Vrab05, 1)));
    Vrab0006 = L_Numbering(L_Cut(Temp01, 5 + Vrab05, Vrab06));
    G_Adjust_Window(Vrab0005, Vrab0006, (Temp01.at(0) == 'T'));
   } if(Vrab0030 == 1)
   {
    statics string Temp01 = std::to_string(Vrab0005);
    statics string Temp02 = std::to_string(Vrab0006);
    L_Save(0, string(string(Vrab0009 ? "T" : "F") + string(Vrab0010 ? "T" : "F") + string(Vrab0011 ? "T" : "F") + std::to_string(Temp01.size()) + Temp01 + std::to_string(Temp02.size()) + Temp02));
   }

   Vrab0002 += 1; if(Vrab0002 == 0xFFFFFFFFFFFFFFFF) Vrab0002 = 0xFFFFFFFFFFFEBF;
   if(Vrab0003 != 1 && Vrab0003 != 2 && Vrab0003 != 4 && Vrab0003 != 8 && Vrab0003 != 16 && Vrab0003 != 32 && Vrab0003 != 64 && Vrab0003 != 128) Vrab0003 = 8;
   remains xint64 Varb01; Varb01 += Vrab01; if(Vrab0002 % ruint64(Vrab0003) != 0) return; Vrab0001 += Vrab0003; M_EngineInput(Ikey01, Ipad01, Imou01); Disp0001.clear();
   remains uint64 Varb02; Varb02 += 1;
   remains uint64 Varb03; if(Varb01 > 1.0){while(Varb01 > 1.0) Varb01 -= 1.0; Varb03 = Varb02; Varb02 = 0;}

   // Starting.
    if(Vrab0001 < 200){P_Set_Display(0, 0xFFFFFF, 0, 0, 0ui8, 255ui8, Vrab0005, Vrab0006); P_Load_Pic(L_Directory("Database\\Interface\\READ.PNG"));}
    {
     statics int64 Vrab05 = 1920 - Vrab0005, Vrab06 = 1080 - Vrab0006;
     if(Vrab0001 >= 200 && Vrab0001 < 4040)
     {
      P_Set_Display(2, P_Load_Pic(L_Directory("Database\\Interface\\READ.PNG")), -L_Rounding64(rxint64(Vrab05) / 2.0), -L_Rounding64(rxint64(Vrab06) / 2.0), 0ui8, 255ui8, -Vrab05, -Vrab06);
      if(Vrab0001 < 680){P_Set_Display(0, 0xFFFFFF, 0, 0, 0ui8, ruint8(255.0 * (rxint64(480 - (Vrab0001 - 200)) / 480.0)), Vrab0005, Vrab0006);} else {P_Load_Pic(L_Directory("Database\\Interface\\TITLE1.PNG")); P_Load_Pic(L_Directory("Database\\Interface\\TITLE2.PNG"));}
      if(Vrab0001 >= 3560){P_Set_Display(0, 0x0, 0, 0, 0ui8, ruint8(255.0 * (rxint64(Vrab0001 - 3560) / 480.0)), Vrab0005, Vrab0006);} else {if(L_Any()) Vrab0001 = 3560;} 
     }
     if(Vrab0001 >= 4040 && Vrab0001 < 8600)
     {
      uint8 Vrab07 = 255;
      if(Vrab0001 < 4520) Vrab07 = ruint8(255.0 * (rxint64(Vrab0001 - 4040) / 480.0));
      if(Vrab0001 >= 5240) Vrab07 = ruint8(255.0 * (rxint64(480 - (Vrab0001 - 5240)) / 480.0));
      if(Vrab0001 >= 5720) Vrab07 = 0;
      P_Set_Display(2, P_Load_Pic(L_Directory("Database\\Interface\\TITLE1.PNG")), -L_Rounding64(rxint64(Vrab05) / 2.0), -L_Rounding64(rxint64(Vrab06) / 2.0), 0ui8, Vrab07, -Vrab05, -Vrab06);
      if(Vrab0001 >= 5000)
      {
       uint8 Vrab08 = 255; if(Vrab0001 < 5480) Vrab08 = ruint8(255.0 * (rxint64(Vrab0001 - 5000) / 480.0));
       P_Set_Display(2, P_Load_Pic(L_Directory("Database\\Interface\\TITLE2.PNG")), -L_Rounding64(rxint64(Vrab05) / 2.0), -L_Rounding64(rxint64(Vrab06) / 2.0), 0ui8, Vrab08, -Vrab05, -Vrab06);
      }
      if(Vrab0001 >= 8120){P_Set_Display(0, 0x0, 0, 0, 0ui8, ruint8(255.0 * (rxint64(Vrab0001 - 8120) / 480.0)), Vrab0005, Vrab0006);} else {if(L_Any()) Vrab0001 = 8120;}
     }
    }

   // Exit.
    if(Vrab0030 == 1) Vrab0030 = 2;

   // LF2 : Enchanted 4th.
    if(Vrab0033 == 2){EIDP_LF2Enchanted(Vrab04, Varb03);} else
    {if(Vrab0001 >= 8600) if(!L_Exist(L_Directory("Setting.ini"))) if(Vrab0033 == 1){P_Unload_Pic(); P_Unload_Image(); Enchanted = std::make_unique < HEPTA_LF2_ENCHANTED > (); Vrab0033 = 2;}}

   // LF2 : Forevered.
    if(Vrab0034 == 2){EIDP_LF2Forevered(Vrab04, Vrab03);} else
    {if(Vrab0001 >= 8600) if(Vrab0033 != 2) if(Vrab0034 == 1){P_Unload_Pic(); P_Unload_Image(); Forevered = std::make_unique < HEPTA_LF2_FOREVERED > (); Vrab0034 = 2;}}
   
   // Purging Offside Images.
   // P_Set_Display(0, 0x0, -rint64(Vrab0007), -rint64(Vrab0008), 0ui8, 255ui8, Vrab0007, rint64(Vrab0008) + rint64(Vrab0006));
   // P_Set_Display(0, 0x0, -rint64(Vrab0007), rint64(Vrab0006), 0ui8, 255ui8, rint64(Vrab0007) + rint64(Vrab0005), Vrab0008);
   // P_Set_Display(0, 0x0, rint64(Vrab0005), 0, 0ui8, 255ui8, Vrab0007, rint64(Vrab0008) + rint64(Vrab0006));
   // P_Set_Display(0, 0x0, 0, -rint64(Vrab0008), 0ui8, 255ui8, rint64(Vrab0007) + rint64(Vrab0005), Vrab0008);
  }

 // External-Included Dependencies Program's Main Functions
  int0 EIDP_LF2Enchanted(uint32 Vrab01, uint64 Vrab02) perfect
  {
   if(Enchanted->Vrab015 != Enchanted->Setting[0].Lang) L_Lang(0, L_Directory(Enchanted->Setting[0].Address) + (Enchanted->Setting[0].Lang == 0 ? "langEN" : (Enchanted->Setting[0].Lang == 1 ? "langID" : "langRU")) + ".txt"); Enchanted->Vrab015 = Enchanted->Setting[0].Lang;
   
   // Initialization
    if(Enchanted->Vrab001)
    {
     Enchanted->Vrab001 = false;
     Enchanted->Setting[0].Player.resize(2);
     Enchanted->Setting[0].Player[0].Name = "Mesujin"; Enchanted->Setting[0].Player[1].Name = "Kitty";
     Enchanted->Setting[0].Player[0].Type = 0;         Enchanted->Setting[0].Player[1].Type = 0;
     Enchanted->Setting[0].Player[0].Up   = 26;        Enchanted->Setting[0].Player[1].Up   = 15;
     Enchanted->Setting[0].Player[0].Left = 22;        Enchanted->Setting[0].Player[1].Left = 29;
     Enchanted->Setting[0].Player[0].Down = 43;        Enchanted->Setting[0].Player[1].Down = 14;
     Enchanted->Setting[0].Player[0].Right = 44;       Enchanted->Setting[0].Player[1].Right = 16;
     Enchanted->Setting[0].Player[0].Attack = 21;      Enchanted->Setting[0].Player[1].Attack = 11;
     Enchanted->Setting[0].Player[0].Defend = 40;      Enchanted->Setting[0].Player[1].Defend = 28;
     Enchanted->Setting[0].Player[0].Jump   = 41;      Enchanted->Setting[0].Player[1].Jump   = 30;
     Enchanted->Setting[0].Player[0].Command = 25;     Enchanted->Setting[0].Player[1].Command = 33;
     Enchanted->Setting_Load(); Enchanted->Setting_Save(); Enchanted->Setting[0].Fullscreen = Vrab0009;
     G_Adjust_Window(Enchanted->Setting[0].Width, Enchanted->Setting[0].Height, Enchanted->Setting[0].Fullscreen, "Little Fighter 2 v3.0");
     P_Set_Music(P_Load_Sound(L_Directory(Enchanted->Setting[0].Address + "Audio\\theme.wav")), (rxint32(Enchanted->Setting[0].Volume) / 100.0f) * Vrab0012, Vrab0013);

     // Language Load.
     {
      statics string Temp01 = L_Directory(Enchanted->Setting[0].Address);
      if(L_Exist(Temp01 + "lang.ini")) while(true)
      {
       std::ifstream File01(Temp01 + "lang.ini"); if(!File01.is_open()) break;
       insize Vrab03 = 0, Vrab04 = 0, Vrab05 = 0; string Temp02; 
       while(File01)
       {
        if(Vrab03 != 13){File01 >> Temp02;} else {Vrab03 = 1;} if(!File01) break; if(Temp02.at(0) == '#'){std::getline(File01, Temp02); continue;} if(Temp02.size() > 1) if(Temp02.at(0) == '/' && Temp02.at(1) == '/'){std::getline(File01, Temp02); continue;}
        switch(Vrab03)
        {
         case 0:
          if(Temp02 == "<text>"){Vrab03 = 1; Vrab04 = Enchanted->Font.size(); Enchanted->Font.resize(Vrab04 + 1); File01 >> Enchanted->Font[Vrab04].Address; continue;}
         break;
         case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
          if(Temp02 == "<text_end>") {Vrab03 = 0; continue;}

          if(Temp02.at(0) == '['){Vrab03 = 11; Vrab05 = Enchanted->Font[Vrab04].Shift.size(); Enchanted->Font[Vrab04].Shift.resize(Vrab05 + 1); statics insize Vrab06 = Temp02.size(); if(Vrab06 > 1){Temp02 = string(Temp02, 1, Vrab06 - 1);} else {continue;}}
          if(Vrab03 == 11) if(Temp02.at(0) == ']'){Vrab03 = 13; statics insize Vrab06 = Temp02.size(); if(Vrab06 > 1){Temp02 = string(Temp02, 1, Vrab06 - 1);} else {Vrab03 = 1;} continue;}
          if(Vrab03 == 11) if(Temp02.at(0) == 'c' || Temp02.at(0) == 'C'){if(Temp02.at(0) == 'c'){Enchanted->Font[Vrab04].Shift[Vrab05].c = true;} else {Enchanted->Font[Vrab04].Shift[Vrab05].C = true;} statics insize Vrab06 = Temp02.size(); if(Vrab06 > 1){Temp02 = string(Temp02, 1, Vrab06 - 1);} else {continue;}}
          if(Vrab03 == 11) {Vrab03 = 12; statics insize Vrab06 = Temp02.size(); insize Vrab07 = 0; while(Vrab06 != Vrab07){if(Temp02.at(Vrab07) == ',' || Temp02.at(Vrab07) == ']') break; Vrab07 += 1;} string Temp03; if(Vrab06 != Vrab07){Temp03 = string(Temp02, 0, Vrab07);} else {Temp03 = Temp02;} Enchanted->Font[Vrab04].Shift[Vrab05].x = L_Numbering(Temp03); if(Vrab06 - Vrab07 > 1){insize Vrab08 = (Temp02.at(Vrab07) == ']') ? 0 : 1; Temp02 = string(Temp02, Vrab07 + Vrab08, Vrab06 - Vrab07 - Vrab08);} else {continue;}}
          if(Vrab03 == 12) if(Temp02.at(0) == ']'){Vrab03 = 13; statics insize Vrab06 = Temp02.size(); if(Vrab06 > 1){Temp02 = string(Temp02, 1, Vrab06 - 1);} else {Vrab03 = 1;} continue;}
          if(Vrab03 == 12) {Vrab03 = 11; statics insize Vrab06 = Temp02.size(); insize Vrab07 = 0; while(Vrab06 != Vrab07){if(Temp02.at(Vrab07) == ',' || Temp02.at(Vrab07) == ']') break; Vrab07 += 1;} string Temp03; if(Vrab06 != Vrab07){Temp03 = string(Temp02, 0, Vrab07);} else {Temp03 = Temp02;} Enchanted->Font[Vrab04].Shift[Vrab05].y = L_Numbering(Temp03); if(Vrab06 - Vrab07 > 1){insize Vrab08 = (Temp02.at(Vrab07) == ']') ? 0 : 1; Temp02 = string(Temp02, Vrab07 + Vrab08, Vrab06 - Vrab07 - Vrab08);} else {continue;}}
          if(Vrab03 == 11) if(Temp02.at(0) == ']'){Vrab03 = 13; statics insize Vrab06 = Temp02.size(); if(Vrab06 > 1){Temp02 = string(Temp02, 1, Vrab06 - 1);} else {Vrab03 = 1;} continue;}

          if(Temp02 == "x:")     {File01 >> Temp02; Enchanted->Font[Vrab04].x = L_Numbering(Temp02); continue;}
          if(Temp02 == "y:")     {File01 >> Temp02; Enchanted->Font[Vrab04].y = L_Numbering(Temp02); continue;}
          if(Temp02 == "w:")     {File01 >> Temp02; Enchanted->Font[Vrab04].w = L_Numbering(Temp02); continue;}
          if(Temp02 == "h:")     {File01 >> Temp02; Enchanted->Font[Vrab04].h = L_Numbering(Temp02); continue;}
          if(Temp02 == "row:")   {File01 >> Temp02; Enchanted->Font[Vrab04].row = L_Numbering(Temp02); continue;}
          if(Temp02 == "col:")   {File01 >> Temp02; Enchanted->Font[Vrab04].col = L_Numbering(Temp02); continue;}
          if(Temp02 == "type:")  {File01 >> Temp02; Enchanted->Font[Vrab04].type = L_Numbering(Temp02); continue;}
          if(Temp02 == "num:")   {File01 >> Temp02; Enchanted->Font[Vrab04].num[0] = L_Numbering(Temp02); Vrab03 = 2; continue;}
          if(Temp02 == "sizex:") {File01 >> Temp02; Enchanted->Font[Vrab04].sizex = L_Numbering(Temp02); continue;}
          if(Temp02 == "sizey:") {File01 >> Temp02; Enchanted->Font[Vrab04].sizey = L_Numbering(Temp02); continue;}
          if(Temp02 == "shiftx:"){File01 >> Temp02; Enchanted->Font[Vrab04].shiftx = L_Numbering(Temp02); continue;}
          if(Temp02 == "shifty:"){File01 >> Temp02; Enchanted->Font[Vrab04].shifty = L_Numbering(Temp02); continue;}
          if(Temp02 == "caps:")  {File01 >> Temp02; Enchanted->Font[Vrab04].caps = L_Numbering(Temp02); continue;}
          if(Temp02 == "caps2:") {File01 >> Temp02; Enchanted->Font[Vrab04].caps2 = L_Numbering(Temp02); continue;}
          if(Temp02 == "stx:")   {File01 >> Temp02; Enchanted->Font[Vrab04].stx = L_Numbering(Temp02); continue;}
          if(Temp02 == "sty:")   {File01 >> Temp02; Enchanted->Font[Vrab04].sty = L_Numbering(Temp02); continue;}

          if(Vrab03 == 2) {Vrab03 = 3; Enchanted->Font[Vrab04].num[1] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 3) {Vrab03 = 4; Enchanted->Font[Vrab04].num[2] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 4) {Vrab03 = 5; Enchanted->Font[Vrab04].num[3] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 5) {Vrab03 = 6; Enchanted->Font[Vrab04].num[4] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 6) {Vrab03 = 7; Enchanted->Font[Vrab04].num[5] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 7) {Vrab03 = 8; Enchanted->Font[Vrab04].num[6] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 8) {Vrab03 = 9; Enchanted->Font[Vrab04].num[7] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 9) {Vrab03 = 10; Enchanted->Font[Vrab04].num[8] = L_Numbering(Temp02); continue;}
          if(Vrab03 == 10){Vrab03 = 1; Enchanted->Font[Vrab04].num[9] = L_Numbering(Temp02); continue;}
         break;
         default: break;
        }
       }
       break;
      }
      insize Vrab03 = Enchanted->Font.size(); while(Vrab03 != 0)
      {Vrab03 -= 1; Enchanted->Font[Vrab03].Pic_Index = P_Load_Pic(Temp01 + Enchanted->Font[Vrab03].Address, Enchanted->Font[Vrab03].x, Enchanted->Font[Vrab03].y, (ruint32(Enchanted->Font[Vrab03].w) + 1) * ruint32(Enchanted->Font[Vrab03].row), (ruint32(Enchanted->Font[Vrab03].h) + 1) * ruint32(Enchanted->Font[Vrab03].col));}
     }

     // Background(s) Load.
     {
      statics string Temp01 = L_Directory(Enchanted->Setting[0].Address + Enchanted->Setting[0].Address_Interface), Temp02 = ".BMP", Temp03 = ".JPG";
      int1 Vrab03 = true; insize Vrab04 = 0;
      while(Vrab03)
      {
       Vrab04 += 1;
       Enchanted->Vect002.push_back(P_Load_Pic(Temp01 + "BACK" + std::to_string(Vrab04) + Temp02, 0ui32, 0ui32, ruint32(-1), 550));
       Enchanted->Vect003.push_back(false); Vrab03 = Enchanted->Vect002[Vrab04 - 1] != rinsize(-1);
       if(!Vrab03)
       {
        Enchanted->Vect002[Vrab04 - 1] = P_Load_Pic(Temp01 + "BACK" + std::to_string(Vrab04) + Temp03, 0ui32, 0ui32, ruint32(-1), 550);
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
      statics string Temp01 = L_Directory(Enchanted->Setting[0].Address + Enchanted->Setting[0].Address_Interface), Temp02 = ".bmp";
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "WORDS" + Temp02, 0, 0, 255, 255));         // Index : 0
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "WORDS2" + Temp02, 0, 0, 255, 255));         // Index : 1
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "WORDS3" + Temp02, 0, 0, 255, 255));         // Index : 2
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "WORDS4" + Temp02, 0, 0, 255, 255));         // Index : 3
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "WORDS5" + Temp02, 0, 0, 255, 255));         // Index : 4
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "WORDS6" + Temp02, 0, 0, 255, 255));         // Index : 5
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 278, 260, 12, 12));        // Index : 6 (Info Bar Top-Left Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 291, 260, 12, 12));        // Index : 7 (Info Bar Top-Right Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 278, 273, 12, 12));        // Index : 8 (Info Bar Bottom-Left Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 291, 273, 12, 12));        // Index : 9 (Info Bar Bottom-Right Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 290, 260, 1, 3));          // Index : 10 (Info Bar Horizontal Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 278, 272, 3, 1));          // Index : 11 (Info Bar Vertical Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 801, 382, 200, 200));      // Index : 12 (Info Bar Area)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "CURSOR1" + Temp02));                        // Index : 13
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "CURSOR2" + Temp02));                        // Index : 14
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 0, 0, 800, 37));           // Index : 15 (Copyright)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 0, 38, 490, 79));          // Index : 16 (Title)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 38, 154, 169));       // Index : 17 (Main Buttons)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 646, 38, 154, 18));        // Index : 18 (Main Buttons - Game Start)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 646, 67, 154, 20));        // Index : 19 (Main Buttons - Network Game)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 646, 98, 154, 20));        // Index : 20 (Main Buttons - General Settings)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 646, 129, 154, 20));       // Index : 21 (Main Buttons - Control Settings)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 646, 161, 154, 19));       // Index : 22 (Main Buttons - Recording Info)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 646, 191, 154, 16));       // Index : 23 (Main Buttons - Official Fansite)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 0, 118, 151, 26));         // Index : 24 (Ok Button)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 0, 145, 151, 26));         // Index : 25 (Ok Button)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 152, 118, 151, 26));       // Index : 26 (Cancel Button)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 152, 145, 151, 26));       // Index : 27 (Cancel Button)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 801, 0, 704, 381));        // Index : 28 (Control Setting Menu)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 587, 300, 106, 91));       // Index : 29 (Input - Keyboard)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 694, 208, 106, 91));       // Index : 30 (Input - Joy1)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 587, 208, 106, 91));       // Index : 31 (Input - Joy2)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 694, 392, 106, 91));       // Index : 32 (Input - Joy3)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 694, 300, 106, 91));       // Index : 33 (Input - Joy4)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 304, 118, 186, 169));      // Index : 34 (Game Buttons)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 304, 288, 186, 14));       // Index : 35 (Game Buttons - Versus)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 304, 319, 186, 18));       // Index : 36 (Game Buttons - Stage)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 304, 349, 186, 19));       // Index : 37 (Game Buttons - Championship)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 304, 380, 186, 15));       // Index : 38 (Game Buttons - Battle)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 304, 411, 186, 19));       // Index : 39 (Game Buttons - Recording Playback)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 304, 443, 186, 14));       // Index : 40 (Game Buttons - Return)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1506, 0, 744, 437));       // Index : 41 (Character Selection)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1264, 382, 120, 66));      // Index : 42 (Character Selection - Press Attack to Join)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1385, 382, 120, 66));      // Index : 43 (Character Selection - Press Attack to Join2)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1001, 382, 120, 120));     // Index : 44 (Character Selection - Random)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 535, 208, 51, 58));        // Index : 45 (Character Selection - Counter - 5)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 535, 267, 51, 58));        // Index : 46 (Character Selection - Counter - 4)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 535, 326, 51, 58));        // Index : 47 (Character Selection - Counter - 3)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 590, 392, 51, 58));        // Index : 48 (Character Selection - Counter - 2)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 642, 392, 51, 58));        // Index : 49 (Character Selection - Counter - 1)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 0, 172, 303, 87));         // Index : 50 (Character Selection - Computer Player)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 208, 6, 10));         // Index : 51 (Character Selection - Computer Player - 0)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 498, 208, 6, 10));         // Index : 52 (Character Selection - Computer Player - 1)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 505, 208, 6, 10));         // Index : 53 (Character Selection - Computer Player - 2)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 512, 208, 6, 10));         // Index : 54 (Character Selection - Computer Player - 3)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 519, 208, 6, 10));         // Index : 55 (Character Selection - Computer Player - 4)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 526, 208, 6, 10));         // Index : 56 (Character Selection - Computer Player - 5)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 219, 6, 10));         // Index : 57 (Character Selection - Computer Player - 6)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 498, 219, 6, 10));         // Index : 58 (Character Selection - Computer Player - 7)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 505, 219, 6, 10));         // Index : 59 (Character Selection - Computer Player - 0 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 512, 219, 6, 10));         // Index : 60 (Character Selection - Computer Player - 1 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 519, 219, 6, 10));         // Index : 61 (Character Selection - Computer Player - 2 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 526, 219, 6, 10));         // Index : 62 (Character Selection - Computer Player - 3 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 230, 6, 10));         // Index : 63 (Character Selection - Computer Player - 4 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 498, 230, 6, 10));         // Index : 64 (Character Selection - Computer Player - 5 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 505, 230, 6, 10));         // Index : 65 (Character Selection - Computer Player - 6 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 512, 230, 6, 10));         // Index : 66 (Character Selection - Computer Player - 7 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 0, 260, 264, 168));        // Index : 67 (Character Selection - Menu)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 208, 1, 1));          // Index : 68 (Color - 1) (#10206C)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 210, 1, 1));          // Index : 69 (Color - 2)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 212, 1, 1));          // Index : 70 (Color - 3)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 214, 1, 1));          // Index : 71 (Color - 4)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 216, 1, 1));          // Index : 72 (Color - 5)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 218, 1, 1));          // Index : 73 (Color - 6)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 220, 1, 1));          // Index : 74 (Color - 7)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 222, 1, 1));          // Index : 75 (Color - 8)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 224, 1, 1));          // Index : 76 (Color - 9)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 226, 1, 1));          // Index : 77 (Color - 10)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 228, 1, 1));          // Index : 78 (Color - 11)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 230, 1, 1));          // Index : 79 (Color - 12)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 232, 1, 1));          // Index : 80 (Color - 13)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 234, 1, 1));          // Index : 81 (Color - 14)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 236, 1, 1));          // Index : 82 (Color - 15)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 533, 238, 1, 1));          // Index : 83 (Color - 16)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 307, 21, 21));        // Index : 84 (Input - Attack)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 307, 21, 21));        // Index : 85 (Input - Attack Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 285, 21, 21));        // Index : 86 (Input - Defend)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 329, 21, 21));        // Index : 87 (Input - Defend Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 285, 21, 21));        // Index : 88 (Input - Jump)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 329, 21, 21));        // Index : 89 (Input - Jump Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 241, 21, 21));        // Index : 90 (Input - Up)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 351, 21, 21));        // Index : 91 (Input - Up Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 241, 21, 21));        // Index : 92 (Input - Left)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 351, 21, 21));        // Index : 93 (Input - Left Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 263, 21, 21));        // Index : 94 (Input - Down)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 373, 21, 21));        // Index : 95 (Input - Down Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 263, 21, 21));        // Index : 96 (Input - Right)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 513, 373, 21, 21));        // Index : 97 (Input - Right Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 395, 66, 17));        // Index : 98 (Setting - Graphic)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 413, 66, 17));        // Index : 99 (Setting - Audio)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 491, 431, 66, 17));        // Index : 100 (Setting - Platform)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 2251, 0, 704, 338));       // Index : 101 (Recording Info)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 456, 484, 344, 23));       // Index : 102 (Recording Info - Button)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 284, 286, 19, 19));        // Index : 103 (Check)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 284, 306, 19, 19));        // Index : 104 (Check - Off)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 265, 286, 18, 18));        // Index : 105 (Info - Question)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 265, 305, 18, 18));        // Index : 106 (Info - Important)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 519, 230, 6, 10));         // Index : 107 (Character Selection - Computer Player - 8 Active)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 286, 326, 8, 8));          // Index : 108 (Menu Bar Top-Left Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 295, 326, 8, 8));          // Index : 109 (Menu Bar Top-Right Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 286, 335, 8, 8));          // Index : 110 (Menu Bar Bottom-Left Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 295, 335, 8, 8));          // Index : 111 (Menu Bar Bottom-Right Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 294, 326, 1, 8));          // Index : 112 (Menu Bar Horizontal-Top Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 286, 334, 8, 1));          // Index : 113 (Menu Bar Vertical-Left Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 294, 335, 1, 8));          // Index : 114 (Menu Bar Horizontal-Bottom Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 295, 334, 8, 1));          // Index : 115 (Menu Bar Vertical-Right Corner)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 294, 334, 1, 1));          // Index : 116 (Menu Bar Area)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 2956, 0, 169, 324));       // Index : 117 (Meta Character Selection - Char View)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 284, 326, 1, 1));          // Index : 118 (Menu Bar Color - 1)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 284, 328, 1, 1));          // Index : 119 (Menu Bar Color - 2)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 284, 330, 1, 1));          // Index : 120 (Menu Bar Color - 3)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 284, 332, 1, 1));          // Index : 121 (Menu Bar Color - 4)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 284, 334, 1, 1));          // Index : 122 (Menu Bar Color - 5)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU2" + Temp02, 0, 0, 665, 900));          // Index : 123 (General Setting - Scrolling Display)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1506, 438, 200, 50));      // Index : 124 (Player Info - 1)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1707, 438, 200, 50));      // Index : 125 (Player Info - 2)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1908, 438, 200, 50));      // Index : 126 (Player Info - 3)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 2109, 438, 200, 50));      // Index : 127 (Player Info - 4)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1506, 489, 200, 50));      // Index : 128 (Player Info - 5)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1707, 489, 200, 50));      // Index : 129 (Player Info - 6)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1908, 489, 200, 50));      // Index : 130 (Player Info - 7)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 2109, 489, 200, 50));      // Index : 131 (Player Info - 8)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1506, 540, 200, 50));      // Index : 132 (Player Info - 9)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1707, 540, 200, 50));      // Index : 133 (Player Info - 10)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 1908, 540, 200, 50));      // Index : 134 (Player Info - 11)
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "MENU1" + Temp02, 2109, 540, 200, 50));      // Index : 135 (Player Info - 12)
     }

     // Sound Load.
     {
     
     }
     
     Enchanted->Vect001.push_back(0);
    } else
    {
     P_Control_Music(P_Load_Sound(L_Directory(Enchanted->Setting[0].Address + "Audio\\theme.wav")), (rxint32(Enchanted->Setting[0].Volume) / 100.0f) * Vrab0012, Vrab0013);
    }

   // Applying Setting
    {
     
    }

   // Inputs
    struct Strc01 {int64 Vrab001, Vrab002; int8 Vrab003; int64 Vrab004, Vrab005;};
    remains std::vector < int8 > Vect01;                 // Overall Input.
    remains std::vector < std::vector < int8 > > Vect02; // Player's Input.
    remains std::vector < Strc01 > Vect03;               // Touch/Mouse Input.
    {
     Vect01.resize(8); std::vector < int1 > Vect04(8, false);
     insize Vrab03 = Enchanted->Setting[0].Player.size(); Vect02.resize(Vrab03);
     while(Vrab03 != 0)
     {
      Vrab03 -= 1; Vect02[Vrab03].resize(8);
      statics int1 Vrab04 = L_Input(Enchanted->Setting[0].Player[Vrab03].Up) > 0;
      statics int1 Vrab05 = L_Input(Enchanted->Setting[0].Player[Vrab03].Left) > 0;
      statics int1 Vrab06 = L_Input(Enchanted->Setting[0].Player[Vrab03].Down) > 0;
      statics int1 Vrab07 = L_Input(Enchanted->Setting[0].Player[Vrab03].Right) > 0;
      statics int1 Vrab08 = L_Input(Enchanted->Setting[0].Player[Vrab03].Attack) > 0;
      statics int1 Vrab09 = L_Input(Enchanted->Setting[0].Player[Vrab03].Defend) > 0;
      statics int1 Vrab10 = L_Input(Enchanted->Setting[0].Player[Vrab03].Jump) > 0;
      statics int1 Vrab11 = L_Input(Enchanted->Setting[0].Player[Vrab03].Command) > 0;
      statics int1 Vrab12 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Up) > 0;
      statics int1 Vrab13 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Left) > 0;
      statics int1 Vrab14 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Down) > 0;
      statics int1 Vrab15 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Right) > 0;
      statics int1 Vrab16 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Attack) > 0;
      statics int1 Vrab17 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Defend) > 0;
      statics int1 Vrab18 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Jump) > 0;
      statics int1 Vrab19 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Command) > 0;
      if(Vect02[Vrab03][0] != 0){Vect02[Vrab03][0] += 1; if(Vect02[Vrab03][0] == 100) Vect02[Vrab03][0] = 70;} if(Vrab04 || Vrab12){if(Vect02[Vrab03][0] <= 0) Vect02[Vrab03][0] = 1;} else {if(Vect02[Vrab03][0] > 0) Vect02[Vrab03][0] = -100;} if(Vect02[Vrab03][0] > 0) Vect04[0] = true;
      if(Vect02[Vrab03][1] != 0){Vect02[Vrab03][1] += 1; if(Vect02[Vrab03][1] == 100) Vect02[Vrab03][1] = 70;} if(Vrab05 || Vrab13){if(Vect02[Vrab03][1] <= 0) Vect02[Vrab03][1] = 1;} else {if(Vect02[Vrab03][1] > 0) Vect02[Vrab03][1] = -100;} if(Vect02[Vrab03][1] > 0) Vect04[1] = true;
      if(Vect02[Vrab03][2] != 0){Vect02[Vrab03][2] += 1; if(Vect02[Vrab03][2] == 100) Vect02[Vrab03][2] = 70;} if(Vrab06 || Vrab14){if(Vect02[Vrab03][2] <= 0) Vect02[Vrab03][2] = 1;} else {if(Vect02[Vrab03][2] > 0) Vect02[Vrab03][2] = -100;} if(Vect02[Vrab03][2] > 0) Vect04[2] = true;
      if(Vect02[Vrab03][3] != 0){Vect02[Vrab03][3] += 1; if(Vect02[Vrab03][3] == 100) Vect02[Vrab03][3] = 70;} if(Vrab07 || Vrab15){if(Vect02[Vrab03][3] <= 0) Vect02[Vrab03][3] = 1;} else {if(Vect02[Vrab03][3] > 0) Vect02[Vrab03][3] = -100;} if(Vect02[Vrab03][3] > 0) Vect04[3] = true;
      if(Vect02[Vrab03][4] != 0){Vect02[Vrab03][4] += 1; if(Vect02[Vrab03][4] == 100) Vect02[Vrab03][4] = 70;} if(Vrab08 || Vrab16){if(Vect02[Vrab03][4] <= 0) Vect02[Vrab03][4] = 1;} else {if(Vect02[Vrab03][4] > 0) Vect02[Vrab03][4] = -100;} if(Vect02[Vrab03][4] > 0) Vect04[4] = true;
      if(Vect02[Vrab03][5] != 0){Vect02[Vrab03][5] += 1; if(Vect02[Vrab03][5] == 100) Vect02[Vrab03][5] = 70;} if(Vrab09 || Vrab17){if(Vect02[Vrab03][5] <= 0) Vect02[Vrab03][5] = 1;} else {if(Vect02[Vrab03][5] > 0) Vect02[Vrab03][5] = -100;} if(Vect02[Vrab03][5] > 0) Vect04[5] = true;
      if(Vect02[Vrab03][6] != 0){Vect02[Vrab03][6] += 1; if(Vect02[Vrab03][6] == 100) Vect02[Vrab03][6] = 70;} if(Vrab10 || Vrab18){if(Vect02[Vrab03][6] <= 0) Vect02[Vrab03][6] = 1;} else {if(Vect02[Vrab03][6] > 0) Vect02[Vrab03][6] = -100;} if(Vect02[Vrab03][6] > 0) Vect04[6] = true;
      if(Vect02[Vrab03][7] != 0){Vect02[Vrab03][7] += 1; if(Vect02[Vrab03][7] == 100) Vect02[Vrab03][7] = 70;} if(Vrab11 || Vrab19){if(Vect02[Vrab03][7] <= 0) Vect02[Vrab03][7] = 1;} else {if(Vect02[Vrab03][7] > 0) Vect02[Vrab03][7] = -100;} if(Vect02[Vrab03][7] > 0) Vect04[7] = true;
     }

     if(L_Input(Vrab0018) > 0) Vect04[0] = true; if(L_Input(Vrab0024) > 0) Vect04[0] = true;
     if(L_Input(Vrab0019) > 0) Vect04[1] = true; if(L_Input(Vrab0025) > 0) Vect04[1] = true;
     if(L_Input(Vrab0020) > 0) Vect04[2] = true; if(L_Input(Vrab0026) > 0) Vect04[2] = true;
     if(L_Input(Vrab0021) > 0) Vect04[3] = true; if(L_Input(Vrab0027) > 0) Vect04[3] = true;
     if(L_Input(Vrab0016) > 0) Vect04[4] = true; if(L_Input(Vrab0022) > 0) Vect04[4] = true;
     if(L_Input(Vrab0017) > 0) Vect04[5] = true; if(L_Input(Vrab0023) > 0) Vect04[5] = true;
     if(Vect01[0] != 0){Vect01[0] += 1; if(Vect01[0] == 100) Vect01[0] = 70;} if(Vect04[0]){if(Vect01[0] <= 0) Vect01[0] = 1;} else {if(Vect01[0] > 0) Vect01[0] = -100;}
     if(Vect01[1] != 0){Vect01[1] += 1; if(Vect01[1] == 100) Vect01[1] = 70;} if(Vect04[1]){if(Vect01[1] <= 0) Vect01[1] = 1;} else {if(Vect01[1] > 0) Vect01[1] = -100;}
     if(Vect01[2] != 0){Vect01[2] += 1; if(Vect01[2] == 100) Vect01[2] = 70;} if(Vect04[2]){if(Vect01[2] <= 0) Vect01[2] = 1;} else {if(Vect01[2] > 0) Vect01[2] = -100;}
     if(Vect01[3] != 0){Vect01[3] += 1; if(Vect01[3] == 100) Vect01[3] = 70;} if(Vect04[3]){if(Vect01[3] <= 0) Vect01[3] = 1;} else {if(Vect01[3] > 0) Vect01[3] = -100;}
     if(Vect01[4] != 0){Vect01[4] += 1; if(Vect01[4] == 100) Vect01[4] = 70;} if(Vect04[4]){if(Vect01[4] <= 0) Vect01[4] = 1;} else {if(Vect01[4] > 0) Vect01[4] = -100;}
     if(Vect01[5] != 0){Vect01[5] += 1; if(Vect01[5] == 100) Vect01[5] = 70;} if(Vect04[5]){if(Vect01[5] <= 0) Vect01[5] = 1;} else {if(Vect01[5] > 0) Vect01[5] = -100;}
     if(Vect01[6] != 0){Vect01[6] += 1; if(Vect01[6] == 100) Vect01[6] = 70;} if(Vect04[6]){if(Vect01[6] <= 0) Vect01[6] = 1;} else {if(Vect01[6] > 0) Vect01[6] = -100;}
     if(Vect01[7] != 0){Vect01[7] += 1; if(Vect01[7] == 100) Vect01[7] = 70;} if(Vect04[7]){if(Vect01[7] <= 0) Vect01[7] = 1;} else {if(Vect01[7] > 0) Vect01[7] = -100;}

     Vect03.resize(3);
     if(Vect03[0].Vrab003 != 0){Vect03[0].Vrab003 += 1; if(Vect03[0].Vrab003 == 100) Vect03[0].Vrab003 = 70;} if(Input->MOUS_Left > 0){if(Vect03[0].Vrab003 <= 0){Vect03[0].Vrab003 = 1; Vect03[0].Vrab001 = Input->MOUS_X; Vect03[0].Vrab002 = Input->MOUS_Y;} Vect03[0].Vrab004 = Input->MOUS_X; Vect03[0].Vrab005 = Input->MOUS_Y;} else {if(Vect03[0].Vrab003 > 0) Vect03[0].Vrab003 = -100;}
     if(Vect03[1].Vrab003 != 0){Vect03[1].Vrab003 += 1; if(Vect03[1].Vrab003 == 100) Vect03[1].Vrab003 = 70;} if(Input->MOUS_Left > 0){if(Vect03[1].Vrab003 <= 0){Vect03[1].Vrab003 = 1; Vect03[1].Vrab001 = Input->MOUS_X; Vect03[1].Vrab002 = Input->MOUS_Y;} Vect03[1].Vrab004 = Input->MOUS_X; Vect03[1].Vrab005 = Input->MOUS_Y;} else {if(Vect03[1].Vrab003 > 0) Vect03[1].Vrab003 = -100;}
     if(Vect03[2].Vrab003 != 0){Vect03[2].Vrab003 += 1; if(Vect03[2].Vrab003 == 100) Vect03[2].Vrab003 = 70;} if(Input->MOUS_Left > 0){if(Vect03[2].Vrab003 <= 0){Vect03[2].Vrab003 = 1; Vect03[2].Vrab001 = Input->MOUS_X; Vect03[2].Vrab002 = Input->MOUS_Y;} Vect03[2].Vrab004 = Input->MOUS_X; Vect03[2].Vrab005 = Input->MOUS_Y;} else {if(Vect03[2].Vrab003 > 0) Vect03[2].Vrab003 = -100;} 
    }

    if(Enchanted->Setting[0].Menu)
    {
     statics int64 Vrab03 = L_Rounding64(rxint64(Vrab0005) / 2.0); statics int64 Vrab04 = L_Rounding64(rxint64(Vrab0006) / 2.0);
     if(Enchanted->Data.size() < 1) Enchanted->Data.resize(1);
     Enchanted->Data[0].INT32.resize(1); Enchanted->Data[0].STRING.resize(1);
     Enchanted->Typing(Enchanted->Data[0].STRING[0]);
     Enchanted->Print_Text(0, 20, 0, Enchanted->Data[0].STRING[0], 800);
     Enchanted->Data[0].INT32[0] += Vrab0003;
    } else
    {
     if(Enchanted->Data.size() < 1) Enchanted->Data.resize(1);
     if(Enchanted->Data[0].INT1.size() < 3) Enchanted->Data[0].INT1.resize(3);
     if(Enchanted->Data[0].INT64.size() < 6){Enchanted->Data[0].INT64.resize(6); Enchanted->Data[0].INT64[5] = rinsize(-1);}
     if(Enchanted->Data[0].XINT64.size() < 6) Enchanted->Data[0].XINT64.resize(6);
     if(Enchanted->Data[0].INSIZE.size() < 1) Enchanted->Data[0].INSIZE.resize(1);
     if(Enchanted->Data[0].STRING.size() < 2) Enchanted->Data[0].STRING.resize(2);

     //if(Vect02[0][0] > 0) Enchanted->Data[0].INT64[1] -= 1;
     //if(Vect02[0][2] > 0) Enchanted->Data[0].INT64[1] += 1;
     //if(Vect02[1][1] > 0) Enchanted->Data[0].INT64[0] -= 1;
     //if(Vect02[1][3] > 0) Enchanted->Data[0].INT64[0] += 1;
     //if(Vect02[0][4] > 0) Enchanted->Data[0].INT64[2] -= 1; if(Enchanted->Data[0].INT64[2] == -1) Enchanted->Data[0].INT64[2] = 359;
     //if(Vect02[0][5] > 0) Enchanted->Data[0].INT64[2] += 1; if(Enchanted->Data[0].INT64[2] == 361) Enchanted->Data[0].INT64[2] = 1;
     //if(Vect02[0][6] > 0) Enchanted->Data[0].INT64[4] -= 1;
     //if(Vect02[0][7] > 0) Enchanted->Data[0].INT64[4] += 1; if(Enchanted->Data[0].INT64[4] < 0) Enchanted->Data[0].INT64[4] = 0; if(Enchanted->Data[0].INT64[4] > 100) Enchanted->Data[0].INT64[4] = 100;

     Enchanted->Data[0].INSIZE[0] = 0;
     if(L_Input(Vrab0016) == 1 || L_Input(Vrab0022) == 1)
     if(Enchanted->Data[0].INT1[1])
     {
      Enchanted->Data[0].STRING[1] = Enchanted->Data[0].STRING[0];
      Enchanted->Data[0].STRING[0] = "";
      Enchanted->Data[0].INT1[1] = false; Enchanted->Data[0].INT1[2] = true;
     } else {Enchanted->Data[0].INT1[1] = true;}
     if(Enchanted->Data[0].INT1[1]) Enchanted->Typing(Enchanted->Data[0].STRING[0]);

     switch(Enchanted->Setting[0].Engine)
     {
      case 1:
      if(!Enchanted->Data[0].INT1[0]) Enchanted->Data[0].INT1[0] = Enchanted->Engine1->Begin(L_Directory(Enchanted->Setting[0].Address), Enchanted->Setting[0].Address_Game);
      if(!Enchanted->Data[0].INT1[1]) Enchanted->Engine1->Keys(Vect02);
      if(Enchanted->Data[0].INT1[2]){if(Enchanted->Data[0].STRING[1].size() > 0) if(Enchanted->Data[0].STRING[1][0] == '/') Enchanted->Engine1->Order(string(Enchanted->Data[0].STRING[1], 1, Enchanted->Data[0].STRING[1].size() - 1), Enchanted->Data[0].INSIZE[0]); Enchanted->Data[0].INT1[2] = false;}
      {
       xint64* Vrab03 = Enchanted->Engine1->Main(Enchanted->Data[0].INSIZE[0]);

       // Auto Start
       {
        if(Enchanted->Engine1->Loaded != 3) Enchanted->Engine1->Load();
        if(!Enchanted->Engine1->Section[Enchanted->Data[0].INSIZE[0]].Ready)
        {
         Enchanted->Engine1->Start(0, 1, 0, 1500, Enchanted->Data[0].INSIZE[0]);
         Enchanted->Engine1->Set(0, 60, 1, "Mesujin", Enchanted->Data[0].INSIZE[0]);
         Enchanted->Engine1->Set(1, 51, 2, "Kitty", Enchanted->Data[0].INSIZE[0]);
        }
       }

       // Camera Movement
       {
        statics xint64   Vrab05 = 0.5, Vrab06 = 0.085, Vrab07 = 40; // Base Velocity, Additional Velocity by Distance, Top Speed.
        statics xint64*  Vrab08 = L_Degree(Enchanted->Data[0].XINT64[0], Enchanted->Data[0].XINT64[1], 0, Vrab03[0], Vrab03[1], 0, false); // Vector
        xint64  Vrab09 = Vrab05 + (Vrab06 * L_Distance(Enchanted->Data[0].XINT64[0], Enchanted->Data[0].XINT64[1], Vrab03[0], Vrab03[1])); // Velocity
        xint64  Vrab10 = Vrab09 * Vrab08[0]; // X-Velocity
        xint64  Vrab11 = Vrab09 * Vrab08[1]; // Y-Velocity
        statics xint64   Vrab12 = Vrab07 * Vrab08[0]; // X-Top Speed
        statics xint64   Vrab13 = Vrab07 * Vrab08[1]; // Y-Top Speed

        statics xint64   Vrab14 = 4, Vrab15 = -4; // Accelerate, Deccelerate
        statics xint64   Vrab16 = Vrab14 * Vrab08[0]; // X-Accelerate
        statics xint64   Vrab17 = Vrab14 * Vrab08[1]; // Y-Accelerate
        statics xint64   Vrab18 = Vrab15 * Vrab08[0]; // X-Deccelerate
        statics xint64   Vrab19 = Vrab15 * Vrab08[1]; // Y-Daccelerate
        statics xint64   Vrab20 = (((Vrab14 < 0) ? (-Vrab14) : Vrab14) + ((Vrab16 < 0) ? (-Vrab16) : Vrab16)) / 2.0;

        if(Vrab08[0] < 0)
        {
         if(Vrab10 < Vrab12) Vrab10 = Vrab12;
         if(Enchanted->Data[0].XINT64[2] > Vrab10) if(Enchanted->Data[0].XINT64[2] + Vrab16 < Vrab10){Enchanted->Data[0].XINT64[2] = Vrab10;} else {Enchanted->Data[0].XINT64[2] += Vrab16;}
         if(Enchanted->Data[0].XINT64[2] < Vrab10) if(Enchanted->Data[0].XINT64[2] + Vrab18 > Vrab10){Enchanted->Data[0].XINT64[2] = Vrab10;} else {Enchanted->Data[0].XINT64[2] += Vrab18;}
        }
        if(Vrab08[0] > 0) 
        { 
         if(Vrab10 > Vrab12) Vrab10 = Vrab12;
         if(Enchanted->Data[0].XINT64[2] < Vrab10) if(Enchanted->Data[0].XINT64[2] + Vrab16 > Vrab10){Enchanted->Data[0].XINT64[2] = Vrab10;} else {Enchanted->Data[0].XINT64[2] += Vrab16;}
         if(Enchanted->Data[0].XINT64[2] > Vrab10) if(Enchanted->Data[0].XINT64[2] + Vrab18 < Vrab10){Enchanted->Data[0].XINT64[2] = Vrab10;} else {Enchanted->Data[0].XINT64[2] += Vrab18;}
        }
        if(Vrab08[0] == 0)
        {
         if(Enchanted->Data[0].XINT64[2] < 0) if(Enchanted->Data[0].XINT64[2] + Vrab20 > 0){Enchanted->Data[0].XINT64[2] = 0;} else {Enchanted->Data[0].XINT64[2] += Vrab20;}
         if(Enchanted->Data[0].XINT64[2] > 0) if(Enchanted->Data[0].XINT64[2] - Vrab20 < 0){Enchanted->Data[0].XINT64[2] = 0;} else {Enchanted->Data[0].XINT64[2] -= Vrab20;}
        }
        if(Vrab08[1] < 0)
        {
         if(Vrab11 < Vrab13) Vrab11 = Vrab13;
         if(Enchanted->Data[0].XINT64[3] > Vrab11) if(Enchanted->Data[0].XINT64[3] + Vrab17 < Vrab11){Enchanted->Data[0].XINT64[3] = Vrab11;} else {Enchanted->Data[0].XINT64[3] += Vrab17;}
         if(Enchanted->Data[0].XINT64[3] < Vrab11) if(Enchanted->Data[0].XINT64[3] + Vrab19 > Vrab11){Enchanted->Data[0].XINT64[3] = Vrab11;} else {Enchanted->Data[0].XINT64[3] += Vrab19;}
        }
        if(Vrab08[1] > 0)
        {
         if(Vrab11 > Vrab13) Vrab11 = Vrab13;
         if(Enchanted->Data[0].XINT64[3] < Vrab11) if(Enchanted->Data[0].XINT64[3] + Vrab17 > Vrab11){Enchanted->Data[0].XINT64[3] = Vrab11;} else {Enchanted->Data[0].XINT64[3] += Vrab17;}
         if(Enchanted->Data[0].XINT64[3] > Vrab11) if(Enchanted->Data[0].XINT64[3] + Vrab19 < Vrab11){Enchanted->Data[0].XINT64[3] = Vrab11;} else {Enchanted->Data[0].XINT64[3] += Vrab19;}
        }
        if(Vrab08[1] == 0)
        {
         if(Enchanted->Data[0].XINT64[3] < 0) if(Enchanted->Data[0].XINT64[3] + Vrab20 > 0){Enchanted->Data[0].XINT64[3] = 0;} else {Enchanted->Data[0].XINT64[3] += Vrab20;}
         if(Enchanted->Data[0].XINT64[3] > 0) if(Enchanted->Data[0].XINT64[3] - Vrab20 < 0){Enchanted->Data[0].XINT64[3] = 0;} else {Enchanted->Data[0].XINT64[3] -= Vrab20;}
        }

        if(Enchanted->Data[0].INT64[4] != 0) Enchanted->Data[0].INT64[4] -= 3; if(Enchanted->Data[0].INT64[4] < 0) Enchanted->Data[0].INT64[4] = 0;
        if(Enchanted->Data[0].INT64[5] != Vrab03[2]){Enchanted->Data[0].INT64[4] = 100; Enchanted->Data[0].XINT64[2] = 0; Enchanted->Data[0].XINT64[0] = Vrab03[0]; Enchanted->Data[0].XINT64[3] = 0; Enchanted->Data[0].XINT64[1] = Vrab03[1];}
        Enchanted->Data[0].INT64[5] = Vrab03[2];

        if(Vrab03[0] - Enchanted->Data[0].XINT64[0] < Vrab05) if(Enchanted->Data[0].XINT64[2] < Vrab05 * 2 && Enchanted->Data[0].XINT64[2] > 0){Enchanted->Data[0].XINT64[2] = 0; Enchanted->Data[0].XINT64[0] = Vrab03[0];}
        if(Vrab03[0] - Enchanted->Data[0].XINT64[0] > -Vrab05) if(Enchanted->Data[0].XINT64[2] > -Vrab05 * 2 && Enchanted->Data[0].XINT64[2] < 0){Enchanted->Data[0].XINT64[2] = 0; Enchanted->Data[0].XINT64[0] = Vrab03[0];}
        if(Vrab03[1] - Enchanted->Data[0].XINT64[1] < Vrab05) if(Enchanted->Data[0].XINT64[3] < Vrab05 * 2 && Enchanted->Data[0].XINT64[3] > 0){Enchanted->Data[0].XINT64[3] = 0; Enchanted->Data[0].XINT64[1] = Vrab03[1];}
        if(Vrab03[1] - Enchanted->Data[0].XINT64[1] > -Vrab05) if(Enchanted->Data[0].XINT64[3] > -Vrab05 * 2 && Enchanted->Data[0].XINT64[3] < 0){Enchanted->Data[0].XINT64[3] = 0; Enchanted->Data[0].XINT64[1] = Vrab03[1];}
        Enchanted->Data[0].XINT64[0] += Enchanted->Data[0].XINT64[2];
        Enchanted->Data[0].XINT64[1] += Enchanted->Data[0].XINT64[3];
       }

       statics uint64 Vrab04 = ruint64(Enchanted->Data[0].INT64[2] + (Enchanted->Data[0].INT64[3] < 0 ? 1000 : 0) + (L_Positive64(Enchanted->Data[0].INT64[3]) * 10000));
       P_Set_Display(10, 0, 4, Enchanted->Data[0].INT64[4]);
       Enchanted->Engine1->Draw(Enchanted->Data[0].INSIZE[0], 0, 25, 800, 400, L_Rounding64(Enchanted->Data[0].XINT64[0]), L_Rounding64(Enchanted->Data[0].XINT64[1]), Enchanted->Data[0].INT64[5], Vrab04);
       P_Set_Display(10, 0, 0, 0);

       if(Enchanted->Data[0].INT1[1]) Enchanted->Print_Text(25, 395, 0, Enchanted->Data[0].STRING[0] + (Vrab0002 % 240 < 120 ? "_" : " "), 800);
       if(Enchanted->Engine1->Loaded == 1)
       {
        statics string Temp01 = Enchanted->Engine1->Load_Text; string Temp02; string Temp03; string Temp04;

        {
         statics insize Vrab05 = Temp01.size(); insize Vrab06 = 0;
         while(Vrab06 < Vrab05){if(Temp01[Vrab06] == '|'){Vrab06 += 1; break;} Temp02.push_back(Temp01[Vrab06]); Vrab06 += 1;}
         while(Vrab06 < Vrab05){if(Temp01[Vrab06] == '|'){Vrab06 += 1; break;} Temp03.push_back(Temp01[Vrab06]); Vrab06 += 1;}
         while(Vrab06 < Vrab05){if(Temp01[Vrab06] == '|'){Vrab06 += 1; break;} Temp04.push_back(Temp01[Vrab06]); Vrab06 += 1;}
        }

        Enchanted->Print_Text(4, 430, 0, Temp04 + (Vrab0002 % 240 < 60 ? "" : (Vrab0002 % 240 < 120 ? "." : (Vrab0002 % 240 < 180 ? ".." : "..."))), 800);
       }
      }
      break;
      default: break;
     }
    }

    
    /*

   // Early Displayed Window
    {
     for(insize Vrab03 = Enchanted->Vect001.size() - 1; Vrab03 + 1 != 0; Vrab03--)
     switch(Enchanted->Vect001[Vrab03])
     {
      case 0: // In-Game Base
       {
        statics int1 Vrab04 = (Enchanted->Vect001[0] == 0); // On focus window?

        Enchanted->Vect006.resize(4); if(Enchanted->Vect006[Enchanted->Setting[0].Engine])
        {
        
        } else 
        {
         if(!Enchanted->Vrab004)
         {Enchanted->Vrab004 = true; Enchanted->Vect001.push_back(1);}
        }
       }
      break;
      default: break;
     }
    }

   // Window
    {
     for(insize Vrab03 = Enchanted->Vect001.size() - 1; Vrab03 + 1 != 0; Vrab03--)
     switch(Enchanted->Vect001[Vrab03])
     {
      case 1: // Engine Loader
       {
        statics int1 Vrab04 = (Enchanted->Vect001[0] == 1); // Focused Window?
        if(Enchanted->Data.size() < 2) Enchanted->Data.resize(2);
        Enchanted->Data[1].INT1.resize(2);
        Enchanted->Data[1].INT64.resize(2);
        Enchanted->Data[1].STRING.resize(1);

        statics int64 Vrab05 = L_Rounding64(rxint64(HEPTA_BASE_FRAME_PER_SECOND * 0.2));
        if(Enchanted->Data[1].INT64[0] < Vrab05) Enchanted->Data[1].INT64[0] += ruint64(Vrab0003);
        if(Enchanted->Data[1].INT64[0] > Vrab05) Enchanted->Data[1].INT64[0] = Vrab05;
        
        Enchanted->Print_Text(0, 30, 0, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" + std::to_string(Enchanted->Data[1].INT64[0]));

        if(Enchanted->Data[1].INT64[0] == Vrab05)
        {
         if(Enchanted->Vrab004)
         {
          string Temp01;
          switch(Enchanted->Setting[0].Engine)
          {
           case 0: Temp01 = Enchanted->Engine0->Load(); break;
           case 1: Temp01 = Enchanted->Engine1->Load(); break;
           case 2: Temp01 = Enchanted->Engine2->Load(); break;
           case 3: Temp01 = Enchanted->Engine3->Load(); break;
           default: break;
          } if(Temp01.size() == 0) Temp01 = "F";

          statics insize Vrab06 = Temp01.size();
          if(Vrab06 > 1) while(true)
          {

           break;
          }

           
           if(Temp01.at(0) == 'F'){Enchanted->Data[1].INT1[0] = true; if(Vrab06 > 3){Enchanted->Data[1].STRING[0] = string(Temp01, 2, Vrab06 - 2);} else {Enchanted->Data[1].STRING[0] = "Unknown reason of failure.";}}

         }
        }

        int1 Vrab06 = Enchanted->Data[1].INT1[1];
        if(Vrab06)
        {
         if(Enchanted->Data[1].INT64[1] < Vrab05) Enchanted->Data[1].INT64[1] += ruint64(Vrab0003);
         if(Enchanted->Data[1].INT64[1] > Vrab05) Enchanted->Data[1].INT64[1] = Vrab05;
        }      
       }
      break;
      default: break;
     }
    }

   // Window Data Cleaning/Exit
    {
     for(insize Vrab03 = Enchanted->Vect001.size() - 1; Vrab03 + 1 != 0; Vrab03--)
     switch(Enchanted->Vect001[Vrab03])
     {
      case 1: // Engine Loader
       {
        if(Enchanted->Data.size() < 2) Enchanted->Data.resize(2);
        Enchanted->Data[1].INT64.resize(2);

        if(Enchanted->Data[1].INT64[1] == L_Rounding64(rxint64(HEPTA_BASE_FRAME_PER_SECOND * 0.2)))
        {Enchanted->Vect001.erase(Enchanted->Vect001.begin() + Vrab03);}
       }
      break;
      default: break;
     }
    }

    */

   // Finalizer.
   {
    // Exit.
    if(Enchanted->Vrab005 == 0)
    if(L_Input(Vrab0017) == 1)
    {
     statics insize Vrab03 = Enchanted->Info.size(); insize Vrab04 = 0;
     while(Vrab03 != Vrab04)
     {
      if(Enchanted->Info[Vrab04].String == (L_Lang(0) + Enchanted->Input_Name(Vrab0017) + L_Lang(1)))
      Vrab0030 = 1;
      Vrab04 += 1;
     } if(Vrab03 == Vrab04) Enchanted->Post_Info(L_Lang(0) + Enchanted->Input_Name(Vrab0017) + L_Lang(1), true);
    }
    
    // Mouse Draw & Brightness.
    {
     int1 Vrab03 = false; Enchanted->Vrab008 = false;
     if(Input->MOUS_Right == 1){Enchanted->Vrab009 += 1; Enchanted->Vrab009 %= 5;}
     if(Input->MOUS_Mid == 1 || ((Input->CONS_LSHIFT >= 1 || Input->CONS_RSHIFT >= 1) && (Input->CONS_LCTRL >= 1 || Input->CONS_RCTRL >= 1) && Input->CONS_WINDOWS == 1)){Enchanted->Vrab010 += 1; Enchanted->Vrab010 %= 5;}
     if(Input->MOUS_Left >= 1 && Enchanted->Vrab007)
     {
      int64 Vrab04 = Input->MOUS_X, Vrab05 = Input->MOUS_Y, Vrab06 = Input->MOUS_X_Left, Vrab07 = Input->MOUS_Y_Left;
      if(Vrab06 < Vrab04){Vrab04 = Vrab06; Vrab06 = Input->MOUS_X;} else {Vrab04 -= 1; Vrab06 += 1;}
      if(Vrab07 < Vrab05){Vrab05 = Vrab07; Vrab07 = Input->MOUS_Y;} else {Vrab05 -= 1; Vrab07 += 1;}
      Vrab06 -= Vrab04; Vrab07 -= Vrab05;

      if(Vrab06 > 10 || Vrab07 > 10)
      {
       Vrab03 = true; Enchanted->Vrab008 = true; insize Vrab08 = 0xFF00; uint8 Vrab09 = 50ui8;
       switch(Enchanted->Vrab009)
       {
        case 1: Vrab08 = 0xFF; break;
        case 2: Vrab08 = 0x0; break;
        case 3: Vrab08 = 0xFFFFFF; break;
        case 4: Vrab08 = 0xFF0000; break;
        default: break;
       }
       switch(Enchanted->Vrab010)
       {
        case 1: Vrab09 = 100ui8; break;
        case 2: Vrab09 = 175ui8; break;
        case 3: Vrab09 = 255ui8; break;
        case 4: Vrab09 = 0ui8; break;
        default: break;
       }
       P_Set_Display(1, Vrab08, Vrab04, Vrab05, 0, 255ui8, Vrab06, Vrab07); P_Set_Display(0, Vrab08, Vrab04 + 1, Vrab05 + 1, 0, Vrab09, Vrab06 - 2, Vrab07 - 2);
      }
     }

     if(L_Input(Enchanted->Setting[0].F12) > 0)
     {
      Enchanted->Vrab008 = true;
      if(Enchanted->Vrab011 - (0.0125 * rxint64(Vrab0003)) < 0.35)
      {Enchanted->Vrab011 = 0.35;} else {Enchanted->Vrab011 -= 0.0125 * rxint64(Vrab0003);}
     } else 
     {
      if(Enchanted->Vrab011 < 1.0) 
      if(Enchanted->Vrab011 + (0.0025 * rxint64(Vrab0003)) > 1.0)
      {Enchanted->Vrab011 = 1.0;} else {Enchanted->Vrab011 += 0.0025 * rxint64(Vrab0003);}
     }
     {
      statics uint8 Vrab04 = ruint8(L_Rounding(rxint64(Enchanted->Setting[0].Brightness) * Enchanted->Vrab011));
      if(Vrab04 > 100)
      {P_Set_Display(0, 0xFFFFFF, 0, 0, 0, ruint8(L_Rounding((rxint64(Vrab04 - 100) / 100.0) * 255.0)), Enchanted->Setting[0].Width, Enchanted->Setting[0].Height);} else
      {P_Set_Display(0, 0x0, 0, 0, 0, 255 - ruint8(L_Rounding((rxint64(Vrab04) / 100.0) * 255.0)), Enchanted->Setting[0].Width, Enchanted->Setting[0].Height);}
     }

     if(Input->MOUS_X == Enchanted->Vrab013 && Input->MOUS_Y == Enchanted->Vrab014 && Input->MOUS_Left == 0){if((++Enchanted->Vrab012) == 255ui8) Enchanted->Vrab012 = 254ui8;} else {Enchanted->Vrab012 = 0ui8;}
     if(Enchanted->Vrab012 < 150ui8){ShowCursor(TRUE); if(Vrab03){P_Set_Display(2, Enchanted->Vect004[14], Input->MOUS_X - 11ull, Input->MOUS_Y - 11ull);} else {P_Set_Display(2, Enchanted->Vect004[13], Input->MOUS_X - 3ull, Input->MOUS_Y - 3ull);}} else
     {if(Enchanted->Vrab012 == 156ui8){ShowCursor(FALSE); SetCursor(NULL);}}
     Enchanted->Vrab013 = Input->MOUS_X; Enchanted->Vrab014 = Input->MOUS_Y;
    }
 
    // Info Notification & Volume.
    {
     insize Vrab03 = Enchanted->Info.size();
     while(Vrab03 != 0)
     {
      Vrab03 -= 1;
  
      // Volume special notification.
      if(Enchanted->Info[Vrab03].Volume) Enchanted->Info[Vrab03].String = L_Lang(2) + std::to_string(Enchanted->Setting[0].Volume) + L_Lang(3);
      insize Vrab04 = Enchanted->Info[Vrab03].String.size();
 
      // Position.
      int64 Vrab05 = 0, Vrab06 = Enchanted->Info[Vrab03].Y + (Enchanted->Vrab005 == 2 ? 15 : (Enchanted->Setting[0].Show_FPS ? 30 : 15));
      if(Enchanted->Vrab005 == 2){int64 Vrab07 = 0; statics int64 Vrab08 = Vrab0005; if(Vrab08 > 400 && Vrab08 < 550){Vrab07 = Vrab08 - 400; if(Vrab07 < 0){Vrab07 = 0;} else {Vrab07 = Vrab07 / 2;}} if(Vrab08 >= 550){Vrab07 = Vrab08 - 500; Vrab07 = (Vrab07 / 2) + 100;} if(Enchanted->Setting[0].Show_FPS) if(Vrab07 < 15) Vrab07 = 15; Vrab06 += Vrab07;}
      int1 Vrab07 = true; int1 Vrab08 = false;

      // Transition.
      if(Enchanted->Info[Vrab03].Runtime < (HEPTA_BASE_FRAME_PER_SECOND / 3))
      {
       statics int64 Vrab09 = (HEPTA_BASE_FRAME_PER_SECOND / 3) - rint64(Enchanted->Info[Vrab03].Runtime);
       Vrab05 = -L_Rounding64(((rxint64((Vrab09 * Vrab09) + Vrab09) / 2) / 39340) * 400.0);
      } else
      {
       statics uint64 Vrab09 = (HEPTA_BASE_FRAME_PER_SECOND * 2) + (ruint64(Vrab04) * (HEPTA_BASE_FRAME_PER_SECOND / 16));
       if(Enchanted->Info[Vrab03].Runtime >= Vrab09 - Vrab0003)
       if(Enchanted->Info[Vrab03].Runtime >= Vrab09)
       {
        statics int64 Vrab10 = rint64(Enchanted->Info[Vrab03].Runtime) - Vrab09; Vrab08 = true;
 
        // Shift back.
        if(Vrab10 >= 24 && Vrab10 < 24 + rint64(Vrab0003))
        {
         Enchanted->Print_Text(0, 0, 0, Enchanted->Info[Vrab03].String, 360, 1);
         int64 Vrab11 = 34 + Enchanted->Vrab016[1];
         statics insize Vrab12 = Enchanted->Info.size();
         for(insize Vrab13 = 0; Vrab13 < Vrab12; ++Vrab13)
         if(Enchanted->Info[Vrab03].Slot > Enchanted->Info[Vrab13].Slot)
         {
          statics insize Vrab14 = Enchanted->Info[Vrab13].Manager.size(); Enchanted->Info[Vrab13].Manager.resize(Vrab14 + 1);
          Enchanted->Info[Vrab13].Manager[Vrab14].Target = -Vrab11;
         }
        }
 
        Vrab05 = -L_Rounding64(((rxint64((Vrab10 * Vrab10) + Vrab10) / 2) / 39340) * 420.0);
       } else {if(Enchanted->Vrab008) Enchanted->Info[Vrab03].Runtime -= Vrab0003;}
       if(Enchanted->Info[Vrab03].Runtime > Vrab09 + (HEPTA_BASE_FRAME_PER_SECOND / 3)) Vrab07 = false;
      }
       
      Enchanted->Info[Vrab03].Runtime += Vrab0003;
 
      // Shifts.
      {
       insize Vrab09 = Enchanted->Info[Vrab03].Manager.size();
       while(Vrab09 != 0)
       {
        Vrab09 -= 1; Enchanted->Info[Vrab03].Manager[Vrab09].Runtime += Vrab0003;
        int64 Vrab10 = 256 - rint64(Enchanted->Info[Vrab03].Manager[Vrab09].Runtime); if (Vrab10 < 0) Vrab10 = 0;
        statics int64 Vrab11 = Enchanted->Info[Vrab03].Manager[Vrab09].Target, Vrab12 = L_Rounding64(((rxint64((Vrab10 * Vrab10) + Vrab10) / 2) / 32896) * Vrab11) - Vrab11;
        Vrab06 -= Vrab12;
        if(Vrab10 == 0 || (Vrab08 && Vrab11 < 0)){Enchanted->Info[Vrab03].Y -= Vrab12; Enchanted->Info[Vrab03].Manager.erase(Enchanted->Info[Vrab03].Manager.begin() + Vrab09);}
       }
      }
 
      // Drawing.
      if(Vrab07)
      {
       Enchanted->Print_Text(0, 0, 0, Enchanted->Info[Vrab03].String, 360, 1);
       Enchanted->Print_Bar(Vrab05 + 15, Vrab06, 13 + Enchanted->Vrab016[0], 5 + Enchanted->Vrab016[1]);
       Enchanted->Print_Text(Vrab05 + 30, Vrab06 - 6, 0, Enchanted->Info[Vrab03].String, 360, 2);
       P_Set_Display(2, Enchanted->Vect004[Enchanted->Info[Vrab03].Question ? 105 : 106], Vrab05 + 9, Vrab06 - 6);
      } else {Enchanted->Info.erase(Enchanted->Info.begin() + Vrab03);}
     }
 
     // Volume
     int1 Vrab04 = false;
     Vrab03 = Enchanted->Info.size(); while(Vrab03 != 0){Vrab03 -= 1; if(Enchanted->Info[Vrab03].Volume) if(Enchanted->Info[Vrab03].Runtime < (HEPTA_BASE_FRAME_PER_SECOND * 2) + (ruint64(Enchanted->Info[Vrab03].String.size()) * (HEPTA_BASE_FRAME_PER_SECOND / 16))){Vrab04 = true; break;}}
     statics uint8 Vrab05 = L_Input(Enchanted->Setting[0].F10), Vrab06 = L_Input(Enchanted->Setting[0].F11);
     if(Vrab05 > 0 || Vrab06 > 0)
     {
      if(Vrab04){if(Enchanted->Info[Vrab03].Runtime > (HEPTA_BASE_FRAME_PER_SECOND / 3)) Enchanted->Info[Vrab03].Runtime = (HEPTA_BASE_FRAME_PER_SECOND / 3);} else {Enchanted->Post_Info("", false, true);}
      uint8 Vrab07 = ruint8(L_Rounding(16.0 / rxint64(Vrab0003))); if(Vrab07 == 0) Vrab07 = 1;
      if(Vrab05 > 0 && Vrab06 == 0)
      if(Vrab05 == 1 || (Vrab05 % Vrab07 == 0 && Vrab05 > Vrab07 * 12)){Enchanted->Setting[0].Volume -= 1; if(Enchanted->Setting[0].Volume > 150) Enchanted->Setting[0].Volume = 0; Enchanted->Setting[1].Volume = Enchanted->Setting[0].Volume;}
      if(Vrab06 > 0 && Vrab05 == 0)
      if(Vrab06 == 1 || (Vrab06 % Vrab07 == 0 && Vrab06 > Vrab07 * 12)){Enchanted->Setting[0].Volume += 1; if(Enchanted->Setting[0].Volume > 150) Enchanted->Setting[0].Volume = 150; Enchanted->Setting[1].Volume = Enchanted->Setting[0].Volume;}
     }
    }

    // FPS Draw.
    string Temp01 = "";
    switch(Enchanted->Setting[0].Engine){case 1: Temp01 = Enchanted->Engine1->Temp(); break; default: break;}
    if(Enchanted->Setting[0].Show_FPS) Enchanted->Print_Text(0, -3, 0, std::to_string(Vrab01) + "|" + std::to_string(Vrab02) + " " + Temp01);
   }
  }
  int0 EIDP_LF2Forevered(uint32 Vrab01, uint64 Vrab02) perfect
  {
   UNREFERENCED_PARAMETER(Vrab01); UNREFERENCED_PARAMETER(Vrab02);
   // Initialization
    if(Forevered->Vrab001)
    {
     Forevered->Vrab001 = false;
     Forevered->Setting_Load(); Forevered->Setting_Save(); Forevered->Setting[0].Fullscreen = Vrab0009;
     G_Adjust_Window(Forevered->Setting[0].Width, Forevered->Setting[0].Height, Forevered->Setting[0].Fullscreen, "Little Fighter 2 : Happy Birthday Evered!");

    }
  }
#endif

// Documentation ////
// 
//  This project was made out of basic C++ programming language, while this would be easier to be
//  modify or such for beginners, you'll find this hard to understand if you're an advance or
//  professional programmer.
//  I would suggest to reformat the coding style.
//  Althought a documentation should be explicit about many stuffs, i only document the major.
//  And sorry for my bad english, i hope you found this useful.
// 
//  Basically there are 3 core thing;
//  > Display
//    The way you can display is by using "P_Set_Display()", but before you can display any image, you need to load the image first
//    with "P_Load_Pic()" or "P_Load_Sprite()" function.
//    Each function has 5 members/value you can fill/put, "Temp01", "Vrab01", "Vrab02", "Vrab03", and "Vrab04".
// 
//    "Temp01" : The address/directory to the image.
//    "Vrab01" : The top left position or x for the part of the image to be load by "G_Load_Pic()" or the width of the sprite for "G_Load_Sprite()".
//    "Vrab02" : The top left position or y for the part of the image to be load by "G_Load_Pic()" or the height of the sprite for "G_Load_Sprite()".
//    "Vrab03" : The width for the part of the image to be load by "G_Load_Pic()" or the row of the sprite for "G_Load_Sprite()".
//    "Vrab04" : The height for the part of the image to be load by "G_Load_Pic()" or the column of the sprite for "G_Load_Sprite()".
//    
//    You can left the Vrab01, Vrab02, Vrab03, and Vrab04 empty in "P_Load_Pic()" if you want to load the intire image.
//    Those "G_Load_Pic()" and "G_Load_Sprite" will return a certain number that can be used in "P_Set_Display()".
// 
//    There are many type of "P_Set_Display()" that you can use to display various way of displaying.
//    This "P_Set_Display()" itself has a total of 12 member/value you can fill/put, from "Vrab01" to "Vrab12".
//    The type of way it display is determine by the value of "Vrab01" ;
//    Vrab01 = 0 : Plain color rectangle.
//    Vrab01 = 1 : Plain color rectangle without fill.
//    Vrab01 = 2 / 6 : Basic image draw.
//    Vrab01 = 3 / 7 : Specified area image draw.
//    Vrab01 = 4 / 5 / 8 / 9 : Sprite image draw.
//    Vrab01 = 10 : Color control for next usage of "P_Set_Display()".
//    
//    Each member/value/variable will act different for each type ;
//    - Type 0 - Plain color rectangle
//      P_Set_Display(0, Color, X, Y, Rotate, Transparency, W, H);
//    - Type 1 - Plain color rectangle without fill
//      P_Set_Display(1, Color, X, Y, Rotate, Transparency, W, H);
//    - Type 2 / 6 - Basic image draw
//      P_Set_Display(2, Address, X, Y, Effect, Transparency, Strect_W, Strect_H, Rotate);
//      P_Set_Display(6, Address, X, Y, Effect, Transparency, Strect_W, Strect_H, Rotate);
//    - Type 3 / 7 - Specified area image draw.
//      P_Set_Display(3, Address, X, Y, Effect & Rotate, Transparency, Img_X, Img_Y, Img_W, Img_H, Strect_W, Strect_H);
//      P_Set_Display(7, Address, X, Y, Effect & Rotate, Transparency, Img_X, Img_Y, Img_W, Img_H, Strect_W, Strect_H);
//    - Type 4 / 5 / 8 / 9 - Sprite image draw
//      P_Set_Display(4, Address, X, Y, Effect, Transparency, Strect_W, Strect_H, Rotate);
//      P_Set_Display(5, Address, X, Y, Effect, Transparency, Strect_W, Strect_H, Rotate);
//      P_Set_Display(8, Address, X, Y, Effect, Transparency, Strect_W, Strect_H, Rotate);
//      P_Set_Display(9, Address, X, Y, Effect, Transparency, Strect_W, Strect_H, Rotate);
//    - Type 10 - Color Control
//    
//  > Audio
//    Currently, this engine only support ".wav" format, which is limited in higher level of audio management.
//    To play an audio, you have to load the audio first by using "P_Load_Sound()", it has one member that's the file address,
//    return a number that will be used by "P_Set_Sound()" or "P_Set_Music()".
//    
//    The different between "P_Set_Sound()" and "P_Set_Music()" is just that "P_Set_Music()" will keep on repeat.
// 
//  > Input
//    
/////////////////////