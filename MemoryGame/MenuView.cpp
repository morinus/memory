#include "MenuView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

#include <iostream>


MemoryGame::MenuView::MenuView()
{
	try
	{
		this->InitBoardBackground();
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}
}

MemoryGame::MenuView::~MenuView()
{

}

void MemoryGame::MenuView::InitBoardBackground()
{
	if (!_backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILEPATH))
	{
		throw(ERROR_LOADING_TEXTURE);
	}

	_backgroundImage = sf::Sprite(_backgroundTexture);
}

void MemoryGame::MenuView::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(this->_backgroundImage);
}

void MemoryGame::MenuView::Update(float elapsedTime)
{

}
