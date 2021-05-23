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

	this->_playersLeftButtonSprite = sf::Sprite(_buttonArrowTexture);
	this->_playersLeftButtonSprite.setPosition(NUMBER_OF_PLAYERS_OFFSET_X - BUTTON_OFFSET_X, NUMBER_OF_PLAYERS_OFFSET_Y);
	this->_playersLeftButtonSprite.setScale(sf::Vector2f(-0.1f, 0.1f));

	this->_playersRightButtonSprite = sf::Sprite(_buttonArrowTexture);
	this->_playersRightButtonSprite.setPosition(NUMBER_OF_PLAYERS_OFFSET_X + BUTTON_OFFSET_X * 2, NUMBER_OF_PLAYERS_OFFSET_Y);
	this->_playersRightButtonSprite.setScale(sf::Vector2f(0.1f, 0.1f));

	this->_cardsLeftButtonSprite = sf::Sprite(_buttonArrowTexture);
	this->_cardsLeftButtonSprite.setPosition(NUMBER_OF_CARDS_OFFSET_X - BUTTON_OFFSET_X, NUMBER_OF_CARDS_OFFSET_Y);
	this->_cardsLeftButtonSprite.setScale(sf::Vector2f(-0.1f, 0.1f));

	this->_cardsRightButtonSprite = sf::Sprite(_buttonArrowTexture);
	this->_cardsRightButtonSprite.setPosition(NUMBER_OF_CARDS_OFFSET_X + BUTTON_OFFSET_X * 2, NUMBER_OF_CARDS_OFFSET_Y);
	this->_cardsRightButtonSprite.setScale(sf::Vector2f(0.1f, 0.1f));
}

void MemoryGame::MenuView::InitTexts()
{
	if (!this->_font.loadFromFile(FONT_FILEPATH))
	{
		throw(ERROR_LOADING_FONT);
	}

	this->_sceneTitleText.setString(std::string(MENU_TITLE_TEXT));
	this->_sceneTitleText.setFont(this->_font);
	this->_sceneTitleText.setPosition(sf::Vector2f(TITLE_TEXT_OFFSET_X, TITLE_TEXT_OFFSET_Y));
	this->_sceneTitleText.setCharacterSize(TITLE_FONT_SIZE);

	this->_numberOfPlayersText.setString(std::to_string(NUMBER_OF_PLAYERS_INIT_NUMBER));
	this->_numberOfPlayersText.setFont(this->_font);
	this->_numberOfPlayersText.setPosition(sf::Vector2f(NUMBER_OF_PLAYERS_OFFSET_X, NUMBER_OF_PLAYERS_OFFSET_Y));
	this->_numberOfPlayersText.setCharacterSize(NUMBER_FONT_SIZE);
	this->_numberOfPlayersText.setFillColor(sf::Color::Green);

	this->_numberOfCardsText.setString(std::to_string(NUMBER_OF_CARDS_INIT_NUMBER));
	this->_numberOfCardsText.setFont(this->_font);
	this->_numberOfCardsText.setPosition(sf::Vector2f(NUMBER_OF_CARDS_OFFSET_X, NUMBER_OF_CARDS_OFFSET_Y));
	this->_numberOfCardsText.setCharacterSize(NUMBER_FONT_SIZE);
	this->_numberOfCardsText.setFillColor(sf::Color::Green);

	this->_playText.setString(std::string(PLAY_BUTTON_TEXT));
	this->_playText.setFont(this->_font);
	this->_playText.setPosition(sf::Vector2f(PLAY_BUTTON_OFFSET_X, PLAY_BUTTON_OFFSET_Y));
	this->_playText.setCharacterSize(PLAY_BUTTON_FONT_SIZE);
	this->_playText.setFillColor(sf::Color::Green);
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

void MemoryGame::MenuView::Update(float elapsedTime)
{

}
