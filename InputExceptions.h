#pragma once
#include <exception>

class InputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid input: expected a number.";
    }
};
