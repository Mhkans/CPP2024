#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include <algorithm> 
#include<string>


using namespace std;
bool Find_if(int element) {
	return element > 25;
}
int main() {
	
	vector<int> v = { 31,23,3,2,1,3,12,15,19 };
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	cout << endl;
	//1.v���� 23�� �ִ� ������ �ڸ��� ã���ּ��� find
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;
	vector<int>::iterator Iter1 = std::find(v.begin(), v.end(), 23);

	if (Iter1 != v.end()) {
		cout << *Iter1 << endl;
	}
	
	//2.v���� 25���� ū ���� �ִٸ� �ڸ��� ã���ּ��� find_if
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	vector<int>::iterator Iter2;

	for (Iter2 = v.begin(); Iter2 != v.end(); Iter2++) {
		if (*Iter2 > 25) {
			break;
		}
	}
	Iter2 = std::find_if(v.begin(), v.end(), &Find_if); //�Լ��θ���� ��� ���ľ��� -> �Լ���ü
	struct F1 {
		bool operator()(int a) {
			return a>compareNum;
		}
		int compareNum;
	};

	F1 f1;
	f1.compareNum = 25;
	Iter2 = std::find_if(v.begin(), v.end(), f1);
	
	f1.compareNum = 27;
	Iter2 = std::find_if(v.begin(), v.end(), f1); //�Լ���ü ��Ȱ��

	if (Iter2 != v.end()) {
		cout << *Iter2 << endl;
	}
	else {
		cout << "no" << endl;
	}
	//3.v���� 3�� ������ ����� count
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	cout << std::count(v.begin(), v.end(), 3) << endl;

	//4.v���� 10���� ū���� ����� count_if
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	
	f1.compareNum = 10;
	cout << std::count_if(v.begin(), v.end(), f1) << endl;;

	//5.v���� ������ 50���� ������ all_of
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	struct F2 {

		bool operator()(int a) {
			return a < compareNum;
		}
		int compareNum;
	};
	F2 f2;
	f2.compareNum = 50;
	cout << std::all_of(v.begin(), v.end(), f2) << endl;;
	//6.v���� �ϳ��� 20����ũ�� 30���� ���� ���� �ִ��� any_of
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	struct F3 {
		bool operator()(int a) {

			return compareNum1 < a && a < compareNum2;
		}
		int compareNum1;
		int compareNum2;
	};
	F3 f3;
	f3.compareNum1 = 20;
	f3.compareNum2 = 30;
	cout << std::any_of(v.begin(), v.end(), f3) << endl;;
	//7.v�� �Ųٷ� reverse
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	std::reverse(v.begin(), v.end());
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	//8.�� v�� ���ҿ� 3�� �����ּ��� replace , for_each
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	for (int i = 0; i < v.size(); i++) {
		std::replace(v.begin(), v.end(), v[i], v[i] * 3);
	}
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}

	cout << endl;
	//9.v�� �������ּ��� sort
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	struct F4 {
		bool operator()(int a, int b) {
			return a < b;
		}
	};
	F4 f4;
	std::sort(v.begin(), v.end(), f4);
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	//10.v���� �������Ұ� �ִٸ� �������ּ��� erase->unique
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	v.erase(std::unique(v.begin(), v.end()), v.end());
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	//11.v���� 45�� ���Ұ� �ִٸ� ���� erase->remove
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	v.erase(std::remove(v.begin(), v.end(), 45), v.end());
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	//12.v���� 20���� ���� ���ҵ� ���� erase->remove_if
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	struct F5 {
		bool operator()(int a) {
			return a < compareNum;
		}
		int compareNum;
	};
	F5 f5;
	f5.compareNum = 20;
	v.erase(std::remove_if(v.begin(), v.end(), f5), v.end());
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;
	

	for (auto Iter = v.begin(); Iter != v.end();) {
		if (*Iter == 57) {
			Iter = v.erase(Iter);
		}
		else {
			Iter++;
		}
	}
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;


	return 0;
}