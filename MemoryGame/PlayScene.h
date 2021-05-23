#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "BoardController.h"
#include "GameScene.h"
#include "GameSettings.h"


namespace MemoryGame
{
	class PlayScene : public GameScene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Init(std::shared_ptr<GameSettings> gameSettings) override;
		virtual void Update(float elapsedTime) override;
		virtual void Render(std::shared_ptr<sf::RenderWindow> window) override;
		virtual void ProcessMouseClick(sf::Vector2f mousePosition) override;

	private:

		BoardController _boardController;
	};
}

#endif // PLAYSCENE_H
