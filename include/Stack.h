#pragma once
#include <Vector.h>
#include <stdexcept>

class Stack : private Vector
{
public:
	/* Constructor */
	explicit Stack(const size_t& size = 0, const int& value = 0);

	/* Copy Constructor */
	Stack(const Stack& other);

	/* Move Constructor */
	Stack(Stack&& other) noexcept;

	/* Destructor */
	~Stack();

	/* Assimengt */
	Stack& operator=(const Stack& other);
	Stack& operator=(Stack&& other) noexcept;

	/* Access */
	int top();

	/* Capacity */
	bool isEmpty() const;
	size_t size() const;

	/* Modifiers */
	void push(int value);
	void pop();

	/* Operators */
	void operator+=(int value);
	void operator-=(int value);
	void operator*=(int value);
	void operator/=(int value);

	bool operator==(const Stack& other) const;

	Stack operator+(const Stack& other);
	Stack& operator+=(const Stack& other);
private:
};

/* Non - member functions */

bool operator!=(const Stack& lhs, const Stack& rhs);
bool operator<(const Stack& lhs, const Stack& rhs);
bool operator<(const Stack& lhs, const Stack& rhs);