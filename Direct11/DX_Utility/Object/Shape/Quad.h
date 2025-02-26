#pragma once
/*
Quad : 일반적으로는 "넷"을 뜻하는 말
여기서는 사각형이라 보면 됨
-> 사각형의 "이미지"를 출력하기 위한 클래스

기존의 Shape는 SRT 변환을 통한 위치 관리를 직접 할 수 없는 클래스였어서,
이를 스스로 관리할 수 있게 Transform을 상속시키는 새 클래스를 만들어야 더 편해짐
-> 출력 부분을 포함해 전부 관리할 수 있는 새로운 종류의 Shape를 다시 만든 것

지금 만드는 이 Quad라는 클래스는
후일 애니메이션을 만들기 위해 들어가있는 부분이 약간 있음
지금 당장은 쓸 수 없는 부분이다보니, 이는 일단 추가는 하되 각주로 처리할 것
-> 나중엔 이 클래스를 좀 뒤엎을 예정
*/

class Quad : public Transform
{
protected:
	vector<Vertex> verticies = {};
	vector<VertexUV> vertices_uv = {};

	VertexBuffer* VB;

	VertexShader* VS;
	PixelShader* PS;

	ColourBuffer* CB;

	/*
	IndexBuffer* IB;
	
	Texture* texture;

	void SetPixelShader(wstring file)
	*/
	
	void Create();

public:
	Quad(/*wstring file,*/Vector2 size, Vector2 scale = Vector2(1, 1),
		Vector2 startUV = Vector2(0, 0), Vector2 EndUV = Vector2(1, 1));
	virtual ~Quad();

	virtual void Render();
};