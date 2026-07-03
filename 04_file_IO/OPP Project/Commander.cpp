#include "Commander.h"  // connects Commander class 
#include <iostream>     // for cout

// constructor, stores the name and rank that get passed in
Commander::Commander(std::string n, std::string r) {
    // store the name that was passed in
    name = n;
    // store the rank that was passed in
    rank = r;
}

// gives the order to attack
void Commander::giveOrders(Army &army) {
    // print a message showing the commander giving the order
    std::cout << rank << " " << name << " gives the order to attack!" << std::endl;
    // tell the army to actually carry out the attack
    army.attackAll();
}
