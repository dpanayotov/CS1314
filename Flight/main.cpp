/*
 * main.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */
#include "Flight.h"
#include <iostream>

using namespace std;

int main()
{
	Date date(1,2,3);
	Time time(9,8,7);
	FlightTime ft(date, time);
	Flight f(ft, ft, "buras", "sofia", 2);
	f.printFlight();

	return 0;
}



