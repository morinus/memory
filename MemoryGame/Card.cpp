#include "Card.h"


MemoryGame::Card::Card(CardType cardType)
{
	this->_cardType = cardType;
	this->_isFaceDown = true;
}

MemoryGame::Card::~Card()
{

}

MemoryGame::CardType MemoryGame::Card::GetCardType()
{
	return this->_cardType;
}

bool MemoryGame::Card::IsFaceDown()
{
	return this->_isFaceDown;
}