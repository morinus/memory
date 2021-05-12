#include "Game.h"

// Utils
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

// Consts
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto WINDOW_WIDTH = 1024;
constexpr auto WINDOW_TITLE = "Memory Game";


MemoryGame::Game::Game()
{
	this->InitWindow();
	this->InitGame();
}

MemoryGame::Game::~Game()
{
	delete this->_window;
}

void MemoryGame::Game::InitWindow()
{
	this->_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close);

	// Render Window Icon
	sf::Image icon;
	if (!icon.loadFromFile(WINDOW_ICON_FILEPATH))
	{
		std::cout << ERROR_LOADING_WINDOW_ICON << std::endl;
	}

	this->_window->setIcon(icon.getSize().y, icon.getSize().x, icon.getPixelsPtr());
}

void MemoryGame::Game::InitGame()
{
	this->_soundController.PlayMusic();

	this->_boardController.InitBoard(3, 4);
}

sf::RenderWindow* MemoryGame::Game::GetWindow()
{
	return this->_window;
}

void MemoryGame::Game::Update()
{
	this->ProcessInput();
	this->Render();
}

void MemoryGame::Game::ProcessInput()
{
	// Event Pooling
	sf::Event event;
	while (this->_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->_window->close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			this->_soundController.PlayMouseClickSound();
		}
	}
}

void MemoryGame::Game::Render()
{
	this->_window->clear();

	_boardController.Render(this->_window);
	_menuController.Render(this->_window);

	this->_window->display();
}