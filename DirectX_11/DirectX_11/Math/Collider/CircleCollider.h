#pragma once
#include "Collider.h"
class CircleCollider :public Collider
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update() override;
	void Render() override;

	bool IsCollision(const Vector& pos)override; //Á¡Ãæµ¹
	bool IsCollision(shared_ptr<class RectCollider> rect)override;
	bool IsCollision(shared_ptr<class CircleCollider> circle)override;

	float Radius() { return _radius * _transform->GetWorldScale().x; }
protected:
	void CreateVertices() override;
	float _radius;	
	int vCount = 37;
	float angle = 2 * PI / vCount;
};

