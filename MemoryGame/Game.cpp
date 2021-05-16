#include "Game.h"

// Utils
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

// Consts
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto WINDOW_WIDTH = 1024;
constexpr auto WINDOW_TITLE = "Memory Game";

// Game Setup
constexpr int NUMBER_OF_PLAYERS = 3;
constexpr int NUMBER_OF_CARDS = 12;


MemoryGame::Game::Game()
{
	try
	{
		this->InitWindow();
		this->InitGame();
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}
}

MemoryGame::Game::~Game()
{
	delete this->_window;
}

void MemoryGame::Game::InitWindow()
{
	this->_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close);

	sf::Image icon;
	if (!icon.loadFromFile(WINDOW_ICON_FILEPATH))
	{
		throw(ERROR_LOADING_WINDOW_ICON);
	}

	this->_window->setIcon(icon.getSize().y, icon.getSize().x, icon.getPixelsPtr());
}

void MemoryGame::Game::InitGame()
{
	this->_soundController.PlayMusic();

	// Temporary
	this->_boardController.InitBoard(NUMBER_OF_PLAYERS, NUMBER_OF_CARDS);
}

void MemoryGame::Game::Play()
{
	while (this->_window->isOpen())
	{
		this->ProcessInput();
		this->Update();
		this->Render();
	}
}

void MemoryGame::Game::ProcessInput()
{
	sf::Event event;

	while (this->_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->_window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mousePosition = this->_window->mapPixelToCoords(sf::Mouse::getPosition(*this->_window));

				this->_boardController.ProcessMouseClick(mousePosition);
				this->_soundController.PlayMouseClickSound();
			}
			break;
		default:
			break;
		}
	}
}

void MemoryGame::Game::Render()
{
	this->_window->clear();

	_boardController.Render(this->_window);
	//_menuController.Render(this->_window);

	this->_window->display();
}

void MemoryGame::Game::Update()
{
	_boardController.Update();
}