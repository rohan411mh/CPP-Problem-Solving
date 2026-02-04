/* 
Topic: 02_Pointers
Problem #2:
👉 Find the Sum of Array Elements Using Pointer Arithmetic
*/

#include <iostream>
int main() {
    int n;
    std::cout << "Enter the number of elements in an array:"<< std:: endl;
    std::cin >>n;
    int* arr = new int[n];
    std::cout << "Enter "<< n << "elements in this array:" << std::endl;
    int sum = 0;
    for(int i=0; i<n; i++){
        std::cin >> *(arr + i);
        sum += *(arr + i);
    }
    std::cout << "Sum of the elements in this array  using pointer arithmetic is :" << sum;
    delete[] arr;
    return 0;
}

/*
📌 Problem Statement

Write a C++ program to:

Take n elements in an array

Use only pointer arithmetic to calculate the sum of elements

Do not use array indexing like arr[i]

📋 Rules (strict)

Use a pointer (int* ptr)

Use a loop with *(ptr + i)

Use a size variable (no hardcoding)

No STL, no shortcuts
*/
