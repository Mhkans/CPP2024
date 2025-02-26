#include "framework.h"

bool Collider::debug_mode = true;

Collider::Collider()
{
	is_active = false;

	VS = new VertexShader(L"Shader/VertexShader/VertexPos.hlsl", 2);
	PS = new PixelShader(L"Shader/PixelShader/PixelPos.hlsl");

	CB = new ColourBuffer();
	CB->data.colour = { 0,1,0,1 };
}

Collider::~Collider()
{
	delete CB;
}

void Collider::Render()
{
	if (!is_active || !debug_mode) return;
	// 이 충돌판정이 활성화되어있지 않거나,
	// 아니면 충동판정 자체를 출력하지 않는 모드로 설정되었다면 출력하지 않고 종료

	WB->Set(world);
	WB->SetVS(0);
	CB->SetPS(0);

	VB->Set(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	VS->Set();
	PS->Set();
	DVC->Draw(vertices.size(), 0);

	// 이 클래스에서 정의된 적 없는 월드 버퍼/꼭지점 버퍼 등을 멀쩡히 쓰고 있는데,
	// 이는 이 부모 클래스가 추상 클래스이기 때문에 인스턴스를 만들 일이 없기 때문
	// -> 어차피 이 함수가 실제로 실행될 때는 이런 내용들이 전부 정의된 자식 클래스이기 때문에
	// 거기서 실행할 때는 아무런 문제가 없는 것
}

bool Collider::isCollision(Collider* collider, Vector2* overwrap)
{
	if (!is_active || !(collider->is_active)) 
		return false;

	switch (collider->type)
	// 이 클래스는 최소 2종류 이상의 자식 클래스를 가진 추상 클래스
	// 따라서 비교할 상대방의 실제 클래스가 무엇이냐에 따라
	// 사용해야 할 충돌 알고리즘이 달라지기 때문에 이를 분기문을 통해 분리
	{
	case TYPE::RECT:
		return isRectCollision((RectCollider*)collider, overwrap);

	case TYPE::CIRCLE:
		return isCircleCollision((CircleCollider*)collider);
		
	default:
		break;
	}
	

}
