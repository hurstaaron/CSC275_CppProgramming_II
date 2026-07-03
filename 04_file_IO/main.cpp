/*
    Assignment 04: File I/O 
    Professor: Rawad Habib
    Start Date: 6/10/26
    End Date:   6/24/26
    By: Aaron Hurst
*/

#include <iostream>   // needed so I can use cin and cout to talk to the user
#include <fstream>    // needed so I can open, write to, and read from a text file
#include <string>     // needed so I can use the string data type for text

// I am not using "using namespace std" in this version
// so every time I use something like cout or string I have to
// write std:: in front of it to tell the compiler where it comes from

int main()
{
    // These first few lines just print out a little intro so whoever runs
    // the program knows what it does before they start typing anything.
    // This covers the requirement that the app has to explain itself when it starts.
    std::cout << "=====================================" << std::endl;
    std::cout << "   Welcome to my Simple Notes App!" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "This program lets you type in some notes." << std::endl;
    std::cout << "Every note you type gets saved to a text file called notes.txt" << std::endl;
    std::cout << "and it also shows up right here on the screen at the same time." << std::endl;
    std::cout << "When you are done typing notes, just type the word quit and press enter." << std::endl;
    std::cout << std::endl;

    // this string will hold whatever the user types in on each line
    std::string userInput;

    // this string is just the name of the file we are saving everything to
    // I made it a variable instead of typing "notes.txt" everywhere in the code
    // in case I ever want to change the file name later, only have to change it once
    std::string fileName = "notes.txt";

    // this keeps track of how many notes the user has typed in, starts at zero
    int noteCount = 0;

    // ofstream is the data type used for writing OUT to a file
    // opening it here so the file is ready to be written to
    std::ofstream outputFile(fileName);

    // if the file did not open for some reason, tell the user and end the program
    // instead of letting it crash or do something weird
    if (!outputFile)
    {
        std::cout << "Something went wrong opening the file. Closing program." << std::endl;
        return 0;
    }

    // this loop keeps asking the user for a note over and over again
    // it will keep looping forever until the user types the word quit
    while (true)
    {
        std::cout << "Enter a note (or type quit to stop): ";
        std::getline(std::cin, userInput);

        // if the user typed quit, break out of the loop and stop asking for notes
        if (userInput == "quit")
        {
            break;
        }

        // this line writes the note the user typed into the text file
        outputFile << userInput << std::endl;

        // this line prints that exact same note to the screen right away
        // so the file and the screen are getting the same info at the same time
        std::cout << "Saved to file: " << userInput << std::endl;

        // add one to the note counter since we just saved a note
        noteCount++;
    }

    // now that the loop is over, close the output file so everything actually saves
    outputFile.close();

    std::cout << std::endl;
    std::cout << "You entered " << noteCount << " notes. They have been saved to " << fileName << std::endl;
    std::cout << std::endl;

    // now we open the file again, but this time we are reading from it instead of writing
    // ifstream is the data type used for reading IN from a file
    std::ifstream inputFile(fileName);

    // if the file did not open for reading, tell the user and end the program
    if (!inputFile)
    {
        std::cout << "Could not open the file to read it back. Closing program." << std::endl;
        return 0;
    }

    std::cout << "Here is everything that is saved in " << fileName << ":" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // this string will hold each line as we pull it out of the file one at a time
    std::string lineFromFile;

    // this loop reads the file line by line until there is nothing left to read
    // getline returns false once it hits the end of the file, which stops the loop
    while (std::getline(inputFile, lineFromFile))
    {
        // print out each line we just pulled from the file
        std::cout << lineFromFile << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

    // close the input file since we are done reading from it
    inputFile.close();

    std::cout << std::endl;
    std::cout << "Thanks for using the Simple Notes App. Goodbye!" << std::endl;

    return 0;
}
