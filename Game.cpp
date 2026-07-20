//	ここにゲーム本編の処理を実装する
//	今回はスライム、ゴブリン、オークを１体ずつ呼び出す

#include "Game.h"

// ---------------------------------------------------------
//	初期化処理
// ---------------------------------------------------------
void Scene_Game::Init()
{
	//	敵の生成
	for (int i = 0; i < 3; ++i)
	{
		enemy[i] = EnemyFactory::CreateEnemy(i + 1);
		std::cout << enemy[i]->Data.name << "が表れた！\n";
	}
	std::cout << std::endl;
	//	プレイヤーの生成
	for (int i = 0; i < 4; ++i)
	{
		player[i] = PlayerFactory::CreatePlayer(i + 1);
		std::cout << player[i]->Data.name << "の登場！\n";
	}

}

void Scene_Game::Update()
{
	//	味方のコマンド

}