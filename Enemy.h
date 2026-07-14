#pragma once
#include"Data.h"

class Enemy
{
public:
	EnemyData Data;
	Enemy(const EnemyData& data)
		:Data(data)
	{
	}
};