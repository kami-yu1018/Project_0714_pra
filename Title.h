#pragma once
#include <iostream>
#include <conio.h>
#include "Key.h"

class Title
{
public:
	Title()
	{
		std::cout << "Input SPACE to start.\n";
	}
	int Update();
};
