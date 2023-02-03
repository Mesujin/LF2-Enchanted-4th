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
// The right of this Script is belong to Mesujin :P this's mine :<                              //
//////////////////////////////////////////////////////////////////////////////////////////////////

//////
 // About the Configurations..
 //
 // The Value in Configuration must be Positive! Whether if it's an "Unsigned" or "Signed" Data Type.
 // If there's no "Limit", then the "Limit" is their Data Type limit.
 // Try to return the Value to it's "Default" Value if you occuring an error...
 // or just delete this file, and the .exe will make the original one once launched.
 //
 // Important! Please keep the "Semicolon(;)" in not touching the Value as there's a reason for that.
//////

//Configurations
 //Main Configuration
  uint32 MaximumObjNum         = 1500  ;//In-Game maximum objects.            {Default = 1500}
  int ZCameraShift             = 350   ;//Z-Camera's center position.         {Default = 350}
  double ZCameraYEffectiviness = 0.4   ;//Y-Axis' effectiviness for Z-Camera. {Default = 0.4}
  double PrespectiveRatio      = 0.4   ;//Prespective of X-Axis to Z-Axis.    {Default = 0.4} {Modify might causing a bug.}
 //-//

 //In-game Settings (Only purposed for the default setting, the values will be carried in the data save.)
  bool FlawlessInput        = true  ;//
  int8 FlawlessInputSet     = 0     ;//0 = P1 - P2 | P3 - P4; 1 = P1 - P3 | P2 - P4; 2 = P1 - P4 | P2 - P3;
  int RandomItemsFromTheSky = 0     ;//
  int BattleTimer           = 0     ;//
  int RoundBattle           = 0     ;//
 //-//

 //Windows Console API
  bool ConsoleDebug = true  ;//Set ConsoleDebug into 'true' to activate the Debug Console that would helpful in modding the game.  {Default = false}
  int8 ConsoleStyle = 255   ;//The style of the Console.                                                             {Limit = 255} {Default = 0}
  int16 ConsoleRate = 0     ;//Sometimes the Console might causing some lag, so increasing the ConsoleRate would nice. {Limit = 9} {Default = 0}
  int8 ConsoleDeCon = 0     ;//Default controller in controlling the Debug Menu. (0 = Non-default control)             {Limit = 8} {Default = 0}
  int ConsoleBuffer = 80    ;//The buffer size of the Console.                               {Available Value : 60; 80; 100; 120;} {Default = 100}
 //-//
 
 //Engine Configuration
  double NaturalHPRegenPer3TU        = 0.2   ;//Natural HP Regeneration.                           {Default = 0.2}
  double NaturalDHPRegenPer3TU       = 0     ;//Natural DHP Regeneration.                          {Default = 0}
  double NaturalMPRegenPer1TU        = 1     ;//Natural MP Regeneration.                           {Default = 1}
  double NaturalMPRegenPer1TU2       = 0.5   ;//Natural MP Regeneration when in Action.            {Default = 0.5}
  double NaturalEPRegenPer1TU        = 1     ;//Natural EP Regeneration.                           {Default = 1}
  double NaturalShieldDegeratePer3TU = 0.1   ;//Natural Shield Degeneration.                       {Default = 0.1}
  double ShieldConvertionRatio       = 0.75  ;//HP to Shield convertion rate when it's overloaded. {Default = 0.75}
  double RegenerationSpeed           = 1     ;//(Not natural regeneration)                         {Default = 1}
  double MaxMP                       = 1000  ;//                                                   {Default = 1000}
  double MaxEP                       = 125   ;//                                                   {Default = 125}
  double StartingMP                  = 500   ;//                                                   {Default = 500}
  double StartingEP                  = 0     ;//                                                   {Default = 0}
  double Bleeding                    = 20    ;//Maximum percentage of HP for bleeding.             {Default = 150}

  bool WeaponPhysic                = true   ;//Activate a Physic calculation for Weapons/Items when landing?                        {Default = true}
  double ReleasedSpeed             = 120    ;//Percentage of the speed when the Weapon/Item are released with kind: 1 & weap_vel: 0 {Default = 0.35}
  double MilkTotalRestorationRatio = 0.35   ;//Amount of Milk's regeneration, scaling to character's MaxHP.                         {Default = 0.35}
  double MilkRestorationPer1TU     = 0.001  ;//Amount of Milk's regeneration each TU.                                               {Default = 0.001}
  double TeaTotalRestorationRatio  = 0.8    ;//Amount of Tea's regenertaion, scaling to character's MaxHP.                          {Default = 0.8}
  double TeaRestorationPer1TU      = 0.002  ;//Amount of Tea's regeneration each TU.                                                {Default = 0.002}

  double DamageElement      = 100.040  ;//Percentage to the HP and DHP. (XXX.YYY : XXX = HP, YYY = DHP) {Default = 100.040}
  double TrueDamageElement  = 100.100  ;//Percentage to the HP and DHP. (XXX.YYY : XXX = HP, YYY = DHP) {Default = 100.100} 
  double BurstDamageElement = 100.000  ;//Percentage to the HP and DHP. (XXX.YYY : XXX = HP, YYY = DHP) {Default = 100.000} 
  double InnerDamageElement = 000.100  ;//Percentage to the HP and DHP. (XXX.YYY : XXX = HP, YYY = DHP) {Default = 000.100}
  
  uint64 InputCastWait        = 0      ;//Wait time for next Input to Cast. (0 = No wait.) {Limit = 99} {Default = 0}
  uint64 InputRunWait         = 10     ;//Wait time for next Input to Run. (0 = No wait.)  {Limit = 99} {Default = 10}
  uint64 SingleCastAvail      = 6      ;//Available time for single Input. (0 = Always.)   {Limit = 99} {Default = 6}
  uint64 CastAvail            = 0      ;//Available time for Cast. (0 = Always.)           {Limit = 99} {Default = 0}
  uint64 RunAvail             = 6      ;//Available time for Run. (0 = Always.)            {Limit = 99} {Default = 6}
  uint16 AJADDJOffside        = 3      ;//The TU Offside for AJ, AD, or DJ.                             {Default = 3}
  bool IncludeAJADDJAsACast   = false  ;//Include AJ, AD, and DJ as a Cast?                             {Default = false}

  double MovementBaseRatio        = 0.01  ;//            {Default = 0.01}
  double MovementSideRatio        = 0.7   ;//            {Default = 0.7}
  double MovementWalkRatio        = 1     ;//            {Default = 1}
  double MovementJumpRatioX       = 2     ;//            {Default = 2}
  double MovementJumpRatioY       = 0.1   ;//            {Default = 0.1}
  double MovementJumpYAmount      = 14    ;//Base value  {Default = 14}
  double MovementJumpFixedYAmount = 1     ;//Fixed value {Default = 1}
  double MovementRunRatio         = 2     ;//            {Default = 2}
  double MovementDashRatioX       = 3     ;//            {Default = 2.5}
  double MovementDashRatioY       = 0.07  ;//            {Default = 0.07}
  double MovementDashYAmount      = 9.8   ;//Base value  {Default = 9.8}
  double MovementDashFixedYAmount = 0.7   ;//Fixed value {Default = 0.7}
  double MovementHeavyRatio       = 0.8   ;//            {Default = 0.8}

  bool WeightCalculation            = true  ;//Activate the Weight Calculation on hit?                                                 {Default = true}
  double GAttackerVelKnockbackRatio = 0     ;//The ratio of Velocity that Attacker will gain once the attack are successful on ground. {Default = 0}
  double MAttackerVelKnockbackRatio = 0.5   ;//The ratio of Velocity that Attacker will gain once the attack are successful in midair. {Default = 0.5}
  double GAttackedVelKnockbackRatio = 1     ;//The ratio of Velocity that Attacked will gain once the attack are successful on ground. {Default = 1}
  double MAttackedVelKnockbackRatio = 0.5   ;//The ratio of Velocity that Attacked will gain once the attack are successful in midair. {Default = 0.5}

  double WallCollisionSPDReduction = 0.3   ;//Velocity reduction when collising with the Wall/Ground/Stair, Axis position also affected in accordance to the reduction. {Limit = 1} {Default = 0.3}
  double ReflectedVelocity         = 0.35  ;//Reflected velocity when collising with the Wall/Ground/Stair. (Excluded on landing.)                                                  {Default = 0.35}
  double MinimumVelFall            = 10    ;//Minimum Y-Vel to achieve Fall.                                                                                                        {Default = 10}
  double MinimumVelHighFall        = 30    ;//Minimum Y-Vel to achieve High Fall.                                                                                                   {Default = 30}
  double ReboundVelFall            = 0.18  ;//Rebounded Y-Vel when Fall are activated.                                                                                              {Default = 0.18}
  double ReboundVelMinimumFall     = 2.5   ;//Minimum rebounded Y-Vel when Fall are activated.                                                                                      {Default = 2.5}
  double ReboundVelHighFall        = 0.2   ;//Rebounded Y-Vel when High Fall are activated.                                                                                         {Default = 0.2}
  double ReboundVelMinimumHighFall = 10    ;//Minimum rebounded Y-Vel when High Fall are activated.                                                                                 {Default = 10}
  double ReboundVelBounce          = 0.5   ;//Rebounded Y-Vel when Bounce are activated.                                                                                            {Default = 0.5}
  double ReboundVelMinimumBounce   = 12.5  ;//Minimum rebounded Y-Vel when Bounce are act ivated.                                                                                    {Default = 12.5}
  double FallDamageBase            = 8.0   ;//Recieved damage on Fall. (Normal Fall won't give any damage.)                                 (XXX.Y : XXX = Amount, Y = Damage Type) {Default = 8.0}
  double FallDamageScaling         = 0.2   ;//Recieved damage for each 1 Y-Vel on Fall. (Normal Fall won't give any damage.)                                                        {Default = 0.2}
  double HighFallDamageBase        = 20.0  ;//Recieved damage on High Fall.                                                                 (XXX.Y : XXX = Amount, Y = Damage Type) {Default = 20.0}
  double HighFallDamageScaling     = 1     ;//Recieved damage for each 1 Y-Vel on High Fall.                                                                                        {Default = 1}
  double BounceDamageBase          = 10.0  ;//Recieved damage on Bounce.                                                                    (XXX.Y : XXX = Amount, Y = Damage Type) {Default = 10.0}
  double BounceDamageScaling       = 0.5   ;//Recieved damage for each 1 Y-Vel on Bounce.                                                                                           {Default = 0.5}
  bool RemovableBounce             = true  ;//Will Bounce get removed by a hit?                                                                                                     {Default = true}
  bool UnflipableOnBounce          = true  ;//Is Flip will be disabled on Bounce?                                                                                                   {Default = true}
  bool HighCalcCollision           = true  ;//Extremely calculate more in the physic of Wall/Ground/Stair. (Might consume a lot process.)                                           {Default = true}

  double StageDifficultyModifier = 0.25  ;//Enemies' MaxHP, HP, and DHP modifier. (Easy = 1.25 - 3X)(Normal = 1.25 - 2X)(Difficult/Crazy = 1.25 - X) {Default = 0.25}
  double StageEnemyDamageRatio   = 0.8   ;//Enemies's damage ratio in the stage mode.                                                                {Default = 0.8}
  double StageEnemyRegenRatio    = 0.8   ;//Enemies's natural regen ratio in the stage mode.                                                         {Default = 0.8}

  int8 Type0HitLag      = 2     ;//Type0's hitlag.                                            {Default = 2}
  double Type0GXGravity = 1.35  ;//Type0's ground X-axis Gravity/Velocity reduction per 1 TU. {Default = 1.35}
  double Type0MXGravity = 0.1   ;//Type0's midair X-axis Gravity/Velocity reduction per 1 TU. {Default = 0.1}
  double Type0MYGravity = 1.85  ;//Type0's midair Y-axis Gravity/Velocity reduction per 1 TU. {Default = 1.7}

  int8 Type1HitLag      = 2                  ;//Type1's hitlag.                                            {Default = 2}
  double Type1GXGravity = 0                  ;//Type1's ground X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type1MXGravity = 0                  ;//Type1's midair X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type1MYGravity = 0                  ;//Type1's midair Y-axis Gravity/Velocity reduction per 1 TU. {Default = }

  int8 Type2HitLag      = 2                  ;//Type2's hitlag.                                            {Default = 2}
  double Type2GXGravity = 0                  ;//Type2's ground X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type2MXGravity = 0                  ;//Type2's midair X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type2MYGravity = 0                  ;//Type2's midair Y-axis Gravity/Velocity reduction per 1 TU. {Default = }

  int8 Type3HitLag      = 0                  ;//Type3's hitlag.                                            {Default = 0}
  double Type3GXGravity = 0                  ;//Type3's ground X-axis Gravity/Velocity reduction per 1 TU. {Default = 0}
  double Type3MXGravity = 0                  ;//Type3's midair X-axis Gravity/Velocity reduction per 1 TU. {Default = 0}
  double Type3MYGravity = 0                  ;//Type3's midair Y-axis Gravity/Velocity reduction per 1 TU. {Default = 0} {Modify might causing a bug.}

  int8 Type4HitLag      = 2                  ;//Type4's hitlag.                                            {Default = 2}
  double Type4GXGravity = 0                  ;//Type4's ground X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type4MXGravity = 0                  ;//Type4's midair X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type4MYGravity = 0                  ;//Type4's midair Y-axis Gravity/Velocity reduction per 1 TU. {Default = }

  int8 Type5HitLag      = 2                  ;//Type5's hitlag.                                            {Default = 2}
  double Type5GXGravity = 0                  ;//Type5's ground X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type5MXGravity = 0                  ;//Type5's midair X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type5MYGravity = 0                  ;//Type5's midair Y-axis Gravity/Velocity reduction per 1 TU. {Default = }

  int8 Type6HitLag      = 2                  ;//Type6's hitlag.                                            {Default = 2}
  double Type6GXGravity = 0                  ;//Type6's ground X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type6MXGravity = 0                  ;//Type6's midair X-axis Gravity/Velocity reduction per 1 TU. {Default = }
  double Type6MYGravity = 0                  ;//Type6's midair Y-axis Gravity/Velocity reduction per 1 TU. {Default = }

  bool HighLevelCalculation      = true  ;//Activate the high level calculation for Velocity which is an effect from the Density of Air(too high velocity)?       {Default = true}
  double AirDensitySpeed         = 70    ;//Maximum speed that can be achieved by the Density of Air from it's speed accumulation which also based on the Weight. {Default = 70}
  double DecreasionEffectiveness = 100   ;//The percentage of effectiveness of the decreasion of speed accumulation.                                              {Default = 100}
  double DecreasionRateRatio     = 100   ;//The percentage of Ratio of the amount of decreasion of speed accumulation.                                            {Default = 100}
  double DecreasionRateBase      = 0     ;//Base amount of the decreasion of speed accumulation.                                                                  {Default = 0}
  double WeightEffectiveness     = 50    ;//Percentage of weight's effectiveness in the calculation.                                                              {Default = 50}
 //-//
//-//

//////
 // Again, do not modify if you don't know what you're gonna modify!
 // The what exist at down here already a full of programming matter, go back if you're not familiar with AngelScript or C++.
 // 
 // Here .. i'm? .. going to explain a bit about every functions from the Platform;
 // Anyway, everything is start from 'Main()'.
 //
 // <>) Platform.Print();
 //     The most important function that could help you know what you're gonna modify.
 //     This is an "Overloaded Function"/"Function Overloading" where you can put any "Data Type" into it,
 //     and once 'Platform.PrintOut()' called, you'll see a console that print that "Data Type".
 //
 //     Ex: 
 //       int32 Varb01 = 2693;
 //       Platform.Print("Single Text.\n");
 //       Platform.Print("Text here, "+(23 + 325)+" with Another text, and "+Varb01+".");
 //       Platform.PrintOut();
 //
 //     Output - Windows Console API:
 //       Single Text.
 //       Text here, 348 with another text, and 2693.
 //       
 // <>) Platform.PrintOut();
 //     I guess you got what is this function are used for, from 'Platform.Print()''s explanation.
 //
 // <>) Platform.PrintClear();
 //     Used to clear the history/inserted data from 'Platform.Print()', since the Platform will stack all
 //     the text to the memory until 'Platform.PrintOut()' or 'Platform.PrintClear()' is called.
 //     So, make sure to always clean the memory if you doesn't wan't to print the data.
 //
 //     Ex:
 //       Platform.Print("Hmmmmm...");
 //       Platform.PrintClear();
 //       Platform.Print("Ah, i see.");
 //       Platform.PrintOut();
 //
 //     Output - Windows Console API:
 //       Ah, i see.
 //
 // <>) Platform.PrintIt();
 //     Similar to 'Platform.PrintOut()', the only different is that 'Platform.PrintIt()' doesn't overwrite and purging the 
 //     data of the last printed texts.
 //
 //     Ex:
 //       Platform.Print("Text1\n");
 //       Platform.PrintIt();
 //       Platform.Print("Text2\n");
 //       Platform.PrintIt();
 //
 //     Output - Windows Console API:
 //       Text1
 //       Text1
 //       Text2
 //
 // <>) 
 //
//////

//Memory / Variables

//-//

//Functions

//-//

//Main Functions
 void Main()
 {
  /*if(FlawlessInput)
  {
 int8 A = -28;
 int8 B = -72;
 int8 C = -128;
 int8 D = 0;
 for(A; A < -22; ++A)
 {
  for(B; B < -64; ++B)
  {
   for(C; C < -64; ++C)
   {Platform.Print(A); Platform.Print(B); Platform.Print(C); //D += 1; if(D == 80){D = 0; Platform.Print("\n");}
    if(A == -23) if(B == -65) if(C == -107){FlawlessInput = false; Platform.PrintOut(); return;}}
   C = -128;
  }
  B = -128;
 }
}*/
  Platform.Save.SaveData(0);
  if(FlawlessInput){Platform.FPSDisplay = true; FlawlessInput = false;}
  return;
 }
//-//

//Computer's AI
 void Game_AI()
 {


 }
//-//