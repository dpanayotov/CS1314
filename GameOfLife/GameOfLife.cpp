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

	board[2][3] = ALIVE;
	board[2][4] = ALIVE;
	board[2][2] = ALIVE;
}

GameOfLife::GameOfLife(int _rows, int _cols, int* coords) :
		rows(_rows), cols(_cols)
{
	cout<<"asd";
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

	cout << this;
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

	cout << this;
}

GameOfLife::~GameOfLife()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] board[i];
	}

	delete[] board;
}

void GameOfLife::advance()
{
	int aliveCells = 0;

	//create buffer board to check neighbor states
	CELL_STATUS** tempBoard = new CELL_STATUS*[rows];
	for(int i=0; i<rows; i++)
	{
		tempBoard[i] = new CELL_STATUS[cols];
	}

	for (int i = 1; i < rows-1; i++)
	{
		for (int j = 1; j < cols-1; j++)
		{
			//current cell
			if (board[i][j] == ALIVE)
			{
				aliveCells++;
			}
			//left neightbor
			if (board[i][j - 1] == ALIVE)
			{
				aliveCells++;
			}
			//right neighbor
			if (board[i][j + 1] == ALIVE)
			{
				aliveCells++;
			}
			//top neighbor
			if (board[i - 1][j] == ALIVE)
			{
				aliveCells++;
			}
			//bottom neighbor
			if (board[i + 1][j] == ALIVE)
			{
				aliveCells++;
			}
			//top left neighbor
			if (board[i - 1][j - 1] == ALIVE)
			{
				aliveCells++;
			}
			//top right neighbor
			if (board[i - 1][j + 1] == ALIVE)
			{
				aliveCells++;
			}
			//bottom left neighbor
			if (board[i + 1][j - 1] == ALIVE)
			{
				aliveCells++;
			}
			//bottom right neighbor
			if (board[i + 1][j + 1] == ALIVE)
			{
				aliveCells++;
			}

			//set temporary values
			tempBoard[i][j] = DEAD;

			//there are less than 2 alive neighbors => die due to under-population
			if(board[i][j] == ALIVE && aliveCells<2)
			{
				tempBoard[i][j] = DEAD;
			}
			//there are 2 or 3 alive neighbors => cell lives in the next generation
			else if(board[i][j] == ALIVE && (aliveCells == 2 || aliveCells == 3))
			{
				tempBoard[i][j] = ALIVE;
			}
			//there are more than 3 neighbors => cell dies due to overcrowding
			else if(board[i][j] == ALIVE && aliveCells > 3)
			{
				tempBoard[i][j] = DEAD;
			}
			//the cell has exactly 3 alive neighbors => it is reproduced
			else if(board[i][j] == DEAD && aliveCells == 3)
			{
				tempBoard[i][j] = ALIVE;
			}
		}
	}

	//delete old board
	for(int i=0; i<rows; i++)
	{
		delete[] board[i];
	}
	delete[] board;

	//create board
	board = new CELL_STATUS*[rows];
	for(int i=0; i<rows; i++)
	{
		board[i] = new CELL_STATUS[cols];
	}

	//copy buffer board
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			board[i][j] = tempBoard[i][j];
		}
	}

	//delete buffer board
	for(int i=0; i<rows; i++)
	{
		delete[] tempBoard[i];
	}
	delete[] tempBoard;

	//draw next state of the board
	cout<<endl;
	cout<<*this;
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

char* GameOfLife::getCell(int x, int y) const
{
	if (board[x][y] == DEAD)
	{
		return "DEAD";
	}
	return "ALIVE";
}
