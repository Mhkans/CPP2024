#pragma once
class LineScene : public Scene
{
public:
	LineScene();
	~LineScene();
	virtual void PostInitialize() override {}

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Liner> _line1;
	shared_ptr<Liner> _line2;
	shared_ptr<Liner> _line3;

	shared_ptr<Collider> _circle;

};

