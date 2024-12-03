#ifndef CALCULATE_H
#define CALCULATE_H


class Calculate
{
    public:

        Calculate();
        int accept_user_option(), accept_user_number(), find_factorial(int user_answer); // Set of int functions
        void validate_user_option(int user_option), validate_user_number(int user_answer); //Set of void functions.

};

#endif // CALCULATE_H
