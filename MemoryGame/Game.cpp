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
	delete this->_currentScene;
}

void MemoryGame::Game::InitWindow()
{
	this->_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close);

	sf::Image icon;
	if (!icon.loadFromFile(WINDOW_ICON_FILEPATH))
	{
		throw(ERROR_LOADING_WINDOW_ICON);
	}

	this->_window->setIcon(icon.getSize().y, icon.getSize().x, icon.getPixelsPtr());
}

void MemoryGame::Game::InitGame()
{
	this->_currentScene = &this->_playScene;
	this->_soundController.PlayMusic();
	this->_currentScene->Init();
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
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mousePosition = this->_window->mapPixelToCoords(sf::Mouse::getPosition(*this->_window));

				this->_currentScene->ProcessMouseClick(mousePosition);
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

	this->_currentScene->Render(this->_window);

	this->_window->display();
}

void MemoryGame::Game::Update()
{
	auto elapsedTime = this->_clock.restart().asMilliseconds();

	this->_currentScene->Update((float)elapsedTime);
}