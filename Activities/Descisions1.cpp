// Name: Mac McCoy
// Date: 2026-09-23
// Program Name: Making Decisions Exercise
// Program Description: This program sells movie tickets after checking age and parental permission.

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Store each movie name and rating in its own variable.
    // The assignment asks for variables instead of arrays or other collections.
    string movie1Name = "Aladdin";
    string movie1Rating = "G";
    
    string movie2Name = "Inception";
    string movie2Rating = "PG-13";
    
    string movie3Name = "Alien";
    string movie3Rating = "R";

    // Plan the user-input variables before writing the decision logic.
    // Choose data types that match the information the user will enter.
    int movieChoice = 0;
    string movieChoiceTitle;
    string movieChoiceRating;
    int viewerAge;
    char parentPresent = 'N';

    // Display a numbered menu using the movie-name and movie-rating variables.
    // Include clear instructions so the user knows which number to enter.
    cout << "Welcome to the cinema!" << endl;
    cout << "Now Playing the following movies:" << endl;
    cout << "Cinema 1: " << movie1Name << " (" << movie1Rating << ")" << endl;
    cout << "Cinema 2: " << movie2Name << " (" << movie2Rating << ")" << endl;
    cout << "Cinema 3: " << movie3Name << " (" << movie3Rating << ")" << endl;
   
    // Ask which movie the user wants to see until a listed option is entered.
    while (movieChoice < 1 || movieChoice > 3) {
        cout << "Please enter the number 1-3 of the movie you wish to see: ";
        cin >> movieChoice;

        if (movieChoice < 1 || movieChoice > 3) {
            cout << "Invalid choice. Please choose a movie number from 1 to 3." << endl;
        }
    }

    // Set the movieChoiceTitle and movieChoiceRating based on the user's selection.
    if (movieChoice == 1) {
        movieChoiceTitle = movie1Name;
        movieChoiceRating = movie1Rating;
    } else if (movieChoice == 2) {
        movieChoiceTitle = movie2Name;
        movieChoiceRating = movie2Rating;
    } else {
        movieChoiceTitle = movie3Name;
        movieChoiceRating = movie3Rating;
    }

    cout << "You selected movie number " << movieChoice << ", " << movieChoiceTitle << "." << endl;

    // Ask for the viewer's age and store it.
    cout << "This movie has a rating of " << movieChoiceRating << "." << endl;
    
    cout << "Please enter your age: ";
    cin >> viewerAge;

    
    // Use the selected movie's rating to decide whether the viewer may enter.
    // Required rating rules:
    // - G: viewers of all ages pass.
    // - PG-13: the viewer must be 13 or older, OR have a parent present.
    // - R: the viewer must be 17 or older, OR have a parent present.

    // Ask about a parent only when the selected rating requires permission.
    // Viewers old enough for PG-13 or R do not need to answer this question.
    if ((movieChoiceRating == "PG-13" && viewerAge < 13) ||
        (movieChoiceRating == "R" && viewerAge < 17)) {
        cout << "Are you accompanied by a parent or guardian? (Y/N): ";
        cin >> parentPresent;
    }

    // First determine which movie was selected. Then apply that movie's rule.
    // Make sure every pass/fail path produces an understandable message.
    cout << "You selected " << movieChoiceTitle << " which has a rating of " << movieChoiceRating << "." << endl;
    cout << "You are " << viewerAge << " years old and " << (parentPresent == 'Y' || parentPresent == 'y' ? "accompanied by a parent." : "not accompanied by a parent.") << endl;

    if (movieChoiceRating == "G") {
        cout << "This movie is suitable for all ages, enjoy." << endl;
    } else if (movieChoiceRating == "PG-13") {
        if (viewerAge >= 13 || parentPresent == 'Y' || parentPresent == 'y') {
            cout << "You are allowed to watch this movie." << endl;
        } else {
            cout << "You are not allowed to watch this movie." << endl;
        }
    } else if (movieChoiceRating == "R") {
        if (viewerAge >= 17 || parentPresent == 'Y' || parentPresent == 'y') {
            cout << "You are allowed to watch this movie." << endl;
        } else {
            cout << "You are not allowed to watch this movie." << endl;
        }
    } else {
        cout << "Invalid movie rating." << endl;
    }
    // Additional requirements before submitting:
    // - Use the variables above in the menu instead of repeating movie text.
    // - Check that the selected choice is one of the movies in the menu.
    // - Use good grammar and spelling in every prompt and result.
    // - Decide how your program responds to an invalid movie choice.
    // - Decide whether Y/y and N/n should both be accepted for parentPresent.
    // - Do not forget to test both outcomes of every condition.
    //
    // Test-data table to create separately for submission:
    // Rating | User age | Parent present? | Expected result
    // G      | 5        | N                | Pass
    // PG-13  | 12       | N                | Fail
    // PG-13  | 10       | Y                | Pass
    // PG-13  | 13+      | N                | Pass
    // R      | 16       | N                | Fail
    // R      | 16       | Y                | Pass
    // R      | 17+      | N                | Pass

    return 0;
}


/* Easy-run instructions, enter exactly
 g++ -std=c++17 Activities/Descisions1.cpp -o Activities/Descisions1 && ./Activities/Descisions1
*/