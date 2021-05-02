#include "Card.h"


MemoryGame::Card::Card(CardType cardType)
{
	this->_cardType = cardType;
}

MemoryGame::Card::~Card()
{

}

MemoryGame::CardType MemoryGame::Card::GetCardType()
{
	return this->_cardType;
}