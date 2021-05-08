#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"


namespace MemoryGame
{
	enum ButtonState
	{
		NORMAL = 0,
		HOVERED = 1,
		CLICKED = 2
	};

	class Button
	{
	public:
		Button();
		~Button();

		void Init();
		void Update(sf::Event e);

		sf::Vector2f GetPosition() { return _position; }
		sf::Vector2f SetPosition(sf::Vector2f newPosition) { _position = newPosition; }

	private:
		sf::Vector2f _position;
		ButtonState _state;

	};
}

#endif // BUTTON_H