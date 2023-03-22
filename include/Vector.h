
#pragma once
#include <stdexcept>

class Vector {
public:
	/* Constructor */
	explicit Vector(const size_t& size = 0, const int& value = 0);

	/* Copy Constructor */
	Vector(const Vector& other);

	/* Move Constructor */
	Vector(Vector&& other) noexcept;
	/* Destructor */
	~Vector();

	/* Assimengt */
	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other) noexcept;

	/* Capacity */
	bool empty() const;
	size_t size() const;
	void reserve(const size_t& new_cap);
	size_t capacity() const;
	
	/* Element Access */
	const int& operator[](int index) const;
	int& operator[](int index);
	int* data() const;
	
	/* Modifiers */
	void clear();
	void resize(const size_t& count = 0, const int& value = 0);

	void pop_back();
	void push_back(int value);
	void erase(size_t index);
	void insert(size_t index, int value);
	
	bool operator==(const Vector& other) const;

private:
	/* Members*/
	int* _data;
	size_t _size;
	size_t _capacity;

	/* Member Functions*/
	void swap(Vector& other);

};

/* Non - member functions */

bool operator!=(const Vector& lhs, const Vector& rhs);
bool operator<(const Vector& lhs, const Vector& rhs);
bool operator<=(const Vector& lhs, const Vector& rhs);
bool operator>(const Vector& lhs, const Vector& rhs);
bool operator>=(const Vector& lhs, const Vector& rhs);
//std::strong_ordering operator<=>(const Vector& other);