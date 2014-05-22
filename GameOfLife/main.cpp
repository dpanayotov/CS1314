/*
 * main.cpp
 *
 *  Created on: May 20, 2014
 *      Author: dpanayotov
 */

//googled Thread Sleep
#include "GameOfLife.h"
#include <windows.h>
#include <cstdlib>
using namespace std;

int main()
{
	int a[12] =
	{ 0, 1, 1, 2, 2, 0, 2, 1, 2, 2 };
	GameOfLife gol(4, 4, a, 10);
	while (1)
	{
		cout << gol;
		Sleep(300);
		system("CLS");
		gol.advance();
		if (GetAsyncKeyState(VK_UP))
		{
			break;
		}
	}

	return 0;
}
