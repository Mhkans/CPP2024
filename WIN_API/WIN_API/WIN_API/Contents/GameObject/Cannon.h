#pragma once

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	const Vector& GetCenter() { return _body->Center(); }

	void Fire();
	void Ready() { _barrel->SetCannon(shared_from_this()); }

private:
	// 입력으로 좌우로 움직이게 만드는 함수
	void InputMove();
	// 입력으로 총신의 각도가 +,-가 되게 만드는 함수
	void InputBarrelRotation();

private:	
	shared_ptr<CircleCollider> _body;
	shared_ptr<Barrel> _barrel;	
	vector< shared_ptr<Ball>> _balls;
	int _ballCount = 3;
	int _index = 0;
	bool _spacebarPressed = false;
};

