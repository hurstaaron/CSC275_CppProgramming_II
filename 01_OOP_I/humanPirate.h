/*  ===== This is a subclass header file for the Ninja class =====
    Inherits from the Character class.
    This will only have the constructor that chains up Ninja class.
    An empty body { } means no need for a maleNinja.cpp file. 
 */
#pragma once // Using pragma instead of indef and define guards for simplicity
#include "pirate.h"

class UndeadPirate : public Pirate {
public:
    // Create the constructor
    UndeadPirate()
        // Pass parameters: 1 string, 10 ints, 1 bool, 2 floats
        : Pirate("Sestus Paks",  120, 35, 65, 20, 45, 30, 
                55, 15, 0, 100, false, 1.5f, 2.0f) {}    
};