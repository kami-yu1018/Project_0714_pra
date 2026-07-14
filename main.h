#pragma once

#include<iostream>
#include"Data.h"

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