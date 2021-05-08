#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

namespace MemoryGame
{
	class Player
	{
	public:
		Player(std::string name);
		~Player();

		const int GetScore();
		void SetScore(int newScore);

		const std::string GetName();

	private:
		int _score;
		std::string _name;

	};
}

#endif // PLAYER_H