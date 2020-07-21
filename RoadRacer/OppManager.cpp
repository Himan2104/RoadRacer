#include "pch.h"
#include "OppManager.hpp"

OppManager::OppManager()
{
	tdelay = float(rand() % 20 + 10);
	hdelay = float(rand() % 40 + 20);

	nClk.restart().asSeconds();
	tClk.restart().asSeconds();
	hClk.restart().asSeconds();
}

OppManager::~OppManager()
{
}

void OppManager::init()
{
	thicc.custom("thicc",sf::Vector2f(50.0f, 140.0f));
	health.custom("health", sf::Vector2f(25.0f, 50.0f));
}

void OppManager::update(Player& player, float delTime)
{
	for (auto& val : normies) val->update(delTime);
	thicc.update(delTime);
	health.update(delTime);

	for (size_t i = 0; i < normies.size(); i++)
	{
		if (player.getGB().intersects(normies[i]->getGB()) && normies[i]->isDed == false)
		{
			normies[i]->overrideTexture(Assets::access()->getTxr("boom"));
			normies[i]->vFac = 200.0f;
			if (player.lives > 0) player.lives--;
			normies[i]->isDed = true;
		}
		if (normies[i]->getPos().y > 650.0f)
		{
			delete normies[i];
			normies.erase(normies.begin() + i);
		}
	}
	if (player.getGB().intersects(thicc.getGB()))
	{
		if (player.getPos().y > thicc.getPos().y) player.addPushback(sf::Vector2f(0.0f, 10.0f));
		if (player.getPos().x > thicc.getPos().x) player.addPushback(sf::Vector2f(10.0f, 10.0f));
		if (player.getPos().x < thicc.getPos().x) player.addPushback(sf::Vector2f(-10.0f, 10.0f));
		
		if (player.lives > 1) player.lives -= 2;
	}
	if (player.getGB().intersects(health.getGB()))
	{
		health.setPos({ health.getPos().x, 800.0f });
		player.lives++;
	}

	if (nClk.getElapsedTime().asSeconds() >= 0.95f)
	{
		normies.push_back(new Enemy(sf::Vector2f(float(rand() % 400 + 200), -50.0f)));
		nClk.restart().asSeconds();
	}
	if (tClk.getElapsedTime().asSeconds() >= tdelay)
	{
		thicc.setPos(sf::Vector2f(float(rand() % 400 + 200), -50.0f));
		tClk.restart().asSeconds();
		tdelay = float(rand() % 20 + 10);
	}
	if (hClk.getElapsedTime().asSeconds() >= hdelay)
	{
		health.setPos(sf::Vector2f(float(rand() % 400 + 200), -50.0f));
		hClk.restart().asSeconds();
		hdelay = float(rand() % 40 + 20);
	}
}

void OppManager::render(sf::RenderTarget& target)
{
	for (auto& val : normies) val->render(target);
	if (thicc.getPos().y < 650.0f)  thicc.render(target);
	if (health.getPos().y < 650.0f)  health.render(target);
}
