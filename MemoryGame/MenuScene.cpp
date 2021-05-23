#include "MenuScene.h"


MemoryGame::MenuScene::MenuScene()
{

}

MemoryGame::MenuScene::~MenuScene()
{

}

void MemoryGame::MenuScene::Init(std::shared_ptr<GameSettings> gameSettings)
{
	this->_menuController.InitMenu(gameSettings);
}

void MemoryGame::MenuScene::Update(float elapsedTime)
{
	this->_menuController.Update(elapsedTime);
}

void MemoryGame::MenuScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
	this->_menuController.Render(window);
}

void MemoryGame::MenuScene::ProcessMouseClick(sf::Vector2f mousePosition)
{
	this->_menuController.ProcessMouseClick(mousePosition);
}
