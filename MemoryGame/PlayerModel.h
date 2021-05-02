#include <iostream>


namespace MemoryGame
{
	class PlayerModel
	{
	public:
		PlayerModel(std::string name);
		~PlayerModel();

		const int GetScore();
		void SetScore(int newScore);

		const std::string GetName();

	private:
		int _score;
		std::string _name;

	};
}