#include "InvalidUnitException.h"   // use the class declaration linking the code

// constructor saves the message passed to it as astrting named msg
InvalidUnitException::InvalidUnitException(std::string msg) {
    // store the message so what() can return it later
    message = msg;
}

// sends error message as a string
const char* InvalidUnitException::what() const noexcept {
    // c_str() converts std::string into the text format this function returns
    return message.c_str();
}
