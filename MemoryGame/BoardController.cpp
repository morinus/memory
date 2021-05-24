#include "BoardController.h"
#include "stdlib.h"

constexpr int NUMBER_OF_CARD_TYPES = 4;


MemoryGame::BoardController::BoardController()
{
	this->_firstSelectedCardIndex = -1;
	this->_secondSelectedCardIndex = -1;
	this->_currentPlayerIndex = 0;
	this->_isGameOver = false;
	this->_isInited = false;
}

MemoryGame::BoardController::~BoardController()
{

}

void MemoryGame::BoardController::InitBoard(std::shared_ptr<GameSettings> gameSettings)
{
	this->_gameSettings = gameSettings;
	this->_isGameOver = false;

	try
	{
		if (this->_isInited)
		{
			this->_players.clear();
			this->_cards.clear();
			this->_currentPlayerIndex = 0;
		}

		this->InitPlayers(this->_gameSettings->NumberOfPlayers);
		this->InitCards(this->_gameSettings->Width, this->_gameSettings->Height);

		this->_scoresView.Init(this->_players);
		this->_boardView.Init(this->_cards, this->_gameSettings->Width, this->_gameSettings->Height);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}

	this->_isInited = true;
}

void MemoryGame::BoardController::InitPlayers(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; ++i)
	{
		std::string playerName = "Player" + std::to_string(i + 1);
		Player player(playerName);

		this->_players.push_back(player);
	}
}

void MemoryGame::BoardController::InitCards(int width, int height)
{
	int numberOfCardPairs = (width * height) / 2;

	for (int i = 0; i < numberOfCardPairs; ++i)
	{
		CardType cardType = CardType(std::rand() % NUMBER_OF_CARD_TYPES + 1);
		Card card(cardType);

		// We need two of the same type of cards
		this->_cards.push_back(card);
		this->_cards.push_back(card);
	}
}

void MemoryGame::BoardController::ProcessMouseClick(sf::Vector2f mousePosition)
{
	auto selectedCardIndex = this->_boardView.GetSelectedButtonIndex(mousePosition);

	if (selectedCardIndex > -1)
	{
		auto firstCardIsSelected = this->_firstSelectedCardIndex > -1;

		if (firstCardIsSelected)
		{
			_secondSelectedCardIndex = selectedCardIndex;

			this->ProcessCurrentlySelectedCards();
		}
		else
		{
			_firstSelectedCardIndex = selectedCardIndex;
		}
	}
}

void MemoryGame::BoardController::ProcessCurrentlySelectedCards()
{
	auto firstCardIndex = this->_firstSelectedCardIndex;
	auto secondCardIndex = this->_secondSelectedCardIndex;

	auto firstSelectedCardType = this->_cards[firstCardIndex].GetCardType();
	auto secondSelectedCardType = this->_cards[secondCardIndex].GetCardType();

	if (firstSelectedCardType == secondSelectedCardType)
	{
		this->_players[_currentPlayerIndex].IncreaseScore();
		this->UpdateCurrentPlayerText();
		this->_cards[firstCardIndex].Solve();
		this->_cards[secondCardIndex].Solve();

		if (this->CheckIfGameOver())
		{
			this->_gameSettings->Players = this->_players;
			this->_changeGameStateDelegate(GameState::LEADERBOARD_SCENE);
		}
	}
	else
	{
		this->ChangePlayerTurn();
		this->_boardView.SetIsInteractible(firstCardIndex, true);
		this->_boardView.SetIsInteractible(secondCardIndex, true);
		this->_scoresView.ColorCurrentPlayerText(this->_currentPlayerIndex);
	}

	this->DeselectEverything();
}

void MemoryGame::BoardController::DeselectEverything()
{
	this->_firstSelectedCardIndex = -1;
	this->_secondSelectedCardIndex = -1;
}

void MemoryGame::BoardController::UpdateCurrentPlayerText()
{
	auto playerName = this->_players[_currentPlayerIndex].GetName();
	auto newScore = this->_players[_currentPlayerIndex].GetScore();
	auto newPlayerText = playerName + ": " + std::to_string(newScore);

	this->_scoresView.UpdatePlayerText(this->_currentPlayerIndex, newPlayerText);
}

void MemoryGame::BoardController::ChangePlayerTurn()
{
	auto numberOfPlayers = this->_players.size();
	auto isCurrentPlayerLastPlayer = _currentPlayerIndex == numberOfPlayers - 1;

	this->_currentPlayerIndex = isCurrentPlayerLastPlayer ? 0 : _currentPlayerIndex + 1;
}

bool MemoryGame::BoardController::CheckIfGameOver()
{
	for (auto card : this->_cards)
	{
		if (!card.GetIsSolved())
		{
			return false;
		}
	}

	return true;
}

void MemoryGame::BoardController::ResetGame()
{

}

void MemoryGame::BoardController::Render(std::shared_ptr<sf::RenderWindow> window)
{
	this->_boardView.Render(window);
	this->_scoresView.Render(window);
}

void MemoryGame::BoardController::Update(float elapsedTime)
{
	this->_boardView.Update(elapsedTime);
}

void MemoryGame::BoardController::SetChangeGameStateDelegate(std::function<void(GameState)> changeGameStateDelegate)
{
	this->_changeGameStateDelegate = changeGameStateDelegate;
}
