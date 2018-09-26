#include <iostream>
#include <cmath>
#include "functions_set.h"

int main(){
    char user_input;
    std::cout << "Possible functions: 'f' for Fibonacci, 'g' for GCD, 'l' for LCM, 'c' for Collatz, and 'r' for rounding.";
    std::cout << "Choose a function." << std::endl;

    std::cin >> user_input;
    //As prompted by user, finds GCD.
    if(user_input == 'g' || user_input == 'G'){
        gcd();
        std::cout << std::endl;
    }
    
    //As prompted by user, finds Fibonacci sequence or term.
    else if(user_input == 'f'|| user_input == 'F'){
        fibonacci();
        std::cout << std::endl;
    }
    
    //As prompted by user, finds LCM.
    else if(user_input == 'l' || user_input == 'L'){
        lcm();
        std::cout << std::endl;
    }
    
    //Rounding.
    else if(user_input == 'r' || user_input == 'R'){
        round();
        std::cout << std::endl;
    }
    
    //Collatz
    else if(user_input == 'c' || user_input == 'C'){
        collatz();
        std::cout << std::endl;
    }
    
    else{
        std::cout << "Error.";
    }

    return(0);
}
