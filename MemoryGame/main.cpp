// Controllers
#include "BoardController.h"
#include "MenuController.h"

// Consts
constexpr auto WINDOW_HEIGHT = 600;
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_TITLE = "Memory Game";


int main()
{
	MemoryGame::BoardController boardController;
	MemoryGame::MenuController menuController;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

	while (window.isOpen())
	{
		// Event Pooling
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Rendering
		window.clear();

		boardController.Render(&window);
		menuController.Render(&window);

		window.display();
	}

	return 0;
}