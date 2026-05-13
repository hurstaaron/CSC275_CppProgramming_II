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
