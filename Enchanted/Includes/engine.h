#pragma once
////////////////////////////////////////////////////////////////////////////////////////////
// Main source of "Hepta: Enchanted".                                                     //
// Dunno what to text here, but this is my usual style for a header text...               //
//                                                                                        //
// Under GNU General Public License v3.0.                                                 //
// Last modify - 2022 4 8 5:11 PM                                                         //
////////////////////////////////////////////////////////////////////////////////////////////

//Commands
 #include "angelscript.h"
 #include "scriptarray.h"
 #include "scriptbuilder.h"
 #include "scriptstdstring.h"
 #include <filesystem>
 #include <fstream>

 #define THIS_VERSION      0.85220408
 #define ENGINE            "System.as"
 #define DATA              "Data.txt"
 #define DATABASE          "Database.edb"
 #define BASE_LOCATION     "Database"
 #define LOCATION_LANG_EN  BASE_LOCATION "\\LangEN.txt"
 #define LOCATION_LANG_ID  BASE_LOCATION "\\LangID.txt"
 #define LOCATION_LANG_CN  BASE_LOCATION "\\LangCN.txt"
 #define LOCATION_LANG_CN2 BASE_LOCATION "\\LangCN2.txt"
 #define LOCATION_LANG_RU  BASE_LOCATION "\\LangRU.txt"
 #define LOCATION_LANG_JP  BASE_LOCATION "\\LangJP.txt"
 #define R_LOCATION        "R-Series"
 #define RECORD_LOCATION   "Recording"

 using int0 = void;                 // -
 using int1 = bool;                 // I know it's not being stored as 1 bit.
 using int8 = char;                 // -
 using int16 = short;               // -
 using int32 = int;                 // -
 using int64 = long long;           // -
 using uint8 = unsigned char;       // -
 using uint16 = unsigned short;     // -
 using uint32 = unsigned int;       // -
 using uint64 = unsigned long long; // -
 using xint32 = float;              // -
 using xint64 = double;             // -
 using string = std::string;        // -
//-//
//Memory / Variables
 //Non-Basic
  struct INPUTIN {int1 ESC; int1 F1;};

  INPUTIN Inpt0001;
  string Text0001;        // Language Text
  std::ofstream File0001;
  std::ifstream File0002;

 //Basic
  uint64 Varb0001 = 0;    // App Runtime
  uint32 Varb0002 = 800;  // Display W
  uint32 Varb0003 = 600;  // Display H
  uint8 Varb0004 = 1;     // FPS Ratio
  int1 Varb0005 = true;   // Keep aspect ratio?

 //Temporals (Process-Wise)
  uint32 Vrab0001;        // Temporal I-01
  uint32 Vrab0002;        // Temporal I-02
  uint32 Vrab0003;        // Temporal I-03
  uint32 Vrab0004;        // Temporal I-03
  string Strn0001;        // Temporal T-01
  string Strn0002;        // Temporal T-02

//-//
//Dynamic Memory / Variables
 struct COLOUR {uint8 Red; uint8 Green; uint8 Blue;};
 struct OBJECT {int1 Exist = false; int1 Loaded = false; uint8 Type = 255; string Address = ""; uint64 PropertyAdd = 0; uint64 FrameAdd = 0; uint64 FrameNum = 0; uint64 GuideAdd = 0;};
 struct DISPLAY {uint8 Red; uint8 Green; uint8 Blue; uint8 BTrans;};

 std::vector <DISPLAY> Display;
 
 std::vector <OBJECT> DATA_ID;           // -
 std::vector <uint32> DATA_Property;     // +>> (+0)Name; (+1)Face; (+2)Small; (+3)Pic_Num; (+4)Pic_Add; (+5)MaxHP; (+6)MovementSpeed; (+7)Weight; (+8 - +22)Speciality; (+23)StartingFrame;
 std::vector <uint32> DATA_Property_Pic; // +>> (+0)Address; (+1)W; (+2)H; (+3)Row; (+4)Col;
 std::vector <uint32> DATA_Frame;        // +>> (+0)Number; (+1)FType; (+2)State; (+3)State2; (+4)State3; (+5)CenterX; (+6)CenterY; (+7)Wait; (+8)Next; (+9)Vx; (+10)Vy; (+11)Vz; (+12 - +29)in_##; (+30)Sound; (+31)MP; (+32)HeldA; (+33)HeldA_Add; (+34)HeldB; (+35)HeldB_Add; (+36)Catch; (+37)Catch_Add; (+38)Body; (+39)Body_Add; (+40)SPoint_Num; (+41)SPoint_Add; (+42)BPoint_Num; (+43)BPoint_Add; (+44)FPoint_Num; (+45)FPoint_Add; (+46)IPoint_Num; (+47)IPoint_Add; (+48)RPoint_Num; (+49)RPoint_Add; (+50)OPoint_Num; (+51)OPoint_Add;
 std::vector <uint32> DATA_Frame_Body;   // +>> (+0)Kind; (+1)X; (+2)Y; (+3)W; (+4)H; (+5)Rotate;
 std::vector <uint32> DATA_Frame_HeldA;  // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)Action; (+5)Attack;
 std::vector <uint32> DATA_Frame_HeldB;  // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)Action; (+5)Attack;
 std::vector <uint32> DATA_Frame_Catch;  // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)Action; (+5)Hurt_Act;
 std::vector <uint32> DATA_Frame_SPoint; // +>> (+0)Pic; (+1)X1; (+2)Y1; (+3)X2; (+4)Y2; (+5)X3; (+6)Y3; (+7)X4; (+8)Y4; (+9)Trans;
 std::vector <uint32> DATA_Frame_FPoint; // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z;
 std::vector <uint32> DATA_Frame_BPoint; // +>> (+0)X; (+1)Y;
 std::vector <uint32> DATA_Frame_IPoint; // +>> (+0)Dimension; (+1)X; (+2)Y; (+3)Z; (+4)W; (+5)H; (+6)L; (+7)Shape; (+8)X_Rot; (+9)Y_Rot; (+10)Z_Rot (+11)Kind;
 std::vector <uint32> DATA_Frame_RPoint; // +>> (+0)Dimension; (+1)X; (+2)Y; (+3)Z; (+4)W; (+5)H; (+6)L; (+7)Shape;
 std::vector <uint32> DATA_Frame_OPoint; // +>> (+0)Kind; (+1)X; (+2)Y; (+3)Z; (+4)ID; (+5)Action;
 std::vector <uint32> DATA_Guide;        // -

 std::vector <uint32> INDEX_Language;     // -
 std::vector <uint32> INDEX_Frame;        // -

 std::vector <COLOUR> BMP_Color;
 std::vector <uint32> BMP_Index;
 std::vector <uint32> BMP_Width;
 std::vector <uint32> BMP_Height;
 std::vector <string> BMP_Address;
//-//
//Useful Functions
 int1 SetLang(uint8 Vrab01){switch(Vrab01){case 0: File0002.open(LOCATION_LANG_EN); break; case 1: File0002.open(LOCATION_LANG_ID); break; case 2: File0002.open(LOCATION_LANG_CN); break; case 3: File0002.open(LOCATION_LANG_CN2); break; case 4: File0002.open(LOCATION_LANG_RU); break; case 5: File0002.open(LOCATION_LANG_JP); break;} if(!File0002.is_open()) return false; Strn0002.assign((std::istreambuf_iterator<char>(File0002)), (std::istreambuf_iterator<char>())); Vrab0001 = Strn0002.length(); Vrab0002 = 0; Vrab0003 = 0; INDEX_Language.clear(); INDEX_Language.resize(0); Text0001 = ""; while(Vrab0002 < Vrab0001){if(Strn0002[Vrab0002] == '<') if(Strn0002[Vrab0002 + 1] == '/') if(Strn0002[Vrab0002 + 2] == '>'){Labl0012: Vrab0002 += 3; INDEX_Language.push_back(Vrab0003); Vrab0004 = 0; while(Strn0002[Vrab0002 + Vrab0004] == ' ') Vrab0004 += 1; if(Strn0002[Vrab0002 + Vrab0004] == '\n'){Vrab0004 += 1; Vrab0002 += Vrab0004;} else {if(Strn0002[Vrab0002 + Vrab0004] == '/') if(Strn0002[Vrab0002 + Vrab0004 + 1] == '/'){while(Strn0002[Vrab0002 + Vrab0004 + 2] != '\n') Vrab0004 += 1; Vrab0004 += 3; Vrab0002 += Vrab0004;}}} if(Strn0002[Vrab0002] == '/') if(Strn0002[Vrab0002 + 1] == '/'){Labl0013: Vrab0002 += 2; while(Strn0002[Vrab0002] != '\n') Vrab0002 += 1;} if(Strn0002[Vrab0002] == '\n'){Vrab0004 = 1; while(Strn0002[Vrab0002 + Vrab0004] == '\n') Vrab0004 += 1; if(Strn0002[Vrab0002 + Vrab0004] == '<') if(Strn0002[Vrab0002 + Vrab0004 + 1] == '/') if(Strn0002[Vrab0002 + Vrab0004 + 2] == '>'){Vrab0002 += Vrab0004; goto Labl0012;}} if(Strn0002[Vrab0002] == ' '){Vrab0004 = 1; while(Strn0002[Vrab0002 + Vrab0004] == ' ') Vrab0004 += 1; if(Strn0002[Vrab0002 + Vrab0004] == '/') if(Strn0002[Vrab0002 + Vrab0004 + 1] == '/'){Vrab0002 += Vrab0004; goto Labl0013;}} Text0001 += Strn0002[Vrab0002]; Vrab0003 += 1; Vrab0002 += 1;} File0001.open("TextLangOutPut.txt"); for(Vrab0002 = 0; Vrab0002 < INDEX_Language.size(); ++Vrab0002) File0001 << INDEX_Language[Vrab0002] << " "; File0001 << "\n================\n" << Text0001; File0001.close(); return true;}
 string GetLang(uint32 Vrab01){if(Vrab01 >= INDEX_Language.size()) return ""; string Vrab03 = ""; for(uint32 Vrab02 = INDEX_Language[Vrab01]; Vrab02 < INDEX_Language[Vrab01 + 1]; ++Vrab02) Vrab03 += Text0001[Vrab02]; return Vrab03;}
//-//
//AngelScript's Communication
 
//-//
//Main Functions
 int0 Platform_Main()
 {
  return;
 }
//-//