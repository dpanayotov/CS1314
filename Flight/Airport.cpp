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
		flights[i].id++;
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
		flights[i].id++;
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
			flights[i].id++;
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
	temp[size].id++;
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
	for(int i=0; i<size; i++)
	{
		if(flights[i].id != mID)
		{
			temp[i] = flights[i];
		}
	}

	delete[] flights;
	size--;
	flights = new Flight[size];
	for(int i=0; i<size; i++)
	{
		flights[i] = temp[i];
	}
	delete[] temp;
}


void Airport::print() const
{
	for(int i=0; i<size; i++)
	{
		flights[i].printFlight();
		cout<<endl;
	}
}
