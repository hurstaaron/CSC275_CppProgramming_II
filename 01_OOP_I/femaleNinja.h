/*  ===== This is a subclass header file for the Ninja class =====
    Inherits from the Character class.
    This will only have the constructor that chains up Ninja class.
    An empty body { } means no need for a maleNinja.cpp file. 
 */
#pragma once // Using pragma instead of indef and define guards for simplicity
#include "ninja.h"

class FemaleNinja : public Ninja {
public:
    // Create the constructor
    FemaleNinja()
        // Pass parameters: 1 string, 10 ints, 1 bool, 2 floats
        : Ninja("Mochizuki",  85, 20, 45, 60, 90, 10, 
                20, 55, 0, 80, false, 1.25f, 1.75f) {}    
};