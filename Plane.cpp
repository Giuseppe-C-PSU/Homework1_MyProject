// Plane.cpp
#include "Plane.h"
#include <iostream>

// Constructor
Plane::Plane(const std::string& from, const std::string& to)
	: pos(0), vel(0), distance(0), at_SCE(true), origin(from),
	destination(to) {
	// Initialize flight distances
	flightdistances[{"SCE", "PHL"}] = 160;
	flightdistances[{"SCE", "ORD"}] = 640;
	flightdistances[{"SCE", "EWR"}] = 220;

	// Set the distance based on the origin and destination
	distance = flightdistances[{from, to}];
	std::cout << "Plane Created at " << this << std::endl;
}

//Deconstructor
Plane::~Plane() {
	std::cout << "Plane Destroyed" << std::endl;
}

// Getter and setter functions
double Plane::getPos() const { return pos; }
void Plane::setPos(double position) { pos = position; }

double Plane::getVel() const { return vel; }
void Plane::setVel(double velocity) { vel = velocity; }

double Plane::getDistance() const { return distance; }
bool Plane::isatSCE() const { return at_SCE; }

void Plane::operate(double dt) {
	pos += vel * dt;
		if (pos >= distance) {
			pos = distance;
			at_SCE = true;
		}
		else {
			at_SCE = false;
		}
}