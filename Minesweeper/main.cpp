/*
 * main.cpp
 *
 *  Created on: Mar 30, 2014
 *      Author: Dimitar
 */

#include "Cell.h"
#include "Field.h"

int main()
{
    Field f1(2, 2);
    Cell c(-1);
    cout << c.status() << endl;
    f1.flagCell(0, 0);
    f1.helpOpen(0,0);
    cout << f1.isSolved() << endl;
	return 0;
}


