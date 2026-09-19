// Mac McCoy
// 2024-09-19
// Expressions2-credit.cpp
// Calculates the estimate for computer equipment and switch counts.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

/* Format the amount with two decimal places, add commas to the whole-number portion, and return the result with a dollar sign. */
string formatCurrency(double amount) {
    ostringstream amountStream;
    amountStream << fixed << setprecision(2) << amount;
    string formattedAmount = amountStream.str();
    size_t decimalPosition = formattedAmount.find('.');

    for (int position = static_cast<int>(decimalPosition) - 3;
         position > 0;
         position -= 3) {
        formattedAmount.insert(position, ",");
    }

    return "$" + formattedAmount;
}

int main() {
     /* Store the fixed prices and prepare variables for input and calculations. */
    double computerPrice = 50.0;
    double switchPrice = 125.0;
    double consultationFee = 200.0;

    string companyName;
    int computerCount = 0;
    int switchCount = 0;
    double computerCost = 0.0;
    double switchCost = 0.0;
    double finalEstimate = 0.0;
    string formattedFinalEstimate;

     /* Display the available equipment and service prices before collecting input. */
    cout << "Cybersecurity Service Pricing" << endl;
    cout << left << setw(24) << "Item"
         << right << setw(12) << "Price" << endl;
    cout << left << setw(24) << "Computer"
         << right << setw(12) << computerPrice << endl;
    cout << left << setw(24) << "Switch"
         << right << setw(12) << switchPrice << endl;
    cout << left << setw(24) << "Consultation Fee"
         << right << setw(12) << consultationFee << endl;

    cout << endl << "Enter the company name: ";
    getline(cin, companyName);

          /* Ask for the computer count until the user enters a whole number and
                confirms the value with Y or Yes. */
    string confirm;
    bool confirmed = false;
    while (!confirmed) {
        cout << "How many computers do you need for company "
             << companyName << "? ";

        if (!(cin >> computerCount)) {
            cout << "Please enter a whole number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "You said " << computerCount
             << " computers. Is that correct? (y/n): ";
        cin >> confirm;
        confirmed = confirm == "Y" || confirm == "y" ||
                    confirm == "Yes" || confirm == "yes";

        if (!confirmed) {
            cout << "You need to confirm the computer count to continue." << endl;
        }
    }

          /* Divide computers by six and round up to find the required switches.
                Multiply each quantity by its price, then add the consultation fee. */
    switchCount = ceil(computerCount / 6.0);
    cout << "Every 6 computers require one switch." << endl;
    cout << "Calculated switch count for " << computerCount
         << " computers: " << switchCount << endl;

    cout << "Calculating costs..." << endl;
    computerCost = computerCount * computerPrice;
    switchCost = switchCount * switchPrice;
    finalEstimate = computerCost + switchCost + consultationFee;

    cout << "Computer cost for " << computerCount << " computers: $" << computerCost << endl;
    cout << "Switch cost for " << switchCount << " switches: $" << switchCost << endl;
    cout << "Add in our base consultation fee: $" << consultationFee << endl;
    cout << "And your final estimate becomes: $" << finalEstimate << endl;

     /* Print an itemized invoice showing each quantity, unit price, and total. */
    cout << endl << "Cybersecurity Estimate for " << companyName << endl;
    cout << left << setw(15) << "Item"
         << right << setw(10) << "Quantity"
         << right << setw(15) << "Unit Price"
         << right << setw(15) << "Total" << endl;
    cout << setw(55) << setfill('-') << "" << setfill(' ') << endl;
    cout << left << setw(15) << "Computers"
         << right << setw(10) << computerCount
         << right << setw(15) << computerPrice
         << right << setw(15) << computerCost << endl;
    cout << left << setw(15) << "Switches"
         << right << setw(10) << switchCount
         << right << setw(15) << switchPrice
         << right << setw(15) << switchCost << endl;
    cout << left << setw(15) << "Consultation"
         << right << setw(10) << 1
         << right << setw(15) << consultationFee
         << right << setw(15) << consultationFee << endl;
    cout << setw(55) << setfill('-') << "" << setfill(' ') << endl;
    cout << left << setw(15) << "Total"
         << right << setw(10) << ""
         << right << setw(15) << ""
         << right << setw(15) << finalEstimate << endl;

    // Format the final estimate for a readable currency display.
    formattedFinalEstimate = formatCurrency(finalEstimate);
    cout << "Your final estimate is " << formattedFinalEstimate
         << ". Do you have a line of credit set up or will you be paying the full balance today?"
         << endl;

    return 0;
}
