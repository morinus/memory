#include <iostream>

#include "GameController.h"


int main()
{
	MemoryGame::GameController gameController;

	while (gameController.GetWindowIsOpen())
	{
		gameController.PoolEvents();

		gameController.Render();
	}

	return 0;
}