// Mac McCoy
// August 31, 2026 
//TODO: always update to on each day you modify this file
// variables2.cpp (file name)
// This program will output my academic plan for Fall'26, the classes I'm taking, and each class's credit hour value.

// C++ Boilerplate: I'll use this in most .cpp programs I write.
// #include is used to include libraries, similar to importing modules in Python or packages in JavaScript.
// We need <iostream> library for input/output operations like printing to the console.
// Other common things to include might be <vector> for dynamic arrays, <string> for string manipulation, etc.
#include <iostream>

// using namespace std; lets us use standard C++ tools without writing std:: every time.
// This keeps the code shorter and easier to read for beginner programs.
using namespace std;

// main() is the starting point of every C++ program.
// The program begins executing here when you run it.
int main() {
    // declare a variable for the current term (e.g. "Fall 2026")
    string currentTerm = "Fall 2026";
    
    // declare variables for at least 3 course names (descriptive names, e.g. course1Name)
    string csc1111 = "Intro to C++ Programming";
    
    string csc2165 = "Database Management";
    
    string bis1230 = "Spreadsheet Software";
    
    string math1450 = "Introduction to Data Science";
    
    string excuse = "I need to scale back my course load this term due to medical reasons.";

    // declare variables for each course's credit hours (descriptive names, e.g. course1Credits)
    int csc1111Credits = 3;
    
    int csc2165Credits = 4;
    
    int bis1230Credits = 3;
    
    int math1450Credits = 5;

    // use cout to print the term, then each course name paired with its credit hours
    // Remember: no hard-coded literals here for the data itself -- output the variables.
    cout << "During this term, " << currentTerm <<  ", I am registered for the following courses:" 
        << endl;

    cout << "I'm taking " << csc1111 << ", which is worth " << csc1111Credits << " credits, and " 
        << csc2165 << ", which is worth " << csc2165Credits << " credits." << endl;
    
    cout << "I had also planned on taking " << bis1230 <<" and " << math1450 << " during " 
        << currentTerm << ", which" << endl <<" are worth " << bis1230Credits << " and " 
        << math1450Credits << " credits respectively." << endl;

    cout << "Unfortunately, however, " << excuse << " I decided to drop " << math1450 << " and " 
        << bis1230 << ". So instead of" << endl << " taking " 
        << csc1111Credits+csc2165Credits+bis1230Credits+math1450Credits 
        << " credits, I am now only taking " << csc1111Credits+csc2165Credits << " credits." << endl;

    // return 0; tells the program to end successfully.
    // In C++, 0 usually means the program ran without errors.
    // if we build in error codes to certain numbers we can have it tell us which step went wrong.
    return 0;
}

// How to use this program:
// 1. Open the terminal in the same folder as this file
// 2. Compile: g++ variables2.cpp -o variables2
// 3. Run: ./variables2
// This compiles the C++ source code into an executable and then runs it.

// 4. You can also chain the compile and run commands together using &&, like this:
//    g++ variables2.cpp -o variables2 && ./variables2
//    This will compile the program and, if successful, immediately run the resulting executable.
//    If the compilation fails, the second command will not execute, helping you catch errors early.
