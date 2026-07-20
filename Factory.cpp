#include "Factory.h"

#include "Enemy.h"

const EnemyData EnemyFactory::EnemyTable[] =
{
	{ "スライム" , 1, 10,  5, 2, 1, 10,  5,  0.01, Element::None},
	{ "ゴブリン", 2, 20, 10, 5, 2, 20, 10,  0.03, Element::Earth},
	{ "オーク"   , 3, 30, 15, 8, 3, 30, 15,  0.05, Element::Fire},
};

const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

Enemy* EnemyFactory::CreateEnemy(int ID)
{
	for (int i = 0; i < EnemyTableSize; ++i)
	{
		if (EnemyTable[i].ID == ID)
		{
			return new Enemy(EnemyTable[i]);
		}
	}

	return nullptr;
}

#include "Player.h"

const PlayerData PlayerFactory::PlayerTable[] = {
	{"剣士", 1, 28,12,8,3,0.03,Element::None},
	{"魔導士", 2 ,18, 16,3,2,0.03,Element::None},
	{"賢者",3,24,11,6,2,0.01,Element::Light},
	{"盗賊",4,22,10,5,5,Element::Wind}
};

const int PlayerFactory::PlayerTableSize = sizeof(PlayerTable) / sizeof(PlayerData);

Player* PlayerFactory::CreatePlayer(int ID)
{
	for (int i = 0; i < PlayerTableSize; ++i)
	{

		if(PlayerTable[i].ID==ID)
		{
			return new Player(PlayerTable[i]);
		}
	}
	return nullptr;
}