#include"main.h"

void Game::GameLoop()
{
	switch (scene)
	{
	case Scene_Title:
		break;
	case Scene_Play:
		break;
	case Scene_End:
		break;
	}
}

int main()
{
	EnemyData slime = { "slime",1,50,50,20,10,10,10,3,None };

	std::cout << sizeof(slime) << std::endl;
}