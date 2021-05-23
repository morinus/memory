#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "MenuView.h"
#include "GameSettings.h"


namespace MemoryGame
{
	class MenuController
	{
	public:
		MenuController();
		~MenuController();

		void InitMenu(std::shared_ptr<GameSettings> gameSettings);
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

		std::shared_ptr<GameSettings> _gameSettings;
	};
}

#endif // MENUCONTROLLER_H