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
	float4 uv : UV;
};
struct PixelInput
{
	float4 position : SV_Position;
	float4 uv : UV;
};
/*
UV : 지금 사용하고 있는 텍스쳐에서 어떤 지점에 있는 데이터를 가져올 것인지를 지정하는,
	 텍스쳐 안에서의 좌표
텍스쳐(Texture = 질감) : 어떤 물체의 표면이 가지고 있는 질감
						그래픽에서는 어떤 오브젝트를 표현할 때 사용하는 데이터
						(2D의 경우엔 출력하는 데 사용하는 이미지,
						 3D의 경우엔 일단 뼈대가 만들어진 모델의 표면에 어떤 색을 입힐 것인지를 결정하는 데이터)

3D건 2D건 출력하고자 하는 꼭지점에 사용할 데이터의 어떤 위치에 있는 색상을 이용할 것인지를 결정해야 하며,
그 방식으로는 그 데이터에 저장되어 있는 자료들 중 출력하고자 하는 "위치"에 있는 색을 확인할 수 있도록
텍스쳐 상에서의 좌표를 정해줘야 함

그런 용도로 사용되는, X/Y/Z 등의 실제 공간과 구분되는 텍스처 상에서의 좌표를 정해줘야 하며,
그 용도로 텍스쳐 상에서의 X/Y/Z 좌표로 이용하는 값이 U/V/W라는 값
단, 본 프로젝트는 3D가 아닌 2D라서 사용하는 이미지도 2D 이미지이므로 W값은 사용하지 않고 
UV만을 이용하는 것

기본적으로, 원본의 데이터에서 왼쪽 위 끝부분에 있는 데이터의 위치를 0,0으로 취급하며
오른쪽 아래 끝을 1,1으로 취급함
기준은 원본 데이터의 상대 좌표


*/

PixelInput main(VertexInput input)
{
	PixelInput output;
	output.position = mul(input.pos, world);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);
	
	output.uv = input.uv;
	
	return output;
}