/*
 * Airport.h
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#ifndef AIRPORT_H_
#define AIRPORT_H_
#include "Flight.h"
class Airport
{
	Flight* flights;
	static int flightNumber;
public:
	Airport();
	Airport(Flight*);
	Airport(const Airport&);
	Airport&operator=(const Airport&);
	~Airport();
	void addFlight(Flight);
	void removeFlight(Flight);
	Flight* flightsFrom(char*);
	Flight* flightsTo(char*);
	void sort();
	void print() const;

};

#endif /* AIRPORT_H_ */
