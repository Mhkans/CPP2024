#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;
//1.완전이진트리 2.부모가 자식보다 커야함 (max heap)
//완전이진트리 -> vector로 구현할수있다
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
	void pop() {//이거완성하기 BFS최단경로 만들어오기
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

			//next는 부모 자식 두명 사이에서 최대값을 가진 Index
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