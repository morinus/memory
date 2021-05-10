#include "BoardController.h"
#include "stdlib.h"

constexpr int NUMBER_OF_CARD_TYPES = 4;


MemoryGame::BoardController::BoardController()
{

}

MemoryGame::BoardController::~BoardController()
{

}

void MemoryGame::BoardController::InitBoard(int numberOfPlayers, int numberOfCardPairs)
{
	this->InitPlayers(numberOfPlayers);
	this->InitCards(numberOfCardPairs);

	this->_leaderboardView.Init(this->_players);
	this->_boardView.Init(this->_cards);
}

void MemoryGame::BoardController::InitPlayers(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; ++i)
	{
		std::string playerName = "Player" + std::to_string(i);
		Player player(playerName);

		this->_players.push_back(player);
	}
}

void MemoryGame::BoardController::InitCards(int numberOfCardPairs)
{
	for (int i = 0; i < numberOfCardPairs; i += 2)
	{
		CardType cardType = CardType(std::rand() % NUMBER_OF_CARD_TYPES);
		Card card(cardType);

		// We need two of the same type of cards
		this->_cards.push_back(card);
		this->_cards.push_back(card);
	}
}

void MemoryGame::BoardController::Render(sf::RenderWindow* window)
{
	this->_boardView.Render(window);
	this->_leaderboardView.Render(window);
}

void MemoryGame::BoardController::Update()
{

}