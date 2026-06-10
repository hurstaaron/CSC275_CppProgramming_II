// Using pragma instead of indef and define guards for simplicity
#pragma once
#include <string>

class Character {
public:
    // Create Name as a public property - accessable to everyone using the Character class
    std::string Name;

    // Build the Constructor - special member function that is auto-called when objects 
    // of the Character class is created
    Character(
        std::string inName, int inHealth, int inAttackPowerMin, int inAttackPowerMax,
        int inPrecisionMin, int inPrecisionMax, int inDefenseMin, int inDefenseMax, 
        int inEvasionChance, int inUltimateBar, int inUltimateBarMax, bool inUltimateReady,
        float inUltMultiplierMin, float inUltMultiplierMax
    );

private:
    // Create Health as a private property - only accessible within Character class
    int Health;

protected:
    // Create Character modifiers that are hidden from outside of Character class, 
    // but accessible by the derived classes
    int AttackPowerMin, AttackPowerMax, PrecisionMin, PrecisionMax, DefenseMin, DefenseMax, 
        EvasionChance, UltimateBar, UltimateBarMax;
    bool UltimateReady;
    float UltMultiplierMin, UltMultiplierMax;

};