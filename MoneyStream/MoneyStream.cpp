/*
 * MoneyStream.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: Dimitar
 */

#include "MoneyStream.h"

MoneyStream::MoneyStream()
{
	srand(time(0));
	size = 1;
	stream = new double[size];
	assert(stream != NULL);
	for(int i=0; i<size; i++)
	{
		stream[i] = 1000 * ( (double)rand() / (double)RAND_MAX);
	}
}
 MoneyStream::MoneyStream(int newSize)
 {
	 srand(time(0));
	 size = newSize;
	 stream = new double[size];
	 assert(stream != NULL);
	 for(int i=0; i<size; i++)
	 {
		 stream[i] = 1000 * ( (double)rand() / (double)RAND_MAX);
	 }
 }

 MoneyStream::MoneyStream(const MoneyStream& newStream)
 {
	 size = newStream.size;
	 stream = new double[size];
	 assert(stream != NULL);
	 for(int i=0; i<size; i++)
	 {
		 stream[i] = 10000 * ( (double)rand() / (double)RAND_MAX);
	 }
 }

MoneyStream& MoneyStream::operator=(const MoneyStream& newStream)
{
	if(this != &newStream)
	{
		if(stream != NULL)
		{
			delete[] stream;
		}
		size = newStream.size;
		stream = new double[size];
		assert(stream != NULL);
		for(int i=0; i<size; i++)
		{
			stream[i] = newStream.stream[i];
		}
	}
	return *this;
}

MoneyStream::~MoneyStream()
{
	delete[] stream;
}

int MoneyStream::getSize() const
{
	return size;
}

double MoneyStream::getValue(int index)
{
	if(isAvailable(index))
	{
		double temp = stream[index];
		stream[index] = 0;
		return temp;
	}
	return -1;
}

bool MoneyStream::isAvailable(int index)
{
	if(stream[index]==0)
	{
		return false;
	}
	return true;
}

bool MoneyStream::hasAvailable()
{
	for(int i=0; i<size; i++)
	{
		if(stream[i]!=0)
		{
			return true;
		}
	}
	return false;
}
