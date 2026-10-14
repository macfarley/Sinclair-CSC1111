// Name: Mac McCoy
// Date: October 13, 2026
// Program Name: Currency Exchange Kiosk
// Program Description: A multilingual kiosk UI that guides a user through exchanging an amount from one currency to another.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {
    
    // translate them to zero-based array indexes before using prompt arrays.
    const int languageCount = 4;
    const int currencyCount = 5;

    // ------------------------------------------------------------------
    // The language-selection menu is the only prompt shown in all languages.
    string welcomePrompt[languageCount] = {
        "1. English — Welcome to the Exchange Kiosk.",
        "2. Deutsch — Willkommen am Wechselautomaten.",
        "3. Arabiya (Romanized) — Marhaban! Ahlan wa sahlan.",
        "4. Nihongo (Romaji) — Konnichiwa! Yōkoso."
    };

    // Localized prompts. Index 0 is English, 1 German, 2 romanized Arabic, and 3 romaji Japanese.
    string currencyPrompt[languageCount] = {
        "Please choose your desired currency:",
        "Bitte wählen Sie die gewünschte Währung:",
        "Min fadlak, ikhtar al-'umla al-marghouba:",
        "Kibō suru tsūka o erande kudasai:"
    };
    string inputCurrencyPrompt[languageCount] = {
        "Choose an input currency:",
        "Wählen Sie eine Eingabewährung:",
        "Ikhtar al-'umla al-dakhiliyya:",
        "Nyūryoku tsūka o erande kudasai:"
    };
    string outputCurrencyPrompt[languageCount] = {
        "Choose the currency you want to convert to:",
        "Wählen Sie die Zielwährung:",
        "Ikhtar al-'umla allati turid al-tabdil ilayha:",
        "Kōkan saki no tsūka o erande kudasai:"
    };
    string exchangeIntro[languageCount] = {
        "You would like to exchange ",
        "Sie möchten wechseln ",
        "Turid an tukawwin ",
        "Anata wa kōkan shitai desu "
    };
    string receiveIntro[languageCount] = {
        "You would like to receive ",
        "Sie möchten erhalten ",
        "Wa turid an tataqabbal ",
        "Uketori tai tsūka wa "
    };
    string confirmCurrencyChoices[languageCount] = {
        "Are you sure about your currency choices? (Y to confirm, anything else to restart): ",
        "Sind Sie sicher über Ihre Währungswahl? (Y zum Bestätigen, alles andere startet neu): ",
        "Hal anta muta'akkid min ikhtiyarat al-'umla? (Y lil-tawthiq, ay shay akhar sayubda' min jadid): ",
        "Tsūka no sentaku ni kakunin shimasu ka? (Kakunin suru ni wa Y, soretomo saisho kara yarinaoshimasu): "
    };
    string sameCurrencyError[languageCount] = {
        "Input and output currency must be different. Please choose again.",
        "Eingabe- und Zielwährung müssen verschieden sein. Bitte erneut wählen.",
        "Yajib an takun al-'umla al-dakhiliyya wa al-kharijiyya mukhtalifatayn. Ikhtar min jadid.",
        "Nyūryoku tsūka to kōkan saki no tsūka wa chigau mono ni shite kudasai. Mō ichido erande kudasai."
    };
    string invalidCurrencyError[languageCount] = {
        "Please enter a number from 1 to 5.",
        "Bitte geben Sie eine Zahl von 1 bis 5 ein.",
        "Min fadlak, adkhil raqman min 1 ila 5.",
        "1 kara 5 made no bangō o nyūryoku shite kudasai."
    };
    string enterAmountPrompt[languageCount] = {
        "Enter the amount you wish to exchange (minimum value equivalent to €50): ",
        "Geben Sie den Betrag ein, den Sie wechseln möchten (Mindestwert entspricht 50 €): ",
        "Adkhil al-mablagh alladhi turid tabdilahu (al-hadd al-adna ma yu'adil 50 €): ",
        "Kōkan shitai kingaku o nyūryoku shite kudasai (saitei 50 € sōtō): "
    };
    string amountTooLow[languageCount] = {
        "We require a minimum amount of ",
        "Wir verlangen einen Mindestbetrag von ",
        "Natlub mablagh adna qadruhu ",
        "Saitei kingaku wa "
    };
    string youEntered[languageCount] = {
        "You have entered ",
        "Sie haben eingegeben ",
        "Qad adkhalta ",
        "Anata ga nyūryoku shita no wa "
    };
    string feeForAmount[languageCount] = {
        "The fee for this amount is ",
        "Die Gebühr für diesen Betrag beträgt ",
        "Al-rasm lihatha al-mablagh huwa ",
        "Kono kingaku no tesūryō wa "
    };
    string totalOutput[languageCount] = {
        "The total in your chosen currency is ",
        "Ihr Gesamtauszahlungsbetrag ist ",
        "Majmou' al-mablagh al-nahai huwa ",
        "Saishū shutsuryoku wa "
    };
    string confirmPrompt[languageCount] = {
        "Press Enter or Y to confirm, anything else will start over: ",
        "Drücken Sie Enter oder Y zum Bestätigen, alles andere startet neu: ",
        "Idghat Enter aw Y lil-tawthiq, wa ay shay akhar sayubda' min jadid: ",
        "Enter matawa Y de kakunin, hoka wa saisho kara yarinaoshimasu: "
    };
    string transactionCancelled[languageCount] = {
        "Transaction cancelled.",
        "Transaktion abgebrochen.",
        "Al-'amaliyya l-mulgha.",
        "Torihiki wa chūshi saremashita."
    };
    string successPrompt[languageCount] = {
        "Exchange completed successfully. Your currency is dispensed below.",
        "Der Umtausch war erfolgreich. Ihre Währung wird unten ausgegeben.",
        "Tam al-tabdil binajah. Sayutrak al-'umla tahta al-masraf.",
        "Kōkan ga seikō shimashita. Tsūka wa shita kara dispensed saremasu."
    };
    string thankYouPrompt[languageCount] = {
        "Thank you for using the Currency Converter Kiosk.",
        "Danke, dass Sie den Wechselautomaten benutzt haben.",
        "Shukran li-istikhdamika Currency Converter Kiosk.",
        "Currency Converter Kiosk o riyō shite itadaki arigatō gozaimasu."
    };
    string startOverPrompt[languageCount] = {
        "Do you want to start another exchange? (Y/N): ",
        "Möchten Sie einen weiteren Umtausch starten? (Y/N): ",
        "Hal tatawish bidaya tabdil akhar? (Y/N): ",
        "Mō hitotsu kōkan o hajimeru ka? (Y/N): "
    };
    string goodByePrompt[languageCount] = {
        "Goodbye!",
        "Auf Wiedersehen!",
        "Ma'a as-salama!",
        "Sayonara!"
    };

    // Currency symbols match the planned currency order: USD, GBP, EUR, JPY, and AED.
    string currencySymbol[currencyCount] = {
        "$", "£", "€", "¥", "AED"
    };
    string currencyName[currencyCount] = {
        "1. US Dollar", "2. British Pound", "3. Euro", "4. Japanese Yen", "5. United Arab Emirates Dirham"
    };

    // Reference tables. Index order matches the currency menu: USD, GBP, EUR, JPY, AED.
    // Smallest amount worth exchanging, checked against the amount converted to EUR.
    const double minAmountEUR = 50.0;

    // Sample exchange rates, all routed through EUR. Replace with current rates before use.
    double rateInputToEUR[currencyCount] = {
        0.92,     // 1 USD in EUR
        1.17,     // 1 GBP in EUR
        1.0,      // 1 EUR in EUR
        0.0061,   // 1 JPY in EUR
        0.25      // 1 AED in EUR
    };
    double rateEURToOutput[currencyCount] = {
        1.09,     // 1 EUR in USD
        0.855,    // 1 EUR in GBP
        1.0,      // 1 EUR in EUR
        164.0,    // 1 EUR in JPY
        3.97      // 1 EUR in AED
    };

    // Fee tiers use the amount in EUR. A tier applies when the amount is at or above its threshold.
    const int feeTierCount = 6;
    double feeTierThreshold[feeTierCount] = {
        0.0, 100.0, 200.0, 500.0, 1000.0, 2000.0
    };
    double feeTierPercent[feeTierCount] = {
        6.0, 5.0, 4.0, 3.0, 2.0, 1.5
    };


    // User input and selection variables.
    int languageChoice = 0;
    int inputCurrencyChoice = 0;
    int outputCurrencyChoice = 0;
    // Y/N answers are single characters, read as the first character of the line.
    char confirmCurrency = 'N';
    char exchangeConfirmation = 'N';
    char restartChoice = 'N';
    string answerLine;
    bool kioskRunning = true;
    bool currencyChoicesValid = true;

    // Values to calculate after the required inputs are available.
    double amountEntry = 0.0;
    double amountInEUR = 0.0;
    double exchangeFeePercent = 0.0;
    double exchangeFeeAmount = 0.0;
    double outputAmount = 0.0;

    // Step A: Repeat the kiosk transaction until the user chooses to exit.
    while (kioskRunning) {
    // Step B: Display the multilingual welcome menu and get the language choice.
    cout << "Welcome to the Currency Converter Kiosk! English is the default, please select your preferred language." << endl;
    //this should show all options
    for (int i = 0; i < languageCount; i++) {
        cout << welcomePrompt[i] << endl;
    }
    cin >> languageChoice;
    if (cin.fail()) {
        if (cin.eof()) return 0;
        cin.clear(); // Non-numeric entry defaults to English below.
        languageChoice = 0;
    }
    cin.ignore(10000, '\n'); // Clear the rest of the line.
    //map the choice to a valid index
    if(languageChoice < 1 || languageChoice > languageCount) {
        languageChoice = 0; // Default to English if the choice is invalid.
    }else{
        languageChoice = languageChoice - 1; 
        //adjust to proper index
    }
    //from this point on all prompts will appear in the chosen language
    // Step C: Display the currency menu and get the input and output currencies.
    // Step D: Repeat only this step until both choices are 1-5 and the two currencies differ.
    do {
        currencyChoicesValid = true;
        for (int i = 0; i < currencyCount; i++) {
            cout << currencyName[i] << endl;
        }
        cout << inputCurrencyPrompt[languageChoice] << endl;
        cin >> inputCurrencyChoice;
        if (cin.fail()) {
            if (cin.eof()) return 0;
            cin.clear(); // Non-numeric entry becomes an invalid choice.
            inputCurrencyChoice = 0;
        }
        cin.ignore(10000, '\n'); // Clear the rest of the line.
        inputCurrencyChoice = inputCurrencyChoice - 1; //adjust to proper index

        // what they have
        cout << outputCurrencyPrompt[languageChoice] << endl;
        cin >> outputCurrencyChoice;
        if (cin.fail()) {
            if (cin.eof()) return 0;
            cin.clear();
            outputCurrencyChoice = 0;
        }
        cin.ignore(10000, '\n');
        outputCurrencyChoice = outputCurrencyChoice - 1; //adjust to proper index

        if (inputCurrencyChoice < 0 || inputCurrencyChoice >= currencyCount ||
            outputCurrencyChoice < 0 || outputCurrencyChoice >= currencyCount) {
            cout << invalidCurrencyError[languageChoice] << endl;
            currencyChoicesValid = false;
        } else if (inputCurrencyChoice == outputCurrencyChoice) {
            cout << sameCurrencyError[languageChoice] << endl;
            currencyChoicesValid = false;
        }
    } while (!currencyChoicesValid);

    // Step E: Display both selected currencies back to the user.
    cout << exchangeIntro[languageChoice] << currencySymbol[inputCurrencyChoice] << endl;
    cout << receiveIntro[languageChoice] << currencySymbol[outputCurrencyChoice] << endl;
    
    // Step F: Confirm the currency choices. Anything but Y/y restarts at the language menu (Step B).
    cout << confirmCurrencyChoices[languageChoice] << endl;
    getline(cin, answerLine);
    if (cin.eof() && answerLine == "") return 0;
    confirmCurrency = answerLine.empty() ? 'N' : answerLine[0];
    switch (confirmCurrency) {
        case 'Y':
        case 'y':
            break; // Continue to the amount.
        default:
            continue; // Return to the language menu.
    }
    
    // Step G: Get the amount, convert it to EUR, and repeat only this prompt until it is worth at least minAmountEUR.
    do {
        cout << currencySymbol[inputCurrencyChoice] << " -> " << currencySymbol[outputCurrencyChoice] << endl;
        cout << enterAmountPrompt[languageChoice] << endl;
        cin >> amountEntry;
        if (cin.fail()) {
            if (cin.eof()) return 0;
            cin.clear(); // Non-numeric entry counts as zero, which fails the minimum check.
            amountEntry = 0.0;
        }
        cin.ignore(10000, '\n'); // Clear the rest of the line.

        // Convert the input amount to EUR (unless the input currency is EUR).
        if (inputCurrencyChoice == 2) {
            amountInEUR = amountEntry;
        } else {
            amountInEUR = amountEntry * rateInputToEUR[inputCurrencyChoice];
        }

        // The single minimum check uses the EUR equivalent.
        if (amountInEUR < minAmountEUR) {
            cout << amountTooLow[languageChoice] << currencySymbol[2] << minAmountEUR << endl;
        }
    } while (amountInEUR < minAmountEUR);
    // Step H: Select a fee tier using the EUR amount and the feeTierThreshold + feeTierPercent tables.
    // Thresholds ascend, so every tier the amount reaches overwrites the last; the highest one reached wins.
    for (int i = 0; i < feeTierCount; i++) {
        if (amountInEUR >= feeTierThreshold[i]) {
            exchangeFeePercent = feeTierPercent[i];
        }
    }
    // Step I: Calculate the fee in EUR, subtract it, then convert to the output currency (unless it is EUR).
    exchangeFeeAmount = amountInEUR * (exchangeFeePercent / 100);
    if (outputCurrencyChoice == 2) {
        outputAmount = amountInEUR - exchangeFeeAmount;
    } else {
        outputAmount = (amountInEUR - exchangeFeeAmount) * rateEURToOutput[outputCurrencyChoice];
    }
    // The kiosk cannot dispense sub-denomination currency: round to the nearest 5 yen or 0.05 of any other currency.
    switch (outputCurrencyChoice) {
        case 3: // JPY
            outputAmount = round(outputAmount / 5.0) * 5.0;
            break;
        default:
            outputAmount = round(outputAmount / 0.05) * 0.05;
    }

    // Step J: Display the localized amount and exchange summary.
    // Money shows two decimals, except yen which has no fractional unit.
    cout << fixed;
    //starting amount
    cout << youEntered[languageChoice] << currencySymbol[inputCurrencyChoice]
         << setprecision(inputCurrencyChoice == 3 ? 0 : 2) << amountEntry << endl;
    //fee for amount
    cout << feeForAmount[languageChoice] << setprecision(1) << exchangeFeePercent << "% ("
         << currencySymbol[2] << setprecision(2) << exchangeFeeAmount << ")" << endl;
    //total output amount
    cout << totalOutput[languageChoice] << currencySymbol[outputCurrencyChoice]
         << setprecision(outputCurrencyChoice == 3 ? 0 : 2) << outputAmount << endl;
    cout << endl; 
    // Step K: Confirm the exchange. Anything but Y/y cancels and restarts at the language menu (Step B).
    // A blank Enter also confirms, as the prompt says.
    cout << confirmPrompt[languageChoice];
    getline(cin, answerLine);
    if (cin.eof() && answerLine == "") return 0;
    exchangeConfirmation = answerLine.empty() ? 'Y' : answerLine[0];
    switch (exchangeConfirmation) {
        case 'Y':
        case 'y':
            break; // Complete the exchange.
        default:
            cout << transactionCancelled[languageChoice] << endl;
            continue; // Return to the language menu.
    }
    
    // Step L: Display the localized success and thank-you messages.
    cout << successPrompt[languageChoice] << endl;
    cout << thankYouPrompt[languageChoice] << endl;
    // Step M: Ask whether to start another exchange; anything but Y/y exits the loop.
    cout << startOverPrompt[languageChoice];
    getline(cin, answerLine);
    restartChoice = answerLine.empty() ? 'N' : answerLine[0];
    switch (restartChoice) {
        case 'Y':
        case 'y':
            break; // Start another exchange.
        default:
            cout << goodByePrompt[languageChoice] << endl;
            kioskRunning = false; // Exit the kiosk loop.
    }
    }

    return 0;
}
