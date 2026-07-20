#include "Title.h"

int Title::Update()
{
	const int key = _getch();

	// Space キーならゲームシーンへ進む合図として 1 を返す。
	return key == ' ' ? 1 : 0;
}
