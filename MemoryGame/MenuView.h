#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "SFML/Graphics.hpp"

namespace MemoryGame
{
	class MenuView
	{
	public:
		MenuView();
		~MenuView();

		void Render(std::shared_ptr<sf::RenderWindow> window);
		void Update(float elapsedTime);

	private:
		void InitBoardBackground();

		sf::Texture _backgroundTexture;
		sf::Sprite _backgroundImage;
	};
}

#endif // MENUVIEW_H