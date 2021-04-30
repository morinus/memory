#include <iostream>

#include "Game.h"


int main()
{
	MemoryGame::Game game;

	while (game.GetWindowIsOpen())
	{
		game.PoolEvents();

		game.Render();
	}

	return 0;
}