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
	scene = new ImageScene();
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

	CreateSamplerState();
	CreateBlendState();
	CreateRasterizerState();
}

void Program::Delete()
{
	Device::Delete();
}

void Program::CreateSamplerState()
// �Է¹��� �̹����� ��� ó���� �������� �����ϴ� state�� �����ϴ� �Լ�
// state : �׳� �����̶� ����ϸ� OK, ���� �浵 "����"��� ��
{
	D3D11_SAMPLER_DESC desc = {};
	desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
	// �� �̹����� � ������ "����"�� ������ �����ϴ� ��
	// ���� : ������ �����͵� ���̿� �ִ�, �����Ͱ� ���� �������� ���� ����
	//		  ������ �Լ��� �̿��� �� �����͸� ������ִ� ����
	// ������ ���ϸ� �̹����� ũ�Ⱑ ������ �� �� �� �ڿ������� ��µǵ��� �ϴ� ����

	desc.AddressU = D3D11_TEXTURE_ADDRESS_MIRROR;
	desc.AddressV = D3D11_TEXTURE_ADDRESS_MIRROR;
	desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	// �Է¹��� �̹��� ������ �̿��� ��,
	// UV���� 0~1 ������ ����� ��� ��� �κ��� ��� ó������ �����ϴ� ������

	/*
	MIRROR : 1�� ������ ���� ������ ���� ������ �ִ� ������ �������� ����ϴ� ���
	WRAP : 1�� ������ ���� ������ ������ ó������ �ٽ� �׸��� ���
	BORDER : 0~1�� ����� ������ �ƿ� �׸��� �ʴ� ���
	CLAMP : 0~1������ ���� ���� ���κ��� �����ϴ� �ȼ��� ������ �� �ٱ� �κ��� ���� ä��� ���
			��, ���� X��ǥ(U) or Y��ǥ(V)�� �ִ� �ȼ��� ���� ���� ������ ä��� ���
	MIRROR_ONCE : ~1 ~ 1������ ������ MIRROR, �� ���� ������ CLAMP�� ó���ϴ� ���

	*/


	// ������ ������ 2D�� �ƴ� 3D���� ���� �����̹Ƿ� ���⼱ ���� ����

	desc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	desc.MinLOD = 0;
	desc.MaxLOD = D3D11_FLOAT32_MAX;

	DEVICE->CreateSamplerState(&desc, &samplerState);

	DVC->PSSetSamplers(0, 1, &samplerState);
}

void Program::CreateBlendState()
// ���ݱ��� DX���� ������ �ٷ� �� ����ߴ� "���İ�"�� �̿��� ����ó���� �ϴ� �κ�
/* ����(Alpha)�� : �ش� �ȼ��� ���� ���� �������� "������"�� �ǹ��ϴ� ������,
0�� ����� ���� ����(=�����δ� �����ͻ� ���� ���� ������ �ִ� �ϴ��� ���� ������ ����Ѵ�)
1�� ����� ���� ������(=���� ���� ������ �־ �̸� ����ؾ� �Ѵٰ� ���Ѵ�)
�̸� �̿��ؼ� �Է¹��� �̹���, Ȥ�� ������ ������ �츮�� "�������� ����� ��"�� �����ϴٸ�
�ش� �����ʹ� ������� �ʵ��� �ϴ� ���� �� �Լ��� ����

���⼭�� �׳� ���� ó���� ���� �� �Լ��� ��������� �Ѵٰ� ����ϸ� ��
*/
{
	D3D11_BLEND_DESC desc = {};
	desc.RenderTarget[0].BlendEnable = true;
	desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

	desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
	desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

	desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	DEVICE->CreateBlendState(&desc, &blendState);

	float blendFactor[] = { 0, 0, 0, 0 };
	DVC->OMSetBlendState(blendState, blendFactor, 0xffffffff);
}

void Program::CreateRasterizerState()
// Rasterizer �׷��� ���������� �ܰ踦 ����ϴ� �κ�
// 2D���� 3D���� �� ���� ���̴� �����̶�, �̿� ���� ������ ����
{
	D3D11_RASTERIZER_DESC desc = {};
	desc.CullMode = D3D11_CULL_NONE;
	desc.FillMode = D3D11_FILL_SOLID;

	DEVICE->CreateRasterizerState(&desc, &rasterizerState);

	DVC->RSSetState(rasterizerState);
}