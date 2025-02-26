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
	Planet* mercury_dummy;

	Planet* venus; // (������ �ƴ����� ���⼱)�ݼ��� ���� ������ �ٸ���
	Planet* venus_dummy;
public:
	SolarSystemScene();
	~SolarSystemScene();



	// Inherited via Scene
	virtual void Update() override;

	virtual void Render() override;

};