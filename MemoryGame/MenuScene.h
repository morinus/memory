#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "MenuController.h"
#include "GameScene.h"

class Game;

namespace MemoryGame
{
	class MenuScene : public GameScene
	{
	public:
		MenuScene();
		~MenuScene();

		virtual void Init() override;
		virtual void Update(float elapsedTime) override;
		virtual void Render(std::shared_ptr<sf::RenderWindow> window) override;
		virtual void ProcessMouseClick(sf::Vector2f mousePosition) override;

	private:
		MenuController _menuController;

	};
}

#endif // MENUSCENE_H
