#include "framework.h"

ImageRect::ImageRect(Vector2 pos, Vector2 size)
{
	image = new RectUV(size, Vector2(0, 0), Vector2(1, 1));
	this->pos = pos;

	// �� �Ʒ��� ������ �ȼ����̴� ������ ������ �ڿ� �̾ ����

	ScratchImage img;
	// �̹��� �����͸� ��������, DXTex���� �����ϴ� Ŭ����

	LoadFromWICFile(L"Texture/Image/missile.jpg", WIC_FLAGS_NONE, nullptr, img);
	// ��� ���� �ν��Ͻ��� ������ �ҷ���

	CreateShaderResourceView(DEVICE, img.GetImages(), img.GetImageCount(),
		img.GetMetadata(), &srv);
	// �ҷ��� ������ �����͵��� �̿��� ���̴��� �ѱ� ���̴� ���ҽ� �並 ����� ��
	// �̷��� ������� srv�� ������ �ش� �ؽ�ó�� ������ �ִ� �°� �����͸� ����ϰ� �Ǹ�,
	// �׷� ſ�� �̰����� ������ �� �� ������ �˾Ƶ־� �ϴ� �߿��� ����
	// -�׷��� 2D������ �� �¹��� ������� �ʴٺ���, ���⼱ �ٷ��� �ʴ´�

	rotate_speed = M_PI / 2.0f;
}

ImageRect::~ImageRect()
{
	delete image;
	srv->Release();
}

void ImageRect::Update()
{
	if(KEY_PRESS('E'))
		rot.z += rotate_speed * DELTA;
	if(KEY_PRESS('Q'))
		rot.z -= rotate_speed * DELTA;

	WorldUpdate();
}

void ImageRect::Render()
{
	WB->SetVS(0);
	DVC->PSSetShaderResources(0, 1, &srv);
	// �̹����� �ε��� ���̴� ���ҽ� �並 ����̽��� ���

	image->Render();
}
