#ifndef FROM_CURRENCY_H
#define FROM_CURRENCY_H

#include <Currency.h>


class From_Currency : public Currency
{
    public:
        From_Currency();
        double Calculate(double amount, string currency) override;

    protected:

    private:
};

#endif // FROM_CURRENCY_H
