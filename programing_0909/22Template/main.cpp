#include<iostream>

using namespace std;

template <typename T = float>

struct Vector2 {

	T DotProduct(const Vector2<T>& other) {

		return other.x * x + other.y * y;

	}

	T x;
	T y;

};
//���ø� Ư��ȭ
template <>
struct Vector2<double> {

	double DotProduct(const Vector2<double>& other) {

		cout << "���ø� Ư��ȭ" << endl;

		return other.x * x + other.y * y;

	}

	double x;
	double y;

};

int main() {

	Vector2<int> v = { 1,2 };








	return 0;
}
/*
#include<iostream>
using namespace std;

int Add(int a, int b) {

	return a + b;
}
float Add(float a, float b) {

	return a + b;
}

template <typename T = int>
T Add(T a, T b) {

	return a + b;
}
//���ø� Ư��ȭ
template <>
double Add(double a, double b) {

	cout << a << "+" << b << endl;
	return a + b;
}

template <typename F>
void Execute(F func) {

	func();//�Ű������� ���� �Լ������� �Լ���ü ���
}

void HelloWordl() {

	cout << "Hello Template" << endl;
}
struct Hello {

	void operator()() {
		cout << "hello template _Functor" << endl;
	}
};
typedef void(*FN)(void);

int main() {


	int aInt = Add<int>(1, 2);
	float aFloat = Add<float>(1.1f, 1.2f);
	double aDouble = Add<double>(1.1, 2.5);

	Execute<FN>(&HelloWordl);
	Hello functor;
	Execute<Hello>(functor);

	return 0;
}
*/

