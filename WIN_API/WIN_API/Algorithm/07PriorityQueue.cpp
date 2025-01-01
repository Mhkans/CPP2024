#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;
//1.��������Ʈ�� 2.�θ� �ڽĺ��� Ŀ���� (max heap)
//��������Ʈ�� -> vector�� �����Ҽ��ִ�
template<typename T>

class Priority_Queue {
	//123 1 12 3 55 150 6
public:
	void push(const T& value) {

		v.push_back(value);
		int nowIndex = v.size() - 1;
		while (true) {
			if (nowIndex <= 0) {
				break;
			}
			int parentIndex = (nowIndex - 1) / 2;
			if (v[parentIndex] >= v[nowIndex]) {
				break;
			}
			swap(v[nowIndex], v[parentIndex]);
			nowIndex = parentIndex;
		}
	}
	void pop() {//�̰ſϼ��ϱ� BFS�ִܰ�� ��������
		if (v.size() == 1) {
			v.pop_back();
			return;
		}
		if (v.empty()) {
			return;
		}
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		int nowIndex = 0;

		while (true) {
			int leftChild = nowIndex * 2 + 1;
			int rightChild = nowIndex * 2 + 2;

			if (leftChild >= v.size()) {
				break;
			}
			int next = nowIndex;
			if ((v[next]<v[leftChild]))
			{
				next = leftChild;
			}
			if (rightChild < v.size() && v[next] < v[rightChild])
			{
				next = rightChild;
			}

			if (nowIndex == next)
				break;

			//next�� �θ� �ڽ� �θ� ���̿��� �ִ밪�� ���� Index
			std::swap(v[nowIndex], v[next]);
			nowIndex = next;
		}
			//123 1 12 3 55 150 6
			// 0  1  2  3 4 5  6

		
	}
	int top() {

		return v[0];

	}
	bool empty() {

		return v.empty();
	}

private:
	vector<T> v;
};
int main() {
	
	Priority_Queue<int> pq;
	pq.push(123);
	pq.push(1);
	pq.push(12);
	pq.push(3);
	pq.push(55);
	pq.push(150);
	pq.push(6);

	while (true) {
		if (pq.empty()) {
			
			break;

		}
		int top = pq.top();
		cout << top << endl;
		pq.pop();
	}
	return 0;
}