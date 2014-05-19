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
	GameOfLife gol;
	for(int i=0; i<10; i++)
	{
		cout<<gol;
		gol.advance();
	}
	return 0;

}


