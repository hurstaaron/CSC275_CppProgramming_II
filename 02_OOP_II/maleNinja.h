/*  ===== This is a subclass header file for the Ninja class =====
    Inherits from the Character class.
    This will only have the constructor that chains up Ninja class.
    An empty body { } means no need for a maleNinja.cpp file. 
 */
#pragma once // Using pragma instead of indef and define guards for simplicity
#include "ninja.h"

class MaleNinja  : public Ninja {
public:
    // Create the constructor
    MaleNinja ()
        // Pass parameters: 1 string, 10 ints, 1 bool, 2 floats
        : Ninja("Musashi",  100, 30, 60, 40, 70, 10, 
                25, 35, 0, 100, false, 1.75f, 2.5f) {}    
};

