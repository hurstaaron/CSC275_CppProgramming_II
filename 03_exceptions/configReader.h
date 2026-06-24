#pragma once // including programa once so we don't have to worry about multiple includes
// include libraries for needed for the program to run: i/o, fstream for file handling, 
// string for strings, and stdexcept for exceptions
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class ConfigReader {
public:
    ConfigReader();                             // constructor initializes all of the member variables to a default state
    void loadFile(std::string inFileName);      // opens the file, throws 'runtime_error' if it fails
    void parseLayerCount(std::string inInput);  // validate layer count, throws 'invalid_argument' if non-number is entered
    void parseLearningRate(std::string inInput);// validate learning rate, throws 'out_of_range' if outside of 0.0 to 1.0 
    void parseEpochs(std::string inInput);      // validate epochs, throws 'runtime_error' if negative
    void displayConfig();                       // display configuration for UX

private:
    /* === ML Theme ==
    I want to learn more about using C++ for ML.
    Variables in private ensure we protect our data from outside manipulation
    Epochs represent each iteration through the entire neural network. 
        1 Epoch == 1 iteration, we want to track epochs. */
    std::string fileName;    // store the name of the file
    int layerCount;          // store the number of layers in the network
    float learningRate;      // store the learning rate value, it will be between 0.0 and 1.0
    int epochs;              // store the number of training epochs (machine lerning theme for nueral networks
};
    
