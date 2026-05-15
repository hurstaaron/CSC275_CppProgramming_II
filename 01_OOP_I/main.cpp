 /*  ====== Object Oriented Programming I ======
    Assignment 01: Pirates vs Ninjas
    Professor:  Rawad Habib
    Start Date: 5/13/26
    End Date:   5/xx/26
    By Aaron Hurst
    References after main()
 */

 // Preprocessing Libraries
 #include "character.h"
 #include "ninja.h"
 #include "pirate.h"
 #include "boss.h"
 #include <iostream>
 #include <string>
 #include <cmath>

 // Fucntion Prototypes
 void gameIntro();

 // Main
 int main () {
   // Call the game intro function to introduce the game to the user
   gameIntro();

   /* --- Create a NINJA, PIRATE, and BOSS objects ---
      Use the constructor 
      Name this character Shadow
      Pass the 14 parameters - 1 string, 10 ints, 1 bool, 2 floats
      */
   Ninja Shadow{"Shadow", 100, 15, 25, 80, 95, 40, 50, 70, 0, 100, false, 1.5f, 2.0f};
   Pirate OneEye{"One-Eye", 100, 80, 95, 15, 25, 55, 75, 20, 0, 100, false, 1.5f, 2.0f};
   Boss EvilNed{"Evil Ned", 135, 70, 90, 20, 25, 65, 75, 30, 10, 90, false, 1.75f, 2.25f};

   /* --- Call all of the objects ---
      -- Expecting: --             
         Shadow used Precision Strike!
         One-Eye is fighting Mean and Dirty!
         Evil Ned uses Thunder Punch!
   */ 
   Shadow.PrecisionStrike();
   OneEye.DirtyBrawler();
   EvilNed.ThunderPunch();
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
   //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::cin.get();
 }

