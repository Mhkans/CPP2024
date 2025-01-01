// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN  // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <memory.h>
#include<memory>
#include <tchar.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<functional>
#include<stack>
#include<queue>

using namespace std;

#include"Types.h"
//math 
#include<math/Vector.h>

//contents
#include "Contents/Objects/Collider.h"
#include "Contents/Objects/CircleCollider.h"
#include "Contents/Objects/RectangleCollider.h"
#include "Contents/Objects/Liner.h"

//GameObject
#include "Contents/GameObject/Ball.h"
#include "Contents/GameObject/Barrel.h"
#include "Contents/GameObject/Cannon.h"
#include "Contents/GameObject/Maze/Block.h"
//scene
#include"Scenes/Scene.h"
#include"Scenes/PaintScene.h"
#include"Scenes/CollisionScene.h"
#include"Scenes/CannonScene.h"
#include"Scenes/LineScene.h"
#include"Scenes/FortressScene.h"
#include"Scenes/MazeScene.h"

//program
#include"Program/Program.h"


extern Vector mousePos;
extern HWND hWnd;