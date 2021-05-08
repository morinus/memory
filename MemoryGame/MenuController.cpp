#include "MenuController.h"


MemoryGame::MenuController::MenuController()
{

}

MemoryGame::MenuController::~MenuController()
{

}

void MemoryGame::MenuController::Render(sf::RenderWindow* window)
{
	_menuView.Render(window);
}