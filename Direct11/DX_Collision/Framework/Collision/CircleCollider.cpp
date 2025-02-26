#include "framework.h"

void CircleCollider::CreateLine()
{
	float angle = 2 * M_PI;

	for (int i = 0; i <= 50; i++)
	{
		vertices.emplace_back(
			cos(angle) * radius,
			sin(angle) * radius);
		angle -= 2.0f * M_PI / 50.0f;
	}

	VB = new VertexBuffer(vertices.data(), sizeof(VertexPos), vertices.size());
}

CircleCollider::CircleCollider(float rad)
	:	radius(rad)
{
	type = TYPE::CIRCLE;
	CreateLine();
}

CircleCollider::~CircleCollider()
{
	delete VB;
}

bool CircleCollider::isPointCollision(Vector2 point)
{
	float distance = (this->pos - point).GetLength();
	if (distance < radius)
		return true;
	else
	    return false;
}

bool CircleCollider::isCircleCollision(CircleCollider* collider)
{
	float distance = (this->pos - collider->pos).GetLength();
	if (distance < radius + collider->GetRadius())
		return true;
	else
		return false;
}

bool CircleCollider::isRectCollision(RectCollider* collider, Vector2* overwrap)
/*
사각형의 모든 점 중 원과 제일 가까운 점이 어디인지를 계산
그 점이 원 안에 들어있는지 아닌지를 통해 충돌 여부를 확인하는 방식

단, 그냥 이대로만 계산하면 사각형의 회전엔 대응하지 못하는 관계로
그 회전에 대응하기 위해-

아예 충돌여부를 계산할 때에 한정하여 "화면 자체를 돌려버리는 식"으로 보정하는 과정이 필요함
즉, 공간 전체를 "사각형이 화전하지 않은 상태로 가정"하여
오브젝트 등을 계산하는 위치를 사각형의 중앙점으로 잡아서 새 공간에서 계산하는 방식
*/
{

	Matrix T = XMMatrixTranslation(pos.x - collider->pos.x, pos.y - collider->pos.y, 0.0f);
	// 사각형의 회전에 따른 보정을 위하여
	// 여기서만 사용할 임시 웓드에 적용할 T 변환 행렬
	// 여기서는 사각형의 좌표를 기준으로 계산하는 것

	// 어디까지나 이번 충돌판정에 사용할 내용을 적어둘 것 뿐이므로
	// 이 오브젝트 = 원 충돌판정의 트랜스퓨ㅗㅁ이 가지고 있는 T행렬을 건드려선 안 됨
	// 따라서 여기 새로 작성

	Matrix circle_world = S * R * T;
	// S,R은 이 원이 가진 트랜스폼에서 월드 업데이트할 때 사용했던 값을 그대로 이용,
	// T 행렬만 위의 행렬로 교체하여 중앙점(=원점)을 사각형의 중심점으로 이동

	circle_world *= XMMatrixRotationZ(-collider->rot.z);
	// 그렇게 구한 새로운 월드 행렬에 사각형이 회전해있는 만큼 반대방향으로 회전시킴

	// 이 일련의 작업들을 통해 "사각형이 회전하지 않았다 가정했을 때"의 사각형과 원의 위치를
	// 임시로 구현함

	XMFLOAT4X4 temp_matrix;
	XMStoreFloat4x4(&temp_matrix, circle_world);
	// 위에서 구한 행렬을 사용하기 편한 형태인 Float4x4 행렬에 복사,

	Vector2 circle_obb_center = Vector2(temp_matrix._41, temp_matrix._42));
	// 위의 행렬에서 pos 정보만을 추출
	// 그렇게 추출된 데이터가 원의 "저 가상공간에서의 좌표"

	// 이 데이터를 이용해서 상술한 알고리즘을 이행

	Vector2 half = collider->Size() * 0.5f;
	Vector2 closest; // 원에 제일 가까운 사각형의 점


	if (circle_obb_center.x < -half.x)
		closest.x = -half.x;
	else if (circle_obb_center.x > half.x)
		closest.x = half.x;
	else
		closest.x = circle_obb_center.x;

	if (circle_obb_center.y < -half.y)
		closest.y = -half.y;
	else if (circle_obb_center.y > half.y)
		closest.y = half.y;
	else
		closest.y = circle_obb_center.y;

	return (circle_obb_center - closest).GetLength() < GetRadius();
}

/*

과제 :

위에서 이렇게 만든 원-사각형 충돌 함수를
사각형 측에서도 사각형-원 충돌 함수로서 구현해볼 것

*/