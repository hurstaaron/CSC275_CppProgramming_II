#include "Unit.h"
// pulls in the Unit class declaration
#include "InvalidUnitException.h"
// pulls in my custom exception so I can throw it in the constructor
#include <iostream>
// needed for cout so I can print things to the screen
#include <sstream>
// needed for stringstream so I can build the comma separated file line

// this is the constructor, it runs every time a new Unit (or something that
// inherits from Unit) gets created
Unit::Unit(std::string n, int hp, Weapon w) {
    // if someone tries to make a unit with negative health that is not a real
    // situation, so I throw my custom exception instead of letting bad data
    // sit inside my program
    if (hp < 0) {
        // stop right here and hand control back up to whoever called this constructor,
        // carrying my custom error message with it
        throw InvalidUnitException("Cannot create unit '" + n + "' with negative health.");
    }
    // store the name that was passed in
    name = n;
    // store the starting health that was passed in
    health = hp;
    // store the weapon that was passed in
    weapon = w;
}

// destructor, runs automatically when a Unit object gets deleted or goes out of scope
Unit::~Unit() {
    // nothing to clean up here, Unit does not allocate anything on its own with new,
    // this is just here because the destructor needs to exist and be virtual
}

// hands back the name to whoever calls this
std::string Unit::getName() const {
    return name;
}

// hands back the health to whoever calls this
int Unit::getHealth() const {
    return health;
}

// returns true only if health is still greater than zero
bool Unit::isAlive() const {
    return health > 0;
}

// this is the only way health is allowed to change after the unit is created
void Unit::takeDamage(int dmg) {
    // subtract the incoming damage from the current health
    health -= dmg;
    // health should never go below zero, so clamp it back up to zero if it does
    if (health < 0) {
        health = 0;
    }
}

// this is the base version of attack, Infantry and Vehicle will override this
// with their own version, but this is what runs if nothing overrides it
void Unit::attack() {
    // print out a generic attack message using this unit's name and weapon
    std::cout << name << " attacks with " << weapon.getName()
               << " for " << weapon.getDamage() << " damage." << std::endl;
}

// prints this unit's basic info to the screen, does not change any data (that is why it is const)
void Unit::displayInfo() const {
    std::cout << "Name: " << name << " | Health: " << health
               << " | Weapon: " << weapon.getName() << " (" << weapon.getDamage() << " dmg)";
}

// builds one line of text that represents this unit, used for saving to a file
std::string Unit::toFileString() const {
    // stringstream lets me build up a string piece by piece using the << operator,
    // just like I would with cout, except it goes into a string instead of the screen
    std::stringstream ss;
    // "UNIT" at the front tells loadFromFile what kind of object this line represents
    ss << "UNIT," << name << "," << health << "," << weapon.getName() << "," << weapon.getDamage();
    // convert the stringstream into an actual std::string and hand it back
    return ss.str();
}
