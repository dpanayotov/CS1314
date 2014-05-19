/*
 * GamOfLife.cpp
 *
 *  Created on: May 18, 2014
 *      Author: dpanayotov
 */

#include "GameOfLife.h"
using namespace std;

GameOfLife::GameOfLife() :
		flag(true)
{
	rows = 4;
	cols = 4;
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

	//create buffer board to check neighbor states
	tempBoard = new CELL_STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempBoard[i] = new CELL_STATUS[cols];
	}

	board[0][1] = ALIVE;
	board[1][2] = ALIVE;
	board[2][0] = ALIVE;
	board[2][1] = ALIVE;
	board[2][2] = ALIVE;
}

GameOfLife::GameOfLife(int _rows, int _cols, int* coords) :
		rows(_rows), cols(_cols), flag(true)
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
	//create buffer board to check neighbor states
	tempBoard = new CELL_STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempBoard[i] = new CELL_STATUS[cols];
	}

	cout << this;
}

GameOfLife::GameOfLife(const GameOfLife& other) :
		flag(other.flag)
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

	//create buffer board to check neighbor states
	tempBoard = new CELL_STATUS*[rows];
	for (int i = 0; i < rows; i++)
	{
		tempBoard[i] = new CELL_STATUS[cols];
	}
	cout << this;
}

GameOfLife::~GameOfLife()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] board[i];
		delete[] tempBoard[i];
	}

	delete[] board;
	delete[] tempBoard;
}

void GameOfLife::advance()
{

	if (flag)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				tempBoard[i][j] = getCell(board[i][j], i, j, flag);
			}
		}
		flag = !flag;
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				board[i][j] = getCell(tempBoard[i][j], i, j, flag);
			}
		}
		flag = !flag;
	}
}

ostream& operator<<(ostream& out, const GameOfLife& other)
{
	if (other.flag)
	{
		for (int i = 0; i < other.rows; i++)
		{
			for (int j = 0; j < other.cols; j++)
			{
				(other.board[i][j] == DEAD) ? out << '.' : out << 'X';
			}
			out<<endl;
		}
	}
	else
	{
		for (int i = 0; i < other.rows; i++)
		{
			for (int j = 0; j < other.cols; j++)
			{
				(other.tempBoard[i][j] == DEAD) ? out << '.' : out << 'X';
			}
			out<<endl;
		}
	}

	for(int i=0; i<other.cols; i++)
	{
		out<<'=';
	}

	out<<endl;

	return out;
}

CELL_STATUS GameOfLife::getCell(CELL_STATUS state, int _x, int _y,
		bool _flag) const
{
	int aliveCells = 0;

	if (_flag)
	{
		for (int i = _x - 1; i <= _x + 1; i++)
		{
			for (int j = _y - 1; j <= _y + 1; j++)
			{
				if (i == _x && j == _y)
				{
					continue;
				}
				if (i > -1 && i < rows && j > -1 && j < cols)
				{
					if (board[i][j] == ALIVE)
					{
						aliveCells++;
					}
				}
			}
		}
	}
	else
	{
		for (int i = _x - 1; i <= _x + 1; i++)
		{
			for (int j = _y - 1; j <= _y + 1; j++)
			{
				if (i == _x && j == _y)
				{
					continue;
				}
				if (i > -1 && i < rows && j > -1 && j < cols)
				{
					if (tempBoard[i][j] == ALIVE)
					{
						aliveCells++;
					}
				}
			}
		}
	}

	if (state == ALIVE)
	{
		return (aliveCells > 1 && aliveCells < 4) ? ALIVE : DEAD;
	}
	else
	{
		return (aliveCells == 3) ? ALIVE : DEAD;
	}
}
