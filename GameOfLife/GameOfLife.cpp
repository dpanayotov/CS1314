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

GameOfLife::GameOfLife(int _rows, int _cols, int coords[], int size) :
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

	for (int i = 0; i < size; i += 2)
	{
		field[coords[i]][coords[i + 1]] = ALIVE;
	}

	**field = DEAD;
	**tempField = **field;
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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tempField[i][j] = getCell(field[i][j], i, j);
		}
	}

	//delete old field
	for (int i = 0; i < rows; i++)
	{
		delete[] field[i];
	}
	delete[] field;

	//create new field and copy the next-state-field to this one
	field = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		field[i] = new STATUS[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			field[i][j] = tempField[i][j];
		}
	}

	//if we have an alive cell on the border - expand
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (getCell(field[i][j], i, j) == ALIVE && onBorder(i, j))
			{
				expand();
				return;
			}
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
	for (int i = 0; i < other.cols; i++)
	{
		out << '=';
	}
	out<<endl;

	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			(other.field[i][j] == DEAD) ? out << ' ' : out << '*';
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

void GameOfLife::expand()
{
	rows = 2 * rows + 1;
	cols = 2 * cols + 1;

	tempField = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempField[i] = new STATUS[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tempField[i][j] = DEAD;
		}
	}
	for (int i = 0; i < (rows - 1) / 2; i++)
	{
		for (int j = 0; j < (cols - 1) / 2; j++)
		{
			if (field[i][j] == ALIVE)
				tempField[i + 2][j + 2] = ALIVE;
		}
	}
	for (int i = 0; i < (rows - 1) / 2; i++)
	{
		delete[] field[i];
	}
	delete[] field;

	field = new STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		field[i] = new STATUS[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			field[i][j] = tempField[i][j];
		}
	}

}

bool GameOfLife::onBorder(int x, int y)
{
	return (x == 0 || y == 0 || x == rows - 1 || y == cols - 1) ? true : false;
}

