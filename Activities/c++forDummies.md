CSC 1111 Weeks 1–2: Beginner’s Guide for a Python/React Developer
CSC 1111 Weeks 1–2: Beginner’s Guide for a Python/React Developer
A practical, no‑nonsense guide to the first two weeks of an intro C++ course — written for someone who already understands programming logic from Python and React.

1. What C++ Actually Is (Compared to Python)
C++ is a compiled, statically typed language. You must:

Declare types explicitly.

Compile before running.

Manage memory more directly.

But the core logic — variables, loops, functions — is the same.

Mental model: Python is automatic; C++ is manual.

2. Your First C++ Program
Every C++ program needs a main() function.

#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
Breakdown
#include <iostream> — imports input/output tools.

int main() — required entry point.

std::cout — C++ version of print().

return 0; — signals successful program end.

3. Variables & Types
Python lets you write:

x = 10
C++ requires:

int x = 10;
Common Types
int — whole numbers

double — decimals (called Floats elsewhere)

char — single characters

bool — true/false (Boolean logic)

std::string — text

Type Inference
Modern C++ allows:

auto y = 3.14;  // becomes double
4. Input & Output
Output
std::cout << "Result: " << value << std::endl;
Input
int age;
std::cin >> age;
Note: cin stops at whitespace. You’ll learn safer input methods later.

5. Conditionals
Python:

if x > 10:
    ...
C++:

if (x > 10) {
    ...
}
Structure Rules
Parentheses around conditions.

Curly braces for blocks.

6. Loops
for loop
for (int i = 0; i < 10; i++) {
    std::cout << i << std::endl;
}
while loop
while (count > 0) {
    count--;
}
do-while
Runs at least once.

do {
    std::cout << "Running";
} while (condition);
7. Functions
Python:

def add(a, b):
    return a + b
C++:

int add(int a, int b) {
    return a + b;
}
Key Differences
Must declare return type.

Must declare parameter types.

Must end statements with semicolons.

8. Arrays & Vectors
Arrays (fixed size)
int nums[5] = {1, 2, 3, 4, 5};
Vectors (dynamic, like Python lists)
#include <vector>

std::vector<int> nums = {1, 2, 3};
nums.push_back(4);
Use vectors unless the assignment specifically requires arrays.

9. Basic String Handling
std::string name = "Mac";
std::cout << name.length();
Common Operations
.length() — size

+ — concatenation

name[i] — indexing

10. Compilation Workflow
Unlike Python, you must compile.

Typical workflow:

Write program.cpp

Compile:

g++ program.cpp -o program
Run:

./program
Errors appear at compile time, not runtime.

11. Common Beginner Mistakes
Missing semicolons.

Forgetting #include <iostream>.

Using = instead of == in conditions.

Not initializing variables.

Confusing arrays with vectors.

12. Week 1–2 Practice Problems
1. Basic I/O
Write a program that asks for your name and age, then prints a greeting.

2. Conditionals
Ask for a number and print whether it’s even or odd.

3. Loops
Print numbers 1–100.

4. Functions
Write a function that returns the larger of two numbers.

5. Arrays/Vectors
Store 5 numbers in a vector and compute their sum.

13. Quick Reference Table
Concept

Python

C++

Types

dynamic

static

Printing

print()

std::cout

Input

input()

std::cin

Lists

list

vector

Functions

simple

typed

Errors

runtime

compile-time

14. Suggested Next Steps
Practice writing small programs.

Get comfortable with cout, cin, loops, and functions.

Use vectors instead of arrays unless required.

Start reading error messages carefully — they matter.

15. Helpful Follow-Up Topics
C++ syntax basics

Pointers explained simply

Side-by-side C++ vs Python examples

CSC 1111 practice problems

Write your first multi-file C++ project



