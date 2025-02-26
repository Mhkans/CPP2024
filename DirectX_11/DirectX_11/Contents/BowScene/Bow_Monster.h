#pragma once
class Bow_Monster
{
public:
	Bow_Monster();
	~Bow_Monster();

	bool isActive = true;

	void SetValue(float value);

	void PreUpdate();
	void Update();
	void Render();
	void PostRender();

	shared_ptr<Quad> GetMonster() { return _quad; }
	shared_ptr<CircleCollider>GetCollider() { return _body; }

	void SetHP(float value) { _HP = value; }
	float GetHP() { return _HP; }

	void BossMove();
	void BossAttack();

	Vector GetBossDir() { return _dir; }
	void SetBossDir(Vector v) { _dir = v.Normalize(); }
private:
	shared_ptr<Quad> _quad;
	shared_ptr<CircleCollider> _body;
	float _HP;
	const float& _maxHP = 500.0f;

	Vector _dir = Vector(1, 1).Normalize();
	float _speed = 500.0f;
};

