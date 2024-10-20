//
// Created by Achyutan Srinivasan on 10/20/24.

// HW1.cpp
#include "Q2.h"
#include <iostream>

int main() {
    // Initialize the flight distances
    FlightDistances();

    // Define the Departure and Arrival
    std::string From = "SCE";
    std::string To = "ORD";

    // Access the flight distance between the cities
    int distance = getFlightDistance(From, To);
    if (distance != 'Not Found') { // as long as a route exists
        std::cout << "Distance between " << From << " and " << To << " is " << distance << " miles." << std::endl;
    } else {
        std::cout << "Route not found." << std::endl;
    }

    return 0;
}