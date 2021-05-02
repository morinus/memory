#include <SFML/Graphics.hpp>

#include "BoardController.h"


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
		BoardController _boardController;

		sf::RenderWindow* _window;

		void InitWindow();

	};
}