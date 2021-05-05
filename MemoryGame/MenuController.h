#include "MenuView.h"


namespace MemoryGame
{
	class MenuController
	{
	public:
		MenuController();
		~MenuController();

		bool IsActive();
		void Render(sf::RenderWindow* window);

	private:
		bool _isActive;

		MenuView _menuView;
	};
}