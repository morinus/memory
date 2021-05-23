#include "Game.h"
#include "PlayScene.h"


MemoryGame::PlayScene::PlayScene()
{

}

MemoryGame::PlayScene::~PlayScene()
{

}

void MemoryGame::PlayScene::Init(std::shared_ptr<GameSettings> gameSettings, std::function<void(GameState)> changeGameStateDelegate)
{
	this->_boardController.InitBoard(gameSettings->NumberOfPlayers, gameSettings->NumberOfCards);
}

void MemoryGame::PlayScene::Update(float elapsedTime)
{
	this->_boardController.Update(elapsedTime);
}

void MemoryGame::PlayScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
	this->_boardController.Render(window);
}

void MemoryGame::PlayScene::ProcessMouseClick(sf::Vector2f mousePosition)
{
	this->_boardController.ProcessMouseClick(mousePosition);
}
