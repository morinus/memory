#include <iostream>

#include "SFML/Audio.hpp"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

// Controllers
#include "BoardController.h"
#include "MenuController.h"
#include "SoundController.h"

// Consts
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto WINDOW_WIDTH = 1024;
constexpr auto WINDOW_TITLE = "Memory Game";


int main()
{
	MemoryGame::BoardController boardController;
	MemoryGame::MenuController menuController;
	MemoryGame::SoundController soundController;

	// Render Window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close);

	// Render Window Icon
	sf::Image icon;
	if (!icon.loadFromFile(WINDOW_ICON_FILEPATH))
	{
		std::cout << ERROR_LOADING_WINDOW_ICON << std::endl;
	}

	window.setIcon(icon.getSize().y, icon.getSize().x, icon.getPixelsPtr());

	boardController.InitBoard(3, 1);

	// Music
	soundController.PlayMusic();

	while (window.isOpen())
	{
		// Event Pooling
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();

				return 0;
			}
		}

		// Button Update


		// Render
		window.clear();

		boardController.Render(&window);
		menuController.Render(&window);

		window.display();
	}

	return 0;
}