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
		void Render(sf::RenderWindow* window);
		void Update();

	private:
		void InitPlayers(int numberOfPlayers);
		void InitCards(int numberOfCardPairs);
		void ProcessCurrentlySelectedCards();
		void DeselectEverything();
		void UpdateCurrentPlayerText();
		void ChangePlayerTurn();

		BoardView _boardView;
		LeaderboardView _leaderboardView;

		std::vector<MemoryGame::Player> _players;
		std::vector<MemoryGame::Card> _cards;

		int _firstSelectedCardIndex;
		int _secondSelectedCardIndex;
		int _currentPlayerIndex;
	};
}

#endif // BOARDCONTROLLER.H