// 3. Reverse an array without using another array
#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int size = 10;
    cout << "Enter 10 array elements:"<< endl;
    for(int i=0; i<10; i++){
        cin >> arr[i];
    }
    for(int i=0; i<size/2; i++){
        int temp = arr[i]; // Store the current element in a temporary variable
        arr[i] = arr[9-i]; // 9-i to get the corresponding element from the end
        arr[9-i] = temp; // Assign the value from the temporary variable to the end position
    }
    /*
    // Alternative approach using two pointers
        int start =0;
    int end = size -1;
    while(i<j){
        int temp = arr[start]; // Store the current element in a temporary variable
        arr[start] = arr[end]; // Assign the value from the end position to the current position
        arr[end] = temp; // Assign the value from the temporary variable to the end position
        i++;
        j--;
    }
    */
    cout << "Array elements in reverse order are:"<< endl;
    for(int i=0; i<10; i++){
        cout << arr[i] <<endl;;
    }
    return 0;
}