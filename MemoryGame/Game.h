#include <SFML/Graphics.hpp>

namespace MemoryGame
{
	class Game
	{
	public:
		void PoolEvents();
		void Render();

		const bool GetWindowIsOpen();

		Game();
		~Game();


	private:
		void InitWindow();

		sf::RenderWindow* _window;
	};
}