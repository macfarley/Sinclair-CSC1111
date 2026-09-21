// Mac McCoy
// Date: 2026-09-21
// Program Name: Interactivity Lab
// Program Description: Reads a number and a full name, then prints a customized square result.  Started with a buggy version and fixed the issues.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string userName;
    int userNum = 0;
    int squaredNum = 0;

    // Bug #1 fixed here: keep the prompt/output string intact to avoid stray quotes and spacing issues.
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
- Bug 1: A quote mark was left open when the output string was split across lines, which caused a compiler error.

- Bug 2: Using cin for the name only captured the first word, so getline(cin, userName) was required. 
Because cin leaves a newline character in the input buffer, cin.ignore() was used to discard it before calling getline().

- Bug 3: The square value was printed before it was calculated, so the result was wrong or uninitialized.

Debugging Reflection:
This assignment reminded me that sometimes “vertical bloat” is worth it if it makes the code easier to read. The syntax issue I hit wasn’t hard to find: it was caused by a long line wrapping in a weird way and making an extra quote mark easy to miss. The real lesson there was not to fear spreading things out if it prevents confusion.  
The trickiest part was the getline() behavior, because I hadn’t run into that particular C++ quirk before: getline() will grab the empty newline “character” sitting in the input buffer after a cin >> operation. That leftover newline char hangs around between steps, so you have to clear it with cin.ignore() before reading a new full string. 
The logic problem was just an out‑of‑order calculation, where the square was printed before it was actually computed, so the variable looked like it held a random value (31275 or something crazy).
*/