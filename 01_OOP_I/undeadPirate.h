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
        : Pirate("Benjin Bonejaw",  110, 25, 50, 35, 60, 40, 
                65, 10, 0, 100, false, 1.25f, 1.75f) {}    
};