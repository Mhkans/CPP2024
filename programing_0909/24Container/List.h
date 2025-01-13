#pragma once
template<typename T>
struct Node {
	Node():data(T()),prev(nullptr),next(nullptr){}
	Node(const T& data):data(data),prev(nullptr),next(nullptr){}
	~Node(){}
	T data;
	Node<T>* prev;
	Node<T>* next;
};
template<typename T>
class List {
public:
	List() :_size(0) {
		_head = new Node<T>();
		_head->next = _head;
		_head->prev = _head;
	}
	~List() {

		clear();
		delete _head;
	}
	void clear() {
		int size = _size;
		for (int i = 0; i < size; i++) {
			pop_back();
		}
	}
	
	void push_back(const T& data) {

		Node<T>* newNode = new Node<T>(data);

		Node<T>* prevNode = _head->prev;
		Node<T>* nextNode = _head;
		
		newNode->next = nextNode;
		newNode->prev = prevNode;

		nextNode->prev = newNode;
		prevNode->next = newNode;

		_size++;
	}
	void push_front(const T& data) {
		Node<T>* newNode = new Node<T>(data);

		Node<T>* prevNode = _head;
		Node<T>* nextNode = _head->next;

		newNode->prev = prevNode;
		newNode->next = nextNode;

		prevNode->next = newNode;
		nextNode->prev = newNode;

		_size++;

	}
	void pop_back() {

		Node<T>* delNode = _head->prev;
		Node<T>* prevNode = delNode->prev;

		delete delNode;

		prevNode->next = _head;
		_head->prev = prevNode;

		_size--;

	}
	void pop_front() {
		Node<T>* delNode = _head->next;
		Node<T>* nextNode = delNode->next;

		delete delNode;

		nextNode->prev = _head;
		_head->next = nextNode;

		_size--;
	}
	T operator[](size_t index) {
		if (index >= _size) {
			//error
		}
		Node<T>* node = _head->next;
		for (int i = 0; i < index; i++) {
			node = node->next;

		}
		return node->data;
	}
	void insert(const T& data, size_t index) {
		Node<T>* newNode = new Node<T>(data);
		Node<T>* prevNode = at(index);
		Node<T>* nextNode = prevNode->next;

		prevNode->next = newNode;
		nextNode->prev = newNode;

		newNode->next = nextNode;
		newNode->prev = prevNode;
		_size++;
	}
	size_t size() { return _size; }
private:
	Node<T>* at(size_t index) {
		Node<T>* node = _head->next;
		for (int i = 0; i < index; i++) {
			node = node->next;

		}
		return node;
	}
	Node<T>* _head;
	size_t _size;
};