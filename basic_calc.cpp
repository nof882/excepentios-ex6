#include <iostream>
int add(int a, int b, bool* errorflag) {
    int result = a + b;
    if (result == 8200) {
        *errorflag = true;
    }
    return result;
}

int  multiply(int a, int b, bool* errorflag) {
    int sum = 0;

    for (int i = 0; i < b; i++) {
        sum = add(sum, a, errorflag);
        if (sum == 8200)
            *errorflag = true;
    };
    return sum;
}

int  pow(int a, int b, bool* errorflag) {
    int exponent = 1;
    for (int i = 0; i < b; i++) {
        exponent = multiply(exponent, a, errorflag);
        if (exponent == 8200)
            *errorflag = true;
    };
    return exponent;
}

int main(void) {
    bool error = false;
    int result = pow(5, 5, &error);
    if (error)
    {
        std::cout << "This user is not authorized to access 8200, "
            "please enter different numbers, or try to get clearance in 1 year\n";
    }
    else
        std::cout << result << std::endl;

    error = false;
    result = pow(8200, 1, &error);
    if (error)
    {
        std::cout << "This user is not authorized to access 8200, "
            "please enter different numbers, or try to get clearance in 1 year\n";
    }
    else
        std::cout << result << std::endl;

    error = false;
    result = multiply(5, 5, &error);
    if (error)
    {
        std::cout << "This user is not authorized to access 8200, "
            "please enter different numbers, or try to get clearance in 1 year\n";
    }
    else
        std::cout << result << std::endl;
    error = false;
    result = multiply(8200, 1, &error);
    if (error)
    {
        std::cout << "This user is not authorized to access 8200, "
            "please enter different numbers, or try to get clearance in 1 year\n";
    }
    else
        std::cout << result << std::endl;
    error = false;
    result = add(5, 5, &error);
    if (error)
    {
        std::cout << "This user is not authorized to access 8200, "
            "please enter different numbers, or try to get clearance in 1 year\n";
    }
    else
        std::cout << result << std::endl;
    error = false;
    result = add(8195, 5, &error);
    if (error)
    {
        std::cout << "This user is not authorized to access 8200, "
            "please enter different numbers, or try to get clearance in 1 year\n";
    }
    else
        std::cout << result << std::endl;


}
