/*
 * Airport.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: Dimitar
 */

#include "Airport.h"
#include <iostream>


Airport::Airport()
{
	flights = new Flight[1];
	flights[0] = Flight();
}
