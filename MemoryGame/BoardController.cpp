#include "BoardController.h"


MemoryGame::BoardController::BoardController()
{

}

MemoryGame::BoardController::~BoardController()
{

}

void MemoryGame::BoardController::Init(sf::RenderWindow* window)
{
	this->_boardView.Init(window);
}

void MemoryGame::BoardController::InitBoard(int numberOfPlayers, int numberOfCardPairs)
{
	this->numberOfPlayers = numberOfPlayers;
	this->numberOfCardPairs = numberOfCardPairs;
}

void MemoryGame::BoardController::Render()
{
	this->_boardView.Render();
}