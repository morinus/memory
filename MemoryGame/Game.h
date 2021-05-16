#include "SFML/Graphics.hpp"

#include "BoardController.h"
#include "SoundController.h"


namespace MemoryGame
{
	class Game
	{
	public:
		Game();
		~Game();

		void Play();
		std::shared_ptr<sf::RenderWindow> GetWindow() { return _window; }

	private:
		MemoryGame::BoardController _boardController;
		MemoryGame::SoundController _soundController;

		std::shared_ptr<sf::RenderWindow> _window;
		sf::Clock _clock;

		void InitWindow();
		void InitGame();

		void ProcessInput();
		void Update();
		void Render();
	};
}