#include "Game.h"

using namespace MemoryGame;

Game::Game()
{
	this->InitWindow();
}

Game::~Game()
{
	delete this->_window;
}

void Game::InitWindow()
{
	this->_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Memory Game");
}

void Game::Render()
{
	this->_window->clear();

	// Render

	this->_window->display();
}

void Game::PoolEvents()
{
	sf::Event event;

	while (this->_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->_window->close();
		}
	}
}

const bool Game::GetWindowIsOpen()
{
	return this->_window->isOpen();
}