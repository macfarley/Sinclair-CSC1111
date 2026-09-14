// Mac McCoy
// 2024-06-05
// Expressions1-credit.cpp
// This program calculates tour ticket totals, tax, and required tour guides.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string companyName = "International Tours of Bixby, Oklahoma";
    string tourTitle = "Kleenex Tissue Plant Tour";
    string groupLeaderName;
    string confirmResponse;

    double adultPrice = 59.95;
    double childPrice = 19.95;
    double studentPrice = 29.95;
    const double taxRate = 0.075;

    int adultTickets = 0;
    int childTickets = 0;
    int studentTickets = 0;
    int totalPeople = 0;
    int tourGuideCount = 0;

    double adultTicketCost = 0.00;
    double childTicketCost = 0.00;
    double studentTicketCost = 0.00;
    double ticketSubtotal = 0.00;
    double taxAmount = 0.00;
    double finalTourTotal = 0.00;

    bool ticketsConfirmed = false;

    // Display ticket prices before collecting customer input.
    cout << "Thank you for choosing " << companyName << ". Your only choice for exciting, unforgettable tours!"
         << endl << endl;
    cout << "Ticket Prices for " << tourTitle << endl;
    cout << " Adult: $" << adultPrice << endl
         << " Child: $" << childPrice << endl
         << " Student: $" << studentPrice << endl << endl;

    cout << "Enter the group leader's name: ";
    getline(cin, groupLeaderName);

    while (!ticketsConfirmed) {
        // Collect ticket totals and confirm they are correct before continuing.
        cout << "Welcome, " << groupLeaderName << "!" << endl;
        cout << "How many adult tickets will you need for your group? ";
        cin >> adultTickets;

        cout << "How many child tickets will you need for your group? ";
        cin >> childTickets;

        cout << "How many student tickets will you need for your group? ";
        cin >> studentTickets;

        totalPeople = adultTickets + childTickets + studentTickets;
        if (totalPeople == 0) {
            cout << "You must select at least one ticket." << endl;
            continue;
        }

        while (true) {
            cout << "I have a total of " << totalPeople << " guests." << endl
                 << "Adult tickets: " << adultTickets << endl
                 << "Child tickets: " << childTickets << endl
                 << "Student tickets: " << studentTickets << endl
                 << "Is this correct? Enter Y/Yes or N/No: ";
            cin >> confirmResponse;

            if (confirmResponse == "Y" || confirmResponse == "y" ||
                confirmResponse == "Yes" || confirmResponse == "yes") {
                cout << "Confirmed. Continuing with your tour reservation." << endl;
                ticketsConfirmed = true;
                break;
            }
            else if (confirmResponse == "N" || confirmResponse == "n" ||
                     confirmResponse == "No" || confirmResponse == "no") {
                cout << "Please review your ticket information. Let's try that again." << endl;
                break;
            }
            else {
                cout << "I'm sorry, that response was not recognized. Please enter Y/Yes to confirm or N/No to check your ticket quantities." << endl;
            }
        }
    }

    // Calculate tour guides and the final receipt values.
    tourGuideCount = ceil(totalPeople / 3.0);
    adultTicketCost = adultTickets * adultPrice;
    childTicketCost = childTickets * childPrice;
    studentTicketCost = studentTickets * studentPrice;
    ticketSubtotal = adultTicketCost + childTicketCost + studentTicketCost;
    taxAmount = ticketSubtotal * taxRate;
    finalTourTotal = ticketSubtotal + taxAmount;

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

    return 0;
}
