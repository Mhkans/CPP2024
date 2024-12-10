#pragma once
class FortressScene : public Scene
{
public: 
	FortressScene();
	~FortressScene();
	virtual void PostInitialize() override;
	void Update() override;
	void Render(HDC hdc) override;
private:
	shared_ptr<Cannon> _cannon1;
	shared_ptr<Cannon> _cannon2;

};

