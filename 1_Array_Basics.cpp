/*1️⃣ Array Basics
Write a program that:

// Takes 5 integers from the user into an array
Prints:
The array elements
Sum of all elements
Average of the elements
👉 Concepts used: arrays, loops, cin/cout */


#include <iostream>
using namespace std;

int main() {
    float arry[5];
    float sum=0;
    cout <<"Enter 5 array elements:"<< endl;
    int size = (sizeof(arry)/sizeof(arry[0]));
    for(int i=0; i<size; i++){
        cin >> arry[i];
        sum += arry[i];
    }
    for(int i=0; i<size; i++){
        cout <<"The array element at index " << i << " is: " << arry[i] << endl;
    }
    cout << "Sum of all array elements: " << sum << endl;
    cout << "Average of array elements: " << sum/size << endl;
    return 0;
}