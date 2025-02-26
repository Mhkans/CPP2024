#pragma once
/*
Quad : �Ϲ������δ� "��"�� ���ϴ� ��
���⼭�� �簢���̶� ���� ��
-> �簢���� "�̹���"�� ����ϱ� ���� Ŭ����

������ Shape�� SRT ��ȯ�� ���� ��ġ ������ ���� �� �� ���� Ŭ�������,
�̸� ������ ������ �� �ְ� Transform�� ��ӽ�Ű�� �� Ŭ������ ������ �� ������
-> ��� �κ��� ������ ���� ������ �� �ִ� ���ο� ������ Shape�� �ٽ� ���� ��

���� ����� �� Quad��� Ŭ������
���� �ִϸ��̼��� ����� ���� ���ִ� �κ��� �ణ ����
���� ������ �� �� ���� �κ��̴ٺ���, �̴� �ϴ� �߰��� �ϵ� ���ַ� ó���� ��
-> ���߿� �� Ŭ������ �� �ھ��� ����
*/

class Quad : public Transform
{
protected:
	vector<Vertex> verticies = {};
	vector<VertexUV> vertices_uv = {};

	VertexBuffer* VB;

	VertexShader* VS;
	PixelShader* PS;

	ColourBuffer* CB;

	/*
	IndexBuffer* IB;
	
	Texture* texture;

	void SetPixelShader(wstring file)
	*/
	
	void Create();

public:
	Quad(/*wstring file,*/Vector2 size, Vector2 scale = Vector2(1, 1),
		Vector2 startUV = Vector2(0, 0), Vector2 EndUV = Vector2(1, 1));
	virtual ~Quad();

	virtual void Render();
};