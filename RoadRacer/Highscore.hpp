#pragma once
#include<fstream>

class Highscore
{
public:
	Highscore();
	~Highscore();

	unsigned long  getHighScore();
	void setHighScore(unsigned long hs);

};

