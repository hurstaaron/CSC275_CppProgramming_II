#include "Infantry.h"
// pulls in the Infantry class declaration
#include <iostream>
// needed for cout
#include <sstream>
// needed for stringstream when building the file line

// constructor, first calls the Unit constructor using the : Unit(n, hp, w) part,
// then sets the one extra thing Infantry has that Unit does not, which is ammoCount
Infantry::Infantry(std::string n, int hp, Weapon w, int ammo) : Unit(n, hp, w) {
    // store the starting ammo count
    ammoCount = ammo;
}

// this is the Infantry specific version of attack
void Infantry::attack() {
    // only fire a shot if there is ammo left
    if (ammoCount > 0) {
        // print the attack message, showing how much ammo will be left after this shot
        std::cout << name << " the infantry unit fires " << weapon.getName()
                   << " for " << weapon.getDamage() << " damage. Ammo left: "
                   << (ammoCount - 1) << std::endl;
        // actually use up one shot of ammo
        ammoCount--;
    } else {
        // if there is no ammo left, fall back to a weak melee attack instead
        std::cout << name << " is out of ammo and swings a rifle butt for 2 damage instead." << std::endl;
    }
}

// this is the Infantry specific version of displayInfo
void Infantry::displayInfo() const {
    // call the base class version first so I do not have to retype the name, health, and weapon part
    Unit::displayInfo();
    // then add the extra Infantry specific info on top of that
    std::cout << " | Type: Infantry | Ammo: " << ammoCount << std::endl;
}

// this is the Infantry specific version of toFileString
std::string Infantry::toFileString() const {
    // same idea as Unit's version, but tagged as INFANTRY and with ammo added on the end
    std::stringstream ss;
    ss << "INFANTRY," << name << "," << health << "," << weapon.getName()
       << "," << weapon.getDamage() << "," << ammoCount;
    return ss.str();
}
