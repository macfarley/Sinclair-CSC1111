// Mac McCoy
// August 30, 2026
// FizzBuzz.cpp
// Practice using loops, conditionals, and the modulo operator.

// Needed for cout, which prints to the console.
// Similar idea to importing a module in Python or JavaScript.
#include <iostream>

// Lets me write cout instead of std::cout in this beginner program.
using namespace std;

// main() is where a C++ program starts running.
int main() {
	// These variables define the range the program will check.
	// In JavaScript or Python, I could also use values like these in a for loop.
	int startNumber = 1;
	int endNumber = 100;

	// A for loop repeats code while the counter stays within the range.
	// This is similar to: for (let number = 1; number <= 100; number++) in JavaScript.
	// It is also similar to: for number in range(1, 101): in Python.
	for (int number = startNumber; number <= endNumber; number++) {
		// TODO: Decide which divisibility checks need to happen first.
		// % is the modulo operator: it gives the remainder after division.
		// Example: 10 % 5 is 0 because 10 divides evenly by 5.

		// TODO: Add if / else if / else statements here.
		// if is used to make a decision based on true or false conditions.
		// The order matters when a number matches more than one rule.

		// TODO: In each branch, use cout to print either a word or the number.
		// endl puts the next result on a new line.
	}

	// 0 means the program finished successfully.
	return 0;
}

// How to run this program from the terminal:
// 1. Open a terminal in this folder.
// 2. Compile: g++ FizzBuzz.cpp -o FizzBuzz
// 3. Run: ./FizzBuzz
// Or combine both steps: g++ FizzBuzz.cpp -o FizzBuzz && ./FizzBuzz
