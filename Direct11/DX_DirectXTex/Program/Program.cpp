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
// 입력받은 이미지를 어떻게 처라힐 것인지를 결정하는 state를 정의하는 함수
// state : 그냥 설정이라 기억하면 OK, 원래 뜻도 "상태"라는 뜻
{
	D3D11_SAMPLER_DESC desc = {};
	desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
	// 이 이미지를 어떤 식으로 "보간"할 것인지 지정하는 값
	// 보간 : 인접한 데이터들 사이에 있는, 데이터가 아직 정해지지 않은 점에
	//		  적합한 함수를 이용해 들어갈 데이터를 만들어주는 행위
	// 간단히 말하면 이미지의 크기가 변했을 떄 좀 더 자연스럽게 출력되도록 하는 보정

	desc.AddressU = D3D11_TEXTURE_ADDRESS_MIRROR;
	desc.AddressV = D3D11_TEXTURE_ADDRESS_MIRROR;
	desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	// 입력받은 이미지 파일을 이용할 때,
	// UV값이 0~1 범위를 벗어났을 경우 벗어난 부분을 어떻게 처리할지 결정하는 설정값

	/*
	MIRROR : 1의 단위를 넘을 때마다 직전 영역에 있던 내용을 반전시켜 출력하는 모드
	WRAP : 1의 단위를 넘을 떄마다 원본을 처음부터 다시 그리는 모드
	BORDER : 0~1을 벗어나는 범위는 아예 그리지 않는 모드
	CLAMP : 0~1까지의 범위 제일 끝부분을 결정하는 픽셀의 값으로 그 바깥 부분을 전부 채우는 모드
			즉, 같은 X좌표(U) or Y좌표(V)에 있는 픽셀은 전부 같은 색으로 채우는 방식
	MIRROR_ONCE : ~1 ~ 1까지의 범위는 MIRROR, 그 외의 범위는 CLAMP로 처리하는 방식

	*/


	// 이하의 내용은 2D가 아닌 3D에서 쓰는 내용이므로 여기선 설명 생략

	desc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	desc.MinLOD = 0;
	desc.MaxLOD = D3D11_FLOAT32_MAX;

	DEVICE->CreateSamplerState(&desc, &samplerState);

	DVC->PSSetSamplers(0, 1, &samplerState);
}

void Program::CreateBlendState()
// 지금까지 DX에서 색상을 다룰 떄 언급했던 "알파값"을 이용해 투명처리를 하는 부분
/* 알파(Alpha)값 : 해당 픽셀이 가진 색상 데이터의 "불투명도"를 의미하는 값으로,
0에 가까울 수록 투명(=실제로는 데이터상 무슨 색을 가지고 있다 하더라도 없는 것으로 취급한다)
1에 가까울 수록 불투명(=뭔가 색을 가지고 있어서 이를 출력해야 한다고 정한다)
이를 이용해서 입력받은 이미지, 혹은 정점의 색상이 우리가 "투명으로 취급할 값"과 동일하다면
해당 데이터는 출력하지 않도록 하는 것이 본 함수의 역할

여기서는 그냥 투명 처리를 위해 이 함수를 구성해줘야 한다고만 기억하면 됨
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
// Rasterizer 그래픽 파이프라인 단계를 담당하는 부분
// 2D보다 3D에서 더 자주 쓰이는 구간이라, 이에 대한 설명은 생략
{
	D3D11_RASTERIZER_DESC desc = {};
	desc.CullMode = D3D11_CULL_NONE;
	desc.FillMode = D3D11_FILL_SOLID;

	DEVICE->CreateRasterizerState(&desc, &rasterizerState);

	DVC->RSSetState(rasterizerState);
}