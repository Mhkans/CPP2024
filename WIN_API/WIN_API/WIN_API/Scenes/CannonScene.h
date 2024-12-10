#pragma once
class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();
	virtual void PostInitialize() override { _cannon->PostInitialize(); }

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<class Cannon> _cannon;
};

