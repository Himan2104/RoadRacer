#include "pch.h"
#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
	
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialize()
{
	splash.setTexture(Assets::access()->getTxr("ss_main"));
	rect1.setSize({ 800, 100 });
	rect1.setPosition(0.0f, 150.0f);
	rect1.setFillColor(sf::Color::Black);

	rect2.setSize({ 800, 100 });
	rect2.setPosition(0.0f, 280.0f);
	rect2.setFillColor(sf::Color::Black);
}

void SplashScreen::update(float delTime, sf::Vector2f mpos, int& statevar)
{
	if (rect1.getPosition().x < 1500 && rect2.getPosition().x > -9000)
	{
		rect1.move(420 * delTime, 0 * delTime);
		rect2.move(-420 * delTime, 0 * delTime);
	}
	else statevar = 1;
}

void SplashScreen::render(sf::RenderTarget& renderer)
{
	renderer.draw(splash);
	renderer.draw(rect1);
	renderer.draw(rect2);

}
