#include <iostream>

#include "SoundController.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

MemoryGame::SoundController::SoundController()
{
	if (!_backgroundMusic.openFromFile(MUSIC_FILEPATH))
	{
		std::cout << ERROR_LOADING_MUSIC_FILE << std::endl;
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