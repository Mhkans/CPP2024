#include<iostream>

using namespace std;

int Add(int a, int b); // ����� ���Ǹ� ���ΰ��� �Լ��ñ״���
float Add(float a, float b);
int Add(int a, int b, int c);
int Add(int a, int b, int c, int d, int e = 1);

int Factorial(int n) {

	if (n == 1) {
		return 1;
	}
	return n * Factorial(n - 1);
}
int main() {

	//Add[��ȯ�ּҰ� ,�������� c , �Ű����� a ,b] 
	//main[��ȯ�ּҰ� , aInt , ]
	int aInt = Add(5, 3);
	float aFloat = Add(1.1f, 2.1f);
	int aInt3 = Add(1,2,3);
	int aInt4 = Add(1,2,3,4);
	int factorial = Factorial(5);

	cout << aInt << endl;
	cout << aFloat << endl;
	cout << aInt3 << endl;
	cout << aInt4 << endl;
	cout << factorial << endl;


	return 0;
}

int Add(int a, int b) {

	int c = a + b;

	return c;
}

int Add(int a, int b , int c) {

	int d = a + b + c;

	return d;
}

float Add(float a, float b) {

	float c = a + b;

	return c;
}
int Add(int a, int b, int c , int d , int e ) { // �Լ��� �⺻���� �ǵں��� �⺻���ڷ� ������ �� �ִ�.

	int f = Add(a, b, c) + Add(d, e);

	return f;
}


/*

���� : ��ȩ�� �����

1. ��ǻ�Ͱ� 1���� 500 ������ ������ ���ڸ� ���´� . 
2. �÷��̾ ���ڸ� �Է��Ѵ�
3. ��ǻ�Ͱ� ���ڰ� ū�� ������ up down ���� ��� �� 400 �� 200 up
4. ��ȩ������ ������� ĸ���ؼ� ���� �ø���


�޸� 4����

code 
data : �������� ��������
stack : ��ȯ�ּҰ� , �������� , �Ű����� ���� ����������
heap 

��ȯ���� , �Ű������� �ڷ��� , ���� , �Լ��̸� => �Լ� �ñ״���

�Լ������ε� : �Լ��� �̸��� �����ϰ� �Ű������� �ڷ����̳� �Ű������� ������ �޶� ��밡��

��������
1.�õ� srand(time(NULL))
2.��������

�Է�
int Num;
cin >> Num;

*/