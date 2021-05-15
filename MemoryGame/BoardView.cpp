#include <iostream>
#include <random>
#include <chrono>

#include "BoardView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"


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
	this->InitBoardBackground();
	this->InitTextures();
	this->InitCards(cards);

	this->SetupCardButtons();
}

int MemoryGame::BoardView::GetClickedButtonIndex(sf::Vector2f mousePosition)
{
	for (int i = 0; i < this->_cardButtons.capacity() - 1; ++i)
	{
		auto button = this->_cardButtons[i];

		if (button->GetImage().getGlobalBounds().contains(mousePosition))
		{
			button->ChangeButtonState(MemoryGame::ButtonState::CLICKED);

			return button->GetIndex();
		}
	}

	return -1;
}

void MemoryGame::BoardView::InitBoardBackground()
{
	if (!_backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	_backgroundImage = sf::Sprite(_backgroundTexture);
}

void MemoryGame::BoardView::InitCards(std::vector<MemoryGame::Card> cards)
{
	int i = 0;
	for (auto card : cards)
	{
		CardType cardType = card.GetCardType();
		Button* cardButton = new Button(&_cardBackTexture, this->GetTextureByCardType(cardType), i++);

		this->_cardButtons.push_back(cardButton);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->_cardButtons.begin(), this->_cardButtons.end(), std::default_random_engine(seed));
}

void MemoryGame::BoardView::SetupCardButtons()
{
	int offset = 150;

	/*for (int i = 0; i < this->_cardButtons.capacity(); ++i)
	{
		this->_cardButtons[i]->SetPosition(sf::Vector2f(300 + offset * i, 100));
		this->_cardButtons[i]->SetScale(sf::Vector2f(0.5, 0.5));
	}*/

	// Temporary solution, should be done inside a rectangle dynamically in algorithm pattern

	int cardsPlaced = 0;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 4; ++i)
		{
			this->_cardButtons[cardsPlaced]->SetPosition(sf::Vector2f(300 + offset * i, 100 + (200 * j)));
			this->_cardButtons[cardsPlaced]->SetScale(sf::Vector2f(0.5, 0.5));
			cardsPlaced++;
		}
	}
}

void MemoryGame::BoardView::InitTextures()
{
	if (!_monsterATexture.loadFromFile(MONSTER_A_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	if (!_monsterBTexture.loadFromFile(MONSTER_B_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	if (!_monsterCTexture.loadFromFile(MONSTER_C_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	if (!_monsterDTexture.loadFromFile(MONSTER_D_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	if (!_cardBackTexture.loadFromFile(CARD_BACKGROUND_TEXTURE_FILEPATH))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
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