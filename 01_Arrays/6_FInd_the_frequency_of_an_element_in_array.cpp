// 6. Find the Frequency of an Element in an Array
#include <iostream>
using namespace std;
int main() {
    int arr[10];
    int size = 10;
    cout << "Enter 10 array elements :"<<endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    int target;
    cout << "Enter target element to count: "<< endl;
    cin >> target;
    int count=0;
    for (int i=0; i<size; i++){
        if(target == arr[i]){
            count++;
        }
    }
    cout << "The target value appears in the array "<< count <<" times";

    return 0;
}
/*
Problem Statement

Write a C++ program that:
Takes 10 integers from the user into an array
Takes one integer as a target value
Counts how many times the target value appears in the array
Prints the frequency

🔒 Rules
Use only one loop for counting
Use integers only
Do not sort the array
Do not use STL or extra arrays
🧠 Concepts Tested

Array traversal
Conditional checks
Counter logic
*/