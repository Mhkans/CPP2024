#pragma once
class BowScene : public Scene
{
public:
	BowScene();
	~BowScene();

	void ShootArrow(float angle);
	void SetAngle(shared_ptr<Quad> obj, float angle);

	void PreUpdate()override;
	void Update() override;

	void Render() override;
	void PostRender()override;
private:
	shared_ptr<class Bow> _bow;
	vector<shared_ptr<class Arrow>> _arrows;
	shared_ptr<class Bow_Monster> _monster;

	shared_ptr<Transform> _tip;

	int _arrowCount = 10;
	float angle;

	const float _delay = 0.5f;
	float _deltaTime = 0.0f;
};

