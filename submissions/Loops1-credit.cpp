// Name: Mac McCoy
// Date: 2026-10-19
// Program Name: Loops Exercise 1
// Program Description: Repeatedly prompts the user until they enter a number from 1 to 10.

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    double userNumber = 0.0;
    bool isValidNumber = false;
    string inputText;

    do {
        cout << "Please enter a number from 1 to 10: ";

        if (!getline(cin, inputText)) {
            cout << endl << "Error: No input was received." << endl;
            return 1;
        }

        istringstream inputStream(inputText);
        if (inputStream >> userNumber) {
            inputStream >> ws;
            if (!inputStream.eof()) {
                cout << "Error: Please enter only one number from 1 to 10." << endl;
            } else if (userNumber >= 1 && userNumber <= 10) {
                isValidNumber = true;
            } else {
                cout << "Error: The number must be between 1 and 10. Please try again." << endl;
            }
        } else {
            cout << "Error: Please enter a number from 1 to 10." << endl;
        }
    } while (!isValidNumber);

    cout << "Thank you! You entered " << userNumber << ", which is between 1 and 10." << endl;

    return 0;
}
