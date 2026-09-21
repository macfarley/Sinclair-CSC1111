// Mac McCoy
// 2026-09-21
// Program Name: Interactivity Notes
// Program Description: This program demonstrates a series of bugs in a basic user interaction scenario.  Notes at the bottom will explain the issues and how to fix them.




#include<iostream>
#include<string>
using namespace std;
int main() {
// Declare storage for the name and the numeric input.
string userName;
int userNum, squaredNum;






// Prompt the user for a number to square.
cout << "Please input a number: ";
cin >> userNum;

// Calculate the square after the input values are known.
squaredNum = userNum * userNum;


// Prompt the user for their full name.
cout << "\nPlease enter your full name: ";

// Use getline to read the full name including spaces.
 // Ignore the leftover newline character from previous input buffer before using getline()
cin.ignore();
getline(cin, userName);






// Display a message that uses the saved name.
cout << "\nThank you, " << userName 
    << ". The square of your number is: " << squaredNum;






cout << endl << endl;


return 0;
}

/* How it's supposed to work:
When run, the program is supposed to prompt the user for a number, then prompt for their full name, and finally display a message thanking the user and showing the square of the number.

Final Expected Output:
Please input a number: (input: 4)
Please enter your full name: (input: Mac McCoy)
Thank you, Mac McCoy. The square of your number is: 16
*/
/* Reflection Log:
While debugging this lab, the first bug encountered was at line 19 in the output statement that prints the thank-you message. The compiler reported a missing terminating quote because the string literal was split across two lines and wrapped awkwardly, which caused the program to fail before runtime.
The fix was to break the cout statement into separate lines without leaving the string open, so the text reads as one complete output message and avoids mistakes from line wrapping, extra quotation marks, and confusing spacing.
The next bug was the input format: using cin to read the full name only captured the first word, so the program needed getline(cin, userName) to read the entire string, including spaces.
The final bug was the calculation order: the square had to be calculated before it was used in the cout statement, because a variable cannot be displayed correctly before it has been assigned a value.
This showed that debugging a program usually happens in stages: fix syntax first, then input handling, then logic order, and only then can the final output be trusted.
*/
