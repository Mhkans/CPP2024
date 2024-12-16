#pragma once
class Block;
class Maze;
class MazePlayer;

class MazeScene : public Scene
{
public:
	MazeScene();
	~MazeScene();

	void PostInitialize() override;
	void Update() override;
	void Render(HDC hdc) override;

private:
	// 25 x 25
	shared_ptr<Maze> _maze;
	shared_ptr<MazePlayer> _player;
};


