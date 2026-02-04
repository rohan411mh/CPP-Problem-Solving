/*
 3. Pass-by-Reference: Write a function void swap(int *a, int *b) that swaps the values of two variables in main().
*/

#include <iostream>
// Function to swap two integers using pointers by reference
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int num1, num2;
    std::cout << "Enter two numbers to swap:"<< std::endl;
    std::cin >> num1 >> num2;
    std::cout << "Before swaping x is " << num1 << " and y is " << num2 <<std::endl;
    swap(&num1, &num2); // Call swap function with addresses of num1 and num2
    std::cout << "After swaping x is " << num1 << " and y is " << num2 <<std::endl;
    return 0;
    
}