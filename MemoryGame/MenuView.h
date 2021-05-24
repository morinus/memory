#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "SFML/Graphics.hpp"
#include "GameSettings.h"

#include <functional>


namespace MemoryGame
{
	class MenuView
	{
	public:
		MenuView();
		~MenuView();

		void Render(std::shared_ptr<sf::RenderWindow> window);

		void Init(std::shared_ptr<GameSettings> gameSettings);
		void ProcessMouseClick(sf::Vector2f mousePosition);
		void UpdateNumberOfPlayers(int numberOfPlayers);
		void UpdateHeight(int newHeight);
		void UpdateWidth(int newWidth);
		void SetChangeNumberOfPlayersDelegate(std::function<void(bool)> changeNumberOfPlayersDelegate);
		void SetChangeBoardHeightDelegate(std::function<void(bool)> changeBoardHeightDelegate);
		void SetChangeBoardWidthDelegate(std::function<void(bool)> changeBoardWidthDelegate);
		void SetChangePlayButtonDelegate(std::function<void()> playButtonDelegate);

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
		sf::Sprite _widthLeftButtonSprite;
		sf::Sprite _widthRightButtonSprite;
		sf::Sprite _heightLeftButtonSprite;
		sf::Sprite _heightRightButtonSprite;

		sf::Font _font;

		sf::Text _sceneTitleText;
		sf::Text _numberOfPlayersText;
		sf::Text _numberOfPlayersTitleText;
		sf::Text _widthText;
		sf::Text _widthTitleText;
		sf::Text _heightText;
		sf::Text _heightTitleText;
		sf::Text _playText;

		std::function<void(bool)> _changeNumberOfPlayersDelegate;
		std::function<void(bool)> _changeBoardWidthDelegate;
		std::function<void(bool)> _changeBoardHeightDelegate;
		std::function<void()> _playGameDelegate;

		bool _isInited;
	};
}

#endif // MENUVIEW_H