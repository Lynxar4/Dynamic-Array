#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <initializer_list>

class DynamicArray
{
public:
	DynamicArray(int size)
		: m_length{ size }, m_capacity{size * 2}
	{
		if (size <= 0)
		{
			m_length = 0;
			m_capacity = 2;
		}
		m_array = new int[m_capacity] {};
	}

	DynamicArray()
		:m_length{ 0 }, m_capacity{2}
	{
		m_array = new int[m_capacity] {};
	}

	DynamicArray(const DynamicArray& other)
		: m_length{ other.m_length }, m_capacity{ other.m_capacity }
	{
		m_array = new int[m_capacity] {};
		for (int i{ 0 }; i < other.m_length; ++i)
		{
			m_array[i] = other[i];
		}
	}

	DynamicArray(std::initializer_list<int> list)
		:m_length{ static_cast<int>(list.size())}, m_capacity{m_length * 2}
	{
		if (list.size() == 0)
			m_capacity = 2;
		m_array = new int[m_capacity];

		int index{0};
		for (const auto& e : list)
		{
			m_array[index] = e;
			index++;
		}
	}

	DynamicArray(DynamicArray&& other) noexcept 
		: m_array{ other.m_array }, m_length{other.m_length}, m_capacity{other.m_capacity}
	{
		other.m_array = nullptr;
		other.m_length = 0;
		other.m_capacity = 0;
	}

	DynamicArray& operator=(DynamicArray&& other) noexcept
	{
		swap(other);
		return *this;
	}

	~DynamicArray()
	{
		delete[] m_array;
		std::cout << "Array deleted\n";
	}

	void swap(DynamicArray& other) noexcept 
	{
		int* tempPointer{this->m_array};
		int tempLength{ this->m_length };
		int tempCapacity{ this->m_capacity };

		m_array = other.m_array;
		m_length = other.m_length;
		m_capacity = other.m_capacity;

		other.m_array = tempPointer;
		other.m_length = tempLength;
		other.m_capacity = tempCapacity;
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

	void push_back(int val)
	{
		if (m_length == m_capacity)
			reallocate();

		m_array[m_length] = val;
		++m_length;
	}

	void pop_back()
	{
		if (m_length == 0)
			return;

		--m_length;
	}

	int size() const
	{
		return m_length;
	}

	int* begin()
	{
		return m_array;
	}

	int* end()
	{
		return m_array + m_length;
	}

	const int* begin() const
	{
		return m_array;
	}

	const int* end() const
	{
		return m_array + m_length;
	}

private:
	void reallocate()
	{
		m_capacity = (m_capacity == 0) ? 2 : m_capacity * 2;
		int* newArr = new int[m_capacity];
		for (int i{ 0 }; i < m_length; ++i)
		{
			newArr[i] = m_array[i];
		}
		delete[] m_array;
		m_array = newArr;
	}

	int* m_array{};
	int m_length{};
	int m_capacity{};
};


#endif