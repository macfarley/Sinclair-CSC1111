// Mac McCoy
// Date: 2024-06-06
// Program Name: Expressions Exercise 1 - Tour Company Receipt
// Program Description: Collect tour ticket choices and prepare an itemized receipt.


#include <cmath>       // Provides ceil(), which will be needed for tour guides.
#include <iomanip>     // Provides fixed, setprecision(), and setw() for receipt columns.
#include <iostream>    // Provides cin, cout, and getline() for console input/output.
#include <sstream>     // Provides ostringstream for formatting a complete money field.
#include <string>      // Provides the string data type for names and tour labels.

using namespace std;

int main() {
    // -------------------------------------------------------------------------
    // Company and tour information
    // -------------------------------------------------------------------------
    // Choose a company name and three tour names for the finished program.
    // Keeping these as variables makes the labels easy to change in one place.
    string companyName = "International Tours of Bixby, Oklahoma";
    
    string tourTitle = "Kleenex brand Facial Tissue Production Plant Tour";
    
    // Ticket price variables
    double adultPrice = 59.95;
    double childPrice = 19.95;
    double studentPrice = 29.95;

    // The tax rate is stored as a decimal because it will be used in a multiplication calculation. The assignment specifies 7.5 percent.
    const double taxRate = 0.075;

    // Input variables

    string groupLeaderName;

    // The ticket counts record how many tickets the group wants to purchase.

    int adultTickets = 0;
    int childTickets = 0;
    int studentTickets = 0;
    string confirmResponse;
    //initialize the ticketsConfirmed flag to false
    bool ticketsConfirmed = false;

    // Calculated-value variables
    // These variables provide named storage for each step of the receipt. They are declared before the calculations so the receipt can use clear names.
    double adultTicketCost = 0.00;
    double childTicketCost = 0.00;
    double studentTicketCost = 0.00;
    double ticketSubtotal = 0.00;
    double taxAmount = 0.00;
    double finalTourTotal = 0.00;

    int totalPeople = 0;
    int tourGuideCount = 0;

    // Display ticket prices to user
    cout << endl << endl << "Thank you for choosing " << companyName << ". Your only choice for exciting, unforgettable tours!" 
        << endl  << endl;
    cout << "Ticket Prices for " << tourTitle << endl;
    cout << " Adult: $" << adultPrice << endl
        << " Child: $" << childPrice << endl
        << " Student: $" << studentPrice << endl << endl;



    // Collect group information and ticket quantities
    // The prompt must appear before getline(). If another input operation is added immediately before getline(), remember to handle its leftover newline.
    // getline() is required for the group leader so names containing spaces can be read as one complete value.  Otherwise it breaks and truncates at the first space.
    cout << "Enter the group leader's name: ";
    getline(cin, groupLeaderName);

    while (!ticketsConfirmed) { //Not Confirmed yet loop
        cout << endl << "Welcome, " << groupLeaderName << "! " << endl
        << "How many adult tickets will you need for your group? ";
        cin >> adultTickets;

        cout << endl << "How many child tickets will you need for your group? ";
        cin >> childTickets;

        cout << endl << "How many student tickets will you need for your group? ";
        cin >> studentTickets;
        
        //sanity check here: ensure at least one ticket is selected
        totalPeople = adultTickets + childTickets + studentTickets;
        if (totalPeople == 0)
        {
            cout << "You must select at least one ticket." << endl;
            continue; // Skip the rest of the loop and prompt again.
        }
        

        while (true) {
            cout << endl << "I have a total of " << totalPeople << " guests." << endl
                << "Adult tickets: " << adultTickets << endl
                << "Child tickets: " << childTickets << endl
                << "Student tickets: " << studentTickets << endl
                << "Is this correct? Enter Y/Yes or N/No: ";
            cin >> confirmResponse; // Store the user's confirmation response.

            if (confirmResponse == "Y" || confirmResponse == "y" ||
                confirmResponse == "Yes" || confirmResponse == "yes") {
                cout << "Confirmed. Continuing with your tour reservation." << endl;
                ticketsConfirmed = true;
                break;
            }
            else if (confirmResponse == "N" || confirmResponse == "n" ||
                     confirmResponse == "No" || confirmResponse == "no") {
                cout << "Please review your ticket information."
                     << " Let's try that again." << endl;
                break;
            }
            else {
                cout << "I'm sorry, that response was not recognized. Please enter Y/Yes to confirm or N/No to check your ticket quantities." << endl;
            }
        }
    }
    
    // Perform calculations
    // Calculate the number of tour guides needed based on the total number of people, always a whole integer.
    tourGuideCount = ceil(totalPeople / 3.0);

    cout << "To enhance the experience, we require 1 tour guide per 3 guests." << endl 
        << "With a total group count of " << totalPeople << ", this group will require " 
        << tourGuideCount << " tour guides." << endl;

    // Calculate the subtotals for the tickets.
    adultTicketCost = adultTickets * adultPrice;
    childTicketCost = childTickets * childPrice;
    studentTicketCost = studentTickets * studentPrice;
    ticketSubtotal = adultTicketCost + childTicketCost + studentTicketCost;
    taxAmount = ticketSubtotal * taxRate;
    finalTourTotal = ticketSubtotal + taxAmount;

    // Display the column-formatted receipt
    // -------------------------------------------------------------------------
    // fixed and setprecision(2) keep money values readable as dollars and cents.
    // setw() "set width (in characters for the next output field)" creates aligned columns so the receipt is easy to scan.

    cout << fixed << setprecision(2);
    cout << endl << "Receipt" << endl;
    cout << "Group Leader: " << groupLeaderName << endl;
    cout << "Tour Guides: " << tourGuideCount << endl;
    cout << left << setw(18) << "Ticket Type"
	    << right << setw(10) << "Cost"
	    << setw(12) << "How Many"
	    << setw(12) << "Total" << endl;

    cout << left << setw(18) << "Adult"
            << right << setw(10) << adultPrice
         << setw(12) << adultTickets
            << setw(12) << adultTicketCost << endl;

    cout << left << setw(18) << "Child"
            << right << setw(10) << childPrice
         << setw(12) << childTickets
            << setw(12) << childTicketCost << endl;

    cout << left << setw(18) << "Student"
            << right << setw(10) << studentPrice
         << setw(12) << studentTickets
            << setw(12) << studentTicketCost << endl;

    cout << left << setw(18) << "Subtotal"
         << right << setw(10) << ""
         << setw(12) << ""
         << setw(12) << ticketSubtotal << endl;

    cout << left << setw(18) << "Tax"
         << right << setw(10) << ""
         << setw(12) << ""
         << setw(12) << taxAmount << endl;

        ostringstream formattedFinalTotal;
        formattedFinalTotal << "$" << fixed << setprecision(2) << finalTourTotal;

    cout << left << setw(18) << "Total"
         << right << setw(10) << ""
         << setw(12) << ""
            << setw(12) << formattedFinalTotal.str() << endl;

    /* Testing Data
    Use each row as a separate test run. Enter the ticket counts, confirm them with Y, and compare the program's receipt to the expected values. 
    Current prices: Adult = $59.95, Child = $19.95, Student = $29.95. 
    Tax rate: 7.5 percent.
    Test Case | Adult | Child | Student | People | Guides | Subtotal | Tax    | Final Total
    ----------|-------|-------|---------|--------|--------|----------|--------|------------
    Case 1    |   2   |   5   |    1    |   8    |   3    |  $249.60 | $18.72 | $268.32
    Case 2    |   0   |   0   |    4    |   4    |   2    |  $119.80 |  $8.99 | $128.79
    Case 3    |   7   |   2   |    0    |   9    |   3    |  $459.55 | $34.47 | $494.02
    */
    return 0; // condition 0 is always the successful outcome and end program
}

/* Compile and run from any terminal:
 g++ -std=c++17 Expressions1-notes.cpp -o Expressions1-notes && ./Expressions1-notes
*/