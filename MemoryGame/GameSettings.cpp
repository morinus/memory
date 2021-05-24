#include "GameSettings.h"

MemoryGame::GameSettings::GameSettings(int numberOfPlayers, int width, int height)
{
	this->NumberOfPlayers = numberOfPlayers;
	this->Width = width;
	this->Height = height;
}

MemoryGame::GameSettings::~GameSettings()
{

}
