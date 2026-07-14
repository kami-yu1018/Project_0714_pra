#pragma once

enum Element
{
	None,
	Fire,
	Water,
	Earth,
	Wind,
	Light,
	Dark
};


struct EnemyData
{
	const char name[256];
	int ID;
	int HP;
	int ATK;
	int DEF;
	int SPD;
	int GOLD;
	int EXP;
	float CriticalRate;
	Element element;
	
};