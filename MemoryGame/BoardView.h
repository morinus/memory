#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "SFML/Graphics.hpp"

#include "Card.h"


namespace MemoryGame
{
	class BoardView
	{
	public:
		BoardView();
		~BoardView();

		void Init(int numberOfCards);

		void Render(sf::RenderWindow* window);

	private:
		sf::Texture _backgroundTexture;
		sf::Sprite _backgroundImage;
		std::vector<MemoryGame::Card> _cards;

		void InitBoardBackground();
		void InitCards(int numberOfCards);
	};
}

#endif // BOARDVIEW_H