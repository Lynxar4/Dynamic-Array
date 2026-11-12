#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray
{
public:
	DynamicArray(int size)
		: m_length{ size }
	{
		if (m_length > 0)
			m_array = new int[m_length];
		else
			m_array = nullptr;
	}

	DynamicArray()
		:m_length{ 0 }
	{
		m_array = nullptr;
	}

	DynamicArray(const DynamicArray& other)
		: m_length{ other.m_length }
	{
		m_array = new int[m_length];
		for (std::size_t i{ 0 }; i < other.m_length; ++i)
		{
			m_array[i] = other[i];
		}
	}

	void swap(DynamicArray& other)
	{
		int* tempPointer{this->m_array};
		int tempLength{ this->m_length };
		m_array = other.m_array;
		m_length = other.m_length;
		other.m_array = tempPointer;
		other.m_length = tempLength;
	}

	DynamicArray& operator=(const DynamicArray& other)
	{
		DynamicArray temp{ other };
		swap(temp);
		return *this;
	}

	int& operator[](int index)
	{
		return m_array[index];
	}

	const int& operator[](int index) const
	{
		return m_array[index];
	}

	~DynamicArray()
	{
		delete[] m_array;
		std::cout << "Array deleted";
	}

private:
	int* m_array{};
	int m_length{};
};


#endif