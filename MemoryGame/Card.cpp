#include "Card.h"


MemoryGame::Card::Card(CardType cardType)
{
	this->_cardType = cardType;
	this->_isSolved = false;
}

MemoryGame::Card::~Card()
{

}