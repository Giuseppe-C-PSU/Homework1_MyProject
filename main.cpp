#include <iostream>
#include "Plane.h"
#include <string>



int main() {

	std::string from, to;
	double velocity;

	
	// Create a Plane object with inputs

	Plane plane(from, to);
	//Set the velocity
	plane.setVel(500); // Velo

	//Simulate plane's operation
	double dt = 10; // Time step
	for (int i = 0; i < 1500; ++i) {
		plane.operate(dt);
		std::cout << "Position: " << plane.getPos() << ", At SCE: " << plane.isatSCE() << std::endl;

	}


	return 0;
}