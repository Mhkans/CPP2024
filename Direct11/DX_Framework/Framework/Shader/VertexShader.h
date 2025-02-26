#pragma once
class VertexShader // �� ��ü�� ���������� �׷��� ���������ο��� ����
{
private:
	ID3D11VertexShader* VS;
	// ������ ���̴�(=���� ���̴�)�� ����� Ŭ���� ��ü
	ID3D11InputLayout* input_layout;
	// DX ��ġ�� � ������ �����͸� ������ ������
	// �� �������� ���̾ƿ�(=����)�� ������ �����صδ� ��ü
	// ���⿡ ����� �����͸� ���� �������� �Էµ��� �� ���̴� ������ �̸� �ؼ��Ͽ� �̿�

public:
	VertexShader(LPCWSTR file_loc, DWORD flags);
	~VertexShader();

	void Release();
	ID3D11InputLayout* GetInputLayout() { return input_layout; }
	ID3D11VertexShader* GetVertexShader() { return VS; }
};