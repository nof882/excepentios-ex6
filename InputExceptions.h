#pragma once
#include <exception>
#include <string>

class InputException : public std::exception {
    std::string msg;
public:
    InputException(const std::string& m) : msg(m) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
