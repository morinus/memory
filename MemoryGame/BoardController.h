#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H

#include "BoardView.h"
#include "ScoresView.h"
#include "Player.h"
#include "GameState.h"
#include "GameSettings.h"

#include <functional>


namespace MemoryGame
{
	class BoardController
	{
	public:
		BoardController();
		~BoardController();

		void InitBoard(std::shared_ptr<GameSettings> gameSettings);
		void ProcessMouseClick(sf::Vector2f mousePosition);
		void ResetGame();
		void Render(std::shared_ptr<sf::RenderWindow> window);
		void Update(float elapsedTime);
		void SetChangeGameStateDelegate(std::function<void(GameState)> changeGameStateDelegate);

	private:
		void InitPlayers(int numberOfPlayers);
		void InitCards(int boardWidth, int boardHeight);
		void ProcessCurrentlySelectedCards();
		void DeselectEverything();
		void UpdateCurrentPlayerText();
		void ChangePlayerTurn();
		bool CheckIfGameOver();

		BoardView _boardView;
		ScoresView _scoresView;

		std::shared_ptr<GameSettings> _gameSettings;
		std::vector<MemoryGame::Player> _players;
		std::vector<MemoryGame::Card> _cards;

		int _firstSelectedCardIndex;
		int _secondSelectedCardIndex;
		int _currentPlayerIndex;
		bool _isGameOver;

		std::function<void(GameState)> _changeGameStateDelegate;
	};
}

#endif // BOARDCONTROLLER.H