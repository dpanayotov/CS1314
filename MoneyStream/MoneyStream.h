/*
 * MoneyStream.h
 *
 *  Created on: Mar 26, 2014
 *      Author: Dimitar
 */

#ifndef MONEYSTREAM_H_
#define MONEYSTREAM_H_

#include <iostream>
#include <stdlib.h> //random
#include <cassert>
#include <cstring>
#include <sstream>
#include <ctime> //even more randomness

using namespace std;

class MoneyStream
{
	double* stream;
	int size;
public:
	MoneyStream();
	MoneyStream(int);
	MoneyStream(const MoneyStream&);
	MoneyStream&operator=(const MoneyStream&);
	~MoneyStream();
	int getSize() const;
	double getValue(int);
	bool isAvailable(int);
	bool hasAvailable();
};



#endif /* MONEYSTREAM_H_ */
