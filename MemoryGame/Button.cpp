#include "Button.h"

constexpr float PAUSE_TIME_IN_MILLISECONDS = 500.f;


MemoryGame::Button::Button(sf::Texture* backTexture, sf::Texture* frontTexture, int index)
{
	this->_backTexture = backTexture;
	this->_frontTexture = frontTexture;
	this->_index = index;
	this->_isInteractible = true;
	this->_interactionPaused = false;
	this->_animationPlaying = false;

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
	isInteractible ? this->_interactionPaused = true : this->_isInteractible = isInteractible;
}

sf::Sprite MemoryGame::Button::GetImage()
{
	return this->_isInteractible ? this->_backSprite : this->_frontSprite;
}

void MemoryGame::Button::ProcessTurnAnimation(float elapsedTime)
{

}

void MemoryGame::Button::ProcessInteractionPaused(float elapsedTime)
{
	this->_pauseTimeElapsed += elapsedTime;
	if (this->_pauseTimeElapsed >= PAUSE_TIME_IN_MILLISECONDS)
	{
		this->_pauseTimeElapsed = 0;
		this->_isInteractible = true;
		this->_interactionPaused = false;
	}
}

void MemoryGame::Button::Update(float elapsedTime)
{
	if (this->_animationPlaying) this->ProcessTurnAnimation(elapsedTime);
	if (this->_interactionPaused) this->ProcessInteractionPaused(elapsedTime);
}
