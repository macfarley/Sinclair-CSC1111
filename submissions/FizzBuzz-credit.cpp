#include <iostream>
using namespace std;

int main() {
    int startNumber = 1;
    int endNumber = 100;

    for (int number = startNumber; number <= endNumber; number++) {
        bool divisibleByThree = (number % 3 == 0);
        bool divisibleByFive = (number % 5 == 0);

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
