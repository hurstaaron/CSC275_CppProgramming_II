#pragma once        // no need for indef guards now
#include <string>

// A weapon has a name and does damage. 
class Weapon {
private:
    // holds the name of the weapon, like "Rifle" or "flame thrower"
    std::string weaponName;
    // holds how much damage this instance of weapon does during an attack
    int damage;

public:
    // constructor called if someone makes a Weapon with no arguments
    // default unarmed weapon so the object is never blank
    Weapon();

    // constructor builds a weapon with a specific name and damage amount
    Weapon(std::string name, int dmg);

    // returns the weapon's name so outside code can read it without touching altering it
    std::string getName() const;

    // returns the weapon's damage number, same idea as getName above
    int getDamage() const;

    // overloads the "+" operator to combine two weapons into one stronger weapon 
    // writing weaponOne + weaponTwo, kind of like adding two numbers together. 
    // This is a natural adn easire wayto read this than calling a separate
    // function like combineWeapons(weaponOne, weaponTwo) every time.
    Weapon operator+(const Weapon& other) const;
};
