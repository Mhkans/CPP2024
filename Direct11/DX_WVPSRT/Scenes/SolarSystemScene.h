#pragma once
class SolarSystemScene : public Scene
// �¾�踦 ���� �����غ��� Scene
/*
������ҷμ��� �¾� + ���� �༺���� �� ��
�ϴ��� ������ȭ�� Ȯ��, �� ���Ĵ� ���� �ð��� ������ �߰��� �����

�������δ� �� �¾�� �༺���� ��� ����� ���ΰ�?


*/
{
private:
	Planet* sun;

	Planet* mercury;
	Planet* venus; // (������ �ƴ����� ���⼱)�ݼ��� ���� ������ �ٸ���

public:
	SolarSystemScene();
	~SolarSystemScene();



	// Inherited via Scene
	virtual void Update() override;

	virtual void Render() override;

};