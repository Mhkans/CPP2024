#pragma once
class Arrow
{
public:
	Arrow(shared_ptr<class Bow> bow);
	~Arrow();

	bool isActive = false;
	shared_ptr<Quad> GetArrow() { return _arrow; }
	shared_ptr<CircleCollider>GetCollider() { return _collider; }

	float GetArrowSpeed() { return _arrowSpeed; }
	void SetDir(Vector dir) { _dir = dir.Normalize(); _arrow->GetTransform()->SetAngle(_dir.Angle()); }

	void PreUpdate();
	void Update();
	void Render();
	void PostRender();

	//�浹ó�� �ݹ�ó��
	bool Collision(shared_ptr<class Bow_Monster> monster);
private:
	shared_ptr<Quad> _arrow;
	shared_ptr<CircleCollider> _collider; //����ü�� �ڿ��� ���ԸԴ� ���� (��)
	Vector _dir;

	weak_ptr<class Bow> _bow;
	float _arrowSpeed = 500.0f;
};

