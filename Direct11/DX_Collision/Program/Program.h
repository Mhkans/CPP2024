#pragma once
// DirectX�� �̿��� ��������� ���α׷��� "��ü",
// �� DX�� �������� ������ ������ �ν��Ͻ��μ� ���Ǵ� Ŭ����

// ������ ����� �Լ��� ����������,
// DX�� �����ӿ�ũ�� �����س����鼭 ���� �߰��Ǵ� ������ �������� �� ��
class Program
{
private:
	class Scene* scene;

	MatrixBuffer* view;
	MatrixBuffer* projection;
	// ���� WVP ��ȯ �� View ��ȯ�� Projection ��ȯ�� ����� ���(=���) ����

	void CreateProjection(); // �� 2���� ��ȯ ����� �ʱ�ȭ���� �Լ�

	ID3D11SamplerState* samplerState;
	ID3D11BlendState* blendState;
	ID3D11RasterizerState* rasterizerState;

	void CreateSamplerState();
	void CreateBlendState();
	void CreateRasterizerState();

public:
	Program();
	~Program();

	void Update();
	void Render();

	void Create();
	void Delete();
};