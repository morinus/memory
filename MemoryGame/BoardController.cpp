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

	this->_leaderboardView.Init(numberOfPlayers);
}

void MemoryGame::BoardController::Render(sf::RenderWindow* window)
{
	this->_boardView.Render(window);
	this->_leaderboardView.Render(window);
}