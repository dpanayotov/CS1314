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
	cout<<gol;
	cout<<gol.getCell(1,1);
	return 0;

}


