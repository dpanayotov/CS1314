/*
 * main.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */
#include "Airport.h"
#include <iostream>

using namespace std;

int main()
{
	Date date(1,2,3);
	Time time(9,8,7);
	Time time1(1,2,3);
	FlightTime ft(date, time);
	FlightTime ft1(date, time1);
	char from[32] = "sofia";
	char to[32] = "burgas";
	Flight f[2];
	Flight f1(ft, ft, from, to);
	f[0] = Flight(ft, ft, from, to);
	f[1] = Flight(ft1, ft1, to, from);
	Airport air(f,2);
	air.print();
	cout<<"Sorted"<<endl;
	air.sort();
	air.print();
	return 0;
}



