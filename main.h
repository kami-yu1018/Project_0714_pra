#pragma once

#include"Data.h"
#include <iostream>
#include <conio.h>

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
	int scene = Scene_Title;
public:
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static Game& Instance()
	{
		static Game instance;
		return instance;
	}

	void GameLoop();
};