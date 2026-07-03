#pragma once        // So I don't need guards
#include <string>   // needed for the armyName variable
#include "Unit.h"   // needed because Army stores an array of Unit pointers


// This class owns and manages a collection of units. I used a fixed size array 
// of Unit pointers instead to keep things simple. Using Unit pointers, instead of an
// array of Unit objects is better becauyse it allows thepolymorphism to work when
// I loop the array and call attack().
class Army {
private:
    // the biggest number of units this army can hold fixed at 20
    static const int MAX_UNITS = 20;
    // array of pointers to units currently in this army
    Unit* units[MAX_UNITS];
    // how many units are currently stored in the array
    int unitCount;
    // a name for the army for display purposes
    std::string armyName;

public:
    // constructor sets army ame and starts the unit count at zero
    Army(std::string aName);

    // destructor deletes every unit Icreated with "new" so no memory leaks happen.
    // Unit has a virtual destructor to correctly clean Infantry and Vehicle too.
    ~Army();

    // adds a new unit to the army
    // throws std::runtime_error if the army is full
    void addUnit(Unit* u);

    // calls attack() on every unit in army. The loop is simple and has has one line 
    // but each unit attacks differently depending n whether it is Infantry or a Vehicle
    // That is why I used the virtual functions here.
    void attackAll();

    // prints out the army roster calling displayInfo() on each unit
    void displayRoster() const;

    // saves eachunit in the army to a text file one unit per line. Each line
    // starts with the unit type, either INFANTRY or VEHICLE, so that when the file is
    // read back later I know which class to rebuild. Throws runtime_error if file can't opened.
    void saveToFile(std::string fileName);

    // reads the army in from the text file, rebuilding the correct object type
    // for each line. Throws runtime_error if the file cannot be opened.
    void loadFromFile(std::string fileName);
};
