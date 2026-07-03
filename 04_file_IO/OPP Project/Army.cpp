#include "Army.h"       // pulls in the Army class declaration
#include "Infantry.h"   // needed because loadFromFile has to create new Infantry objects
#include "Vehicle.h"    // needed because loadFromFile has to create new Vehicle objects
#include <iostream>     // needed for cout
#include <fstream>      // needed for ofstream and ifstream, the file writing and reading tools
#include <sstream>      // needed for stringstream, used to split apart lines from the file
#include <stdexcept>    // needed for std::runtime_error

// constructor, sets the army's name and makes sure unitCount starts at zero
Army::Army(std::string aName) {
    armyName = aName;
    unitCount = 0;
}

// destructor, cleans up every unit we created with "new"
Army::~Army() {
    // loop through every unit currently stored and delete it one at a time
    for (int i = 0; i < unitCount; i++) {
        delete units[i];
    }
}

// adds a new unit pointer into the array
void Army::addUnit(Unit* u) {
    // if the army is already full that creates a runtime problem so I throw
    // a runtime_error here instead of the custom exception because this is a general 
    // "ran out of room" error
    if (unitCount >= MAX_UNITS) {
        throw std::runtime_error("Army is full, cannot add any more units.");
    }
    // put the new unit into the next open slot in the array
    units[unitCount] = u;
    // increment counter
    unitCount++;
}

// calls attack() on every unit in the army
void Army::attackAll() {
    // print a header line so it is clear the attack phase is starting
    std::cout << "--- " << armyName << " begins the attack! ---" << std::endl;
    // loop through every unit in the army
    for (int i = 0; i < unitCount; i++) {
        // call attack() through the base class pointer, the correct override runs automatically
        units[i]->attack();
    }
}

// prints the full roster of the army
void Army::displayRoster() const {
    // header line so it is clear what is being printed
    std::cout << "--- " << armyName << " Roster ---" << std::endl;
    // loop through every unit and print its info
    for (int i = 0; i < unitCount; i++) {
        units[i]->displayInfo();
    }
}

// saves the whole army to a text file
void Army::saveToFile(std::string fileName) {
    // open the file for writing, this creates it if it does not already exist
    std::ofstream outFile(fileName);
    // if the file did not open correctly, stop here and throw an error
    if (!outFile) {
        throw std::runtime_error("Could not open file to save the army.");
    }
    // loop through every unit and write its file line to the file
    for (int i = 0; i < unitCount; i++) {
        outFile << units[i]->toFileString() << std::endl;
    }
    // close the file now that everything has been written
    outFile.close();
    // let the user know the save was successful
    std::cout << armyName << " has been saved to " << fileName << std::endl;
}

// loads the army back in from a text file
void Army::loadFromFile(std::string fileName) {
    // open the file for reading
    std::ifstream inFile(fileName);
    // if the file did not open correctly, stop here and throw an error
    if (!inFile) {
        throw std::runtime_error("Could not open file to load the army.");
    }

    // I picked a simple comma separated format on purpose, since it lines up
    // directly with the attributes each class already has, and it is easy to
    // split apart using stringstream and getline.
    // this string will hold each line as it comes in from the file
    std::string line;
    // keep reading lines until there are no more lines left in the file
    while (std::getline(inFile, line)) {
        // stringstream lets me treat this one line like its own little input stream
        // so I can pull pieces out of it separated by commas
        std::stringstream ss(line);

        // these strings will hold each comma separated piece of the line
        std::string type, name, healthStr, weaponName, damageStr;
        std::getline(ss, type, ',');        // pull out the type field (UNIT, INFANTRY, or VEHICLE)
        std::getline(ss, name, ',');        // pull out the name field
        std::getline(ss, healthStr, ',');   // pull out the health field as text
        std::getline(ss, weaponName, ',');  // pull out the weapon name field
        std::getline(ss, damageStr, ',');   // pull out the weapon damage field as text

        
        int health = std::stoi(healthStr);  // stoi turns the text number into a real int
        int damage = std::stoi(damageStr);  // same thing for the damage number
        Weapon w(weaponName, damage);       // build a new Weapon object using the name and damage we just read

        // now I check the type field to decide which class to actually rebuild
        if (type == "INFANTRY") {
            // infantry lines have one more field after damage, the ammo count
            std::string ammoStr;
            std::getline(ss, ammoStr, ',');
            // convert the ammo text into a real int
            int ammo = std::stoi(ammoStr);
            // create a new Infantry object and add it into this army
            addUnit(new Infantry(name, health, w, ammo));
        } else if (type == "VEHICLE") {
            // vehicle lines have one more field after damage, the vehicle type
            std::string vType;
            std::getline(ss, vType, ',');
            // create a new Vehicle object and add it into this army
            addUnit(new Vehicle(name, health, w, vType));
        }
    }

    // close the file now that we are done reading from it
    inFile.close();
    // let the user know the load was successful
    std::cout << armyName << " has been loaded from " << fileName << std::endl;
}
