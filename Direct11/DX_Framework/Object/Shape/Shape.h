#pragma once
class Shape
// 앞으로 DX에서 도형 등을 출력하고자 할 때, Scene이 아니라
// 각각의 도형 오브젝트들이 자체적으로 출력과 관련된 내용들을 수행하도록 만들어줄 클래스
// 이제부터 우리가 DX에서 오브젝트를 만들었을 떄, 그 오브젝트가 가지고 있는 생김새 등을 이 클래스가 전담

// 단, 이건 어디까지나 뼈대일 뿐이며 실제 처리는 이 클래스를 상속받은 자식 클래스에서 처리하게 됨
{
protected:
	vector<Vertex> verticies = {};
	// vector를 이용해 이 도형이 출력되는 데 사용할 정점을 저장

	float pos_x, pos_y;
	// 도형의 위치를 기록해둘 변수
	ID3D11Buffer* VB;
	// 도형 각각이 그래픽 출력에 필요한 데이터를 알아서 저장하도록,
	// 각 객체가 멤버로 버퍼를 보유

public:
	Shape(float x, float y);
	~Shape();

	ID3D11Buffer** const GetBuffer() { return &VB; }
	int GetVertexSize() { return verticies.size(); }
};