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

	b.pop_back();
	b.pop_back();

	for (const auto& e : b)
	{
		std::cout << e << ' ';
	}

	return 0;
}