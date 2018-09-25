#include <iostream>
#include <cmath>
#include "functions_set.h"

int main(){
    char user_input;
    std::cout << "What would you like to calculate today? Enter 'f' for Fibonacci functions, 'g' for Greatest Common Divisors, and 'l' for Lowest Common Multiple. " << std::endl;

    std::cin >> user_input;
    if(user_input == 'g' || user_input == 'G'){
        gcd();
        std::cout << std::endl;
    }
    else if(user_input == 'f'|| user_input == 'F'){
        fibonacci();
        std::cout << std::endl;
    }
    else if(user_input == 'l' || user_input == 'L'){
        lcm();
        std::cout << std::endl;
    }
    else{
        std::cout << "Error.";
    }

    return(0);
}