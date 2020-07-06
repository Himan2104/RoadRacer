#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"State.hpp"
#include"Assets.hpp"

const sf::VideoMode Vmode(800, 600, 32);
const unsigned int frameRateCap = 120;

template<typename T>
inline void centerOrigin(T& object)
{
	object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
}

/*
void textSetup(sf::Text& text, unsigned int charSize, std::string txt, sf::Vector2f pos)
{
	text.setCharacterSize(charSize);
	text.setString(txt);
	centerOrigin(text);
}*/

//-1 : window closed
//0 : splash screen
//1 : Main Menu
//2 : Game State
//3 : High Score