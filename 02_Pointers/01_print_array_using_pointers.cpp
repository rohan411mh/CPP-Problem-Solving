// 1. Print array elements using pointer arithmetic
#include <iostream>
using namespace std;
int main() {
    int arr[5];
    int size=5;
    int* ptr=arr;

    cout << "Enter 5 array elements:" << endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    
    cout << "Prints all elements using pointer arithmetic only:"<< endl;
    for(int i=0; i<size; i++){
        cout << *(ptr+i)<< endl;
    }
    return 0;
}

/*
📌 Problem Statement
Write a C++ program that:
Takes 5 integers into an array
Uses a pointer to access the array
Prints all elements using pointer arithmetic only:
*(ptr + i)

🔒 Rules (strict)
❌ Do NOT use arr[i] in the print loop
❌ Do NOT use STL
✅ Use integers only
✅ Use a pointer variable (int *ptr)
🧠 Concepts Tested
Relationship between arrays and pointers
Pointer arithmetic
Memory access
*/

