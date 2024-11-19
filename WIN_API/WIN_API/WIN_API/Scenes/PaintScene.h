#pragma once
class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();

	void Update() override;
	void Render(HDC hdc)override;

private:
	shared_ptr<CircleCollider> myCircle = make_shared<CircleCollider>(Vector(200, 200), 70);
	shared_ptr<Liner> myLine = make_shared<Liner>(Vector(300, 300), Vector(400, 400));
	shared_ptr<RectangleCollider> myRect = make_shared<RectangleCollider>(Vector(500, 500), Vector(100, 100));
};
