#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H
#include <iostream>
#include <cmath>

//Pertains only to functions with sequences
class Sequences {
public:
    long int terminalnumber;

    void fib_seq();
    long unsigned int fib_term();
    void collatz();
};

//Pertains to miscellaneous functions
class Misc {
public:
    long unsigned int user_input;

    void friendly();
    int friendly_counter();
    long int reverse();
    bool palindrome();
};

//Pertains to numbers
class Nums {
public:
    long unsigned int primary_input;
    long unsigned int secondary_input;

    long unsigned int gcd();
    long unsigned int lcm();

    //Means
    long double amean();
    long double gmean();
    long double hmean();

    //Prime
    void primerange();
    bool primebool();
};
#endif
