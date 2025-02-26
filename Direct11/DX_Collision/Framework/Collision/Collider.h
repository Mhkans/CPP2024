#pragma once
class Collider : public Transform
/*
그래픽 프로그래밍에서 오브젝트와 오브젝트가 충돌했는지 판단할 떄는
각 오브젝트마다 "충돌범위"를 지정해두고,
그 두 오브젝트의 충돌범위를 특정 알고리즘을 통해 비교해서
그 알고리즘의 통과 여부에 따라 충돌여부를 검사

이 클래스는 바로 그 오브젝트의 충돌판정 그 자체를 구성하는 부모 클래스
이 클래스의 내용을 상속받아 실제로 여러 종류의 자식 클래스를 만들 것
*/
{
public:
	enum class TYPE
	{
		RECT,
		CIRCLE
	};
	// 어떤 충돌판정을 다루는지 표기하는 데 사용할 열거형 클래스
	// 2D 환경에서 주로 사용되는 충돌 판정이 이 둘(사각형, 원형)이기 때문에,
	// 본 수업에서는 이 둘만 다룸 
	// - 다르게 생긴 판정들은 보통 이 판정들을 응용해서 만드는 경우가 대부분

protected:	
	TYPE type;

	VertexShader* VS;
	PixelShader* PS;

	VertexBuffer* VB;
	ColourBuffer* CB;

	vector<VertexPos> vertices;

	static bool debug_mode; // 정말 나중에 다룰 멤버이므로 지금은 설명 생략

public:
	Collider();
	virtual ~Collider();

	void Render();

	TYPE GetType() { return type; }

	static void SetDebugMode() { debug_mode = !debug_mode; }

	virtual bool isCollision(Collider* collider, Vector2* overwrap = NULL);
	// 실질적인 충돌판정을 다루는 함수들...인데,
	// 정확히는 실제 충돌 검사함수들을 부르는 역할

	// 아래의 3개 순수 가상함수들에 부모 클래스에서 접속하는 역할을 맡는다, 라는 느낌

	virtual bool isPointCollision(Vector2 point) = 0;
	virtual bool isCircleCollision(class CircleCollider* collider) = 0;
	virtual bool isRectCollision(class RectCollider* collider,
		Vector2* overwrap = NULL) = 0;
	// 자식 클래스 그 자체를 부모 클래스에서 사용해야 하는 상황이 올 경우,
	// 그냥 만들게 되면 부모 클래스를 정의하는 시점에선 자식 클래스들이 선언되어있지 않아
	// 어떤 것을 호칭하는 이름인지 컴파일러가 인식하지 못함
	// 그래서 "뭔진 몰라도 일단 클래스다"라고 선언을 해두면
	// 나중에 컴파일이 될 때 컴파일러가 일단 클래스라고 인식을 해두고
	// 실제로 그 내용을 찾아갈 때는 저 클래스듫이 선언된 부분을 찾아가 실행하게 되도록 하는 것
	
	void SetColor(float r, float g, float b)
	{
		CB->data.colour = Float4(r, g, b, 1);
	}

protected:
	virtual void CreateLine() = 0; // 꼭지점을 구현하는 함수

};