#include "framework.h"

int main()
{
	
	//World* world = new World();
	SoundManager::CreateInstance();
	BossWorld* bossWorld = new BossWorld();


	while (true) {
		/*
		world->Update();
		if (world->End()) {
			
			break;
		}
		*/
		bossWorld->Update();		
		if (bossWorld->End()) {

			break;
		}
		
	}
	//delete world;
	delete bossWorld;
	SoundManager::DeleteInstance();
	return 0;
}

