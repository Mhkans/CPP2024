#pragma once
#include "Collider.h"
class RectCollider :public Collider
{
private:
	struct OBB {
		Vector position;
		Vector direction[2];
		float length[2];
	};
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	void Update() override;
	void Render() override;

	bool IsCollision(const Vector& pos)override; //Á¡Ãæµ¹
	bool IsCollision(shared_ptr<class CircleCollider> circle)override;
	bool IsCollision(shared_ptr<class RectCollider> rect)override;

	OBB GetOBB();

	Vector GetHalfSize() { return _halfSize; }
	void SetHalfSize(Vector vec) { _halfSize = vec; }

protected:
	void CreateVertices() override;
	Vector _halfSize;

};

