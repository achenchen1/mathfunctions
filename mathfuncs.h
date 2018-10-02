#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H
#include <iostream>
#include <cmath>

//Pertains only to functions with sequences
class Sequences {
public:
    void fib_seq(long int terminalnumber);
    long unsigned int fib_term(long int terminalnumber);
    void collatz(long int terminalnumber);
};

//Pertains to miscellaneous functions
class Misc {
public:
    void friendly(long unsigned int user_input);
    int friendly_counter(long unsigned int user_input);
    long int reverse(long int user_input);
    bool palindrome(long int user_input);
};

//Pertains to numbers
class Nums {
public:
    long int gcd(long int num1, long int num2);
    long int lcm(long int num1, long int num2);
    
    //Means 
    long double amean(unsigned int quantnum);
    long double gmean(unsigned int quantnum);
    long double hmean(unsigned int quantnum);
    
    //Prime
    bool prime(long unsigned int prime1);
    void primerange(long int prime1, long int prime2);
    bool primebool(long int prime1);
};
#endif
