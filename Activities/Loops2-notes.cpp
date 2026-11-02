// Name: Mac McCoy
// Date: 10/21/2026
// Program Name: Loops Exercise 2
// Program Description: This program asks the user for a number and displays its multiplication table from 1 through 12.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare variables, specs call for ANY NUMBER input, not just integers.
    double inputNumber;
    double result;

    //Test Data, uncomment for a testing run.
    // double tests[] = {10, 2.5, 3.0/5.0 , 4.12, .0005};
    // Final line for each: 120, 30, 0.6, 49.44, 0.006

    // Prompt the user for a number
    cout << "Welcome to the Multiplication Table Program!" << endl;
    cout << "This program will display the number you enter, times the numbers 1-12." << endl;
    cout << "Please enter a number to see its multiplication table: ";
    // Read the user's number
    cin >> inputNumber;

    // Display the user's number back to them
    cout << endl << "You have entered: " << inputNumber << endl;

    // Display a heading for the multiplication table
    cout << "Multiplication table for " << inputNumber << ":" << endl;

    // Use a for loop from 1 to 12.  i is the classic for "iterator", could be any single character or variable name.  since it's scoped to this loop only, it won't be used elsewhere, doesn't need to be esoteric. 
    // i is an integer because we know each step in the multiplication table is a whole number, but the result needs to be a double to handle non-integer input numbers.
    // double plus (++) makes it an up-counter.
    for (int i = 1; i <= 12; i++)
    {
        // Calculate number times the i value, each loop adds i+1.
        result = inputNumber * i;
        // Display the multiplication table line
        //setw sets the width of the next output field, ensuring alignment in the table.
        cout << setw(5) << inputNumber
             << " X " << setw(2) << i
             << " = " << setw(7) << result << endl;
    }

    return 0;
}