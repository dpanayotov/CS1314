/*
 * Time.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#include "Time.h"

using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0)
{

}

Time::Time(int newHours, int newMinutes, int newSeconds)
{
	hours = newHours;
	minutes = newMinutes;
	seconds = newSeconds;
}

Time::Time(const Time& other)
{
	hours = other.hours;
	minutes = other.minutes;
	seconds = other.seconds;
}

Time& Time::operator=(const Time& other)
{
	if(this != &other)
	{
		hours = other.hours;
		minutes = other.minutes;
		seconds = other.seconds;
	}
	return *this;
}

bool Time::operator<(const Time& other)
{
	if(hours<other.hours)
	{
		return true;
	}
	else if(minutes < other.minutes)
	{
		return true;
	}
	else if(seconds < other.seconds)
	{
		return true;
	}
	return false;
}

bool Time::operator>(const Time& other)
{
	if(hours>other.hours)
	{
		return true;
	}
	else if(minutes > other.minutes)
	{
		return true;
	}
	else if(seconds > other.seconds)
	{
		return true;
	}
	return false;
}

void Time::printTime() const
{
	cout<<hours<<':'<<minutes<<':'<<seconds<<' ';
}
