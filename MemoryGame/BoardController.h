namespace MemoryGame
{
	class BoardController
	{
	public:
		void InitBoard(int numberOfPlayers, int numberOfCardPairs);

		BoardController();
		~BoardController();

	private:
		int numberOfPlayers;
		int numberOfCardPairs;

	};
}