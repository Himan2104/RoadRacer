#include "pch.h"
#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	
}

MainMenu::~MainMenu()
{
}

void MainMenu::initialize()
{;
	bg.setTexture(Assets::access()->getTxr("mm_bg"));
	play.setFont(Assets::access()->getFont("mm_fmain"));
	exit.setFont(Assets::access()->getFont("mm_fmain"));
	highscore.setFont(Assets::access()->getFont("mm_fmain"));
	

	play.setCharacterSize(40);
	play.setString("[PLAY]");
	centerOrigin(play);
	play.setPosition(400.0f, 300.0f);

	exit.setCharacterSize(40);
	exit.setString("[EXIT]");
	centerOrigin(exit);
	exit.setPosition(400.0f, 400.0f);

	select.setBuffer(Assets::access()->getSoundBuffer("mm_select"));
	hover.setBuffer(Assets::access()->getSoundBuffer("mm_hover"));

	highscore.setCharacterSize(40);
	highscore.setString("HIGHSCORE : " + std::to_string(hs.getHighScore()));
	centerOrigin(highscore);
	highscore.setStyle(sf::Text::Italic);
	highscore.setFillColor(sf::Color::Cyan);
	highscore.setPosition(400.0f, 500.0f);
}

void MainMenu::update(float delTime, sf::Vector2f mpos, int& statevar)
{
	if (play.getGlobalBounds().contains(mpos))
	{
		play.setFillColor(sf::Color::Green);
		//hover.play();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			select.play();
			statevar = 2;
		}
		
	}
	else play.setFillColor(sf::Color::White);

	if (exit.getGlobalBounds().contains(mpos))
	{
		exit.setFillColor(sf::Color::Green);
		//hover.play();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			select.play();
			statevar = -1;
		}
	}
	else exit.setFillColor(sf::Color::White);
}

void MainMenu::render(sf::RenderTarget& renderer)
{
	renderer.draw(bg);
	renderer.draw(play);
	renderer.draw(exit);
	renderer.draw(highscore);
}
