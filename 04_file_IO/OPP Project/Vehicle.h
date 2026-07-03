#pragma once        // no indef guards needed now
#include "Unit.h"   // needed because Vehicle inherits from Unit

// Same idea as Infantry, Vehicle gets name, health, and weapon from Unit for free,
// and just adds its own vehicleType on top of that.
class Vehicle : public Unit {
private:
    // what kind of vehicle this is, example: "Tank" or "Transport"
    std::string vehicleType;

public:
    // constructor, takes everything a normal Unit needs plus the vehicle type
    Vehicle(std::string n, int hp, Weapon w, std::string type);

    // another example of overriding attack(), Vehicles attack differently than Infantry
    void attack();

    // overrides displayInfo() so it also shows the vehicle type
    void displayInfo() const;

    // overrides toFileString() so the saved line also includes vehicle type
    std::string toFileString() const;
};
