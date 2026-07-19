#pragma once

#include"Data.h"
#include <iostream>

enum
{
	Scene_Title,
	Scene_Play,
	Scene_End,
};

class Game
{
private:
	Game() {};
public:
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static Game& Instance()
	{
		static Game instance;
		return instance;
	}

	void GameLoop()
	{

	}
};