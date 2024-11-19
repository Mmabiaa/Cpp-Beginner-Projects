#include "Currency.h"
#include <iostream>

using namespace std;
//Constructor to display Headers
Currency::Currency()
{
    cout<< "--Welcome to the Currency Converter--\n";
    cout<< "---------------------------------------\n";
    cout<<"\t ---Menu---\n";
    cout<< "----------------------------------------\n";
    diplay_Currencies();
}

// Function to calculate currency
double Currency::Calculate(double amount, string from, string to)
{
    return amount * (exchange_Rates[to] / exchange_Rates[from]);
}

//Display various currencies
void Currency::diplay_Currencies()
{
    cout<< "Available Currencies:\n";
    for(const auto& rate : exchange_Rates)
    {
        cout<<" \t"<< rate.first << endl;
    }
    cout<<"--------------------------------------------"<<endl;
}

// Accepts users credentials
void Currency::get_credentials()
{
    double amount;
    string to, from;
    cout<< "Enter currency to convert from(e.g. USD): ";
    cin>>from;
    cout<<"--------------------------------------------"<<endl;
    cout<< "Enter currency to convert to: ";
    cin>>to;
    cout<<"--------------------------------------------"<<endl;

    if(exchange_Rates.find(from) != exchange_Rates.end() &&
       exchange_Rates.find(to) != exchange_Rates.end())
    {
        cout<< "Enter amount: ";
        cin>> amount;
        cout<<"--------------------------------------------"<<endl;
        cout<< from<<" "<< amount<< " = " <<to <<" "<< Calculate(amount, from, to)<<endl;
        cout<<"--------------------------------------------"<<endl;
    }
    else
    {
        cout<< "Invalid Currency Code!"<<endl;
    }
}
