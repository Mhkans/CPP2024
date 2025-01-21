#include <string>
#include <vector>
#include<iostream>
using namespace std;

/*
shift move : �̵�

lvalue : ������ �� �ִ� ���� (����)
rvalue : lvalue �� �ƴ� �� , ���� ������ �� ���� �� (���)
*/

class Pet {

public:
};

class Player {
public:
    Player() :_pet(new Pet()) { cout << " �⺻������ ȣ��" << endl; }
    Player(int hp) :_hp(hp), _pet(new Pet()) { cout << "Ÿ�Ժ�ȯ ������ " << endl; }
    Player(const Player& other) : _hp(other._hp), _pet(new Pet(*other._pet)) { cout << "���� ������" << endl; } //_pet(other._pet) �������� ->�ȵ�
    ~Player() { 
        if(_pet!=nullptr)
        delete _pet; 
    
        cout << "�Ҹ��� ȣ��" << endl;
    }
    Player(Player&& other) noexcept //�̵������� other�Ǹ����� ���� ������ �� �ű�� other�� �����⸸ �����.
    {
        cout << "�̵������� ȣ��" << endl;
        _hp = other._hp;
        _pet = other._pet;
        other._pet = nullptr;
    }
    int _hp = 0;
    Pet* _pet;
};
/*
void Func(Player p) {

    //p = Player(5);  �ڷ����� ���µ� ���� => ������� , Ÿ�Ժ�ȯ����
    //Player p3 = Player(5); // Ÿ�Ժ�ȯ������ ȣ�� , �ڷ����� �ִµ� ���� => ������ Ÿ�Ժ�ȯ������
    
}
void Func(Player* p) {

    //�������� ���� 4,8����Ʈ
    //������ ���� ������
    

}
void Func(Player& p) {

    //�������� ���Ե��
    //������ ���� ������
    //���°� Ȥ�� �ӽð�ü�� �ѱ� �� ����
}
*/
//������ ���� ����

void Func(Player&& p) {

    //�������� ���� ���
    //������ ���� ������
    //call by value�� �����ϰ� �۵� ���⽱��
    //�ӽð�ü �ѱ� �� �ִ�.
    cout << "������ ���� ����" << endl;
}

int main(){

    //int(10) = 5; X �ӽð� �ӽð�ü
    //Player()._hp = 10; Player() �̸��� ���� �ӽð�ü �����ٿ� �����

    //Player&& : ������ ���� :lvalue �� rvalue�� ����� -> lvalue�� �����⸸ �����
    Player* p = new Player();
    Player* p2 = new Player(*p);
    Player* p3 = new Player(move(*p2));
    //���ϳ��� �����ؾ� �ϴ� ptr
    unique_ptr<Player> unique_p = make_unique<Player>(1);
    unique_ptr<Player> uniquer_p2 = move(unique_p); //�� ����ϰڴ�

    Func(Player()); //�ӽð�ü��(������) ������ ������ �ѱ�� ->�ӽð�ü�� ���� �ٷ� �Ҹ�
    Func(std :: move(*p)); // *p�� ������ ������ �ѱ�� -> *p�� ���Ŀ� �����⸸ ����ڴ�.


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