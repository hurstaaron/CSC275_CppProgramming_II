#include "character.h"
#include <iostream>

Character::Character(
    // List of constructor parameters
    std::string inName, int inHealth, int inAttackPowerMin, int inAttackPowerMax,
    int inPrecisionMin, int inPrecisionMax, int inDefenseMin, int inDefenseMax, 
    int inEvasionChance, int inUltimateBar, int inUltimateBarMax, bool inUltimateReady,
    float inUltMultiplierMin, float inUltMultiplierMax) 
    // List of data members and initialize them
    : Name{inName}, 
    Health{inHealth}, 
    AttackPowerMin{inAttackPowerMin}, 
    AttackPowerMax {inAttackPowerMax},
    PrecisionMin{inPrecisionMin}, 
    PrecisionMax{inPrecisionMax}, 
    DefenseMin{inDefenseMin},
    DefenseMax{inDefenseMax}, 
    EvasionChance{inEvasionChance}, 
    UltimateBar{inUltimateBar},
    UltimateBarMax{inUltimateBarMax}, 
    UltimateReady{inUltimateReady}, 
    UltMultiplierMin{inUltMultiplierMin},
    UltMultiplierMax{inUltMultiplierMax}    // no comma here to signify last data memeber
    // Start the constructor body
    {

    }

// Returns the current Health value
int Character::getHealth() {
    return Health;
}

// Updates Health and if the new value is below zero it sets to zero and notifies player
void Character::setHealth(int inHealth) {
    if (inHealth < 0) {
        Health = 0;
        std::cout << Name << " has Expired..." << std::endl;
    } else {
        Health = inHealth;
    }
}

// Outputs the character's name followed by their message
void Character::Talk(std::string inName, std::string inStuffToSay) {
    std::cout << inName << " says: " << inStuffToSay << std::endl;
}

// Base attack, the base attack will return 10 hit points
int Character::attack() {
    return 10;
}

// Provides Character instructions to the player
void Character::Help() {
    std::cout << "Characters have Health, Attack, Defense, and Evasion stats." << std::endl;
}
