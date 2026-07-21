#pragma once

#include"Data.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include "Title.h"
#include "Game.h"

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

	Title title;
	Scene_Game game;

	int init = 0;
	int game_endhing = 0;

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