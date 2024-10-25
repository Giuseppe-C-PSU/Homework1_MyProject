#ifndef Q7_H
#define Q7_H

#include <iostream>
#include <string>
#include "Plane.h"

class Pilot {
private:
    std::string name;

public:
    Plane* myPlane;

    // Constructor
    Pilot(const std::string& pilotname);

    // Destructor
    ~Pilot();

    std::string getName() const;
    void printControlInfo() const;
};

void switchPilots(Pilot*& currentPilot, Pilot*& nextPilot);

#endif // Q7_H
