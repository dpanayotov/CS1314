/*
 * Field.h
 *
 *  Created on: Mar 30, 2014
 *      Author: Dimitar
 */

#ifndef FIELD_H_
#define FIELD_H_

#include "Cell.h"
using namespace std;

class Field
{
	int width, height;
	Cell** cells;
public:
	Field();
	Field(int,int);
	Field(const Field&);
	Field&operator=(const Field&);
	~Field();
	void openCell(int, int);
	void flagCell(int, int);
	void unflagCell(int, int);
	bool isSolved();
	void del();
	bool inBounds(int, int);
	void helpOpen(int, int);
};

#endif /* FIELD_H_ */
