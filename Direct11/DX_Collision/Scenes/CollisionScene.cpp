#include "framework.h"

CollisionScene::CollisionScene()
{
	player_m = new RectCollider({ 200,200 });
	player_m->pos = mouse_pos;
	player_m->SetActive(true);

	player_k = new RectCollider({ 400,100 });
	player_k->pos = {WIN_CENTER_X, WIN_CENTER_Y};
	player_k->SetActive(true);
}

CollisionScene::~CollisionScene()
{
	delete player_m;
	delete player_k;
}

void CollisionScene::Update()
{

	if (KEY_PRESS('E'))
		player_k->rot.z += 2 * M_PI * DELTA;
	if (KEY_PRESS('Q'))
		player_k->rot.z -= 2 * M_PI * DELTA;



	player_m->pos = mouse_pos;



	if (player_k->isRectCollision(player_m))
	{
		player_k->SetColor(0, 0, 1);
	}
	else
	{
		player_k->SetColor(0, 1, 0);
	}
	
	if (player_m->isRectCollision(player_k))
	{
		player_m->SetColor(0, 0, 1);
	}
	else
	{
		player_m->SetColor(0, 1, 0);
	}
	if (player_k->isPointCollision(mouse_pos))
	{
		player_k->SetColor(1, 0, 0);
	}
	else
	{
		player_k->SetColor(0, 1, 0);
	}

	player_m->WorldUpdate();
	player_k->WorldUpdate();


}

void CollisionScene::Render()
{
	player_m->Render();
	player_k->Render();

}

void CollisionScene::PostRender()
{
	ImGui::SliderFloat2("player_k's pos", (float*)&player_k->pos, 0, WIN_WIDTH);

	ImGui::SliderFloat3("player_k's rot", (float*)&player_k->rot, -2 * M_PI, 2 * M_PI);

}
