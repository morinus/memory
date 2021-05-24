#ifndef LEADERBOARDCONTROLLER_H
#define LEADERBOARDCONTROLLER_H

#include "LeaderboardView.h"

namespace MemoryGame
{
	class LeaderboardController
	{
	public:
		LeaderboardController();
		~LeaderboardController();

	private:
		LeaderboardView _leaderboardView;
	};
}

#endif // LEADERBOARDCONTROLLER_H
