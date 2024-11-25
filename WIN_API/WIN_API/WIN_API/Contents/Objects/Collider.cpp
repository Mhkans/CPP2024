#include "framework.h"
#include "Collider.h"

Collider::Collider() 
{
}

Collider::~Collider()
{
}



bool Collider::IsCollision(shared_ptr<Collider> collider) const// -> 내부에서 안고치면 const
{
	switch (collider ->_type) 
	{
	case Collider::NONE:
		return false;
		
	case Collider::CIRCLE: {
		shared_ptr<CircleCollider> circle = dynamic_pointer_cast<CircleCollider>(collider);
		return IsCollision(circle);
		
	}
	case Collider::RECT: {
		shared_ptr<RectangleCollider> rect = dynamic_pointer_cast<RectangleCollider>(collider);
		return IsCollision(rect);

	}
		
	default:
		break;
	}


	
}
