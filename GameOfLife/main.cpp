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
	int alive[8] = {1,2,3,4,5,6,7,8};
	GameOfLife gol;
	cout<<gol;
	cout<<endl;
	gol.advance();
	gol.advance();
	gol.advance();
	return 0;

}


