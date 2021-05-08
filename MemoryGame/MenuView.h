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

		void Render(sf::RenderWindow* window);

	};
}

#endif // MENUVIEW_H