#include "BoardView.h"


MemoryGame::BoardView::BoardView()
{

}

MemoryGame::BoardView::~BoardView()
{

}

void MemoryGame::BoardView::Init(sf::RenderWindow* window)
{
	this->_window = window;

	this->InitBoardBackground();
}

void MemoryGame::BoardView::InitBoardBackground()
{
	if (!_backgroundTexture.loadFromFile("../Images/background.jpg"))
	{
		// error
	}

	_backgroundImage = sf::Sprite(_backgroundTexture);
}

void MemoryGame::BoardView::Render()
{
	this->_window->draw(_backgroundImage);
}