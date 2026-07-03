#include "Vehicle.h"
#include <iostream>
#include <sstream>

// constructor, calls the Unit constructor first, then stores the vehicle type
Vehicle::Vehicle(std::string n, int hp, Weapon w, std::string type) : Unit(n, hp, w) {
    // store what type of vehicle this is
    vehicleType = type;
}

// Vehicle specific version of attack
void Vehicle::attack() {
    // print a message showing the vehicle firing its weapon
    std::cout << name << " the " << vehicleType << " fires " << weapon.getName()
               << " for " << weapon.getDamage() << " damage!" << std::endl;
}

// Vehicle specific version of displayInfo
void Vehicle::displayInfo() const {
    // reuse the base class version first
    Unit::displayInfo();
    // then add the vehicle type on top
    std::cout << " | Type: Vehicle (" << vehicleType << ")" << std::endl;
}

// Vehicle specific version of toFileString
std::string Vehicle::toFileString() const {
    // same pattern as Infantry, but tagged VEHICLE and with vehicle type on the end
    std::stringstream ss;
    ss << "VEHICLE," << name << "," << health << "," << weapon.getName()
       << "," << weapon.getDamage() << "," << vehicleType;
    return ss.str();
}
