/*
Problem 04_Unions 1: The Memory Shape-Shifter

1. Create a union Data that contains an int i and a float f.
2. In main():
    Assign 10 to i. Print i.
    Now, assign 22.5 to f.
    Print f, and then print i again.
3. Task: Observe what happens to the value of i after you assigned something to f.
Note for your log: This will show you how Unions share the same memory address for all members.
*/
#include <iostream>
union data{
    int i;
    float f;
};
int main() {
    union data value;
    value.i = 10;
    std::cout << "Initially Value of i is " <<value.i << std::endl;
    value.f = 22.5;
    std::cout << "Now value of f is "<< value.f << std::endl;
    std::cout << "Now value of i is "<< value.i << std::endl;
    std::cout << "Value of i become undefined because value of f overwrote it. Unions allow different data types in the same memory." << std::endl;
    return 0;
}