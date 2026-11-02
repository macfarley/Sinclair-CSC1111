// Mac McCoy
// Date: 10-26-2026
// Program Name: Files Assignment - Word Search
// Program Description: Reads message.txt, counts how many times two user-entered words appear (case-insensitive), and reports the results to the screen and to results.txt.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Make a word easier to compare by ignoring letter case and punctuation attached to either end of the word.
// Saving this snippet for later use in other programs
string normalizeWord(string text)
{
    // Convert each character to lowercase. Casting to unsigned char first makes the call to tolower safe for every possible char value.
    for (char& character : text)
    {
        character = static_cast<char>(tolower(static_cast<unsigned char>(character)));
    }

    // Remove punctuation from the beginning, such as an opening quotation mark.
    while (!text.empty() && ispunct(static_cast<unsigned char>(text.front())))
    {
        text.erase(0, 1);
    }

    // Remove punctuation from the end, such as a comma or period.
    while (!text.empty() && ispunct(static_cast<unsigned char>(text.back())))
    {
        text.pop_back();
    }

    return text;
}

int main()
{
    // Declare one stream for reading the message and one for writing results.
    ifstream inputFile;
    ofstream outputFile;

    // Keep the two requested search words, the current file token, and a separate occurrence count for each search word.
    string word1, word2;
    string fileWord;

    int count1 = 0;
    int count2 = 0;

    // Ask the user for the two words to find. The >> operator reads each word up to whitespace.
    cout << "Enter the first word: ";
    cin >> word1;

    cout << "Enter the second word: ";
    cin >> word2;

    // Normalize the search words the same way as file words so comparisons are case-insensitive and ignore punctuation at the word boundaries.
    word1 = normalizeWord(word1);
    word2 = normalizeWord(word2);

    // Open the input file from the program's current working directory.
    inputFile.open("message.txt");

    // Stop with status 1 if the input file could not be opened.
    if (!inputFile)
    {
        cout << "Error opening message.txt" << endl;
        return 1;
    }

    // Extract one whitespace-separated word at a time until the file is read.
    while (inputFile >> fileWord)
    {
        // Normalize each token before comparing it with the search words.
        fileWord = normalizeWord(fileWord);

        // Increment the matching word's count. Separate if statements allow both counts to increase if the user enters the same word twice.
        if (fileWord == word1)
        {
            count1++;
        }

        if (fileWord == word2)
        {
            count2++;
        }
    }

    // Close the input file after all of its words have been processed.
    inputFile.close();

    // Display both labeled counts in the console.
    cout << "\nSearch Results\n";
    cout << word1 << ": " << count1 << endl;
    cout << word2 << ": " << count2 << endl;

    // Create or replace results.txt in the current working directory.
    outputFile.open("results.txt");

    // Stop with status 2 if the output file could not be opened.
    if (!outputFile)
    {
        cout << "Error opening results.txt" << endl;
        return 2;
    }

    // Write the same labels and counts that were displayed in the console.
    outputFile << "Search Results" << endl;
    outputFile << word1 << ": " << count1 << endl;
    outputFile << word2 << ": " << count2 << endl;

    // Close the output file to finish writing and release the file resource.
    outputFile.close();

    // Return 0 to indicate that the program completed successfully.
    return 0;
}


/*
Reflection Paragraph

I started by setting up the file stream variables and making sure I could open and access the input file correctly. I used message-test.txt, which contains text from the HMS Pinafore musical, to check the logic of my reading loop and word counts. I tried several different search terms with that test text and with the regular message.txt file to see whether the program found and counted the words as expected. I also needed to add informative error messages and distinct return codes so it would be clearer whether the input file or the results file had failed to open. Through this assignment, I learned how to use ifstream and ofstream, read data from a file using a loop, and perform a case-insensitive word search by converting strings to lowercase before comparing them. Testing with different files and search terms helped me understand how to check the program's logic, while the error handling helped me identify file-opening problems. The assignment helped me better understand file processing and troubleshooting in C++.
*/