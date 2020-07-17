#include "pch.h"
#include "GameState.hpp"

GameState::GameState()
{
	isOver = false;
}

GameState::~GameState()
{
}

void GameState::initialize()
{
	player.init();
	Oman.init();

	bgA.setTexture(Assets::access()->getTxr("game_bg"));
	bgB.setTexture(Assets::access()->getTxr("game_bg"));
	bgB.setPosition(0.0f, bgA.getPosition().y - bgB.getGlobalBounds().height);

	debug.setFont(Assets::access()->getFont("debug"));
	debug.setCharacterSize(15);
	debug.setFillColor(sf::Color::Green);
	debug.setOutlineColor(sf::Color::Black);
	debug.setOutlineThickness(1.0f);
	
	Score.setFont(Assets::access()->getFont("mm_fmain"));
	Score.setCharacterSize(35);
	Score.setFillColor(sf::Color::White);

	gameOver.setFont(Assets::access()->getFont("mm_fmain"));
	gameOver.setCharacterSize(100);
	gameOver.setFillColor(sf::Color::Red);
	gameOver.setString("GAME OVER!");
	gameOver.setStyle(sf::Text::Italic);
	centerOrigin(gameOver);
	gameOver.setPosition(390.0f, 250.0f);
	gSha = gameOver;
	gSha.setPosition(gameOver.getPosition().x + 5.0f, gameOver.getPosition().y + 5.0f);
	gSha.setFillColor(sf::Color(0, 0, 0, 150));

	score = 0;
	scoreClk.restart().asMilliseconds();
}

void GameState::update(float delTime, sf::Vector2f mpos, int& statevar)
{
	if (player.lives != 0)
	{
		Oman.update(player, delTime);
		player.update(delTime);
		bgA.move(0.0f, gameSpeed * delTime);
		bgB.move(0.0f, gameSpeed * delTime);
		if (bgA.getPosition().y >= 600.0f)	bgA.setPosition(0.0f, bgB.getPosition().y - bgA.getGlobalBounds().height);
		if (bgB.getPosition().y >= 600.0f)	bgB.setPosition(0.0f, bgA.getPosition().y - bgB.getGlobalBounds().height);

		if (scoreClk.getElapsedTime().asMilliseconds() > 100)
		{
			scoreClk.restart().asMilliseconds();
			score++;
		}
	}
	else
	{
		if (!isOver)
		{
			scoreClk.restart().asSeconds();
			isOver = true;
		}
		else if (scoreClk.getElapsedTime().asSeconds() > 10) statevar = -1;
	}

	Score.setString(std::to_string(score));
	centerOrigin(Score);
	Score.setPosition(400.0f, 20.0f);
	sf::Text ScoreShadow(Score);

	debug.setString("Lives : " + std::to_string(player.lives) + "\tFPS : " + std::to_string(1.0f / delTime) + "\t[+] Increase HP");
	debug.setPosition(10.0f, 570.0f);
}

void GameState::render(sf::RenderTarget& renderer)
{
	renderer.draw(bgA);
	renderer.draw(bgB);
	Oman.render(renderer);
	player.render(renderer);
	renderer.draw(debug);
	sf::Text ScoreShadow(Score);
	ScoreShadow.setFillColor(sf::Color(0, 0, 0, 150));
	ScoreShadow.setPosition(Score.getPosition().x + 3.0f, Score.getPosition().y + 3.0f);
	renderer.draw(ScoreShadow);
	renderer.draw(Score);
	if (player.lives == 0)
	{
		renderer.draw(gSha);
		renderer.draw(gameOver);	
	}
}
