#include "BoardView.h"


MemoryGame::BoardView::BoardView()
{
	this->Init();
}

MemoryGame::BoardView::~BoardView()
{

}

void MemoryGame::BoardView::Init()
{
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

void MemoryGame::BoardView::Render(sf::RenderWindow* window)
{
	window->draw(_backgroundImage);
}