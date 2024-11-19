#ifndef TO_CURRENCY_H
#define TO_CURRENCY_H

#include <Currency.h>


class To_Currency : public Currency
{
    public:
        To_Currency();
        From_Currency();
        double Calculate(double amount, string currency) override;

    protected:

    private:
};

#endif // TO_CURRENCY_H
