#include<iostream>

using namespace std;

/*
�̱���

1. �����ֱ⸦ ������ �� �־���Ѵ�.
2. �Ѱ��� ����
3. �������� ���� ����

����Ŵ����� 100�� �ʿ��Ҷ� ��� �ϳ��� ���������� new/delete�� �Ͼ�鼭 �ü���� ��ġ�⶧���� �������ϰ� ����
�̱��� ����Ŵ����� ���� ����ϸ� �ذᰡ��

����Ŵ���
1. ���α׷� ������ �� �Ѱ�
2. �������� ���带 ���� , ��𼭵� ��µ� �����ؾ���
3. ���� ������ ����ڰ� ������ �� �־���� - ���α׷� ���� / ����

���� / ����

���� : ������ �ð��� ���� , ��Ÿ�ӿ� �������� ����
���� : ��Ÿ�ӿ� ���� ����, ��Ÿ�ӿ� ���� ����
*/

class SoundManager {

private:
	SoundManager() {
		_warriorSound = "WarriorSound";
	}
	~SoundManager() {

	}

public:
	static void CreateInstance() {
		if (_instance == nullptr) {

			_instance = new SoundManager();
		}

	}
	static void DeleteInstance() {

		if (_instance != nullptr) {

			delete _instance;
		}
	}
	static SoundManager* GetInstance() {

		if (_instance != nullptr) {

			return _instance;

		}
		return nullptr;
	}
	void PrintHello() {

		cout << _warriorSound << endl;
	}
private:
	static SoundManager* _instance;
	string _warriorSound;
};



//static ������ �ݵ�� �������� �ʱ�ȭ�� ����� �Ѵ�
SoundManager* SoundManager::_instance = nullptr;

int main() {

	SoundManager::CreateInstance();

	SoundManager::GetInstance()->PrintHello();

	SoundManager::DeleteInstance();

	return 0;
}

//static

//class Marine {
//
//public:
//	void PrintInfo() {
//
//		cout << _hp << endl;
//		cout << _atk << endl;
//	}
//
//	//��������Լ� : ����Լ��� �����Լ�ó�� �������
//
//	//����Լ� ȣ�� ����
//	//1. ��� �������� �� �� �־�� �Ѵ�
//	//2. ��ü�� �־�� �Ѵ�.
//	static void Hello() {
//
//		cout << "Hello World" << endl;
//		cout << _atk << endl;
//		//cout << _hp << endl; �� ���� ���� ���� : ������ hp�ΰ� ��
//		//��������Լ��� static��� �������� �����ؼ� ��� �� �� �ִ�.
//	}
//public:
//	int _hp;
//	static int _atk;
//};
//int Marine::_atk = 0;

/*
	Marine::_atk = 5;
	Marine::Hello();

	Marine* arr[100];

	for (int i = 0; i < 100; i++) {

		arr[i] = new Marine;
		arr[i]->_hp = 50;

	}

	//���ݷ� ��

	for (int i = 0; i < 100; i++) {

		arr[i]->PrintInfo();


	}



	for (int i = 0; i < 100; i++) {

		delete arr[i];
	}
	*/