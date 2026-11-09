// Mac McCoy
// 11/8/2026
// Simple Calculator App
// Performs basic math operations

// Include any libraries needed for input/output
#include <iostream>
using namespace std;

// Function prototype for addition
// Receives two numbers as parameters
// Calculates and displays the sum
void add(double num1, double num2){
    cout << "Result: " << num1 + num2 << endl;
}

// Function prototype for subtraction
// Receives two numbers as parameters
// Calculates and displays the difference
void sub(double num1, double num2){
    cout << "Result: " << num1 - num2 << endl;
}

// Function prototype for multiplication
// Receives two numbers as parameters
// Calculates and displays the product
void mult(double num1, double num2){
    cout << "Result: " << num1 * num2 << endl;
}

// Function prototype for division
// Receives two numbers as parameters
// Calculates and displays the quotient
void divide(double num1, double num2){
    if (num2 == 0){
        cout << "Cannot divide by zero." << endl;
        return;
    }

    cout << "Result: " << num1/num2 << endl;
}

//function to display operation choices
    // Display menu:
    // 1. Add
    // 2. Subtract
    // 3. Multiply
    // 4. Divide
void showMenu(){
    cout << "Choose operation: " << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
}

// Main function starts here
int main()
{
    double term1;
    double term2;
    int opChoice;
    char another;

    do
    {
        cout << "Enter any number: ";
        if (!(cin >> term1)){
            cerr << "Invalid first number." << endl;
            return 1;
        }

        cout << "Enter any second number: ";
        if (!(cin >> term2)){
            cerr << "Invalid second number." << endl;
            return 1;
        }

        showMenu();
        if (!(cin >> opChoice)){
            cerr << "Invalid menu choice." << endl;
            return 1;
        }


        // Call the function corresponding to the chosen operation.
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
        if (!(cin >> another)){
            cerr << "Could not read your answer." << endl;
            return 1;
        }
    } while (another == 'y' || another == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}

/* Test Data
Test Case	Number 1	Number 2	Choice	    Expected Result
1	        10	        5	        1 (Add)	    Result: 15
2	        20	        7	        2 (Sub)	    Result: 13
3	        4	        6	        3 (Mult)	Result: 24
4	        15	        3	        4 (Divide)	Result: 5
5	        12.5	    2.5	        1 (Add)	    Result: 15
6	        10	        0	        4 (Divide)	Cannot divide by zero*/