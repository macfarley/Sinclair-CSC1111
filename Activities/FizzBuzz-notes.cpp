// FizzBuzz-notes.cpp
// This is the learning-friendly version of the FizzBuzz exercise.
// Rubber-ducky explanation:
// We loop through a range of numbers, check divisibility, and print
// either the number itself or a special word when the rule matches.
// This is a classic beginner problem because it combines loops, if/else,
// and the modulo operator (%), which gives us the remainder after division.

#include <iostream>
using namespace std;

int main() {
    // startNumber and endNumber define the range of values we inspect.
    int startNumber = 1;
    int endNumber = 100;

    // A for loop repeats the code while the counter stays in range.
    // This is similar to a Python range loop or a JavaScript for loop.
    for (int number = startNumber; number <= endNumber; number++) {
        bool divisibleByThree = (number % 3 == 0);
        bool divisibleByFive = (number % 5 == 0);

        // Order matters here: FizzBuzz should win when both rules match.
        // If we tested the single checks first, the combined case would be
        // missed because the first match would stop the condition chain.
        if (divisibleByThree && divisibleByFive) {
            cout << "FizzBuzz" << endl;
        } else if (divisibleByThree) {
            cout << "Fizz" << endl;
        } else if (divisibleByFive) {
            cout << "Buzz" << endl;
        } else {
            cout << number << endl;
        }
    }

    return 0;
}
