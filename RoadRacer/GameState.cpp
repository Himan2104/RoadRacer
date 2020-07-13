#include "pch.h"
#include "GameState.hpp"

GameState::GameState()
{

}

GameState::~GameState()
{
}

void GameState::initialize()
{
	player.init();
	bgA.setTexture(Assets::access()->getTxr("game_bg"));
	bgB.setTexture(Assets::access()->getTxr("game_bg"));
	bgB.setPosition(0.0f, bgA.getPosition().y - bgB.getGlobalBounds().height);

}

void GameState::update(float delTime, sf::Vector2f mpos, int& statevar)
{
	player.update(delTime);
	Oman.update(player, delTime);
	bgA.move(0.0f, gameSpeed * delTime);
	bgB.move(0.0f, gameSpeed * delTime);
	if (bgA.getPosition().y >= 600.0f)	bgA.setPosition(0.0f, bgB.getPosition().y - bgA.getGlobalBounds().height);
	if (bgB.getPosition().y >= 600.0f)	bgB.setPosition(0.0f, bgA.getPosition().y - bgB.getGlobalBounds().height);
}

void GameState::render(sf::RenderTarget& renderer)
{
	renderer.draw(bgA);
	renderer.draw(bgB);
	player.render(renderer);
	Oman.render(renderer);
}
