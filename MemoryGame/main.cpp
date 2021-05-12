#include "Game.h"


int main()
{
	MemoryGame::Game game;

	while (game.GetWindow()->isOpen())
	{
		game.Update();
	}

	return 0;
}