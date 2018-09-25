#include <iostream>
#ifndef MATH_MATH_H
#define MATH_MATH_H

void fibonacci();
void fib_seq(int termnum);
void fib_term(int termnum);
void gcd();
void lcm();
long int gcd_lcm(long int a, long int b);
void round();

//Prompts user to choose if they would like to find a term or the entire list of numbers leading up to the term.
void fibonacci(){
    int termnum{0};
    char func_choice{1};

    std::cout << "Would you like to find the term or the sequence leading up to it? \'s\' for the sequence,";
    std::cout << "\'t\' for the specific term." << std::endl;
    std::cin >> func_choice;

    if(func_choice == 's'){
        fib_seq(termnum);
    }

    else if(func_choice == 't'){
        fib_term(termnum);
    }
    else{
        std::cout << "Error!";
    }
}

//If user would like to find entire sequence
void fib_seq(int termnum){
    long unsigned int set3[3]={1, 0, 0};
    std::cout << "How many terms would you like?" << std::endl;
    std::cin >> termnum;
    for (int i = 0; i < termnum; i++) {
        //set3[2] is the specific number, while set3[0] and set3[1] store the previous two numbers.
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];
        
        //For aesthetics, the sequence has commas between terms, and a period at the end of the sequence.
        std::cout << set3[2] << ((i == termnum - 1) ? "." : ", ");
    }
}

//If user would like to find only the term.
void fib_term(int termnum){
    long unsigned int set3[3]={1, 0, 0};
    std::cout << "Which term would you like?" << std::endl;
    std::cin >> termnum;
    for (int i = 0; i < termnum; i++) {
        //Like before, set3[2] is the specific number, while set3[0] and set3[1] store the previous two numbers.
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];
    }

    std::cout << set3[2];
}

void lcm(){
    long int a;
    long int b;

    std::cout << "Enter your first number:" << std::endl;
    std::cin >> a;
    std::cout << "Enter your second number:" << std::endl;
    std::cin >> b;

    gcd_lcm(a, b);
    
    //Using LCM = (a*b)/GCD
    std::cout << a*b/gcd_lcm(a, b);
}

//The GCD calculator that is only used to calculate the LCM
long int gcd_lcm(long int a, long int b){
    long int divisor{1};

    if(a>b){
        long int tmp;
        tmp=b;
        b=a;
        a=tmp;
    }
    
    //Cycles through values of i, to find if i is a possible factor.
    int i{1};
    while(i<=a){
        if(a%i==0 && b%i==0){
            divisor=i;
        }
        i++;
    }

    return(divisor);
}

//For finding the GCD
void gcd(){
    long int divisor{1};
    long int a{1};
    long int b{1};

    std::cout << "Enter your first number: " << std::endl;
    std::cin >> a;
    std::cout << "Enter your second number: " << std::endl;
    std::cin >> b;

    if(a>b){
        long int tmp;
        tmp=b;
        b=a;
        a=tmp;
    }
    
    //Cycles through values of i, to find if i is a possible factor.
    int i{1};
    int i{1};
    while(i<=a){
        if(a%i==0 && b%i==0){
            divisor=i;
        }
        i++;
    }

    std::cout << divisor;
}

//If user would like to round
void round(){
    long double user_double{0};
    long int user_input{0};

    std::cout << "Enter the number you would like rounded:" << std::endl;
    std::cin >> user_double;
    user_input = (long int)(user_double+0.5);

    std::cout << user_input;
}

#endif
#endif
