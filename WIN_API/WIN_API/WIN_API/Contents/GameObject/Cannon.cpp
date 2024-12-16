#include "framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(350,350), 50);
	_barrel = make_shared<Barrel>();
	
	for (int i = 0; i < _ballCount; i++) {

		_ballPool.push_back(make_shared<Ball>());
	}
	
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (_hp == 0) {
		_isAtctive = false;
	}
	if (_isAtctive) {
		_body->Update();
		_barrel->Update();
		for (auto ball : _ballPool)
		{
			ball->Update();
		}
	}
	
	


}

void Cannon::Render(HDC hdc)
{
	if (_isAtctive) {
		_barrel->Render(hdc);
		_body->Render(hdc);
		for (auto& _ball : _ballPool) {
			_ball->Render(hdc);

		}
	}
	
}

//void Cannon::Fire()
//{
//	//if (GetAsyncKeyState(VK_SPACE) & 0x8001 && !_spacebarPressed)
//	//{
//
//	//	// 단발식 애쉬평타 만들어오기
//	//	auto iter = std::find_if(_ballPool.begin(), _ballPool.end(), [](const shared_ptr<Ball>& ball) -> bool
//	//	{
//	//		if (ball->IsActive() == false)
//	//			return true;
//	//		return false;
//	//	});
//
//	//	if (iter != _ballPool.end()) {
//
//	//		(*iter)->Fire(_barrel->GetMuzzle(), _barrel->GetDirection());
//	//	}
//
//
//	//}
//	//else if (!(GetAsyncKeyState(VK_SPACE) & 0x8001) && _spacebarPressed)
//	//{
//	//	_spacebarPressed = false;
//	//}
//	
//
//
//
//	if (GetAsyncKeyState(VK_SPACE) & 0x8001 && !_spacebarPressed)
//	{		
//		_ballPool[_index]->Fire(_barrel->GetMuzzle(), _barrel->GetDirection());
//     	_index++;
//		if (_index >= _ballCount) {
//			_index = 0;
//		}
//		_spacebarPressed = true;
//		//아래로 천천히 떨어지게 하기
//		//공 여러개 날아가게 하기 메모리 누수 x 
//	}
//	else if (!(GetAsyncKeyState(VK_SPACE) & 0x8001) && _spacebarPressed)
//	{
//		_spacebarPressed = false;
//	}
//}
void Cannon::Fire(bool& turn)
{
	// 0b 1000 0000 0000 0001
	// 0b 0111 0000 0000 0001
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		auto iter = std::find_if(_ballPool.begin(), _ballPool.end(), [](const shared_ptr<Ball>& ball) -> bool
		{
			if (ball->IsActive() == false)
				return true;
			return false;
		});

		if (iter == _ballPool.end()) return;

		(*iter)->Fire(_barrel->GetMuzzle(), _barrel->GetDirection());

		turn = !turn;
		
	
		
	}
}


void Cannon::InputMove()
{
	if(GetAsyncKeyState(VK_LEFT) & 0x8001)
		_body->Center().x -= 3;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		_body->Center().x += 3;
}

void Cannon::InputBarrelRotation()
{
	Vector dir = mousePos - _body->Center();
	dir.Normalize();

	_barrel->SetDirection(dir);
}

void Cannon::IsDamaged(shared_ptr<class Ball> ball)
{	
	if (ball->GetCollider()->IsCollision(_body) && !_isDamaged)
	{
		_hp -= 15;
		_body->SetRed();
		_isDamaged = true;
	}
	if (_hp <= 0) {
		_hp = 0;
	}
}
