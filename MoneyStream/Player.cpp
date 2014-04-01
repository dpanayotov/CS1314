/*
 * Player.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: Dimitar
 */

#include "Player.h"

Player::Player()
{
	nickname = new char[10];
	assert(nickname != NULL);
	strcpy(nickname,"NO_NAME"); //if only '\0' getInfo gives exception
	score = 0;
}

Player::Player(char* newNickname)
{
	nickname = new char[strlen(newNickname)+1];
	assert(nickname != NULL);
	strcpy(nickname,newNickname);
	score = 0;
}


Player::Player(const Player& newPlayer)
{
	nickname = new char[strlen(newPlayer.nickname)+1];
	assert(nickname != NULL);
	nickname = newPlayer.nickname;
	score = newPlayer.score;
}

Player& Player::operator =(const Player& newPlayer)
{
	if(this != &newPlayer)
	{
		if(nickname != NULL)
		{
			delete[] nickname;
		}
		nickname = new char[strlen(newPlayer.nickname)+1];
		assert(nickname != NULL);
		nickname = newPlayer.nickname;
		score = newPlayer.score;
	}
	return *this;
}



char* Player::getNickname() const
{
	return nickname;
}

double Player::getScore() const
{
	return score;
}

char* Player::getInfo()
{
	//googled it, no itoa function and sprintf is not working
	char* result = new char[strlen(nickname) + 1];
	strcpy(result, nickname);
	stringstream ss;
	ss<<score;
	string str = ss.str();
	strcat(result, "'s score is ");
	strcat(result, str.c_str());
	return result;
}

void Player::addScore(double newScore)
{
	score+=newScore;
}
Player::~Player()
{
	delete[] nickname;
}

