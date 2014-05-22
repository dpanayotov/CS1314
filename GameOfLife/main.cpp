/*
 * main.cpp
 *
 *  Created on: May 20, 2014
 *      Author: dpanayotov
 */

#include "GameOfLife.h"
using namespace std;
int main()
{
	int a[12] =
	{ 0, 1, 1, 2, 2, 0, 2, 1, 2, 2 };
	GameOfLife gol(4, 4, a, 10);
	cout << gol;
	gol.advance();
	cout << gol;
	for (int i = 0; i < 3; i++)
	{
		cout << gol;
		gol.advance();
	}
	return 0;
}
