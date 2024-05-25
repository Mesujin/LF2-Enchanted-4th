////////////////////////////////////////////////////////////////////////////////////////////
// "engine.h"                                                                             //
//                                                                                        //
// Main source of "Hepta: Enchanted".                                                     //
// Dunno what to text here, but this is my usual style for a header text...               //
// I'am "mid" in english, keep it in your mind.                                           //
// Everything that's about the "mechanism" of the game were written here, the other part  //
// of the game, such as drawing, playing the sound, etc weren't written here.             //
//                                                                                        //
// There's one documentation on the bottom about how to use the "platform", but for the   //
// engine, there's no documentation exist and mostly there aren't note exist about        //
// "what was it?", "what this line of code do?", etc, since most of the code were written //
// in basic C++ programming, i thought it might not that necessary to have a note.        //
// "A note won't help much here anyway..". Either a documentation if you're not used to   //
// my code format.                                                                        //
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

  // Pre-defined Variable
   #define HEPTA_BASE_FRAME_PER_SECOND 960

 // Early Declaration (In order to be accessible by Global Variables.)
  int1   L_Exist(statics string&)     perfect;
  int32  L_Rounding(statics xint64)   perfect;
  int64  L_Rounding64(statics xint64) perfect;
  string L_Execute(statics string)    perfect;
  string L_Pronounce(statics uint64)  perfect; 
  string L_Directory(statics string)  perfect;
  string L_Lowercase(string)          perfect;
  string L_Cut(string Temp01, insize Vrab01 = 2, insize Vrab02 = 0) perfect;
  string L_Load(uint8 Vrab01, uint8 Vrab02 = 0)                     perfect;
  string L_Save(uint8 Vrab01, string Temp01 = "", uint8 Vrab02 = 0) perfect;
  int0   EIDP_LF2Enchanted(uint32, uint64) perfect;
  int0   EIDP_LF2Forevered(uint32, uint64) perfect;

  // Encryption & Decryption Functions
   int0   S_Control()                        perfect;
   int8   S_Decryption94(const int8)         perfect;
   int8   S_DecryptionINT8(const int8[2])    perfect;
   int16  S_DecryptionINT16(const int8[3])   perfect;
   int32  S_DecryptionINT32(const int8[5])   perfect;
   int64  S_DecryptionINT64(const int8[10])  perfect;
   uint32 S_DecryptionUINT4(const int8[1])   perfect;
   uint8  S_DecryptionUINT8(const int8[2])   perfect;
   uint32 S_DecryptionUINT10(const int8[2])  perfect;
   uint16 S_DecryptionUINT16(const int8[3])  perfect;
   uint32 S_DecryptionUINT18(const int8[3])  perfect;
   uint32 S_DecryptionUINT24(const int8[4])  perfect;
   uint32 S_DecryptionUINT32(const int8[5])  perfect;
   uint64 S_DecryptionUINT64(const int8[10]) perfect;
   xint64 S_DecryptionXINT64(const int8[11]) perfect;
   string S_DecryptionSTRING(string)         perfect;
   string S_Encryption94(const uint64)       perfect;
   string S_EncryptionUINT4(const uint32)    perfect;
   string S_EncryptionUINT8(const uint8)     perfect;
   string S_EncryptionUINT10(const uint32)   perfect;
   string S_EncryptionUINT16(const uint16)   perfect;
   string S_EncryptionUINT18(const uint32)   perfect;
   string S_EncryptionUINT24(const uint32)   perfect;
   string S_EncryptionUINT32(const uint32)   perfect;
   string S_EncryptionUINT64(const uint64)   perfect;
   string S_EncryptionXINT64(const xint64)   perfect;
   string S_EncryptionSTRING(string)         perfect;

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
  uint8  Vrab0022 = 0;      // Input Pad Default OK.
  uint8  Vrab0023 = 0;      // Input Pad Default CANCEL.
  uint8  Vrab0024 = 0;      // Input Pad Default UP.
  uint8  Vrab0025 = 0;      // Input Pad Default LEFT.
  uint8  Vrab0026 = 0;      // Input Pad Default DOWN.
  uint8  Vrab0027 = 0;      // Input Pad Default RIGHT.
  uint32 Vrab0028 = 800;    // Window Width.
  uint32 Vrab0029 = 450;    // Window Height.
  uint8  Vrab0030 = 0;      // Window Exit?
  uint64 Vrab0031 = 0;      // Random Seed.
  int1   Vrab0032 = true;   // Random Reset.

  uint8  Vrab0033 = 0;      // LF2_Enchanted Status.
  uint8  Vrab0034 = 0;      // LF2_Forevered Status.
 
 // Stuctures
  struct HEPTA_INPUT
  {
   uint8 RESH_ANY;

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
      /*
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGES_STAGE_PHASE_ENTITY
      {
       uint8  role = 0; // <boss> , <soldier>
       insize id = rinsize(-1);
       int32  hp = 500;
       int32  x, y, z, act, times, reserve, join, join_reserve;
       xint64 ratio = 1;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGES_STAGE_PHASE
      {
       int32  bound = 0;
       insize music_Index = rinsize(-1);
       insize when_clear_goto_phase = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGES_STAGE_PHASE_ENTITY > Entity;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGES_STAGE
      {
       insize id = 0;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGES_STAGE_PHASE > Phase;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_STAGES
      {
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_STAGES_STAGE > Stage;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER 
      {
       int32  transparency, width, height, x, y, loop, cc, c1, c2, rect32;
       insize image_Index = rinsize(-1);
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND
      {
       string name;
       insize id = rinsize(-1);
       int32  x, width, zboundary[2]{}, perspective[2]{}, shadowsize[2]{};
       insize shadow_Index = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND_LAYER > Layer;
      };
	     struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_PPOINT
	  {
	   int32 pic, x, y, z, rotate, w, h, trans;
	  };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_BPOINT
      {
       int32 x, y, z, w, h, rect32;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_CPOINT
      {
       int32 kind, x, y, z, vaction, aaction, daction, jaction, taction, throwvx, throwvy, throwvz, throwinjury, dircontrol, hurtable, decrease, cover, injury, fronthurtact, backhurtact;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_WPOINT
      {
       int32 kind, x, y, z, dvx, dvy, dvz, weaponact, attacking, cover;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_OPOINT
      {
       int32 kind, x, y, z, dvx, dvy, dvz, oid, action, facing;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT
      {
       int32 kind, x, y, z, w, h, zwidth, dvx, dvy, dvz, fall, arest, vrest, respond, effect, bdefend, injury, catchingact[2], caughtact[2];
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_HPOINT
      {
       int32 kind, x, y, z, w, h, zwidth;
      };
      struct HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME
      {
       int1   Exist = false;
       insize pic = rinsize(-1);
       int32  state, wait, next, dvx, dvy, dvz, centerx, centery, centerz, mp, hit_a, hit_d, hit_j, hit_Fa, hit_Fj, hit_Da, hit_Dj, hit_Ua, hit_Uj, hit_ja;
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
       int32 dvx, dvy, dvz, fall, arest, vrest, respond, effect, bdefend, injury;
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
       uint8  type = 0;
       string name;
       insize head_Index = rinsize(-1), small_Index = rinsize(-1);
       std::vector < insize > file_Index;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_PIC > file;
       int32  walking_frame_rate, running_frame_rate, weapon_hp, weapon_drop_hurt;
       xint64 walking_speed, walking_speedz, running_speed, running_speedz, heavy_walking_speed, heavy_walking_speedz, heavy_running_speed, heavy_running_speedz, jump_height, jump_distance, jump_distancez, dash_height, dash_distance, dash_distancez, rowing_height, rowing_distance;
       insize weapon_hit_sound_Index = rinsize(-1), weapon_drop_sound_Index = rinsize(-1), weapon_broken_sound_Index = rinsize(-1);
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_STRENGTH > Strength;
       std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME* > Frame;
      };
    
      struct HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT
      {
       xint64 X = 0.0, Y = 0.0, Z = 0.0; int1 Exist = true;
       insize Pic = 0; int1 Sprite = false; int1 Loop = false; int1 Screen = false;
       std::vector < insize > Pics;
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

      string Temp001;        // Working Address.
      int1   Vrab001 = true; // Debug output.

      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_EFFECT >     Effect;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Object;
     
      unique < HEPTA_LF2_ENCHANTED_ENGINE1_STAGES > Stages;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT >     Objects;             // Database of Objects.
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND > Backgrounds;         // Database of Backgrounds.
      std::vector < unique < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME > > Frames; // Frames' Pointer.
      */
      
      string Temp001;        // Working Address.
      int1   Vrab001 = true; // Debug output.
      //asIScriptEngine Engi001; // AngelScript's Engine.

      int0   Debug(statics string Temp01, statics int8 Vrab01 = 0 , statics int1 Vrab02 = false) perfect
      {
       if(!Vrab001) return;
       if(Vrab02){std::ofstream File01(L_Execute(Temp001 + "debug.log"), std::ios::binary); File01 << ""; File01.close();}
       std::ofstream File01(L_Execute(Temp001 + "debug.log"), std::ios::binary | std::ios::app);
       File01 << (Vrab01 == 0 ? "[" : (Vrab01 == 1 ? ")" : ">")) << L_Pronounce(std::chrono::time_point_cast < std::chrono::milliseconds > (std::chrono::system_clock::now()).time_since_epoch().count()) << (Vrab01 == 0 ? "] INFO - " : (Vrab01 == 1 ? "( WARNING - " : "< ERROR - ")) << Temp01 << "\n";
       File01.close();
      }

     public:
      HEPTA_LF2_ENCHANTED_ENGINE1(){}

      int0   Begin(statics string Temp01) perfect
      {
       Temp001 = Temp01; Debug("Engine1 : Origin - Starting.", 0, true);
       
       AllocConsole();
       freopen("CONIN$", "rb", stdin);   // Reopen stdin handle as console window input.
       freopen("CONOUT$", "wb", stdout); // Reopen stout handle as console window output.
       freopen("CONOUT$", "wb", stderr); // Reopen stderr handle as console window output.
  
      // Engi001 = NULL;
      // Engi001 = asCreateScriptEngine(ANGELSCRIPT_VERSION);
      // if(!Engi001) return "";
      }
      string Load() perfect
      {
       return "";
      }
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE2
    {
     string Load() perfect
     {
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
     std::vector < string > STRING;

     int0 CLEAR(){INT1.clear(); INT8.clear(); INT16.clear(); INT32.clear(); INT64.clear(); UINT8.clear(); UINT16.clear(); UINT32.clear(); UINT64.clear(); XINT64.clear(); STRING.clear();}
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
     
    HEPTA_LF2_ENCHANTED_SETTING Setting[2];
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
    int0   Post_Info(statics string Temp01, statics int1 Vrab01 = false, statics int1 Vrab02 = false) perfect
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
     if(Vrab03 == 0) Vrab006 = 0; Info[Vrab03].Slot = ++Vrab006;
     if(Vrab02){Info[Vrab03].Volume = true;} else {Info[Vrab03].String = Temp01;}
     Info[Vrab03].Question = Vrab01;
    }
    int0   Print_Text(statics int64 Vrab01, statics int64 Vrab02, uint8 Vrab03, statics string &Temp01, statics int64 Vrab04 = 0, statics int64 Vrab05 = 0) perfect
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
       P_Set_Display(3, Vect004[rinsize(Vrab03)], Vrab08 - Vrab10, Vrab02 + Vrab11, 0ui8, 255ui8, 15, 15, (Vrab09 % 16) * 16, (Vrab09 / 16) * 16);
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
       P_Set_Display(3, Vect004[rinsize(Vrab03)], Vrab08 - Vrab10, Vrab02 + Vrab11 + Vrab12, 0ui8, 255ui8, 15, 15 - Vrab12 - Vrab13, (Vrab09 % 16) * 16, ((Vrab09 / 16) * 16) + Vrab12);
       Vrab07 += 1; Vrab08 += 9;
      }
     }
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

 // Unique
  unique < HEPTA_INPUT > Input;
  unique < HEPTA_ANGELSCRIPT > Angel;
  unique < HEPTA_LF2_ENCHANTED > Enchanted;
  unique < HEPTA_LF2_FOREVERED > Forevered;

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
   return 255ui8;
  }
  int32  L_Numbering(string Temp01)                                 perfect {while(Temp01.size() > 0 && Temp01.at(0) != '-' && (Temp01.at(0) < '0' || Temp01.at(0) > '9')) Temp01.erase(0, 1); uint32 Vrab01 = Temp01.size(); if(Vrab01 == 0) return 0; while(Vrab01 != 1) if(Temp01.at(Vrab01 - 1) < '0' || Temp01.at(Vrab01 - 1) > '9'){Vrab01 -= 1;} else {break;} int32 Vrab02 = 0; if(Temp01.at(0) == '-'){if(Vrab01 == 1) return 0; if(Temp01.at(1) < '0' || Temp01.at(1) > '9') return 0; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1; break; case '2': Vrab02 -= 2; break; case '3': Vrab02 -= 3; break; case '4': Vrab02 -= 4; break; case '5': Vrab02 -= 5; break; case '6': Vrab02 -= 6; break; case '7': Vrab02 -= 7; break; case '8': Vrab02 -= 8; break; case '9': Vrab02 -= 9; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10; break; case '2': Vrab02 -= 20; break; case '3': Vrab02 -= 30; break; case '4': Vrab02 -= 40; break; case '5': Vrab02 -= 50; break; case '6': Vrab02 -= 60; break; case '7': Vrab02 -= 70; break; case '8': Vrab02 -= 80; break; case '9': Vrab02 -= 90; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100; break; case '2': Vrab02 -= 200; break; case '3': Vrab02 -= 300; break; case '4': Vrab02 -= 400; break; case '5': Vrab02 -= 500; break; case '6': Vrab02 -= 600; break; case '7': Vrab02 -= 700; break; case '8': Vrab02 -= 800; break; case '9': Vrab02 -= 900; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000; break; case '2': Vrab02 -= 2000; break; case '3': Vrab02 -= 3000; break; case '4': Vrab02 -= 4000; break; case '5': Vrab02 -= 5000; break; case '6': Vrab02 -= 6000; break; case '7': Vrab02 -= 7000; break; case '8': Vrab02 -= 8000; break; case '9': Vrab02 -= 9000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000; break; case '2': Vrab02 -= 20000; break; case '3': Vrab02 -= 30000; break; case '4': Vrab02 -= 40000; break; case '5': Vrab02 -= 50000; break; case '6': Vrab02 -= 60000; break; case '7': Vrab02 -= 70000; break; case '8': Vrab02 -= 80000; break; case '9': Vrab02 -= 90000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000; break; case '2': Vrab02 -= 200000; break; case '3': Vrab02 -= 300000; break; case '4': Vrab02 -= 400000; break; case '5': Vrab02 -= 500000; break; case '6': Vrab02 -= 600000; break; case '7': Vrab02 -= 700000; break; case '8': Vrab02 -= 800000; break; case '9': Vrab02 -= 900000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000000; break; case '2': Vrab02 -= 2000000; break; case '3': Vrab02 -= 3000000; break; case '4': Vrab02 -= 4000000; break; case '5': Vrab02 -= 5000000; break; case '6': Vrab02 -= 6000000; break; case '7': Vrab02 -= 7000000; break; case '8': Vrab02 -= 8000000; break; case '9': Vrab02 -= 9000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000000; break; case '2': Vrab02 -= 20000000; break; case '3': Vrab02 -= 30000000; break; case '4': Vrab02 -= 40000000; break; case '5': Vrab02 -= 50000000; break; case '6': Vrab02 -= 60000000; break; case '7': Vrab02 -= 70000000; break; case '8': Vrab02 -= 80000000; break; case '9': Vrab02 -= 90000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000; break; case '2': Vrab02 -= 200000000; break; case '3': Vrab02 -= 300000000; break; case '4': Vrab02 -= 400000000; break; case '5': Vrab02 -= 500000000; break; case '6': Vrab02 -= 600000000; break; case '7': Vrab02 -= 700000000; break; case '8': Vrab02 -= 800000000; break; case '9': Vrab02 -= 900000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; for(int32 Vrab03 = 10; Vrab01 > 0; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000 * Vrab03; break; case '2': Vrab02 -= 200000000 * Vrab03; break; case '3': Vrab02 -= 300000000 * Vrab03; break; case '4': Vrab02 -= 400000000 * Vrab03; break; case '5': Vrab02 -= 500000000 * Vrab03; break; case '6': Vrab02 -= 600000000 * Vrab03; break; case '7': Vrab02 -= 700000000 * Vrab03; break; case '8': Vrab02 -= 800000000 * Vrab03; break; case '9': Vrab02 -= 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;} else {Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1; break; case '2': Vrab02 += 2; break; case '3': Vrab02 += 3; break; case '4': Vrab02 += 4; break; case '5': Vrab02 += 5; break; case '6': Vrab02 += 6; break; case '7': Vrab02 += 7; break; case '8': Vrab02 += 8; break; case '9': Vrab02 += 9; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10; break; case '2': Vrab02 += 20; break; case '3': Vrab02 += 30; break; case '4': Vrab02 += 40; break; case '5': Vrab02 += 50; break; case '6': Vrab02 += 60; break; case '7': Vrab02 += 70; break; case '8': Vrab02 += 80; break; case '9': Vrab02 += 90; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100; break; case '2': Vrab02 += 200; break; case '3': Vrab02 += 300; break; case '4': Vrab02 += 400; break; case '5': Vrab02 += 500; break; case '6': Vrab02 += 600; break; case '7': Vrab02 += 700; break; case '8': Vrab02 += 800; break; case '9': Vrab02 += 900; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000; break; case '2': Vrab02 += 2000; break; case '3': Vrab02 += 3000; break; case '4': Vrab02 += 4000; break; case '5': Vrab02 += 5000; break; case '6': Vrab02 += 6000; break; case '7': Vrab02 += 7000; break; case '8': Vrab02 += 8000; break; case '9': Vrab02 += 9000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000; break; case '2': Vrab02 += 20000; break; case '3': Vrab02 += 30000; break; case '4': Vrab02 += 40000; break; case '5': Vrab02 += 50000; break; case '6': Vrab02 += 60000; break; case '7': Vrab02 += 70000; break; case '8': Vrab02 += 80000; break; case '9': Vrab02 += 90000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000; break; case '2': Vrab02 += 200000; break; case '3': Vrab02 += 300000; break; case '4': Vrab02 += 400000; break; case '5': Vrab02 += 500000; break; case '6': Vrab02 += 600000; break; case '7': Vrab02 += 700000; break; case '8': Vrab02 += 800000; break; case '9': Vrab02 += 900000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000000; break; case '2': Vrab02 += 2000000; break; case '3': Vrab02 += 3000000; break; case '4': Vrab02 += 4000000; break; case '5': Vrab02 += 5000000; break; case '6': Vrab02 += 6000000; break; case '7': Vrab02 += 7000000; break; case '8': Vrab02 += 8000000; break; case '9': Vrab02 += 9000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000000; break; case '2': Vrab02 += 20000000; break; case '3': Vrab02 += 30000000; break; case '4': Vrab02 += 40000000; break; case '5': Vrab02 += 50000000; break; case '6': Vrab02 += 60000000; break; case '7': Vrab02 += 70000000; break; case '8': Vrab02 += 80000000; break; case '9': Vrab02 += 90000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000; break; case '2': Vrab02 += 200000000; break; case '3': Vrab02 += 300000000; break; case '4': Vrab02 += 400000000; break; case '5': Vrab02 += 500000000; break; case '6': Vrab02 += 600000000; break; case '7': Vrab02 += 700000000; break; case '8': Vrab02 += 800000000; break; case '9': Vrab02 += 900000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; for(int32 Vrab03 = 10; Vrab01 != -1; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000 * Vrab03; break; case '2': Vrab02 += 200000000 * Vrab03; break; case '3': Vrab02 += 300000000 * Vrab03; break; case '4': Vrab02 += 400000000 * Vrab03; break; case '5': Vrab02 += 500000000 * Vrab03; break; case '6': Vrab02 += 600000000 * Vrab03; break; case '7': Vrab02 += 700000000 * Vrab03; break; case '8': Vrab02 += 800000000 * Vrab03; break; case '9': Vrab02 += 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;}}
  int32  L_Rounding(statics xint64 Vrab01)                          perfect {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint32(Vrab01); return rint32(Vrab01) + (Vrab02 ? -1 : 1);} // Round xint64 into int32.
  int64  L_Rounding64(statics xint64 Vrab01)                        perfect {statics int1 Vrab02 = Vrab01 < 0; if(rint64(Vrab01) == rint64(Vrab01 + (Vrab02 ? -0.5 : 0.5))) return rint64(Vrab01); return rint64(Vrab01) + (Vrab02 ? -1 : 1);} // Round xint64 into int64.
  uint64 L_Random(uint64 Vrab01, insize Vrab02 = 0)                 perfect 
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
   uint64 Vrab03 = ruint64(Vect02[Vrab02]());
   Vrab03 %= ruint64(0xFFFFFFFF) + 1;
   return ruint64(L_Rounding64((rxint64(Vrab03) / rxint64(0xFFFFFFFF)) * rxint64(Vrab01)));
  }
  string L_Cut(string Temp01, insize Vrab01, insize Vrab02)         perfect {statics insize Vrab03 = Temp01.size(); if(Vrab01 > Vrab03) Vrab01 = Vrab03; if(Vrab02 == 0) Vrab02 = Vrab03 - Vrab01; return string(Temp01, Vrab01, Vrab02);}
  string L_Pronounce(statics uint64 Vrab01)                         perfect {statics uint64 Vrab02 = (Vrab01 % 1000) + 1000; statics uint64 Vrab03 = Vrab01 / 1000; statics uint64 Vrab04 = Vrab03 / 60; statics uint64 Vrab05 = Vrab04 / 60; return std::to_string(Vrab05 / 24) + " - "+ string(std::to_string((Vrab05 % 24) + 100), 1, 2) + ":" + string(std::to_string((Vrab04 % 60) + 100), 1, 2) + ":" + string(std::to_string((Vrab03 % 60) + 100), 1, 2) + "." + string(std::to_string(Vrab02), 1, 3);}
  string L_Directory(statics string Temp01)                         perfect {return Temp0001 + Temp01;}
  string L_Execute(statics string Temp01)                           perfect {string Temp02 = Temp01; uint32 Vrab01 = Temp02.size() - 1; while(Vrab01 != 0 && Temp02.at(Vrab01) != '\\') Vrab01 -= 1; if(Vrab01 > 0) Temp02.erase(Vrab01, Temp02.size() - Vrab01); std::filesystem::create_directories(Temp02); return Temp01;}
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

 // Main Functions
  int0 M_EngineInput(DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01) perfect
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
    if(Vrab0001 >= 8600 && !L_Exist(L_Directory("Setting.ini")))
    if(Vrab0033 == 1){P_Unload_Pic(); P_Unload_Image(); Enchanted = std::make_unique < HEPTA_LF2_ENCHANTED > (); Vrab0033 = 2;}
	   if(Vrab0033 == 2) EIDP_LF2Enchanted(Vrab04, Varb03);

   // LF2 : Forevered.
    if(Vrab0001 >= 8600 && Vrab0033 != 2)
    if(Vrab0034 == 1){P_Unload_Pic(); P_Unload_Image(); Forevered = std::make_unique < HEPTA_LF2_FOREVERED > (); Vrab0034 = 2;}
    if(Vrab0034 == 2) EIDP_LF2Forevered(Vrab04, Vrab03);
   
   // Purging Offside Images.
    P_Set_Display(0, 0x0, -rint64(Vrab0007), -rint64(Vrab0008), 0ui8, 255ui8, Vrab0007, rint64(Vrab0008) + rint64(Vrab0006));
    P_Set_Display(0, 0x0, -rint64(Vrab0007), rint64(Vrab0006), 0ui8, 255ui8, rint64(Vrab0007) + rint64(Vrab0005), Vrab0008);
    P_Set_Display(0, 0x0, rint64(Vrab0005), 0, 0ui8, 255ui8, Vrab0007, rint64(Vrab0008) + rint64(Vrab0006));
    P_Set_Display(0, 0x0, 0, -rint64(Vrab0008), 0ui8, 255ui8, rint64(Vrab0007) + rint64(Vrab0005), Vrab0008);
  }

 // External-Included Dependencies Program's Main Functions
  int0 EIDP_LF2Enchanted(uint32 Vrab01, uint64 Vrab02) perfect
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
     Enchanted->Setting_Load(); Enchanted->Setting_Save(); Enchanted->Setting[0].Fullscreen = Vrab0009;
     G_Adjust_Window(Enchanted->Setting[0].Width, Enchanted->Setting[0].Height, Enchanted->Setting[0].Fullscreen, "Little Fighter 2 : Enchanted");
     Enchanted->Engine1->Begin(L_Directory(Enchanted->Setting[0].Address));

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
      Enchanted->Vect004.push_back(P_Load_Pic(Temp01 + "WORDS1" + Temp02, 0, 0, 255, 255));         // Index : 0
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
    }

   // Applying Setting
    {
     
    }

   // Inputs
    std::vector < uint8 > Vect01;                 // Overall Input.
    std::vector < std::vector < uint8 > > Vect02; // Player's Input.
    {
     Vect01.resize(8);
     insize Vrab03 = Enchanted->Setting[0].Player.size();
     if(Vrab03 == 0)
     {
      statics uint8 Vrab04 = L_Input(Vrab0018);
      statics uint8 Vrab05 = L_Input(Vrab0019);
      statics uint8 Vrab06 = L_Input(Vrab0020);
      statics uint8 Vrab07 = L_Input(Vrab0021);
      statics uint8 Vrab08 = L_Input(Vrab0016);
      statics uint8 Vrab09 = L_Input(Vrab0017);
      statics uint8 Vrab10 = L_Input(Vrab0024);
      statics uint8 Vrab11 = L_Input(Vrab0025);
      statics uint8 Vrab12 = L_Input(Vrab0026);
      statics uint8 Vrab13 = L_Input(Vrab0027);
      statics uint8 Vrab14 = L_Input(Vrab0022);
      statics uint8 Vrab15 = L_Input(Vrab0023);
      Vect01[0] = Vrab04 > Vrab10 ? Vrab04 : Vrab10;
      Vect01[1] = Vrab05 > Vrab11 ? Vrab05 : Vrab11;
      Vect01[2] = Vrab06 > Vrab12 ? Vrab06 : Vrab12;
      Vect01[3] = Vrab07 > Vrab13 ? Vrab07 : Vrab13;
      Vect01[4] = Vrab08 > Vrab14 ? Vrab08 : Vrab14;
      Vect01[5] = Vrab09 > Vrab15 ? Vrab09 : Vrab15;
     } Vect02.resize(Vrab03);
     while(Vrab03 != 0)
     {
      Vrab03 -= 1; Vect02[Vrab03].resize(8);
      statics uint8 Vrab04 = L_Input(Enchanted->Setting[0].Player[Vrab03].Up);
      statics uint8 Vrab05 = L_Input(Enchanted->Setting[0].Player[Vrab03].Left);
      statics uint8 Vrab06 = L_Input(Enchanted->Setting[0].Player[Vrab03].Down);
      statics uint8 Vrab07 = L_Input(Enchanted->Setting[0].Player[Vrab03].Right);
      statics uint8 Vrab08 = L_Input(Enchanted->Setting[0].Player[Vrab03].Attack);
      statics uint8 Vrab09 = L_Input(Enchanted->Setting[0].Player[Vrab03].Defend);
      statics uint8 Vrab10 = L_Input(Enchanted->Setting[0].Player[Vrab03].Jump);
      statics uint8 Vrab11 = L_Input(Enchanted->Setting[0].Player[Vrab03].Command);
      statics uint8 Vrab12 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Up);
      statics uint8 Vrab13 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Left);
      statics uint8 Vrab14 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Down);
      statics uint8 Vrab15 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Right);
      statics uint8 Vrab16 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Attack);
      statics uint8 Vrab17 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Defend);
      statics uint8 Vrab18 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Jump);
      statics uint8 Vrab19 = L_Input(Enchanted->Setting[0].Player[Vrab03].P_Command);
      Vect02[Vrab03][0] = Vrab04 > Vrab12 ? Vrab04 : Vrab12; if(Vect01[0] < Vect02[Vrab03][0]) Vect01[0] = Vect02[Vrab03][0];
      Vect02[Vrab03][1] = Vrab05 > Vrab13 ? Vrab05 : Vrab13; if(Vect01[1] < Vect02[Vrab03][1]) Vect01[1] = Vect02[Vrab03][1];
      Vect02[Vrab03][2] = Vrab06 > Vrab14 ? Vrab06 : Vrab14; if(Vect01[2] < Vect02[Vrab03][2]) Vect01[2] = Vect02[Vrab03][2];
      Vect02[Vrab03][3] = Vrab07 > Vrab15 ? Vrab07 : Vrab15; if(Vect01[3] < Vect02[Vrab03][3]) Vect01[3] = Vect02[Vrab03][3];
      Vect02[Vrab03][4] = Vrab08 > Vrab16 ? Vrab08 : Vrab16; if(Vect01[4] < Vect02[Vrab03][4]) Vect01[4] = Vect02[Vrab03][4];
      Vect02[Vrab03][5] = Vrab09 > Vrab17 ? Vrab09 : Vrab17; if(Vect01[5] < Vect02[Vrab03][5]) Vect01[5] = Vect02[Vrab03][5];
      Vect02[Vrab03][6] = Vrab10 > Vrab18 ? Vrab10 : Vrab18; if(Vect01[6] < Vect02[Vrab03][6]) Vect01[6] = Vect02[Vrab03][6];
      Vect02[Vrab03][7] = Vrab11 > Vrab19 ? Vrab11 : Vrab19; if(Vect01[7] < Vect02[Vrab03][7]) Vect01[7] = Vect02[Vrab03][7];
     }
    }
    
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

   // Finalizer.
    {
     // Exit.
     {
      if(Enchanted->Vrab005 == 0)
      if(L_Input(Vrab0017) == 1)
      {
       statics insize Vrab03 = Enchanted->Info.size(); insize Vrab04 = 0;
       while(Vrab03 != Vrab04)
       {
        if(Enchanted->Info[Vrab04].String == ("Press \"" + Enchanted->Input_Name(Vrab0017) + "\" once again to exit."))
        Vrab0030 = 1;
        Vrab04 += 1;
       } if(Vrab03 == Vrab04)
       {
        Enchanted->Post_Info("Press \"" + Enchanted->Input_Name(Vrab0017) + "\" once again to exit.", true);
 
        /* ID3D11Debug* Debg01;
        Game0001->m_deviceResources->GetD3DDevice()->QueryInterface < ID3D11Debug > (&Debg01);
        ThrowIfFailed(Debg01->ReportLiveDeviceObjects(D3D11_RLDO_DETAIL));*/
       }
      }
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
       if(Enchanted->Vrab011 + 0.00025 * rxint64(Vrab0003) > 1.0)
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
       if(Enchanted->Info[Vrab03].Volume) Enchanted->Info[Vrab03].String = "Volume is adjusted to " + std::to_string(Enchanted->Setting[0].Volume) + "%.";
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
          int64 Vrab11 = 29;
          {
           insize Vrab12 = 0, Vrab13 = 0, Vrab14 = Vrab04; while(Vrab14 > 41){Vrab14 -= 40; if(Enchanted->Info[Vrab03].String.at((Vrab12 * 40) + Vrab13 + 40) == ' '){ Vrab14 -= 1; Vrab13 += 1;} Vrab12 += 1;}
           if(Vrab04 > 41){Vrab11 += 7 + (16 * rint64(Vrab12));} else {Vrab11 += 5;}
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
        {
         insize Vrab09 = 0, Vrab10 = 0, Vrab11 = Vrab04;
         while(Vrab11 > 41){Vrab11 -= 40; if(Enchanted->Info[Vrab03].String.at((Vrab09 * 40) + Vrab10 + 40) == ' '){Vrab11 -= 1; Vrab10 += 1;} Vrab09 += 1;}
         if(Vrab04 > 41){Enchanted->Print_Bar(Vrab05 + 15, Vrab06, 380, 7 + (16 * rint64(Vrab09)));} else{Enchanted->Print_Bar(Vrab05 + 15, Vrab06, 13 + (9 * rint64(Vrab11)), 5);}
        }
        {
         insize Vrab09 = 0, Vrab10 = 0;
         while(Vrab04 > 41){Vrab04 -= 40; statics insize Vrab11 = Vrab09 * 40; string Temp01 = string(Enchanted->Info[Vrab03].String, Vrab11 + Vrab10, 40); if(Enchanted->Info[Vrab03].String.at(Vrab11 + Vrab10 + 40) != ' '){if(Enchanted->Info[Vrab03].String.at(Vrab11 + Vrab10 + 39) != ' ') Temp01.push_back('-');} else {Vrab04 -= 1; Vrab10 += 1;} Enchanted->Print_Text(Vrab05 + 30, Vrab06 - 6 + (16 * rint64(Vrab09)), 0, Temp01); Vrab09 += 1;}
         Enchanted->Print_Text(Vrab05 + 30, Vrab06 - 6 + (16 * rint64(Vrab09)), 0, string(Enchanted->Info[Vrab03].String, (Vrab09 * 40) + Vrab10, Vrab04));
        }
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
     if(Enchanted->Setting[0].Show_FPS) Enchanted->Print_Text(3, 0, 0, std::to_string(Vrab01) + "|" + std::to_string(Vrab02));
    }
  }
  int0 EIDP_LF2Forevered(uint32 Vrab01, uint64 Vrab02) perfect
  {
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
//  Althought a documentation should be explicit about many stuffs, i only document the major.
//  And sorry for my bad english, i hope you found this useful.
// 
//  There are three things that a must platform should provide, which is ;
//  - Display
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
//    
//  - Audio
//    Currently, this engine only support ".wav" format, which is limited in higher level of audio management.
//    To play an audio, you have to load the audio first by using "P_Load_Sound()", it has one member that's the file address,
//    return a number that will be used by "P_Set_Sound()" or "P_Set_Music()".
//    
//    The different between "P_Set_Sound()" and "P_Set_Music()" is just that "P_Set_Music()" will keep repeat
//    
/////////////////////