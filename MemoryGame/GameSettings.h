#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "Player.h"
#include <vector>


namespace MemoryGame
{
	class GameSettings
	{
	public:
		GameSettings(int numberOfPlayers, int width, int height);
		~GameSettings();

		int NumberOfPlayers;
		int Width;
		int Height;

		std::vector<Player> Players;
	};
}

#endif // GAMESETTINGS_H