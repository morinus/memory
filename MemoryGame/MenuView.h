#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "SFML/Graphics.hpp"

namespace MemoryGame
{
	class MenuView
	{
	public:
		MenuView();
		~MenuView();

		void Render(std::shared_ptr<sf::RenderWindow> window);

		int GetSelectedButtonType(sf::Vector2f mousePosition);
		void UpdateNumberOfPlayers(int numberOfPlayers);
		void UpdateNumberOfCards(int numberOfCards);

	private:
		void InitBoardBackground();
		void InitButtons();
		void InitButton(sf::Sprite* button, sf::Vector2f position, sf::Vector2f scale);
		void InitTexts();
		void InitText(sf::Text* text, std::string textString, sf::Vector2f position, int characterSize, sf::Color fillColor = sf::Color::White);

		sf::Texture _backgroundTexture;
		sf::Texture _buttonArrowTexture;
		sf::Sprite _backgroundSprite;
		sf::Sprite _playersLeftButtonSprite;
		sf::Sprite _playersRightButtonSprite;
		sf::Sprite _cardsLeftButtonSprite;
		sf::Sprite _cardsRightButtonSprite;

		sf::Font _font;

		sf::Text _sceneTitleText;
		sf::Text _numberOfPlayersText;
		sf::Text _numberOfCardsText;
		sf::Text _playText;
	};
}

#endif // MENUVIEW_H