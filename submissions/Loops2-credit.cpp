// Name: Mac McCoy
// Date: 10/21/2026
// Program Name: Loops Exercise 2
// Program Description: This program asks the user for a number and displays its multiplication table from 1 through 12.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double inputNumber;
    double result;

    // Prompt for and read the number used to generate the table.
    cout << "Welcome to the Multiplication Table Program!" << endl;
    cout << "This program will display the number you enter, times the numbers 1-12." << endl;
    cout << "Please enter a number to see its multiplication table: ";
    cin >> inputNumber;

    cout << endl << "You have entered: " << inputNumber << endl;
    cout << "Multiplication table for " << inputNumber << ":" << endl;

    // Calculate and display each product from 1 through 12.
    for (int i = 1; i <= 12; i++)
    {
        result = inputNumber * i;
        cout << setw(5) << inputNumber
             << " X " << setw(2) << i
             << " = " << setw(7) << result << endl;
    }

    return 0;
}
