cbuffer world : register(b0)
{
	matrix world;
}
cbuffer view : register(b1)
{
	matrix view;
}
cbuffer projection : register(b2)
{
	matrix projection;
}

struct VertexInput
{
	float4 pos : POSITION;
};
struct PixelInput
{
	float4 position : SV_Position;
};

PixelInput main(VertexInput input)
{
	PixelInput output;
	output.position = mul(input.pos, world);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);
	
	return output;
}
// 좌표만 다루는 꼭지점이므로, 그에 걸맞게 다른 데이터들을 이 셰이더에서 취급할 필요 X