#include "MenuController.h"


MemoryGame::MenuController::MenuController()
{
	_isActive = true;
}

MemoryGame::MenuController::~MenuController()
{

}

bool MemoryGame::MenuController::IsActive()
{
	return _isActive;
}

void MemoryGame::MenuController::Render(sf::RenderWindow* window)
{
	_menuView.Render(window);
}