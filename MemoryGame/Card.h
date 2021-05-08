#ifndef CARD_H
#define CARD_H

#include "Button.h"

namespace MemoryGame
{
	enum CardType
	{
		A = 1,
		B = 2,
		C = 3,
		D = 4
	};

	class Card : public Button
	{
	public:
		Card(CardType cardType);
		~Card();

		CardType GetCardType();

	private:
		CardType _cardType;

	};
}

#endif // CARD_H