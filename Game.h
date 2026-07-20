#pragma once

#include "Factory.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

class Scene_Game
{
	Enemy* enemy[3] = {};
	Player* player[4] = {};


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
	void Exit();
};
