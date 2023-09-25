Texture2D < float4 > Text0001 : register(t0);
sampler Samp0001 : register(s0);

float4 main(float4 Flot01 : COLOR0, float2 Cord01 : TEXCOORD0) : SV_Target0
{
 float4 Flot02;

 if(Flot01.a <= 1.0f)        // (0.0f ~ 1.0f) : Plain Color.
 {

  Flot02 = Flot01;

 } else if(Flot01.a <= 3.0f) // (2.0f ~ 3.0f) : Normal Image.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 2.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;

 } else if(Flot01.a <= 5.0f) // (4.0f ~ 5.0f) : #000000 as Transparent.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 4.0f;
  if(Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0) Flot02.a = 0.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;

 } else if(Flot01.a <= 7.0f) // (6.0f ~ 7.0f) : Plain Color with no color.
 {

  Flot02 = Flot01; Flot02.a = Flot01.a - 6.0f;
		float1 Flot03 = (Flot02.x + Flot02.y + Flot02.z) / 3.0f;
		Flot02.xyz = Flot03;

 } else if(Flot01.a <= 9.0f) // (8.0f ~ 9.0f) : Normal Image with no color.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 8.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
		float1 Flot03 = (Flot02.x + Flot02.y + Flot02.z) / 3.0f;
		Flot02.xyz = Flot03;

 } else if(Flot01.a <= 11.0f) // (10.0f ~ 11.0f) : #000000 as Transparent with no color.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 10.0f;
  if(Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0) Flot02.a = 0.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
		float1 Flot03 = (Flot02.x + Flot02.y + Flot02.z) / 3.0f;
		Flot02.xyz = Flot03;

 } else if(Flot01.a <= 13.0f) // (12.0f ~ 13.0f) : Plain Color with no color.
 {

  Flot02 = Flot01; Flot02.a = Flot01.a - 12.0f;
		Flot02.x = 1.0f - Flot02.x; Flot02.y = 1.0f - Flot02.y; Flot02.z = 1.0f - Flot02.z;

 } else if(Flot01.a <= 15.0f) // (14.0f ~ 15.0f) : Normal Image with no color.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 14.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
		Flot02.x = 1.0f - Flot02.x; Flot02.y = 1.0f - Flot02.y; Flot02.z = 1.0f - Flot02.z;

 } else                      // (16.0f ~ 17.0f) : #000000 as Transparent with no color.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 16.0f;
  if(Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0) Flot02.a = 0.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;
		Flot02.x = 1.0f - Flot02.x; Flot02.y = 1.0f - Flot02.y; Flot02.z = 1.0f - Flot02.z;

 }

 return Flot02;
}