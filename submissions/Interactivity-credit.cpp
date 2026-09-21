// Mac McCoy
// Date: 2026-09-21
// Program Name: Interactivity Lab
// Program Description: Reads a number and a full name, then prints a customized square result.  Started with a buggy version and fixed the issues.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string userName;
    double userNum = 0.0;
    double squaredNum = 0.0;

    // Bug #1 fixed here: declare the numeric values as doubles so the square calculation matches the intended math.
    cout << "Please input a number: ";
    cin >> userNum;

    // Bug #2 fixed here: use getline() so the full name is captured, including spaces.
    cout << "\nPlease enter your full name: ";
    cin.ignore();
    getline(cin, userName);

    // Bug #3 fixed here: calculate the square before using the value in the final output.
    squaredNum = userNum * userNum;

    cout << "\nThank you, " << userName
         << ". The square of your number is: " << squaredNum << endl;

    return 0;
}

/*
Flowchart:
Start Program
    -> display prompt for number input
    -> Read integer input from user
        -> Store integer input in userNum
    -> Display prompt for full name input
    -> Read full name line from user including spaces
        -> Store full name in userName
    -> Calculate square of userNum and store as squaredNum
    -> Display thank-you message with userName and squaredNum
End program.

Debugging notes:
- Bug 1: The numeric variables were declared as integers instead of doubles, which caused the square values to behave incorrectly for the intended math.

- Bug 2: Using cin for the name only captured the first word, so getline(cin, userName) was required. Because cin leaves a newline character in the input buffer, cin.ignore() was used to discard it before calling getline().

- Bug 3: The square value was printed before it was calculated, so the result was wrong or uninitialized.

Debugging Reflection:
This assignment helped me see that debugging is really about finding the real source of the problem instead of guessing at the first symptom. The final issue turned out to be the variable types: the number and square were declared as integers, so the program was not storing the data in a way that matched the intended mathematical behavior. Once I changed those values to double, the calculation made sense and the output became stable. The next issue was the input handling, because using cin to read a full name only captured the first word before it hit a space, so I used getline() and cleared the leftover newline with cin.ignore(). Finally, I fixed the order of operations by calculating the square before printing it. This sequence showed me that syntax, input flow, type selection, and calculation order all matter in C++, and they have to be checked in a logical order to avoid confusing results.
*/