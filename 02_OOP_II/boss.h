// Using pragma instead of indef and define guards for simplicity
#pragma once
#include "character.h"

// Build the Boss character class -  a derived class of the Character (base) class
class Boss : public Character {
    public:
        // Constructor
        // No parameters because there is one boss and stats are fixed
        Boss ();

        // Abaddon's (Boss) signature attack
        void RendingClaws();
};