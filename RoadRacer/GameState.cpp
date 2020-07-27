#include "pch.h"
#include "GameState.hpp"

GameState::GameState()
{
	isOver = false;
	score = 0;
	isStarted = false;
	cnt = 4;
	countDown.restart().asSeconds();
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

	cntDn.setFont(Assets::access()->getFont("mm_fmain"));
	cntDn.setCharacterSize(175);
	cntDn.setFillColor(sf::Color::Cyan);
	cntDn.setString(std::to_string(cnt));
	cntDn.setStyle(sf::Text::Italic);
	centerOrigin(cntDn);
	cntDn.setPosition(400.0f, 200.0f);

	CDX.setBuffer(Assets::access()->getSoundBuffer("CDX"));
	CDGO.setBuffer(Assets::access()->getSoundBuffer("CDGO"));

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

	scoreClk.restart().asMilliseconds();

	heart.setSize(sf::Vector2f(21.0f, 21.0f));
	heart.setOrigin(10.0f, 10.0f);
	heart.setTexture(&Assets::access()->getTxr("heart"));
	for (int i = 0; i < player.lives; i++)
		lives.push_back(sf::RectangleShape(heart));

}

void GameState::update(float delTime, sf::Vector2f mpos, int& statevar)
{
	if (player.lives != 0)
	{
		
		if (!isStarted)
		{
			if (countDown.getElapsedTime().asSeconds() >= 1.0f)
			{
				cnt--;
				if (cnt == 0)
				{
					cntDn.setString("GO!");
					centerOrigin(cntDn);
					cntDn.setPosition(400.0f, 200.0f);
					isStarted = true;
					CDGO.play();
					countDown.restart().asSeconds();
				}
				else
				{
					cntDn.setString(std::to_string(cnt));
					countDown.restart().asSeconds();
					CDX.play();
				}
			}
		}
		else
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
			for (int i = 0; i < player.lives; i++)
				lives.push_back(sf::RectangleShape(heart));
		}
	}
	else
	{
		if (!isOver)
		{
			scoreClk.restart().asSeconds();
			isOver = true;
			if (score > hs.getHighScore()) hs.setHighScore(score);
		}
		else if (scoreClk.getElapsedTime().asSeconds() > 5.0f) statevar = 1;
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
	
	for (int i = 1; i <= player.lives; i++)
	{
		lives[i - 1].setPosition(22.5f * i, 20.0f);
		renderer.draw(lives[i - 1]);
	}
	//renderer.draw(debug);
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
	if(countDown.getElapsedTime().asSeconds() < 1.0f) renderer.draw(cntDn);
}
