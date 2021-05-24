#ifndef LEADERBOARDSCENE_H
#define LEADERBOARDSCENE_H

#include "LeaderboardController.h"
#include "GameScene.h"

class Game;

namespace MemoryGame
{
	class LeaderboardScene : public GameScene
	{
	public:
		LeaderboardScene();
		~LeaderboardScene();

		virtual void Init(std::shared_ptr<GameSettings> gameSettings, std::function<void(GameState)> changeGameStateDelegate) override;
		virtual void Update(float elapsedTime) override;
		virtual void Render(std::shared_ptr<sf::RenderWindow> window) override;
		virtual void ProcessMouseClick(sf::Vector2f mousePosition) override;

	private:
		LeaderboardController _leaderboardController;

	};
}

#endif // LEADERBOARDSCENE_H
