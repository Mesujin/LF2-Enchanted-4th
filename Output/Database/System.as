uint32 MaximumObjNum = 1500 ; uint16 ConsoleBuffer = 60 ; uint8 Loop; uint64 SystemRunTime = 0;
 
void Main(){
Loop += 1;
if(Loop == 1){SystemRunTime += 1; Loop = 0;} if(SystemRunTime == 60) Platform.Save.SaveData(0); if(SystemRunTime == 120) if(Platform.Save.LoadData(0)) Platform.FPSDisplay = true;
//if(SystemRunTime % 2 == 0){Platform.Print("a kaodkaodkasod sfssd dkao");} else {Platform.Print("a   kaodkod sss\nrd dkdsg  dsf ao");}

for(uint64 A = 0; A < SystemRunTime % 140; ++A) Platform.Print(" "); Platform.Print("===>");
 Platform.PrintOut(); return;}