#include <iostream>
#include "Plane.h"
#include <string>


int main() {
	std::string origin, destination;

	//Get the origin and destination
	std::cout << "Enter the Origin: ";
	std::cin >> origin;
	std::cout << "Enter the destination: ";
	std::cin >> destination;

	// Create a Plane object with inputs
	Plane plane(origin, destination);

	//Set the velocity

}