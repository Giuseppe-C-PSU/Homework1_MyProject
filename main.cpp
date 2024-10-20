
//
// Created by Achyutan Srinivasan on 10/20/24.

// HW1.cpp
#include "Q2.h"
#include <iostream>

#include "Plane.h"
#include <string>



int main() {
    // Initialize the flight distances
    FlightDistances();

// Display supported city codes
    std::cout << "Supported City Codes are SCE, PHL, ORD, and EWR." << std::endl;

    // Define the Departure and Arrival
    std::string From;
    std::string To;

    // Get user input for Departure and Arrival
    std::cout << "Enter the departure city code: ";
    std::cin >> From;
    std::cout << "Enter the arrival city code: ";
    std::cin >> To;

    // Access the flight distance between the cities
    int distance = getFlightDistance(From, To);
    if (distance != 'Not Found') { // as long as a route exists
        std::cout << "Distance between " << From << " and " << To << " is " << distance << " miles." << std::endl;
    } else {
        std::cout << "Route not found." << std::endl;
    }



// parts 3-5
    std::string from, to;



    // Create a Plane object with inputs

    Plane plane(from, to);
    //Set the velocity
    plane.setVel(500); // Velo

    //Simulate plane's operation
    double dt = 10; // Time step
    for (int i = 0; i < 1500; ++i) {
        plane.operate(dt);
        std::cout << "Position: " << plane.getPos() << ", At SCE: " << plane.isatSCE() << std::endl;

    }


    return 0;
}











