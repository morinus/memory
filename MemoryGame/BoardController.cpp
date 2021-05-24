#include "BoardController.h"
#include "stdlib.h"

constexpr int NUMBER_OF_CARD_TYPES = 4;


MemoryGame::BoardController::BoardController()
{
	this->_firstSelectedCardIndex = -1;
	this->_secondSelectedCardIndex = -1;
	this->_currentPlayerIndex = 0;
	this->_isGameOver = false;
}

MemoryGame::BoardController::~BoardController()
{

}

void MemoryGame::BoardController::InitBoard(int numberOfPlayers, int boardWidth, int boardHeight)
{
	try
	{
		this->InitPlayers(numberOfPlayers);
		this->InitCards(boardWidth, boardHeight);

		this->_leaderboardView.Init(this->_players);
		this->_boardView.Init(this->_cards, boardWidth, boardHeight);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}
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
			this->CheckIfGameOver();
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
		this->_isGameOver = this->CheckIfGameOver();
	}
	else
	{
		this->ChangePlayerTurn();
		this->_boardView.SetIsInteractible(firstCardIndex, true);
		this->_boardView.SetIsInteractible(secondCardIndex, true);
		this->_leaderboardView.ColorCurrentPlayerText(this->_currentPlayerIndex);
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

	this->_leaderboardView.UpdatePlayerText(this->_currentPlayerIndex, newPlayerText);
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
	this->_leaderboardView.Render(window);

	if (this->_isGameOver) {}
}

void MemoryGame::BoardController::Update(float elapsedTime)
{
	this->_boardView.Update(elapsedTime);
}

void MemoryGame::BoardController::SetChangeGameStateDelegate(std::function<void(GameState)> changeGameStateDelegate)
{
	this->_changeGameStateDelegate = changeGameStateDelegate;
}
