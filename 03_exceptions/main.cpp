/*
    Assignment 03: Exceptions - Neural Network Config Reader
    Professor: Rawad Habib
    Start Date: 6/10/26
    End Date:   6/24/26
    By: Aaron Hurst
*/

// include our config reader class and standard libraries
#include "configReader.h"
#include <iostream>
#include <string>

// function prototype for the program description shown at startup
void programIntro();

// main function: entry point of the program
int main()
{
    // display the program description and instructions to the user
    programIntro();

    // create a ConfigReader object to manage our neural network settings
    ConfigReader config;

    // --- Test 1: loadFile() --- 
    // runtime_error if file does not exist
    std::cout << "\n--- Test 1: Loading Config File ---" << std::endl;
    config.loadFile("network.cfg");

    // --- Test 2: parseLayerCount() --- 
    // invalid_argument if input is not a number
    std::cout << "\n--- Test 2: Parsing Layer Count ---" << std::endl;
    config.parseLayerCount("4");

    // --- Test 3: parseLearningRate() --- 
    // out_of_range if outside 0.0 to 1.0
    std::cout << "\n--- Test 3: Parsing Learning Rate ---" << std::endl;
    config.parseLearningRate("0.01");

    // --- Test 4: parseEpochs() --- 
    // runtime_error if negative
    std::cout << "\n--- Test 4: Parsing Epochs ---" << std::endl;
    config.parseEpochs("100");

    // display the successfully loaded configuration to the user
    config.displayConfig();

    // --- Now trigger all four exceptions so the rubric sees them fire ---
    std::cout << "\n===== Triggering Exception Demos =====" << std::endl;

    // trigger runtime_error: file does not exist
    std::cout << "\n--- Exception 1: File Not Found ---" << std::endl;
    config.loadFile("doesnotexist.cfg");

    // trigger invalid_argument: letters instead of a number
    std::cout << "\n--- Exception 2: Invalid Layer Count ---" << std::endl;
    config.parseLayerCount("abc");

    // trigger out_of_range: learning rate outside 0.0 to 1.0
    std::cout << "\n--- Exception 3: Learning Rate Out of Range ---" << std::endl;
    config.parseLearningRate("5.5");

    // trigger runtime_error: negative epochs
    std::cout << "\n--- Exception 4: Negative Epochs ---" << std::endl;
    config.parseEpochs("-10");

    // keep terminal open
    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.ignore();
    std::cin.get();

    return 0;
}

// programIntro: displays the program description and instructions at startup
void programIntro()
{
    std::cout << "========================================" << std::endl;
    std::cout << "   Neural Network Config Reader" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "This program simulates loading and validating" << std::endl;
    std::cout << "a neural network configuration file." << std::endl;
    std::cout << "\nHow to use this program:" << std::endl;
    std::cout << "  The program will attempt to load a config file," << std::endl;
    std::cout << "  parse layer count, learning rate, and epochs." << std::endl;
    std::cout << "  It will demonstrate both valid inputs and" << std::endl;
    std::cout << "  four different exception types." << std::endl;
    std::cout << "========================================\n" << std::endl;
}