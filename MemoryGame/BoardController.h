#ifndef  BOARDCONTROLLER_H
#define BOARDCONTROLLER_H

#include "BoardView.h"

namespace MemoryGame
{
	class BoardController
	{
	public:
		void InitBoard(int numberOfPlayers, int numberOfCardPairs);
		void Render(sf::RenderWindow* window);

		BoardController();
		~BoardController();

	private:
		int numberOfPlayers;
		int numberOfCardPairs;

		BoardView _boardView;
	};
}

#endif // BOARDCONTROLLER.H