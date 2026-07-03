#include "InvalidUnitException.h"   // use the class declaration linking the code

// constructor saves the message passed to it as astrting named msg
InvalidUnitException::InvalidUnitException(std::string msg) {
    // store the message so what() can return it later
    message = msg;
}

// this hands back the error message as a plain C style string
const char* InvalidUnitException::what() const noexcept {
    // c_str() converts my std::string into the plain text format this function has to return
    return message.c_str();
}
