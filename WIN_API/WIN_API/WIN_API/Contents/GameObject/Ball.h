#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc); 

	void SetCenter(Vector center) { _ball->Center() = center; }
	Vector GetDirection() { return _direction; }
	void SetDirection(const Vector& dir) { _direction = dir; }
	void SetPos(const Vector& pos) { _ball->Center() = pos; }
	const Vector& GetPos() { return _ball->Center(); }
	void Fire(Vector pos, Vector dir);
	bool& IsActive() { return _isActive; }
	bool IsOut();
	shared_ptr<Collider> GetCollider() { return _ball; }
private:
	shared_ptr<CircleCollider> _ball;
	Vector _direction = Vector(1,0);
	float _speed = 30.0f;
	float _gravity = 0.0f;
	bool _isActive = false;
};

