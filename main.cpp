#include "functions_set.h"

/**********************************************************
Demos all functions contained in functions_set.h; functions 
that call other functions (e.g. fibonacci(long int termnum)
are not included here, but all other functions are demoed.
 **********************************************************/
int main(){
    //Sequences and special functions
    std::cout << "These are for sequences and special functions." << std::endl;
    long int input1{0};
    std::cin >> input1;

    std::cout << "Collatz" << std::endl;
    collatz(input1);
    std::cout << std::endl;
    std::cout << "Fibonacci sequence" << std::endl;
    fib_seq(input1);
    std::cout << std::endl;
    std::cout << "Fibonacci term" << std::endl;
    fib_term(input1);
    std::cout << std::endl;
    std::cout << "Reversing your number and testing if it's a palindrome." << std::endl;
    palindrome(input1);
    std::cout << std::endl << std::endl;

    //GCD and LCM
    std::cout << "These are for GCD and LCM." << std::endl;
    std::cin >> input1;
    long int input2{0};
    std::cin >> input2;

    std::cout << "GCD" << std::endl;
    gcd(input1, input2);
    std::cout << std::endl;
    std::cout << "LCM" << std::endl;
    lcm(input1, input2);
    std::cout << std::endl << std::endl;

    //If it's prime
    std::cout << "These are for testing if your number is prime." << std::endl;
    unsigned long int input3{0};
    std::cin >> input3;

    prime(input3);
    std::cout << std::endl << std::endl;
    
    //Primes between two numbers
    std::cout << "These are for finding primes within a range (inclusive)." << std::endl;
    std::cin >> input1;
    std::cin >> input2;

    primerange(input1, input2);

    return(0);
}
