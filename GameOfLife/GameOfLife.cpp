/*
 * GamOfLife.cpp
 *
 *  Created on: May 18, 2014
 *      Author: dpanayotov
 */

#include "GameOfLife.h"
using namespace std;

GameOfLife::GameOfLife()
{
	rows = 5;
	cols = 10;
	board = new CELL_STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new CELL_STATUS[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = DEAD;
		}
	}
}

GameOfLife::GameOfLife(int _rows, int _cols, CELL_STATUS* coords) :
		rows(_rows), cols(_cols)
{
	int k = 0;
	board = new CELL_STATUS*[rows];

	for (int i = 0; i < rows; i++)
	{
		board[i] = new CELL_STATUS[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = DEAD;
		}
	}

	while (coords[k])
	{
		board[coords[k]][coords[k + 1]] = ALIVE;
		k += 2;
	}

	draw();
}

GameOfLife::GameOfLife(const GameOfLife& other)
{
	rows = other.rows;
	cols = other.cols;
	board = new CELL_STATUS*[rows];

	for (int i = 0; i < rows; i++)
	{
		board[i] = new CELL_STATUS[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = other.board[i][j];
		}
	}

	draw();
}

GameOfLife::~GameOfLife()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] board[i];
	}

	delete[] board;
}

ostream& operator<<(ostream& out, const GameOfLife& other)
{
	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			if (other.board[i][j] == DEAD)
			{
				out << '.';
			}
			else if (other.board[i][j] == ALIVE)
			{
				out << 'X';
			}
		}
		out << endl;
	}
	return out;
}

CELL_STATUS GameOfLife::getCell(int x, int y) const
{
	if (board[x][y] == 0)
	{
		return DEAD;
	}
	return ALIVE;
}
