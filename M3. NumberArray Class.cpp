// M3. NumberArray Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include "NumberArray.h"
using namespace std;

int main()
{
	int size = 10;
	random_device engine;
	uniform_real_distribution<double> randomNum(0.0, 10.0);
	NumberArray arr(size);

	for (int a = 0; a < size; a++)
	{
		arr.setNumber(a, randomNum(engine));
	}

	arr.print();
	cout << endl;

	return 0;
}


