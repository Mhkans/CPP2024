#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
/*

6. using
- typedef 와 동일
typedef의 단점 : template과 호환 안됨 

7. enum class
-장점 : 열거형의 이름이 겹쳐도 상관없다
 단점 : casting을 해줘야한다
*/
//6
typedef unsigned int UINT;
using UINT2 = unsigned int;

template<typename T>
using MyV = std::vector<T>;
//typedef std::vector<T> Myv; 안됨

//7
/*
enum PlayerType {
	NONE,Knight,Mage,Archer
};

enum ItemType {

	NONE, Potion,Armor,Weapon // NONE이 재정의됨
};*/

enum class PlayerType {
	NONE, Knight, Mage, Archer
};

enum class ItemType {

	NONE, Potion, Armor, Weapon // NONE이 재정의됨
}; 

int main() {
	
	PlayerType type = PlayerType::NONE;
	PlayerType type2 = static_cast<PlayerType>(1);






	return 0;
}