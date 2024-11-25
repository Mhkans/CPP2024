#pragma once
class RectangleCollider:public Collider
{
public:
	struct OBB_INFO {

		Vector position;
		Vector direction[2]; //���μ��� ����
		float length[2]; //���� ���� ����

	};
	RectangleCollider(Vector center, Vector size);
	virtual ~RectangleCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	int Left()const { return _center.x - _halfSize.x; }
	int Right()const { return _center.x + _halfSize.x; }
	int Top()const{ return _center.y - _halfSize.y; }
	int Bottom()const { return _center.y + _halfSize.y; }

	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<RectangleCollider> other) const override;

	OBB_INFO GetOBB() const;
	float SeperateAxis(Vector seperate, Vector e1, Vector e2)const;
private:
	
	Vector _halfSize;
	
};

