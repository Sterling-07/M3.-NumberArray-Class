
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
	else 
	{
		size = size;
	}
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
	if (index >= 0 && index < size)
	{
		return data[index];
	}
	else
	{
		cout << "There was an error, the index is out of bounds.\n";
	}
}

double NumberArray::getMin() const
{
	double min = 0;
	for (int a = 0; a < size; a++)
	{
		if (data[a] < min)
		{
			min = data[a];
		}
	}
	return min;
}

double NumberArray::getMax() const
{
	double max = 0;
	for (int a = 0; a < size; a++)
	{
		if (data[a] > max)
		{
			max = data[a];
		}
	}
	return max;
}

double NumberArray::getAverage() const
{
	double total;
	for (int a = 0; a < size; a++)
	{
		total += data[a];
	}
	return total/size;
}

void NumberArray::print() const
{
	cout << "Array Information:\n";
	for (int a = 0; a < size; a++)
	{
		cout << data[a] << " ";
	}
}
