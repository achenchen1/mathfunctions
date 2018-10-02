#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H
#include <iostream>
#include <cmath>
class Sequences {
public:
    void fib_seq(long int terminalnumber);
    long unsigned int fib_term(long int terminalnumber);
    void collatz(long int terminalnumber);
};

class Misc {
public:
    void friendly(long unsigned int user_input);
    int friendly_counter(long unsigned int user_input);
    long int reverse(long int user_input);
    bool palindrome(long int user_input);
};

class Nums {
public:
    long int gcd(long int num1, long int num2);
    long int lcm(long int num1, long int num2);
};

class Primes {
public:
    bool prime(long unsigned int prime1);
    void primerange(long int prime1, long int prime2);
    bool primebool(long int prime1);
};
#endif
