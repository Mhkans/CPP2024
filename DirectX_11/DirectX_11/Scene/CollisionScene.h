#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	void Update() override;
	void Render() override;

	void Input();
private:
	shared_ptr<CircleCollider> _circle1;
	shared_ptr<CircleCollider> _circle2;
	shared_ptr<CircleCollider> _circle3;
};

