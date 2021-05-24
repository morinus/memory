#include "LeaderboardScene.h"


MemoryGame::LeaderboardScene::LeaderboardScene()
{

}

MemoryGame::LeaderboardScene::~LeaderboardScene()
{

}

void MemoryGame::LeaderboardScene::Init(std::shared_ptr<GameSettings> gameSettings, std::function<void(GameState)> changeGameStateDelegate)
{
	this->_leaderboardController.Init(gameSettings->Players, changeGameStateDelegate);
}

void MemoryGame::LeaderboardScene::Update(float elapsedTime)
{

}

void MemoryGame::LeaderboardScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
	this->_leaderboardController.Render(window);
}

void MemoryGame::LeaderboardScene::ProcessMouseClick(sf::Vector2f mousePosition)
{
	this->_leaderboardController.ProcessMouseClick(mousePosition);
}
