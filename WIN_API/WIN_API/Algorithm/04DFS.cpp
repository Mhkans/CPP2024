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
//�Լ��� ������������ �̿��Ͽ� ���
void DFS(int here ) {

	visited[here] = true;
	cout << here << "�湮" << endl;

	for (int there = 0; there < adjacent.size(); there++) {
		if (here == there) {//�ڱ��ڽ� Ȯ��
			continue;
		}
		if (!adjacent[here][there]) {//�����ߴ��� Ȯ��
			continue;
		}
		if (visited[there]) {//�湮�Ǿ����� Ȯ��
			continue;
		}
		DFS(there);
	}

}
void DFS_ALL() { //DFS�� �̿��ؼ� ������ ������ ���� �ƴ¹��

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
