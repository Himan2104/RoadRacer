#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Assets.hpp"
#include"State.hpp"

const sf::VideoMode Vmode(800, 600, 32);
const unsigned int frameRateCap = 120;

template<typename T>
inline void centerOrigin(T& object)
{
	object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
}


const sf::Vector2f playerSpeed(200.0f, 200.0f);

const float enemySpeed = 200.0f;
const float gameSpeed = 400.0f;


/*
void textSetup(sf::Text& text, unsigned int charSize, std::string txt, sf::Vector2f pos)
{
	text.setCharacterSize(charSize);
	text.setString(txt);
	centerOrigin(text);
}
*/

//-1 : Window Closed
//0  : Splash Screen
//1  : Main Menu
//2  : Game State
//3  : High Score