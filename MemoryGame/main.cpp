#include "SFML/Audio.hpp"

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
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

	// Music
	//soundController.PlayMusic();

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