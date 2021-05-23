#include "SFML/Graphics.hpp"

#include "MenuScene.h"
#include "PlayScene.h"

#include "BoardController.h"
#include "SoundController.h"

#include "GameSettings.h"

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
		void ChangeGameState(GameState newGameState);
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
		MenuScene _menuScene;

		GameState _currentGameState;
		std::shared_ptr<sf::RenderWindow> _window;
		sf::Clock _clock;

		std::shared_ptr<GameSettings> _gameSettings;
	};
}