#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include <algorithm> 
#include<string>


using namespace std;

class Player {


public:
	Player(string name, int hp) :_name(name), _hp(hp) {

	}

	bool operator<(const Player& other) const { //�ڿ����� const�� ��������� ������ ������ ���������ʰڴٴ� ��

		return _hp < other._hp;
	}
	const int& GetHP() {

		return _hp;
	}
	int _hp;
	string _name;
};

struct Functor1{ 
	bool operator()(int num) {

		if (num > comNum) {
			return true;
		}
		return false;
	}
	int comNum;
};
struct Functor2 {
	bool operator()(int num) {

		if (num < comNum) {
			return true;
		}
		return false;
	}
	int comNum;
};
struct Functor3 {
	void operator()(int& num) {

		num *= multNum;
	}
	int multNum;
};

int main() {

	vector<int> v = { 3,2,4,10,3,3,4,11,250,1,211 };
	vector<int>::iterator findIter;
	vector<int>::iterator vIter = v.begin();
	int index = 0;	
	
	// 1�� �ִ��� ã���ּ���. �׸��� index�� Ȥ�� iterator�ڸ��� ã���ּ���
	findIter = std::find(v.begin(), v.end(), 1);
	index = findIter - v.begin();
	cout << index << ":" << *findIter << endl;
	// 15���� ū ���� �ִ��� ã���ּ���. �׸��� index�� Ȥ�� iterator �ڸ��� ã���ּ���.
	vIter = v.begin();
	Functor1 f1;
	f1.comNum = 15;
	findIter = std::find_if(v.begin(), v.end(), f1);
	index = findIter - v.begin();

	cout << index <<":"<<v[index] << endl;
	// ��� ���� 50���� ������ bool���� �˷��ּ���.
	Functor2 f2;
	f2.comNum = 50;

	bool result = std::all_of(v.begin(),v.end(),f2);

	cout << result << endl;
	
	// �ϳ��� 30���� ū ���� �ִ��� bool���� �˷��ּ���.
	f1.comNum = 30;
	bool result2 = std::any_of(v.begin(), v.end(), f1);

	cout << result2 << endl;
	// ���Ұ� 3�� ���ҵ��� ������ �˷��ּ���.
	int count1 = std::count(v.begin(), v.end(),3);
	cout << count1 << endl;
	// ���Ұ� 5���� ū ���ҵ��� ������ �˷��ּ���.
	f1.comNum = 5;
	int count2 = std::count_if(v.begin(), v.end(), f1);
	cout << count2 << endl;
	// ��� ���ҿ� 3�� �����ּ���.
	Functor3 f3;

	f3.multNum = 3;
	std::for_each(v.begin(), v.end(), f3);

	for (vIter; vIter != v.end(); vIter++) {

		cout << *vIter<<" ";

	}

	cout<<endl;
	// �ߺ��� ���ҵ��� '����'���ּ���.
	
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());





	// ���Ұ� 12�� ���Ҹ� �����ּ���.
	vIter = v.begin();
	v.erase(std::remove(v.begin(), v.end(), 12));
	for (vIter; vIter != v.end(); vIter++) {

		cout << *vIter << " ";

	}
	cout << endl;
	// ���Ұ� 10���� ���� ���ҵ��� �����ּ���.
	vIter = v.begin();
	f2.comNum = 10;
	v.erase(std::remove_if(v.begin(), v.end(),f2),v.end());
	
	for (vIter; vIter != v.end(); vIter++) {

		cout << *vIter << " ";

	}
	cout << endl;



	//��������
	struct sortFunctor {

		bool operator()(const int& a, const int& b) {

			if (a < b) {

				return true;
			}
			return false;
		}
	};
	sortFunctor sortfunctor;
	std::sort(v.begin(), v.end(), sortfunctor);



	vector<Player*> players;

	players.reserve(10);
	for (int i = 0; i < 10; i++) {

		Player* p = new Player("hanil" + to_string(rand()%100), rand() % 100);
		players.push_back(p);
	}

	//players sort by hp ��������

	struct PlayerSort {

		bool operator()(const Player* a , const Player* b)const{
		
			int aHp = a->_hp;
			int bHp = b->_hp;

			return aHp < bHp;
		}
	};
	std::sort(players.begin(), players.end(), PlayerSort());


	vector<Player*>().swap(players); // �ӽð�ü -> �����ٿ� �Ҹ��� ȣ���� �����ͻ���

	v.push_back(3);
	v.push_back(10);
	v.push_back(15);
	v.push_back(11);

	
	for (vector<int>::iterator iter = v.begin(); iter != v.end();) {

		if (*iter == 10) {
			
			iter = v.erase(iter);
			continue;
		}
		else {
			iter++;
		}
	}












	return 0;

}
//pred -> callabel ��ü : �Լ�ó�� ȣ�Ⱑ�� ()�Լ������ڿ� �����ų �� �ִ� �ֵ�
