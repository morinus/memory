#ifndef LEADERBOARDCONTROLLER_H
#define LEADERBOARDCONTROLLER_H

#include "LeaderboardView.h"
#include "Player.h"

#include <vector>


namespace MemoryGame
{
	class LeaderboardController
	{
	public:
		LeaderboardController();
		~LeaderboardController();

		void Init(std::vector<Player> players);

	private:
		LeaderboardView _leaderboardView;
	};
}

#endif // LEADERBOARDCONTROLLER_H
