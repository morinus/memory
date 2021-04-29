#include <SFML/Graphics.hpp>


class Game
{
public:
	void PoolEvents();
	void Render();

	const bool GetWindowIsOpen();

	Game();
	~Game();


private:
	void InitWindow();

	sf::RenderWindow* _window;
};