/*
 * GameOfLife.cpp
 *
 *  Created on: May 20, 2014
 *      Author: dpanayotov
 */

#include "GameOfLife.h"

using namespace std;

GameOfLife::GameOfLife() :
		rows(4), cols(4)
{
	field = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		field[i] = new STATUS[cols];
	}

	tempField = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempField[i] = new STATUS[cols];
	}

	field[0][1] = ALIVE;
    field[1][2] = ALIVE;
    field[2][0] = ALIVE;
    field[2][1] = ALIVE;
    field[2][2] = ALIVE;

	**field = DEAD;
	**tempField = **field;
}

GameOfLife::GameOfLife(int _rows, int _cols, int coords[]) :
		rows(_rows), cols(_cols)
{
	field = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		field[i] = new STATUS[cols];
	}

	tempField = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempField[i] = new STATUS[cols];
	}

	int k = 0;
	while (coords[k])
	{
		field[coords[k]][coords[k + 1]] = ALIVE;
		k += 2;
	}
}

GameOfLife::GameOfLife(const GameOfLife& other) :
		rows(other.rows), cols(other.cols)
{
	field = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		field[i] = new STATUS[cols];
	}

	tempField = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempField[i] = new STATUS[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			field[i][j] = other.field[i][j];
		}
	}

	**tempField = **field;
}

GameOfLife::~GameOfLife()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] field[i];
		delete[] tempField[i];
	}

	delete[] field;
	delete[] tempField;
}

void GameOfLife::advance()
{
	//copy next-state-field in the buffer field and then copy it back
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(getCell(field[i][j], i, j)==ALIVE)
			{
				tempField[i][j] = ALIVE;
			}
			else
			{
				tempField[i][j] = DEAD;
			}
		}
	}

	for(int i=0; i<rows; i++)
	{
		delete[] field[i];
	}
	delete[] field;

	field = new STATUS*[rows];
	for(int i=0; i<rows; i++)
	{
		field[i] = new STATUS[cols];
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			field[i][j] = tempField[i][j];
		}
	}
}

STATUS GameOfLife::getCell(STATUS state, int _x, int _y)
{
	int aliveCells = 0;

	//iterate over the 8 neighbouring cells
	for (int i = _x - 1; i <= _x + 1; i++)
	{
		for (int j = _y - 1; j <= _y + 1; j++)
		{
			//we don't want to get the current cell so we skip it
			if (i == _x && j == _y)
			{
				continue;
			}
			if (i > -1 && i < rows && j > -1 && j < cols)
			{
				if (field[i][j] == ALIVE)
				{
					aliveCells++;
				}
			}
		}
	}

	if (state == ALIVE) //the cell is live and has 2 or 3 alive neighbours => continues to live
	{
		return (aliveCells > 1 && aliveCells < 4) ? ALIVE : DEAD;
	}
	else
	{
		//the cell is dead but has exactly 3 live neighbours => reproduced
		return (aliveCells == 3) ? ALIVE : DEAD;
	}
}

ostream& operator<<(ostream& out, const GameOfLife& other)
{
	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			(other.field[i][j] == DEAD) ? out << '.' : out << 'X';
		}
		out << endl;
	}

	for (int i = 0; i < other.cols; i++)
	{
		out << '=';
	}

	out << endl;

	return out;
}
