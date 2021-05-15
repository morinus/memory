#include "Button.h"


MemoryGame::Button::Button(sf::Texture* backTexture, sf::Texture* frontTexture, int index)
{
	this->_backTexture = backTexture;
	this->_frontTexture = frontTexture;
	this->_index = index;
	this->_isInteractible = true;

	this->_image = sf::Sprite(*_backTexture);
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
	window->draw(this->_image);
}

void MemoryGame::Button::ChangeButtonState(ButtonState newState)
{
	this->_state = newState;
}

void MemoryGame::Button::ResetButtonState()
{
	this->_state = ButtonState::NORMAL;
}

void MemoryGame::Button::SetPosition(sf::Vector2f newPosition)
{
	this->_image.setPosition(newPosition);
}

void MemoryGame::Button::SetScale(sf::Vector2f newScale)
{
	this->_image.setScale(newScale);
}
