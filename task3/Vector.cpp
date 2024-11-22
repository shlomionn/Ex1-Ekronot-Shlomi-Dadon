#include "Vector.h"
#include <iostream>
#define MIN_SIZE 2

Vector::Vector(int n)
{
	if (n < MIN_SIZE)
	{
		_elements = new int[MIN_SIZE];
		_capacity = MIN_SIZE;
		_resizeFactor = MIN_SIZE;
	}
	else
	{
		_elements = new int[n];
		_capacity = n;
		_resizeFactor = n;
	}
	_size = 0;
}

Vector::~Vector()
{
	delete[] _elements;
	_elements = nullptr;
}

//return size of vector
int Vector::size() const
{
	return _size;
}

//return  of vector
int Vector::capacity() const
{
	return _capacity;
}

//return resizeFactor of vector
int Vector::resizeFactor() const
{
	return _resizeFactor;
}

//returns true if size = 0
bool Vector::empty() const
{
	return _size == 0;
}
//change the capacity
void Vector::reserve(const int n)
{
	int i = 0;
	int* arr = nullptr;
	if (_capacity < n)
	{
		while (_capacity < n)
		{
			_capacity += _resizeFactor;
		}
		arr = new int[_capacity];
		for (i = 0; i < _size; i++)
		{
			arr[i] = _elements[i];
		}
		this->~Vector();
		_elements = arr;
	}
}

//adds element at the end of the vector
void Vector::push_back(const int& val)
{
	this->reserve(_size + 1);
	_elements[_size] = val;
	_size++;
}

//removes and returns the last element of the vector
int Vector::pop_back()
{
	int temp = 0;
	if (_size == 0)
	{
		std::cout << "error: pop from empty vector" << std::endl;
		return -9999;
	}
	temp = _elements[_size - 1];
	_elements[_size - 1] = NULL;
	_size--;
	return temp;
}

//change _size to n, unless n is greater than the vector's capacity
void Vector::resize(int n)
{
	int i = 0;
	this->reserve(n);
	if (n > _size)
	{
		for (i = _size; i < n; i++)
		{
			_elements[i] = 0; //how can my program tell if it's deleted or newly created? hope you can answer me next time
		}
	}
	else
	{
		for (i = n; i < _size; i++)
		{
			_elements[i] = NULL;
		}
	}
	_size = n;
}

//assigns val to all elemnts
void Vector::assign(const int val)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		_elements[i] = val;
	}
}

//same as above, if new elements added their value is val
void Vector::resize(const int n, const int& val)
{
	int i = 0;
	this->reserve(n);
	if (n > _size)
	{
		for (i = _size; i < n; i++)
		{
			_elements[i] = val;
		}
	}
	else
	{
		for (i = n; i < _size; i++)
		{
			_elements[i] = NULL;
		}
	}
	_size = n;
}

