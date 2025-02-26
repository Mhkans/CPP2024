#include "framework.h"

ScrollingBG::ScrollingBG(Vector2 pos, Vector2 size,
	Vector2 scale, float angle, Matrix* parent)
	: Transform(pos, scale, angle)
{
	/*
	단순히 그래픽을 표기할 뿐인 shape 계열 클래스라고 하더라도,
	지금 이 오브젝트처럼 하나의 오브젝트가 둘 이상의 이미지를 이용해야 할 경우엔
	shape 그 자체가 Transform을 가지고 있는 것이 훨씬 다루기 편함

	-> 기존의 Transform을 가지지 않은 shape 클래스가 아닌,
	Transform 데이터를 가지고 있는 shape 클래스를 새로 만들어두는 것이 좀 더 편함
	이에 해당하는 클래스인 Quad를 만들 것
	
	*/

	image[0] = new Quad(size, Vector2(1, 1), Vector2(0, 0), Vector2(1, 1));
	image[0]->pos = pos;
	image[0]->SetActive(true);

	image[1] = new Quad(size, Vector2(1, 1), Vector2(1, 0), Vector2(2, 1));
	image[1]->pos = pos + Vector2(WIN_WIDTH, 0);
	image[1]->SetActive(true);

	ScratchImage img;

	LoadFromWICFile(L"Texture/Image/SpaceBackground.jpg", WIC_FLAGS_NONE, nullptr, img);

	CreateShaderResourceView(DEVICE, img.GetImages(), img.GetImageCount(),
		img.GetMetadata(), &srv);
}

ScrollingBG::~ScrollingBG()
{
	for (auto i : image)
		delete i;
	srv->Release();

}

void ScrollingBG::Update()
{
	for (auto i : image)
	{
		i->pos.x -= 0.1f;
		if (i->pos.x <= -WIN_CENTER_X)
			i->pos.x += WIN_WIDTH * 2;

		i->WorldUpdate();
	}
	WorldUpdate();
}

void ScrollingBG::Render()
{
	WB->SetVS(0);
	DVC->PSSetShaderResources(0, 1, &srv);

	image[0]->Render();
	image[1]->Render();
}
