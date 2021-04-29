#include <iostream>

#include "Game.h"


int main()
{
	Game game;

	while (game.GetWindowIsOpen())
	{
		game.PoolEvents();

		game.Render();
	}

	return 0;
}