#include <string>
#include <vector>
#include<iostream>
#include <vector>
#include <memory>


using namespace std;

struct RefCountBlock {

	int refCount = 1;

};

template<typename T>
class SharedPtr {

public:
	SharedPtr(T* ptr) :_block(nullptr), _ptr(ptr) {

		_block = new RefCountBlock();
		cout << "RefCount :" << _block->refCount << endl;
	}
	SharedPtr(const SharedPtr<T>& other) :_ptr(other._ptr), _block(other._block) {

		if (_ptr != nullptr) {

			_block->refCount++;
			cout << "RefCount :" << _block->refCount << endl;
		}
	}
	~SharedPtr() {

		if (_ptr != nullptr) {
			_block->refCount--;
			cout << "RefCount :" << _block->refCount << endl;

			if (_block->refCount <= 0) { // 참조하고있는애가 아무도 없다

				delete _block;
				delete _ptr;
				_ptr = nullptr;

			}
		}
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& other) {

		_ptr = other._ptr;
		_block = other._block;
		if (_ptr != nullptr) {

			_block->refCount++;
			cout << "RefCount :" << _block->refCount << endl;
		}

		return *this;
	}
	T* operator->() {
		if (_ptr != nullptr) {
			return _ptr;

		}
		return nullptr;
	}
private:
	RefCountBlock* _block;
	T* _ptr;
};

class Knight {

public:
	Knight() {
		cout << "knight 기본 생성자" << endl;
	}
	Knight(int a) {
		cout << "knight 타입변환 생성자" << endl;
	}
	~Knight() {
		cout << "knight 소멸자" << endl;
	}

	void Attack(SharedPtr<Knight> other) {

		other->_hp -= _atk;
	}
	void Attack() {

		target->_hp -= _atk;
	}
	void attack() {

		if (Target.expired() == false) {
			Target.lock()->_hp -= _atk;
		}
		
	}
	SharedPtr<Knight> target = nullptr;
	weak_ptr<Knight> Target;
	int _hp = 0 ;
	int _atk = 0;
private:
};
int main() {

	/*
	shared_ptr<Knight> k = make_shared<Knight>();

	k->_atk = 10;
	k->_hp = 100;

	shared_ptr<Knight> k2 = make_shared<Knight>();

	k->_atk = 5;
	k->_hp = 50;

	k->Attack(k2);
	k2->Attack(k);
	*/
	//얕은복사 -> refcount로 delete할지 결정
	SharedPtr<Knight> p1 = SharedPtr<Knight>(new Knight());
	SharedPtr<Knight> p2 = SharedPtr<Knight>(new Knight());

	p1->target = p2;
	p2->target = p1;
	p1->Attack();
	p2->Attack();
	p1->target = nullptr;
	p2->target = nullptr;
	
	return 0;
}