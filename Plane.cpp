// Plane.cpp
#include "Q2.h"
#include "Plane.h"
#include <iostream>
#include <chrono>
#include <thread>

// Constructor
Plane::Plane(const std::string& From, const std::string& To)
	: pos(0), vel(0), distance(0), at_SCE(false), origin(From),
	destination(To) {
	// Initialize flight distances
	FlightDistances();

	// Set the distance based on the origin and destination
	distance = getFlightDistance(To, From);
	std::cout << "Plane Created at " << this << std::endl;
}




//Deconstructor
Plane::~Plane() {
	std::cout << "Plane Destroyed" << std::endl;
}



void Plane::operate(double dt) {
	
		if (pos < distance) {
			at_SCE = false;
			pos += vel * (dt/3600);
		}
		else {
			if (destination == "SCE"){
				at_SCE = true;
				std::string temp = origin;
				origin = destination;
				destination = temp;
				pos = 0;
			}else{
				std::string temp = origin;
				origin = destination;
				destination = temp;
				pos = 0;
			}
		}
}

// Getter and setter functions
double Plane::getPos() const { return pos; }
void Plane::setPos(double position) { pos = position; }

double Plane::getVel() const { return vel; }
void Plane::setVel(double velocity) { vel = velocity; }

double Plane::getDistance() const { return distance; }
bool Plane::isatSCE() const { return at_SCE; }
