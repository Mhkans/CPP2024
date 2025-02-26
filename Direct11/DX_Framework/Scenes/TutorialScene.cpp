#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	// ���̴��� �����ϴ� �� �ʿ��� �÷��׸� �̸� ����
	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);
	// ���̴� �ּҰ� �ִ� ������ �Է��Ͽ� ���� ���̴��� �ȼ� ���̴��� �����

	vector<Vertex> vx_triangle_list =
	{
		Vertex(-0.1f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.8f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.8f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.1f, +0.8f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.1f, +0.1f, 0.17f, 0.8f, 0.8f),
	};

	list_triangle = new Triangle(vx_triangle_list);

	vector<Vertex> vx_triangle_strip =
	{
		Vertex(-0.8f, -0.8f, 0.8f, 0.17f, 0.17f),
		Vertex(-0.8f, -0.1f, 0.1f, 0.1f, 0.17f),
		Vertex(-0.1f, -0.8f, 0.1f, 0.1f, 0.17f),
		Vertex(-0.4f, -0.1f, 0.8f, 0.17f, 0.17f),
	};

	strip_triangle = new Triangle(vx_triangle_strip,
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	// D3D11_PRIMITIVE_TOPOLOGY : ��ġ�� � ������ �׸� �������� �˸��� ������ �ô� ������
	// TRIANGLELIST : ������ �������� �ʰ� 3�� ������ ���� ��� �ﰢ���� ������ ��
	// TRIANGLESTRIP : �������� ����ߴ� 2�� ���� ��Ȱ���ؼ�
	//				   �� �ڿ� �߰��� ������ ���� ���� �ﰢ���� ����϶�� ��

	// LINELIST 
	// LINESTRIP
	// ���� �ٸ� �͵鵵 ����
}

TutorialScene::~TutorialScene()
{
	delete list_triangle;
	delete VS;
	delete PS;
}

void TutorialScene::Update()
{
}

void TutorialScene::Render()
{
	/*
	DX�� ���� �������� �׷����� ��µ� ������ ���İ��� �Ǵ� �ܰ�� ������ ���� : 
	1) Update()�� ���� ���� ����ǰ� �ִ� Scene���� ���� �������� �� ������� ������
	2) Program���� Render()�� �����ؼ� ���� ���� ȭ���� �������� ���� ĥ��
	3) Scene()�� Render�� ���ͼ�, �� Scene �ȿ� �ִ� ������Ʈ���� ����� ������
	 * �� ������Ʈ�� ������ ����� ������ ���� �����
	 A) DX�� �׷��� ����� ����ϴ� ��ġ�� deviceContext��
	    ���ݺ��� ����ϱ� ���� � ������ �ؾ� �ϴ����� �˸��� �ʿ��� �����͵��� ����
		(� ���̴��� �� ������, �Է¹޴� �������� ������ ��� �����Ǿ������� ����,
		���� ���������� ����Ǿ� �ִ� ����, �� ���������� � �������μ� ����� ������ ��� ����)
	 B) ��� �����Ͱ� ���õǾ�����, �տ������� �� �� ���� ���������� �̿��� ������ ����� ������ �Է¹ް�
	    �̸� �׷���(�����)�� ���
	4) Scene�� ��� �׷����� �� �׸��� �� ���������� �� ����۸� ���� ȭ��� ��ü
	*/

	UINT stride = sizeof(Vertex);	// ������ �ϳ��ϳ��ϰ� �����ϴ� �뷮
	UINT offset = 0;
	

	Device::Get()->GetDeviceContext()->VSSetShader(VS->GetVertexShader(), nullptr, 0);
	Device::Get()->GetDeviceContext()->PSSetShader(PS->GetPixelShader(), nullptr, 0);
	// ���� �׸��� �׸��� ���� � ���̴��� ����� �������� �� �Լ����� ���� ����
	// �Ǽ��ζ� Set�� �ƴ� Get���� �ڵ��ϼ��Ǿ������� �ݵ�� üũ�� ��

	Device::Get()->GetDeviceContext()->IASetInputLayout(VS->GetInputLayout());
	// �������� VS �ʿ� �� �������� ��� �����Ǿ��ִ��� �� ��ǥ�� ��ġ�� ����

	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, list_triangle->GetBuffer(), &stride, &offset);
	// �ش� ������ ������ �ִ�, ���������� ����� ���۸� �� �Լ��� ���� ��ġ�� ����

	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_triangle->GetType());
	// ��ġ�� �������� �������� �̿��� �׸� ������ � ����������
	// �������� ���� ����

	Device::Get()->GetDeviceContext()->Draw(list_triangle->GetVertexSize(), 0);
	// �������� �� ������ ������ �ִ� ���������� ������ �Է��Ͽ�
	// �� ������ŭ�� �̿��� ������ ���鵵�� �ϸ� ���� �׷��ȿ� ������ �׷����� ��


	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, strip_triangle->GetBuffer(), &stride, &offset);

	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(strip_triangle->GetType());

	Device::Get()->GetDeviceContext()->Draw(strip_triangle->GetVertexSize(), 0);

}


/*

����)

1. ������ LINELIST�� LINESTRIP�� �Ẹ�� �ʾҴµ�,
�̰͵��� �̿��ؼ� ���� �������� �������� ���� ��
���� Triangle�� ���� �̿��غ��� �� ��

2. �������� ������ �Է��ϸ�
�� ������ �´� ���ٰ����� ����ϴ� ������ Ŭ�����μ� ���� ��
5��� ������ �������� �����, 12��� ������ ���̰��� ��

�������� ������ ������ ���� :

Polygon(float x, float y, int vertex_count, ���� ������Ƽ�� ��������)
x,y : �� ������ ȭ��󿡼��� ��ǥ
vertex_count : �� ������ ������ ����

�̸� ���ؼ� �ʱ� ��ġ���� �����ϴ� ������ ���� ��



*/