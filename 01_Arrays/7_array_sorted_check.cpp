// 7. Check Whether Array Is Sorted (Ascending)
#include <iostream>
using namespace std;
int main() {
    int arr[10];
    int size = 10;
    cout << "Enter 10 array elements: "<< endl;
    for (int i=0; i<size; i++){
        cin >> arr[i];
    }
    bool isSorted = true; //sorted
    for(int i=0; i<(size-1); i++){ 
        if(arr[i] > arr[i+1]){
            isSorted = false; // not sorted
            break;
        }
    }
    if(isSorted){
        cout << "Array is sorted." << endl;
    }
    else{
        cout << "Array is not sorted." << endl;
    }
    return 0;
}


/*
📌 Problem Statement

Write a C++ program that:

Takes 10 integers from the user into an array
Checks whether the array is sorted in ascending order
Prints:
"Array is sorted" or
"Array is not sorted"

🔒 Rules
Use only one loop
Do not sort the array
Use integers only
No STL, no extra arrays

🧠 Concepts Tested
Adjacent element comparison
Loop control
Early termination logic (optional but good)

⚠️ Common Mistakes to Avoid
Comparing every element with all others
Using nested loops
Printing sorted elements instead of checking order
*/