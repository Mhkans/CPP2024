#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
�̹� ��ġ�� ã�Ƴ��� ����� ���Ի����� O(1)
��ġ�� �𸦰�� O(n)
*/
/*
iterator : ��ȸ�� 
 C++ STL �����ϴ� �˰��� �Լ��� , �����̳� ����Լ����� ����Ҷ� ���δ�.
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

	//1 �ε����� Ȱ���� ��ȸ
	/*
	for (int i = 0; i < v.size(); i++) {

		cout << v[i] << endl;
		
	}
	*/

	///2 iterator �� Ȱ���� ��ȸ
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