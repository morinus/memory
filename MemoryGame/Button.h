#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"


namespace MemoryGame
{
	class Button
	{
	public:
		Button(sf::Texture* backTexture, sf::Texture* frontTexture, int index);
		~Button();

		void Init(int index);
		void Update(sf::Event e);
		void Render(sf::RenderWindow* window);

		void SetPosition(sf::Vector2f newPosition);
		void SetScale(sf::Vector2f newScale);
		void SetIsInteractible(bool isInteractible);

		sf::Sprite GetImage() { return _image; }
		int GetIndex() { return _index; }
		bool GetIsInteractible() { return _isInteractible; }

	private:
		void SetFrontTexture();
		void SetBackTexture();

		sf::Texture* _backTexture;
		sf::Texture* _frontTexture;
		sf::Sprite _image;

		int _index;
		bool _isInteractible;
	};
}

#endif // BUTTON_H