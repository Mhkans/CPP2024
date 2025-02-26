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

	VertexBuffer* VB;
	// 도형 각각이 그래픽 출력에 필요한 데이터를 알아서 저장하도록,
	// 각 객체가 멤버로 버퍼를 보유

	VertexShader* VS;
	PixelShader* PS;
	// 오브젝트 자체가 출력과 관련된 기능을 전부 담당하려면,
	// 결국 스스로 셰이더를 보유하고 있어야 가능함
	// 따라서, 이제는 각 오브젝트(정확히는 그 오브젝트의 그래픽을 출력할 객체)가 셰이더를 보유하고 있어야 한다

	ColourBuffer* CB;
	// 이제는 꼭지점의 색만이 아니라 자체적으로 보유하고 있는 색상 보정값을 이용할 것이므로
	// 그 기능을 담당할, 정확히는 해당 색상데이터를 저장했다가 셰이더에 넘길 버퍼를 만들어두는 것

public:
	Shape();
	~Shape();

	VertexBuffer** const GetBuffer() { return &VB; }
	int GetVertexSize() { return verticies.size(); }

	virtual void Render() = 0;
	// 앞으로 만들 모든 Shape 클래스의 자식들은 스스로 출력하는 기능을 갖춰야 하므로
	// 순수 가상 함수로서 이를 강제

	void SetColor(Float4 colour) // 색 버퍼에 새로운 색을 저장하는 함수
	{
		CB->data.colour = colour;
	}
};