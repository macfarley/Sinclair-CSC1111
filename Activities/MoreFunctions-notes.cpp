// Mac McCoy
// November 9, 2026
// Trigonometry functions
// Takes user input for triangle sides and calculates perimeter and area

// Include libraries needed for:
// - input/output
// - square root calculations
// - output formatting (2 decimal places)
#include <cmath> //math keywords like sqrt
#include <iomanip> // for setprecision
#include <iostream> // for cin/cout
#include <sstream>
#include <string>
using namespace std; // for convenience, saves repetition of std::

// Create variables for:
    // first leg length
        double side1;
    // second leg length
    double side2;
    // sum of sides result
    double perimeter;
    // area result
    double area;

// Read a whole line containing one positive number up to the chosen maximum.
// Returns false if input ends or the maximum is invalid.
bool readPositiveNumber(const string& prompt, double maximum, double& number)
{
    if (!isfinite(maximum) || maximum <= 0)
    {
        cerr << "The maximum must be a finite positive number." << endl;
        return false;
    }

    string line;
    while (true)
    {
        cout << prompt;
        if (!getline(cin, line))
        {
            cerr << "\nCould not read input; the calculation was not completed." << endl << endl << endl;
            return false;
        }

        istringstream input(line);
        double value;
        if (input >> value)
        {
            input >> ws;
            if (input.eof() && isfinite(value) && value > 0 && value <= maximum)
            {
                number = value;
                return true;
            }
        }

        cout << "Enter one positive number no greater than " << maximum << "." << endl << endl << endl;
    }
}

// Function for perimeter:
// Receives the lengths of the two legs
// Calculates the hypotenuse using the Pythagorean Theorem
// Calculates the sum of all three sides
// Returns the sum of the sides
double perimeterFormula(double side1, double side2){
    double hypotenuse = sqrt(side1*side1 + side2*side2);
    return perimeter = side1 + side2 + hypotenuse;
};


// Function for area:
// Receives the lengths of the two legs
// Calculates the area of the right triangle
// Returns the area
double areaFormula(double side1, double side2){
    return area = 0.5 * (side1 * side2);
};


int main()
{
    const double maximumSide = 1000000;
    if (!readPositiveNumber("Enter the length of triangle side 1: ", maximumSide, side1) ||
        !readPositiveNumber("Enter the length of triangle side 2: ", maximumSide, side2))
    {
        return 1;
    }

    // Call the sum-of-sides function
    // Store the returned value
    perimeter = perimeterFormula(side1, side2);

    // Call the area function
    // Store the returned value
    area = areaFormula(side1, side2);

    // Format output to display 2 decimal places
    cout << fixed << setprecision(2);

    // Display a label for side 1
    cout << "Side 1: " << side1 << endl;

    // Display a label for side 2
    cout << "Side 2: " << side2 << endl;

    // Display the total sum of sides
    cout << "Perimeter: " << perimeter << endl;

    // Display the area
    cout << "Area: " << area << endl;

    // End program
    return 0;
}


/* Test Data
Case | Side 1 | Side 2 | Expected result
-----|--------|--------|-----------------------------------------------
1    | 3      | 4      | Perimeter 12.00; area 6.00
2    | 5      | 12     | Perimeter 30.00; area 30.00
3    | 1      | 1      | Perimeter 3.41; area 0.50
4    | 1.5    | 2      | Perimeter 6.00; area 1.50
5    | 0.5    | 1.2    | Perimeter 3.00; area 0.30
6    | 0      | 4      | Reject 0, then ask for side 1 again
7    | -3     | 4      | Reject -3, then ask for side 1 again
8    | 3      | -4     | Reject -4, then ask for side 2 again
9    | 0      | 0      | Reject each 0 when entered for a side
10   | abc    | 4      | Reject abc, then ask for side 1 again
11   | 1e154  | 1e154  | Reject each value: exceeds the maximum
12   | 1e308  | 1e308  | Reject each value: exceeds the maximum
13   | 1e6    | 1e6    | Perimeter 3414213.56; area 500000000000.00
14   | 3abc   | 4      | Reject 3abc, then ask for side 1 again

After an invalid entry, provide a valid replacement for that same side.
Ending input instead should report an error and stop without a result.
For valid cases, display two decimal places.
*/

/* Reflections:
When I tested my program, I first tried to compile it, but it stopped before I could run the test cases. I found that I had used ^ for squaring, but C++ uses the pow keyword instead, not the upcarrot^ exponents. I tried to break the program with invalid input to see if it handled errors correctly, ended up creating a re-usable helper function for reading numbers for projects like this: only accepts positive numbers under a million. */