#include "Button.h"

constexpr float PAUSE_TIME_IN_MILLISECONDS = 1000.f;
constexpr float ANIMATION_DURATION_IN_MILLISECONDS = 250.f;
constexpr float ANGLE_FULL_CIRCLE = 360.f;


MemoryGame::Button::Button(sf::Texture* backTexture, sf::Texture* frontTexture, int index)
{
	this->_backTexture = backTexture;
	this->_frontTexture = frontTexture;
	this->_index = index;
	this->_isInteractible = true;
	this->_interactionPaused = false;
	this->_pauseTimeElapsed = 0;
	this->_animationPlaying = false;
	this->_animationTimeElapsed = 0;

	this->_backSprite = sf::Sprite(*this->_backTexture);
	this->_backSprite.setOrigin(this->_backSprite.getTexture()->getSize().x / 2.f, this->_backSprite.getTexture()->getSize().y / 2.f);

	this->_frontSprite = sf::Sprite(*this->_frontTexture);
	this->_frontSprite.setOrigin(this->_frontSprite.getTexture()->getSize().x / 2.f, this->_frontSprite.getTexture()->getSize().y / 2.f);
}

MemoryGame::Button::~Button()
{

}

void MemoryGame::Button::Init(int index)
{
	this->_index = index;
}

void MemoryGame::Button::Render(std::shared_ptr<sf::RenderWindow> window)
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
	if (isInteractible)
	{
		this->_interactionPaused = true;
	}
	else
	{
		this->_animationPlaying = true;
		this->_isInteractible = isInteractible;
	}
}

sf::Sprite MemoryGame::Button::GetImage()
{
	return this->_isInteractible ? this->_backSprite : this->_frontSprite;
}

void MemoryGame::Button::ProcessTurnAnimation(float elapsedTime)
{
	this->_animationTimeElapsed += elapsedTime;

	if (this->_isInteractible)
	{
		this->_backSprite.setRotation((this->_animationTimeElapsed / ANIMATION_DURATION_IN_MILLISECONDS) * ANGLE_FULL_CIRCLE);
	}
	else
	{
		this->_frontSprite.setRotation((this->_animationTimeElapsed / ANIMATION_DURATION_IN_MILLISECONDS) * ANGLE_FULL_CIRCLE);
	}

	bool animationCompleted = this->_animationTimeElapsed >= ANIMATION_DURATION_IN_MILLISECONDS;
	if (animationCompleted)
	{
		this->_frontSprite.setRotation(0);
		this->_backSprite.setRotation(0);

		this->_animationPlaying = false;
		this->_animationTimeElapsed = 0;
	}
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
