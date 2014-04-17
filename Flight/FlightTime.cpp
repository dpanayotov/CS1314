/*
 * FlightTime.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#include "FlightTime.h"

using namespace std;

FlightTime::FlightTime()
{
	date = Date();
	time = Time();
}

FlightTime::FlightTime(Date newDate, Time newTime)
{
	date = newDate;
	time = newTime;
}

FlightTime::FlightTime(const FlightTime& other)
{
	date = other.date;
	time = other.time;
}

FlightTime& FlightTime::operator=(const FlightTime& other)
{
	if(this != &other)
	{
		date = other.date;
		time = other.time;
	}
	return *this;
}

void FlightTime::printFlightTime() const
{
	time.printTime();
	date.printDate();
}
