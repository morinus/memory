#include "PlayScene.h"

// Game Setup
constexpr int NUMBER_OF_PLAYERS = 5;
constexpr int NUMBER_OF_CARDS = 24;


MemoryGame::PlayScene::PlayScene()
{

}

MemoryGame::PlayScene::~PlayScene()
{

}

void MemoryGame::PlayScene::Init(std::shared_ptr<GameSettings> gameSettings)
{
	this->_boardController.InitBoard(NUMBER_OF_PLAYERS, NUMBER_OF_CARDS);
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
