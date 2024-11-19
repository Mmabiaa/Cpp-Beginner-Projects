#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int accept_guess() // Renamed the function
{
    int Guess; // Local variable to store the guess
    cout << "Guess a number between (1 to 100) inclusive: ";
    cin >> Guess;
    return Guess; // Return the user's guess
}

void Check_Equality(int number, int guess)
{
    if (number < guess)
    {
        cout << "Guess is too high!" << endl;
    }
    else if (number > guess)
    {
        cout << "Guess is too low!" << endl;
    }
    else
    {
        cout << "Congratulation! Your guess was right!" << endl;
    }
}

int main()
{
    srand(time(0)); // Initialize random seed
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int Guess;


    cout << "---Welcome to the Guessing Game---" << endl;
    cout << "------------------------------------------- \n";
    do{
    Guess = accept_guess(); // Get the guess from the user
    cout << "------------------------------------------- \n";
    Check_Equality(number, Guess); // Pass the correct variables
    cout << "------------------------------------------- \n";
    }while(Guess !=number);

    return 0;
}
