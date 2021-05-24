#ifndef SCORESVIEW_H
#define SCORESVIEW_H

#include "SFML/Graphics.hpp"

#include "Player.h"


namespace MemoryGame
{
	class ScoresView
	{
	public:
		ScoresView();
		~ScoresView();

		void Init(std::vector<Player> players);
		void UpdatePlayerText(int index, sf::String newString);
		void ColorCurrentPlayerText(int playerIndex);
		void Render(std::shared_ptr<sf::RenderWindow> window);

	private:
		void InitFont();
		void InitPlayerTexts(std::vector<Player> players);
		void InitLeaderboardTitleText();
		void SetPlayerTextPositions();

		sf::Font _font;
		sf::Text _leaderboardTitleText;
		std::vector<sf::Text> _playerTexts;
	};
}

#endif // SCORESVIEW_H