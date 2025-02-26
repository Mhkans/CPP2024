#include "framework.h"
#include "Program.h"

void Program::CreateProjection()
{
	view = new MatrixBuffer();
	projection = new MatrixBuffer();

	Matrix orthographic = XMMatrixOrthographicOffCenterLH(
		0.0f, (float)WIN_WIDTH,
		(float)WIN_HEIGHT, 0.0f,
		-1.0f, 1.0f
	);

	projection->Set(orthographic);

	view->SetVS(1);
	projection->SetVS(2);
}

Program::Program()
{
	Create();
	scene = new SolarSystemScene();
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

	CreateProjection();
}

void Program::Delete()
{
	Device::Delete();
}
