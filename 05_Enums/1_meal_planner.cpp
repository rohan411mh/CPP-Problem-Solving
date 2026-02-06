/*
Problem 05_Enums 1: The Meal Planner

1.Define an enum Meal {BREAKFAST, LUNCH, DINNER}.
2.Create a variable of type Meal and set it to LUNCH.
3.Use a switch statement to print a message based on the meal.
    If BREAKFAST: "Morning energy!"
    If LUNCH: "Midday fuel!"
    If DINNER: "Evening relax!"
4.Extra Credit: Print the integer value of LUNCH to see what number the computer assigned to it.
*/
#include <iostream>

int main() {
    enum meal { BREAKFAST, LUNCH , DINNER}
    m = LUNCH; // Create a variable of type Meal and set it to LUNCH
    switch(m){
        case BREAKFAST:
            std::cout << "Morning energy!";
            break;
        case LUNCH:
            std::cout << "Midday fuel!";
            break;
        case DINNER:
            std::cout << "Evening relax!";
            break;
    }
    std::cout << "\nInteger value of LUNCH is "<< LUNCH;
    return 0;
}