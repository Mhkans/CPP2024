cbuffer Color : register(b0)
{
	float4 color;
}

struct PixelInput
{
	float4 position : SV_Position;
};

float4 main(PixelInput input) : SV_TARGET
{
	return color;
	// 이번엔 꼭지점의 데이터에서 색상을 전혀 정의하지 않고 있으니,
	// 같이 전달되었을 색상버퍼의 색을 그대로 이용
}