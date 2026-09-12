// Name: Travis "Mac" McCoy
// Date: September 2026
// Program Name: To Infinity and Beyond!
// Program Description: Calculates Buzz Lightyear's rate of travel and the fuel used for 4 rocket trips, using only variables

// 1. Store the units for distance, time, and fuel.
// 2. Store the rocket's fuel burn rate.
// 3. Store Trip 1's starting planet, destination planet, distance, travel time, and fuel used.
// 4. Calculate the travel rate by dividing Trip 1's distance by its travel time.
// 5. Store the light-year conversion value for use with Trip 4.
// 6. Store Trip 2's starting planet, destination planet, and distance.
// 7. Calculate Trip 2's time by dividing its distance by the travel rate.
// 8. Calculate Trip 2's fuel use by multiplying its time by the fuel burn rate.
// 9. Store Trip 3's starting planet, destination planet, and distance.
// 10. Calculate Trip 3's time and fuel use using the same formulas as Trip 2.
// 11. Store Trip 4's starting planet, destination planet, and distance in light-years.
// 12. Convert Trip 4's distance to miles.
// 13. Calculate Trip 4's time and fuel use using the travel rate and fuel burn rate.
// 14. Format all numeric output to two decimal places.
// 15. Display the travel rate and each trip's planets, travel time, and fuel use.

// Reflection:
// I solved this problem by storing the provided trip information in variables first.
// I calculated the travel rate from Trip 1 and reused that result to calculate the times for the other trips.
// I then multiplied each calculated time by the fuel burn rate to find the fuel used.
// Using descriptive variables and setting the output precision made the calculations easier to follow and the results easier to read.

#include <iomanip> // "in-out manipulation" library
#include <iostream>
#include <string>

using namespace std;

int main() {
     // Store the units used in the program's output.
    string distanceUnit = " miles";
    string timeUnit = " minutes";
    string fuelUnit = " gallons";

     // Store the rocket's fuel burn rate.
    const double fuelBurnRate = 12.75;

     // Store the known values for the first trip.
    string originPlanet1 = "Aldor";
    string destination1 = "Earth";
    double trip1Distance = 77891;
    double trip1Time = 2.3;
    double trip1Fuel = 29.33;

     // Calculate the constant travel rate from the first trip.
    const double galacticSpeedLimit = trip1Distance / trip1Time;
    const double lightYearConversion = 5.878625e12;

     // Store Trip 2 and calculate its time and fuel use.
    string originPlanet2 = "Mandalore";
    string destination2 = "Riza";
    double trip2Distance = 24812;
    double trip2Time = trip2Distance / galacticSpeedLimit;
    double trip2Fuel = trip2Time * fuelBurnRate;

     // Store Trip 3 and calculate its time and fuel use.
    string originPlanet3 = "Earth";
    string destination3 = "Kronos";
    double trip3Distance = 163628;
    double trip3Time = trip3Distance / galacticSpeedLimit;
    double trip3Fuel = trip3Time * fuelBurnRate;

     // Store Trip 4 and calculate its time and fuel use.
    string originPlanet4 = "Vulcan";
    string destination4 = "Ferenginar";
    double trip4Distance = 60 * lightYearConversion;
    double trip4Time = trip4Distance / galacticSpeedLimit;
    double trip4Fuel = trip4Time * fuelBurnRate;

     // Format each numeric result to two decimal places.
    cout << fixed << setprecision(2);

     // Display the travel rate and the details for each trip.
    cout << "Travel Rate is " << galacticSpeedLimit << distanceUnit
         << " per minute." << endl << endl;

    cout << "Trip 1: " << originPlanet1 << " to " << destination1 << endl;
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
