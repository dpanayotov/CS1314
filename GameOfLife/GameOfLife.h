/*
 * GamOfLife.h
 *
 *  Created on: May 18, 2014
 *      Author: dpanayotov
 */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_
#include <iostream>


enum CELL_STATUS
{
	DEAD, ALIVE
};

class GameOfLife
{
	int rows;
	int cols;
	CELL_STATUS** board;
	CELL_STATUS** tempBoard;
	bool flag; //switch between boards without coping
public:
	GameOfLife();
	GameOfLife(int, int, int*);
	GameOfLife(const GameOfLife&);
	~GameOfLife();
	void advance();
	CELL_STATUS getCell(CELL_STATUS, int, int, bool) const;
	friend std::ostream& operator<<(std::ostream&, const GameOfLife&);
};

#endif /* GAMOFLIFE_H_ */
