#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"

#include "LeaderboardScene.h"
#include "MenuScene.h"
#include "PlayScene.h"

#include "BoardController.h"
#include "SoundController.h"

#include "GameSettings.h"
#include "GameState.h"

namespace MemoryGame
{
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
		LeaderboardScene _leaderboardScene;
		MenuScene _menuScene;
		PlayScene _playScene;

		GameState _currentGameState;
		std::shared_ptr<sf::RenderWindow> _window;
		sf::Clock _clock;

		std::shared_ptr<GameSettings> _gameSettings;
	};
}

#endif // GAME_H