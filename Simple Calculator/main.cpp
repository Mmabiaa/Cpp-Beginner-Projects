#include <iostream>

// Including All class header files
#include "Calculator.h" // Parent Calculator class
#include "Addition.h" // Addition class
#include "Subtraction.h" // Subtraction class
#include "Division.h" // Division class
#include "Multiplication.h" // Multiplication class


using namespace std;

// Main function to be executed.
int main()
{
    //Instantiating various classes
    Addition add; //object for Addition claas
    Subtraction sub; // object for Subtraction class
    Division div; // object for Division class
    Multiplication mul; // object for multiplication class

    int choice; //variable to hold user choices for menu options
    double fnum, lnum; // variables to hold user number input (type double)


    cout<< "---------------------------------------"<<endl;
    cout<< "----Welcome to the Simple Calculator---"<<endl; // Welcome message

do{ // do-while loop to iterate the program till a user choice is 5 to exit
    cout<< "--------------------------------------------"<<endl;
    cout<< "\t --Menu-- \t\n 1. Addition \t\n 2. Subtraction \t\n 3. Division \t\n 4. Multiplication \t\n 5. Exit"<<endl; // Menu and menu options display
    cout<< "---------------------------------------"<<endl;

    cout<< "Enter a choice (1-5): ";cin>>choice; //Prompt to accept user choice input

    cout<< "---------------------------------------"<<endl;

        // Conditions to check and validate user choice for menu options
    if (0 < choice && choice < 5) // Condition to check if user choice is within 1 to 4
    {
        // Prompt to accept user values or numbers for calculations
        cout<< "Enter first number: ";cin>>fnum;
        cout<< "Enter last number: ";cin>>lnum;
        cout<< "---------------------------------------"<<endl;

        switch(choice) // Switch case to switch between user choices if choice is between 0 and 5 exclusive.
        {

        case 1: // Addition choice
            cout << fnum << " + " << lnum << " = " << add.calculate(fnum, lnum) << endl;
            break;
        case 2:// Subtraction choice
            cout << fnum << " - " << lnum << " = " << sub.calculate(fnum, lnum) << endl;
        break;
        case 3:// Division choice
            // Checking and validating the division by zero error!
            if(lnum==0) // try for error!
            {
                cout<< "Division by zero is invalid! "<<endl;
            }
            else // try for no error !
            {
                cout << fnum << " / " << lnum << " = " << div.calculate(fnum, lnum) << endl;
            }
        break;
        default:// Multiplication choice
            cout << fnum << " * " << lnum << " = " << mul.calculate(fnum, lnum) << endl;
        }
    }

    else if(choice == 5) // Choice to quit or exit the program.
    {
        cout<< "Thanks for using the program...Byeeeeee!"<<endl;
        cout<< "----------------------------------------";

    }

    else{// Error check condition to prompt user of a Value Error!
        cout<< "Invalid Input! Enter a number from (1-5)"<<endl;
        cout<< "----------------------------------------"<<endl;
    }

}while( choice != 5);// Loop till user choice is not 5 then quit!


    return 0;
}
