#pragma once
#include"Data.h"

class Player
{
public:
	PlayerData Data;
	Player(const PlayerData& data)
		:Data(data)
	{

	}
};
