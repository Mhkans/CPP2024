#pragma once
//Collider : �浹ü
class RectangleCollider;

class CircleCollider :public Collider
{
public:
	
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;


	float& Radius() { return _radius; }
	
	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<RectangleCollider> other) const override;

	
private:

	float _radius;

};

