#ifndef ADD_H
#define ADD_H

#include <Calculator.h>


class Add : public Calculator
{
    public:
        Add();
        double calculate(double a, double b) override;

    protected:

    private:
};

#endif // ADD_H
