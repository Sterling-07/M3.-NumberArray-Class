#pragma once

#include <array>
using namespace std;

template <typename T>
class NumberArray 
{
	private:
		int size;
		T* data;

		void allocateAndInit(int newSize);

	public:
		NumberArray(int size = 10);

		NumberArray(const NumberArray<T>& other);

		~NumberArray();

		NumberArray<T>& operator =(const NumberArray<T>& other);

		void setNumber(int index, T value);

		T getNumber(int index) const;

		T getMin() const;
		T getMax() const;
		double getAverage() const;

		void print() const;
};

#include "NumberArray.tpp"