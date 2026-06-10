// Using pragma instead of indef and define guards for simplicity
#pragma once
#include "character.h"

// Build the ninja character class -  a derived class of the Character (base) class
class Ninja : public Character {
    public:
        // Constructor
        Ninja (
            // List of parameters inherited from the Character (base) class
            std::string inName, int inHealth, int inAttackPowerMin, int inAttackPowerMax,
            int inPrecisionMin, int inPrecisionMax, int inDefenseMin, int inDefenseMax, 
            int inEvasionChance, int inUltimateBar, int inUltimateBarMax, bool inUltimateReady,
            float inUltMultiplierMin, float inUltMultiplierMax
        );

        // Create the signature method for the Ninja class
        void PrecisionStrike();

        // Override attack, the Ninja will return 25 hit points
        int attack() override;

        // Override Help, provides Ninja game instructions
        void Help() override;
        
    private:
        // Methods
};