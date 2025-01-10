#include "framework.h"
#include"Math/DisjointSet.h"
#include "Maze.h"
#include "Block.h"
Maze::Maze()
{
	Vector offset = Vector(400, 100);
	_blocks.resize(MAX_Y);
	for (int y = 0; y < MAX_Y; y++) {
		_blocks[y].reserve(MAX_X);
		for (int x = 0; x < MAX_X; x++) {

			shared_ptr<Block> block = make_shared<Block>();
			Vector pos;
			pos.y = y*21;
			pos.x = x*21;
			block->SetPos(pos+offset);
			block->SetType(Block::ABLE);
			_blocks[y].push_back(block);
		}
	}
	CreateMaze_Kruskal();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
		{
			block->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
		{
			block->Render(hdc);
		}
	}
}

void Maze::CreateMaze()
{
	// 사방향 벽을 막고
	// 갈 수 있는 노드 만들기
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetType(Block::BlockType::DISABLE);
			}
			else
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
			}
		}
	}

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			// 시작점
			if (x == 1 && y == 1)
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
			}

			// 끝점
			if (x == MAX_X - 2 && y == MAX_Y - 2)
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
				continue;
			}

			// 처음 빨간 곳으로 설정한 블럭
			if (x % 2 == 0 || y % 2 == 0) continue;

			// 오른쪽 맨 끝에 있는 노드는 아래쪽으로 뚫는다.
			if (x == MAX_X - 2)
			{
				_blocks[y + 1][x]->SetType(Block::BlockType::ABLE);
				continue;
			}

			// 맨 아래쪽 끝에 있는 노드는 오른쪽으로만 뚫는다.
			if (y == MAX_Y - 2)
			{
				_blocks[y][x + 1]->SetType(Block::BlockType::ABLE);
				continue;
			}

			// 오른쪽 아니면 아래쪽으로만 뚫는다
			int randValue = rand() % 2;
			if (randValue == 0)
				_blocks[y][x + 1]->SetType(Block::BlockType::ABLE); // 오른쪽 뚫기
			else
				_blocks[y + 1][x]->SetType(Block::BlockType::ABLE); // 아래쪽 뚫기
		}
	}
}

void Maze::CreateMaze_Kruskal()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetType(Block::BlockType::DISABLE);
			}
			else
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
			}
		}
	}
	//Edge만들기

	vector<Edge> edges;
	for (int y = 0; y < MAX_Y; y++) {

		for (int x = 0; x < MAX_X; x++) {

			if (x % 2 == 0 ||y%2 ==0) { //노드가 아니면 패스
				continue;
			}
			if (x < MAX_X - 2) {
				int randCost = rand() % 100;

				Edge edge;
				edge.cost = randCost;
				edge.u = Vector(x, y);
				edge.v = Vector(x + 2, y);

				edges.push_back(edge);

			}
			if (y < MAX_Y - 2) {
				int randCost = rand() % 100;

				Edge edge;
				edge.cost = randCost;
				edge.u = Vector(x, y);
				edge.v = Vector(x, y+2);

				edges.push_back(edge);

			}
			
		}
	}

	std::sort(edges.begin(), edges.end(), [](const Edge& a , const Edge& b) {

		if (a.cost < b.cost) {
			return true;
		}
		else {
			return false;
		}

	});
	DisJointSet set(MAX_Y * MAX_X);
	for (auto& edge : edges) {
		int u = edge.u.y * MAX_Y + edge.u.x;
		int v = edge.v.y * MAX_Y + edge.v.x;

		if (set.FindLeader(u) == set.FindLeader(v)) {
			continue;
		}
		set.Merge(u, v);
		int x = ((int)edge.u.x + (int)edge.v.x) / 2;
		int y = ((int)edge.u.y + (int)edge.v.y) / 2;
		_blocks[y][x]->SetType(Block::BlockType::ABLE);
	}
}
