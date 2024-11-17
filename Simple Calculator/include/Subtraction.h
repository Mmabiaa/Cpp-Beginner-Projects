#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <Calculator.h>


class Subtraction : public Calculator
{
    public:
        Subtraction();
        double calculate(double a, double b) override;

    protected:

    private:
};

#endif // SUBTRACTION_H
