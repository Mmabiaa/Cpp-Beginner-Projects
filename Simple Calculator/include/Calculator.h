#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>

using namespace std;

// Class file for the calculator program
class Calculator
{
    public:
        Calculator();

        virtual double calculate(double num1, double num2) = 0; //Pure virtual function

};



#endif // CALCULATOR_H
