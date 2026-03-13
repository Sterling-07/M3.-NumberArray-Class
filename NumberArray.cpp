
#include "NumberArray.h"
#include <array>
#include <iostream>
using namespace std;

NumberArray::NumberArray(int size)
{
	if (size <= 0)
	{
		size = MAX_SIZE;
	}
	size = size;

}

NumberArray::~NumberArray()
{
	delete[] data;
	cout << "Destructor has released its memory.\n";
}

void NumberArray::setNumber(int index, double value)
{
	if (index >= 0 && index < size)
	{
		data[index] = value;
	}
	else
	{
		cout << "There was an error, the index is out of bounds.\n";
	}
}

double NumberArray::getNumber(int index) const
{

	return 0.0;
}
