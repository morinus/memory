#include <iostream>

#include "BoardView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"


MemoryGame::BoardView::BoardView()
{

}

MemoryGame::BoardView::~BoardView()
{

}

void MemoryGame::BoardView::Init(int numberOfCards)
{
	this->InitBoardBackground();
	this->InitCards(numberOfCards);
}

void MemoryGame::BoardView::InitBoardBackground()
{
	if (!_backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	_backgroundImage = sf::Sprite(_backgroundTexture);
}

void MemoryGame::BoardView::InitCards(int numberOfCards)
{

}

void MemoryGame::BoardView::Render(sf::RenderWindow* window)
{
	window->draw(_backgroundImage);
}