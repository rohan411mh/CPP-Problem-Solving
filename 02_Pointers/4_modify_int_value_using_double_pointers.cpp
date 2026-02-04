/*
 4. Double Pointers: Create an int x = 5. Create a pointer p to x,
    and a pointer-to-pointer pp to p. Change x to 50 using only pp.
*/
#include <iostream>

int main() {
    int x=5;
    std::cout << "The initial value of x is "<< x << std::endl;
    int* p=&x;
    int** pp=&p;
    // use pp to change the value of x
    **pp = 50;
    std::cout << "The modified value of x using double pointer is "<< x << std::endl;
    return 0;
}   