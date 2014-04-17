/*
 * date.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#include "date.h"

using namespace std;

Date::Date() : day(0), month(0), year(0)
{
}

Date::Date(int newDay, int newMonth, int newYear)
{
	if(validDate(newDay, newMonth, newYear))
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}
}

Date::Date(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}

Date& Date::operator=(const Date& other)
{
	if(this != &other)
	{
		day = other.day;
		month = other.month;
		year = other.year;
	}
	return *this;
}

bool Date::validDate(int newDay, int newMonth, int newYear)
{
	if(newDay>0 && newDay<=31 && newMonth <=12 && newMonth>0)//no check if year is leap or in which month we are
	{
		return true;
	}
	return false;
}

void Date::printDate() const
{
	cout<<day<<'.'<<month<<'.'<<year;
}
