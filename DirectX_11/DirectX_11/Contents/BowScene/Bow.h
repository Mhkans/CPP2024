#pragma once
class Bow :public enable_shared_from_this<Bow>
{
public:
	Bow();
	~Bow();

	void Init();

	bool isFired = false;

	Vector GetDirection() { return _dir; }
	void SetDirection(Vector dir) { _dir = dir; }

	shared_ptr<RectCollider> GetCollider() { return _collider; }
	vector<shared_ptr<class Arrow>> GetArrows() { return _arrows; }

	void PreUpdate();
	void Update();
	void Render();
	void PostRender();

	void ShootArrow();
private:
	shared_ptr<Quad> _bow;
	shared_ptr<RectCollider> _collider;
	Vector _dir;

	vector<shared_ptr<class Arrow>> _arrows;
	int _arrowCount = 10;
	float _delay = 0.0f;

	weak_ptr<class Player> _player;
};

