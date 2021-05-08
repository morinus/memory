#include <iostream>
#include "BoardView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"


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
	if (!_backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	_backgroundImage = sf::Sprite(_backgroundTexture);
}

void MemoryGame::BoardView::Render(sf::RenderWindow* window)
{
	window->draw(_backgroundImage);
}