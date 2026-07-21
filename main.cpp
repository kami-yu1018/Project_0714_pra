#include"main.h"

void Game::GameLoop()
{
	switch (scene)
	{
	case Scene_Title:
		if (title.Update() == 1)
		{
			scene = Scene_Play;
			init = 1;
		}
		break;
	case Scene_Play:
		if(init==0)
		{
			game.Init();
			init++;
		}
		game.Update();
		if (game.Exit() > 0)
		{
			scene = Scene_End;
			game_endhing = game.Exit();
		}
		break;
	case Scene_End:
		if (game_endhing == 1)
		{
			std::cout << "You Win!\n";
			std::cout << "Push Space to title.\n";
			std::cout << "\n";
		}
		else
		{
			std::cout << "You Lose...\n";
			std::cout << "Push Space to title.\n";
			std::cout << "\n";
		}
		const int key = _getch();
		if (key == ' ')
		{
			scene = Scene_Title;
		}

		break;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	while (1)
	{
		Game::Instance().GameLoop();
	}
}