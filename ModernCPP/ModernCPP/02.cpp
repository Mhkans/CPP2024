#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
/*

6. using
- typedef �� ����
typedef�� ���� : template�� ȣȯ �ȵ� 

7. enum class
-���� : �������� �̸��� ���ĵ� �������
 ���� : casting�� ������Ѵ�
*/
//6
typedef unsigned int UINT;
using UINT2 = unsigned int;

template<typename T>
using MyV = std::vector<T>;
//typedef std::vector<T> Myv; �ȵ�

//7
/*
enum PlayerType {
	NONE,Knight,Mage,Archer
};

enum ItemType {

	NONE, Potion,Armor,Weapon // NONE�� �����ǵ�
};*/

enum class PlayerType {
	NONE, Knight, Mage, Archer
};

enum class ItemType {

	NONE, Potion, Armor, Weapon // NONE�� �����ǵ�
}; 

int main() {
	
	PlayerType type = PlayerType::NONE;
	PlayerType type2 = static_cast<PlayerType>(1);






	return 0;
}