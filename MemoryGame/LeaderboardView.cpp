#include <iostream>

#include "LeaderboardView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

constexpr int PLAYER_TEXT_SIZE = 24;
constexpr int PLAYER_TEXT_OFFSET = 45;
constexpr int PLAYER_TEXT_OFFSET_X = 25;
constexpr int PLAYER_TEXT_OFFSET_Y = 20;


MemoryGame::LeaderboardView::LeaderboardView()
{

}

MemoryGame::LeaderboardView::~LeaderboardView()
{

}

void MemoryGame::LeaderboardView::Init(int numberOfPlayers)
{
	this->InitPlayerTexts(numberOfPlayers);
	this->SetTextPositions();
}

void MemoryGame::LeaderboardView::InitPlayerTexts(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; ++i)
	{
		if (!_font.loadFromFile(FONT_FILEPATH))
		{
			std::cout << ERROR_LOADING_FONT << std::endl;
		}

		sf::Text playerText;
		playerText.setFont(_font);
		playerText.setString("Player");
		playerText.setCharacterSize(PLAYER_TEXT_SIZE);
		playerText.setPosition(PLAYER_TEXT_OFFSET_X, PLAYER_TEXT_OFFSET_Y);

		_playerTexts.push_back(playerText);
	}
}

void MemoryGame::LeaderboardView::SetTextPositions()
{
	int offset = 0;
	for (auto &playerText : _playerTexts)
	{
		float x = playerText.getPosition().x;
		float y = playerText.getPosition().y;

		playerText.setPosition(x, y - offset);

		offset -= PLAYER_TEXT_OFFSET;
	}
}

void MemoryGame::LeaderboardView::UpdatePlayerText(int index, int newScore)
{
	// TODO:
	//_playerTexts[index].setString("Player" + index + 1 + ':' + newScore);
}

void MemoryGame::LeaderboardView::Render(sf::RenderWindow* window)
{
	for (sf::Text playerText : _playerTexts)
	{
		window->draw(playerText);
	}
}