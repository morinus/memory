#include "BoardController.h"


MemoryGame::BoardController::BoardController()
{

}

MemoryGame::BoardController::~BoardController()
{

}

void MemoryGame::BoardController::InitBoard(int numberOfPlayers, int numberOfCardPairs)
{
	this->InitPlayers(numberOfPlayers);
	this->InitCards(numberOfCardPairs);

	this->_leaderboardView.Init(this->_players);
	this->_boardView.Init(this->_cards);
}

void MemoryGame::BoardController::InitPlayers(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; ++i)
	{
		std::string playerName = "Player" + std::to_string(i);
		Player player(playerName);

		this->_players.push_back(player);
	}
}

void MemoryGame::BoardController::InitCards(int numberOfCardPairs)
{

}

void MemoryGame::BoardController::Render(sf::RenderWindow* window)
{
	this->_boardView.Render(window);
	this->_leaderboardView.Render(window);
}

void MemoryGame::BoardController::Update()
{

}