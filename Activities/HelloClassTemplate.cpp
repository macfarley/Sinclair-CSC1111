// Mac McCoy
// August 29, 2026 (always update to current)
// HelloClassTemplate.cpp (file name)
// This program prints out basic class information and a reflection on how the course helps achieve goals. (short description of the program for easy recall)

// #include is used to include libraries, similar to importing modules in Python or packages in JavaScript.
// We need <iostream> for input/output operations like printing to the console.
#include <iostream>

// using namespace std; lets us use standard C++ tools without writing std:: every time.
// This keeps the code shorter and easier to read for beginner programs.
using namespace std;

// main() is the starting point of every C++ program.
// The program begins executing here when you run it.
int main() {
    // string is a data type used for text.
    // Replace these values with your own information later.
    string name = "Your Name";
    string major = "Your Major";

    // int is a data type used for whole numbers.
    // This stores the number of credits being taken this term.
    int credits = 0;

    // This is a short reflection sentence or answer to the prompt.
    string reflection = "This course will help me by...";

    // cout is like print() in Python or console.log() in JavaScript.
    // << sends values to the output stream.
    // endl moves to the next line after printing.
    cout << "Name: " << name << endl;
    cout << "Major: " << major << endl;
    cout << "Credits this term: " << credits << endl;
    cout << "How this course helps my goals: " << reflection << endl;

    // return 0; tells the program to end successfully.
    // In C++, 0 usually means the program ran without errors.
    // if we build in error codes to certain numbers we can have it tell us which step went wrong.
    return 0;
}

// How to use this program:
// 1. Open the terminal in the same folder as this file
// 2. Compile: g++ HelloClassTemplate.cpp -o HelloClassTemplate
// 3. Run: ./HelloClassTemplate
// This compiles the C++ source code into an executable and then runs it.

// 4. You can also chain the compile and run commands together using &&, like this:
//    g++ HelloClassTemplate.cpp -o HelloClassTemplate && ./HelloClassTemplate
//    This will compile the program and, if successful, immediately run the resulting executable.
//    If the compilation fails, the second command will not execute, helping you catch errors early.
