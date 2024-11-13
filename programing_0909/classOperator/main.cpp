#include<iostream>

using namespace std;

//������ �����ε� -> ������
/*
���������� : a+b , a��b�� ���ϰ� �� ���� ��ȯ�Ѵ�


*/



class Vector {

public:
	Vector() :_x(0.0f), _y(0.0f) {


	}

	Vector(float x, float y) : _x(x), _y(y) {


	}
	//��������� �Ͻ������� �������
	Vector(const Vector& other) : _x(other._x) , _y(other._y){


	}

	~Vector() {


	}

	void PrintVector() {

		cout << "X : " << _x << endl;
		cout << "Y : " << _y << endl;

	}
	//�������ٿ����� �����ε�

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
	Vector operator+(const Vector& other) const { //�ڿ����� const �� �ڱ��ڽ��� �ٲ�������� ��

		//this -> 5; //����

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
	float Cross(const Vector& other) { //3d���� ����ȿ���� �ٶ� ���, ���ͻ��̿� ���ϴº��Ͱ� �ִ��� �Ǻ��Ҷ� ���

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
	//�׳� Vector ��� const �������� ����ϴ� ���� : �Ű������� �����ͷ����� 32��Ʈ���� 4����Ʈ 64��Ʈ���� 8����Ʈ

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

