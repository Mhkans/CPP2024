#include<iostream>

using namespace std;

//Data ���� - �������� �������� 
//�����ֱ� : ���α׷� ���� �� �Ҵ� / ���α׷� ���� �� ����

static int aInt = 1;
int bInt = 1;

class Marine {

public:
	Marine():_hp(40),_armor(1){}
	~Marine(){}
	//����Լ� ȣ������
	//1. ��ü�� ���� 2. ��� ���Ͽ� �ִ��� �˾ƾ���
	void Upgrade_ATK1() { marine_atk++; }
	//��������Լ�
	//1. ��ü�� ��� ȣ�� ���� 2. ��� ��ü���� �ٶ󺸰��ִ� ���� �Լ� 3. ���� ��������� ���� ���� 
	static void Upgrade_ATK2() { marine_atk++; }
	
private:
	int _hp;
	int _armor;
	static int marine_atk;

};

//���� ��������� �ܺο��� �ʱ�ȭ �ؾ��Ѵ�
int Marine::marine_atk = 5;

int main() {

	Marine marine[50];
	Marine::Upgrade_ATK1();
	Marine::Upgrade_ATK2();
	return 0;
}
