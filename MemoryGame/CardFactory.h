#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <vector>

#include "Card.h"


namespace MemoryGame
{
	class CardFactory
	{
	public:
		CardFactory();
		~CardFactory();

		std::vector<MemoryGame::Card> GetCards(int numberOfCards);

	};
}

#endif // CARDFACTORY_H