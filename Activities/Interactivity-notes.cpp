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




// Prompt the user for their full name.
cout << "\nPlease enter your full name: ";
cin >> userName;






// Display a message that uses the saved name.
cout << "\nThank you, " << userName << ". The square of
your number is: " << squaredNum;




// Calculate the square after the input values are known.
squaredNum = userNum * userNum;





// Add spacing before the program ends.
cout << endl << endl;
system("pause");
return 0;
}

/* How it's supposed to work:
When run, the program is supposed to prompt the user for a number, then prompt for their full name, and finally display a message thanking the user and showing the square of the number.

Final Expected Output:
Please input a number: 4
Please enter your full name: Mac McCoy
Thank you, Mac McCoy. The square of your number is: 16
*/
/* Reflection Log:
While debugging this lab, the first bug encountered was at line 19 in the output statement that prints the thank-you message The compiler reported a missing terminating quote because the string literal was split across two lines, which caused the program to fail before runtime.
This showed that syntax issues must be fixed before we can test the lab's intended logic, and that output formatting can break the whole program even when the rest of the logic is close to correct.
*/
