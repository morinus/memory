#include "SFML/Graphics.hpp"

#include "BoardController.h"
#include "MenuController.h"
#include "SoundController.h"


namespace MemoryGame
{
	class Game
	{
	public:
		Game();
		~Game();

		void Play();
		sf::RenderWindow* GetWindow();

	private:
		MemoryGame::BoardController _boardController;
		MemoryGame::MenuController _menuController;
		MemoryGame::SoundController _soundController;

		sf::RenderWindow* _window;

		void InitWindow();
		void InitGame();

		void ProcessInput();
		void Update();
		void Render();
	};
}