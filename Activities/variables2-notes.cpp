// variables2-notes.cpp
// This assignment practices declaring several variables and printing them
// in a readable sentence-based format.

#include <iostream>
using namespace std;

int main() {
    string currentTerm = "Fall 2026";

    string csc1111 = "Intro to C++ Programming";
    string csc2165 = "Database Management";
    string bis1230 = "Spreadsheet Software";
    string math1450 = "Introduction to Data Science";

    string excuse = "I need to scale back my course load this term due to medical reasons.";

    int csc1111Credits = 3;
    int csc2165Credits = 4;
    int bis1230Credits = 3;
    int math1450Credits = 5;

    cout << "During this term, " << currentTerm << ", I am registered for the following courses:"
         << endl;

    cout << "I'm taking " << csc1111 << ", which is worth " << csc1111Credits << " credits, and "
         << csc2165 << ", which is worth " << csc2165Credits << " credits." << endl;

    cout << "I had also planned on taking " << bis1230 << " and " << math1450 << " during "
         << currentTerm << ", which" << endl
         << " are worth " << bis1230Credits << " and " << math1450Credits
         << " credits respectively." << endl;

    cout << "Unfortunately, however, " << excuse << " I decided to drop " << math1450 << " and "
         << bis1230 << ". So instead of" << endl << " taking "
         << csc1111Credits + csc2165Credits + bis1230Credits + math1450Credits
         << " credits, I am now only taking " << csc1111Credits + csc2165Credits << " credits." << endl;

    return 0;
}
