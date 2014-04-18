/*
 * Flight.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#include "Flight.h"
using namespace std;

int Flight::id=0;
Flight::Flight()
{
	departure = FlightTime();
	arrival = FlightTime();
	from = new char[1];
	assert(from != NULL);
	from = '\0';
	to = new char[1];
	assert(to != NULL);
	to = '\0';
	id++;
}

Flight::Flight(FlightTime newDeparture, FlightTime newArrival, char* newFrom, char* newTo)
{
	departure = newDeparture;
	arrival = newArrival;
	from = new char[strlen(newFrom) + 1];
	strcpy(from, newFrom);
	to = new char[strlen(newTo) + 1];
	strcpy(to, newTo);
	id++;
}

Flight::Flight(const Flight& other)
{
	departure = other.departure;
	arrival = other.arrival;
	from = new char[strlen(other.from)+ 1];
	strcpy(from, other.from);
	to = new char[strlen(other.to)+1];
	strcpy(to, other.to);
	id++;
}

Flight& Flight::operator =(const Flight& other)
{
	if(this != &other)
	{
		departure = other.departure;
		arrival = other.arrival;
		delete[] from;
		delete[] to;
		from = new char[strlen(other.from)+1];
		assert(from != NULL);
		to = new char[strlen(other.to)+1];
		assert(to != NULL);
		strcpy(from, other.from);
		strcpy(to, other.to);
		id++;
	}
	return *this;
}

Flight::~Flight()
{
	delete[] from;
	delete[] to;
}

void Flight::printFlight() const
{
	cout<<"Flight ID: "<<id<<endl;
	cout<<"From: "<<from<<endl;
	cout<<"To: "<<to<<endl;
	cout<<"Departure: ";
	departure.printFlightTime();
	cout<<endl;
	cout<<"Arrival: ";
	arrival.printFlightTime();
	cout<<endl;

}
