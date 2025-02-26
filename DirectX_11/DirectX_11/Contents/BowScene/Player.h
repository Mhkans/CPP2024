#pragma once
#include"Bow.h"
class Player : public enable_shared_from_this<Player>
{
public:
	Player();
	~Player();

	void Init();

	void PreUpdate();
	void Update();

	void Render();
	void PostRender();

	void Input();
	void Jump();
	
	bool isFalling = true;
	shared_ptr<RectCollider> GetCollider() { return _body; }
	vector<shared_ptr<class Arrow>> GetArrows() { return _bow->GetArrows(); }
private:
	shared_ptr<Quad> _quad;
	shared_ptr<RectCollider> _body;

	float _speed = 300.0f;
	float _jumpForce = 0.0f;

	shared_ptr<class Bow> _bow;
	
};

