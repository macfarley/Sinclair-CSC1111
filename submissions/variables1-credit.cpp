#include <iostream>
using namespace std;

int main() {
    string parkName = "Anatomy Park";
    string attraction1 = "Spleen Mountain";
    string attraction2 = "Pirates of the Pancreas";
    string attraction3 = "the Bone Train";
    double ticketPrice = 99.95;

    cout << "Welcome...to " << parkName << "." << endl << endl;
    cout << "Our park has 3 family-friendly attractions for you to enjoy: "
         << attraction1 << ", " << attraction2 << ", and " << attraction3 << "." << endl << endl;
    cout << "All for the low introductory admission price of $" << ticketPrice
         << "! Book your trip today." << endl;

    return 0;
}
