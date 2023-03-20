
#include <iostream>
#include "Vector.h"
#include "Stack.h"

int main() {
    // Default constructor
    Vector vec1;
    std::cout << "vec1: size=" << vec1.size() << ", capacity=" << vec1.capacity() << std::endl;

    // Constructor with size and value
    Vector vec2(5, 1);
    std::cout << "vec2: size=" << vec2.size() << ", capacity=" << vec2.capacity() << std::endl;
    std::cout << "vec2 contents: ";
    for (int i = 0; i < vec2.size(); i++) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    // Constructor with size and array
    int arr[3] = { 2, 4, 6 };
    Vector vec3(3, 4);
    std::cout << "vec3: size=" << vec3.size() << ", capacity=" << vec3.capacity() << std::endl;
    std::cout << "vec3 contents: ";
    for (int i = 0; i < vec3.size(); i++) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    // Copy constructor
    Vector vec4 = vec2;
    std::cout << "vec4: size=" << vec4.size() << ", capacity=" << vec4.capacity() << std::endl;
    std::cout << "vec4 contents: ";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Assignment operator
    Vector vec5;
    vec5 = vec3;
    std::cout << "vec5: size=" << vec5.size() << ", capacity=" << vec5.capacity() << std::endl;
    std::cout << "vec5 contents: ";
    for (int i = 0; i < vec5.size(); i++) {
        std::cout << vec5[i] << " ";
    }
    std::cout << std::endl;

    // Move Constructor
    auto vec6 = std::move(vec3); 
    std::cout << "vec6 after move Constructor with vec3: size=" << vec6.size() << ", capacity=" << vec6.capacity() << std::endl;
    std::cout << "vec6 contents: ";
    for (int i = 0; i < vec6.size(); i++) {
        std::cout << vec6[i] << " ";
    }
    std::cout << std::endl;

    // Move assigment
    vec3 = std::move(Vector(3, 4)); 
    std::cout << "vec3 after move with (4,4,4): size=" << vec3.size() << ", capacity=" << vec3.capacity() << std::endl;
    std::cout << "vec3 contents: ";
    for (int i = 0; i < vec3.size(); i++) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    // Empty
    std::cout << "vec1 is empty: " << vec1.empty() << std::endl;

    // Size
    std::cout << "vec2 size: " << vec2.size() << std::endl;

    // Reserve
    vec2.reserve(10);
    std::cout << "vec2 after reserve: size=" << vec2.size() << ", capacity=" << vec2.capacity() << std::endl;

    // Capacity
    std::cout << "vec3 capacity: " << vec3.capacity() << std::endl;

    // Operator[]
    std::cout << "vec4[1]: " << vec4[1] << std::endl;

    // Data
    int* data_ptr = vec3.data();
    std::cout << "vec3 data pointer: " << data_ptr << ", contents: ";
    for (int i = 0; i < vec3.size(); i++) {
        std::cout << *(data_ptr + i) << " ";
    }
    std::cout << std::endl;

    // Clear
    vec4.clear();
    std::cout << "vec4 after clear: size=" << vec4.size() << ", capacity=" << vec4.capacity() << std::endl;

    // Resize
    vec4.resize(3);
    std::cout << "vec4 after resize(3): size=" << vec4.size() << ", capacity=" << vec4.capacity() << ", contents=";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Pop back
    vec4.pop_back();
    std::cout << "vec4 after pop_back: size=" << vec4.size() << ", capacity=" << vec4.capacity() << ", contents=";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Push back
    vec4.push_back(5);
    std::cout << "vec4 after push_back: size=" << vec4.size() << ", capacity=" << vec4.capacity() << ", contents=";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Erase
    vec4.erase(1);
    std::cout << "vec4 after erase(1): size=" << vec4.size() << ", capacity=" << vec4.capacity() << ", contents=";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Insert
    vec4.insert(1, 3);
    std::cout << "vec4 after insert(1, 3): size=" << vec4.size() << ", capacity=" << vec4.capacity() << ", contents=";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Equality comparison
    std::cout << "vec1 == vec2: " << std::boolalpha << (vec1 == vec2) << std::endl;
    vec3 = vec1;
    std::cout << "vec1 == vec3: " << std::boolalpha << (vec1 == vec3) << std::endl;

    // Inequality comparison
    std::cout << "vec1 != vec2: " << std::boolalpha << (vec1 != vec2) << std::endl;
    std::cout << "vec1 != vec3: " << std::boolalpha << (vec1 != vec3) << std::endl;

    // Less than comparison
    std::cout << "vec1 < vec2: " << std::boolalpha << (vec1 < vec2) << std::endl;
    std::cout << "vec1 < vec3: " << std::boolalpha << (vec1 < vec3) << std::endl;
    std::cout << "vec2 < vec1: " << std::boolalpha << (vec2 < vec1) << std::endl;

    // Less than or equal to comparison
    std::cout << "vec1 <= vec2: " << std::boolalpha << (vec1 <= vec2) << std::endl;
    std::cout << "vec1 <= vec3: " << std::boolalpha << (vec1 <= vec3) << std::endl;
    std::cout << "vec2 <= vec1: " << std::boolalpha << (vec2 <= vec1) << std::endl;

    // Greater than comparison
    std::cout << "vec1 > vec2: " << std::boolalpha << (vec1 > vec2) << std::endl;
    std::cout << "vec1 > vec3: " << std::boolalpha << (vec1 > vec3) << std::endl;
    std::cout << "vec2 > vec1: " << std::boolalpha << (vec2 > vec1) << std::endl;

    // Greater than or equal to comparison
    std::cout << "vec1 >= vec2: " << std::boolalpha << (vec1 >= vec2) << std::endl;
    std::cout << "vec1 >= vec3: " << std::boolalpha << (vec1 >= vec3) << std::endl;
    std::cout << "vec2 >= vec1: " << std::boolalpha << (vec2 >= vec1) << std::endl;



    /************************ Stack Main *************************************/

    Stack stack1;

    // Constructs a stack with 5 elements, all set to 10
    Stack stack2(5, 10);

    // Push and pop
    stack1.push(5);
    stack1.push(10);
    stack1.push(15);
    stack1.pop(); // Removes the last element (15)

    // Top
    int topValue = stack1.top(); // Returns the value of the top element
    std::cout << "top element of stack1: " << topValue << std::endl;

    // Size and isEmpty
    if (stack1.isEmpty()) {
        std::cout << "stack1 is empty" << std::endl;
    }
    else {
        std::cout << "stack1 has " << stack1.size() << " elements: ";
        Stack copy = stack1;
        while (!copy.isEmpty()) {
            std::cout << copy.top() << " ";
            copy.pop();
        }
        std::cout << std::endl;
    }
    std::cout << "stack1 has " << stack1.size() << " elements: " << std::endl;

    /*operator ==*/
    Stack stack12(5, 10);
    Stack stack13(5, 10);

    std::cout << "stack12 == stack13: " << std::boolalpha << (stack12 == stack13) << std::endl;

    // Operator +=
    stack1 += 5; // Adds 5 to each element in the stack

    // Operator -=
    stack1 -= 10; // Subtracts 10 from each element in the stack

    // Operator *=
    stack1 *= 2; // Multiplies each element in the stack by 2

    // Operator /=
    stack1 /= 2; // Divides each element in the stack by 2

    // Operator +
    Stack stack3 = stack1 + stack2; // Concatenates stack1 and stack2 into a new stack

    // Operator +=
    stack1 += stack2; // Concatenates stack2 to stack1

    // Print contents of stack1
    std::cout << "stack1: ";
    Stack copy1 = stack1;
    while (!copy1.isEmpty()) {
        std::cout << copy1.top() << " ";
        copy1.pop();
    }
    std::cout << std::endl;

    // Print contents of stack2
    std::cout << "stack2: ";
    Stack copy2 = stack2;
    while (!copy2.isEmpty()) {
        std::cout << copy2.top() << " ";
        copy2.pop();
    }
    std::cout << std::endl;

    // Print contents of stack3
    std::cout << "stack3: ";
    Stack copy3 = stack3;
    while (!copy3.isEmpty()) {
        std::cout << copy3.top() << " ";
        copy3.pop();
    }
    std::cout << std::endl;


    /*Class test */
    Stack s1;
    s1.push(11);
    s1.push(22);
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);
    s1 /= 11;

    // Print contents of stack3
    std::cout << "s1 after s1/=11: ";
    Stack copys1 = s1;
    while (!copys1.isEmpty()) {
        std::cout << copys1.top() << " ";
        copys1.pop();
    }
    std::cout << std::endl;

    s1 += 3;

    std::cout << "s1 after s1+=3: ";
    copys1 = s1;
    while (!copys1.isEmpty()) {
        std::cout << copys1.top() << " ";
        copys1.pop();
    }
    std::cout << std::endl;

    Stack s2, s3;
    s2.push(2);
    s2.push(4);
    s2.push(6);

    std::cout << "s2: ";
    Stack copys2 = s2;
    while (!copys2.isEmpty()) {
        std::cout << copys2.top() << " ";
        copys2.pop();
    }
    std::cout << std::endl;

    s3.push(10);
    s3.push(20);
    s3.push(30);
    s3.push(40);
    s3.push(50);

    std::cout << "s3: ";
    Stack copys3 = s3;
    while (!copys3.isEmpty()) {
        std::cout << copys3.top() << " ";
        copys3.pop();
    }
    std::cout << std::endl;

    Stack s4 = s2 + s3;
    std::cout << "s4 = s2+ s3: ";
    while (!s4.isEmpty()) {
        std::cout << s4.top() << " ";
        s4.pop();
    }
    std::cout << std::endl;


    s2 += s3;
    std::cout << "s2 += s3: ";
    while (!s2.isEmpty()) {
        std::cout << s2.top() << " ";
        s2.pop();
    }
    std::cout << std::endl;
}
