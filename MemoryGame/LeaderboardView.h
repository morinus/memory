#ifndef LEADERBOARDVIEW_H
#define LEADERBOARDVIEW_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "GameState.h"

#include <vector>
#include <functional>


namespace MemoryGame
{
	class LeaderboardView
	{
	public:
		LeaderboardView();
		~LeaderboardView();

		void Init(std::vector<Player> players, std::function<void(GameState)> changeGameStateDelegate);
		void Render(std::shared_ptr<sf::RenderWindow> window);
		void ProcessMouseClick(sf::Vector2f mousePosition);

	private:
		void InitBackground();
		void InitFont();
		void InitTexts();
		void InitPlayerTexts(std::vector<Player> players);
		void SetPlayerTextPositions();
		void ChangeGameState();

		sf::Font _font;
		sf::Texture _backgroundTexture;
		sf::Sprite _backgroundSprite;

		sf::Text _titleText;
		sf::Text _playAgainText;
		std::vector<sf::Text> _playerTexts;

		std::function<void(GameState)> _changeSceneDelegate;
	};
}

#endif // LEADERBOARDVIEW_H
