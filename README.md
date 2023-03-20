# Vector and Stack Classes

This project implements a simple `Vector` and `Stack` class in C++. The `Vector` class provides dynamic array functionality, while the `Stack` class implements a stack data structure using the `Vector` class as the underlying container.

## Author
**Ori Vered**

## Features

### Vector class

1. Constructors: default, size and value, and copy
2. Move constructor
3. Destructor
4. Assignment and move assignment operators
5. Capacity related methods: `empty`, `size`, `reserve`, and `capacity`
6. Element access methods: `operator[]` and `data`
7. Modifiers: `clear`, `resize`, `pop_back`, `push_back`, `erase`, and `insert`
8. Comparison operators: `==`, `!=`, `<`, `<=`, `>`, and `>=`

### Stack class

1. Constructors: default, size and value, and copy
2. Move constructor
3. Destructor
4. Assignment and move assignment operators
5. Access: `top`
6. Capacity related methods: `isEmpty`, `size`
7. Modifiers: `push`, `pop`
8. Arithmetic and comparison operators: `+=`, `-=`, `*=`, `/=`, `==`, `+`, and `+=`

## Usage

1. Download or clone this repository.
2. Include the header files `Vector.h` and `Stack.h` in your project.
3. Create instances of the `Vector` and `Stack` classes and utilize their methods as per your requirements.

## Example

```cpp
#include "Vector.h"
#include "Stack.h"

int main() {
    // Create a Vector object with 3 elements, all set to 4
    Vector vec(3, 4);

    // Access the second element and print it
    std::cout << "Second element of vec: " << vec[1] << std::endl;

    // Create a Stack object and push some elements
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Pop the top element and print the new top element
    stack.pop();
    std::cout << "Top element of stack: " << stack.top() << std::endl;

    return 0;
}
