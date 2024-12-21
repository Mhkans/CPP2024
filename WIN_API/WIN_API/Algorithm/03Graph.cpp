#include <iostream>
#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<algorithm>


using namespace std;

vector<vector<int>> adjacent_List;
vector<vector<bool>> adjacent;

//인접행렬과 인접리스트 - 인접행렬은 탐색속도가 상수이지만 메모리를 많이 차지한다
// 그래프란...
// 1. 레온하르트 오일러가 도시마다 다리를 연결하는 문제에서 생겨난 개념

// 코드로 그래프를 그리는 방법

// - 인접 행렬
// - 인접 리스트
// => 인접 행렬은 탐색속도는 상수이지만, 데이터를 많이 차지한다.

void CreateGraph_List() { //양방향 인접리스트

	adjacent_List.resize(7);
	
	adjacent_List[0].push_back(0);
	adjacent_List[0].push_back(1);
	adjacent_List[0].push_back(2);

	adjacent_List[1].push_back(1);
	adjacent_List[1].push_back(0);
	adjacent_List[1].push_back(4);
	adjacent_List[1].push_back(5);

	adjacent_List[2].push_back(0);
	adjacent_List[2].push_back(2);
	adjacent_List[2].push_back(3);

	adjacent_List[3].push_back(2);
	adjacent_List[3].push_back(3);

	adjacent_List[4].push_back(4);
	adjacent_List[4].push_back(1);
	adjacent_List[4].push_back(6);

	adjacent_List[5].push_back(1);
	adjacent_List[5].push_back(5);

	adjacent_List[6].push_back(4);
	adjacent_List[6].push_back(6);

	

}
void CreateGraph_Matrix() { //인접행렬
	adjacent.resize(7, vector<bool>(7, false));

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

int main()
{
	CreateGraph_List();

	auto Iter = find(adjacent_List[6].begin(), adjacent_List[6].end(), 4);
	if (Iter != adjacent_List[6].end()) {
		cout << "인접" << endl;
	}

	CreateGraph_Matrix();

	if (adjacent[4][1]) {
		cout << "인접" << endl;
	}

	return 0;
}
