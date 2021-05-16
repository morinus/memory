#include <iostream>

#include "SoundController.h"
#include "ErrorMessageStrings.h"
#include "ResourceLocator.h"

constexpr int MOUSECLICK_VOLUME = 50;


MemoryGame::SoundController::SoundController()
{
	try
	{
		this->InitBackgroundMusic();
		this->InitMouseClickSound();
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}
}

MemoryGame::SoundController::~SoundController()
{

}

void MemoryGame::SoundController::InitBackgroundMusic()
{
	if (!_backgroundMusic.openFromFile(BACKGROUND_MUSIC_FILEPATH))
	{
		throw(ERROR_LOADING_AUDIO_FILE);
	}

	_backgroundMusic.setLoop(true);
}

void MemoryGame::SoundController::InitMouseClickSound()
{
	if (!_mouseClickSoundBuffer.loadFromFile(SOUND_MOUSECLICK_FILEPATH))
	{
		throw(ERROR_LOADING_AUDIO_FILE);
	}

	_mouseClickSound.setBuffer(_mouseClickSoundBuffer);
	_mouseClickSound.setVolume(MOUSECLICK_VOLUME);
}

void MemoryGame::SoundController::PlayMusic()
{
	_backgroundMusic.play();
}

void MemoryGame::SoundController::PlayMouseClickSound()
{
	_mouseClickSound.play();
}

void MemoryGame::SoundController::StopPlayingMusic()
{
	_backgroundMusic.stop();
}