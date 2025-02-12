#pragma once
class BowScene : public Scene
{
public:
	BowScene();
	~BowScene();

	void ShootArrow(float angle);
	void SetAngle(shared_ptr<Quad> obj, float angle);

	void Update() override;
	void Render() override;
private:
	shared_ptr<class Bow> _bow;
	vector<shared_ptr<class Arrow>> _arrows;
	shared_ptr<Transform> _tip;

	int _arrowCount = 10;
	float angle;

	const float _delay = 200.0f;
	float _deltaTime = 0.0f;

	shared_ptr<RectCollider> _rect;
	shared_ptr<CircleCollider> _circle;
};

