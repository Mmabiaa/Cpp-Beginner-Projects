#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

void Triangle::to_continue(){
    int c;
    cout<<"Do you want to continue?(1. Yes 2. No): ";
    cin>>c;
    if (c != 1)
    {
        cout<< "Exiting... Thanks for using the program!";
    }
    else{
        cout<< "-------------------------------------------------"<<endl;
            get_side();}
}

Triangle::Triangle()
{
    cout<< "---Menu---"<<endl;
    cout<< "1. Find The Side of a Triangle"<<endl;
    cout<< "2. Exit"<<endl;
    cout<< "-------------------------------------------------"<<endl;

    get_user_option();
}

int Triangle::get_user_option()
{
    int user_option;
    cout<< "Enter your option: ";
    cin>> user_option;
    cout<< "-------------------------------------------------"<<endl;

    if (user_option < 1 || user_option >2){
        cout<< "Please enter a valid user option."<<endl;
    }
    else{
        check_user_option(user_option);
    cout<< "-------------------------------------------------"<<endl;
    }

    return user_option;
}

void Triangle::check_user_option(int option){
    if (option == 2)
    {
        cout<< "Thanks for using the program...byeeeeee";
    }
    else{
        get_side();
        cout<< "-------------------------------------------------"<<endl;
    }
}

void Triangle::get_side()
{
    int side;
    cout<< "1. Adjacent 2. Opposite 3. hypotenuse"<<endl;
    cout<< "Enter the side to find(1 - 3): ";
    cin>>side;
    cout<< "-------------------------------------------------"<<endl;

    if (side < 1 || side > 3){
        cout<< "Enter a valid side (1-3)."<< endl;
    }
    else{
        calculate_side(side);
        cout<< "-------------------------------------------------"<<endl;
    }

}

void Triangle::calculate_side(int side)
{
    int opp, adj, hyp;
    if (side == 1){
        cout<< "Finding the Adjacent side..."<<endl;
        cout<< "-------------------------------------------------"<<endl;
        cout<< "Enter the opposite side: ";
        cin>>opp;
        cout<< "Enter the hypotenuse side: ";
        cin>>hyp;
        cout<< "-------------------------------------------------"<<endl;
        adj = sqrt((hyp*hyp)+(opp*opp));
        cout<< "Adjacent side = "<<adj<<endl;
        cout<< "-------------------------------------------------"<<endl;
    }
    else if (side == 2){
        cout<< "Finding the Opposite side..."<<endl;
        cout<< "-------------------------------------------------"<<endl;
        cout<< "Enter the adjacent side: ";
        cin>>adj;
        cout<< "Enter the hypotenuse side: ";
        cin>>hyp;
        cout<< "-------------------------------------------------"<<endl;

        opp = sqrt((hyp*hyp)+(adj*adj));
        cout<< "Opposite side = "<<adj<<endl;
        cout<< "-------------------------------------------------"<<endl;
    }
    else{
        cout<< "Finding the Hypotenuse side..."<<endl;
        cout<< "-------------------------------------------------"<<endl;
        cout<< "Enter the opposite side: ";
        cin>>opp;
        cout<< "Enter the adjacent side: ";
        cin>>adj;
        cout<< "-------------------------------------------------"<<endl;

        hyp = sqrt((adj*adj)+(opp*opp));
        cout<< "Hypotanus side = "<<adj<<endl;
        cout<< "-------------------------------------------------"<<endl;
    }

    to_continue();
    cout<< "-------------------------------------------------"<<endl;
}
