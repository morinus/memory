#include <iostream>
#include <random>
#include <chrono>

#include "BoardView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

constexpr float STARTING_OFFSET_X = 350.f;
constexpr float STARTING_OFFSET_Y = 150.f;
constexpr float HORIZONTAL_OFFSET = 150.f;
constexpr float VERTICAL_OFFSET = 200.f;
constexpr float CARD_SCALE = 0.5f;

// TEMPORARY
constexpr int ROWS = 3;
constexpr int COLUMNS = 4;


MemoryGame::BoardView::BoardView()
{

}

MemoryGame::BoardView::~BoardView()
{
	for (auto button : this->_cardButtons)
	{
		delete button;
	}

	this->_cardButtons.clear();
}

void MemoryGame::BoardView::Init(std::vector<MemoryGame::Card> cards)
{
	try
	{
		this->InitBoardBackground();
		this->InitTextures();
		this->InitCards(cards);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}

	this->SetupCardButtons();
}

int MemoryGame::BoardView::GetSelectedButtonIndex(sf::Vector2f mousePosition)
{
	for (int i = 0; i < this->_cardButtons.capacity() - 1; ++i)
	{
		Button* button = this->_cardButtons[i];
		auto isInteractible = button->GetIsInteractible();
		auto isInsideBounds = button->GetImage().getGlobalBounds().contains(mousePosition);

		if (isInteractible && isInsideBounds)
		{
			button->SetIsInteractible(false);

			return button->GetIndex();
		}
	}

	return -1;
}

void MemoryGame::BoardView::DeselectButtons()
{
	for (auto button : this->_cardButtons)
	{
		button->SetIsInteractible(true);
	}
}

void MemoryGame::BoardView::SetIsInteractible(int index, bool isInteractible)
{
	for (auto button : this->_cardButtons)
	{
		if (button->GetIndex() == index)
		{
			button->SetIsInteractible(isInteractible);
			break;
		}

	}
}

void MemoryGame::BoardView::InitBoardBackground()
{
	if (!_backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILEPATH))
	{
		throw(ERROR_LOADING_TEXTURE);
	}

	_backgroundImage = sf::Sprite(_backgroundTexture);
}

void MemoryGame::BoardView::InitCards(std::vector<MemoryGame::Card> cards)
{
	int i = 0;
	for (auto card : cards)
	{
		auto cardType = card.GetCardType();
		Button* cardButton = new Button(&_cardBackTexture, this->GetTextureByCardType(cardType), i++);

		this->_cardButtons.push_back(cardButton);
	}

	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->_cardButtons.begin(), this->_cardButtons.end(), std::default_random_engine(seed));
}

void MemoryGame::BoardView::SetupCardButtons()
{
	// Temporary solution, should be done inside a rectangle dynamically in algorithm pattern
	int cardsPlaced = 0;
	for (int j = 0; j < ROWS; j++)
	{
		for (int i = 0; i < COLUMNS; ++i)
		{
			this->_cardButtons[cardsPlaced]->SetPosition(sf::Vector2f(STARTING_OFFSET_X + HORIZONTAL_OFFSET * i, STARTING_OFFSET_Y + (VERTICAL_OFFSET * j)));
			this->_cardButtons[cardsPlaced]->SetScale(sf::Vector2f(CARD_SCALE, CARD_SCALE));
			cardsPlaced++;
		}
	}
}

void MemoryGame::BoardView::InitTextures()
{
	if (!_monsterATexture.loadFromFile(MONSTER_A_TEXTURE_FILEPATH)
		|| !_monsterBTexture.loadFromFile(MONSTER_B_TEXTURE_FILEPATH)
		|| !_monsterCTexture.loadFromFile(MONSTER_C_TEXTURE_FILEPATH)
		|| !_monsterDTexture.loadFromFile(MONSTER_D_TEXTURE_FILEPATH)
		|| !_cardBackTexture.loadFromFile(CARD_BACKGROUND_TEXTURE_FILEPATH))
	{
		throw(ERROR_LOADING_TEXTURE);
	}
}

sf::Texture* MemoryGame::BoardView::GetTextureByCardType(CardType cardType)
{
	switch (cardType)
	{
	case CardType::MONSTER_A:
		return &this->_monsterATexture;
	case CardType::MONSTER_B:
		return &this->_monsterBTexture;
	case CardType::MONSTER_C:
		return &this->_monsterCTexture;
	case CardType::MONSTER_D:
		return &this->_monsterDTexture;
	}
}

void MemoryGame::BoardView::Render(sf::RenderWindow* window)
{
	window->draw(_backgroundImage);

	for (auto button : this->_cardButtons)
	{
		button->Render(window);
	}
}

void MemoryGame::BoardView::Update(float elapsedTime)
{
	for (auto button : this->_cardButtons)
	{
		button->Update(elapsedTime);
	}
}
