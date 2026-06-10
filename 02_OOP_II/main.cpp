/*  ====== Object Oriented Programming I ======
    Assignment 02: Pirates vs Ninjas (Updated)
    Professor:  Rawad Habib
    Start Date: 5/13/26
    End Date:   6/10/26
    By Aaron Hurst
    References after main()
 */

// Preprocessing Libraries
#include "gameStructure.h"
#include "character.h"
#include "ninja.h"
#include "pirate.h"
#include "boss.h"
#include "maleNinja.h"
#include "femaleNinja.h"
#include "humanPirate.h"
#include "undeadPirate.h"
#include <iostream>
#include <string>
#include <cmath>
#include <memory> // for smart pointers

// Fucntion Prototypes
void gameIntro();
std::unique_ptr<Character> chooseFighter();

// Main
int main () {
  // Call the game intro function to introduce the game to the user
  gameIntro();
  // Get the palyer's fighter choice
  // adding 'auto' to force compiler to looke at the return type of chooseFighter() and assign it to the 'player' variable.
  // this is faster thay typing out std::unique_ptr<Character> every time, and also makes it easier to change the return type
  auto player = chooseFighter();
  // Display fighter choice to the player
  std::cout << "\nYou chose: " << player->Name << std::endl;

  // Talk() for overloaded polymorphism
  player->Talk(player->Name, "I am ready to fight!");
  
  // Help() for polymorphic override
  player->Help();
  
  // Attack() for virtual override that returns 25
  std::cout << player->Name << " attacks for " << player->attack() << " hit points!" << std::endl;

  // getHealth() and setHealth()
  std::cout << "Current Health: " << player->getHealth() << std::endl;
  player->setHealth(-10);
  std::cout << "Health after taking fatal damage: " << player->getHealth() << std::endl;

  // This code block helps compile past the VS Code constraints in the terminal
  // Without this I was running into issues with the terminal closing out too early, this sucked!
  // The outputs were disappearing before the player could read what was happening, so now the program forces an extra ENTER for UX
  // Pause before exit to keep the terminal open so the player can read the output
  std::cout << "\nPress [ENTER] to exit...\n";
  // Clear leftover inputs from cin before waiting for the player to push ENTER
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  // Waiting for the player to push ENTER
  std::cin.get();

 }

// Function Declarations
/*===== Introduce the Game to the User =====
   Create a strong UX that looks good and
   informs the play what will happen in game          
 */
void gameIntro(){
   std::cout << "\n\n"; // create some separation
   //----- GAME BANNER -----
   std::cout << "==========================================\n";
   std::cout << "             PIRATES v. NINJAS            \n";
   std::cout << "              Shadow or Steal             \n";
   std::cout << "==========================================\n";

   //----- NARATIVE -----
   std::cout << "\nTwo worlds collide. One survives.\n\n";
   std::cout << "The docks of Port Kurai is where the ninja clans\n";
   std::cout << "and pirate crews have drawn blood for generations.\n";
   std::cout << "Tonight, you enter the fight.\n\n";

   //----- WORKFLOW -----
   std::cout << "------------------------------------------\n";
   std::cout << "  HOW IT WORKS:\n";
   std::cout << "  1. You will choose your fighter from the menu.\n";
   std::cout << "  2. You must defeat two opponents to advance.\n";
   std::cout << "  3. Engage and defeat the the boss... if you can\n";
   std::cout << "------------------------------------------\n\n";

   //----- PROMPT PLAYER TO START -----
   std::cout << "\nPress [ENTER] to begin...\n";
   // clear the buffer and ignore any input before the enter key, 
   // then pause the game for the user to press enter before proceeding
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::cin.get();
 }

std::unique_ptr<Character> chooseFighter() {
    // Display the fighter selection menu
    std::cout << "\n==========================================\n";
    std::cout << "         CHOOSE YOUR FIGHTER\n";
    std::cout << "==========================================\n";
    std::cout << "  1. Musashi        (Male Ninja)\n";
    std::cout << "  2. Mochizuki      (Female Ninja)\n";
    std::cout << "  3. Sestus Paks    (Human Pirate)\n";
    std::cout << "  4. Benjin Bonejaw (Undead Pirate)\n";
    std::cout << "------------------------------------------\n";
    std::cout << "Enter your choice (1-4): ";

    // Read the player's choice
    int choice{0};
    std::cin >> choice;

    // Return the selected fighter as a unique_ptr to the base class
    switch (choice) {
        case 1: return std::make_unique<MaleNinja>();
        case 2: return std::make_unique<FemaleNinja>();
        case 3: return std::make_unique<HumanPirate>();
        case 4: return std::make_unique<UndeadPirate>();
        default:
            std::cout << "Invalid choice. Defaulting to Musashi.\n";
            return std::make_unique<MaleNinja>();
    }
}



