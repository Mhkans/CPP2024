#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include <algorithm> 

using namespace std;

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
	
	
	
	// ���Ұ� 12�� ���Ҹ� �����ּ���.
	vIter = v.begin();
	std::remove(v.begin(), v.end(), 12);
	for (vIter; vIter != v.end(); vIter++) {

		cout << *vIter << " ";

	}
	cout << endl;
	// ���Ұ� 10���� ���� ���ҵ��� �����ּ���.
	vIter = v.begin();
	f2.comNum = 10;
	std::remove_if(v.begin(), v.end(),f2);

	for (vIter; vIter != v.end(); vIter++) {

		cout << *vIter << " ";

	}
	cout << endl;


	return 0;
}