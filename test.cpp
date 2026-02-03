#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter " << size << " array elements:" << endl;
    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int i=0;
    int j=size -1;
    while(i<j){
        int temp = arr[i]; // Store the current element in a temporary variable
        arr[i] = arr[j]; // Assign the value from the end position to the current position
        arr[j] = temp; // Assign the value from the temporary variable to the end position
        i++;
        j--;
    }
    cout << "Array elements in reverse order are: " << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }


    return 0;
}