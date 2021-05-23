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

		void InitMenu();
		void Render(std::shared_ptr<sf::RenderWindow> window);
		void Update(float elapsedTime);
		void ProcessMouseClick(sf::Vector2f mousePosition);

	private:
		void IncreaseNumberOfPlayers();
		void DecreaseNumberOfPlayers();
		void IncreaseNumberOfCards();
		void DecreaseNumberOfCards();
		void ProcessPlayGameAction();

		MenuView _menuView;

		int _numberOfPlayers;
		int _numberOfCards;
	};
}

#endif // MENUCONTROLLER_H