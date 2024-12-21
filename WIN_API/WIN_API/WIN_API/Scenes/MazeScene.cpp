#include "framework.h"
#include "MazeScene.h"
#include"Contents/GameObject/Maze/Block.h"
#include"Contents/GameObject/Maze/Maze.h"
#include "Contents/GameObject/Maze/MazePlayer.h"
MazeScene::MazeScene()
{
	_maze = make_shared<Maze>();
	_player = make_shared<MazePlayer>();
}

MazeScene::~MazeScene()
{
}

void MazeScene::PostInitialize()
{
	_player->SetMaze(_maze);
	_player->Init();
	//_player->RightHand();
	_player->RightHand_stack();
}

void MazeScene::Update()
{
	_maze->Update();
	_player->Update();
	_maze->SetBlockType(_player->GetStartPos().y, _player->GetStartPos().x, Block::BlockType::NONE);
	_maze->SetBlockType(_player->GetEndPos().y, _player->GetEndPos().x, Block::BlockType::NONE);
}

void MazeScene::Render(HDC hdc)
{
	_maze->Render(hdc);
}
