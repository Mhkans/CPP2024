#include "framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	_sun = make_shared<Quad>(L"Resource/sun.png");
	_earth = make_shared<Quad>(L"Resource/earth.png");

	_sun->GetTransform()->SetScale({ 0.5f, 0.5f });
	_sun->GetTransform()->SetLocation(CENTER);

	_earth->GetTransform()->SetScale({ 0.2f, 0.2f });
	_earth->GetTransform()->SetLocation(Vector(500, 0));

	// Matrix의 종속
	// => 좌표계 변환
	_earth->GetTransform()->SetParent(_sun->GetTransform());
}

SolarSystemScene::~SolarSystemScene()
{
}

void SolarSystemScene::Update()
{
	_sun->Update();
	_earth->Update();

	_sun->GetTransform()->AddAngle(0.0001f);
}

void SolarSystemScene::Render()
{
	_sun->Render();
	_earth->Render();
}
