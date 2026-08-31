// Mac McCoy
// August 28, 2026
// HelloClass.cpp
// This program prints some intro info to the console when it runs.

// #include is used to include libraries, similar to importing modules in Python or node packages JavaScript.
// Need this for input/output stuff. Without it, cout won't work.
#include <iostream>

// using is a keyword for loading in standard C++ stuff without writing std:: as in "standard command, this one" all the time. Similar to loading in a function defined elsewhere.
// namespace means a named scope that contains identifiers like classes, functions, and variables. In this case, std is the "standard" C++ namespace.
// other common namespaces include std::chrono for time-related functions, std::filesystem for file system operations, and std::regex for regular expressions.
using namespace std;

// main() is where the program starts in C++ like the main function in Python or the entry point in JavaScript.
int main() {
    // string = text. The value goes in "quotes".
    string name = "Mac McCoy";

    string major = "Data Analytics AAS";

    // int = integer, so whole numbers only, different from floats/decimal numbers.
    int credits = 6; // total credits this term

    // This is my short answer / reflection sentence.
    string reflection = "This course will help me by formalizing what I learned at General Assembly. C++ is a new language for me, but will build on the syntax learned in Python and JavaScript.";

    // Print stuff to the terminal.
    // cout is like print() in Python. Or console(log) in JavaScript.
    // << sends values into cout.
    // endl makes a new line, like a spelled out semicolon;.
    cout << "Name: " << name << endl;
    cout << "Major: " << major << endl;
    cout << "Credits this term: " << credits << endl;
    cout << "How this course helps my goals: " << reflection << endl;

    // End the program. The zero means it finished successfully, otherwise it returns an error code.
    return 0;
}

// How to use this program:
// 1. Open the terminal in the same folder as this file
// 2. Compile: g++ HelloClass.cpp -o HelloClass (g++ is the GNU free C++ compiler I have installed in my Ubuntu WSL partition)
// C++ files have to be compiled before they can run because the source code needs to be translated into machine code, binary or whatever.
// most programming languages are designed for human readability, so they need to be compiled, the compiler is like a translator.

// 3. Run: ./HelloClass (./ means current directory)
// If the compiler works, the program should print the info in the console under the command.

