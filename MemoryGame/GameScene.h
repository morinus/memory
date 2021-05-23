#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "SFML/Graphics.hpp"
#include "GameSettings.h"
#include "GameState.h"

#include <functional>


namespace MemoryGame
{
	class GameScene
	{
	public:
		virtual void Init(std::shared_ptr<GameSettings> gameSettings, std::function<void(GameState)> changeGameStateDelegate) = 0;
		virtual void Update(float elapsedTime) = 0;
		virtual void Render(std::shared_ptr<sf::RenderWindow> window) = 0;
		virtual void ProcessMouseClick(sf::Vector2f mousePosition) = 0;
	};
}

#endif // GAMESCENE_H

