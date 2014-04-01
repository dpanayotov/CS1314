/*
 * Field.cpp
 *
 *  Created on: Mar 30, 2014
 *      Author: Dimitar
 */

#include "Field.h"

//rows - height; cols - width

Field::Field()
{
	width = 0;
	height = 0;
	cells = new Cell*[height];
	for (int i = 0; i < height; ++i)
	{
		cells[i] = new Cell[width];
	}
	assert(cells != NULL);
	srand(time(0));
	int number;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			number = rand() % 10 - 1; //gives remained from 0 to 9 => -1, 8
			cells[i][j] = number;
		}
	}
}

Field::Field(int x, int y)
{
	width = x;
	height = y;
	cells = new Cell*[height];
	for (int i = 0; i < height; ++i)
	{
		cells[i] = new Cell[width];
	}
	assert(cells != NULL);
	srand(time(0));
	int number;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			number = rand() % 10 - 1;
			cout << i << ' ' << j << " value: " << number << endl;
			cells[i][j] = number;
		}
	}
}

Field::Field(const Field& other)
{
	width = other.width;
	height = other.height;
	cells = new Cell*[height];
	for (int i = 0; i < height; i++)
	{
		cells[i] = new Cell[width];
	}
	assert(cells!=NULL);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cells[i][j] = other.cells[i][j];
		}
	}
}

Field& Field::operator=(const Field& other)
{
	if (this != &other)
	{
		if (cells != NULL)
		{
			del();
		}
		width = other.width;
		height = other.height;
		cells = new Cell*[height];
		for (int i = 0; i < height; i++)
		{
			cells[i] = new Cell[width];
		}
		assert(cells!=NULL);
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				cells[i][j] = other.cells[i][j];
			}
		}
	}
	return *this;
}

void Field::helpOpen(int x, int y)
{
	if (inBounds(x, y))
	{
		if (cells[x][y].getValue() == -1)
		{
			cout << "You stepped on a mine!" << endl << "GAME OVER" << endl;
			return;
		}
		else
		{
			openCell(x, y);
		}
	}
	else
	{
		cout<<"Out of bounds!"<<endl;
	}
}

void Field::openCell(int x, int y)
{
	if (cells[x][y].status() == 1)
	{
		if (cells[x][y].getValue() == -1)
		{
			return;
		}
		cells[x][y].open(); //open cell
		cout << "Opened " << x << ' ' << y << endl;
		openCell(x - 1, y); //up
		openCell(x + 1, y); //down
		openCell(x, y + 1); //right
		openCell(x, y - 1); //left
	}
}

void Field::flagCell(int x, int y)
{
	if (inBounds(x, y))
	{
		if (cells[x][y].status() == 1)
		{
			cells[x][y].flag();
		}
	}
	else
	{
		cout << "Out of bounds!" << endl;
	}
}

void Field::unflagCell(int x, int y)
{
	if (inBounds(x, y))
	{
		if (cells[x][y].status() == 2)
		{
			cells[x][y].unflag();
		}
	}
	else
	{
		cout << "Out of bounds!" << endl;
	}
}

bool Field::isSolved()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (cells[i][j].getValue() == -1
					&& (cells[i][j].status() == 2 || cells[i][j].status() == 1)
					|| (cells[i][j].getValue() != -1
							&& cells[i][j].status() != 0))
			{
				return true;
			}
		}
	}
	return false;
}

bool Field::inBounds(int x, int y)
{
	if (x < height && y < width && x >= 0 && y >= 0)
	{
		return true;
	}
	return false;
}

void Field::del()
{
	for (int i = 0; i < height; i++)
	{
		delete[] cells[i];
	}
	delete[] cells;
}

Field::~Field()
{
	del();
}

