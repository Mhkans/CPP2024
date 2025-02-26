#include "framework.h"

ScrollingBG::ScrollingBG(Vector2 pos, Vector2 size,
	Vector2 scale, float angle, Matrix* parent)
	: Transform(pos, scale, angle)
{
	/*
	�ܼ��� �׷����� ǥ���� ���� shape �迭 Ŭ������� �ϴ���,
	���� �� ������Ʈó�� �ϳ��� ������Ʈ�� �� �̻��� �̹����� �̿��ؾ� �� ��쿣
	shape �� ��ü�� Transform�� ������ �ִ� ���� �ξ� �ٷ�� ����

	-> ������ Transform�� ������ ���� shape Ŭ������ �ƴ�,
	Transform �����͸� ������ �ִ� shape Ŭ������ ���� �����δ� ���� �� �� ����
	�̿� �ش��ϴ� Ŭ������ Quad�� ���� ��
	
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
