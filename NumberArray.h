#pragma once

#include <array>
using namespace std;

class NumberArray 
{
	private:
		int size;
		static const int MAX_SIZE = 10;
		double* data;

	public:
		NumberArray(int size = MAX_SIZE);

		~NumberArray();

		void setNumber(int index, double value);

		double getNumber(int index) const;

		double getMin() const;
		double getMax() const;
		double getAverage() const;

		void print() const;
};