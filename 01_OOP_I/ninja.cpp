#include "ninja.h"
#include <iostream>

Ninja::Ninja (
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
        Ninja::PrecisionStrike();
            std::cout << "Ninja used Precision Strike!" << std::endl;
        
    }

    