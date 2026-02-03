// 2. Find **maximum and minimum** element in an array of size 10

#include <iostream>
using namespace std;

int main() {
    float arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Enter 10 array elements:"<< endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    float max = arr[0];
    float min = arr[0];
    for(int i =1; i<size; i++){
        if (arr[i]>max){
            max = arr[i];
        }
        if (arr[i]<min){
            min = arr[i];
        }
    }
    cout << " Maimum elements in array is: " << max << endl;
    cout << " Minimum elements in array is: " << min << endl;
    return 0;
}