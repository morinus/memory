#include "MenuController.h"


MemoryGame::MenuController::MenuController()
{
	this->_numberOfPlayers = 0;
	this->_numberOfCards = 0;
}

MemoryGame::MenuController::~MenuController()
{

}

void MemoryGame::MenuController::InitMenu()
{

}

void MemoryGame::MenuController::Render(std::shared_ptr<sf::RenderWindow> window)
{
	this->_menuView.Render(window);
}

void MemoryGame::MenuController::Update(float elapsedTime)
{
	this->_menuView.Update(elapsedTime);
}

void MemoryGame::MenuController::ProcessMouseClick(sf::Vector2f mousePosition)
{

}
