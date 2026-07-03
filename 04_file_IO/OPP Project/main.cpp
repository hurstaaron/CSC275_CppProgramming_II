/*
    Assignment 05: OPP Project
    Professor: Rawad Habib
    Start Date: 6/25/26
    End Date:   7/3/26
    By: Aaron Hurst
*/

// ---------- Introduction ----------
// This project is split into a separate .h and .cpp file for each class for modular
// design. The .h file for a class will describe what the class looks like, e.g. data
// and function names, and the matching .cpp file implements the code. This is the main
// file of the program and includes all class headers and runs the demo.

// ---------- Preprossesor Libraries ----------
#include <iostream>                 // for cout so I can print things to the screen
#include "Weapon.h"                 // for creating Weapon objects
#include "InvalidUnitException.h"   // for catching specific exception type
#include "Unit.h"                   // for the parent Unit type
#include "Infantry.h"               // for creating Infantry objects
#include "Vehicle.h"                // for creating Vehicle objects
#include "Army.h"                   // for creating Army objects
#include "Commander.h"              // for reating Commander objects

// A simple war game army roster meshing game design and real world scenarios.
// I can build an army of different units, have the whole army attack at once, 
// and save, or load, the army to a text file to maintain progress data between 
// sessions. Assignment requirements met:
// Inheritance (different unit types - complete)
// Polymorphism (each unit attacks differently - complete)
// Encapsulation (complete)
// Operator overloading (complete) 
// Exception handling (cemplete)
// File I/O (complete)

int main() {
    // print a little banner so whoever runs this knows what the program does
    std::cout << "=====================================" << std::endl;
    std::cout << "       Army Roster Manager" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "This program builds a small army that attacks, and saves the" << std::endl;
    std::cout << "whole roster to a text file so it can be loaded for later sessions." << std::endl;
    std::cout << std::endl;

    // I wrap main in a try block because several of operations, like creating a unit or
    // opening a file, can throw an exception if/when something goes wrong
    try {
        // create the main army named Alpha Company
        Army myArmy("Alpha Company");

        // create two weapons for the Units
        Weapon rifle("Rifle", 10);
        Weapon cannon("Main Cannon", 25);

        // create one infantry unit and create one vehicle unit 
        // Use heap memory because I want the Army to store pointers not objects
        Infantry* soldier1 = new Infantry("Private Reyes", 100, rifle, 5);
        Vehicle* tank1 = new Vehicle("Iron Fist", 250, cannon, "Tank");

        // add both units into the army
        myArmy.addUnit(soldier1);
        myArmy.addUnit(tank1);

        // show the roster before anything happens
        myArmy.displayRoster();
        std::cout << std::endl;

        // create a commander and give the order to attack
        Commander commander("Vasquez", "Sergeant");
        commander.giveOrders(myArmy);
        std::cout << std::endl;

        // demonstrating the overloaded + operator on the Weapon class
        Weapon comboWeapon = rifle + cannon;
        std::cout << "Combined weapon created: " << comboWeapon.getName()
                  << " with " << comboWeapon.getDamage() << " damage." << std::endl;
        std::cout << std::endl;

        // saving the army to a text file
        myArmy.saveToFile("army_roster.txt");
        std::cout << std::endl;

        // loading the army into a brand new Army object to validate that the file save works
        Army loadedArmy("Alpha Company (Reloaded)");
        loadedArmy.loadFromFile("army_roster.txt");
        std::cout << std::endl;
        // show the roster of the reloaded army to the user so it can be compared to the original
        loadedArmy.displayRoster();
        std::cout << std::endl;

        // trying to create a bad unit with negative health to break the program
        // this proves the custom exception will be caught and handled correctly
        try {
            // this line should throw InvalidUnitException since -10 is negative
            Infantry badUnit("Ghost", -10, rifle, 0);
        } catch (InvalidUnitException &e) {
            // print out the specific error message from the exception
            std::cout << "Caught expected error: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        // catch any other exception like a file failing to open or close correctly
        std::cout << "An error occurred: " << e.what() << std::endl;
    }

    // program ending message
    std::cout << std::endl;
    std::cout << "Program finished." << std::endl;

    return 0;
}
