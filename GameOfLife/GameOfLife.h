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
public:
	GameOfLife();
	GameOfLife(int, int, CELL_STATUS*);
	GameOfLife(const GameOfLife&);
	~GameOfLife();
	void advance();
	CELL_STATUS getCell(int, int) const;
	friend std::ostream& operator<<(std::ostream&, const GameOfLife&);
};

#endif /* GAMOFLIFE_H_ */
