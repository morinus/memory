#include "PlayerFactory.h"


MemoryGame::PlayerFactory::PlayerFactory()
{

}

MemoryGame::PlayerFactory::~PlayerFactory()
{

}

std::vector<MemoryGame::Player> MemoryGame::PlayerFactory::CreatePlayers(int numberOfPlayers)
{
	std::vector<MemoryGame::Player> players;

	for (int i = 0; i < numberOfPlayers; ++i)
	{
		Player newPlayer = Player("Player" + i + 1);
		newPlayer.SetScore(0);

		players.push_back(newPlayer);
	}

	return players;
}