#include "framework.h"
#include "Program.h"

Program::Program()
{
	Create();
	scene = new TutorialScene();
}

Program::~Program()
{
	delete scene;
}

void Program::Update()
{
	scene->Update();
}

void Program::Render()
{
	Device::Get()->Clear();

	scene->Render();

	Device::Get()->Present();
}

void Program::Create()
{
	Device::Get();
}

void Program::Delete()
{
	Device::Delete();
}
