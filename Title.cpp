#include "Title.h"

int Title::Update()
{
	std::cout << "Input SPACE to start.\n";
	std::cout << "\n";

 	const int key = ReadValidKey(" ");

	// Space キーならゲームシーンへ進む合図として 1 を返す。
	return key == ' ' ? 1 : 0;
}
