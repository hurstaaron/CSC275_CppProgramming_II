#pragma once        // used so I don't have to use indef guards
#include <string>   // using some strings
#include "Army.h"   // needed so giveOrders can take an Army reference as a parameter

// This class leads an Army. It does not inherit but wanted more modularity
// in the design that shows how a Commander gives orders to an Army
class Commander {
private:
    std::string name;   // this commander's name
    std::string rank;   // this commander's rank, like "Captain or Sergeant"

public:
    Commander(std::string n, std::string r);    // constructor, sets the name and rank for this commander
    void giveOrders(Army &army);                // tells the given army to attack, and prints a message first
};
