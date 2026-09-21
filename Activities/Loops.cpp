// Demonstrates fixed-point formatting and a field width for four values.

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	double star1 = 1.234;
	double star2 = 12.345;
	double star3 = 123.456;
	double star4 = 1234.567;

	/* Put the existing star values into an array, then format each value
	   with two decimal places, fixed notation, and an eight-character field. */
	double stars[] = {star1, star2, star3, star4};
	int starCount = sizeof(stars) / sizeof(stars[0]);

	cout << fixed << setprecision(2);
	for (int index = 0; index < starCount; index++) {
		cout << setw(8) << stars[index] << endl;
	}

	return 0;
}
