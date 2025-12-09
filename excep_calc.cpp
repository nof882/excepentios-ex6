#include <iostream>
#include <stdexcept>

void throw8200() {
    throw std::runtime_error(
        "This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year"
    );
}

int add(int a, int b) {
    int result = a + b;
    if (a == 8200 || b == 8200 || result == 8200)
        throw8200();
    return result;
}

int multiply(int a, int b) {
    if (a == 8200 || b == 8200)
        throw8200();
    int sum = 0;
    for (int i = 0; i < b; i++) {
        sum = add(sum, a);
        if (sum == 8200)
            throw8200();
    }
    return sum;
}

int pow(int a, int b) {
    if (a == 8200 || b == 8200)
        throw8200();
    int exponent = 1;
    for (int i = 0; i < b; i++) {
        exponent = multiply(exponent, a);
        if (exponent == 8200)
            throw8200();
    }
    return exponent;
}

int main() {
    try { std::cout << add(5, 5) << std::endl; }
    catch (const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << add(8195, 5) << std::endl; }
    catch (const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << multiply(5, 5) << std::endl; }
    catch (const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << multiply(8200, 1) << std::endl; }
    catch (const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << pow(5, 5) << std::endl; }
    catch (const std::exception& e) { std::cout << e.what() << std::endl; }

    try { std::cout << pow(8200, 2) << std::endl; }
    catch (const std::exception& e) { std::cout << e.what() << std::endl; }
}
