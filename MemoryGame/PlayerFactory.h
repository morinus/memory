#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <vector>

#include "Player.h"


namespace MemoryGame
{
	class PlayerFactory
	{
	public:
		PlayerFactory();
		~PlayerFactory();

		std::vector<Player> CreatePlayers(int numberOfPlayers);
	};
}

#endif // PLAYERFACTORY_H