#ifndef DIVISION_H
#define DIVISION_H

#include <Calculator.h>


class Division : public Calculator
{
    public:
        Division();
        double calculate(double a, double b) override;
    protected:

    private:
};

#endif // DIVISION_H
