// Mac McCoy
// 2024-06-05
// Expressions2-notes
// This program calculates the cost of computers, switches, and consultation fees for a cybersecurity service.

#include <cmath>       // Provides ceil() for calculating the number of switches.
#include <iomanip>     // Provides fixed, setprecision(), and setw() for columns.
#include <iostream>    // Provides cin, cout, and getline().
#include <limits>      // Provides numeric_limits for clearing invalid input.
#include <sstream>     // Provides ostringstream for formatted currency.
#include <string>      // Provides the string data type for the company name.

using namespace std;

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
    // Equipment prices.
    double computerPrice = 50;
    double switchPrice = 125;
    double consultationFee = 200;

    // Input variables.
    string companyName;
    int computerCount = 0;

    // Calculated-value variables.
    int switchCount = 0;
    double computerCost = 0.00;
    double switchCost = 0.00;
    double finalEstimate = 0.00;
     string formattedFinalEstimate;

    // Display pricing to the user.  Using the setw() and alignment manipulators for neat columns.
    cout << "Cybersecurity Service Pricing" << endl;
    cout << left << setw(24) << "Item"
         << right << setw(12) << "Price" << endl;
    cout << left << setw(24) << "Computer"
         << right << setw(12) << computerPrice << endl;
    cout << left << setw(24) << "Switch"
         << right << setw(12) << switchPrice << endl;
    cout << left << setw(24) << "Consultation Fee"
         << right << setw(12) << consultationFee << endl;

    // getline() reads the entire company name, including spaces.
    cout << endl << "Enter the company name: ";
    getline(cin, companyName);

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

    // Calculate the number of switches needed.
    // Two ports are reserved for uplinks, so six computers use one switch.

    switchCount = ceil(computerCount / 6.0);
    cout << "Every 6 computers require one switch." << endl;
    cout << "Calculated switch count for " << computerCount << "  computers: " << switchCount << endl;

    cout << "Calculating costs..." << endl;
    computerCost = computerCount * computerPrice;
    switchCost = switchCount * switchPrice;
    finalEstimate = computerCost + switchCost + consultationFee;

    cout << "Computer cost for " << computerCount << " computers: $" << computerCost << endl;
    cout << "Switch cost for " << switchCount << " switches: $" << switchCost << endl;
    cout << "Add in our base consultation fee: $" << consultationFee << endl;
    cout << "And your final estimate becomes: $" << finalEstimate << endl;

    // Display the itemized invoice in aligned columns.
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

     // Format the final estimate with commas and two decimal places, using the formatCurrency function found inside the Utilities namespace.
     formattedFinalEstimate = formatCurrency(finalEstimate);

     cout << "Your final estimate is " << formattedFinalEstimate
         << ". Do you have a line of credit set up or will you be paying the full balance today?"
         << endl;

    /* Testing Data
    Case | Company Name                  | Computers| Switches | Expected Total
    -----|-------------------------------|----------|----------|----------------
     1    |Fission Chips                  | 199      | 34       | 14400 |
     2    |Series of Tubes, Inc.          | 50       | 9        | 3825  |
     3    |Ultimate Robot Fighting League | 64       | 11       | 4775  |
    */

    return 0;
}

/* Compile and run:
 g++ -std=c++17 Expressions2-notes.cpp -o Expressions2-notes && ./Expressions2-notes
*/
