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
		void StopPlayingMusic();

	private:
		sf::Music _backgroundMusic;

	};
}

#endif // SOUNDCONTROLLER_H