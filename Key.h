#pragma once
#include <iostream>
#include <conio.h>


namespace
{
	//	許可したキーが押されるまで待つ関数
	int ReadValidKey(const char* validKeys)
	{
		while (true)
		{
			const int key = _getch();

			//	取得したキーが許可したキーと同じであるとき
			for (int i = 0; validKeys[i] != '\0'; ++i)
			{
				if (key == validKeys[i])
				{
					//	値を返す
					return key;
				}
			}

		}
	}
}