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
		void InitBoard(int numberOfPlayers, int numberOfCardPairs);
		void Render(sf::RenderWindow* window);
		void Update();

		BoardController();
		~BoardController();

	private:
		BoardView _boardView;
		LeaderboardView _leaderboardView;

		std::vector<MemoryGame::Player> _players;
	};
}

#endif // BOARDCONTROLLER.H