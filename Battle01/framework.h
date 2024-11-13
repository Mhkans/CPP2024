#pragma once

//�̸������ϵ� ��� pch : pre compiled header
/*
1.framework.h / framework.cpp ����� 
2.framework.cpp �Ӽ� �̸������ϵ� ��� -> framework.h �����
3.������Ʈ �Ӽ� �̸������ϵ� ��� -> framework.h ���
framework.h�� ��� �˷��ֱ�
������Ʈ�Ӽ� - vc++���丮 -> ���� ���丮 -> $(ProjectDir) ... ���� ������Ʈ�� ���
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

#include"World.h" //�� �����Ҽ��ִ°� �� �Ʒ���
#include"BossWorld.h"
#include"SoundManager.h"

