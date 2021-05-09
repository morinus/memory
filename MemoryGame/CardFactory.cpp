#include <stdlib.h>

#include "CardFactory.h"

class Card;

constexpr int NUMBER_OF_CARD_TYPES = 4;


MemoryGame::CardFactory::CardFactory()
{

}

MemoryGame::CardFactory::~CardFactory()
{

}

std::vector<MemoryGame::Card> GetCards(int numberOfCards)
{
	std::vector<MemoryGame::Card> cards;

	for (int i = 0; i < numberOfCards; i += 2)
	{
		int rand = std::rand() % NUMBER_OF_CARD_TYPES + 1;

		MemoryGame::Card card = MemoryGame::Card(MemoryGame::CardType(rand));

		cards.push_back(card);
		cards.push_back(card);
	}

	return cards;
}