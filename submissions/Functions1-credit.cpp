// Mac McCoy
// 11/8/2026
// Simple Calculator App
// Performs basic math operations.

#include <iostream>
using namespace std;

// Display the result of the selected operation.
void add(double num1, double num2)
{
    cout << "Result: " << num1 + num2 << endl;
}

void sub(double num1, double num2)
{
    cout << "Result: " << num1 - num2 << endl;
}

void mult(double num1, double num2)
{
    cout << "Result: " << num1 * num2 << endl;
}

void divide(double num1, double num2)
{
    if (num2 == 0)
    {
        cout << "Cannot divide by zero." << endl;
        return;
    }

    cout << "Result: " << num1 / num2 << endl;
}

void showMenu()
{
    cout << "Choose operation: " << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
}

int main()
{
    double term1;
    double term2;
    int opChoice;
    char another;

    // Collect numbers and repeat calculations while requested.
    do
    {
        cout << "Enter any number: ";
        if (!(cin >> term1))
        {
            cerr << "Invalid first number." << endl;
            return 1;
        }

        cout << "Enter any second number: ";
        if (!(cin >> term2))
        {
            cerr << "Invalid second number." << endl;
            return 1;
        }

        showMenu();
        if (!(cin >> opChoice))
        {
            cerr << "Invalid menu choice." << endl;
            return 1;
        }

        switch (opChoice)
        {
            case 1:
                add(term1, term2);
                break;
            case 2:
                sub(term1, term2);
                break;
            case 3:
                mult(term1, term2);
                break;
            case 4:
                divide(term1, term2);
                break;
            default:
                cout << "Invalid menu choice." << endl;
                break;
        }

        cout << "Would you like to perform another calculation? (y/n): ";
        if (!(cin >> another))
        {
            cerr << "Could not read your answer." << endl;
            return 1;
        }
    } while (another == 'y' || another == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
