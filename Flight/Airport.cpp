/*
 * Airport.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#include "Airport.h"
#include <iostream>

using namespace std;

Airport::Airport()
{
	size = 1;
	flights = new Flight[size];
	assert(flights != NULL);
	for(int i=0; i<size; i++)
	{
		Flight f;
		flights[i] = f;
	}
}

Airport::Airport(Flight* newFlights, int size)
{
	this->size = size;
	flights = new Flight[size];
	assert(flights != NULL);
	for(int i=0; i<size; i++)
	{
		flights[i] = newFlights[i];
		flights[i].flightNumber++;
	}
}

Airport::Airport(const Airport& other)
{
	size = other.size;
	flights = new Flight[size];
	assert(flights != NULL);
	for(int i=0; i<size; i++)
	{
		flights[i] = other.flights[i];
		flights[i].flightNumber++;
	}
}

Airport& Airport::operator =(const Airport& other)
{
	if(this != &other)
	{
		size = other.size;
		delete[] flights;
		flights = new Flight[size];
		assert(flights != NULL);
		for(int i=0; i<size; i++)
		{
			flights[i] = other.flights[i];
			flights[i].flightNumber++;
		}
	}
	return *this;
}

Airport::~Airport()
{
	delete[] flights;
}

void Airport::addFlight(Flight newFlight)
{
	Flight* temp = new Flight[size+1];
	assert(temp != NULL);
	for(int i=0; i<size; i++)
	{
		temp[i] = flights[i];
	}
	temp[size] = newFlight;
	temp[size].flightNumber++;
	delete[] flights;
	size++;
	flights = new Flight[size];
	assert(flights != NULL);
	for(int i=0; i<size; i++)
	{
		flights[i] = temp[i];
	}
	delete[] temp;
}

void Airport::removeFlight(int mID)
{
	Flight* temp = new Flight[size-1];
	int k=0;
	for(int i=0; i<size; i++)
	{
		if(flights[i].getID() != mID)
		{
			temp[k] = flights[i];
			temp[k].setID(flights[i].getID()); //workaround because operator= increments id
			k++;
		}
	}
	delete[] flights;
	size--;
	flights = new Flight[size];
	for(int i=0; i<size; i++)
	{
		flights[i] = temp[i];
		flights[i].setID(temp[i].getID());
	}
	delete[] temp;
}

void Airport::flightsFrom(char* mFrom)
{
	cout<<"Flights from "<<mFrom<<':'<<endl;
	for(int i=0; i<size; i++)
	{
		if(strcmp(flights[i].getFrom(), mFrom) == 0)
		{
			flights[i].printFlight();
		}
	}
}

void Airport::flightsTo(char* mTo)
{
	cout<<"\nFlights to "<<mTo<<':'<<endl;
	for(int i=0; i<size; i++)
	{
		if(strcmp(flights[i].getTo(), mTo) == 0)
		{
			flights[i].printFlight();
		}
	}
}

void Airport::sort()
{
	Flight* temp = new Flight[size];
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(flights[i].getDeparture() < flights[j].getDeparture())
			{
				Flight swap = flights[i];
				swap.setID(flights[i].getID());
				flights[i] = flights[j];
				flights[i].setID(flights[j].getID());
				flights[j] = swap;
				flights[j].setID(swap.getID());
			}
		}
	}
}

void Airport::print() const
{
	for(int i=0; i<size; i++)
	{
		flights[i].printFlight();
		cout<<endl;
	}
}
