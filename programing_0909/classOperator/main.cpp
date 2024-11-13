#include<iostream>

using namespace std;

//연산자 오버로딩 -> 다형성
/*
덧셈연산자 : a+b , a와b를 더하고 그 값을 반환한다


*/



class Vector {

public:
	Vector() :_x(0.0f), _y(0.0f) {


	}

	Vector(float x, float y) : _x(x), _y(y) {


	}
	//복사생성자 암시적으로 만들어줌
	Vector(const Vector& other) : _x(other._x) , _y(other._y){


	}

	~Vector() {


	}

	void PrintVector() {

		cout << "X : " << _x << endl;
		cout << "Y : " << _y << endl;

	}
	//임의접근연산자 오버로딩

	float& operator[](int temp) {

		if (temp == 0) {

			return _x;

		}
		else {

			return _y;
		}
	}
	/*
	Vector operator=(const Vector& other) {

		_x = other._x;
		_y = other._y;

		return *this;

	}
	*/
	Vector operator+(const Vector& other) const { //뒤에붙은 const 는 자기자신을 바꾸지말라는 뜻

		//this -> 5; //오류

		Vector result;

		result._x = this->_x + other._x;
		result._y = this->_y + other._y;

		return result;

	}
	
	Vector operator-(const Vector& other) const {

		Vector result;

		result._x = this->_x - other._x;
		result._y = this->_y - other._y;

		return result;
	}
	float Dot(const Vector& other) {

		float result;

		result = (this->_x * other._x) + (this->_y * other._y);

		return result;
	}
	float Cross(const Vector& other) { //3d에서 광원효과를 줄때 사용, 벡터사이에 원하는벡터가 있는지 판별할때 사용

		float result;

		result = (this->_x * other._y) - (this->_y * other._x);

		return result;

	}
	float Length() {

		return sqrtf((_x * _x) + (_y * _y));
	}
	Vector NormalVector() {

		_x = (this->_x * (1 / Length()));
		_y = (this->_y * (1 / Length()));

		return ;
	}
public:
	float _x;
	float _y;

};
/*
Vector operator+(const Vector& a, const Vector& b) { 
	//그냥 Vector 대신 const 참조형을 사용하는 이유 : 매개변수의 데이터량떄문 32비트에서 4바이트 64비트에서 8바이트

	Vector result;

	result._x = a._x + b._x;
	result._y = a._y + b._y;

	return result;
}
*/


int main() {


	Vector v1 = Vector(1, 1);
	Vector v2 = Vector(1, 2);

	Vector v3;
	float result = 0.0f;

	//v3 = v1 + v2; 
	v3 = v1.operator+(v2);
	v3.PrintVector();

	//v3 = v1 - v2;
	v3 = v1.operator-(v2);
	v3.PrintVector();

	result = v1.Dot(v2);
	cout <<"("<< v1._x <<" , " << v1._y << ")" << " * " << "(" << v2._x << " , " << v2._y << ")"<< " : " << result << endl;


	result = v1.Cross(v2);
	cout << "(" << v1._x << " , " << v1._y << ")" << " X " << "(" << v2._x << " , " << v2._y << ")" << " : " << result << endl;


	return 0;
}

