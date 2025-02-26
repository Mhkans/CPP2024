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




	// assert(image->pos.x > 0);
	// 0 ������ ���� ���� ��� ��Ÿ�� ����� �߻���Ű��,
	// �������� ���� ��� ���⼭ �ڵ� ������ �Ͻ� �ߴܽ�Ű�� �ڵ�

	// �� ����� �̿��ϸ� ���� �ߴ����� ��Ȯ�� Ÿ�ֿ̹� Ŭ���Ϸ� �õ����� �ʾƵ�,
	// ���Ǹ� �´� ��� ���α׷��� �Ͻ������Ͽ� �� �ν��Ͻ��� ������ Ȯ���� �� ����

	// ��, �� �Լ��� "����� ���"�� ���� ����


	//if (image->pos.x <= 0)
	//	image->pos.x += WIN_WIDTH;

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

void ImageScene::PostRender()
{
	ImGui::SliderFloat2("image's pos", (float*)&image->pos, -WIN_WIDTH, WIN_WIDTH);
	ImGui::SliderFloat3("image's rot", (float*)&image->rot, -2 * M_PI, 2 * M_PI);
	// SliderFloatX : X���� �Ǽ� �����͸� �޾Ƽ�,
	//				  �̸� �����̴� �� �������� ImGui â�� ����Ͽ�
	//				  �ش� �������� ���� ���� Ȯ�� �� �������� ������ ����
	
	// ������ �Ű������� ������ ���� �ǹ� - 
	/*
	���ڿ� - "�� �ٸ� ���ؼ� �����ϰ� �� �����Ϳ� ���� �̸�"����,
			ImGui������ ������ ���� ���̶� ���� OK
			-> ���� �̸��� �ٸ� ImGui �׿��� ����� ���,
			������ ����Ű�� �����Ͱ� �ٸ����� �ұ��ϰ� �� ���� ���� �ǵ帮�� �ȴ�
			���� �������̸� �� �̸� = ID�� ��ġ���� �ʰ� ���� ��

	���� ������ - "�� �ٸ� ���ؼ� ������ �������� �ּ�"
				 �� ���� �����͸� �ٷ�� �� �������� �˸� �ǹǷ�,
				 ���� ������ ������ ��ġ���� �ʴ´� �ϴ���
				 �ٿ��� �ٷ�� �������� �������� ���⸸ �ϴٸ� OK

	MIN, MAX - �� �׿� ������� �����̴� ���� �ּҰ��� �ִ밪
			   ����Ű�� �������� �ѵ� ��ü�� �� ���� ���� ���������,
			   �� �� ������ ǥ�� ������ �ѵ�����
			   �� ���ÿ� �� �ٸ� ���ؼ� ���� ������ ���� �ѵ��� �̰� ���ؼ� ����
	*/

	player->PostRender();
}
