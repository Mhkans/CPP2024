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
	void SetArrowSpeedn(float value) { _arrowSpeed = value; }

	void Update();
	void Render();

private:
	shared_ptr<Quad> _arrow;
	//weak_ptr<class Bow> _bow;
	float _angle = 0;
	float _arrowSpeed = 0.2f;
};

