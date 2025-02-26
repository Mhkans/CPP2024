#pragma once
class ImageScene : public Scene
{
private:
	ImageRect* image;
	ImageRect* player;

	ScrollingBG* bg;
public:
	ImageScene();
	~ImageScene();


	// Inherited via Scene
	virtual void Update() override;

	virtual void Render() override;

	virtual void PostRender() override;
	// ImGui�� ����� �����͵��� ����ϵ��� �����ϴ� �Լ�

};


/* ���� :

�̹����� ����, �����̴� ������Ʈ�� �ϳ� ���� ��
��, �� �����̴� ������Ʈ�� "���콺 �̵�"�� ���� �������� �Ѵ�

���� )
1) ��� ������Ʈ�� ���� �ٸ� �̹����� ����ؾ� ��
2) ������Ʈ�� ������ ����� �����ϰ� �ּ� 2��(����� �ݵ�� ����)
-> ���� ������Ʈ�� ���ΰ� ���� �ϳ� ����� �̾߱�
3) �������� �߰��� ������Ʈ�� ���콺�� �̵��� �״�� ���󰡾� ��

��Ʈ
1) API �� �ٷ�� ���콺 �� ��ü

2) extern Vector2 mouse_pos;


*/