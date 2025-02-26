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