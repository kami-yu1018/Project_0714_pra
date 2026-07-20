#pragma once

#include "Factory.h"
#include "Player.h"
#include "Enemy.h"

class Scene_Game
{
	Enemy* enemy[3];
	Player* player[4];


public:
	Game() {};
	~Game()
	{
		delete enemy;
		delete player;
	};

	void Init();
	void Update();
	void Exit();
};