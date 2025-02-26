#include "framework.h"
#include "DungreedScene.h"
#include "Contents/BowScene/Arrow.h"
#include "Contents/BowScene/Player.h"
#include"Contents/BowScene/Map/Track.h"
#include "Contents/BowScene/Bow_Monster.h"
#include "Contents/UI/HpBar.h"
DungreedScene::DungreedScene()
{
	_player = make_shared<Player>();
	_boss = make_shared<Bow_Monster>();
	_bg = make_shared<Quad>(L"Resource/bg.png");
	_track = make_shared<Track>();

	_hpBar = make_shared<HpBar>(CENTER + Vector(-400,300),Vector(200,50));

	_effect = make_shared<Effect>(L"Resource/Effects/hit_4X2.png", Vector(4, 2), 0.1f, Action::END);

	_bg->GetTransform()->SetLocalLocation(CENTER);
	_bg->Update();

}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::PreUpdate()
{
	_player->PreUpdate();
	_boss->PreUpdate();
	_track->PreUpdate();
}

void DungreedScene::Update()
{
	_track->Update();
	_player->Update();
	_boss->Update();
	auto arrows = _player->GetArrows();
	for (auto arrow : arrows) {
		if (arrow->Collision(_boss)) {
			auto pos = arrow->GetCollider()->GetTransform()->GetWorldLocation();
			_effect->Play(pos);
			arrow->isActive = false;
		}
	}
	_hpBar->Update();
	_track->Block(_player);
	_effect->Update();

}

void DungreedScene::Render()
{
	_bg->Render();
	_track->Render();

	_player->Render();
	_boss->Render();
	_effect->Render();
	_hpBar->Render();

}

void DungreedScene::PostRender()
{
	
	_player->PostRender();
	_boss->PostRender();

	_track->PostRender();
	_effect->PostRender();

}
