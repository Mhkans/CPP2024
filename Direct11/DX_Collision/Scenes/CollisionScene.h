#pragma once
class CollisionScene : public Scene 
{
private:
	RectCollider* player_m; // ���콺�� �����̴� �� ������Ʈ
	RectCollider* player_k; // Ű����� �����̴� �� ������Ʈ

public:
	CollisionScene();
	~CollisionScene();

	// Inherited via Scene
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

};
