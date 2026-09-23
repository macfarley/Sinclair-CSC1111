// Name: Mac McCoy
// Date: 2026-09-23
// Program Name: Making Decisions Exercise
// Program Description: This program sells movie tickets after checking age and parental permission.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string movie1Name = "Aladdin";
    string movie1Rating = "G";
    string movie2Name = "Inception";
    string movie2Rating = "PG-13";
    string movie3Name = "Alien";
    string movie3Rating = "R";
    string failMessage = "You are not old enough to watch this movie.  Please come back when you're older, or with your Mommy or Daddy.";

    string passMessage = "You are allowed to watch this movie. Enjoy!";

    int movieChoice = 0;
    string movieChoiceTitle;
    string movieChoiceRating;
    int viewerAge;
    char parentPresent = 'N';

    cout << "Welcome to the cinema!" << endl;
    cout << "Now playing:" << endl;
    cout << "1. " << movie1Name << " (" << movie1Rating << ")" << endl;
    cout << "2. " << movie2Name << " (" << movie2Rating << ")" << endl;
    cout << "3. " << movie3Name << " (" << movie3Rating << ")" << endl;

    while (movieChoice < 1 || movieChoice > 3) {
        cout << "Please enter the number 1-3 of the movie you wish to see: ";
        cin >> movieChoice;

        if (movieChoice < 1 || movieChoice > 3) {
            cout << "Invalid choice. Please choose a movie number from 1 to 3." << endl;
        }
    }

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
    cout << "This movie has a rating of " << movieChoiceRating << "." << endl;
    cout << "Please enter your age: ";
    cin >> viewerAge;

    if ((movieChoiceRating == "PG-13" && viewerAge < 13) ||
        (movieChoiceRating == "R" && viewerAge < 17)) {
        cout << "Are you accompanied by a parent or guardian? (Y/N): ";
        cin >> parentPresent;
    }

    cout << "You selected " << movieChoiceTitle << " which has a rating of " << movieChoiceRating << "." << endl;
    cout << "You are " << viewerAge << " years old and "
         << (parentPresent == 'Y' || parentPresent == 'y'
                 ? "accompanied by a parent."
                 : "not accompanied by a parent.")
         << endl;

    if (movieChoiceRating == "G") {
        cout << "This movie is suitable for all ages. Enjoy!" << endl;
    } else if (movieChoiceRating == "PG-13") {
        if (viewerAge >= 13 || parentPresent == 'Y' || parentPresent == 'y') {
            cout << passMessage << endl;
        } else {
            cout << failMessage << endl;
        }
    } else if (movieChoiceRating == "R") {
        if (viewerAge >= 17 || parentPresent == 'Y' || parentPresent == 'y') {
            cout << passMessage << endl;
        } else {
            cout << failMessage << endl;
        }
    }

    /* Test data:
       Test | Movie     | Rating | Age | Parent present? | Expected result
       1    | Aladdin   | G      | 5   | N                | Pass
       2    | Inception | PG-13  | 12  | N                | Fail
       3    | Inception | PG-13  | 12  | Y                | Pass
       4    | Inception | PG-13  | 13  | N                | Pass
       5    | Alien     | R      | 16  | N                | Fail
       6    | Alien     | R      | 16  | Y                | Pass
       7    | Alien     | R      | 17  | N                | Pass
    */

    return 0;
}
