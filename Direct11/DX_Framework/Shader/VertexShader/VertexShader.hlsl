// HLSL : High-Level Shader Language = 고수준 셰이더 언어
// 셰이더를 만들기 위해 만들어진 언어로, 이 언어를 통해 그래픽 파이프라인에서 다루는 셰이더들을 관리함

// DX에서 다루는 내용이라고는 하나, C나 C++과는 다른 언어이기 때문에
// 메인 프로젝트에서 쓰고 있는 C++ 언어와는 100% 호환되지 않음
// 따라서 HLSL 고유의 용도에 맞게 코드를 구성해줘야 하고,
// 특히 프로젝트의 메인 코드 쪽에서 어느 데이터가 들어오는지를 이 셰이더 파일 쪽에서 알 방도가 없기 때문에
// 보내주는 C++ 쪽에서 I-A 단계를 통해 어떤 데이터를 보내주는 것인지 명시해줘야 함

// 그 과정에서 사용되는 것이 아래에 있는 구조체 포맷 + 시멘틱

struct VertexInput // 입력받은 정점 데이터가 이뤄져있는 구조를 알리는 구조체
{
	float4 pos : POSITION;
	// float4 : HLSL에서 지원하는, 실수 4개를 저장하는 자료형
	float4 color : COLOR;
};
struct PixelInput // 정점 셰이더에서의 처리가 끝나, 픽셀 셰이더로 보낼 꼭지점의 데이터
{
	float4 position : SV_Position;
	float4 color : COLOR;
};

// 변수 뒤에 다른 이름들이 : 뒤에 적혀있는 것을 확인 가능
// 이를 시멘틱(Symentic)이라 부름

// C++에서 데이터를 HLSL 파일에 보낼 때, 보낸 데이터가 정확히 어디에 사용되는 데이터인지를 명시해야 하는데
// 그 떄, 그 데이터의 도착지를 표기하기 위해 사용하는 개념
// VertexShader.cpp에서 layout을 구성할 때 POSITION이라고 태그를 붙여서 보낸 데이터는
// 이 파일에서 위에 저기 VertexInput에 POSITION이라는 시멘틱이 적혀있는 pos에 입력되는 것


PixelInput main(VertexInput input)
{
	PixelInput output;
	output.position = input.pos;
	output.color = input.color;
	// 현재는 이 셰이더에서 특별한 작업은 하지 않을 것이므로,
	// 입력받은 데이터를 그대로 PixelInput으로 변환하여 PS에 옮겨주는 것
	// 나중에는 input의 데이터를 손봐서 PS에 전달할 예정
	
	/*
	지금 코드만 보면 VI의 데이터를 PI로 옮기기만 할 뿐이라 아무 의미가 없어보이는 작업이지만,
	pos이 부여받고 있는 시멘틱이 완전히 다름
	PS 측에서는 PI가 가지고 있는 시멘틱을 이용해서 작업을 처리해야 하기 떄문에,
	입력받은 데이터에 붙어있는 VS 전용 시멘틱을 떼고
	PS에서 사용하는 데 필요한 시멘틱을 붙여주는 작업이라 봐도 무방
	*/
	
	return output;
	// 그렇게 가공이 끝난 데이터를 반환하여 픽셀 셰이더 측에 넘길 수 있게 함
}