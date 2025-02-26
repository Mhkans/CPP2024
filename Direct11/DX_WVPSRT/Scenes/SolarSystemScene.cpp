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
과제 ) 완성되지 않은 태양계를 자기 손으로 직접 완성시켜보기

조건 - 
1) 최소한 수금지화까지는 만들 것
+ 달까지도 만들 것

2) 각각의 천체들은 전부 자전속도와 공전속도가 다를 것
(방향은 금성만 시계 반대 방향이고 나머지는 자율, 현실과 일치하지 않아도 됨)

3) 모든 천체들은 서로 다른 다각형일 것

*/