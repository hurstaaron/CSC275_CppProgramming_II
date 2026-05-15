#include "pirate.h"
#include <iostream>

// Build the constructor for the Ninja class - a derived class of the Character (base) class
Pirate::Pirate (
    // List of parameters inherited from the Character (base) class
    std::string inName, int inHealth, int inAttackPowerMin, int inAttackPowerMax,
    int inPrecisionMin, int inPrecisionMax, int inDefenseMin, int inDefenseMax, 
    int inEvasionChance, int inUltimateBar, int inUltimateBarMax, bool inUltimateReady,
    float inUltMultiplierMin, float inUltMultiplierMax
    ) : Character
    // List of values inherited from the Character (base) class  
    (inName, inHealth, inAttackPowerMin, inAttackPowerMax, inPrecisionMin, inPrecisionMax, 
    inDefenseMin, inDefenseMax, inEvasionChance, inUltimateBar, inUltimateBarMax, inUltimateReady,
    inUltMultiplierMin, inUltMultiplierMax)
    {
        
    }

    // Build the signature method for the Ninja class
    void Pirate::DirtyBrawler() {
        std::cout << Name << " is fighting Mean and Dirty!" << std::endl;
    }