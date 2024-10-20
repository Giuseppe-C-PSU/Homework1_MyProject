#include <iostream>
#include <string>

class Plane {};

class Pilot {
private:
  std::string name;

public:
// Constructor
  Plane* myPlane;
  Pilot(const std::string& pilotname) : name(pilotname) {myPlane = nullptr; 
    std::cout << "Pilot " << name << "Memory Address: " << this << " is at the gate and ready to board the plane!.\n";}

// Destructor
  ~Pilot() {
    if (myPlane != nullptr)
    std::cout << "The pilot, " << name << ",is out of the plane. \n";}

std:: string getName() const {
return name;
}

int main() {
    Pilot* p = new Pilot("John Doe");
    std::cout << "Pilot's name through getter: " << p->getName() << "\n";

    delete p;  
    return 0;
}
  };


