#ifndef CURRENCY_H
#define CURRENCY_H
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;


class Currency
{
    public:
        Currency();
        double Calculate(double Amount, string from, string to);
        void diplay_Currencies();
        void get_credentials();

    protected:

    private:
        unordered_map<string, double> exchange_Rates =
{
    {"USD", 1.0}, //Base currency
    {"EUR", 0.85},
    {"GBP", 0.75},
    {"JPY", 110.0},
    {"GHS", 16.02},
    {"NIN", 1679.60}
};
};

#endif // CURRENCY_H
