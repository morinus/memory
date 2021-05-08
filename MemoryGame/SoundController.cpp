#include "SoundController.h"

MemoryGame::SoundController::SoundController()
{
	if (!_backgroundMusic.openFromFile("../Sounds/Jorge Hernandez - Chopsticks.ogg"))
	{
		// error
	}

	_backgroundMusic.setLoop(true);
}

MemoryGame::SoundController::~SoundController()
{

}

void MemoryGame::SoundController::PlayMusic()
{
	_backgroundMusic.play();
}

void MemoryGame::SoundController::StopPlayingMusic()
{
	_backgroundMusic.stop();
}