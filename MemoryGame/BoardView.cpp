#include <iostream>
#include <random>
#include <chrono>

#include "BoardView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

constexpr float STARTING_OFFSET_X = 300.f;
constexpr float STARTING_OFFSET_Y = 100.f;
constexpr float HORIZONTAL_OFFSET = 125.f;
constexpr float VERTICAL_OFFSET = 150.f;
constexpr float CARD_SCALE = 0.35f;
constexpr int BOARD_HEIGHT = 1000;
constexpr int BOARD_WIDTH = 1000;

// TEMPORARY
constexpr int ROWS = 4;
constexpr int COLUMNS = 6;


MemoryGame::BoardView::BoardView()
{

}

MemoryGame::BoardView::~BoardView()
{
	this->_cardButtons.clear();
}

void MemoryGame::BoardView::Init(std::vector<MemoryGame::Card> cards, int boardWidth, int boardHeight)
{
	try
	{
		if (!this->_isInited)
		{
			this->InitBoardBackground();
			this->InitTextures();
		}

		this->_cardButtons.clear();
		this->InitCards(cards);
		this->_isInited = true;
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}

	this->SetupCardButtons(boardWidth, boardHeight);
}

int MemoryGame::BoardView::GetSelectedButtonIndex(sf::Vector2f mousePosition)
{
	for (int i = 0; i < this->_cardButtons.size(); ++i)
	{
		std::shared_ptr<ButtonView> buttonView = this->_cardButtons[i];
		auto isInteractible = buttonView->GetIsInteractible();
		auto isInsideBounds = buttonView->GetImage().getGlobalBounds().contains(mousePosition);

		if (isInteractible && isInsideBounds)
		{
			buttonView->SetIsInteractible(false);

			return buttonView->GetIndex();
		}
	}

	return -1;
}

void MemoryGame::BoardView::DeselectButtons()
{
	for (auto buttonView : this->_cardButtons)
	{
		buttonView->SetIsInteractible(true);
	}
}

void MemoryGame::BoardView::SetIsInteractible(int index, bool isInteractible)
{
	for (auto buttonView : this->_cardButtons)
	{
		if (buttonView->GetIndex() == index)
		{
			buttonView->SetIsInteractible(isInteractible);

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

	_backgroundSprite = sf::Sprite(_backgroundTexture);
}

void MemoryGame::BoardView::InitCards(std::vector<MemoryGame::Card> cards)
{
	int i = 0;
	for (auto card : cards)
	{
		auto cardType = card.GetCardType();
		std::shared_ptr<ButtonView> cardButton = std::make_shared<ButtonView>(&_cardBackTexture, this->GetTextureByCardType(cardType), i++);

		this->_cardButtons.push_back(cardButton);
	}

	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->_cardButtons.begin(), this->_cardButtons.end(), std::default_random_engine(seed));
}

void MemoryGame::BoardView::SetupCardButtons(int width, int height)
{
	int cardWidth = (this->_cardButtons[0]->GetImage().getLocalBounds().width * CARD_SCALE) + HORIZONTAL_OFFSET;
	int cardHeight = (this->_cardButtons[0]->GetImage().getLocalBounds().height * CARD_SCALE) + VERTICAL_OFFSET;
	float cardScaledWidth = BOARD_WIDTH / width;
	float cardScaledHeight = BOARD_HEIGHT / height;
	float widthFactor = cardScaledWidth / cardWidth;
	float heightFactor = cardScaledHeight / cardHeight;

	int cardsPlaced = 0;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; ++i)
		{
			if (widthFactor > 1 && heightFactor > 1)
			{
				this->_cardButtons[cardsPlaced]->SetPosition(sf::Vector2f(STARTING_OFFSET_X + HORIZONTAL_OFFSET * i, STARTING_OFFSET_Y + (VERTICAL_OFFSET * j)));
				this->_cardButtons[cardsPlaced]->SetScale(sf::Vector2f(CARD_SCALE, CARD_SCALE));
			}
			else
			{
				if (heightFactor < widthFactor)
				{
					this->_cardButtons[cardsPlaced]->SetPosition(sf::Vector2f(STARTING_OFFSET_X + HORIZONTAL_OFFSET * heightFactor * i, STARTING_OFFSET_Y + (VERTICAL_OFFSET * heightFactor * j)));
					this->_cardButtons[cardsPlaced]->SetScale(sf::Vector2f(CARD_SCALE * heightFactor, CARD_SCALE * heightFactor));
				}
				else
				{
					this->_cardButtons[cardsPlaced]->SetPosition(sf::Vector2f(STARTING_OFFSET_X + HORIZONTAL_OFFSET * widthFactor * i, STARTING_OFFSET_Y + (VERTICAL_OFFSET * widthFactor * j)));
					this->_cardButtons[cardsPlaced]->SetScale(sf::Vector2f(CARD_SCALE * widthFactor, CARD_SCALE * widthFactor));
				}
			}

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

void MemoryGame::BoardView::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(_backgroundSprite);

	for (auto button : this->_cardButtons)
	{
		button->Render(window);
	}
}

void MemoryGame::BoardView::Update(float elapsedTime)
{
	for (auto buttonView : this->_cardButtons)
	{
		buttonView->Update(elapsedTime);
	}
}
