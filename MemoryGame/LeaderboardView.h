#ifndef LEADERBOARDVIEW_H
#define LEADERBOARDVIEW_H

#include "SFML/Graphics.hpp"


namespace MemoryGame
{
	class LeaderboardView
	{
	public:
		LeaderboardView();
		~LeaderboardView();

		void Init(int numberOfPlayers);
		void UpdatePlayerText(int playerIndex, int newScore);
		void Render(sf::RenderWindow* window);

	private:
		void InitPlayerTexts(int numberOfPlayers);
		void SetTextPositions();

		sf::Font _font;
		std::vector<sf::Text> _playerTexts;
	};
}

#endif // LEADERBOARDVIEW_H