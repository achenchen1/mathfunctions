#include "functions_set.h"

/************************************************************************
 Demos all functions that do not themselves simply call another function.
           For explanations on each function, see mathfuncs.cpp
 ************************************************************************/

int main(){
    long unsigned int user_input1{0};
    long unsigned int user_input2{0};
    
    std::cout << "Enter your first input: ";
    std::cin >> user_input1;
    std::cout << "Enter your second input: ";
    std::cin >> user_input2;
    std::cout << "Functions that take one value take user_input, functions that take two will use both.";
    
    std::cout << std::endl <<  "Collatz" << std::endl;
    collatz(user_input1);
    std::cout << std::endl << "Fibonacci Sequence" << std::endl;
    fib_seq(user_input1);
    std::cout << std::endl << "Term in Fibonacci sequence" << std::endl;
    fib_term(user_input1);
    std::cout << std::endl << "Shows friendly sequences" << std::endl;
    friendly(user_input1);
    std::cout << "Number of friendly sequences" << std::endl;
    friendly_counter(user_input1);
    std::cout << std::endl << "GCD of two numbers" << std::endl;
    gcd(user_input1, user_input2);
    std::cout << std::endl << "LCM of two numbers" << std::endl;
    lcm(user_input1, user_input2);
    std::cout << std::endl << "Flips your number, identifies if your number is a palindrome" << std::endl;
    palindrome(user_input1);
    std::cout << std::endl << "Identifies if the number is prime" << std::endl;
    prime(user_input1);
    std::cout << std::endl << "Primes in the range of two numbers (inclusive)" << std::endl;
    primerange(user_input1, user_input2);
    
    return(0);
}
