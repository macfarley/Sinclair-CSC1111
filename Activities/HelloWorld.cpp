// Mac McCoy
// August 29, 2026
// HelloWorld.cpp
// This program prints "Hello, World!" to the console when it runs.

#include <iostream>
//the difference between #include and using is
// #include is used to include libraries, similar to importing modules in Python or node packages in JavaScript.
// using is a keyword for loading in standard C++ stuff without writing std:: as in "standard command, this one" all the time.
using namespace std;

// you always start a C++ program with the main() function, which is where the program begins execution.
int main() {

    // cout is like console(log) in JavaScript or print() in Python.  it's part of that std namespace.
    // other common objects in the std namespace include cin for input, cerr for error messages, and clog for logging.
    
    // always use the << "carrots" between terms in the output stream to separate different values.
    // endl is used to insert a newline character and flush the output buffer, it's basically a more formal semicolon or return/enter/nextline
    cout << "Hello, World!" << endl;


    // what happens if this number is different? 
    // The return value of main() is used as the program's exit code. 
    // By convention, 0 means success, and any non-zero value indicates an error.
    // so you could add in-line debugging of certain conditions by returning different non-zero values.
    return 0;
}



// How to use this program:
// 1. Open the terminal in the same folder as this file
// 2. Compile: g++ HelloWorld.cpp -o HelloWorld (g++ is the GNU free C++ compiler I have installed in my Ubuntu WSL partition), the -o flag specifies the output file name for the compiled program, that compiled file is sometimes called a "binary" or "executable".  It doesn't have a file extension because compiled programs are platform-specific and don't need one.

// C++ files have to be compiled before they can run because the source code needs to be translated into machine code, binary or executable.  You can't open those in VSCode because they're not meant to be edited directly, you just run a new compile with your updated source file.

// most programming languages are designed for human readability (Python in particular is less punctuation dependent and more tabs to indicate ownership), so they need to be compiled, the compiler is like a translator.

// 3. Run: ./HelloWorld (./ means current directory), you don't need to include the file extension (.cpp) but you do need to include it when compiling. If you do include the extension in this command, it will still work, but it's not necessary unless you have more than one file with the same name in the folder.

// 4. to save time you can run the commands with a single line by using && to chain them together, like this:
//    g++ HelloWorld.cpp -o HelloWorld && ./HelloWorld
//    This will compile the program and, if the compilation is successful, immediately run the resulting executable.  If the compile runs badly, the second command (./HelloWorld) will not execute. 

// If the compiler worked, the program should print "Hello, World!" in the console under the command. If it successfully ran and returned 0, the next line down should revert to your command prompt (the ~ in my terminal setup.)