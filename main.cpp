#include <iostream>
#include "DynamicArray.h"

int main()
{
	DynamicArray arr{ 1, 2, 3, 4 };

	for (int i{ 0 }; i < arr.size(); ++i)
	{
		std::cout << arr[i] << ' ';
	}

	return 0;
}