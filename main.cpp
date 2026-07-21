#include"main.h"

void Game::GameLoop()
{
	switch (scene)
	{
	case Scene_Title:
		if (title.Update() == 1)
		{
			scene = Scene_Play;
		}
		break;
	case Scene_Play:
		if(init==0)
		{
			game.Init();
			init++;
		}
		game.Update();
		break;
	case Scene_End:
		break;
	}
}

int main()
{

	while (1)
	{
		Game::Instance().GameLoop();
	}
}