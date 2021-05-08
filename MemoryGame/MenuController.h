#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "MenuView.h"

namespace MemoryGame
{
	class MenuController
	{
	public:
		MenuController();
		~MenuController();

		void Render(sf::RenderWindow* window);

	private:

		MenuView _menuView;
	};
}

#endif // MENUVIEW_H