#include "BoardController.h"


MemoryGame::BoardController::BoardController()
{

}

MemoryGame::BoardController::~BoardController()
{

}

void MemoryGame::BoardController::InitBoard(int numberOfPlayers, int numberOfCardPairs)
{
	this->_leaderboardView.Init(numberOfPlayers);
	this->_boardView.Init(numberOfCardPairs);
}

void MemoryGame::BoardController::Render(sf::RenderWindow* window)
{
	this->_boardView.Render(window);
	this->_leaderboardView.Render(window);
}

void MemoryGame::BoardController::Update()
{

}