#pragma once

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();
	void PostInitialize() { Ready(); }

	void Update();
	void Render(HDC hdc);

	const Vector& GetCenter() { return _body->Center(); }

	void Fire();
	bool IsFireReady()
	{
		_fireTime += 0.01f;
		if (_fireTime > _fireDelay)
		{
			_fireTime = 0.0f;
			return true;
		}

		return false;
	}
private:
	void Ready() { _barrel->SetCannon(shared_from_this()); }

	// �Է����� �¿�� �����̰� ����� �Լ�
	void InputMove();
	// �Է����� �ѽ��� ������ +,-�� �ǰ� ����� �Լ�
	void InputBarrelRotation();

private:	
	shared_ptr<CircleCollider> _body;
	shared_ptr<Barrel> _barrel;	
	vector< shared_ptr<Ball>> _ballPool;
	int _ballCount = 30;
	int _index = 0;
	bool _spacebarPressed = false;
	float _fireDelay = 0.5f; // 1�ʸ� ��Ȯ�� �� �� ������? X
	float _fireTime = 0.0f;
};

