#pragma once

#include <array>
using namespace std;

template <typename T>
class NumberArray 
{
	private:
		int size;
		T* data;

	public:
		NumberArray(int size = 10);

		NumberArray(const NumberArray& other);

		~NumberArray();

		NumberArray& operator =(const NumberArray& other);

		void setNumber(int index, double value);

		double getNumber(int index) const;

		double getMin() const;
		double getMax() const;
		double getAverage() const;

		void print() const;
};