#include "framework.h"
#include "FortressScene.h"

FortressScene::FortressScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
}

FortressScene::~FortressScene()
{
}

void FortressScene::PostInitialize()
{
	_cannon1->PostInitialize();
	_cannon2->PostInitialize();
	_cannon1->Update();
	_cannon2->Update();
}


void FortressScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();
	_cannon1->IsDamaged(_cannon2->GetBall());
	_cannon2->IsDamaged(_cannon1->GetBall());
	if (_isTurn) {
		
		_cannon1->InputMove();
		_cannon1->InputBarrelRotation();
		if (_cannon1->IsFireReady()) {
			_cannon1->Fire(_isTurn);
		}
		if (_cannon1->GetBall()->GetCollider()->IsCollision(_cannon2->GetBody())) {
			
			_cannon2->GetisDamaged() = false;
		}
		
	}
	else {
		
		_cannon2->InputMove();
		_cannon2->InputBarrelRotation();		
		if (_cannon2->IsFireReady()) {
			_cannon2->Fire(_isTurn);
		}
		if (_cannon2->GetBall()->GetCollider()->IsCollision(_cannon1->GetBody())) {

			_cannon1->GetisDamaged() = false;
		}
	}
	
}


void FortressScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}
