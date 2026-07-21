//	ここにゲーム本編の処理を実装する
//	今回はスライム、ゴブリン、オークを１体ずつ呼び出す

#include "Game.h"

// ---------------------------------------------------------
//	初期化処理
// ---------------------------------------------------------
void Scene_Game::Init()
{
	Reset();

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

	std::cout << "\n";
}

void Scene_Game::Update()
{
	//	味方のコマンド
	for (int i = 0; i < 4; ++i)
	{
		//	生きていたら処理
		if(p_alive[i]==1)
		{
			std::cout << player[i]->Data.name << "はどうする？\n";
			std::cout << "１：攻撃　２：防御　３：スキル\n";
			const int command = ReadValidKey("123");
			//	通常攻撃
			if (command == '1')
			{
				//	テキスト
				std::cout << "ターゲットを選択してください" << std::endl;
				std::cout << "１：" << enemy[0]->Data.name <<
					"　２：" << enemy[1]->Data.name <<
					"　３：" << enemy[2]->Data.name << std::endl;

				//	ターゲット選択
				const int target = ReadValidKey("123");
				int tag;
				if (target == '1')
				{
					tag = 0;
				}
				else if (target == '2')
				{
					tag = 1;
				}
				else if (target == '3')
				{
					tag = 2;
				}

				//	ダメージ計算＆クリティカル率計算
				DamageResult result = CalculateDamage(
					player[i]->Data.ATK,
					player[i]->Data.CriticalRate,
					enemy[tag]->Data.DEF);

				enemy[tag]->Data.HP -= result.damage;

				//	テキスト
				std::cout << player[i]->Data.name << "の攻撃！\n";
				if (result.isCritical)
				{
					std::cout << "クリティカルヒット！\n";
				}
				std::cout << enemy[tag]->Data.name << "に" << result.damage << "ダメージ！\n";
				std::cout << "\n";
			}
			//	防御
			else if (command == '2')
			{
				//	防禦態勢でそのターンの防御力を1.5倍に
				player[i]->Data.DEF *= 1.5;

				//	テキスト
				std::cout << player[i]->Data.name << "は防御態勢を取った！\n";
				std::cout << "\n";
			}
			//	スキル
			else if (command == '3')
			{
				switch (i)
				{
				case 0:		//	剣士
				{
					//	全体攻撃
					std::cout << player[i]->Data.name << "の必殺斬！\n";
					for (int ene = 0; ene < 3; ++ene)
					{
						DamageResult result = CalculateDamage(
							player[i]->Data.ATK,
							player[i]->Data.CriticalRate,
							enemy[ene]->Data.DEF);

						enemy[ene]->Data.HP -= result.damage;
						if (result.isCritical)
						{
							std::cout << "クリティカルヒット！\n";
						}
						std::cout << enemy[ene]->Data.name << "に" << result.damage << "ダメージ！\n";
					}
					std::cout << "\n";
					break;
				}

				case 1:		//	魔法使い
				{
					//	火力の高い単体攻撃

					std::cout << "ターゲットを選択してください" << std::endl;
					std::cout << "１：" << enemy[0]->Data.name <<
						"　２：" << enemy[1]->Data.name <<
						"　３：" << enemy[2]->Data.name << std::endl;
					const int target_2 = ReadValidKey("123");
					int tag;
					if (target_2 == '1')
					{
						tag = 0;
					}
					else if (target_2 == '2')
					{
						tag = 1;
					}
					else if (target_2 == '3')
					{
						tag = 2;
					}

					std::cout << player[i]->Data.name << "のファイアボール！\n";
					player[i]->Data.ATK *= 1.5;

					DamageResult result = CalculateDamage(
						player[i]->Data.ATK,
						player[i]->Data.CriticalRate,
						enemy[tag]->Data.DEF);

					enemy[tag]->Data.HP -= result.damage;

					std::cout << enemy[tag]->Data.name << "に" << result.damage << "ダメージ！\n";
					std::cout << "\n";

					break;
				}

				case 2:		//	賢者
				{
					//	選択した味方の体力を回復

					std::cout << "ターゲットを選択してください" << std::endl;
					std::cout << "１：" << player[0]->Data.name <<
						"　２：" << player[1]->Data.name <<
						"　３：" << player[2]->Data.name <<
						"　４：" << player[3]->Data.name << std::endl;
					const int target_3 = ReadValidKey("1234");
					int tag;
					if (target_3 == '1')
					{
						tag = 0;
					}
					else if (target_3 == '2')
					{
						tag = 1;
					}
					else if (target_3 == '3')
					{
						tag = 2;
					}
					else if (target_3 == '4')
					{
						tag = 3;
					}
					else
					{

					}

					player[tag]->Data.HP += player[i]->Data.DEF * 2;
					std::cout << player[i]->Data.name << "のヒール！\n";
					std::cout << player[tag]->Data.name << "のＨＰが" << player[i]->Data.DEF * 2 << "回復！\n";
					std::cout << "\n";

					break;
				}

				case 3:		//	盗賊
				{
					std::cout << player[i]->Data.name << "の盗賊乱舞！\n";

					//	ランダムに4回攻撃
					for (int atk = 0; atk < 4; ++atk)
					{
						const int tag = rand() % 3;
						DamageResult result = CalculateDamage(
							player[i]->Data.ATK,
							player[i]->Data.CriticalRate,
							enemy[tag]->Data.DEF);

						enemy[tag]->Data.HP -= result.damage;

						std::cout << enemy[tag]->Data.name << "に" << result.damage << "ダメージ！\n";
					}
					std::cout << "\n";

					break;
				}

				}
			}

			for (int ene= 0; ene < 3; ++ene)
			{
				if (enemy[ene]->Data.HP <= 0 && e_alive[ene] == 1)
				{
					e_alive[ene] = 0;
					std::cout << enemy[ene]->Data.name << "は倒れた！\n";
					std::cout << "\n";
				}
			}

			if (e_alive[0] == 0 && e_alive[1] == 0 && e_alive[2] == 0)
			{
				break;
			}
		}
		else
		{
			continue;
		}
	}

	//	敵の攻撃
	for (int i = 0; i < 3; ++i)
	{
		if(e_alive[i]==1)
		{
			std::cout << enemy[i]->Data.name << "の攻撃！\n";
			const int tag = rand() % 4;
			DamageResult result = CalculateDamage(
				enemy[i]->Data.ATK,
				enemy[i]->Data.CriticalRate,
				player[tag]->Data.DEF);

			player[tag]->Data.HP -= result.damage;

			std::cout << player[tag]->Data.name << "に" << result.damage << "ダメージ！\n";
			std::cout << "\n";

			if (player[tag]->Data.HP <= 0)
			{
				p_alive[tag] = false;
				std::cout << player[tag]->Data.name << "は倒れた！";
			}
		}
		else
		{
			continue;
		}
	}
}

int Scene_Game::Exit()
{
	if (e_alive[0] == 0 && e_alive[1] == 0 && e_alive[2] == 0)
	{
		return 1;
	}
	else if (p_alive[0] == 0 && p_alive[1] == 0 && p_alive[2] == 0 && p_alive[3] == 0)
	{
		return 2;
	}

	return 0;
}

//	前回の処理をリセット
void Scene_Game::Reset()
{
	for (int i = 0; i < 3; ++i)
	{
		delete enemy[i];
		enemy[i] = nullptr;
		e_alive[i] = true;
	}
	for (int i = 0; i < 4; ++i)
	{
		delete player[i];
		player[i] = nullptr;
		p_alive[i] = true;
	}
}