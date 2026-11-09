// Mac McCoy
// November 9, 2026
// Trigonometry functions
// Calculates the perimeter and area of a right triangle.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double side1;
double side2;
double perimeter;
double area;

/* Read a complete line and accept one positive number within the limit. */
bool readPositiveNumber(const string& prompt, double maximum, double& number){
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

/* Calculate the hypotenuse and add it to the two legs. */
double perimeterFormula(double side1, double side2)
{
    double hypotenuse = sqrt(side1 * side1 + side2 * side2);
    return perimeter = side1 + side2 + hypotenuse;
}

/* Calculate the area from the two perpendicular legs. */
double areaFormula(double side1, double side2)
{
    return area = 0.5 * (side1 * side2);
}

int main()
{
    /* Read both legs before calculating either result. */
    const double maximumSide = 1000000;
    if (!readPositiveNumber("Enter the length of triangle side 1: ", maximumSide, side1) ||
        !readPositiveNumber("Enter the length of triangle side 2: ", maximumSide, side2))
    {
        return 1;
    }

    perimeter = perimeterFormula(side1, side2);
    area = areaFormula(side1, side2);

    /* Display the sides and results to two decimal places. */
    cout << fixed << setprecision(2);
    cout << "Side 1: " << side1 << endl;
    cout << "Side 2: " << side2 << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

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

/* Reflection:
I used the Pythagorean theorem to find the hypotenuse, then added all three
sides for the perimeter. I used half the product of the legs for the area.
My first compilation revealed that ^ does not mean exponentiation in C++, so
I used multiplication to square each leg. Testing invalid and very large
inputs showed that I needed better validation. I used a reusable function
to check the whole input line, reject values outside the allowed range, and
prompt again. Normal and fractional test cases produced the expected results,
and invalid entries were rejected.
*/
