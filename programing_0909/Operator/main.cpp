#include<iostream>

using namespace std;

/*
operator : ������

aInt + bInt = a�� b�� ���ϰ� �ӽð��� ��ȯ�Ѵ� ����
aFloat + bFloat = a�� b�� ���ϰ� �ӽð��� ��ȯ�Ѵ� �Ǽ�
aInt / bInt = ���� ������ �������� ����
aFloat / bFloat = �Ǽ� ������ �Ǽ����� ����
�Ǽ����� ������ ���� �ȵ�

���Կ����� 
=
a = b : a�� b�� �����ϰ� a�� ������ ��ȯ�Ѵ�.

���׿�����

++aInt : ���������� aInt ������ 1�� ���ϰ� aInt������ ��ȯ�Ѵ�
aInt++ : ���������� aInt �� ���� ������ �ӽð��� ����� aInt�� 1�� ���� �� �ӽð��� ��ȯ�Ѵ�.

�񱳿�����
> < == !=
��ȯ���� bool

aInt = 3  bInt = 5

aInt > bInt : false
aInt == bInt : false 
aInt!=bInt : true

��������
! && ||

! : true ������ false false������true
&& : and �Ѵ� true �̸� true ���߿� �ϳ��� false �� false
|| : or ���߿� �ϳ��� true�� true �Ѵ� false �� false

��Ʈ������
<< , >> , & , | , ^

<< : ���� shift���� , ���ϱ� 2 ó�� ������ ������ ��Ʈ�� 0����ä������. ���� unsigned ������ ���̾���
>> : ������ shift���� ,������ 2 �ƴ� , �� ������ ��Ʈ�� �������� ��ȣ��Ʈ�� �� ���� ��Ʈ�� ��ȣ�� �����Եȴ�.
��Ʈ & ��Ʈ : ��Ʈand���� �� ��Ʈ�߿� �����͸� 1 ������ 0 
��Ʈ | ��Ʈ : ��Ʈor���� 
��Ʈ ^ ��Ʈ : ��Ʈ xor���� ������ false �ٸ��� true

^�� �ι����� ������ �˼��ִ� ��ȣ���� ���

(aInt ^ bInt)^bInt = aInt


�����̻� ó���Ҷ� ��밡��


*/

int main() {

	
	int aInt = 10;
	int bInt = 3;

	int dInt = (aInt = bInt); // 3 

	aInt += bInt; //6

	aInt = 0;
	bInt = 3;

	

	//cout << ++aInt << endl; 1
	
	aInt = bInt++; //a = 3 b = 4
	aInt = ++bInt; //a = 5 b = 5

	cout << aInt << endl; // 5

	aInt = 3;
	bInt = 5;

	bool check1 = (aInt < bInt);//1 t
	bool check2 = (aInt == bInt);//0 f
	bool check3 = check1 < check2;//0 f
	bool check4 = (check1 && check3);// 0 f
	bool check5 = !check4 +10;//1 t
	bool check6 = check4 || check5 || check1||check3||check2;//1 t
	
	unsigned char stun = 0b1000;
	unsigned char airbone = 0b0100;
	unsigned char rooted = 0b0010;
	unsigned char slow = 0b0001;
	//�����̻� ó���Ҷ� ��밡��
	unsigned char bitFlag = 0;

	//������ �ɸ�
	bitFlag = 0b1000;
	bitFlag = stun | slow; // ���� , ��ȭ ����
	//������ �ɷȴ��� Ȯ���ϰ�ʹ� ���ǹ��ȿ� 0�� �ƴϸ� true
	if (bitFlag & stun /* 0b1000*/) {
		//and��Ʈ�������� �����̻� Ȯ��
		cout << " ���������Դϴ� " << endl;
	}

	bitFlag^ slow; // bitFlag -= slow;
	bitFlag | rooted;

	/*
	bitFlag ^=(slow|rooted);
	*/
	if (bitFlag & stun | bitFlag & rooted) { // bitFlag&(slow|rooted)
		cout << " ������ �ӹڿ� �ɷȽ��ϴ� " << endl;

	}


}
/*
����
1. ���(����ٲܼ�����)�� ǥ���ϴ� 3���� ���

*/