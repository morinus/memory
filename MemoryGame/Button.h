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
		Button(sf::Texture* backTexture, sf::Texture* frontTexture, int index);
		~Button();

		void Init(int index);
		void Update(sf::Event e);
		void Render(sf::RenderWindow* window);

		void ChangeButtonState(ButtonState newState);
		void ResetButtonState();

		void SetPosition(sf::Vector2f newPosition);
		void SetScale(sf::Vector2f newScale);

	private:
		ButtonState _state;

		sf::Texture* _backTexture;
		sf::Texture* _frontTexture;
		sf::Sprite _image;

		int _index;
	};
}

#endif // BUTTON_H