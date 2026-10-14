// Mac McCoy
// Date: 2026-10-08
// Program Name: Relational-Operators-notes.cpp
/* Program Description: The user picks a prize and guesses its price; the program decides
   whether the guess is within the allowed percentage for that price bracket. */

#include <iostream>
#include <cmath>   // fabs() and round()
#include <limits>  // numeric_limits, used to discard bad input
using namespace std;

/* wholeCents helper function returns true if the amount has no fraction of a cent, otherwise false.
 amount * 100 turns dollars into cents (12.34 -> 1234).
 round() rounds that to the nearest whole number (1234.5 -> 1235).
 Subtracting leaves the fractional-cent part, and fabs() makes it positive (absolute value of a decimal). 
 A double can't store most cents exactly (12.34 is really 12.339999...), so instead of requiring exactly 0,
  we allow a leftover of up to 0.0001. 12.345 leaves 0.5, so it is not whole cents.*/
bool wholeCents(double amount) {
    return fabs(amount * 100 - round(amount * 100)) <= 0.0001;
}

int main() {

    // DECLARE prizeName1 and so on...
    string prizeName1 = "A pair of Apple Airbuds";
    string prizeName2 = "A 5 pack of tickets to the Opera";
    string prizeName3 = "An all-expense paid cruise to Alaska";
    string prizeName4 = "One week at a 5-star resort in Bali";

    // DECLARE prizeValue1 and so on...
    double prizeValue1 = 99.99;
    double prizeValue2 = 150.00;
    double prizeValue3 = 999.00;
    double prizeValue4 = 5000.00;

    // DECLARE userChoice, userPrizeName, userPrizeValueGuess
    int userChoice;
    bool userChoiceValid = false;
    string userPrizeName;
    double userPrizeValue;
    // Guess must be a valid dollar value, xx.xx format.
    double userPrizeValueGuess;
    // The margin that applies to the chosen prize (0.12, 0.10, 0.05, or 0 for exact)
    double guessMargin;
    bool userWins = false;

    // DECLARE margin for error based on prize value
    double smallPrizeMargin = 0.12;
    double mediumPrizeMargin = 0.10;
    double largePrizeMargin = 0.05;
    // The lowest and highest guesses that still win, calculated once the prize is known
    double smallestWin;
    double largestWin;


    // DISPLAY "~*~~ Welcome to The Price Is Close-Enough! ~~~"
    cout << endl;
    cout << "~*~*~ Welcome to The Price Is Close-Enough! ~*~*~" << endl;
    cout << endl<< "Here are this week's fabulous prizes!" << endl;

    // DISPLAY "1. " + prize1Name
    cout << "1. " << prizeName1 << endl;
    cout << "2. " << prizeName2 << endl;
    cout << "3. " << prizeName3 << endl;
    cout << "4. " << prizeName4 << endl;

    // LOOP until userChoice is valid
    while (!userChoiceValid) {
    // PROMPT "Please enter the number for the prize you wish to guess the price of: "
    cout << "Please enter the number for the prize you wish to guess the price of: ";
    
    // READ userChoice, map it to a selected prize name and value
    cin >> userChoice;
    // cin.fail() is true if the user typed something that isn't a whole number (like a letter).
    // Without clearing the error and discarding the bad text, the loop would repeat forever.
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Try again." << endl;
    } else if (userChoice == 1) {
        userPrizeName = prizeName1;
        userPrizeValue = prizeValue1;
        userChoiceValid = true;
    }else if (userChoice == 2){
        userPrizeName = prizeName2;
        userPrizeValue = prizeValue2;
        userChoiceValid = true;
    }else if (userChoice == 3){
        userPrizeName = prizeName3;
        userPrizeValue = prizeValue3;
        userChoiceValid = true;
    }else if (userChoice == 4){
        userPrizeName = prizeName4;
        userPrizeValue = prizeValue4;
        userChoiceValid = true;
    }else{
        cout << "Invalid choice. Try again." << endl;
    }}
    
    // PROMPT "What is your price guess for " + selectedPrizeName + "? $"
    cout << "What is your price guess for " << userPrizeName << " in dollars and cents? $ ";

    // READ userGuess
    cin >> userPrizeValueGuess;
    /* Only allow valid guesses: a number, not negative, and whole cents.
    The while loop repeats while ANY of these says the guess is bad:
    1. cin.fail() is true when the read failed (letters typed into a double variable).
        It is checked first so a failed read is rejected before the value is examined.
    2. userPrizeValueGuess < 0 rejects negative amounts.
    3. !wholeCents(guess) fires when the guess has a fraction of a cent. */
    while (cin.fail() || userPrizeValueGuess < 0 || !wholeCents(userPrizeValueGuess)) {
        
        // cin.clear() resets the error flag; cin refuses all input until this is done.
        cin.clear();
        
        // cin.ignore() throws away the leftover bad text up to the Enter key ('\n'),
        // numeric_limits<streamsize>::max() means "as many characters as there are".
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "Invalid guess. Enter a non-negative amount in dollars and cents (12.34 for 12 dollars and 34 cents): ";
        // Read again; the while condition then re-checks the new value.
        cin >> userPrizeValueGuess;
    }

    // Prize value determines the margin bracket; only the margin changes per bracket
    if(userPrizeValue <= 100){
        guessMargin = smallPrizeMargin;
    } else if(userPrizeValue <= 500){
        guessMargin = mediumPrizeMargin;
    } else if(userPrizeValue <= 1000){
        guessMargin = largePrizeMargin;
    } else {
        guessMargin = 0; // jackpot prizes must be exact
    }

    // Guess range: prize value minus/plus (prize value * margin).
    // With a margin of 0 both ends equal the prize value, so only an exact guess wins.
    smallestWin = userPrizeValue - (userPrizeValue * guessMargin);
    largestWin = userPrizeValue + (userPrizeValue * guessMargin);

    // The user wins if the guess falls between smallestWin and largestWin (inclusive)
    if (userPrizeValueGuess >= smallestWin && userPrizeValueGuess <= largestWin) {
        userWins = true;
    }
    // by this point userWins will be true if the user's guess was within the allowed margin, otherwise false
    //then we display the result to the user based on whether they won or not
    if(userWins){
        cout << "Congratulations! Your guess was Close Enough!" << endl;
        cout << "Enjoy your " << userPrizeName << ", actual retail price: " << userPrizeValue << "!" << endl;
        cout << "This is Bob Banker signing off, and remember: you can be a winner too, if the price is...Close Enough!" << endl;
    } else {
        cout << "Sorry, your guess was Not Close Enough. The actual retail price of the " << userPrizeName 
        << " is $" << userPrizeValue << "." << endl << endl;
        cout << "But don't worry, you won't be leaving empty-handed!"  << endl;
        cout << "All guests on the Price is Close Enough show receive a consolation prize: a lifetime supply of Turtle Wax brand car polish!" << endl;
        cout << "Turtle Wax: it doesn't matter how slow your car is, you'll get there shiny!" << endl;
    }
    //end game logic

    return 0;
}

/* ==================== TEST DATA ====================
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

/* ==================== REFLECTION(3-5 sentences) ====================
1. Where did I start?
I started by declaring the variables to store prize names and prices, and the user inputs.  Then started designing the logic for comparing the user's guess with the actual prize values.

2. What issues did I run into?
The program broke if the user enters an invalid guess, such as letters, negative numbers, or fractions of a cent.

3. How did I solve them?
I wrote a reusable helper function to check for the fractions of a cent in the user's guess. I also added input validation to handle letters, negative numbers, and other invalid guesses gracefully.

4. What did I learn that was new?
The math libraries needed for the helper function were new, as well as the cin.fail() method for input validation.

5. Anything else relevant?
Even this simple program has a lot of test cases. Anytime you're taking user input, you have to anticipate invalid entries and handle them properly.  Human logic is easy, the computer has to be told what a nonsensical answer looks like.
*/
