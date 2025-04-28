#include <iostream>
#include <cmath>
using namespace std;

// TODO
int factorial(int input){
    if (input <= 1){return 1;}
    return input*factorial(input-1);
}
double factorial(double float_input){
    int input((int)float_input);
    if (input <= 1){return 1;}
    return input*factorial(input-1);
}
int sumDigits(int input){
    if (input < 10){return input;}
    return input%10 + sumDigits(input/10);
}
double sumDigits(double float_input){
    int input((int)(float_input*100));
    if (input < 10){return input;}
    return input%10 + sumDigits(input/10);
}

int main() {
    int int_factorial_input, int_factorial_output;
    double double_factorial_input, double_factorial_output;

    cin >> int_factorial_input;
    cin >> double_factorial_input;

    double_factorial_output = factorial(int_factorial_input);
    int_factorial_output = factorial(double_factorial_input);
    cout << double_factorial_output << endl;
    cout << int_factorial_output << endl;

    int int_sum_input, int_sum_output;
    double double_sum_input, double_sum_output;

    cin >> int_sum_input;
    cin >> double_sum_input;
    
    double_sum_output = sumDigits(int_sum_input);
    int_sum_output = sumDigits(double_sum_input);
    cout << double_sum_output << endl;
    cout << int_sum_output << endl;

    return 0;
}