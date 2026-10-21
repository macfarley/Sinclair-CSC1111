// Name: Mac McCoy
// Date: 2026-10-19
// Program Name: Loops Exercise 1
// Program Description: Repeatedly prompts the user until they enter a number from 1 to 10.

#include <iostream>
#include <limits>

using namespace std;

int main() {
    // Store the user's entry as a decimal number.
    double userNumber = 0.0;
    // Track whether the input is both numeric and within the allowed range.
    bool validInput = false;

    // Repeat the prompt until the user enters a valid number from 1 to 10.
    do {
        // Ask for a number in the required range.
        cout << "Please enter a number from 1 to 10: ";

        // Check whether the user's entry can be read as a number.
        if (!(cin >> userNumber)) {
            cout << "Error: Please enter a number." << endl;

            // Reset the input stream so another value can be read.
            cin.clear();
            // Discard the invalid entry before prompting again.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (userNumber < 1 || userNumber > 10) {
            // A numeric entry still needs to be within the allowed range.
            cout << "Error: The number must be between 1 and 10. Please try again." << endl;
        } else {
            // The entry is numeric and within range, so the loop can stop.
            validInput = true;
        }
    } while (!validInput);

    // Confirm the valid number entered by the user.
    cout << "Thank you! You entered " << userNumber << ", which is between 1 and 10." << endl;

    return 0;
}
