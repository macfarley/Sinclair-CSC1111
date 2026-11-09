//Name: Travis McCoy
//Date: 11/4/2026
//Program Name: Functions Exercise 2
//Program Description: Simulates an online ordering system using functions.

#include <iostream> // Provides cin, cout, and endl.
#include <iomanip>  // Provides fixed, setprecision, and setw.
#include <sstream>  // Provides istringstream for checking an entire input line.
#include <string>   // Provides string and getline.
using namespace std; // for cin, cout, etc.

// Read a whole number, retrying invalid lines and stopping at end of input.
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

        // Check the whole line, not just the integer before a decimal or text.
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

// Receive the current prices and display them without changing them.
void displayMenu(double lasagna, double ravioli, double garlicKnot)
{
    cout << "\n========== MENU ==========\n";
    // Display prices with exactly two digits after the decimal point.
    cout << fixed << setprecision(2);

    cout << "Benvenuti! Welcome to Luigi's Italiano!\n";
    // setw sets the minimum width of the next price, helping align the menu.
    cout << "1. Lasagna--- $" << setw(6) << lasagna << endl;
    cout << "2. Ravioli---- $" << setw(6) << ravioli << endl;
    cout << "3. Garlic Knots----- $" << setw(6) << garlicKnot << endl;
    cout << "4. Cash Out" << endl;
}

// Calculate the 20% tip from the food subtotal, then display the final bill.
void displayBill(double subtotal)
{
    double tip = subtotal * 0.20;
    double total = subtotal + tip;

    cout << "\n========== FINAL BILL ==========\n";
    // Format the bill as dollars and cents.
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "20% Tip : $" << tip << endl;
    cout << "Total   : $" << total << endl;
}

int main()
{
    // Store the price of one order of each item.
    double lasagnaPrice = 14.99;
    double ravioliPrice = 12.49;
    double garlicKnotPrice = 9.99;

    int choice;    // The customer's menu selection.
    int quantity;  // The number of servings to add.
    double subtotal = 0.00;
    bool hasItems = false;

    // Continue until the customer checks out a nonempty order.
    do
    {
        displayMenu(lasagnaPrice, ravioliPrice, garlicKnotPrice);

        if (!readWholeNumber("\nEnter your choice: ", choice))
        {
            return 1;
        }

        // Only food choices require a quantity.
        if (choice >= 1 && choice <= 3)
        {
            if (!readWholeNumber("How many would you like? (0 to cancel): ", quantity))
            {
                return 1;
            }

            // Reject negative quantities; zero cancels the current selection.
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

            // Add the selected item's price times its quantity to the order.
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

            // Show the running subtotal before the tip.
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
            // Only a nonempty order can be checked out.
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

/*
Manual test cases (enter each value on a separate line):

1. Empty order: 4, 1, 1, 4
   Expected: show "You haven't added anything to your order yet.",
   return to the menu, then add one lasagna and check out.

2. Mixed order: 1, 2, 2, 1, 3, 3, 4
   Orders 2 lasagnas, 1 ravioli, and 3 garlic knots.
   Expected: subtotal $72.44, tip $14.49, total $86.93.

3. Negative quantity: 1, -1, 2, 4
   Expected: reject -1, accept 2, and show a $29.98 subtotal.

4. Zero quantity: 1, 2, 2, 0, 4
   Expected: cancel the ravioli selection, return to the menu, and
   preserve the previous $29.98 subtotal without adding ravioli.

5. Invalid menu choice: 5, 1, 1, 4
   Expected: show an error, display the menu again, then check out.

6. Non-numeric menu choice: abc, 1, 1, 4
   Expected: reject abc, ask again, then check out.

7. Non-numeric quantity: 1, abc, 2, 4
   Expected: reject abc, accept 2, and show a $29.98 subtotal.

8. End of input (Ctrl+D on Linux): immediately at the first prompt
   Expected: report that the order was not completed and exit.

9. Blank or whitespace-only input: press Enter at either prompt, then
   enter a valid value. Expected: reject the blank input and ask again.

10. Fractional quantity: 1, 1.5, 2, 4
    Expected: reject 1.5, accept 2, and show a $29.98 subtotal.

11. Extra characters or an out-of-range number: 1, 2abc,
    999999999999999999999, 2, 4
    Expected: reject both invalid quantities, then accept 2.

12. Cancel after a negative quantity: 3, -1, 0, 4, 1, 1, 4
    Expected: reject -1, cancel the garlic knots selection, and return
    to the menu; reject empty checkout, then add lasagna and check out.
*/