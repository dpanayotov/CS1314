/*
 * Time.h
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#ifndef TIME_H_
#define TIME_H_
#include <iostream>

class Time
{
	int hours, minutes, seconds;
public:
	Time();
	Time(int, int, int);
	Time(const Time&);
	Time&operator=(const Time&);
	bool operator<(const Time&);
	bool operator>(const Time&);
	void printTime() const;
};

#endif /* TIME_H_ */
