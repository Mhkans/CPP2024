#include "framework.h"
#include "MazePlayer.h"
#include "Contents/GameObject/Maze/Maze.h"
#include "Contents/GameObject/Maze/Block.h"

MazePlayer::MazePlayer()
{
}

MazePlayer::~MazePlayer()
{
}

void MazePlayer::Update() //플레이어 위치표시
{
    if (_pathIndex >= _path.size() - 1) {
               
        _maze->CreateMaze_Kruskal();
        Init();
        FindPath_Astar(_startPos,_endPos);
        _maze->SetBlockType(_maze->GetEndPos().y, _maze->GetEndPos().x, Block::BlockType::NONE);

    }

    _time += 0.2f;
    if (_time > 1.0f)
    {
        _time = 0.0f;
        _maze->SetBlockType(_pos.y, _pos.x, Block::BlockType::FOOT_PRINT);
        _pos = _path[_pathIndex];

        _pathIndex++;
    }

    _maze->SetBlockType(_pos.y, _pos.x, Block::Block::PLAYER);
   
}

void MazePlayer::SetMaze(shared_ptr<Maze> maze)
{
    _maze = maze;
}

void MazePlayer::Init()
{
    _pos = _startPos;
    _pathIndex = 0;
    _time = 0.0f;
    _dir = Dir::UP;
    _path.clear();

    if (_maze != nullptr)
    {
        _startPos = _maze->GetStartPos();
        _endPos = _maze->GetEndPos();
    }
}

void MazePlayer::RightHand()
{
    // 우수법으로 갈 수 있는 경로(pos)들을 _path에다가 담아놓을 예정
    _pos = _startPos;
    _path.push_back(_pos);

    Vector frontPos[4] = 
    {
        Vector{0, -1}, // UP
        Vector{-1, 0}, // LEFT
        Vector{0,1}, // DOWN
        Vector{1,0} // RIGHT
    };

    while (true)
    {
        // 끝점에 도달했다.
        if (_pos == _endPos)
        {
            _path.push_back(_pos);
            break;
        }

        // 이동
        int newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT; // 오른쪽 회전 => % 순환 구조를 이용한 설계
        Vector oldDirVector = frontPos[_dir]; // 지금 내 앞방향
        Vector newDirVector = frontPos[newDir]; // 지금 내 오른쪽

        Vector rightPos = _pos + newDirVector;
        Vector forwardPos = _pos + oldDirVector;
        if (CanGo(rightPos.y, rightPos.x)) // 내 오른쪽이 뚫려있냐
        {
            // 오른쪽으로 회전하고 1칸 움직임
            _dir = static_cast<Dir>(newDir);
            _pos = rightPos;
            _path.push_back(_pos);
        }
        else if (CanGo(forwardPos.y, forwardPos.x)) // 오른쪽이 막혀있으면 가던 방향 그대로 간다.
        {
            // 가던 방향으로 1칸 움직임
            _pos = forwardPos;
            _path.push_back(_pos);
        }
        else // 오른쪽도 막혀있고, 앞도 막혀있다.
        {
            // 왼쪽으로 회전
            int leftDir = (_dir + 1) % DIR_COUNT;
            _dir = static_cast<Dir>(leftDir);
        }
    }

    _pos = _startPos;
}
void MazePlayer::RightHand_stack()
{
    // 우수법으로 갈 수 있는 경로(pos)들을 _path에다가 담아놓을 예정
    _pos = _startPos;
    _path.push_back(_pos);

    Vector frontPos[4] =
    {
        Vector{0, -1}, // UP
        Vector{-1, 0}, // LEFT
        Vector{0,1}, // DOWN
        Vector{1,0} // RIGHT
    };

    while (true)
    {
        // 끝점에 도달했다.
        if (_pos == _endPos)
        {
            _path.push_back(_pos);
            break;
        }

        // 이동
        //            LEFT(1)         4
        int newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT; // 오른쪽 회전 => % 순환 구조를 이용한 설계
        Vector oldDirVector = frontPos[_dir]; // 지금 내 앞방향
        Vector newDirVector = frontPos[newDir]; // 지금 내 오른쪽

        Vector rightPos = _pos + newDirVector;
        Vector forwardPos = _pos + oldDirVector;
        if (CanGo(rightPos.y, rightPos.x)) // 내 오른쪽이 뚫려있냐
        {
            // 오른쪽으로 회전하고 1칸 움직임
            _dir = static_cast<Dir>(newDir);
            _pos = rightPos;
            _path.push_back(_pos);
        }
        else if (CanGo(forwardPos.y, forwardPos.x)) // 오른쪽이 막혀있으면 가던 방향 그대로 간다.
        {
            // 가던 방향으로 1칸 움직임
            _pos = forwardPos;
            _path.push_back(_pos);
        }
        else // 오른쪽도 막혀있고, 앞도 막혀있다.
        {
            // 왼쪽으로 회전
            int leftDir = (_dir + 1) % DIR_COUNT;
            _dir = static_cast<Dir>(leftDir);
        }
    }

    stack<Vector> s;

    for (int i = 0; i < _path.size() - 1; i++)
    {
        if (s.empty() == false && s.top() == _path[i + 1])
            s.pop();
        else
            s.push(_path[i]);
    }


    //사이클(갔다가 돌아오는 길)이였으면 Pop

    _path.clear();
    while (true)
    {
        _path.push_back(s.top());
        s.pop();

        if (s.empty())
            break;
    }
    std::reverse(_path.begin(), _path.end());

    _pos = _startPos;
}
void MazePlayer::FindPath_DFS()
{
    _visited.resize(MAX_Y, vector<bool>(MAX_X, false));
    _pos = _startPos;
    
    _path.push_back(_pos);
    DFS(_startPos.y, _startPos.x);

}
void MazePlayer::DFS(int y, int x)
{

    Vector frontPos[4] =
    {
        Vector{0, -1}, // UP
        Vector{-1, 0}, // LEFT
        Vector{0,1}, // DOWN
        Vector{1,0} // RIGHT
    };
    if (x == _endPos.x && y == _endPos.y) {
        return;
    }
    _visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        Vector next = Vector(x, y) + frontPos[i];
        if (!CanGo(next.y, next.x)) {
            continue;
        }
        if (_visited[next.y][next.x]) {
            continue;
        }
        _path.push_back(next);
        DFS(next.y, next.x);

    }
}

void MazePlayer::FindPath_BFS()
{    
    _visited.resize(MAX_Y, vector<bool>(MAX_X, false));
    _pos = _startPos;
    _path.push_back(_pos);
    q.push(_pos);
    _visited[_startPos.y][_startPos.x] = true;
    BFS();
}

void MazePlayer::BFS()
{
    Vector frontPos[4] =
    {
        Vector{0, -1}, // UP
        Vector{-1, 0}, // LEFT
        Vector{0,1}, // DOWN
        Vector{1,0} // RIGHT
    };
    while (true) {        
        if (q.empty()) {
            break;
        }
        
        Vector temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {      
            Vector next = temp + frontPos[i];
            if (!CanGo(next.y, next.x)) {
                continue;
            }
            if (_visited[next.y][next.x]) {
                continue;
            }
            if (next.x == _endPos.x && next.y == _endPos.y) {
                return;
            }
            _visited[next.y][next.x] = true;
            q.push(next);            
            _path.push_back(next);
        }
    }
}

void MazePlayer::Shortest_FindPath_BFS()
{
    _visited.resize(MAX_Y, vector<bool>(MAX_X, false));
    _parents.resize(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
    _pos = _startPos;
    q.push(_pos);
    _visited[_startPos.y][_startPos.x] = true;
    _parents[_startPos.y][_startPos.x] = _pos;
    Shortest_BFS();
}

void MazePlayer::Shortest_BFS()
{
    Vector frontPos[8] =
    {
        Vector{0,1}, // DOWN
        Vector{1,0}, // RIGHT
        Vector{0, -1}, // UP
        Vector{-1, 0}, // LEFT
        Vector{1,1}, // RIGHTDOWN
        Vector{1,-1}, // RIGHT UP
        Vector{-1, -1}, // LEFT UP
        Vector{-1, 1} // LEFT DOWN
    };
    while (true) {
        if (q.empty()) {
            break;
        }

        Vector temp = q.front();
        q.pop();

        //탐색한 과정을 색으로 구분
        _maze->SetBlockType(temp.y, temp.x, Block::BlockType::FOOT_PRINT);

        for (int i = 0; i < 8; i++) {
            Vector next = temp + frontPos[i];
            if (!CanGo(next.y, next.x)) {
                continue;
            }
            if (_visited[next.y][next.x]) {
                continue;
            }
            if (next.x == _endPos.x && next.y == _endPos.y) {
                _parents[next.y][next.x] = temp;
                Vector curr = _endPos;
                _path.push_back(curr);
                while (true) {                    
                    if (_parents[curr.y][curr.x] == _startPos) {
                        std::reverse(_path.begin(),_path.end());
                        return;
                    }

                    Vector nextPath = _parents[curr.y][curr.x];
                    _path.push_back(nextPath);

                    curr = nextPath;

                }
                
            }
            _visited[next.y][next.x] = true;
            _parents[next.y][next.x] = temp;
            q.push(next);
            
           
        }
    }
}

void MazePlayer::FindPath_Djikstra(const Vector& start)
{
    Vector frontPos[8] =
    {
        Vector{0,1}, // DOWN
        Vector{1,0}, // RIGHT
        Vector{0, -1}, // UP
        Vector{-1, 0}, // LEFT
        Vector{1,1}, // RIGHTDOWN
        Vector{1,-1}, // RIGHT UP
        Vector{-1, -1}, // LEFT UP
        Vector{-1, 1} // LEFT DOWN
    };
    
    priority_queue<Vertex_djikstra, vector<Vertex_djikstra>, greater<Vertex_djikstra>> pq;
    vector<vector<int>> best; //가중치 합 저장
    best.resize(MAX_Y, vector<int>(MAX_X, INT_MAX));
    _parents.resize(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
    Vertex_djikstra startV = Vertex_djikstra(start.y, start.x, 0);
    pq.push(startV);
    _parents[start.y][start.x] = _startPos;

    while (true) {
        if (pq.empty()) {
            break;
        }
        Vertex_djikstra hereV = pq.top();
        Vector here = Vector(hereV.x, hereV.y);
        pq.pop();
        //탐색반경 
        if (hereV.x == _endPos.x && hereV.y == _endPos.y) {
            break;
        }
        //탐색한 과정을 색으로 구분
        _maze->SetBlockType(hereV.y, hereV.x, Block::BlockType::FOOT_PRINT);
        
        if (best[here.y][here.x] < hereV.g) { //전에 발견한 경로가 더 좋을경우
            continue;
        }
        for (int i = 0; i < 8; i++) {
            Vector next = here + frontPos[i];
            if (!CanGo(next.y, next.x)) {
                continue;
            }

            int nowCost;
            if (i < 4) {
                nowCost = best[here.y][here.x] + 10;

            }
            if (i >= 4) {
                nowCost = best[here.y][here.x] + 14;

            }
            if (nowCost >= best[next.y][next.x]) {
                continue;
            }
            _parents[next.y][next.x] = here;
            best[next.y][next.x] = nowCost;
            pq.push(Vertex_djikstra(next.y, next.x, nowCost));
        }
    }
    Vector curr = _endPos;
    _path.push_back(curr);
    while (true) {
        if (_parents[curr.y][curr.x] == _startPos) {
            break;
        }

        Vector nextPath = _parents[curr.y][curr.x];
        _path.push_back(nextPath);

        curr = nextPath;

    }
    std::reverse(_path.begin(), _path.end());


}

void MazePlayer::FindPath_Astar(const Vector& start, const Vector& end)
{
    Vector frontPos[8] =
    {
        Vector{0,1}, // DOWN
        Vector{1,0}, // RIGHT
        Vector{0, -1}, // UP
        Vector{-1, 0}, // LEFT
        Vector{1,1}, // RIGHTDOWN
        Vector{1,-1}, // RIGHT UP
        Vector{-1, -1}, // LEFT UP
        Vector{-1, 1} // LEFT DOWN
    };
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;   
    vector<vector<float>> best;
    _parents.resize(MAX_Y,vector<Vector>(MAX_X,Vector(-1,-1)));
    best.resize(MAX_Y, vector<float>(MAX_X, 50000.0f));
    Vertex startV(start.y,start.x);
    startV.g = 0;
    startV.h = (end - Vector(startV.x,startV.y)).Length() * 10;
    startV.f = startV.g + startV.h;

    pq.push(startV);
    best[startV.y][startV.x] = startV.f;
    _parents[startV.y][startV.x] = Vector(startV.x, startV.y);

    while (true) {
        if (pq.empty()) {
            break;
        }
        Vertex hereV = pq.top();
        pq.pop();
        if (hereV.x == _endPos.x && hereV.y == _endPos.y) {
            break;
        }
        //탐색한 과정을 색으로 구분
        _maze->SetBlockType(hereV.y, hereV.x, Block::BlockType::FOOT_PRINT);
        if (best[hereV.y][hereV.x] < hereV.f) {
            continue;
        }
        for (int i = 0; i < 8; i++) {

            Vector next = Vector(hereV.x,hereV.y) + frontPos[i];
            if (!CanGo(next.y, next.x)) {
                continue;
            }
            float cost_g;   
            float cost_h;
            float cost_f;
            cost_h = (end - next).Length() * 10;
            if (i < 4) {
                cost_g = hereV.g + 10.0f;
            }
            if (i >= 4) {
                cost_g = hereV.g + 14.4f;
            }
            cost_f = cost_g + cost_h;

            if (best[next.y][next.x] < cost_f) {
                continue;
            }

            Vertex nextV = Vertex(next.y, next.x);
            nextV.g = cost_g;
            nextV.h = cost_h;
            nextV.f = cost_f;

            pq.push(nextV);
            _parents[next.y][next.x] = Vector(hereV.x, hereV.y);

        }
    }
    Vector curr = _endPos;
    _path.push_back(curr);
    while (true) {
        if (_parents[curr.y][curr.x] == _startPos) {
            break;
        }

        Vector nextPath = _parents[curr.y][curr.x];
        _path.push_back(nextPath);

        curr = nextPath;

    }
    std::reverse(_path.begin(), _path.end());

}

bool MazePlayer::CanGo(int y, int x)
{

    if(y >= MAX_Y || x >= MAX_X) return false;
    if(y < 0 || x < 0) return false;

    Block::BlockType type = _maze->GetBlockType(y,x);

    switch (type)
    {
    case Block::NONE:
        return false;
    case Block::ABLE:
        return true;
    case Block::DISABLE:
        return false;
    default:
        break;
    }

    return false;
}
