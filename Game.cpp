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

	std::cout << "\n";
}

void Scene_Game::Update()
{
	//	味方のコマンド
	for (int i = 0; i < 4; ++i)
	{

		std::cout << player[i]->Data.name << "はどうする？\n";
		std::cout << "１：攻撃　２：防御　３：スキル\n";
		const int command = _getch();
		if (command == '1')
		{
			std::cout << "ターゲットを選択してください" << std::endl;
			std::cout << "１：" << enemy[0]->Data.name <<
				"　２：" << enemy[1]->Data.name <<
				"　３：" << enemy[2]->Data.name << std::endl;
			const int target = _getch();
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
			DamageResult result = CalculateDamage(
				player[i]->Data.ATK,
				player[i]->Data.CriticalRate,
				enemy[tag]->Data.DEF);

			enemy[tag]->Data.HP -= result.damage;
			
			std::cout << player[i]->Data.name << "の攻撃！\n";
			if (result.isCritical)
			{
				std::cout << "クリティカルヒット！\n";
			}
			std::cout << enemy[tag]->Data.name << "に" << result.damage << "ダメージ！\n";
			std::cout << "\n";
		}
		else if (command == '2')
		{
			player[i]->Data.DEF *= 1.5;

			std::cout << player[i]->Data.DEF << "は防御態勢を取った！\n";
			std::cout << "\n";
		}
		else if (command == '3')
		{
			switch (i)
			{
			case 0:

			{
				std::cout << player[i]->Data.name << "の必殺斬！\n";
				for (int i = 0; i < 3; ++i)
				{
					DamageResult result = CalculateDamage(
						player[i]->Data.ATK,
						player[i]->Data.CriticalRate,
						enemy[i]->Data.DEF);

					enemy[i]->Data.HP -= result.damage;
					if (result.isCritical)
					{
						std::cout << "クリティカルヒット！\n";
					}
					std::cout << enemy[i]->Data.name << "に" << result.damage << "ダメージ！\n";
				}
				std::cout << "\n";
				break;
			}

			case 1:

			{
				std::cout << "ターゲットを選択してください" << std::endl;
				std::cout << "１：" << enemy[0]->Data.name <<
					"　２：" << enemy[1]->Data.name <<
					"　３：" << enemy[2]->Data.name << std::endl;
				const int target_2 = _getch();
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

			case 2:
			{
				std::cout << "ターゲットを選択してください" << std::endl;
				std::cout << "１：" << player[0]->Data.name <<
					"　２：" << player[1]->Data.name <<
					"　３：" << player[2]->Data.name <<
					"　４：" << player[3]->Data.name << std::endl;
				const int target_3 = _getch();
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
			case 3:
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
	}
}