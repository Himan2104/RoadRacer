#include "pch.h"
#include "GameState.hpp"

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::initialize(Assets& assets)
{
	this->assets = assets;
}

void GameState::update(float delTime, sf::Vector2f mpos, int& statevar)
{
}

void GameState::render(sf::RenderTarget& renderer)
{
}
