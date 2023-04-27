#pragma once
#include "Stack.h"


Stack::Stack(const size_t& size, const int& value)
	:Vector::Vector(size, value)
{
}

// Copy constructor
Stack::Stack(const Stack& other) {
	*this = other;//use Vector Copy Assiment
}

// Move Constructor
Stack::Stack(Stack&& other) noexcept
{
	Vector::operator=(other);
}

Stack::~Stack()
{
}

/* Assimengt */
Stack& Stack::operator=(const Stack& other)
{
	Vector::operator=(other);
	return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept
{
	Vector::operator=(other);
	return *this;
}

int Stack::top()
{
	size_t index = size() - 1;
	if (index < 0 || index >= size()) {
		throw std::out_of_range("Index out of bounds");
	}
	return (*this)[index];
}

/* Capacity */
bool Stack::isEmpty() const
{
	return empty();
}

size_t Stack::size() const
{
	return Vector::size();
}

/* Modifiers */
void Stack::push(int value)
{
	push_back(value); // invoke base class push_back function
}

void Stack::pop()
{
	pop_back(); 
}



/* Comparison operators */
bool Stack::operator==(const Stack& other) const
{
	return Vector::operator==( other);
}

bool operator!=(const Stack& lhs, const Stack& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Stack& lhs, const Stack& rhs)
{
	return  lhs.size() < rhs.size();
}

bool operator>(const Stack& lhs, const Stack& rhs)
{
	return  lhs.size() > rhs.size();
}

/* Arithmetic operators */
void Stack::operator+=(int value) 
{
	const size_t size = Vector::size();
	for (size_t i = 0; i < size; i++)
	{
		(*this)[i] += value;
	}
}

void Stack::operator-=(int value)
{
	*this += -value;
}

void Stack::operator*=(int value)
{
	const size_t size = Vector::size();
	for (size_t i = 0; i < size; i++)
	{
		(*this)[i] *= value;
	}
}

void Stack::operator/=(int value)
{
	const size_t size = Vector::size();
	for (size_t i = 0; i < size; i++)
	{
		(*this)[i] /= value;
	}

}



/* Chain operators */
Stack Stack::operator+(const Stack& other)
{
	Stack result;

	for (int i = 0; i < size(); i++)
	{
		result.push((*this)[i]);
	}

	for (int i = 0; i < other.size(); i++)
	{
		result.push(other[i]);
	}
	return result;
}

Stack& Stack::operator+=(const Stack& other)
{
	for (int i = 0; i < other.size(); i++)
	{
		push(other[i]);
	}

	return *this;
}