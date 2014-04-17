/*
 * Flight.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#include "Flight.h"
using namespace std;

Flight::Flight()
{
	departure = FlightTime();
	arrival = FlightTime();
	id = 0;
	from = new char[1];
	from = '\0';
	to = new char[1];
	to = '\0';
}

Flight::Flight(FlightTime newDeparture, FlightTime newArrival, char* newFrom, char* newTo, int newId)
{
	departure = newDeparture;
	arrival = newArrival;
	from = new char[strlen(newFrom) + 1];
	strcpy(from, newFrom);
	to = new char[strlen(newTo) + 1];
	strcpy(to, newTo);
	id = newId;
}

Flight::Flight(const Flight& other)
{
	departure = other.departure;
	arrival = other.arrival;
	from = new char[strlen(other.from)+ 1];
	strcpy(from, other.from);
	to = new char[strlen(other.to)+1];
	strcpy(to, other.to);
	id = other.id;
}

Flight& Flight::operator =(const Flight& other)
{
	if(this != &other)
	{
		departure = other.departure;
		arrival = other.arrival;
		strcpy(from, other.from);
		strcpy(to, other.to);
		id = other.id;
	}
	return *this;
}

Flight::~Flight()
{
	delete from;
	delete to;
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
