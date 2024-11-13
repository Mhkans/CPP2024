#pragma once

//미리컴파일된 헤더 pch : pre compiled header
/*
1.framework.h / framework.cpp 만들기 
2.framework.cpp 속성 미리컴파일된 헤더 -> framework.h 만들기
3.프로젝트 속성 미리컴파일된 헤더 -> framework.h 사용
framework.h의 경로 알려주기
프로젝트속성 - vc++디렉토리 -> 포함 디렉토리 -> $(ProjectDir) ... 현재 프로젝트의 경로
*/

#include <string>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
#include <memory>
using namespace std;

#include "Objects/Creature.h"
#include "Objects/Player.h"
#include "Objects/Monster.h"
#include "Objects/Knight.h"
#include "Objects/Goblin.h"
#include "Objects/Archer.h"
#include "Objects/Mage.h"
#include "Objects/Boss.h"

#include"World.h" //다 포함할수있는건 맨 아래로
#include"BossWorld.h"
#include"SoundManager.h"

