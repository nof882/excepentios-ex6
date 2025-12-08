#include <iostream>
int add(int a, int b) {
  return a + b;
}

int  multiply(int a, int b) {
  int sum = 0;
  for(int i = 0; i < b; i++) {
    sum = add(sum, a);
  };
  return sum;
}

int  pow(int a, int b) {
  int exponent = 1;
  for(int i = 0; i < b; i++) {
    exponent = multiply(exponent, a);
  };
  return exponent;
}

int main(void) {
  std::cout << pow(5, 5) << std::endl;
}