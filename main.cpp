#include <iostream>
#include "DynamicArray.h"

DynamicArray createArray()
{
	DynamicArray arr{ 1, 2, 3, 4 };
	return arr;
}

int main()
{
	DynamicArray a{ createArray()};
	DynamicArray b{ std::move(a) };

	for (int i{ 0 }; i < b.size(); ++i)
	{
		std::cout << b[i] << ' ';
	}

	return 0;
}