#include "Button.h"


MemoryGame::Button::Button(sf::Texture* backTexture, sf::Texture* frontTexture, int index)
{
	this->_backTexture = backTexture;
	this->_frontTexture = frontTexture;
	this->_index = index;

	this->_image = sf::Sprite(*_backTexture);
}

MemoryGame::Button::~Button()
{
	delete _backTexture;
	delete _frontTexture;
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
