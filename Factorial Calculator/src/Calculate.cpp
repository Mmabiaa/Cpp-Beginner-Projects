#include <iostream>
#include "Calculate.h"

using namespace std;

Calculate::Calculate() // Constructor
{
    cout<< "----Welcome to the Factorial Finder---- \n"<<endl;

    accept_user_option();// Calling the accept_user_option to get user option.

}

//Method to get and accept user option
int Calculate::accept_user_option()
{
    cout<< "Would you like to continue? (1. Yes 2.No): ";
    int user_option;//Variable to store user option.

    cin>>user_option;
    cout<< endl;

     validate_user_option(user_option);//Calling the validate_user_option to validate user option.

    return user_option;

}


//Method to validate user option.
void Calculate::validate_user_option(int user_option)
{
    //Conditions to satisfy validations.
    if (user_option != 1 && user_option !=2)//Option must be 1 or 2
    {
        cout<< "Please enter 1 or 2"<<endl;//warning propmt
        accept_user_option();//calling this method for recursion.
    }

    else{ // If user option is one or two.

        if( user_option == 1) // for option 1
        {
            int num = accept_user_number();// call this method to accept user numbers for calculations.
        }
        else{ // for option 2 --Quit program.
            cout<< "Thanks for using the program! Quiting..."<<endl;
        }
    }
}

//Method to accept user number.
int Calculate::accept_user_number()
{
    cout<< "Enter the number: ";
    int number;// variable to store user number.
    cin>>number;

    validate_user_number(number);// Calling this method for validations of the user number.

    return number;

}

//Method to validate user number.
void Calculate::validate_user_number(int number)
{// Conditions to be met!

    if(number <= 0)//number must not be 0 or less
    {
        cout<< "Number can't be zero or negative"<<endl; //Prompt.
        accept_user_number();//Calling this function for recursion.
    }

    else{// When condition is satisfied.

        int answer = find_factorial(number);//storing and Calling the factorial method for calculations in a variable.

        cout<< number<< "! = "<<answer<<endl; // displaying the results.
        cout<<endl;
        accept_user_option();// Recursion for program continuetion.
    }
}

//Method to find the factorial.
int Calculate::find_factorial(int number)
{
    if (number == 1) // 1! = 1
    {
        return 1;
    }

    else{
        return number * (find_factorial(number-1)); //recursion of the method till number - 1 = 1.
    }
}

