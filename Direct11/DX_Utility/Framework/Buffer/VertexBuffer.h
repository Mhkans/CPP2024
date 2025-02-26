#pragma once
// Buffer Ŭ������ : ID3D11Buffer�� �뵵�� �°� �˾Ƽ� �������ֵ��� �ϴ� Ŭ�������� ������

// VertexBuffer : �� �� �������� �����͸� ����� �ѱ� ���۸� ����ϴ� Ŭ����
class VertexBuffer
{
private:
	ID3D11Buffer* buffer;
	// DX11 �԰��� ����

	UINT stride;
	// �� �ν��Ͻ����� �����ϰ� �ִ� ���۰� �� ĭ���� ����ϴ� �뷮�� ������ ����

	UINT offset;
	// ����� �������� ����ϴ� ���

public:
	VertexBuffer(void* data, UINT s, UINT count);
	~VertexBuffer();

	void Set(D3D11_PRIMITIVE_TOPOLOGY type
		= D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// ������ ����ϴ� ����� ���� ���ۿ��� �����ϵ��� ���ִ� �Լ�

};
