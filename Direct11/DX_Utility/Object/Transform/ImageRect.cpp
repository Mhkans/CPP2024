#include "framework.h"

ImageRect::ImageRect(Vector2 pos, Vector2 size)
{
	image = new RectUV(size, Vector2(0, 0), Vector2(1, 1));
	this->pos = pos;

	// 이 아래의 내용은 픽셀셰이더 측에서 설명한 뒤에 이어서 설명

	ScratchImage img;
	// 이미지 데이터를 저장해줄, DXTex에서 제공하는 클래스

	LoadFromWICFile(L"Texture/Image/missile.jpg", WIC_FLAGS_NONE, nullptr, img);
	// 방금 만든 인스턴스에 파일을 불러옴

	CreateShaderResourceView(DEVICE, img.GetImages(), img.GetImageCount(),
		img.GetMetadata(), &srv);
	// 불러온 파일의 데이터들을 이용해 셰이더에 넘길 셰이더 리소스 뷰를 만드는 것
	// 이렇게 만들어진 srv는 앞으로 해당 텍스처가 가지고 있는 온갖 데이터를 담당하게 되며,
	// 그런 탓에 이것으로 무엇을 할 수 있을지 알아둬야 하는 중요한 개념
	// -그러나 2D에서는 그 태반을 사용하지 않다보니, 여기선 다루지 않는다

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
	// 이미지가 로딩된 셰이더 리소스 뷰를 디바이스에 등록

	image->Render();
}
