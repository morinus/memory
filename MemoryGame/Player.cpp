#include "Player.h"


MemoryGame::Player::Player(std::string name)
{
	this->_name = name;
	this->_score = 0;
}

MemoryGame::Player::~Player()
{

}

const std::string MemoryGame::Player::GetName()
{
	return this->_name;
}

const int MemoryGame::Player::GetScore()
{
	return this->_score;
}

void MemoryGame::Player::SetScore(int newScore)
{
	this->_score = newScore;
}