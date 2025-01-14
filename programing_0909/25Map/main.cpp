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
	//1.v에서 23이 있는 원소의 자리를 찾아주세요 find
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;
	vector<int>::iterator Iter1 = std::find(v.begin(), v.end(), 23);

	if (Iter1 != v.end()) {
		cout << *Iter1 << endl;
	}
	
	//2.v에서 25보다 큰 수가 있다면 자리를 찾아주세요 find_if
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	vector<int>::iterator Iter2;

	for (Iter2 = v.begin(); Iter2 != v.end(); Iter2++) {
		if (*Iter2 > 25) {
			break;
		}
	}
	Iter2 = std::find_if(v.begin(), v.end(), &Find_if); //함수로만들면 계속 고쳐야함 -> 함수객체
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
	Iter2 = std::find_if(v.begin(), v.end(), f1); //함수객체 재활용

	if (Iter2 != v.end()) {
		cout << *Iter2 << endl;
	}
	else {
		cout << "no" << endl;
	}
	//3.v에서 3의 개수가 몇개인지 count
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	cout << std::count(v.begin(), v.end(), 3) << endl;

	//4.v에서 10보다 큰수는 몇개인지 count_if
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	
	f1.compareNum = 10;
	cout << std::count_if(v.begin(), v.end(), f1) << endl;;

	//5.v에서 모든수가 50보다 작은지 all_of
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
	//6.v에서 하나라도 20보다크고 30보다 작은 수가 있는지 any_of
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
	//7.v를 거꾸로 reverse
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
	//8.각 v의 원소에 3을 곱해주세요 replace , for_each
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	for (int i = 0; i < v.size(); i++) {
		std::replace(v.begin(), v.end(), v[i], v[i] * 3);
	}
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}

	cout << endl;
	//9.v를 정렬해주세요 sort
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
	//10.v에서 같은원소가 있다면 삭제해주세요 erase->unique
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	v.erase(std::unique(v.begin(), v.end()), v.end());
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	//11.v에서 45인 원소가 있다면 삭제 erase->remove
	cout << "- - - - -- - - - -- - - - - - -- ---" << endl;

	v.erase(std::remove(v.begin(), v.end(), 45), v.end());
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		cout << *Iter << " ";
	}
	cout << endl;
	//12.v에서 20보다 작은 원소들 삭제 erase->remove_if
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