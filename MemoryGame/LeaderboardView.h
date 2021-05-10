#ifndef LEADERBOARDVIEW_H
#define LEADERBOARDVIEW_H

#include "SFML/Graphics.hpp"

#include "Player.h"


namespace MemoryGame
{
	class LeaderboardView
	{
	public:
		LeaderboardView();
		~LeaderboardView();

		void Init(std::vector<Player> players);
		void UpdatePlayerText(int playerIndex, int newScore);
		void ColorCurrentPlayerText(int playerIndex);
		void Render(sf::RenderWindow* window);

	private:
		void InitPlayerTexts(std::vector<Player> players);
		void InitLeaderboardTitleText();
		void SetPlayerTextPositions();

		sf::Font _font;
		sf::Text _leaderboardTitleText;
		std::vector<sf::Text> _playerTexts;
	};
}

#endif // LEADERBOARDVIEW_H