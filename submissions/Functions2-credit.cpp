// Name: Travis McCoy
// Date: 11/4/2026
// Program Name: Functions Exercise 2
// Program Description: Simulates an online ordering system using functions.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

// Read and validate an entire line as a whole number.
bool readWholeNumber(const string& prompt, int& number)
{
    string line;
    while (true)
    {
        cout << prompt;
        if (!getline(cin, line))
        {
            cerr << "\nInput ended; the order was not completed." << endl;
            return false;
        }

        istringstream input(line);
        if (input >> number)
        {
            input >> ws;
            if (input.eof())
            {
                return true;
            }
        }
        cout << "Please enter a whole number." << endl;
    }
}

// Display the menu with prices formatted as dollars and cents.
void displayMenu(double lasagna, double ravioli, double garlicKnot)
{
    cout << "\n========== MENU ==========\n";
    cout << fixed << setprecision(2);

    cout << "Benvenuti! Welcome to Luigi's Italiano!\n";
    cout << "1. Lasagna--- $" << setw(6) << lasagna << endl;
    cout << "2. Ravioli---- $" << setw(6) << ravioli << endl;
    cout << "3. Garlic Knots----- $" << setw(6) << garlicKnot << endl;
    cout << "4. Cash Out" << endl;
}

// Calculate the tip and total from the subtotal.
void displayBill(double subtotal)
{
    double tip = subtotal * 0.20;
    double total = subtotal + tip;

    cout << "\n========== FINAL BILL ==========\n";
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "20% Tip : $" << tip << endl;
    cout << "Total   : $" << total << endl;
}

int main()
{
    double lasagnaPrice = 14.99;
    double ravioliPrice = 12.49;
    double garlicKnotPrice = 9.99;

    int choice;
    int quantity;
    double subtotal = 0.00;
    bool hasItems = false;

    // Continue taking orders until a nonempty order is checked out.
    do
    {
        displayMenu(lasagnaPrice, ravioliPrice, garlicKnotPrice);

        if (!readWholeNumber("\nEnter your choice: ", choice))
        {
            return 1;
        }

        if (choice >= 1 && choice <= 3)
        {
            if (!readWholeNumber("How many would you like? (0 to cancel): ", quantity))
            {
                return 1;
            }

            while (quantity < 0)
            {
                if (!readWholeNumber("Quantity cannot be negative. Enter again (0 to cancel): ", quantity))
                {
                    return 1;
                }
            }

            if (quantity == 0)
            {
                cout << "Selection cancelled. Returning to menu.\n";
                continue;
            }

            // Add the cost of the selected quantity to the subtotal.
            switch (choice)
            {
                case 1:
                    subtotal += lasagnaPrice * quantity;
                    cout << "Added lasagna.\n";
                    break;
                case 2:
                    subtotal += ravioliPrice * quantity;
                    cout << "Added ravioli.\n";
                    break;
                case 3:
                    subtotal += garlicKnotPrice * quantity;
                    cout << "Added garlic knots.\n";
                    break;
            }
            hasItems = true;

            cout << "Current subtotal: $" << fixed
                 << setprecision(2) << subtotal << endl;
        }
        else if (choice == 4)
        {
            if (!hasItems)
            {
                cout << "You haven't added anything to your order yet.\n";
                continue;
            }
            displayBill(subtotal);
            break;
        }
        else
        {
            cout << "Invalid menu choice.\n";
        }

    } while (true);

    cout << "\nThank you for dining with us! Arrivederci!" << endl;

    return 0;
}
