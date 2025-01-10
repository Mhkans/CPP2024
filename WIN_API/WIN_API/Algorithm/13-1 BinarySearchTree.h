#pragma once
#include <iostream>
using namespace std;
struct Node {

	Node(){}
	Node(int key):key(key){}

	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;

	int key = -1;
	int data = 0;
};
class BinarySearchTree {

public:
	BinarySearchTree(){}
	~BinarySearchTree(){}

	Node* root = nullptr;

	void Insert(int key)
	{
		Node* newNode = new Node(key);
		if (root == nullptr) {

			root = newNode;
			return;
		}
		Node* node = root;
		Node* parent = nullptr;

		while (true) {
			if (node == nullptr) {//������ leaf��� ��� break

				break;
			}
			parent = node;

			if (key < node->key) {
				node = node->left;
			}
			else {
				node = node->right;
			}

		}
		//�θ� ã������ �������� ���������� ã��
		newNode->parent = parent;
		if (key < parent->key) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
	void PrintTree(Node* node) {
		if (node == nullptr) {
			return;
		}
		//������ȸ �θ� - ���� - ������
		/*cout << node->key << endl;
		PrintTree(node->left);
		PrintTree(node->right);*/
		
		//������ȸ ���� - �θ� - ������
		PrintTree(node->left);
		cout << node->key << endl;
		PrintTree(node->right);

		//������ȸ ������ - �θ� -����
		/*PrintTree(node->left);
		PrintTree(node->right);		
		cout << node->key << endl;*/
		
	}

	Node* Min(Node* node) {
		if (node == nullptr) {

			return nullptr;
		}
		if (node->left != nullptr) {
			return Min(node->left);
			
		}
		return node;

	}
	Node* Max(Node* node) {
		if (node == nullptr) {

			return nullptr;
		}
		if (node->right != nullptr) {
			return Max(node->right);

		}
		return node;
	}
	Node* Search(Node* node, int key) {

		if (node == nullptr) {

			return nullptr;
		}
		if (node->key == key) {
			return node;
		}
		if(node->key > key){
			return Search(node->left, key);
		}
		if(node->key < key){
			return Search(node->right, key);
		}
		return nullptr;
	}
	Node* Previous(Node* node) {//root ����
		if (node == nullptr) {
			return nullptr;
		}
		if (node->left == nullptr) {
			return nullptr;
		}
		return Max(node->left);
	}
	Node* Next(Node* node) {//root ����
		if (node == nullptr) {
			return nullptr;
		}
		if (node->right == nullptr) {
			return nullptr;
		}
		return Min(node->right);

	}
	void Delete(Node* node) {
		if (node == nullptr) {
			return;
		}
		if (node->parent == nullptr) {
			Replace(node, next(node));
		}		
		else if (node->left == nullptr &&node->right == nullptr) {
			if (node->parent->left == node) {
				node->parent->left =nullptr;
			}
			else {
				node->parent->right = nullptr;
			}
			delete node;
		}
		else if (node->left == nullptr) {
			Replace(node, node->right);
		}
		else{
			Replace(node, node->left);
		}
	}
	
private:
	void Replace(Node* node1, Node* node2) {

		if (node1->parent == nullptr) {
			root = node2;
		}
		else if (node1 == node1->parent->left) {
			node1->parent->left = node2;
		}
		else {
			node1->parent->right = node2;
		}
		if (node2 != nullptr) {
			node2->parent = node1->parent;
		}
		delete node1;
	}
};