//
// Created by Achyutan Srinivasan on 10/20/24.
//

#ifndef HOMEWORK1_Q2_H
#define HOMEWORK1_Q2_H

#include <map>
#include <string>
#include <iostream>

extern std::map<std::pair<std::string, std::string>, int> flightDistances;

void FlightDistances();
int getFlightDistance(const std::string& To, const std::string& From);


#endif //HOMEWORK1_Q2_H
