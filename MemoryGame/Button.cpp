#include "Button.h"


MemoryGame::Button::Button(sf::Texture* backTexture, sf::Texture* frontTexture, int index)
{
	this->_backTexture = backTexture;
	this->_frontTexture = frontTexture;
	this->_index = index;
	this->_isInteractible = true;

	this->_backSprite = sf::Sprite(*_backTexture);
	this->_frontSprite = sf::Sprite(*_frontTexture);
}

MemoryGame::Button::~Button()
{

}

void MemoryGame::Button::Init(int index)
{
	this->_index = index;
}

void MemoryGame::Button::Update(sf::Event e)
{

}

void MemoryGame::Button::Render(sf::RenderWindow* window)
{
	if (this->_isInteractible)
	{
		window->draw(this->_backSprite);
	}
	else
	{
		window->draw(this->_frontSprite);
	}
}

void MemoryGame::Button::SetPosition(sf::Vector2f newPosition)
{
	this->_frontSprite.setPosition(newPosition);
	this->_backSprite.setPosition(newPosition);
}

void MemoryGame::Button::SetScale(sf::Vector2f newScale)
{
	this->_frontSprite.setScale(newScale);
	this->_backSprite.setScale(newScale);
}

void MemoryGame::Button::SetIsInteractible(bool isInteractible)
{
	this->_isInteractible = isInteractible;
}

sf::Sprite MemoryGame::Button::GetImage()
{
	return this->_isInteractible ? this->_backSprite : this->_frontSprite;
}
