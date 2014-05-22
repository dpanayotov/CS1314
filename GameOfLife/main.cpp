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
   int a[80] =
	{       5, 1, 6, 1,
            5, 2, 6, 2,
			5, 11, 6, 11,
            7, 11,4, 12,
            3, 13, 3, 14,
			8, 12, 9, 13, 9, 14,
			6, 15, 6, 18,
			4, 16, 5, 17,
            6, 17, 7, 17,
			3, 21, 3, 22,
			4, 21, 4, 22,
			5, 21, 5, 22,
			2, 23, 2, 25,
			1, 25, 6, 23,
			6, 25, 7, 25,
			3, 35, 3, 36,
			4, 35, 4, 36
	};
	GameOfLife gol(11, 40, a, 70);
	gol.advance();
    while (1)
    {
        cout << gol;
        Sleep(150);
        system("CLS");
        gol.advance();

        if (GetAsyncKeyState(VK_UP))
        {
            break;
        }
    }

	return 0;
}
