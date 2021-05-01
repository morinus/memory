#include <SFML/Graphics.hpp>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define WINDOW_TITLE "Memory Game"

namespace MemoryGame
{
	class GameController
	{
	public:
		void PoolEvents();
		void Render();

		const bool GetWindowIsOpen();

		GameController();
		~GameController();


	private:
		void InitWindow();

		sf::RenderWindow* _window;
	};
}