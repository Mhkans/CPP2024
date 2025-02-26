#include "framework.h"
#include "ImageScene.h"

ImageScene::ImageScene()
{
	image = new ImageRect(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(80, 300));
	player = new ImageRect(Vector2(0, 0), Vector2(80, 300));

	bg = new ScrollingBG(Vector2(WIN_CENTER_X, WIN_CENTER_Y),
		Vector2(WIN_WIDTH, WIN_HEIGHT));
}

ImageScene::~ImageScene()
{
	delete player;
	delete image;
	delete bg;
}

void ImageScene::Update()
{
	player->pos = mouse_pos;

	if (KEY_PRESS(VK_F2))
		image->pos = { WIN_CENTER_X, WIN_CENTER_Y };


	if(Control::Get()->Press(VK_LEFT)) // ���� Ű �ڵ带 �̿��� � Ű�� �˻��� �������� ���
		image->pos.x -= WIN_WIDTH / 2 * DELTA;



	if (image->pos.x <= 0)
		image->pos.x += WIN_WIDTH;

	player->Update();
	image->Update();
	bg->Update();
}

void ImageScene::Render()
{
	bg->Render();
	player->Render();
	image->Render();
}
