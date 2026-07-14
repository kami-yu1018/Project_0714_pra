#pragma once
#include "Data.h"

class Enemy;

class EnemyFactory
{
	static const EnemyData EnemyTable[];
	static const int EnemyTableSize;
public:
	static Enemy* CreateEnemy(int ID);
};

class Player;
class PlayerFactory
{
	static const PlayerData PlayerTable[];
	static const int PlayerTableSize;
public:
	static Player* CreatePlayer(int ID);
};