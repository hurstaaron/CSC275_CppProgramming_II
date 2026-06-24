#include "ConfigReader.h"
// Constructor inistializes all member variables to default values
ConfigReader::ConfigReader()
    : fileName{""}, layerCount{0}, learningRate{0.0f}, epochs{0}{
        // keeping the body emopty, initialization handled in the member initializer list above

    }

// loadfile() opens the configReader file by name
// will throw std::runtime_error if the files canno be opened
void ConfigReader::loadFile(std::string inFileName){
    try{
        fileName = inFileName;              // store the incoming file name in private member
        std::ifstream configFile{fileName}; // create input file stream object and try to open the file
        if (!configFile.is_open()){         // if the file fails to open throw: runtime_error
            throw std::runtime_error("Error: could not open file: " + fileName);
        }

        // tell the user the file opens successfully
        std::cout << "Config file opened successfully: " << fileName << std::endl;

        configFile.close();                 // close the file        
    }

    catch (std::runtime_error& e){                  // catch the error
        std::cout << "Runtime error in loadFile: "  // tell the user what the error is
            << e.what() << std::endl;
    }    
}

// parselayerCount converts the input string to an integer for layer count
// will throw std::invlaid_argument if the input cannot be converted to a numbner
void ConfigReader::parseLayerCount(std::string inInput){
    try{
        // std::stoi (string to integer found in <string> ) will convert to an integer
        // this auto throws invalid_argument if the string is not a number
        layerCount = std::stoi(inInput);

        // tell the user the layer count was set correctly
        std::cout << "layer count set to: " << layerCount << std::endl;
    }
    // catch error if the input is not valiud
    catch(std::invalid_argument& e){
        std::cout << "Invalid argument in parseLayerCount: " 
            << e.what() << std::endl;
    }
}

// parseLearningRate: converts input string to a float for the learning rate
// throws std::out_of_range if the value is not between 0.0 and 1.0
void ConfigReader::parseLearningRate(std::string inInput)
{
    try
    {
        // std::stof (string to float is in <string>) converts a string to a float
        float incomingRate = std::stof(inInput);

        // check if the value is outside the valid range of 0.0 to 1.0
        // learning rate must be between 0.0 and 1.0 for neural network training
        if (incomingRate < 0.0f || incomingRate > 1.0f)
        {
            throw std::out_of_range("Error: learning rate must be between 0.0 and 1.0, got: " + inInput);
        }

        // value is valid, store it in the private member
        learningRate = incomingRate;

        // tell the user the learning rate was set successfully
        std::cout << "Learning rate set to: " << learningRate << std::endl;
    }
    catch (std::out_of_range& e)
    {
        // catch the error if the value was outside the valid range
        std::cout << "Out of range error in parseLearningRate: " << e.what() << std::endl;
    }
}

// parseEpochs: converts input string to an integer for the number of training epochs
// throws std::runtime_error if the value is negative
void ConfigReader::parseEpochs(std::string inInput)
{
    try
    {
        // std::stoi converts the string to an integer
        int incomingEpochs = std::stoi(inInput);

        // epochs cannot be negative, a negative number of training passes makes no sense
        if (incomingEpochs < 0)
        {
            throw std::runtime_error("Error: epochs cannot be negative, got: " + inInput);
        }

        // value is valid, store it in the private member
        epochs = incomingEpochs;

        // tell the user the epochs value was set successfully
        std::cout << "Epochs set to: " << epochs << std::endl;
    }
    catch (std::runtime_error& e)
    {
        // catch the error if the epochs value was negative
        std::cout << "Runtime error in parseEpochs: " << e.what() << std::endl;
    }
}

// displayConfig: prints all stored configuration values to the screen
// this gives the user a summary of what was loaded and validated
void ConfigReader::displayConfig()
{
    // print a separator line for clean UX
    std::cout << "\n===== Neural Network Configuration =====" << std::endl;

    // display each stored member variable with a label
    std::cout << "File Name:     " << fileName << std::endl;
    std::cout << "Layer Count:   " << layerCount << std::endl;
    std::cout << "Learning Rate: " << learningRate << std::endl;
    std::cout << "Epochs:        " << epochs << std::endl;

    // closing separator for clean UX
    std::cout << "========================================" << std::endl;
}

