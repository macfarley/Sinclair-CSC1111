// Name: Mac McCoy
// Date: 2026-10-08
// Program Name: The Price Is Close-Enough
// Program Description: The user picks a prize and guesses its price; the program decides whether the guess is within the allowed percentage for that price bracket.

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

/* Returns true if the amount has no fraction of a cent.
   The amount is converted to cents and compared to the nearest whole number;
   a small tolerance is allowed because doubles cannot store most cents exactly. */
bool wholeCents(double amount) {
    return fabs(amount * 100 - round(amount * 100)) <= 0.0001;
}

int main() {
    /* Logic:
       1. Store the prize names, prices, and allowed guess margins.
       2. Display the prize menu and read a valid prize choice.
       3. Read a valid guess (a number, not negative, whole cents).
       4. Pick the margin for the prize's price bracket and check the guess against it.
       5. Display the win or lose message. */

    // Prize names, prices, and bracket margins
    string prizeName1 = "A pair of Apple Airbuds";
    string prizeName2 = "A 5 pack of tickets to the Opera";
    string prizeName3 = "An all-expense paid cruise to Alaska";
    string prizeName4 = "One week at a 5-star resort in Bali";

    // Prize values
    double prizeValue1 = 99.99;
    double prizeValue2 = 150.00;
    double prizeValue3 = 999.00;
    double prizeValue4 = 5000.00;

    // Prize bracket margins
    double smallPrizeMargin = 0.12;
    double mediumPrizeMargin = 0.10;
    double largePrizeMargin = 0.05;
    double smallestWin;
    double largestWin;

    // User input and result
    int userChoice;
    bool userChoiceValid = false;
    string userPrizeName;
    double userPrizeValue;
    double userPrizeValueGuess;
    double guessMargin;
    bool userWins = false;

    // Display the prize menu
    cout << endl;
    cout << "~*~*~ Welcome to The Price Is Close-Enough! ~*~*~" << endl;
    cout << endl << "Here are this week's fabulous prizes!" << endl;
    cout << "1. " << prizeName1 << endl;
    cout << "2. " << prizeName2 << endl;
    cout << "3. " << prizeName3 << endl;
    cout << "4. " << prizeName4 << endl;

    // Prize choice validation: repeat until the choice is 1-4
    while (!userChoiceValid) {
        cout << "Please enter the number for the prize you wish to guess the price of: ";
        cin >> userChoice;
        // Non-numeric input: clear the error and discard the bad text before asking again
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Try again." << endl;
        } else if (userChoice == 1) {
            userPrizeName = prizeName1;
            userPrizeValue = prizeValue1;
            userChoiceValid = true;
        } else if (userChoice == 2) {
            userPrizeName = prizeName2;
            userPrizeValue = prizeValue2;
            userChoiceValid = true;
        } else if (userChoice == 3) {
            userPrizeName = prizeName3;
            userPrizeValue = prizeValue3;
            userChoiceValid = true;
        } else if (userChoice == 4) {
            userPrizeName = prizeName4;
            userPrizeValue = prizeValue4;
            userChoiceValid = true;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    // Guess input
    cout << "What is your price guess for " << userPrizeName << " in dollars and cents? $ ";
    cin >> userPrizeValueGuess;

    // Guess validation: reject non-numeric input, negative values, and fractions of a cent
    while (cin.fail() || userPrizeValueGuess < 0 || !wholeCents(userPrizeValueGuess)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid guess. Enter a non-negative amount in dollars and cents (12.34 for 12 dollars and 34 cents): ";
        cin >> userPrizeValueGuess;
    }

    // The prize price determines the allowed margin; jackpot prizes must be exact
    if(userPrizeValue <= 100){
        guessMargin = smallPrizeMargin;
    } else if(userPrizeValue <= 500){
        guessMargin = mediumPrizeMargin;
    } else if(userPrizeValue <= 1000){
        guessMargin = largePrizeMargin;
    } else {
        guessMargin = 0; // Jackpot prizes must be exact
    }
    smallestWin = userPrizeValue - (userPrizeValue * guessMargin);
    largestWin = userPrizeValue + (userPrizeValue * guessMargin);

    // User wins if their guess falls between smallestWin and largestWin
    if (userPrizeValueGuess >= smallestWin && userPrizeValueGuess <= largestWin) {
        userWins = true;
    }

    // Display the result
    if (userWins) {
        cout << "Congratulations! Your guess was Close Enough!" << endl;
        cout << "Enjoy your " << userPrizeName << ", actual retail price: $" << userPrizeValue << "!" << endl;
        cout << "This is Bob Banker signing off, and remember:" << endl;
        cout << "You can be a winner too, if The Price is...Close Enough!" << endl;
    } else {
        cout << "Sorry, your guess was Not Close Enough. The actual retail price of the " << userPrizeName
             << " is $" << userPrizeValue << "." << endl << endl;
        cout << "But don't worry, you won't be leaving empty-handed!" << endl;
        cout << "All guests on the Price is Close Enough show receive a consolation prize: a lifetime supply of Turtle Wax brand car polish!" << endl;
        cout << "Turtle Wax: it doesn't matter how slow your car is, you'll get there shiny!" << endl;
    }

    return 0;
}

/* Test Data
| # | Prize | Price    | Bracket / Allowance | User Guess | Expected | Actual | Pass / Fail |
|---|-------|----------|---------------------|------------|----------|--------|-------------|
| 1 | 1     | 99.99    | $0-$100 / 12%       | 105.00     | Win      | Win    | Pass        |
| 2 | 1     | 99.99    | $0-$100 / 12%       | 80.00      | Lose     | Lose   | Pass        |
| 3 | 2     | 150.00   | $101-$500 / 10%     | 160.00     | Win      | Win    | Pass        |
| 4 | 2     | 150.00   | $101-$500 / 10%     | 100.00     | Lose     | Lose   | Pass        |
| 5 | 3     | 999.00   | $501-$1,000 / 5%    | 1000.00    | Win      | Win    | Pass        |
| 6 | 3     | 999.00   | $501-$1,000 / 5%    | 800.00     | Lose     | Lose   | Pass        |
| 7 | 4     | 5000.00  | $1,001+ / exact     | 5000.00    | Win      | Win    | Pass        |
| 8 | 4     | 5000.00  | $1,001+ / exact     | 4999.00    | Lose     | Lose   | Pass        |
| 9 | 4     | 5000.00  | $1,001+ / exact     | 5001.00    | Lose     | Lose   | Pass        |
| 10| 2     | 150.00   | Boundary: low edge  | 135.00     | Win      | Win    | Pass        |
| 11| 2     | 150.00   | Boundary: just under| 134.99     | Lose     | Lose   | Pass        |
| 12| 2     | 150.00   | Boundary: high edge | 165.00     | Win      | Win    | Pass        |
| 13| 2     | 150.00   | Boundary: just over | 165.01     | Lose     | Lose   | Pass        |
| 14| 1     | 99.99    | Edge (87.9912-111.9888) | 111.98 | Win      | Win    | Pass        |
| 15| 9, 0  | n/a      | Invalid prize choice| n/a        | Re-prompt| Re-prompt | Pass     |
| 16| 2     | 150.00   | Bad guess: letters  | abc        | Re-prompt| Re-prompt | Pass     |
| 17| 2     | 150.00   | Bad guess: negative | -5         | Re-prompt| Re-prompt | Pass     |
| 18| 2     | 150.00   | Bad guess: 3 decimals | 150.456  | Re-prompt| Re-prompt | Pass     |
| 19| 2     | 150.00   | Bad guess: irrational | 3.14159  | Re-prompt| Re-prompt | Pass     |
| 20| 2     | 150.00   | Bad guess: fraction of a cent | 0.001 | Re-prompt| Re-prompt | Pass |
| 21| 2     | 150.00   | Valid edge: zero    | 0          | Lose     | Lose   | Pass        |
| 22| 2     | 150.00   | Retry after bad guess | abc, then 150 | Re-prompt, then Win | Re-prompt, then Win | Pass |
| 23| n/a   | n/a      | Bad prize choice: letters | xyz, then 2 | Re-prompt| Re-prompt | Pass     |
*/

/* Reflection
I started the assignment by setting up the variables for the prize names, prices, and user inputs, then outlining the logic for comparing the user's guess to the actual value. 
I ran into issues when users entered invalid guesses like letters, negative numbers, or fractional-cent values, which broke the program. To fix that, I added input validation using cin.fail and wrote a helper function to catch fractions of a cent. 
Coming from a background in physical security, I'm used to playing the "what if" game, and that mindset helped me anticipate weird edge cases and potential vulnerabilities in the code. 
Overall, I learned that even simple programs need thorough testing because computers don't understand nonsense unless you explicitly teach them what nonsense looks like.  After building this I might like to try a whole text-based Price is Close Enough game with a "closest without going over" rule, a randomized wheel for showcase showdowns, and perhaps even figure out how to support multiple players on the same game session.  It would probably require a whole database of prizes to keep it fresh.
*/
