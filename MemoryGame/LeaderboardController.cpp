#include "LeaderboardController.h"


MemoryGame::LeaderboardController::LeaderboardController()
{

}

MemoryGame::LeaderboardController::~LeaderboardController()
{

}

void MemoryGame::LeaderboardController::Init(std::vector<Player> players, std::function<void(GameState)> changeGameStateDelegate)
{
	this->_leaderboardView.Init(players, changeGameStateDelegate);
}

void MemoryGame::LeaderboardController::Render(std::shared_ptr<sf::RenderWindow> window)
{
	this->_leaderboardView.Render(window);
}

void MemoryGame::LeaderboardController::ProcessMouseClick(sf::Vector2f mousePosition)
{
	this->_leaderboardView.ProcessMouseClick(mousePosition);
}
