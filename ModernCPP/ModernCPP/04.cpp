#include <string>
#include <vector>
#include<iostream>
using namespace std;

/*
shift move : 이동

lvalue : 수정할 수 있는 변수 (참조)
rvalue : lvalue 가 아닌 수 , 식을 수정할 수 없는 수 (상수)
*/

class Pet {

public:
};

class Player {
public:
    Player() :_pet(new Pet()) { cout << " 기본생성자 호출" << endl; }
    Player(int hp) :_hp(hp), _pet(new Pet()) { cout << "타입변환 생성자 " << endl; }
    Player(const Player& other) : _hp(other._hp), _pet(new Pet(*other._pet)) { cout << "복사 생성자" << endl; } //_pet(other._pet) 얕은복사 ->안됨
    ~Player() { 
        if(_pet!=nullptr)
        delete _pet; 
    
        cout << "소멸자 호출" << endl;
    }
    Player(Player&& other) noexcept //이동생성자 other의모든것을 현재 나에게 다 옮기고 other은 껍데기만 남긴다.
    {
        cout << "이동생성자 호출" << endl;
        _hp = other._hp;
        _pet = other._pet;
        other._pet = nullptr;
    }
    int _hp = 0;
    Pet* _pet;
};
/*
void Func(Player p) {

    //p = Player(5);  자료형이 없는데 대입 => 복사대입 , 타입변환대입
    //Player p3 = Player(5); // 타입변환생성자 호출 , 자료형이 있는데 대입 => 생성자 타입변환생성자
    
}
void Func(Player* p) {

    //복사비용이 낮음 4,8바이트
    //원본에 접근 가능함
    

}
void Func(Player& p) {

    //복사비용이 적게든다
    //원본에 접근 가능함
    //없는값 혹은 임시객체를 넘길 수 없다
}
*/
//우측값 참조 전달

void Func(Player&& p) {

    //복사비용이 적게 든다
    //원본에 접근 가능함
    //call by value와 동일하게 작동 쓰기쉽다
    //임시객체 넘길 수 있다.
    cout << "우측값 참조 전달" << endl;
}

int main(){

    //int(10) = 5; X 임시값 임시객체
    //Player()._hp = 10; Player() 이름이 없는 임시객체 다음줄에 사라짐

    //Player&& : 우측값 참조 :lvalue 를 rvalue로 만든다 -> lvalue는 껍데기만 남긴다
    Player* p = new Player();
    Player* p2 = new Player(*p);
    Player* p3 = new Player(move(*p2));
    //단하나만 존재해야 하는 ptr
    unique_ptr<Player> unique_p = make_unique<Player>(1);
    unique_ptr<Player> uniquer_p2 = move(unique_p); //다 흡수하겠다

    Func(Player()); //임시객체를(생성자) 우측값 참조로 넘긴다 ->임시객체를 쓰고 바로 소멸
    Func(std :: move(*p)); // *p를 우측값 참조로 넘긴다 -> *p는 이후에 껍데기만 남기겠다.


    delete p;
    delete p2;
    delete p3;
    cout << "--------------------------------" << endl;
    vector<Player> players;
    Player player123;
    players.push_back(Player());
    players.emplace_back(Player());

    players.emplace_back(move(player123));




    return 0;
}