#pragma once
class CircleCollider
{

public:

	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update();
	void Render(HDC hdc);

	Vector _center;
	float _radius;

};
//�� �簢�� 
