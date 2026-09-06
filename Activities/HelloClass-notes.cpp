// HelloClass-notes.cpp
// This is the learning version of the Hello Class assignment.
// It is meant to explain the ideas behind the code, not just provide the final output.

#include <iostream>
using namespace std;

int main() {
    // string is a text data type, like a string in Python.
    string name = "Mac McCoy";
    string major = "Data Analytics AAS";

    // int stores a whole number without decimals.
    int credits = 6;

    // Reflection text explains how this course helps the student grow.
    string reflection = "This course will help me by formalizing what I learned at General Assembly. C++ is a new language for me, but will build on the syntax learned in Python and JavaScript.";

    // cout writes output to the console.
    // It is like print() in Python or console.log() in JavaScript.
    cout << "Name: " << name << endl;
    cout << "Major: " << major << endl;
    cout << "Credits this term: " << credits << endl;
    cout << "How this course helps my goals: " << reflection << endl;

    // Returning 0 means the program finished successfully.
    return 0;
}
