#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

#include "SFML/Audio.hpp"


namespace MemoryGame
{
	class SoundController
	{
	public:
		SoundController();
		~SoundController();

		void PlayMusic();
		void PlayMouseClickSound();
		void StopPlayingMusic();

	private:
		void InitBackgroundMusic();
		void InitMouseClickSound();

		sf::SoundBuffer _mouseClickSoundBuffer;
		sf::Sound _mouseClickSound;
		sf::Music _backgroundMusic;
	};
}

#endif // SOUNDCONTROLLER_H