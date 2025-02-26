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

	//충돌처리 콜백처리
	bool Collision(shared_ptr<class Bow_Monster> monster);
private:
	shared_ptr<Quad> _arrow;
	shared_ptr<CircleCollider> _collider; //투사체는 자원을 적게먹는 원형 (구)
	Vector _dir;

	weak_ptr<class Bow> _bow;
	float _arrowSpeed = 500.0f;
};

