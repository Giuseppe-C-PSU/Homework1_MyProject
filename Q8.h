#ifndef Q8_H
#define Q8_H

#include <iostream>
#include <string>
#include <memory>
#include "Plane.h"

class ModernPilot {
private:
    std::string name;

public:
    std::unique_ptr<Plane> myPlane;

    // Constructor
    ModernPilot(const std::string& pilotname);

    // Destructor
    ~ModernPilot();

    std::string getName() const;
    void printControlInfo() const;
};

void switchModernPilots(std::unique_ptr<ModernPilot>& currentPilot, std::unique_ptr<ModernPilot>& nextPilot);

#endif // Q8_H