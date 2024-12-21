#include <iostream>
#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<algorithm>


using namespace std;

template<typename T>

class Queue {
public:

	void push(const T& num) {

		temp.push_back(num);

	}
	T front() {

		return temp.front(); //temp.back();  마지막에 있는 원소
	}
	void pop() {
		temp.pop_front();
	}
	bool empty() {
		return temp.empty();
	}
private:
	list<T> temp;
};

//Queue 구조 - First Input First Out

int main()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (true) {

		cout << q.front() << endl;
		q.pop();
		if (q.empty() == true) {
			break;
		}
	}
	return 0;
}