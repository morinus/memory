#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "SFML/Graphics.hpp"

namespace MemoryGame
{
	class BoardView
	{
	public:
		BoardView();
		~BoardView();

		void Init();

		void Render(sf::RenderWindow* window);

	private:
		sf::Texture _backgroundTexture;
		sf::Sprite _backgroundImage;

		void InitBoardBackground();
	};
}

#endif // BOARDVIEW_H