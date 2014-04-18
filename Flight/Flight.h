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
	int id;
public:
	static int flightNumber;
	Flight();
	Flight(FlightTime, FlightTime, char*, char*);
	Flight(const Flight&);
	Flight&operator=(const Flight&);
	~Flight();
	void printFlight() const;
	int getID() const;
	char* getFrom() const;
	char* getTo() const;
	void setID(int);
	FlightTime getDeparture() const;
};

#endif /* FLIGHT_H_ */
