/*
 * Cell.cpp
 *
 *  Created on: Mar 30, 2014
 *      Author: Dimitar
 */

#include "Cell.h"

Cell::Cell()
{
	srand(time(0));
	value = rand() % 10 - 1;
	stat = CLOSED;
}

Cell::Cell(int val)
{
	value = val;
	stat = CLOSED;
}

Cell::CELL_STATUS Cell::status()
{
	return stat;
}

void Cell::open()
{
	if(stat == CLOSED)
	{
		stat = OPEN;
	}
}

void Cell::flag()
{
	if(stat == CLOSED)
	{
		stat = FLAGGED;
	}
}

void Cell::unflag()
{
	if(stat == FLAGGED)
	{
		stat = CLOSED;
	}
}

int Cell::getValue() const
{
	return value;
}

Cell::~Cell()
{
}
