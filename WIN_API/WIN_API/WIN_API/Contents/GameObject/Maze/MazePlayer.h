#pragma once
class Maze;

class MazePlayer
{
public:
	enum Dir
	{
		UP,
		LEFT,
		DOWN,
		RIGHT,

		DIR_COUNT = 4
	};
	struct Vertex_djikstra {
		Vertex_djikstra(int y,int x,int g):y(y),x(x),g(g){}

		bool operator>(const Vertex_djikstra& other) const {
			return g > other.g;
		}
		bool operator<(const Vertex_djikstra& other) const {

			return g < other.g;
		}

		int y;
		int x;
		int g;

	};
	struct Vertex {
		Vertex(float y, float x) :y(y), x(x) {}

		bool operator>(const Vertex& other) const {
			return f > other.f;
		}
		bool operator<(const Vertex& other) const {

			return f < other.f;
		}

		float y;
		float x;

		float g = 0.0f;
		float h = 0.0f;
		float f = 0.0f;

	};
	MazePlayer();
	~MazePlayer();

	void Update();

	void SetMaze(shared_ptr<Maze> maze);
	void Init();
	Vector& GetStartPos() { return _startPos; }
	Vector& GetEndPos() { return _endPos; }

	void RightHand();
	void RightHand_stack();

	void FindPath_DFS();
	void DFS(int y, int x);

	void FindPath_BFS();
	void BFS();

	void Shortest_FindPath_BFS();
	void Shortest_BFS();

	void FindPath_Djikstra(const Vector& start);

	void FindPath_Astar(const Vector& start ,const Vector& end);

	bool CanGo(int y, int x);

private:
	shared_ptr<Maze> _maze;

	Dir _dir = Dir::UP;
	Vector _pos = {1,1};
	Vector _startPos = {};
	Vector _endPos = {};

	int _pathIndex = 0;
	int _footPrintIndex = 0;
	float _time = 0.0f;

	vector<Vector> _path; // 찾은 길에 대한 정보
	vector<vector<bool>> _visited;
	queue<Vector> q;
	vector<vector<Vector>> _parents;
};

