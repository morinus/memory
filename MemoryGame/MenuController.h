#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "MenuView.h"
#include "GameSettings.h"
#include "GameState.h"

#include <functional>


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
		void SetChangeGameStateDelegate(std::function<void(GameState)> changeGameStateDelegate);

	private:
		void ChangeNumberOfPlayers(bool isIncreased);
		void ChangeBoardHeight(bool isIncreased);
		void ChangeBoardWidth(bool isIncreased);
		void ProcessPlayGameAction();

		MenuView _menuView;

		std::shared_ptr<GameSettings> _gameSettings;
		std::function<void(GameState)> _changeGameStateDelegate;
	};
}

#endif // MENUCONTROLLER_H