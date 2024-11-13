#include<iostream>

using namespace std;

/*
�̱���

1. �����ֱ⸦ �츮�� ������ �� �־���Ѵ�.�������ϰ� �Ͼ�������Ƿ� �ѹ��� �����ϴ°� �ƴ� �ʿ��� �� �����ǵ��� �ؾ��Ѵ�
2. �Ѱ��� ����
3. �������� ���� ����


���� / ����

���� : ������ �ð��� ���� , ��Ÿ�ӿ� �������� ����
���� : ��Ÿ�ӿ� ���� ����, ��Ÿ�ӿ� ���� ����
*/

class SoundManager {

private:
	SoundManager() {
		_warriorSound = "WarriorSound!!!";
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



class Marine {

public:
	void PrintInfo() {

		cout << _hp << endl;
		cout << _atk << endl;
	}

	//��������Լ� : ����Լ��� �����Լ�ó�� �������
	
	//����Լ� ȣ�� ����
	//1. ��� �������� �� �� �־�� �Ѵ�
	//2. ��ü�� �־�� �Ѵ�.
	static void Hello() {

		cout << "Hello World" << endl;
		cout << _atk << endl; 
		//cout << _hp << endl; �� ���� ���� ���� : ������ hp�ΰ� ��
		//��������Լ��� static��� �������� �����ؼ� ��� �� �� �ִ�.
	}
public:
	int _hp;
	static int _atk;
};
int Marine::_atk = 0;

//static ������ �ݵ�� �������� �ʱ�ȭ�� ����� �Ѵ�
SoundManager* SoundManager::_instance = nullptr;

int main() {

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


	SoundManager::CreateInstance();

	SoundManager::GetInstance()->PrintHello();

	SoundManager::DeleteInstance();

	return 0;
}