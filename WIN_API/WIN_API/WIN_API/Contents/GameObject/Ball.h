#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);
	void SetCenter(Vector center) { _ball->Center() = center; }
	void SetDirection(Vector dir) { _direction = dir; }
	Vector GetDirection() { return _direction; }

private:
	shared_ptr<CircleCollider> _ball;
	Vector _direction = Vector(-1000,0);
	float _speed = 30.0f;;
};

