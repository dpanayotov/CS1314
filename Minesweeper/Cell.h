/*
 * Cell.h
 *
 *  Created on: Mar 30, 2014
 *      Author: Dimitar
 */

#ifndef CELL_H_
#define CELL_H_

#include <stdlib.h>
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

class Cell
{
	int value;
	enum CELL_STATUS{
		OPEN, CLOSED, FLAGGED
	};
	CELL_STATUS stat;
public:
	Cell();
	Cell(int);
	CELL_STATUS status();
	void open();
	void flag();
	void unflag();
	int getValue() const;
	~Cell();
};

#endif /* CELL_H_ */
