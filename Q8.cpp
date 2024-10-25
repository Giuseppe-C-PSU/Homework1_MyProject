#include "Q8.h"

// Constructor
ModernPilot::ModernPilot(const std::string& pilotname) : name(pilotname) {
    myPlane = nullptr;
    std::cout << "Modern Pilot " << name << " is at the gate, ready to board the plane.\n";
}

// Destructor
ModernPilot::~ModernPilot() {
    std::cout << "Modern Pilot " << name << " is out of the plane.\n";
}

std::string ModernPilot::getName() const {
    return name;
}

void ModernPilot::printControlInfo() const {
    std::cout << "Modern Pilot " << name << " is flying the plane " << myPlane.get() << ".\n";
}

void switchModernPilots(std::unique_ptr<ModernPilot>& currentPilot, std::unique_ptr<ModernPilot>& nextPilot) {
    std::cout << "The plane (" << currentPilot->myPlane.get() << ") has arrived at SCE.\n";
    std::cout << "Modern Pilot " << currentPilot->getName() << " is taking a break.\n";
    nextPilot->myPlane = std::move(currentPilot->myPlane);
    std::cout << "Modern Pilot " << nextPilot->getName() << " is flying the plane " << nextPilot->myPlane.get() << ".\n";
}
