#include<iostream>

using namespace std;
/*
functor : 함수객체 


*/

struct Functor {

	void operator()(void) {

		cout << "Hellow World" << endl;
		PrintNum();
	}

	void PrintNum() {

		cout << num << endl;
	}

	int num; //속성을 가질 수 있다
};

struct Functor2 {

	bool operator()(int num) {

		if (num == compareNum) {

			return true;
		}
		return false;
	}
	int compareNum;
};

int main() {
	
	Functor functor;
	Functor2 functor2;
	functor();
	functor.num = 1;
	functor();
	functor.num = 2;
	functor();
	functor.num = 3;
	functor();
	

	functor2.compareNum = 5;


	int aInt = 12;

	if (functor2(12)) {

		cout << "aInt는" << functor2.compareNum << "과 같습니다" << endl;

	}
	else {

		cout << "aInt는" << functor2.compareNum << "과 다릅니다" << endl;
	}






	return 0;
}