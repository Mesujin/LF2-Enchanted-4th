Texture2D < float4 > Text0001 : register(t0);
sampler Samp0001 : register(s0);

float4 main(float4 Flot01 : COLOR0, float2 Cord01 : TEXCOORD0) : SV_Target0
{
 if(Flot01.a <= 1.0f)
 {
  float4 Flot02 = Text0001.Sample(Samp0001, Cord01); Flot02.a = Flot01.a;
  if(Flot02.x == 0 && Flot02.y == 0 && Flot02.z == 0) Flot02.a = 0.0f;
  return Flot02;
 } else
 {
  if(Flot01.a <= 3.0f)
  {
   float4 Flot02 = Flot01; Flot02.a -= 2.0f;
   return Flot02;
  } else
  {
   float4 Flot02 = Text0001.Sample(Samp0001, Cord01); Flot02.a = Flot01.a;
   return Flot02;
  }
 }
}