//Name: Travis "Mac" McCoy
//Date: September 2026
//Program Name: To Infinity and Beyond!
//Program Description: Calculates Buzz Lightyear's rate of travel and the fuel used for 4 rocket trips, using only variables 


// Needed for cout/cin and std::string
#include <iostream>
// Needed for setprecision() / fixed formatting of doubles
#include <iomanip>
using namespace std;

int main() {
    // ------------------------------------------------------------------
    // Units as variables:
    // This reinforces:
    // - No hard-coded literals in cout
    // - Output formatting is data-driven
    string distanceUnit = " miles";   // appended after distance values
    string timeUnit = " minutes";     // appended after travel time values
    string fuelUnit = " gallons";     // appended after fuel usage values

    // ------------------------------------------------------------------
    // Constant: fuel burn rate given by the assignment (gallons/minute).
    const double fuelBurnRate = 12.75;   // gallons per minute or fuelUnit per timeUnit
    // ------------------------------------------------------------------
    // Trip 1
    //   - starting planet name (Aldor)
    string originPlanet = "Aldor";
    //   - ending planet name (Earth)
    string destination1 = "Earth";
    //   - distance in miles (77,891)
    double trip1Distance = 77891;
    //   - travel time in minutes (2.3)
    double trip1Time = 2.3;
    //   - fuel used in gallons (29.33) 
    double trip1Fuel = 29.33;

    // ------------------------------------------------------------------
    // Rate of travel (miles per minute) — calculated ONCE from Trip 1,
    // then reused for every other trip since it's constant.
    const double travelRate = trip1Distance / trip1Time;
    const double lightYearConversion = 5.878625e12;   // 1 light‑year = 5.878625 trillion miles

    // ------------------------------------------------------------------
    // Trip 2 (Mandalore -> Riza, 24,812 miles). Time and fuel are NOT
    // given — calculate them using the rate and the fuel burn rate.
    //       and variables for the calculated time and fuel
    string originPlanet2 = "Mandalore";
    string destination2 = "Riza";
    double trip2Distance = 24812;
    double trip2Time = trip2Distance / travelRate;
    double trip2Fuel = trip2Time * fuelBurnRate;
    // ------------------------------------------------------------------
    // Trip 3 (Earth -> Kronos, 163,628 miles). Same idea as Trip 2.

    string originPlanet3 = "Earth";
    string destination3 = "Kronos"; //also transliterated as Qo'noS
    
    double trip3Distance = 163628;
    double trip3Time = trip3Distance / travelRate;
    double trip3Fuel = trip3Time * fuelBurnRate;

    // ------------------------------------------------------------------
    // Trip 4 (your own made-up planets and distance). and variables for the calculated time and fuel

    string originPlanet4 = "Vulcan";
    string destination4 = "Ferenginar";
    //canonical distance approximate 60ly
    double trip4Distance = 60 * lightYearConversion;
    double trip4Time = trip4Distance / travelRate;
    double trip4Fuel = trip4Time * fuelBurnRate;
    // ------------------------------------------------------------------
    // Output section.
    // - Use cout << fixed << setprecision(2) to limit numeric output to
    //   two decimal places (set this once before your output statements).
    // - Build every line from variables — no literal numbers or planet
cout << fixed << setprecision(2);

cout << "Travel Rate is " << travelRate << distanceUnit << " per minute." << endl << endl;

cout << "Trip 1: " << originPlanet << " to " << destination1 << endl;
cout << "Travel time = " << trip1Time << timeUnit
     << ", Fuel use = " << trip1Fuel << fuelUnit << "." << endl << endl;

cout << "Trip 2: " << originPlanet2 << " to " << destination2 << endl;
cout << "Travel time = " << trip2Time << timeUnit
     << ", Fuel use = " << trip2Fuel << fuelUnit << "." << endl << endl;

cout << "Trip 3: " << originPlanet3 << " to " << destination3 << endl;
cout << "Travel time = " << trip3Time << timeUnit
     << ", Fuel use = " << trip3Fuel << fuelUnit << "." << endl << endl;

cout << "Trip 4: " << originPlanet4 << " to " << destination4 << endl;
cout << "Travel time = " << trip4Time << timeUnit
     << ", Fuel use = " << trip4Fuel << fuelUnit << "." << endl;


    return 0;
}

