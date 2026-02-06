/*
Problem 03_Structs 2: Student Grading System

Use typedef to create an alias for a struct named Student.

The struct should contain:

1.string name
2.int marks[3] (an array to store marks for 3 subjects)
3.Task: Create one student object. Take input for the name and the 3 marks.
4.Calculate the Average Mark and print the Student's name along with their average.
*/

#include <iostream>

typedef struct {
    std:: string name;
    int marks[3];
} Student;
int main(){
    Student student; // Create one student object
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name); // Input for the name
    std::cout << "Enter marks for 3 subjects: "; // Input for the 3 marks
    int totalmarks =0;
    for(int i=0; i<3; i++){
        std::cin >> student.marks[i];
        totalmarks += student.marks[i];
    }
    float average = totalmarks / 3; // Calculate the Average Mark
    std::cout <<"Student Name: "<< student.name << std::endl; // Print the Student's name
    std::cout << "Average Marks: "<< average << std::endl;  // Print the average
    return 0;
}

