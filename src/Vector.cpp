#pragma once
#include "Vector.h"


Vector::Vector(const size_t& size, const int& value)
    : _size(size) {
    _capacity = 1;
    while (_capacity < size) {
        _capacity *= (_capacity < 128) ?2 : 1.5;
    }
    _data = new int[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = value;
    }
}

Vector::~Vector() {
    if (_data != nullptr)
        delete[] _data;
}

// Copy constructor
Vector::Vector(const Vector& other) {
    *this = other;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other)
        return *this;

    _size = other._size;
    _capacity = other._capacity;
    _data = new int[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = other[i];
    }
    return *this;
}

// Move Constructor
Vector::Vector(Vector&& other) noexcept
    : _size(0), _capacity(0), _data(nullptr)
{
    if (this != &other) {
        swap(other);
    }
}

// Move Assignment Operator
Vector& Vector::operator=(Vector&& other) noexcept
{
    if (this != &other) {
        swap(other);
    }
    return *this;
}

// Access operator
int& Vector::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

const int& Vector::operator[](int index) const {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

int* Vector::data() const {
    return _data;
}

bool Vector::empty() const {
    return _size == 0;
}

size_t Vector::size() const {
    return _size;
}

void Vector::reserve(const size_t& new_cap) {
    if (new_cap > _capacity) {
        int* new_data = new int[new_cap];
        for (size_t i = 0; i < _size; i++) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_cap;
    }
}

size_t Vector::capacity() const {
    return _capacity;
}

void Vector::clear() {
    _size = 0;
}

void Vector::resize(const size_t& count, const int& value) {
    if (count < _size) {
        _size = count;
    }
    else if (count > _size) {
        reserve(count);
        for (std::size_t i = _size; i < count; i++) {
            push_back(value);
        }
    }
}

void Vector::push_back(int value) {
    if (_size >= _capacity) {
        size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
        reserve(new_capacity);
    }
    _data[_size++] = value;
}

void Vector::pop_back() {
    if (_size > 0) {
        _size--;
    }
}

void Vector::swap(Vector& other) {
    int* temp_data = _data;
    size_t temp_size = _size;
    size_t temp_capacity = _capacity;
    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;
    other._data = temp_data;
    other._size = temp_size;
    other._capacity = temp_capacity;
}

void Vector::erase(size_t index) {
    if (index < _size) {
        // shift elements to the left
        for (size_t i = index + 1; i < _size; i++) {
            _data[i - 1] = _data[i];
        }
        _size--;
    }
}

void Vector::insert(size_t index, int value) {
    if (index <= _size) {
        if (_size >= _capacity) {
            size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
            reserve(new_capacity);
        }
        // shift elements to the right
        for (size_t i = _size; i > index; i--) {
            _data[i] = _data[i - 1];
        }
        _data[index] = value;
        _size++;
    }
}

bool Vector::operator==(const Vector& other) const {
    if ((*this).size() != other.size()) {
        return false;
    }
    else {
        for (size_t i = 0; i < (*this).size(); i++) {
            if ((*this)[i] != other[i]) {
                return false;
            }
        }
        return true;
    }
}



bool operator!=(const Vector& lhs, const Vector& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Vector& lhs, const Vector& rhs) {
    size_t min_size = (lhs.size() < rhs.size()) ? lhs.size() : rhs.size();
    for (size_t i = 0; i < min_size; i++) {
        if (lhs[i] < rhs[i]) {
            return true;
        }
        else if (lhs[i] > rhs[i]) {
            return false;
        }
    }
    return lhs.size() < rhs.size();
}

bool operator<=(const Vector& lhs, const Vector& rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>(const Vector& lhs, const Vector& rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const Vector& lhs, const Vector& rhs) {
    return !(lhs < rhs);
}

//std::strong_ordering Vector::operator<=>(const Vector& other) const {
//    if (*this < other) {
//        return std::strong_ordering::less;
//    }
//    else if (*this > other) {
//        return std::strong_ordering::greater;
//    }
//    else {
//        return std::strong_ordering::equal;
//    }
//}