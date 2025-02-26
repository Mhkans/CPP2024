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
// cbuffer(= Construct Buffer = 상수 버퍼) 3개를 선언하고,
// 그 3개 버퍼들을 각각의 슬롯에 등록한다는 코드
// 이 각각의 버퍼엔 4X4 크기의 행렬이 들어가있어서,
// 각각 W, V, P 변환을 위해 C++ 쪽에서 받아와야 하는 공간/시점/투영 변환 행렬이 기록되어있는 데이터

// World라고 하는, world 행렬을 저장하는 상수 버퍼는 b0라는 "슬롯"에 등록해서 그 슬롯을 통해 데이터를 입력받겠다
// 같은 식으로 b1에는 view 행렬을 view에,
// b2에는 projection 행렬을 projection에 저장하도록 슬롯을 매칭시켜주는 것
// 그렇게 하면 C++ 쪽에서 해당 슬롯으로 데이터를 보낼 경우 위에 정의되어있는 각각의 행렬에 알아서 데이터가 세팅된다


struct VertexInput
{
	float4 pos : POSITION;
	float4 color : COLOR;
};
struct PixelInput
{
	float4 position : SV_Position;
	float4 color : COLOR;
};

PixelInput main(VertexInput input)
{
	PixelInput output;
	output.position = mul(input.pos, world);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);
	// mul : HLSL에서 지원하는 행렬 * 행렬 간 곱셈을 수행해주는 예약어
	// 정확히는 벡터 * 행렬도 지원하고, 실제로 지금 이것도 pos이라는 벡터값을 행렬에 곱하는 중이기도 함
	
	// 위 3개는 각각 World 변환 / View 변환 / Projection 변환을 담당하는 코드
	// -> WVP 변환은 오브젝트가 가지고 있는 좌표를 월드/뷰/프로젝션 순으로 곱하는 단계
	
	output.color = input.color;
	
	return output;
}