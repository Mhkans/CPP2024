#pragma once
class World
{
public:

	World()
	{
		Init();
	}
	~World();
	
	void Init();

	void Update();
	bool End();


	

private:
	bool CheckCreatureArr(Creature* arr[], int size);

	Creature* _player;
	Creature* _monsters[10];
};

