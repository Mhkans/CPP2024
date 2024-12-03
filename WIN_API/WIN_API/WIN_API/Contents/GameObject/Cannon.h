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
	// �Է����� �¿�� �����̰� ����� �Լ�
	void InputMove();
	// �Է����� �ѽ��� ������ +,-�� �ǰ� ����� �Լ�
	void InputBarrelRotation();

private:	
	shared_ptr<CircleCollider> _body;
	shared_ptr<Barrel> _barrel;	
	vector< shared_ptr<Ball>> _balls;
	int _ballCount = 3;
	int _index = 0;
	bool _spacebarPressed = false;
};

