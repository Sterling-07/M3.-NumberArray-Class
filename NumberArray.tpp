
#include "NumberArray.h"
#include <iostream>
using namespace std;

template <typename T>
void NumberArray<T>::allocateAndInit(int newSize)
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
		allocateAndInit(10);
	}
	else 
	{
		allocateAndInit(area);
	}
}

template <typename T>
NumberArray<T>::NumberArray(const NumberArray<T>& other)
{
	allocateAndInit(other.size);

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

		allocateAndInit(other.size);

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
	if (index < 0 || index >= size)
	{
		throw out_of_range("The index is out of range.\n");
	}
	
	data[index] = value;
}

template <typename T>
T NumberArray<T>::getNumber(int index) const
{
	if (index < 0 || index >= size)
	{
		throw out_of_range("The index is out of range.\n");
	}
	
	return data[index];
}

template <typename T>
T NumberArray<T>::getMin() const
{
	if (size == 0)
	{
		throw out_of_range("The array is empty.\n");
	}

	T min = data[0];
	for (int a = 1; a < size; a++)
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
	if (size == 0)
	{
		throw out_of_range("The array is empty.\n");
	}

	T max = data[0];
	for (int a = 1; a < size; a++)
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
	if (size == 0)
	{
		throw out_of_range("The array is empty.\n");
	}

	double total = 0;
	for (int a = 0; a < size; a++)
	{
		total += static_cast<double>(data[a]);
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