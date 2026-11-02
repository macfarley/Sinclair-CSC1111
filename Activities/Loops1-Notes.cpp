// Name: Mac McCoy
// Date: 10/19/2026
// Program Name: Loops Exercise 1
// Program Description: Repeatedly prompts the user until they enter a number from 1 to 10.

#include <iostream>
#include <limits>
using namespace std;

int main() {
    double userNumber = 0.0;
    bool isValidNumber = false;

    // Keep prompting until the input is numeric and within the required range.
    // do {
    //     cout << "Please enter a number from 1 to 10: ";

    //     if (cin >> userNumber) {
    //         if (userNumber >= 1 && userNumber <= 10) {
    //             isValidNumber = true;
    //         } else {
    //             cout << "Error: The number must be between 1 and 10. Please try again." << endl;
    //         }
    //     } else {
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         cout << "Error: Please enter a number from 1 to 10." << endl;
    //     }
    // } while (!isValidNumber);

    // cout << "Thank you! You entered " << userNumber << ", which is between 1 and 10." << endl;
    bool purge = false;

    do
    {cout << "Crimes crimes crimes!" << endl;
        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> purge;
    } while (purge == true);
    

    return 0;
}