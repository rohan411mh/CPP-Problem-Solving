// 5. Find the Second Largest Element in an Array
#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int size =10;
    cout << "Enter 10 array elements:"<< endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    int firstLargest = arr[0]; // Initialize to the smallest integer
    int secondLargest = arr[0]; // Initialize to the smallest integer
    for(int i=0; i<size; i++){
        if(arr[i] > firstLargest){
            secondLargest =firstLargest; // Update second largest
            firstLargest = arr[i]; // Update first largest
        }
        else if(arr[i] > secondLargest && arr[i]!= firstLargest){
            secondLargest = arr[i]; // Update second largest
        }
    }
// Edge case: all elements equal ---> Recommendation to handle by ChatGPT
    if(firstLargest == secondLargest) {
        cout << "Second largest element does not exist." << endl;
    } 
    else {
        cout << "The second largest element is: "
             << secondLargest << endl;
    }
    return 0;
}

/*
Write a C++ program that:
Takes 10 integers from the user into an array
Finds the second largest element 
Prints the second largest value

Rules (strict)
❌ Do NOT sort the array
❌ Do NOT use another array
❌ Do NOT use STL (sort, vector, etc.)
✅ Use loops and conditions only
✅ Use integers

Concepts Tested
Comparison logic
Proper initialization
Handling edge cases (duplicate values)
*/