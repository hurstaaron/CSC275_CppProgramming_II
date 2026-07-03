#pragma once
#include <string>
// needed so I can use std::string for the name attribute
#include "Weapon.h"
// needed because Unit actually holds a real Weapon object, not just a pointer to one

// This holds everything that EVERY unit in the army has in common, a name, health,
// and a weapon. I made name and health "protected" instead of "private" because
// the classes that inherit from Unit need to use them directly. Outside code that
// is not part of this class family still cannot touch them at all, it has to go
// through the public methods below, so the data is still protected from the outside
// world, just not from my own child classes.
class Unit {
protected:
    // name of this unit, protected so Infantry and Vehicle can use it directly
    std::string name;
    // current health of this unit, protected for the same reason as name
    int health;
    // the weapon this unit is currently using
    Weapon weapon;

public:
    // constructor, builds a new Unit with a name, starting health, and a weapon
    // throws InvalidUnitException if hp is negative, see Unit.cpp for the actual check
    Unit(std::string n, int hp, Weapon w);

    // virtual destructor. This matters because later on I delete units through a
    // Unit pointer, even though the actual object might really be an Infantry or
    // a Vehicle underneath. Without marking this virtual, only the Unit part of
    // the object would get cleaned up properly, which is a common beginner mistake.
    virtual ~Unit();

    // returns this unit's name to outside code
    std::string getName() const;

    // returns this unit's current health to outside code
    int getHealth() const;

    // returns true if health is still above zero, false if the unit is dead
    bool isAlive() const;

    // I did not add a plain setHealth() function on purpose. Instead health can
    // only change through takeDamage(). This way health can never accidentally
    // get set to some random number from outside the class, it can only go down
    // the way combat is actually supposed to work.
    void takeDamage(int dmg);

    // this is marked virtual so that Infantry and Vehicle can override it with
    // their own version. This is what makes polymorphism possible later on.
    virtual void attack();

    // prints out this unit's basic info, also virtual so child classes can add more to it
    virtual void displayInfo() const;

    // builds one line of comma separated text describing this unit, used when
    // saving the army to a file. I put "UNIT" first so that if I ever load this
    // file back in, I know what kind of object to rebuild.
    virtual std::string toFileString() const;
};
