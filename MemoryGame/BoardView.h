#include "SFML/Graphics.hpp"


namespace MemoryGame
{
	class BoardView
	{
	public:
		BoardView();
		~BoardView();

		void Init(sf::RenderWindow* window);

		void Render();

	private:
		sf::RenderWindow* _window;
		sf::Image _backgroundImage;

		void InitBoardTexture();
	};
}