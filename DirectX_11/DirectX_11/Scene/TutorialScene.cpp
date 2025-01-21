#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad1 = make_shared<Quad>(L"Resource/SCS.png");
	_quad2 = make_shared<Quad>(L"Resource/SCS2.png");

	_quad1->SetScale({ 0.5f, 0.5f });
	_quad1->SetAngle(0.0005f);
	_quad1->SetPos({ WIN_WIDTH * 0.3f,WIN_HEIGHT * 0.3f });

	_quad2->SetScale({ 0.5f, 0.5f });
	_quad2->SetAngle(-0.0005f);
	_quad2->SetPos({ WIN_WIDTH * 0.7f,WIN_HEIGHT * 0.7f });
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_quad1->Update();
	_quad2->Update();
}

void TutorialScene::Render()
{
	_quad1->Render();
	_quad2->Render();
}
