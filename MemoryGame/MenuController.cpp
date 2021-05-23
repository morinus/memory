#include "MenuController.h"

constexpr int MINIMUM_NUMBER_OF_PLAYERS = 2;
constexpr int MINIMUM_NUMBER_OF_CARDS = 2;
constexpr int INCREMENTAL_STEP_FOR_CARDS = 2;


MemoryGame::MenuController::MenuController()
{
	this->_menuView.SetChangeNumberOfPlayersDelegate([this](bool isIncreased) { ChangeNumberOfPlayers(isIncreased); });
	this->_menuView.SetChangeNumberOfCardsDelegate([this](bool isIncreased) { ChangeNumberOfCards(isIncreased); });
	this->_menuView.SetChangePlayButtonDelegate([this]() { ProcessPlayGameAction(); });
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
	this->_menuView.ProcessMouseClick(mousePosition);
}

void MemoryGame::MenuController::SetChangeGameStateDelegate(std::function<void(GameState)> changeGameStateDelegate)
{
	this->_changeGameStateDelegate = changeGameStateDelegate;
}

void MemoryGame::MenuController::ChangeNumberOfPlayers(bool isIncreased)
{
	if (isIncreased)
	{
		this->_gameSettings->NumberOfPlayers++;
		this->_menuView.UpdateNumberOfPlayers(this->_gameSettings->NumberOfPlayers);
	}
	else
	{
		if (this->_gameSettings->NumberOfPlayers > MINIMUM_NUMBER_OF_PLAYERS)
		{
			this->_gameSettings->NumberOfPlayers--;
			this->_menuView.UpdateNumberOfPlayers(this->_gameSettings->NumberOfPlayers);
		}
	}
}

void MemoryGame::MenuController::ChangeNumberOfCards(bool isIncreased)
{
	if (isIncreased)
	{
		this->_gameSettings->NumberOfCards += INCREMENTAL_STEP_FOR_CARDS;
		this->_menuView.UpdateNumberOfCards(this->_gameSettings->NumberOfCards);
	}
	else
	{
		if (this->_gameSettings->NumberOfCards > MINIMUM_NUMBER_OF_CARDS)
		{
			this->_gameSettings->NumberOfCards -= INCREMENTAL_STEP_FOR_CARDS;
			this->_menuView.UpdateNumberOfCards(this->_gameSettings->NumberOfCards);
		}
	}
}

void MemoryGame::MenuController::ProcessPlayGameAction()
{
	this->_changeGameStateDelegate(GameState::PLAY_SCENE);
}