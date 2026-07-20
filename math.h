#pragma once
#include <algorithm>		//	std::max用
#include <random>

struct DamageResult
{
	int damate;			//	与えたダメージの値
	bool isCritical;	//	クリティカルが出たかどうか
};

inline DamageResult CalculateDamage(int a_ATK, float a_criticakRate, int t_DEF)
{
	//	攻撃する側の攻撃力とターゲットの防御力からダメージを計算
	//	最低でも１ダメージは入るようにする
	const int normalDamage = std::max(1, a_ATK - t_DEF);

	static std::random_device seed;		//	乱数シードの作成
	static std::mt19937 engine(seed());	//	連続した乱数の生成
	static std::uniform_real_distribution<float> random(0.0f, 1.0f);	//	偏りのない乱数を作るための設定

	const bool isCritical = random(engine) < a_criticakRate;	//	乱数をもう一つ作り、その値がクリティカルレートよりも小さければクリティカル成功
	const float criticalMultiplier = 1.5f;		//	クリティカル時のダメージ倍率

	//	三項演算子
	//	条件 ? 条件がtrueの場合 : 条件がfalseの場合
	const int damage = isCritical
		? static_cast<int>(normalDamage * criticalMultiplier) : normalDamage;
	
	return { damage,isCritical };


}