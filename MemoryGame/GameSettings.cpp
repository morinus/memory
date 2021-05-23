#include "GameSettings.h"

MemoryGame::GameSettings::GameSettings(int numberOfPlayers, int numberOfCards)
{
	this->NumberOfPlayers = numberOfPlayers;
	this->NumberOfCards = numberOfCards;
}

MemoryGame::GameSettings::~GameSettings()
{

}
