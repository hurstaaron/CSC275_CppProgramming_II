#pragma once
#include "Unit.h"   // needed because Infantry inherits from Unit, so I need the full Unit class definition

// Infantry is a Unit that also carries ammo. Instead of rewriting name, health, 
// and weapon over again, Infantry inherits from Unit and just adds the one new 
// thing it actually needs, like the ammoCount. Nobody wants to copy and paste the
// the same variables and functions repeatedly, so inheritance!
class Infantry : public Unit {
private:
    // how many shots of ammo this instance of the infantry unit has 
    int ammoCount;

public:
    // constructor, takes everything a normal Unit needs plus a starting ammo count
    Infantry(std::string n, int hp, Weapon w, int ammo);

    // this will override the parent class attack() using polymorphism because   
    // an Infantry unit attacks different than a Vehicle. I didn't change anything in 
    // the Army class
    void attack();

    // overrides displayInfo() so it also shows ammoCount
    void displayInfo() const;

    // overrides toFileString() so the saved line andincludes ammo count
    std::string toFileString() const;
};
