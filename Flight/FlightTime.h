/*
 * FlightTime.h
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#ifndef FLIGHTTIME_H_
#define FLIGHTTIME_H_
#include <iostream>
#include "Date.h"
#include "Time.h"

class FlightTime
{
	Date date;
	Time time;
public:
	FlightTime();
	FlightTime(Date, Time);
	FlightTime(const FlightTime&);
	FlightTime&operator=(const FlightTime&);
	bool operator<(const FlightTime&);
	bool operator>(const FlightTime&);
	void printFlightTime() const;
};

#endif /* FLIGHTTIME_H_ */
