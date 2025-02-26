#pragma once
struct Vertex
	// 앞으로 우리가 도형을 만들 때 쓸 정점의 정보는 이 구조체를 통해 관리함
{
	Float3 position; // 이 꼭지점에 저장되는 좌표 정보
	Float4 colour; // 이 꼭지점에 저장되는 색상 정보

	Vertex()
		// C++에선 구조체는 사실상 public만 존재하는 클래스라 봐도 무방
		// 이렇게 생성자를 만드는 것도 문제 X
		// 아무 입력 없이 디폴트 선언했을 때의 초기화값
	{
		position = Float3(0, 0, 0);
		colour = Float4(0, 0, 0, 1);
		// RGB값 외에 4번째 값인 알파값은 사용할 기회가 왔을 때 실행
	}
	Vertex(float x, float y, float r, float g, float b)
	{
		position = Float3(x, y, 0);
		// 2D에선 z축의 위치를 사용하지 않음
		colour = Float4(r, g, b, 1);
	}
};

struct VertexUV
{
	Float3 position; // 이 꼭지점에 저장되는 좌표 정보
	Float2 uv; // 이 꼭지점에 저장되는 텍스쳐의 좌표 정보

	VertexUV()
	{
		position = Float3(0, 0, 0);
		uv = Float2(0, 0);
	}
	VertexUV(float x, float y, float u, float v)
	{
		position = Float3(x, y, 0);
		uv = Float2(u, v);
	}
};

struct VertexPos // 좌표를 제외한 어떤 데이터도 없는 정점
{
	Float3 position; // 이 꼭지점에 저장되는 좌표 정보

	VertexPos()
	{
		position = Float3(0, 0, 0);
	}
	VertexPos(float x, float y)
	{
		position = Float3(x, y, 0);
	}
};