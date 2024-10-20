// Plane.h
#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <map>

class Plane {
private:
	// Private varibles
	double pos; // Position
	double vel; // Velocity
	double distance; // Distance
	bool at_SCE; // Verifies that the plane is at SCE
	std::string origin; // Origin of the Flight
	std::string destination; // Destination of the flight
	std::map<std::pair<std::string, std::string>, double>flightdistances; // Container for flight distances from part 2
public:
	//Constructor
	Plane(const std::string& from, const std::string& to);
	//Deconstructor
	~Plane();

	// Getter and Setter functions
	double getPos() const; // gets the position of the plane
	void setPos(double position); // sets the position of the plane

	double getVel() const; // gets the velocity of the plane
	void setVel(double velocity); //sets the velo of the plane

	double getDistance() const; //gets the distance between origin and destination
	bool isatSCE() const; //checks if the plane is at SCE

	std::string getOrigin() const;
	std::string getDestination() const;

	// Declare the operate function
	void operate(double dt);
};

#endif // PLANE_H