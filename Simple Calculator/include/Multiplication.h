#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <Calculator.h>


class Multiplication : public Calculator
{
    public:
        Multiplication();
        double calculate(double a, double b) override;

    protected:

    private:
};

#endif // MULTIPLICATION_H
