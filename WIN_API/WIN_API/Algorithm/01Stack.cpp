#include <iostream>
#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<algorithm>


using namespace std;

template<typename T>

class Stack {
public:

	void push(const T& num) {

		temp.push_back(num);

	}
	T top() {

		return temp[temp.size() - 1]; //temp.back();  마지막에 있는 원소
	}
	void pop() {
		temp.pop_back();
	}
	bool empty() {
		return temp.size() == 0;
	}
private:
	vector<T> temp;
};

//stack 구조 - First Input Last Out

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	while (true) {

		cout << s.top() << endl;
		s.pop();
		if (s.empty() == true) {
			break;
		}
	}
	return 0;
}
