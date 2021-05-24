#ifndef LEADERBOARDCONTROLLER_H
#define LEADERBOARDCONTROLLER_H

#include "LeaderboardView.h"
#include "Player.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"

#include <vector>
#include <functional>


namespace MemoryGame
{
	class LeaderboardController
	{
	public:
		LeaderboardController();
		~LeaderboardController();

		void Init(std::vector<Player> players, std::function<void(GameState)> changeGameStateDelegate);
		void Render(std::shared_ptr<sf::RenderWindow> window);
		void ProcessMouseClick(sf::Vector2f mousePosition);

	private:
		LeaderboardView _leaderboardView;
	};
}

#endif // LEADERBOARDCONTROLLER_H
