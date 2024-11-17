#ifndef ADDITION_H
#define ADDITION_H

#include <Calculator.h>


class Addition : public Calculator
{
    public:
        Addition();
        double calculate(double a, double b);

    protected:

    private:
};

#endif // ADDITION_H
