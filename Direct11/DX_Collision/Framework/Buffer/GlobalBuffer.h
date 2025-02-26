#pragma once
// �� ����� �� ������Ʈ���� ����� ���� ��� ���۵��� �����ϴ� ���

class MatrixBuffer : public ConstBuffer // ��ȯ ����� ���� �� ������ ����
{
private:
	struct Data
	{
		Matrix matrix;
	} data;

public:
	MatrixBuffer() : ConstBuffer(&data, sizeof(data))
	{
		data.matrix = XMMatrixIdentity();
		// �⺻ �����ڷμ��� ���� ���͸� ����

	}

	void Set(Matrix value)
	{
		data.matrix = XMMatrixTranspose(value);
		// ��� ���� �����Լ�
	}

};

class ColourBuffer : public ConstBuffer // ������ �����صδ� ����
{
public:
	struct Data
	{
		Float4 colour;
	} data;

	ColourBuffer() : ConstBuffer(&data, sizeof(data))
	{
		data.colour = Float4(1.0f, 1.0f, 1.0f, 1.0f);
	}
};