#include "MenuController.h"

constexpr int MINIMUM_NUMBER_OF_PLAYERS = 2;
constexpr int MINIMUM_WIDTH = 1;
constexpr int MINIMUM_HEIGHT = 1;


MemoryGame::MenuController::MenuController()
{
	this->_menuView.SetChangeNumberOfPlayersDelegate([this](bool isIncreased) { ChangeNumberOfPlayers(isIncreased); });
	this->_menuView.SetChangeBoardHeightDelegate([this](bool isIncreased) { ChangeBoardHeight(isIncreased); });
	this->_menuView.SetChangeBoardWidthDelegate([this](bool isIncreased) { ChangeBoardWidth(isIncreased); });
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

void MemoryGame::MenuController::ChangeBoardWidth(bool isIncreased)
{
	if (isIncreased)
	{
		this->_gameSettings->Width++;
		this->_menuView.UpdateWidth(this->_gameSettings->Width);
	}
	else
	{
		if (this->_gameSettings->Width > MINIMUM_WIDTH)
		{
			this->_gameSettings->Width--;
			this->_menuView.UpdateWidth(this->_gameSettings->Width);
		}
	}
}

void MemoryGame::MenuController::ChangeBoardHeight(bool isIncreased)
{
	if (isIncreased)
	{
		this->_gameSettings->Height++;
		this->_menuView.UpdateHeight(this->_gameSettings->Height);
	}
	else
	{
		if (this->_gameSettings->Height > MINIMUM_HEIGHT)
		{
			this->_gameSettings->Height--;
			this->_menuView.UpdateHeight(this->_gameSettings->Height);
		}
	}
}

bool MemoryGame::MenuController::ValidateBoardSize()
{
	int boardWidth = this->_gameSettings->Width;
	int boardHeight = this->_gameSettings->Height;
	bool isValid = (boardHeight * boardWidth) % 2 == 0;

	return isValid;
}

void MemoryGame::MenuController::ProcessPlayGameAction()
{
	bool boardIsValid = this->ValidateBoardSize();

	if (boardIsValid)
	{
		this->_changeGameStateDelegate(GameState::PLAY_SCENE);
	}

}