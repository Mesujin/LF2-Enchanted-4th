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

 } else                      // (4.0f ~ 5.0f) : #000000 as Transparent.
 {

  Flot02 = Text0001.Sample(Samp0001, Cord01);
  Flot02.a *= Flot01.a - 4.0f;
  if(Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0) Flot02.a = 0.0f;
  Flot02.x += Flot01.x; //Flot02.x %= 1.0f;
  Flot02.y += Flot01.y; //Flot02.y %= 1.0f;
  Flot02.z += Flot01.z; //Flot02.z %= 1.0f;

 }

 return Flot02;
}