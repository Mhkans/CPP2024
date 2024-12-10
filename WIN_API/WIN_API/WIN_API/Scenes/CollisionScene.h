#pragma once
class CollisionScene:public Scene
{
public:

	CollisionScene();
	~CollisionScene();
	virtual void PostInitialize() override {}

	virtual void Update() override;
	virtual void Render(HDC hdc) override;


private:
	shared_ptr<Collider> _moved;
	shared_ptr<Collider> _fixed; 


};

