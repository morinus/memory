#include "CardType.h"


namespace MemoryGame
{
	class Card
	{
	public:
		Card(CardType cardType);
		~Card();

		CardType GetCardType();

	private:
		CardType _cardType;

	};
}