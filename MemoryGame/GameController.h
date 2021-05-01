#include <SFML/Graphics.hpp>


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