/*
 4. Double Pointers: Create an int x = 5. Create a pointer p to x,
    and a pointer-to-pointer pp to p. Change x to 50 using only pp.
*/
#include <iostream>

int main() {
    int x=5;
    int* p=&x;
    int** pp=&p;
    // use pp to change the value of x
    **pp = 50;
    std::cout <<"The value of x is now "<< x;
    return 0;
}   