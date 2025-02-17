#include "framework.h"
#include "Collider.h"
#include "RectCollider.h"
#include "CircleCollider.h"

bool Collider::IsCollision(shared_ptr<Collider> other)
{
	int typeNum = other->GetType();

	switch (typeNum) {
	case 1: {
		shared_ptr<RectCollider> rect = dynamic_pointer_cast<RectCollider>(other);
		return IsCollision(rect);
	}
	case 2: {
		shared_ptr<CircleCollider> circle = dynamic_pointer_cast<CircleCollider>(other);
		return IsCollision(circle);
	}
	default:
		break;
	}

	return false;
}
