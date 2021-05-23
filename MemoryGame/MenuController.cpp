#include "MenuController.h"

constexpr int INITIAL_NUMBER_OF_PLAYERS = 5;
constexpr int INITIAL_NUMBER_OF_CARDS = 24;
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
	this->_numberOfPlayers = INITIAL_NUMBER_OF_PLAYERS;
	this->_numberOfCards = INITIAL_NUMBER_OF_CARDS;
}

MemoryGame::MenuController::~MenuController()
{

}

void MemoryGame::MenuController::InitMenu()
{

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

void MemoryGame::MenuController::IncreaseNumberOfPlayers()
{
	this->_numberOfPlayers++;
	this->_menuView.UpdateNumberOfPlayers(this->_numberOfPlayers);
}

void MemoryGame::MenuController::DecreaseNumberOfPlayers()
{
	if (this->_numberOfPlayers > MINIMUM_NUMBER_OF_PLAYERS)
	{
		this->_numberOfPlayers--;
		this->_menuView.UpdateNumberOfPlayers(this->_numberOfPlayers);
	}
}

void MemoryGame::MenuController::IncreaseNumberOfCards()
{
	this->_numberOfCards += INCREMENTAL_STEP_FOR_CARDS;
	this->_menuView.UpdateNumberOfCards(this->_numberOfCards);
}

void MemoryGame::MenuController::DecreaseNumberOfCards()
{
	if (this->_numberOfCards > MINIMUM_NUMBER_OF_CARDS)
	{
		this->_numberOfCards -= INCREMENTAL_STEP_FOR_CARDS;
		this->_menuView.UpdateNumberOfCards(this->_numberOfCards);
	}
}

void MemoryGame::MenuController::ProcessPlayGameAction()
{

}