// M3. NumberArray Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include "NumberArray.h"
using namespace std;

int main()
{
	cout << "\nNumberArray<int>\n";
	NumberArray<int> a(4);

	for (int b = 0; b < 4; b++)
	{
		a.setNumber(b, b * 2);
	}
	a.print();

	cout << "\nNumberArray<double>\n";
	NumberArray<double> e(4);
	e.setNumber(0, 1.50);
	e.setNumber(1, 3.65);
	e.setNumber(2, 5.47);
	e.setNumber(3, 6.98);
	e.print();

	cout << "\nCopy Constructor\n";
	NumberArray<int> c(a);
	c.print();

	cout << "\nException Handling\n";
	try
	{
		a.getNumber(50);
	}
	catch (const out_of_range& d)
	{
		cout << "Exception cuaght: " << d.what() << endl;
	}

	return 0;
}


