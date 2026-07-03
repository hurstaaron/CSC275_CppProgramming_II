#include "Weapon.h" // inherits from the Weapon class 

// This is the IMPLEMENTATION file for Weapon. This is where I write out
// what each function does. Notice every function name has "Weapon::" in front of
// it, that just tells the compiler "this function belongs to the Weapon class,
// the one described over in Weapon.h".

// default constructor, runs when someone writes something like Weapon w;
Weapon::Weapon() {
    // if no name is given, just call it "Bare Fists" so it is not blank
    weaponName = "Bare Fists";
    // give it a tiny bit of damage so it is not completely useless
    damage = 1;
}

// this constructor runs when someone gives a name and a damage number
Weapon::Weapon(std::string name, int dmg) {
    // store whatever name was passed in
    weaponName = name;
    // store whatever damage number was passed in
    damage = dmg;
}

// simple getter, just hands back the name, does not change anything (that is what const means here)
std::string Weapon::getName() const {
    return weaponName;
}

// simple getter, just hands back the damage number
int Weapon::getDamage() const {
    return damage;
}

// this is the actual code for the + operator overload
Weapon Weapon::operator+(const Weapon& other) const {
    // build a new name that shows both weapons got combined, like "Rifle + Main Cannon"
    std::string combinedName = weaponName + " + " + other.weaponName;
    // add the two damage numbers together for the new combined weapon
    int combinedDamage = damage + other.damage;
    // return a brand new Weapon object built from the combined name and damage
    return Weapon(combinedName, combinedDamage);
}
