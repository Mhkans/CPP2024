#include<iostream>
#include<vector>
#include<list>

using namespace std;

//�����迭
int arr[5] = { 1,2,3,4,5 };

//�����迭
//vector
/*
1. ���̰� �������� ���Ҽ��ִ�

���ÿ��� ���� ����Ŵ
������ 4�� �뷮�� �Ѿ�� 5�� �뷮�� �����
���� ������ �����ؼ� �ű�� ���

capacity : �ڿ� �󸶳� �߰����� �𸣴� �̸� 1.5�� �Ҵ�

size : ���� ���� ������

���� �޸� ����ȭ,����ȭ -> �ü������ ������

���Ͱ� ����Ʈ���� ���Ի����� ��������
ĳ�н��Ϳ� ����� �����Ҷ� �ش� ��ġ�� new delete�� �����ϱ⶧����
*/

#include"vector_Iter.h"

int main() {

	Vector<int> v;
	
	//v.reserve(1000); //capacity�� �̸� 1000 ������� 1����
	//v.resize(1000,-1); // size���� �̸� 1000

	v.reserve(3000);
	for (int i = 0; i < 1000; i++) {

		v.push_back(i);
		cout << "Capacity : " << v.capacity() << endl;
		cout << "size     : " << v.size() << endl;
		cout << endl;
	}

	//v.shrink_to_fit(); //capacity�� size�� ������


	Vector<int>::Iterator iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}




	return 0;
}
