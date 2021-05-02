#include "BoardController.h"


MemoryGame::BoardController::BoardController()
{

}

MemoryGame::BoardController::~BoardController()
{

}

void MemoryGame::BoardController::InitBoard(int numberOfPlayers, int numberOfCardPairs)
{
	this->numberOfPlayers = numberOfPlayers;
	this->numberOfCardPairs = numberOfCardPairs;
}