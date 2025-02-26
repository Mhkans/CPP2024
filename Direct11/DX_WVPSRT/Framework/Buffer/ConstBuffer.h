#pragma once
// Constant(���) ���� - ���� �������� ����ϴ� ����, Ȥ�� ������ ������ ����ϱ� ���� ����ϴ� ���� �ܿ�
//						�ٸ� �뵵�� ����ϴ� ���۵��� �⺻������ "���" ���۸� �̿���
// ���� ����, �ε��� ���� ���� DX���� ���������� ���������μ� �ٷ�� ��������
// ������ ���۵��� ���� ���� ���۸� �غ������� �ʾ����Ƿ�,
// �׷� �͵��� ��s�� �����ϴ� ����

/*
������ ��� ���۵��� ���������� ������ �ִ� ������� �����ϱ� ���� Ŭ������,
������ ����� ��� ���۵��� �� Ŭ������ ��ӹ޾Ƽ� ����(GlobalBuffer.h)
*/
class ConstBuffer
{
private:
	ID3D11Buffer* buffer;

	void* data;

	UINT data_size;

public:
	ConstBuffer(void* data, UINT data_size);
	~ConstBuffer();

	void SetVS(UINT slot);
	void SetPS(UINT slot);
};