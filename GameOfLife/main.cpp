/*
 * main.cpp
 *
 *  Created on: May 18, 2014
 *      Author: dpanayotov
 */

#include "GameOfLife.h"
#include<time.h>
#include<stdlib.h>

using namespace std;
int main()
{
	CELL_STATUS** coords = new CELL_STATUS*[10];
	for(int i=0; i<10; i++)
	{
		coords[i] = new CELL_STATUS[10];
	}


	for(int i=0; i<10; i++)
	{

		for(int j=0; j<10; j++)
		{
			srand(time(NULL));
			int x = rand()%6+1;
			int y = rand()%7+1;
			if(i == x && j==y)
			{
				coords[i][j] = ALIVE;
			}
			else
			{
				coords[i][j] = DEAD;
			}
		}
	}
	GameOfLife gol();

	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(coords[i][j]==DEAD)
			{
				cout<<'.';
			}
			else
			{
				cout<<'X';
			}
		}
		cout<<endl;
	}

	for(int i=0; i<10; i++)
	{
		delete[] coords[i];
	}
	delete[] coords;
	return 0;

}


