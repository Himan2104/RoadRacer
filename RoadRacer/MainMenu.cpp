#include "pch.h"
#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	
}

MainMenu::~MainMenu()
{
}

void MainMenu::initialize(Assets& assets)
{
	this->assets = assets;

	bg.setTexture(assets.getTxr("mm_bg"));
	play.setFont(assets.getFont("mm_fmain"));
	exit.setFont(assets.getFont("mm_fmain"));

	play.setCharacterSize(40);
	play.setString("[PLAY]");
	centerOrigin(play);
	play.setPosition(400.0f, 300.0f);

	exit.setCharacterSize(40);
	exit.setString("[EXIT]");
	centerOrigin(exit);
	exit.setPosition(400.0f, 400.0f);
}

void MainMenu::update(float delTime, sf::Vector2f mpos, int& statevar)
{
	if (play.getGlobalBounds().contains(mpos))
	{
		play.setFillColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) statevar = 2;
		
	}
	else play.setFillColor(sf::Color::White);

	if (exit.getGlobalBounds().contains(mpos))
	{
		exit.setFillColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) statevar = -1;
	}
	else exit.setFillColor(sf::Color::White);
}

void MainMenu::render(sf::RenderTarget& renderer)
{
	renderer.draw(bg);
	renderer.draw(play);
	renderer.draw(exit);
}
