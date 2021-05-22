#include "SFML/Graphics.hpp"

#include "PlayScene.h"

#include "BoardController.h"
#include "SoundController.h"


namespace MemoryGame
{
	enum GameState
	{
		MENU_SCENE = 1,
		PLAY_SCENE = 2,
		LEADERBOARD_SCENE = 3
	};

	class Game
	{
	public:
		Game();
		~Game();

		void Play();
		std::shared_ptr<sf::RenderWindow> GetWindow() { return _window; }

	private:
		void InitWindow();
		void InitGame();

		void ProcessInput();
		void Update();
		void Render();

		MemoryGame::SoundController _soundController;

		GameScene* _currentScene;
		PlayScene _playScene;

		GameState _currentGameState;
		std::shared_ptr<sf::RenderWindow> _window;
		sf::Clock _clock;
	};
}