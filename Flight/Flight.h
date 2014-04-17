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
class Flight
{
	FlightTime departure, arrival;
	int id;
	char* from;
	char* to;
public:
	Flight();
	Flight(FlightTime, FlightTime, char*, char*, int);
	Flight(const Flight&);
	Flight&operator=(const Flight&);
	~Flight();
	void printFlight() const;
};

#endif /* FLIGHT_H_ */
