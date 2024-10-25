
#include "Q2.h"
#include <iostream>

std::map<std::pair<std::string, std::string>, int> flightDistances;
// Store Flight Distances
void FlightDistances() {
    flightDistances[{"SCE", "PHL"}] = 160;
    flightDistances[{"SCE", "ORD"}] = 640;
    flightDistances[{"SCE", "EWR"}] = 220;
}

int getFlightDistance(const std::string& To, const std::string& From) {
    std::pair<std::string, std::string> route = {To, From};
    std::pair<std::string, std::string> reverseRoute = {From, To};

    if (flightDistances.find(route) != flightDistances.end()) {
        return flightDistances[route];
    } else if (flightDistances.find(reverseRoute) != flightDistances.end()) {
        return flightDistances[reverseRoute];
    } else {
        return -1; // Indicates that the route was not found
    }
}
