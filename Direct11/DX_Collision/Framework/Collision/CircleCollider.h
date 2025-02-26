#pragma once
/* 
원형 충돌 판정은 다른 오브젝트와 어떻게 충돌 판정을 할까?

이 중에서 원-사각형끼리는 제일 난이도가 높으니 패스
원-점, 원-원 사이가 충돌했는지를 판단하는 것은 어떻게 하는 것일까

원 - 점 : 원이라는 것은 원점에서 정확히 일정 거리 떨어진 점의 집합이므로
		  검사하고자 하는 점과 원의 원점 사이의 거리가 반지름보다 작다면 충돌한 것
원 - 원 : 두 원의 반지름의 합보다 두 원의 중심끼의 거리가 더 가까우면
		  서로의 방향으로 반지름만큼 그었을 때 겹치는 부분이 존재, 즉 충돌한 것
*/

class CircleCollider : public Collider
{
private:
	float radius;
	// 여기선 타원은 고려하지 않고 원만 작성
	virtual void CreateLine() override;

public:
	CircleCollider(float rad);
	~CircleCollider();

	float GetRadius()
	{
		return radius;
	}

	// Inherited via Collider
	virtual bool isPointCollision(Vector2 point) override;
	virtual bool isCircleCollision(CircleCollider* collider) override;
	virtual bool isRectCollision(RectCollider* collider, Vector2* overwrap = NULL) override;
};