#include <iostream>
#include "DynamicArray.h"

int main()
{
	DynamicArray arr{};
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	for (int i{ 0 }; i < arr.size(); ++i)
	{
		std::cout << arr[i] << ' ';
	}

	return 0;
}