#include "framework.h"
#include "ImageScene.h"

ImageScene::ImageScene()
{
	image = new ImageRect(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(80, 300));

	bg = new ScrollingBG(Vector2(WIN_CENTER_X, WIN_CENTER_Y),
		Vector2(WIN_WIDTH, WIN_HEIGHT));
}

ImageScene::~ImageScene()
{
	delete image;
	delete bg;
}

void ImageScene::Update()
{
	image->Update();
	bg->Update();
}

void ImageScene::Render()
{
	bg->Render();
	image->Render();
}
