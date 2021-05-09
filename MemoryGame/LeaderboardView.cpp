#include <iostream>
#include <string>

#include "LeaderboardView.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

constexpr int PLAYER_TEXT_SIZE = 30;
constexpr int PLAYER_TEXT_OFFSET = 55;
constexpr int PLAYER_TEXT_OFFSET_X = 35;
constexpr int PLAYER_TEXT_OFFSET_Y = 100;
constexpr int LEADERBOARD_TITLE_TEXT_OFFSET_X = 20;
constexpr int LEADERBOARD_TITLE_TEXT_OFFSET_Y = 25;


MemoryGame::LeaderboardView::LeaderboardView()
{
	if (!_font.loadFromFile(FONT_FILEPATH))
	{
		std::cout << ERROR_LOADING_FONT << std::endl;
	}
}

MemoryGame::LeaderboardView::~LeaderboardView()
{

}

void MemoryGame::LeaderboardView::Init(int numberOfPlayers)
{
	this->InitPlayerTexts(numberOfPlayers);
	this->InitLeaderboardTitleText();

	this->SetPlayerTextPositions();

	this->ColorCurrentPlayerText(0);
}

void MemoryGame::LeaderboardView::InitPlayerTexts(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; ++i)
	{
		sf::Text playerText;
		playerText.setFont(_font);
		playerText.setString("Player " + std::to_string(i + 1) + ": 0");
		playerText.setCharacterSize(PLAYER_TEXT_SIZE);
		playerText.setPosition(PLAYER_TEXT_OFFSET_X, PLAYER_TEXT_OFFSET_Y);

		_playerTexts.push_back(playerText);
	}
}

void MemoryGame::LeaderboardView::InitLeaderboardTitleText()
{
	this->_leaderboardTitleText.setFont(this->_font);
	this->_leaderboardTitleText.setString("SCORES:");
	this->_leaderboardTitleText.setCharacterSize(48);
	this->_leaderboardTitleText.setPosition(LEADERBOARD_TITLE_TEXT_OFFSET_X, LEADERBOARD_TITLE_TEXT_OFFSET_Y);
}

void MemoryGame::LeaderboardView::SetPlayerTextPositions()
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

void MemoryGame::LeaderboardView::ColorCurrentPlayerText(int index)
{
	int lastPlayerIndex = index != 0 ? index - 1 : _playerTexts.size() - 1;

	this->_playerTexts[lastPlayerIndex].setFillColor(sf::Color::White);
	this->_playerTexts[index].setFillColor(sf::Color::Green);
}

void MemoryGame::LeaderboardView::Render(sf::RenderWindow* window)
{
	window->draw(_leaderboardTitleText);

	for (sf::Text playerText : _playerTexts)
	{
		window->draw(playerText);
	}
}