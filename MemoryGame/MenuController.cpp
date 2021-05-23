#include "MenuController.h"

constexpr int MINIMUM_NUMBER_OF_PLAYERS = 2;
constexpr int MINIMUM_NUMBER_OF_CARDS = 2;
constexpr int INCREMENTAL_STEP_FOR_CARDS = 2;


enum MenuViewButton
{
	PLAYERS_LEFT_BUTTON = 0,
	PLAYERS_RIGHT_BUTTON = 1,
	CARDS_LEFT_BUTTON = 2,
	CARDS_RIGHT_BUTTON = 3,
	PLAY_BUTTON = 4
};

MemoryGame::MenuController::MenuController()
{

}

MemoryGame::MenuController::~MenuController()
{

}

void MemoryGame::MenuController::InitMenu(std::shared_ptr<GameSettings> gameSettings)
{
	this->_gameSettings = gameSettings;
}

void MemoryGame::MenuController::Render(std::shared_ptr<sf::RenderWindow> window)
{
	this->_menuView.Render(window);
}

void MemoryGame::MenuController::Update(float elapsedTime)
{
	//this->_menuView.Update(elapsedTime);
}

void MemoryGame::MenuController::ProcessMouseClick(sf::Vector2f mousePosition)
{
	auto menuViewButtonType = this->_menuView.GetSelectedButtonType(mousePosition);

	switch (menuViewButtonType)
	{
	case MenuViewButton::PLAYERS_LEFT_BUTTON:
		this->DecreaseNumberOfPlayers();
		break;
	case MenuViewButton::PLAYERS_RIGHT_BUTTON:
		this->IncreaseNumberOfPlayers();
		break;
	case MenuViewButton::CARDS_LEFT_BUTTON:
		this->DecreaseNumberOfCards();
		break;
	case MenuViewButton::CARDS_RIGHT_BUTTON:
		this->IncreaseNumberOfCards();
		break;
	case MenuViewButton::PLAY_BUTTON:
		this->ProcessPlayGameAction();
		break;
	}
}

void MemoryGame::MenuController::SetChangeGameStateDelegate(std::function<void(GameState)> changeGameStateDelegate)
{
	this->_changeGameStateDelegate = changeGameStateDelegate;
}

void MemoryGame::MenuController::IncreaseNumberOfPlayers()
{
	this->_gameSettings->NumberOfPlayers++;
	this->_menuView.UpdateNumberOfPlayers(this->_gameSettings->NumberOfPlayers);
}

void MemoryGame::MenuController::DecreaseNumberOfPlayers()
{
	if (this->_gameSettings->NumberOfPlayers > MINIMUM_NUMBER_OF_PLAYERS)
	{
		this->_gameSettings->NumberOfPlayers--;
		this->_menuView.UpdateNumberOfPlayers(this->_gameSettings->NumberOfPlayers);
	}
}

void MemoryGame::MenuController::IncreaseNumberOfCards()
{
	this->_gameSettings->NumberOfCards += INCREMENTAL_STEP_FOR_CARDS;
	this->_menuView.UpdateNumberOfCards(this->_gameSettings->NumberOfCards);
}

void MemoryGame::MenuController::DecreaseNumberOfCards()
{
	if (this->_gameSettings->NumberOfCards > MINIMUM_NUMBER_OF_CARDS)
	{
		this->_gameSettings->NumberOfCards -= INCREMENTAL_STEP_FOR_CARDS;
		this->_menuView.UpdateNumberOfCards(this->_gameSettings->NumberOfCards);
	}
}

void MemoryGame::MenuController::ProcessPlayGameAction()
{
	this->_changeGameStateDelegate(GameState::PLAY_SCENE);
}