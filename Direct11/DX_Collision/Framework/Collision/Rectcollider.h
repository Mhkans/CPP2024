#pragma once
class RectCollider : public Collider
{
public:
	struct ObbDesc // OBB 충돌 때 사용할,
		// 현재 이 충돌판정의 회전상황을 반영해서
		// 실제로 계산할 떄 이용할 데이터를 정의한 구조체
	{
		Vector2 pos; // 좌표(=중앙점)
		Vector2 Axis[2]; // 회전된 충돌판정의 축을 따로 기록해두는 배열
		Vector2 half_size; // 이 회전된 충돌판정의 상하/좌우 크기
	};

private:
	Vector2 size;
	ObbDesc obb_desc;

	virtual void CreateLine() override;

	bool isAABB(RectCollider* rect, Vector2* overwrap = NULL);
	bool isAABB(class CircleCollider* circle, Vector2* overwrap = NULL);
	bool isOBB(RectCollider* rect);
	bool isOBB(class CircleCollider* circle);
	// 각각의 알고리즘에 따라 사각형/원형 충돌판정과 겹치는지의 여부를 계산하는 함수들

	float separateAxis(Vector2 seperate, Vector2 e1, Vector2 e2);
	// OBB 충돌처리의 연산괒어 도중 사용할 함수
	// 이 함수가 무엇인지는 OBB 알고리즘을 만들 때 구현하면서 설명

public:
	RectCollider(Vector2 size);
	~RectCollider();

	RectCollider::ObbDesc GetObbDesc(); // 호출된 시점에서 이 충돌판정의 회전이 반영된,
	// 실제 충돌판정 데이터를 그 자리에서 계산해 반환하는 코드

	// Inherited via Collider
	virtual bool isPointCollision(Vector2 point) override;

	virtual bool isCircleCollision(class CircleCollider* collider) override;

	virtual bool isRectCollision(RectCollider* collider, Vector2* overwrap = NULL) override;

	// 이 충돌판정이 화면 기준으로 실제로 얼마만큼의 사이즈를 가지고 있는지
	// 전체 화면 기준의 길이로 환산해 반환
	Vector2 Size() { return size * GlobalScale(); }

	float RightVX() { return GlobalPos().x + Size().x * 0.5f; }
	float LeftVX() { return GlobalPos().x - Size().x * 0.5f; }
	float TopVX() { return GlobalPos().y - Size().y * 0.5f; }
	float BottomVX() { return GlobalPos().y + Size().y * 0.5f; }
	// 이상의 4개 함수들은 AABB 충돌 처리과정에서 사용되는,
	// 이 충돌판정의 상/하/좌/우 각각의 끝자락의 좌표를 계산하는 함수

};