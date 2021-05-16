#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H

#include "BoardView.h"
#include "LeaderboardView.h"
#include "Player.h"


namespace MemoryGame
{
	class BoardController
	{
	public:
		BoardController();
		~BoardController();

		void InitBoard(int numberOfPlayers, int numberOfCards);
		void ProcessMouseClick(sf::Vector2f mousePosition);
		void Render(std::shared_ptr<sf::RenderWindow> window);
		void Update(float elapsedTime);

	private:
		void InitPlayers(int numberOfPlayers);
		void InitCards(int numberOfCardPairs);
		void ProcessCurrentlySelectedCards();
		void DeselectEverything();
		void UpdateCurrentPlayerText();
		void ChangePlayerTurn();
		bool CheckIfGameOver();

		BoardView _boardView;
		LeaderboardView _leaderboardView;

		std::vector<MemoryGame::Player> _players;
		std::vector<MemoryGame::Card> _cards;

		int _firstSelectedCardIndex;
		int _secondSelectedCardIndex;
		int _currentPlayerIndex;
		bool _isGameOver;
	};
}

#endif // BOARDCONTROLLER.H