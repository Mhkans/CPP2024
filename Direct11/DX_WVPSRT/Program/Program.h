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

public:
	Program();
	~Program();

	void Update();
	void Render();

	void Create();
	void Delete();
};