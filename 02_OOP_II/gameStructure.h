// Using pragma instead of indef and define guards for simplicity
#pragma once

// Abstract base class; this defines the structure all game classes must follow
class GameStructure {
public:
    // Pure virtual method; this forces all derived classes to implement their own Help()
    virtual void Help() = 0;

    // Virtual destructor; this ensures proper cleanup when deleting derived class objects
    virtual ~GameStructure() {}
};