/*
Problem 03_Structs 1: The Book Database
Problem Statement: Create a struct named Book that contains three members: title (string), author (string), and price (float).

Create an array of 2 Book variables.

Use a loop to take input for both books.

Compare their prices and print the full details (Title, Author, and Price) of the cheaper book.
*/
#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    float price;
};

int main() {
    struct Book books[2]; // Create an array of 2 Book variables
    // Input details for both books
    for (int i =0; i<2; i++){
        cout << "Enter details for book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Price: ";
        cin >> books[i].price;
        cin.ignore();
    }
    // Compare prices and print details of the cheaper book
    if (books[0].price < books[1].price) {
        cout << "\nCheaper Book Details:\n";
        cout << "Title: " << books[0].title << endl;
        cout << "Author: " << books[0].author << endl;
        cout << "Price: " << books[0].price << endl;
    } else {
        cout << "\nCheaper Book Details:\n";
        cout << "Title: " << books[1].title << endl;
        cout << "Author: " << books[1].author << endl;
        cout << "Price: " << books[1].price << endl;
    }

    return 0;
}