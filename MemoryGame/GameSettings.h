#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

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
	};
}

#endif // GAMESETTINGS_H