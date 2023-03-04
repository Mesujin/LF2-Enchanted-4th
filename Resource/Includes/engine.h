////////////////////////////////////////////////////////////////////////////////////////////
// "engine.h"                                                                             //
//                                                                                        //
// Main source of "Hepta: Enchanted".                                                     //
// Dunno what to text here, but this is my usual style for a header text...               //
//                                                                                        //
// Under GNU General Public License v3.0.                                                 //
// Last modify - 2023 01 17 4:39 PM                                                       //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef _HEPTA_PRAGMA_ENGINE_H
 #define _HEPTA_PRAGMA_ENGINE_H
 // Commands
  #include <chrono>
  #include <filesystem>
  #include "platform.h"
 //-//
 // Earlier Function Declaration
  int0   LF2_Enchanted(uint32, uint64) fastened;
  uint8  L_Input(uint8) fastened;
  int32  L_Numbering(string) fastened;
  int32  L_Rounding(xint64) fastened;
  int64  L_Rounding64(xint64) fastened;
  xint64 L_Doubling(string) fastened;
  string L_Number(insize) fastened;
  string L_Lowercase(string) fastened;
  string L_Spacemaker(string) fastened;
  string L_Execute(statics string) fastened;
  string L_Rename(string, string) fastened;
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
   uint64 Varb0016 = 0;               // Random Counter
   uint64 Varb0017 = 0;               // Random Counter 2
   uint64 Varb0018 = 0;               // Random Counter 3
   uint8  Varb0019 = 52;              // Common ESC   - Keyboard
   uint8  Varb0020 = 70;              // Common Enter - Keyboard
   uint8  Varb0021 = 48;              // Common Up    - Keyboard
   uint8  Varb0022 = 49;              // Common Left  - Keyboard
   uint8  Varb0023 = 50;              // Common Down  - Keyboard
   uint8  Varb0024 = 51;              // Common Right - Keyboard
   int1   Varb0025 = false;           // LF2 : Enchanted 4th Available?
   int1   Varb0026 = false;           // LF2 : Enchanted 4th?
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

     int1  RESH_CAPS;
    };

    struct HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW
    {
     xint64 X = 0; xint64 Y = 0; xint64 Z = 0; insize D = 0; int1 F = false;
    };
    struct HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW
    {
     uint8 Type = 0;
     insize Pic = rinsize(-1);
     int64 X = 0; int64 Y = 0;
    };
    struct HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW
    {
     string Name;
     xint64 HP = 0; xint64 DHP = 0; xint64 MHP = 0; xint64 MP = 0; xint64 MMP = 0;
     insize Pic = rinsize(-1); insize Pic_M = rinsize(-1); uint8 Team = 0; uint8 Player = 0; int1 Facing = false; int1 Shadow = true;
     int64 X = 0; int64 Y = 0; int64 Z = 0; int64 CenX = 0; int64 CenY = 0; int64 W = 0;
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
     insize sound_index = rinsize(-1);
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_BPOINT > bpoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_CPOINT > cpoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_WPOINT > wpoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_OPOINT > opoint;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_IPOINT > itr;
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME_HPOINT > bdy;
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
     std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT_FRAME > Frame;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT
    {
     int1 Exist = true; int1 Lock = false; int1 Facing = false; int1 Landing = false;
     insize Frame = 0, Wait = 0, Team = 0, Owner = 0;
     xint64 X = 0, Y = 0, Z = 0; insize D = 0;
     xint64 X_Vel = 0, Y_Vel = 0, Z_Vel = 0;
     uint32 Walk_Animation = 0; uint32 Walk_Phase = 0;
     uint32 Run_Animation = 0; uint32 Run_Phase = 0;



     uint8  Player = 9;
     insize Index = 0;
     string Name;
     xint64 MHP = 0, DHP = 0, HP = 0, SP = 0, MMP = 0, MP = 0;
     int32  Blink = 0;
     
     
     
     int1  In_A = false, In_D = false, In_J = false, In_C = false, In_Up = false, In_Left = false, In_Down = false, In_Right = false;
     uint8 Input_A = 0, Input_D = 0, Input_J = 0, Input_C = 0, Input_Up = 0, Input_Left = 0, Input_Down = 0, Input_Right = 0;
     uint8 Cast_A = 0, Cast_D = 0, Cast_J = 0, Cast_RR = 0, Cast_LL = 0, Cast_DRA = 0, Cast_DLA = 0, Cast_DRJ = 0, Cast_DLJ = 0, Cast_DDA = 0, Cast_DDJ = 0, Cast_DUA = 0, Cast_DUJ = 0, Cast_DJA = 0;
     HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT *Data;
    };
    struct HEPTA_LF2_ENCHANTED_ENGINE1
    {
     HEPTA_LF2_ENCHANTED_ENGINE1()
     {
      std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out); if(File01.is_open()){File01 << "[] INFO - Engine1 : Origin - Starting.\n";}
     }
     int0   Start(statics uint8 Vrab01, statics insize Vrab02, statics uint8 Vrab03, statics insize Vrab04)
     {
      Independent_Team = 5; Mode = Vrab01; Background = Vrab02; Difficult = Vrab03; Max = Vrab04; Object.clear(); Animation[Background].clear(); if(Backgrounds[Background].width < 800) Backgrounds[Background].Shift = L_Rounding(rxint64(800 - Backgrounds[Background].width) / 2);
     }
     int0   Set(statics uint8 Vrab01, statics insize Vrab02, statics uint8 Vrab03, statics string Temp01)
     {
      statics insize Vrab04 = Object.size(); Object.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT());
      if(Vrab03 == 0){Object[Vrab04].Team = Independent_Team; Independent_Team += 1;} else {Object[Vrab04].Team = Vrab03 - 1;}
      Object[Vrab04].Player = Vrab01 + 1;
      Object[Vrab04].Name = Temp01;
      Object[Vrab04].Data = &Objects[Vrab02];
      Object[Vrab04].Lock = true; Object[Vrab04].HP = 500; Object[Vrab04].DHP = 500; Object[Vrab04].MHP = 500; Object[Vrab04].MP = 200; Object[Vrab04].MMP = 500;
     }
     int0   Input(statics uint8 Vrab01, statics int1 Vrab02, statics int1 Vrab03, statics int1 Vrab04, statics int1 Vrab05, statics int1 Vrab06, statics int1 Vrab07, statics int1 Vrab08, statics int1 Vrab09) fastened
     {
      statics insize Vrab10 = Object.size(); insize Vrab11 = 0;
      while(Vrab11 < Vrab10){if(Object[Vrab11].Player == Vrab01 + 1) break; Vrab11 += 1;}
      Object[Vrab11].In_Up = Vrab02;
      Object[Vrab11].In_Left = Vrab03;
      Object[Vrab11].In_Down = Vrab04;
      Object[Vrab11].In_Right = Vrab05;
      Object[Vrab11].In_A = Vrab06;
      Object[Vrab11].In_J = Vrab07;
      Object[Vrab11].In_D = Vrab08;
      Object[Vrab11].In_C = Vrab09;
     }
     std::vector < HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW > Run()
     {
      std::vector < HEPTA_LF2_ENCHANTED_PROSPECTIVE_DRAW > Vect01;
      {
       std::vector < insize > Vect02; {statics insize Vrab99 = Object.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98) if(Object[Vrab98].Exist) Vect02.push_back(Vrab98);}
       if(Background >= Backgrounds.size()) Background = 0;

       // Phase 1 : Wait, Next, Negative MP, Opoint.
       {
        insize Vrab99 = Vect02.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
        {
         statics insize Vrab97 = Vect02[Vrab98];
         statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) continue; if(!Object[Vrab97].Data->Frame[Vrab96].Exist) continue;
         Object[Vrab97].Wait += 1; if(Object[Vrab97].Data->Frame[Vrab96].state == 14 && Object[Vrab97].HP <= 0) Object[Vrab97].Wait = 0;
         {
          int32 Vrab95 = Object[Vrab97].Data->Frame[Vrab96].next;
          if(Object[Vrab97].Wait > ruint32(Object[Vrab97].Data->Frame[Vrab96].wait) && Vrab95 != 0)
          {
           if(Object[Vrab97].Data->Frame[Vrab96].state == 14 && Object[Vrab97].Wait >= 20) Object[Vrab97].Blink = -45;
           Object[Vrab97].Wait = 0; if(Vrab95 == 0) continue;
           if(Vrab95 < 0){Vrab95 = -Vrab95; Object[Vrab97].Facing = !Object[Vrab97].Facing;}
           if(Vrab95 == 1000 || Vrab95 == 9998){Remove(Vrab97); continue;}
           Object[Vrab97].Frame = ruint32(Vrab95);
           if(Object[Vrab97].Frame == 212)
           {
            Object[Vrab97].Landing = true;
            statics xint64 Vrab94 = Object[Vrab97].Data->jump_height; if((Vrab94 > 0 && Object[Vrab97].Y_Vel < Vrab94) || (Vrab94 < 0 && Object[Vrab97].Y_Vel > Vrab94)) Object[Vrab97].Y_Vel = Vrab94;
            statics xint64 Vrab93 = Object[Vrab97].Data->jump_distance, Vrab92 = Object[Vrab97].Data->jump_distancez;
            if(Object[Vrab97].Input_Left >= 1 && Object[Vrab97].Input_Right == 0) if((Vrab93 > 0 && Object[Vrab97].X_Vel > -Vrab93) || (Vrab93 < 0 && Object[Vrab97].X_Vel < -Vrab93)) Object[Vrab97].X_Vel = -Vrab93;
            if(Object[Vrab97].Input_Right >= 1 && Object[Vrab97].Input_Left == 0) if((Vrab93 > 0 && Object[Vrab97].X_Vel < Vrab93) || (Vrab93 < 0 && Object[Vrab97].X_Vel > Vrab93)) Object[Vrab97].X_Vel = Vrab93;
            if(Object[Vrab97].Input_Up >= 1 && Object[Vrab97].Input_Down == 0) if((Vrab92 > 0 && Object[Vrab97].Z_Vel > -Vrab92) || (Vrab92 < 0 && Object[Vrab97].Z_Vel < -Vrab92)) Object[Vrab97].Z_Vel = -Vrab92;
            if(Object[Vrab97].Input_Down >= 1 && Object[Vrab97].Input_Up == 0) if((Vrab92 > 0 && Object[Vrab97].Z_Vel < Vrab92) || (Vrab92 < 0 && Object[Vrab97].Z_Vel > Vrab92)) Object[Vrab97].Z_Vel = Vrab92;
           }
           if(Object[Vrab97].Frame >= Object[Vrab97].Data->Frame.size()) continue; if(!Object[Vrab97].Data->Frame[Object[Vrab97].Frame].Exist) continue;
           if((Object[Vrab97].Frame >= 1100 && Object[Vrab97].Frame <= 1299) || Object[Vrab97].Frame == 999) continue;
           statics int32 Vrab94 = Object[Vrab97].Data->Frame[Object[Vrab97].Frame].mp;
           if(Vrab94 < 0)
           {
            Object[Vrab97].MP -= rxint64(-Vrab94);
            if(Object[Vrab97].MP < rxint64(-Vrab94))
            {
             int32 Vrab93 = Object[Vrab97].Data->Frame[Object[Vrab97].Frame].hit_d; if(Vrab93 < 0){Vrab93 = -Vrab93; Object[Vrab97].Facing = !Object[Vrab97].Facing;}
             if(Vrab93 == 1000 || Vrab93 == 9998){Remove(Vrab97); continue;}
             Object[Vrab97].Frame = Vrab93;
            }
           }
          }
         }
         if(Object[Vrab97].Wait == 0)
         {
          statics insize Vrab95 = Object[Vrab97].Data->Frame[Vrab96].opoint.size(); for(insize Vrab94 = 0; Vrab94 < Vrab95; ++Vrab94)
          {
           statics int32 Vrab93 = Object[Vrab97].Data->Frame[Vrab96].opoint[Vrab94].kind;
           if(Vrab93 == 1)
           {
            statics insize Vrab92 = rinsize(Object[Vrab97].Data->Frame[Vrab96].opoint[Vrab94].oid);
            statics insize Vrab91 = Add(Vrab92); if(Vrab91 != rinsize(-1))
            {
             Vect02.push_back(Vrab91); Vrab99 += 1;
             Object[Vrab91].Facing = Object[Vrab97].Facing; Object[Vrab91].Team = Object[Vrab97].Team; Object[Vrab91].Name = Object[Vrab97].Name;
             if(Object[Vrab97].Facing)
             {Object[Vrab91].X = Object[Vrab97].X - rxint64(Object[Vrab97].Data->Frame[Vrab96].centery) + rxint64(Object[Vrab97].Data->Frame[Vrab96].opoint[Vrab94].x);} else
             {Object[Vrab91].X = Object[Vrab97].X + rxint64(Object[Vrab97].Data->Frame[Vrab96].centery) - rxint64(Object[Vrab97].Data->Frame[Vrab96].opoint[Vrab94].x);}
             Object[Vrab91].Y = Object[Vrab97].Y - rxint64(Object[Vrab97].Data->Frame[Vrab96].centery) + rxint64(Object[Vrab97].Data->Frame[Vrab96].opoint[Vrab94].y);
             Object[Vrab91].Z = Object[Vrab97].Z + 1.0; Object[Vrab91].Frame = rinsize(Object[Vrab97].Data->Frame[Vrab96].opoint[Vrab94].action);
            }
            continue;
           }
          }
         }
        }
        {Vect02.clear(); statics insize Vrab98 = Object.size(); for(insize Vrab97 = 0; Vrab97 < Vrab98; ++Vrab97) if(Object[Vrab97].Exist) Vect02.push_back(Vrab97);}
       }

       // Phase 2 : Friction, Input Manage, Hardcoded Input, Hardcoded Next, Cast & Input, Position Shift.
       {
        insize Vrab99 = Vect02.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
        {
         statics insize Vrab97 = Vect02[Vrab98];

         // Friction
          {
           if(Object[Vrab97].Y < 0){Object[Vrab97].Y_Vel += 1.7;} else
           {
            if(Object[Vrab97].X_Vel > 0) if(Object[Vrab97].X_Vel - 1 < 0){Object[Vrab97].X_Vel = 0;} else {Object[Vrab97].X_Vel -= 1;}
            if(Object[Vrab97].X_Vel < 0) if(Object[Vrab97].X_Vel + 1 > 0){Object[Vrab97].X_Vel = 0;} else {Object[Vrab97].X_Vel += 1;}
            if(Object[Vrab97].Z_Vel > 0) if(Object[Vrab97].Z_Vel - 1 < 0){Object[Vrab97].Z_Vel = 0;} else {Object[Vrab97].Z_Vel -= 1;}
            if(Object[Vrab97].Z_Vel < 0) if(Object[Vrab97].Z_Vel + 1 > 0){Object[Vrab97].Z_Vel = 0;} else {Object[Vrab97].Z_Vel += 1;}
           }
          }

         // Input Manage
          {
           if(Object[Vrab97].Cast_A > 0) Object[Vrab97].Cast_A -= 1;
           if(Object[Vrab97].Cast_D > 0) Object[Vrab97].Cast_D -= 1;
           if(Object[Vrab97].Cast_J > 0) Object[Vrab97].Cast_J -= 1;
           if(Object[Vrab97].Cast_LL > 0) if(Object[Vrab97].Cast_LL < 246){Object[Vrab97].Cast_LL -= 1;} else {Object[Vrab97].Cast_LL += 1;}
           if(Object[Vrab97].Cast_RR > 0) if(Object[Vrab97].Cast_RR < 246){Object[Vrab97].Cast_RR -= 1;} else {Object[Vrab97].Cast_RR += 1;}
           if(Object[Vrab97].In_Up)   {if((++Object[Vrab97].Input_Up) == 255ui8) Object[Vrab97].Input_Up = 250ui8;} else {Object[Vrab97].Input_Up = 0ui8;}
           if(Object[Vrab97].In_Left) {if((++Object[Vrab97].Input_Down) == 255ui8) Object[Vrab97].Input_Down = 250ui8;} else {Object[Vrab97].Input_Down = 0ui8;}
           if(Object[Vrab97].In_Down) {if((++Object[Vrab97].Input_Left) == 255ui8) Object[Vrab97].Input_Left = 250ui8;} else {Object[Vrab97].Input_Left = 0ui8;}
           if(Object[Vrab97].In_Right){if((++Object[Vrab97].Input_Right) == 255ui8) Object[Vrab97].Input_Right = 250ui8;} else {Object[Vrab97].Input_Right = 0ui8;}
           if(Object[Vrab97].In_A)    {if((++Object[Vrab97].Input_A) == 255ui8) Object[Vrab97].Input_A = 250ui8;} else {Object[Vrab97].Input_A = 0ui8;}
           if(Object[Vrab97].In_J)    {if((++Object[Vrab97].Input_J) == 255ui8) Object[Vrab97].Input_J = 250ui8;} else {Object[Vrab97].Input_J = 0ui8;}
           if(Object[Vrab97].In_D)    {if((++Object[Vrab97].Input_D) == 255ui8) Object[Vrab97].Input_D = 250ui8;} else {Object[Vrab97].Input_D = 0ui8;}
           if(Object[Vrab97].In_C)    {if((++Object[Vrab97].Input_C) == 255ui8) Object[Vrab97].Input_C = 250ui8;} else {Object[Vrab97].Input_C = 0ui8;}
           if(Object[Vrab97].Input_D == 1){Object[Vrab97].Cast_D = 5; Object[Vrab97].Cast_DRA = 1; Object[Vrab97].Cast_DLA = 1; Object[Vrab97].Cast_DRJ = 1; Object[Vrab97].Cast_DLJ = 1; Object[Vrab97].Cast_DDA = 1; Object[Vrab97].Cast_DDJ = 1; Object[Vrab97].Cast_DUA = 1; Object[Vrab97].Cast_DUJ = 1; Object[Vrab97].Cast_DJA = 1;}
           if(Object[Vrab97].Input_Left == 1) {if(Object[Vrab97].Cast_LL > 0){if(Object[Vrab97].Cast_LL < 246){Object[Vrab97].Cast_LL = 253;} else {Object[Vrab97].Cast_LL = 0;}} else {Object[Vrab97].Cast_LL = 10;} Object[Vrab97].Cast_RR = 0; if(Object[Vrab97].Cast_DLA == 1){Object[Vrab97].Cast_DLA = 2;} else {Object[Vrab97].Cast_DLA = 0;} if(Object[Vrab97].Cast_DLJ == 1){Object[Vrab97].Cast_DLJ = 2;} else {Object[Vrab97].Cast_DLJ = 0;} Object[Vrab97].Cast_DRA = 0; Object[Vrab97].Cast_DRJ = 0; Object[Vrab97].Cast_DDA = 0; Object[Vrab97].Cast_DDJ = 0; Object[Vrab97].Cast_DUA = 0; Object[Vrab97].Cast_DUJ = 0; Object[Vrab97].Cast_DJA = 0;}
           if(Object[Vrab97].Input_Right == 1){if(Object[Vrab97].Cast_RR > 0){if(Object[Vrab97].Cast_RR < 246){Object[Vrab97].Cast_RR = 253;} else {Object[Vrab97].Cast_RR = 0;}} else {Object[Vrab97].Cast_RR = 10;} Object[Vrab97].Cast_LL = 0; if(Object[Vrab97].Cast_DRA == 1){Object[Vrab97].Cast_DRA = 2;} else {Object[Vrab97].Cast_DRA = 0;} if(Object[Vrab97].Cast_DRJ == 1){Object[Vrab97].Cast_DRJ = 2;} else {Object[Vrab97].Cast_DRJ = 0;} Object[Vrab97].Cast_DLA = 0; Object[Vrab97].Cast_DLJ = 0; Object[Vrab97].Cast_DDA = 0; Object[Vrab97].Cast_DDJ = 0; Object[Vrab97].Cast_DUA = 0; Object[Vrab97].Cast_DUJ = 0; Object[Vrab97].Cast_DJA = 0;}
           if(Object[Vrab97].Input_Up == 1)  {if(Object[Vrab97].Cast_DUA == 1){Object[Vrab97].Cast_DUA = 2;} else {Object[Vrab97].Cast_DUA = 0;} if(Object[Vrab97].Cast_DUJ == 1){Object[Vrab97].Cast_DUJ = 2;} else {Object[Vrab97].Cast_DUJ = 0;} Object[Vrab97].Cast_DLA = 0; Object[Vrab97].Cast_DLJ = 0; Object[Vrab97].Cast_DRA = 0; Object[Vrab97].Cast_DRJ = 0; Object[Vrab97].Cast_DDA = 0; Object[Vrab97].Cast_DDJ = 0; Object[Vrab97].Cast_DJA = 0;}
           if(Object[Vrab97].Input_Down == 1){if(Object[Vrab97].Cast_DDA == 1){Object[Vrab97].Cast_DDA = 2;} else {Object[Vrab97].Cast_DDA = 0;} if(Object[Vrab97].Cast_DDJ == 1){Object[Vrab97].Cast_DDJ = 2;} else {Object[Vrab97].Cast_DDJ = 0;} Object[Vrab97].Cast_DLA = 0; Object[Vrab97].Cast_DLJ = 0; Object[Vrab97].Cast_DRA = 0; Object[Vrab97].Cast_DRJ = 0; Object[Vrab97].Cast_DUA = 0; Object[Vrab97].Cast_DUJ = 0; Object[Vrab97].Cast_DJA = 0;}
           if(Object[Vrab97].Input_J == 1){Object[Vrab97].Cast_J = 5; if(Object[Vrab97].Cast_DRJ == 2){Object[Vrab97].Cast_DRJ = 3;} else {Object[Vrab97].Cast_DRJ = 0;} if(Object[Vrab97].Cast_DLJ == 2){Object[Vrab97].Cast_DLJ = 3;} else {Object[Vrab97].Cast_DLJ = 0;} if(Object[Vrab97].Cast_DDJ == 2){Object[Vrab97].Cast_DDJ = 3;} else {Object[Vrab97].Cast_DDJ = 0;} if(Object[Vrab97].Cast_DUJ == 2){Object[Vrab97].Cast_DUJ = 3;} else {Object[Vrab97].Cast_DUJ = 0;} if(Object[Vrab97].Cast_DJA == 1){Object[Vrab97].Cast_DJA = 2;} else {Object[Vrab97].Cast_DJA = 0;} Object[Vrab97].Cast_DRA = 0; Object[Vrab97].Cast_DLA = 0; Object[Vrab97].Cast_DDA = 0; Object[Vrab97].Cast_DUA = 0;}
           if(Object[Vrab97].Input_A == 1){Object[Vrab97].Cast_A = 5; if(Object[Vrab97].Cast_DRA == 2){Object[Vrab97].Cast_DRA = 3;} else {Object[Vrab97].Cast_DRA = 0;} if(Object[Vrab97].Cast_DLA == 2){Object[Vrab97].Cast_DLA = 3;} else {Object[Vrab97].Cast_DLA = 0;} if(Object[Vrab97].Cast_DDA == 2){Object[Vrab97].Cast_DDA = 3;} else {Object[Vrab97].Cast_DDA = 0;} if(Object[Vrab97].Cast_DUA == 2){Object[Vrab97].Cast_DUA = 3;} else {Object[Vrab97].Cast_DUA = 0;} if(Object[Vrab97].Cast_DJA == 2){Object[Vrab97].Cast_DJA = 3;} else {Object[Vrab97].Cast_DJA = 0;} Object[Vrab97].Cast_DRJ = 0; Object[Vrab97].Cast_DLJ = 0; Object[Vrab97].Cast_DDJ = 0; Object[Vrab97].Cast_DUJ = 0;}
          } 

         // Hardcoded Input
         while(true)
         {
          {
           statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab96].Exist) break;
           int32 Vrab95 = Object[Vrab97].Data->Frame[Vrab96].state;
           {
            int1 Vrab94 = false;
            switch(Vrab96)
            {
             case 110: case 212: Vrab94 = true; break;
             default: break;
            }
            switch(Vrab95)
            {
             case 0: case 1: case 4: case 5: Vrab94 = true; break;
             default: break;
            }
            if(Vrab94){if(Object[Vrab97].Input_Left >= 1 && Object[Vrab97].Input_Right == 0) Object[Vrab97].Facing = false; if(Object[Vrab97].Input_Right >= 1 && Object[Vrab97].Input_Left == 0) Object[Vrab97].Facing = true;}
           }
           if(Vrab95 == 0 || Vrab95 == 1)
           {
            if(Object[Vrab97].Cast_LL >= 246){Vrab95 = 2; Object[Vrab97].Facing = false;}
            if(Object[Vrab97].Cast_RR >= 246){Vrab95 = 2; Object[Vrab97].Facing = true;}
           }
           if(Vrab95 == 0 || Vrab95 == 1)
           {
            xint64 Vrab94 = Object[Vrab97].Data->walking_speed; xint64 Vrab93 = Object[Vrab97].Data->walking_speedz; int1 Vrab92 = false;
            if(Object[Vrab97].Input_Up >= 1 && Object[Vrab97].Input_Down == 0){Vrab94 *= 0.714285185; if(Object[Vrab97].Z_Vel > -Vrab93) Object[Vrab97].Z_Vel = -Vrab93; Vrab92 = true;}
            if(Object[Vrab97].Input_Down >= 1 && Object[Vrab97].Input_Up == 0){Vrab94 *= 0.714285185; if(Object[Vrab97].Z_Vel < Vrab93) Object[Vrab97].Z_Vel = Vrab93; Vrab92 = true;}
            if(Object[Vrab97].Input_Left >= 1 && Object[Vrab97].Input_Right == 0){if(Object[Vrab97].X_Vel > -Vrab94) Object[Vrab97].X_Vel = -Vrab94; Vrab92 = true;}
            if(Object[Vrab97].Input_Right >= 1 && Object[Vrab97].Input_Left == 0){if(Object[Vrab97].X_Vel < Vrab94) Object[Vrab97].X_Vel = Vrab94; Vrab92 = true;}
            if(Vrab92)
            {
             Object[Vrab97].Walk_Animation += 1; if(Object[Vrab97].Walk_Animation >= Object[Vrab97].Data->walking_frame_rate){Object[Vrab97].Walk_Animation = 0; Object[Vrab97].Walk_Phase += 1; if(Object[Vrab97].Walk_Phase > 5) Object[Vrab97].Walk_Phase = 0;}
             switch(Object[Vrab97].Walk_Phase)
             {
              case 1: case 5: Object[Vrab97].Frame = 6; break;
              case 2: case 4: Object[Vrab97].Frame = 7; break;
              case 3: Object[Vrab97].Frame = 8; break;
              default: Object[Vrab97].Frame = 5; break;
             }
             Object[Vrab97].Wait = 0;
            }
           }
           if(Vrab95 == 2)
           {
            xint64 Vrab94 = Object[Vrab97].Data->running_speed, Vrab93 = Object[Vrab97].Data->running_speedz;
            if(Object[Vrab97].Input_Up >= 1 && Object[Vrab97].Input_Down == 0){Vrab94 *= 0.833333333; if(Object[Vrab97].Z_Vel > -Vrab93) Object[Vrab97].Z_Vel = -Vrab93;}
            if(Object[Vrab97].Input_Down >= 1 && Object[Vrab97].Input_Up == 0){Vrab94 *= 0.833333333; if(Object[Vrab97].Z_Vel < Vrab93) Object[Vrab97].Z_Vel = Vrab93;}
            Object[Vrab97].Run_Animation += 1; if(Object[Vrab97].Run_Animation >= Object[Vrab97].Data->running_frame_rate){Object[Vrab97].Run_Animation = 0; Object[Vrab97].Run_Phase += 1; if(Object[Vrab97].Run_Phase > 3) Object[Vrab97].Run_Phase = 0;}
            switch(Object[Vrab97].Run_Phase)
            {
             case 1: case 3: Object[Vrab97].Frame = 10; break;
             case 2: Object[Vrab97].Frame = 11; break;
             default: Object[Vrab97].Frame = 9; break;
            }
            if(Object[Vrab97].Facing)
            {
             if(Object[Vrab97].X_Vel < Vrab94) Object[Vrab97].X_Vel = Vrab94;
             if(Object[Vrab97].Input_Left >= 1) Object[Vrab97].Frame = 218;
            } else
            {
             if(Object[Vrab97].X_Vel > -Vrab94) Object[Vrab97].X_Vel = -Vrab94;
             if(Object[Vrab97].Input_Right >= 1) Object[Vrab97].Frame = 218;
            }
            Object[Vrab97].Wait = 0;
           }
          }
          
          statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab96].Exist) break;
          statics int32 Vrab95 = Object[Vrab97].Data->Frame[Vrab96].state;
          if(true)
          {
           if(Vrab95 == 0 || Vrab95 == 1)
           {
            if(Object[Vrab97].Cast_J > 0){Object[Vrab97].Frame = 210; Object[Vrab97].Wait = 0; Object[Vrab97].Cast_J = 0;}
            if(Object[Vrab97].Cast_D > 0){Object[Vrab97].Frame = 110; Object[Vrab97].Wait = 0; Object[Vrab97].Cast_D = 0;}
           }
           if(Vrab96 == 215)
           {
            if(Object[Vrab97].Cast_D > 0){Object[Vrab97].Frame = 102; Object[Vrab97].Wait = 0; Object[Vrab97].Cast_D = 0;}
            if(Object[Vrab97].Cast_J > 0){Object[Vrab97].Frame = 213; Object[Vrab97].Wait = 0; Object[Vrab97].Cast_J = 0;}
           }
          }
          break;
         }

         // Hardcoded Next
         {
          if(Object[Vrab97].Frame == 999){if(Object[Vrab97].Y < 0){Object[Vrab97].Frame = 212; Object[Vrab97].Landing = true;} else {Object[Vrab97].Frame = 0;} continue;}
          if(Object[Vrab97].Frame >= 1100 && Object[Vrab97].Frame <= 1299){Object[Vrab97].Frame = 0; Object[Vrab97].Blink = Object[Vrab97].Frame - 1100; continue;}
         }

         // Cast & Input
         while(true)
         {
          statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab96].Exist) break;


          break;
         }

         //Position Shift
         {
          statics xint64 Vrab96 = rxint64(Backgrounds[Background].Shift), Vrab95 = Vrab96 + rxint64(Backgrounds[Background].width), Vrab94 = rxint64(Backgrounds[Background].zboundary[0]), Vrab93 = rxint64(Backgrounds[Background].zboundary[1]);
          if(Object[Vrab97].Lock)
          {
           if(Object[Vrab97].X < Vrab96) Object[Vrab97].X = Vrab96; if(Object[Vrab97].X > Vrab95) Object[Vrab97].X = Vrab95;
           if(Object[Vrab97].Z < Vrab94) Object[Vrab97].Z = Vrab94; if(Object[Vrab97].Z > Vrab93) Object[Vrab97].Z = Vrab93;
          } else
          {
           if(Object[Vrab97].X < Vrab96 - 200) Object[Vrab97].X = Vrab96 - 200; if(Object[Vrab97].X > Vrab95 + 200) Object[Vrab97].X = Vrab95 + 200;
           if(Object[Vrab97].Z < Vrab94) Object[Vrab97].Z = Vrab94; if(Object[Vrab97].Z > Vrab93) Object[Vrab97].Z = Vrab93;
          }
         }
        }
       }

       // Phase 3 : Velocity, Landing, Position Shift.
       {
        insize Vrab99 = Vect02.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
        {
         statics insize Vrab97 = Vect02[Vrab98];
         {
          while(true)
          {
           statics insize Vrab96 = Object[Vrab97].Frame; if(Vrab96 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab96].Exist) break;
           statics xint64 Vrab95 = rxint64(Object[Vrab97].Data->Frame[Vrab96].dvx), Vrab94 = rxint64(Object[Vrab97].Data->Frame[Vrab96].dvy), Vrab93 = rxint64(Object[Vrab97].Data->Frame[Vrab96].dvz);
           statics int1 Vrab92 = Object[Vrab97].Facing;
           if(Vrab95 < 0) if(Vrab92){if(Object[Vrab97].X_Vel > Vrab95) Object[Vrab97].X_Vel = Vrab95;} else {if(Object[Vrab97].X_Vel < -Vrab95) Object[Vrab97].X_Vel = -Vrab95;}
           if(Vrab95 > 0 && Vrab95 < 500) if(Vrab92){if(Object[Vrab97].X_Vel < Vrab95) Object[Vrab97].X_Vel = Vrab95;} else {if(Object[Vrab97].X_Vel > -Vrab95) Object[Vrab97].X_Vel = -Vrab95;}
           if(Vrab95 >= 500) Object[Vrab97].X_Vel = Vrab95 - 550;
           if(Vrab94 < 0) if(Object[Vrab97].Y_Vel > Vrab94) Object[Vrab97].Y_Vel = Vrab94;
           if(Vrab94 > 0 && Vrab94 < 500) if(Object[Vrab97].Y_Vel < Vrab94) Object[Vrab97].Y_Vel = Vrab94;
           if(Vrab94 >= 500) Object[Vrab97].Y_Vel = Vrab94 - 550;
           if(Vrab93 < 0) if(Object[Vrab97].X_Vel > Vrab93) Object[Vrab97].X_Vel = Vrab93;
           if(Vrab93 > 0 && Vrab93 < 500) if(Object[Vrab97].X_Vel < Vrab93) Object[Vrab97].X_Vel = Vrab93;
           if(Vrab93 >= 500) Object[Vrab97].X_Vel = Vrab93 - 550;
           break;
          }
          Object[Vrab97].X += Object[Vrab97].X_Vel; Object[Vrab97].Z += Object[Vrab97].Z_Vel;
          if(Object[Vrab97].Y_Vel != 0)
          {
           Object[Vrab97].Y += Object[Vrab97].Y_Vel;
           if(Object[Vrab97].Y >= 0)
           {
            int1 Vrab96 = true;
            while(true){statics insize Vrab95 = Object[Vrab97].Frame; if(Vrab95 >= Object[Vrab97].Data->Frame.size()) break; if(!Object[Vrab97].Data->Frame[Vrab95].Exist) break; if(Object[Vrab97].Data->Frame[Vrab95].state == 100) Vrab96 = true; break;}
            if(Vrab96)
            {
             if(Object[Vrab97].Landing){Object[Vrab97].Frame = 215;} else {Object[Vrab97].Frame = 219;}
            } else {Object[Vrab97].Frame = 94;}
            Object[Vrab97].Landing = false; if(Object[Vrab97].X_Vel != 0) Object[Vrab97].X_Vel /= 3; Object[Vrab97].Y_Vel = 0; Object[Vrab97].Y = 0; Object[Vrab97].Wait = 0;
           }
          }
         }
         {
          statics xint64 Vrab96 = rxint64(Backgrounds[Background].Shift), Vrab95 = Vrab96 + rxint64(Backgrounds[Background].width), Vrab94 = rxint64(Backgrounds[Background].zboundary[0]), Vrab93 = rxint64(Backgrounds[Background].zboundary[1]);
          if(Object[Vrab97].Lock)
          {
           if(Object[Vrab97].X < Vrab96) Object[Vrab97].X = Vrab96; if(Object[Vrab97].X > Vrab95) Object[Vrab97].X = Vrab95;
           if(Object[Vrab97].Z < Vrab94) Object[Vrab97].Z = Vrab94; if(Object[Vrab97].Z > Vrab93) Object[Vrab97].Z = Vrab93;
          } else
          {
           if(Object[Vrab97].X < Vrab96 - 200) Object[Vrab97].X = Vrab96 - 200; if(Object[Vrab97].X > Vrab95 + 200) Object[Vrab97].X = Vrab95 + 200;
           if(Object[Vrab97].Z < Vrab94) Object[Vrab97].Z = Vrab94; if(Object[Vrab97].Z > Vrab93) Object[Vrab97].Z = Vrab93;
          }
         }
        }
       }

       // Phase 4 : Interact.

       // Phase 5 : Catch & Weapon.

       // Last Phase : Camera.
       {
        insize Vrab99 = Vect02.size(); for(insize Vrab98 = 0; Vrab98 < Vrab99; ++Vrab98)
        {
         statics insize Vrab97 = Vect02[Vrab98];
         if(Object[Vrab97].Player > 0 && Object[Vrab97].Player <= 4)
         if(Object[Vrab97].HP > 0)
         Vect01.push_back({Object[Vrab97].X, Object[Vrab97].Y, Object[Vrab97].Z, Object[Vrab97].D});
        }
        if(Vect01.size() == 0)
        {
         
        }
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
       statics int64  Vrab09 = Backgrounds[Background].Layer[Vrab04].x + Backgrounds[Background].Shift, Vrab10 = Backgrounds[Background].Layer[Vrab04].y;

       if(Vrab07 != 0){int64 Vrab11 = rint64(Backgrounds[Background].Layer[Vrab04].width); if(Backgrounds[Background].Shift == 0 && Vrab11 == 794) Vrab11 = 800; Vect01.push_back({3, Vrab07, Vrab09, Vrab10}); Vect01.push_back({0, 0, Vrab11, rint64(Backgrounds[Background].Layer[Vrab04].height)});} else
       {
        Animation[Background][Vrab04] += 1; if(Animation[Background][Vrab04] >= ruint32(Backgrounds[Background].Layer[Vrab04].cc)) Animation[Background][Vrab04] = 0; statics uint32 Vrab11 = Animation[Background][Vrab04];
        if(Vrab11 >= ruint32(Backgrounds[Background].Layer[Vrab04].c1) && Vrab11 <= ruint32(Backgrounds[Background].Layer[Vrab04].c2))
        if(Vrab06 == 0)
        {
         if(Vrab08 == 0){Vect01.push_back({2, Vrab05, Vrab09, Vrab10});} else {Vect01.push_back({0, Vrab05, Vrab09, Vrab10});}
        } else
        {
         int64 Vrab12 = 0; statics int64 Vrab13 = rint64(Backgrounds[Background].width);
         while(Vrab12 < Vrab13)
         {
          if(Vrab08 == 0){Vect01.push_back({2, Vrab05, Vrab09 + Vrab12, Vrab10});} else {Vect01.push_back({0, Vrab05, Vrab09 + Vrab12, Vrab10});}
          Vrab12 += rint64(Vrab06);
         }
        }
       }
       Vrab04 += 1;
      }
      return Vect01;
     }
     std::vector < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW > Draw() fastened
     {
      std::vector < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW > Vect01;
      
      {
       std::vector < insize > Vect02; std::vector < uint32 > Vect03; std::vector < xint64 > Vect04;
       insize Vrab01 = Object.size(); while(Vrab01 != 0)
       {
        Vrab01 -= 1;
        statics insize Vrab02 = Vect02.size(); statics uint32 Vrab03 = Object[Vrab01].Data->type; statics xint64 Vrab04 = Object[Vrab01].Z;
        insize Vrab05 = 0; while(Vrab05 != Vrab02)
        {
         if(Vrab04 < Vect04[Vrab05]) break;
         if(Vrab03 < Vect03[Vrab05]) break;
         Vrab05 += 1;
        }
        if(Vrab05 == Vrab02){Vect02.push_back(Vrab01); Vect03.push_back(Vrab03); Vect04.push_back(Vrab04);} else
        {Vect02.insert(Vect02.begin() + Vrab05, Vrab01); Vect03.insert(Vect03.begin() + Vrab05, Vrab03); Vect04.insert(Vect04.begin() + Vrab05, Vrab04);}
       }

       statics insize Vrab02 = Vect02.size(); insize Vrab03 = 0;
       while(Vrab03 != Vrab02)
       {
        Vect01.push_back(HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW()); statics insize Vrab04 = Vect02[Vrab03];
        Vect01[Vrab03].X = L_Rounding64(Object[Vrab04].X); Vect01[Vrab03].Y = L_Rounding64(Object[Vrab04].Y); Vect01[Vrab03].Z = L_Rounding64(Object[Vrab04].Z); if(Object[Vrab04].Data->type == 0) Vect01[Vrab03].Name = Object[Vrab04].Name; Vect01[Vrab03].Player = Object[Vrab04].Player - 1; if(Object[Vrab04].Team < 5) Vect01[Vrab03].Team = ruint8(Object[Vrab04].Team) + 1;
        Vect01[Vrab03].HP = Object[Vrab04].HP; Vect01[Vrab03].DHP = Object[Vrab04].DHP; Vect01[Vrab03].MHP = Object[Vrab04].MHP; Vect01[Vrab03].MP = Object[Vrab04].MP; Vect01[Vrab03].MMP = Object[Vrab04].MMP;
        statics insize Vrab05 = Object[Vrab04].Frame; if(Vrab05 < Object[Vrab04].Data->Frame.size()) if(Object[Vrab04].Data->Frame[Vrab05].Exist)
        {
         statics insize Vrab06 = Object[Vrab04].Data->Frame[Vrab05].pic; statics insize Vrab07 = Object[Vrab04].Data->file_Index.size(); insize Vrab08 = 0;
         while(Vrab08 < Vrab07){if(Vrab06 < Object[Vrab04].Data->file_Index[Vrab08]) break; Vrab08 += 1;}
         if(Vrab08 < Vrab07)
         {
          Vect01[Vrab03].Pic = Object[Vrab04].Data->file[Vrab08].Picture_Index + Vrab06; statics insize Vrab09 = Object[Vrab04].Data->file[Vrab08].Picture_Mirror_Index; if(Vrab09 != rinsize(-1)) Vect01[Vrab03].Pic_M = Vrab09 + Vrab06;
          if(Vrab08 > 0){Vect01[Vrab03].Pic -= Object[Vrab04].Data->file_Index[Vrab08 - 1]; if(Vrab09 != rinsize(-1)) Vect01[Vrab03].Pic_M -= Object[Vrab04].Data->file_Index[Vrab08 - 1];}
          Vect01[Vrab03].Facing = Object[Vrab04].Facing; Vect01[Vrab03].CenX = Object[Vrab04].Data->Frame[Vrab05].centerx; Vect01[Vrab03].CenY = Object[Vrab04].Data->Frame[Vrab05].centery; Vect01[Vrab03].W = Object[Vrab04].Data->file[Vrab08].w;
         }
        }
        Vrab03 += 1;
       }
      }

      return Vect01;
     }
     HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND *Shadow()                                fastened {return &Backgrounds[Background];}
     int1   Warning()                                                                fastened {return Vrab003;}
     int1   Select(statics insize Vrab01, statics uint8 Vrab02)                      fastened
     {
      if(Vrab02 == 0)
      if((Vrab01 >= 0 && Vrab01 <= 29) || Vrab01 >= 100){Selectable_Char.push_back(true); return true;} else {Selectable_Char.push_back(false);}
      return false;
     }
     int1   Random(statics insize Vrab01)                                            fastened {statics insize Vrab02 = Objects[Vrab01].id; if(Vrab02 == 0 || (Vrab02 >= 30 && Vrab02 <= 99)) return false; return true;}
     uint8  Pick(statics insize Vrab01)                                              fastened
     {
      if(Vrab01 >= Selectable_Char.size()) return 2;
      if(Selectable_Char[Vrab01]) return 1; return 0;
     }
     insize Face(statics insize Vrab01)                                              fastened {return Objects[Vrab01].head_Index;}
     insize Range()                                                                  fastened {return Selectable_Char.size();}
     insize Limit()                                                                  fastened {return Backgrounds.size();}
     string Name(statics insize Vrab01)                                              fastened {return Objects[Vrab01].name;}
     string Place(statics insize Vrab01)                                             fastened {return Backgrounds[Vrab01].name;}
     uint8  New(statics insize Vrab01, statics uint8 Vrab02, statics string &Temp01) fastened
     {
      if(File001.is_open()) File001.close(); File001.open(Temp01, std::ios::in | std::ios::binary); if(!File001.is_open()) return 1;
      statics string Temp02 = L_Lowercase(string(Temp01, Temp01.size() - 4, 4)); if(Temp02 != ".dat" && Temp02 != ".txt") return 2;
      if(Temp02 == ".dat")
      {
       stream Strn01; Strn01 << File001.rdbuf(); File001.close();
       string Temp03 = Strn01.str(); statics string Temp04 = "SiuHungIsAGoodBearBecauseHeIsVeryGood";
       statics insize Vrab03 = Temp03.size(); insize Vrab04 = 12; statics insize Vrab05 = Temp04.size();
       for(uint32 Vrab06 = 123; Vrab06 < Vrab03; ++Vrab06){Temp03.at(Vrab06) -= Temp04.at(Vrab04); Vrab04 += 1; if(Vrab04 == Vrab05) Vrab04 = 0;}
       std::ofstream File01(L_Execute("Database\\Temp.log"), std::ios::binary | std::ios::out); Temp03.erase(0, 123); File01 << Temp03; File01.close();
       File001.open("Database\\Temp.log", std::ios::binary | std::ios::in);
      } if(!File001.is_open()) return 3;
      Vrab001 = Objects.size(); Vrab002 = 0; Vrab004 = 0; Objects.resize(Vrab001 + 1);
      Objects[Vrab001].id = Vrab01; Objects[Vrab001].type = Vrab02;
      std::ofstream File01("Database\\Log.log", std::ios::binary | std::ios::out | std::ios::app); if(File01.is_open()){File01 << "[] INFO - Processing \"" + Temp01 + "\" object into the system.\n";}
      return 0;
     }
     uint8  Create(statics insize Vrab01, statics string &Temp01)                    fastened
     {
      if(File001.is_open()) File001.close(); File001.open(Temp01, std::ios::in | std::ios::binary); if(!File001.is_open()) return 1;
      statics string Temp02 = L_Lowercase(string(Temp01, Temp01.size() - 4, 4)); if(Temp02 != ".dat" && Temp02 != ".txt") return 2;
      if(Temp02 == ".dat")
      {
       stream Strn01; Strn01 << File001.rdbuf(); File001.close();
       string Temp03 = Strn01.str(); statics string Temp04 = "SiuHungIsAGoodBearBecauseHeIsVeryGood";
       statics insize Vrab03 = Temp03.size(); insize Vrab04 = 12; statics insize Vrab05 = Temp04.size();
       for(uint32 Vrab06 = 123; Vrab06 < Vrab03; ++Vrab06){Temp03.at(Vrab06) -= Temp04.at(Vrab04); Vrab04 += 1; if(Vrab04 == Vrab05) Vrab04 = 0;}
       std::ofstream File01(L_Execute("Database\\Temp.log"), std::ios::binary | std::ios::out); Temp03.erase(0, 123); File01 << Temp03; File01.close();
       File001.open("Database\\Temp.log", std::ios::binary | std::ios::in);
      } if(!File001.is_open()) return 3;
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
         statics insize Vrab06 = G_SetSprite(Temp02, Objects[Vrab001].file[Vrab05].row, Objects[Vrab001].file[Vrab05].col, Objects[Vrab001].file[Vrab05].w, Objects[Vrab001].file[Vrab05].h);
         if(Vrab06 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible.";} else
         {
          Temp03 = "S"+ Temp02; Objects[Vrab001].file[Vrab05].Picture_Index = Vrab06;
          if(Vrab01) Objects[Vrab001].file[Vrab05].Picture_Mirror_Index = G_SetSprite(L_Rename(Temp02, "_mirror"), Objects[Vrab001].file[Vrab05].row, Objects[Vrab001].file[Vrab05].col, Objects[Vrab001].file[Vrab05].w, Objects[Vrab001].file[Vrab05].h);
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
         if(Temp02 == "<frame>")                   {Vrab002 = 3; File001 >> Temp02; statics insize Vrab05 = rinsize(L_Numbering(Temp02)); statics insize Vrab06 = Objects[Vrab001].Frame.size(); if(Vrab06 <= Vrab05) Objects[Vrab001].Frame.resize(Vrab05 + 1); Vrab03 = Vrab05; Objects[Vrab001].Frame[Vrab03].Exist = true; File001 >> Temp02; continue;}
        break;
        case 1:
         if(Temp02 == "<bmp_end>")                 {Vrab002 = 99ui8; continue;}
         if(Temp02 == "name:")                     {File001 >> Objects[Vrab001].name; continue;}
         if(Temp02 == "head:")                     {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_SetPic(Temp02); if(Vrab05 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible.";} else {Temp03 = "S"+ Temp02; Objects[Vrab001].head_Index = Vrab05;} Vrab02 = true; break;}
         if(Temp02 == "small:")                    {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_SetPic(Temp02); if(Vrab05 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible.";} else {Temp03 = "S"+ Temp02; Objects[Vrab001].small_Index = Vrab05;} Vrab02 = true; break;}
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
         if(Temp02 == "weapon_hit_sound:")         {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_SetSound(Temp02); if(Vrab05 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible."; Vrab02 = true; break;} else {Temp03 = "S"+ Temp02; Objects[Vrab001].weapon_hit_sound_Index = Vrab05; continue;}}
         if(Temp02 == "weapon_drop_sound:")        {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_SetSound(Temp02); if(Vrab05 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible."; Vrab02 = true; break;} else {Temp03 = "S"+ Temp02; Objects[Vrab001].weapon_drop_sound_Index = Vrab05; continue;}}
         if(Temp02 == "weapon_broken_sound:")      {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_SetSound(Temp02); if(Vrab05 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible."; Vrab02 = true; break;} else {Temp03 = "S"+ Temp02; Objects[Vrab001].weapon_broken_sound_Index = Vrab05; continue;}}
         
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
         if(Temp02 == "pic:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].pic = L_Numbering(Temp02); continue;}
         if(Temp02 == "state:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].state = L_Numbering(Temp02); continue;}
         if(Temp02 == "wait:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wait = L_Numbering(Temp02); continue;}
         if(Temp02 == "next:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].next = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvz:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].dvz = L_Numbering(Temp02); continue;}
         if(Temp02 == "centerx:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].centerx = L_Numbering(Temp02); continue;}
         if(Temp02 == "centery:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].centery = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_a:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_a = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_d:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_d = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_j:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_j = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Fa:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_Fa = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Fj:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_Fj = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Da:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_Da = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Dj:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_Dj = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Ua:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_Ua = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_Uj:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_Uj = L_Numbering(Temp02); continue;}
         if(Temp02 == "hit_ja:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].hit_ja = L_Numbering(Temp02); continue;}
         if(Temp02 == "mp:")                       {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].mp = L_Numbering(Temp02); continue;}
         if(Temp02 == "sound:")                    {File001 >> Temp02; Temp02 = Temp01 + Temp02; statics insize Vrab05 = G_SetSound(Temp02); if(Vrab05 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible."; Vrab02 = true; break;} else {Temp03 = "S"+ Temp02; Objects[Vrab001].Frame[Vrab03].sound_index = Vrab05; continue;}}
         if(Temp02 == "bpoint:")                   {Vrab002 = 4; Vrab04 = Objects[Vrab001].Frame[Vrab03].bpoint.size(); Objects[Vrab001].Frame[Vrab03].bpoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "cpoint:")                   {Vrab002 = 5; Vrab04 = Objects[Vrab001].Frame[Vrab03].cpoint.size(); Objects[Vrab001].Frame[Vrab03].cpoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "wpoint:")                   {Vrab002 = 6; Vrab04 = Objects[Vrab001].Frame[Vrab03].wpoint.size(); Objects[Vrab001].Frame[Vrab03].wpoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "opoint:")                   {Vrab002 = 7; Vrab04 = Objects[Vrab001].Frame[Vrab03].opoint.size(); Objects[Vrab001].Frame[Vrab03].opoint.resize(Vrab04 + 1); continue;}
         if(Temp02 == "itr:")                      {Vrab002 = 8; Vrab04 = Objects[Vrab001].Frame[Vrab03].itr.size(); Objects[Vrab001].Frame[Vrab03].itr.resize(Vrab04 + 1); continue;}
         if(Temp02 == "bdy:")                      {Vrab002 = 9; Vrab04 = Objects[Vrab001].Frame[Vrab03].bdy.size(); Objects[Vrab001].Frame[Vrab03].bdy.resize(Vrab04 + 1); continue;}
         
         if(Temp02 == "<bmp_begin>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<weapon_strength_list>")    {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 4:
         if(Temp02 == "bpoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].bpoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].bpoint[Vrab04].y = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 5:
         if(Temp02 == "cpoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "vaction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].vaction = L_Numbering(Temp02); continue;}
         if(Temp02 == "aaction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].aaction = L_Numbering(Temp02); continue;}
         if(Temp02 == "daction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].daction = L_Numbering(Temp02); continue;}
         if(Temp02 == "jaction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].jaction = L_Numbering(Temp02); continue;}
         if(Temp02 == "taction:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].taction = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwvx:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].throwvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwvy:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].throwvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwvz:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].throwvz = L_Numbering(Temp02); continue;}
         if(Temp02 == "throwinjury:")              {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].throwinjury = L_Numbering(Temp02); continue;}
         if(Temp02 == "dircontrol:")               {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].dircontrol = L_Numbering(Temp02); continue;}
         if(Temp02 == "hurtable:")                 {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].hurtable = L_Numbering(Temp02); continue;}
         if(Temp02 == "decrease:")                 {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].decrease = L_Numbering(Temp02); continue;}
         if(Temp02 == "cover:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].cover = L_Numbering(Temp02); continue;}
         if(Temp02 == "injury:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].injury = L_Numbering(Temp02); continue;}
         if(Temp02 == "fronthurtact:")             {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].fronthurtact = L_Numbering(Temp02); continue;}
         if(Temp02 == "backhurtact:")              {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].cpoint[Vrab04].backhurtact = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 6:
         if(Temp02 == "wpoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvz:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].dvz = L_Numbering(Temp02); continue;}
         if(Temp02 == "weaponact:")                {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].weaponact = L_Numbering(Temp02); continue;}
         if(Temp02 == "attacking:")                {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].attacking = L_Numbering(Temp02); continue;}
         if(Temp02 == "cover:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].wpoint[Vrab04].cover = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 7:
         if(Temp02 == "opoint_end:")               {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "oid:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].oid = L_Numbering(Temp02); continue;}
         if(Temp02 == "action:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].action = L_Numbering(Temp02); continue;}
         if(Temp02 == "facing:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].opoint[Vrab04].facing = L_Numbering(Temp02); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}
        break;
        case 8: case 10: case 11:
         if(Temp02 == "itr_end:")                  {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "w:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].w = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "h:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].h = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "zwidth:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].zwidth = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "dvx:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].dvx = L_Numbering(Temp02); continue;}
         if(Temp02 == "dvy:")                      {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].dvy = L_Numbering(Temp02); continue;}
         if(Temp02 == "fall:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].fall = L_Numbering(Temp02); continue;}
         if(Temp02 == "arest:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].arest = L_Numbering(Temp02); continue;}
         if(Temp02 == "vrest:")                    {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].vrest = L_Numbering(Temp02); continue;}
         if(Temp02 == "respond:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].respond = L_Numbering(Temp02); continue;}
         if(Temp02 == "effect:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].effect = L_Numbering(Temp02); continue;}
         if(Temp02 == "bdefend:")                  {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].bdefend = L_Numbering(Temp02); continue;}
         if(Temp02 == "injury:")                   {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].injury = L_Numbering(Temp02); continue;}
         if(Temp02 == "catchingact:")              {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].catchingact[0] = L_Numbering(Temp02); Vrab002 = 10; continue;}
         if(Temp02 == "caughtact:")                {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].caughtact[0] = L_Numbering(Temp02); Vrab002 = 11; continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "cpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "wpoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "opoint:")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "itr:")                      {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "bdy:")                      {Vrab002 += 100; Vrab02 = true; break;}

         if(Vrab002 == 10){Vrab002 = 8; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].catchingact[1] = L_Numbering(Temp02); continue;}
         if(Vrab002 == 11){Vrab002 = 8; Objects[Vrab001].Frame[Vrab03].itr[Vrab04].caughtact[1] = L_Numbering(Temp02); continue;}
        break;
        case 9:
         if(Temp02 == "bdy_end:")                  {Vrab002 = 3; continue;}
         if(Temp02 == "kind:")                     {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].bdy[Vrab04].kind = L_Numbering(Temp02); continue;}
         if(Temp02 == "x:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].bdy[Vrab04].x = L_Numbering(Temp02); continue;}
         if(Temp02 == "y:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].bdy[Vrab04].y = L_Numbering(Temp02); continue;}
         if(Temp02 == "w:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].bdy[Vrab04].w = ruint32(L_Numbering(Temp02)); continue;}
         if(Temp02 == "h:")                        {File001 >> Temp02; Objects[Vrab001].Frame[Vrab03].bdy[Vrab04].h = ruint32(L_Numbering(Temp02)); continue;}

         if(Temp02 == "<frame>")                   {Vrab002 += 100; Vrab02 = true; break;}
         if(Temp02 == "<frame_end>")               {Vrab002 += 100; Vrab02 = true; break;}
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
         case 4: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"bpoint:\".\n"; break;
         case 5: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"cpoint:\".\n"; break;
         case 6: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"wpoint:\".\n"; break;
         case 7: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"opoint:\".\n"; break;
         case 8: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"itr:\".\n"; break;
         case 9: File01 << ")( WARNING - Unknown syntax, \"" + Temp02 + "\", found in " + L_Number(Vrab04 + 1) + " \"bdy:\".\n"; break;
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
        case 4: return "E\"bpoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"bpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 5: return "E\"cpoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"cpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 6: return "E\"wpoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"wpoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 7: return "E\"opoint:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"opoint:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
        case 8: return "E\"itr:\"|0|Unexpected end of " + L_Number(Vrab04 + 1) + " \"itr:\" in \"<frame> " + std::to_string(Vrab03) + "\".";
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
         if(Temp02 == "shadow:")     {File001 >> Temp02; Vrab002 = 3; Temp02 = Temp01 + Temp02; statics insize Vrab03 = G_SetPic(Temp02); if(Vrab03 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible.";} else {Temp03 = "S"+ Temp02; Backgrounds[Vrab001].shadow_Index = Vrab03;} Vrab01 = true; break;}
         if(Temp02 == "layer:")      {File001 >> Temp02; Vrab002 = 6; Temp02 = Temp01 + Temp02; statics insize Vrab03 = G_SetPic(Temp02); if(Vrab03 == rinsize(-1)){Temp03 = "E"+ Temp02 + "|1|Either the following file cannot be found or inaccessible.";} else {Temp03 = "S"+ Temp02; statics insize Vrab04 = Backgrounds[Vrab001].Layer.size(); Backgrounds[Vrab001].Layer.resize(Vrab04 + 1); Backgrounds[Vrab001].Layer[Vrab04].image_Index = Vrab03;} Vrab01 = true; break;}
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
        case 7: return "E\"layer:\"|0|Unexpected end of " + L_Number(Vrab02 + 1) + " \"layer:\", it should be end with \"layer_end\".";
        default: File001.close(); return "D";
       }
      }
     }
     uint8  Frame()                                                                  fastened {return 8ui8;}
     string Debug() fastened {return std::to_string(Object[0].X_Vel);}
     private:
      insize Vrab001 = 0;
      uint8  Vrab002 = 0;
      int1   Vrab003 = false;
      uint8  Vrab004 = 0;
      std::ifstream File001;

      uint8  Mode = 0;
      uint8  Difficult = 0;
      insize Background = 0;
      insize Independent_Team = 0;
      insize Max = 0;
      std::vector < int1 > Selectable_Char;
      std::vector < std::vector < uint32 > > Animation;
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT > Object;
     
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_OBJECT > Objects;         // In-Game's objects.
      std::vector < HEPTA_LF2_ENCHANTED_ENGINE1_BACKGROUND > Backgrounds; // In-Game's background.

      int0 Remove(statics insize Vrab01) fastened
      {
       statics insize Vrab02 = Object.size(); if(Vrab01 >= Vrab02) return;
       Object[Vrab01] = HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT(); Object[Vrab01].Exist = false;
      }
      insize Add(statics insize Vrab01) fastened
      {
       statics insize Vrab02 = Object.size(); insize Vrab03 = 0;
       while(Vrab03 < Vrab02)
       {if(!Object[Vrab03].Exist) break; Vrab03 += 1;}
       if(Vrab03 == Vrab02)
       {if(Vrab02 == Max) return rinsize(-1); Object.push_back(HEPTA_LF2_ENCHANTED_ENGINE1_GAMEOBJECT()); statics insize Vrab04 = Objects.size(); insize Vrab05 = 0; while(Vrab05 < Vrab04){if(Objects[Vrab05].id == Vrab01){Object[Vrab02].Data = &Objects[Vrab05]; break;} Vrab05 += 1;} if(Vrab05 == Vrab04){Object.pop_back(); return rinsize(-1);} return Vrab02;} else
       {statics insize Vrab04 = Objects.size(); insize Vrab05 = 0; while(Vrab05 < Vrab04){if(Objects[Vrab05].id == Vrab01){Object[Vrab03].Data = &Objects[Vrab05]; break;} Vrab05 += 1;} if(Vrab05 == Vrab04) return rinsize(-1); Object[Vrab03].Exist = true; return Vrab03;}
      }
    };

    struct HEPTA_LF2_ENCHANTED_INFO_MANAGER
    {
     int64 Runtime = 0;
     int64 Counter = 0;
     int64 Target = 0;
    };
    struct HEPTA_LF2_ENCHANTED_INFO
    {
     int64 PositionX = 0;
     int64 PositionY = 0;
     uint64 Runtime = 0;
     insize Slot = 0;
     string String;
     std::vector < HEPTA_LF2_ENCHANTED_INFO_MANAGER > Manager;
    };
    struct HEPTA_LF2_ENCHANTED_MEMORY
    {
     uint8  P_Con[4]{};
     uint8  P_Input[4][16]{};
     string P_Name[4]{"P1", "P2", "P3", "P4"};

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
     insize Max_SFX = 20;
     insize Max_Object = 2000;
     string Address = "Database\\Game\\Enchanted\\Origin";
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
     string Record_Address = "recording\\";
     string User = "<none>";
     string Email = "<none>";
     string Note = "<none>";
    };
    struct HEPTA_LF2_ENCHANTED
    {
     // Core
      int1   Initialization = true;    // First initialization?
      int1   Draw = true;              // Mouse's rectangle draw?
      int1   Draw_Pausing = false;     // Mouse's rectangle draw's pausing?
      uint8  Draw_Color = 0;           // Mouse's rectangle draw's color.
      uint8  Draw_Trans = 0;           // Mouse's rectangle draw's trans.
      uint8  Menu = 0;                 // Interface's menu.
      int64  Display_CenX = 0, Display_CenY = 0, Display_W = 0, Display_H = 0; // For compatible positioning.
      int32  Mouse_X = 0, Mouse_Y = 0; // Last frame position.
      uint8  Mouse_Standby = 0;        // Stay countup.
      uint64 Tick = 0;                 // Playtime.
      insize Number_Of_Sound = 0;      // Max SFX.
      insize Info_Slot = 0;            // Info current slot.
     //-//
     // Event
      uint64 Runtime1 = 0; uint64 Runtime2 = 0; uint8 Runtime3 = 0;
      int64  CameraX = 0; int64 CameraY = 0;
      xint64 Darktime1 = 0;
      insize Background1 = 0;
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
    //unique < HEPTA_LF2_ENCHANTED_ENGINE2 > Engine2;             // System's In-Game. (Engine 1)
      std::vector < insize > Pic_Index_Interface;                // System's pics.
      std::vector < insize > Back_Index_Interface;               // System's background.
      std::vector < insize > Sound_Index_Interface;              // System's sounds.
      std::vector < HEPTA_LF2_ENCHANTED_INFO > Info;             // System's info notification.
     //-//
     // Light Functions
      int0   Not_Found() fastened {String[2] = "\"" + String[1] + "\""; String[3] = "Either can't be found or inaccessible.";}
      int0   Reset(statics uint8 Vrab01 = 0, statics uint64 Vrab02 = 0, statics uint64 Vrab03 = 0, statics uint8 Vrab04 = 0) fastened {Menu = Vrab01; Runtime1 = Vrab02; Runtime2 = Vrab03; Runtime3 = Vrab04;}
      int0   Print_Text(statics int64 Vrab01, statics int64 Vrab02, uint8 Vrab03, statics string &Temp01) fastened
      {
       statics insize Vrab04 = Temp01.size(); insize Vrab05 = 0; int64 Vrab06 = rint64(Vrab01); Vrab03 %= 6;
       while(Vrab05 != Vrab04)
       {
        statics insize Vrab07 = rinsize(Temp01.at(Vrab05)); int64 Vrab08 = 0, Vrab09 = 0;
        switch(Vrab07)
        {
         case 95: case 103: case 106: case 112: case 113: case 121: case 152: case 159: case 230: case 237: case 244: case 245: Vrab09 = 1; break;
         case 128: case 135: Vrab09 = 2; break;
         case 109: Vrab08 = 1;
         default: break;
        }
        G_SetDisplay(4, Pic_Index_Interface[rinsize(Vrab03)] + Vrab07, Vrab06 - Vrab08, Vrab02 + Vrab09);
        Vrab05 += 1; Vrab06 += 9;
       }
      }
      int0   Print_Bar(int64 Vrab01, int64 Vrab02, uint64 Vrab03, uint64 Vrab04) fastened
      {
       if(Vrab03 % 2 == 1) Vrab03 += 1; if(Vrab04 % 2 == 1) Vrab04 += 1;
       G_SetDisplay(2, Pic_Index_Interface[6], Vrab01 - 12, Vrab02 - 12);
       G_SetDisplay(2, Pic_Index_Interface[7], Vrab01 + Vrab03 + 1, Vrab02 - 12);
       G_SetDisplay(2, Pic_Index_Interface[8], Vrab01 - 12, Vrab02 + Vrab04 + 1);
       G_SetDisplay(2, Pic_Index_Interface[9], Vrab01 + Vrab03 + 1, Vrab02 + Vrab04 + 1);
       G_SetDisplay(2, Pic_Index_Interface[10], Vrab01, Vrab02 - 12, 0ui8, 255ui8, Vrab03);
       G_SetDisplay(2, Pic_Index_Interface[10], Vrab01, Vrab02 + Vrab04 + 10, 0ui8, 255ui8, Vrab03);
       G_SetDisplay(2, Pic_Index_Interface[11], Vrab01 - 12, Vrab02, 0ui8, 255ui8, 0, Vrab04);
       G_SetDisplay(2, Pic_Index_Interface[11], Vrab01 + Vrab03 + 10, Vrab02, 0ui8, 255ui8, 0, Vrab04);

       {
        uint64 Vrab05 = Vrab04 + 1; uint64 Vrab06 = ruint64(-1);
        while(Vrab05 > 0)
        {
         uint64 Vrab07 = Vrab05 / 198; if(Vrab07 > 0){Vrab07 = 198;} else {Vrab07 = Vrab05 % 198;} Vrab05 -= Vrab07; Vrab06 += 1;
         G_SetDisplay(3, Pic_Index_Interface[12], Vrab01 - 9, Vrab02 + (Vrab06 * 198), 0ui8, 255ui8, 9, Vrab07, 0, 1);
         G_SetDisplay(3, Pic_Index_Interface[12], Vrab01 + Vrab03 + 1, Vrab02 + (Vrab06 * 198), 0ui8, 255ui8, 9, Vrab07, 0, 1);
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
          G_SetDisplay(3, Pic_Index_Interface[12], Vrab01 + (Vrab09 * 198), Vrab02 - 9 + (Vrab06 * 198), 0ui8, 255ui8, Vrab10, Vrab07, 1, 0);
         }
        }
       }
      }
      int0   Play_Sound(statics insize Vrab01, statics xint32 Vrab02 = 0.0, statics uint32 Vrab03 = 100) fastened
      {
       if(Number_Of_Sound == Memory[0].Max_SFX) return;
       Number_Of_Sound += 1;
       G_SetSoundplay(Vrab01, rxint32((rxint64(Vrab03) / 100) * rxint64(Varb0012)), rxint32(Varb0013 + Vrab02));
      }
      int0   Post_Info(statics string Temp01) fastened
      {
       statics insize Vrab01 = Info.size(); Info.resize(Vrab01 + 1);
       Info[Vrab01].Slot = Info_Slot; Info[Vrab01].String = Temp01;
       int64 Vrab02 = 29;
       {
        insize Vrab03 = 0, Vrab04 = 0, Vrab05 = Temp01.size(); while(Vrab05 > 40){Vrab05 -= 40; if(Temp01.at((Vrab03 * 40) + Vrab04 + 40) == ' '){Vrab05 -= 1; Vrab04 += 1;} Vrab03 += 1;}
        Vrab05 = Temp01.size() - Vrab04;
        if(Vrab05 >= 41){Vrab02 += 7 + (16 * rint64((Vrab05 - 1) / 40));} else
        {Vrab02 += 5;}
       }
       for(insize Vrab03 = 0; Vrab03 < Vrab01; ++Vrab03) if(Info[Vrab03].Slot < Info_Slot)
       {
        statics insize Vrab04 = Info[Vrab03].Manager.size(); Info[Vrab03].Manager.resize(Vrab04 + 1);
        Info[Vrab03].Manager[Vrab04].Target = Vrab02;
       }
       Info_Slot += 1;
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
      string Version() fastened {return "v1.0.230215";}
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
      int0   Save_Memory(statics string Temp01) fastened
      {
       std::ofstream File01(L_Execute(Temp01));
       if(!File01.is_open()) return;

       File01 << Memory[0].P_Name[0] << " " << Memory[0].P_Name[1] << " " << Memory[0].P_Name[2] << " " << Memory[0].P_Name[3] << "\n";
       File01 << ruint32(Memory[0].P_Input[0][0]) << " " << ruint32(Memory[0].P_Input[0][1]) << " " << ruint32(Memory[0].P_Input[0][2]) << " " << ruint32(Memory[0].P_Input[0][3]) << " " << ruint32(Memory[0].P_Input[0][4]) << " " << ruint32(Memory[0].P_Input[0][5]) << " " << ruint32(Memory[0].P_Input[0][6]) << " " << ruint32(Memory[0].P_Input[0][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[1][0]) << " " << ruint32(Memory[0].P_Input[1][1]) << " " << ruint32(Memory[0].P_Input[1][2]) << " " << ruint32(Memory[0].P_Input[1][3]) << " " << ruint32(Memory[0].P_Input[1][4]) << " " << ruint32(Memory[0].P_Input[1][5]) << " " << ruint32(Memory[0].P_Input[1][6]) << " " << ruint32(Memory[0].P_Input[1][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[2][0]) << " " << ruint32(Memory[0].P_Input[2][1]) << " " << ruint32(Memory[0].P_Input[2][2]) << " " << ruint32(Memory[0].P_Input[2][3]) << " " << ruint32(Memory[0].P_Input[2][4]) << " " << ruint32(Memory[0].P_Input[2][5]) << " " << ruint32(Memory[0].P_Input[2][6]) << " " << ruint32(Memory[0].P_Input[2][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[3][0]) << " " << ruint32(Memory[0].P_Input[3][1]) << " " << ruint32(Memory[0].P_Input[3][2]) << " " << ruint32(Memory[0].P_Input[3][3]) << " " << ruint32(Memory[0].P_Input[3][4]) << " " << ruint32(Memory[0].P_Input[3][5]) << " " << ruint32(Memory[0].P_Input[3][6]) << " " << ruint32(Memory[0].P_Input[3][7]) << "\n";
       File01 << ruint32(Memory[0].P_Input[0][8]) << " " << ruint32(Memory[0].P_Input[0][9]) << " " << ruint32(Memory[0].P_Input[0][10]) << " " << ruint32(Memory[0].P_Input[0][11]) << " " << ruint32(Memory[0].P_Input[0][12]) << " " << ruint32(Memory[0].P_Input[0][13]) << " " << ruint32(Memory[0].P_Input[0][14]) << " " << ruint32(Memory[0].P_Input[0][15]) << "\n";
       File01 << ruint32(Memory[0].P_Input[1][8]) << " " << ruint32(Memory[0].P_Input[1][9]) << " " << ruint32(Memory[0].P_Input[1][10]) << " " << ruint32(Memory[0].P_Input[1][11]) << " " << ruint32(Memory[0].P_Input[1][12]) << " " << ruint32(Memory[0].P_Input[1][13]) << " " << ruint32(Memory[0].P_Input[1][14]) << " " << ruint32(Memory[0].P_Input[1][15]) << "\n";
       File01 << ruint32(Memory[0].P_Input[2][8]) << " " << ruint32(Memory[0].P_Input[2][9]) << " " << ruint32(Memory[0].P_Input[2][10]) << " " << ruint32(Memory[0].P_Input[2][11]) << " " << ruint32(Memory[0].P_Input[2][12]) << " " << ruint32(Memory[0].P_Input[2][13]) << " " << ruint32(Memory[0].P_Input[2][14]) << " " << ruint32(Memory[0].P_Input[2][15]) << "\n";
       File01 << ruint32(Memory[0].P_Input[3][8]) << " " << ruint32(Memory[0].P_Input[3][9]) << " " << ruint32(Memory[0].P_Input[3][10]) << " " << ruint32(Memory[0].P_Input[3][11]) << " " << ruint32(Memory[0].P_Input[3][12]) << " " << ruint32(Memory[0].P_Input[3][13]) << " " << ruint32(Memory[0].P_Input[3][14]) << " " << ruint32(Memory[0].P_Input[3][15]) << "\n";
       File01 << ruint32(Memory[0].P_Con[0]) << " " << ruint32(Memory[0].P_Con[1]) << " " << ruint32(Memory[0].P_Con[2]) << " " << ruint32(Memory[0].P_Con[3]) << "\n";

       if(Memory[0].Custom_Mirror){File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Fast_Loading) {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Show_FPS)     {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Show_Time)    {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Fullscreen)   {File01 << "T ";} else {File01 << "F ";}
       if(Memory[0].Aspect_Ratio) {File01 << "T ";} else {File01 << "F ";}
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


       File01.close();
      }
      int0   Load_Memory(statics string Temp01) fastened
      {
       std::ifstream File01(Temp01); 
       if(!File01.is_open()){Save_Memory(Temp01); File01.open(Temp01);}
       if(!File01.is_open()) return;

       string Temp02;

       if(File01){File01 >> Memory[1].P_Name[0];} else {return;} if(File01){File01 >> Memory[1].P_Name[1];} else {return;} if(File01){File01 >> Memory[1].P_Name[2];} else {return;} if(File01){File01 >> Memory[1].P_Name[3];} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[0][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[1][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[2][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[3][0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][3] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][4] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][5] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][6] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][7] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[0][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[0][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[1][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[1][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[2][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[2][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Input[3][8] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][9] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][10] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][11] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][12] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][13] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][14] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Input[3][15] = ruint8(L_Numbering(Temp02));} else {return;}
       if(File01){File01 >> Temp02; Memory[1].P_Con[0] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Con[1] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Con[2] = ruint8(L_Numbering(Temp02));} else {return;} if(File01){File01 >> Temp02; Memory[1].P_Con[3] = ruint8(L_Numbering(Temp02));} else {return;}
       
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
       if(File01){File01 >> Temp02; if(Temp02 == "_") Temp02 = ""; Memory[1].Address = Temp02;} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "_") Temp02 = ""; Memory[1].Data_Address = Temp02;} else {return;}

       if(File01){File01 >> Temp02; Memory[1].Recording = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; Memory[1].True_Recording = Temp02 == "T";} else {return;}
       if(File01){File01 >> Temp02; if(Temp02 == "_") Temp02 = ""; Memory[1].Record_Address = Temp02;} else {return;}
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
   if(Input.RESH_CAPS || Input.CONS_LSHIFT > 0 || Input.CONS_RSHIFT > 0)
   {
    {statics uint8 Vrab01 = Input.MAIN_A; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('A'); if(Vrab01 == 40) Input.MAIN_A = 253;}
    {statics uint8 Vrab01 = Input.MAIN_B; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('B'); if(Vrab01 == 40) Input.MAIN_B = 253;}
    {statics uint8 Vrab01 = Input.MAIN_C; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('C'); if(Vrab01 == 40) Input.MAIN_C = 253;}
    {statics uint8 Vrab01 = Input.MAIN_D; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('D'); if(Vrab01 == 40) Input.MAIN_D = 253;}
    {statics uint8 Vrab01 = Input.MAIN_E; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('E'); if(Vrab01 == 40) Input.MAIN_E = 253;}
    {statics uint8 Vrab01 = Input.MAIN_F; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('F'); if(Vrab01 == 40) Input.MAIN_F = 253;}
    {statics uint8 Vrab01 = Input.MAIN_G; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('G'); if(Vrab01 == 40) Input.MAIN_G = 253;}
    {statics uint8 Vrab01 = Input.MAIN_H; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('H'); if(Vrab01 == 40) Input.MAIN_H = 253;}
    {statics uint8 Vrab01 = Input.MAIN_I; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('I'); if(Vrab01 == 40) Input.MAIN_I = 253;}
    {statics uint8 Vrab01 = Input.MAIN_J; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('J'); if(Vrab01 == 40) Input.MAIN_J = 253;}
    {statics uint8 Vrab01 = Input.MAIN_K; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('K'); if(Vrab01 == 40) Input.MAIN_K = 253;}
    {statics uint8 Vrab01 = Input.MAIN_L; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('L'); if(Vrab01 == 40) Input.MAIN_L = 253;}
    {statics uint8 Vrab01 = Input.MAIN_M; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('M'); if(Vrab01 == 40) Input.MAIN_M = 253;}
    {statics uint8 Vrab01 = Input.MAIN_N; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('N'); if(Vrab01 == 40) Input.MAIN_N = 253;}
    {statics uint8 Vrab01 = Input.MAIN_O; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('O'); if(Vrab01 == 40) Input.MAIN_O = 253;}
    {statics uint8 Vrab01 = Input.MAIN_P; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('P'); if(Vrab01 == 40) Input.MAIN_P = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Q; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('Q'); if(Vrab01 == 40) Input.MAIN_Q = 253;}
    {statics uint8 Vrab01 = Input.MAIN_R; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('R'); if(Vrab01 == 40) Input.MAIN_R = 253;}
    {statics uint8 Vrab01 = Input.MAIN_S; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('S'); if(Vrab01 == 40) Input.MAIN_S = 253;}
    {statics uint8 Vrab01 = Input.MAIN_T; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('T'); if(Vrab01 == 40) Input.MAIN_T = 253;}
    {statics uint8 Vrab01 = Input.MAIN_U; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('U'); if(Vrab01 == 40) Input.MAIN_U = 253;}
    {statics uint8 Vrab01 = Input.MAIN_V; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('V'); if(Vrab01 == 40) Input.MAIN_V = 253;}
    {statics uint8 Vrab01 = Input.MAIN_W; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('W'); if(Vrab01 == 40) Input.MAIN_W = 253;}
    {statics uint8 Vrab01 = Input.MAIN_X; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('X'); if(Vrab01 == 40) Input.MAIN_X = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Y; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('Y'); if(Vrab01 == 40) Input.MAIN_Y = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Z; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('Z'); if(Vrab01 == 40) Input.MAIN_Z = 253;}
   } else
   {
    {statics uint8 Vrab01 = Input.MAIN_A; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('a'); if(Vrab01 == 40) Input.MAIN_A = 253;}
    {statics uint8 Vrab01 = Input.MAIN_B; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('b'); if(Vrab01 == 40) Input.MAIN_B = 253;}
    {statics uint8 Vrab01 = Input.MAIN_C; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('c'); if(Vrab01 == 40) Input.MAIN_C = 253;}
    {statics uint8 Vrab01 = Input.MAIN_D; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('d'); if(Vrab01 == 40) Input.MAIN_D = 253;}
    {statics uint8 Vrab01 = Input.MAIN_E; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('e'); if(Vrab01 == 40) Input.MAIN_E = 253;}
    {statics uint8 Vrab01 = Input.MAIN_F; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('f'); if(Vrab01 == 40) Input.MAIN_F = 253;}
    {statics uint8 Vrab01 = Input.MAIN_G; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('g'); if(Vrab01 == 40) Input.MAIN_G = 253;}
    {statics uint8 Vrab01 = Input.MAIN_H; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('h'); if(Vrab01 == 40) Input.MAIN_H = 253;}
    {statics uint8 Vrab01 = Input.MAIN_I; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('i'); if(Vrab01 == 40) Input.MAIN_I = 253;}
    {statics uint8 Vrab01 = Input.MAIN_J; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('j'); if(Vrab01 == 40) Input.MAIN_J = 253;}
    {statics uint8 Vrab01 = Input.MAIN_K; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('k'); if(Vrab01 == 40) Input.MAIN_K = 253;}
    {statics uint8 Vrab01 = Input.MAIN_L; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('l'); if(Vrab01 == 40) Input.MAIN_L = 253;}
    {statics uint8 Vrab01 = Input.MAIN_M; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('m'); if(Vrab01 == 40) Input.MAIN_M = 253;}
    {statics uint8 Vrab01 = Input.MAIN_N; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('n'); if(Vrab01 == 40) Input.MAIN_N = 253;}
    {statics uint8 Vrab01 = Input.MAIN_O; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('o'); if(Vrab01 == 40) Input.MAIN_O = 253;}
    {statics uint8 Vrab01 = Input.MAIN_P; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('p'); if(Vrab01 == 40) Input.MAIN_P = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Q; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('q'); if(Vrab01 == 40) Input.MAIN_Q = 253;}
    {statics uint8 Vrab01 = Input.MAIN_R; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('r'); if(Vrab01 == 40) Input.MAIN_R = 253;}
    {statics uint8 Vrab01 = Input.MAIN_S; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('s'); if(Vrab01 == 40) Input.MAIN_S = 253;}
    {statics uint8 Vrab01 = Input.MAIN_T; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('t'); if(Vrab01 == 40) Input.MAIN_T = 253;}
    {statics uint8 Vrab01 = Input.MAIN_U; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('u'); if(Vrab01 == 40) Input.MAIN_U = 253;}
    {statics uint8 Vrab01 = Input.MAIN_V; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('v'); if(Vrab01 == 40) Input.MAIN_V = 253;}
    {statics uint8 Vrab01 = Input.MAIN_W; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('w'); if(Vrab01 == 40) Input.MAIN_W = 253;}
    {statics uint8 Vrab01 = Input.MAIN_X; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('x'); if(Vrab01 == 40) Input.MAIN_X = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Y; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('y'); if(Vrab01 == 40) Input.MAIN_Y = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Z; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('z'); if(Vrab01 == 40) Input.MAIN_Z = 253;}
   }
   {statics uint8 Vrab01 = Input.NUMS_0; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('0'); if(Vrab01 == 40) Input.NUMS_0 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_1; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('1'); if(Vrab01 == 40) Input.NUMS_1 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_2; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('2'); if(Vrab01 == 40) Input.NUMS_2 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_3; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('3'); if(Vrab01 == 40) Input.NUMS_3 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_4; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('4'); if(Vrab01 == 40) Input.NUMS_4 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_5; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('5'); if(Vrab01 == 40) Input.NUMS_5 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_6; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('6'); if(Vrab01 == 40) Input.NUMS_6 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_7; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('7'); if(Vrab01 == 40) Input.NUMS_7 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_8; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('8'); if(Vrab01 == 40) Input.NUMS_8 = 253;}
   {statics uint8 Vrab01 = Input.NUMS_9; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('9'); if(Vrab01 == 40) Input.NUMS_9 = 253;}
   if(Input.CONS_LSHIFT > 0 || Input.CONS_RSHIFT > 0)
   {
    {statics uint8 Vrab01 = Input.MAIN_0; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back(')'); if(Vrab01 == 40) Input.MAIN_0 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_1; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('!'); if(Vrab01 == 40) Input.MAIN_1 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_2; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('@'); if(Vrab01 == 40) Input.MAIN_2 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_3; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('#'); if(Vrab01 == 40) Input.MAIN_3 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_4; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('$'); if(Vrab01 == 40) Input.MAIN_4 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_5; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('%'); if(Vrab01 == 40) Input.MAIN_5 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_6; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('^'); if(Vrab01 == 40) Input.MAIN_6 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_7; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('&'); if(Vrab01 == 40) Input.MAIN_7 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_8; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('*'); if(Vrab01 == 40) Input.MAIN_8 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_9; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('('); if(Vrab01 == 40) Input.MAIN_9 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_TILDE;        if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('~');  if(Vrab01 == 40) Input.MAIN_TILDE = 253;}
    {statics uint8 Vrab01 = Input.MAIN_MINUS;        if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('_');  if(Vrab01 == 40) Input.MAIN_MINUS = 253;}
    {statics uint8 Vrab01 = Input.MAIN_PLUS;         if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('+');  if(Vrab01 == 40) Input.MAIN_PLUS = 253;}
    {statics uint8 Vrab01 = Input.MAIN_OPENBRACKED;  if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('{');  if(Vrab01 == 40) Input.MAIN_OPENBRACKED = 253;}
    {statics uint8 Vrab01 = Input.MAIN_CLOSEBRACKED; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('}');  if(Vrab01 == 40) Input.MAIN_CLOSEBRACKED = 253;}
    {statics uint8 Vrab01 = Input.MAIN_PIPE;         if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('|');  if(Vrab01 == 40) Input.MAIN_PIPE = 253;}
    {statics uint8 Vrab01 = Input.MAIN_SEMICOLON;    if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back(':');  if(Vrab01 == 40) Input.MAIN_SEMICOLON = 253;}
    {statics uint8 Vrab01 = Input.MAIN_QUOTES;       if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('\"'); if(Vrab01 == 40) Input.MAIN_QUOTES = 253;}
    {statics uint8 Vrab01 = Input.MAIN_QUESTION;     if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('?');  if(Vrab01 == 40) Input.MAIN_QUESTION = 253;}
    {statics uint8 Vrab01 = Input.MAIN_PERIOD;       if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('>');  if(Vrab01 == 40) Input.MAIN_PERIOD = 253;}
    {statics uint8 Vrab01 = Input.MAIN_COMMA;        if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('<');  if(Vrab01 == 40) Input.MAIN_COMMA = 253;}
   } else
   {
    {statics uint8 Vrab01 = Input.MAIN_0; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('0'); if(Vrab01 == 40) Input.MAIN_0 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_1; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('1'); if(Vrab01 == 40) Input.MAIN_1 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_2; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('2'); if(Vrab01 == 40) Input.MAIN_2 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_3; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('3'); if(Vrab01 == 40) Input.MAIN_3 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_4; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('4'); if(Vrab01 == 40) Input.MAIN_4 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_5; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('5'); if(Vrab01 == 40) Input.MAIN_5 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_6; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('6'); if(Vrab01 == 40) Input.MAIN_6 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_7; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('7'); if(Vrab01 == 40) Input.MAIN_7 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_8; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('8'); if(Vrab01 == 40) Input.MAIN_8 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_9; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('9'); if(Vrab01 == 40) Input.MAIN_9 = 253;}
    {statics uint8 Vrab01 = Input.MAIN_TILDE;        if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('`'); if(Vrab01 == 40) Input.MAIN_TILDE = 253;}
    {statics uint8 Vrab01 = Input.MAIN_MINUS;        if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('-');  if(Vrab01 == 40) Input.MAIN_MINUS = 253;}
    {statics uint8 Vrab01 = Input.MAIN_PLUS;         if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('=');  if(Vrab01 == 40) Input.MAIN_PLUS = 253;}
    {statics uint8 Vrab01 = Input.MAIN_OPENBRACKED;  if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('[');  if(Vrab01 == 40) Input.MAIN_OPENBRACKED = 253;}
    {statics uint8 Vrab01 = Input.MAIN_CLOSEBRACKED; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back(']');  if(Vrab01 == 40) Input.MAIN_CLOSEBRACKED = 253;}
    {statics uint8 Vrab01 = Input.MAIN_PIPE;         if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('\\'); if(Vrab01 == 40) Input.MAIN_PIPE = 253;}
    {statics uint8 Vrab01 = Input.MAIN_SEMICOLON;    if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back(';');  if(Vrab01 == 40) Input.MAIN_SEMICOLON = 253;}
    {statics uint8 Vrab01 = Input.MAIN_QUOTES;       if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('\''); if(Vrab01 == 40) Input.MAIN_QUOTES = 253;}
    {statics uint8 Vrab01 = Input.MAIN_QUESTION;     if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('/');  if(Vrab01 == 40) Input.MAIN_QUESTION = 253;}
    {statics uint8 Vrab01 = Input.MAIN_PERIOD;       if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('.');  if(Vrab01 == 40) Input.MAIN_PERIOD = 253;}
    {statics uint8 Vrab01 = Input.MAIN_COMMA;        if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back(',');  if(Vrab01 == 40) Input.MAIN_COMMA = 253;}
   }
   {statics uint8 Vrab01 = Input.MAIN_SPACE;        if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back(' ');  if(Vrab01 == 40) Input.MAIN_SPACE = 253;}
   {statics uint8 Vrab01 = Input.CONS_BACK; if(Vrab01 == 1 || Vrab01 == 254) if(Temp01.size() > 0) Temp01.pop_back(); if(Vrab01 == 40) Input.CONS_BACK = 253;}
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
  int32  L_Rounding(xint64 Vrab01)        fastened {if(rint64(Vrab01) == rxint64(rint64(Vrab01 + 0.5))) return rint32(Vrab01); return rint32(Vrab01) + 1;}
  int64  L_Rounding64(xint64 Vrab01)      fastened {if(rint64(Vrab01) == rxint64(rint64(Vrab01 + 0.5))) return rint64(Vrab01); return rint64(Vrab01) + 1;}
  uint64 L_Random(uint64 Vrab01)          fastened {Varb0015 += 1; Varb0016 += Varb0015; Varb0017 -= Varb0016; Varb0018 ^= Varb0017; Varb0018 |= Varb0016; Varb0018 -= Varb0015; Varb0016 *= Varb0018; Varb0016 %= ruint64(ruint32(-1)) + 1; return ruint64(L_Rounding64((rxint64(Varb0016) / rxint64(0xFFFFFFFF) * rxint64(Vrab01))));}
  xint64 L_Doubling(string Temp01)        fastened 
  {
   statics insize Vrab01 = Temp01.size(); insize Vrab02 = Vrab01;
   while(Vrab02 != 0){Vrab02 -= 1; if(Temp01.at(Vrab02) == '.') break;}
   xint64 Vrab03 = 0.0;
   if(Vrab02 != 0) Vrab03 = rxint64(L_Numbering(string(Temp01, 0, Vrab02)));
   if(Vrab02 != Vrab01)
   {
    int32 Vrab04 = Vrab01 - Vrab02 + 1; if(Vrab04 < 9){Vrab04 = L_Numbering(string(Temp01, Vrab02 + 1, Vrab04));} else {Vrab04 = L_Numbering(string(Temp01, Vrab02 + 1, 9));}
    statics int32 Vrab05 = Vrab04;
    if(Vrab03 < 0) Vrab04 = -Vrab04;
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
   }
   return Vrab03;
  }
  string L_Number(insize Vrab01)          fastened {statics string Temp01 = std::to_string(Vrab01); Vrab01 %= 100; if(Vrab01 <= 10 || Vrab01 >= 20){switch(ruint8(Vrab01 % 10)){case 1: return Temp01 + "st"; case 2: return Temp01 + "nd"; case 3: return Temp01 + "rd"; default: return Temp01 + "th";}} else {return Temp01 + "th";}}
  string L_Lowercase(string Temp01)       fastened {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) >= 'A' && Temp01.at(Vrab01) <= 'Z') Temp01.at(Vrab01) += 32;} return Temp01;}
  string L_Spacemaker(string Temp01)      fastened {insize Vrab01 = Temp01.size(); if(Vrab01 == 0) return "_"; while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) == ' ') Temp01.at(Vrab01) = '?';} return Temp01;}
  string L_Execute(statics string Temp01) fastened {string Temp02 = Temp01; uint32 Vrab01 = Temp02.size() - 1; while(Vrab01 != 0 && Temp02.at(Vrab01) != '\\') Vrab01 -= 1; if(Vrab01 > 0) Temp02.erase(Vrab01, Temp02.size() - Vrab01); std::filesystem::create_directories(Temp02); return Temp01;}
  string L_Rename(string Temp01, string Temp02) fastened 
  {
   insize Vrab01 = Temp01.size();
   while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) == '.') break;}
   if(Vrab01 != 0){Temp01.insert(Vrab01, Temp02);} else {Temp01 += Temp02;}
   return Temp01;
  }
  string L_Revoke(string Temp01, uint8 Vrab01, uint8 Vrab02) fastened {insize Vrab03 = Temp01.size(); while(Vrab03 != 0){Vrab03 -= 1; if(Temp01.at(Vrab03) == Vrab01) Temp01.at(Vrab03) = Vrab02;} return Temp01;}
 //-//
 // Prime Functions
  int0 P_EngineInput(DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01)
  {
   auto Ikey02 = Ikey01->GetState();
   if(Ikey02.D0){if((++Input.MAIN_0) == 255ui8) Input.MAIN_0 = 250ui8;} else {Input.MAIN_0 = 0ui8;}
   if(Ikey02.D1){if((++Input.MAIN_1) == 255ui8) Input.MAIN_1 = 250ui8;} else {Input.MAIN_1 = 0ui8;}
   if(Ikey02.D2){if((++Input.MAIN_2) == 255ui8) Input.MAIN_2 = 250ui8;} else {Input.MAIN_2 = 0ui8;}
   if(Ikey02.D3){if((++Input.MAIN_3) == 255ui8) Input.MAIN_3 = 250ui8;} else {Input.MAIN_3 = 0ui8;}
   if(Ikey02.D4){if((++Input.MAIN_4) == 255ui8) Input.MAIN_4 = 250ui8;} else {Input.MAIN_4 = 0ui8;}
   if(Ikey02.D5){if((++Input.MAIN_5) == 255ui8) Input.MAIN_5 = 250ui8;} else {Input.MAIN_5 = 0ui8;}
   if(Ikey02.D6){if((++Input.MAIN_6) == 255ui8) Input.MAIN_6 = 250ui8;} else {Input.MAIN_6 = 0ui8;}
   if(Ikey02.D7){if((++Input.MAIN_7) == 255ui8) Input.MAIN_7 = 250ui8;} else {Input.MAIN_7 = 0ui8;}
   if(Ikey02.D8){if((++Input.MAIN_8) == 255ui8) Input.MAIN_8 = 250ui8;} else {Input.MAIN_8 = 0ui8;}
   if(Ikey02.D9){if((++Input.MAIN_9) == 255ui8) Input.MAIN_9 = 250ui8;} else {Input.MAIN_9 = 0ui8;}
   if(Ikey02.A){if((++Input.MAIN_A) == 255ui8) Input.MAIN_A = 250ui8;} else {Input.MAIN_A = 0ui8;}
   if(Ikey02.B){if((++Input.MAIN_B) == 255ui8) Input.MAIN_B = 250ui8;} else {Input.MAIN_B = 0ui8;}
   if(Ikey02.C){if((++Input.MAIN_C) == 255ui8) Input.MAIN_C = 250ui8;} else {Input.MAIN_C = 0ui8;}
   if(Ikey02.D){if((++Input.MAIN_D) == 255ui8) Input.MAIN_D = 250ui8;} else {Input.MAIN_D = 0ui8;}
   if(Ikey02.E){if((++Input.MAIN_E) == 255ui8) Input.MAIN_E = 250ui8;} else {Input.MAIN_E = 0ui8;}
   if(Ikey02.F){if((++Input.MAIN_F) == 255ui8) Input.MAIN_F = 250ui8;} else {Input.MAIN_F = 0ui8;}
   if(Ikey02.G){if((++Input.MAIN_G) == 255ui8) Input.MAIN_G = 250ui8;} else {Input.MAIN_G = 0ui8;}
   if(Ikey02.H){if((++Input.MAIN_H) == 255ui8) Input.MAIN_H = 250ui8;} else {Input.MAIN_H = 0ui8;}
   if(Ikey02.I){if((++Input.MAIN_I) == 255ui8) Input.MAIN_I = 250ui8;} else {Input.MAIN_I = 0ui8;}
   if(Ikey02.J){if((++Input.MAIN_J) == 255ui8) Input.MAIN_J = 250ui8;} else {Input.MAIN_J = 0ui8;}
   if(Ikey02.K){if((++Input.MAIN_K) == 255ui8) Input.MAIN_K = 250ui8;} else {Input.MAIN_K = 0ui8;}
   if(Ikey02.L){if((++Input.MAIN_L) == 255ui8) Input.MAIN_L = 250ui8;} else {Input.MAIN_L = 0ui8;}
   if(Ikey02.M){if((++Input.MAIN_M) == 255ui8) Input.MAIN_M = 250ui8;} else {Input.MAIN_M = 0ui8;}
   if(Ikey02.N){if((++Input.MAIN_N) == 255ui8) Input.MAIN_N = 250ui8;} else {Input.MAIN_N = 0ui8;}
   if(Ikey02.O){if((++Input.MAIN_O) == 255ui8) Input.MAIN_O = 250ui8;} else {Input.MAIN_O = 0ui8;}
   if(Ikey02.P){if((++Input.MAIN_P) == 255ui8) Input.MAIN_P = 250ui8;} else {Input.MAIN_P = 0ui8;}
   if(Ikey02.Q){if((++Input.MAIN_Q) == 255ui8) Input.MAIN_Q = 250ui8;} else {Input.MAIN_Q = 0ui8;}
   if(Ikey02.R){if((++Input.MAIN_R) == 255ui8) Input.MAIN_R = 250ui8;} else {Input.MAIN_R = 0ui8;}
   if(Ikey02.S){if((++Input.MAIN_S) == 255ui8) Input.MAIN_S = 250ui8;} else {Input.MAIN_S = 0ui8;}
   if(Ikey02.T){if((++Input.MAIN_T) == 255ui8) Input.MAIN_T = 250ui8;} else {Input.MAIN_T = 0ui8;}
   if(Ikey02.U){if((++Input.MAIN_U) == 255ui8) Input.MAIN_U = 250ui8;} else {Input.MAIN_U = 0ui8;}
   if(Ikey02.V){if((++Input.MAIN_V) == 255ui8) Input.MAIN_V = 250ui8;} else {Input.MAIN_V = 0ui8;}
   if(Ikey02.W){if((++Input.MAIN_W) == 255ui8) Input.MAIN_W = 250ui8;} else {Input.MAIN_W = 0ui8;}
   if(Ikey02.X){if((++Input.MAIN_X) == 255ui8) Input.MAIN_X = 250ui8;} else {Input.MAIN_X = 0ui8;}
   if(Ikey02.Y){if((++Input.MAIN_Y) == 255ui8) Input.MAIN_Y = 250ui8;} else {Input.MAIN_Y = 0ui8;}
   if(Ikey02.Z){if((++Input.MAIN_Z) == 255ui8) Input.MAIN_Z = 250ui8;} else {Input.MAIN_Z = 0ui8;}
   if(Ikey02.OemTilde)        {if((++Input.MAIN_TILDE) == 255ui8) Input.MAIN_TILDE = 250ui8;} else {Input.MAIN_TILDE = 0ui8;}
   if(Ikey02.OemMinus)        {if((++Input.MAIN_MINUS) == 255ui8) Input.MAIN_MINUS = 250ui8;} else {Input.MAIN_MINUS = 0ui8;}
   if(Ikey02.OemPlus)         {if((++Input.MAIN_PLUS) == 255ui8) Input.MAIN_PLUS = 250ui8;} else {Input.MAIN_PLUS = 0ui8;}
   if(Ikey02.OemOpenBrackets) {if((++Input.MAIN_OPENBRACKED) == 255ui8) Input.MAIN_OPENBRACKED = 250ui8;} else {Input.MAIN_OPENBRACKED = 0ui8;}
   if(Ikey02.OemCloseBrackets){if((++Input.MAIN_CLOSEBRACKED) == 255ui8) Input.MAIN_CLOSEBRACKED = 250ui8;} else {Input.MAIN_CLOSEBRACKED = 0ui8;}
   if(Ikey02.OemPipe)         {if((++Input.MAIN_PIPE) == 255ui8) Input.MAIN_PIPE = 250ui8;} else {Input.MAIN_PIPE = 0ui8;}
   if(Ikey02.OemSemicolon)    {if((++Input.MAIN_SEMICOLON) == 255ui8) Input.MAIN_SEMICOLON = 250ui8;} else {Input.MAIN_SEMICOLON = 0ui8;}
   if(Ikey02.OemQuotes)       {if((++Input.MAIN_QUOTES) == 255ui8) Input.MAIN_QUOTES = 250ui8;} else {Input.MAIN_QUOTES = 0ui8;}
   if(Ikey02.OemQuestion)     {if((++Input.MAIN_QUESTION) == 255ui8) Input.MAIN_QUESTION = 250ui8;} else {Input.MAIN_QUESTION = 0ui8;}
   if(Ikey02.OemPeriod)       {if((++Input.MAIN_PERIOD) == 255ui8) Input.MAIN_PERIOD = 250ui8;} else {Input.MAIN_PERIOD = 0ui8;}
   if(Ikey02.OemComma)        {if((++Input.MAIN_COMMA) == 255ui8) Input.MAIN_COMMA = 250ui8;} else {Input.MAIN_COMMA = 0ui8;}
   if(Ikey02.Space)           {if((++Input.MAIN_SPACE) == 255ui8) Input.MAIN_SPACE = 250ui8;} else {Input.MAIN_SPACE = 0ui8;}
   if(Ikey02.Escape){if((++Input.CONS_ESC) == 255ui8) Input.CONS_ESC = 250ui8;} else {Input.CONS_ESC = 0ui8;}
   if(Ikey02.F1)    {if((++Input.CONS_F1) == 255ui8) Input.CONS_F1 = 250ui8;} else {Input.CONS_F1 = 0ui8;}
   if(Ikey02.F2)    {if((++Input.CONS_F2) == 255ui8) Input.CONS_F2 = 250ui8;} else {Input.CONS_F2 = 0ui8;}
   if(Ikey02.F3)    {if((++Input.CONS_F3) == 255ui8) Input.CONS_F3 = 250ui8;} else {Input.CONS_F3 = 0ui8;}
   if(Ikey02.F4)    {if((++Input.CONS_F4) == 255ui8) Input.CONS_F4 = 250ui8;} else {Input.CONS_F4 = 0ui8;}
   if(Ikey02.F5)    {if((++Input.CONS_F5) == 255ui8) Input.CONS_F5 = 250ui8;} else {Input.CONS_F5 = 0ui8;}
   if(Ikey02.F6)    {if((++Input.CONS_F6) == 255ui8) Input.CONS_F6 = 250ui8;} else {Input.CONS_F6 = 0ui8;}
   if(Ikey02.F7)    {if((++Input.CONS_F7) == 255ui8) Input.CONS_F7 = 250ui8;} else {Input.CONS_F7 = 0ui8;}
   if(Ikey02.F8)    {if((++Input.CONS_F8) == 255ui8) Input.CONS_F8 = 250ui8;} else {Input.CONS_F8 = 0ui8;}
   if(Ikey02.F9)    {if((++Input.CONS_F9) == 255ui8) Input.CONS_F9 = 250ui8;} else {Input.CONS_F9 = 0ui8;}
   if(Ikey02.F10)   {if((++Input.CONS_F10) == 255ui8) Input.CONS_F10 = 250ui8;} else {Input.CONS_F10 = 0ui8;}
   if(Ikey02.F11)   {if((++Input.CONS_F11) == 255ui8) Input.CONS_F11 = 250ui8;} else {Input.CONS_F11 = 0ui8;}
   if(Ikey02.F12)   {if((++Input.CONS_F12) == 255ui8) Input.CONS_F12 = 250ui8;} else {Input.CONS_F12 = 0ui8;}
   if(Ikey02.PrintScreen) {if((++Input.CONS_PRTSC) == 255ui8) Input.CONS_PRTSC = 250ui8;} else {Input.CONS_PRTSC = 0ui8;}
   if(Ikey02.Delete)      {if((++Input.CONS_DELETE) == 255ui8) Input.CONS_DELETE = 250ui8;} else {Input.CONS_DELETE = 0ui8;}
   if(Ikey02.Back)        {if((++Input.CONS_BACK) == 255ui8) Input.CONS_BACK = 250ui8;} else {Input.CONS_BACK = 0ui8;}
   if(Ikey02.Tab)         {if((++Input.CONS_TAB) == 255ui8) Input.CONS_TAB = 250ui8;} else {Input.CONS_TAB = 0ui8;}
   if(Ikey02.CapsLock)    {if((++Input.CONS_CAPS) == 255ui8) Input.CONS_CAPS = 250ui8;} else {Input.CONS_CAPS = 0ui8;}
   if(Ikey02.Enter)       {if((++Input.CONS_ENTER) == 255ui8) Input.CONS_ENTER = 250ui8;} else {Input.CONS_ENTER = 0ui8;}
   if(Ikey02.LeftShift)   {if((++Input.CONS_LSHIFT) == 255ui8) Input.CONS_LSHIFT = 250ui8;} else {Input.CONS_LSHIFT = 0ui8;}
   if(Ikey02.RightShift)  {if((++Input.CONS_RSHIFT) == 255ui8) Input.CONS_RSHIFT = 250ui8;} else {Input.CONS_RSHIFT = 0ui8;}
   if(Ikey02.LeftAlt)     {if((++Input.CONS_LALT) == 255ui8) Input.CONS_LALT = 250ui8;} else {Input.CONS_LALT = 0ui8;}
   if(Ikey02.RightAlt)    {if((++Input.CONS_RALT) == 255ui8) Input.CONS_RALT = 250ui8;} else {Input.CONS_RALT = 0ui8;}
   if(Ikey02.LeftControl) {if((++Input.CONS_LCTRL) == 255ui8) Input.CONS_LCTRL = 250ui8;} else {Input.CONS_LCTRL = 0ui8;}
   if(Ikey02.RightControl){if((++Input.CONS_RCTRL) == 255ui8) Input.CONS_RCTRL = 250ui8;} else {Input.CONS_RCTRL = 0ui8;}
   if(Ikey02.Up)   {if((++Input.CONS_UP) == 255ui8) Input.CONS_UP = 250ui8;} else {Input.CONS_UP = 0ui8;}
   if(Ikey02.Left) {if((++Input.CONS_LEFT) == 255ui8) Input.CONS_LEFT = 250ui8;} else {Input.CONS_LEFT = 0ui8;}
   if(Ikey02.Down) {if((++Input.CONS_DOWN) == 255ui8) Input.CONS_DOWN = 250ui8;} else {Input.CONS_DOWN = 0ui8;}
   if(Ikey02.Right){if((++Input.CONS_RIGHT) == 255ui8) Input.CONS_RIGHT = 250ui8;} else {Input.CONS_RIGHT = 0ui8;}
   if(Ikey02.NumPad0){if((++Input.NUMS_0) == 255ui8) Input.NUMS_0 = 250ui8;} else {Input.NUMS_0 = 0ui8;}
   if(Ikey02.NumPad1){if((++Input.NUMS_1) == 255ui8) Input.NUMS_1 = 250ui8;} else {Input.NUMS_1 = 0ui8;}
   if(Ikey02.NumPad2){if((++Input.NUMS_2) == 255ui8) Input.NUMS_2 = 250ui8;} else {Input.NUMS_2 = 0ui8;}
   if(Ikey02.NumPad3){if((++Input.NUMS_3) == 255ui8) Input.NUMS_3 = 250ui8;} else {Input.NUMS_3 = 0ui8;}
   if(Ikey02.NumPad4){if((++Input.NUMS_4) == 255ui8) Input.NUMS_4 = 250ui8;} else {Input.NUMS_4 = 0ui8;}
   if(Ikey02.NumPad5){if((++Input.NUMS_5) == 255ui8) Input.NUMS_5 = 250ui8;} else {Input.NUMS_5 = 0ui8;}
   if(Ikey02.NumPad6){if((++Input.NUMS_6) == 255ui8) Input.NUMS_6 = 250ui8;} else {Input.NUMS_6 = 0ui8;}
   if(Ikey02.NumPad7){if((++Input.NUMS_7) == 255ui8) Input.NUMS_7 = 250ui8;} else {Input.NUMS_7 = 0ui8;}
   if(Ikey02.NumPad8){if((++Input.NUMS_8) == 255ui8) Input.NUMS_8 = 250ui8;} else {Input.NUMS_8 = 0ui8;}
   if(Ikey02.NumPad9){if((++Input.NUMS_9) == 255ui8) Input.NUMS_9 = 250ui8;} else {Input.NUMS_9 = 0ui8;}
   if(Ikey02.LeftWindows || Ikey02.RightWindows){if((++Input.CONS_WINDOWS) == 255ui8) Input.CONS_WINDOWS = 250ui8;} else {Input.CONS_WINDOWS = 0ui8;}
   
   if(Input.CONS_CAPS == 1) Input.RESH_CAPS = !Input.RESH_CAPS;

   auto Imou02 = Imou01->GetState();
   Input.MOUS_X = L_Rounding(rxint64(Imou02.x) / Varb0010) - Varb0008;
   Input.MOUS_Y = L_Rounding(rxint64(Imou02.y) / Varb0011) - Varb0009;
   if(Imou02.leftButton)    {if((++Input.MOUS_Left) == 255ui8) Input.MOUS_Left = 250ui8; Input.MOUS_Left_Release = 0ui8;} else {Input.MOUS_Left = 0ui8; if((++Input.MOUS_Left_Release) == 255ui8) Input.MOUS_Left_Release = 250ui8;}
   if(Imou02.middleButton)  {if((++Input.MOUS_Mid) == 255ui8) Input.MOUS_Mid = 250ui8; Input.MOUS_Mid_Release = 0ui8;} else {Input.MOUS_Mid = 0ui8; if((++Input.MOUS_Mid_Release) == 255ui8) Input.MOUS_Mid_Release = 250ui8;}
   if(Imou02.rightButton)   {if((++Input.MOUS_Right) == 255ui8) Input.MOUS_Right = 250ui8; Input.MOUS_Right_Release = 0ui8;} else {Input.MOUS_Right = 0ui8; if((++Input.MOUS_Right_Release) == 255ui8) Input.MOUS_Right_Release = 250ui8;}
   if(Input.MOUS_Left == 1 || Input.MOUS_Left_Release > 1) {Input.MOUS_X_Left = Input.MOUS_X; Input.MOUS_Y_Left = Input.MOUS_Y;}
   if(Input.MOUS_Mid == 1 || Input.MOUS_Mid_Release > 1)  {Input.MOUS_X_Mid = Input.MOUS_X; Input.MOUS_Y_Mid = Input.MOUS_Y;}
   if(Input.MOUS_Right == 1 || Input.MOUS_Right_Release > 1){Input.MOUS_X_Right = Input.MOUS_X; Input.MOUS_Y_Right = Input.MOUS_Y;}

   auto Ipad02 = Ipad01->GetState(0);
  }
  int0 P_EngineFrame(xint64 Vrab01, xint64 Vrab02, uint32 Vrab03, uint32 Vrab04, DirectX::Keyboard *Ikey01, DirectX::GamePad *Ipad01, DirectX::Mouse *Imou01)
  {
   UNREFERENCED_PARAMETER(Vrab02); UNREFERENCED_PARAMETER(Vrab03); UNREFERENCED_PARAMETER(Vrab04); if(Varb0001 == 0){Varb0015 = std::chrono::steady_clock::now().time_since_epoch().count(); Varb0025 = L_Exist("Database\\Game\\Enchanted");} Varb0001 += 1; if(Varb0001 == 0xFFFFFFFFFFFFFFFF) Varb0001 = 0xFFFFFFFFFFFEBF; remains xint64 Varb01; Varb01 += Vrab01; if(Varb0001 % ruint64(Varb0004) != 0) return; P_EngineInput(Ikey01, Ipad01, Imou01); Disp0001.clear(); remains uint64 Varb02; Varb02 += 1; remains uint64 Varb03; if(Varb01 > 1.0){while(Varb01 > 1.0) Varb01 -= 1.0; Varb03 = Varb02; Varb02 = 0;}

   if(Varb0026){LF2_Enchanted(Vrab04, Varb03); return;}

   if(!Varb0026 && Varb0025) // Go to LF2 : Enchanted
   {
    Enchanted = std::make_unique < HEPTA_LF2_ENCHANTED > (); Varb0026 = true;
   }
  }
 //-//











 // External-Included Dependency Program - LF2 : Enchanted 4th
  int0 LF2_Enchanted(uint32 Vrab01, uint64 Vrab02) fastened
  {
   string Temp69; // debug

   if(Enchanted->Initialization)
   {
    Varb0004 = 2;
    Enchanted->Initialization = false;
    Enchanted->Pic_Index_Interface.clear(); Enchanted->Sound_Index_Interface.clear(); Enchanted->Back_Index_Interface.clear(); statics string Temp01 = Enchanted->Memory[0].Address;
    Enchanted->Load_Memory(Temp01 + "config.ini"); Enchanted->Save_Memory(Temp01 + "config.ini"); Varb0012 = rxint32((rxint64(Enchanted->Memory[0].Volume) / 100) * 0.1); if(Enchanted->Memory[0].Pan > 0){Varb0013 = rxint32(Enchanted->Memory[0].Pan) / 100;} else {Varb0013 = -(rxint32(-Enchanted->Memory[0].Pan) / 100);}
    Enchanted->Update_Window(Enchanted->Memory[0].Screen_W, Enchanted->Memory[0].Screen_H, Enchanted->Memory[0].Fullscreen);
    // Interface's background load.
     {
      statics string Temp02 = "Database\\Interface\\Enchanted\\", Temp03 = ".bmp";
      int1 Vrab03 = true; insize Vrab04 = 0;
      while(Vrab03){Vrab04 += 1; Enchanted->Back_Index_Interface.push_back(G_SetPic(Temp02 + "BACK" + std::to_string(Vrab04) + Temp03)); Vrab03 = Enchanted->Back_Index_Interface[Vrab04 - 1] != rinsize(-1);}
      Enchanted->Back_Index_Interface.pop_back();
      // First randomized background.
       if(Enchanted->Back_Index_Interface.size() > 0)
       Enchanted->Background1 = Enchanted->Back_Index_Interface[rinsize(L_Random(Enchanted->Back_Index_Interface.size() - 1))];
      //-//
     }
    //-//
    // Interface's pic load.
     {
      statics string Temp02 = "Database\\Interface\\Enchanted\\", Temp03 = ".bmp";
      Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp02 + "WORDS0" + Temp03, 16, 16, 15, 15));     // Index : 0
      Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp02 + "WORDS1" + Temp03, 16, 16, 15, 15));     // Index : 1
      Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp02 + "WORDS2" + Temp03, 16, 16, 15, 15));     // Index : 2
      Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp02 + "WORDS3" + Temp03, 16, 16, 15, 15));     // Index : 3
      Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp02 + "WORDS4" + Temp03, 16, 16, 15, 15));     // Index : 4
      Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp02 + "WORDS5" + Temp03, 16, 16, 15, 15));     // Index : 5
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 278, 260, 12, 12));        // Index : 6 (Info Bar Top-Left Corner)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 291, 260, 12, 12));        // Index : 7 (Info Bar Top-Right Corner)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 278, 273, 12, 12));        // Index : 8 (Info Bar Bottom-Left Corner)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 291, 273, 12, 12));        // Index : 9 (Info Bar Bottom-Right Corner)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 290, 260, 1, 3));          // Index : 10 (Info Bar Horizontal Corner)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 278, 272, 3, 1));          // Index : 11 (Info Bar Vertical Corner)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 801, 382, 200, 200));      // Index : 12 (Info Bar Area)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "CURSOR1" + Temp03));                       // Index : 13
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "CURSOR2" + Temp03));                       // Index : 14

      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 0, 0, 800, 37));           // Index : 15 (Copyright)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 0, 38, 490, 79));          // Index : 16 (Title)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 38, 154, 169));       // Index : 17 (Main Buttons)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 646, 38, 154, 18));        // Index : 18 (Main Buttons - Game Start)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 646, 67, 154, 20));        // Index : 19 (Main Buttons - Network Game)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 646, 99, 154, 19));        // Index : 20 (Main Buttons - Game Settings)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 646, 129, 154, 20));       // Index : 21 (Main Buttons - Control Settings)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 646, 161, 154, 19));       // Index : 22 (Main Buttons - Recording Info)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 646, 191, 154, 16));       // Index : 23 (Main Buttons - Official Fansite)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 0, 118, 151, 26));         // Index : 24 (Ok Button)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 0, 145, 151, 26));         // Index : 25 (Ok Button)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 152, 118, 151, 26));       // Index : 26 (Cancel Button)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 152, 145, 151, 26));       // Index : 27 (Cancel Button)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 801, 0, 704, 381));        // Index : 28 (Control Setting Menu)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 587, 300, 106, 91));       // Index : 29 (Input - Keyboard)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 694, 208, 106, 91));       // Index : 30 (Input - Joy1)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 587, 208, 106, 91));       // Index : 31 (Input - Joy2)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 694, 392, 106, 91));       // Index : 32 (Input - Joy3)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 694, 300, 106, 91));       // Index : 33 (Input - Joy4)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 304, 118, 186, 169));      // Index : 34 (Game Buttons)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 304, 288, 186, 14));       // Index : 35 (Game Buttons - Versus)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 304, 319, 186, 18));       // Index : 36 (Game Buttons - Stage)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 304, 349, 186, 19));       // Index : 37 (Game Buttons - Championship)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 304, 380, 186, 15));       // Index : 38 (Game Buttons - Battle)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 304, 411, 186, 19));       // Index : 39 (Game Buttons - Recording Playback)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 304, 443, 186, 14));       // Index : 40 (Game Buttons - Return)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 1506, 0, 744, 437));       // Index : 41 (Character Selection)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 1264, 382, 120, 66));      // Index : 42 (Character Selection - Press Attack to Join)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 1385, 382, 120, 66));      // Index : 43 (Character Selection - Press Attack to Join2)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 1001, 382, 120, 120));     // Index : 44 (Character Selection - Random)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 535, 208, 51, 58));        // Index : 45 (Character Selection - Counter - 5)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 535, 267, 51, 58));        // Index : 46 (Character Selection - Counter - 4)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 535, 326, 51, 58));        // Index : 47 (Character Selection - Counter - 3)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 590, 392, 51, 58));        // Index : 48 (Character Selection - Counter - 2)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 642, 392, 51, 58));        // Index : 49 (Character Selection - Counter - 1)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 0, 172, 303, 87));         // Index : 50 (Character Selection - Computer Player)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 208, 6, 10));         // Index : 51 (Character Selection - Computer Player - 0)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 498, 208, 6, 10));         // Index : 52 (Character Selection - Computer Player - 1)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 505, 208, 6, 10));         // Index : 53 (Character Selection - Computer Player - 2)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 512, 208, 6, 10));         // Index : 54 (Character Selection - Computer Player - 3)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 519, 208, 6, 10));         // Index : 55 (Character Selection - Computer Player - 4)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 526, 208, 6, 10));         // Index : 56 (Character Selection - Computer Player - 5)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 219, 6, 10));         // Index : 57 (Character Selection - Computer Player - 6)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 498, 219, 6, 10));         // Index : 58 (Character Selection - Computer Player - 7)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 505, 219, 6, 10));         // Index : 59 (Character Selection - Computer Player - 0 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 512, 219, 6, 10));         // Index : 60 (Character Selection - Computer Player - 1 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 519, 219, 6, 10));         // Index : 61 (Character Selection - Computer Player - 2 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 526, 219, 6, 10));         // Index : 62 (Character Selection - Computer Player - 3 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 230, 6, 10));         // Index : 63 (Character Selection - Computer Player - 4 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 498, 230, 6, 10));         // Index : 64 (Character Selection - Computer Player - 5 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 505, 230, 6, 10));         // Index : 65 (Character Selection - Computer Player - 6 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 512, 230, 6, 10));         // Index : 66 (Character Selection - Computer Player - 7 Active)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 0, 260, 264, 168));        // Index : 67 (Character Selection - Menu)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 208, 0, 0));          // Index : 68 (Color - 1) (#10206C)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 210, 0, 0));          // Index : 69 (Color - 2)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 212, 0, 0));          // Index : 70 (Color - 3)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 214, 0, 0));          // Index : 71 (Color - 4)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 216, 0, 0));          // Index : 72 (Color - 5)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 218, 0, 0));          // Index : 73 (Color - 6)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 220, 0, 0));          // Index : 74 (Color - 7)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 222, 0, 0));          // Index : 75 (Color - 8)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 224, 0, 0));          // Index : 76 (Color - 9)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 226, 0, 0));          // Index : 77 (Color - 10)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 228, 0, 0));          // Index : 78 (Color - 11)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 230, 0, 0));          // Index : 79 (Color - 12)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 232, 0, 0));          // Index : 80 (Color - 13)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 234, 0, 0));          // Index : 81 (Color - 14)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 236, 0, 0));          // Index : 82 (Color - 15)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 533, 238, 0, 0));          // Index : 83 (Color - 16)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 307, 21, 21));        // Index : 84 (Input - Attack)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 307, 21, 21));        // Index : 85 (Input - Attack Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 285, 21, 21));        // Index : 86 (Input - Defend)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 329, 21, 21));        // Index : 87 (Input - Defend Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 285, 21, 21));        // Index : 88 (Input - Jump)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 329, 21, 21));        // Index : 89 (Input - Jump Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 241, 21, 21));        // Index : 90 (Input - Up)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 351, 21, 21));        // Index : 91 (Input - Up Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 241, 21, 21));        // Index : 92 (Input - Left)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 351, 21, 21));        // Index : 93 (Input - Left Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 263, 21, 21));        // Index : 94 (Input - Down)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 373, 21, 21));        // Index : 95 (Input - Down Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 263, 21, 21));        // Index : 96 (Input - Right)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 513, 373, 21, 21));        // Index : 97 (Input - Right Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 395, 66, 17));        // Index : 98 (Setting - Graphic)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 413, 66, 17));        // Index : 99 (Setting - Audio)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 491, 431, 66, 17));        // Index : 100 (Setting - Platform)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 2251, 0, 704, 338));       // Index : 101 (Recording Info)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 456, 484, 344, 23));       // Index : 102 (Recording Info - Button)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 284, 286, 19, 19));        // Index : 103 (Check)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 284, 306, 19, 19));        // Index : 104 (Check - Off)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 265, 286, 18, 18));        // Index : 105 (Info - Question)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 265, 305, 18, 18));        // Index : 106 (Info - Important)
      Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp02 + "MENU" + Temp03, 519, 230, 6, 10));         // Index : 107 (Character Selection - Computer Player - 8 Active)
     }
    //-//
    // Interface's sound load.
     {
      statics string Temp02 = "Database\\Audio\\Enchanted\\", Temp03 = ".wav";
      Enchanted->Sound_Index_Interface.push_back(G_SetSound(Temp02 + "OK" + Temp03));       // Index : 0
      Enchanted->Sound_Index_Interface.push_back(G_SetSound(Temp02 + "CANCEL" + Temp03));   // Index : 1
     }
    //-//
     Enchanted->Post_Info("Platform Version : " + Enchanted->Version() + " (Beta).");
   } else {if(Enchanted->Memory[0].Fullscreen != Varb0014){Enchanted->Memory[0].Fullscreen = Varb0014; Enchanted->Save_Memory(Enchanted->Memory[0].Address + "config.ini");} L_Random(0); Enchanted->Tick += 1; if(Enchanted->Tick == 0xFFFFFFFFFFFFFFFF) Enchanted->Tick = 0xFFFFFFFFFFFEBF; Enchanted->Draw = true; Enchanted->Number_Of_Sound = 0; Varb0012 = rxint32((rxint64(Enchanted->Memory[0].Volume) / 100) * 0.1); if(Enchanted->Memory[0].Pan > 0){Varb0013 = rxint32(Enchanted->Memory[0].Pan) / 100;} else {Varb0013 = -(rxint32(-Enchanted->Memory[0].Pan) / 100);}}

   {
    statics int64 &Vrab03 = Enchanted->Display_CenX, &Vrab04 = Enchanted->Display_CenY, &Vrab05 = Enchanted->Display_W, &Vrab06 = Enchanted->Display_H;
    switch(Enchanted->Menu)
    {
     case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 252: case 253: case 254: case 255: // Main Menu
      {
       G_SetDisplay(6, Enchanted->Pic_Index_Interface[68], 0, 0, 0, 255ui8, Vrab05, Vrab06);
       G_SetDisplay(2, Enchanted->Background1, 0, Vrab04 - 275ll);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[15], Vrab03 - 400, Vrab06 - 45);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[16], Vrab03 - 245, L_Rounding64(rxint64(Vrab04) / 2) - 79);
       if(Enchanted->Menu < 7 || Enchanted->Menu > 8) G_SetDisplay(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85);

       switch(Enchanted->Menu)
       {
        case 0: // Base
         {
          uint8 Vrab07 = 0;
          if(L_In(Vrab03 - 80, Vrab04 - 86, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[18], Vrab03 - 77, Vrab04 - 85); if(L_On(Vrab03 - 80, Vrab04 - 86, 160, 20)) Vrab07 = 1;}
        //if(L_In(Vrab03 - 80, Vrab04 - 55, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[19], Vrab03 - 77, Vrab04 - 56); if(L_On(Vrab03 - 80, Vrab04 - 55, 160, 20)) Vrab07 = 2;}
          if(L_In(Vrab03 - 80, Vrab04 - 24, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[20], Vrab03 - 77, Vrab04 - 24); if(L_On(Vrab03 - 80, Vrab04 - 24, 160, 20)) Vrab07 = 3;}
          if(L_In(Vrab03 - 80, Vrab04 + 7, 160, 20)) {Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[21], Vrab03 - 77, Vrab04 + 6);  if(L_On(Vrab03 - 80, Vrab04 + 7, 160, 20))  Vrab07 = 4;}
          if(L_In(Vrab03 - 80, Vrab04 + 38, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[22], Vrab03 - 77, Vrab04 + 38); if(L_On(Vrab03 - 80, Vrab04 + 38, 160, 20)) Vrab07 = 5;}
          if(L_In(Vrab03 - 80, Vrab04 + 69, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[23], Vrab03 - 77, Vrab04 + 68); if(L_On(Vrab03 - 80, Vrab04 + 69, 160, 20)) Vrab07 = 6;}
          if(Enchanted->Runtime3 > 2) if(Enchanted->Memory[0].Skip_Animation){Enchanted->Runtime3 = 0;} else {Enchanted->Runtime3 -= 3; G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);}

          int1 Vrab08 = L_Input(Varb0021) == 1, Vrab09 = L_Input(Varb0023) == 1, Vrab10 = L_Input(Varb0020) == 1; statics int1 Vrab11 = ((Enchanted->Tick % 20) / 10) == 0;
          if(!Vrab08){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab08 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][0]) == 1); if(Vrab08) break;}}
          if(!Vrab09){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab09 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][1]) == 1); if(Vrab09) break;}}
          if(!Vrab10){for(insize Vrab12 = 0; Vrab12 < 4; ++Vrab12){Vrab10 = (L_Input(Enchanted->Memory[0].P_Input[Vrab12][4]) == 1); if(Vrab10) break;}}
          if(Vrab08 == Vrab09){Vrab08 = Vrab09 = false;} if(Enchanted->Runtime1 == 0) if(L_Input(Varb0022) == 1 || L_Input(Varb0024) == 1) Enchanted->Runtime1 = 1;
          {
           statics int64 Vrab12 = Vrab03 - 95, Vrab13 = 190, Vrab14 = 26; int64 Vrab15 = Vrab04 - 1;
           switch(ruint8(Enchanted->Runtime1))
           {
            case 1: Vrab15 -= 89; case 0: if(Vrab08) Enchanted->Runtime1 = 6; if(Vrab09) Enchanted->Runtime1 = 3; if(Vrab10) Vrab07 = 1;
            break;
            case 2: Vrab15 -= 58; if(Vrab08) Enchanted->Runtime1 = 1; if(Vrab09) Enchanted->Runtime1 = 3; if(Vrab10) Vrab07 = 2; break;
            case 3: Vrab15 -= 27; if(Vrab08) Enchanted->Runtime1 = 1; if(Vrab09) Enchanted->Runtime1 = 4; if(Vrab10) Vrab07 = 3; break;
            case 4: Vrab15 += 4; if(Vrab08) Enchanted->Runtime1 = 3; if(Vrab09) Enchanted->Runtime1 = 5; if(Vrab10) Vrab07 = 4; break;
            case 5: Vrab15 += 35; if(Vrab08) Enchanted->Runtime1 = 4; if(Vrab09) Enchanted->Runtime1 = 6; if(Vrab10) Vrab07 = 5; break;
            case 6: Vrab15 += 66; if(Vrab08) Enchanted->Runtime1 = 5; if(Vrab09) Enchanted->Runtime1 = 1; if(Vrab10) Vrab07 = 6; break;
            default: break;
           }
           if(Enchanted->Runtime1 > 0){G_SetDisplay(1, 0xFFFFFF, Vrab12, Vrab15, 0, 255ui8, Vrab13, Vrab14); if(Vrab11) G_SetDisplay(1, 0xFFFFFF, Vrab12 - 1, Vrab15 - 1, 0, 255ui8, Vrab13 + 2, Vrab14 + 2);}
          }

          if(Vrab07 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);
          switch(Vrab07)
          {
           case 1: if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(255);} else {Enchanted->Reset(1, 0, 120, Enchanted->Runtime3);} break;
           case 2: break;
           case 3: break;
           case 4: Enchanted->Memory[1] = Enchanted->Memory[0]; if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(255);} else {Enchanted->Reset(254, 0, 120, Enchanted->Runtime3);} break;
           case 5: Enchanted->Memory[1] = Enchanted->Memory[0]; if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(253);} else {Enchanted->Reset(252, 0, 120, Enchanted->Runtime3);} break;
           case 6: ShellExecuteW(0, 0, L"http://www.lf-empire.de", 0, 0, SW_SHOW); break;
           default: break;
          }
         }
        break;
        case 1: // Game Start - Animation Phase 1
         {
          if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);
          Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 -= 1;

          Enchanted->Print_Bar(Vrab03 + 500 - (Enchanted->Runtime1), Vrab04 - 24, 100, 0);

          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(2, 0, 64, Enchanted->Runtime3);
         }
        break;
        case 2: // Game Start - Animation Phase 2
         {
          if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);
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
           if(Enchanted->Runtime3 == 2){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "Unexpected end of \"<object>\", it should be end with \"<object_end>\"."; Enchanted->Runtime3 = 7;}
          }

          if(Enchanted->Runtime3 == 3)
          {
           string Temp01; Labl03:
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: Temp01 = Enchanted->Engine1->Load(Enchanted->Memory[0].Address, Enchanted->Memory[0].Custom_Mirror);
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
           if(Enchanted->Runtime3 == 5){Enchanted->String[2] = "\"" + Temp02 + "\""; Enchanted->String[3] = "Unexpected end of \"<background>\", it should be end with \"<background_end>\"."; Enchanted->Runtime3 = 7;}
          }

          if(Enchanted->Runtime3 == 6)
          {
           string Temp01; Labl04:
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: Temp01 = Enchanted->Engine1->Manage(Enchanted->Memory[0].Address);
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
          
          if(Enchanted->Runtime3 == 7) Enchanted->Reset(4, 0, 100);

          if(Enchanted->Runtime3 == 8){{int1 Vrab07 = false; switch(Enchanted->Memory[0].Engine){case 1: break; default: Vrab07 = Enchanted->Engine1->Warning(); break;} if(Vrab07) Enchanted->Post_Info("Warning(s) found while processing the data(s), check \"Database\\Log.log\" for details.");} Enchanted->Reset(7, 0, 0, 180); Enchanted->String[0] = "<none>"; Enchanted->String[1] = "<none>"; if(Enchanted->File1.is_open()) Enchanted->File1.close();}

          {
           G_SetDisplay(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06);
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
          G_SetDisplay(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06);
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
          G_SetDisplay(2, Enchanted->Pic_Index_Interface[24], Vrab03 - 76, Vrab04 + 509 - rint64(Enchanted->Runtime1));
          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(5);
         }
        break;
        case 5: // Game Start - Failed
         {
          if(Enchanted->Runtime3 == 0)
          {
           Enchanted->Runtime3 = 1;
           if(Enchanted->File1.is_open()) Enchanted->File1.close();
           G_ClearSprite(6); G_ClearPic(Enchanted->Pic_Index_Interface[Enchanted->Pic_Index_Interface.size() - 1] + 1); G_CleanUnreferencedImage();
           switch(Enchanted->Memory[0].Engine)
           {
            case 1: break;
            default: Enchanted->Engine1.reset(); break;
           }
          }
          G_SetDisplay(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06);
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
          statics int64 Vrab12 = Vrab03 - 76, Vrab13 = Vrab04 + 133; if(L_In(Vrab12, Vrab13, 151, 26)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[25], Vrab12, Vrab13); if(L_On(Vrab12, Vrab13, 151, 26)){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); Enchanted->Reset(6, 0, 0, 180);}} else
          {G_SetDisplay(2, Enchanted->Pic_Index_Interface[24], Vrab12, Vrab13);}
          if(Enchanted->Runtime1 == 0)
          {if(L_Input(Varb0021) == 1 || L_Input(Varb0022) == 1 || L_Input(Varb0023) == 1 || L_Input(Varb0024) == 1) Enchanted->Runtime1 = 1;}
          if(Enchanted->Runtime1 == 1)
          {G_SetDisplay(1, 0xFFFFFF, Vrab12 -1, Vrab13 - 1, 0ui8, 255ui8, 153, 28); if((Enchanted->Tick % 20) / 10 == 0) G_SetDisplay(1, 0xFFFFFF, Vrab12 - 2, Vrab13 - 2, 0ui8, 255ui8, 155, 30);}
         }
        break;
        case 6: // Game Start - Failed - Animation Phase 2
         {
          if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);
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
          G_SetDisplay(2, Enchanted->Pic_Index_Interface[24], Vrab03 - 76, Vrab04 + 133 + rint64(Enchanted->Runtime1));

          if(Enchanted->Runtime2 == 121) Enchanted->Reset(0);
         }
        break;
        case 7: // Game Start - Success
         {
          Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 += 1;

          if(Enchanted->Runtime2 < 20) G_SetDisplay(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85);
          if(Enchanted->Runtime2 >= 20 && Enchanted->Runtime2 <= 70){G_SetDisplay(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(70 - Enchanted->Runtime2) / 50) * 255.0)));}
          if(Enchanted->Runtime2 >= 71){G_SetDisplay(2, Enchanted->Pic_Index_Interface[34], Vrab03 - 93, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(Enchanted->Runtime2 - 71) / 50) * 255.0)));}
          
          if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);

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
          if(Enchanted->Runtime1 != 7){G_SetDisplay(2, Enchanted->Pic_Index_Interface[34], Vrab03 - 93, Vrab04 - 85);} else
          {
           Enchanted->Runtime2 += 1;
           if(Enchanted->Runtime2 <= 50){G_SetDisplay(2, Enchanted->Pic_Index_Interface[34], Vrab03 - 93, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(50 - Enchanted->Runtime2) / 50) * 255.0)));}
           if(Enchanted->Runtime2 >= 51){G_SetDisplay(2, Enchanted->Pic_Index_Interface[17], Vrab03 - 77, Vrab04 - 85, 0ui8, ruint8(L_Rounding((rxint64(Enchanted->Runtime2 - 51) / 50) * 255.0)));}
           if(Enchanted->Runtime2 == 101){Enchanted->Reset(0); break;}
          }

          if(Enchanted->Runtime1 <= 6)
          {
           uint8 Vrab07 = 0;
           if(L_In(Vrab03 - 80, Vrab04 - 86, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[35], Vrab03 - 93, Vrab04 - 85); if(L_On(Vrab03 - 80, Vrab04 - 86, 160, 20)) Vrab07 = 1;}
           if(L_In(Vrab03 - 80, Vrab04 - 55, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[36], Vrab03 - 93, Vrab04 - 54); if(L_On(Vrab03 - 80, Vrab04 - 55, 160, 20)) Vrab07 = 2;}
           if(L_In(Vrab03 - 80, Vrab04 - 24, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[37], Vrab03 - 93, Vrab04 - 24); if(L_On(Vrab03 - 80, Vrab04 - 24, 160, 20)) Vrab07 = 3;}
           if(L_In(Vrab03 - 80, Vrab04 + 7, 160, 20)) {Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[38], Vrab03 - 93, Vrab04 + 7);  if(L_On(Vrab03 - 80, Vrab04 + 7, 160, 20))  Vrab07 = 4;}
           if(L_In(Vrab03 - 80, Vrab04 + 38, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[39], Vrab03 - 93, Vrab04 + 38); if(L_On(Vrab03 - 80, Vrab04 + 38, 160, 20)) Vrab07 = 5;}
           if(L_In(Vrab03 - 80, Vrab04 + 69, 160, 20)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[40], Vrab03 - 93, Vrab04 + 70); if(L_On(Vrab03 - 80, Vrab04 + 69, 160, 20)) Vrab07 = 6;}

           if(Enchanted->Runtime3 > 2) if(Enchanted->Memory[0].Skip_Animation){Enchanted->Runtime3 = 0;} else {Enchanted->Runtime3 -= 3; G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);}

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
            if(Enchanted->Runtime1 > 0){G_SetDisplay(1, 0xFFFFFF, Vrab12, Vrab15, 0, 255ui8, Vrab13, Vrab14); if(Vrab11) G_SetDisplay(1, 0xFFFFFF, Vrab12 - 1, Vrab15 - 1, 0, 255ui8, Vrab13 + 2, Vrab14 + 2);}
           }

           if(Vrab07 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);
           switch(Vrab07)
           {
            case 1: Enchanted->Reset(8, 8); break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6:
             {
              G_ClearSprite(6); G_ClearPic(Enchanted->Pic_Index_Interface[Enchanted->Pic_Index_Interface.size() - 1] + 1); G_CleanUnreferencedImage();
              switch(Enchanted->Memory[0].Engine)
              {
               case 1: break;
               default: Enchanted->Engine1.reset(); break;
              }
              Enchanted->Runtime1 = 7; Enchanted->Runtime2 = 0;
             }
            break;
            default: break;
           }
          }

          if(Enchanted->Runtime1 == 8)
          {
           G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(Enchanted->Runtime2) / 30) * 255.0)), Vrab05, Vrab06);
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
           G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(30 - Enchanted->Runtime2) / 30) * 255.0)), Vrab05, Vrab06);
           if(Enchanted->Runtime2 <= 30){Enchanted->Runtime2 += 1;} else {Enchanted->Reset(8);}
          }
         }
        break;
        case 252: // Recording Info - Animation Phase
         {
          if(Enchanted->Runtime2 > 120)
          {if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; Enchanted->Runtime1 -= ((Enchanted->Runtime2 - 120) / 12); Enchanted->Runtime2 += 1;} else
          {if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 -= 1;}
          G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);

          {
           statics int64 Vrab07 = Vrab03 - 352, Vrab08 = Vrab04 - 718 + (Enchanted->Runtime1);
           G_SetDisplay(2, Enchanted->Pic_Index_Interface[101], Vrab07, Vrab08);
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
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[103], Vrab07 + 166, Vrab08 + 211);} else
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[104], Vrab07 + 166, Vrab08 + 211);}
           if(Enchanted->Memory[1].True_Recording)
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[103], Vrab07 + 519, Vrab08 + 211);} else
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[104], Vrab07 + 519, Vrab08 + 211);}
          }
          
          if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(253);
          if(Enchanted->Runtime2 == 241) Enchanted->Reset(0, 0, 0, Enchanted->Runtime3);
         }
        break;
        case 253: // Recording Info
         {
          G_SetDisplay(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06); uint8 Vrab07 = 0;

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
           G_SetDisplay(2, Enchanted->Pic_Index_Interface[101], Vrab08, Vrab09);

           if(L_In(Vrab08 + 165, Vrab09 + 211, 19, 19)){Enchanted->Draw = false; if(L_On(Vrab08 + 165, Vrab09 + 211, 19, 19)) Enchanted->Memory[1].Recording = !Enchanted->Memory[1].Recording;}
           if(L_In(Vrab08 + 519, Vrab09 + 211, 19, 19)){Enchanted->Draw = false; if(L_On(Vrab08 + 519, Vrab09 + 211, 19, 19)) Enchanted->Memory[1].True_Recording = !Enchanted->Memory[1].True_Recording;}
           if(L_In(Vrab08 + 180, Vrab09 + 261, 344, 23)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[102], Vrab08 + 180, Vrab09 + 261); if(L_On(Vrab08 + 180, Vrab09 + 261, 344, 23)) Vrab07 = 6;}
           if(L_In(Vrab08 + 187, Vrab09 + 296, 151, 26)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[25], Vrab08 + 187, Vrab09 + 296); if(L_On(Vrab08 + 187, Vrab09 + 296, 151, 26)) Vrab07 = 7;}
           if(L_In(Vrab08 + 366, Vrab09 + 296, 151, 26)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[27], Vrab08 + 366, Vrab09 + 296); if(L_On(Vrab08 + 366, Vrab09 + 296, 151, 26)) Vrab07 = 8;}

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
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[103], Vrab08 + 166, Vrab09 + 211);} else
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[104], Vrab08 + 166, Vrab09 + 211);}
           if(Enchanted->Memory[1].True_Recording)
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[103], Vrab08 + 519, Vrab09 + 211);} else
           {G_SetDisplay(2, Enchanted->Pic_Index_Interface[104], Vrab08 + 519, Vrab09 + 211);}

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
            G_SetDisplay(1, 0xFFFFFF, Vrab11, Vrab12, 0ui8, 255ui8, Vrab13, Vrab14); if(Vrab10) G_SetDisplay(1, 0xFFFFFF, Vrab11 - 1, Vrab12 - 1, 0ui8, 255ui8, Vrab13 + 2, Vrab14 + 2);
           }
          }

          switch(Vrab07)
          {
           case 6: {statics string Temp01 = Enchanted->Memory[0].Address + Enchanted->Memory[1].Record_Address; if(L_Exist(Temp01)) ShellExecuteW(0, 0, std::wstring(Temp01.begin(), Temp01.end()).c_str(), 0, 0, SW_SHOW);} break;
           case 7: Enchanted->Memory[0] = Enchanted->Memory[1]; Enchanted->Save_Memory(Enchanted->Memory[0].Address + "config.ini");
           case 9:
            if(Enchanted->Memory[0].Skip_Animation){Enchanted->Reset(0);} else {Enchanted->Reset(252, 550, 121, 180);}
           break;
           default: break;
          }
          if(Vrab07 == 9){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]);} else
          {if(Vrab07 > 0) Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]);}
         }
        break;
        case 254: // Control Setting - Animation Phase
         {
          if(Enchanted->Runtime2 > 120)
          {if(Enchanted->Runtime3 > 2) Enchanted->Runtime3 -= 3; Enchanted->Runtime1 -= ((Enchanted->Runtime2 - 120) / 12); Enchanted->Runtime2 += 1;} else
          {if(Enchanted->Runtime3 < 180) Enchanted->Runtime3 += 3; Enchanted->Runtime1 += (Enchanted->Runtime2 / 12); Enchanted->Runtime2 -= 1;}
          G_SetDisplay(0, 0x0, 0, 0, 0, Enchanted->Runtime3, Vrab05, Vrab06);

          {
           statics int64 Vrab07 = Vrab03 - 352, Vrab08 = Vrab04 + 356 - (Enchanted->Runtime1);
           G_SetDisplay(2, Enchanted->Pic_Index_Interface[28], Vrab07, Vrab08);
           for(uint64 Vrab09 = 0; Vrab09 < 4; ++Vrab09)
           {
            if(Enchanted->Memory[1].P_Name[Vrab09] == "") Enchanted->Memory[1].P_Name[Vrab09] = "P" + std::to_string(Vrab09 + 1);
            Enchanted->Print_Text(Vrab07 + 203 + (139 * Vrab09) - L_Rounding64(rxint64(Enchanted->Memory[1].P_Name[Vrab09].size()) * 4.5), Vrab08 + 35, 0, Enchanted->Memory[1].P_Name[Vrab09]);
            G_SetDisplay(2, Enchanted->Pic_Index_Interface[29 + Enchanted->Memory[1].P_Con[Vrab09]], Vrab07 + 148 + (139 * Vrab09), Vrab08 + 61);
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
        case 255: // Control Setting
         {
          G_SetDisplay(0, 0x0, 0, 0, 0, 180, Vrab05, Vrab06); uint8 Vrab07 = 0;

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
           G_SetDisplay(2, Enchanted->Pic_Index_Interface[28], Vrab08, Vrab09);
           {statics int64 Vrab10 = Vrab08 + 362, Vrab11 = Vrab09 + 342; if(L_In(Vrab10, Vrab11, 151, 26)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[25], Vrab10, Vrab11); if(L_On(Vrab10, Vrab11, 151, 26)) Vrab07 = 41;}}
           {statics int64 Vrab10 = Vrab08 + 534, Vrab11 = Vrab09 + 342; if(L_In(Vrab10, Vrab11, 151, 26)){Enchanted->Draw = false; G_SetDisplay(2, Enchanted->Pic_Index_Interface[27], Vrab10, Vrab11); if(L_On(Vrab10, Vrab11, 151, 26)) Vrab07 = 42;}}

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
            G_SetDisplay(2, Enchanted->Pic_Index_Interface[29 + Enchanted->Memory[1].P_Con[Vrab10]], Vrab08 + 148 + (139 * Vrab10), Vrab09 + 61);
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
             if(Vrab10 > 40 && Vrab10 < 43){Vrab12 = Vrab08 + 361 + (172 * rint64(Vrab10 - 41)); Vrab13 = Vrab09 + 341; Vrab14 = 153; Vrab15 = 28;}
             G_SetDisplay(1, 0xFFFFFF, Vrab12, Vrab13, 0ui8, 255ui8, Vrab14, Vrab15); if(Vrab11) G_SetDisplay(1, 0xFFFFFF, Vrab12 - 1, Vrab13 - 1, 0ui8, 255ui8, Vrab14 + 2, Vrab15 + 2);
            }
           }
          }
          
          switch(Vrab07)
          {
           case 41: Enchanted->Memory[0] = Enchanted->Memory[1]; Enchanted->Save_Memory(Enchanted->Memory[0].Address + "config.ini");
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
       statics int64 Vrab07 = Vrab03 - 372, Vrab08 = Vrab04 - 218; G_SetDisplay(2, Enchanted->Pic_Index_Interface[41], Vrab07, Vrab08);

       if(Enchanted->Runtime1 == 0)
       {
        Enchanted->Select.resize(8); Enchanted->Select_Team.resize(8); Enchanted->Select_Character.resize(8);
        int1 Vrab09 = true;
        for(insize Vrab10 = 0; Vrab10 < 8; ++Vrab10) if(Enchanted->Select[Vrab10] > 0){Vrab09 = false; break;}
        if(Vrab09)
        {
         if(L_Input(Varb0020) == 1){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[0]); Enchanted->Runtime1 = 1;}
         for(insize Vrab10 = 0; Vrab10 < 4; ++Vrab10)
         if(L_Input(Enchanted->Memory[0].P_Input[Vrab10][5]) == 1){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); Enchanted->Runtime3 = 31;}
        }
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
             default: Vrab15 = Enchanted->Engine1->Range(); break;
            }
            if(Vrab11) Enchanted->Select[Vrab10] += 8; if(Vrab14) Enchanted->Select[Vrab10] = 0; if(Vrab17) Enchanted->Select_Character[Vrab10] = 0;
            if(Vrab12) if(Enchanted->Select_Character[Vrab10] == 0){Enchanted->Select_Character[Vrab10] = Vrab15;} else
            {
             uint8 Vrab16 = 0;
             while(Vrab16 != 1)
             {
              Enchanted->Select_Character[Vrab10] -= 1;
              if(Enchanted->Select_Character[Vrab10] == 0){Vrab16 = 1;} else
              {
               switch(Enchanted->Memory[0].Engine)
               {
                case 1: break;
                default: Vrab16 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab10] - 1); break;
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
                default: Vrab16 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab10 ] - 1); break;
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
        insize Vrab10 = 0, Vrab11 = 0;
        while(Vrab10 < 8){if(Enchanted->Select[Vrab10] != 0){if(Enchanted->Select[Vrab10] < 17) break;} else {Vrab11 += 1;} Vrab10 += 1;}
        if(Vrab10 == 8 && Vrab11 != 8) Enchanted->Runtime1 = 1;
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
        insize Vrab14 = 0; while(Vrab14 < 8)
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
              insize Vrab16 = 8; int1 Vrab17 = true;
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
              default: Vrab16 = Enchanted->Engine1->Range(); break;
             }
             if(Vrab11) Enchanted->Select_Character[Vrab14] = 0;
             if(Vrab09) if(Enchanted->Select_Character[Vrab14] == 0){Enchanted->Select_Character[Vrab14] = Vrab16;} else
             {
              uint8 Vrab17 = 0;
              while(Vrab17 != 1)
              {
               Enchanted->Select_Character[Vrab14] -= 1; if(Enchanted->Select_Character[Vrab14] == 0){Vrab17 = 1;} else
               {
                switch(Enchanted->Memory[0].Engine)
                {
                 case 1: break;
                 default: Vrab17 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab14] - 1); break;
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
                 default: Vrab17 = Enchanted->Engine1->Pick(Enchanted->Select_Character[Vrab14] - 1); break;
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
            {insize Vrab17 = 8; while(Vrab17 != 0){Vrab17 -= 1; if(Enchanted->Select[Vrab17] >= 34) if(Vrab17 == Vrab14){Vrab16 = 255ui8; break;} else {break;}}}
            if(Vrab16 == 255ui8) for(insize Vrab17 = 0; Vrab17 < 8; ++Vrab17) if(Vrab17 != Vrab14) if(Enchanted->Select[Vrab17] != 0 && Enchanted->Select[Vrab17] != 34) if(Vrab16 == 255ui8){if(Enchanted->Select_Team[Vrab17] == 0){Vrab16 = 254ui8; break;} Vrab16 = Enchanted->Select_Team[Vrab17];} else {if(Enchanted->Select_Team[Vrab17] != Vrab16){Vrab16 = 254ui8; break;}}
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
        for(insize Vrab10 = 0; Vrab10 < 4; ++Vrab10)
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

         G_SetDisplay(2, Vrab12, Vrab07 + 107 + Vrab21 + Vrab17, Vrab08 + 19 + Vrab13 + Vrab18);
         Enchanted->Print_Text(Vrab07 + 169 + Vrab17 - L_Rounding64(rxint64(Temp01.size()) * 4.5), Vrab08 + 143 + Vrab18, Vrab14, Temp01);
         Enchanted->Print_Text(Vrab07 + 169 + Vrab17 - L_Rounding64(rxint64(Temp02.size()) * 4.5), Vrab08 + 165 + Vrab18, Vrab15, Temp02);
         Enchanted->Print_Text(Vrab07 + 169 + Vrab17 - L_Rounding64(rxint64(Temp03.size()) * 4.5), Vrab08 + 187 + Vrab18, Vrab16, Temp03);
        }
       }

       if(Enchanted->Runtime1 >= 605)
       {
        if(Enchanted->Runtime1 < 896){Enchanted->Runtime1 += 1; statics uint64 Vrab09 = Enchanted->Runtime1; if(Vrab09 >= 785 && Vrab09 < 845){Enchanted->Runtime2 += (Vrab09 - 785) / 12;} if(Vrab09 >= 845 && Vrab09 < 905){Enchanted->Runtime2 += (60 - (Vrab09 - 845)) / 12;}  if(Vrab09 >= 894) Enchanted->Runtime2 += 1;}
        statics int64 Vrab09 = -rint64(Enchanted->Runtime2 % 1000) + 6, Vrab10 = Vrab06 - 174;
        G_SetDisplay(0, 0x0, Vrab09 + 124, Vrab10 + 87, 0, 255ui8, 122, 16); G_SetDisplay(0, 0x0, Vrab09 + 124, Vrab10 + 111, 0, 255ui8, 100, 16);
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
         case 3: {insize Vrab18 = 0; switch(Enchanted->Memory[0].Engine){case 1: break; default: Vrab18 = Enchanted->Engine1->Limit(); break;} if(Enchanted->Select_Background == Vrab18 - 1){Enchanted->Select_Background = 0;} else {Enchanted->Select_Background += 1;}} break;
         case 4: if(Enchanted->Select_Difficult == 3){Enchanted->Select_Difficult = 0;} else {Enchanted->Select_Difficult += 1;} break;
         default: Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); if(Enchanted->Runtime3 == 30) Enchanted->Runtime3 = 31; break;
        }
        Enchanted->Runtime2 = (Enchanted->Runtime2 % 1000) + (Vrab17 * 1000);
        string Temp01;
        switch(Enchanted->Memory[0].Engine)
        {
         case 1: break;
         default: Temp01 = Enchanted->Engine1->Place(Enchanted->Select_Background); break;
        }
        if(Temp01.size() > 14) Temp01.resize(14);
        Enchanted->Print_Text(Vrab09 + 127, Vrab10 + 86, 0, L_Revoke(Temp01, '_', ' '));
        Enchanted->Print_Text(Vrab09 + 127, Vrab10 + 110, 0, Enchanted->Difficult(Enchanted->Select_Difficult));
        G_SetDisplay(2, Enchanted->Pic_Index_Interface[67], Vrab09, Vrab10);
        G_SetDisplay(1, 0xFFFFFF, Vrab09 + 13, Vrab10 + 13 + (24 * Vrab17), 0, 255ui8, 238, 20); if((Enchanted->Tick % 20) / 10 == 0) G_SetDisplay(1, 0xFFFFFF, Vrab09 + 12, Vrab10 + 12 + (24 * Vrab17), 0, 255ui8, 240, 22);
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
        G_SetDisplay(2, Enchanted->Pic_Index_Interface[50], Vrab09, Vrab10);
        insize Vrab11 = 0, Vrab12 = 0;
        for(insize Vrab13 = 0; Vrab13 < 8; ++Vrab13) if(Enchanted->Select[Vrab13] == 0) Vrab11 += 1;
        statics int1 Vrab16 = (Vrab11 == 8); if(Vrab16)
        {
         for(insize Vrab13 = 0; Vrab13 < 6; ++Vrab13)
         {G_SetDisplay(2, Enchanted->Pic_Index_Interface[61 + Vrab13], Vrab09 + 73 + (rint64(Vrab13) * 30), Vrab10 + 53);}
         G_SetDisplay(2, Enchanted->Pic_Index_Interface[52], Vrab09 + 43, Vrab10 + 53);
         G_SetDisplay(2, Enchanted->Pic_Index_Interface[107], Vrab09 + 253, Vrab10 + 53); Vrab12 = 1;
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
         {insize Vrab14 = 0; if(Vrab13 < Vrab12 || Vrab13 > Vrab11) Vrab14 = 8; G_SetDisplay(2, Enchanted->Pic_Index_Interface[59 + Vrab13 - Vrab14], Vrab09 + 43 + (rint64(Vrab13) * 30), Vrab10 + 53);}
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

        G_SetDisplay(1, 0xFFFFFF, Vrab09 + 38 + (rint64(Enchanted->Runtime2) * 30), Vrab10 + 48, 0, 255ui8, 16, 20); if((Enchanted->Tick % 20) / 10 == 0) G_SetDisplay(1, 0xFFFFFF, Vrab09 + 37 + (rint64(Enchanted->Runtime2) * 30), Vrab10 + 47, 0, 255ui8, 18, 22);
       }

       if(Enchanted->Runtime3 < 30)
       {
        G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(30 - Enchanted->Runtime3) / 30) * 255.0)), Vrab05, Vrab06);
        Enchanted->Runtime3 += 1;
       }
       if(Enchanted->Runtime3 > 30)
       {
        G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(Enchanted->Runtime3 - 30) / 30) * 255.0)), Vrab05, Vrab06);
        Enchanted->Runtime3 += 1;
       }
       if(Enchanted->Runtime3 == 60) if(Enchanted->Runtime1 == 900)
       {Enchanted->Reset(10);} else
       {Enchanted->Reset(8, 9); if(Enchanted->Back_Index_Interface.size() > 0) Enchanted->Background1 = Enchanted->Back_Index_Interface[rinsize(L_Random(Enchanted->Back_Index_Interface.size() - 1))]; for(insize Vrab09 = 0; Vrab09 < 8; ++Vrab09) if((Enchanted->Select[Vrab09] >= 25 && Enchanted->Select[Vrab09] <= 33) || Enchanted->Select[Vrab09] == 38) Enchanted->Select_Character[Vrab09] = 0; Enchanted->Select.clear();}
      }
     break;
     case 10: // In-game 
      {
       // Initialization
       if(Enchanted->Runtime1 == 0)
       {
        switch(Enchanted->Memory[0].Engine)
        {
         case 1: break;
         default:
          {
           Varb0004 = Enchanted->Engine1->Frame();
           Enchanted->Engine1->Start(Enchanted->Select_Mode, Enchanted->Select_Background, Enchanted->Select_Difficult, Enchanted->Memory[0].Max_Object);
           for(insize Vrab07 = 0; Vrab07 < 8; ++Vrab07) if(Enchanted->Select[Vrab07] > 0 && Enchanted->Select[Vrab07] <= 33){statics uint8 Vrab08 = (Enchanted->Select[Vrab07] - 1) % 8; Enchanted->Engine1->Set(Vrab08, Enchanted->Select_Character[Vrab07] - 1, Enchanted->Select_Team[Vrab07], Enchanted->Memory[0].P_Name[rinsize(Vrab08)]);}
           for(insize Vrab07 = 0; Vrab07 < 8; ++Vrab07) if(Enchanted->Select[Vrab07] > 34 && Enchanted->Select[Vrab07] <= 38) Enchanted->Engine1->Set(ruint8(Vrab07) + 8, Enchanted->Select_Character[Vrab07] - 1, Enchanted->Select_Team[Vrab07], "Com");
          }
         break;
        }
       }

       // Progressive
       std::vector < HEPTA_LF2_ENCHANTED_PERSPECTIVE_DRAW > Vect01;
       std::vector < HEPTA_LF2_ENCHANTED_INTERACTIVE_DRAW > Vect02;
       switch(Enchanted->Memory[0].Engine)
       {
        case 1: break;
        default:
         {
          for(insize Vrab07 = 0; Vrab07 < 4; ++Vrab07) Enchanted->Engine1->Input(ruint8(Vrab07), L_Input(Enchanted->Memory[0].P_Input[Vrab07][0]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][1]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][2]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][3]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][4]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][5]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][6]) > 0, L_Input(Enchanted->Memory[0].P_Input[Vrab07][7]) > 0);
          Enchanted->Engine1->Run();
          Enchanted->CameraY = 100;
          Vect01 = Enchanted->Engine1->Rear(Enchanted->CameraX, Enchanted->CameraY);
          Vect02 = Enchanted->Engine1->Draw();
         }
        break;
       }
       {
        statics insize Vrab07 = Vect01.size(); insize Vrab08 = 0;
        while(Vrab08 < Vrab07)
        {
         if(Vect01[Vrab08].Type == 3)
         {
          statics insize Vrab09 = Vect01[Vrab08].Pic; statics int64 Vrab10 = Vect01[Vrab08].X, Vrab11 = Vect01[Vrab08].Y;
          Vrab08 += 1; G_SetDisplay(0, Vrab09, Vrab10 - Enchanted->CameraX, Vrab11 - Enchanted->CameraY, 0ui8, 255ui8, Vect01[Vrab08].X, Vect01[Vrab08].Y);
         } else
         {
          uint8 Vrab09 = 2; statics insize Vrab10 = Vect01[Vrab08].Pic;
          if(Vect01[Vrab08].Type == 1){Vrab09 = 6;}
          if(Vect01[Vrab08].Type == 2)
          {
           statics int64 Vrab11 = rint64(Pics0001[Vrab10].Get_Width()) - 1, Vrab12 = rint64(Pics0001[Vrab10].Get_Height()) - 1;
           statics int64 Vrab13 = L_Rounding64(30 * (40.0 / rxint64(Vrab12)));
           if(Vrab12 - Vrab13 >= 0)
           G_SetDisplay(3, Vrab10, Vect01[Vrab08].X - Enchanted->CameraX, Vect01[Vrab08].Y - Enchanted->CameraY + Vrab12 - Vrab13, 0ui8, 255ui8, 1, 1, 42, Vrab12 - 5, Vrab11, Vrab13);
          }
          G_SetDisplay(Vrab09, Vrab10, Vect01[Vrab08].X - Enchanted->CameraX, Vect01[Vrab08].Y - Enchanted->CameraY);
         }
         Vrab08 += 1;
        }
       }
       {
        insize Vrab07 = 0; int64 Vrab08 = 0; int64 Vrab09 = 0;
        switch(Enchanted->Memory[0].Engine)
        {
         case 1: break;
         default: statics auto Back01 = Enchanted->Engine1->Shadow(); Vrab07 = Back01->shadow_Index; Vrab08 = rint64(rxint64(Back01->shadowsize[0]) / 2); Vrab09 = rint64(rxint64(Back01->shadowsize[1]) / 2); break;
        }
        statics insize Vrab10 = Vect02.size(); insize Vrab11 = 0;
        while(Vrab11 < Vrab10)
        {
         G_SetDisplay(2, Vrab07, Vect02[Vrab11].X - Vrab08 - Enchanted->CameraX, Vect02[Vrab11].Z - Vrab09 - Enchanted->CameraY); Vrab11 += 1;
        }
        Vrab11 = 0; while(Vrab11 < Vrab10)
        {
         if(Vect02[Vrab11].Facing)
         {G_SetDisplay(4, Vect02[Vrab11].Pic, Vect02[Vrab11].X - Vect02[Vrab11].CenX - Enchanted->CameraX, Vect02[Vrab11].Z + Vect02[Vrab11].Y - Vect02[Vrab11].CenY - Enchanted->CameraY);} else
         {
          statics insize Vrab12 = Vect02[Vrab11].Pic_M;
          if(Vrab12 != rinsize(-1))
          {G_SetDisplay(5, Vrab12, Vect02[Vrab11].X + Vect02[Vrab11].CenX - Vect02[Vrab11].W - Enchanted->CameraX, Vect02[Vrab11].Z + Vect02[Vrab11].Y - Vect02[Vrab11].CenY - Enchanted->CameraY);} else
          {G_SetDisplay(4, Vect02[Vrab11].Pic, Vect02[Vrab11].X + Vect02[Vrab11].CenX - Vect02[Vrab11].W - Enchanted->CameraX, Vect02[Vrab11].Z + Vect02[Vrab11].Y - Vect02[Vrab11].CenY - Enchanted->CameraY, 1);}
         }
         statics int64 Vrab12 = rint64(Vect02[Vrab11].Name.size()) * 9; statics int64 Vrab13 = Vect02[Vrab11].X - L_Rounding64(rxint64(Vrab12) / 2.0) - Enchanted->CameraX;
         int64 Vrab14 = Vrab13;
         if(Vrab14 + Vrab12 > 800) Vrab14 = 800 - Vrab12;
         if(Vrab14 < 0) Vrab14 = 0;
         Enchanted->Print_Text(Vrab14, Vect02[Vrab11].Z - Enchanted->CameraY + 2, Vect02[Vrab11].Team, Vect02[Vrab11].Name);
         Vrab11 += 1;
        }
       }
       Enchanted->Print_Text(3, 15, 0, Enchanted->Engine1->Debug());

       {
        uint8 Vrab07 = 0; switch(Varb0004){case 0: Vrab07 = 60; break; case 2: Vrab07 = 30; break; case 4: Vrab07 = 15; break; case 8: Vrab07 = 8; break; default: break;}
        Enchanted->Runtime1 += 1; if(Enchanted->Runtime1 == 0xFFFFFFFFFFFFFFFF) Enchanted->Runtime1 = 0xFFFFFFFFFFFEBF;
        if(L_Input(Varb0019) == 1 && Enchanted->Runtime3 == Vrab07){Enchanted->Play_Sound(Enchanted->Sound_Index_Interface[1]); Enchanted->Runtime3 = Vrab07 + 1;}
        if(Enchanted->Runtime3 < Vrab07){G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(8 - Enchanted->Runtime3) / 8) * 255.0)), Vrab05, Vrab06); Enchanted->Runtime3 += 1;}
        if(Enchanted->Runtime3 > Vrab07){G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(L_Rounding((rxint64(Enchanted->Runtime3 - 8) / 8) * 255.0)), Vrab05, Vrab06); Enchanted->Runtime3 += 1;}
        if(Enchanted->Runtime3 == Vrab07 * 2){Enchanted->Reset(9, 605); Varb0004 = 2;}
       }
      }
     break;
     default: break;
    }
   }

   // Finalizer.
    {
     // Mouse Draw & Brightness
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
         G_SetDisplay(1, Vrab08, Vrab04, Vrab05, 0, 255ui8, Vrab06, Vrab07); G_SetDisplay(0, Vrab08, Vrab04 + 1, Vrab05 + 1, 0, Vrab09, Vrab06 - 2, Vrab07 - 2);
        }
       }

       if(L_Input(Enchanted->Memory[0].F12) > 0){if(Enchanted->Darktime1 - (0.0125 * rxint64(Varb0004)) < 0.35){Enchanted->Darktime1 = 0.35;} else {Enchanted->Darktime1 -= 0.0125 * rxint64(Varb0004);}} else
       {if(Enchanted->Darktime1 < 1.0) Enchanted->Darktime1 += 0.0025 * rxint64(Varb0004);}
       {
        statics uint8 Vrab04 = ruint8(L_Rounding(rxint64(Enchanted->Memory[0].Brightness) * Enchanted->Darktime1));
        if(Vrab04 > 100)
        {G_SetDisplay(0, 0xFFFFFF, 0, 0, 0, ruint8(L_Rounding((rxint64(Vrab04 - 100) / 100.0) * 255.0)), Enchanted->Display_W, Enchanted->Display_H);} else
        {G_SetDisplay(0, 0x0, 0, 0, 0, 255 - ruint8(L_Rounding((rxint64(Vrab04) / 100.0) * 255.0)), Enchanted->Display_W, Enchanted->Display_H);}
       }

       if(Input.MOUS_X == Enchanted->Mouse_X && Input.MOUS_Y == Enchanted->Mouse_Y && Input.MOUS_Left == 0){if((++Enchanted->Mouse_Standby) == 255ui8) Enchanted->Mouse_Standby = 254ui8;} else {Enchanted->Mouse_Standby = 0ui8;}
       if(Enchanted->Mouse_Standby < 150ui8){ShowCursor(TRUE); if(Vrab03){G_SetDisplay(2, Enchanted->Pic_Index_Interface[14], Input.MOUS_X - 11ull, Input.MOUS_Y - 11ull);} else {G_SetDisplay(2, Enchanted->Pic_Index_Interface[13], Input.MOUS_X - 3ull, Input.MOUS_Y - 3ull);}} else
       {if(Enchanted->Mouse_Standby == 156ui8){ShowCursor(FALSE); SetCursor(NULL);}}
       Enchanted->Mouse_X = Input.MOUS_X; Enchanted->Mouse_Y = Input.MOUS_Y;
      }
     //-//
     // Info Notification
      {
       insize Vrab03 = Enchanted->Info.size();
       while(Vrab03 != 0)
       {
        Vrab03 -= 1; int1 Vrab04 = false; insize Vrab05 = Enchanted->Info[Vrab03].String.size();
        if(Enchanted->Info[Vrab03].Runtime <= 70) Enchanted->Info[Vrab03].PositionX += rint64(70 - Enchanted->Info[Vrab03].Runtime) / 5;
        {
         statics uint64 Vrab06 = (660 / ruint64(Varb0004)) + 72 + (ruint64(Vrab05) * 8); if(Enchanted->Info[Vrab03].Runtime == Vrab06 && Enchanted->Draw_Pausing) Enchanted->Info[Vrab03].Runtime -= 1; if(Enchanted->Info[Vrab03].Runtime >= Vrab06) Enchanted->Info[Vrab03].PositionX -= rint64(Enchanted->Info[Vrab03].Runtime - Vrab06) / 5;
         Enchanted->Info[Vrab03].Runtime += 1; Vrab04 = Enchanted->Info[Vrab03].Runtime == (Vrab06 + 80);
        }
        
        int64 Vrab06 = Enchanted->Info[Vrab03].PositionY;
        {
         insize Vrab07 = Enchanted->Info[Vrab03].Manager.size();
         while(Vrab07 != 0)
         {
          Vrab07 -= 1;
          Vrab06 += L_Rounding64((rxint64(Enchanted->Info[Vrab03].Manager[Vrab07].Runtime) / 342.0) * rxint64(Enchanted->Info[Vrab03].Manager[Vrab07].Target)); Enchanted->Info[Vrab03].Manager[Vrab07].Runtime += (60 - Enchanted->Info[Vrab03].Manager[Vrab07].Counter) / 5; Enchanted->Info[Vrab03].Manager[Vrab07].Counter += 1;
          if(Enchanted->Info[Vrab03].Manager[Vrab07].Counter == 61){Enchanted->Info[Vrab03].PositionY += Enchanted->Info[Vrab03].Manager[Vrab07].Target; Enchanted->Info[Vrab03].Manager.erase(Enchanted->Info[Vrab03].Manager.begin() + Vrab07);}
         }
        }
        if(Enchanted->Memory[0].Show_FPS){Vrab06 += 30;} else {Vrab06 += 15;}
        {
         insize Vrab07 = 0, Vrab08 = 0, Vrab09 = Vrab05; while(Vrab09 > 40){Vrab09 -= 40; if(Enchanted->Info[Vrab03].String.at((Vrab07 * 40) + Vrab08 + 40) == ' '){Vrab09 -= 1; Vrab08 += 1;} Vrab07 += 1;}
         Vrab09 = Vrab05 - Vrab08;
         if(Vrab09 >= 41){Enchanted->Print_Bar(Enchanted->Info[Vrab03].PositionX - 454, Vrab06, 380, 7 + (16 * rint64((Vrab09 - 1) / 40)));} else
         {Enchanted->Print_Bar(Enchanted->Info[Vrab03].PositionX - 454, Vrab06, 13 + (9 * rint64(Vrab09)), 5);}
        }
        {
         insize Vrab07 = 0, Vrab08 = 0;
         while(Vrab05 > 40){Vrab05 -= 40; statics insize Vrab09 = Vrab07 * 40; string Temp01 = string(Enchanted->Info[Vrab03].String, Vrab09 + Vrab08, 40); if(Enchanted->Info[Vrab03].String.at(Vrab09 + Vrab08 + 40) != ' '){if(Enchanted->Info[Vrab03].String.at(Vrab09 + Vrab08 + 39) != ' ') Temp01.push_back('-');} else {Vrab05 -= 1; Vrab08 += 1;} Enchanted->Print_Text(Enchanted->Info[Vrab03].PositionX - 439, Vrab06 - 6 + (16 * rint64(Vrab07)), 0, Temp01); Vrab07 += 1;}
         Enchanted->Print_Text(Enchanted->Info[Vrab03].PositionX - 439, Vrab06 - 6 + (16 * rint64(Vrab07)), 0, string(Enchanted->Info[Vrab03].String, (Vrab07 * 40) + Vrab08, Vrab05));
        }
        G_SetDisplay(2, Enchanted->Pic_Index_Interface[106], Enchanted->Info[Vrab03].PositionX - 460, Vrab06 - 6);
        if(Vrab04) Enchanted->Info.erase(Enchanted->Info.begin() + Vrab03);
       }
      }
     //-//
     // FPS Draw
      if(Enchanted->Memory[0].Show_FPS) Enchanted->Print_Text(3, 0, 0, std::to_string(Vrab01) + "|" + std::to_string(Vrab02));
      Enchanted->Print_Text(3, 15, 0, Temp69);
     //-//
     // Purging Offside Images
      G_SetDisplay(0, 0x0, -Enchanted->Display_W, -Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, rint64(Enchanted->Display_H) * 3); G_SetDisplay(0, 0x0, Enchanted->Display_W, -Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, rint64(Enchanted->Display_H) * 3); G_SetDisplay(0, 0x0, 0, Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, Enchanted->Display_H); G_SetDisplay(0, 0x0, 0, -Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, Enchanted->Display_H);
     //-//
    }
   //-//
  }
 //-//









  /*
 int0 LF2_Enchanted(uint32 Vrab01, uint64 Vrab99) fastened
   {
   if(Enchanted->Initialization)
   {
    Enchanted->Initialization = false;
    Enchanted->Update_Window(800, 450, "LF2");
    Enchanted->Sound_Index_Interface.clear();
    Enchanted->Pic_Index_Interface.clear();
    {
     statics string Temp01 = "System\\Interface\\Enchanted\\", Temp02 = ".bmp"; Enchanted->Memory[0].Data_Address = "data\\data.txt"; Enchanted->Load_Memory(Temp01 + "config.ini"); Enchanted->Save_Memory(Temp01 + "config.ini");
     Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS0" + Temp02, 16, 16, 15, 15));     // Index : 0
     Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS1" + Temp02, 16, 16, 15, 15));     // Index : 1
     Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS2" + Temp02, 16, 16, 15, 15));     // Index : 2
     Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS3" + Temp02, 16, 16, 15, 15));     // Index : 3
     Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS4" + Temp02, 16, 16, 15, 15));     // Index : 4
     Enchanted->Pic_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS5" + Temp02, 16, 16, 15, 15));     // Index : 5
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 0, 0, 12, 12));        // Index : 6 (Info Bar Top-Left Corner)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 13, 0, 12, 12));       // Index : 7 (Info Bar Top-Right Corner)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 0, 13, 12, 12));       // Index : 8 (Info Bar Bottom-Left Corner)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 13, 13, 12, 12));      // Index : 9 (Info Bar Bottom-Right Corner)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 12, 0, 1, 3));         // Index : 10 (Info Bar Horizontal Corner)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 0, 12, 3, 1));         // Index : 11 (Info Bar Vertical Corner)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR2" + Temp02, 0, 0, 200, 200));     // Index : 12 (Info Bar Area)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "CURSOR" + Temp02));                        // Index : 13
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "CURSOR2" + Temp02));                       // Index : 14

     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 0, 0, 800, 37));           // Index : 15 (Copyright)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 0, 38, 490, 79));          // Index : 16 (Title)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 491, 38, 154, 169));       // Index : 17 (Main Buttons)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 646, 38, 154, 18));        // Index : 18 (Main Buttons - Game Start)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 646, 67, 154, 20));        // Index : 19 (Main Buttons - Network Game)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 646, 99, 154, 19));        // Index : 20 (Main Buttons - Game Settings)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 646, 129, 154, 20));       // Index : 21 (Main Buttons - Control Settings)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 646, 161, 154, 19));       // Index : 22 (Main Buttons - Recording Info)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 646, 191, 154, 16));       // Index : 23 (Main Buttons - Official Fansite)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 0, 118, 151, 26));         // Index : 24 (Ok Button)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 0, 145, 151, 26));         // Index : 25 (Ok Button)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 152, 118, 151, 26));       // Index : 26 (Cancel Button)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 152, 145, 151, 26));       // Index : 27 (Cancel Button)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 801, 0, 704, 353));        // Index : 28 (Control Setting Menu)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 587, 300, 106, 91));       // Index : 29 (Input - Keyboard)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 694, 208, 106, 91));       // Index : 30 (Input - Joy1)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 587, 208, 106, 91));       // Index : 31 (Input - Joy2)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 694, 392, 106, 91));       // Index : 32 (Input - Joy3)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 694, 300, 106, 91));       // Index : 33 (Input - Joy4)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 304, 118, 186, 169));      // Index : 34 (Game Buttons)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 304, 288, 186, 14));       // Index : 35 (Game Buttons - Versus)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 304, 319, 186, 18));       // Index : 36 (Game Buttons - Stage)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 304, 349, 186, 19));       // Index : 37 (Game Buttons - Championship)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 304, 380, 186, 15));       // Index : 38 (Game Buttons - Battle)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 304, 411, 186, 19));       // Index : 39 (Game Buttons - Recording Playback)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 304, 443, 186, 14));       // Index : 40 (Game Buttons - Return)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 1506, 0, 744, 437));       // Index : 41 (Character Selection)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 1264, 354, 120, 66));      // Index : 42 (Character Selection - Press Attack to Join)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 1385, 354, 120, 66));      // Index : 43 (Character Selection - Press Attack to Join2)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 1385, 421, 120, 120));     // Index : 44 (Character Selection - Random)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 535, 208, 51, 58));        // Index : 45 (Character Selection - Counter - 5)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 535, 267, 51, 58));        // Index : 46 (Character Selection - Counter - 4)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 535, 326, 51, 58));        // Index : 47 (Character Selection - Counter - 3)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 590, 392, 51, 58));        // Index : 48 (Character Selection - Counter - 2)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 642, 392, 51, 58));        // Index : 49 (Character Selection - Counter - 1)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 0, 172, 303, 87));         // Index : 50 (Character Selection - Computer Player)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 491, 208, 6, 10));         // Index : 51 (Character Selection - Computer Player - 0)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 498, 208, 6, 10));         // Index : 52 (Character Selection - Computer Player - 1)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 505, 208, 6, 10));         // Index : 53 (Character Selection - Computer Player - 2)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 512, 208, 6, 10));         // Index : 54 (Character Selection - Computer Player - 3)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 519, 208, 6, 10));         // Index : 55 (Character Selection - Computer Player - 4)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 526, 208, 6, 10));         // Index : 56 (Character Selection - Computer Player - 5)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 491, 219, 6, 10));         // Index : 57 (Character Selection - Computer Player - 6)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 498, 219, 6, 10));         // Index : 58 (Character Selection - Computer Player - 7)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 505, 219, 6, 10));         // Index : 59 (Character Selection - Computer Player - 0 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 512, 219, 6, 10));         // Index : 60 (Character Selection - Computer Player - 1 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 519, 219, 6, 10));         // Index : 61 (Character Selection - Computer Player - 2 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 526, 219, 6, 10));         // Index : 62 (Character Selection - Computer Player - 3 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 491, 230, 6, 10));         // Index : 63 (Character Selection - Computer Player - 4 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 498, 230, 6, 10));         // Index : 64 (Character Selection - Computer Player - 5 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 505, 230, 6, 10));         // Index : 65 (Character Selection - Computer Player - 6 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 512, 230, 6, 10));         // Index : 66 (Character Selection - Computer Player - 7 Active)
     Enchanted->Pic_Index_Interface.push_back(G_SetPic(Temp01 + "MENU" + Temp02, 0, 260, 264, 168));        // Index : 67 (Character Selection - Menu)
    }
    {
     statics string Temp01 = "System\\Audio\\Enchanted\\", Temp02 = ".wav";
     Enchanted->Sound_Index_Interface.push_back(G_SetSound(Temp01 + "m_ok" + Temp02));       // Index : 0
     Enchanted->Sound_Index_Interface.push_back(G_SetSound(Temp01 + "m_cancel" + Temp02));   // Index : 1
    }
   }

   {
    statics int64 &Vrab02 = Enchanted->Display_CenX, &Vrab03 = Enchanted->Display_CenY, &Vrab04 = Enchanted->Display_W, &Vrab05 = Enchanted->Display_H;
    switch(Enchanted->Menu)
    {
     case 0: case 1: case 2: case 3: case 4: case 5: case 6:
     {
      G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, Vrab04, Vrab05);
      G_SetDisplay(2, Enchanted->Pic_Index_Interface[15], Vrab02 - 400, Vrab05 - 45);
      G_SetDisplay(2, Enchanted->Pic_Index_Interface[16], Vrab02 - 245, L_Rounding64(rxint64(Vrab03) / 2) - 79);
      G_SetDisplay(2, Enchanted->Pic_Index_Interface[17], Vrab02 - 77, Vrab03 - 85);
      
      switch(Enchanted->Menu)
      {
       case 0:
        {
         if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) - 86, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[18], Vrab02 - 77, Vrab03 - 85); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) - 86, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Reset(0, 0, 55, 1);}}
         //if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) - 55, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[19], Vrab02 - 77, Vrab03 - 56);}
         if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) - 24, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[20], Vrab02 - 77, Vrab03 - 24); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) - 24, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); }}
         if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) + 7, 160, 20)) {G_SetDisplay(2, Enchanted->Pic_Index_Interface[21], Vrab02 - 77, Vrab03 + 6);  if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) + 7, 160, 20) && Input.MOUS_Left_Release == 1) {G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Reset(0, 0, 0, 11); Enchanted->Memory[1] = Enchanted->Memory[0];}}
         if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) + 38, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[22], Vrab02 - 77, Vrab03 + 38); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) + 38, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); }}
         if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) + 69, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[23], Vrab02 - 77, Vrab03 + 68); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) + 69, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); ShellExecuteW(0, 0, L"http://www.lf-empire.de", 0, 0, SW_SHOW);}}
         if(Enchanted->Runtime < 165 && Enchanted->Runtime > 0){Enchanted->Runtime -= 3; G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(Enchanted->Runtime), Vrab04, Vrab05);}
        }
       break;
       case 1:
        {
         G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(Enchanted->Runtime += 3), Vrab04, Vrab05);
         Enchanted->Print_Bar(Vrab04 + 45 - (Enchanted->Runtime2), Vrab03 - 24, 100, 0);
         Enchanted->Runtime2 += (Enchanted->Runtime3 / 3); Enchanted->Runtime3 -= 1;
         if(Enchanted->Runtime3 == 0) Enchanted->Reset(0, 0, 30, 2);
        }
       break;
       case 2:
        {
         statics int64 Vrab06 = L_Rounding64(rxint64(Enchanted->Runtime2) / 2), Vrab07 = L_Rounding64(rxint64(Enchanted->Runtime2) / 4);
         G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, Vrab04, Vrab05);
         Enchanted->Print_Bar(Vrab04 - 450 - Vrab06, Vrab03 - 24 - Vrab07, 100 + (Vrab06 * 2), Vrab06);
         Enchanted->Runtime2 += (Enchanted->Runtime3 / 3); Enchanted->Runtime3 -= 1;
         if(Enchanted->Runtime3 == 0) Enchanted->Reset(0, 0, 0, 3);
        }
       break;
       case 3:
        {
         statics int64 Vrab06 = L_Rounding64(145.0 / 2), Vrab07 = L_Rounding64(145.0 / 4);
         G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, Vrab04, Vrab05);
         Enchanted->Print_Bar(Vrab04 - 450 - Vrab06, Vrab03 - 24 - Vrab07, 100 + (Vrab06 * 2), Vrab06);
         
         Enchanted->Runtime += 1; if(Enchanted->Runtime == 82) Enchanted->Runtime = 2; if(Enchanted->Runtime == 162) Enchanted->Runtime = 82;
         if(Enchanted->Runtime == 1)
         {
          Enchanted->String[0] = Enchanted->String[1] = "<none>";
          Enchanted->File.open(Enchanted->Memory[0].Data_Address);
          if(!Enchanted->File.is_open()){Enchanted->String[2] = "\"" + Enchanted->Memory[0].Data_Address + "\""; Enchanted->String[3] = "Either can't be found or inaccessible."; Enchanted->Reset(0, 0, 32, 4);} else
          {
           string Temp01;
           while(Enchanted->File)
           {
            Enchanted->File >> Temp01; if(!Enchanted->File) break; if(Temp01[0] == '#'){std::getline(Enchanted->File, Temp01); continue;}
            if(Temp01 == "<object>") goto Labl01;
           }
           {Enchanted->String[2] = "\"" + Enchanted->Memory[0].Data_Address + "\""; Enchanted->String[3] = "\"<object>\" is undefined in that file."; Enchanted->Reset(0, 0, 32, 4);}
          }
         } else
         {
          Labl01:
          if(Enchanted->File2.is_open()) goto Labl03; Enchanted->String[1] = "<none>"; 
          if(Enchanted->Runtime <= 80)
          {
           string Temp01;
           while(Enchanted->File)
           {
            Enchanted->File >> Temp01; if(!Enchanted->File) break; if(Temp01[0] == '#'){std::getline(Enchanted->File, Temp01); continue;}
            if(Temp01 == "id:")
            {
             Enchanted->Data_Read = 0ui8;
             Enchanted->File >> Temp01; statics uint32 Vrab08 = L_Numbering(Temp01);
             Enchanted->File >> Temp01; if(Temp01 != "type:"){Enchanted->String[2] = "\"" + Enchanted->Memory[0].Data_Address + "\""; Enchanted->String[3] = "\"id: " + std::to_string(Vrab08) + "\" isn't followed with \"type:\"."; Enchanted->Reset(0, 0, 32, 4); goto Labl02;}
             Enchanted->File >> Temp01; statics uint32 Vrab09 = L_Numbering(Temp01);
             Enchanted->File >> Temp01; if(Temp01 != "file:"){Enchanted->String[2] = "\"" + Enchanted->Memory[0].Data_Address + "\""; Enchanted->String[3] = "\"id: " + std::to_string(Vrab08) + " type: " + std::to_string(Vrab09) + "\" isn't followed with \"file:\"."; Enchanted->Reset(0, 0, 32, 4); goto Labl02;}
             Enchanted->File >> Temp01; 
             {statics string Temp02 = L_Lowercase(string(Temp01, Temp01.size() - 4, 4)); if(Temp02 != ".txt" && Temp02 != ".dat") continue;}
             Enchanted->String[0] = Temp01;
             Enchanted->Runtime2 = Enchanted->Object.size(); Enchanted->Object.resize(rinsize(Enchanted->Runtime2) + 1);
             Enchanted->Object[rinsize(Enchanted->Runtime2)].id = Vrab08;
             Enchanted->Object[rinsize(Enchanted->Runtime2)].type = Vrab09;
             if(Vrab09 == 0 && (Vrab08 < 30 || Vrab08 > 100)) Enchanted->Select_AvailableChar.push_back(rinsize(Enchanted->Runtime2));
             if(Enchanted->File2.is_open()) Enchanted->File2.close(); Enchanted->File2.open(Temp01, std::ios::binary | std::ios::in);
             if(!Enchanted->File2.is_open()){Enchanted->String[2] = "\"" + Temp01 + "\""; Enchanted->String[3] = "Either can't be found or inaccessible."; Enchanted->Reset(0, 0, 32, 4); goto Labl02;} else
             {
              if(L_Lowercase(string(Temp01, Temp01.size() - 4, 4)) == ".dat")
              {
               stream Temp02; Temp02 << Enchanted->File2.rdbuf(); Enchanted->File2.close();
               string Temp03 = Temp02.str(); statics string Temp04 = "SiuHungIsAGoodBearBecauseHeIsVeryGood";
               statics insize Vrab10 = Temp03.size(); insize Vrab11 = 12; statics insize Vrab12 = Temp04.size();
               for(uint32 Vrab13 = 123; Vrab13 < Vrab10; ++Vrab13){Temp03.at(Vrab13) -= Temp04.at(Vrab11); Vrab11 += 1; if(Vrab11 == Vrab12) Vrab11 = 0;}
               std::ofstream File01("data\\temporary.txt", std::ios::binary | std::ios::out); Temp03.erase(0, 123); File01 << Temp03; File01.close();
               Enchanted->File2.open("data\\temporary.txt", std::ios::binary | std::ios::in);
              }
             }
             goto Labl03;
            }
            if(Temp01 == "<object_end>")
            {
             Enchanted->Runtime += 80; Enchanted->String[0] = "<none>"; 
             while(Enchanted->File)
             {
              Enchanted->File >> Temp01; if(!Enchanted->File) break; if(Temp01[0] == '#'){std::getline(Enchanted->File, Temp01); continue;}
              if(Temp01 == "<background>") goto Labl01;
             }
             {Enchanted->String[2] = "\"" + Enchanted->Memory[0].Data_Address + "\""; Enchanted->String[3] = "\"<background>\" is undefined in that file."; Enchanted->Reset(0, 0, 32, 4);}
             goto Labl02;
            }
            if(Temp01 == "<file_editing>") break;
            if(Temp01 == "<background>") break;
           }
           {Enchanted->String[2] = "\"" + Enchanted->Memory[0].Data_Address + "\""; Enchanted->String[3] = "Unexpected end of \"<object>\". It should be closed with \"<object_end>\" syntax."; Enchanted->Reset(0, 0, 32, 4);} goto Labl02;
          } else
          {
           string Temp01;
           while(Enchanted->File)
           {
            Enchanted->File >> Temp01; if(!Enchanted->File) break; if(Temp01[0] == '#'){std::getline(Enchanted->File, Temp01); continue;}
            if(Temp01 == "id:"){Enchanted->File >> Temp01; continue;}
            if(Temp01 == "file:")
            {
             Enchanted->Data_Read = 0ui8;
             Enchanted->File >> Temp01; 
             {statics string Temp02 = L_Lowercase(string(Temp01, Temp01.size() - 4, 4)); if(Temp02 != ".txt" && Temp02 != ".dat") continue;}
             Enchanted->String[0] = Temp01;
             Enchanted->Runtime2 = Enchanted->Background.size(); Enchanted->Background.resize(rinsize(Enchanted->Runtime2) + 1);
             if(Enchanted->File2.is_open()) Enchanted->File2.close(); Enchanted->File2.open(Temp01, std::ios::binary | std::ios::in);
             if(!Enchanted->File2.is_open()){Enchanted->String[2] = "\"" + Temp01 + "\""; Enchanted->String[3] = "Either can't be found or inaccessible."; Enchanted->Reset(0, 0, 32, 4); goto Labl02;} else
             {
              if(L_Lowercase(string(Temp01, Temp01.size() - 4, 4)) == ".dat")
              {
               stream Temp02; Temp02 << Enchanted->File2.rdbuf(); Enchanted->File2.close();
               string Temp03 = Temp02.str(); statics string Temp04 = "SiuHungIsAGoodBearBecauseHeIsVeryGood";
               statics insize Vrab10 = Temp03.size(); insize Vrab11 = 12; statics insize Vrab12 = Temp04.size();
               for(uint32 Vrab13 = 123; Vrab13 < Vrab10; ++Vrab13){Temp03.at(Vrab13) -= Temp04.at(Vrab11); Vrab11 += 1; if(Vrab11 == Vrab12) Vrab11 = 0;}
               std::ofstream File01("data\\temporary.txt", std::ios::binary | std::ios::out); Temp03.erase(0, 123); File01 << Temp03; File01.close();
               Enchanted->File2.open("data\\temporary.txt", std::ios::binary | std::ios::in);
              }
             }
             goto Labl03;
            }
            if(Temp01 == "<background_end>"){Enchanted->Runtime = 0; goto Labl02;}
            if(Temp01 == "<file_editing>") break;
            if(Temp01 == "<object>") break;
           }
           {Enchanted->String[2] = "\"" + Enchanted->Memory[0].Data_Address + "\""; Enchanted->String[3] = "Unexpected end of \"<background>\". It should be closed with \"<background_end>\" syntax."; Enchanted->Reset(0, 0, 32, 4);} goto Labl02;
          }
          Labl03:
          if(Enchanted->Runtime <= 81)
          {
           string Temp01; uint8 Vrab08 = Enchanted->Data_Read; insize Vrab10 = 0, Vrab11 = 0;
           while(Enchanted->File2)
           {
            if(Vrab08 != 254ui8){Enchanted->File2 >> Temp01; if(!Enchanted->File2) break; if(Temp01.at(0) == '#'){std::getline(Enchanted->File2, Temp01); continue;}} else
            {
             if(Enchanted->Runtime3 != ruint64(Enchanted->Object[rinsize(Enchanted->Runtime2)].file.size()))
             {
              if(Enchanted->Runtime3 == 0) Enchanted->Object[rinsize(Enchanted->Runtime2)].file_Index = Spic0001.size();
              Enchanted->String[1] = Enchanted->Object[rinsize(Enchanted->Runtime2)].file[rinsize(Enchanted->Runtime3)].address;
              statics insize Vrab09 = G_SetSprite(Enchanted->String[1], Enchanted->Object[rinsize(Enchanted->Runtime2)].file[rinsize(Enchanted->Runtime3)].row, Enchanted->Object[rinsize(Enchanted->Runtime2)].file[rinsize(Enchanted->Runtime3)].col, Enchanted->Object[rinsize(Enchanted->Runtime2)].file[rinsize(Enchanted->Runtime3)].w, Enchanted->Object[rinsize(Enchanted->Runtime2)].file[rinsize(Enchanted->Runtime3)].h);
              if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4);} else {Enchanted->Data_Read = 254ui8;}
              Enchanted->Runtime3 += 1; goto Labl02;
             } else
             {Vrab08 = 0; continue;}
            }
            switch(Vrab08)
            {
             case 0:
              if(Temp01 == "<bmp_begin>")               {Vrab08 = 1; continue;}
              if(Temp01 == "<weapon_strength_list>")    {Vrab08 = 2; continue;}
              if(Temp01 == "<frame>")                   {Vrab08 = 3; Enchanted->File2 >> Temp01; statics insize Vrab09 = rinsize(L_Numbering(Temp01)); statics insize Vrab12 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame.size(); if(Vrab12 <= Vrab09) Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame.resize(Vrab09 + 1); Vrab10 = Vrab09; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].Exist = true; Enchanted->File2 >> Temp01; std::ofstream OP("sda.txt"); OP << Vrab10; OP.close(); continue;}
             break;
             case 1:
              if(Temp01 == "<bmp_end>")                 {Vrab08 = 254ui8; Enchanted->Runtime3 = 0; continue;}
              if(Temp01 == "name:")                     {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].name; continue;}
              if(Temp01 == "head:")                     {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetSprite(Enchanted->String[1], 1, 1, 120, 121); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4); Vrab08 = 255ui8;} else {Enchanted->Object[rinsize(Enchanted->Runtime2)].head_Index = Vrab09; Enchanted->Data_Read = Vrab08; Vrab08 = 255ui8;} break;}
              if(Temp01 == "small:")                    {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetSprite(Enchanted->String[1], 1, 1, 40, 45); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4); Vrab08 = 255ui8;} else {Enchanted->Object[rinsize(Enchanted->Runtime2)].small_Index = Vrab09; Enchanted->Data_Read = Vrab08; Vrab08 = 255ui8;} break;}
              if(string(Temp01, 0, 5) == "file(")       {Vrab10 = Enchanted->Object[rinsize(Enchanted->Runtime2)].file.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].file.resize(Vrab10 + 1); Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].file[Vrab10].address; continue;}
              if(Temp01 == "w:")                        {Enchanted->File2 >> Temp01; if(Enchanted->Object[rinsize(Enchanted->Runtime2)].file.size() > 0){Enchanted->Object[rinsize(Enchanted->Runtime2)].file[Vrab10].w = ruint32(L_Numbering(Temp01));} continue;}
              if(Temp01 == "h:")                        {Enchanted->File2 >> Temp01; if(Enchanted->Object[rinsize(Enchanted->Runtime2)].file.size() > 0){Enchanted->Object[rinsize(Enchanted->Runtime2)].file[Vrab10].h = ruint32(L_Numbering(Temp01));} continue;}
              if(Temp01 == "row:")                      {Enchanted->File2 >> Temp01; if(Enchanted->Object[rinsize(Enchanted->Runtime2)].file.size() > 0){Enchanted->Object[rinsize(Enchanted->Runtime2)].file[Vrab10].row = ruint32(L_Numbering(Temp01));} continue;}
              if(Temp01 == "col:")                      {Enchanted->File2 >> Temp01; if(Enchanted->Object[rinsize(Enchanted->Runtime2)].file.size() > 0){Enchanted->Object[rinsize(Enchanted->Runtime2)].file[Vrab10].col = ruint32(L_Numbering(Temp01));} continue;}
              if(Temp01 == "walking_frame_rate")        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].walking_frame_rate = ruint32(L_Numbering(Temp01)); continue;}
              if(Temp01 == "running_frame_rate")        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].running_frame_rate = ruint32(L_Numbering(Temp01)); continue;}
              if(Temp01 == "walking_speed")             {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].walking_speed; continue;}
              if(Temp01 == "walking_speedz")            {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].walking_speedz; continue;}
              if(Temp01 == "running_speed")             {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].running_speed; continue;}
              if(Temp01 == "running_speedz")            {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].running_speedz; continue;}
              if(Temp01 == "heavy_walking_speed")       {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].heavy_walking_speed; continue;}
              if(Temp01 == "heavy_walking_speedz")      {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].heavy_walking_speedz; continue;}
              if(Temp01 == "heavy_running_speed")       {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].heavy_running_speed; continue;}
              if(Temp01 == "heavy_running_speedz")      {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].heavy_running_speedz; continue;}
              if(Temp01 == "jump_height")               {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].jump_height; continue;}
              if(Temp01 == "jump_distance")             {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].jump_distance; continue;}
              if(Temp01 == "jump_distancez")            {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].jump_distancez; continue;}
              if(Temp01 == "dash_height")               {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].dash_height; continue;}
              if(Temp01 == "dash_distance")             {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].dash_distance; continue;}
              if(Temp01 == "dash_distancez")            {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].dash_distancez; continue;}
              if(Temp01 == "rowing_height")             {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].rowing_height; continue;}
              if(Temp01 == "rowing_distance")           {Enchanted->File2 >> Enchanted->Object[rinsize(Enchanted->Runtime2)].rowing_distance; continue;}
              if(Temp01 == "weapon_hp:")                {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].weapon_hp = L_Numbering(Temp01); continue;}
              if(Temp01 == "weapon_drop_hurt:")         {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].weapon_drop_hurt = L_Numbering(Temp01); continue;}
              if(Temp01 == "weapon_hit_sound:")         {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetSound(Enchanted->String[1]); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4); Vrab08 = 255ui8; break;} else {Enchanted->Object[rinsize(Enchanted->Runtime2)].weapon_hit_sound_Index = Vrab09; continue;}}
              if(Temp01 == "weapon_drop_sound:")        {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetSound(Enchanted->String[1]); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4); Vrab08 = 255ui8; break;} else {Enchanted->Object[rinsize(Enchanted->Runtime2)].weapon_drop_sound_Index = Vrab09; continue;}}
              if(Temp01 == "weapon_broken_sound:")      {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetSound(Enchanted->String[1]); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4); Vrab08 = 255ui8; break;} else {Enchanted->Object[rinsize(Enchanted->Runtime2)].weapon_broken_sound_Index = Vrab09; continue;}}
             break;
             case 2:
              if(Temp01 == "<weapon_strength_list_end>"){Vrab08 = 0; continue;}
              if(Temp01 == "entry:")                    {Enchanted->File2 >> Temp01; Vrab10 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength.resize(Vrab10 + 1); continue;}
              if(Temp01 == "zwidth:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].zwidth = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvx:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].dvx = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvy:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].dvy = L_Numbering(Temp01); continue;}
              if(Temp01 == "fall:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].fall = L_Numbering(Temp01); continue;}
              if(Temp01 == "arest:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].arest = L_Numbering(Temp01); continue;}
              if(Temp01 == "vrest:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].vrest = L_Numbering(Temp01); continue;}
              if(Temp01 == "respond:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].respond = L_Numbering(Temp01); continue;}
              if(Temp01 == "effect:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].effect = L_Numbering(Temp01); continue;}
              if(Temp01 == "bdefend:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].bdefend = L_Numbering(Temp01); continue;}
              if(Temp01 == "injury:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Strength[Vrab10].injury = L_Numbering(Temp01); continue;}
             break;
             case 3:
              if(Temp01 == "<frame_end>")               {Vrab08 = 0; continue;}
              if(Temp01 == "pic:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].pic = L_Numbering(Temp01); continue;}
              if(Temp01 == "state:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].state = L_Numbering(Temp01); continue;}
              if(Temp01 == "wait:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wait = L_Numbering(Temp01); continue;}
              if(Temp01 == "next:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].next = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvx:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].dvx = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvy:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].dvy = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvz:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].dvz = L_Numbering(Temp01); continue;}
              if(Temp01 == "centerx:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].centerx = L_Numbering(Temp01); continue;}
              if(Temp01 == "centery:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].centery = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_a:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_a = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_d:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_d = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_j:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_j = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_Fa:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_Fa = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_Fj:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_Fj = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_Da:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_Da = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_Dj:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_Dj = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_Ua:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_Ua = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_Uj:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_Uj = L_Numbering(Temp01); continue;}
              if(Temp01 == "hit_ja:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].hit_ja = L_Numbering(Temp01); continue;}
              if(Temp01 == "mp:")                       {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].mp = L_Numbering(Temp01); continue;}
              if(Temp01 == "sound:")                    {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetSound(Enchanted->String[1]); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4); Vrab08 = 255ui8; break;} else {Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].sound_index = Vrab09; continue;}}
              if(Temp01 == "bpoint:")                   {Vrab08 = 4; Vrab11 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bpoint.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bpoint.resize(Vrab11 + 1); continue;}
              if(Temp01 == "cpoint:")                   {Vrab08 = 5; Vrab11 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint.resize(Vrab11 + 1); continue;}
              if(Temp01 == "wpoint:")                   {Vrab08 = 6; Vrab11 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint.resize(Vrab11 + 1); continue;}
              if(Temp01 == "opoint:")                   {Vrab08 = 7; Vrab11 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint.resize(Vrab11 + 1); continue;}
              if(Temp01 == "itr:")                      {Vrab08 = 8; Vrab11 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr.resize(Vrab11 + 1); continue;}
              if(Temp01 == "bdy:")                      {Vrab08 = 9; Vrab11 = Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bdy.size(); Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bdy.resize(Vrab11 + 1); continue;}
             break;
             case 4:
              if(Temp01 == "bpoint_end:")               {Vrab08 = 3; continue;}
              if(Temp01 == "x:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bpoint[Vrab11].x = L_Numbering(Temp01); continue;}
              if(Temp01 == "y:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bpoint[Vrab11].y = L_Numbering(Temp01); continue;}
             break;
             case 5:
              if(Temp01 == "cpoint_end:")               {Vrab08 = 3; continue;}
              if(Temp01 == "kind:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].kind = L_Numbering(Temp01); continue;}
              if(Temp01 == "x:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].x = L_Numbering(Temp01); continue;}
              if(Temp01 == "y:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].y = L_Numbering(Temp01); continue;}
              if(Temp01 == "vaction:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].vaction = L_Numbering(Temp01); continue;}
              if(Temp01 == "aaction:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].aaction = L_Numbering(Temp01); continue;}
              if(Temp01 == "daction:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].daction = L_Numbering(Temp01); continue;}
              if(Temp01 == "jaction:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].jaction = L_Numbering(Temp01); continue;}
              if(Temp01 == "taction:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].taction = L_Numbering(Temp01); continue;}
              if(Temp01 == "throwvx:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].throwvx = L_Numbering(Temp01); continue;}
              if(Temp01 == "throwvy:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].throwvy = L_Numbering(Temp01); continue;}
              if(Temp01 == "throwvz:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].throwvz = L_Numbering(Temp01); continue;}
              if(Temp01 == "throwinjury:")              {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].throwinjury = L_Numbering(Temp01); continue;}
              if(Temp01 == "dircontrol:")               {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].dircontrol = L_Numbering(Temp01); continue;}
              if(Temp01 == "hurtable:")                 {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].hurtable = L_Numbering(Temp01); continue;}
              if(Temp01 == "decrease:")                 {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].decrease = L_Numbering(Temp01); continue;}
              if(Temp01 == "cover:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].cover = L_Numbering(Temp01); continue;}
              if(Temp01 == "injury:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].injury = L_Numbering(Temp01); continue;}
              if(Temp01 == "fronthurtact:")             {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].fronthurtact = L_Numbering(Temp01); continue;}
              if(Temp01 == "backhurtact:")              {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].cpoint[Vrab11].backhurtact = L_Numbering(Temp01); continue;}
             break;
             case 6:
              if(Temp01 == "wpoint_end:")               {Vrab08 = 3; continue;}
              if(Temp01 == "kind:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].kind = L_Numbering(Temp01); continue;}
              if(Temp01 == "x:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].x = L_Numbering(Temp01); continue;}
              if(Temp01 == "y:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].y = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvx:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].dvx = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvy:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].dvy = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvz:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].dvz = L_Numbering(Temp01); continue;}
              if(Temp01 == "weaponact:")                {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].weaponact = L_Numbering(Temp01); continue;}
              if(Temp01 == "attacking:")                {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].attacking = L_Numbering(Temp01); continue;}
              if(Temp01 == "cover:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].wpoint[Vrab11].cover = L_Numbering(Temp01); continue;}
             break;
             case 7:
              if(Temp01 == "opoint_end:")               {Vrab08 = 3; continue;}
              if(Temp01 == "kind:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].kind = L_Numbering(Temp01); continue;}
              if(Temp01 == "x:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].x = L_Numbering(Temp01); continue;}
              if(Temp01 == "y:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].y = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvx:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].dvx = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvy:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].dvy = L_Numbering(Temp01); continue;}
              if(Temp01 == "oid:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].oid = L_Numbering(Temp01); continue;}
              if(Temp01 == "action:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].action = L_Numbering(Temp01); continue;}
              if(Temp01 == "facing:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].opoint[Vrab11].facing = L_Numbering(Temp01); continue;}
             break;
             case 8: case 10: case 11:
              if(Temp01 == "itr_end:")                  {Vrab08 = 3; continue;}
              if(Temp01 == "kind:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].kind = L_Numbering(Temp01); continue;}
              if(Temp01 == "x:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].x = L_Numbering(Temp01); continue;}
              if(Temp01 == "y:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].y = L_Numbering(Temp01); continue;}
              if(Temp01 == "w:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].w = ruint32(L_Numbering(Temp01)); continue;}
              if(Temp01 == "h:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].h = ruint32(L_Numbering(Temp01)); continue;}
              if(Temp01 == "zwidth:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].zwidth = ruint32(L_Numbering(Temp01)); continue;}
              if(Temp01 == "dvx:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].dvx = L_Numbering(Temp01); continue;}
              if(Temp01 == "dvy:")                      {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].dvy = L_Numbering(Temp01); continue;}
              if(Temp01 == "fall:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].fall = L_Numbering(Temp01); continue;}
              if(Temp01 == "arest:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].arest = L_Numbering(Temp01); continue;}
              if(Temp01 == "vrest:")                    {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].vrest = L_Numbering(Temp01); continue;}
              if(Temp01 == "respond:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].respond = L_Numbering(Temp01); continue;}
              if(Temp01 == "effect:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].effect = L_Numbering(Temp01); continue;}
              if(Temp01 == "bdefend:")                  {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].bdefend = L_Numbering(Temp01); continue;}
              if(Temp01 == "injury:")                   {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].injury = L_Numbering(Temp01); continue;}
              if(Temp01 == "catchingact:")              {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].catchingact[0] = L_Numbering(Temp01); Vrab08 = 10; continue;}
              if(Temp01 == "caughtact:")                {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].caughtact[0] = L_Numbering(Temp01); Vrab08 = 11; continue;}
              if(Vrab08 == 10){Vrab08 = 8; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].catchingact[1] = L_Numbering(Temp01); continue;}
              if(Vrab08 == 11){Vrab08 = 8; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].itr[Vrab11].caughtact[1] = L_Numbering(Temp01); continue;}
             break;
             case 9:
              if(Temp01 == "bdy_end:")                  {Vrab08 = 3; continue;}
              if(Temp01 == "kind:")                     {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bdy[Vrab11].kind = L_Numbering(Temp01); continue;}
              if(Temp01 == "x:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bdy[Vrab11].x = L_Numbering(Temp01); continue;}
              if(Temp01 == "y:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bdy[Vrab11].y = L_Numbering(Temp01); continue;}
              if(Temp01 == "w:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bdy[Vrab11].w = ruint32(L_Numbering(Temp01)); continue;}
              if(Temp01 == "h:")                        {Enchanted->File2 >> Temp01; Enchanted->Object[rinsize(Enchanted->Runtime2)].Frame[Vrab10].bdy[Vrab11].h = ruint32(L_Numbering(Temp01)); continue;}
             break;
             default: break;
            }
            if(Vrab08 == 255ui8) goto Labl02;
           }
           if(Enchanted->File2.is_open()) Enchanted->File2.close(); goto Labl01;
          } else
          {
           string Temp01; uint8 Vrab08 = Enchanted->Data_Read; insize Vrab10 = 0;
           while(Enchanted->File2)
           {
            Enchanted->File2 >> Temp01; if(!Enchanted->File2) break; if(Temp01.at(0) == '#'){std::getline(Enchanted->File2, Temp01); continue;}
            switch(Vrab08)
            {
             case 0: case 1: case 2: case 3: case 4: case 5:
              if(Temp01 == "name:")       {Enchanted->File2 >> Enchanted->Background[rinsize(Enchanted->Runtime2)].name; continue;}
              if(Temp01 == "width:")      {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].width = L_Numbering(Temp01); continue;}
              if(Temp01 == "zboundary:")  {Enchanted->File2 >> Temp01; Vrab08 = 1; Enchanted->Background[rinsize(Enchanted->Runtime2)].zboundary[0] = L_Numbering(Temp01); continue;}
              if(Temp01 == "perspective:"){Enchanted->File2 >> Temp01; Vrab08 = 2; Enchanted->Background[rinsize(Enchanted->Runtime2)].perspective[0] = L_Numbering(Temp01); continue;}
              if(Temp01 == "shadow:")     {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetPic(Enchanted->String[1]); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4);} else {Enchanted->Background[rinsize(Enchanted->Runtime2)].shadow_Index = Vrab09; Enchanted->Data_Read = 3;} Vrab08 = 255ui8; break;}
              if(Temp01 == "layer:")      {Enchanted->File2 >> Enchanted->String[1]; statics insize Vrab09 = G_SetPic(Enchanted->String[1]); if(Vrab09 == rinsize(-1)){Enchanted->Not_Found(); Enchanted->Reset(0, 0, 32, 4);} else {statics insize Vrab11 = Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer.size(); Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer.resize(Vrab11 + 1); Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab11].image_Index = Vrab09; Enchanted->Data_Read = 6;} Vrab08 = 255ui8; break;}
              if(Vrab08 == 1){Vrab08 = 0; Enchanted->Background[rinsize(Enchanted->Runtime2)].zboundary[1] = L_Numbering(Temp01); continue;}
              if(Vrab08 == 2){Vrab08 = 0; Enchanted->Background[rinsize(Enchanted->Runtime2)].perspective[1] = L_Numbering(Temp01); continue;}
              if(Vrab08 == 3){Vrab08 = 4; continue;}
              if(Vrab08 == 4){Vrab08 = 5; Enchanted->Background[rinsize(Enchanted->Runtime2)].shadowsize[0] = L_Numbering(Temp01); continue;}
              if(Vrab08 == 5){Vrab08 = 0; Enchanted->Background[rinsize(Enchanted->Runtime2)].shadowsize[1] = L_Numbering(Temp01); continue;}
             break;
             case 6: Vrab10 = Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer.size() - 1; Vrab08 = 7;
             case 7:
              if(Temp01 == "layer_end")    {Vrab08 = 0; continue;}
              if(Temp01 == "transparency:"){Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].transparency = L_Numbering(Temp01); continue;}
              if(Temp01 == "width:")       {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].width = L_Numbering(Temp01); continue;}
              if(Temp01 == "height:")      {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].height = L_Numbering(Temp01); continue;}
              if(Temp01 == "x:")           {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].x = L_Numbering(Temp01); continue;}
              if(Temp01 == "y:")           {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].y = L_Numbering(Temp01); continue;}
              if(Temp01 == "cc:")          {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].cc = L_Numbering(Temp01); continue;}
              if(Temp01 == "c1:")          {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].c1 = L_Numbering(Temp01); continue;}
              if(Temp01 == "c2:")          {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].c2 = L_Numbering(Temp01); continue;}
              if(Temp01 == "rect:")        
              {
               Enchanted->File2 >> Temp01; statics uint32 Vrab09 = ruint32(L_Numbering(Temp01));
               statics uint32 Vrab11 = (8 * ((Vrab09 / 2048) % 32)) + ((4 * ((Vrab09 / 32) % 64) + 7) / 256) + 5;
               statics uint32 Vrab12 = (((4 * ((Vrab09 / 32) % 64)) + 7) % 256) - 4;
               statics uint32 Vrab13 = (8 * (Vrab09 % 32)) + 9;
               Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].rect32 = Vrab13 + (Vrab12 << 8) + (Vrab11 << 16);
               continue;
              }
              if(Temp01 == "rect32:")      {Enchanted->File2 >> Temp01; Enchanted->Background[rinsize(Enchanted->Runtime2)].Layer[Vrab10].rect32 = L_Numbering(Temp01); continue;}
             break;
             default: break;
            }
            if(Vrab08 == 255ui8) goto Labl02;
           }
           if(Enchanted->File2.is_open()) Enchanted->File2.close(); goto Labl01;
          }
         }
         Labl02:
         if(Enchanted->Menu == 3 && Enchanted->Runtime == 0){Enchanted->Reset(0, 0, 0, 7); Enchanted->Data_Read = 165;}

         string Temp01 = "Loading data(s)"; statics uint64 Vrab08 = Enchanted->Runtime % 80; if(Vrab08 / 20 > 0) Temp01.push_back('.'); if(Vrab08 / 40 > 0) Temp01.push_back('.'); if(Vrab08 / 60 > 0) Temp01.push_back('.');
         string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
         string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}

         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 - 24 - Vrab07, 0, Temp01);
         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 + 14 - Vrab07, 0, Temp02);
         Enchanted->Print_Text(Vrab04 - 448 - Vrab06 + 243 - (rint64(Temp03.size()) * 9), Vrab03 + 33 - Vrab07, 0, Temp03);
        }
       break;
       case 4:
        {
         statics int64 Vrab06 = L_Rounding64(145.0 / 2), Vrab07 = L_Rounding64(145.0 / 4);
         G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, Vrab04, Vrab05);
         Enchanted->Print_Bar(Vrab04 - 450 - Vrab06, Vrab03 - 24 - Vrab07, 100 + (Vrab06 * 2), Vrab06);
         string Temp01 = "Loading data(s)...";
         string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
         string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 - 24 - Vrab07, 2, Temp01);
         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 + 14 - Vrab07, 0, Temp02);
         Enchanted->Print_Text(Vrab04 - 448 - Vrab06 + 243 - (rint64(Temp03.size()) * 9), Vrab03 + 33 - Vrab07, 0, Temp03);

         int32 Vrab08 = 15;
         if(Enchanted->String[2].size() > rinsize(Vrab08)) Vrab08 = Enchanted->String[2].size();
         if(Enchanted->String[3].size() > rinsize(Vrab08)) Vrab08 = Enchanted->String[3].size();
         statics int32 Vrab09 = L_Rounding(rxint64(rint64(Vrab08) - 1) * 4.5) - 1;

         Enchanted->Print_Bar(Vrab02 - Vrab09 - 8, Vrab05 - Enchanted->Runtime2, (ruint64(Vrab09) * 2) + 14, Vrab06 + 6);
         Enchanted->Print_Text(Vrab02 - L_Rounding64(rxint64(rint64(Enchanted->String[2].size())) * 4.5), Vrab05 - Enchanted->Runtime2, 0, Enchanted->String[2]);
         Enchanted->Print_Text(Vrab02 - L_Rounding64(rxint64(rint64(Enchanted->String[3].size())) * 4.5), Vrab05 - Enchanted->Runtime2 + 19, 0, Enchanted->String[3]);
         G_SetDisplay(2, Enchanted->Pic_Index_Interface[24], Vrab02 - 76, Vrab05 - Enchanted->Runtime2 + 51);
         
         Enchanted->Runtime2 += (Enchanted->Runtime3 / 3); Enchanted->Runtime3 -= 1;
         if(Enchanted->Runtime3 == 0) Enchanted->Reset(0, 0, 0, 5);
        }
       break;
       case 5:
        {
         if(Enchanted->Runtime == 0)
         {
          Enchanted->Runtime += 1;
          if(Enchanted->File.is_open()) Enchanted->File.close();
          if(Enchanted->File2.is_open()) Enchanted->File2.close();
          G_ClearSprite(6);
          G_ClearPic(68);
          //G_CleanUnreferencedImage();
          Enchanted->Object.clear();
          Enchanted->Background.clear();
          Enchanted->Select_AvailableChar.clear();
         }
         statics int64 Vrab06 = L_Rounding64(145.0 / 2), Vrab07 = L_Rounding64(145.0 / 4);
         G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, Vrab04, Vrab05);
         Enchanted->Print_Bar(Vrab04 - 450 - Vrab06, Vrab03 - 24 - Vrab07, 100 + (Vrab06 * 2), Vrab06);
         string Temp01 = "Loading data(s)...";
         string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
         string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 - 24 - Vrab07, 2, Temp01);
         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 + 14 - Vrab07, 0, Temp02);
         Enchanted->Print_Text(Vrab04 - 448 - Vrab06 + 243 - (rint64(Temp03.size()) * 9), Vrab03 + 33 - Vrab07, 0, Temp03);
         int32 Vrab08 = 15;
         if(Enchanted->String[2].size() > rinsize(Vrab08)) Vrab08 = Enchanted->String[2].size();
         if(Enchanted->String[3].size() > rinsize(Vrab08)) Vrab08 = Enchanted->String[3].size();
         statics int32 Vrab09 = L_Rounding(rxint64(rint64(Vrab08) - 1) * 4.5) - 1;
         Enchanted->Print_Bar(Vrab02 - Vrab09 - 8, Vrab05 - 165, (ruint64(Vrab09) * 2) + 14, Vrab06 + 6);
         Enchanted->Print_Text(Vrab02 - L_Rounding64(rxint64(rint64(Enchanted->String[2].size())) * 4.5), Vrab05 - 165, 0, Enchanted->String[2]);
         Enchanted->Print_Text(Vrab02 - L_Rounding64(rxint64(rint64(Enchanted->String[3].size())) * 4.5), Vrab05 - 146, 0, Enchanted->String[3]);
  
         if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 76, rint32(Vrab05) - 114, 151, 26)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[25], Vrab02 - 76, Vrab05 - 114); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 76, rint32(Vrab05) - 114, 151, 26) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Reset(165, 0, 1, 6);}} else
         {G_SetDisplay(2, Enchanted->Pic_Index_Interface[24], Vrab02 - 76, Vrab05 - 114);}
        }
       break;
       case 6:
        {
         statics int64 Vrab06 = L_Rounding64(145.0 / 2), Vrab07 = L_Rounding64(145.0 / 4);
         G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(Enchanted->Runtime -= 3), Vrab04, Vrab05);
         Enchanted->Print_Bar(Vrab04 - 450 - Vrab06, Vrab03 - 24 - Vrab07 - (Enchanted->Runtime2), 100 + (Vrab06 * 2), Vrab06);
         string Temp01 = "Loading data(s)...";
         string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
         string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 - 24 - Vrab07 - (Enchanted->Runtime2), 2, Temp01);
         Enchanted->Print_Text(Vrab04 - 447 - Vrab06, Vrab03 + 14 - Vrab07 - (Enchanted->Runtime2), 0, Temp02);
         Enchanted->Print_Text(Vrab04 - 448 - Vrab06 + 243 - (rint64(Temp03.size()) * 9), Vrab03 + 33 - Vrab07 - (Enchanted->Runtime2), 0, Temp03);
         int32 Vrab08 = 15;
         if(Enchanted->String[2].size() > rinsize(Vrab08)) Vrab08 = Enchanted->String[2].size();
         if(Enchanted->String[3].size() > rinsize(Vrab08)) Vrab08 = Enchanted->String[3].size();
         statics int32 Vrab09 = L_Rounding(rxint64(rint64(Vrab08) - 1) * 4.5) - 1;
         Enchanted->Print_Bar(Vrab02 - Vrab09 - 8, Vrab05 - 165 + (Enchanted->Runtime2), (ruint64(Vrab09) * 2) + 14, Vrab06 + 6);
         Enchanted->Print_Text(Vrab02 - L_Rounding64(rxint64(rint64(Enchanted->String[2].size())) * 4.5), Vrab05 - 165 + (Enchanted->Runtime2), 0, Enchanted->String[2]);
         Enchanted->Print_Text(Vrab02 - L_Rounding64(rxint64(rint64(Enchanted->String[3].size())) * 4.5), Vrab05 - 146 + (Enchanted->Runtime2), 0, Enchanted->String[3]);
         G_SetDisplay(2, Enchanted->Pic_Index_Interface[24], Vrab02 - 76, Vrab05 - 114 + (Enchanted->Runtime2));

         Enchanted->Runtime2 += (Enchanted->Runtime3 / 2); Enchanted->Runtime3 += 1;
         if(Enchanted->Runtime3 == 40) Enchanted->Reset(Enchanted->Runtime);
        }
       break;
       default: break;
      }
     }
     break;
     case 7:
      {
       G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, Vrab04, Vrab05);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[15], Vrab02 - 400, Vrab05 - 45);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[16], Vrab02 - 245, L_Rounding64(rxint64(Vrab03) / 2) - 79);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[17], Vrab02 - 77 - (Enchanted->Runtime2), Vrab03 - 85);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[34], Vrab02 + 663 - (Enchanted->Runtime), Vrab03 - 85);

       statics int64 Vrab06 = L_Rounding64(145.0 / 2), Vrab07 = L_Rounding64(145.0 / 4);
       G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(Enchanted->Data_Read -= 3), Vrab04, Vrab05);
       Enchanted->Print_Bar(Vrab04 - 450 - Vrab06 - (Enchanted->Runtime2), Vrab03 - 24 - Vrab07, 100 + (Vrab06 * 2), Vrab06); 
       string Temp01 = "Loading data(s) - Completed"; 
       string Temp02 = Enchanted->String[0]; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
       string Temp03 = Enchanted->String[1]; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
       Enchanted->Print_Text(Vrab04 - 447 - Vrab06 - (Enchanted->Runtime2), Vrab03 - 24 - Vrab07, 1, Temp01);
       Enchanted->Print_Text(Vrab04 - 447 - Vrab06 - (Enchanted->Runtime2), Vrab03 + 14 - Vrab07, 0, Temp02);
       Enchanted->Print_Text(Vrab04 - 448 - Vrab06 + 243 - (rint64(Temp03.size()) * 9) - (Enchanted->Runtime2), Vrab03 + 33 - Vrab07, 0, Temp03);

       Enchanted->Runtime += ((55 - Enchanted->Runtime3) / 2);
       Enchanted->Runtime2 += (Enchanted->Runtime3 / 2); Enchanted->Runtime3 += 1;
       if(Enchanted->Runtime3 == 55) Enchanted->Reset(0, 0, 0, 8);
      }
     break;
     case 8: case 9:
      {
       G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, Vrab04, Vrab05);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[15], Vrab02 - 400, Vrab05 - 45);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[16], Vrab02 - 245, L_Rounding64(rxint64(Vrab03) / 2) - 79);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[34], Vrab02 - 93, Vrab03 - 85);
       
       switch(Enchanted->Menu)
       {
        case 8:
         {
          if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) - 86, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[35], Vrab02 - 93, Vrab03 - 85); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) - 86, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Reset(0, 0, 0, 9);}}
          if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) - 55, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[36], Vrab02 - 93, Vrab03 - 54); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) - 55, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013);}}
          if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) - 24, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[37], Vrab02 - 93, Vrab03 - 24); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) - 24, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013);}}
          if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) + 7, 160, 20)) {G_SetDisplay(2, Enchanted->Pic_Index_Interface[38], Vrab02 - 93, Vrab03 + 7);  if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) + 7, 160, 20) && Input.MOUS_Left_Release == 1) {G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013);}}
          if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) + 38, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[39], Vrab02 - 93, Vrab03 + 38); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) + 38, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013);}}
          if(L_Within(Input.MOUS_X, Input.MOUS_Y, rint32(Vrab02) - 80, rint32(Vrab03) + 69, 160, 20)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[40], Vrab02 - 93, Vrab03 + 70); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, rint32(Vrab02) - 80, rint32(Vrab03) + 69, 160, 20) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013);}}
          switch(Enchanted->Runtime)
          {
           case 0:
           default: break;
          }
         }
        break;
        case 9:
         {
          if(Enchanted->Runtime == 255) Enchanted->Runtime2 = 1;
          if(Enchanted->Runtime2 == 0)
          {
           Enchanted->Runtime += 17;
           if(Enchanted->Runtime3 == 1 || Enchanted->Runtime3 == 2)
           {
            G_SetDisplay(0, 0x0, 0, 0, 0, 255ui8, Vrab04, Vrab05);
            G_SetDisplay(2, Enchanted->Pic_Index_Interface[41], Vrab02 - 372, Vrab03 - 218);
            if(Enchanted->Runtime3 == 2){G_SetDisplay(2, Enchanted->Pic_Index_Interface[67], 0, 0); G_SetDisplay(0, 0x0, 124, 87, 0, 255ui8, 122, 16); G_SetDisplay(0, 0x0, 124, 111, 0, 255ui8, 100, 16);}
           }
          } else 
          {
           Enchanted->Runtime -= 17;
           if(Enchanted->Runtime3 == 0)
           {
            G_SetDisplay(0, 0x0, 0, 0, 0, 255ui8, Vrab04, Vrab05);
            G_SetDisplay(2, Enchanted->Pic_Index_Interface[41], Vrab02 - 372, Vrab03 - 218);
           }
           if(Enchanted->Runtime3 == 2)
           {
            G_SetDisplay(0, 0x0, 0, 0, 0, 255ui8, Vrab04, Vrab05);
            Enchanted->Reset(0, 0, 0, 13);
           }
           if(Enchanted->Runtime3 == 3)
           {
            G_SetDisplay(0, 0x0, 0, 0, 0, 255ui8, Vrab04, Vrab05);
            G_SetDisplay(2, Enchanted->Pic_Index_Interface[41], Vrab02 - 372, Vrab03 - 218);
            G_SetDisplay(2, Enchanted->Pic_Index_Interface[67], 0, 0);
            G_SetDisplay(0, 0x0, 124, 87, 0, 255ui8, 122, 16);
            G_SetDisplay(0, 0x0, 124, 111, 0, 255ui8, 100, 16);
           }
          }
          G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(Enchanted->Runtime), Vrab04, Vrab05);
          if(Enchanted->Runtime2 == 1 && Enchanted->Runtime == 0) if(Enchanted->Runtime3 == 3){Enchanted->Reset(0, 0, 11, 10);} else {if(Enchanted->Runtime3 == 0){Enchanted->Reset(0, 0, 0, 10); for(insize Vrab06 = 0; Vrab06 < 8; ++Vrab06){if((Enchanted->Select_Active[Vrab06] > 12 && Enchanted->Select_Active[Vrab06] <= 16) || Enchanted->Select_Active[Vrab06] == 20) Enchanted->Select_Index[Vrab06] = 0; Enchanted->Select_Active[Vrab06] = 0;}} else {if(Enchanted->Runtime3 == 2){Enchanted->Reset(0, 0, 0, 13);} else {Enchanted->Reset(0, 0, 0, 8);}}}
         }
        break;
        default: break;
       }
      }
     break;
     case 10:
      {
       Enchanted->Runtime += 1; if(Enchanted->Runtime == 20) Enchanted->Runtime = 0;
       G_SetDisplay(0, 0x0, 0, 0, 0, 255ui8, Vrab04, Vrab05);
       statics int64 Vrab06 = Vrab02 - 372, Vrab07 = Vrab03 - 248; G_SetDisplay(2, Enchanted->Pic_Index_Interface[41], Vrab06, Vrab07 + 30);
       int64 Vrab08 = 0;

       if(Enchanted->Runtime3 == 0)
       {
        while(Vrab08 != 4){if(Enchanted->Select_Active[Vrab08] != 0) break; Vrab08 += 1;}
        if(Vrab08 == 4)
        {for(Vrab08 = 0; Vrab08 < 4; ++Vrab08) if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][5]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013); Enchanted->Reset(0, 0, 99, 9);}} else
        {Vrab08 = 0; while(Vrab08 != 4){statics uint8 Vrab09 = Enchanted->Select_Active[Vrab08]; if(Vrab09 >= 1 && Vrab09 <= 8) break; Vrab08 += 1;} if(Vrab08 == 4) Enchanted->Runtime3 = 1;}
       }

       if(Enchanted->Runtime3 == 1)
       {
        for(Vrab08 = 0; Vrab08 < 4; ++Vrab08) if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][5]) == 1) Enchanted->Runtime2 += 60;
        Enchanted->Runtime2 += 1; if(Enchanted->Runtime2 > 299) Enchanted->Reset(0, 0, 2, 10);
       }

       if(Enchanted->Runtime3 >= 3 && Enchanted->Runtime3 < 10)
       {
        while(Enchanted->Select_Active[Enchanted->Runtime2] != 0 && Enchanted->Select_Active[Enchanted->Runtime2] <= 16) Enchanted->Runtime2 += 1;
        if(Enchanted->Select_Active[Enchanted->Runtime2] == 0) Enchanted->Select_Active[Enchanted->Runtime2] = 17;
        for(uint8 Vrab13 = 0; Vrab13 < 4; ++Vrab13)
        {
         if(Enchanted->Select_Active[Enchanted->Runtime2] == 17)
         {
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][0]) == 1) Enchanted->Select_Index[Enchanted->Runtime2] = 0;
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][2]) == 1) Enchanted->Select_Index[Enchanted->Runtime2] -= 1;
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][3]) == 1) Enchanted->Select_Index[Enchanted->Runtime2] += 1;
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Select_Active[Enchanted->Runtime2] = 18;}
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][5]) == 1)
          {
           G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013);
           Enchanted->Select_Active[Enchanted->Runtime2] = 0; Enchanted->Runtime2 -= 1;
           if(Enchanted->Runtime2 == ruint64(-1)){Enchanted->Runtime3 = 2; Enchanted->Runtime2 = 0; break;}
           while(Enchanted->Select_Active[Enchanted->Runtime2] != 0 && Enchanted->Select_Active[Enchanted->Runtime2] <= 16){Enchanted->Runtime2 -= 1; if(Enchanted->Runtime2 == ruint64(-1)){Enchanted->Runtime3 = 2; Enchanted->Runtime2 = 0; break;}}
           if(Enchanted->Runtime3 != 2) Enchanted->Select_Active[Enchanted->Runtime2] = 18;
           break;
          }
         } else
         {
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][2]) == 1) Enchanted->Select_Team[Enchanted->Runtime2] -= 1;
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][3]) == 1) Enchanted->Select_Team[Enchanted->Runtime2] += 1;
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Select_Active[Enchanted->Runtime2] = 19; Enchanted->Runtime2 += 1; Enchanted->Runtime3 += 1; if(Enchanted->Runtime3 == 10) Enchanted->Runtime2 = 0;}
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][5]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013); Enchanted->Select_Active[Enchanted->Runtime2] = 17;}
         }
         if(Enchanted->Select_Index[Enchanted->Runtime2] == rinsize(-1)) Enchanted->Select_Index[Enchanted->Runtime2] = Enchanted->Select_AvailableChar.size();
         if(Enchanted->Select_Index[Enchanted->Runtime2] == Enchanted->Select_AvailableChar.size() + 1) Enchanted->Select_Index[Enchanted->Runtime2] = 0;
         if(Enchanted->Select_Team[Enchanted->Runtime2] == 255ui8) Enchanted->Select_Team[Enchanted->Runtime2] = 5;
         if(Enchanted->Select_Team[Enchanted->Runtime2] == 6) Enchanted->Select_Team[Enchanted->Runtime2] = 0;
        }
       }

       for(Vrab08 = 0; Vrab08 < 4; ++Vrab08)
       for(int64 Vrab09 = 0; Vrab09 < 2; ++Vrab09)
       {
        statics insize Vrab10 = rinsize((4 * Vrab09) + Vrab08);
        if(Vrab09 == 0)
        if(Enchanted->Runtime3 <= 1)
        if(Enchanted->Select_Active[Vrab08] == 0)
        {
         if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Select_Active[Vrab08] = ruint8(Vrab08) + 1; Enchanted->Runtime3 = 0; Enchanted->Runtime2 = 0;}
        } else
        {
         if(Enchanted->Runtime3 == 0)
         if(Enchanted->Select_Active[Vrab08] > 4)
         {
          if(Enchanted->Select_Active[Vrab08] > 8)
          {
           if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][5]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013); Enchanted->Select_Active[Vrab08] -= 4;}
          } else
          {
           if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Select_Active[Vrab08] += 4;}
           if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][5]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013); Enchanted->Select_Active[Vrab08] -= 4;}
           if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][2]) == 1) Enchanted->Select_Team[Vrab08] -= 1;
           if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][3]) == 1) Enchanted->Select_Team[Vrab08] += 1;
          }
         } else
         {
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Select_Active[Vrab08] += 4;}
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][5]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013); Enchanted->Select_Active[Vrab08] = 0;}
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][0]) == 1) Enchanted->Select_Index[Vrab08] = 0;
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][2]) == 1) Enchanted->Select_Index[Vrab08] -= 1;
          if(L_Input(Enchanted->Memory[0].P_Input[Vrab08][3]) == 1) Enchanted->Select_Index[Vrab08] += 1;
         }
        }

        if(Enchanted->Select_Active[Vrab10] == 0)
        {
         if(Enchanted->Runtime3 == 0)
         {
          G_SetDisplay(2, Enchanted->Pic_Index_Interface[42 + rinsize((Enchanted->Runtime % 10) / 5)], Vrab06 + 107 + (Vrab08 * 153), Vrab07 + 76 + (Vrab09 * 212));
          Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(5.0 * 4.5), Vrab07 + 173 + (Vrab09 * 212), ruint8(Enchanted->Runtime / 10), "Join?");
         } else
         {
          if(Enchanted->Runtime3 == 1)
          {
           G_SetDisplay(2, Enchanted->Pic_Index_Interface[45 + rinsize(Enchanted->Runtime2 / 60)], Vrab06 + 142 + (Vrab08 * 153), Vrab07 + 81 + (Vrab09 * 212));
          }
         }
        } else
        {
         if(Enchanted->Select_Index[Vrab10] == rinsize(-1)) Enchanted->Select_Index[Vrab10] = Enchanted->Select_AvailableChar.size();
         if(Enchanted->Select_Index[Vrab10] == Enchanted->Select_AvailableChar.size() + 1) Enchanted->Select_Index[Vrab10] = 0;

         if(Enchanted->Select_Index[Vrab10] == 0)
         {G_SetDisplay(2, Enchanted->Pic_Index_Interface[44], Vrab06 + 107 + (Vrab08 * 153), Vrab07 + 49 + (Vrab09 * 212));} else
         {
          G_SetDisplay(4, Enchanted->Object[Enchanted->Select_AvailableChar[Enchanted->Select_Index[Vrab10] - 1]].head_Index, Vrab06 + 107 + (Vrab08 * 153), Vrab07 + 49 + (Vrab09 * 212));
         }

         if(Enchanted->Select_Active[Vrab10] <= 16)
         {
          Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(rxint64(Enchanted->Memory[0].P_Name[(Enchanted->Select_Active[Vrab10] - 1) % 4].size()) * 4.5), Vrab07 + 173 + (Vrab09 * 212), 0, Enchanted->Memory[0].P_Name[(Enchanted->Select_Active[Vrab10] - 1) % 4]);
         } else
         {
          Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(8.0 * 4.5), Vrab07 + 173 + (Vrab09 * 212), 0, "Computer");
         }

         if(Enchanted->Select_Active[Vrab10] <= 4 || Enchanted->Select_Active[Vrab10] == 17)
         {
          if(Enchanted->Select_Index[Vrab10] == 0){Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(6.0 * 4.5), Vrab07 + 195 + (Vrab09 * 212), ruint8(Enchanted->Runtime / 10), "Random");} else
          {Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(rxint64(Enchanted->Object[Enchanted->Select_AvailableChar[Enchanted->Select_Index[Vrab10] - 1]].name.size()) * 4.5), Vrab07 + 195 + (Vrab09 * 212), ruint8(Enchanted->Runtime / 10), Enchanted->Object[Enchanted->Select_AvailableChar[Enchanted->Select_Index[Vrab10] - 1]].name);}
         } else
         {
          if(Enchanted->Select_Index[Vrab10] == 0){Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(6.0 * 4.5), Vrab07 + 195 + (Vrab09 * 212), 0, "Random");} else
          {Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(rxint64(Enchanted->Object[Enchanted->Select_AvailableChar[Enchanted->Select_Index[Vrab10] - 1]].name.size()) * 4.5), Vrab07 + 195 + (Vrab09 * 212), 0, Enchanted->Object[Enchanted->Select_AvailableChar[Enchanted->Select_Index[Vrab10] - 1]].name);}
          
          if(Enchanted->Select_Team[Vrab10] == 255ui8) Enchanted->Select_Team[Vrab10] = 5;
          if(Enchanted->Select_Team[Vrab10] == 6) Enchanted->Select_Team[Vrab10] = 0;
          if((Enchanted->Select_Active[Vrab10] > 4 && Enchanted->Select_Active[Vrab10] <= 8) || Enchanted->Select_Active[Vrab10] == 18)
          {
           if(Enchanted->Select_Team[Vrab10] == 0){Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(11.0 * 4.5), Vrab07 + 217 + (Vrab09 * 212), ruint8(Enchanted->Runtime / 10), "Independent");} else
           {Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(6.0 * 4.5), Vrab07 + 217 + (Vrab09 * 212), ruint8(Enchanted->Runtime / 10), "Team " + std::to_string(Enchanted->Select_Team[Vrab10]));}
          } else
          {
           if(Enchanted->Select_Team[Vrab10] == 0){Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(11.0 * 4.5), Vrab07 + 217 + (Vrab09 * 212), 0, "Independent");} else
           {Enchanted->Print_Text(Vrab06 + 169 + (Vrab08 * 153) - L_Rounding64(6.0 * 4.5), Vrab07 + 217 + (Vrab09 * 212), 0, "Team " + std::to_string(Enchanted->Select_Team[Vrab10]));}
          }
         }
        }
       }

       if(Enchanted->Runtime3 == 2)
       {
        statics int64 Vrab09 = Vrab02 - 152, Vrab10 = Vrab03 - 44;
        G_SetDisplay(2, Enchanted->Pic_Index_Interface[50], Vrab09, Vrab10);
        uint8 Vrab11 = 0; uint8 Vrab12 = 0;
        for(uint8 Vrab13 = 0; Vrab13 < 8; ++Vrab13){if(Enchanted->Select_Active[Vrab13] != 0){Vrab11 += 1; if(Vrab12 == 0){Vrab12 = Enchanted->Select_Team[Vrab13];} else {if(Vrab12 != Enchanted->Select_Team[Vrab13]) Vrab12 = 6;}}}
        int1 Vect01[8]{};
        if((Vrab12 == 0 && Vrab11 > 1) || Vrab12 == 6)
        {Vect01[0] = true;} else {if(Enchanted->Runtime2 == 0) Enchanted->Runtime2 = 1;}
        for(uint8 Vrab13 = 1; Vrab13 < 9 - Vrab11; ++Vrab13) Vect01[Vrab13] = true;
        for(uint8 Vrab13 = 0; Vrab13 < 4; ++Vrab13)
        {
         if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][2]) == 1){Enchanted->Runtime2 -= 1; if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Runtime2 = 7; while(!Vect01[Enchanted->Runtime2]){Enchanted->Runtime2 -= 1; if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Runtime2 = 7;}}
         if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][3]) == 1){Enchanted->Runtime2 += 1; if(Enchanted->Runtime2 == 8) Enchanted->Runtime2 = 0; while(!Vect01[Enchanted->Runtime2]){Enchanted->Runtime2 += 1; if(Enchanted->Runtime2 == 8) Enchanted->Runtime2 = 0;}}
         if(L_Input(Enchanted->Memory[0].P_Input[Vrab13][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Runtime3 = 10 - Enchanted->Runtime2; Enchanted->Runtime2 = 0;}
        }
        if(Enchanted->Runtime3 == 2)
        for(int64 Vrab13 = 0; Vrab13 < 8; ++Vrab13)
        {
         if(Vect01[Vrab13]){G_SetDisplay(2, Enchanted->Pic_Index_Interface[59 + rinsize(Vrab13)], Vrab09 + 43 + (Vrab13 * 30), Vrab10 + 53);} else {G_SetDisplay(2, Enchanted->Pic_Index_Interface[51 + rinsize(Vrab13)], Vrab09 + 43 + (Vrab13 * 30), Vrab10 + 53);}
         if(Enchanted->Runtime2 == ruint64(Vrab13)){G_SetDisplay(1, 0xFFFFFF, Vrab09 + 38 + (Vrab13 * 30), Vrab10 + 48, 0, 255ui8, 16, 20); if((Enchanted->Runtime % 10) / 5 == 0) G_SetDisplay(1, 0xFFFFFF, Vrab09 + 37 + (Vrab13 * 30), Vrab10 + 47, 0, 255ui8, 18, 22);}
        }
       }

       if(Enchanted->Runtime3 == 11)
       {
        G_SetDisplay(2, Enchanted->Pic_Index_Interface[67], 0, 0);
        G_SetDisplay(0, 0x0, 124, 87, 0, 255ui8, 122, 16);
        G_SetDisplay(0, 0x0, 124, 111, 0, 255ui8, 100, 16);
        for(uint8 Vrab09 = 0; Vrab09 < 4; ++Vrab09)
        {
         if(L_Input(Enchanted->Memory[0].P_Input[Vrab09][0]) == 1){Enchanted->Runtime2 -= 1; if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Runtime2 = 5;}
         if(L_Input(Enchanted->Memory[0].P_Input[Vrab09][1]) == 1){Enchanted->Runtime2 += 1; if(Enchanted->Runtime2 == 6) Enchanted->Runtime2 = 0;}
         if(Enchanted->Runtime2 == 0) if(L_Input(Enchanted->Memory[0].P_Input[Vrab09][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Reset(0, 0, 100, 9); break;}
         if(Enchanted->Runtime2 == 1) if(L_Input(Enchanted->Memory[0].P_Input[Vrab09][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); for(insize Vrab10 = 0; Vrab10 < 8; ++Vrab10){if((Enchanted->Select_Active[Vrab10] > 12 && Enchanted->Select_Active[Vrab10] <= 16) || Enchanted->Select_Active[Vrab10] == 20) Enchanted->Select_Index[Vrab10] = 0; Enchanted->Select_Active[Vrab10] = 0;} Enchanted->Runtime2 = 0; Enchanted->Runtime3 = 0; break;}
         if(Enchanted->Runtime2 == 2) if(L_Input(Enchanted->Memory[0].P_Input[Vrab09][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); for(uint8 Vrab10 = 0; Vrab10 < 8; ++Vrab10){int1 Vrab11 = false; if(Enchanted->Select_Active[Vrab10] > 12 && Enchanted->Select_Active[Vrab10] <= 16){Enchanted->Select_Active[Vrab10] -= 4; Vrab11 = true;} if(Enchanted->Select_Active[Vrab10] == 20){Enchanted->Select_Active[Vrab10] = 19; Vrab11 = true;} if(Vrab11) Enchanted->Select_Index[Vrab10] = 0;} Enchanted->Runtime3 = 10; break;}
         if(Enchanted->Runtime2 == 5) if(L_Input(Enchanted->Memory[0].P_Input[Vrab09][4]) == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013); Enchanted->Reset(0, 0, 99, 9); break;}
        }
        if(Enchanted->Menu == 10 && Enchanted->Runtime3 == 11)
        {
         G_SetDisplay(1, 0xFFFFFF, 13, 13 + (24 * Enchanted->Runtime2), 0, 255ui8, 238, 20);
         if((Enchanted->Runtime % 10) / 5 == 0) G_SetDisplay(1, 0xFFFFFF, 12, 12 + (24 * Enchanted->Runtime2), 0, 255ui8, 240, 22);
        }
       }
       if(Enchanted->Runtime3 == 10)
       {
        Enchanted->Runtime3 += 1; statics insize Vrab09 = Enchanted->Select_AvailableChar.size();
        std::vector < insize > Vect01;
        for(insize Vrab10 = 0; Vrab10 < Vrab09; ++Vrab10){statics insize Vrab11 = Enchanted->Object[Enchanted->Select_AvailableChar[Vrab10]].id; if(Vrab11 >= 1 && Vrab11 <= 29) Vect01.push_back(Vrab10);}
        for(int64 Vrab10 = 0; Vrab10 < 8; ++Vrab10) if(Enchanted->Select_Active[Vrab10] != 0) if(Enchanted->Select_Index[Vrab10] != 0){insize Vrab11 = Vect01.size(); while(Vrab11 != 0){Vrab11 -= 1; if(Vect01[Vrab11] == Enchanted->Select_Index[Vrab10] - 1){Vect01.erase(Vect01.begin() + Vrab11); break;}}}
        for(int64 Vrab10 = 0; Vrab10 < 8; ++Vrab10)
        if(Enchanted->Select_Active[Vrab10] != 0)
        if(Enchanted->Select_Index[Vrab10] == 0)
        {
         if(Enchanted->Select_Active[Vrab10] > 8 && Enchanted->Select_Active[Vrab10] <= 12) Enchanted->Select_Active[Vrab10] += 4;
         if(Enchanted->Select_Active[Vrab10] == 19) Enchanted->Select_Active[Vrab10] = 20;
         if(Vect01.size() > 0)
         {
          statics insize Vrab11 = rinsize(L_Random(Vect01.size() - 1));
          Enchanted->Select_Index[Vrab10] = Vect01[Vrab11] + 1;
          Vect01.erase(Vect01.begin() + Vrab11);
         } else
         {
          Enchanted->Select_Index[Vrab10] = rinsize(L_Random(Enchanted->Select_AvailableChar.size() - 1)) + 1;
         } 
        }
       }

       if(Enchanted->Runtime3 >= 99) Enchanted->Runtime3 -= 98;
      }
     break;
     case 11:
      {
       G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, Vrab04, Vrab05);
       if(Enchanted->Runtime3 < 6){Enchanted->Runtime += Enchanted->Runtime2;} else {Enchanted->Runtime -= Enchanted->Runtime2;} if(Enchanted->Runtime3 % 6 == 0){Enchanted->Runtime2 += 1;} if(Enchanted->Runtime3 % 6 == 3){Enchanted->Runtime2 -= 1;} if(Enchanted->Runtime2 == 14){Enchanted->Runtime3 += 3; Enchanted->Runtime2 -= 1;} if(Enchanted->Runtime3 % 3 != 2){Enchanted->Runtime3 += 1;} else {Enchanted->Runtime3 -= 2;}
       
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[15], Vrab02 - 400, Vrab05 - 45 - (Enchanted->Runtime));
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[16], Vrab02 - 245, L_Rounding64(rxint64(Vrab03) / 2) - 79 - (Enchanted->Runtime));
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[17], Vrab02 - 77, Vrab03 - 85 - (Enchanted->Runtime));
       
       statics int64 Vrab06 = Vrab02 - 352, Vrab07 = Vrab03 + 370 - (Enchanted->Runtime);
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[28], Vrab06, Vrab07);
       for(uint64 Vrab08 = 0; Vrab08 < 4; ++Vrab08)
       {
        if(Enchanted->Memory[1].P_Name[Vrab08] == "") Enchanted->Memory[1].P_Name[Vrab08] = "P" + std::to_string(Vrab08 + 1);
        Enchanted->Print_Text(Vrab06 + 203 + (139 * Vrab08) - L_Rounding64(rxint64(Enchanted->Memory[1].P_Name[Vrab08].size()) * 4.5), Vrab07 + 35, 0, Enchanted->Memory[1].P_Name[Vrab08]);
        G_SetDisplay(2, Enchanted->Pic_Index_Interface[29 + Enchanted->Memory[1].P_Con[Vrab08]], Vrab06 + 148 + (139 * Vrab08), Vrab07 + 61);
        uint64 Vrab09 = 0; if(Enchanted->Memory[1].P_Con[Vrab08] != 0) Vrab09 = 7;
        for(uint64 Vrab10 = Vrab09; Vrab10 < Vrab09 + 7; ++Vrab10)
        {
         statics string Temp01 = Enchanted->Input_Name(Enchanted->Memory[1].P_Input[Vrab08][Vrab10]);
         Enchanted->Print_Text(Vrab06 + 203 + (139 * Vrab08) - L_Rounding(rxint64(Temp01.size()) * 4.5), Vrab07 + 159 + (22 * (Vrab10 - Vrab09)), 0, Temp01);
        }
       }
       
       if(Enchanted->Runtime3 < 6)
       {if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset(0, 0, 0, 12);} else
       {if(Enchanted->Runtime2 == ruint64(-1)) Enchanted->Reset();}
      }
     break;
     case 12:
      {
       G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, Vrab04, Vrab05);
       statics int64 Vrab06 = Vrab02 - 352, Vrab07 = Vrab03 - 177;
       G_SetDisplay(2, Enchanted->Pic_Index_Interface[28], Vrab06, Vrab07);
       {statics int32 Vrab08 = rint32(Vrab06) + 362, Vrab09 = rint32(Vrab07) + 320; if(L_Within(Input.MOUS_X, Input.MOUS_Y, Vrab08, Vrab09, 151, 26)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[25], Vrab08, Vrab09); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, Vrab08, Vrab09, 151, 26) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[0], Varb0012, Varb0013); Enchanted->Reset(547, 0, 6, 11); Enchanted->Memory[0] = Enchanted->Memory[1]; Enchanted->Save_Memory("System\\Interface\\Enchanted\\config.ini");}}}
       {statics int32 Vrab08 = rint32(Vrab06) + 534, Vrab09 = rint32(Vrab07) + 320; if(L_Within(Input.MOUS_X, Input.MOUS_Y, Vrab08, Vrab09, 151, 26)){G_SetDisplay(2, Enchanted->Pic_Index_Interface[27], Vrab08, Vrab09); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, Vrab08, Vrab09, 151, 26) && Input.MOUS_Left_Release == 1){G_SetSoundplay(Enchanted->Sound_Index_Interface[1], Varb0012, Varb0013); Enchanted->Reset(547, 0, 6, 11);}}}

       for(uint64 Vrab08 = 0; Vrab08 < 4; ++Vrab08)
       {
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, Vrab06 + 148 + (139 * Vrab08), Vrab07 + 35, 106, 19))
        if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, Vrab06 + 148 + (139 * Vrab08), Vrab07 + 35, 106, 19) && Input.MOUS_Left_Release == 1)
        {statics auto Vrab09 = ruint64(Vrab08) + 1; if(Enchanted->Runtime2 == Vrab09){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = Vrab09;}}
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, Vrab06 + 148 + (139 * Vrab08), Vrab07 + 61, 106, 91))
        if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, Vrab06 + 148 + (139 * Vrab08), Vrab07 + 61, 106, 91) && Input.MOUS_Left_Release == 1)
        {Enchanted->Memory[1].P_Con[Vrab08] += 1; Enchanted->Memory[1].P_Con[Vrab08] %= 5;}
        
        if(Enchanted->Runtime2 == ruint64(Vrab08) + 1)
        {
         L_Typing(Enchanted->Memory[1].P_Name[Vrab08]); if(Enchanted->Memory[1].P_Name[Vrab08].size() > 100) Enchanted->Memory[1].P_Name[Vrab08].resize(100); if(Input.CONS_ENTER == 1) Enchanted->Runtime2 = 0;
         Enchanted->Print_Text(Vrab06 + 203 + (139 * Vrab08) - L_Rounding64(rxint64(Enchanted->Memory[1].P_Name[Vrab08].size()) * 4.5), Vrab07 + 35, 1, Enchanted->Memory[1].P_Name[Vrab08]);
        } else
        {
         if(Enchanted->Memory[1].P_Name[Vrab08] == "") Enchanted->Memory[1].P_Name[Vrab08] = "P" + std::to_string(Vrab08 + 1);
         Enchanted->Print_Text(Vrab06 + 203 + (139 * Vrab08) - L_Rounding64(rxint64(Enchanted->Memory[1].P_Name[Vrab08].size()) * 4.5), Vrab07 + 35, 0, Enchanted->Memory[1].P_Name[Vrab08]);
        }
        G_SetDisplay(2, Enchanted->Pic_Index_Interface[29 + Enchanted->Memory[1].P_Con[Vrab08]], Vrab06 + 148 + (139 * Vrab08), Vrab07 + 61);
        uint64 Vrab09 = 0; if(Enchanted->Memory[1].P_Con[Vrab08] != 0) Vrab09 = 7;
        for(uint64 Vrab10 = Vrab09; Vrab10 < Vrab09 + 7; ++Vrab10)
        {
         if(L_Within(Input.MOUS_X, Input.MOUS_Y, Vrab06 + 148 + (139 * Vrab08), Vrab07 + 159 + (22 * (Vrab10 - Vrab09)), 106, 19))
         if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left,Vrab06 + 148 + (139 * Vrab08), Vrab07 + 159 + (22 * (Vrab10 - Vrab09)), 106, 19) && Input.MOUS_Left_Release == 1)
         {statics auto Vrab11 = (ruint64(Vrab08) * 7) + 5 + (Vrab10 - Vrab09); if(Enchanted->Runtime2 == Vrab11){Enchanted->Runtime2 = 0;} else {Enchanted->Runtime2 = Vrab11;}}
         
         statics string Temp01 = Enchanted->Input_Name(Enchanted->Memory[1].P_Input[Vrab08][Vrab10]);
         if(Enchanted->Runtime2 == (ruint64(Vrab08) * 7) + 5 + (Vrab10 - Vrab09))
         {
          statics uint8 Vrab11 = L_Press(); if(Vrab11 != 255ui8){Enchanted->Memory[1].P_Input[Vrab08][Vrab10] = Vrab11; Enchanted->Runtime2 = 0;}
          Enchanted->Print_Text(Vrab06 + 203 + (139 * Vrab08) - L_Rounding(rxint64(Temp01.size()) * 4.5), Vrab07 + 159 + (22 * (Vrab10 - Vrab09)), 1, Temp01);
         } else {Enchanted->Print_Text(Vrab06 + 203 + (139 * Vrab08) - L_Rounding(rxint64(Temp01.size()) * 4.5), Vrab07 + 159 + (22 * (Vrab10 - Vrab09)), 0, Temp01);}
        }
       }
      }
     break;
     case 13:
      {
       Enchanted->Runtime += 1; if(Enchanted->Runtime == 0xFFFFFFFFFFFFFFFF){Enchanted->Reset(255, 0, 3, 9); Enchanted->Game->Background += 1; Enchanted->Game->Object.clear(); Enchanted->Game.reset(); break;} if(Enchanted->Runtime == 0xFFFFFFFFFFFFFFF0) Enchanted->Runtime = 0xFFFFFFFFFFFFFFEF;
       
       // Initialization
        if(Enchanted->Runtime == 1)
        {
         Enchanted->Game = std::make_unique < HEPTA_LF2_ENCHANTED_GAME > ();
         Enchanted->Game->Background -= 0;
         Enchanted->Game->Independent_Team = 5;
         for(uint8 Vrab06 = 0; Vrab06 < 8; ++Vrab06)
         {
          if(Enchanted->Select_Active[Vrab06] == 0) continue;
          statics insize Vrab07 = Enchanted->Game->Object.size(); Enchanted->Game->Object.resize(Vrab07 + 1);
          Enchanted->Game->Object[Vrab07].Index = Enchanted->Select_AvailableChar[Enchanted->Select_Index[Vrab06] - 1];
          if(Enchanted->Select_Active[Vrab06] < 8 || Enchanted->Select_Active[Vrab06] > 16){Enchanted->Game->Object[Vrab07].Player = 9; Enchanted->Game->Object[Vrab07].Name = "Com";} else
          {
           if(Enchanted->Select_Active[Vrab06] > 12){Enchanted->Game->Object[Vrab07].Player = Enchanted->Select_Active[Vrab06] - 13;} else
           {Enchanted->Game->Object[Vrab07].Player = Enchanted->Select_Active[Vrab06] - 9;}
           Enchanted->Game->Object[Vrab07].Name = Enchanted->Memory[0].P_Name[Enchanted->Game->Object[Vrab07].Player];
          }
          if(Enchanted->Select_Team[Vrab06] == 0)
          {Enchanted->Game->Object[Vrab07].Actual_Team = (Enchanted->Game->Object[Vrab07].Team = (Enchanted->Game->Independent_Team += 1));} else {Enchanted->Game->Object[Vrab07].Actual_Team = (Enchanted->Game->Object[Vrab07].Team = Enchanted->Select_Team[Vrab06]);}
         }
        }
       //-//

       // Mechanism
        Enchanted->Camera_Y = 550 - rint64(Enchanted->Display_H);
        if(Enchanted->Game->Background < Enchanted->Background.size())
        {
         Enchanted->Resist_Offside();
         Enchanted->Inputs();

        
         Enchanted->Draw_Background();
         Enchanted->Draw_Character();
        
         Enchanted->Print_Text(3, 30, 0, std::to_string(Enchanted->Game->Object.size()));
        }
       //-//

       if(Enchanted->Runtime <= 15) G_SetDisplay(0, 0x0, 0, 0, 0, 255ui8 - (ruint8(Enchanted->Runtime) * 17), Vrab04, Vrab05);
       if(Enchanted->Runtime > 0xFFFFFFFFFFFFFFF0) G_SetDisplay(0, 0x0, 0, 0, 0, (ruint8(Enchanted->Runtime - 0xFFFFFFFFFFFFFFF0) * 17), Vrab04, Vrab05);
       if(Input.CONS_F4 == 1) Enchanted->Runtime = 0xFFFFFFFFFFFFFFF0;
      }
     break;
     default: break;
    }
   }

   G_SetDisplay(0, 0x0, -Enchanted->Display_W, -Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, rint64(Enchanted->Display_H) * 3); G_SetDisplay(0, 0x0, Enchanted->Display_W, -Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, rint64(Enchanted->Display_H) * 3);
   G_SetDisplay(0, 0x0, 0, Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, Enchanted->Display_H); G_SetDisplay(0, 0x0, 0, -Enchanted->Display_H, 0, 255ui8, Enchanted->Display_W, Enchanted->Display_H);
   if(Input.MOUS_X == Enchanted->Mouse_X && Input.MOUS_Y == Enchanted->Mouse_Y && Input.MOUS_Left == 0){if((++Enchanted->Mouse_Standby) == 255ui8) Enchanted->Mouse_Standby = 254ui8;} else {Enchanted->Mouse_Standby = 0ui8;}
   if(Enchanted->Mouse_Standby < 150ui8){ShowCursor(TRUE); G_SetDisplay(2, Enchanted->Pic_Index_Interface[13], Input.MOUS_X - 3ull, Input.MOUS_Y - 3ull);} else {if(Enchanted->Mouse_Standby == 153ui8){ShowCursor(FALSE); SetCursor(NULL);}}
   Enchanted->Mouse_X = Input.MOUS_X; Enchanted->Mouse_Y = Input.MOUS_Y;
   if(Input.MOUS_Left >= 1 && Enchanted->Draw)
   {
    int64 Vrab02 = Input.MOUS_X; int64 Vrab03 = Input.MOUS_Y;
    int64 Vrab04 = Input.MOUS_X_Left; int64 Vrab05 = Input.MOUS_Y_Left;
    if(Vrab04 < Vrab02){Vrab02 = Vrab04; Vrab04 = Input.MOUS_X;}
    if(Vrab05 < Vrab03){Vrab03 = Vrab05; Vrab05 = Input.MOUS_Y;}
    Vrab04 -= Vrab02; Vrab05 -= Vrab03;
    if(Vrab04 > 10 || Vrab05 > 10)
    G_SetDisplay(1, 0xFF00, Vrab02, Vrab03, 0, 255ui8, Vrab04, Vrab05);
    if(Vrab04 > 2 && Vrab05 > 2)
    G_SetDisplay(0, 0x00FF00, Vrab02 + 1, Vrab03 + 1, 0, 50ui8, Vrab04 - 2, Vrab05 - 2);
   }
   Enchanted->Print_Text(3, 0, 0, std::to_string(Vrab01));
   Enchanted->Print_Text(3, 15, 0, std::to_string(L_Random(10)));
  }
 //-/*/
 





















/*
 // Earlier Declaration
  int32  L_Numbering(string) fastened;
 //-//
 // Memory
  struct HEPTA_INPUT
  {
   uint8 MAIN_1;
   uint8 MAIN_2;
   uint8 MAIN_3;
   uint8 MAIN_4;
   uint8 MAIN_5;
   uint8 MAIN_6;
   uint8 MAIN_7;
   uint8 MAIN_8;
   uint8 MAIN_9;
   uint8 MAIN_0;
   uint8 MAIN_A;
   uint8 MAIN_B;
   uint8 MAIN_C;
   uint8 MAIN_D;
   uint8 MAIN_E;
   uint8 MAIN_F;
   uint8 MAIN_G;
   uint8 MAIN_H;
   uint8 MAIN_I;
   uint8 MAIN_J;
   uint8 MAIN_K;
   uint8 MAIN_L;
   uint8 MAIN_M;
   uint8 MAIN_N;
   uint8 MAIN_O;
   uint8 MAIN_P;
   uint8 MAIN_Q;
   uint8 MAIN_R;
   uint8 MAIN_S;
   uint8 MAIN_T;
   uint8 MAIN_U;
   uint8 MAIN_V;
   uint8 MAIN_W;
   uint8 MAIN_X;
   uint8 MAIN_Y;
   uint8 MAIN_Z;
   uint8 CORE_ESC;
   uint8 CORE_F1;
   uint8 CORE_F2;
   uint8 CORE_F3;
   uint8 CORE_F4;
   uint8 CORE_F5;
   uint8 CORE_F6;
   uint8 CORE_F7;
   uint8 CORE_F8;
   uint8 CORE_F9;
   uint8 CORE_F10;
   uint8 CORE_F11;
   uint8 CORE_F12;
   uint8 CORE_PSCREEN;
   uint8 CORE_DELETE;
   uint8 CORE_BACKSPACE;
   uint8 CORE_TAB;
   uint8 CORE_CAPSLOCK;
   uint8 CORE_ENTER;
   uint8 CORE_LSHIFT;
   uint8 CORE_RSHIFT;
   uint8 CORE_LCTRL;
   uint8 CORE_RCTRL;
   uint8 CORE_LALT;
   uint8 CORE_RALT;
   uint8 CORE_LWIN;
   uint8 CORE_RWIN;
   uint8 CORE_UP;
   uint8 CORE_LEFT;
   uint8 CORE_DOWN;
   uint8 CORE_RIGHT;
   uint8 NUMS_1;
   uint8 NUMS_2;
   uint8 NUMS_3;
   uint8 NUMS_4;
   uint8 NUMS_5;
   uint8 NUMS_6;
   uint8 NUMS_7;
   uint8 NUMS_8;
   uint8 NUMS_9;
   uint8 NUMS_0;
   uint8 NUMS_ENTER;
   uint8 NUMS_INSERT;
   uint8 NUMS_DELETE;
   uint8 NUMS_NUMLOCK;
   uint8 NUMS_ADD;
   uint8 NUMS_SUB;
   uint8 NUMS_SLASH;
   uint8 NUMS_MULTIPLE;
   uint8 NUMS_DOT;
   uint8 SYMB_BACKTICK;
   uint8 SYMB_UNDERSCORE;
   
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

   int1  CAPS_ON;
  };
  struct HEPTA_LF2_ENCHANTED_CONFIG 
  {
   uint8 P_Con[4]{};
   uint8 P_Input[4][14]{};
   string P_Name[4]{};
  };
  struct HEPTA_LF2_ENCHANTED
  {
   uint8 Menu;
   int32 Mouse_X; int32 Mouse_Y; uint8 Mouse_Standby;
   uint64 Runtime; uint64 Runtime2; uint64 Runtime3;
   
   string String, String_Load, String_Load2;
   std::ifstream File;
   std::streampos Lastread;

   HEPTA_LF2_ENCHANTED_CONFIG Config[2];
   std::vector < insize > Sound_Index;
   std::vector < insize > Sprite_Index_Interface;
   std::vector < insize > Sprite_Index_Character;
   
   int0 PrintText(int32 Vrab01, int32 Vrab02, uint8 Vrab03, statics string &Temp01)
   {
    statics insize Vrab04 = Temp01.size(); insize Vrab05 = 0; int64 Vrab06 = rint64(Vrab01); Vrab03 %= 6;
    while(Vrab05 != Vrab04)
    {
     G_SetDisplay(4, Sprite_Index_Interface[rinsize(Vrab03)] + rinsize(Temp01.at(Vrab05)), Vrab06, Vrab02);
     Vrab05 += 1; Vrab06 += 9;
    }
   }
   int0 Load(statics string Temp01)
   {
    std::ifstream File01(Temp01); 
    if(!File01.is_open()){std::ofstream File02(Temp01); File02 << ""; File02.close(); File01.open(Temp01);}
    string Temp02;
    if(File01){File01 >> Config[1].P_Name[0];} else {return;}
    if(File01){File01 >> Config[1].P_Name[1];} else {return;}
    if(File01){File01 >> Config[1].P_Name[2];} else {return;}
    if(File01){File01 >> Config[1].P_Name[3];} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][0] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][1] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][2] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][3] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][4] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][5] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][6] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][0] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][1] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][2] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][3] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][4] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][5] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][6] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][0] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][1] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][2] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][3] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][4] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][5] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][6] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][0] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][1] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][2] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][3] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][4] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][5] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][6] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][7] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][8] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][9] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][10] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][11] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][12] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[0][13] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][7] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][8] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][9] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][10] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][11] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][12] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[1][13] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][7] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][8] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][9] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][10] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][11] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][12] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[2][13] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][7] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][8] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][9] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][10] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][11] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][12] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Input[3][13] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Con[0] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Con[1] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Con[2] = ruint8(L_Numbering(Temp02));} else {return;}
    if(File01){File01 >> Temp02; Config[1].P_Con[3] = ruint8(L_Numbering(Temp02));} else {return;}
    Config[0] = Config[1];
   }
   int0 Save(statics string Temp01)
   {
    std::ofstream File01(Temp01);
    if(!File01.is_open()) return;

    File01 << Config[0].P_Name[0] << " " << Config[0].P_Name[1] << " " << Config[0].P_Name[2] << " " << Config[0].P_Name[3] << "\n";
    File01 << ruint32(Config[0].P_Input[0][0]) << " " << ruint32(Config[0].P_Input[0][1]) << " " << ruint32(Config[0].P_Input[0][2]) << " " << ruint32(Config[0].P_Input[0][3]) << " " << ruint32(Config[0].P_Input[0][4]) << " " << ruint32(Config[0].P_Input[0][5]) << " " << ruint32(Config[0].P_Input[0][6]) << "\n";
    File01 << ruint32(Config[0].P_Input[1][0]) << " " << ruint32(Config[0].P_Input[1][1]) << " " << ruint32(Config[0].P_Input[1][2]) << " " << ruint32(Config[0].P_Input[1][3]) << " " << ruint32(Config[0].P_Input[1][4]) << " " << ruint32(Config[0].P_Input[1][5]) << " " << ruint32(Config[0].P_Input[1][6]) << "\n";
    File01 << ruint32(Config[0].P_Input[2][0]) << " " << ruint32(Config[0].P_Input[2][1]) << " " << ruint32(Config[0].P_Input[2][2]) << " " << ruint32(Config[0].P_Input[2][3]) << " " << ruint32(Config[0].P_Input[2][4]) << " " << ruint32(Config[0].P_Input[2][5]) << " " << ruint32(Config[0].P_Input[2][6]) << "\n";
    File01 << ruint32(Config[0].P_Input[3][0]) << " " << ruint32(Config[0].P_Input[3][1]) << " " << ruint32(Config[0].P_Input[3][2]) << " " << ruint32(Config[0].P_Input[3][3]) << " " << ruint32(Config[0].P_Input[3][4]) << " " << ruint32(Config[0].P_Input[3][5]) << " " << ruint32(Config[0].P_Input[3][6]) << "\n";
    File01 << ruint32(Config[0].P_Input[0][7]) << " " << ruint32(Config[0].P_Input[0][8]) << " " << ruint32(Config[0].P_Input[0][9]) << " " << ruint32(Config[0].P_Input[0][10]) << " " << ruint32(Config[0].P_Input[0][11]) << " " << ruint32(Config[0].P_Input[0][12]) << " " << ruint32(Config[0].P_Input[0][13]) << "\n";
    File01 << ruint32(Config[0].P_Input[1][7]) << " " << ruint32(Config[0].P_Input[1][8]) << " " << ruint32(Config[0].P_Input[1][9]) << " " << ruint32(Config[0].P_Input[1][10]) << " " << ruint32(Config[0].P_Input[1][11]) << " " << ruint32(Config[0].P_Input[1][12]) << " " << ruint32(Config[0].P_Input[1][13]) << "\n";
    File01 << ruint32(Config[0].P_Input[2][7]) << " " << ruint32(Config[0].P_Input[2][8]) << " " << ruint32(Config[0].P_Input[2][9]) << " " << ruint32(Config[0].P_Input[2][10]) << " " << ruint32(Config[0].P_Input[2][11]) << " " << ruint32(Config[0].P_Input[2][12]) << " " << ruint32(Config[0].P_Input[2][13]) << "\n";
    File01 << ruint32(Config[0].P_Input[3][7]) << " " << ruint32(Config[0].P_Input[3][8]) << " " << ruint32(Config[0].P_Input[3][9]) << " " << ruint32(Config[0].P_Input[3][10]) << " " << ruint32(Config[0].P_Input[3][11]) << " " << ruint32(Config[0].P_Input[3][12]) << " " << ruint32(Config[0].P_Input[3][13]) << "\n";
    File01 << ruint32(Config[0].P_Con[0]) << " " << ruint32(Config[0].P_Con[1]) << " " << ruint32(Config[0].P_Con[2]) << " " << ruint32(Config[0].P_Con[3]);

    File01.close();
   }
   string InputName(uint8 Vrab01)
   {
    switch(Vrab01)
    {
     case 0: return "<none>";
     case 1: return "1";
     case 2: return "2";
     case 3: return "3";
     case 4: return "4";
     case 5: return "5";
     case 6: return "6";
     case 7: return "7";
     case 8: return "8";
     case 9: return "9";
     case 10: return "0";
     case 11: return "A";
     case 12: return "B";
     case 13: return "C";
     case 14: return "D";
     case 15: return "E";
     case 16: return "F";
     case 17: return "G";
     case 18: return "H";
     case 19: return "I";
     case 20: return "J";
     case 21: return "K";
     case 22: return "L";
     case 23: return "M";
     case 24: return "N";
     case 25: return "O";
     case 26: return "P";
     case 27: return "Q";
     case 28: return "R";
     case 29: return "S";
     case 30: return "T";
     case 31: return "U";
     case 32: return "V";
     case 33: return "W";
     case 34: return "X";
     case 35: return "Y";
     case 36: return "Z";
     case 37: return "0";
     default: return "";
    }
   }
   int0 Info_Bar(int64 Vrab01, int64 Vrab02, uint64 Vrab03, uint64 Vrab04)
   {
    if(Vrab03 % 2 == 1) Vrab03 += 1; if(Vrab04 % 2 == 1) Vrab04 += 1;
    G_SetDisplay(2, Sprite_Index_Interface[26], Vrab01 - 12, Vrab02 - 12);
    G_SetDisplay(2, Sprite_Index_Interface[27], Vrab01 + Vrab03 + 1, Vrab02 - 12);
    G_SetDisplay(2, Sprite_Index_Interface[28], Vrab01 - 12, Vrab02 + Vrab04 + 1);
    G_SetDisplay(2, Sprite_Index_Interface[29], Vrab01 + Vrab03 + 1, Vrab02 + Vrab04 + 1);
    G_SetDisplay(2, Sprite_Index_Interface[30], Vrab01, Vrab02 - 12, 0ui8, 255ui8, Vrab03);
    G_SetDisplay(2, Sprite_Index_Interface[30], Vrab01, Vrab02 + Vrab04 + 10, 0ui8, 255ui8, Vrab03);
    G_SetDisplay(2, Sprite_Index_Interface[31], Vrab01 - 12, Vrab02, 0ui8, 255ui8, 0, Vrab04);
    G_SetDisplay(2, Sprite_Index_Interface[31], Vrab01 + Vrab03 + 10, Vrab02, 0ui8, 255ui8, 0, Vrab04);

    {
     uint64 Vrab05 = Vrab04 + 1; uint64 Vrab06 = ruint64(-1);
     while(Vrab05 > 0)
     {
      uint64 Vrab07 = Vrab05 / 200; if(Vrab07 > 0){Vrab07 = 200;} else {Vrab07 = Vrab05 % 200;} Vrab05 -= Vrab07; Vrab06 += 1;
      G_SetDisplay(3, Sprite_Index_Interface[32], Vrab01 - 9, Vrab02 + (Vrab06 * 200), 0ui8, 255ui8, 9, Vrab07, 0, 1);
      G_SetDisplay(3, Sprite_Index_Interface[32], Vrab01 + Vrab03 + 1, Vrab02 + (Vrab06 * 200), 0ui8, 255ui8, 9, Vrab07, 0, 1);
     }
    }
    {
     uint64 Vrab05 = Vrab04 + 19; uint64 Vrab06 = ruint64(-1);
     while(Vrab05 > 0)
     {
      uint64 Vrab07 = Vrab05 / 200; if(Vrab07 > 0){Vrab07 = 200;} else {Vrab07 = Vrab05 % 200;} Vrab05 -= Vrab07; Vrab06 += 1;
      uint64 Vrab08 = Vrab03 + 1; uint64 Vrab09 = ruint64(-1);
      while(Vrab08 > 0)
      {
       uint64 Vrab10 = Vrab08 / 198; if(Vrab10 > 0){Vrab10 = 198;} else {Vrab10 = Vrab08 % 198;} Vrab08 -= Vrab10; Vrab09 += 1;
       G_SetDisplay(3, Sprite_Index_Interface[32], Vrab01 + (Vrab09 * 198), Vrab02 - 9 + (Vrab06 * 200), 0ui8, 255ui8, Vrab10, Vrab07, 1, 0);
      }
     }
    }
   }
  };

  // Non-Basic
   HEPTA_INPUT Input;                  // Inputs
   string Text0001;                   // Language Text
   std::ifstream File0001;            // -
   std::ofstream File0002;            // -

  // Basic
   uint64 Varb0001 = 0;               // App Runtime
   uint32 Varb0002 = 800;             // Display W
   uint32 Varb0003 = 600;             // Display H
   uint8 Varb0004 = 1;                // FPS Ratio
   int1 Varb0005 = true;              // Keep aspect ratio?
   int1 Varb0006 = true;              // Limit displayed resolution if window's resolution is higher than display's resolution?
   int1 Varb0007 = false;             // Update Display?
   uint32 Varb0008 = 0;               // X Display Offset
   uint32 Varb0009 = 0;               // Y Display Offset
   xint64 Varb0010 = 1;               // Mouse Offset Ratio
   xint64 Varb0012 = 0.6;             // Volume
   uint64 Varb0013 = 0;               // Menu
   uint64 Varb0014 = 0;               // Random Seed
   uint64 Varb0025 = 0;               // Random Seed 2
   uint64 Varb0015 = 0;               // Random Seed 3
   uint64 Varb0016 = 0;               // Random Seed 4
   int1 Varb0017 = false;             // LF2 Enchanted

  // Enchanted Memory
   unique < HEPTA_LF2_ENCHANTED > Ench0001;    //

  // Temporals
   std::vector < uint32 > Vect0001;   // Random Accessed Vector

 //-//
 // Light Functions
  uint8  L_Press()
  {
   if(Input.CORE_ESC == 1) return 0ui8;
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
   return 255ui8;
  }
  int0   L_Typing(string &Temp01)
  {
   if(Input.CAPS_ON)
   {
    {statics uint8 Vrab01 = Input.MAIN_A; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('A'); if(Vrab01 == 40) Input.MAIN_A = 253;}
    {statics uint8 Vrab01 = Input.MAIN_B; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('B'); if(Vrab01 == 40) Input.MAIN_B = 253;}
    {statics uint8 Vrab01 = Input.MAIN_C; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('C'); if(Vrab01 == 40) Input.MAIN_C = 253;}
    {statics uint8 Vrab01 = Input.MAIN_D; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('D'); if(Vrab01 == 40) Input.MAIN_D = 253;}
    {statics uint8 Vrab01 = Input.MAIN_E; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('E'); if(Vrab01 == 40) Input.MAIN_E = 253;}
    {statics uint8 Vrab01 = Input.MAIN_F; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('F'); if(Vrab01 == 40) Input.MAIN_F = 253;}
    {statics uint8 Vrab01 = Input.MAIN_G; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('G'); if(Vrab01 == 40) Input.MAIN_G = 253;}
    {statics uint8 Vrab01 = Input.MAIN_H; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('H'); if(Vrab01 == 40) Input.MAIN_H = 253;}
    {statics uint8 Vrab01 = Input.MAIN_I; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('I'); if(Vrab01 == 40) Input.MAIN_I = 253;}
    {statics uint8 Vrab01 = Input.MAIN_J; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('J'); if(Vrab01 == 40) Input.MAIN_J = 253;}
    {statics uint8 Vrab01 = Input.MAIN_K; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('K'); if(Vrab01 == 40) Input.MAIN_K = 253;}
    {statics uint8 Vrab01 = Input.MAIN_L; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('L'); if(Vrab01 == 40) Input.MAIN_L = 253;}
    {statics uint8 Vrab01 = Input.MAIN_M; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('M'); if(Vrab01 == 40) Input.MAIN_M = 253;}
    {statics uint8 Vrab01 = Input.MAIN_N; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('N'); if(Vrab01 == 40) Input.MAIN_N = 253;}
    {statics uint8 Vrab01 = Input.MAIN_O; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('O'); if(Vrab01 == 40) Input.MAIN_O = 253;}
    {statics uint8 Vrab01 = Input.MAIN_P; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('P'); if(Vrab01 == 40) Input.MAIN_P = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Q; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('Q'); if(Vrab01 == 40) Input.MAIN_Q = 253;}
    {statics uint8 Vrab01 = Input.MAIN_R; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('R'); if(Vrab01 == 40) Input.MAIN_R = 253;}
    {statics uint8 Vrab01 = Input.MAIN_S; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('S'); if(Vrab01 == 40) Input.MAIN_S = 253;}
    {statics uint8 Vrab01 = Input.MAIN_T; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('T'); if(Vrab01 == 40) Input.MAIN_T = 253;}
    {statics uint8 Vrab01 = Input.MAIN_U; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('U'); if(Vrab01 == 40) Input.MAIN_U = 253;}
    {statics uint8 Vrab01 = Input.MAIN_V; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('V'); if(Vrab01 == 40) Input.MAIN_V = 253;}
    {statics uint8 Vrab01 = Input.MAIN_W; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('W'); if(Vrab01 == 40) Input.MAIN_W = 253;}
    {statics uint8 Vrab01 = Input.MAIN_X; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('X'); if(Vrab01 == 40) Input.MAIN_X = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Y; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('Y'); if(Vrab01 == 40) Input.MAIN_Y = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Z; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('Z'); if(Vrab01 == 40) Input.MAIN_Z = 253;}
   } else
   {
    {statics uint8 Vrab01 = Input.MAIN_A; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('a'); if(Vrab01 == 40) Input.MAIN_A = 253;}
    {statics uint8 Vrab01 = Input.MAIN_B; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('b'); if(Vrab01 == 40) Input.MAIN_B = 253;}
    {statics uint8 Vrab01 = Input.MAIN_C; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('c'); if(Vrab01 == 40) Input.MAIN_C = 253;}
    {statics uint8 Vrab01 = Input.MAIN_D; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('d'); if(Vrab01 == 40) Input.MAIN_D = 253;}
    {statics uint8 Vrab01 = Input.MAIN_E; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('e'); if(Vrab01 == 40) Input.MAIN_E = 253;}
    {statics uint8 Vrab01 = Input.MAIN_F; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('f'); if(Vrab01 == 40) Input.MAIN_F = 253;}
    {statics uint8 Vrab01 = Input.MAIN_G; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('g'); if(Vrab01 == 40) Input.MAIN_G = 253;}
    {statics uint8 Vrab01 = Input.MAIN_H; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('h'); if(Vrab01 == 40) Input.MAIN_H = 253;}
    {statics uint8 Vrab01 = Input.MAIN_I; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('i'); if(Vrab01 == 40) Input.MAIN_I = 253;}
    {statics uint8 Vrab01 = Input.MAIN_J; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('j'); if(Vrab01 == 40) Input.MAIN_J = 253;}
    {statics uint8 Vrab01 = Input.MAIN_K; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('k'); if(Vrab01 == 40) Input.MAIN_K = 253;}
    {statics uint8 Vrab01 = Input.MAIN_L; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('l'); if(Vrab01 == 40) Input.MAIN_L = 253;}
    {statics uint8 Vrab01 = Input.MAIN_M; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('m'); if(Vrab01 == 40) Input.MAIN_M = 253;}
    {statics uint8 Vrab01 = Input.MAIN_N; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('n'); if(Vrab01 == 40) Input.MAIN_N = 253;}
    {statics uint8 Vrab01 = Input.MAIN_O; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('o'); if(Vrab01 == 40) Input.MAIN_O = 253;}
    {statics uint8 Vrab01 = Input.MAIN_P; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('p'); if(Vrab01 == 40) Input.MAIN_P = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Q; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('q'); if(Vrab01 == 40) Input.MAIN_Q = 253;}
    {statics uint8 Vrab01 = Input.MAIN_R; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('r'); if(Vrab01 == 40) Input.MAIN_R = 253;}
    {statics uint8 Vrab01 = Input.MAIN_S; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('s'); if(Vrab01 == 40) Input.MAIN_S = 253;}
    {statics uint8 Vrab01 = Input.MAIN_T; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('t'); if(Vrab01 == 40) Input.MAIN_T = 253;}
    {statics uint8 Vrab01 = Input.MAIN_U; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('u'); if(Vrab01 == 40) Input.MAIN_U = 253;}
    {statics uint8 Vrab01 = Input.MAIN_V; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('v'); if(Vrab01 == 40) Input.MAIN_V = 253;}
    {statics uint8 Vrab01 = Input.MAIN_W; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('w'); if(Vrab01 == 40) Input.MAIN_W = 253;}
    {statics uint8 Vrab01 = Input.MAIN_X; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('x'); if(Vrab01 == 40) Input.MAIN_X = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Y; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('y'); if(Vrab01 == 40) Input.MAIN_Y = 253;}
    {statics uint8 Vrab01 = Input.MAIN_Z; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('z'); if(Vrab01 == 40) Input.MAIN_Z = 253;}
   }
   {statics uint8 Vrab01 = Input.MAIN_0; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('0'); if(Vrab01 == 40) Input.MAIN_0 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_1; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('1'); if(Vrab01 == 40) Input.MAIN_1 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_2; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('2'); if(Vrab01 == 40) Input.MAIN_2 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_3; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('3'); if(Vrab01 == 40) Input.MAIN_3 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_4; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('4'); if(Vrab01 == 40) Input.MAIN_4 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_5; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('5'); if(Vrab01 == 40) Input.MAIN_5 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_6; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('6'); if(Vrab01 == 40) Input.MAIN_6 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_7; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('7'); if(Vrab01 == 40) Input.MAIN_7 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_8; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('8'); if(Vrab01 == 40) Input.MAIN_8 = 253;}
   {statics uint8 Vrab01 = Input.MAIN_9; if(Vrab01 == 1 || Vrab01 == 254) Temp01.push_back('9'); if(Vrab01 == 40) Input.MAIN_9 = 253;}
   {statics uint8 Vrab01 = Input.CORE_BACKSPACE; if(Vrab01 == 1 || Vrab01 == 254) if(Temp01.size() > 0) Temp01.pop_back(); if(Vrab01 == 40) Input.CORE_BACKSPACE = 253;}
  }
  int1   L_Within(int32 Vrab01, int32 Vrab02, int32 Vrab03, int32 Vrab04, uint32 Vrab05, uint32 Vrab06)
  {
   if(Vrab01 >= Vrab03 && Vrab01 <= rint32(Vrab03 + Vrab05))
   if(Vrab02 >= Vrab04 && Vrab02 <= rint32(Vrab04 + Vrab06))
   return true;
   return false;
  }
  int32  L_Rounding(xint64 Vrab01){if(rint64(Vrab01) == rxint64(rint64(Vrab01 + 0.5))) return rint32(Vrab01); return rint32(Vrab01) + 1;}
  int32  L_Numbering(string Temp01) fastened {while(Temp01.size() > 0 && Temp01.at(0) != '-' && (Temp01.at(0) < '0' || Temp01.at(0) > '9')) Temp01.erase(0, 1); uint32 Vrab01 = Temp01.size(); if(Vrab01 == 0) return 0; while(Vrab01 != 1) if(Temp01.at(Vrab01 - 1) < '0' || Temp01.at(Vrab01 - 1) > '9'){Vrab01 -= 1;} else {break;} int32 Vrab02 = 0; if(Temp01.at(0) == '-'){if(Vrab01 == 1) return 0; if(Temp01.at(1) < '0' || Temp01.at(1) > '9') return 0; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1; break; case '2': Vrab02 -= 2; break; case '3': Vrab02 -= 3; break; case '4': Vrab02 -= 4; break; case '5': Vrab02 -= 5; break; case '6': Vrab02 -= 6; break; case '7': Vrab02 -= 7; break; case '8': Vrab02 -= 8; break; case '9': Vrab02 -= 9; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10; break; case '2': Vrab02 -= 20; break; case '3': Vrab02 -= 30; break; case '4': Vrab02 -= 40; break; case '5': Vrab02 -= 50; break; case '6': Vrab02 -= 60; break; case '7': Vrab02 -= 70; break; case '8': Vrab02 -= 80; break; case '9': Vrab02 -= 90; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100; break; case '2': Vrab02 -= 200; break; case '3': Vrab02 -= 300; break; case '4': Vrab02 -= 400; break; case '5': Vrab02 -= 500; break; case '6': Vrab02 -= 600; break; case '7': Vrab02 -= 700; break; case '8': Vrab02 -= 800; break; case '9': Vrab02 -= 900; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000; break; case '2': Vrab02 -= 2000; break; case '3': Vrab02 -= 3000; break; case '4': Vrab02 -= 4000; break; case '5': Vrab02 -= 5000; break; case '6': Vrab02 -= 6000; break; case '7': Vrab02 -= 7000; break; case '8': Vrab02 -= 8000; break; case '9': Vrab02 -= 9000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000; break; case '2': Vrab02 -= 20000; break; case '3': Vrab02 -= 30000; break; case '4': Vrab02 -= 40000; break; case '5': Vrab02 -= 50000; break; case '6': Vrab02 -= 60000; break; case '7': Vrab02 -= 70000; break; case '8': Vrab02 -= 80000; break; case '9': Vrab02 -= 90000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000; break; case '2': Vrab02 -= 200000; break; case '3': Vrab02 -= 300000; break; case '4': Vrab02 -= 400000; break; case '5': Vrab02 -= 500000; break; case '6': Vrab02 -= 600000; break; case '7': Vrab02 -= 700000; break; case '8': Vrab02 -= 800000; break; case '9': Vrab02 -= 900000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 1000000; break; case '2': Vrab02 -= 2000000; break; case '3': Vrab02 -= 3000000; break; case '4': Vrab02 -= 4000000; break; case '5': Vrab02 -= 5000000; break; case '6': Vrab02 -= 6000000; break; case '7': Vrab02 -= 7000000; break; case '8': Vrab02 -= 8000000; break; case '9': Vrab02 -= 9000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 10000000; break; case '2': Vrab02 -= 20000000; break; case '3': Vrab02 -= 30000000; break; case '4': Vrab02 -= 40000000; break; case '5': Vrab02 -= 50000000; break; case '6': Vrab02 -= 60000000; break; case '7': Vrab02 -= 70000000; break; case '8': Vrab02 -= 80000000; break; case '9': Vrab02 -= 90000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000; break; case '2': Vrab02 -= 200000000; break; case '3': Vrab02 -= 300000000; break; case '4': Vrab02 -= 400000000; break; case '5': Vrab02 -= 500000000; break; case '6': Vrab02 -= 600000000; break; case '7': Vrab02 -= 700000000; break; case '8': Vrab02 -= 800000000; break; case '9': Vrab02 -= 900000000; break; default: break;} Vrab01 -= 1; if(Vrab01 == 0) return Vrab02; for(int32 Vrab03 = 10; Vrab01 > 0; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 -= 100000000 * Vrab03; break; case '2': Vrab02 -= 200000000 * Vrab03; break; case '3': Vrab02 -= 300000000 * Vrab03; break; case '4': Vrab02 -= 400000000 * Vrab03; break; case '5': Vrab02 -= 500000000 * Vrab03; break; case '6': Vrab02 -= 600000000 * Vrab03; break; case '7': Vrab02 -= 700000000 * Vrab03; break; case '8': Vrab02 -= 800000000 * Vrab03; break; case '9': Vrab02 -= 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;} else {Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1; break; case '2': Vrab02 += 2; break; case '3': Vrab02 += 3; break; case '4': Vrab02 += 4; break; case '5': Vrab02 += 5; break; case '6': Vrab02 += 6; break; case '7': Vrab02 += 7; break; case '8': Vrab02 += 8; break; case '9': Vrab02 += 9; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10; break; case '2': Vrab02 += 20; break; case '3': Vrab02 += 30; break; case '4': Vrab02 += 40; break; case '5': Vrab02 += 50; break; case '6': Vrab02 += 60; break; case '7': Vrab02 += 70; break; case '8': Vrab02 += 80; break; case '9': Vrab02 += 90; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100; break; case '2': Vrab02 += 200; break; case '3': Vrab02 += 300; break; case '4': Vrab02 += 400; break; case '5': Vrab02 += 500; break; case '6': Vrab02 += 600; break; case '7': Vrab02 += 700; break; case '8': Vrab02 += 800; break; case '9': Vrab02 += 900; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000; break; case '2': Vrab02 += 2000; break; case '3': Vrab02 += 3000; break; case '4': Vrab02 += 4000; break; case '5': Vrab02 += 5000; break; case '6': Vrab02 += 6000; break; case '7': Vrab02 += 7000; break; case '8': Vrab02 += 8000; break; case '9': Vrab02 += 9000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000; break; case '2': Vrab02 += 20000; break; case '3': Vrab02 += 30000; break; case '4': Vrab02 += 40000; break; case '5': Vrab02 += 50000; break; case '6': Vrab02 += 60000; break; case '7': Vrab02 += 70000; break; case '8': Vrab02 += 80000; break; case '9': Vrab02 += 90000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000; break; case '2': Vrab02 += 200000; break; case '3': Vrab02 += 300000; break; case '4': Vrab02 += 400000; break; case '5': Vrab02 += 500000; break; case '6': Vrab02 += 600000; break; case '7': Vrab02 += 700000; break; case '8': Vrab02 += 800000; break; case '9': Vrab02 += 900000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 1000000; break; case '2': Vrab02 += 2000000; break; case '3': Vrab02 += 3000000; break; case '4': Vrab02 += 4000000; break; case '5': Vrab02 += 5000000; break; case '6': Vrab02 += 6000000; break; case '7': Vrab02 += 7000000; break; case '8': Vrab02 += 8000000; break; case '9': Vrab02 += 9000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 10000000; break; case '2': Vrab02 += 20000000; break; case '3': Vrab02 += 30000000; break; case '4': Vrab02 += 40000000; break; case '5': Vrab02 += 50000000; break; case '6': Vrab02 += 60000000; break; case '7': Vrab02 += 70000000; break; case '8': Vrab02 += 80000000; break; case '9': Vrab02 += 90000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000; break; case '2': Vrab02 += 200000000; break; case '3': Vrab02 += 300000000; break; case '4': Vrab02 += 400000000; break; case '5': Vrab02 += 500000000; break; case '6': Vrab02 += 600000000; break; case '7': Vrab02 += 700000000; break; case '8': Vrab02 += 800000000; break; case '9': Vrab02 += 900000000; break; default: break;} if(Vrab01 == 0) return Vrab02; Vrab01 -= 1; for(int32 Vrab03 = 10; Vrab01 != -1; Vrab03 *= 10){switch(Temp01.at(Vrab01)){case '1': Vrab02 += 100000000 * Vrab03; break; case '2': Vrab02 += 200000000 * Vrab03; break; case '3': Vrab02 += 300000000 * Vrab03; break; case '4': Vrab02 += 400000000 * Vrab03; break; case '5': Vrab02 += 500000000 * Vrab03; break; case '6': Vrab02 += 600000000 * Vrab03; break; case '7': Vrab02 += 700000000 * Vrab03; break; case '8': Vrab02 += 800000000 * Vrab03; break; case '9': Vrab02 += 900000000 * Vrab03; break; default: break;} Vrab01 -= 1;} return Vrab02;}}
  int64  L_Rounding64(xint64 Vrab01){if(rint64(Vrab01) == rxint64(rint64(Vrab01 + 0.5))) return rint64(Vrab01); return rint64(Vrab01) + 1;}
  uint64 L_Random(uint64 Vrab01)
  {
   Varb0016 += 69; Varb0015 += Varb0016; Varb0013 &= Varb0015; Varb0014 += 1; Varb0016 -= Varb0014; Varb0014 |= Varb0001;
   return ruint64(L_Rounding64((rxint64(rint64(Varb0014)) / rxint64(0xFFFFFFFFFFFFFFFF)) * rxint64(rint64(Vrab01))));
  }
  string L_Lowercase(string Temp01)     fastened {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) >= 'A' && Temp01.at(Vrab01) <= 'Z') Temp01.at(Vrab01) += 32;} return Temp01;}
 //-//
 // Prime Functions
  int0 P_EngineInput(std::unique_ptr < DirectX::Keyboard > *Inpt01, std::unique_ptr < DirectX::GamePad > *Inpt02, std::unique_ptr < DirectX::Mouse > *Inpt03)
  {
   auto Inpt05 = (*Inpt01)->GetState();
   if(Inpt05.D0){if((++Input.MAIN_0) == 255ui8) Input.MAIN_0 = 250ui8;} else {Input.MAIN_0 = 0ui8;}
   if(Inpt05.D1){if((++Input.MAIN_1) == 255ui8) Input.MAIN_1 = 250ui8;} else {Input.MAIN_1 = 0ui8;}
   if(Inpt05.D2){if((++Input.MAIN_2) == 255ui8) Input.MAIN_2 = 250ui8;} else {Input.MAIN_2 = 0ui8;}
   if(Inpt05.D3){if((++Input.MAIN_3) == 255ui8) Input.MAIN_3 = 250ui8;} else {Input.MAIN_3 = 0ui8;}
   if(Inpt05.D4){if((++Input.MAIN_4) == 255ui8) Input.MAIN_4 = 250ui8;} else {Input.MAIN_4 = 0ui8;}
   if(Inpt05.D5){if((++Input.MAIN_5) == 255ui8) Input.MAIN_5 = 250ui8;} else {Input.MAIN_5 = 0ui8;}
   if(Inpt05.D6){if((++Input.MAIN_6) == 255ui8) Input.MAIN_6 = 250ui8;} else {Input.MAIN_6 = 0ui8;}
   if(Inpt05.D7){if((++Input.MAIN_7) == 255ui8) Input.MAIN_7 = 250ui8;} else {Input.MAIN_7 = 0ui8;}
   if(Inpt05.D8){if((++Input.MAIN_8) == 255ui8) Input.MAIN_8 = 250ui8;} else {Input.MAIN_8 = 0ui8;}
   if(Inpt05.D9){if((++Input.MAIN_9) == 255ui8) Input.MAIN_9 = 250ui8;} else {Input.MAIN_9 = 0ui8;}
   if(Inpt05.A){if((++Input.MAIN_A) == 255ui8) Input.MAIN_A = 250ui8;} else {Input.MAIN_A = 0ui8;}
   if(Inpt05.B){if((++Input.MAIN_B) == 255ui8) Input.MAIN_B = 250ui8;} else {Input.MAIN_B = 0ui8;}
   if(Inpt05.C){if((++Input.MAIN_C) == 255ui8) Input.MAIN_C = 250ui8;} else {Input.MAIN_C = 0ui8;}
   if(Inpt05.D){if((++Input.MAIN_D) == 255ui8) Input.MAIN_D = 250ui8;} else {Input.MAIN_D = 0ui8;}
   if(Inpt05.E){if((++Input.MAIN_E) == 255ui8) Input.MAIN_E = 250ui8;} else {Input.MAIN_E = 0ui8;}
   if(Inpt05.F){if((++Input.MAIN_F) == 255ui8) Input.MAIN_F = 250ui8;} else {Input.MAIN_F = 0ui8;}
   if(Inpt05.G){if((++Input.MAIN_G) == 255ui8) Input.MAIN_G = 250ui8;} else {Input.MAIN_G = 0ui8;}
   if(Inpt05.H){if((++Input.MAIN_H) == 255ui8) Input.MAIN_H = 250ui8;} else {Input.MAIN_H = 0ui8;}
   if(Inpt05.I){if((++Input.MAIN_I) == 255ui8) Input.MAIN_I = 250ui8;} else {Input.MAIN_I = 0ui8;}
   if(Inpt05.J){if((++Input.MAIN_J) == 255ui8) Input.MAIN_J = 250ui8;} else {Input.MAIN_J = 0ui8;}
   if(Inpt05.K){if((++Input.MAIN_K) == 255ui8) Input.MAIN_K = 250ui8;} else {Input.MAIN_K = 0ui8;}
   if(Inpt05.L){if((++Input.MAIN_L) == 255ui8) Input.MAIN_L = 250ui8;} else {Input.MAIN_L = 0ui8;}
   if(Inpt05.M){if((++Input.MAIN_M) == 255ui8) Input.MAIN_M = 250ui8;} else {Input.MAIN_M = 0ui8;}
   if(Inpt05.N){if((++Input.MAIN_N) == 255ui8) Input.MAIN_N = 250ui8;} else {Input.MAIN_N = 0ui8;}
   if(Inpt05.O){if((++Input.MAIN_O) == 255ui8) Input.MAIN_O = 250ui8;} else {Input.MAIN_O = 0ui8;}
   if(Inpt05.P){if((++Input.MAIN_P) == 255ui8) Input.MAIN_P = 250ui8;} else {Input.MAIN_P = 0ui8;}
   if(Inpt05.Q){if((++Input.MAIN_Q) == 255ui8) Input.MAIN_Q = 250ui8;} else {Input.MAIN_Q = 0ui8;}
   if(Inpt05.R){if((++Input.MAIN_R) == 255ui8) Input.MAIN_R = 250ui8;} else {Input.MAIN_R = 0ui8;}
   if(Inpt05.S){if((++Input.MAIN_S) == 255ui8) Input.MAIN_S = 250ui8;} else {Input.MAIN_S = 0ui8;}
   if(Inpt05.T){if((++Input.MAIN_T) == 255ui8) Input.MAIN_T = 250ui8;} else {Input.MAIN_T = 0ui8;}
   if(Inpt05.U){if((++Input.MAIN_U) == 255ui8) Input.MAIN_U = 250ui8;} else {Input.MAIN_U = 0ui8;}
   if(Inpt05.V){if((++Input.MAIN_V) == 255ui8) Input.MAIN_V = 250ui8;} else {Input.MAIN_V = 0ui8;}
   if(Inpt05.W){if((++Input.MAIN_W) == 255ui8) Input.MAIN_W = 250ui8;} else {Input.MAIN_W = 0ui8;}
   if(Inpt05.X){if((++Input.MAIN_X) == 255ui8) Input.MAIN_X = 250ui8;} else {Input.MAIN_X = 0ui8;}
   if(Inpt05.Y){if((++Input.MAIN_Y) == 255ui8) Input.MAIN_Y = 250ui8;} else {Input.MAIN_Y = 0ui8;}
   if(Inpt05.Z){if((++Input.MAIN_Z) == 255ui8) Input.MAIN_Z = 250ui8;} else {Input.MAIN_Z = 0ui8;}
   if(Inpt05.Escape){if((++Input.CORE_ESC) == 255ui8) Input.CORE_ESC = 250ui8;} else {Input.CORE_ESC = 0ui8;}
   if(Inpt05.F1){if((++Input.CORE_F1) == 255ui8) Input.CORE_F1 = 250ui8;} else {Input.CORE_F1 = 0ui8;}
   if(Inpt05.F2){if((++Input.CORE_F2) == 255ui8) Input.CORE_F2 = 250ui8;} else {Input.CORE_F2 = 0ui8;}
   if(Inpt05.F3){if((++Input.CORE_F3) == 255ui8) Input.CORE_F3 = 250ui8;} else {Input.CORE_F3 = 0ui8;}
   if(Inpt05.F4){if((++Input.CORE_F4) == 255ui8) Input.CORE_F4 = 250ui8;} else {Input.CORE_F4 = 0ui8;}
   if(Inpt05.F5){if((++Input.CORE_F5) == 255ui8) Input.CORE_F5 = 250ui8;} else {Input.CORE_F5 = 0ui8;}
   if(Inpt05.F6){if((++Input.CORE_F6) == 255ui8) Input.CORE_F6 = 250ui8;} else {Input.CORE_F6 = 0ui8;}
   if(Inpt05.F7){if((++Input.CORE_F7) == 255ui8) Input.CORE_F7 = 250ui8;} else {Input.CORE_F7 = 0ui8;}
   if(Inpt05.F8){if((++Input.CORE_F8) == 255ui8) Input.CORE_F8 = 250ui8;} else {Input.CORE_F8 = 0ui8;}
   if(Inpt05.F9){if((++Input.CORE_F9) == 255ui8) Input.CORE_F9 = 250ui8;} else {Input.CORE_F9 = 0ui8;}
   if(Inpt05.F10){if((++Input.CORE_F10) == 255ui8) Input.CORE_F10 = 250ui8;} else {Input.CORE_F10 = 0ui8;}
   if(Inpt05.F11){if((++Input.CORE_F11) == 255ui8) Input.CORE_F11 = 250ui8;} else {Input.CORE_F11 = 0ui8;}
   if(Inpt05.F12){if((++Input.CORE_F12) == 255ui8) Input.CORE_F12 = 250ui8;} else {Input.CORE_F12 = 0ui8;}
   if(Inpt05.PrintScreen){if((++Input.CORE_PSCREEN) == 255ui8) Input.CORE_PSCREEN = 250ui8;} else {Input.CORE_PSCREEN = 0ui8;}
   if(Inpt05.Delete){if((++Input.CORE_DELETE) == 255ui8) Input.CORE_DELETE = 250ui8;} else {Input.CORE_DELETE = 0ui8;}
   if(Inpt05.Back){if((++Input.CORE_BACKSPACE) == 255ui8) Input.CORE_BACKSPACE = 250ui8;} else {Input.CORE_BACKSPACE = 0ui8;}
   if(Inpt05.Tab){if((++Input.CORE_TAB) == 255ui8) Input.CORE_TAB = 250ui8;} else {Input.CORE_TAB = 0ui8;}
   if(Inpt05.Enter){if((++Input.CORE_ENTER) == 255ui8) Input.CORE_ENTER = 250ui8;} else {Input.CORE_ENTER = 0ui8;}
   if(Inpt05.CapsLock){if((++Input.CORE_CAPSLOCK) == 255ui8) Input.CORE_CAPSLOCK = 250ui8; if(Input.CORE_CAPSLOCK == 1) Input.CAPS_ON = !Input.CAPS_ON;} else {Input.CORE_CAPSLOCK = 0ui8;}
   if(Inpt05.LeftShift){if((++Input.CORE_LSHIFT) == 255ui8) Input.CORE_LSHIFT = 250ui8;} else {Input.CORE_LSHIFT = 0ui8;}
   if(Inpt05.RightShift){if((++Input.CORE_RSHIFT) == 255ui8) Input.CORE_RSHIFT = 250ui8;} else {Input.CORE_RSHIFT = 0ui8;}
   if(Inpt05.LeftControl){if((++Input.CORE_LCTRL) == 255ui8) Input.CORE_LCTRL = 250ui8;} else {Input.CORE_LCTRL = 0ui8;}
   if(Inpt05.RightControl){if((++Input.CORE_RCTRL) == 255ui8) Input.CORE_RCTRL = 250ui8;} else {Input.CORE_RCTRL = 0ui8;}
   if(Inpt05.LeftAlt){if((++Input.CORE_LALT) == 255ui8) Input.CORE_LALT = 250ui8;} else {Input.CORE_LALT = 0ui8;}
   if(Inpt05.RightAlt){if((++Input.CORE_RALT) == 255ui8) Input.CORE_RALT = 250ui8;} else {Input.CORE_RALT = 0ui8;}
   if(Inpt05.LeftWindows){if((++Input.CORE_LWIN) == 255ui8) Input.CORE_LWIN = 250ui8;} else {Input.CORE_LWIN = 0ui8;}
   if(Inpt05.RightWindows){if((++Input.CORE_RWIN) == 255ui8) Input.CORE_RWIN = 250ui8;} else {Input.CORE_RWIN = 0ui8;}
   if(Inpt05.Up){if((++Input.CORE_UP) == 255ui8) Input.CORE_UP = 250ui8;} else {Input.CORE_UP = 0ui8;}
   if(Inpt05.Left){if((++Input.CORE_LEFT) == 255ui8) Input.CORE_LEFT = 250ui8;} else {Input.CORE_LEFT = 0ui8;}
   if(Inpt05.Down){if((++Input.CORE_DOWN) == 255ui8) Input.CORE_DOWN = 250ui8;} else {Input.CORE_DOWN = 0ui8;}
   if(Inpt05.Right){if((++Input.CORE_RIGHT) == 255ui8) Input.CORE_RIGHT = 250ui8;} else {Input.CORE_RIGHT = 0ui8;}
   auto Inpt06 = (*Inpt02)->GetState(0);
   auto Inpt07 = (*Inpt03)->GetState();
   Input.MOUS_X = L_Rounding(rxint64(Inpt07.x) / Varb0010) - Varb0008;
   Input.MOUS_Y = L_Rounding(rxint64(Inpt07.y) / Varb0010) - Varb0009;
   if(Inpt07.leftButton){if((++Input.MOUS_Left) == 255ui8) Input.MOUS_Left = 250ui8; Input.MOUS_Left_Release = 0ui8;} else {Input.MOUS_Left = 0ui8; if((++Input.MOUS_Left_Release) == 255ui8) Input.MOUS_Left_Release = 250ui8;}
   if(Inpt07.middleButton){if((++Input.MOUS_Mid) == 255ui8) Input.MOUS_Mid = 250ui8; Input.MOUS_Mid_Release = 0ui8;} else {Input.MOUS_Mid = 0ui8; if((++Input.MOUS_Mid_Release) == 255ui8) Input.MOUS_Mid_Release = 250ui8;}
   if(Inpt07.rightButton){if((++Input.MOUS_Right) == 255ui8) Input.MOUS_Right = 250ui8; Input.MOUS_Right_Release = 0ui8;} else {Input.MOUS_Right = 0ui8; if((++Input.MOUS_Right_Release) == 255ui8) Input.MOUS_Right_Release = 250ui8;}
   if(Input.MOUS_Left == 1){Input.MOUS_X_Left = Input.MOUS_X; Input.MOUS_Y_Left = Input.MOUS_Y;}
   if(Input.MOUS_Mid == 1){Input.MOUS_X_Mid = Input.MOUS_X; Input.MOUS_Y_Mid = Input.MOUS_Y;}
   if(Input.MOUS_Right == 1){Input.MOUS_X_Right = Input.MOUS_X; Input.MOUS_Y_Right = Input.MOUS_Y;}
   return;
  }
  int0 P_EngineFrame(xint64 Vrab01, xint64 Vrab02, uint32 Vrab03, uint32 Vrab04)
  {
   Varb0001 += 1; if(Varb0001 == 0xFFFFFFFFFFFFFFFF) Varb0001 = 0xFFFFFFFFFFFFFF;
   UNREFERENCED_PARAMETER(Vrab01); UNREFERENCED_PARAMETER(Vrab02); UNREFERENCED_PARAMETER(Vrab03);//UNREFERENCED_PARAMETER(Vrab04);

   if(Varb0001 == 1) // Enter LF2 Enchanted.
   {
    Varb0013 = 0; Ench0001 = std::make_unique < HEPTA_LF2_ENCHANTED > (); Varb0017 = true; Ench0001->Load("System\\Interface\\Enchanted\\config.ini");
    Varb0002 = 794; Varb0003 = 550; Game0001->OnWindowSizeChanged(Varb0002, Varb0003);
    SetWindowPos(Game0001->m_deviceResources->GetWindow(), HWND_TOP, CW_USEDEFAULT, CW_USEDEFAULT, static_cast < LONG > (Varb0002 + 16), static_cast < LONG > (Varb0003 + 39), SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
   }

   if(Varb0017)
   {
    switch(Ench0001->Menu)
    {
     case 0: case 3: case 4: case 5: case 6: case 7:
      {
       if(Ench0001->Menu == 0)
       if(Ench0001->Runtime == 0) // Load basic interface.
       {
        ++Ench0001->Runtime;
        {
         Ench0001->Sound_Index.clear(); statics string Temp01 = "System\\Audio\\Music\\"; 
         Ench0001->Sound_Index.push_back(G_SetSound(Temp01 + "main.wav"));                  // Index : 0
        }
        Ench0001->Sprite_Index_Interface.clear(); statics string Temp01 = "System\\Interface\\Enchanted\\"; statics string Temp02 = ".bmp";
        Ench0001->Sprite_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS0" + Temp02, 16, 16, 15, 15));    // Index : 0
        Ench0001->Sprite_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS1" + Temp02, 16, 16, 15, 15));    // Index : 1
        Ench0001->Sprite_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS2" + Temp02, 16, 16, 15, 15));    // Index : 2
        Ench0001->Sprite_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS3" + Temp02, 16, 16, 15, 15));    // Index : 3
        Ench0001->Sprite_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS4" + Temp02, 16, 16, 15, 15));    // Index : 4
        Ench0001->Sprite_Index_Interface.push_back(G_SetSprite(Temp01 + "WORDS5" + Temp02, 16, 16, 15, 15));    // Index : 5
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "LF2_CURSOR" + Temp02));                   // Index : 6
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "LF2_CURSOR2" + Temp02));                  // Index : 7
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP" + Temp02, 0, 0, 794, 37));     // Index : 8  (Copyright)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP" + Temp02, 0, 41, 496, 80));    // Index : 9  (Title)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP5" + Temp02, 0, 0, 280, 180));   // Index : 10 (Buttons)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP" + Temp02, 535, 105, 255, 25)); // Index : 11 (Game Start Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP" + Temp02, 535, 137, 255, 25)); // Index : 12 (Network Game Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP" + Temp02, 535, 169, 255, 25)); // Index : 13 (Control Setting Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP5" + Temp02, 285, 0, 240, 25));  // Index : 14 (Recording Info Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP5" + Temp02, 285, 32, 240, 25)); // Index : 15 (Official Website Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP2" + Temp02, 0, 0, 704, 353));   // Index : 16 (Control Setting)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP" + Temp02, 489, 426, 151, 26)); // Index : 17 (OK Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP" + Temp02, 643, 426, 151, 26)); // Index : 18 (Cancel Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "CS6" + Temp02, 0, 0, 106, 91));           // Index : 19 (Input Keyboard)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "CS2" + Temp02, 0, 0, 106, 91));           // Index : 20 (Input Joy1)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "CS3" + Temp02, 0, 0, 106, 91));           // Index : 21 (Input Joy2)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "CS4" + Temp02, 0, 0, 106, 91));           // Index : 22 (Input Joy3)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "CS5" + Temp02, 0, 0, 106, 91));           // Index : 23 (Input Joy4)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP5" + Temp02, 528, 0, 240, 25));  // Index : 24 (Game Setting Button)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP5" + Temp02, 528, 32, 240, 25)); // Index : 25 (Official Website Button2)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 0, 0, 12, 12));       // Index : 26 (Info Bar Top-Left Corner)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 13, 0, 12, 12));      // Index : 27 (Info Bar Top-Right Corner)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 0, 13, 12, 12));      // Index : 28 (Info Bar Bottom-Left Corner)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 13, 13, 12, 12));     // Index : 29 (Info Bar Bottom-Right Corner)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 12, 0, 1, 3));        // Index : 30 (Info Bar Horizontal Corner)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR" + Temp02, 0, 12, 3, 1));        // Index : 31 (Info Bar Vertical Corner)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "INFO_BAR2" + Temp02, 0, 0, 200, 200));    // Index : 32 (Info Bar Area)
        Ench0001->Sprite_Index_Interface.push_back(G_SetPic(Temp01 + "MENU_CLIP2" + Temp02, 495, 354, 151, 26));// Index : 33 (Ok Button)

        //G_SetMusic(Ench0001->Sound_Index[0], Varb0012);
       }
       G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, 794, 550);
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[8], 0, 505);
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[9], 397 - 248, 65);
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[10], 397 - 130, 175);
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[25], 283, 346);

       if(Ench0001->Menu == 0)
       {
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, 397 - 80, 192, 160, 20)){G_SetDisplay(2, Ench0001->Sprite_Index_Interface[11], 281, 188); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 397 - 80, 192, 160, 20) && Input.MOUS_Left_Release == 1){Ench0001->Menu = 3; Ench0001->Runtime = 0; Ench0001->Runtime3 = 55;}}
        //if(L_Within(Input.MOUS_X, Input.MOUS_Y, 397 - 80, 244, 160, 20)) G_SetDisplay(2, Ench0001->Sprite_Index_Interface[12], 281, 240);
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, 397 - 80, 256, 160, 20)){G_SetDisplay(2, Ench0001->Sprite_Index_Interface[13], 281, 252); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 397 - 80, 256, 160, 20) && Input.MOUS_Left_Release == 1){Ench0001->Menu = 1; Ench0001->Runtime = 0; Ench0001->Runtime2 = 0; Ench0001->Runtime3 = 0; Ench0001->Config[1] = Ench0001->Config[0];}}
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, 397 - 80, 288, 160, 20)) G_SetDisplay(2, Ench0001->Sprite_Index_Interface[24], 283, 282);
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, 397 - 80, 320, 160, 20)) G_SetDisplay(2, Ench0001->Sprite_Index_Interface[14], 283, 314);
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, 397 - 80, 352, 160, 20)){G_SetDisplay(2, Ench0001->Sprite_Index_Interface[15], 283, 346); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 397 - 80, 352, 160, 20) && Input.MOUS_Left_Release == 1) ShellExecute(0, 0, L"http://www.lf2.net", 0, 0, SW_SHOW);}
        break;
       }
       if(Ench0001->Menu == 3)
       {
        G_SetDisplay(0, 0x0, 0, 0, 0, ruint8(Ench0001->Runtime += 3), 794, 550);
        Ench0001->Info_Bar(842 - (Ench0001->Runtime2), 275, 100, 0);
        Ench0001->Runtime2 += (Ench0001->Runtime3 / 3); Ench0001->Runtime3 -= 1;
        if(Ench0001->Runtime3 == 0){Ench0001->Menu = 4; Ench0001->Runtime2 = 0; Ench0001->Runtime3 = 30;}
        break;
       }
       if(Ench0001->Menu == 4)
       {
        statics int64 Vrab05 = L_Rounding(rxint64(Ench0001->Runtime2) / 2);
        statics int64 Vrab06 = L_Rounding(rxint64(Ench0001->Runtime2) / 4);
        G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, 794, 550);
        Ench0001->Info_Bar(842 - 495 - Vrab05, 275 - Vrab06, 100 + (Vrab05 * 2), Vrab05);
        Ench0001->Runtime2 += (Ench0001->Runtime3 / 3); Ench0001->Runtime3 -= 1;
        if(Ench0001->Runtime3 == 0){Ench0001->Menu = 5; Ench0001->Runtime = 0; Ench0001->Runtime2 = 0;}
        break;
       }
       if(Ench0001->Menu == 5)
       {
        if(Ench0001->Runtime == 0)
        {
         Ench0001->String_Load = Ench0001->String_Load2 = "<none>";
         Ench0001->File.open("data\\data.txt");
         if(!Ench0001->File.is_open()){Ench0001->String = "Either \"data.txt\" cannot be found or it's inaccessible."; Ench0001->Menu = 6; Ench0001->Runtime = ruint64(-1); Ench0001->Runtime2 = 0; Ench0001->Runtime3 = 34;}
        }
        Ench0001->Runtime += 1; if(Ench0001->Runtime == 0xFFFFFFFFFFFFFFFF) Ench0001->Runtime = 0xFFFFFFFFFFFFFFFE;
        statics int64 Vrab05 = L_Rounding(145.0 / 2);
        statics int64 Vrab06 = L_Rounding(145.0 / 4);
        G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, 794, 550);
        Ench0001->Info_Bar(842 - 495 - Vrab05, 275 - Vrab06, 100 + (Vrab05 * 2), Vrab05);
        string Temp01 = "Loading data(s)"; statics uint64 Vrab07 = Ench0001->Runtime % 80; if(Vrab07 / 20 > 0) Temp01.push_back('.'); if(Vrab07 / 40 > 0) Temp01.push_back('.'); if(Vrab07 / 60 > 0) Temp01.push_back('.');
        Ench0001->PrintText(842 - 492 - rint32(Vrab05), 275 - rint32(Vrab06), 0, Temp01);
        string Temp02 = Ench0001->String_Load; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
        Ench0001->PrintText(842 - 492 - rint32(Vrab05), 313 - rint32(Vrab06), 0, Temp02);
        string Temp03 = Ench0001->String_Load2; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
        Ench0001->PrintText(842 - 493 + 243 - rint32(Vrab05) - (Temp03.size() * 9), 332 - rint32(Vrab06), 0, Temp03);
        break;
       }
       if(Ench0001->Menu == 6)
       {
        statics int64 Vrab05 = L_Rounding(145.0 / 2);
        statics int64 Vrab06 = L_Rounding(145.0 / 4);
        G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, 794, 550);
        Ench0001->Info_Bar(842 - 495 - Vrab05, 275 - Vrab06, 100 + (Vrab05 * 2), Vrab05);
        string Temp01 = "Loading data(s)...";
        Ench0001->PrintText(842 - 492 - rint32(Vrab05), 275 - rint32(Vrab06), 0, Temp01);
        string Temp02 = Ench0001->String_Load; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
        Ench0001->PrintText(842 - 492 - rint32(Vrab05), 313 - rint32(Vrab06), 0, Temp02);
        string Temp03 = Ench0001->String_Load2; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
        Ench0001->PrintText(842 - 493 + 243 - rint32(Vrab05) - (Temp03.size() * 9), 332 - rint32(Vrab06), 0, Temp03);
        
        Ench0001->Info_Bar(392 - L_Rounding(rxint64(Ench0001->String.size() - 1) * 4.5), 575 - Vrab06 - Ench0001->Runtime2, Ench0001->String.size() * 9, Vrab05 + 6);
        Ench0001->PrintText(392 - L_Rounding(rxint64(Ench0001->String.size() - 1) * 4.5), 575 - Vrab06 - Ench0001->Runtime2, 0, Ench0001->String);
        Ench0001->PrintText(392 - L_Rounding(rxint64(Ench0001->String.size() - 1) * 4.5), 594 - Vrab06 - Ench0001->Runtime2, 0, Ench0001->String);
        G_SetDisplay(2, Ench0001->Sprite_Index_Interface[33], 392 - 70, 624 - Vrab06 - Ench0001->Runtime2);

        Ench0001->Runtime2 += (Ench0001->Runtime3 / 3); Ench0001->Runtime3 -= 1;
        if(Ench0001->Runtime3 == 0){Ench0001->Menu = 7; Ench0001->Runtime3 = 0;}
        break;
       }
       if(Ench0001->Menu == 7)
       {
        statics int64 Vrab05 = L_Rounding(145.0 / 2);
        statics int64 Vrab06 = L_Rounding(145.0 / 4);
        G_SetDisplay(0, 0x0, 0, 0, 0, 165ui8, 794, 550);
        Ench0001->Info_Bar(842 - 495 - Vrab05, 275 - Vrab06, 100 + (Vrab05 * 2), Vrab05);
        string Temp01 = "Loading data(s)...";
        Ench0001->PrintText(842 - 492 - rint32(Vrab05), 275 - rint32(Vrab06), 0, Temp01);
        string Temp02 = Ench0001->String_Load; if(Temp02.size() > 25){Temp02 = string(Temp02, Temp02.size() - 25, 25); Temp02.at(0) = Temp02.at(1) = Temp02.at(2) = '.';} Temp02 += " :";
        Ench0001->PrintText(842 - 492 - rint32(Vrab05), 313 - rint32(Vrab06), 0, Temp02);
        string Temp03 = Ench0001->String_Load2; if(Temp03.size() > 26){Temp03 = string(Temp03, Temp03.size() - 26, 26); Temp03.at(0) = Temp03.at(1) = Temp03.at(2) = '.';}
        Ench0001->PrintText(842 - 493 + 243 - rint32(Vrab05) - (Temp03.size() * 9), 332 - rint32(Vrab06), 0, Temp03);
        
        Ench0001->Info_Bar(392 - L_Rounding(rxint64(Ench0001->String.size() - 1) * 4.5), 575 - Vrab06 - Ench0001->Runtime2, Ench0001->String.size() * 9, Vrab05 + 6);
        Ench0001->PrintText(392 - L_Rounding(rxint64(Ench0001->String.size() - 1) * 4.5), 575 - Vrab06 - Ench0001->Runtime2, 0, Ench0001->String);
        Ench0001->PrintText(392 - L_Rounding(rxint64(Ench0001->String.size() - 1) * 4.5), 594 - Vrab06 - Ench0001->Runtime2, 0, Ench0001->String);
        G_SetDisplay(2, Ench0001->Sprite_Index_Interface[33], 392 - 70, 624 - Vrab06 - Ench0001->Runtime2);

        Ench0001->PrintText(3, 15, 0, std::to_string(Ench0001->Runtime2));
        break;
       }
      }
     break;
     case 1:
      {
       G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, 794, 550);
       if(Ench0001->Runtime3 < 6){Ench0001->Runtime += Ench0001->Runtime2;} else {Ench0001->Runtime -= Ench0001->Runtime2;} if(Ench0001->Runtime3 % 6 == 0){Ench0001->Runtime2 += 1;} if(Ench0001->Runtime3 % 6 == 3){Ench0001->Runtime2 -= 1;} if(Ench0001->Runtime2 == 14){Ench0001->Runtime3 += 3; Ench0001->Runtime2 -= 1;} if(Ench0001->Runtime3 % 3 != 2){Ench0001->Runtime3 += 1;} else {Ench0001->Runtime3 -= 2;}
       
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[8], 0, 505 - (Ench0001->Runtime));
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[9], 397 - 248, 65 - (Ench0001->Runtime));
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[10], 397 - 130, 175 - (Ench0001->Runtime));
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[25], 283, 346 - (Ench0001->Runtime));
       
       if(Ench0001->Runtime3 < 6)
       {if(Ench0001->Runtime2 == ruint64(-1)){Ench0001->Runtime2 = 0; Ench0001->Runtime3 = 0; Ench0001->Menu = 2;}} else
       {if(Ench0001->Runtime2 == ruint64(-1)){Ench0001->Runtime = 1; Ench0001->Runtime2 = 0; Ench0001->Runtime3 = 0; Ench0001->Menu = 0;}}

       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[16], 397 - 352, 85 - (Ench0001->Runtime) + 550);
       for(uint32 Vrab05 = 0; Vrab05 < 4; ++Vrab05)
       {
        if(Ench0001->Config[1].P_Name[Vrab05] == "") Ench0001->Config[1].P_Name[Vrab05] = "P" + std::to_string(Vrab05 + 1);
        Ench0001->PrintText(247 + (139 * Vrab05) - L_Rounding(rxint64(Ench0001->Config[1].P_Name[Vrab05].size()) * 4.5), 124 - rint32(Ench0001->Runtime) + 547, 0, Ench0001->Config[1].P_Name[Vrab05]);
        G_SetDisplay(2, Ench0001->Sprite_Index_Interface[19 + Ench0001->Config[1].P_Con[Vrab05]], 193 + (rint64(139) * Vrab05), 149 - rint32(Ench0001->Runtime) + 547);
        uint32 Vrab08 = 0; if(Ench0001->Config[1].P_Con[Vrab05] != 0) Vrab08 = 7;
        for(uint32 Vrab06 = Vrab08; Vrab06 < Vrab08 + 7; ++Vrab06)
        {
         statics string Temp01 = Ench0001->InputName(Ench0001->Config[1].P_Input[Vrab05][Vrab06]);
         Ench0001->PrintText(247 + (139 * Vrab05) - L_Rounding(rxint64(Temp01.size()) * 4.5), 248 + (22 * (Vrab06 - Vrab08)) - rint32(Ench0001->Runtime) + 547, 0, Temp01);
        }
       }
      }
     break;
     case 2:
      {
       G_SetDisplay(0, 0x10206C, 0, 0, 0, 255ui8, 794, 550);
       G_SetDisplay(2, Ench0001->Sprite_Index_Interface[16], 397 - 352, 85 + 3);
       if(L_Within(Input.MOUS_X, Input.MOUS_Y, 407, 408, 151, 26)){G_SetDisplay(2, Ench0001->Sprite_Index_Interface[17], 407, 408); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 407, 408, 151, 26) && Input.MOUS_Left_Release == 1){Ench0001->Config[0] = Ench0001->Config[1]; Ench0001->Save("System\\Interface\\Enchanted\\config.ini"); Ench0001->Runtime2 = 0; Ench0001->Runtime3 = 6; Ench0001->Menu = 1;}}
       if(L_Within(Input.MOUS_X, Input.MOUS_Y, 579, 408, 151, 26)){G_SetDisplay(2, Ench0001->Sprite_Index_Interface[18], 579, 408); if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 579, 408, 151, 26) && Input.MOUS_Left_Release == 1){Ench0001->Runtime2 = 0; Ench0001->Runtime3 = 6; Ench0001->Menu = 1;}}
      
       for(uint32 Vrab05 = 0; Vrab05 < 4; ++Vrab05)
       {
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, 193 + (rint64(139) * Vrab05),  124, 106, 19))
        if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 193 + (rint64(139) * Vrab05),  124, 106, 19) && Input.MOUS_Left_Release == 1)
        {statics auto Vrab07 = ruint64(Vrab05) + 1; if(Ench0001->Runtime2 == Vrab07){Ench0001->Runtime2 = 0;} else {Ench0001->Runtime2 = Vrab07;}}

        if(Ench0001->Runtime2 == ruint64(Vrab05) + 1)
        {L_Typing(Ench0001->Config[1].P_Name[Vrab05]); if(Ench0001->Config[1].P_Name[Vrab05].size() > 100) Ench0001->Config[1].P_Name[Vrab05].resize(100); Ench0001->PrintText(247 + (139 * Vrab05) - L_Rounding(rxint64(Ench0001->Config[1].P_Name[Vrab05].size()) * 4.5), 124, 1, Ench0001->Config[1].P_Name[Vrab05]);} else
        {
         if(Ench0001->Config[1].P_Name[Vrab05] == "") Ench0001->Config[1].P_Name[Vrab05] = "P" + std::to_string(Vrab05 + 1);
         Ench0001->PrintText(247 + (139 * Vrab05) - L_Rounding(rxint64(Ench0001->Config[1].P_Name[Vrab05].size()) * 4.5), 124, 0, Ench0001->Config[1].P_Name[Vrab05]);
        }
        
        if(L_Within(Input.MOUS_X, Input.MOUS_Y, 193 + (rint64(139) * Vrab05),  149, 106, 91))
        if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 193 + (rint64(139) * Vrab05),  149, 106, 91) && Input.MOUS_Left_Release == 1)
        {Ench0001->Config[1].P_Con[Vrab05] += 1; Ench0001->Config[1].P_Con[Vrab05] %= 5;}

        G_SetDisplay(2, Ench0001->Sprite_Index_Interface[19 + Ench0001->Config[1].P_Con[Vrab05]], 193 + (rint64(139) * Vrab05), 149);
        uint32 Vrab08 = 0; if(Ench0001->Config[1].P_Con[Vrab05] != 0) Vrab08 = 7;
        for(uint32 Vrab06 = Vrab08; Vrab06 < Vrab08 + 7; ++Vrab06)
        {
         statics string Temp01 = Ench0001->InputName(Ench0001->Config[1].P_Input[Vrab05][Vrab06]);

         if(L_Within(Input.MOUS_X, Input.MOUS_Y, 193 + (rint64(139) * Vrab05),  248 + (22 * (Vrab06 - Vrab08)), 106, 19))
         if(L_Within(Input.MOUS_X_Left, Input.MOUS_Y_Left, 193 + (rint64(139) * Vrab05),  248 + (22 * (Vrab06 - Vrab08)), 106, 19) && Input.MOUS_Left_Release == 1)
         {statics auto Vrab07 = (ruint64(Vrab05) * 7) + 5 + (Vrab06 - Vrab08); if(Ench0001->Runtime2 == Vrab07){Ench0001->Runtime2 = 0;} else {Ench0001->Runtime2 = Vrab07;}}

         if(Ench0001->Runtime2 == (ruint64(Vrab05) * 7) + 5 + (Vrab06 - Vrab08))
         {Ench0001->PrintText(247 + (139 * Vrab05) - L_Rounding(rxint64(Temp01.size()) * 4.5), 248 + (22 * (Vrab06 - Vrab08)), 1, Temp01); statics uint8 Vrab07 = L_Press(); if(Vrab07 != 255ui8){Ench0001->Config[1].P_Input[Vrab05][Vrab06] = Vrab07; Ench0001->Runtime2 = 0;}} else
         {Ench0001->PrintText(247 + (139 * Vrab05) - L_Rounding(rxint64(Temp01.size()) * 4.5), 248 + (22 * (Vrab06 - Vrab08)), 0, Temp01);}
        }
       }
      }
     break;
     default: Varb0017 = false; break;
    }
    
    if(Input.MOUS_X == Ench0001->Mouse_X && Input.MOUS_Y == Ench0001->Mouse_Y){if((++Ench0001->Mouse_Standby) == 255ui8) Ench0001->Mouse_Standby = 254ui8;} else {Ench0001->Mouse_Standby = 0ui8;}
    if(Ench0001->Mouse_Standby < 150ui8){ShowCursor(TRUE); G_SetDisplay(2, Ench0001->Sprite_Index_Interface[6], Input.MOUS_X - 3ull, Input.MOUS_Y - 3ull);} else {if(Ench0001->Mouse_Standby == 153ui8){ShowCursor(FALSE); SetCursor(NULL);}}
    Ench0001->Mouse_X = Input.MOUS_X; Ench0001->Mouse_Y = Input.MOUS_Y;
    if(Input.MOUS_Left >= 1)
    {
     int64 Vrab05 = Input.MOUS_X; int64 Vrab06 = Input.MOUS_Y;
     int64 Vrab07 = Input.MOUS_X_Left; int64 Vrab08 = Input.MOUS_Y_Left;
     if(Vrab07 < Vrab05){Vrab05 = Vrab07; Vrab07 = Input.MOUS_X;}
     if(Vrab08 < Vrab06){Vrab06 = Vrab08; Vrab08 = Input.MOUS_Y;}
     Vrab07 -= Vrab05; Vrab08 -= Vrab06;
     if(Vrab07 > 10 || Vrab08 > 10)
     G_SetDisplay(1, 0xFF00, Vrab05, Vrab06, 0, 255ui8, Vrab07, Vrab08);
     if(Vrab07 > 2 && Vrab08 > 2)
     G_SetDisplay(0, 0x00FF00, Vrab05 + 1, Vrab06 + 1, 0, 50ui8, Vrab07 - 2, Vrab08 - 2);
    }
    Ench0001->PrintText(3, 0, 0, std::to_string(Vrab04));
    G_SetDisplay(0, 0x0, -794, -550, 0, 255ui8, 794, 1650); G_SetDisplay(0, 0x0, 794, -550, 0, 255ui8, 794, 1650); G_SetDisplay(0, 0x0, 0, 550, 0, 255ui8, 794, 550); G_SetDisplay(0, 0x0, 0, -550, 0, 255ui8, 794, 550);
   }






    /*remains int1 Vrab05 = true;
    statics string Temp01 = "System\\Interface\\Enchanted\\";
    if(Vrab05)
    {
     Vrab05 = false; insize Vrab06 = 1; insize Vrab07 = rinsize(-1); Vect1001.clear(); Vect1001.push_back(0);
     while((Vrab07 = G_SetSprite(Temp01 + "BACK" + std::to_string(Vrab06) + ".bmp", 1, 1, Varb0002, Varb0003)) != rinsize(-1))
     {
      Vrab06 += 1; Vect1001.push_back(Vrab07);
     }
     Vect1001[0] = Vrab06 - 1;
     Vect1002[0] = L_Random(Vect1001[0]);
    }
    G_SetDisplay(2, Vect1001[rinsize(Vect1002[0]) + 1 + (Varb0001 % Vect1001[0])], 0, 0);
    std::ofstream OP("DSAD.txt"); OP << Vect1001[0] << " " << Vect1002[0] << " " << Vect1001[1] << " : " << Input.MOUS_X << " " << Input.MOUS_Y << (Temp01 + "BACK" + std::to_string(13) + ".bmp"); OP.close();
   }
  }
 //-//*/

























//Memory / Variables
/*
 struct E_INPUT {
 uint8 MAIN_1;
 uint8 MAIN_2;
 uint8 MAIN_3;
 uint8 MAIN_4;
 uint8 MAIN_5;
 uint8 MAIN_6;
 uint8 MAIN_7;
 uint8 MAIN_8;
 uint8 MAIN_9;
 uint8 MAIN_0;
 uint8 MAIN_A;
 uint8 MAIN_B;
 uint8 MAIN_C;
 uint8 MAIN_D;
 uint8 MAIN_E;
 uint8 MAIN_F;
 uint8 MAIN_G;
 uint8 MAIN_H;
 uint8 MAIN_I;
 uint8 MAIN_J;
 uint8 MAIN_K;
 uint8 MAIN_L;
 uint8 MAIN_M;
 uint8 MAIN_N;
 uint8 MAIN_O;
 uint8 MAIN_P;
 uint8 MAIN_Q;
 uint8 MAIN_R;
 uint8 MAIN_S;
 uint8 MAIN_T;
 uint8 MAIN_U;
 uint8 MAIN_V;
 uint8 MAIN_W;
 uint8 MAIN_X;
 uint8 MAIN_Y;
 uint8 MAIN_Z;
 uint8 CORE_ESC;
 uint8 CORE_F1;
 uint8 CORE_F2;
 uint8 CORE_F3;
 uint8 CORE_F4;
 uint8 CORE_F5;
 uint8 CORE_F6;
 uint8 CORE_F7;
 uint8 CORE_F8;
 uint8 CORE_F9;
 uint8 CORE_F10;
 uint8 CORE_F11;
 uint8 CORE_F12;
 uint8 CORE_PSCREEN;
 uint8 CORE_DELETE;
 uint8 CORE_BACKSPACE;
 uint8 CORE_TAB;
 uint8 CORE_CAPSLOCK;
 uint8 CORE_ENTER;
 uint8 CORE_LSHIFT;
 uint8 CORE_RSHIFT;
 uint8 CORE_LCTRL;
 uint8 CORE_RCTRL;
 uint8 CORE_LALT;
 uint8 CORE_RALT;
 uint8 CORE_LWIN;
 uint8 CORE_RWIN;
 uint8 CORE_UP;
 uint8 CORE_LEFT;
 uint8 CORE_DOWN;
 uint8 CORE_RIGHT;
 uint8 NUMS_1;
 uint8 NUMS_2;
 uint8 NUMS_3;
 uint8 NUMS_4;
 uint8 NUMS_5;
 uint8 NUMS_6;
 uint8 NUMS_7;
 uint8 NUMS_8;
 uint8 NUMS_9;
 uint8 NUMS_0;
 uint8 NUMS_ENTER;
 uint8 NUMS_INSERT;
 uint8 NUMS_DELETE;
 uint8 NUMS_NUMLOCK;
 uint8 NUMS_ADD;
 uint8 NUMS_SUB;
 uint8 NUMS_SLASH;
 uint8 NUMS_MULTIPLE;
 uint8 NUMS_DOT;
 uint8 SYMB_BACKTICK;
 uint8 SYMB_UNDERSCORE;
 };

 // Non-Basic
  E_INPUT Input;                  // Inputs
  string Text0001;                   // Language Text
  std::ifstream File0001;            // -
  std::ofstream File0002;            // -

 // Basic
  uint64 Varb0001 = 0;               // App Runtime
  uint32 Varb0002 = 800;             // Display W
  uint32 Varb0003 = 600;             // Display H
  uint8 Varb0004 = 1;                // FPS Ratio
  int1 Varb0005 = true;              // Keep aspect ratio?
  int1 Varb0006 = true;              // Limit displayed resolution if window's resolution is higher than display's resolution?
  int1 Varb0007 = false;             // Update Display?
  int1 Varb0008 = false;              // CPU Graphing?

 // Temporals (Process-Wise)
  std::vector < uint32 > Vect0001;   // Random Accessed Vector

//-//
//Dynamic Memory / Variables
 struct COLOUR {uint8 Red; uint8 Green; uint8 Blue; uint8 Trans;};
 struct DISPLAY {uint8 Type; insize Target; int32 Post_X1; int32 Post_Y1; uint8 Effect; uint8 Trans; string Text; int32 Post_X2; int32 Post_X3; int32 Post_X4; int32 Post_Y2; int32 Post_Y3; int32 Post_Y4;};
 struct SPRITE {insize BMP; uint32 W; uint32 H; uint32 Row; insize Zeroth;};
 struct OBJ_DATA_ID {int1 Exist = false; int1 Loaded = false; uint8 Type = 255; string Address = ""; insize PropertyAdd; insize FrameNum; insize FrameAdd; insize GuideAdd;};
 struct OBJ_DATA_PR {string Name; insize Face; insize Small; insize PicNum; insize PicAdd; uint32 MaxHP; uint32 MovementSpeed; xint64 Weight; uint8 Speciality[15]; insize StartingFrame;};
 struct OBJ_DATA_PP {insize Address; uint32 W; uint32 H; uint32 Row; uint32 Col;};
 struct OBJ_DATA_FM {insize Number; int8 FType; uint32 State; uint32 State2; uint32 State3; uint32 CenterX; uint32 CenterY; uint32 Wait; insize Next; uint32 Vx; uint32 Vy; uint32 Vz; uint8 InputType[18]; insize InputFrame[18]; insize Sound; uint32 MP; int1 HeldA; insize HeldAAdd; int1 HeldB; insize HeldBAdd; int1 Catch; insize CatchAdd; int1 Body; insize BodyAdd; insize SpointNum; insize SpointAdd; insize BpointNum; insize BpointAdd; insize FpointNum; insize FpointAdd; insize IpointNum; insize IpointAdd; insize RpointNum; insize RpointAdd; insize OpointNum; insize OpointAdd;};
 struct OBJ_DATA_FD {uint8 Kind; uint32 X; uint32 Y; uint32 W; uint32 H; uint16 Rotate;};
 struct OBJ_DATA_FA {uint8 kind; uint32 X; uint32 Y; uint32 Z; insize Action; insize Velocity;};
 struct OBJ_DATA_FH {uint8 kind; uint32 X; uint32 Y; uint32 Z; insize Action; insize Velocity;};
 struct OBJ_DATA_FC {};
 struct OBJ_DATA_FS {};
 struct OBJ_DATA_FF {};
 struct OBJ_DATA_FB {};
 struct OBJ_DATA_FI {};
 struct OBJ_DATA_FR {};
 struct OBJ_DATA_FO {};
 struct OBJ_DATA_GD {};
 
 std::vector < std::vector < COLOUR > > Display;
 std::vector < DISPLAY > DisplayStack;

 std::vector < SPRITE > Sprite;
 std::vector < insize > Sprite_Index;

 std::vector < COLOUR > BMP_Color;
 std::vector < insize > BMP_Index;
 std::vector < uint32 > BMP_Width;
 std::vector < uint32 > BMP_Height;
 std::vector < string > BMP_Address;
 
 std::vector < OBJ_DATA_ID > DATA_ID;           // -
 std::vector < OBJ_DATA_PR > DATA_Property;     // +>> (+0)Name; (+1)Face; (+2)Small; (+3)Pic_Num; (+4)Pic_Add; (+5)MaxHP; (+6)MovementSpeed; (+7)Weight; (+8 - +22)Speciality; (+23)StartingFrame;
 std::vector < OBJ_DATA_PP > DATA_Property_Pic; // +>> (+0)Address; (+1)W; (+2)H; (+3)Row; (+4)Col;
 std::vector < OBJ_DATA_FM > DATA_Frame;        // +>> (+0)Number; (+1)FType; (+2)State; (+3)State2; (+4)State3; (+5)CenterX; (+6)CenterY; (+7)Wait; (+8)Next; (+9)Vx; (+10)Vy; (+11)Vz; (+12 - +29)in_##; (+30)Sound; (+31)MP; (+32)HeldA; (+33)HeldA_Add; (+34)HeldB; (+35)HeldB_Add; (+36)Catch; (+37)Catch_Add; (+38)Body; (+39)Body_Add; (+40)SPoint_Num; (+41)SPoint_Add; (+42)BPoint_Num; (+43)BPoint_Add; (+44)FPoint_Num; (+45)FPoint_Add; (+46)IPoint_Num; (+47)IPoint_Add; (+48)RPoint_Num; (+49)RPoint_Add; (+50)OPoint_Num; (+51)OPoint_Add;
 std::vector < OBJ_DATA_FD > DATA_Frame_Body;   // +>> (+0)Kind; (+1)X; (+2)Y; (+3)W; (+4)H; (+5)Rotate;
 std::vector < OBJ_DATA_FA > DATA_Frame_HeldA;  // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)Action; (+5)Attack;
 std::vector < OBJ_DATA_FH > DATA_Frame_HeldB;  // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)Action; (+5)Attack;
 std::vector < OBJ_DATA_FC > DATA_Frame_Catch;  // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)Action; (+5)Hurt_Act;
 std::vector < OBJ_DATA_FS > DATA_Frame_SPoint; // +>> (+0)Pic; (+1)X1; (+2)Y1; (+3)X2; (+4)Y2; (+5)X3; (+6)Y3; (+7)X4; (+8)Y4; (+9)Trans;
 std::vector < OBJ_DATA_FF > DATA_Frame_FPoint; // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z;
 std::vector < OBJ_DATA_FB > DATA_Frame_BPoint; // +>> (+0)X; (+1)Y;
 std::vector < OBJ_DATA_FI > DATA_Frame_IPoint; // +>> (+0)Dimension; (+1)X; (+2)Y; (+3)Z; (+4)W; (+5)H; (+6)L; (+7)Shape; (+8)X_Rot; (+9)Y_Rot; (+10)Z_Rot (+11)Kind; ...
 std::vector < OBJ_DATA_FR > DATA_Frame_RPoint; // +>> (+0)Dimension; (+1)X; (+2)Y; (+3)Z; (+4)W; (+5)H; (+6)L; (+7)Shape;
 std::vector < OBJ_DATA_FO > DATA_Frame_OPoint; // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)ID; (+5)Action;
 std::vector < OBJ_DATA_GD > DATA_Guide;        // -

 std::vector < insize > INDEX_Language;     // -
 std::vector < insize > INDEX_Frame;        // -
//-//
// Light Functions
 int1   L_Open(const string &Temp01)            {if(File0001.is_open()) File0001.close(); File0001.open(Temp01, std::ios::binary | std::ios::in); if(File0001.is_open()) return true; return false;}
 int1   L_Exist(const string &Temp01)  fastened {struct stat Vrab01; return (stat(Temp01.c_str(), &Vrab01) == 0);}
 int1   L_Create(const string &Temp01)          {if(File0002.is_open()) File0002.close(); File0002.open(Temp01, std::ios::binary | std::ios::out); if(File0002.is_open()) return true; return false;}
 int1   L_SetLang(uint8 Vrab01)        fastened {switch(Vrab01){case 0: if(!L_Open(HEPTA_LOCATION_LANG_EN)) return false; break; case 1: if(!L_Open(HEPTA_LOCATION_LANG_ID)) return false; break; case 2: if(!L_Open(HEPTA_LOCATION_LANG_CN)) return false; break; case 3: if(!L_Open(HEPTA_LOCATION_LANG_CN2)) return false; break; case 4: if(!L_Open(HEPTA_LOCATION_LANG_RU)) return false; break; case 5: if(!L_Open(HEPTA_LOCATION_LANG_JP)) return false; break; default: return false;} stream Strn01; Strn01 << File0001.rdbuf(); File0001.close(); const string Temp01 = Strn01.str(); INDEX_Language.clear(); INDEX_Language.resize(0); Text0001 = ""; const insize Vrab03 = Temp01.length(); insize Vrab04 = 0; insize Vrab05 = 0; insize Vrab06 = 0; while(Vrab04 < Vrab03){if(Temp01[Vrab04] == '<') if(Temp01[Vrab04 + 1] == '/') if(Temp01[Vrab04 + 2] == '>'){Labl01: Vrab04 += 3; INDEX_Language.push_back(Vrab05); Vrab06 = 0; while(Temp01[Vrab04 + Vrab06] == ' ') Vrab06 += 1; if(Temp01[Vrab04 + Vrab06] == '\n'){Vrab06 += 1; Vrab04 += Vrab06;} else {if(Temp01[Vrab04 + Vrab06] == '/') if(Temp01[Vrab04 + Vrab06 + 1] == '/'){while(Temp01[Vrab04 + Vrab06 + 2] != '\n') Vrab06 += 1; Vrab06 += 3; Vrab04 += Vrab06;}}} if(Temp01[Vrab04] == '/') if(Temp01[Vrab04 + 1] == '/'){Labl02: Vrab04 += 2; while(Temp01[Vrab04] != '\n') Vrab04 += 1;} if(Temp01[Vrab04] == '\n'){Vrab06 = 1; while(Temp01[Vrab04 + Vrab06] == '\n') Vrab06 += 1; if(Temp01[Vrab04 + Vrab06] == '<') if(Temp01[Vrab04 + Vrab06 + 1] == '/') if(Temp01[Vrab04 + Vrab06 + 2] == '>'){Vrab04 += Vrab06; goto Labl01;}} if(Temp01[Vrab04] == ' '){Vrab06 = 1; while(Temp01[Vrab04 + Vrab06] == ' ') Vrab06 += 1; if(Temp01[Vrab04 + Vrab06] == '/') if(Temp01[Vrab04 + Vrab06 + 1] == '/'){Vrab04 += Vrab06; goto Labl02;}} Text0001 += Temp01[Vrab04]; Vrab05 += 1; Vrab04 += 1;} return true;}
 string L_GetLang(insize Vrab01)       fastened {if(Vrab01 >= INDEX_Language.size()) return "[ERROR]"; string Temp01 = ""; for(insize Vrab02 = INDEX_Language[Vrab01]; Vrab02 < INDEX_Language[Vrab01 + 1]; ++Vrab02) Temp01 += Text0001[Vrab02]; return Temp01;}
 string L_Lowercase(string Temp01)     fastened {insize Vrab01 = Temp01.size(); while(Vrab01 != 0){Vrab01 -= 1; if(Temp01.at(Vrab01) >= 'A' && Temp01.at(Vrab01) <= 'Z') Temp01.at(Vrab01) += 32;} return Temp01;}
 string L_Execute(const string Temp01)          {string Temp02 = Temp01; uint32 Vrab01 = Temp02.size() - 1; while(Vrab01 != 0 && Temp02.at(Vrab01) != '\\') Vrab01 -= 1; if(Vrab01 > 0) Temp02.erase(Vrab01, Temp02.size() - Vrab01); std::filesystem::create_directories(Temp02); return Temp01;}
  
 int32 INT32Rounding(xint64 Vrab01){if(rint64(Vrab01) == rxint64(rint64(Vrab01 + 0.5))) return rint32(Vrab01); return rint32(Vrab01) + 1;}
 int64 INT64Rounding(xint64 Vrab01){if(rint64(Vrab01) == rxint64(rint64(Vrab01 + 0.5))) return rint64(Vrab01); return rint64(Vrab01) + 1;}
 xint64 XINT64Rounding(xint64 Vrab01){if(rint64(Vrab01) == rxint64(rint64(Vrab01 + 0.5))) return Vrab01; return Vrab01 + 1;}
 xint64 RatioLeft(xint64 Vrab01){return Vrab01 - rxint64(rint64(Vrab01));}
 xint64 RatioRight(xint64 Vrab01){return 1 - (Vrab01 - rxint64(rint64(Vrab01)));}
//-//
// Core Functions
 int0   C_BMP_Clear()                    fastened {BMP_Color.clear(); BMP_Index.clear(); BMP_Width.clear(); BMP_Height.clear(); BMP_Address.clear();}
 insize C_BMP_Load(const string &Temp01) fastened
 {
  string Temp02 = L_Lowercase(Temp01);
  {
   const insize Vrab01 = BMP_Address.size(); insize Vrab02 = 0; while(Vrab01 != Vrab02){if(Temp02 == BMP_Address[Vrab02]) return Vrab02; Vrab02 += 1;}
  }
  BMP Bitm01(Temp01.c_str()); const insize Vrab01 = Bitm01.bmp_info_header.width * Bitm01.bmp_info_header.height; if(Bitm01.bmp_info_header.compression != 3 && Bitm01.bmp_info_header.bit_count != 3 && Bitm01.bmp_info_header.size_image != 0 && Bitm01.data.size() != Vrab01 * 3) return rinsize(-1);
  const insize Vrab02 = Bitm01.data.size(); insize Vrab03 = rinsize(-1); const insize Vrab04 = BMP_Color.size(); insize Vrab05 = 0; const insize Vrab06 = Bitm01.bmp_info_header.width; insize Vrab07 = Vrab06; insize Vrab08 = (Bitm01.bmp_info_header.height - 1) * Vrab06 * 3;
  BMP_Color.resize(Vrab04 + Vrab01); BMP_Index.push_back(Vrab04); BMP_Width.push_back(Bitm01.bmp_info_header.width); BMP_Height.push_back(Bitm01.bmp_info_header.height); BMP_Address.push_back(Temp02);
  while(Vrab05 != Vrab01)
  {
   BMP_Color[Vrab04 + Vrab05].Blue = Bitm01.data[Vrab08 + ++Vrab03];
   BMP_Color[Vrab04 + Vrab05].Green = Bitm01.data[Vrab08 + ++Vrab03];
   BMP_Color[Vrab04 + Vrab05].Red = Bitm01.data[Vrab08 + ++Vrab03];
   Vrab05 += 1; Vrab07 -= 1; if(Vrab07 == 0){Vrab07 = Vrab06; Vrab08 -= Vrab06 * 3; Vrab03 = rinsize(-1);}
  }
  return (BMP_Address.size() - 1);
 }
 int0   C_Sprite_Clear() fastened {Sprite.clear(); Sprite_Index.clear();}
 insize Game::C_Sprite_Set(const string &Temp01, uint32 Vrab01, uint32 Vrab02, uint32 Vrab03, uint32 Vrab04) fastened
 {
  if(Varb0008)
  {
   const insize Vrab05 = C_BMP_Load(Temp01);
   if(Vrab05 == rinsize(-1))
   {
    const insize Vrab06 = Sprite_Index.size(); const insize Vrab07 = Vrab06 + (Vrab03 * Vrab04);
    Sprite_Index.resize(Vrab07);
    for(insize Vrab08 = Vrab06; Vrab08 < Vrab07; ++Vrab08)
    Sprite_Index[Vrab08] = rinsize(-1);
    return rinsize(-1);
   } else
   {
    const insize Vrab06 = Sprite.size(); const insize Vrab07 = Sprite_Index.size(); 
    Sprite.push_back({Vrab05, Vrab01, Vrab02, Vrab03, Vrab07});
    const insize Vrab08 = Vrab07 + (Vrab03 * Vrab04);
    Sprite_Index.resize(Vrab08);
    for(insize Vrab09 = Vrab07; Vrab09 < Vrab08; ++Vrab09)
    Sprite_Index[Vrab09] = Vrab06;
    return Vrab07;
   }
  } else
  {

   return 0;
  }
 }
 int0   C_Display(const uint8 Vrab01, const insize Vrab02, const int32 Vrab03 = 0, const int32 Vrab04 = 0, const uint8 Vrab05 = 0, const string Temp01 = "", const int32 Vrab06 = 0, const int32 Vrab07 = 0, const int32 Vrab08 = 0, const int32 Vrab09 = 0, const int32 Vrab10 = 0, const int32 Vrab11 = 0, const int8 Vrab12 = 0)
 {
  const insize Vrab13 = DisplayStack.size();
  DisplayStack.resize(Vrab13 + 1);
  DisplayStack[Vrab13].Type = Vrab01;
  DisplayStack[Vrab13].Target = Vrab02;
  DisplayStack[Vrab13].Post_X1 = Vrab03;
  DisplayStack[Vrab13].Post_Y1 = Vrab04;
  DisplayStack[Vrab13].Effect = Vrab05;
  DisplayStack[Vrab13].Text = Temp01;
  DisplayStack[Vrab13].Post_X2 = Vrab06;
  DisplayStack[Vrab13].Post_X3 = Vrab07;
  DisplayStack[Vrab13].Post_X4 = Vrab08;
  DisplayStack[Vrab13].Post_Y2 = Vrab09;
  DisplayStack[Vrab13].Post_Y3 = Vrab10;
  DisplayStack[Vrab13].Post_Y4 = Vrab11;
  DisplayStack[Vrab13].Trans = Vrab12;
 }
//-//
//AngelScript's Communication
 
//-//
//Main Functions
 int0 Game::Engine_Display() fastened
 {
  if(Varb0008)
  {
  if(Display.size() != Varb0002)
  {Display.resize(Varb0002); for(insize Vrab01 = 0; Vrab01 < Varb0002; ++Vrab01) Display[Vrab01].resize(Varb0003);} else
  {if(Display[0].size() != Varb0003){Display.resize(Varb0002); for(insize Vrab01 = 0; Vrab01 < Varb0002; ++Vrab01) Display[Vrab01].resize(Varb0003);}}

  {
   for(insize Vrab01 = 0; Vrab01 < Varb0002; ++Vrab01)
   for(insize Vrab02 = 0; Vrab02 < Varb0003; ++Vrab02)
   {
    Display[Vrab01][Vrab02].Green = (uint8)((uint32)(Varb0001 + (Vrab01 / 2)) % 256);
    Display[Vrab01][Vrab02].Blue = 0ui8;
    Display[Vrab01][Vrab02].Red = 0ui8;
   }//Display[Vrab05].Red = (uint8)((uint32)(Varb0001 + Vrab05) % 256);} //{switch(Vrab05 % 3){case 0: Display[Vrab05].Green = 0; break; case 1: Display[Vrab05].Blue = 0; break; case 2: Display[Vrab05].Red = 0; break; default: break;}}
  }

  const insize Vrab01 = DisplayStack.size();
  for(insize Vrab02 = 0; Vrab02 < Vrab01; ++Vrab02) switch(DisplayStack[Vrab02].Type)
  {
   case 0: // Simple PIC Display
   {
    if(DisplayStack[Vrab02].Target >= Sprite_Index.size()) break;
    const insize Vrab03 = Sprite_Index[DisplayStack[Vrab02].Target];
    const insize Vrab04 = Sprite[Vrab03].BMP;
    const insize Vrab05 = (Sprite[Vrab03].W + 1) * (DisplayStack[Vrab02].Target - Sprite[Vrab03].Zeroth); insize Vrab06 = (Sprite[Vrab03].H) * ((DisplayStack[Vrab02].Target - Sprite[Vrab03].Zeroth) / Sprite[Vrab03].Row);
    std::ofstream Labo("shj.txt"); Labo << Vrab05 << " " << Vrab06; Labo.close();
    const insize Vrab07 = Vrab05 + Sprite[Vrab03].W; const insize Vrab08 = Vrab06 + Sprite[Vrab03].H; insize Vrab10 = rinsize(DisplayStack[Vrab02].Post_Y1);
    if(DisplayStack[Vrab02].Effect == 0)
    {
     while(Vrab06 != Vrab08)
     {
      if(Vrab10 >= 0 && Vrab10 < Varb0003)
      {
       const insize Vrab11 = Vrab06 * BMP_Width[Vrab04];
       insize Vrab12 = Vrab05; insize Vrab09 = rinsize(DisplayStack[Vrab02].Post_X1);
       while(Vrab12 != Vrab07)
       {
        if(Vrab09 >= 0 && Vrab09 < Varb0002)
        {
         const auto Vrab13 = BMP_Color[BMP_Index[Vrab04] + Vrab11 + Vrab12];
         if(Vrab13.Blue != 0ui8 || Vrab13.Green != 0ui8 || Vrab13.Red != 0ui8) 
         Display[Vrab09][Vrab10] = Vrab13;
        }
        Vrab12 += 1; Vrab09 += 1;
       }
      }
      Vrab06 += 1; Vrab10 += 1;
     }
    } else
    {
     while(Vrab06 != Vrab08)
     {
      if(Vrab10 >= 0 && Vrab10 < Varb0003)
      {
       const insize Vrab11 = Vrab06 * BMP_Width[Vrab04];
       insize Vrab12 = Vrab05; insize Vrab09 = rinsize(DisplayStack[Vrab02].Post_X1) + Sprite[Vrab03].W;
       while(Vrab12 != Vrab07)
       {
        if(Vrab09 >= 0 && Vrab09 < Varb0002)
        {
         const auto Vrab13 = BMP_Color[BMP_Index[Vrab04] + Vrab11 + Vrab12];
         if(Vrab13.Blue != 0ui8 || Vrab13.Green != 0ui8 || Vrab13.Red != 0ui8) 
         Display[Vrab09][Vrab10] = Vrab13;
        }
        Vrab12 += 1; Vrab09 -= 1;
       }
      }
      Vrab06 += 1; Vrab10 += 1;
     }
    }
   }
   break;
   default: break;
  }
  } else
  {
   m_spriteBatch->Begin();

   const auto Vrab01 = m_spriteBatch.get();
   m_source[0]->Draw(Vrab01, {0, 0});

   m_spriteBatch->End();
  }
  DisplayStack.clear();
 }
 int0 Engine_Input(std::unique_ptr < DirectX::Keyboard > *Inpt01, std::unique_ptr < DirectX::GamePad > *Inpt02, std::unique_ptr < DirectX::Mouse > *Inpt03)
 {
  auto Inpt05 = (*Inpt01)->GetState();
  if(Inpt05.D0){if((++Input.MAIN_0) == 255ui8) Input.MAIN_0 = 254ui8;} else {Input.MAIN_0 = 0ui8;}
  if(Inpt05.D1){if((++Input.MAIN_1) == 255ui8) Input.MAIN_1 = 254ui8;} else {Input.MAIN_1 = 0ui8;}
  if(Inpt05.D2){if((++Input.MAIN_2) == 255ui8) Input.MAIN_2 = 254ui8;} else {Input.MAIN_2 = 0ui8;}
  if(Inpt05.D3){if((++Input.MAIN_3) == 255ui8) Input.MAIN_3 = 254ui8;} else {Input.MAIN_3 = 0ui8;}
  if(Inpt05.D4){if((++Input.MAIN_4) == 255ui8) Input.MAIN_4 = 254ui8;} else {Input.MAIN_4 = 0ui8;}
  if(Inpt05.D5){if((++Input.MAIN_5) == 255ui8) Input.MAIN_5 = 254ui8;} else {Input.MAIN_5 = 0ui8;}
  if(Inpt05.D6){if((++Input.MAIN_6) == 255ui8) Input.MAIN_6 = 254ui8;} else {Input.MAIN_6 = 0ui8;}
  if(Inpt05.D7){if((++Input.MAIN_7) == 255ui8) Input.MAIN_7 = 254ui8;} else {Input.MAIN_7 = 0ui8;}
  if(Inpt05.D8){if((++Input.MAIN_8) == 255ui8) Input.MAIN_8 = 254ui8;} else {Input.MAIN_8 = 0ui8;}
  if(Inpt05.D9){if((++Input.MAIN_9) == 255ui8) Input.MAIN_9 = 254ui8;} else {Input.MAIN_9 = 0ui8;}
  if(Inpt05.A){if((++Input.MAIN_A) == 255ui8) Input.MAIN_A = 254ui8;} else {Input.MAIN_A = 0ui8;}
  if(Inpt05.B){if((++Input.MAIN_B) == 255ui8) Input.MAIN_B = 254ui8;} else {Input.MAIN_B = 0ui8;}
  if(Inpt05.C){if((++Input.MAIN_C) == 255ui8) Input.MAIN_C = 254ui8;} else {Input.MAIN_C = 0ui8;}
  if(Inpt05.D){if((++Input.MAIN_D) == 255ui8) Input.MAIN_D = 254ui8;} else {Input.MAIN_D = 0ui8;}
  if(Inpt05.E){if((++Input.MAIN_E) == 255ui8) Input.MAIN_E = 254ui8;} else {Input.MAIN_E = 0ui8;}
  if(Inpt05.F){if((++Input.MAIN_F) == 255ui8) Input.MAIN_F = 254ui8;} else {Input.MAIN_F = 0ui8;}
  if(Inpt05.G){if((++Input.MAIN_G) == 255ui8) Input.MAIN_G = 254ui8;} else {Input.MAIN_G = 0ui8;}
  if(Inpt05.H){if((++Input.MAIN_H) == 255ui8) Input.MAIN_H = 254ui8;} else {Input.MAIN_H = 0ui8;}
  if(Inpt05.I){if((++Input.MAIN_I) == 255ui8) Input.MAIN_I = 254ui8;} else {Input.MAIN_I = 0ui8;}
  if(Inpt05.J){if((++Input.MAIN_J) == 255ui8) Input.MAIN_J = 254ui8;} else {Input.MAIN_J = 0ui8;}
  if(Inpt05.K){if((++Input.MAIN_K) == 255ui8) Input.MAIN_K = 254ui8;} else {Input.MAIN_K = 0ui8;}
  if(Inpt05.L){if((++Input.MAIN_L) == 255ui8) Input.MAIN_L = 254ui8;} else {Input.MAIN_L = 0ui8;}
  if(Inpt05.M){if((++Input.MAIN_M) == 255ui8) Input.MAIN_M = 254ui8;} else {Input.MAIN_M = 0ui8;}
  if(Inpt05.N){if((++Input.MAIN_N) == 255ui8) Input.MAIN_N = 254ui8;} else {Input.MAIN_N = 0ui8;}
  if(Inpt05.O){if((++Input.MAIN_O) == 255ui8) Input.MAIN_O = 254ui8;} else {Input.MAIN_O = 0ui8;}
  if(Inpt05.P){if((++Input.MAIN_P) == 255ui8) Input.MAIN_P = 254ui8;} else {Input.MAIN_P = 0ui8;}
  if(Inpt05.Q){if((++Input.MAIN_Q) == 255ui8) Input.MAIN_Q = 254ui8;} else {Input.MAIN_Q = 0ui8;}
  if(Inpt05.R){if((++Input.MAIN_R) == 255ui8) Input.MAIN_R = 254ui8;} else {Input.MAIN_R = 0ui8;}
  if(Inpt05.S){if((++Input.MAIN_S) == 255ui8) Input.MAIN_S = 254ui8;} else {Input.MAIN_S = 0ui8;}
  if(Inpt05.T){if((++Input.MAIN_T) == 255ui8) Input.MAIN_T = 254ui8;} else {Input.MAIN_T = 0ui8;}
  if(Inpt05.U){if((++Input.MAIN_U) == 255ui8) Input.MAIN_U = 254ui8;} else {Input.MAIN_U = 0ui8;}
  if(Inpt05.V){if((++Input.MAIN_V) == 255ui8) Input.MAIN_V = 254ui8;} else {Input.MAIN_V = 0ui8;}
  if(Inpt05.W){if((++Input.MAIN_W) == 255ui8) Input.MAIN_W = 254ui8;} else {Input.MAIN_W = 0ui8;}
  if(Inpt05.X){if((++Input.MAIN_X) == 255ui8) Input.MAIN_X = 254ui8;} else {Input.MAIN_X = 0ui8;}
  if(Inpt05.Y){if((++Input.MAIN_Y) == 255ui8) Input.MAIN_Y = 254ui8;} else {Input.MAIN_Y = 0ui8;}
  if(Inpt05.Z){if((++Input.MAIN_Z) == 255ui8) Input.MAIN_Z = 254ui8;} else {Input.MAIN_Z = 0ui8;}
  if(Inpt05.Escape){if((++Input.CORE_ESC) == 255ui8) Input.CORE_ESC = 254ui8;} else {Input.CORE_ESC = 0ui8;}
  if(Inpt05.F1){if((++Input.CORE_F1) == 255ui8) Input.CORE_F1 = 254ui8;} else {Input.CORE_F1 = 0ui8;}
  if(Inpt05.F2){if((++Input.CORE_F2) == 255ui8) Input.CORE_F2 = 254ui8;} else {Input.CORE_F2 = 0ui8;}
  if(Inpt05.F3){if((++Input.CORE_F3) == 255ui8) Input.CORE_F3 = 254ui8;} else {Input.CORE_F3 = 0ui8;}
  if(Inpt05.F4){if((++Input.CORE_F4) == 255ui8) Input.CORE_F4 = 254ui8;} else {Input.CORE_F4 = 0ui8;}
  if(Inpt05.F5){if((++Input.CORE_F5) == 255ui8) Input.CORE_F5 = 254ui8;} else {Input.CORE_F5 = 0ui8;}
  if(Inpt05.F6){if((++Input.CORE_F6) == 255ui8) Input.CORE_F6 = 254ui8;} else {Input.CORE_F6 = 0ui8;}
  if(Inpt05.F7){if((++Input.CORE_F7) == 255ui8) Input.CORE_F7 = 254ui8;} else {Input.CORE_F7 = 0ui8;}
  if(Inpt05.F8){if((++Input.CORE_F8) == 255ui8) Input.CORE_F8 = 254ui8;} else {Input.CORE_F8 = 0ui8;}
  if(Inpt05.F9){if((++Input.CORE_F9) == 255ui8) Input.CORE_F9 = 254ui8;} else {Input.CORE_F9 = 0ui8;}
  if(Inpt05.F10){if((++Input.CORE_F10) == 255ui8) Input.CORE_F10 = 254ui8;} else {Input.CORE_F10 = 0ui8;}
  if(Inpt05.F11){if((++Input.CORE_F11) == 255ui8) Input.CORE_F11 = 254ui8;} else {Input.CORE_F11 = 0ui8;}
  if(Inpt05.F12){if((++Input.CORE_F12) == 255ui8) Input.CORE_F12 = 254ui8;} else {Input.CORE_F12 = 0ui8;}
  if(Inpt05.PrintScreen){if((++Input.CORE_PSCREEN) == 255ui8) Input.CORE_PSCREEN = 254ui8;} else {Input.CORE_PSCREEN = 0ui8;}
  if(Inpt05.Delete){if((++Input.CORE_DELETE) == 255ui8) Input.CORE_DELETE = 254ui8;} else {Input.CORE_DELETE = 0ui8;}
  if(Inpt05.Back){if((++Input.CORE_BACKSPACE) == 255ui8) Input.CORE_BACKSPACE = 254ui8;} else {Input.CORE_BACKSPACE = 0ui8;}
  if(Inpt05.Tab){if((++Input.CORE_TAB) == 255ui8) Input.CORE_TAB = 254ui8;} else {Input.CORE_TAB = 0ui8;}
  if(Inpt05.Enter){if((++Input.CORE_ENTER) == 255ui8) Input.CORE_ENTER = 254ui8;} else {Input.CORE_ENTER = 0ui8;}
  if(Inpt05.CapsLock){if((++Input.CORE_CAPSLOCK) == 255ui8) Input.CORE_CAPSLOCK = 254ui8;} else {Input.CORE_CAPSLOCK = 0ui8;}
  if(Inpt05.LeftShift){if((++Input.CORE_LSHIFT) == 255ui8) Input.CORE_LSHIFT = 254ui8;} else {Input.CORE_LSHIFT = 0ui8;}
  if(Inpt05.RightShift){if((++Input.CORE_RSHIFT) == 255ui8) Input.CORE_RSHIFT = 254ui8;} else {Input.CORE_RSHIFT = 0ui8;}
  if(Inpt05.LeftControl){if((++Input.CORE_LCTRL) == 255ui8) Input.CORE_LCTRL = 254ui8;} else {Input.CORE_LCTRL = 0ui8;}
  if(Inpt05.RightControl){if((++Input.CORE_RCTRL) == 255ui8) Input.CORE_RCTRL = 254ui8;} else {Input.CORE_RCTRL = 0ui8;}
  if(Inpt05.LeftAlt){if((++Input.CORE_LALT) == 255ui8) Input.CORE_LALT = 254ui8;} else {Input.CORE_LALT = 0ui8;}
  if(Inpt05.RightAlt){if((++Input.CORE_RALT) == 255ui8) Input.CORE_RALT = 254ui8;} else {Input.CORE_RALT = 0ui8;}
  if(Inpt05.LeftWindows){if((++Input.CORE_LWIN) == 255ui8) Input.CORE_LWIN = 254ui8;} else {Input.CORE_LWIN = 0ui8;}
  if(Inpt05.RightWindows){if((++Input.CORE_RWIN) == 255ui8) Input.CORE_RWIN = 254ui8;} else {Input.CORE_RWIN = 0ui8;}
  if(Inpt05.Up){if((++Input.CORE_UP) == 255ui8) Input.CORE_UP = 254ui8;} else {Input.CORE_UP = 0ui8;}
  if(Inpt05.Left){if((++Input.CORE_LEFT) == 255ui8) Input.CORE_LEFT = 254ui8;} else {Input.CORE_LEFT = 0ui8;}
  if(Inpt05.Down){if((++Input.CORE_DOWN) == 255ui8) Input.CORE_DOWN = 254ui8;} else {Input.CORE_DOWN = 0ui8;}
  if(Inpt05.Right){if((++Input.CORE_RIGHT) == 255ui8) Input.CORE_RIGHT = 254ui8;} else {Input.CORE_RIGHT = 0ui8;}
  auto Inpt06 = (*Inpt02)->GetState(0);
  auto Inpt07 = (*Inpt03)->GetState();
  return;
 }
 int0 Engine_Main(xint64 Vrab01, xint64 Vrab02, uint32 Vrab03, uint32 Vrab04)
 {
  Varb0001 += 1;
  if(Varb0001 == 1)
  {
   Vect0001.resize(4);
   Vect0001[0] = g_game->C_Sprite_Set("System\\Sprite\\Template\\template_0_mirror.bmp", 79, 79, 19, 6);
   Vect0001[0] = g_game->C_Sprite_Set("System\\Sprite\\Template\\template_0.bmp", 79, 79, 19, 6);
  }
  
  for(uint32 Vrab69 = 0; Vrab69 < 50; ++Vrab69)
  C_Display(0, Vect0001[0], Vect0001[1] + (Vrab69 * 5), Vect0001[2] + (Vrab69 * 5), ruint8(Vect0001[3]));
  std::ofstream DO("ADD.txt"); DO << DisplayStack.size() << " : " << Vect0001[0]; DO.close();


  if(Input.MAIN_1 == 1){Vect0001[0] += 1;}
  if(Input.MAIN_2 == 1){Vect0001[0] -= 1;}
  if(Input.MAIN_3 == 1){Vect0001[1] += 1;}//std::ofstream KO("asds.txt"); L_SetLang(0); KO << L_GetLang(3); for(uint32 Vrab99 = 0; Vrab99 < BMP_Color.size(); ++Vrab99) KO << (int32)BMP_Color[Vrab99].Red << " " << (int32)BMP_Color[Vrab99].Green << " " << (int32)BMP_Color[Vrab99].Blue << " | ";}
  if(Input.MAIN_4 == 1){Vect0001[1] -= 1;} //std::ofstream KO("asds.txt"); L_SetLang(0); KO << L_GetLang(4);}
  if(Input.MAIN_5 == 1){Vect0001[2] += 1;}//std::ofstream KO("asds.txt"); L_SetLang(0); KO << L_GetLang(5);}
  if(Input.MAIN_6 == 1){Vect0001[2] -= 1;} //std::ofstream KO("asds.txt"); L_SetLang(0); KO << L_GetLang(6);}
  if(Input.MAIN_7 == 1){if(Vect0001[3] == 1){Vect0001[3] = 0;} else {Vect0001[3] = 1;}}
  if(Input.MAIN_8 == 1){std::ofstream KO("asds.txt"); L_SetLang(0); KO << L_GetLang(8);}
  if(Input.MAIN_9 == 1){std::ofstream KO("asds.txt"); L_SetLang(0); KO << L_GetLang(9);}
  if(Input.MAIN_0 == 1){C_BMP_Load("System\\Sprite\\Template\\template_0.bmp");}
  return;
 }
//-//
*/
#endif