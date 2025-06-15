Texture2D < float4 > Text0001 : register(t0);
Texture2D < float4 > Text0002 : register(t1);
sampler Samp0001 : register(s0);

float4 main(float4 Flot01 : COLOR0, float2 Cord01 : TEXCOORD0) : SV_TARGET0
{
 float4 Flot02;

 if (Flot01.a <= 1.0f)         // (0.0f ~ 1.0f) : Plain color texture.
 {

  Flot02 = Flot01;

 } else if (Flot01.a <= 3.0f)  // (2.0f ~ 3.0f) : Image texture.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 2.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;

 } else if (Flot01.a <= 5.0f)  // (4.0f ~ 5.0f) : Image texture with #000000 as transparent.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 4.0f;
  if (Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0)
  Flot02.a = 0.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;

 } else if (Flot01.a <= 7.0f)  // (6.0f ~ 7.0f) : Plain color texture. (grayscaled)
 {

  Flot02 = Flot01;
  Flot02.a = Flot01.a - 6.0f;
  float1 Flot03 = (Flot02.x + Flot02.y + Flot02.z) / 3.0f;
  Flot02.xyz = Flot03;

 } else if (Flot01.a <= 9.0f)  // (8.0f ~ 9.0f) : Image texture. (grayscaled)
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 8.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
  float1 Flot03 = (Flot02.x + Flot02.y + Flot02.z) / 3.0f;
  Flot02.xyz = Flot03;

 } else if (Flot01.a <= 11.0f) // (10.0f ~ 11.0f) : Image texture with #000000 as transparent. (grayscaled)
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 10.0f;
  if (Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0)
  Flot02.a = 0.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
  float1 Flot03 = (Flot02.x + Flot02.y + Flot02.z) / 3.0f;
  Flot02.xyz = Flot03;

 } else if (Flot01.a <= 13.0f) // (12.0f ~ 13.0f) : Plain color texture. (inverted)
 {

  Flot02 = Flot01;
  Flot02.a = Flot01.a - 12.0f;
  Flot02.x = 1.0f - Flot02.x;
  Flot02.y = 1.0f - Flot02.y;
  Flot02.z = 1.0f - Flot02.z;

 } else if (Flot01.a <= 15.0f) // (14.0f ~ 15.0f) : Image texture. (inverted)
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 14.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
  Flot02.x = 1.0f - Flot02.x;
  Flot02.y = 1.0f - Flot02.y;
  Flot02.z = 1.0f - Flot02.z;

 } else if (Flot01.a <= 17.0f) // (16.0f ~ 17.0f) : Image texture with #000000 as transparent. (inverted)
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 16.0f;
  if (Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0)
  Flot02.a = 0.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
  Flot02.x = 1.0f - Flot02.x;
  Flot02.y = 1.0f - Flot02.y;
  Flot02.z = 1.0f - Flot02.z;

 } else if (Flot01.a <= 19.0f) // (18.0f ~ 19.0f) : Plain color texture. (fixed color)
 {

  Flot02 = Flot01;
  Flot02.a = Flot01.a - 18.0f;

 } else if (Flot01.a <= 21.0f) // (20.0f ~ 21.0f) : Image texture. (fixed color)
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 20.0f;
  Flot02.xyz = Flot01.xyz;

 } else if (Flot01.a <= 23.0f)// (22.0f ~ 23.0f) : Image texture with #000000 as transparent. (fixed color)
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 22.0f;
  if (Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0)
  Flot02.a = 0.0f;
  Flot02.xyz += Flot01.xyz;

 } else
 {
  // Adjustable color blind.
  int Uint01 = (int(Flot01.a) / 100) * 100;
  float1 Flot03 = float(Uint01) / 10000.0f;
  Flot01.a = Flot01.a - float(Uint01);
  if (Flot01.a <= 25.0f) // (24.0f ~ 25.0f) : Plain color texture. (adjustable grayscale)
  {

   Flot02 = Flot01;
   Flot02.a = Flot01.a - 24.0f;
   float1 Flot04 = ((Flot02.x + Flot02.y + Flot02.z) / 3.0f);
   Flot02.x += (Flot04 - Flot02.x) * Flot03;
   Flot02.y += (Flot04 - Flot02.y) * Flot03;
   Flot02.z += (Flot04 - Flot02.z) * Flot03;

  }
  else if (Flot01.a <= 27.0f) // (26.0f ~ 27.0f) : Image texture. (adjustable grayscale)
  {

   Flot02 = Text0001.Sample(Samp0001, Cord01);
   Flot02.a *= Flot01.a - 26.0f;
   Flot02.x += Flot01.x;
   Flot02.y += Flot01.y;
   Flot02.z += Flot01.z;
   float1 Flot04 = ((Flot02.x + Flot02.y + Flot02.z) / 3.0f);
   Flot02.x += (Flot04 - Flot02.x) * Flot03;
   Flot02.y += (Flot04 - Flot02.y) * Flot03;
   Flot02.z += (Flot04 - Flot02.z) * Flot03;

  }
  else if (Flot01.a <= 29.0f) // (28.0f ~ 29.0f) :  Image texture with #000000 as transparent. (adjustable grayscale)
  {

   Flot02 = Text0001.Sample(Samp0001, Cord01);
   Flot02.a *= Flot01.a - 28.0f;
   if (Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0)
   Flot02.a = 0.0f;
   Flot02.x += Flot01.x;
   Flot02.y += Flot01.y;
   Flot02.z += Flot01.z;
   float1 Flot04 = ((Flot02.x + Flot02.y + Flot02.z) / 3.0f);
   Flot02.x += (Flot04 - Flot02.x) * Flot03;
   Flot02.y += (Flot04 - Flot02.y) * Flot03;
   Flot02.z += (Flot04 - Flot02.z) * Flot03;

  }
 }
 return Flot02;
}