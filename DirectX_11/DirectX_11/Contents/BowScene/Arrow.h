#pragma once
#include <Scene/BowScene.h>
class Arrow
{
public:
	Arrow();
	~Arrow();

	bool isActive = false;

	void SetAngle(float angle) { _angle = angle; }

	shared_ptr<Quad> GetCollider() { return _arrow; }

	float GetArrowSpeed() { return _arrowSpeed; }

	void Update();
	void Render();
	void PostRender();

private:
	shared_ptr<Quad> _arrow;
	shared_ptr<CircleCollider> _collider; //투사체는 자원을 적게먹는 원형 (구)
	float _angle = 0;
	float _arrowSpeed = 300.0f;
};

