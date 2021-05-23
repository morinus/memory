#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

namespace MemoryGame
{
	class GameSettings
	{
	public:
		GameSettings(int numberOfPlayers, int numberOfCards);
		~GameSettings();

		int NumberOfPlayers;
		int NumberOfCards;
	};
}

#endif // GAMESETTINGS_H