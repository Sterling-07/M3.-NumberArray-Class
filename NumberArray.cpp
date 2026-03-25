
#include "NumberArray.h"
#include <array>
#include <iostream>
using namespace std;

NumberArray::NumberArray(int area)
{
	if (area <= 0)
	{
		size = MAX_SIZE;
	}
	else 
	{
		size = area;
	}

	data = new double[size];
	for (int a = 0; a < size; a++)
	{
		data[a] = 0.0;
	}
}

NumberArray::NumberArray(const NumberArray& other)
{
	size = other.size;
	data = new double[size];

	for (int a = 0; a < size; a++)
	{
		data[a] = other.data[a];
	}
}

NumberArray::~NumberArray()
{
	delete[] data;
	cout << "Destructor has released its memory.\n";
}

NumberArray& NumberArray::operator=(const NumberArray& other)
{
	if (this == &other)
	{
		delete[] data;

		size = other.size;
		data = new double[size];

		for (int a = 0; a < size; a++)
		{
			data[a] = other.data[a];
		}
		return *this;
	}
}

void NumberArray::setNumber(int index, double value)
{
	if (index >= 0 && index < size)
	{
		data[index] = value;
	}
	else
	{
		cout << "setNumber - There was an error, the index is out of bounds.\n";
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
		cout << "getNumber - There was an error, the index is out of bounds.\n";
		return -9999.0;
	}
}

double NumberArray::getMin() const
{
	if (size == 0) return 0;

	double min = data[0];
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
	if (size == 0) return 0;

	double max = data[0];
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
	double total = 0;
	for (int a = 0; a < size; a++)
	{
		total += data[a];
	}
	return total/size;
}

void NumberArray::print() const
{
	cout << "Array Values:\n";
	for (int a = 0; a < size; a++)
	{
		cout << data[a] << " ";
	}
	
	cout << endl;
	cout << "Max value: " << getMax() << endl;
	cout << "Min value: " << getMin() << endl;
	cout << "Average " << getAverage() << endl;
}
