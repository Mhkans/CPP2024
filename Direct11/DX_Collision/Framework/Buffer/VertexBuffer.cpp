#include "framework.h"

VertexBuffer::VertexBuffer(void* data, UINT s, UINT count)
	: stride(s), offset(0)
{
	// ������ ������ ����ϱ� ���� Scene ��� ��������� ���� ���� �ڵ带
	// ���⼭ �����ϵ��� ������

	D3D11_BUFFER_DESC bd = {}; // ������ �����صδ� ����ü
	bd.Usage = D3D11_USAGE_DEFAULT; // �� ������ �뵵
	bd.ByteWidth = stride * count; // �뿪�� - �� ���۰� ���� �����Ͱ� �� �󸶸�ŭ������ ǥ���ϴ� ��
	// ���̴� ������ C++�� �ƴ� ſ�� �޾ƿ��� �������� �� �뷮 ���� ����� �ľ����� ����
	// ���� �� �뷮�� �������� ���� �����ͷμ� ������� �� �ʿ䰡 ����
	
	// ���⼭�� ���� �ϳ����� �뷮�� �Ű������μ� �Է¹޾�, ���� �Է¹��� �������� ������ ���� �� �뷮�� ���
	
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	// �� ���۰� � ���� �����صδ� ���������� �˸��� ���
	// �̰� ���� �뵵�� ��ġ���� ������ ���������� ó������ �����Ƿ� �ݵ�� �뵵�� �°� ������� ��
	// ���⼭�� ������ ����ϴ� �����̹Ƿ� ���� ���� ���� ��

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;
	// �ʱ�ȭ�ϴµ� �����, ���� �����Ͱ� ����Ǿ� �ִ� ����ü�� ����

	DEVICE->CreateBuffer(&bd, &initData, &buffer);
	// ��� �����Ͱ� �غ�Ǿ�����, �̸� DX ����̽��� ���� ���۸� �����Ͽ� ����� ����
}

VertexBuffer::~VertexBuffer()
{
	buffer->Release();
}

void VertexBuffer::Set(D3D11_PRIMITIVE_TOPOLOGY type)
// �޾ƿ� �Ű������� ���� DVC�� � ������ ����� ������ + � �ڷḦ ����� �������� �����ϴ� �Լ�
{
	DVC->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
	DVC->IASetPrimitiveTopology(type);
}
