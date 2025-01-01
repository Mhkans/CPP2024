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
	int g = 0; // 가중치

};
//다익스트라 - 시작점이 존재함
// - BFS기반 우선순위 큐 사용 
vector<bool> discovered;
vector<int> parent;
vector<int> best; //해당 노드의 최소 가중치를 기입

void Djikstra(int start) {

	parent = vector<int>(adjacent.size(), -1);
	best.resize(adjacent.size(), INT_MAX);
	priority_queue<Vertex_djikstra, vector<Vertex_djikstra>, greater<Vertex_djikstra>> pq; //힙에서 내려갈수록 커져야하니까 greater가 최소힙을 이룬다

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

		if (best[here.vertexNum] < here.g) { //더 좋은 경로를 발견했을때 알림
			cout << here.vertexNum << endl; 
			cout << here.g << endl; 
			cout << best[here.vertexNum] << endl;
			continue;
		}
		for (int there = 0; there < adjacent.size(); there++) {

			if (here.vertexNum == there) {
				continue;
			}
			if (adjacent[here.vertexNum][there] == -1) {//인접했나
				continue;
			}
			int nowCost = best[here.vertexNum] + adjacent[here.vertexNum][there]; // 지금 나의 위치의 베스트값 there까지의 간선의 길이

			if (nowCost >= best[there]) {//이전 best가 더 작았을때
				continue;
			}
			
			pq.push(Vertex_djikstra(there,nowCost));
			best[there] = nowCost;
			parent[there] = here.vertexNum;
		}
	}
}
// 인접행렬
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
		cout << i << "의 부모 : " << parent[i] << endl;
		cout << "0부터 " << i << "까지의 최소 가중치" << best[i] << endl;
	}

	return 0;
}