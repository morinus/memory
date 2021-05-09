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

		void InitBoard(int numberOfPlayers, int numberOfCardPairs);
		void Render(sf::RenderWindow* window);
		void Update();

	private:
		void InitPlayers(int numberOfPlayers);
		void InitCards(int numberOfCardPairs);

		BoardView _boardView;
		LeaderboardView _leaderboardView;

		std::vector<MemoryGame::Player> _players;
		std::vector<MemoryGame::Card> _cards;
	};
}

#endif // BOARDCONTROLLER.H