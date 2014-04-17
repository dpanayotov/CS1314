/*
 * date.h
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#ifndef DATE_H_
#define DATE_H_
#include <iostream>
class Date
{
	int day, month, year;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	Date&operator=(const Date&);
	void printDate() const;
	bool validDate(int, int, int);
};

#endif /* DATE_H_ */
