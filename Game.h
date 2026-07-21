#pragma once

#include "Factory.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <conio.h>
#include "math.h"

class Scene_Game
{
	Enemy* enemy[3] = {};
	bool e_alive[3] = { 1,1,1 };
	Player* player[4] = {};
	bool p_alive[4] = { 1,1,1,1 };


public:
	Scene_Game() {};
	~Scene_Game()
	{
		for (Enemy*& value : enemy)
		{
			delete value;
		}
		for (Player*& value : player)
		{
			delete value;
		}
	};

	void Init();
	void Update();
	int Exit();
};
