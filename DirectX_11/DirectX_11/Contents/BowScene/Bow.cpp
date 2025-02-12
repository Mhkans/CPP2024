#include "framework.h"
#include "Bow.h"

Bow::Bow()
{
	_bow = make_shared<Quad>(L"Resource/Bow.png");
}

Bow::~Bow()
{
}

void Bow::Update()
{
	_bow->Update();
}

void Bow::Render()
{
	_bow->Render();
}
