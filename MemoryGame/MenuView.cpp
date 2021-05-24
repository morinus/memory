#include "MenuView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

#include <iostream>

constexpr char MENU_TITLE_TEXT[] = "Main Menu";
constexpr int TITLE_FONT_SIZE = 52;
constexpr int SMALL_TITLE_FONT_SIZE = 42;
constexpr int TITLE_TEXT_OFFSET_X = 365;
constexpr int TITLE_TEXT_OFFSET_Y = 40;
constexpr int NUMBER_OF_PLAYERS_OFFSET_X = 480;
constexpr int NUMBER_OF_PLAYERS_OFFSET_Y = 250;
constexpr int NUMBER_OF_PLAYERS_TITLE_TEXT_OFFSET_X = 420;
constexpr int NUMBER_OF_PLAYERS_TITLE_TEXT_OFFSET_Y = 200;
constexpr char NUMBER_OF_PLAYERS_TITLE_TEXT[] = "Players";
constexpr int NUMBER_OF_PLAYERS_INIT_NUMBER = 5;
constexpr int WIDTH_BUTTON_OFFSET_X = 480;
constexpr int WIDTH_BUTTON_OFFSET_Y = 400;
constexpr int WIDTH_TITLE_TEXT_OFFSET_X = 430;
constexpr int WIDTH_TITLE_TEXT_OFFSET_Y = 350;
constexpr char WIDTH_TITLE_TEXT[] = "Width";
constexpr int HEIGHT_BUTTON_OFFSET_X = 480;
constexpr int HEIGHT_BUTTON_OFFSET_Y = 550;
constexpr int HEIGHT_TITLE_TEXT_OFFSET_X = 430;
constexpr int HEIGHT_TITLE_TEXT_OFFSET_Y = 500;
constexpr char HEIGHT_TITLE_TEXT[] = "Height";
constexpr int INITIAL_BOARD_HEIGHT = 4;
constexpr int INITIAL_BOARD_WIDTH = 6;
constexpr int NUMBER_FONT_SIZE = 52;
constexpr char PLAY_BUTTON_TEXT[] = "PLAY";
constexpr int PLAY_BUTTON_FONT_SIZE = 52;
constexpr int PLAY_BUTTON_OFFSET_X = 450;
constexpr int PLAY_BUTTON_OFFSET_Y = 700;
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

	this->InitButton(&this->_heightLeftButtonSprite, sf::Vector2f(HEIGHT_BUTTON_OFFSET_X - BUTTON_OFFSET_X, HEIGHT_BUTTON_OFFSET_Y), sf::Vector2f(-0.1f, 0.1f));

	this->InitButton(&this->_heightRightButtonSprite, sf::Vector2f(HEIGHT_BUTTON_OFFSET_X + BUTTON_OFFSET_X * 2, HEIGHT_BUTTON_OFFSET_Y), sf::Vector2f(0.1f, 0.1f));

	this->InitButton(&this->_widthLeftButtonSprite, sf::Vector2f(WIDTH_BUTTON_OFFSET_X - BUTTON_OFFSET_X, WIDTH_BUTTON_OFFSET_Y), sf::Vector2f(-0.1f, 0.1f));

	this->InitButton(&this->_widthRightButtonSprite, sf::Vector2f(WIDTH_BUTTON_OFFSET_X + BUTTON_OFFSET_X * 2, WIDTH_BUTTON_OFFSET_Y), sf::Vector2f(0.1f, 0.1f));
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

	this->InitText(&this->_heightText, std::to_string(INITIAL_BOARD_HEIGHT), sf::Vector2f(HEIGHT_BUTTON_OFFSET_X, HEIGHT_BUTTON_OFFSET_Y), NUMBER_FONT_SIZE, sf::Color::Green);

	this->InitText(&this->_widthText, std::to_string(INITIAL_BOARD_WIDTH), sf::Vector2f(WIDTH_BUTTON_OFFSET_X, WIDTH_BUTTON_OFFSET_Y), NUMBER_FONT_SIZE, sf::Color::Green);

	this->InitText(&_playText, std::string(PLAY_BUTTON_TEXT), sf::Vector2f(PLAY_BUTTON_OFFSET_X, PLAY_BUTTON_OFFSET_Y), PLAY_BUTTON_FONT_SIZE, sf::Color::Green);

	this->InitText(&_numberOfPlayersTitleText, std::string(NUMBER_OF_PLAYERS_TITLE_TEXT), sf::Vector2f(NUMBER_OF_PLAYERS_TITLE_TEXT_OFFSET_X, NUMBER_OF_PLAYERS_TITLE_TEXT_OFFSET_Y), SMALL_TITLE_FONT_SIZE);

	this->InitText(&_widthTitleText, std::string(WIDTH_TITLE_TEXT), sf::Vector2f(WIDTH_TITLE_TEXT_OFFSET_X, WIDTH_TITLE_TEXT_OFFSET_Y), SMALL_TITLE_FONT_SIZE);

	this->InitText(&_heightTitleText, std::string(HEIGHT_TITLE_TEXT), sf::Vector2f(HEIGHT_TITLE_TEXT_OFFSET_X, HEIGHT_TITLE_TEXT_OFFSET_Y), SMALL_TITLE_FONT_SIZE);
}

void MemoryGame::MenuView::InitText(sf::Text* text, std::string textString, sf::Vector2f position, int characterSize, sf::Color fillColor)
{
	text->setString(textString);
	text->setFont(this->_font);
	text->setPosition(position);
	text->setCharacterSize(characterSize);
	text->setFillColor(fillColor);
}

void MemoryGame::MenuView::ProcessMouseClick(sf::Vector2f mousePosition)
{
	if (this->_playersLeftButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		bool isIncreased = false;
		this->_changeNumberOfPlayersDelegate(isIncreased);
		return;
	}

	if (this->_playersRightButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		bool isIncreased = true;
		this->_changeNumberOfPlayersDelegate(isIncreased);
		return;
	}

	if (this->_heightLeftButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		bool isIncreased = false;
		this->_changeBoardHeightDelegate(isIncreased);
		return;
	}

	if (this->_heightRightButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		bool isIncreased = true;
		this->_changeBoardHeightDelegate(isIncreased);
		return;
	}

	if (this->_widthLeftButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		bool isIncreased = false;
		this->_changeBoardWidthDelegate(isIncreased);
		return;
	}

	if (this->_widthRightButtonSprite.getGlobalBounds().contains(mousePosition))
	{
		bool isIncreased = true;
		this->_changeBoardWidthDelegate(isIncreased);
		return;
	}

	if (this->_playText.getGlobalBounds().contains(mousePosition))
	{
		this->_playGameDelegate();
	}
}

void MemoryGame::MenuView::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(this->_backgroundSprite);
	window->draw(this->_sceneTitleText);
	window->draw(this->_numberOfPlayersText);
	window->draw(this->_numberOfPlayersTitleText);
	window->draw(this->_heightText);
	window->draw(this->_heightTitleText);
	window->draw(this->_widthText);
	window->draw(this->_widthTitleText);
	window->draw(this->_playText);

	window->draw(this->_playersLeftButtonSprite);
	window->draw(this->_playersRightButtonSprite);
	window->draw(this->_heightLeftButtonSprite);
	window->draw(this->_heightRightButtonSprite);
	window->draw(this->_widthLeftButtonSprite);
	window->draw(this->_widthRightButtonSprite);
}

void MemoryGame::MenuView::UpdateNumberOfPlayers(int numberOfPlayers)
{
	this->_numberOfPlayersText.setString(std::to_string(numberOfPlayers));
}

void MemoryGame::MenuView::UpdateHeight(int newHeight)
{
	this->_heightText.setString(std::to_string(newHeight));
}

void MemoryGame::MenuView::UpdateWidth(int newWidth)
{
	this->_widthText.setString(std::to_string(newWidth));
}

void MemoryGame::MenuView::SetChangeNumberOfPlayersDelegate(std::function<void(bool)> changeNumberOfPlayersDelegate)
{
	this->_changeNumberOfPlayersDelegate = changeNumberOfPlayersDelegate;
}

void MemoryGame::MenuView::SetChangeBoardHeightDelegate(std::function<void(bool)> changeBoardHeightDelegate)
{
	this->_changeBoardHeightDelegate = changeBoardHeightDelegate;
}

void MemoryGame::MenuView::SetChangeBoardWidthDelegate(std::function<void(bool)> changeBoardWidthDelegate)
{
	this->_changeBoardWidthDelegate = changeBoardWidthDelegate;
}

void MemoryGame::MenuView::SetChangePlayButtonDelegate(std::function<void()> playGameDelegate)
{
	this->_playGameDelegate = playGameDelegate;
}
