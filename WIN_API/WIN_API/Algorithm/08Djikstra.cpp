#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> adjacent;

struct Vertex_djikstra {
	Vertex_djikstra(int num , int g):vertexNum(num),g(g){}
	bool operator<(const Vertex_djikstra& other) const {

		return g < other.g;
	}
	bool operator>(const Vertex_djikstra& other) const {

		return g > other.g;
	}
	int vertexNum = 0;
	int g = 0; // ����ġ

};
//���ͽ�Ʈ�� - �������� ������
// - BFS��� �켱���� ť ��� 
vector<bool> discovered;
vector<int> parent;
vector<int> best; //�ش� ����� �ּ� ����ġ�� ����

void Djikstra(int start) {

	parent = vector<int>(adjacent.size(), -1);
	best.resize(adjacent.size(), INT_MAX);
	priority_queue<Vertex_djikstra, vector<Vertex_djikstra>, greater<Vertex_djikstra>> pq; //������ ���������� Ŀ�����ϴϱ� greater�� �ּ����� �̷��

	Vertex_djikstra startV = Vertex_djikstra(start, 0);
	best[start] = 0;
	pq.push(startV);

	parent[startV.vertexNum] = startV.vertexNum;

	while (true) {
		if (pq.empty()) {
			break;
		}
		Vertex_djikstra here = pq.top();
		pq.pop();

		if (best[here.vertexNum] < here.g) { //�� ���� ��θ� �߰������� �˸�
			cout << here.vertexNum << endl; 
			cout << here.g << endl; 
			cout << best[here.vertexNum] << endl;
			continue;
		}
		for (int there = 0; there < adjacent.size(); there++) {

			if (here.vertexNum == there) {
				continue;
			}
			if (adjacent[here.vertexNum][there] == -1) {//�����߳�
				continue;
			}
			int nowCost = best[here.vertexNum] + adjacent[here.vertexNum][there]; // ���� ���� ��ġ�� ����Ʈ�� there������ ������ ����

			if (nowCost >= best[there]) {//���� best�� �� �۾�����
				continue;
			}
			
			pq.push(Vertex_djikstra(there,nowCost));
			best[there] = nowCost;
			parent[there] = here.vertexNum;
		}
	}
}
// �������
void CreateGraph_Matrix()
{
	adjacent.resize(7, vector<int>(7, -1));
	
	adjacent[0][0] = 0;
	adjacent[0][1] = 10;
	adjacent[0][2] = 3;

	adjacent[1][0] = 10;
	adjacent[1][1] = 0;
	adjacent[1][4] = 1;
	adjacent[1][5] = 4;

	adjacent[2][0] = 3;
	adjacent[2][2] = 0;
	adjacent[2][3] = 2;

	adjacent[3][2] = 2;
	adjacent[3][3] = 0;
	adjacent[3][4] = 2;

	adjacent[4][1] = 1;
	adjacent[4][3] = 2;
	adjacent[4][4] = 0;
	adjacent[4][6] = 7;

	adjacent[5][1] = 4;
	adjacent[5][5] = 0;

	adjacent[6][4] = 7;
	adjacent[6][6] = 0;
}



int main()
{
	CreateGraph_Matrix();
	Djikstra(0);
	cout << best[6] << endl;
	for (int i = 0; i < adjacent.size(); i++) {
		cout << i << "�� �θ� : " << parent[i] << endl;
		cout << "0���� " << i << "������ �ּ� ����ġ" << best[i] << endl;
	}

	return 0;
}