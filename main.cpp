

// HW1.cpp
#include "Q2.h"
#include <iostream>
#include "Plane.h"
#include <string>
#include <set>
#include "q1.h"


int main() {
    {// Question 1
        int allowed = question1();
        if (allowed){
            std::cout << "Plane is safe" << std::endl;
        }else{
            std::cout << "Plane is not safe" << std::endl;
        }

    }

    // Initialize the flight distances
    FlightDistances();

// Display supported city codes
    std::cout << "Supported City Codes are SCE, PHL, ORD, and EWR." << std::endl;

    // Define the Departure and Arrival
    std::string From;
    std::string To;

    // Set of valid city codes
    std::set<std::string> validCodes = {"SCE", "PHL", "ORD", "EWR"};


    // Maximum number of attempts
    const int maxAttempts = 5;
    int j = 0;

    // Get user input for Departure
    do {
        std::cout << "Enter the departure city code: ";
        std::cin >> From;
        if (validCodes.find(From) == validCodes.end()) {
            std::cout << "Invalid city code. Please try again.\nSupported City Codes are SCE, PHL, ORD, and EWR.\n";
            j++;
        }
        if (j >= maxAttempts) {
            std::cout << "Too many invalid attempts. Program will terminate.\n";
            return 1; // Terminate the program
        }
    } while (validCodes.find(From) == validCodes.end());

    j = 0; // Reset attempts for the next input

    // Get user input for Arrival
    do {
        std::cout << "Enter the arrival city code: ";
        std::cin >> To;
        if (validCodes.find(To) == validCodes.end()) {
            std::cout << "Invalid city code. Please try again.\nSupported City Codes are SCE, PHL, ORD, and EWR.\n";
            j++;
        }
        if (j >= maxAttempts) {
            std::cout << "Too many invalid attempts. Program will terminate.\n";
            return 1; // Terminate the program
        }
    } while (validCodes.find(To) == validCodes.end());

    // Access the flight distance between the cities
    int distance = getFlightDistance(To, From);
    if (distance != -1) { // as long as a route exists
        std::cout << "Distance between " << From << " and " << To << " is " << distance << " miles." << std::endl;
    } else {
        std::cout << "Route not found." << std::endl;
    }



// parts 3-5

    // Create a Plane object with inputs

    Plane plane(From, To);
    //Set the velocity
    plane.setVel(500); // Velo

    //Simulate plane's operation
    double dt = 10; // Time step
    for (int i = 0; i < 1500; i++) {
        plane.operate(dt);
        std::cout << "Time: " << i*dt << " Seconds || " << "Position: " << plane.getPos() << " Miles " << std::endl;

    }

    return 0;
}











