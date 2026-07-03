#pragma once
#include <exception>
// this gives me access to std::exception, the built in base class I am inheriting from
#include <string>
// this gives me access to std::string so I can store my own error message

// This is my own custom exception class. I made it inherit from the built in
// std::exception class. I use this specifically for problems that only make sense
// in my own program, like someone trying to create a unit with negative health.
// A negative health value does not mean anything in real life, so instead of letting
// the program keep running with bad data, I throw this exception and stop it right there.
class InvalidUnitException : public std::exception {
private:
    // message holds the specific text that explains what went wrong
    std::string message;

public:
    // constructor, takes in whatever error message I want this exception to carry
    InvalidUnitException(std::string msg);

    // this is required when you inherit from std::exception
    // it returns the error message as plain text so it can be printed
    // noexcept means this function promises it will never throw its own exception
    const char* what() const noexcept;
};
