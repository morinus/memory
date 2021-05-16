#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "SFML/Graphics.hpp"

#include "Card.h"


namespace MemoryGame
{
	class BoardView
	{
	public:
		BoardView();
		~BoardView();

		void Init(std::vector<MemoryGame::Card> cards);
		void DeselectButtons();
		void SetIsInteractible(int index, bool isInteractible);
		void Render(sf::RenderWindow* window);

		int GetSelectedButtonIndex(sf::Vector2f mousePosition);

	private:
		void InitBoardBackground();
		void InitCards(std::vector<MemoryGame::Card> cards);
		void InitTextures();
		void SetupCardButtons();

		sf::Texture* GetTextureByCardType(CardType cardType);

		sf::Texture* _monsterATexture;
		sf::Texture* _monsterBTexture;
		sf::Texture* _monsterCTexture;
		sf::Texture* _monsterDTexture;
		sf::Texture* _cardBackTexture;

		std::vector<Button*> _cardButtons;

		sf::Texture _backgroundTexture;
		sf::Sprite _backgroundImage;
	};
}

#endif // BOARDVIEW_H