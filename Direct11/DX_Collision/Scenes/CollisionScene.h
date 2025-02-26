#pragma once
class CollisionScene : public Scene 
{
private:
	RectCollider* player_m; // 마우스로 움직이는 내 오브젝트
	RectCollider* player_k; // 키보드로 움직이는 내 오브젝트

public:
	CollisionScene();
	~CollisionScene();

	// Inherited via Scene
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

};
