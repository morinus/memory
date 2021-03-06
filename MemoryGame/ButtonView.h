#ifndef BUTTONVIEW_H
#define BUTTONVIEW_H

#include "SFML/Graphics.hpp"


namespace MemoryGame
{
	class ButtonView
	{
	public:
		ButtonView(sf::Texture* backTexture, sf::Texture* frontTexture, int index);
		~ButtonView();

		void Init(int index);
		void Update(float elapsedTime);
		void Render(std::shared_ptr<sf::RenderWindow> window);

		void SetPosition(sf::Vector2f newPosition);
		void SetScale(sf::Vector2f newScale);
		void SetIsInteractible(bool isInteractible);

		sf::Sprite GetImage();
		int GetIndex() { return _index; }
		bool GetIsInteractible() { return _isInteractible; }

	private:
		void ProcessTurnAnimation(float elapsedTime);
		void ProcessInteractionPaused(float elapsedTime);

		sf::Texture* _backTexture;
		sf::Texture* _frontTexture;
		sf::Sprite _frontSprite;
		sf::Sprite _backSprite;

		int _index;
		bool _isInteractible;
		bool _animationPlaying;
		bool _interactionPaused;

		float _pauseTimeElapsed;
		float _animationTimeElapsed;
	};
}

#endif // BUTTONVIEW_H