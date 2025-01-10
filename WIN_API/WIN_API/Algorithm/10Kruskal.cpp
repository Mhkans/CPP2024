#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

struct Edge {
	int u;//시작점
	int v;//끝점
	int cost;//가중치
};
vector<Edge> edges;
vector<vector<int>> adjacent;

void CreateEdges() {
	for (int u = 0; u < adjacent.size(); u++) {
		for (int v = 0; v < adjacent.size(); v++) {
			if (u >= v) {
				continue;
			}
			if (adjacent[u][v] == -1) {
				continue;
			}
			Edge edge;
			edge.u = u;
			edge.v = v;
			edge.cost = adjacent[u][v];
			edges.push_back(edge);
		}
	}
}

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

class DisJointSet {

public:
	DisJointSet(int n) {

		_parent = vector<int>(n, 0);
		_rank = vector<int>(n, 1);
		for (int i = 0; i < n; i++) {

			_parent[i] = i;
		}
	}
	int FindLeader(int u) {
		if (u == _parent[u]) {
			return u;
		}
		int parent = _parent[u];
		return FindLeader(parent);
	}

	void Merge(int u, int v) {

		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader) {
			return;
		}
		if (_rank[uLeader] > _rank[vLeader]) {

			std::swap(uLeader, vLeader);
		}
		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader]) {
			_rank[vLeader]++;
		}


	}
private:
	vector<int> _parent;
	vector<int> _rank;
};

vector<Edge> Kruskal() {
	//탐욕법
	vector<Edge> result;

	std::sort(edges.begin(), edges.end(), [](const Edge& a , const Edge& b) { //정렬

		if (a.cost < b.cost) {
			return true;

		}
		else {
			return false;
		}
	}); // priority_queue 로만들어도 됨
	DisJointSet set(adjacent.size());
	for (auto& edge : edges) {
		int u = edge.u;
		int v = edge.v;
		if (set.FindLeader(u) == set.FindLeader(v)) { // 서로 같은 집합인가
			continue;

		}
		set.Merge(u, v);
		result.push_back(edge);

	}
	return result;
}
int main()
{
	CreateGraph_Matrix();
	CreateEdges();

	auto edges = Kruskal();

	for (auto& edge : edges) {
		cout << edge.u << "  ~  " << edge.v << " 까지의 길이는  " << edge.cost << endl;
	}
	
	return 0;
}