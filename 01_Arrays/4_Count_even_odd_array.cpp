// 4.Count Even and Odd Numbers in an Array
#include <iostream>
using namespace std;

int main() {
    // Initialize array and variables
    int arr[10];
    int size = 10;
    cout <<"Enter 10 array elements: "<< endl;
    // Input array elements
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    int evenCount =0; // Count of even numbers
    int oddCount =0; // Count of odd numbers
    // Count even and odd numbers
    for(int i=0; i<size; i++){
        if(arr[i] % 2 ==0){
            evenCount++; // Increment even count
        }
        else{
            oddCount++; // Increment odd count
        }
    }
    // Output the counts
    cout << "Number of even elements: " << evenCount << endl;
    cout << "Number of odd elements: " << oddCount << endl;

    return 0;
}


/*
📌 Problem Statement

Write a C++ program that:

Takes 10 integers from the user into an array

Counts how many numbers are:

Even

Odd

Prints the count of even and odd numbers

🔒 Rules (important)

Use only one loop for counting

Use integers (not float)

Do not hardcode answers

Array size must be clear (no magic logic)
*/