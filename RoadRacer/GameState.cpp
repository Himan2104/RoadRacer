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
	player.init(this->assets);
	bgA.setTexture(this->assets.getTxr("game_bg"));
	bgB.setTexture(this->assets.getTxr("game_bg"));
	bgB.setPosition(0.0f, bgA.getPosition().y - bgB.getGlobalBounds().height);
}

void GameState::update(float delTime, sf::Vector2f mpos, int& statevar)
{
	player.update(delTime);

	bgA.move(0.0f, 100.0f * delTime);
	bgB.move(0.0f, 100.0f * delTime);
	if (bgA.getPosition().y >= 600.0f)	bgA.setPosition(0.0f, bgB.getPosition().y - bgA.getGlobalBounds().height);
	if (bgB.getPosition().y >= 600.0f)	bgB.setPosition(0.0f, bgA.getPosition().y - bgB.getGlobalBounds().height);
}

void GameState::render(sf::RenderTarget& renderer)
{
	renderer.draw(bgA);
	renderer.draw(bgB);
	player.render(renderer);
}
