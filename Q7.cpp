#include "Q7.h"

// Constructor
Pilot::Pilot(const std::string& pilotname) : name(pilotname) {
    myPlane = nullptr;
    std::cout << "Ancient Pilot " << name << " is at the gate, ready to board the plane.\n";
}

// Destructor
Pilot::~Pilot() {
    std::cout << "Ancient Pilot " << name << " is out of the plane.\n";
}

std::string Pilot::getName() const {
    return name;
}

void Pilot::printControlInfo() const {
    std::cout << "Ancient Pilot " << name << " is flying the plane " << myPlane << ".\n";
}

void switchPilots(Pilot*& currentPilot, Pilot*& nextPilot) {
    std::cout << "The plane (" << currentPilot->myPlane << ") has arrived at SCE.\n";
    std::cout << "The Ancient Pilot " << currentPilot->getName() << " is taking a break.\n";
    nextPilot->myPlane = currentPilot->myPlane;
    std::cout << "The Ancient Pilot " << nextPilot->getName() << " is flying the plane " << nextPilot->myPlane << ".\n";
    currentPilot->myPlane = nullptr;
}
