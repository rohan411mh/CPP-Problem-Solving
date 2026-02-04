/*
 5. Array Traversal: Create an array of 5 integers.
    Use a pointer and a while loop to print the array
    in reverse order using only pointer decrementing (ptr--).
*/
#include <iostream>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr + 4; // Point to the last element of the array
    std::cout << "Array elements in reverse order are:" << std::endl;
    while (ptr >= arr) { // explanation: Loop until the pointer is greater than or equal to the address of the first element
        std::cout << *ptr << " ";
        ptr--; // Decrement the pointer to point to the previous element
    }
    return 0;
}