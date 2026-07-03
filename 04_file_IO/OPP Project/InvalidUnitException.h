#pragma once            // so i dont need indef guards
#include <exception>    // access to std::exception that was built in the parent class I'm inheriting from
#include <string>       // access to std::string for storing my error message

// This is a custom exception class. I made it inherit from the std::exception class. I use for problems 
// that happen in my own program, e.g someone trie to create a unit with negative health.
// Negative health value doesn't mean anything in "real" life and I don't want the program to run with 
// bad data. I throw this exception and stop the program immediately.
class InvalidUnitException : public std::exception {
private:
    std::string message;                    // message holds the specific text that explains what went wrong

public:
    InvalidUnitException(std::string msg);  // constructor, takes in whatever error message I want this exception to carry

    // used when inheriting from std::exception because it returns the error message 
    // as plain text so it can be printed noexcept means the function promises it 
    // never throws its own exception
    const char* what() const noexcept;
};
