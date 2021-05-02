#include "BoardView.h"


namespace MemoryGame
{
	class BoardController
	{
	public:
		void Init(sf::RenderWindow* window);
		void InitBoard(int numberOfPlayers, int numberOfCardPairs);
		void Render();

		BoardController();
		~BoardController();

	private:
		int numberOfPlayers;
		int numberOfCardPairs;

		BoardView _boardView;
	};
}