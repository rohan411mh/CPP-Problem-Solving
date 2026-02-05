/*
6. Pointer Constants: Declare a const int* and an int* const.
Try to modify the value and the address for both and document which one the compiler blocks.
*/
#include <iostream>
using namespace std;

int main() {
    int x=10, y=20;
    const int* ptr1 = &x; // Pointer to a constant integer ---> the value being pointed to cannot be changed through this pointer
    int* const ptr2 = &x; // Constant pointer to an integer ---> the address being pointed to cannot be changed
    cout << "Initial values:" << endl;
    cout << "ptr1 points to value: " << *ptr1 << endl;
    cout << "ptr2 points to value: " << *ptr2 << endl;
    // Trying to modify the value pointed by ptr1
    // *ptr1 = 15; // This line would cause a compilation error: cannot modify a const value
    cout << "After attempting to modify value via ptr1 (commented out):" << endl;
    cout << "ptr1 points to value: " << *ptr1 << endl;
    // Modifying the address ptr1 points to 
    ptr1 = &y; // This is allowed
    cout << "After changing ptr1 to point to y:" << endl;
    cout << "ptr1 points to value: " << *ptr1 << endl;
    // Trying to modify the address ptr2 points to
    // ptr2 = &y; // This line would cause a compilation error: cannot change a constant pointer
    cout << "After attempting to change ptr2 to point to y (commented out):" << endl;
    cout << "ptr2 points to value: " << *ptr2 << endl;
    // Modifying the value pointed by ptr2
    *ptr2 = 25; // This is allowed
    cout << "After modifying value via ptr2:" << endl;
    cout << "ptr2 points to value: " << *ptr2 << endl;

    return 0;
}