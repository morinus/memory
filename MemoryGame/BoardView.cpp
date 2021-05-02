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

	this->InitBoardTexture();
}

void MemoryGame::BoardView::InitBoardTexture()
{
	sf::Texture texture;
	if (!texture.loadFromFile("Images/background.jpg"))
	{
		// error
	}


}

void MemoryGame::BoardView::Render()
{

}