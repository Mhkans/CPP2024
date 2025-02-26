#pragma once
struct Vertex
	// ������ �츮�� ������ ���� �� �� ������ ������ �� ����ü�� ���� ������
{
	Float3 position; // �� �������� ����Ǵ� ��ǥ ����
	Float4 colour; // �� �������� ����Ǵ� ���� ����

	Vertex()
		// C++���� ����ü�� ��ǻ� public�� �����ϴ� Ŭ������ ���� ����
		// �̷��� �����ڸ� ����� �͵� ���� X
		// �ƹ� �Է� ���� ����Ʈ �������� ���� �ʱ�ȭ��
	{
		position = Float3(0, 0, 0);
		colour = Float4(0, 0, 0, 1);
		// RGB�� �ܿ� 4��° ���� ���İ��� ����� ��ȸ�� ���� �� ����
	}
	Vertex(float x, float y, float r, float g, float b)
	{
		position = Float3(x, y, 0);
		// 2D���� z���� ��ġ�� ������� ����
		colour = Float4(r, g, b, 1);
	}
};

struct VertexUV
{
	Float3 position; // �� �������� ����Ǵ� ��ǥ ����
	Float2 uv; // �� �������� ����Ǵ� �ؽ����� ��ǥ ����

	VertexUV()
	{
		position = Float3(0, 0, 0);
		uv = Float2(0, 0);
	}
	VertexUV(float x, float y, float u, float v)
	{
		position = Float3(x, y, 0);
		uv = Float2(u, v);
	}
};

struct VertexPos // ��ǥ�� ������ � �����͵� ���� ����
{
	Float3 position; // �� �������� ����Ǵ� ��ǥ ����

	VertexPos()
	{
		position = Float3(0, 0, 0);
	}
	VertexPos(float x, float y)
	{
		position = Float3(x, y, 0);
	}
};