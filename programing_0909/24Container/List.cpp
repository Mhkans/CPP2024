#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
이미 위치를 찾아놓은 노드의 삽입삭제는 O(1)
위치를 모를경우 O(n)
*/
/*
iterator : 순회자 
 C++ STL 제공하는 알고리즘 함수들 , 컨테이너 멤버함수들을 사용할때 쓰인다.
*/
template<typename Container , typename Iter>
void PrintContainer(Container container) {

	Iter iter;
	iter = container.begin();
	for (iter; iter != container.end(); iter++) {

		cout << *iter << endl;
	}
}
int main() {
	/*
	list<int> l;

	for (int i = 0; i < 1000; i++) {

		l.push_back(i);
		l.push_front(i);

		cout << l.size() << endl;
	}
	*/

	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(90);
	v.push_back(100);

	//1 인덱스를 활용한 순회
	/*
	for (int i = 0; i < v.size(); i++) {

		cout << v[i] << endl;
		
	}
	*/

	///2 iterator 를 활용한 순회
	vector<int>::iterator vIter = v.begin();
	
	for (vIter; vIter != v.end(); vIter++) {

		cout << *vIter << endl;
	}
	cout << "-------------" << endl;
	PrintContainer<vector<int>,vector<int>::iterator>(v);
	list<int> l = { 1,2,34,5,6,8 };
	PrintContainer<list<int>, list<int>::iterator>(l);

	return 0;
}