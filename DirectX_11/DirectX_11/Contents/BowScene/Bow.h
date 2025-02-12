#pragma once
class Bow
{
public:
	Bow();
	~Bow();

	bool isFired = false;

	Vector GetDirection() { return _dir; }
	void SetDirection(Vector dir) { _dir = dir; }

	shared_ptr<Quad> GetCollider() { return _bow; }

	void Update();
	void Render();
private:
	shared_ptr<Quad> _bow;
	Vector _dir;

};

