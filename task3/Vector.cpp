#include "Vector.h"
#include <iostream>
#define MIN_SIZE 2


Vector::Vector(int n = 10)
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