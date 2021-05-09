#include "Button.h"


MemoryGame::Button::Button()
{

}

MemoryGame::Button::~Button()
{

}

void MemoryGame::Button::Init()
{

}

void MemoryGame::Button::Update(sf::Event e)
{
	// sf::Vector2i mousePosition = sf::Mouse::getPosition();

	// Check whether mouse position is inside bounds of texture image of the button
}

void MemoryGame::Button::ChangeButtonState(ButtonState newState)
{
	this->_state = newState;
}

void MemoryGame::Button::ResetButtonState()
{
	this->_state = ButtonState::NORMAL;
}