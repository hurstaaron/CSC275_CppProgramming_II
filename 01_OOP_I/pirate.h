// Using pragma instead of indef and define guards for simplicity
#pragma once
#include "character.h"

// Build the ninja character class -  a derived class of the Character (base) class
class Pirate : public Character {
    public:
        // Constructor
        Pirate (
            // List of parameters inherited from the Character (base) class
            std::string inName, int inHealth, int inAttackPowerMin, int inAttackPowerMax,
            int inPrecisionMin, int inPrecisionMax, int inDefenseMin, int inDefenseMax, 
            int inEvasionChance, int inUltimateBar, int inUltimateBarMax, bool inUltimateReady,
            float inUltMultiplierMin, float inUltMultiplierMax
        );

        // Create the signature method for the Ninja class
        void DirtyBrawler();
        
    private:
        // Methods
};