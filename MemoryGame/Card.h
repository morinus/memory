#ifndef CARD_H
#define CARD_H

#include "Button.h"


namespace MemoryGame
{
	enum CardType
	{
		MONSTER_A = 1,
		MONSTER_B = 2,
		MONSTER_C = 3,
		MONSTER_D = 4
	};

	class Card
	{
	public:
		Card(CardType cardType);
		~Card();

		CardType GetCardType();
		bool IsFaceDown();

	private:
		CardType _cardType;
		bool _isFaceDown;

	};
}

#endif // CARD_H