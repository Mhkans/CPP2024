#include <iostream>
#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<algorithm>


using namespace std;

vector<vector<bool>> adjacent;
vector<bool> visited;

void CreateGraph_Matrix() {
	adjacent.resize(7, vector<bool>(7, false));
	visited = vector<bool>(7, false);


	// 7 x 7
	//    0   1   2   3   4   5   6
	// 0  T   T   T   F   F   F   F
	// 1  T   T   F   F   T   T   F
	// 2  T   F   T   T   F   F   F
	// 3  F   F   T   T   F   F   F
	// 4  F   T   F   F   T   F   T
	// 5  F   T   F   F   F   T   F
	// 6  F   F   F   F   T   F   T


	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][4] = true;
	adjacent[1][5] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;

	adjacent[3][2] = true;
	adjacent[3][3] = true;

	adjacent[4][1] = true;
	adjacent[4][4] = true;
	adjacent[4][6] = true;

	adjacent[5][1] = true;
	adjacent[5][5] = true;

	adjacent[6][4] = true;
	adjacent[6][6] = true;



}
//함수의 스택프레임을 이용하여 재귀
void DFS(int here ) {

	visited[here] = true;
	cout << here << "방문" << endl;

	for (int there = 0; there < adjacent.size(); there++) {
		if (here == there) {//자기자신 확인
			continue;
		}
		if (!adjacent[here][there]) {//인접했는지 확인
			continue;
		}
		if (visited[there]) {//방문되었는지 확인
			continue;
		}
		DFS(there);
	}

}
void DFS_ALL() { //DFS를 이용해서 인접한 집단의 수를 아는방법

	int count = 0;
	for (int i = 0; i < adjacent.size(); i++) {

		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}
	cout << count << endl;
}
int main()
{
	CreateGraph_Matrix();
	DFS(0);

	return 0;
}
