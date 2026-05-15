#include "boss.h"
#include <iostream>

// Build the constructor for the Boss
// Chains directly to character and has no subclasses
// Stats will be fixed
Boss::Boss () : Character(
    // Fixed Stats 
    "Abaddon",      // inName                           - demon's name
    175,            // inHealth                         - above avg health
    65, 95,         // inAttackMin, inAttackMax         - hits hard
    50, 75,         // inPrecisionMin, inPrecisionMax   - calculated strikes
    30, 50,         // inDefenseMin, inDefenseMax       - tanks hits
    5,              // inEvasionChance                  - barely dodges
    0, 250,         // inUltimateBar, inUltimateMax     - fills slower
    false,          // inUltimateReady                  - starts empty      
    2.0f, 3.5f      // inUltimateMultiplierMin / Max    - lethal criticals
    )
    // Constructor body 
    {
        
    }

    // Build the signature method for the Boss class
    void Boss::RendingClaws() {
        std::cout << Name << " hits with Rending Claws!\n";
    }