/*
 * GameOfLife.h
 *
 *  Created on: May 20, 2014
 *      Author: dpanayotov
 */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_
#include <iostream>

enum STATUS
{
	DEAD, ALIVE
};

class GameOfLife
{
	STATUS** field;
	STATUS** tempField;
	int rows, cols;
public:
	GameOfLife();
	GameOfLife(const GameOfLife&);
	GameOfLife(int, int, int*);
	~GameOfLife();
	void advance();
	STATUS getCell(STATUS, int, int);
	friend std::ostream& operator<<(std::ostream&, const GameOfLife&);
};

#endif /* GAMEOFLIFE_H_ */
