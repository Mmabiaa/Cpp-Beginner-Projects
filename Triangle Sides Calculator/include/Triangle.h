#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle
{
    public:
        Triangle();
        int get_user_option();
        void check_user_option(int option);
        void get_side();
        void calculate_side(int side);
        void to_continue();

    protected:

    private:
};

#endif // TRIANGLE_H
