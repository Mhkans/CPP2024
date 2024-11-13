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
//템플릿 특수화
template <>
struct Vector2<double> {

	double DotProduct(const Vector2<double>& other) {

		cout << "템플릿 특수화" << endl;

		return other.x * x + other.y * y;

	}

	double x;
	double y;

};

int main() {

	Vector2<int> v = { 1,2 };








	return 0;
}