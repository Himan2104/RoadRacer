#include "pch.h"
#include "Highscore.hpp"
#include<iostream>
#include<string>

Highscore::Highscore()
{
}

Highscore::~Highscore()
{
}

unsigned long Highscore::getHighScore()
{
	std::ifstream file;
	file.open("data/hs.txt");
	std::string str;
	std::getline(file, str);
	file.close();
	return std::stoi(str);
}

void Highscore::setHighScore(unsigned long hs)
{
	std::ofstream file;
	file.open("data/hs.txt", std::ios::trunc);
	file << std::to_string(hs);
	file.close();

}
