#pragma once
// DirectX�� �̿��� ��������� ���α׷��� "��ü",
// �� DX�� �������� ������ ������ �ν��Ͻ��μ� ���Ǵ� Ŭ����

// ������ ����� �Լ��� ����������,
// DX�� �����ӿ�ũ�� �����س����鼭 ���� �߰��Ǵ� ������ �������� �� ��
class Program
{
private:
	class Scene* scene;

public:
	Program();
	~Program();

	void Update();
	void Render();

	void Create();
	void Delete();
};