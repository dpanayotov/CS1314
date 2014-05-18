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
	cout<<"asd";
}

GameOfLife::GameOfLife(int _rows, int _cols, CELL_STATUS* coords) :
		rows(_rows), cols(_cols)
{
	int k=0;
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

	while(coords[k])
	{
		board[coords[k]][coords[k+1]] = ALIVE;
		k+=2;
	}

	draw(board);
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

	draw(board);
}

GameOfLife::~GameOfLife()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] board[i];
	}

	delete[] board;
}

void GameOfLife::draw(CELL_STATUS *_board[])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}
