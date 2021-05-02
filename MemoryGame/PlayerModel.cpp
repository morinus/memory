#include "PlayerModel.h"


MemoryGame::PlayerModel::PlayerModel(std::string name)
{
	this->_name = name;
}

MemoryGame::PlayerModel::~PlayerModel()
{

}

const std::string MemoryGame::PlayerModel::GetName()
{
	return this->_name;
}

const int MemoryGame::PlayerModel::GetScore()
{
	return this->_score;
}

void MemoryGame::PlayerModel::SetScore(int newScore)
{
	this->_score = newScore;
}