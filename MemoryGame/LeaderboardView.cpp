#include "LeaderboardView.h"
#include "ResourceLocator.h"
#include "ErrorMessageStrings.h"

constexpr int PLAYER_TEXT_INITIAL_OFFSET_X = 350;
constexpr int PLAYER_TEXT_INITIAL_OFFSET_Y = 100;
constexpr int PLAYER_TEXT__OFFSET_Y = 20;
constexpr int PLAYER_TEXT_SIZE = 30;
constexpr int TITLE_FONT_SIZE = 52;
constexpr int TITLE_TEXT_X = 300;
constexpr int TITLE_TEXT_Y = 50;
constexpr int PLAY_AGAIN_FONT_SIZE = 42;
constexpr int PLAY_AGAIN_TEXT_Y = 700;


MemoryGame::LeaderboardView::LeaderboardView()
{

}

MemoryGame::LeaderboardView::~LeaderboardView()
{

}

void MemoryGame::LeaderboardView::Init(std::vector<Player> players, std::function<void(GameState)> changeGameStateDelegate)
{
	try
	{
		this->InitBackground();
		this->InitFont();
		this->InitTexts();
		this->InitPlayerTexts(players);
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << std::endl;
	}

	this->_changeSceneDelegate = changeGameStateDelegate;
}

void MemoryGame::LeaderboardView::InitFont()
{
	if (!this->_font.loadFromFile(FONT_FILEPATH))
	{
		throw(ERROR_LOADING_FONT);
	}
}

void MemoryGame::LeaderboardView::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(this->_backgroundSprite);

	window->draw(this->_titleText);
	window->draw(this->_playAgainText);

	for (auto playerText : this->_playerTexts)
	{
		window->draw(playerText);
	}
}

void MemoryGame::LeaderboardView::ProcessMouseClick(sf::Vector2f mousePosition)
{
	if (this->_playAgainText.getLocalBounds().contains(mousePosition))
	{
		this->_changeSceneDelegate(GameState::MENU_SCENE);
	}
}

void MemoryGame::LeaderboardView::InitBackground()
{
	if (!_backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILEPATH))
	{
		throw(ERROR_LOADING_TEXTURE);
	}

	_backgroundSprite = sf::Sprite(_backgroundTexture);
}

void MemoryGame::LeaderboardView::InitPlayerTexts(std::vector<Player> players)
{
	std::sort(players.begin(), players.end(), [](Player& first, Player& second)
	{
		return (first.GetScore() > second.GetScore());
	});

	int textsPlaced = 0;
	for (auto player : players)
	{
		sf::Text playerText;
		playerText.setString(sf::String(std::string(player.GetName() + ": " + std::to_string(player.GetScore()))));
		playerText.setFont(this->_font);
		playerText.setCharacterSize(PLAYER_TEXT_SIZE);
		playerText.setPosition(sf::Vector2f(PLAYER_TEXT_INITIAL_OFFSET_X, PLAYER_TEXT_INITIAL_OFFSET_Y * textsPlaced));
		textsPlaced++;

		this->_playerTexts.push_back(playerText);
	}
}

void MemoryGame::LeaderboardView::InitTexts()
{
	this->_titleText = sf::Text(sf::String("Leaderboard"), this->_font, TITLE_FONT_SIZE);
	this->_titleText.setPosition(TITLE_TEXT_X, TITLE_TEXT_Y);
	this->_titleText.setFillColor(sf::Color::Green);

	this->_playAgainText = sf::Text(sf::String("Play Again"), this->_font, PLAY_AGAIN_FONT_SIZE);
	this->_playAgainText.setPosition(TITLE_TEXT_X, PLAY_AGAIN_TEXT_Y);
	this->_playAgainText.setFillColor(sf::Color::Green);
}

void MemoryGame::LeaderboardView::ChangeGameState()
{
	this->_changeSceneDelegate(GameState::MENU_SCENE);
}
