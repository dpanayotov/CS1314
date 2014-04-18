/*
 * Flight.h
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include "FlightTime.h"
#include <cstring>
#include <cassert>
class Flight
{
	FlightTime departure, arrival;
	char* from;
	char* to;
public:
	static int id;
	Flight();
	Flight(FlightTime, FlightTime, char*, char*);
	Flight(const Flight&);
	Flight&operator=(const Flight&);
	~Flight();
	void printFlight() const;
};

#endif /* FLIGHT_H_ */
