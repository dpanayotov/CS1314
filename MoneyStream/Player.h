/*
 * Player.h
 *
 *  Created on: Mar 26, 2014
 *      Author: Dimitar
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <stdio.h>
#include <cassert>
#include <cstring>
#include <sstream>

using namespace std;

class Player
{
	double score;
	char* nickname;
public:
	Player();
	Player(char*);
	Player(const Player&);
	Player&operator=(const Player&);
	~Player();
	char* getNickname() const;
	double getScore() const;
	char* getInfo()  ;
	void addScore(double);
};

#endif /* PLAYER_H_ */
