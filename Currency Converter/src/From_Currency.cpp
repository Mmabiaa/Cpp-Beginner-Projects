#include "From_Currency.h"

From_Currency::From_Currency()
{
    //ctor
}


double From_Currency::Calculate(double amount, string from, string to) override
{
    return amount * (exchange_Rates[to / exchange_Rates[from])
}
