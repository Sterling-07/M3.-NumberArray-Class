
#include "NumberArray.h"
#include <array>
#include <iostream>
using namespace std;

template <typename T>
void NumberArray<T>::allocateAndInint(int newSize)
{
	size = newSize;
	data = new T[size];

	for (int a = 0; a < size; a++)
	{
		data[a] = T{};
	}
}

template <typename T>
NumberArray<T>::NumberArray(int area)
{
	if (area <= 0)
	{
		aalocateAndInint(10);
	}
	else 
	{
		allocateAndInint(area);
	}

	data = new double[size];
	for (int a = 0; a < size; a++)
	{
		data[a] = 0.0;
	}
}

template <typename T>
NumberArray<T>::NumberArray(const NumberArray<T>& other)
{
	allocateAndInint(other.size);

	for (int a = 0; a < size; a++)
	{
		data[a] = other.data[a];
	}
}

template <typename T>
NumberArray<T>::~NumberArray()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

template <typename T>
NumberArray<T>& NumberArray<T>::operator=(const NumberArray<T>& other)
{
	if (this != &other)
	{
		delete[] data;

		size = other.size;
		data = new double[size];

		for (int a = 0; a < size; a++)
		{
			data[a] = other.data[a];
		}
	}
	return *this;
}

template <typename T>
void NumberArray<T>::setNumber(int index, T value)
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

template <typename T>
T NumberArray<T>::getNumber(int index) const
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

template <typename T>
T NumberArray<T>::getMin() const
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

template <typename T>
T NumberArray<T>::getMax() const
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

template <typename T>
double NumberArray<T>::getAverage() const
{
	double total = 0;
	for (int a = 0; a < size; a++)
	{
		total += data[a];
	}
	return total/size;
}

template <typename T>
void NumberArray<T>::print() const
{
	cout << "Array Values:\n";
	for (int a = 0; a < size; a++)
	{
		cout << data[a] << " ";
	}
	
	cout << endl;
	cout << "Max value: " << getMax() << endl;
	cout << "Min value: " << getMin() << endl;
	cout << "Average: " << getAverage() << endl;
}
