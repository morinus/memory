#include "MenuView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

#include <iostream>

constexpr char MENU_TITLE_TEXT[] = "Main Menu";
constexpr int TITLE_FONT_SIZE = 52;
constexpr int TITLE_TEXT_OFFSET_X = 365;
constexpr int TITLE_TEXT_OFFSET_Y = 40;
constexpr int NUMBER_OF_PLAYERS_OFFSET_X = 480;
constexpr int NUMBER_OF_PLAYERS_OFFSET_Y = 250;
constexpr int NUMBER_OF_PLAYERS_INIT_NUMBER = 5;
constexpr int NUMBER_OF_CARDS_OFFSET_X = 480;
constexpr int NUMBER_OF_CARDS_OFFSET_Y = 400;
constexpr int NUMBER_OF_CARDS_INIT_NUMBER = 24;
constexpr int NUMBER_FONT_SIZE = 52;
constexpr char PLAY_BUTTON_TEXT[] = "PLAY";
constexpr int PLAY_BUTTON_FONT_SIZE = 52;
constexpr int PLAY_BUTTON_OFFSET_X = 450;
constexpr int PLAY_BUTTON_OFFSET_Y = 550;
constexpr int BUTTON_OFFSET_X = 30;


MemoryGame::MenuView::MenuView()
{
	try
	{
		this->InitBoardBackground();
		this->InitButtons();
		this->InitTexts();
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}
}

MemoryGame::MenuView::~MenuView()
{

}

void MemoryGame::MenuView::InitBoardBackground()
{
	if (!_backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILEPATH))
	{
		throw(ERROR_LOADING_TEXTURE);
	}

	_backgroundSprite = sf::Sprite(_backgroundTexture);
}

void MemoryGame::MenuView::InitButtons()
{
	if (!_buttonArrowTexture.loadFromFile(ARROW_TEXTURE_FILEPATH))
	{
		throw(ERROR_LOADING_TEXTURE);
	}

	this->InitButton(&this->_playersLeftButtonSprite, sf::Vector2f(NUMBER_OF_PLAYERS_OFFSET_X - BUTTON_OFFSET_X, NUMBER_OF_PLAYERS_OFFSET_Y), sf::Vector2f(-0.1f, 0.1f));

	this->InitButton(&this->_playersRightButtonSprite, sf::Vector2f(NUMBER_OF_PLAYERS_OFFSET_X + BUTTON_OFFSET_X * 2, NUMBER_OF_PLAYERS_OFFSET_Y), sf::Vector2f(0.1f, 0.1f));

	this->InitButton(&this->_cardsLeftButtonSprite, sf::Vector2f(NUMBER_OF_CARDS_OFFSET_X - BUTTON_OFFSET_X, NUMBER_OF_CARDS_OFFSET_Y), sf::Vector2f(-0.1f, 0.1f));

	this->InitButton(&this->_cardsRightButtonSprite, sf::Vector2f(NUMBER_OF_CARDS_OFFSET_X + BUTTON_OFFSET_X * 2, NUMBER_OF_CARDS_OFFSET_Y), sf::Vector2f(0.1f, 0.1f));
}

void MemoryGame::MenuView::InitButton(sf::Sprite* button, sf::Vector2f position, sf::Vector2f scale)
{
	*button = sf::Sprite(this->_buttonArrowTexture);
	button->setPosition(position);
	button->setScale(scale);
}

void MemoryGame::MenuView::InitTexts()
{
	if (!this->_font.loadFromFile(FONT_FILEPATH))
	{
		throw(ERROR_LOADING_FONT);
	}

	this->InitText(&this->_sceneTitleText, std::string(MENU_TITLE_TEXT), sf::Vector2f(TITLE_TEXT_OFFSET_X, TITLE_TEXT_OFFSET_Y), TITLE_FONT_SIZE);

	this->InitText(&this->_numberOfPlayersText, std::to_string(NUMBER_OF_PLAYERS_INIT_NUMBER), sf::Vector2f(NUMBER_OF_PLAYERS_OFFSET_X, NUMBER_OF_PLAYERS_OFFSET_Y), NUMBER_FONT_SIZE, sf::Color::Green);

	this->InitText(&this->_numberOfCardsText, std::to_string(NUMBER_OF_CARDS_INIT_NUMBER), sf::Vector2f(NUMBER_OF_CARDS_OFFSET_X, NUMBER_OF_CARDS_OFFSET_Y), NUMBER_FONT_SIZE, sf::Color::Green);

	this->InitText(&_playText, std::string(PLAY_BUTTON_TEXT), sf::Vector2f(PLAY_BUTTON_OFFSET_X, PLAY_BUTTON_OFFSET_Y), PLAY_BUTTON_FONT_SIZE, sf::Color::Green);
}

void MemoryGame::MenuView::InitText(sf::Text* text, std::string textString, sf::Vector2f position, int characterSize, sf::Color fillColor)
{
	text->setString(textString);
	text->setFont(this->_font);
	text->setPosition(position);
	text->setCharacterSize(characterSize);
	text->setFillColor(fillColor);
}

int MemoryGame::MenuView::GetSelectedButtonType(sf::Vector2f mousePosition)
{
	// Temporary Solution
	if (this->_playersLeftButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		return 0;
	}

	if (this->_playersRightButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		return 1;
	}

	if (this->_cardsLeftButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		return 2;
	}

	if (this->_cardsRightButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		return 3;
	}

	if (this->_playText.getGlobalBounds().contains(mousePosition))
	{
		return 4;
	}

	return -1;
}

void MemoryGame::MenuView::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(this->_backgroundSprite);
	window->draw(this->_sceneTitleText);
	window->draw(this->_numberOfPlayersText);
	window->draw(this->_numberOfCardsText);
	window->draw(this->_playText);

	window->draw(this->_playersLeftButtonSprite);
	window->draw(this->_playersRightButtonSprite);
	window->draw(this->_cardsLeftButtonSprite);
	window->draw(this->_cardsRightButtonSprite);
}

void MemoryGame::MenuView::UpdateNumberOfPlayers(int numberOfPlayers)
{
	this->_numberOfPlayersText.setString(std::to_string(numberOfPlayers));
}

void MemoryGame::MenuView::UpdateNumberOfCards(int numberOfCards)
{
	this->_numberOfCardsText.setString(std::to_string(numberOfCards));
}
