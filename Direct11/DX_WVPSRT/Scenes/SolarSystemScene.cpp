#include "framework.h"

SolarSystemScene::SolarSystemScene()
{
	sun = new Planet(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(1, 1), 0.0f,
		50.0f, 30, 0.0002f);
	sun->SetColor(Float4(242.0f / 256.0f, 184.0f / 256.0f, 6.0f / 256.0f, 1.0f));

	mercury = new Planet(Vector2(100.0f, 0), Vector2(1, 1), 0,
		30.0f, 4, 0.0001f);

	venus = new Planet(Vector2(180.0f, 0), Vector2(1, 1), 0,
		40.0f, 7, -0.00015f);
	venus->SetColor({ 0.7f, 0.5f, 0.2f, 1.0f });

}

SolarSystemScene::~SolarSystemScene()
{
	delete sun;
	delete mercury;
	delete venus;
}

void SolarSystemScene::Update()
{
	sun->Update();
	mercury->Update(sun->GetWorld());
	venus->Update(sun->GetWorld());
}

void SolarSystemScene::Render()
{
	sun->Render();
	mercury->Render();
	venus->Render();
}

/*
���� ) �ϼ����� ���� �¾�踦 �ڱ� ������ ���� �ϼ����Ѻ���

���� - 
1) �ּ��� ������ȭ������ ���� ��
+ �ޱ����� ���� ��

2) ������ õü���� ���� �����ӵ��� �����ӵ��� �ٸ� ��
(������ �ݼ��� �ð� �ݴ� �����̰� �������� ����, ���ǰ� ��ġ���� �ʾƵ� ��)

3) ��� õü���� ���� �ٸ� �ٰ����� ��

*/