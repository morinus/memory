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

		void Init(std::vector<MemoryGame::Card> cards);

		void Render(sf::RenderWindow* window);

	private:
		sf::Texture _backgroundTexture;
		sf::Sprite _backgroundImage;

		void InitBoardBackground();
		void InitCards(std::vector<MemoryGame::Card> cards);
	};
}

#endif // BOARDVIEW_H