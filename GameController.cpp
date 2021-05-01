#include "GameController.h"


MemoryGame::GameController::GameController()
{
	this->InitWindow();
}

MemoryGame::GameController::~GameController()
{
	delete this->_window;
}

void MemoryGame::GameController::InitWindow()
{
	this->_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), WINDOW_TITLE);
}

void MemoryGame::GameController::Render()
{
	this->_window->clear();

	// Render

	this->_window->display();
}

void MemoryGame::GameController::PoolEvents()
{
	sf::Event event;

	while (this->_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->_window->close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.KeyPressed == sf::Keyboard::Escape)
			{
				// this->_menuController.Open();
			}
		}
	}
}

const bool MemoryGame::GameController::GetWindowIsOpen()
{
	return this->_window->isOpen();
}